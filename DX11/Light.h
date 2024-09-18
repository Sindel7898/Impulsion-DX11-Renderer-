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

class Light : public Drawable {

public:
    Light(ID3D11Device* device, ID3D11DeviceContext* D3DDeviceContext, Window* windowContextHolder, DirectX::XMFLOAT3A location);

    virtual void Draw(ID3D11DeviceContext* context, ID3D11Device* device, Window* windowApp) override;
    virtual void Update(ID3D11DeviceContext* context, ID3D11Device* device, Window* windowApp, float updateRotation);




   FORCEINLINE DirectX::XMFLOAT3A GetLocation()  { return Location; }
   FORCEINLINE  DirectX::XMFLOAT4 GetColor() const { return BaseColor; }


private:
    DirectX::XMFLOAT3A Location;
    DirectX::XMFLOAT4 BaseColor = { 1.0f,0.0f,1.0f,1.0f };

   
    std::shared_ptr<ConstantBuffer<DirectX::XMMATRIX>> transformationConstantBuffer;
    

    Window* windowContextHolderHolder;
    

   
};
