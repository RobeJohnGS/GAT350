#include "Material.h"
#include "Engine.h"

namespace JREngine {
    bool Material::Create(std::string name, ...){
        rapidjson::Document document;
        bool success = JREngine::json::Load(name, document);
        if (!success) {
            LOG("Could not create material (%s)", name.c_str());
            return false;
        }

        std::string program;
        READ_DATA(document, program);
        m_program = JREngine::g_resources.Get<JREngine::Program>(program);

        std::string texture;
        READ_DATA(document, texture);
        if (!texture.empty()) {
            m_textures.push_back(JREngine::g_resources.Get<JREngine::Texture>(texture));
        }

        READ_DATA(document, ambient);
        READ_DATA(document, diffuse);
        READ_DATA(document, specular);
        READ_DATA(document, shininess);
        return true;
    }

    void Material::Bind(){
        m_program->Use();
        for (auto& texture : m_textures) {
            texture->Bind();
        }
    }
}