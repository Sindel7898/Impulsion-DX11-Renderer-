#include "CubeDrawable.h"


Window* windowContextHolderHolder;

std::vector<UINT> CubeIndex = {

    // Front face
    0, 1, 2, 0, 2, 3,
    // Back face
    4,6,5,4,7,6,
    // Left face
    8, 10, 9, 8, 11, 10,

    // Right face
    12, 13, 14, 12, 14, 15,
    // Top face
    16, 18, 17, 16, 19, 18,

    // Bottom face
    20, 21, 22, 20, 22, 23
};



CubeDrawable::CubeDrawable(ID3D11Device* device, ID3D11DeviceContext* d3dDeviceContext, Window* windowContextHolder, DirectX::XMFLOAT3 location, int cubenumber)
    : Location(location),
      Device(device), D3DDeviceContext(d3dDeviceContext), 
      WindowContextHolder(windowContextHolder)
{
    CubeNumber = cubenumber;

   
    windowContextHolderHolder = windowContextHolder;
   
   
    
        struct Vertex {

        DirectX::XMFLOAT3A position;   // Vertex position
        DirectX::XMFLOAT3A normal;
        DirectX::XMFLOAT2A Texture;
        DirectX::XMFLOAT3A color;
    };

    DirectX::XMFLOAT3A BaseColor = { 1.0f,1.0f,1.0f };

    std::vector<Vertex> CubeData = {

        // Front face
      { DirectX::XMFLOAT3A(-1.0f, -1.0f, -1.0f), DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f), DirectX::XMFLOAT2A(0.0f, 1.0f), BaseColor }, // Bottom-left
       { DirectX::XMFLOAT3A(-1.0f,  1.0f, -1.0f), DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f), DirectX::XMFLOAT2A(0.0f, 0.0f),  BaseColor }, // Top-left
       { DirectX::XMFLOAT3A(1.0f,  1.0f, -1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f), DirectX::XMFLOAT2A(1.0f, 0.0f), BaseColor }, // Top-right
       { DirectX::XMFLOAT3A(1.0f, -1.0f, -1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f), DirectX::XMFLOAT2A(1.0f, 1.0f),  BaseColor }, // Bottom-right

      // Back face (Z = 1)                       
       { DirectX::XMFLOAT3A(-1.0f, -1.0f, 1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f), DirectX::XMFLOAT2A(1.0f, 1.0f), BaseColor },  // Bottom-left
       { DirectX::XMFLOAT3A(-1.0f,  1.0f, 1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f), DirectX::XMFLOAT2A(1.0f, 0.0f), BaseColor },  // Top-left
       { DirectX::XMFLOAT3A(1.0f,  1.0f, 1.0f),   DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f), DirectX::XMFLOAT2A(0.0f, 0.0f), BaseColor },  // Top-right
       { DirectX::XMFLOAT3A(1.0f, -1.0f, 1.0f),   DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f), DirectX::XMFLOAT2A(0.0f, 1.0f), BaseColor },  // Bottom-right
       // Left face (X = -1)                      
       { DirectX::XMFLOAT3A(-1.0f, -1.0f, -1.0f), DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f), DirectX::XMFLOAT2A(1.0f, 1.0f), BaseColor },  // Bottom-front
       { DirectX::XMFLOAT3A(-1.0f,  1.0f, -1.0f), DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f), DirectX::XMFLOAT2A(1.0f, 0.0f), BaseColor },  // Top-front
       { DirectX::XMFLOAT3A(-1.0f,  1.0f,  1.0f), DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f), DirectX::XMFLOAT2A(0.0f, 0.0f), BaseColor },  // Top-back
       { DirectX::XMFLOAT3A(-1.0f, -1.0f,  1.0f), DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f), DirectX::XMFLOAT2A(0.0f, 1.0f), BaseColor },  // Bottom-back
                                                 
       // Right face (X = 1)                     
       { DirectX::XMFLOAT3A(1.0f, -1.0f, -1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f),  DirectX::XMFLOAT2A(0.0f, 1.0f), BaseColor },  // Bottom-front
       { DirectX::XMFLOAT3A(1.0f,  1.0f, -1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f),  DirectX::XMFLOAT2A(0.0f, 0.0f), BaseColor },  // Top-front
      { DirectX::XMFLOAT3A(1.0f,  1.0f,  1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f),  DirectX::XMFLOAT2A(1.0f, 0.0f), BaseColor },  // Top-back
       { DirectX::XMFLOAT3A(1.0f, -1.0f,  1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f),  DirectX::XMFLOAT2A(1.0f, 1.0f), BaseColor },  // Bottom-back
                                                  
       // Top face (Y = 1)                      
       { DirectX::XMFLOAT3A(-1.0f, 1.0f, -1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f),  DirectX::XMFLOAT2A(0.0f, 0.0f), BaseColor },  // Front-left
       { DirectX::XMFLOAT3A(1.0f, 1.0f, -1.0f),   DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f),  DirectX::XMFLOAT2A(1.0f, 0.0f), BaseColor },  // Front-right
       { DirectX::XMFLOAT3A(1.0f, 1.0f,  1.0f),   DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f),  DirectX::XMFLOAT2A(1.0f, 1.0f), BaseColor },  // Back-right
       { DirectX::XMFLOAT3A(-1.0f, 1.0f,  1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f),  DirectX::XMFLOAT2A(0.0f, 1.0f), BaseColor },  // Back-left
                                                  
       // Bottom face (Y = -1)                   
       { DirectX::XMFLOAT3A(-1.0f, -1.0f, -1.0f), DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f), DirectX::XMFLOAT2A(0.0f, 1.0f), BaseColor },  // Front-left
       { DirectX::XMFLOAT3A(1.0f, -1.0f, -1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f), DirectX::XMFLOAT2A(1.0f, 1.0f), BaseColor },  // Front-right
       { DirectX::XMFLOAT3A(1.0f, -1.0f,  1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f), DirectX::XMFLOAT2A(1.0f, 0.0f), BaseColor },  // Back-right
       { DirectX::XMFLOAT3A(-1.0f, -1.0f,  1.0f), DirectX::XMFLOAT3A(0.0f, 0.0f, -0.0f), DirectX::XMFLOAT2A(0.0f, 1.0f), BaseColor },  // Back-left
    };


    for (int i = 0; i < CubeIndex.size()/3; ++i) {

        auto i0 = CubeIndex[i * 3 + 0];
        auto i1 = CubeIndex[i * 3 + 1];
        auto i2 = CubeIndex[i * 3 + 2];

        DirectX::XMVECTOR  V0 = DirectX::XMLoadFloat3(&CubeData[i0].position);
        DirectX::XMVECTOR  V1 = DirectX::XMLoadFloat3(&CubeData[i1].position);
        DirectX::XMVECTOR  V2 = DirectX::XMLoadFloat3(&CubeData[i2].position);



        DirectX::XMVECTOR E1 = DirectX::XMVectorSubtract(V1, V0);
        DirectX::XMVECTOR E2 = DirectX::XMVectorSubtract(V2, V0);
        DirectX::XMVECTOR FACENORMAL = DirectX::XMVector3Cross(E1, E2);

        DirectX::XMFLOAT3A FloatFacenormal;

        DirectX::XMStoreFloat3A(&FloatFacenormal, FACENORMAL);

        CubeData[i0].normal = FloatFacenormal;
        CubeData[i1].normal = FloatFacenormal;
        CubeData[i2].normal = FloatFacenormal;

    }


    
    
      auto vertexBuffer =  std::make_shared<VertexBuffer<Vertex>>(device, CubeData,1,0);
     AddBindable(vertexBuffer);
     ///////////////////////////////////////////////////////////////////////////////////////////
     
    //INITIALMATIXDATA////////////////////////////////////////////////////////////////////////////
     DirectX::XMMATRIX WorldMatrix = DirectX::XMMatrixIdentity();
     DirectX::XMMATRIX projectionmatrix = DirectX::XMMatrixIdentity();
     DirectX::XMMATRIX viewMatrix = DirectX::XMMatrixIdentity();

     DirectX::XMFLOAT3 CameraPosition = Camera::GetInstance().GetPosition();
     float MatrixDataCBPadding1 = 0.0f;

     std::vector<VERTEXDATA> vertexDatainfo;

     VERTEXDATA VertexData = {

        WorldMatrix,
        projectionmatrix,
        viewMatrix,
        CameraPosition,
        MatrixDataCBPadding1

     };

     vertexDatainfo.push_back(VertexData);



   Matrix = std::make_shared<ConstantBuffer<VERTEXDATA>>(device, vertexDatainfo, "Vertex",0);
   AddBindable(Matrix);

   DirectX::XMFLOAT3A Lightlocation = { -2.0f,1.0f,1.0f };

   DirectX::XMMATRIX lightPerspectiveMatrix = DirectX::XMMatrixPerspectiveFovRH(DirectX::XM_PIDIV2, 1.0f, 12.f, 50.f);

   DirectX::XMFLOAT3 eye = { 0.0f, 2.0f, -5.0f }; // Move the camera away from the target
   DirectX::XMFLOAT3 at = { Lightlocation.x, Lightlocation.y, Lightlocation.z };
   DirectX::XMFLOAT3 up = { 0.0f, 1.0f, 0.0f };

   DirectX::XMMATRIX lightviewMatrix = DirectX::XMMatrixLookAtLH(

       DirectX::XMLoadFloat3(&at),   // Camera position
       DirectX::XMLoadFloat3(&eye),     // Target we're looking at
       DirectX::XMLoadFloat3(&up)          // Up direction

   );

   std::vector<DirectX::XMMATRIX> initialLightPosition = {

     lightviewMatrix,
     lightPerspectiveMatrix
   };

   LightPositionConstantBuffer = std::make_shared<ConstantBuffer<DirectX::XMMATRIX>>(device, initialLightPosition, "Vertex", 1);
   AddBindable(LightPositionConstantBuffer);




   
   std::vector<std::shared_ptr<Light>> FaulseLights;

   int  LightNumber = 0;

   FaulseLights.push_back(std::make_shared<Light>(device, d3dDeviceContext, windowContextHolder, Lightlocation, LightNumber++));
   FaulseLights.push_back(std::make_shared<Light>(device, d3dDeviceContext, windowContextHolder, Lightlocation, LightNumber++));
   FaulseLights.push_back(std::make_shared<Light>(device, d3dDeviceContext, windowContextHolder, Lightlocation, LightNumber++));
   FaulseLights.push_back(std::make_shared<Light>(device, d3dDeviceContext, windowContextHolder, Lightlocation, LightNumber++));
   FaulseLights.push_back(std::make_shared<Light>(device, d3dDeviceContext, windowContextHolder, Lightlocation, LightNumber++));


   std::vector<LightData> LightDatainfo;

   for (size_t i = 0; i < FaulseLights.size(); i++)
   {
       LightData lightData = {
            FaulseLights[i]->GetLocation(),
            FaulseLights[i]->GetDirection(),

            FaulseLights[i]->GetColor(),
            FaulseLights[i]->GetConeDetails(),

            FaulseLights[i]->GetAttenuition()
       };

       LightDatainfo.push_back(lightData);
   }

   LightBuffer = std::make_shared<ConstantBuffer<LightData>>(device, LightDatainfo, "Pixel",0,2);
   AddBindable(LightBuffer);


  auto texture = std::make_shared<Texture>(Device, D3DDeviceContext,0, L"Texture/BrickTexture.png");
   AddBindable(texture);

   auto NormalMap = std::make_shared<Texture>(Device, D3DDeviceContext, 1,L"Texture/BrickNormal.png");
   AddBindable(NormalMap);

   /// Create index Buffer/////////////////////////////////////////////////////////////////

   auto indexBuffer = std::make_shared<IndexBuffer>(device, CubeIndex);
   AddBindable(indexBuffer);

   ////////////////////////////////////////////////////////////////////

   ////Create pixel and vertex shaders//////////////////////////////////////////////////////
   auto pixelShader = std::make_shared<PixelShader>(device, L"DiffuseLighting.hlsl");
   AddBindable(pixelShader);


   auto vertexShader = std::make_shared<VertexShader>(device, L"BoxVertexShader.hlsl", pixelShader.get() );
   AddBindable(vertexShader);
   ///////////////////////////////////////////////////////////////////////////////////////////


   ///INPUT LAYOUT/////////////////////////////////////////////////////////////////////////////
   D3D11_INPUT_ELEMENT_DESC ied[]{

        {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
        {"NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 16, D3D11_INPUT_PER_VERTEX_DATA, 0},
        {"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 32, D3D11_INPUT_PER_VERTEX_DATA, 0},
        {"COLOR", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 48, D3D11_INPUT_PER_VERTEX_DATA, 0},

   };

   auto inputLayout = std::make_shared<InputLayout>(device, ied, std::size(ied), pixelShader.get());
   AddBindable(inputLayout);

   ////////////////////////////////////////////////////////////////////////////////////////////////////  

   

}


// stuff to be updated every frame
void CubeDrawable::Update(std::vector<std::shared_ptr<Light>>& Lights){
    LightsRef = Lights;

    ImGui::Begin("Cube Controls");

    ImGui::SliderFloat3(("Cube Position" + std::to_string(CubeNumber)).c_str(), &Location.x, -50.0f, 50.0f);
    ImGui::SliderFloat3(("Scale" + std::to_string(CubeNumber)).c_str(), &Scaling.x, -50.0f, 50.0f);
    ImGui::SliderFloat3(("Rotation" + std::to_string(CubeNumber)).c_str(), &Rotation.x, -360.0f, 360.0f);


    ImGui::End();



    DirectX::XMMATRIX WorldMatrix = DirectX::XMMatrixTranspose(
      
        DirectX::XMMatrixScaling(Scaling.x, Scaling.y, Scaling.z) *
        DirectX::XMMatrixRotationX(Rotation.x)*
        DirectX::XMMatrixRotationY(Rotation.y)*
        DirectX::XMMatrixRotationZ(Rotation.z) *

        DirectX::XMMatrixTranslation(Location.x, Location.y, Location.z));

           
    DirectX::XMMATRIX ProjectionMatrix = Camera::GetInstance().GetProjectionMatrix();

    DirectX::XMMATRIX ViewMatrix = Camera::GetInstance().GetViewMatrix();

    DirectX::XMFLOAT3 CameraPosition = Camera::GetInstance().GetPosition();

    float MatrixDataCBPadding1 = 0.0f;

    VERTEXDATA vertexDatainfo = {

       WorldMatrix,
       ProjectionMatrix,
       ViewMatrix,
       CameraPosition,
       MatrixDataCBPadding1

    };

    std::vector<VERTEXDATA> VertexData;
    VertexData.push_back(vertexDatainfo);

    //update constant buffer data || LOOK A BIT MORE INTO THIS||
    Matrix->Update(D3DDeviceContext, VertexData);


    std::vector<LightData> LightDatainfo;
    DirectX::XMINT3 Padding;

    for (size_t i = 0; i < LightsRef.size(); i++)
    {
        LightData lightData = {

             LightsRef[i]->GetLocation(),
             LightsRef[i]->GetDirection(),
             LightsRef[i]->GetColor(),
             LightsRef[i]->GetConeDetails(),
             LightsRef[i]->GetAttenuition(),
             LightsRef[i]->GetLightType(),
        };

        LightDatainfo.push_back(lightData);
    }


    LightBuffer->Update(D3DDeviceContext, LightDatainfo);


}

void CubeDrawable::Draw()  {

    Bind(D3DDeviceContext);//Bind all the bindables to the object 

    D3DDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    D3D11_VIEWPORT vp{};

    vp.Width = static_cast<float>(WindowContextHolder->GetWindowWidth());
    vp.Height = static_cast<float>(WindowContextHolder->GetWindowHeight());
    vp.MaxDepth = 1;
    vp.MinDepth = 0;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;

    D3DDeviceContext->RSSetViewports(1, &vp);

    UINT indexCount = static_cast<UINT>(CubeIndex.size());

    D3DDeviceContext->DrawIndexed(indexCount, 0, 0);
}


void CubeDrawable::RenderShadowMap(ID3D11DeviceContext* context, ShadowMap* shadow) {

    // Clear the depth stencil view
    context->ClearDepthStencilView(shadow->DepthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

    // Set the depth stencil view as the render target
    context->OMSetRenderTargets(0, nullptr, shadow->DepthStencilView.Get());

    // Set the rasterizer state for shadow rendering
    context->RSSetState(shadow->ShadowRenderState.Get());

    // Set the viewport for shadow rendering
    D3D11_VIEWPORT shadowViewport = {};
    shadowViewport.Width = static_cast<FLOAT>(WindowContextHolder->GetWindowWidth());  // Set the width of the shadow map
    shadowViewport.Height = static_cast<FLOAT>(WindowContextHolder->GetWindowWidth()); // Set the height of the shadow map
    shadowViewport.MinDepth = 0.0f;
    shadowViewport.MaxDepth = 1.0f;
    context->RSSetViewports(1, &shadowViewport);


    auto shadowPixelShader = std::make_shared<PixelShader>(Device, L"ShadowPixelShader.hlsl");
    context->PSSetShader(shadowPixelShader->GetShader(), nullptr, 0);


    // Set the vertex and pixel shaders for shadow mapping
    auto shadowVertexShader = std::make_shared<VertexShader>(Device, L"ShadowVertexShader.hlsl", shadowPixelShader.get());
    context->VSSetShader(shadowVertexShader->GetShader(), nullptr, 0);

    
    

    DirectX::XMFLOAT3A Lightlocation = { -2.0f,1.0f,1.0f };

    DirectX::XMMATRIX lightProjectionMatrix = DirectX::XMMatrixPerspectiveFovLH(DirectX::XM_PIDIV2, 1.0f, 12.f, 50.f);

    DirectX::XMFLOAT3 eye = { 0.0f, 2.0f, -5.0f }; // Move the camera away from the target
    DirectX::XMFLOAT3 at = { 0.0f, 0.0f, 0.0f };
    DirectX::XMFLOAT3 up = { 0.0f, 1.0f, 0.0f };

    DirectX::XMMATRIX lightviewMatrix = DirectX::XMMatrixLookAtLH(

        DirectX::XMLoadFloat3(&at),   // Camera position
        DirectX::XMLoadFloat3(&eye),     // Target we're looking at
        DirectX::XMLoadFloat3(&up)          // Up direction

    );

    std::vector<DirectX::XMMATRIX> initialLightPosition = {

      lightviewMatrix,
      lightProjectionMatrix
    };

    LightPositionConstantBuffer->Update(D3DDeviceContext, initialLightPosition);

    // Draw the shadow-casting geometry
    UINT indexCount = static_cast<UINT>(CubeIndex.size());
    context->DrawIndexed(indexCount, 0, 0);
}