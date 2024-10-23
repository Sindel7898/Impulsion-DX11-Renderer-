#pragma once

#include "assimp\Importer.hpp"      // C++ importer interface
#include "assimp\scene.h"           // Output data structure
#include "assimp\postprocess.h"     // Post processing flags
#include <vector>
#include <DirectXMath.h>

class MeshLoader
{
public:
    struct ModelVertex {

        DirectX::XMFLOAT3A vert;
        DirectX::XMFLOAT3A norm;
        DirectX::XMFLOAT2A text;
        DirectX::XMFLOAT3A tangent;     // Tangent vector
        DirectX::XMFLOAT3A bitangent;   // Bitangent vector

    };

    void LoadModel(const std::string& pFile);
    void ProcessNode(aiNode* node, const aiScene* scene);
    void ProcessMesh(aiMesh* mesh, const aiScene* scene);

     std::vector<ModelVertex>& GetVertices() ;
     std::vector<unsigned int>& GetIndices();

    std::vector<ModelVertex> vertices;
    std::vector<unsigned int> indices;
private:
    Assimp::Importer importer;

  
};
