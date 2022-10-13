#include "Engine.h"
#include <iostream>

//format
float points[] = {
  -0.5f, -0.5f,  0.0f,
  -0.5f,  0.5f,  0.0f,
   0.5f,  0.5f,  0.0f,
   0.5f, -0.5f,  0.0f,
  -0.5f, -0.5f,  0.0f,
   0.5f,  0.5f,  0.0f
};

//glm::vec3 colors[] = {
//	{1,0,0},
//	{0,1,0},
//	{0,0,1},
//	{0,1,1},
//	{1,0,1},
//	{1,1,1}
//};

/*glm::vec2 texCoords[]{
	{0, 0},
	{0, 1),
	{1, 0},
	{0, 1},
	{1, 1},
	{1, 0}
}
*/

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
	LOG("Application started...");
	JREngine::InitializeMemory();
	JREngine::SetFilePath("../Assets");

	JREngine::Engine::Instance().Initialize();
	JREngine::Engine::Instance().Register();
	LOG("Engine initialized...");

	JREngine::g_renderer.CreateWindow("Game", 800, 600);
	LOG("Window created...");

	//pos
	GLuint pvbo = 0;
	glGenBuffers(1, &pvbo);
	glBindBuffer(GL_ARRAY_BUFFER, pvbo);
	glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(float), points, GL_STATIC_DRAW);
	//color
	GLuint cvbo = 0;
	glGenBuffers(1, &cvbo);
	glBindBuffer(GL_ARRAY_BUFFER, cvbo);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(glm::vec3), colors, GL_STATIC_DRAW);

	GLuint tvbo = 0;
	glGenBuffers(1, &tvbo);
	glBindBuffer(GL_ARRAY_BUFFER, tvbo);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(glm::vec2), colors, GL_STATIC_DRAW);

	//vertex array
	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, pvbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, cvbo);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, tvbo);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, NULL);

	std::shared_ptr<JREngine::Shader> vs = JREngine::g_resources.Get<JREngine::Shader>("Shaders/basic.vert", GL_VERTEX_SHADER);
	std::shared_ptr<JREngine::Shader> fs = JREngine::g_resources.Get<JREngine::Shader>("Shaders/basic.frag", GL_FRAGMENT_SHADER);

	GLuint program = glCreateProgram();

	glAttachShader(program, fs->m_shader);
	glAttachShader(program, vs->m_shader);
	glLinkProgram(program);
	glUseProgram(program);


	//other gl stuff but
	// create uniform2 for the tint
	// uniform 3 is transform
	GLint uniform1 = glGetUniformLocation(program, "scale");
	GLint uniform2 = glGetUniformLocation(program, "tint");
	GLint uniform3 = glGetUniformLocation(program, "transformation");

	glUniform3f(uniform2, 1, 1, 1);

	//glm::mat4 mx{ 1 };
	////mx = glm::scale(glm::vec3{0.5, 0.5, 0.5});
	//mx - glm::eulerAngleXYZ;
	//glUniformMatrix4fv(uniform3, 1, GL_FALSE, glm::value_ptr(mx));

	bool quit = false;
	while (!quit) {
		JREngine::Engine::Instance().Update();

		if (JREngine::g_inputSystem.GetKeyState(JREngine::key_escape) == JREngine::InputSystem::KeyState::Pressed) {
			quit = true;
		}
		
		glUniform1f(uniform1, 0.8f);

		JREngine::g_renderer.BeginFrame();

		glDrawArrays(GL_TRIANGLES, 0, 6);

		JREngine::g_renderer.EndFrame();
	}

	JREngine::Engine::Instance().Shutdown();
	return 0;
}