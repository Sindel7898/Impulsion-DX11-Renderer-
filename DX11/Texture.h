#pragma once
#include"Bindable.h"
#include "string"
#include <WICTextureLoader.h>


class Texture : public Bindable {

public:

    Texture(ID3D11Device* device, ID3D11DeviceContext* DeviceContext, int slot, const wchar_t* FileName) :Slot(slot) {

        DirectX::CreateWICTextureFromFile(device, DeviceContext, FileName, &texture, &textureView);

        D3D11_SAMPLER_DESC samplerDesc = {};

        samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR; // Linear filtering
        samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;    // Wrap mode for U
        samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;    // Wrap mode for V
        samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;    // Wrap mode for W
        samplerDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
        samplerDesc.MinLOD = 0;
        samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;
        samplerDesc.MipLODBias = 0;
        samplerDesc.MaxAnisotropy = 1;


        device->CreateSamplerState(&samplerDesc, &samplerState);
      
    }

    virtual void Bind(ID3D11DeviceContext* context) override {

        context->PSSetSamplers(Slot, 1, &samplerState);
        context->PSSetShaderResources(Slot, 1, &textureView);

    }

    virtual void Update(ID3D11DeviceContext* context) {

      
    }


private:


    ID3D11Resource* texture = nullptr;

    ID3D11ShaderResourceView* textureView = nullptr;

    ID3D11SamplerState* samplerState = nullptr;

    int Slot;
};