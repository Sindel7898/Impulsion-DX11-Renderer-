// DiffuseLighting.hlsl

Texture2D texture0 : register(t0);
SamplerState sampler0 : register(s0);

cbuffer LightBuffer : register(b0)
{
    float3 lightPosition ;
    float4 lightColor;
    float constantAtt; // Constant attenuation factor
    float linearAtt; // Linear attenuation factor
    float quadraticAtt; // Q

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
    float4 textureColor = texture0.Sample(sampler0, input.tex);

    // Calculate the light direction
    float3 lightVector = normalize(lightPosition.xyz - input.WorldPosition.xyz);
    
    float distance = length(lightVector);

     
    float attenuation = constantAtt +
                        linearAtt * distance +
                        quadraticAtt * distance * distance;

    
    float diffuseFactor = saturate(dot(input.normal, lightVector));
    
    float4 diffuse = diffuseFactor * lightColor + (lightColor * 0.25) * (1.0f / attenuation) ;
    
    float4 finalColor = textureColor * diffuse;
    
    
    return finalColor;

}
