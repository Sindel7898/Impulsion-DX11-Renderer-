#include "ShadowMap.h"

ShadowMap::ShadowMap(ID3D11Device* device, UINT width, UINT height)
    : mWidth(width), mHeight(height) {


    // Create depth texture
    D3D11_TEXTURE2D_DESC shadowMapDesc = {};
    ZeroMemory(&shadowMapDesc, sizeof(D3D11_TEXTURE2D_DESC));
    shadowMapDesc.Format = DXGI_FORMAT_R24G8_TYPELESS;
    shadowMapDesc.MipLevels = 1;
    shadowMapDesc.ArraySize = 1;
    shadowMapDesc.SampleDesc.Count = 1;
    shadowMapDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL | D3D11_BIND_SHADER_RESOURCE;
    shadowMapDesc.Width = mWidth;
    shadowMapDesc.Height = mHeight;

    device->CreateTexture2D(&shadowMapDesc, nullptr, &ShadowMapTexture);

    // Create depth stencil view
    D3D11_DEPTH_STENCIL_VIEW_DESC DepthStencilViewDesc = {};
    ZeroMemory(&shadowMapDesc, sizeof(D3D11_TEXTURE2D_DESC));
    DepthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    DepthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
    DepthStencilViewDesc.Texture2D.MipSlice = 0;

    device->CreateDepthStencilView(ShadowMapTexture.Get(), &DepthStencilViewDesc, &DepthStencilView);

    D3D11_SHADER_RESOURCE_VIEW_DESC shaderResourceViewDesc;
    ZeroMemory(&shaderResourceViewDesc, sizeof(D3D11_SHADER_RESOURCE_VIEW_DESC));
    shaderResourceViewDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
    shaderResourceViewDesc.Format = DXGI_FORMAT_R24_UNORM_X8_TYPELESS;
    shaderResourceViewDesc.Texture2D.MipLevels = 1;

    device->CreateShaderResourceView(ShadowMapTexture.Get(), &shaderResourceViewDesc, &ShadowMapView);


    D3D11_SAMPLER_DESC comparisonSamplerDesc;
    ZeroMemory(&comparisonSamplerDesc, sizeof(D3D11_SAMPLER_DESC));
    comparisonSamplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_BORDER;
    comparisonSamplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_BORDER;
    comparisonSamplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_BORDER;
    comparisonSamplerDesc.BorderColor[0] = 1.0f;
    comparisonSamplerDesc.BorderColor[1] = 1.0f;
    comparisonSamplerDesc.BorderColor[2] = 1.0f;
    comparisonSamplerDesc.BorderColor[3] = 1.0f;
    comparisonSamplerDesc.MinLOD = 0.f;
    comparisonSamplerDesc.MaxLOD = D3D11_FLOAT32_MAX;
    comparisonSamplerDesc.MipLODBias = 0.f;
    comparisonSamplerDesc.MaxAnisotropy = 0;
    comparisonSamplerDesc.ComparisonFunc = D3D11_COMPARISON_LESS_EQUAL;
    comparisonSamplerDesc.Filter = D3D11_FILTER_COMPARISON_MIN_MAG_MIP_POINT;

    // Point filtered shadows can be faster, and may be a good choice when
    // rendering on hardware with lower feature levels. This sample has a
    // UI option to enable/disable filtering so you can see the difference
    // in quality and speed.
    device->CreateSamplerState(&comparisonSamplerDesc, &SamplerState);

};

 void ShadowMap::SwitchtoNormalRenderState(ID3D11Device* device, ID3D11DeviceContext* context)
 {
     D3D11_RASTERIZER_DESC drawingRenderStateDesc;
     ZeroMemory(&drawingRenderStateDesc, sizeof(D3D11_RASTERIZER_DESC));
     drawingRenderStateDesc.FillMode = D3D11_FILL_SOLID;      // Render filled triangles
     drawingRenderStateDesc.CullMode = D3D11_CULL_BACK;       // Cull back-facing triangles
     drawingRenderStateDesc.FrontCounterClockwise = FALSE;    // Use clockwise winding order for front faces
     drawingRenderStateDesc.DepthClipEnable = TRUE;           // Enable depth clippingure level 9_1 requires DepthClipEnable == true
    
     device->CreateRasterizerState(&drawingRenderStateDesc,&NormalRenderState);
     context->RSSetState(NormalRenderState.Get());

 }

 void ShadowMap::SwitchtoShadowRenderState(ID3D11Device* device, ID3D11DeviceContext* context)
 {
     D3D11_RASTERIZER_DESC shadowRenderStateDesc;
     ZeroMemory(&shadowRenderStateDesc, sizeof(D3D11_RASTERIZER_DESC));
     shadowRenderStateDesc.CullMode = D3D11_CULL_FRONT;
     shadowRenderStateDesc.FillMode = D3D11_FILL_SOLID;
     shadowRenderStateDesc.DepthClipEnable = true;

     device->CreateRasterizerState(&shadowRenderStateDesc,&ShadowRenderState);
     context->RSSetState(NormalRenderState.Get());

 }





