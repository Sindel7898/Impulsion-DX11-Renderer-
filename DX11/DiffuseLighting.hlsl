// DiffuseLighting.hlsl

Texture2D texture0 : register(t0);
SamplerState sampler0 : register(s0);

cbuffer LightBuffer : register(b0)
{
    float3 lightPosition ;
    float4 lightColor;
};

struct VSOUT
{
    float4 position : SV_POSITION;
    float4 WorldPosition : WorldPosition;
    float3 normal : NORMAL;
    float2 tex : TEXCOORD;
    float3 color : COLOR;
   
};


float4 PSMain(VSOUT input) : SV_TARGET
{
    float lightIntensity = 1.0;
    // Calculate the light direction
    float3 lightDir = normalize(lightPosition.xyz - input.WorldPosition.xyz);
    
    float diffuseFactor = saturate(dot(input.normal, lightDir));
    
    float4 diffuse = diffuseFactor * lightColor * lightIntensity;
    
    float4 finalColor = saturate(float4(input.color, 1.0f) * diffuse);
    
   // return float4(finalColor, 1);

    float4 textureColor = texture0.Sample(sampler0, input.tex);
    textureColor *= finalColor;
    
    
    return textureColor;

}
