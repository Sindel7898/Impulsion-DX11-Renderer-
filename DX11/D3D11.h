#pragma once
#include <d3d11.h>
#include <dxgi1_3.h>
#include <wrl.h>
#include "Window.h"

#include <d3dcompiler.h>
#include <DirectXMath.h>
#include "comdef.h"

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dxguid.lib")

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
        
        };

        const Vertex TriangleData[] = {
            {0.0f,0.5f},
            {0.5f,-0.5f},
            {-0.5f,-0.5f}
        };

        Microsoft::WRL::ComPtr<ID3D11Buffer> TriangleBuffer;

        D3D11_BUFFER_DESC TriangleBufferData{};
        TriangleBufferData.ByteWidth = sizeof(TriangleData);
        TriangleBufferData.Usage = D3D11_USAGE_DEFAULT;
        TriangleBufferData.BindFlags = D3D11_BIND_VERTEX_BUFFER;
        TriangleBufferData.CPUAccessFlags = 0;
        TriangleBufferData.MiscFlags = 0;
        TriangleBufferData.StructureByteStride = sizeof(TriangleData);

        D3D11_SUBRESOURCE_DATA TriangleSubSurfaceData{};
        TriangleSubSurfaceData.pSysMem = TriangleData;
         
        D3DDevice->CreateBuffer(&TriangleBufferData, &TriangleSubSurfaceData, &TriangleBuffer);
        UINT Stride = sizeof(TriangleData);
        UINT Offset = 0;
        D3DDeviceContext->IASetVertexBuffers(0, 1, &TriangleBuffer, &Stride, &Offset);
        D3DDeviceContext->Draw(3, 0);
    }
private:

    Microsoft::WRL::ComPtr<IDXGISwapChain> SwapChain;
    Microsoft::WRL::ComPtr<ID3D11Device> D3DDevice;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> D3DDeviceContext;
   
    Microsoft::WRL::ComPtr<ID3D11Resource> Buffer ;

    Microsoft::WRL::ComPtr<ID3D11RenderTargetView> RenderTargetView ;
};