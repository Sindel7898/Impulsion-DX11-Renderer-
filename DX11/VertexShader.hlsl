struct VS_OUTPUT
{
    float4 Pos : SV_POSITION;
    float3 Normal : NORMAL;    
    
};

cbuffer Cbuf : register(b0)
{
    matrix WorldMatrix;
    matrix ProjectionMatrix;
    matrix ViewMatrix;
    
};



VS_OUTPUT VSMain(float3 Pos : POSITION, float3 normals : NORMAL, float4 Color : COLOR)
{
    VS_OUTPUT output;
    
    float4 worldPosition = mul(float4(Pos, 1.0f), WorldMatrix);
    
    float4 viewPosition = mul(worldPosition, ViewMatrix);

    output.Pos = mul(viewPosition, ProjectionMatrix);

    
    output.Normal = normalize(mul(float4(normals,0.0f), WorldMatrix));

   
    return output;

}