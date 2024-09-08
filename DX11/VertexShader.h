// VertexShader.h
#pragma once
#include "Bindable.h"
#include <d3dcompiler.h>
#include <string>
#include "PixelShader.h"

class PixelShader;

class VertexShader : public Bindable {
public:

    VertexShader(ID3D11Device* device, LPCWSTR ShaderName, PixelShader* PixelShader) {

        Microsoft::WRL::ComPtr<ID3DBlob> ErrorBlob = nullptr;

        CHECK_HRESULT(D3DCompileFromFile(ShaderName, nullptr, nullptr,"VSMain", "vs_5_0",0, 0,&PixelShader->SharedShaderBlob,&ErrorBlob));
  
        CHECK_HRESULT( device->CreateVertexShader(PixelShader->SharedShaderBlob->GetBufferPointer(), PixelShader->SharedShaderBlob->GetBufferSize(), NULL, &pVertexShader));

    }

    void Bind(ID3D11DeviceContext* context) override {

        context->VSSetShader(pVertexShader.Get(), nullptr, 0);

    }

private:

    Microsoft::WRL::ComPtr<ID3D11VertexShader> pVertexShader;
};
