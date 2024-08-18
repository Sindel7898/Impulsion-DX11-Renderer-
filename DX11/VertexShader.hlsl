
struct Data
{
    float3 Color : COLOR;
    float4 Pos : SV_Position;
    
};

Data main(float2 pos : POSITION, float3 color : COLOR)
{
    
    Data output;
    
    output.Pos = float4(pos.x, pos.y, 0.0f, 1.0f);
    output.Color = color;
    
    return output;

}