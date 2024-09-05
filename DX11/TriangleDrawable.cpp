// TriangleDrawable.cpp
#include "TriangleDrawable.h"

float UpdateAngle = 0;
float UpdateZ = 0;
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



TriangleDrawable::TriangleDrawable(ID3D11Device* device, Window* windowContextHolder) {
 
   
    windowContextHolderHolder = windowContextHolder;

     std::vector<float> CubeData = {

         -1.0f, -1.0f, -1.0f, // Bottom-left, red
          1.0f, -1.0f,  -1.0f,    // Bottom-right, green
         -1.0f,  1.0f,  -1.0f,    // Top-right, blue
          1.0f,  1.0f,  -1.0f,   // Top-left, yellow

          // Back face
          -1.0f, -1.0f, 1.0f,      // Bottom-left, red
           1.0f, -1.0f, 1.0f,    // Bottom-right, green
          -1.0f, 1.0f, 1.0f,      // Top-right, blue
           1.0f,  1.0f, 1.0f,      // Top-left, yellow

     };

     auto vertexBuffer =  std::make_shared<VertexBuffer>(device, CubeData);
    AddBindable(vertexBuffer);


 

   std::vector< DirectX::XMFLOAT4> CubeColors = {

     DirectX::XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f), // Bottom-left, red
     DirectX::XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f), // Bottom-right, green
     DirectX::XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f), // Top-right, blue
     DirectX::XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f), // Top-left, yellow
     DirectX::XMFLOAT4(1.0f, 1.0f, 0.0f, 1.0f), // Bottom-left, red
     DirectX::XMFLOAT4(0.0f, 1.0f, 1.0f, 1.0f)  // Bottom-right, green

   };

   auto coolorconstantBuffer = std::make_shared<ConstantBuffer<DirectX::XMFLOAT4>>(device, CubeColors,"Pixel");
   AddBindable(coolorconstantBuffer);


 
   auto indexBuffer = std::make_shared<IndexBuffer>(device, CubeIndex);
   AddBindable(indexBuffer);

   
   auto pixelShader = std::make_shared<PixelShader>(device, L"PixelShader.hlsl");
   AddBindable(pixelShader);


   auto vertexShader = std::make_shared<VertexShader>(device, L"VertexShader.hlsl", pixelShader.get() );
   AddBindable(vertexShader);



   D3D11_INPUT_ELEMENT_DESC ied[]{

          {"POSITION",0,DXGI_FORMAT_R32G32B32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0},
   };

   auto inputLayout = std::make_shared<InputLayout>(device, ied, std::size(ied), pixelShader.get());
   AddBindable(inputLayout);

   

}





void TriangleDrawable::Draw(ID3D11DeviceContext* context, ID3D11Device* device, Window* windowApp, float updateRotation, float UpdateXp, float UpdateYp ,float UpdateZp)  {


    std::vector<DirectX::XMMATRIX> CubeTransformations = {

        DirectX::XMMatrixTranspose(

                DirectX::XMMatrixScaling(1.7f, 1.7f, 1.7f) *
                DirectX::XMMatrixRotationZ(UpdateAngle) *
                DirectX::XMMatrixRotationX(UpdateAngle) *

                DirectX::XMMatrixTranslation(UpdateXp, UpdateYp, UpdateZp) *
                DirectX::XMMatrixPerspectiveLH(DirectX::XMConvertToRadians(45.0f), windowContextHolderHolder->GetWindowWidth() / windowContextHolderHolder->GetWindowHeight(), 0.5f, 100.0f))

    };


    auto constantBuffer = std::make_shared<ConstantBuffer<DirectX::XMMATRIX>>(device, CubeTransformations, "Vertex");
    AddBindable(constantBuffer);


    Bind(context);

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

    UpdateAngle = updateRotation;
    UpdateZ = UpdateZp;
     context->DrawIndexed(indexCount, 0, 0);
}
