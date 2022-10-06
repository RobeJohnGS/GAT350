#include "Engine.h"
#include <iostream>

int main(int argc, char** argv)
{
	JREngine::InitializeMemory();

	JREngine::Engine::Instance().Initialize();
	JREngine::Engine::Instance().Register();

	JREngine::g_renderer.CreateWindow("Game", 800, 600);

	bool quit = false;
	while (!quit) {
		JREngine::Engine::Instance().Update();

		if (JREngine::g_inputSystem.GetKeyState(JREngine::key_escape) == JREngine::InputSystem::KeyState::Pressed) {
			quit = true;
		}

		JREngine::g_renderer.BeginFrame();
		JREngine::g_renderer.EndFrame();
	}

	JREngine::Engine::Instance().Shutdown();
}