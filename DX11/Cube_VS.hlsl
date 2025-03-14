// VertexShader.hlsl
cbuffer MatrixBuffer : register(b0)
{
    matrix WorldMatrix;
    matrix ProjectionMatrix;
    matrix ViewMatrix;
    float3 CameraPosition;
};

struct VSIN
{
    float3 position : POSITION;
    float3 normal : NORMAL;
    float2 tex : TEXCOORD;
  
};


struct VSOUT
{
    float4 position : SV_POSITION;
    float4 worldPosition : WorldPosition;
    float3 normal : NORMAL;
    float2 tex : TEXCOORD;
    float3 tangent : TANGENT;
    float3 bitangent : BITANGENT;
    float3 viewVector : TEXCOORD2;
    float Emisive : Emision;
};


VSOUT VSMain(VSIN input)
{
    VSOUT output;
    // Transform the vertex position to clip space
    
    float4 worldPosition = mul(float4(input.position, 1.0f), WorldMatrix);
    float4 viewPosition = mul(worldPosition, ViewMatrix);
    output.position = mul(viewPosition, ProjectionMatrix);

    output.viewVector = normalize(CameraPosition - worldPosition.xyz);

    output.normal = normalize(mul(float4(input.normal, 0.0f), WorldMatrix));
    
    output.worldPosition = worldPosition;
    output.tex = input.tex;
    
    output.Emisive = 0;
    output.tangent = (0.0f, 0.0f, 0.0f);
    output.bitangent = (0.0f, 0.0f, 0.0f);
    return output;
}
