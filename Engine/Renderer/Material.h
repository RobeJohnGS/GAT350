#pragma once
#include "Resource/Resource.h"
#include "Math/MathUtils.h"
#include <vector>
#include <memory>

namespace JREngine {
	class Texture;
	class Program;

	class Material : public Resource {
	public:
		

		// Inherited via Resource
		virtual bool Create(std::string name, ...) override;

		void Bind();
		std::shared_ptr<Program> GetProgram() {
			return m_program;
		}

		//variables
		glm::vec3 ambient;
		glm::vec3 diffuse;
		glm::vec3 specular;
		float shininess = 0;

	private:
		std::shared_ptr<Program> m_program;
		std::vector<std::shared_ptr<Texture>> m_textures;
	};
}