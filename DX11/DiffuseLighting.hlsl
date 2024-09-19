// DiffuseLighting.hlsl

cbuffer LightBuffer : register(b0)
{
    float3 lightPosition : SV_POSITION;
    float4 lightColor;
};

struct VSOUT
{
    float4 position : SV_POSITION;
    float3 normal : NORMAL;
    float3 color : COLOR;
    
};


float4 PSMain(VSOUT input) : SV_TARGET
{
    // Calculate the light direction
    float3 lightDir = normalize(lightPosition - input.position.xyz);
    
    float diffuseFactor = saturate(dot(input.normal, lightDir));
    
    float4 diffuse = diffuseFactor * lightColor;
    
    float4 finalColor = saturate(float4(input.color, 1.0f) * diffuse);
    
    //return float4(input.color, 1);

    return finalColor;

}
