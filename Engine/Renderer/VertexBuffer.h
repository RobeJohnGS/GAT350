#pragma once
#include "Renderer.h"
#include "Resource/Resource.h"
#include <vector>

namespace JREngine {
	class VertexBuffer : public Resource {
	public:
		VertexBuffer();


		// Inherited via Resource
		virtual bool Create(std::string name, ...) override;

		void CreateVertexBuffer(GLsizei size, GLsizei m_vertexCount, void* data);
		void SetAttribute(int index, GLint size, GLsizei stride, size_t offset);

		void CreateIndexBuffer(GLenum indextype, GLsizei count, void* data);

		virtual void Draw(GLenum primitiveType = GL_TRIANGLES);

		void Bind() { glBindVertexArray(m_vao); }

	protected:
		GLuint m_vao = 0;

		GLuint m_vbo = 0;
		GLuint m_vertexCount = 0;

		GLuint m_ibo = 0;
		GLuint m_indexCount = 0;
		GLenum m_indexType = 0;
	};
}