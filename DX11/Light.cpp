#include "Light.h"
#include "Camera.h"



std::vector<UINT> LightIndex = {

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




Light::Light(ID3D11Device* device, ID3D11DeviceContext* D3DDeviceContext, Window* windowContextHolder, DirectX::XMFLOAT3A location)
    : Location(location)
{


    windowContextHolderHolder = windowContextHolder;

    //Vertex Data Containing informatoin for vertex positions and texture coords
   
    struct Vertex {

        DirectX::XMFLOAT3A position;   // Vertex position
        DirectX::XMFLOAT3A normal;
        DirectX::XMFLOAT4 color;

    };


    std::vector<Vertex> CubeData = {

     // Front face
    { DirectX::XMFLOAT3A(-1.0f, -1.0f, -1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, -1.0f),  BaseColor }, // Bottom-left
    { DirectX::XMFLOAT3A(-1.0f,  1.0f, -1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, -1.0f),  BaseColor }, // Top-left
    { DirectX::XMFLOAT3A(1.0f,  1.0f, -1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, -1.0f),  BaseColor }, // Top-right
    { DirectX::XMFLOAT3A(1.0f, -1.0f, -1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, -1.0f),  BaseColor }, // Bottom-right

    // Back face (Z = 1)
    { DirectX::XMFLOAT3A(-1.0f, -1.0f, 1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, 1.0f),  BaseColor },  // Bottom-left
    { DirectX::XMFLOAT3A(-1.0f,  1.0f, 1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, 1.0f),  BaseColor },  // Top-left
    { DirectX::XMFLOAT3A(1.0f,  1.0f, 1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, 1.0f),  BaseColor },  // Top-right
    { DirectX::XMFLOAT3A(1.0f, -1.0f, 1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, 1.0f),  BaseColor },  // Bottom-right

    // Left face (X = -1)
    { DirectX::XMFLOAT3A(-1.0f, -1.0f, -1.0f), DirectX::XMFLOAT3A(-1.0f, 0.0f, 0.0f), BaseColor },  // Bottom-front
    { DirectX::XMFLOAT3A(-1.0f,  1.0f, -1.0f), DirectX::XMFLOAT3A(-1.0f, 0.0f, 0.0f), BaseColor },  // Top-front
    { DirectX::XMFLOAT3A(-1.0f,  1.0f,  1.0f), DirectX::XMFLOAT3A(-1.0f, 0.0f, 0.0f), BaseColor },  // Top-back
    { DirectX::XMFLOAT3A(-1.0f, -1.0f,  1.0f), DirectX::XMFLOAT3A(-1.0f, 0.0f, 0.0f), BaseColor },  // Bottom-back

    // Right face (X = 1)
    { DirectX::XMFLOAT3A(1.0f, -1.0f, -1.0f),  DirectX::XMFLOAT3A(1.0f, 0.0f, 0.0f),  BaseColor },  // Bottom-front
    { DirectX::XMFLOAT3A(1.0f,  1.0f, -1.0f),  DirectX::XMFLOAT3A(1.0f, 0.0f, 0.0f),  BaseColor },  // Top-front
    { DirectX::XMFLOAT3A(1.0f,  1.0f,  1.0f),  DirectX::XMFLOAT3A(1.0f, 0.0f, 0.0f),  BaseColor },  // Top-back
    { DirectX::XMFLOAT3A(1.0f, -1.0f,  1.0f),  DirectX::XMFLOAT3A(1.0f, 0.0f, 0.0f),  BaseColor },  // Bottom-back

    // Top face (Y = 1)
    { DirectX::XMFLOAT3A(-1.0f, 1.0f, -1.0f),  DirectX::XMFLOAT3A(0.0f, 1.0f, 0.0f),  BaseColor },  // Front-left
    { DirectX::XMFLOAT3A(1.0f, 1.0f, -1.0f),  DirectX::XMFLOAT3A(0.0f, 1.0f, 0.0f),  BaseColor },  // Front-right
    { DirectX::XMFLOAT3A(1.0f, 1.0f,  1.0f),  DirectX::XMFLOAT3A(0.0f, 1.0f, 0.0f),  BaseColor },  // Back-right
    { DirectX::XMFLOAT3A(-1.0f, 1.0f,  1.0f),  DirectX::XMFLOAT3A(0.0f, 1.0f, 0.0f),  BaseColor },  // Back-left

    // Bottom face (Y = -1)
    { DirectX::XMFLOAT3A(-1.0f, -1.0f, -1.0f), DirectX::XMFLOAT3A(0.0f, -1.0f, 0.0f), BaseColor },  // Front-left
    { DirectX::XMFLOAT3A(1.0f, -1.0f, -1.0f), DirectX::XMFLOAT3A(0.0f, -1.0f, 0.0f), BaseColor },  // Front-right
    { DirectX::XMFLOAT3A(1.0f, -1.0f,  1.0f), DirectX::XMFLOAT3A(0.0f, -1.0f, 0.0f), BaseColor },  // Back-right
    { DirectX::XMFLOAT3A(-1.0f, -1.0f,  1.0f), DirectX::XMFLOAT3A(0.0f, -1.0f, 0.0f), BaseColor },  // Back-left


           
    };

    

    auto vertexBuffer = std::make_shared<VertexBuffer<Vertex>>(device, CubeData);
    AddBindable(vertexBuffer);
    ///////////////////////////////////////////////////////////////////////////////////////////

 //INITIALMATIXDATA////////////////////////////////////////////////////////////////////////////
    DirectX::XMMATRIX WorldPosition = DirectX::XMMatrixIdentity();
    DirectX::XMMATRIX projectionmatrix = DirectX::XMMatrixIdentity();
    DirectX::XMMATRIX ViewMatrix = DirectX::XMMatrixIdentity();

    std::vector<DirectX::XMMATRIX> initialTransformations = {

          WorldPosition,
          projectionmatrix,
          ViewMatrix

    };

    
    transformationConstantBuffer = std::make_shared<ConstantBuffer<DirectX::XMMATRIX>>(device, initialTransformations, "Vertex",0);
    AddBindable(transformationConstantBuffer);

    /// Create index Buffer/////////////////////////////////////////////////////////////////

    auto indexBuffer = std::make_shared<IndexBuffer>(device, LightIndex);
    AddBindable(indexBuffer);

    ////////////////////////////////////////////////////////////////////


    ////Create pixel and vertex shaders//////////////////////////////////////////////////////
    auto pixelShader = std::make_shared<PixelShader>(device, L"PixelShader.hlsl");
    AddBindable(pixelShader);


    auto vertexShader = std::make_shared<VertexShader>(device, L"VertexShader.hlsl", pixelShader.get());
    AddBindable(vertexShader);
    ///////////////////////////////////////////////////////////////////////////////////////////


    ///INPUT LAYOUT/////////////////////////////////////////////////////////////////////////////
    D3D11_INPUT_ELEMENT_DESC ied[]{

         {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT , 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
         {"NORMAL",    0, DXGI_FORMAT_R32G32B32_FLOAT , 0, 16, D3D11_INPUT_PER_VERTEX_DATA, 0},
         {"COLOR",   0, DXGI_FORMAT_R32G32B32A32_FLOAT , 0, 32, D3D11_INPUT_PER_VERTEX_DATA, 0},


    };

    auto inputLayout = std::make_shared<InputLayout>(device, ied, std::size(ied), pixelShader.get());
    AddBindable(inputLayout);

    ////////////////////////////////////////////////////////////////////////////////////////////////////



}


// stuff to be updated every frame
void Light::Update(ID3D11DeviceContext* context, ID3D11Device* device, Window* windowApp, float updateRotation)
{
    ImGui::Begin("Cube Controls");

    ImGui::SliderFloat3("Cube Position", &Location.x, -40.0f, 40.0f);

    ImGui::End();


    DirectX::XMMATRIX WorldPosition = DirectX::XMMatrixTranspose(

        DirectX::XMMatrixScaling(0.5f, 0.5f, 0.5f)*
        DirectX::XMMatrixRotationZ(0) *
        DirectX::XMMatrixRotationX(0) *
        DirectX::XMMatrixTranslation(Location.x, Location.y, Location.z));


    DirectX::XMMATRIX ProjectionMatrix = Camera::GetInstance().GetProjectionMatrix();

    DirectX::XMMATRIX ViewMatrix = Camera::GetInstance().GetViewMatrix();
  

    std::vector< DirectX::XMMATRIX> MatrixData = {

       WorldPosition,
       ProjectionMatrix,
       ViewMatrix
    };


    //update constant buffer data || LOOK A BIT MORE INTO THIS||
    transformationConstantBuffer->Update(context, MatrixData);
    //update constant buffer data || LOOK A BIT MORE INTO THIS||

}

void Light::Draw(ID3D11DeviceContext* context, ID3D11Device* device, Window* windowApp) {

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

    UINT indexCount = static_cast<UINT>(LightIndex.size());

    context->DrawIndexed(indexCount, 0, 0);

}


