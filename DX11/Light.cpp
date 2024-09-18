#include "Light.h"



std::vector<int> LightIndex = {

 0, 1, 2, // Bottom side
    0, 2, 3, // Bottom side
    4, 6, 5, // Left side
    7, 9, 8, // Non-facing side
    10, 12, 11, // Right side
    13, 15, 14 // Facing side
};



Light::Light(ID3D11Device* device, ID3D11DeviceContext* D3DDeviceContext, Window* windowContextHolder, DirectX::XMFLOAT3A location)
    : Location(location)
{


    windowContextHolderHolder = windowContextHolder;

    //Vertex Data Containing informatoin for vertex positions and texture coords
   
    struct Vertex {

        DirectX::XMFLOAT3A position;   // Vertex position
        DirectX::XMFLOAT4 color;
        DirectX::XMFLOAT3A normals;

    };


    std::vector<Vertex> CubeData = {

       { DirectX::XMFLOAT3A(-0.5f, 0.0f,  0.5f), BaseColor,DirectX::XMFLOAT3A(0.0f, -1.0f, 0.0f)},
       { DirectX::XMFLOAT3A(-0.5f, 0.0f, -0.5f), BaseColor,DirectX::XMFLOAT3A(0.0f, -1.0f, 0.0f)},
       { DirectX::XMFLOAT3A(0.5f, 0.0f, -0.5f), BaseColor,DirectX::XMFLOAT3A(0.0f, -1.0f, 0.0f)},
       { DirectX::XMFLOAT3A(0.5f, 0.0f,  0.5f), BaseColor,DirectX::XMFLOAT3A(0.0f, -1.0f, 0.0f)},

       // Back face (normal pointing backward along +Z axis)
       { DirectX::XMFLOAT3A(-0.5f, 0.0f,  0.5f),   BaseColor,DirectX::XMFLOAT3A(-0.8f, 0.5f,  0.0f)},
       { DirectX::XMFLOAT3A(-0.5f, 0.0f, -0.5f),   BaseColor,DirectX::XMFLOAT3A(-0.8f, 0.5f,  0.0f)},
       { DirectX::XMFLOAT3A(0.0f, 0.8f,  0.0f),   BaseColor,DirectX::XMFLOAT3A(-0.8f, 0.5f,  0.0f)},
      
        
        { DirectX::XMFLOAT3A(-0.5f, 0.0f, -0.5f),   BaseColor , DirectX::XMFLOAT3A(0.0f, 0.5f, -0.8f)},
        { DirectX::XMFLOAT3A(0.5f, 0.0f, -0.5f),   BaseColor , DirectX::XMFLOAT3A(0.0f, 0.5f, -0.8f) },
        { DirectX::XMFLOAT3A(0.0f, 0.8f,  0.0f),   BaseColor , DirectX::XMFLOAT3A(0.0f, 0.5f, -0.8f) },

     { DirectX::XMFLOAT3A(0.5f, 0.0f, -0.5f),   BaseColor , DirectX::XMFLOAT3A(0.8f, 0.5f,  0.0f) },
     { DirectX::XMFLOAT3A(0.5f, 0.0f,  0.5f),   BaseColor , DirectX::XMFLOAT3A(0.8f, 0.5f,  0.0f) },
     { DirectX::XMFLOAT3A(0.0f, 0.8f,  0.0f),   BaseColor , DirectX::XMFLOAT3A(0.8f, 0.5f,  0.0f) },

      { DirectX::XMFLOAT3A (0.5f, 0.0f,  0.5f),   BaseColor , DirectX::XMFLOAT3A(0.0f, 0.5f,  0.8f) },
      { DirectX::XMFLOAT3A(-0.5f, 0.0f,  0.5f),   BaseColor , DirectX::XMFLOAT3A(0.0f, 0.5f,  0.8f) },
      { DirectX::XMFLOAT3A(0.0f, 0.8f,  0.0f),   BaseColor , DirectX::XMFLOAT3A(0.0f, 0.5f,  0.8f) },



           
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
         {"COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT , 0, 16, D3D11_INPUT_PER_VERTEX_DATA, 0},
         {"NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT , 0, 32, D3D11_INPUT_PER_VERTEX_DATA, 0},


    };

    auto inputLayout = std::make_shared<InputLayout>(device, ied, std::size(ied), pixelShader.get());
    AddBindable(inputLayout);

    ////////////////////////////////////////////////////////////////////////////////////////////////////



}


// stuff to be updated every frame
void Light::Update(ID3D11DeviceContext* context, ID3D11Device* device, Window* windowApp, float updateRotation)
{
    ImGui::Begin("Cube Controls");

    ImGui::SliderFloat3("Cube Position", &Location.x, -200.0f, 200.0f);

    ImGui::End();


    DirectX::XMMATRIX WorldPosition = DirectX::XMMatrixTranspose(

        DirectX::XMMatrixScaling(2.0f, 2.0f, 2.0f)*
        DirectX::XMMatrixRotationZ(updateRotation) *
        DirectX::XMMatrixRotationX(updateRotation) *
        DirectX::XMMatrixTranslation(Location.x, Location.y, Location.z));


    float aspectRatio = static_cast<int>(windowContextHolderHolder->GetWindowWidth()) /
        static_cast<int>(windowContextHolderHolder->GetWindowHeight());

    DirectX::XMMATRIX ProjectionMatrix = DirectX::XMMatrixTranspose(
        DirectX::XMMatrixPerspectiveLH(DirectX::XMConvertToRadians(60),
            aspectRatio, 1.0f, 200.0f));


    DirectX::XMVECTOR cameraPosition = DirectX::XMVectorSet(0.0f, 0.0f, -5.0f, 0.0f); // Camera position
    DirectX::XMVECTOR lookAtPosition = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f); // Point the camera is looking at
    DirectX::XMVECTOR upDirection = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f); // Up direction

    DirectX::XMMATRIX ViewMatrix = XMMatrixTranspose(DirectX::XMMatrixLookAtLH(cameraPosition, lookAtPosition, upDirection));

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


