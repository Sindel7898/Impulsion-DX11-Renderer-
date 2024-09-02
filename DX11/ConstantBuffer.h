#pragma once
#include"Bindable.h"

class ConstantBuffer : public Bindable {

    ConstantBuffer(ID3D11Device* device, ConstantBuffer cbData, float Vertex) {

        D3D11_BUFFER_DESC ConstBufferDesc = {};
        ConstBufferDesc.ByteWidth = sizeof(cbData);
        ConstBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
        ConstBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
        ConstBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
        ConstBufferDesc.MiscFlags = 0;
        ConstBufferDesc.StructureByteStride = sizeof(Vertex);

        D3D11_SUBRESOURCE_DATA ConstBufferSubSurfaceData = {};
        ConstBufferSubSurfaceData.pSysMem = &cbData;

        device->CreateBuffer(&ConstBufferDesc, &ConstBufferSubSurfaceData, &cConstantBuffer);

    }

    virtual void Bind(ID3D11DeviceContext* context) override {

        context->VSSetConstantBuffers(0, 1, cConstantBuffer.GetAddressOf());
    }

private:

    Microsoft::WRL::ComPtr<ID3D11Buffer> cConstantBuffer;

};