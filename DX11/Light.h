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
    Light(ID3D11Device* device, ID3D11DeviceContext* D3DDeviceContext, Window* windowContext, DirectX::XMFLOAT3A location,int lightNumber);

    void Update();
    virtual void Draw() override;



   FORCEINLINE DirectX::XMFLOAT3A GetLocation()  { return Location; }
   FORCEINLINE DirectX::XMFLOAT3A GetDirection() { return Direction; }
   FORCEINLINE  DirectX::XMFLOAT4A GetColor() const { return BaseColor; }
   FORCEINLINE  DirectX::XMFLOAT2A GetConeDetails() const { return ConeDetails; }
   FORCEINLINE  DirectX::XMFLOAT2A GetLightType() const { return LightType; }



   FORCEINLINE DirectX::XMFLOAT3A  GetAttenuition() { return Attenuition; }

   
private:

    DirectX::XMFLOAT3A Location;
    DirectX::XMFLOAT3A Direction{ 0.0f,-1.0f,0.0f };
    DirectX::XMFLOAT4A BaseColor = { 1.0f,1.0f,1.0f,1.0f };
    DirectX::XMFLOAT2A ConeDetails = { 30.0f,50.0f };
    DirectX::XMFLOAT3A Attenuition{ 0.5f,0.125f,0.0f };
    int  LightNumber;
    std::shared_ptr<ConstantBuffer<DirectX::XMMATRIX>> transformationConstantBuffer;

    std::shared_ptr<ConstantBuffer<DirectX::XMFLOAT4>> LightConstantBuffer;
    
    DirectX::XMFLOAT2A LightType{ 0.0f,0.0f };

    ID3D11Device* Device;
    ID3D11DeviceContext* D3DDeviceContext;
    Window* WindowContextHolder;

   
};
