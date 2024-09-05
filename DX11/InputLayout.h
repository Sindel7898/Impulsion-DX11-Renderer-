#pragma once
#include"Bindable.h"
#include <iterator>
#include "PixelShader.h"


class InputLayout : public Bindable {
public:

    InputLayout(ID3D11Device* device, D3D11_INPUT_ELEMENT_DESC InputElement[], UINT ArraySize,PixelShader* PixelShader) {


       CHECK_HRESULT(device->CreateInputLayout(InputElement, ArraySize, PixelShader->SharedShaderBlob->GetBufferPointer(), PixelShader->SharedShaderBlob->GetBufferSize(), &iInputLayout));

    }

    virtual void Bind(ID3D11DeviceContext* context) override {

     context->IASetInputLayout(iInputLayout.Get());
    }

private:

    Microsoft::WRL::ComPtr<ID3D11InputLayout> iInputLayout;

};