#include "Material.h" 
#include "Engine.h" 

namespace JREngine
{
	bool Material::Create(std::string filename, ...)
	{
		// load program json document 
		rapidjson::Document document;
		bool success = JREngine::json::Load(filename, document);
		if (!success)
		{
			LOG("Could not load program file (%s).", filename.c_str());
			return false;
		}

		// read the program name 
		std::string program;
		READ_DATA(document, program);
		// get program resource 
		m_program = JREngine::g_resources.Get<JREngine::Program>(program);

		// read the texture name 
		std::string texture;
		READ_DATA(document, texture);
		if (!texture.empty())
		{
			// get texture resource 
			m_textures.push_back(JREngine::g_resources.Get<JREngine::Texture>(texture));
		}

		// read colors 
		READ_DATA(document, color);
		READ_DATA(document, shininess);

		READ_DATA(document, uv_tiling);
		READ_DATA(document, uv_offSet);

		return true;
	}

	void Material::Bind()
	{
		m_program->Use();
		m_program->SetUniform("material.color", color);
		m_program->SetUniform("material.shininess", shininess);
		m_program->SetUniform("material.uv_tiling", uv_tiling);
		m_program->SetUniform("material.uv_offSet", uv_offSet);

		for (auto& texture : m_textures)
		{
			texture->Bind();
		}
	}
}