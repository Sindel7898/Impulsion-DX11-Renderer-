struct VS_OUTPUT
{
    float4 Pos : SV_POSITION; // Position in clip space
    float3 TextureCoords : TEXCOORD; // 3D coordinates for cube mapping
};


cbuffer MatrixBuffer : register(b0)
{
    matrix WorldMatrix;
    matrix ProjectionMatrix;
    matrix ViewMatrix;
    float3 CameraPosition;
    float Padding;
};

cbuffer Cbuf : register(b1)
{
    matrix LightViewMatrix; // View matrix for light transformation
    matrix LightProjectionMatrix; // Projection matrix for light
};




VS_OUTPUT VSMain(float3 Pos : POSITION)
{
    VS_OUTPUT output;

    // Transform position to world space
    float4 worldPosition = mul(float4(Pos, 1.0f), WorldMatrix);

    // Transform position to light view space
    float4 lightPosition = mul(worldPosition, LightViewMatrix);

    // Transform position to clip space for shadow mapping
    output.Pos = mul(lightPosition, LightProjectionMatrix); // Use light projection for shadow map rendering

    // Use the world position for cube mapping
    output.TextureCoords = worldPosition.xyz; // Pass the world position as texture coordinates

    return output;
}
