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

	// load scene 
	auto scene = JREngine::g_resources.Get<JREngine::Scene>("Scenes/texture.scn");

	float x = 0;
	glm::vec3 position{ 0, 0, 0 };

	bool quit = false;
	while (!quit)
	{
		JREngine::Engine::Instance().Update();

		


		JREngine::g_GUI.BeginFrame(JREngine::g_renderer);

		if (JREngine::g_inputSystem.GetKeyState(JREngine::key_escape) == JREngine::InputSystem::State::Pressed) quit = true;

		auto actor = scene->GetActorFromName("Ogre");

		actor = scene->GetActorFromName("Light");
		if (actor)
		{
			actor->m_transform.position = position;
		}

		ImGui::Begin("hello");
		ImGui::SliderFloat3("X", &position[0], -4.0f, 4.0f);
		ImGui::End();

		scene->Update();

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