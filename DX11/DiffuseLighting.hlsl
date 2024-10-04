// DiffuseLighting.hlsl

Texture2D texture0 : register(t0);
SamplerState sampler0 : register(s0);



struct LightData
{
    float3 lightPosition ;
    float4 lightColor;
    float constantAtt; // Constant attenuation factor
    float linearAtt; // Linear attenuation factor
    float quadraticAtt; // Q

};

cbuffer LightBuffer : register(b0)
{
    LightData lights[5];
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
    float4 finalColor = float4(0, 0, 0, 1); // Initialize final color
    float4 textureColor = texture0.Sample(sampler0, input.tex);

    
    for (int i = 0; i < 5; i++)
    {
        LightData light = lights[i];

        float3 lightVector = normalize(light.lightPosition.xyz - input.WorldPosition.xyz);
    
        float distance = length(lightVector);

     
        float attenuation = light.constantAtt +
                        light.linearAtt * distance +
                        light.quadraticAtt * distance * distance;

    
        float diffuseFactor = saturate(dot(input.normal, lightVector));
    
        float4 diffuse = diffuseFactor * light.lightColor  * (1.0f / attenuation);
    
        finalColor += textureColor * diffuse;
    }
    
    //finalColor = saturate(finalColor);

    return finalColor;

}
