// VertexShader.h
#pragma once
#include "Bindable.h"
#include <d3dcompiler.h>
#include <string>


class PixelShader : public Bindable {
public:

    PixelShader(ID3D11Device* device, const std::wstring& ShaderName, Microsoft::WRL::ComPtr<ID3DBlob> SharedShderBlob) {

        Microsoft::WRL::ComPtr<ID3DBlob> ErrorBlob = nullptr;

        D3DCompileFromFile(L"ShaderName", nullptr, nullptr, "main", "ps_5_0", 0, 0, &SharedShderBlob, &ErrorBlob);

        device->CreatePixelShader(SharedShderBlob->GetBufferPointer(), SharedShderBlob->GetBufferSize(), NULL, &pPixelShader);

    }

    void Bind(ID3D11DeviceContext* context) override {

        context->PSSetShader(pPixelShader.Get(), nullptr, 0);

    }

private:
    Microsoft::WRL::ComPtr<ID3D11PixelShader> pPixelShader;
};
