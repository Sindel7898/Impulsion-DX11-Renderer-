
cbuffer Cbuf
{
    matrix transform;
};





float4 main(float3 Pos : POSITION) : SV_Position
{
    
    return mul(float4(Pos, 1.0f), transform);

}