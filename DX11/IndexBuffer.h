#pragma once
#include"Bindable.h"
#include <iostream>
using namespace std;



class IndexBuffer : public Bindable {
public:
	IndexBuffer(ID3D11Device* device , std::vector<int> CubeIndex) {


        D3D11_BUFFER_DESC IndexBufferDesc = {};
        IndexBufferDesc.ByteWidth = static_cast<UINT>(sizeof(int) * CubeIndex.size());
        IndexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
        IndexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
        IndexBufferDesc.CPUAccessFlags = 0;
        IndexBufferDesc.MiscFlags = 0;

        D3D11_SUBRESOURCE_DATA INDEXsURF = {};
        INDEXsURF.pSysMem = CubeIndex.data();

        CHECK_HRESULT(device->CreateBuffer(&IndexBufferDesc, &INDEXsURF, &iIndexBuffer));

       
	}

	virtual void Bind(ID3D11DeviceContext* context) override {

        context->IASetIndexBuffer(iIndexBuffer.Get(), DXGI_FORMAT_R32_UINT, 0);
    }
	
private:

    Microsoft::WRL::ComPtr<ID3D11Buffer> iIndexBuffer;

};