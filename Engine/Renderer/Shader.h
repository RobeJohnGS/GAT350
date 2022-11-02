#pragma once
#include "Resource/Resource.h"
#include "Renderer.h"

namespace JREngine
{
	class Shader : public Resource
	{
	public:
		~Shader();

		virtual bool Create(const std::string filename, ...) override;

	public:
		GLuint m_shader = 0;
	};
}