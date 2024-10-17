#include"MeshDrawable.h"



MeshDrawable::MeshDrawable(ID3D11Device* device, ID3D11DeviceContext* d3dDeviceContext, Window* windowContextHolder, DirectX::XMFLOAT3 location, std::vector<std::shared_ptr<Light>>& Lights)
    : Location(location), LightsRef(Lights),
    Device(device), D3DDeviceContext(d3dDeviceContext),
    WindowContextHolder1(windowContextHolder)
{

    WindowContextHolder1 = windowContextHolder;

   
    LoadModel("Texture/models/HELMET/model.obj");


    auto vertexBuffer = std::make_shared<VertexBuffer<MeshLoader::ModelVertex>>(device, vertices, 1, 0);
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



    Matrix = std::make_shared<ConstantBuffer<VERTEXDATA>>(device, vertexDatainfo, "Vertex", 0);
    AddBindable(Matrix);



    std::vector<LightData> LightDatainfo;

    for (size_t i = 0; i < LightsRef.size(); i++)
    {
        LightData lightData = {
             LightsRef[i]->GetLocation(),
             LightsRef[i]->GetDirection(),

             LightsRef[i]->GetColor(),
             LightsRef[i]->GetConeDetails(),

             LightsRef[i]->GetAttenuition()
        };

        LightDatainfo.push_back(lightData);
    }

    LightBuffer = std::make_shared<ConstantBuffer<LightData>>(device, LightDatainfo, "Pixel", 0);
    AddBindable(LightBuffer);


    auto texture = std::make_shared<Texture>(Device, D3DDeviceContext,0, L"Texture/models/HELMET/Texture.jpeg");
      AddBindable(texture);

   

    auto indexBuffer = std::make_shared<IndexBuffer>(device, indices);
    AddBindable(indexBuffer);

    ////////////////////////////////////////////////////////////////////

    ////Create pixel and vertex shaders//////////////////////////////////////////////////////
    auto pixelShader = std::make_shared<PixelShader>(device, L"DiffuseLighting.hlsl");
    AddBindable(pixelShader);


    auto vertexShader = std::make_shared<VertexShader>(device, L"BoxVertexShader.hlsl", pixelShader.get());
    AddBindable(vertexShader);
    ///////////////////////////////////////////////////////////////////////////////////////////


    ///INPUT LAYOUT/////////////////////////////////////////////////////////////////////////////
    D3D11_INPUT_ELEMENT_DESC ied[]{

        {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
        {"NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 16, D3D11_INPUT_PER_VERTEX_DATA, 0},
        {"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 32, D3D11_INPUT_PER_VERTEX_DATA, 0},
        {"COLOR", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 48, D3D11_INPUT_PER_VERTEX_DATA, 0},

    };

    auto inputLayout = std::make_shared<InputLayout>(device, ied, std::size(ied), pixelShader.get());
    AddBindable(inputLayout);

    ////////////////////////////////////////////////////////////////////////////////////////////////////  



}


// stuff to be updated every frame
void MeshDrawable::Update(std::vector<std::shared_ptr<Light>>& Lights) {
    LightsRef = Lights;
    ImGui::Begin("Model Controls");

    ImGui::SliderFloat3("Model Position", &Location.x, -50.0f, 50.0f);


    ImGui::SliderFloat3(" Model Scale", &Scaling.x, -50.0f, 50.0f);
    ImGui::SliderFloat3("Model Rotation", &Rotation.x, -360.0f, 360.0f);


    ImGui::End();



    DirectX::XMMATRIX WorldMatrix = DirectX::XMMatrixTranspose(

        DirectX::XMMatrixScaling(Scaling.x, Scaling.y, Scaling.z) *
        DirectX::XMMatrixRotationX(Rotation.x) *
        DirectX::XMMatrixRotationY(Rotation.y) *
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

    for (size_t i = 0; i < Lights.size(); i++)
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

void MeshDrawable::Draw() {

    Bind(D3DDeviceContext);//Bind all the bindables to the object 

    D3DDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    D3D11_VIEWPORT vp{};

    vp.Width = static_cast<float>(WindowContextHolder1->GetWindowWidth());
    vp.Height = static_cast<float>(WindowContextHolder1->GetWindowHeight());
    vp.MaxDepth = 1;
    vp.MinDepth = 0;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;

    D3DDeviceContext->RSSetViewports(1, &vp);

    UINT indexCount = static_cast<UINT>(GetIndices().size());

    D3DDeviceContext->DrawIndexed(indexCount, 0, 0);
}


