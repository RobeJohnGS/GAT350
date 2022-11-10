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

	// load scene 
	auto scene = JREngine::g_resources.Get<JREngine::Scene>("Scenes/texture.scn");

	bool quit = false;
	while (!quit)
	{
		JREngine::Engine::Instance().Update();

		if (JREngine::g_inputSystem.GetKeyState(JREngine::key_escape) == JREngine::InputSystem::State::Pressed) quit = true;

		auto actor = scene->GetActorFromName("Ogre");

		actor = scene->GetActorFromName("Light");
		if (actor)
		{
			//actor->m_transform.position.x = std::sin(JREngine::g_time.time);
		}

		scene->Update();

		JREngine::g_renderer.BeginFrame();

		scene->Draw(JREngine::g_renderer);

		JREngine::g_renderer.EndFrame();
	}

	scene->RemoveAll();
	JREngine::Engine::Instance().Shutdown();

	return 0;
}