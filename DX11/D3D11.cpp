#include "D3D11.h"


#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dxguid.lib")


D3D11::D3D11(Window* windowApp)
{
   
    DXGI_RATIONAL MonitorRefreshRatedData{};

    MonitorRefreshRatedData.Numerator = 60;
    MonitorRefreshRatedData.Denominator = 1;

    DXGI_MODE_DESC SwapChainBufferData{};

    SwapChainBufferData.Width = windowApp->GetWindowWidth();
    SwapChainBufferData.Height = windowApp->GetWindowHeight();
    SwapChainBufferData.RefreshRate = MonitorRefreshRatedData;
    SwapChainBufferData.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
    SwapChainBufferData.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
    SwapChainBufferData.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

    DXGI_SAMPLE_DESC SamplingData{};
 
    SamplingData.Count = 1;
    SamplingData.Quality = 0;

    HWND window = glfwGetWin32Window(windowApp->GetWindow());
  
    DXGI_SWAP_CHAIN_DESC SwapChainDesc{};

    SwapChainDesc.BufferDesc = SwapChainBufferData;
    SwapChainDesc.SampleDesc = SamplingData;
    SwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    SwapChainDesc.BufferCount = 1;
    SwapChainDesc.OutputWindow = window;
    SwapChainDesc.Windowed = TRUE;
    SwapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
    SwapChainDesc.Flags = 0;

      D3D11CreateDeviceAndSwapChain(
        nullptr,
        D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_HARDWARE,
        nullptr,
        0,
        nullptr,
        0,
        D3D11_SDK_VERSION,
        &SwapChainDesc,
        &SwapChain, 
        &D3DDevice,
        nullptr,
        &D3DDeviceContext);

   
      //GET BUFFERS TO RENDER A COLOR TO IT 
    SwapChain->GetBuffer(0, __uuidof(ID3D11Resource),&Buffer);

    D3DDevice->CreateRenderTargetView(Buffer.Get(), nullptr, &RenderTargetView);



    }




D3D11::~D3D11()
{
    RenderTargetView->Release();
    SwapChain->Release();
    D3DDevice->Release();
    D3DDeviceContext->Release();
}

void D3D11::ClearBuffer(float red, float green, float blue)
{
    float clour[] = { red,green,blue,1.0f };

    D3DDeviceContext->ClearRenderTargetView(RenderTargetView.Get(), clour);


    DrawTriangle();
}


void D3D11::EndFrame()
{
    SwapChain->Present(1, 0);
}


