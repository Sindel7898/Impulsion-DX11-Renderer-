#include "SkyBox.h"

SkyBox::SkyBox(ID3D11Device* device, ID3D11DeviceContext* d3dDeviceContext, Window* windowContextHolder)
    :WindowContextHolder(windowContextHolder), Device(device), D3DDeviceContext(d3dDeviceContext)
{

  
    std::vector<SkyBox::Vertex> CubeData = {

        // Front face
       { DirectX::XMFLOAT3A(-1.0f, -1.0f, -1.0f), DirectX::XMFLOAT2A(0.0f, 1.0f) }, // Bottom-left
       { DirectX::XMFLOAT3A(-1.0f,  1.0f, -1.0f), DirectX::XMFLOAT2A(0.0f, 0.0f) }, // Top-left
       { DirectX::XMFLOAT3A(1.0f,  1.0f, -1.0f),  DirectX::XMFLOAT2A(1.0f, 0.0f) }, // Top-right
       { DirectX::XMFLOAT3A(1.0f, -1.0f, -1.0f),  DirectX::XMFLOAT2A(1.0f, 1.0f) }, // Bottom-right

       // Back face (Z = 1)                      
        { DirectX::XMFLOAT3A(-1.0f, -1.0f, 1.0f), DirectX::XMFLOAT2A(1.0f, 1.0f) },  // Bottom-left
        { DirectX::XMFLOAT3A(-1.0f,  1.0f, 1.0f), DirectX::XMFLOAT2A(1.0f, 0.0f) },  // Top-left
        { DirectX::XMFLOAT3A(1.0f,  1.0f, 1.0f), DirectX::XMFLOAT2A(0.0f, 0.0f)  },  // Top-right
        { DirectX::XMFLOAT3A(1.0f, -1.0f, 1.0f), DirectX::XMFLOAT2A(0.0f, 1.0f)  },  // Bottom-right
        // Left face (X = -1)                    
        { DirectX::XMFLOAT3A(-1.0f, -1.0f, -1.0f), DirectX::XMFLOAT2A(1.0f, 1.0f) },  // Bottom-front
        { DirectX::XMFLOAT3A(-1.0f,  1.0f, -1.0f), DirectX::XMFLOAT2A(1.0f, 0.0f) },  // Top-front
        { DirectX::XMFLOAT3A(-1.0f,  1.0f,  1.0f), DirectX::XMFLOAT2A(0.0f, 0.0f) },  // Top-back
        { DirectX::XMFLOAT3A(-1.0f, -1.0f,  1.0f), DirectX::XMFLOAT2A(0.0f, 1.0f) },  // Bottom-back

        // Right face (X = 1)                    
        { DirectX::XMFLOAT3A(1.0f, -1.0f, -1.0f),  DirectX::XMFLOAT2A(0.0f, 1.0f) },  // Bottom-front
        { DirectX::XMFLOAT3A(1.0f,  1.0f, -1.0f),  DirectX::XMFLOAT2A(0.0f, 0.0f) },  // Top-front
       { DirectX::XMFLOAT3A(1.0f,  1.0f,  1.0f),   DirectX::XMFLOAT2A(1.0f, 0.0f) },  // Top-back
        { DirectX::XMFLOAT3A(1.0f, -1.0f,  1.0f),  DirectX::XMFLOAT2A(1.0f, 1.0f) },  // Bottom-back

        // Top face (Y = 1)                      
        { DirectX::XMFLOAT3A(-1.0f, 1.0f, -1.0f),  DirectX::XMFLOAT2A(0.0f, 0.0f) },  // Front-left
        { DirectX::XMFLOAT3A(1.0f, 1.0f, -1.0f),  DirectX::XMFLOAT2A(1.0f, 0.0f), },  // Front-right
        { DirectX::XMFLOAT3A(1.0f, 1.0f,  1.0f) ,  DirectX::XMFLOAT2A(1.0f, 1.0f) },  // Back-right
        { DirectX::XMFLOAT3A(-1.0f, 1.0f,  1.0f),  DirectX::XMFLOAT2A(0.0f, 1.0f) },  // Back-left

        // Bottom face (Y = -1)                  
        { DirectX::XMFLOAT3A(-1.0f, -1.0f, -1.0f), DirectX::XMFLOAT2A(0.0f, 1.0f) },  // Front-left
        { DirectX::XMFLOAT3A(1.0f, -1.0f, -1.0f), DirectX::XMFLOAT2A(1.0f, 1.0f) },  // Front-right
        { DirectX::XMFLOAT3A(1.0f, -1.0f,  1.0f), DirectX::XMFLOAT2A(1.0f, 0.0f) },  // Back-right
        { DirectX::XMFLOAT3A(-1.0f, -1.0f,  1.0f), DirectX::XMFLOAT2A(0.0f, 1.0f) },  // Back-left
    };
   


    auto vertexBuffer = std::make_shared<VertexBuffer<SkyBox::Vertex>>(device, CubeData, 1, 0);
    AddBindable(vertexBuffer);

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

    };

    vertexDatainfo.push_back(VertexData);


    Matrix = std::make_shared<ConstantBuffer<VERTEXDATA>>(device, vertexDatainfo, "Vertex", 0);
    AddBindable(Matrix);


   /* auto texture = std::make_shared<Texture>(Device, D3DDeviceContext, 0, L"Texture/SkyBox.png");
    AddBindable(texture);*/










    /// Create index Buffer/////////////////////////////////////////////////////////////////

    auto indexBuffer = std::make_shared<IndexBuffer>(device, SkyBox::Index);
    AddBindable(indexBuffer);

    ////////////////////////////////////////////////////////////////////

    ////Create pixel and vertex shaders//////////////////////////////////////////////////////
    auto pixelShader = std::make_shared<PixelShader>(device, L"SkyBoxPS.hlsl");
    AddBindable(pixelShader);


    auto vertexShader = std::make_shared<VertexShader>(device, L"SkyBoxVertexShader.hlsl", pixelShader.get());
    AddBindable(vertexShader);
    ///////////////////////////////////////////////////////////////////////////////////////////


    ///INPUT LAYOUT/////////////////////////////////////////////////////////////////////////////
    D3D11_INPUT_ELEMENT_DESC ied[]{

         {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
         {"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 16, D3D11_INPUT_PER_VERTEX_DATA, 0},

    };

    auto inputLayout = std::make_shared<InputLayout>(device, ied, std::size(ied), pixelShader.get());
    AddBindable(inputLayout);

    ////////////////////////////////////////////////////////////////////////////////////////////////////  


}


void SkyBox::Update()
{
    ImGui::Begin("Model Controls");

    ImGui::SliderFloat3("Model Position", &Location.x, -50.0f, 50.0f);



    ImGui::End();



    DirectX::XMMATRIX WorldMatrix = DirectX::XMMatrixTranspose( DirectX::XMMatrixTranslation(0.0f, 0.0f, 0.0f));


    DirectX::XMMATRIX ProjectionMatrix = Camera::GetInstance().GetProjectionMatrix();

    DirectX::XMMATRIX ViewMatrix = Camera::GetInstance().GetViewMatrix();

    DirectX::XMFLOAT3 CameraPosition = Camera::GetInstance().GetPosition();


    VERTEXDATA vertexDatainfo = {

       WorldMatrix,
       ProjectionMatrix,
       ViewMatrix,

    };

    std::vector<VERTEXDATA> VertexData;
    VertexData.push_back(vertexDatainfo);

    Matrix->Update(D3DDeviceContext, VertexData);

}

void SkyBox::Draw()
{

    //D3D11_DEPTH_STENCIL_DESC depthStencilDescSkybox = {};
    //depthStencilDescSkybox.DepthEnable = TRUE;
    //depthStencilDescSkybox.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO; // Disable depth writing
    //depthStencilDescSkybox.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;

    //ID3D11DepthStencilState* depthStencilStateSkybox;
    //Device->CreateDepthStencilState(&depthStencilDescSkybox, &depthStencilStateSkybox);

    //// Set the depth-stencil state for the skybox
    //D3DDeviceContext->OMSetDepthStencilState(depthStencilStateSkybox, 1);


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

    UINT indexCount = static_cast<UINT>(Index.size());

    D3DDeviceContext->DrawIndexed(indexCount, 0, 0);




    //D3D11_DEPTH_STENCIL_DESC depthStencilDescNormal = {};
    //depthStencilDescNormal.DepthEnable = TRUE;
    //depthStencilDescNormal.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL; // Enable depth writing
    //depthStencilDescNormal.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;

    //ID3D11DepthStencilState* depthStencilStateNormal;
    //Device->CreateDepthStencilState(&depthStencilDescNormal, &depthStencilStateNormal);

    //// Set the depth-stencil state for normal rendering
    //D3DDeviceContext->OMSetDepthStencilState(depthStencilStateNormal, 1);

    //// Render other objects here...

    //// Cleanup: Release depth stencil states when no longer needed
    //depthStencilStateSkybox->Release();
    //depthStencilStateNormal->Release();
}



