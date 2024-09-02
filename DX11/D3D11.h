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
#include <DirectXMath.h>


class D3D11
{

public:

    D3D11(Window* windowApp);
    ~D3D11();

    D3D11& operator=(const D3D11&) = delete;
    D3D11(const D3D11&) = delete;

    void EndFrame();

    void ClearBuffer(float red, float green, float blue);

    Window* windowContextHolder;

    
    float rotaion = 1.0f;
    void DrawTriangle(float angle,float Z) {

        struct Vertex {
            
            float x;
            float y;
            float z;

            float r;
            float g;
            float b;
        
        };

        const Vertex TriangleData[] = {
            
             
             { -1.0f, -1.0f, -1.0f,     1.0f, 0.0f, 0.0f }, // Bottom-left, red
             {  1.0f, -1.0f,  -1.0f,     0.0f, 1.0f, 0.0f }, // Bottom-right, green
             {  -1.0f,  1.0f,  -1.0f,     0.0f, 0.0f, 1.0f }, // Top-right, blue
             { 1.0f,  1.0f,  -1.0f,     1.0f, 1.0f, 0.0f }, // Top-left, yellow

    // Back face
             { -1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 1.0f }, // Bottom-left, red
             {  1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 1.0f }, // Bottom-right, green
             {  -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f }, // Top-right, blue
             { 1.0f,  1.0f, 1.0f, 1.0f, 1.0f, 1.0f }, // Top-left, yellow
        
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
        TriangleSubSurfaceData.pSysMem = &TriangleData;
         
        //Create Vertex Buffer
         D3DDevice->CreateBuffer(&TriangleBufferData, &TriangleSubSurfaceData, &VertexBuffer);

       
        UINT Stride = sizeof(Vertex);
        UINT Offset = 0;

        //set vertex buffer
         D3DDeviceContext->IASetVertexBuffers(0, 1, VertexBuffer.GetAddressOf(), &Stride, &Offset);




        struct  ConstantBuffer {

            struct {

                DirectX::XMMATRIX transform;

            }transformation;

        };

        ConstantBuffer cbData = {

           cbData.transformation = {

                     DirectX::XMMatrixTranspose(

                      DirectX::XMMatrixRotationZ(angle)*
                      DirectX::XMMatrixRotationX(angle)*

                      DirectX::XMMatrixTranslation(0.0f, 0.0f, Z)*
                      DirectX::XMMatrixPerspectiveLH(DirectX::XMConvertToRadians(45.0f), windowContextHolder->GetWindowWidth()/ windowContextHolder->GetWindowHeight(), 0.5f, 100.0f)

            )
           
            }
        };
        

        Microsoft::WRL::ComPtr<ID3D11Buffer>ConstBuffer;

        D3D11_BUFFER_DESC ConstBufferDesc = {};
        ConstBufferDesc.ByteWidth = sizeof(cbData);
        ConstBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
        ConstBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
        ConstBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
        ConstBufferDesc.MiscFlags = 0;
        ConstBufferDesc.StructureByteStride = sizeof(Vertex);
        
         D3D11_SUBRESOURCE_DATA ConstBufferSubSurfaceData = {};
        ConstBufferSubSurfaceData.pSysMem = &cbData;

        D3DDevice->CreateBuffer(&ConstBufferDesc, &ConstBufferSubSurfaceData, &ConstBuffer);

       
        D3DDeviceContext->VSSetConstantBuffers(0, 1, ConstBuffer.GetAddressOf());

       
        

        
        //INDEX BUFFER STUFF
        const unsigned short HexagonIndices[] = {

          0, 2, 1, 2, 3, 1,
          // Back face
          1, 3, 5, 3, 7, 5,
          // Top face
          2, 6, 3, 3, 6, 7,
          // Bottom face
          4, 5, 7, 4, 7, 6,
          // Left face
          0, 4, 2, 2, 4, 6,
          // Right face
          0, 1, 4, 1, 5, 4,
        };


        Microsoft::WRL::ComPtr<ID3D11Buffer> IndexBuffer;


        D3D11_BUFFER_DESC IndexBufferDesc = {};
        IndexBufferDesc.ByteWidth = sizeof(HexagonIndices);
        IndexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
        IndexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
        IndexBufferDesc.CPUAccessFlags = 0;
        IndexBufferDesc.MiscFlags = 0;
        IndexBufferDesc.StructureByteStride = sizeof(Vertex);

        D3D11_SUBRESOURCE_DATA INDEXsURF = {};
        INDEXsURF.pSysMem = HexagonIndices;

         D3DDevice->CreateBuffer(&IndexBufferDesc, &INDEXsURF, &IndexBuffer);

        
        D3DDeviceContext->IASetIndexBuffer(IndexBuffer.Get(), DXGI_FORMAT_R16_UINT, 0);
        //END OF INDEX BUFFER

        Microsoft::WRL::ComPtr<ID3DBlob> triangleBlop;
        Microsoft::WRL::ComPtr<ID3DBlob> errorBlob = nullptr;

     
        
        //START OF PICEL SHADER STUFF
        Microsoft::WRL::ComPtr< ID3D11PixelShader> PixelShader;
        D3DCompileFromFile(L"PixelShader.hlsl",
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

            {"POSITION",0,DXGI_FORMAT_R32G32B32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0},
            {"COLOR",0,DXGI_FORMAT_R32G32B32_FLOAT,0,12,D3D11_INPUT_PER_VERTEX_DATA,0}
        
        };
        

        D3DDevice->CreateInputLayout(ied, std::size(ied), triangleBlop->GetBufferPointer(), triangleBlop->GetBufferSize(), &inputlayout);


        D3DDeviceContext->IASetInputLayout(inputlayout.Get());
    
        D3DDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

        D3D11_VIEWPORT vp{};
        vp.Width = static_cast<float>(windowContextHolder->GetWindowWidth());
        vp.Height = static_cast<float>(windowContextHolder->GetWindowHeight());
        vp.MaxDepth = 1;
        vp.MinDepth = 0;
        vp.TopLeftX = 0;
        vp.TopLeftY = 0;

        D3DDeviceContext->RSSetViewports(1, &vp);


        D3DDeviceContext->DrawIndexed(std::size(HexagonIndices), 0, 0);

     }


private:

    Microsoft::WRL::ComPtr<IDXGISwapChain> SwapChain;
    Microsoft::WRL::ComPtr<ID3D11Device> D3DDevice;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> D3DDeviceContext;
   
    Microsoft::WRL::ComPtr<ID3D11Resource> Buffer ;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView> RenderTargetView ;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView> DepthSentcilView;
};