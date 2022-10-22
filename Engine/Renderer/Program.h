#pragma once

#include "Resource/Resource.h"
#include "Renderer.h"
#include "Math/MathUtils.h"
#include <map>
#include <vector>

namespace JREngine {
	class Shader;

	class Program : public Resource {
	public:
		~Program();
		// Inherited via Resource
		virtual bool Create(std::string name, ...) override;
		void AddShader(const std::shared_ptr<Shader>& shader);

		void Link();
		void Use();

		void SetUniform(const std::string& name, float value);
		void SetUniform(const std::string& name, const glm::vec3& value);
		void SetUniform(const std::string& name, const glm::mat4& value);

		void SetUniform(const std::string& name, int value);
		void SetUniform(const std::string& name, unsigned int value);
		void SetUniform(const std::string& name, bool value);

		void SetUniform(const std::string& name, const glm::vec2& value);
		void SetUniform(const std::string& name, const glm::vec4& value);

		void SetUniform(const std::string& name, const glm::mat3& value);

		//variables

		GLuint m_program = 0;
		std::vector<std::shared_ptr<Shader>> m_shaders;
		std::map<std::string, GLint> m_uniforms;

	private:
		GLint GetUniform(const std::string& name);

	};
}