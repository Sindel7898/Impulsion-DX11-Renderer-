#pragma once
#include"Bindable.h"
#include "string"

template<typename T>

class ConstantBuffer : public Bindable {
  
public:

    ConstantBuffer(ID3D11Device* device, std::vector<T> cbData, std::string ShaderToBind, UINT startslot) {
        HoldShaderToBindText = ShaderToBind;
        Startslot = startslot;
      

        D3D11_BUFFER_DESC ConstBufferDesc = {};
        ConstBufferDesc.ByteWidth = sizeof(T) * cbData.size();;
        ConstBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
        ConstBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
        ConstBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
        ConstBufferDesc.MiscFlags = 0;
        ConstBufferDesc.StructureByteStride = sizeof(T);

        D3D11_SUBRESOURCE_DATA ConstBufferSubSurfaceData = {};
        ConstBufferSubSurfaceData.pSysMem = cbData.data();

        CHECK_HRESULT(device->CreateBuffer(&ConstBufferDesc, &ConstBufferSubSurfaceData, &cConstantBuffer));

    }

    virtual void Bind(ID3D11DeviceContext* context) override {

        if (HoldShaderToBindText == "Vertex") {

            context->VSSetConstantBuffers(Startslot, 1, cConstantBuffer.GetAddressOf());
        }
        else if(HoldShaderToBindText == "Pixel")
        {
            context->PSSetConstantBuffers(Startslot, 1, cConstantBuffer.GetAddressOf());

        }

    }
    
    virtual void Update(ID3D11DeviceContext* context, const std::vector<T>& data)  {

        if (cConstantBuffer != nullptr) {
            
            D3D11_MAPPED_SUBRESOURCE mappedResource{};
           
            context->Map(cConstantBuffer.Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
        
            memcpy(mappedResource.pData, data.data(), sizeof(T) * data.size());

            context->Unmap(cConstantBuffer.Get(), 0);
        }
    }


private:

    string HoldShaderToBindText;

    Microsoft::WRL::ComPtr<ID3D11Buffer> cConstantBuffer;
    UINT Startslot;
};