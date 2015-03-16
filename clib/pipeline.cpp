#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "arch.h"
#include <xtensa/sim.h>
#include <xtensa/hal.h>
#include <xtensa/config/core.h>
#include <xtensa/config/system.h>
#include <xtensa/xt_reftb.h>

void lambda_arris_v3lua_line43_10(const Image<vector32>& in, Image<vector32>& out
	, unsigned int tap_Green_to_Lum_0_s
	, unsigned int tap_Blue_to_Lum_0_s
	, unsigned int tap_Red_to_Lum_0_s
)
{
  // Set up the tap values
  register vector32 tap_Green_to_Lum_0 asm("v32r0"); // keep in the register
  tap_Green_to_Lum_0 = mv32_sv(tap_Green_to_Lum_0_s);
  register vector32 tap_Blue_to_Lum_0 asm("v32r1"); // keep in the register
  tap_Blue_to_Lum_0 = mv32_sv(tap_Blue_to_Lum_0_s);
  register vector32 tap_Red_to_Lum_0 asm("v32r2"); // keep in the register
  tap_Red_to_Lum_0 = mv32_sv(tap_Red_to_Lum_0_s);
  
  // Set up the constant values
  register vector32 c_0_0 asm("v32r3"); // keep in the register
  c_0_0 = mv32_sv(0);
  register vector32 c_32767_0 asm("v32r4"); // keep in the register
  c_32767_0 = mv32_sv(32767);
  
  for(int y = 0; y < in.height(); y++){
    // declare the registers storing the stencil window
    register vector32 cropSpecial0Node_10_pp_0_0_2 asm("v32r5");
    register vector32 cropSpecial0Node_10_pp_0_0_1 asm("v32r6");
    register vector32 cropSpecial0Node_10_pp_0_0_0 asm("v32r7");
    
    // load the stencil window for each scan of row
    
    for(int x = 0; x < in.width(); x++){
      // shift the stencil window, and load the new input pixel
      
      // load the update stencil
      unsigned idx = x + 0;
      if (idx < in.width()) {
        cropSpecial0Node_10_pp_0_0_2 = in(idx, y+0, 2);
        cropSpecial0Node_10_pp_0_0_1 = in(idx, y+0, 1);
        cropSpecial0Node_10_pp_0_0_0 = in(idx, y+0, 0);
      } else {
        cropSpecial0Node_10_pp_0_0_2 = in(idx - in.width(), y+0, 2);
        cropSpecial0Node_10_pp_0_0_2 = getr32_vv(cropSpecial0Node_10_pp_0_0_2);
        cropSpecial0Node_10_pp_0_0_1 = in(idx - in.width(), y+0, 1);
        cropSpecial0Node_10_pp_0_0_1 = getr32_vv(cropSpecial0Node_10_pp_0_0_1);
        cropSpecial0Node_10_pp_0_0_0 = in(idx - in.width(), y+0, 0);
        cropSpecial0Node_10_pp_0_0_0 = getr32_vv(cropSpecial0Node_10_pp_0_0_0);
      }
      
      // Start operation
      vector32 Wxx_8_0 = c_0_0;
      vector32 lambda_arris_v3lua_line43_46_0 = cropSpecial0Node_10_pp_0_0_0;
      vector32 lambda_arris_v3lua_line43_47_0 = lambda_arris_v3lua_line43_46_0;
      vector32 lambda_arris_v3lua_line43_48_0 = mult32_vv(lambda_arris_v3lua_line43_47_0, tap_Red_to_Lum_0);
      vector32 lambda_arris_v3lua_line43_40_0 = cropSpecial0Node_10_pp_0_0_1;
      vector32 lambda_arris_v3lua_line43_41_0 = lambda_arris_v3lua_line43_40_0;
      vector32 Resp_17_0 = c_32767_0;
      vector32 lambda_arris_v3lua_line43_51_pack_1 = Resp_17_0;
      vector32 lambda_arris_v3lua_line43_42_0 = mult32_vv(lambda_arris_v3lua_line43_41_0, tap_Green_to_Lum_0);
      vector32 lambda_arris_v3lua_line43_49_pack_1 = lambda_arris_v3lua_line43_42_0;
      vector32 lambda_arris_v3lua_line43_49_pack_0 = lambda_arris_v3lua_line43_48_0;
      vector32 lambda_arris_v3lua_line43_50_pack_1 = Wxx_8_0;
      vector32 lambda_arris_v3lua_line43_43_0 = cropSpecial0Node_10_pp_0_0_2;
      vector32 lambda_arris_v3lua_line43_44_0 = lambda_arris_v3lua_line43_43_0;
      vector32 lambda_arris_v3lua_line43_45_0 = mult32_vv(lambda_arris_v3lua_line43_44_0, tap_Blue_to_Lum_0);
      vector32 lambda_arris_v3lua_line43_49_pack_2 = lambda_arris_v3lua_line43_45_0;
      // add lambda_arris_v3lua_line43_49_0 <= (lambda_arris_v3lua_line43_49_pack_2 , lambda_arris_v3lua_line43_49_pack_1 , lambda_arris_v3lua_line43_49_pack_0)
      vector32 lambda_arris_v3lua_line43_49_0_cotmp_1 = add32_vv(lambda_arris_v3lua_line43_49_pack_2, lambda_arris_v3lua_line43_49_pack_1);
      vector32 lambda_arris_v3lua_line43_49_0_cotmp_2 = add32_vv(lambda_arris_v3lua_line43_49_0_cotmp_1, lambda_arris_v3lua_line43_49_pack_0);
      vector32 lambda_arris_v3lua_line43_49_0 = lambda_arris_v3lua_line43_49_0_cotmp_2;

      vector32 lambda_arris_v3lua_line43_50_pack_0 = lambda_arris_v3lua_line43_49_0;
      // max lambda_arris_v3lua_line43_50_0 <= (lambda_arris_v3lua_line43_50_pack_1 , lambda_arris_v3lua_line43_50_pack_0)
      vector32 lambda_arris_v3lua_line43_50_0_cotmp_1 = max32_vv(lambda_arris_v3lua_line43_50_pack_1, lambda_arris_v3lua_line43_50_pack_0);
      vector32 lambda_arris_v3lua_line43_50_0 = lambda_arris_v3lua_line43_50_0_cotmp_1;

      vector32 lambda_arris_v3lua_line43_51_pack_0 = lambda_arris_v3lua_line43_50_0;
      // min lambda_arris_v3lua_line43_51_0 <= (lambda_arris_v3lua_line43_51_pack_1 , lambda_arris_v3lua_line43_51_pack_0)
      vector32 lambda_arris_v3lua_line43_51_0_cotmp_1 = min32_vv(lambda_arris_v3lua_line43_51_pack_1, lambda_arris_v3lua_line43_51_pack_0);
      vector32 lambda_arris_v3lua_line43_51_0 = lambda_arris_v3lua_line43_51_0_cotmp_1;
      
      out(x,y,0) = lambda_arris_v3lua_line43_51_0;
    }
  }
} // END lambda_arris_v3lua_line43_10


void Resp_5(const Image<vector32>& in, Image<vector32>& out
	, signed int tap_K_0_s
)
{
  // Set up the tap values
  register vector32 tap_K_0 asm("v32r0"); // keep in the register
  tap_K_0 = mv32_sv(tap_K_0_s);
  
  // Set up the constant values
  register vector32 c_1_0 asm("v32r1"); // keep in the register
  c_1_0 = mv32_sv(1);
  register vector32 c_32767_0 asm("v32r2"); // keep in the register
  c_32767_0 = mv32_sv(32767);
  register vector32 c_16_0 asm("v32r3"); // keep in the register
  c_16_0 = mv32_sv(16);
  register vector32 c_15_0 asm("v32r4"); // keep in the register
  c_15_0 = mv32_sv(15);
  
  for(int y = 0; y < in.height(); y++){
    // declare the registers storing the stencil window
    register vector32 downCast_38_pp_2_2 asm("v32r5");
    register vector32 downCast_38_pp_2_1 asm("v32r6");
    register vector32 downCast_38_pp_2_0 asm("v32r7");
    register vector32 downCast_38_pp_1_2 asm("v32r8");
    register vector32 downCast_38_pp_1_1 asm("v32r9");
    register vector32 downCast_38_pp_1_0 asm("v32r10");
    register vector32 downCast_38_pp_0_2 asm("v32r11");
    register vector32 downCast_38_pp_0_1 asm("v32r12");
    register vector32 downCast_38_pp_0_0 asm("v32r13");
    
    // load the stencil window for each scan of row
    downCast_38_pp_1_2 = in(in.width() -1, y+1, 0);
    downCast_38_pp_1_2 = getl32_vv(downCast_38_pp_1_2);
    downCast_38_pp_1_1 = in(in.width() -1, y+0, 0);
    downCast_38_pp_1_1 = getl32_vv(downCast_38_pp_1_1);
    downCast_38_pp_1_0 = in(in.width() -1, y+-1, 0);
    downCast_38_pp_1_0 = getl32_vv(downCast_38_pp_1_0);
    downCast_38_pp_2_2 = in(0, y+1, 0);
    downCast_38_pp_2_1 = in(0, y+0, 0);
    downCast_38_pp_2_0 = in(0, y+-1, 0);
    
    for(int x = 0; x < in.width(); x++){
      // shift the stencil window, and load the new input pixel
      downCast_38_pp_0_2 = downCast_38_pp_1_2;
      downCast_38_pp_0_1 = downCast_38_pp_1_1;
      downCast_38_pp_0_0 = downCast_38_pp_1_0;
      downCast_38_pp_1_2 = downCast_38_pp_2_2;
      downCast_38_pp_1_1 = downCast_38_pp_2_1;
      downCast_38_pp_1_0 = downCast_38_pp_2_0;
      
      // load the update stencil
      unsigned idx = x + 1;
      if (idx < in.width()) {
        downCast_38_pp_2_2 = in(idx, y+1, 0);
        downCast_38_pp_2_1 = in(idx, y+0, 0);
        downCast_38_pp_2_0 = in(idx, y+-1, 0);
      } else {
        downCast_38_pp_2_2 = in(idx - in.width(), y+1, 0);
        downCast_38_pp_2_2 = getr32_vv(downCast_38_pp_2_2);
        downCast_38_pp_2_1 = in(idx - in.width(), y+0, 0);
        downCast_38_pp_2_1 = getr32_vv(downCast_38_pp_2_1);
        downCast_38_pp_2_0 = in(idx - in.width(), y+-1, 0);
        downCast_38_pp_2_0 = getr32_vv(downCast_38_pp_2_0);
      }
      
      // Start operation
      vector32 in1_29_0 = downCast_38_pp_2_0;
      vector32 in1y_22_pack_5 = in1_29_0;
      vector32 in1_31_0 = downCast_38_pp_1_2;
      vector32 in1_26_0 = downCast_38_pp_0_1;
      vector32 in1_27_0 = downCast_38_pp_0_0;
      vector32 in1y_22_pack_3 = in1_27_0;
      vector32 Resp_22_0 = c_32767_0;
      vector32 Wxx_24_pack_1 = Resp_22_0;
      vector32 Resp_31_pack_1 = Resp_22_0;
      vector32 Wyy_19_pack_1 = Resp_22_0;
      vector32 Resp_23_0 = inv32_vv(Resp_22_0);
      vector32 Wxy_15_pack_1 = Resp_23_0;
      vector32 Resp_30_pack_1 = Resp_23_0;
      vector32 in1x_33_0 = inv32_vv(in1_27_0);
      vector32 Wxx_11_0 = c_16_0;
      vector32 in1x_12_0 = c_1_0;
      vector32 in1x_31_0 = lshift32_vv(in1_26_0, in1x_12_0);
      vector32 in1_32_0 = downCast_38_pp_1_0;
      vector32 Wxy_16_pack_1 = Resp_22_0;
      vector32 TrSq_9_0 = c_15_0;
      vector32 in1x_36_pack_2 = in1x_33_0;
      vector32 in1_28_0 = downCast_38_pp_2_2;
      vector32 in1x_38_pack_1 = Resp_22_0;
      vector32 in1x_37_pack_1 = Resp_23_0;
      vector32 in1_30_0 = downCast_38_pp_2_1;
      vector32 in1x_35_0 = lshift32_vv(in1_30_0, in1x_12_0);
      vector32 in1x_36_pack_4 = in1x_35_0;
      vector32 in1x_36_pack_5 = in1_29_0;
      vector32 in1y_23_pack_1 = Resp_23_0;
      vector32 in1x_32_0 = inv32_vv(in1x_31_0);
      vector32 in1x_36_pack_1 = in1x_32_0;
      vector32 in1y_21_0 = lshift32_vv(in1_32_0, in1x_12_0);
      vector32 in1y_22_pack_4 = in1y_21_0;
      vector32 in1x_36_pack_3 = in1_28_0;
      vector32 in1_25_0 = downCast_38_pp_0_2;
      vector32 in1y_19_0 = lshift32_vv(in1_31_0, in1x_12_0);
      vector32 in1y_24_pack_1 = Resp_22_0;
      vector32 in1x_30_0 = inv32_vv(in1_25_0);
      vector32 in1x_36_pack_0 = in1x_30_0;
      // add in1x_36_0 <= (in1x_36_pack_5 , in1x_36_pack_4 , in1x_36_pack_3 , in1x_36_pack_2 , in1x_36_pack_1 , in1x_36_pack_0)
      vector32 in1x_36_0_cotmp_1 = add32_vv(in1x_36_pack_5, in1x_36_pack_4);
      vector32 in1x_36_0_cotmp_2 = add32_vv(in1x_36_0_cotmp_1, in1x_36_pack_3);
      vector32 in1x_36_0_cotmp_3 = add32_vv(in1x_36_0_cotmp_2, in1x_36_pack_2);
      vector32 in1x_36_0_cotmp_4 = add32_vv(in1x_36_0_cotmp_3, in1x_36_pack_1);
      vector32 in1x_36_0_cotmp_5 = add32_vv(in1x_36_0_cotmp_4, in1x_36_pack_0);
      vector32 in1x_36_0 = in1x_36_0_cotmp_5;
      vector32 in1x_37_pack_0 = in1x_36_0;
      vector32 in1y_22_pack_0 = in1x_30_0;
      vector32 in1x_34_0 = inv32_vv(in1_28_0);
      vector32 in1y_22_pack_2 = in1x_34_0;
      vector32 Wxx_23_pack_1 = Resp_23_0;
      vector32 Wyy_18_pack_1 = Resp_23_0;
      // max in1x_37_0 <= (in1x_37_pack_1 , in1x_37_pack_0)
      vector32 in1x_37_0_cotmp_1 = max32_vv(in1x_37_pack_1, in1x_37_pack_0);
      vector32 in1x_37_0 = in1x_37_0_cotmp_1;

      vector32 in1x_38_pack_0 = in1x_37_0;
      // min in1x_38_0 <= (in1x_38_pack_1 , in1x_38_pack_0)
      vector32 in1x_38_0_cotmp_1 = min32_vv(in1x_38_pack_1, in1x_38_pack_0);
      vector32 in1x_38_0 = in1x_38_0_cotmp_1;

      vector32 sobel_3_0 = in1x_38_0;
      vector32 Wxx_20_0 = sobel_3_0;

      vector32 Wxx_21_0 = mult32_vv(Wxx_20_0, Wxx_20_0);
      vector32 Wxx_22_0 = rshift32_vv(Wxx_21_0, Wxx_11_0);
      vector32 Wxx_23_pack_0 = Wxx_22_0;
      // max Wxx_23_0 <= (Wxx_23_pack_1 , Wxx_23_pack_0)
      vector32 Wxx_23_0_cotmp_1 = max32_vv(Wxx_23_pack_1, Wxx_23_pack_0);
      vector32 Wxx_23_0 = Wxx_23_0_cotmp_1;

      vector32 Wxx_24_pack_0 = Wxx_23_0;
      // min Wxx_24_0 <= (Wxx_24_pack_1 , Wxx_24_pack_0)
      vector32 Wxx_24_0_cotmp_1 = min32_vv(Wxx_24_pack_1, Wxx_24_pack_0);
      vector32 Wxx_24_0 = Wxx_24_0_cotmp_1;

      vector32 in1y_20_0 = inv32_vv(in1y_19_0);
      vector32 in1y_22_pack_1 = in1y_20_0;
      // add in1y_22_0 <= (in1y_22_pack_5 , in1y_22_pack_4 , in1y_22_pack_3 , in1y_22_pack_2 , in1y_22_pack_1 , in1y_22_pack_0)
      vector32 in1y_22_0_cotmp_1 = add32_vv(in1y_22_pack_5, in1y_22_pack_4);
      vector32 in1y_22_0_cotmp_2 = add32_vv(in1y_22_0_cotmp_1, in1y_22_pack_3);
      vector32 in1y_22_0_cotmp_3 = add32_vv(in1y_22_0_cotmp_2, in1y_22_pack_2);
      vector32 in1y_22_0_cotmp_4 = add32_vv(in1y_22_0_cotmp_3, in1y_22_pack_1);
      vector32 in1y_22_0_cotmp_5 = add32_vv(in1y_22_0_cotmp_4, in1y_22_pack_0);
      vector32 in1y_22_0 = in1y_22_0_cotmp_5;

      vector32 in1y_23_pack_0 = in1y_22_0;
      // max in1y_23_0 <= (in1y_23_pack_1 , in1y_23_pack_0)
      vector32 in1y_23_0_cotmp_1 = max32_vv(in1y_23_pack_1, in1y_23_pack_0);
      vector32 in1y_23_0 = in1y_23_0_cotmp_1;

      vector32 in1y_24_pack_0 = in1y_23_0;
      // min in1y_24_0 <= (in1y_24_pack_1 , in1y_24_pack_0)
      vector32 in1y_24_0_cotmp_1 = min32_vv(in1y_24_pack_1, in1y_24_pack_0);
      vector32 in1y_24_0 = in1y_24_0_cotmp_1;

      vector32 sobel_3_1 = in1y_24_0;
      vector32 Wyy_15_0 = sobel_3_1;
      vector32 Wxy_13_0 = mult32_vv(Wxx_20_0, Wyy_15_0);
      vector32 Wyy_16_0 = mult32_vv(Wyy_15_0, Wyy_15_0);
      vector32 Wxy_14_0 = rshift32_vv(Wxy_13_0, Wxx_11_0);
      vector32 Wxy_15_pack_0 = Wxy_14_0;

      // max Wxy_15_0 <= (Wxy_15_pack_1 , Wxy_15_pack_0)
      vector32 Wxy_15_0_cotmp_1 = max32_vv(Wxy_15_pack_1, Wxy_15_pack_0);
      vector32 Wxy_15_0 = Wxy_15_0_cotmp_1;

      vector32 Wxy_16_pack_0 = Wxy_15_0;
      // min Wxy_16_0 <= (Wxy_16_pack_1 , Wxy_16_pack_0)
      vector32 Wxy_16_0_cotmp_1 = min32_vv(Wxy_16_pack_1, Wxy_16_pack_0);
      vector32 Wxy_16_0 = Wxy_16_0_cotmp_1;

      vector32 Det_18_0 = mult32_vv(Wxy_16_0, Wxy_16_0);

      vector32 Det_19_0 = rshift32_vv(Det_18_0, in1x_12_0);
      vector32 Wyy_17_0 = rshift32_vv(Wyy_16_0, Wxx_11_0);
      vector32 Wyy_18_pack_0 = Wyy_17_0;
      // max Wyy_18_0 <= (Wyy_18_pack_1 , Wyy_18_pack_0)
      vector32 Wyy_18_0_cotmp_1 = max32_vv(Wyy_18_pack_1, Wyy_18_pack_0);
      vector32 Wyy_18_0 = Wyy_18_0_cotmp_1;

      vector32 Wyy_19_pack_0 = Wyy_18_0;
      // min Wyy_19_0 <= (Wyy_19_pack_1 , Wyy_19_pack_0)
      vector32 Wyy_19_0_cotmp_1 = min32_vv(Wyy_19_pack_1, Wyy_19_pack_0);
      vector32 Wyy_19_0 = Wyy_19_0_cotmp_1;

      vector32 Det_16_0 = mult32_vv(Wxx_24_0, Wyy_19_0);
      vector32 Det_17_0 = rshift32_vv(Det_16_0, in1x_12_0);
      vector32 TrSq_15_0 = add32_vv(Wxx_24_0, Wyy_19_0);
      vector32 TrSq_16_0 = rshift32_vv(TrSq_15_0, in1x_12_0);
      vector32 TrSq_17_0 = mult32_vv(TrSq_16_0, TrSq_16_0);
      vector32 TrSq_18_0 = rshift32_vv(TrSq_17_0, TrSq_9_0);
      vector32 Resp1_7_0 = mult32_vv(tap_K_0, TrSq_18_0);
      vector32 Det_20_0 = sub32_vv(Det_17_0, Det_19_0);
      vector32 Resp1_8_0 = sub32_vv(Det_20_0, Resp1_7_0);
      vector32 Resp_30_pack_0 = Resp1_8_0;
      // max Resp_30_0 <= (Resp_30_pack_1 , Resp_30_pack_0)
      vector32 Resp_30_0_cotmp_1 = max32_vv(Resp_30_pack_1, Resp_30_pack_0);
      vector32 Resp_30_0 = Resp_30_0_cotmp_1;

      vector32 Resp_31_pack_0 = Resp_30_0;
      // min Resp_31_0 <= (Resp_31_pack_1 , Resp_31_pack_0)
      vector32 Resp_31_0_cotmp_1 = min32_vv(Resp_31_pack_1, Resp_31_pack_0);
      vector32 Resp_31_0 = Resp_31_0_cotmp_1;

      vector32 Resp_32_0 = Resp_31_0;
      out(x,y,0) = Resp_32_0;
    }
  }
} // END Resp_5


void scheduledIRNode_28(const Image<vector32>& in, Image<vector32>& out
)
{
  // Set up the tap values
  
  // Set up the constant values
  
  for(int y = 0; y < in.height(); y++){
    // declare the registers storing the stencil window
    register vector32 special0_pp_0_0_2 asm("v32r0");
    register vector32 special0_pp_0_0_1 asm("v32r1");
    register vector32 special0_pp_0_0_0 asm("v32r2");
    
    // load the stencil window for each scan of row
    
    for(int x = 0; x < in.width(); x++){
      // shift the stencil window, and load the new input pixel
      
      // load the update stencil
      unsigned idx = x + 0;
      if (idx < in.width()) {
        special0_pp_0_0_2 = in(idx, y+0, 2);
        special0_pp_0_0_1 = in(idx, y+0, 1);
        special0_pp_0_0_0 = in(idx, y+0, 0);
      } else {
        special0_pp_0_0_2 = in(idx - in.width(), y+0, 2);
        special0_pp_0_0_2 = getr32_vv(special0_pp_0_0_2);
        special0_pp_0_0_1 = in(idx - in.width(), y+0, 1);
        special0_pp_0_0_1 = getr32_vv(special0_pp_0_0_1);
        special0_pp_0_0_0 = in(idx - in.width(), y+0, 0);
        special0_pp_0_0_0 = getr32_vv(special0_pp_0_0_0);
      }
      
      // Start operation
      vector32 cropSpecial0Node_10_0 = special0_pp_0_0_0;
      vector32 cropSpecial0Node_10_1 = special0_pp_0_0_1;
      vector32 cropSpecial0Node_10_2 = special0_pp_0_0_2;
      out(x,y,2) = cropSpecial0Node_10_2;
      out(x,y,1) = cropSpecial0Node_10_1;
      out(x,y,0) = cropSpecial0Node_10_0;
    }
  }
} // END scheduledIRNode_28

void downCast_15(const Image<vector32>& in, Image<vector32>& out
	, unsigned int tap_G1_0_s
	, unsigned int tap_G0_0_s
	, unsigned int tap_G2_0_s
	, unsigned int tap_G4_0_s
	, unsigned int tap_G3_0_s
	, unsigned int tap_R_0_s
)
{
  // Set up the tap values
  register vector32 tap_G1_0 asm("v32r0"); // keep in the register
  tap_G1_0 = mv32_sv(tap_G1_0_s);
  register vector32 tap_G0_0 asm("v32r1"); // keep in the register
  tap_G0_0 = mv32_sv(tap_G0_0_s);
  register vector32 tap_G2_0 asm("v32r2"); // keep in the register
  tap_G2_0 = mv32_sv(tap_G2_0_s);
  register vector32 tap_G4_0 asm("v32r3"); // keep in the register
  tap_G4_0 = mv32_sv(tap_G4_0_s);
  register vector32 tap_G3_0 asm("v32r4"); // keep in the register
  tap_G3_0 = mv32_sv(tap_G3_0_s);
  register vector32 tap_R_0 asm("v32r5"); // keep in the register
  tap_R_0 = mv32_sv(tap_R_0_s);
  
  // Set up the constant values
  register vector32 c_32767_0 asm("v32r6"); // keep in the register
  c_32767_0 = mv32_sv(32767);

  vector32 *in_ptr = in.mData;
  vector32 *out_ptr = out.mData;
  const int w = in.width();
  const int c = in.channels();
  
  // Turn on SAIF power toggle data capture
  set_power_toggle(POWER_TOGGLE_ON);

  for(int y = 0; y < in.height(); y++){
    // declare the registers storing the stencil window
    register vector32 downCast_20_pp_4_0 asm("v32r7");
    register vector32 downCast_20_pp_3_0 asm("v32r8");
    register vector32 downCast_20_pp_2_0 asm("v32r9");
    register vector32 downCast_20_pp_1_0 asm("v32r10");
    register vector32 downCast_20_pp_0_0 asm("v32r11");
    
    // load the stencil window for each scan of row
    //downCast_20_pp_1_0 = in(in.width() -2, y+0, 0);
    downCast_20_pp_1_0 = in_ptr[(y+0)*w + (w-2) + 0];
    downCast_20_pp_1_0 = getl32_vv(downCast_20_pp_1_0);

    //downCast_20_pp_2_0 = in(in.width() -1, y+0, 0);
    downCast_20_pp_2_0 = in_ptr[(y+0)*w + (w-1) + 0];
    downCast_20_pp_2_0 = getl32_vv(downCast_20_pp_2_0);

    //downCast_20_pp_3_0 = in(0, y+0, 0);
    downCast_20_pp_3_0 = in_ptr[(y+0)*w + 0 + 0];

    //downCast_20_pp_4_0 = in(1, y+0, 0);
    downCast_20_pp_4_0 = in_ptr[(y+0)*w + 1 + 0];

    for(int x = 0; x < w; x++){


      // shift the stencil window, and load the new input pixel
      downCast_20_pp_0_0 = downCast_20_pp_1_0;
      downCast_20_pp_1_0 = downCast_20_pp_2_0;
      downCast_20_pp_2_0 = downCast_20_pp_3_0;
      downCast_20_pp_3_0 = downCast_20_pp_4_0;
      
      // load the update stencil
      unsigned idx = x + 2;
      if (idx < w) {
#pragma frequency_hint FREQUENT
        //downCast_20_pp_4_0 = in(idx, y+0, 0);
	downCast_20_pp_4_0 = in_ptr[(y+0)*w + idx + 0];
      } else {
        //downCast_20_pp_4_0 = in(idx - in.width(), y+0, 0);
	downCast_20_pp_4_0 = in_ptr[(y+0)*w + (idx-w) + 0];
        downCast_20_pp_4_0 = getr32_vv(downCast_20_pp_4_0);
      }
      
      // Start operation
      vector32 convolve_1_5__68_0 = tap_G2_0;
      vector32 convolve_1_5__72_0 = tap_G3_0;
      vector32 upCast_37_0 = downCast_20_pp_2_0;
      vector32 convolve_1_5__89_0 = mult32_vv(upCast_37_0, convolve_1_5__68_0);
      vector32 Resp_20_0 = c_32767_0;
      vector32 convolve_1_5__64_0 = tap_G1_0;
      vector32 upCast_39_0 = downCast_20_pp_3_0;
      vector32 convolve_1_5__70_0 = tap_G4_0;
      vector32 convolve_1_5__93_pack_2 = convolve_1_5__89_0;
      vector32 convolve_1_5__75_0 = tap_R_0;
      vector32 Resp_21_0 = inv32_vv(Resp_20_0);
      vector32 upCast_38_0 = downCast_20_pp_4_0;
      vector32 convolve_1_5__90_0 = mult32_vv(upCast_38_0, convolve_1_5__70_0);
      vector32 convolve_1_5__93_pack_4 = convolve_1_5__90_0;
      vector32 upCast_36_0 = downCast_20_pp_1_0;
      vector32 convolve_1_5__96_pack_1 = Resp_20_0;
      vector32 convolve_1_5__95_pack_1 = Resp_21_0;
      vector32 convolve_1_5__91_0 = mult32_vv(upCast_39_0, convolve_1_5__72_0);
      vector32 convolve_1_5__93_pack_3 = convolve_1_5__91_0;
      vector32 convolve_1_5__88_0 = mult32_vv(upCast_36_0, convolve_1_5__64_0);
      vector32 convolve_1_5__93_pack_1 = convolve_1_5__88_0;
      vector32 upCast_40_0 = downCast_20_pp_0_0;
      vector32 convolve_1_5__66_0 = tap_G0_0;
      vector32 convolve_1_5__92_0 = mult32_vv(upCast_40_0, convolve_1_5__66_0);
      vector32 convolve_1_5__93_pack_0 = convolve_1_5__92_0;
      // add convolve_1_5__93_0 <= (convolve_1_5__93_pack_4 , convolve_1_5__93_pack_3 , convolve_1_5__93_pack_2 , convolve_1_5__93_pack_1 , convolve_1_5__93_pack_0)
      vector32 convolve_1_5__93_0_cotmp_1 = add32_vv(convolve_1_5__93_pack_4, convolve_1_5__93_pack_3);
      vector32 convolve_1_5__93_0_cotmp_2 = add32_vv(convolve_1_5__93_0_cotmp_1, convolve_1_5__93_pack_2);
      vector32 convolve_1_5__93_0_cotmp_3 = add32_vv(convolve_1_5__93_0_cotmp_2, convolve_1_5__93_pack_1);
      vector32 convolve_1_5__93_0_cotmp_4 = add32_vv(convolve_1_5__93_0_cotmp_3, convolve_1_5__93_pack_0);
      vector32 convolve_1_5__93_0 = convolve_1_5__93_0_cotmp_4;

      vector32 convolve_1_5__94_0 = rshift32_vv(convolve_1_5__93_0, convolve_1_5__75_0);
      vector32 convolve_1_5__95_pack_0 = convolve_1_5__94_0;
      // max convolve_1_5__95_0 <= (convolve_1_5__95_pack_1 , convolve_1_5__95_pack_0)
      vector32 convolve_1_5__95_0_cotmp_1 = max32_vv(convolve_1_5__95_pack_1, convolve_1_5__95_pack_0);
      vector32 convolve_1_5__95_0 = convolve_1_5__95_0_cotmp_1;

      vector32 convolve_1_5__96_pack_0 = convolve_1_5__95_0;
      // min convolve_1_5__96_0 <= (convolve_1_5__96_pack_1 , convolve_1_5__96_pack_0)
      vector32 convolve_1_5__96_0_cotmp_1 = min32_vv(convolve_1_5__96_pack_1, convolve_1_5__96_pack_0);
      vector32 convolve_1_5__96_0 = convolve_1_5__96_0_cotmp_1;

      vector32 downCast_38_0 = convolve_1_5__96_0;
      out_ptr[(y+0)*w + x + 0] = downCast_38_0;
    }
  }

  // End SAIF power toggle data capture
  set_power_toggle(POWER_TOGGLE_OFF);
} // END downCast_15 

void NMS_10(const Image<vector32>& in, Image<vector32>& out
	, signed int tap_Peak_0_s
)
{
  // Set up the tap values
  register vector32 tap_Peak_0 asm("v32r0"); // keep in the register
  tap_Peak_0 = mv32_sv(tap_Peak_0_s);
  
  // Set up the constant values
  register vector32 c_0_0 asm("v32r1"); // keep in the register
  c_0_0 = mv32_sv(0);
  register vector32 c_255_0 asm("v32r2"); // keep in the register
  c_255_0 = mv32_sv(255);
  
  for(int y = 0; y < in.height(); y++){
    // declare the registers storing the stencil window
    register vector32 Resp_32_pp_2_2 asm("v32r3");
    register vector32 Resp_32_pp_2_1 asm("v32r4");
    register vector32 Resp_32_pp_2_0 asm("v32r5");
    register vector32 Resp_32_pp_1_2 asm("v32r6");
    register vector32 Resp_32_pp_1_1 asm("v32r7");
    register vector32 Resp_32_pp_1_0 asm("v32r8");
    register vector32 Resp_32_pp_0_2 asm("v32r9");
    register vector32 Resp_32_pp_0_1 asm("v32r10");
    register vector32 Resp_32_pp_0_0 asm("v32r11");
    
    // load the stencil window for each scan of row
    Resp_32_pp_1_2 = in(in.width() -1, y+1, 0);
    Resp_32_pp_1_2 = getl32_vv(Resp_32_pp_1_2);
    Resp_32_pp_1_1 = in(in.width() -1, y+0, 0);
    Resp_32_pp_1_1 = getl32_vv(Resp_32_pp_1_1);
    Resp_32_pp_1_0 = in(in.width() -1, y+-1, 0);
    Resp_32_pp_1_0 = getl32_vv(Resp_32_pp_1_0);
    Resp_32_pp_2_2 = in(0, y+1, 0);
    Resp_32_pp_2_1 = in(0, y+0, 0);
    Resp_32_pp_2_0 = in(0, y+-1, 0);
    
    for(int x = 0; x < in.width(); x++){
      // shift the stencil window, and load the new input pixel
      Resp_32_pp_0_2 = Resp_32_pp_1_2;
      Resp_32_pp_0_1 = Resp_32_pp_1_1;
      Resp_32_pp_0_0 = Resp_32_pp_1_0;
      Resp_32_pp_1_2 = Resp_32_pp_2_2;
      Resp_32_pp_1_1 = Resp_32_pp_2_1;
      Resp_32_pp_1_0 = Resp_32_pp_2_0;
      
      // load the update stencil
      unsigned idx = x + 1;
      if (idx < in.width()) {
        Resp_32_pp_2_2 = in(idx, y+1, 0);
        Resp_32_pp_2_1 = in(idx, y+0, 0);
        Resp_32_pp_2_0 = in(idx, y+-1, 0);
      } else {
        Resp_32_pp_2_2 = in(idx - in.width(), y+1, 0);
        Resp_32_pp_2_2 = getr32_vv(Resp_32_pp_2_2);
        Resp_32_pp_2_1 = in(idx - in.width(), y+0, 0);
        Resp_32_pp_2_1 = getr32_vv(Resp_32_pp_2_1);
        Resp_32_pp_2_0 = in(idx - in.width(), y+-1, 0);
        Resp_32_pp_2_0 = getr32_vv(Resp_32_pp_2_0);
      }
      
      // Start operation
      vector32 PE_4_0 = gt32_vv(Resp_32_pp_1_1, Resp_32_pp_2_1);
      vector32 NMS_5_0 = c_255_0;
      vector32 P_7_0 = Resp_32_pp_1_1;
      vector32 P_8_0 = gt32_vv(P_7_0, tap_Peak_0);
      vector32 PS_4_0 = gte32_vv(Resp_32_pp_1_1, Resp_32_pp_1_0);
      vector32 PW_4_0 = gte32_vv(Resp_32_pp_1_1, Resp_32_pp_0_1);
      vector32 Pk_13_0 = and32_vv(P_8_0, PW_4_0);
      vector32 Pk_14_0 = and32_vv(Pk_13_0, PE_4_0);
      vector32 Pk_15_0 = and32_vv(Pk_14_0, PS_4_0);
      vector32 PN_4_0 = gt32_vv(Resp_32_pp_1_1, Resp_32_pp_1_2);
      vector32 Pk_16_0 = and32_vv(Pk_15_0, PN_4_0);
      vector32 Wxx_25_0 = c_0_0;
      vector32 NMS_10_0 = mux32_vv(Pk_16_0, NMS_5_0, Wxx_25_0);
      vector32 NMS_11_0 = NMS_10_0;
      out(x,y,0) = NMS_11_0;
    }
  }
} // END NMS_10


void downCast_13(const Image<vector32>& in, Image<vector32>& out
	, unsigned int tap_G1_0_s
	, unsigned int tap_G0_0_s
	, unsigned int tap_G2_0_s
	, unsigned int tap_G4_0_s
	, unsigned int tap_G3_0_s
	, unsigned int tap_R_0_s
)
{
  // Set up the tap values
  register vector32 tap_G1_0 asm("v32r0"); // keep in the register
  tap_G1_0 = mv32_sv(tap_G1_0_s);
  register vector32 tap_G0_0 asm("v32r1"); // keep in the register
  tap_G0_0 = mv32_sv(tap_G0_0_s);
  register vector32 tap_G2_0 asm("v32r2"); // keep in the register
  tap_G2_0 = mv32_sv(tap_G2_0_s);
  register vector32 tap_G4_0 asm("v32r3"); // keep in the register
  tap_G4_0 = mv32_sv(tap_G4_0_s);
  register vector32 tap_G3_0 asm("v32r4"); // keep in the register
  tap_G3_0 = mv32_sv(tap_G3_0_s);
  register vector32 tap_R_0 asm("v32r5"); // keep in the register
  tap_R_0 = mv32_sv(tap_R_0_s);
  
  // Set up the constant values
  register vector32 c_32767_0 asm("v32r6"); // keep in the register
  c_32767_0 = mv32_sv(32767);
  
  for(int y = 0; y < in.height(); y++){
    // declare the registers storing the stencil window
    register vector32 lambda_arris_v3lua_line43_51_pp_0_4 asm("v32r7");
    register vector32 lambda_arris_v3lua_line43_51_pp_0_3 asm("v32r8");
    register vector32 lambda_arris_v3lua_line43_51_pp_0_2 asm("v32r9");
    register vector32 lambda_arris_v3lua_line43_51_pp_0_1 asm("v32r10");
    register vector32 lambda_arris_v3lua_line43_51_pp_0_0 asm("v32r11");
    
    // load the stencil window for each scan of row
    
    for(int x = 0; x < in.width(); x++){
      // shift the stencil window, and load the new input pixel
      
      // load the update stencil
      unsigned idx = x + 0;
      if (idx < in.width()) {
        lambda_arris_v3lua_line43_51_pp_0_4 = in(idx, y+2, 0);
        lambda_arris_v3lua_line43_51_pp_0_3 = in(idx, y+1, 0);
        lambda_arris_v3lua_line43_51_pp_0_2 = in(idx, y+0, 0);
        lambda_arris_v3lua_line43_51_pp_0_1 = in(idx, y+-1, 0);
        lambda_arris_v3lua_line43_51_pp_0_0 = in(idx, y+-2, 0);
      } else {
        lambda_arris_v3lua_line43_51_pp_0_4 = in(idx - in.width(), y+2, 0);
        lambda_arris_v3lua_line43_51_pp_0_4 = getr32_vv(lambda_arris_v3lua_line43_51_pp_0_4);
        lambda_arris_v3lua_line43_51_pp_0_3 = in(idx - in.width(), y+1, 0);
        lambda_arris_v3lua_line43_51_pp_0_3 = getr32_vv(lambda_arris_v3lua_line43_51_pp_0_3);
        lambda_arris_v3lua_line43_51_pp_0_2 = in(idx - in.width(), y+0, 0);
        lambda_arris_v3lua_line43_51_pp_0_2 = getr32_vv(lambda_arris_v3lua_line43_51_pp_0_2);
        lambda_arris_v3lua_line43_51_pp_0_1 = in(idx - in.width(), y+-1, 0);
        lambda_arris_v3lua_line43_51_pp_0_1 = getr32_vv(lambda_arris_v3lua_line43_51_pp_0_1);
        lambda_arris_v3lua_line43_51_pp_0_0 = in(idx - in.width(), y+-2, 0);
        lambda_arris_v3lua_line43_51_pp_0_0 = getr32_vv(lambda_arris_v3lua_line43_51_pp_0_0);
      }
      
      // Start operation
      vector32 convolve_1_5__35_0 = tap_G2_0;
      vector32 convolve_1_5__37_0 = tap_G3_0;
      vector32 upCast_22_0 = lambda_arris_v3lua_line43_51_pp_0_2;
      vector32 convolve_1_5__56_0 = mult32_vv(upCast_22_0, convolve_1_5__35_0);
      vector32 Resp_18_0 = c_32767_0;
      vector32 convolve_1_5__31_0 = tap_G1_0;
      vector32 upCast_24_0 = lambda_arris_v3lua_line43_51_pp_0_1;
      vector32 convolve_1_5__39_0 = tap_G4_0;
      vector32 convolve_1_5__60_pack_2 = convolve_1_5__56_0;
      vector32 convolve_1_5__42_0 = tap_R_0;
      vector32 Resp_19_0 = inv32_vv(Resp_18_0);
      vector32 upCast_23_0 = lambda_arris_v3lua_line43_51_pp_0_0;
      vector32 convolve_1_5__57_0 = mult32_vv(upCast_23_0, convolve_1_5__39_0);
      vector32 convolve_1_5__60_pack_4 = convolve_1_5__57_0;
      vector32 upCast_21_0 = lambda_arris_v3lua_line43_51_pp_0_3;
      vector32 convolve_1_5__63_pack_1 = Resp_18_0;
      vector32 convolve_1_5__62_pack_1 = Resp_19_0;
      vector32 convolve_1_5__58_0 = mult32_vv(upCast_24_0, convolve_1_5__37_0);
      vector32 convolve_1_5__60_pack_3 = convolve_1_5__58_0;
      vector32 convolve_1_5__55_0 = mult32_vv(upCast_21_0, convolve_1_5__31_0);
      vector32 convolve_1_5__60_pack_1 = convolve_1_5__55_0;
      vector32 upCast_25_0 = lambda_arris_v3lua_line43_51_pp_0_4;
      vector32 convolve_1_5__33_0 = tap_G0_0;
      vector32 convolve_1_5__59_0 = mult32_vv(upCast_25_0, convolve_1_5__33_0);
      vector32 convolve_1_5__60_pack_0 = convolve_1_5__59_0;
      // add convolve_1_5__60_0 <= (convolve_1_5__60_pack_4 , convolve_1_5__60_pack_3 , convolve_1_5__60_pack_2 , convolve_1_5__60_pack_1 , convolve_1_5__60_pack_0)
      vector32 convolve_1_5__60_0_cotmp_1 = add32_vv(convolve_1_5__60_pack_4, convolve_1_5__60_pack_3);
      vector32 convolve_1_5__60_0_cotmp_2 = add32_vv(convolve_1_5__60_0_cotmp_1, convolve_1_5__60_pack_2);
      vector32 convolve_1_5__60_0_cotmp_3 = add32_vv(convolve_1_5__60_0_cotmp_2, convolve_1_5__60_pack_1);
      vector32 convolve_1_5__60_0_cotmp_4 = add32_vv(convolve_1_5__60_0_cotmp_3, convolve_1_5__60_pack_0);
      vector32 convolve_1_5__60_0 = convolve_1_5__60_0_cotmp_4;

      vector32 convolve_1_5__61_0 = rshift32_vv(convolve_1_5__60_0, convolve_1_5__42_0);
      vector32 convolve_1_5__62_pack_0 = convolve_1_5__61_0;
      // max convolve_1_5__62_0 <= (convolve_1_5__62_pack_1 , convolve_1_5__62_pack_0)
      vector32 convolve_1_5__62_0_cotmp_1 = max32_vv(convolve_1_5__62_pack_1, convolve_1_5__62_pack_0);
      vector32 convolve_1_5__62_0 = convolve_1_5__62_0_cotmp_1;

      vector32 convolve_1_5__63_pack_0 = convolve_1_5__62_0;
      // min convolve_1_5__63_0 <= (convolve_1_5__63_pack_1 , convolve_1_5__63_pack_0)
      vector32 convolve_1_5__63_0_cotmp_1 = min32_vv(convolve_1_5__63_pack_1, convolve_1_5__63_pack_0);
      vector32 convolve_1_5__63_0 = convolve_1_5__63_0_cotmp_1;

      vector32 downCast_20_0 = convolve_1_5__63_0;
      out(x,y,0) = downCast_20_0;
    }
  }
} // END downCast_13


