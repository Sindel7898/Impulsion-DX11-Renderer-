cbuffer ConsBuffer
{
    float3 facecolor[6];
}

float4 main(uint tid : SV_PrimitiveID) : SV_TARGET
{
    return float4(facecolor[tid / 2], 1);

}