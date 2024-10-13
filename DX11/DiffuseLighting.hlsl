// DiffuseLighting.hlsl

Texture2D texture0 : register(t0);
SamplerState sampler0 : register(s0);


Texture2D normalMap : register(t1);
SamplerState samplerNormal : register(s1);

struct LightData
{
    float3 lightPosition ;
    float3 lightDirection;
    
    float4 lightColor;
    float2 ConeParams;
    
    float3 Attenuition;
    float2 LightType;

};

cbuffer LightBuffer : register(b0)
{
    LightData lights[1];
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



float DoAttenuation(LightData light, float distance)
{
    float Attenuation = 1.0f / (light.Attenuition.x + (light.Attenuition.y * distance) + (light.Attenuition.z * pow(distance, 2)));

    return saturate(Attenuation);
}

float4 DoDiffuse(LightData light, float3 LightVector, float3 Normal)
{
    float brightnessMultiplier = 2.0f;
    float3 normalizedNormal = normalize(Normal);

    float diffuseFactor = saturate(dot(normalizedNormal, LightVector));
    return light.lightColor * diffuseFactor * brightnessMultiplier;
}

float3 DoSpotCone(LightData light, float3 L)
{
    float minCos = cos(radians(light.ConeParams.x));
    float maxCos = cos(radians(light.ConeParams.y));
    float cosAngle = dot(normalize(light.lightDirection),L);
    return smoothstep(maxCos, minCos, cosAngle);
}

float4 calcSpecular(float3 lightDirection, float3 normal, float3 viewVector, float4 specularColour, float specularPower)
{
// blinn-phong specular calculation
    float3 halfway = normalize(lightDirection + viewVector);
    float specularIntensity = pow(max(dot(normal, halfway), 0.0), specularPower);
    return saturate(specularColour * specularIntensity);
}


float4 PSMain(VSOUT input) : SV_TARGET
{
    float4 finalColor = float4(0, 0, 0, 1); // Initialize final color
    float4 textureColor = texture0.Sample(sampler0, input.tex);
    float4 SpecularColor = { 1.0f, 1.0f, 1.0f, 1.0f };

    for (int i = 0; i < 1; i++)
    {
        LightData light = lights[i];
        
        float distance = length(light.lightPosition - input.worldPosition.xyz);
        float attenuation = DoAttenuation(light, distance);

        float3 lightVector = normalize(light.lightPosition - input.worldPosition.xyz);
        
        float4 diffuse = DoDiffuse(light, lightVector, input.normal);

        float4 Specular = calcSpecular(lightVector, input.normal, input.viewVector, SpecularColor, 16.0f);

        if (light.LightType.x == 0.0f)
        {
           finalColor += textureColor * diffuse + Specular * attenuation;

        }
        
        if (light.LightType.x == 1.0f)
        {
            float spotEffect = DoSpotCone(light, lightVector);
            finalColor += textureColor * diffuse + Specular * attenuation * spotEffect;

        }
        
    }
    
    finalColor = saturate(finalColor);

    return finalColor;

}
