#pragma once
#include "Renderer.h" 
#include "VertexBuffer.h" 
#include "Math/MathUtils.h" 

#include <assimp/Importer.hpp>
#include <assimp/scene.h> 
#include <assimp/postprocess.h> 

namespace JREngine
{
	class Model : public Resource
	{
	public:
		struct vertex_t
		{
			glm::vec3 position;
			glm::vec2 texcoord;
			glm::vec3 normal;
			glm::vec3 tangent;
		};

	public:
		bool Create(std::string filename, ...) override;

	private:
		void ProcessNode(aiNode* node, const aiScene* scene);
		void ProcessMesh(aiMesh* mesh, const aiScene* scene);

	public:
		VertexBuffer m_vertexBuffer;
	};
}

//#include "Renderer.h"
//#include "Resource/Resource.h"
//#include <vector>
//#include <string>
//
//namespace JREngine
//{
//	class Model : public Resource
//	{
//	public:
//		Model() = default;
//		Model(const std::vector<JREngine::Vector2>& points, const JREngine::Color& color) :
//			m_points{points},
//			m_color{color}
//		{}
//		Model(const std::string& filename);
//
//		bool Create(const std::string filename, ...) override;
//
//		void Draw(Renderer& renderer, const Vector2& position, float angle, const Vector2& scale = Vector2{ 1, 1 });
//		void Draw(Renderer& renderer, const Transform& transform);
//
//		bool Load(const std::string& filename);
//		float CalculateRadius();
//
//		float GetRadius() { return m_radius; }
//
//	private:
//		JREngine::Color m_color;
//		std::vector<JREngine::Vector2> m_points;
//
//		float m_radius = 0;
//	};
//}