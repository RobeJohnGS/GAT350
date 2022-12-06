#include "Engine.h"
#include <vector>
#include <iostream>

#define POST_PROCESS

int main(int argc, char** argv)
{
	LOG("Application Started...");

	JREngine::InitializeMemory();
	JREngine::SetFilePath("../Assets");

	JREngine::Engine::Instance().Initialize();
	JREngine::Engine::Instance().Register();
	LOG("Engine Initialized...");

	JREngine::g_renderer.CreateWindow("JRGame", 800, 600, 0);
	LOG("Window Initialized...");

	JREngine::g_gui.Initialize(JREngine::g_renderer);

	// create framebuffer texture
	auto texture = std::make_shared<JREngine::Texture>();
	texture->CreateTexture(1024, 1024);
	JREngine::g_resources.Add<JREngine::Texture>("fb_texture", texture);

	// create framebuffer
	auto framebuffer = JREngine::g_resources.Get<JREngine::Framebuffer>("framebuffer", "fb_texture");
	framebuffer->Unbind();


	// load scene 
	auto scene = JREngine::g_resources.Get<JREngine::Scene>("Scenes/rtt.scn");

	glm::vec3 pos{ 0, 0, 0 };
	glm::vec3 rot{ 0, 0, 0 };

	float ri = 1.0f;
	bool quit = false;
	while (!quit)
	{
		JREngine::Engine::Instance().Update();
		JREngine::g_gui.BeginFrame(JREngine::g_renderer);

		if (JREngine::g_inputSystem.GetKeyState(JREngine::key_escape) == JREngine::InputSystem::State::Pressed) quit = true;

		auto actor = scene->GetActorFromName("Model");
		if (actor)
		{
			actor->m_transform.rotation = math::EulerToQuaternion(rot);
		}

		actor = scene->GetActorFromName("Light");
		if (actor)
		{
			// move light using sin wave
			//actor->m_transform.position = pos;
		}

		/*auto program = JREngine::g_resources.Get<JREngine::Program>("shaders/fx/refraction.prog");

		if (program)
		{
			program->Use();
			program->SetUniform("ri", ri);
		}*/

		auto program = JREngine::g_resources.Get<JREngine::Program>("shaders/postprocess/postprocess.prog");
		if (program)
		{
			program->Use();
			program->SetUniform("offset", JREngine::g_time.time);
		}

		ImGui::Begin("GUI");
		ImGui::End();

		scene->Update();

#ifdef POST_PROCESS 
		// don't draw post process actor when rendering to the framebuffer 
		{
			auto actor = scene->GetActorFromName("PostProcess");
			if (actor)
			{
				actor->SetActive(false);
			}
		}
		// render pass 1 (render scene to framebuffer) 
		JREngine::g_renderer.SetViewport(0, 0, framebuffer-> GetSize().x, framebuffer->GetSize().y);
		framebuffer->Bind();
		JREngine::g_renderer.BeginFrame();
		scene->PreRender(JREngine::g_renderer);
		scene->Render(JREngine::g_renderer);
		framebuffer->Unbind();

		// render pass 2 (render to screen) 
		JREngine::g_renderer.RestoreViewport();
		JREngine::g_renderer.BeginFrame();
		scene->PreRender(JREngine::g_renderer);

		// draw only the post process actor to the screen 
		{
			auto actor = scene->GetActorFromName("PostProcess");
			if (actor)
			{
				actor->SetActive(true);
				actor->Draw(JREngine::g_renderer);
			}
		}
#else 
		JREngine::g_renderer.BeginFrame();
		scene->PreRender(JREngine::g_renderer);
		scene->Render(JREngine::g_renderer);
#endif // POST_PROCESS 

		JREngine::g_gui.Draw();

		JREngine::g_renderer.EndFrame();
		JREngine::g_gui.EndFrame();
	}

	scene->RemoveAll();
	JREngine::Engine::Instance().Shutdown();

	return 0;
}