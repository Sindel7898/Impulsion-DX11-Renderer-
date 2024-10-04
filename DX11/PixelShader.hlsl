cbuffer LightBuffer : register(b0)
{
    float4 color;

};

  struct VS_OUTPUT
{
    float4 Pos : SV_POSITION;
    float3 Normal : NORMAL;    
};



float4 PSMain(VS_OUTPUT input) : SV_TARGET
{
    
    return color;
}