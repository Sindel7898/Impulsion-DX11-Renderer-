#pragma once
#include"Bindable.h"

class IndexBuffer : public Bindable {

	IndexBuffer(ID3D11Device* device , unsigned short Indices[] , float Vertex) {



        D3D11_BUFFER_DESC IndexBufferDesc = {};
        IndexBufferDesc.ByteWidth = sizeof(Indices);
        IndexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
        IndexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
        IndexBufferDesc.CPUAccessFlags = 0;
        IndexBufferDesc.MiscFlags = 0;
        IndexBufferDesc.StructureByteStride = sizeof(Vertex);

        D3D11_SUBRESOURCE_DATA INDEXsURF = {};
        INDEXsURF.pSysMem = Indices;

        device->CreateBuffer(&IndexBufferDesc, &INDEXsURF, &iIndexBuffer);

	}

	virtual void Bind(ID3D11DeviceContext* context) override {

        context->IASetIndexBuffer(iIndexBuffer.Get(), DXGI_FORMAT_R16_UINT, 0);
    }
	
private:

    Microsoft::WRL::ComPtr<ID3D11Buffer> iIndexBuffer;

};