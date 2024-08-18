#pragma once
#include <d3d11.h>
#include <dxgi1_3.h>
#include <wrl.h>
#include "Window.h"

#include <d3dcompiler.h>
#include <DirectXMath.h>
#include "comdef.h"

#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

class D3D11
{

public:

    D3D11(Window* windowApp);
    ~D3D11();

    D3D11& operator=(const D3D11&) = delete;
    D3D11(const D3D11&) = delete;

    void EndFrame();

    void ClearBuffer(float red, float green, float blue);


    void DrawTriangle() {

        struct Vertex {
            
            float x;
            float y;
            float r;
            float g;
            float b;
        
        };

        const Vertex TriangleData[] = {
            
            {0.0f,0.5f,1.0f,0.0f,0.0f},
            {0.5f,-0.5f,0.0f,1.0f,0.0f},
            {-0.5f,-0.5f,1.0f,1.0f,0.0f}

        };


        Microsoft::WRL::ComPtr<ID3D11Buffer> VertexBuffer;

        D3D11_BUFFER_DESC TriangleBufferData = {};
        TriangleBufferData.ByteWidth = sizeof(TriangleData);
        TriangleBufferData.Usage = D3D11_USAGE_DEFAULT;
        TriangleBufferData.BindFlags = D3D11_BIND_VERTEX_BUFFER;
        TriangleBufferData.CPUAccessFlags = 0;
        TriangleBufferData.MiscFlags = 0;
        TriangleBufferData.StructureByteStride = sizeof(Vertex);

        D3D11_SUBRESOURCE_DATA TriangleSubSurfaceData = {};
        TriangleSubSurfaceData.pSysMem = TriangleData;
         
        //Create Vertex Buffer
        D3DDevice->CreateBuffer(&TriangleBufferData, &TriangleSubSurfaceData, &VertexBuffer);

        UINT Stride = sizeof(Vertex);
        UINT Offset = 0;

        //set vertex buffer
        D3DDeviceContext->IASetVertexBuffers(0, 1, VertexBuffer.GetAddressOf(), &Stride, &Offset);



        Microsoft::WRL::ComPtr<ID3DBlob> triangleBlop;
        Microsoft::WRL::ComPtr<ID3DBlob> errorBlob = nullptr;

     
        
        //START OF PICEL SHADER STUFF
        Microsoft::WRL::ComPtr< ID3D11PixelShader> PixelShader;
        HRESULT hr = D3DCompileFromFile(L"PixelShader.hlsl",
            nullptr, nullptr,
            "main",
            "ps_5_0",
            0, 0,
            &triangleBlop,
            &errorBlob);

        D3DDevice->CreatePixelShader(triangleBlop->GetBufferPointer(), triangleBlop->GetBufferSize(), nullptr, &PixelShader);
        D3DDeviceContext->PSSetShader(PixelShader.Get(), nullptr, 0);
        //END OF PIXEL SHADER STUFF


        //START OF VERTEX SHADER STUFF
        Microsoft::WRL::ComPtr<ID3D11VertexShader> trianglevertexshader;

        D3DCompileFromFile(L"VertexShader.hlsl",
            nullptr, nullptr,
            "main",
            "vs_5_0",
            0, 0,
            &triangleBlop,
            &errorBlob);

        D3DDevice->CreateVertexShader(triangleBlop->GetBufferPointer(), triangleBlop->GetBufferSize(), NULL, &trianglevertexshader);
        D3DDeviceContext->VSSetShader(trianglevertexshader.Get(), nullptr, 0);
        //END OF VERTEX SHADER STUFF

        Microsoft::WRL::ComPtr<ID3D11InputLayout> inputlayout;

        D3D11_INPUT_ELEMENT_DESC ied[]{

            {"POSITION",0,DXGI_FORMAT_R32G32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0},
            {"COLOR",0,DXGI_FORMAT_R32G32B32_FLOAT,0,8,D3D11_INPUT_PER_VERTEX_DATA,0}
        
        };
        

        



        D3DDevice->CreateInputLayout(ied, std::size(ied), triangleBlop->GetBufferPointer(), triangleBlop->GetBufferSize(), &inputlayout);


        D3DDeviceContext->IASetInputLayout(inputlayout.Get());
    
        D3DDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

        D3D11_VIEWPORT vp{};
        vp.Width = 1400;
        vp.Height = 1200;
        vp.MaxDepth = 1;
        vp.MinDepth = 0;
        vp.TopLeftX = 0;
        vp.TopLeftY = 0;

        D3DDeviceContext->RSSetViewports(1, &vp);

        D3DDeviceContext->OMSetRenderTargets(1, RenderTargetView.GetAddressOf(), nullptr);

        D3DDeviceContext->Draw(std::size(TriangleData), 0);

     }


private:

    Microsoft::WRL::ComPtr<IDXGISwapChain> SwapChain;
    Microsoft::WRL::ComPtr<ID3D11Device> D3DDevice;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> D3DDeviceContext;
   
    Microsoft::WRL::ComPtr<ID3D11Resource> Buffer ;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView> RenderTargetView ;
};