struct VS_OUTPUT
{
    float4 Position : SV_Position;
    float2 texCoord : TEXCOORD0;

};

cbuffer Cbuf : register(b0)
{
    matrix transform;
};



VS_OUTPUT VSMain(float3 Pos : POSITION, float2 Texture : TEXCOORD)
{
    VS_OUTPUT output;
    
    output.Position = mul(float4(Pos, 1.0f), transform);
    output.texCoord = Texture;
   
    return output;

}