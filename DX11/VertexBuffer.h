#pragma once
#include "Bindable.h"


class VertexBuffer : public Bindable {
public :
	VertexBuffer(ID3D11Device* Device, std::vector<float> VertexData) {


        D3D11_BUFFER_DESC VertexBufferDesc = {}; 
        VertexBufferDesc.ByteWidth = static_cast<UINT>( sizeof(float) * VertexData.size());

        VertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
        VertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
        VertexBufferDesc.CPUAccessFlags = 0;
        VertexBufferDesc.MiscFlags = 0;

        D3D11_SUBRESOURCE_DATA VertexBufferSubSurfaceData = {};
        VertexBufferSubSurfaceData.pSysMem = VertexData.data();


        //Create Vertex Buffer
        CHECK_HRESULT(Device->CreateBuffer(&VertexBufferDesc, &VertexBufferSubSurfaceData, &vVertexBuffer));

	}

	void Bind(ID3D11DeviceContext* context) override{

        UINT Stride = sizeof(float) * 3;
        UINT Offset = 0;

        context->IASetVertexBuffers(0, 1, vVertexBuffer.GetAddressOf(), &Stride, &Offset);
    }


private:

    Microsoft::WRL::ComPtr<ID3D11Buffer> vVertexBuffer;

};