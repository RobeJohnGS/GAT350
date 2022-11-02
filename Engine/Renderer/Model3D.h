//#pragma once
//#include "Renderer.h"
//#include "VertexBuffer.h"
//#include "Math/MathUtils.h"
//
//#include <assimp/Importer.hpp>
//#include <assimp/scene.h>
//#include <assimp/postprocess.h>
//
//namespace JREngine {
//	class Model3D : public Resource {
//	public:
//		struct vertex_t {
//			glm::vec3 position;
//			glm::vec3 texcoord;
//		};
//
//		// Inherited via Resource
//		virtual bool Create(std::string name, ...) override;
//
//		VertexBuffer m_vertexBuffer;
//
//	private:
//		void ProcessNode(aiNode* node, const aiScene* scene);
//		void ProcessMesh(aiMesh* mesh, const aiScene* scene);
//	};
//}