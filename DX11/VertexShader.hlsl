
struct Data
{
    float3 Color : COLOR;
    float4 Pos : SV_Position;
    
};

cbuffer Cbuf
{
     matrix transform;
};

Data main(float3 pos : POSITION, float3 color : COLOR)
{
    
    Data output;
    
    output.Pos = mul(float4(pos, 1.0f),transform);
    output.Color = color;
    
    return output;

}