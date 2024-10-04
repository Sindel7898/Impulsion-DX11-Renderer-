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
#include <WICTextureLoader.h>
#include <iostream>
#include"Camera.h"
#include "Light.h"

class CubeDrawable : public Drawable {

public:
    CubeDrawable(ID3D11Device* device, ID3D11DeviceContext* d3dDeviceContext, Window* windowContextHolder, DirectX::XMFLOAT3 location,Light* lightRef);


    void Update();

    virtual void Draw() override;


    DirectX::XMFLOAT3 Location;
    DirectX::XMFLOAT3 Scaling = { 30.0f,1.0f,30.0f };
    DirectX::XMFLOAT3 Rotation = { 0.0f,0.0f,00.0f };





    struct LightData {

        DirectX::XMFLOAT3A  LightPosition;
        DirectX::XMFLOAT4 LightColor;
        //Attenuition
        float constantAtt;
        float linearAtt; 
        float quadraticAtt; 
    };



    float constantAtt = 1.0f; // Constant attenuation (base)
    float linearAtt = 0.1f;   // Linear attenuation factor
    float quadraticAtt = 0.01f; // Quadratic attenuation factor

    std::shared_ptr<ConstantBuffer<DirectX::XMMATRIX>> Matrix;

    std::shared_ptr<ConstantBuffer<LightData>> LightBuffer;


private: 

    Light* LightRef;

    ID3D11Device* Device;
    ID3D11DeviceContext* D3DDeviceContext;
    Window* WindowContextHolder;


};
