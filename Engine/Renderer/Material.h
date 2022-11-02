#pragma once 
#include "Resource/Resource.h" 
#include "Math/MathUtils.h" 
#include <vector> 
#include <memory> 

namespace JREngine
{
	class Texture;
	class Program;

	class Material : public Resource
	{
	public:
		virtual bool Create(std::string filename, ...) override;

		void Bind();

		std::shared_ptr<Program> GetProgram() { return m_program; }

	public:
		glm::vec3 color;
		float shininess = 0;

		glm::vec2 uv_tiling{1, 1};
		glm::vec2 uv_offSet{1, 1};

	private:
		std::shared_ptr<Program> m_program;
		std::vector<std::shared_ptr<Texture>> m_textures;
	};
}