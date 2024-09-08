
  
Texture2D texture0 : register(t0);
SamplerState sampler0 : register(s0);

struct VS_OUTPUT
{
    float4 Position : SV_Position;
    float2 texCoord : TEXCOORD0;

};

float4 PSMain(VS_OUTPUT input) : SV_TARGET
{
    return texture0.Sample(sampler0, input.texCoord);
}