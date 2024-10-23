// Texture and Sampler Definition
TextureCube texture0 : register(t0); // Cube texture for the skybox
SamplerState sampler0 : register(s0); // Sampler state

struct VS_OUTPUT
{
    float4 Pos : SV_POSITION;
    float3 TextureCoords : TEXCOORD; // 3D coordinates for cube mapping
    
};

// Pixel Shader
float4 PSMain(VS_OUTPUT input) : SV_TARGET
{
    // Sample the cube texture using 3D texture coordinates
    float4 textureColor = texture0.Sample(sampler0, input.TextureCoords);

    return textureColor; // Return the sampled color
}