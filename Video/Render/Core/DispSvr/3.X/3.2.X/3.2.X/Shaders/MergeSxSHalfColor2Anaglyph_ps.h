#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.27.952.3022
//
//   fxc /T ps_3_0 /Fh MergeSxSHalfColor2Anaglyph_ps.h -E
//    MergeSxSHalfColor2Anaglyph_PS MergeSxSAnaglyph.psh
//
//
// Parameters:
//
//   float $saturation;
//   sampler2D texture0;
//
//
// Registers:
//
//   Name         Reg   Size
//   ------------ ----- ----
//   $saturation  c0       1
//   texture0     s0       1
//

    ps_3_0
    def c1, 0.298999995, 0.587000012, 0.114, 0.5
    def c2, 0.166666672, 0.333333343, 0.666666687, 0
    def c3, 1, -1, 6, 0
    def c4, -1, -2, -3, -4
    dcl_texcoord v0
    dcl_2d s0
    texld r0, v0, s0
    dp3 r0.x, r0, c1
    min r1.x, r0.y, r0.x
    min r2.x, r0.z, r1.x
    max r1.x, r0.y, r0.x
    max r2.y, r0.z, r1.x
    add r0.w, -r2.x, r2.y
    mul r1.x, r0.w, c1.w
    add r1.yzw, -r0.xyzx, r2.y
    add r0.xyz, r0, -r2.y
    mad r1.xyz, r1.yzww, c2.x, r1.x
    rcp r1.w, r0.w
    mad r2.xz, r1.zyxw, r1.w, c2.yyzw
    mad r2.xz, r1.yyzw, -r1.w, r2
    cmp r0.z, -r0_abs.z, r2.z, c2.w
    cmp r0.y, -r0_abs.y, r2.x, r0.z
    mul r0.z, r1.w, r1.x
    mad r0.z, r1.y, r1.w, -r0.z
    cmp r0.x, -r0_abs.x, r0.z, r0.y
    add r0.y, r0.x, c3.x
    cmp r0.x, r0.x, r0.x, r0.y
    add r0.y, -r0.x, c3.x
    add r0.z, r0.x, c3.y
    cmp r0.x, r0.y, r0.x, r0.z
    rcp r0.z, r2.y
    mul r0.y, r0.z, r0.w
    cmp r0.xy, -r0_abs.w, c2.w, r0
    mov r1.x, c3.x
    mad r0.z, r0.y, -c0.x, r1.x
    mul r0.w, r0.x, c3.z
    frc r1.y, r0.w
    add r0.w, r0.w, -r1.y
    mad r0.x, r0.x, c3.z, -r0.w
    mul r0.y, r0.y, c0.x
    add r1.y, -r0.x, c3.x
    mad r0.x, r0.y, -r0.x, c3.x
    mul r0.xz, r0, r2.y
    mad r1.y, r0.y, -r1.y, c3.x
    mul r1.y, r1.y, r2.y
    add r3, r0.w, c4
    cmp r1.y, -r3_abs.w, r1.y, r2.y
    cmp r1.y, -r3_abs.z, r0.z, r1.y
    cmp r0.z, -r3_abs.y, r0.z, r1.y
    cmp r0.x, -r3_abs.x, r0.x, r0.z
    cmp r0.x, -r0_abs.w, r2.y, r0.x
    cmp oC0.x, -r0_abs.y, r2.y, r0.x
    texld r0, v0.zwzw, s0
    dp3 r0.x, r0, c1
    min r1.y, r0.y, r0.x
    min r2.x, r0.z, r1.y
    max r1.y, r0.y, r0.x
    max r3.y, r0.z, r1.y
    add r0.w, -r2.x, r3.y
    mul r1.y, r0.w, c1.w
    add r2.xyz, -r0.yzxw, r3.y
    add r0.xyz, r0, -r3.y
    mad r1.yzw, r2.xxyz, c2.x, r1.y
    rcp r2.x, r0.w
    mad r2.yz, r1.xwyw, r2.x, c2
    mad r2.yz, r1.xzww, -r2.x, r2
    cmp r0.z, -r0_abs.z, r2.z, c2.w
    cmp r0.y, -r0_abs.y, r2.y, r0.z
    mul r0.z, r1.y, r2.x
    mad r0.z, r1.z, r2.x, -r0.z
    cmp r0.x, -r0_abs.x, r0.z, r0.y
    add r0.y, r0.x, c3.x
    cmp r0.x, r0.x, r0.x, r0.y
    add r0.y, -r0.x, c3.x
    add r0.z, r0.x, c3.y
    cmp r0.x, r0.y, r0.x, r0.z
    rcp r0.z, r3.y
    mul r0.y, r0.z, r0.w
    cmp r0.xy, -r0_abs.w, c2.w, r0
    mad r0.z, r0.y, -c0.x, r1.x
    mul r1.y, r0.z, r3.y
    mul r0.z, r0.x, c3.z
    frc r0.w, r0.z
    add r0.z, -r0.w, r0.z
    mad r0.x, r0.x, c3.z, -r0.z
    mul r0.y, r0.y, c0.x
    mad r0.w, r0.y, -r0.x, c3.x
    add r0.x, -r0.x, c3.x
    mad r0.x, r0.y, -r0.x, c3.x
    mul r3.xz, r0.wyxw, r3.y
    add r2, r0.z, c4
    cmp r1.z, -r2_abs.w, r3.y, r3.x
    cmp r0.xw, -r2_abs.z, r3.xyzy, r1.yyzz
    mov r3.w, r1.y
    cmp r0.xw, -r2_abs.y, r3.yyzz, r0
    cmp r0.xw, -r2_abs.x, r3.yyzw, r0
    cmp r0.xz, -r0_abs.z, r3.zyww, r0.xyww
    cmp oC0.yz, -r0_abs.y, r3.y, r0.xxzw
    mov oC0.w, c3.x

// approximately 93 instruction slots used (2 texture, 91 arithmetic)
#endif

const BYTE g_ps30_MergeSxSHalfColor2Anaglyph_PS[] =
{
      0,   3, 255, 255, 254, 255, 
     46,   0,  67,  84,  65,  66, 
     28,   0,   0,   0, 131,   0, 
      0,   0,   0,   3, 255, 255, 
      2,   0,   0,   0,  28,   0, 
      0,   0,   0,   1,   0,   0, 
    124,   0,   0,   0,  68,   0, 
      0,   0,   2,   0,   0,   0, 
      1,   0,   0,   0,  80,   0, 
      0,   0,   0,   0,   0,   0, 
     96,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
    108,   0,   0,   0,   0,   0, 
      0,   0,  36, 115,  97, 116, 
    117, 114,  97, 116, 105, 111, 
    110,   0,   0,   0,   3,   0, 
      1,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
    116, 101, 120, 116, 117, 114, 
    101,  48,   0, 171, 171, 171, 
      4,   0,  12,   0,   1,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 112, 115, 
     95,  51,  95,  48,   0,  77, 
    105,  99, 114, 111, 115, 111, 
    102, 116,  32,  40,  82,  41, 
     32,  72,  76,  83,  76,  32, 
     83, 104,  97, 100, 101, 114, 
     32,  67, 111, 109, 112, 105, 
    108, 101, 114,  32,  57,  46, 
     50,  55,  46,  57,  53,  50, 
     46,  51,  48,  50,  50,   0, 
     81,   0,   0,   5,   1,   0, 
     15, 160, 135,  22, 153,  62, 
    162,  69,  22,  63, 213, 120, 
    233,  61,   0,   0,   0,  63, 
     81,   0,   0,   5,   2,   0, 
     15, 160, 171, 170,  42,  62, 
    171, 170, 170,  62, 171, 170, 
     42,  63,   0,   0,   0,   0, 
     81,   0,   0,   5,   3,   0, 
     15, 160,   0,   0, 128,  63, 
      0,   0, 128, 191,   0,   0, 
    192,  64,   0,   0,   0,   0, 
     81,   0,   0,   5,   4,   0, 
     15, 160,   0,   0, 128, 191, 
      0,   0,   0, 192,   0,   0, 
     64, 192,   0,   0, 128, 192, 
     31,   0,   0,   2,   5,   0, 
      0, 128,   0,   0,  15, 144, 
     31,   0,   0,   2,   0,   0, 
      0, 144,   0,   8,  15, 160, 
     66,   0,   0,   3,   0,   0, 
     15, 128,   0,   0, 228, 144, 
      0,   8, 228, 160,   8,   0, 
      0,   3,   0,   0,   1, 128, 
      0,   0, 228, 128,   1,   0, 
    228, 160,  10,   0,   0,   3, 
      1,   0,   1, 128,   0,   0, 
     85, 128,   0,   0,   0, 128, 
     10,   0,   0,   3,   2,   0, 
      1, 128,   0,   0, 170, 128, 
      1,   0,   0, 128,  11,   0, 
      0,   3,   1,   0,   1, 128, 
      0,   0,  85, 128,   0,   0, 
      0, 128,  11,   0,   0,   3, 
      2,   0,   2, 128,   0,   0, 
    170, 128,   1,   0,   0, 128, 
      2,   0,   0,   3,   0,   0, 
      8, 128,   2,   0,   0, 129, 
      2,   0,  85, 128,   5,   0, 
      0,   3,   1,   0,   1, 128, 
      0,   0, 255, 128,   1,   0, 
    255, 160,   2,   0,   0,   3, 
      1,   0,  14, 128,   0,   0, 
     36, 129,   2,   0,  85, 128, 
      2,   0,   0,   3,   0,   0, 
      7, 128,   0,   0, 228, 128, 
      2,   0,  85, 129,   4,   0, 
      0,   4,   1,   0,   7, 128, 
      1,   0, 249, 128,   2,   0, 
      0, 160,   1,   0,   0, 128, 
      6,   0,   0,   2,   1,   0, 
      8, 128,   0,   0, 255, 128, 
      4,   0,   0,   4,   2,   0, 
      5, 128,   1,   0, 198, 128, 
      1,   0, 255, 128,   2,   0, 
    229, 160,   4,   0,   0,   4, 
      2,   0,   5, 128,   1,   0, 
    229, 128,   1,   0, 255, 129, 
      2,   0, 228, 128,  88,   0, 
      0,   4,   0,   0,   4, 128, 
      0,   0, 170, 140,   2,   0, 
    170, 128,   2,   0, 255, 160, 
     88,   0,   0,   4,   0,   0, 
      2, 128,   0,   0,  85, 140, 
      2,   0,   0, 128,   0,   0, 
    170, 128,   5,   0,   0,   3, 
      0,   0,   4, 128,   1,   0, 
    255, 128,   1,   0,   0, 128, 
      4,   0,   0,   4,   0,   0, 
      4, 128,   1,   0,  85, 128, 
      1,   0, 255, 128,   0,   0, 
    170, 129,  88,   0,   0,   4, 
      0,   0,   1, 128,   0,   0, 
      0, 140,   0,   0, 170, 128, 
      0,   0,  85, 128,   2,   0, 
      0,   3,   0,   0,   2, 128, 
      0,   0,   0, 128,   3,   0, 
      0, 160,  88,   0,   0,   4, 
      0,   0,   1, 128,   0,   0, 
      0, 128,   0,   0,   0, 128, 
      0,   0,  85, 128,   2,   0, 
      0,   3,   0,   0,   2, 128, 
      0,   0,   0, 129,   3,   0, 
      0, 160,   2,   0,   0,   3, 
      0,   0,   4, 128,   0,   0, 
      0, 128,   3,   0,  85, 160, 
     88,   0,   0,   4,   0,   0, 
      1, 128,   0,   0,  85, 128, 
      0,   0,   0, 128,   0,   0, 
    170, 128,   6,   0,   0,   2, 
      0,   0,   4, 128,   2,   0, 
     85, 128,   5,   0,   0,   3, 
      0,   0,   2, 128,   0,   0, 
    170, 128,   0,   0, 255, 128, 
     88,   0,   0,   4,   0,   0, 
      3, 128,   0,   0, 255, 140, 
      2,   0, 255, 160,   0,   0, 
    228, 128,   1,   0,   0,   2, 
      1,   0,   1, 128,   3,   0, 
      0, 160,   4,   0,   0,   4, 
      0,   0,   4, 128,   0,   0, 
     85, 128,   0,   0,   0, 161, 
      1,   0,   0, 128,   5,   0, 
      0,   3,   0,   0,   8, 128, 
      0,   0,   0, 128,   3,   0, 
    170, 160,  19,   0,   0,   2, 
      1,   0,   2, 128,   0,   0, 
    255, 128,   2,   0,   0,   3, 
      0,   0,   8, 128,   0,   0, 
    255, 128,   1,   0,  85, 129, 
      4,   0,   0,   4,   0,   0, 
      1, 128,   0,   0,   0, 128, 
      3,   0, 170, 160,   0,   0, 
    255, 129,   5,   0,   0,   3, 
      0,   0,   2, 128,   0,   0, 
     85, 128,   0,   0,   0, 160, 
      2,   0,   0,   3,   1,   0, 
      2, 128,   0,   0,   0, 129, 
      3,   0,   0, 160,   4,   0, 
      0,   4,   0,   0,   1, 128, 
      0,   0,  85, 128,   0,   0, 
      0, 129,   3,   0,   0, 160, 
      5,   0,   0,   3,   0,   0, 
      5, 128,   0,   0, 228, 128, 
      2,   0,  85, 128,   4,   0, 
      0,   4,   1,   0,   2, 128, 
      0,   0,  85, 128,   1,   0, 
     85, 129,   3,   0,   0, 160, 
      5,   0,   0,   3,   1,   0, 
      2, 128,   1,   0,  85, 128, 
      2,   0,  85, 128,   2,   0, 
      0,   3,   3,   0,  15, 128, 
      0,   0, 255, 128,   4,   0, 
    228, 160,  88,   0,   0,   4, 
      1,   0,   2, 128,   3,   0, 
    255, 140,   1,   0,  85, 128, 
      2,   0,  85, 128,  88,   0, 
      0,   4,   1,   0,   2, 128, 
      3,   0, 170, 140,   0,   0, 
    170, 128,   1,   0,  85, 128, 
     88,   0,   0,   4,   0,   0, 
      4, 128,   3,   0,  85, 140, 
      0,   0, 170, 128,   1,   0, 
     85, 128,  88,   0,   0,   4, 
      0,   0,   1, 128,   3,   0, 
      0, 140,   0,   0,   0, 128, 
      0,   0, 170, 128,  88,   0, 
      0,   4,   0,   0,   1, 128, 
      0,   0, 255, 140,   2,   0, 
     85, 128,   0,   0,   0, 128, 
     88,   0,   0,   4,   0,   8, 
      1, 128,   0,   0,  85, 140, 
      2,   0,  85, 128,   0,   0, 
      0, 128,  66,   0,   0,   3, 
      0,   0,  15, 128,   0,   0, 
    238, 144,   0,   8, 228, 160, 
      8,   0,   0,   3,   0,   0, 
      1, 128,   0,   0, 228, 128, 
      1,   0, 228, 160,  10,   0, 
      0,   3,   1,   0,   2, 128, 
      0,   0,  85, 128,   0,   0, 
      0, 128,  10,   0,   0,   3, 
      2,   0,   1, 128,   0,   0, 
    170, 128,   1,   0,  85, 128, 
     11,   0,   0,   3,   1,   0, 
      2, 128,   0,   0,  85, 128, 
      0,   0,   0, 128,  11,   0, 
      0,   3,   3,   0,   2, 128, 
      0,   0, 170, 128,   1,   0, 
     85, 128,   2,   0,   0,   3, 
      0,   0,   8, 128,   2,   0, 
      0, 129,   3,   0,  85, 128, 
      5,   0,   0,   3,   1,   0, 
      2, 128,   0,   0, 255, 128, 
      1,   0, 255, 160,   2,   0, 
      0,   3,   2,   0,   7, 128, 
      0,   0, 201, 129,   3,   0, 
     85, 128,   2,   0,   0,   3, 
      0,   0,   7, 128,   0,   0, 
    228, 128,   3,   0,  85, 129, 
      4,   0,   0,   4,   1,   0, 
     14, 128,   2,   0, 144, 128, 
      2,   0,   0, 160,   1,   0, 
     85, 128,   6,   0,   0,   2, 
      2,   0,   1, 128,   0,   0, 
    255, 128,   4,   0,   0,   4, 
      2,   0,   6, 128,   1,   0, 
    220, 128,   2,   0,   0, 128, 
      2,   0, 228, 160,   4,   0, 
      0,   4,   2,   0,   6, 128, 
      1,   0, 248, 128,   2,   0, 
      0, 129,   2,   0, 228, 128, 
     88,   0,   0,   4,   0,   0, 
      4, 128,   0,   0, 170, 140, 
      2,   0, 170, 128,   2,   0, 
    255, 160,  88,   0,   0,   4, 
      0,   0,   2, 128,   0,   0, 
     85, 140,   2,   0,  85, 128, 
      0,   0, 170, 128,   5,   0, 
      0,   3,   0,   0,   4, 128, 
      1,   0,  85, 128,   2,   0, 
      0, 128,   4,   0,   0,   4, 
      0,   0,   4, 128,   1,   0, 
    170, 128,   2,   0,   0, 128, 
      0,   0, 170, 129,  88,   0, 
      0,   4,   0,   0,   1, 128, 
      0,   0,   0, 140,   0,   0, 
    170, 128,   0,   0,  85, 128, 
      2,   0,   0,   3,   0,   0, 
      2, 128,   0,   0,   0, 128, 
      3,   0,   0, 160,  88,   0, 
      0,   4,   0,   0,   1, 128, 
      0,   0,   0, 128,   0,   0, 
      0, 128,   0,   0,  85, 128, 
      2,   0,   0,   3,   0,   0, 
      2, 128,   0,   0,   0, 129, 
      3,   0,   0, 160,   2,   0, 
      0,   3,   0,   0,   4, 128, 
      0,   0,   0, 128,   3,   0, 
     85, 160,  88,   0,   0,   4, 
      0,   0,   1, 128,   0,   0, 
     85, 128,   0,   0,   0, 128, 
      0,   0, 170, 128,   6,   0, 
      0,   2,   0,   0,   4, 128, 
      3,   0,  85, 128,   5,   0, 
      0,   3,   0,   0,   2, 128, 
      0,   0, 170, 128,   0,   0, 
    255, 128,  88,   0,   0,   4, 
      0,   0,   3, 128,   0,   0, 
    255, 140,   2,   0, 255, 160, 
      0,   0, 228, 128,   4,   0, 
      0,   4,   0,   0,   4, 128, 
      0,   0,  85, 128,   0,   0, 
      0, 161,   1,   0,   0, 128, 
      5,   0,   0,   3,   1,   0, 
      2, 128,   0,   0, 170, 128, 
      3,   0,  85, 128,   5,   0, 
      0,   3,   0,   0,   4, 128, 
      0,   0,   0, 128,   3,   0, 
    170, 160,  19,   0,   0,   2, 
      0,   0,   8, 128,   0,   0, 
    170, 128,   2,   0,   0,   3, 
      0,   0,   4, 128,   0,   0, 
    255, 129,   0,   0, 170, 128, 
      4,   0,   0,   4,   0,   0, 
      1, 128,   0,   0,   0, 128, 
      3,   0, 170, 160,   0,   0, 
    170, 129,   5,   0,   0,   3, 
      0,   0,   2, 128,   0,   0, 
     85, 128,   0,   0,   0, 160, 
      4,   0,   0,   4,   0,   0, 
      8, 128,   0,   0,  85, 128, 
      0,   0,   0, 129,   3,   0, 
      0, 160,   2,   0,   0,   3, 
      0,   0,   1, 128,   0,   0, 
      0, 129,   3,   0,   0, 160, 
      4,   0,   0,   4,   0,   0, 
      1, 128,   0,   0,  85, 128, 
      0,   0,   0, 129,   3,   0, 
      0, 160,   5,   0,   0,   3, 
      3,   0,   5, 128,   0,   0, 
    199, 128,   3,   0,  85, 128, 
      2,   0,   0,   3,   2,   0, 
     15, 128,   0,   0, 170, 128, 
      4,   0, 228, 160,  88,   0, 
      0,   4,   1,   0,   4, 128, 
      2,   0, 255, 140,   3,   0, 
     85, 128,   3,   0,   0, 128, 
     88,   0,   0,   4,   0,   0, 
      9, 128,   2,   0, 170, 140, 
      3,   0, 100, 128,   1,   0, 
    165, 128,   1,   0,   0,   2, 
      3,   0,   8, 128,   1,   0, 
     85, 128,  88,   0,   0,   4, 
      0,   0,   9, 128,   2,   0, 
     85, 140,   3,   0, 165, 128, 
      0,   0, 228, 128,  88,   0, 
      0,   4,   0,   0,   9, 128, 
      2,   0,   0, 140,   3,   0, 
    229, 128,   0,   0, 228, 128, 
     88,   0,   0,   4,   0,   0, 
      5, 128,   0,   0, 170, 140, 
      3,   0, 246, 128,   0,   0, 
    244, 128,  88,   0,   0,   4, 
      0,   8,   6, 128,   0,   0, 
     85, 140,   3,   0,  85, 128, 
      0,   0, 224, 128,   1,   0, 
      0,   2,   0,   8,   8, 128, 
      3,   0,   0, 160, 255, 255, 
      0,   0
};