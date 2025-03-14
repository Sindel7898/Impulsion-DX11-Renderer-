#if 0
//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// COLOR                    0   xyzw        0     NONE   float   xyzw
// TEXCOORD                 0   xy          1     NONE   float   xy  
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
//
// Sampler/Resource to DX9 shader sampler mappings:
//
// Target Sampler Source Sampler  Source Resource
// -------------- --------------- ----------------
// s0             s0              t0               
//
//
// Level9 shader bytecode:
//
    ps_2_0
    dcl t0  // pin<0,1,2,3>
    dcl t1.xy  // pin<4,5>
    dcl_2d s0

#line 521 "C:\Users\Amir sanni\source\repos\DX11\LearnDX\vcpkg_installed\x64-windows\vcpkg\blds\directxtk\src\jun2024-41841b3d9b.clean\Src\Shaders\BasicEffect.fx"
    texld r0, t1, s0
    mul r0, r0, t0  // ::PSBasicTxNoFog<0,1,2,3>
    mov oC0, r0  // ::PSBasicTxNoFog<0,1,2,3>

// approximately 3 instruction slots used (1 texture, 2 arithmetic)
ps_4_0
dcl_sampler s0, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_input_ps linear v0.xyzw
dcl_input_ps linear v1.xy
dcl_output o0.xyzw
dcl_temps 1
sample r0.xyzw, v1.xyxx, t0.xyzw, s0
mul o0.xyzw, r0.xyzw, v0.xyzw
ret 
// Approximately 0 instruction slots used
#endif

const BYTE BasicEffect_PSBasicTxNoFog[] =
{
     68,  88,  66,  67, 113, 208, 
    233, 232, 232,  62, 124, 195, 
     25,  60, 217, 228, 140, 114, 
    138,  79,   1,   0,   0,   0, 
    204,   3,   0,   0,   4,   0, 
      0,   0,  48,   0,   0,   0, 
    172,   2,   0,   0,  72,   3, 
      0,   0, 152,   3,   0,   0, 
     65, 111, 110,  57, 116,   2, 
      0,   0, 116,   2,   0,   0, 
      0,   2, 255, 255,  76,   2, 
      0,   0,  40,   0,   0,   0, 
      0,   0,  40,   0,   0,   0, 
     40,   0,   0,   0,  40,   0, 
      1,   0,  36,   0,   0,   0, 
     40,   0,   0,   0,   0,   0, 
      0,   2, 255, 255, 254, 255, 
    124,   0,  68,  66,  85,  71, 
     40,   0,   0,   0, 196,   1, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0, 192,   0, 
      0,   0,   6,   0,   0,   0, 
    196,   0,   0,   0,   2,   0, 
      0,   0, 156,   1,   0,   0, 
    244,   0,   0,   0,  67,  58, 
     92,  85, 115, 101, 114, 115, 
     92,  65, 109, 105, 114,  32, 
    115,  97, 110, 110, 105,  92, 
    115, 111, 117, 114,  99, 101, 
     92, 114, 101, 112, 111, 115, 
     92,  68,  88,  49,  49,  92, 
     76, 101,  97, 114, 110,  68, 
     88,  92, 118,  99, 112, 107, 
    103,  95, 105, 110, 115, 116, 
     97, 108, 108, 101, 100,  92, 
    120,  54,  52,  45, 119, 105, 
    110, 100, 111, 119, 115,  92, 
    118,  99, 112, 107, 103,  92, 
     98, 108, 100, 115,  92, 100, 
    105, 114, 101,  99, 116, 120, 
    116, 107,  92, 115, 114,  99, 
     92, 106, 117, 110,  50,  48, 
     50,  52,  45,  52,  49,  56, 
     52,  49,  98,  51, 100,  57, 
     98,  46,  99, 108, 101,  97, 
    110,  92,  83, 114,  99,  92, 
     83, 104,  97, 100, 101, 114, 
    115,  92,  66,  97, 115, 105, 
     99,  69, 102, 102, 101,  99, 
    116,  46, 102, 120,   0, 171, 
     40,   0,   0,   0,   0,   0, 
    255, 255, 248,   1,   0,   0, 
      0,   0, 255, 255,   4,   2, 
      0,   0,   0,   0, 255, 255, 
     16,   2,   0,   0,   9,   2, 
      0,   0,  28,   2,   0,   0, 
      9,   2,   0,   0,  44,   2, 
      0,   0,   9,   2,   0,   0, 
     60,   2,   0,   0,  80,  83, 
     66,  97, 115, 105,  99,  84, 
    120,  78, 111,  70, 111, 103, 
      0, 171,   1,   0,   3,   0, 
      1,   0,   4,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      1,   0,   2,   0,   3,   0, 
      5,   0,   0,   0,   0,   0, 
      1,   0,   2,   0,   3,   0, 
    112, 105, 110,   0,  68, 105, 
    102, 102, 117, 115, 101,   0, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  84, 101, 
    120,  67, 111, 111, 114, 100, 
      0, 171, 171, 171,   1,   0, 
      3,   0,   1,   0,   2,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  48,   1,   0,   0, 
     56,   1,   0,   0,  72,   1, 
      0,   0,  84,   1,   0,   0, 
      5,   0,   0,   0,   1,   0, 
      6,   0,   1,   0,   2,   0, 
    100,   1,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0,   3,   0,   1,   0, 
      0,   0,   4,   0,   5,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 244,   0,   0,   0, 
      4,   1,   0,   0,   2,   0, 
      0,   0,  20,   1,   0,   0, 
    244,   0,   0,   0,  44,   1, 
      0,   0, 116,   1,   0,   0, 
      2,   0,   0,   0, 132,   1, 
      0,   0,  77, 105,  99, 114, 
    111, 115, 111, 102, 116,  32, 
     40,  82,  41,  32,  72,  76, 
     83,  76,  32,  83, 104,  97, 
    100, 101, 114,  32,  67, 111, 
    109, 112, 105, 108, 101, 114, 
     32,  49,  48,  46,  49,   0, 
     31,   0,   0,   2,   0,   0, 
      0, 128,   0,   0,  15, 176, 
     31,   0,   0,   2,   0,   0, 
      0, 128,   1,   0,   3, 176, 
     31,   0,   0,   2,   0,   0, 
      0, 144,   0,   8,  15, 160, 
     66,   0,   0,   3,   0,   0, 
     15, 128,   1,   0, 228, 176, 
      0,   8, 228, 160,   5,   0, 
      0,   3,   0,   0,  15, 128, 
      0,   0, 228, 128,   0,   0, 
    228, 176,   1,   0,   0,   2, 
      0,   8,  15, 128,   0,   0, 
    228, 128, 255, 255,   0,   0, 
     83,  72,  68,  82, 148,   0, 
      0,   0,  64,   0,   0,   0, 
     37,   0,   0,   0,  90,   0, 
      0,   3,   0,  96,  16,   0, 
      0,   0,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      0,   0,   0,   0,  85,  85, 
      0,   0,  98,  16,   0,   3, 
    242,  16,  16,   0,   0,   0, 
      0,   0,  98,  16,   0,   3, 
     50,  16,  16,   0,   1,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   0,   0, 
      0,   0, 104,   0,   0,   2, 
      1,   0,   0,   0,  69,   0, 
      0,   9, 242,   0,  16,   0, 
      0,   0,   0,   0,  70,  16, 
     16,   0,   1,   0,   0,   0, 
     70, 126,  16,   0,   0,   0, 
      0,   0,   0,  96,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   7, 242,  32,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     70,  30,  16,   0,   0,   0, 
      0,   0,  62,   0,   0,   1, 
     73,  83,  71,  78,  72,   0, 
      0,   0,   2,   0,   0,   0, 
      8,   0,   0,   0,  56,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,  15,   0,   0,  62,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   3,   0,   0,  67,  79, 
     76,  79,  82,   0,  84,  69, 
     88,  67,  79,  79,  82,  68, 
      0, 171,  79,  83,  71,  78, 
     44,   0,   0,   0,   1,   0, 
      0,   0,   8,   0,   0,   0, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
     83,  86,  95,  84,  97, 114, 
    103, 101, 116,   0, 171, 171
};
