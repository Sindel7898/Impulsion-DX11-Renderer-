#if 0
//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float       
// COLOR                    0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 0   xy          2     NONE   float       
// TEXCOORD                 1   xyz         3     NONE   float   xyz 
// TEXCOORD                 2   xyz         4     NONE   float       
// TEXCOORD                 3   xyz         5     NONE   float       
// TEXCOORD                 4   xyzw        6     NONE   float       
// TEXCOORD                 5   xyz         7     NONE   float       
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
//
// Constant buffer to DX9 shader constant mappings:
//
// Target Reg Buffer  Start Reg # of Regs        Data Conversion
// ---------- ------- --------- --------- ----------------------
// c0         cb0             0         1  ( FLT, FLT, FLT, FLT)
// c1         cb1             0         5  ( FLT, FLT, FLT, FLT)
// c6         cb1             9         4  ( FLT, FLT, FLT, FLT)
//
//
// Level9 shader bytecode:
//
    ps_2_0
    dcl t0  // pixel<4,5,6,7>
    dcl t2.xyz  // pixel<10,11,12>

#line 95 "C:\Users\Amir sanni\source\repos\DX11\LearnDX\vcpkg_installed\x64-windows\vcpkg\blds\directxtk\src\jun2024-41841b3d9b.clean\Src\Shaders\DGSLLambert.hlsl"
    nrm r0.xyz, t2  // ::worldNormal<0,1,2>

#line 78
    dp3_sat r0.w, c6, r0  // ::diffuseAmount<0>
    mul r1.xyz, r0.w, c2
    mul r1.xyz, r1, t0  // ::diffuse<0,1,2>

#line 101
    mov r2.xyz, c0  // MaterialVars::MaterialAmbient<0,1,2>
    mad r1.xyz, r2, c1, r1  // ::local3<0,1,2>

#line 78
    dp3_sat r0.w, c7, r0  // ::diffuseAmount<0>
    mul r2.xyz, r0.w, c3

#line 101
    mad r1.xyz, r2, t0, r1  // ::local3<0,1,2>

#line 78
    dp3_sat r0.w, c8, r0  // ::diffuseAmount<0>
    dp3_sat r1.w, c9, r0  // ::diffuseAmount<0>
    mul r0.xyz, r1.w, c5
    mul r2.xyz, r0.w, c4

#line 101
    mad r1.xyz, r2, t0, r1  // ::local3<0,1,2>
    mad_sat r0.xyz, r0, t0, r1  // ::local3<0,1,2>

#line 104
    mov r0.w, t0.w
    mov oC0, r0  // ::main<0,1,2,3>

// approximately 19 instruction slots used
ps_4_0
dcl_constantbuffer CB0[1], immediateIndexed
dcl_constantbuffer CB1[13], immediateIndexed
dcl_input_ps linear v1.xyzw
dcl_input_ps linear v3.xyz
dcl_output o0.xyzw
dcl_temps 3
dp3 r0.x, v3.xyzx, v3.xyzx
rsq r0.x, r0.x
mul r0.xyz, r0.xxxx, v3.xyzx
dp3_sat r0.w, cb1[9].xyzx, r0.xyzx
mul r1.xyz, r0.wwww, cb1[1].xyzx
mul r1.xyz, r1.xyzx, v1.xyzx
mad r1.xyz, cb0[0].xyzx, cb1[0].xyzx, r1.xyzx
dp3_sat r0.w, cb1[10].xyzx, r0.xyzx
mul r2.xyz, r0.wwww, cb1[2].xyzx
mad r1.xyz, r2.xyzx, v1.xyzx, r1.xyzx
dp3_sat r0.w, cb1[11].xyzx, r0.xyzx
dp3_sat r0.x, cb1[12].xyzx, r0.xyzx
mul r0.xyz, r0.xxxx, cb1[4].xyzx
mul r2.xyz, r0.wwww, cb1[3].xyzx
mad r1.xyz, r2.xyzx, v1.xyzx, r1.xyzx
mad_sat o0.xyz, r0.xyzx, v1.xyzx, r1.xyzx
mov o0.w, v1.w
ret 
// Approximately 0 instruction slots used
#endif

const BYTE DGSLLambert_main[] =
{
     68,  88,  66,  67, 132, 169, 
    108, 250, 139, 143, 120, 117, 
    205,  91,  10, 183,  11, 207, 
    248, 194,   1,   0,   0,   0, 
     84,   9,   0,   0,   4,   0, 
      0,   0,  48,   0,   0,   0, 
    192,   5,   0,   0,  52,   8, 
      0,   0,  32,   9,   0,   0, 
     65, 111, 110,  57, 136,   5, 
      0,   0, 136,   5,   0,   0, 
      0,   2, 255, 255,  64,   5, 
      0,   0,  72,   0,   0,   0, 
      3,   0,  36,   0,   0,   0, 
     72,   0,   0,   0,  72,   0, 
      0,   0,  36,   0,   0,   0, 
     72,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      5,   0,   1,   0,   0,   0, 
      0,   0,   1,   0,   9,   0, 
      4,   0,   6,   0,   0,   0, 
      0,   0,   0,   2, 255, 255, 
    254, 255,   3,   1,  68,  66, 
     85,  71,  40,   0,   0,   0, 
    224,   3,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
    196,   0,   0,   0,  19,   0, 
      0,   0, 200,   0,   0,   0, 
      7,   0,   0,   0,  84,   3, 
      0,   0,  72,   2,   0,   0, 
     67,  58,  92,  85, 115, 101, 
    114, 115,  92,  65, 109, 105, 
    114,  32, 115,  97, 110, 110, 
    105,  92, 115, 111, 117, 114, 
     99, 101,  92, 114, 101, 112, 
    111, 115,  92,  68,  88,  49, 
     49,  92,  76, 101,  97, 114, 
    110,  68,  88,  92, 118,  99, 
    112, 107, 103,  95, 105, 110, 
    115, 116,  97, 108, 108, 101, 
    100,  92, 120,  54,  52,  45, 
    119, 105, 110, 100, 111, 119, 
    115,  92, 118,  99, 112, 107, 
    103,  92,  98, 108, 100, 115, 
     92, 100, 105, 114, 101,  99, 
    116, 120, 116, 107,  92, 115, 
    114,  99,  92, 106, 117, 110, 
     50,  48,  50,  52,  45,  52, 
     49,  56,  52,  49,  98,  51, 
    100,  57,  98,  46,  99, 108, 
    101,  97, 110,  92,  83, 114, 
     99,  92,  83, 104,  97, 100, 
    101, 114, 115,  92,  68,  71, 
     83,  76,  76,  97, 109,  98, 
    101, 114, 116,  46, 104, 108, 
    115, 108,   0, 171, 171, 171, 
     40,   0,   0,   0,   0,   0, 
    255, 255,  20,   4,   0,   0, 
      0,   0, 255, 255,  32,   4, 
      0,   0,  95,   0,   0,   0, 
     44,   4,   0,   0,  78,   0, 
      0,   0,  56,   4,   0,   0, 
     79,   0,   0,   0,  72,   4, 
      0,   0,  79,   0,   0,   0, 
     88,   4,   0,   0, 101,   0, 
      0,   0, 104,   4,   0,   0, 
    101,   0,   0,   0, 116,   4, 
      0,   0,  78,   0,   0,   0, 
    136,   4,   0,   0,  79,   0, 
      0,   0, 152,   4,   0,   0, 
    101,   0,   0,   0, 168,   4, 
      0,   0,  78,   0,   0,   0, 
    188,   4,   0,   0,  78,   0, 
      0,   0, 204,   4,   0,   0, 
     79,   0,   0,   0, 220,   4, 
      0,   0,  79,   0,   0,   0, 
    236,   4,   0,   0, 101,   0, 
      0,   0, 252,   4,   0,   0, 
    101,   0,   0,   0,  16,   5, 
      0,   0, 104,   0,   0,   0, 
     36,   5,   0,   0, 104,   0, 
      0,   0,  48,   5,   0,   0, 
     77,  97, 116, 101, 114, 105, 
     97, 108,  86,  97, 114, 115, 
      0,  77,  97, 116, 101, 114, 
    105,  97, 108,  65, 109,  98, 
    105, 101, 110, 116,   0, 171, 
    171, 171,   1,   0,   3,   0, 
      1,   0,   4,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      6,   0,   0,   0,   0,   0, 
      1,   0,   2,   0, 255, 255, 
    100, 105, 102, 102, 117, 115, 
    101,   0,   1,   0,   3,   0, 
      1,   0,   3,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      5,   0,   0,   0,   0,   0, 
      1,   0,   2,   0, 255, 255, 
    100, 105, 102, 102, 117, 115, 
    101,  65, 109, 111, 117, 110, 
    116,   0, 171, 171,   0,   0, 
      3,   0,   1,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
      0,   0,   8,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
      0,   0,  11,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
      0,   0,  12,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
      0,   0, 108, 111,  99,  97, 
    108,  51,   0, 171,   7,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0, 255, 255,  10,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0, 255, 255,  15,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0, 255, 255,  16,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0, 255, 255, 109,  97, 
    105, 110,   0, 102, 114,  97, 
    103, 109, 101, 110, 116,   0, 
    171, 171,   1,   0,   3,   0, 
      1,   0,   4,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     77,   2,   0,   0,  88,   2, 
      0,   0,   5,   0,   0,   0, 
      1,   0,   4,   0,   1,   0, 
      1,   0, 104,   2,   0,   0, 
     18,   0,   0,   0,   0,   0, 
      1,   0,   2,   0,   3,   0, 
    112, 105, 120, 101, 108,   0, 
    112, 111, 115,   0, 117, 118, 
      0, 171, 171, 171,   1,   0, 
      3,   0,   1,   0,   2,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0, 119, 111, 114, 108, 
    100,  78, 111, 114, 109,   0, 
    119, 111, 114, 108, 100,  80, 
    111, 115,   0, 116, 111,  69, 
    121, 101,   0, 116,  97, 110, 
    103, 101, 110, 116,   0, 110, 
    111, 114, 109,  97, 108,   0, 
    146,   2,   0,   0,  88,   2, 
      0,   0, 156,   1,   0,   0, 
     88,   2,   0,   0, 150,   2, 
      0,   0, 156,   2,   0,   0, 
    172,   2,   0,   0, 164,   1, 
      0,   0, 182,   2,   0,   0, 
    164,   1,   0,   0, 191,   2, 
      0,   0, 164,   1,   0,   0, 
    197,   2,   0,   0,  88,   2, 
      0,   0, 205,   2,   0,   0, 
    164,   1,   0,   0,   5,   0, 
      0,   0,   1,   0,  26,   0, 
      1,   0,   8,   0, 212,   2, 
      0,   0,   0,   0,   0,   0, 
      4,   0,   5,   0,   6,   0, 
      7,   0,   1,   0,   0,   0, 
     10,   0,  11,   0,  12,   0, 
    255, 255, 119, 111, 114, 108, 
    100,  78, 111, 114, 109,  97, 
    108,   0,   2,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
    255, 255,  96,   1,   0,   0, 
    109,   1,   0,   0, 128,   1, 
      0,   0,   1,   0,   0,   0, 
    144,   1,   0,   0,   0,   0, 
      0,   0, 156,   1,   0,   0, 
    164,   1,   0,   0,   1,   0, 
      0,   0, 180,   1,   0,   0, 
      0,   0,   0,   0, 192,   1, 
      0,   0, 208,   1,   0,   0, 
      4,   0,   0,   0, 224,   1, 
      0,   0,   0,   0,   0,   0, 
     16,   2,   0,   0, 164,   1, 
      0,   0,   4,   0,   0,   0, 
     24,   2,   0,   0,   0,   0, 
      0,   0,  72,   2,   0,   0, 
    112,   2,   0,   0,   1,   0, 
      0,   0, 128,   2,   0,   0, 
     72,   2,   0,   0, 140,   2, 
      0,   0,  20,   3,   0,   0, 
      2,   0,   0,   0,  36,   3, 
      0,   0,   0,   0,   0,   0, 
     60,   3,   0,   0, 164,   1, 
      0,   0,   1,   0,   0,   0, 
     72,   3,   0,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  49,  48,  46, 
     49,   0,  31,   0,   0,   2, 
      0,   0,   0, 128,   0,   0, 
     15, 176,  31,   0,   0,   2, 
      0,   0,   0, 128,   2,   0, 
      7, 176,  36,   0,   0,   2, 
      0,   0,   7, 128,   2,   0, 
    228, 176,   8,   0,   0,   3, 
      0,   0,  24, 128,   6,   0, 
    228, 160,   0,   0, 228, 128, 
      5,   0,   0,   3,   1,   0, 
      7, 128,   0,   0, 255, 128, 
      2,   0, 228, 160,   5,   0, 
      0,   3,   1,   0,   7, 128, 
      1,   0, 228, 128,   0,   0, 
    228, 176,   1,   0,   0,   2, 
      2,   0,   7, 128,   0,   0, 
    228, 160,   4,   0,   0,   4, 
      1,   0,   7, 128,   2,   0, 
    228, 128,   1,   0, 228, 160, 
      1,   0, 228, 128,   8,   0, 
      0,   3,   0,   0,  24, 128, 
      7,   0, 228, 160,   0,   0, 
    228, 128,   5,   0,   0,   3, 
      2,   0,   7, 128,   0,   0, 
    255, 128,   3,   0, 228, 160, 
      4,   0,   0,   4,   1,   0, 
      7, 128,   2,   0, 228, 128, 
      0,   0, 228, 176,   1,   0, 
    228, 128,   8,   0,   0,   3, 
      0,   0,  24, 128,   8,   0, 
    228, 160,   0,   0, 228, 128, 
      8,   0,   0,   3,   1,   0, 
     24, 128,   9,   0, 228, 160, 
      0,   0, 228, 128,   5,   0, 
      0,   3,   0,   0,   7, 128, 
      1,   0, 255, 128,   5,   0, 
    228, 160,   5,   0,   0,   3, 
      2,   0,   7, 128,   0,   0, 
    255, 128,   4,   0, 228, 160, 
      4,   0,   0,   4,   1,   0, 
      7, 128,   2,   0, 228, 128, 
      0,   0, 228, 176,   1,   0, 
    228, 128,   4,   0,   0,   4, 
      0,   0,  23, 128,   0,   0, 
    228, 128,   0,   0, 228, 176, 
      1,   0, 228, 128,   1,   0, 
      0,   2,   0,   0,   8, 128, 
      0,   0, 255, 176,   1,   0, 
      0,   2,   0,   8,  15, 128, 
      0,   0, 228, 128, 255, 255, 
      0,   0,  83,  72,  68,  82, 
    108,   2,   0,   0,  64,   0, 
      0,   0, 155,   0,   0,   0, 
     89,   0,   0,   4,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,  89,   0, 
      0,   4,  70, 142,  32,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0,  98,  16,   0,   3, 
    242,  16,  16,   0,   1,   0, 
      0,   0,  98,  16,   0,   3, 
    114,  16,  16,   0,   3,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   0,   0, 
      0,   0, 104,   0,   0,   2, 
      3,   0,   0,   0,  16,   0, 
      0,   7,  18,   0,  16,   0, 
      0,   0,   0,   0,  70,  18, 
     16,   0,   3,   0,   0,   0, 
     70,  18,  16,   0,   3,   0, 
      0,   0,  68,   0,   0,   5, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   7, 114,   0,  16,   0, 
      0,   0,   0,   0,   6,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  18,  16,   0,   3,   0, 
      0,   0,  16,  32,   0,   8, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  70, 130,  32,   0, 
      1,   0,   0,   0,   9,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   8, 114,   0,  16,   0, 
      1,   0,   0,   0, 246,  15, 
     16,   0,   0,   0,   0,   0, 
     70, 130,  32,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     56,   0,   0,   7, 114,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  70,  18,  16,   0, 
      1,   0,   0,   0,  50,   0, 
      0,  11, 114,   0,  16,   0, 
      1,   0,   0,   0,  70, 130, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  70, 130, 
     32,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     16,  32,   0,   8, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     70, 130,  32,   0,   1,   0, 
      0,   0,  10,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   8, 
    114,   0,  16,   0,   2,   0, 
      0,   0, 246,  15,  16,   0, 
      0,   0,   0,   0,  70, 130, 
     32,   0,   1,   0,   0,   0, 
      2,   0,   0,   0,  50,   0, 
      0,   9, 114,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     70,  18,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  16,  32, 
      0,   8, 130,   0,  16,   0, 
      0,   0,   0,   0,  70, 130, 
     32,   0,   1,   0,   0,   0, 
     11,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     16,  32,   0,   8,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     70, 130,  32,   0,   1,   0, 
      0,   0,  12,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   8, 
    114,   0,  16,   0,   0,   0, 
      0,   0,   6,   0,  16,   0, 
      0,   0,   0,   0,  70, 130, 
     32,   0,   1,   0,   0,   0, 
      4,   0,   0,   0,  56,   0, 
      0,   8, 114,   0,  16,   0, 
      2,   0,   0,   0, 246,  15, 
     16,   0,   0,   0,   0,   0, 
     70, 130,  32,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
     50,   0,   0,   9, 114,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  70,  18,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     50,  32,   0,   9, 114,  32, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  70,  18,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     54,   0,   0,   5, 130,  32, 
     16,   0,   0,   0,   0,   0, 
     58,  16,  16,   0,   1,   0, 
      0,   0,  62,   0,   0,   1, 
     73,  83,  71,  78, 228,   0, 
      0,   0,   8,   0,   0,   0, 
      8,   0,   0,   0, 200,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0, 212,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     15,  15,   0,   0, 218,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
      3,   0,   0,   0, 218,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
      7,   7,   0,   0, 218,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   4,   0,   0,   0, 
      7,   0,   0,   0, 218,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   5,   0,   0,   0, 
      7,   0,   0,   0, 218,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   6,   0,   0,   0, 
     15,   0,   0,   0, 218,   0, 
      0,   0,   5,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   7,   0,   0,   0, 
      7,   0,   0,   0,  83,  86, 
     95,  80,  79,  83,  73,  84, 
     73,  79,  78,   0,  67,  79, 
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