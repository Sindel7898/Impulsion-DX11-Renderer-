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
    Light(ID3D11Device* device, ID3D11DeviceContext* D3DDeviceContext, Window* windowContext, DirectX::XMFLOAT3A location);

    void Update();
    virtual void Draw() override;



   FORCEINLINE DirectX::XMFLOAT3A GetLocation()  { return Location; }
   FORCEINLINE  DirectX::XMFLOAT4 GetColor() const { return BaseColor; }

   FORCEINLINE float GetconstantAtt() { return constantAtt; }
   FORCEINLINE float GetlinearAtt() { return linearAtt; }
   FORCEINLINE float GetquadraticAtt() { return quadraticAtt; }

   
private:
    DirectX::XMFLOAT3A Location;
    DirectX::XMFLOAT4 BaseColor = { 1.0f,1.0f,1.0f,1.0f };

    float constantAtt = 1.0f;
    float linearAtt = 0.1f;  
    float quadraticAtt = 0.01f; 

    std::shared_ptr<ConstantBuffer<DirectX::XMMATRIX>> transformationConstantBuffer;
    
    std::shared_ptr<ConstantBuffer<DirectX::XMFLOAT4>> LightConstantBuffer;

   
    ID3D11Device* Device;
    ID3D11DeviceContext* D3DDeviceContext;
    Window* WindowContextHolder;

   
};
