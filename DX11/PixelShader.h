#pragma once
#include "Bindable.h"
#include <d3dcompiler.h>
#include <string>

class VertexShader;
class InputLayout;

class PixelShader : public Bindable {
public:

    PixelShader(ID3D11Device* device, LPCWSTR ShaderName) {

        Microsoft::WRL::ComPtr<ID3DBlob> ErrorBlob = nullptr;

        CHECK_HRESULT(D3DCompileFromFile(ShaderName, nullptr, nullptr, "main", "ps_5_0", 0, 0, &SharedShaderBlob, &ErrorBlob));

        CHECK_HRESULT(device->CreatePixelShader(SharedShaderBlob->GetBufferPointer(), SharedShaderBlob->GetBufferSize(), NULL, &pPixelShader));

    }

    void Bind(ID3D11DeviceContext* context) override {

        context->PSSetShader(pPixelShader.Get(), nullptr, 0);

    }

    friend class VertexShader;
    friend class InputLayout;

private:

    Microsoft::WRL::ComPtr<ID3DBlob> SharedShaderBlob;
    Microsoft::WRL::ComPtr<ID3D11PixelShader> pPixelShader;
};
