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




Light::Light(ID3D11Device* device, ID3D11DeviceContext* d3dDeviceContext, Window* windowContextHolder, DirectX::XMFLOAT3A location,int lightNumber)
    : Location(location), Device(device), 
      D3DDeviceContext(d3dDeviceContext), 
      WindowContextHolder(windowContextHolder),
      LightNumber(lightNumber)
{
    //Vertex Data Containing informatoin for vertex positions and texture coords
   
    struct Vertex {

        DirectX::XMFLOAT3A position;   // Vertex position
        DirectX::XMFLOAT3A normal;
    };


    std::vector<Vertex> CubeData = {

     // Front face
    { DirectX::XMFLOAT3A(-1.0f, -1.0f, -1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, -1.0f)}, // Bottom-left
    { DirectX::XMFLOAT3A(-1.0f,  1.0f, -1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, -1.0f)}, // Top-left
    { DirectX::XMFLOAT3A(1.0f,  1.0f, -1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, -1.0f)}, // Top-right
    { DirectX::XMFLOAT3A(1.0f, -1.0f, -1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, -1.0f)}, // Bottom-right

    // Back face (Z = 1)
    { DirectX::XMFLOAT3A(-1.0f, -1.0f, 1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, 1.0f)},  // Bottom-left
    { DirectX::XMFLOAT3A(-1.0f,  1.0f, 1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, 1.0f)},  // Top-left
    { DirectX::XMFLOAT3A(1.0f,  1.0f, 1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, 1.0f)},  // Top-right
    { DirectX::XMFLOAT3A(1.0f, -1.0f, 1.0f),  DirectX::XMFLOAT3A(0.0f, 0.0f, 1.0f)},  // Bottom-right

    // Left face (X = -1)
    { DirectX::XMFLOAT3A(-1.0f, -1.0f, -1.0f), DirectX::XMFLOAT3A(-1.0f, 0.0f, 0.0f)},  // Bottom-front
    { DirectX::XMFLOAT3A(-1.0f,  1.0f, -1.0f), DirectX::XMFLOAT3A(-1.0f, 0.0f, 0.0f)},  // Top-front
    { DirectX::XMFLOAT3A(-1.0f,  1.0f,  1.0f), DirectX::XMFLOAT3A(-1.0f, 0.0f, 0.0f)},  // Top-back
    { DirectX::XMFLOAT3A(-1.0f, -1.0f,  1.0f), DirectX::XMFLOAT3A(-1.0f, 0.0f, 0.0f)},  // Bottom-back

    // Right face (X = 1)
    { DirectX::XMFLOAT3A(1.0f, -1.0f, -1.0f),  DirectX::XMFLOAT3A(1.0f, 0.0f, 0.0f)},  // Bottom-front
    { DirectX::XMFLOAT3A(1.0f,  1.0f, -1.0f),  DirectX::XMFLOAT3A(1.0f, 0.0f, 0.0f)},  // Top-front
    { DirectX::XMFLOAT3A(1.0f,  1.0f,  1.0f),  DirectX::XMFLOAT3A(1.0f, 0.0f, 0.0f)},  // Top-back
    { DirectX::XMFLOAT3A(1.0f, -1.0f,  1.0f),  DirectX::XMFLOAT3A(1.0f, 0.0f, 0.0f)},  // Bottom-back

    // Top face (Y = 1)
    { DirectX::XMFLOAT3A(-1.0f, 1.0f, -1.0f),  DirectX::XMFLOAT3A(0.0f, 1.0f, 0.0f)},  // Front-left
    { DirectX::XMFLOAT3A(1.0f, 1.0f, -1.0f),  DirectX::XMFLOAT3A(0.0f, 1.0f, 0.0f)},  // Front-right
    { DirectX::XMFLOAT3A(1.0f, 1.0f,  1.0f),  DirectX::XMFLOAT3A(0.0f, 1.0f, 0.0f)},  // Back-right
    { DirectX::XMFLOAT3A(-1.0f, 1.0f,  1.0f),  DirectX::XMFLOAT3A(0.0f, 1.0f, 0.0f)},  // Back-left

    // Bottom face (Y = -1)
    { DirectX::XMFLOAT3A(-1.0f, -1.0f, -1.0f), DirectX::XMFLOAT3A(0.0f, -1.0f, 0.0f)},  // Front-left
    { DirectX::XMFLOAT3A(1.0f, -1.0f, -1.0f), DirectX::XMFLOAT3A(0.0f, -1.0f, 0.0f)},  // Front-right
    { DirectX::XMFLOAT3A(1.0f, -1.0f,  1.0f), DirectX::XMFLOAT3A(0.0f, -1.0f, 0.0f)},  // Back-right
    { DirectX::XMFLOAT3A(-1.0f, -1.0f,  1.0f), DirectX::XMFLOAT3A(0.0f, -1.0f, 0.0f)},  // Back-left


           
    };

    

    auto vertexBuffer = std::make_shared<VertexBuffer<Vertex>>(device, CubeData,1,0);
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








    std::vector<DirectX::XMFLOAT4> LightPixelData = {

        {BaseColor}
    };


    LightConstantBuffer = std::make_shared<ConstantBuffer<DirectX::XMFLOAT4>>(device, LightPixelData, "Pixel", 0);
    AddBindable(LightConstantBuffer);

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

    }; 

    auto inputLayout = std::make_shared<InputLayout>(device, ied, std::size(ied), pixelShader.get());
    AddBindable(inputLayout);

    ////////////////////////////////////////////////////////////////////////////////////////////////////



}


// stuff to be updated every frame
void Light::Update()
{

    ImGui::Begin("Light Controls");

    ImGui::SliderFloat3(("Light " + std::to_string(LightNumber) + " Position").c_str(), &Location.x, -50.0f, 50.0f);
    //ImGui::SliderFloat3(("Light " + std::to_string(LightNumber) + " Attenition").c_str(), &Attenuition.x, -10.0f, 10.0f);
    ImGui::SliderFloat2(("Light " + std::to_string(LightNumber) + " Cone Details").c_str(), &ConeDetails.x, 0.0f, 100.0f);
    //ImGui::SliderFloat(("Light " + std::to_string(LightNumber) + " quadraticAtt").c_str(), &quadraticAtt, -10.0f, 10.0f);
    ImGui::ColorEdit3(("Light " + std::to_string(LightNumber) + " Color").c_str(), &BaseColor.x);
   
    
    const char* items[] = { "Point Light", "Spot Light"};

    int selectedOption = static_cast<int>(LightType.x);  // Convert LightType.x to an integer for the combo

    if (ImGui::Combo(("Select Option" + std::to_string(LightNumber)).c_str(), reinterpret_cast<int*>(&selectedOption), items, IM_ARRAYSIZE(items))) {

        if (selectedOption == 0) {
            LightType.x = 0.0f;  // Point light
        }
        else if (selectedOption == 1) {
            LightType.x = 1.0f;  // Spot light
        }
      

        ImGui::Text("Selected option: %s", items[selectedOption]);

    }

    ImGui::Text("Current Light Type: %f", LightType.x);

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
    transformationConstantBuffer->Update(D3DDeviceContext, MatrixData);
    //update constant buffer data || LOOK A BIT MORE INTO THIS||


    std::vector<DirectX::XMFLOAT4> LightPixelData = {

      {BaseColor}
    };

    LightConstantBuffer->Update(D3DDeviceContext, LightPixelData);
}

void Light::Draw() {

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

    UINT indexCount = static_cast<UINT>(LightIndex.size());

    D3DDeviceContext->DrawIndexed(indexCount, 0, 0);

}


