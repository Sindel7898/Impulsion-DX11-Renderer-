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

class CubeDrawable : public Drawable {

public:
    CubeDrawable(ID3D11Device* device, ID3D11DeviceContext* D3DDeviceContext, Window* windowContextHolder, DirectX::XMFLOAT3 location);


    void Update(ID3D11DeviceContext* context, ID3D11Device* device, Window* windowApp, float updateRotation, DirectX::XMFLOAT3A uLightPosition, DirectX::XMFLOAT4 uLightColor);

    virtual void Draw(ID3D11DeviceContext* context, ID3D11Device* device , Window* windowApp) override;


    DirectX::XMFLOAT3 Location;




    struct LightData {

        DirectX::XMFLOAT3A  LightPosition;
        DirectX::XMFLOAT4 LightColor;
    };

    std::shared_ptr<ConstantBuffer<DirectX::XMMATRIX>> Matrix;

    std::shared_ptr<ConstantBuffer<LightData>> LightBuffer;

};
