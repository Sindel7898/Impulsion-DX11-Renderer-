#pragma once
#include "Bindable.h"


class VertexBuffer : public Bindable {

	VertexBuffer(float VertexData, ID3D11Device * Device) {


        D3D11_BUFFER_DESC TriangleBufferData = {}; 
        TriangleBufferData.ByteWidth = sizeof(VertexData);
        TriangleBufferData.Usage = D3D11_USAGE_DEFAULT;
        TriangleBufferData.BindFlags = D3D11_BIND_VERTEX_BUFFER;
        TriangleBufferData.CPUAccessFlags = 0;
        TriangleBufferData.MiscFlags = 0;

        /// Keep an EYE on this
        TriangleBufferData.StructureByteStride = sizeof(VertexData);

        D3D11_SUBRESOURCE_DATA TriangleSubSurfaceData = {};
        TriangleSubSurfaceData.pSysMem = &VertexData;

        //Create Vertex Buffer
        Device->CreateBuffer(&TriangleBufferData, &TriangleSubSurfaceData, &vVertexBuffer);




	}

	void Bind(ID3D11DeviceContext* context) override{

        /// Keep an EYE on this
        UINT Stride = sizeof(float)*3;
        UINT Offset = 0;

        context->IASetVertexBuffers(0, 1, vVertexBuffer.GetAddressOf(), &Stride, &Offset);
    }


private:

    Microsoft::WRL::ComPtr<ID3D11Buffer> vVertexBuffer;

};