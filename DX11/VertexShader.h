// VertexShader.h
#pragma once
#include "Bindable.h"
#include <d3dcompiler.h>
#include <string>


class VertexShader : public Bindable {
public:

    VertexShader(ID3D11Device* device, const std::wstring& ShaderName, Microsoft::WRL::ComPtr<ID3DBlob> SharedShderBlob) {

        Microsoft::WRL::ComPtr<ID3DBlob>    ErrorBlob = nullptr;

        D3DCompileFromFile(L"ShaderName", nullptr, nullptr,"main", "vs_5_0",0, 0,&SharedShderBlob,&ErrorBlob);
  
        device->CreateVertexShader(SharedShderBlob->GetBufferPointer(), SharedShderBlob->GetBufferSize(), NULL, &pVertexShader);

    }

    void Bind(ID3D11DeviceContext* context) override {

        context->VSSetShader(pVertexShader.Get(), nullptr, 0);

    }

private:
    Microsoft::WRL::ComPtr<ID3D11VertexShader> pVertexShader;
};
