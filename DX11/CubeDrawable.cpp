#include "CubeDrawable.h"


Window* windowContextHolderHolder;

std::vector<int> CubeIndex = {
     
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



CubeDrawable::CubeDrawable(ID3D11Device* device, ID3D11DeviceContext* D3DDeviceContext, Window* windowContextHolder, float locationX, float locationY, float locationZ)
    : LocationX(locationX), LocationY(locationY), LocationZ(locationZ)
{
 
   
    windowContextHolderHolder = windowContextHolder;
   
    //Vertex Data Containing informatoin for vertex positions and texture coords
    struct Vertex {
        DirectX::XMFLOAT3 position;   // Vertex position
        DirectX::XMFLOAT2 texCoord;   // Texture coordinates (U, V)
    };


     std::vector<Vertex> CubeData = {

            { DirectX::XMFLOAT3(-1.0f, -1.0f, -1.0f), DirectX::XMFLOAT2(0.0f, 1.0f) },  // Bottom-left
            { DirectX::XMFLOAT3(1.0f, -1.0f, -1.0f), DirectX::XMFLOAT2(1.0f, 1.0f) },  // Bottom-right
            { DirectX::XMFLOAT3(-1.0f,  1.0f, -1.0f), DirectX::XMFLOAT2(0.0f, 0.0f) },  // Top-left
            { DirectX::XMFLOAT3(1.0f,  1.0f, -1.0f), DirectX::XMFLOAT2(1.0f, 0.0f) },  // Top-right

            { DirectX::XMFLOAT3(-1.0f, -1.0f, 1.0f), DirectX::XMFLOAT2(1.0f, 1.0f) },   // Bottom-right
            { DirectX::XMFLOAT3(1.0f, -1.0f, 1.0f), DirectX::XMFLOAT2(0.0f, 1.0f) },   // Bottom-left
            { DirectX::XMFLOAT3(-1.0f,  1.0f, 1.0f), DirectX::XMFLOAT2(1.0f, 0.0f) },   // Top-right
            { DirectX::XMFLOAT3(1.0f,  1.0f, 1.0f), DirectX::XMFLOAT2(0.0f, 0.0f) },   // Top-left
     };


     auto vertexBuffer =  std::make_shared<VertexBuffer<Vertex>>(device, CubeData);
     AddBindable(vertexBuffer);
     ///////////////////////////////////////////////////////////////////////////////////////////
    
  //INITIALMATIXDATA////////////////////////////////////////////////////////////////////////////
   
     std::vector<DirectX::XMMATRIX> initialTransformations = {
      DirectX::XMMatrixIdentity()  // Set to identity matrix initially
   };


   transformationConstantBuffer = std::make_shared<ConstantBuffer<DirectX::XMMATRIX>>(device, initialTransformations, "Vertex");
   AddBindable(transformationConstantBuffer);
   //////////////////////////////////////////////////////////////////////////////////////////////
  
   ////Create texture and send data to the pixel shader ////////////////////////////////////////
   
   Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> ShaderResourceView = nullptr;   
   CHECK_HRESULT(DirectX::CreateWICTextureFromFile(device, D3DDeviceContext, L"C:\\Users\\Amir sanni\\source\\repos\\DX11\\LearnDX\\Textures\\wood.jpg", nullptr, ShaderResourceView.GetAddressOf()));
   D3DDeviceContext->PSSetShaderResources(0, 1, ShaderResourceView.GetAddressOf());

   ////////////////////////////////////////////////////////////////////////////////////////////
  
   ///Image sampler info//////////////////////////////////////////////////////////////////////
   D3D11_SAMPLER_DESC sampDesc = {};
   sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
   sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
   sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
   sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
   sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
   sampDesc.MinLOD = 0;
   sampDesc.MaxLOD = D3D11_FLOAT32_MAX;

   Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerState = nullptr;

   device->CreateSamplerState(&sampDesc, &samplerState);
   D3DDeviceContext->PSSetSamplers(0, 1, samplerState.GetAddressOf());
   //Send Sampler to the pixel shader///////////////////////////////////////////////////////

   /// Create index Buffer/////////////////////////////////////////////////////////////////

   auto indexBuffer = std::make_shared<IndexBuffer>(device, CubeIndex);
   AddBindable(indexBuffer);

   ////////////////////////////////////////////////////////////////////

   ////Create pixel and vertex shaders//////////////////////////////////////////////////////
   auto pixelShader = std::make_shared<PixelShader>(device, L"PixelShader.hlsl");
   AddBindable(pixelShader);


   auto vertexShader = std::make_shared<VertexShader>(device, L"VertexShader.hlsl", pixelShader.get() );
   AddBindable(vertexShader);
   ///////////////////////////////////////////////////////////////////////////////////////////


   ///INPUT LAYOUT/////////////////////////////////////////////////////////////////////////////
   D3D11_INPUT_ELEMENT_DESC ied[]{

          {"POSITION",0,DXGI_FORMAT_R32G32B32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0},
          {"TEXCOORD",0,DXGI_FORMAT_R32G32B32_FLOAT,0,12,D3D11_INPUT_PER_VERTEX_DATA,0},

   };

   auto inputLayout = std::make_shared<InputLayout>(device, ied, std::size(ied), pixelShader.get());
   AddBindable(inputLayout);

   ////////////////////////////////////////////////////////////////////////////////////////////////////
   
   

}


// stuff to be updated every frame
void CubeDrawable::Update(ID3D11DeviceContext* context, ID3D11Device* device, Window* windowApp, float updateRotation)
{
    std::vector<DirectX::XMMATRIX> CubeTransformations = {

        DirectX::XMMatrixTranspose(

                DirectX::XMMatrixScaling(0.3f, 0.3f, 0.3f) *
                DirectX::XMMatrixRotationZ(updateRotation) *
                DirectX::XMMatrixRotationX(updateRotation) *

                DirectX::XMMatrixTranslation(LocationX, LocationY, LocationZ) *

                DirectX::XMMatrixPerspectiveLH(DirectX::XMConvertToRadians(45), windowContextHolderHolder->GetWindowWidth() / windowContextHolderHolder->GetWindowHeight(), 1.0f, 200.0f))

    };

    //update constant buffer data || LOOK A BIT MORE INTO THIS||
    transformationConstantBuffer->Update(context, CubeTransformations);

}

void CubeDrawable::Draw(ID3D11DeviceContext* context, ID3D11Device* device, Window* windowApp)  {

    Bind(context);//Bind all the bindables to the object 

    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    D3D11_VIEWPORT vp{};

    vp.Width = static_cast<float>(windowApp->GetWindowWidth());
    vp.Height = static_cast<float>(windowApp->GetWindowHeight());
    vp.MaxDepth = 1;
    vp.MinDepth = 0;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;

    context->RSSetViewports(1, &vp);

    UINT indexCount = static_cast<UINT>(CubeIndex.size());

    context->DrawIndexed(indexCount, 0, 0);

}


