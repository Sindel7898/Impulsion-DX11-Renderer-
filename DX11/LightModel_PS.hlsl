// DiffuseLighting.hlsl
#define PI 3.14159265359f // Define pi using #define

Texture2D texture0 : register(t0);
SamplerState sampler0 : register(s0);


Texture2D normalMap : register(t1);
SamplerState samplerNormal : register(s1);

Texture2D emissiveMap : register(t2);
SamplerState sampleremissive : register(s2);

Texture2D RoughnessMap : register(t3);
SamplerState samplerRoughness : register(s3);


Texture2D MetalicMap : register(t4);
SamplerState samplerMetalic : register(s4);

Texture2D AOMap : register(t5);
SamplerState samplerAO : register(s5);

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
    LightData lights[8];
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



float DoAttenuation(LightData light, float distance)
{
    float Attenuation = 1.0f / (light.Attenuition.x + (light.Attenuition.y * distance) + (light.Attenuition.z * pow(distance, 2)));

    return saturate(Attenuation);
}

float4 DoDiffuse(LightData light, float3 LightVector, float3 Normal)
{
   float brightnessMultiplier = 3.0f;
    
    float3 normalizedNormal = normalize(Normal);
    
    float intensity = saturate(dot(normalizedNormal, LightVector));
    float4 colour = saturate(light.lightColor * intensity);
    return colour * brightnessMultiplier;

}

float3 DoSpotCone(LightData light, float3 L)
{
    float minCos = cos(radians(light.ConeParams.x));
    float maxCos = cos(radians(light.ConeParams.y));
    float cosAngle = dot(normalize(light.lightDirection),L);
    return smoothstep(maxCos, minCos, cosAngle);
}

float DistributionGGX(float3 N, float3 H, float a)
{
    float a2 = a * a;
    float NdotH = max(dot(N, H), 0.0);
    float NdotH2 = NdotH * NdotH;

    float nom = a2;
    float denom = (NdotH2 * (a2 - 1.0) + 1.0);
    denom = PI * denom * denom;

    return nom / denom;
}

float GeometrySchlickGGX(float NdotV, float roughness)
{
    float r = (roughness + 1.0);
    float k = (r * r) / 8.0;

    float num = NdotV;
    float denom = NdotV * (1.0 - k) + k;
	
    return num / denom;
}

float GeometrySmith(float3 N, float3 V, float3 L, float roughness)
{
    float NdotV = max(dot(N, V), 0.0);
    float NdotL = max(dot(N, L), 0.0);
    float ggx1 = GeometrySchlickGGX(NdotV, roughness);
    float ggx2 = GeometrySchlickGGX(NdotL, roughness);
	
    return ggx1 * ggx2;
}


float3 fresnelSchlick(float cosTheta, float3 F0)
{
    return F0 + (1.0 - F0) * pow(clamp(1.0 - cosTheta, 0.0, 1.0), 5.0);
}





float4 PSMain(VSOUT input) : SV_TARGET
{
    float4 finalColor = float4(0, 0, 0, 1); // Initialize final color
    float4 textureColor = texture0.Sample(sampler0, input.tex);
    float4 Ambient = { 0.0f, 0.0f, 0.0f, 0.0f };

    
     // Sample normal map and transform from [0, 1] to [-1, 1]
    float3 normalFromMap = normalMap.Sample(samplerNormal, input.tex).xyz * 2.0f - 1.0f;

    // Create TBN (Tangent, Bitangent, Normal) matrix to transform the normal map value to world space
    float3x3 TBN = float3x3(normalize(input.tangent), normalize(input.bitangent), normalize(input.normal));

    // Transform normal map sample to world space using TBN
    float3 transformedNormal = normalize(mul(normalFromMap, TBN));
    
    float4 AO = AOMap.Sample(samplerAO, input.tex);

    
    float4 emissiveColor = emissiveMap.Sample(sampleremissive, input.tex);
    emissiveColor *= input.Emisive;
    
     float roughnessValue = RoughnessMap.Sample(samplerRoughness, input.tex).r;
 
    float MetalicValue = MetalicMap.Sample(samplerMetalic, input.tex).r;

    
    
    
    for (int i = 0; i < 7; i++)
    {

        LightData light = lights[i];
        

        float3 lightVector = normalize(light.lightPosition - input.worldPosition.xyz);
        float distance = length(light.lightPosition - input.worldPosition.xyz);
        float3 HAlfWayVector = normalize(lightVector + input.viewVector); // Halfway vector

        
        float attenuation = saturate(DoAttenuation(light, distance)); // Ensure attenuation is within [0, 1]
        
        
        /////DIffuse///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        float3 F0 = float3(0.04, 0.04, 0.04);
        F0 = lerp(F0, textureColor.rgb, MetalicValue);
        float4 fresnelDiffuse = float4((1.0f - fresnelSchlick(max(dot(transformedNormal, input.viewVector), 0.0), F0)), 1.0f);
        float4 diffuse = DoDiffuse(light, lightVector, transformedNormal) * fresnelDiffuse;

       ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        
        float NDF = DistributionGGX(transformedNormal, HAlfWayVector, roughnessValue);
        float G = GeometrySmith(transformedNormal, input.viewVector, lightVector, roughnessValue);
        float3 F = fresnelSchlick(max(dot(HAlfWayVector, input.viewVector), 0.0), F0);
        
        
        float3 numerator = NDF * G * F;
        float denominator = 4.0 * max(dot(transformedNormal, input.viewVector), 0.0) * max(dot(transformedNormal, lightVector), 0.0) + 0.0001;
        float3 specular = numerator / denominator;
        specular *= light.lightColor.rgb; // Multiply by light color


        
        if (light.LightType.x == 0.0f)
        {
           // finalColor += textureColor * (Ambient + diffuse * attenuation) + (specular * attenuation);
            finalColor += textureColor * (Ambient + diffuse * attenuation) + (float4(specular, 1.0) * attenuation);


        }
        
        if (light.LightType.x == 1.0f)
        {
            float spotEffect = DoSpotCone(light, lightVector);
         //   finalColor += textureColor * (Ambient + diffuse * attenuation) + specular * attenuation * spotEffect;
            finalColor += textureColor * (Ambient + diffuse * attenuation) + float4(specular * attenuation * spotEffect, 1.0);


        }
        
    }
    finalColor += emissiveColor;

    float luminance = dot(finalColor.rgb, float3(0.299, 0.587, 0.114)); // Standard luminance calculation

    // Boost the color channels
    float boostFactor = 2.0f; // Adjust this value as needed
    finalColor.rgb = (finalColor.rgb - luminance) * boostFactor + luminance;
    
    finalColor = saturate(finalColor); // Clamp final color to [0, 1]
    
    return finalColor *= AO;

}
