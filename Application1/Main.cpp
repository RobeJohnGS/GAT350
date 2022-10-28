#include "Engine.h" 
#include <iostream> 

float points[] = {
	/*-0.5f, -0.5f,  0.0f,
	 0.5f,  0.5f,  0.0f,
	 0.5f, -0.5f,  0.0f,
	 1.5f,  0.5f,  0.0f,
	 1.5f,  0.5f,  0.0f,
	 1.5f, -0.5f,  0.0f*/

	 /* -0.5f, -0.5f,  0.0f,
	  -0.5f,  0.5f,  0.0f,
	   0.5f,  0.5f,  0.0f,
	   0.5f, -0.5f,  0.0f,
	  -0.5f, -0.5f,  0.0f,
	   0.5f,  0.5f,  0.0f*/

		-1.0f, -1.0f, 0.0f,
		-1.0f,  1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,

		 -1.0f, 1.0f, 0.0f,
		  1.0f, 1.0f, 0.0f,
		  1.0f,-1.0f, 0.0f

};

glm::vec3 colors[] = {
	{1,0,0},
	{0,1,0},
	{0,0,1},
	{0,1,1},
	{1,0,1},
	{1,1,1}
};

glm::vec2 texcoords[] = {

	{ 0, 0 },
	{ 0, 1 },
	{ 1, 0 },
	{ 0, 1 },
	{ 1, 1 },
	{ 1, 0 }
};

float vertices[] = { // Each Group = 1 Face Of The Cube
	-0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 1.0f
};

const char* vertex_shader =
"#version 430 core\n"
"in vec3 position;"
"void main() {"
"  gl_Position = vec4(position * 1, 1.0);"
"}";

const char* fragment_shader =
"#version 430 core\n"
"out vec4 color;"
"void main() {"
"  color = vec4(2.0, 0.5, 1.0, 1.0);"
"}";

int main(int argc, char** argv)
{
	LOG("Application Started...");

	JREngine::InitializeMemory();
	JREngine::SetFilePath("../Assets");

	JREngine::Engine::Instance().Initialize();
	JREngine::Engine::Instance().Register();
	LOG("Engine Initialized...");

	JREngine::g_audioSystem.Initialize();
	LOG("Audio System Initialized...");

	JREngine::g_renderer.CreateWindow("JREnginemont", 800, 600);
	LOG("Window Initialized...");

	// load scene
	auto scene = JREngine::g_resources.Get<JREngine::Scene>("Scenes/basic.scn");

	// Create A Model
	auto m = JREngine::g_resources.Get<JREngine::Model3D>("Models/spot.obj");

	// Create Material
	std::shared_ptr<JREngine::Material> material = JREngine::g_resources.Get<JREngine::Material>("Materials/fallguy.mtrl");
	material->Bind();

	material->GetProgram()->SetUniform("scale", 0.5f);
	material->GetProgram()->SetUniform("tint", glm::vec3{ 1, 0, 0 });

	glm::mat4 model{ 1 };
	glm::mat4 projection = glm::perspective(45.0f, (float)JREngine::g_renderer.GetWidth() / (float)JREngine::g_renderer.GetHeight(), 1.0f, 100.0f);

	glm::vec3 cameraPosition = glm::vec3{ 0, 0, 2 };
	float speed = 3;

	std::vector<JREngine::Transform> t;

	for (size_t i = 0; i < 1000; i++)
	{
		t.push_back({ {JREngine::randomf(-10, 10), JREngine::randomf(-10, 10), JREngine::randomf(-10, 10)}, {JREngine::randomf(360), 90, 0} });
	}


	JREngine::Transform transforms[] =
	{
		{ {0, 0, 0}, {0, 90, 90} },
		{ {2, 0, 0}, {90, 90, 90} },
		{ {0, 2, 0}, {0, 90, 0} },
		{ {2, 2, 0}, {20, 90, 0} },
		{ {1, 0, 1}, {0, 90, 0} },
		{ {0, 1, 0}, {90, 90, 0} },
	};

	bool quit = false;
	while (!quit)
	{
		JREngine::Engine::Instance().Update();

		if (JREngine::g_inputSystem.GetKeyState(JREngine::key_escape) == JREngine::InputSystem::KeyState::Pressed) quit = true;

		scene->Update();

		glm::mat4 view = glm::lookAt(cameraPosition, cameraPosition + glm::vec3{ 0 , 0, -1 }, glm::vec3{ 0, 1, 0 });
		model = glm::eulerAngleXYZ(0.0f, JREngine::g_time.time, 0.0f);
		glm::mat4 mvp = projection * view * model;
		material->GetProgram()->SetUniform("mvp", mvp);

		JREngine::g_renderer.BeginFrame();

		scene->Draw(JREngine::g_renderer);
		m->m_vertexBuffer.Draw();

		JREngine::g_renderer.EndFrame();
	}
	scene->RemoveAll();
	JREngine::Engine::Instance().Shutdown();
	return 0;
}