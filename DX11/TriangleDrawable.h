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

class TriangleDrawable : public Drawable {

public:
    TriangleDrawable(ID3D11Device* device, ID3D11DeviceContext* D3DDeviceContext, Window* windowContextHolder, float locationX,float locationY,float locationZ);

    virtual void Draw(ID3D11DeviceContext* context, ID3D11Device* device , Window* windowApp) override;
    virtual void Update(ID3D11DeviceContext* context, ID3D11Device* device, Window* windowApp, float updateRotation);


    float LocationX;
    float LocationY;
    float LocationZ;

    std::shared_ptr<ConstantBuffer<DirectX::XMMATRIX>> transformationConstantBuffer;



};
