#pragma once
#include "Drawable.h"
#include <d3d11.h>
#include <vector>
#include "Window.h"
#include "VertexBuffer.h"
#include "InputLayout.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include <d3dcompiler.h>
#include <wrl/client.h>
#include <DirectXMath.h>
#include "ConstantBuffer.h"
#include <iostream>
#include"Camera.h"
#include "Light.h"
#include "Texture.h"

class SkyBox : public Drawable {

public:


    SkyBox(ID3D11Device* device, ID3D11DeviceContext* d3dDeviceContext, Window* windowContextHolder);

    void Update();

    virtual void Draw() override;

    ID3D11Texture2D* LoadCubeMap(ID3D11Device* device, ID3D11DeviceContext* context, const std::vector<std::string>& faces);




    DirectX::XMFLOAT3 Location;


    struct Vertex {

        DirectX::XMFLOAT3A Position; // 3D position
        DirectX::XMFLOAT2A texCoord; // 2D texture coordinate of the vertex

    };


    std::vector<UINT> Index = {

        // Front face
       0, 1, 2, 0, 2, 3,
       // Back face
       4,6,5,4,7,6,
       // Left face
       8, 10, 9, 8, 11, 10,

       // Right face
       12, 13, 14, 12, 14, 15,
       // Top face
       16, 18, 17, 16, 19, 18,

       // Bottom face
       20, 21, 22, 20, 22, 23

    };



    struct VERTEXDATA {
        DirectX::XMMATRIX  WorldMatrix;
        DirectX::XMMATRIX  ProjectionMatrix;
        DirectX::XMMATRIX  ViewMatrix;
    };




    float constantAtt = 1.0f; // Constant attenuation (base)
    float linearAtt = 0.1f;   // Linear attenuation factor
    float quadraticAtt = 0.01f; // Quadratic attenuation factor

    std::shared_ptr<ConstantBuffer<VERTEXDATA>> Matrix;



    std::vector<SkyBox::Vertex> SphereVertex;
    std::vector<UINT> SphereIndices;
private:

    std::vector<std::shared_ptr<Light>> LightsRef;

    ID3D11Device* Device;
    ID3D11DeviceContext* D3DDeviceContext;
    Window* WindowContextHolder;





    int NumSphereVertices;
    int NumSphereFaces;
};
