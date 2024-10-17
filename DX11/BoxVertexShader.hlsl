// VertexShader.hlsl
cbuffer MatrixBuffer : register(b0)
{
    matrix WorldMatrix;
    matrix ProjectionMatrix;
    matrix ViewMatrix;
    float3 CameraPosition;
    float Padding;
};

struct VSIN
{
    float3 position : POSITION;
    float3 normal : NORMAL;
    float2 tex : TEXCOORD;
    float3 color : COLOR;

};


struct VSOUT
{
    float4 position : SV_POSITION;
    float4 worldPosition : WorldPosition;
    float3 normal : NORMAL;
    float2 tex : TEXCOORD;
    float3 color : COLOR;
    float3 viewVector : TEXCOORD2;

};


VSOUT VSMain(VSIN input)
{
    VSOUT output;
    output.color = input.color; 
    // Transform the vertex position to clip space
    
    float4 worldPosition = mul(float4(input.position, 1.0f), WorldMatrix);
    
    output.viewVector = normalize(CameraPosition - worldPosition.xyz);

    
    float4 viewPosition = mul(worldPosition, ViewMatrix);
    output.position = mul(viewPosition, ProjectionMatrix);


    output.normal = normalize(mul(float4(input.normal, 0.0f), WorldMatrix));
    
    output.worldPosition = worldPosition;
    output.tex = input.tex;
    
    return output;
}
