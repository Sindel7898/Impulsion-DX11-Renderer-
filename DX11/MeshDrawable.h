#pragma once
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
#include "MeshLoader.h"

class MeshDrawable : public Drawable,public MeshLoader {

public:

    MeshDrawable(ID3D11Device* device, ID3D11DeviceContext* d3dDeviceContext, Window* windowContextHolder, DirectX::XMFLOAT3 location);

    void Update(std::vector<std::shared_ptr<Light>>& Lights);

    virtual void Draw() override;



    DirectX::XMFLOAT3 Location{ 0.0f,10.0f,0.0f };
    DirectX::XMFLOAT3 Scaling = { 18.0f,15.0f,15.0f };
    DirectX::XMFLOAT3 Rotation = { 0.0f,0.0f,00.0f };
    float ModelEmision = 1;;


    struct VERTEXDATA {
        DirectX::XMMATRIX  WorldMatrix;
        DirectX::XMMATRIX  ProjectionMatrix;
        DirectX::XMMATRIX  ViewMatrix;
        DirectX::XMFLOAT3 CameraPosition;
        float ModelEmision;
    };


    struct LightData {

        DirectX::XMFLOAT3A  LightPosition;
        DirectX::XMFLOAT3A  LightDirection;
        DirectX::XMFLOAT4A LightColor;
        DirectX::XMFLOAT2A ConeParams;
        DirectX::XMFLOAT3A Attenuition;
        DirectX::XMFLOAT2A LightType;
    };

    DirectX::XMFLOAT2A  NumOFLights;


    float constantAtt = 1.0f; // Constant attenuation (base)
    float linearAtt = 0.1f;   // Linear attenuation factor
    float quadraticAtt = 0.01f; // Quadratic attenuation factor

    std::shared_ptr<ConstantBuffer<VERTEXDATA>> Matrix;

    std::shared_ptr<ConstantBuffer<LightData>> LightBuffer;


private:


    std::vector<std::shared_ptr<Light>> FaulseLights;


    ID3D11Device* Device;
    ID3D11DeviceContext* D3DDeviceContext;
    Window* WindowContextHolder1;
};
