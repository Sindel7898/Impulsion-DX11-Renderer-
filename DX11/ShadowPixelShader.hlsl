Texture2D ShadowMap : register(t0); // Shadow map texture
SamplerState ShadowSampler : register(s0); // Sampler for shadow map

cbuffer LightBuffer : register(b1)
{
    float3 lightPosition;
    float3 lightDirection;
    
    float4 lightColor;
    float2 ConeParams;
    
    float3 Attenuition;
    float2 LightType;
    
};

cbuffer MatrixBuffer : register(b0)
{
    matrix ViewMatrix; // View matrix for the camera
    matrix ProjectionMatrix; // Projection matrix for the camera
};

struct PS_INPUT
{
    float4 Pos : SV_POSITION; // Position in clip space
    float3 TextureCoords : TEXCOORD; // Texture coordinates for cube mapping
};

float4 PSMain(PS_INPUT input) : SV_Target
{
    // Transform fragment position to light space
    float4 lightPos = mul(input.Pos, ViewMatrix);
    lightPos.xyz /= lightPos.w; // Normalize if using perspective projection

    // Calculate shadow map coordinates
    float2 shadowCoord = (lightPos.xy + 1.0) / 2.0; // Convert from [-1, 1] to [0, 1]

    // Sample the shadow map
    float shadowDepth = ShadowMap.Sample(ShadowSampler, shadowCoord).r;

    // Check if the fragment is in shadow
    float visibility = (lightPos.z < shadowDepth) ? 0.5 : 1.0; // Simple shadow comparison

    // Final color (ambient + diffuse) with shadow applied
    float4 finalColor = lightColor * visibility; // Multiply light color with visibility
    float4 Tesdt = { 1.0f, 1.0f, 1.0f, 1.0f };
    return finalColor;
}
