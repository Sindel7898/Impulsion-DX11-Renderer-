#pragma once
#include <d3d11.h>
#include <wrl/client.h>
#include <DirectXMath.h>
#include"Bindable.h"

class ShadowMap  {
public:
    ShadowMap(ID3D11Device* device, UINT width, UINT height);
    void SwitchtoNormalRenderState(ID3D11Device* device, ID3D11DeviceContext* context);
    void SwitchtoShadowRenderState(ID3D11Device* device, ID3D11DeviceContext* context);
    ID3D11ShaderResourceView* GetShaderResourceView() { return ShadowMapView.Get(); }


    Microsoft::WRL::ComPtr<ID3D11Texture2D> ShadowMapTexture;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView> DepthStencilView;
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> ShadowMapView;
    Microsoft::WRL::ComPtr<ID3D11SamplerState> SamplerState;
    Microsoft::WRL::ComPtr<ID3D11RasterizerState> NormalRenderState;
    Microsoft::WRL::ComPtr<ID3D11RasterizerState> ShadowRenderState;


    UINT mWidth;
    UINT mHeight;
};
