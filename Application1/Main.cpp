#include "Engine.h"
#include <vector>
#include <iostream>
//John Roberts GAT-350

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
	JREngine::g_GUI.Initialize(JREngine::g_renderer);

	//create frame buffer texture
	auto texture = std::make_shared<JREngine::Texture>();
	texture->CreateTexture(512, 512);
	JREngine::g_resources.Add<JREngine::Texture>("fb_texture", texture);

	//create frame buffer
	auto framebuffer = JREngine::g_resources.Get<JREngine::Framebuffer>("framebuffer", "fb_texture");
	framebuffer->Unbind();

	// load scene 
	auto scene = JREngine::g_resources.Get<JREngine::Scene>("Scenes/rtt.scn");

	float x = 0;
	glm::vec3 rot{ 0, 0, 0 };

	bool quit = false;
	float ri = 1;
	while (!quit)
	{
		JREngine::Engine::Instance().Update();

		


		JREngine::g_GUI.BeginFrame(JREngine::g_renderer);

		if (JREngine::g_inputSystem.GetKeyState(JREngine::key_escape) == JREngine::InputSystem::State::Pressed) quit = true;

		auto actor = scene->GetActorFromName("Squirrel");

		//actor = scene->GetActorFromName("Light");
		if (actor)
		{
			actor->m_transform.rotation = math::EulerToQuaternion(rot);
		}

		auto program = JREngine::g_resources.Get<JREngine::Program>("Shaders/fx/refraction.prog");
		if (program) {
			program->Use();
			program->SetUniform("ri", ri);
		}

		ImGui::Begin("hello");
		ImGui::DragFloat3("Rotation", &rot[0]);
		ImGui::DragFloat("Refraction", &ri, 0.01f, 0, 1.5f);
		ImGui::End();

		scene->Update();
		//render pass 1
		glViewport(0, 0, 512, 512);
		framebuffer->Bind();
		JREngine::g_renderer.BeginFrame();

		scene->PreRender(JREngine::g_renderer);
		scene->Render(JREngine::g_renderer);
		framebuffer->Unbind();

		//render pass 2
		glViewport(0, 0, 800, 600);
		JREngine::g_renderer.BeginFrame();

		scene->PreRender(JREngine::g_renderer);
		scene->Render(JREngine::g_renderer);

		JREngine::g_GUI.Draw();

		JREngine::g_renderer.EndFrame();
		JREngine::g_GUI.EndFrame();
	}

	scene->RemoveAll();
	JREngine::Engine::Instance().Shutdown();

	return 0;
}