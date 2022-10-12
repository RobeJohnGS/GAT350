#include "Shader.h"
#include "Core/File.h"
#include "Core/Logger.h"

namespace JREngine {
	Shader::~Shader()
	{
		if (m_shader != 0) {
			glDeleteShader(m_shader);
		}
	}

	bool Shader::Create(std::string filename, ...)
	{
		std::string source;
		bool success = ReadFile(filename, source);
		if (!success) {
			//log
		}

		va_list args;
		va_start(args, filename);
		GLuint shaderType = va_arg(args, GLuint);
		va_end(args);

		m_shader = glCreateShader(shaderType);

		const char* source_c = source.c_str();
		glShaderSource(m_shader, 1, &source_c, NULL);
		glCompileShader(m_shader);

		GLint status;
		glGetShaderiv(m_shader, GL_COMPILE_STATUS, &status);
		if (status == GL_FALSE) {
			GLint length = 0;
			glGetShaderiv(m_shader, GL_INFO_LOG_LENGTH, &length);

			if (length > 0) {
				std::string infolog(length, ' ');
				glGetShaderInfoLog(m_shader, length, &length, &infolog[0]);
				LOG("failed to compile shader %s.", filename.c_str());
				LOG("shader info: %s", infolog.c_str());
			}

			// delete shader
			glDeleteShader(m_shader);
			m_shader = 0;
		}
		return true;
	}
}