#include "pipeline.h"

#include <xtensa/sim.h>
#include <xtensa/hal.h>
#include <xtensa/config/core.h>
#include <xtensa/config/system.h>
#include <xtensa/xt_reftb.h>

void downCast_13(const Image<V16S>& in, Image<V16S>& out
	, signed int tap_G1_0_s
	, signed int tap_G0_0_s
	, signed int tap_G2_0_s
	, signed int tap_G4_0_s
	, signed int tap_G3_0_s
	, unsigned int tap_R_0_s
)
{
  // Set up the tap values
  const register V16S tap_G1_0 = mv_sv(tap_G1_0_s);
  const register V16S tap_G0_0 = mv_sv(tap_G0_0_s);
  const register V16S tap_G2_0 = mv_sv(tap_G2_0_s);
  const register V16S tap_G4_0 = mv_sv(tap_G4_0_s);
  const register V16S tap_G3_0 = mv_sv(tap_G3_0_s);
  const register V16S tap_R_0 = mv_sv(tap_R_0_s);
  
  // Set up the constant values
  const register V16S c_0_0 = mv_sv(0);
  const register V16S c_255_0 = mv_sv(255);
  
  const V16S *in_ptr = in.mData; // use direct access to speed up inner loop
  V16S *out_ptr = out.mData; // use direct access to speed up inner loop
  const int IN_WIDTH = in.width();
  const int IN_HEIGHT = in.height();
  const int IN_CHANNELS = 1; // use static value to allow more compiler optimization
  const int OUT_CHANNELS = 1; /// use static value to allow more compiler optimization
  
  // Turn on SAIF power toggle data capture
  set_power_toggle(POWER_TOGGLE_ON);
  for(int y = 0; y < in.height(); y++){
    // DEBUG: y_min=-2, y_max=2, y_padding_ofst=2
    // declare the registers storing the stencil window
    register V16S convertToIllum_55_pp_0_4;
    register V16S convertToIllum_55_pp_0_3;
    register V16S convertToIllum_55_pp_0_2;
    register V16S convertToIllum_55_pp_0_1;
    register V16S convertToIllum_55_pp_0_0;
    
    // load the stencil window for each scan of row
    
    for(int x = 0; x < IN_WIDTH - 0; x++){
      // not on X boundry, common case
      // shift the stencil window, and load the new input pixel
      
      // load the update stencil
      convertToIllum_55_pp_0_4 = in_ptr[(y+4)*IN_WIDTH*IN_CHANNELS + (x+0)*IN_CHANNELS + 0];
      convertToIllum_55_pp_0_3 = in_ptr[(y+3)*IN_WIDTH*IN_CHANNELS + (x+0)*IN_CHANNELS + 0];
      convertToIllum_55_pp_0_2 = in_ptr[(y+2)*IN_WIDTH*IN_CHANNELS + (x+0)*IN_CHANNELS + 0];
      convertToIllum_55_pp_0_1 = in_ptr[(y+1)*IN_WIDTH*IN_CHANNELS + (x+0)*IN_CHANNELS + 0];
      convertToIllum_55_pp_0_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (x+0)*IN_CHANNELS + 0];
      
      // Start operation
      V16S upCast_25_0 = convertToIllum_55_pp_0_4;
      V16S convolve_1_5__58_0 = mult_vv(upCast_25_0, tap_G0_0);
      V16S upCast_23_0 = convertToIllum_55_pp_0_0;
      V16S convolve_1_5__56_0 = mult_vv(upCast_23_0, tap_G4_0);
      V16S convolve_1_5__59_pack_4 = convolve_1_5__56_0;
      V16S Wxx_13_0 = c_0_0;
      V16S convolve_1_5__40_0 = c_255_0;
      V16S upCast_24_0 = convertToIllum_55_pp_0_1;
      V16S convolve_1_5__63_pack_1 = convolve_1_5__40_0;
      V16S convolve_1_5__59_pack_0 = convolve_1_5__58_0;
      V16S convolve_1_5__37_0 = tap_R_0;
      V16S convolve_1_5__62_pack_1 = Wxx_13_0;
      V16S upCast_22_0 = convertToIllum_55_pp_0_2;
      V16S convolve_1_5__55_0 = mult_vv(upCast_22_0, tap_G2_0);
      V16S convolve_1_5__59_pack_2 = convolve_1_5__55_0;
      V16S convolve_1_5__57_0 = mult_vv(upCast_24_0, tap_G3_0);
      V16S convolve_1_5__59_pack_3 = convolve_1_5__57_0;
      V16S upCast_21_0 = convertToIllum_55_pp_0_3;
      V16S convolve_1_5__54_0 = mult_vv(upCast_21_0, tap_G1_0);
      V16S convolve_1_5__59_pack_1 = convolve_1_5__54_0;
      // add convolve_1_5__59_0 <= (convolve_1_5__59_pack_4 , convolve_1_5__59_pack_3 , convolve_1_5__59_pack_2 , convolve_1_5__59_pack_1 , convolve_1_5__59_pack_0)
      V16S convolve_1_5__59_0_cotmp_1 = add_vv(convolve_1_5__59_pack_4, convolve_1_5__59_pack_3);
      V16S convolve_1_5__59_0_cotmp_2 = add_vv(convolve_1_5__59_0_cotmp_1, convolve_1_5__59_pack_2);
      V16S convolve_1_5__59_0_cotmp_3 = add_vv(convolve_1_5__59_0_cotmp_2, convolve_1_5__59_pack_1);
      V16S convolve_1_5__59_0_cotmp_4 = add_vv(convolve_1_5__59_0_cotmp_3, convolve_1_5__59_pack_0);
      V16S convolve_1_5__59_0 = convolve_1_5__59_0_cotmp_4;

      V16S convolve_1_5__60_0 = convolve_1_5__59_0;
      V16S convolve_1_5__61_0 = rshift_vv(convolve_1_5__60_0, convolve_1_5__37_0);
      V16S convolve_1_5__62_pack_0 = convolve_1_5__61_0;
      // max convolve_1_5__62_0 <= (convolve_1_5__62_pack_1 , convolve_1_5__62_pack_0)
      V16S convolve_1_5__62_0_cotmp_1 = max_vv(convolve_1_5__62_pack_1, convolve_1_5__62_pack_0);
      V16S convolve_1_5__62_0 = convolve_1_5__62_0_cotmp_1;

      V16S convolve_1_5__63_pack_0 = convolve_1_5__62_0;
      // min convolve_1_5__63_0 <= (convolve_1_5__63_pack_1 , convolve_1_5__63_pack_0)
      V16S convolve_1_5__63_0_cotmp_1 = min_vv(convolve_1_5__63_pack_1, convolve_1_5__63_pack_0);
      V16S convolve_1_5__63_0 = convolve_1_5__63_0_cotmp_1;

      V16S convolve_1_5__64_0 = convolve_1_5__63_0;
      V16S downCast_20_0 = convolve_1_5__64_0;
      out_ptr[y*IN_WIDTH*OUT_CHANNELS + x*OUT_CHANNELS + 0] = downCast_20_0;
    }
  }
  
  // End SAIF power toggle data capture
  set_power_toggle(POWER_TOGGLE_OFF);
} // END downCast_13


void Resp_5(const Image<V16S>& in, Image<V16S>& out
	, signed int tap_K_0_s
)
{
  // Set up the tap values
  const register V16S tap_K_0 = mv_sv(tap_K_0_s);
  
  // Set up the constant values
  const register V16S c_1_0 = mv_sv(1);
  const register V16S c_127_0 = mv_sv(127);
  const register V16S c_8_0 = mv_sv(8);
  const register V16S c_7_0 = mv_sv(7);
  
  const V16S *in_ptr = in.mData; // use direct access to speed up inner loop
  V16S *out_ptr = out.mData; // use direct access to speed up inner loop
  const int IN_WIDTH = in.width();
  const int IN_HEIGHT = in.height();
  const int IN_CHANNELS = 1; // use static value to allow more compiler optimization
  const int OUT_CHANNELS = 1; /// use static value to allow more compiler optimization
  
  // Turn on SAIF power toggle data capture
  set_power_toggle(POWER_TOGGLE_ON);
  for(int y = 0; y < in.height(); y++){
    // DEBUG: y_min=-1, y_max=1, y_padding_ofst=1
    // declare the registers storing the stencil window
    register V16S downCast_38_pp_2_2;
    register V16S downCast_38_pp_2_1;
    register V16S downCast_38_pp_2_0;
    register V16S downCast_38_pp_1_2;
    register V16S downCast_38_pp_1_1;
    register V16S downCast_38_pp_1_0;
    register V16S downCast_38_pp_0_2;
    register V16S downCast_38_pp_0_1;
    register V16S downCast_38_pp_0_0;
    
    // load the stencil window for each scan of row
    downCast_38_pp_1_2 = in_ptr[(y+2)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -1)*IN_CHANNELS + 0];
    downCast_38_pp_1_2 = getl_vv(downCast_38_pp_1_2);
    downCast_38_pp_1_1 = in_ptr[(y+1)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -1)*IN_CHANNELS + 0];
    downCast_38_pp_1_1 = getl_vv(downCast_38_pp_1_1);
    downCast_38_pp_1_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -1)*IN_CHANNELS + 0];
    downCast_38_pp_1_0 = getl_vv(downCast_38_pp_1_0);
    downCast_38_pp_2_2 = in_ptr[(y+2)*IN_WIDTH*IN_CHANNELS + (0)*IN_CHANNELS + 0];
    downCast_38_pp_2_1 = in_ptr[(y+1)*IN_WIDTH*IN_CHANNELS + (0)*IN_CHANNELS + 0];
    downCast_38_pp_2_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (0)*IN_CHANNELS + 0];
    
    for(int x = 0; x < IN_WIDTH - 1; x++){
      // not on X boundry, common case
      // shift the stencil window, and load the new input pixel
      downCast_38_pp_0_2 = downCast_38_pp_1_2;
      downCast_38_pp_0_1 = downCast_38_pp_1_1;
      downCast_38_pp_0_0 = downCast_38_pp_1_0;
      downCast_38_pp_1_2 = downCast_38_pp_2_2;
      downCast_38_pp_1_1 = downCast_38_pp_2_1;
      downCast_38_pp_1_0 = downCast_38_pp_2_0;
      
      // load the update stencil
      downCast_38_pp_2_2 = in_ptr[(y+2)*IN_WIDTH*IN_CHANNELS + (x+1)*IN_CHANNELS + 0];
      downCast_38_pp_2_1 = in_ptr[(y+1)*IN_WIDTH*IN_CHANNELS + (x+1)*IN_CHANNELS + 0];
      downCast_38_pp_2_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (x+1)*IN_CHANNELS + 0];
      
      // Start operation
      V16S in1_27_0 = downCast_38_pp_0_0;
      V16S TrSq_12_0 = c_7_0;
      V16S Resp_11_0 = c_127_0;
      V16S Wyy_26_pack_1 = Resp_11_0;
      V16S in1_30_0 = downCast_38_pp_2_1;
      V16S in1y_22_pack_3 = in1_27_0;
      V16S Resp_12_0 = inv_vv(Resp_11_0);
      V16S in1x_51_pack_1 = Resp_12_0;
      V16S in1_28_0 = downCast_38_pp_2_2;
      V16S in1x_52_pack_1 = Resp_11_0;
      V16S Wyy_25_pack_1 = Resp_12_0;
      V16S in1y_23_pack_1 = Resp_12_0;
      V16S in1_25_0 = downCast_38_pp_0_2;
      V16S Resp_17_pack_1 = Resp_12_0;
      V16S in1x_42_0 = inv_vv(in1_25_0);
      V16S in1x_47_0 = inv_vv(in1_28_0);
      V16S in1y_22_pack_0 = in1x_42_0;
      V16S Wxy_22_pack_1 = Resp_12_0;
      V16S in1x_46_0 = inv_vv(in1_27_0);
      V16S in1x_50_pack_2 = in1x_46_0;
      V16S in1x_50_pack_0 = in1x_42_0;
      V16S Wxx_18_0 = c_8_0;
      V16S Resp_18_pack_1 = Resp_11_0;
      V16S in1x_48_0 = in1_30_0;
      V16S in1_29_0 = downCast_38_pp_2_0;
      V16S in1y_22_pack_5 = in1_29_0;
      V16S in1x_50_pack_5 = in1_29_0;
      V16S Wxx_34_pack_1 = Resp_12_0;
      V16S in1_31_0 = downCast_38_pp_1_2;
      V16S Wxy_23_pack_1 = Resp_11_0;
      V16S in1x_53_0 = in1_31_0;
      V16S in1x_50_pack_3 = in1_28_0;
      V16S in1_26_0 = downCast_38_pp_0_1;
      V16S in1x_43_0 = in1_26_0;
      V16S in1y_24_pack_1 = Resp_11_0;
      V16S Wxx_35_pack_1 = Resp_11_0;
      V16S in1_32_0 = downCast_38_pp_1_0;
      V16S in1x_54_0 = in1_32_0;
      V16S in1y_22_pack_2 = in1x_47_0;
      V16S in1x_17_0 = c_1_0;
      V16S in1y_19_0 = lshift_vv(in1x_53_0, in1x_17_0);
      V16S in1y_21_0 = lshift_vv(in1x_54_0, in1x_17_0);
      V16S in1y_22_pack_4 = in1y_21_0;
      V16S in1x_49_0 = lshift_vv(in1x_48_0, in1x_17_0);
      V16S in1x_50_pack_4 = in1x_49_0;
      V16S in1x_44_0 = lshift_vv(in1x_43_0, in1x_17_0);
      V16S in1x_45_0 = inv_vv(in1x_44_0);
      V16S in1x_50_pack_1 = in1x_45_0;
      // add in1x_50_0 <= (in1x_50_pack_5 , in1x_50_pack_4 , in1x_50_pack_3 , in1x_50_pack_2 , in1x_50_pack_1 , in1x_50_pack_0)
      V16S in1x_50_0_cotmp_1 = add_vv(in1x_50_pack_5, in1x_50_pack_4);
      V16S in1x_50_0_cotmp_2 = add_vv(in1x_50_0_cotmp_1, in1x_50_pack_3);
      V16S in1x_50_0_cotmp_3 = add_vv(in1x_50_0_cotmp_2, in1x_50_pack_2);
      V16S in1x_50_0_cotmp_4 = add_vv(in1x_50_0_cotmp_3, in1x_50_pack_1);
      V16S in1x_50_0_cotmp_5 = add_vv(in1x_50_0_cotmp_4, in1x_50_pack_0);
      V16S in1x_50_0 = in1x_50_0_cotmp_5;

      V16S in1x_51_pack_0 = in1x_50_0;
      // max in1x_51_0 <= (in1x_51_pack_1 , in1x_51_pack_0)
      V16S in1x_51_0_cotmp_1 = max_vv(in1x_51_pack_1, in1x_51_pack_0);
      V16S in1x_51_0 = in1x_51_0_cotmp_1;

      V16S in1x_52_pack_0 = in1x_51_0;
      // min in1x_52_0 <= (in1x_52_pack_1 , in1x_52_pack_0)
      V16S in1x_52_0_cotmp_1 = min_vv(in1x_52_pack_1, in1x_52_pack_0);
      V16S in1x_52_0 = in1x_52_0_cotmp_1;

      V16S sobel_3_0 = in1x_52_0;
      V16S Wxx_30_0 = sobel_3_0;
      V16S Wxx_31_0 = mult_vv(Wxx_30_0, Wxx_30_0);
      V16S in1y_20_0 = inv_vv(in1y_19_0);
      V16S in1y_22_pack_1 = in1y_20_0;
      // add in1y_22_0 <= (in1y_22_pack_5 , in1y_22_pack_4 , in1y_22_pack_3 , in1y_22_pack_2 , in1y_22_pack_1 , in1y_22_pack_0)
      V16S in1y_22_0_cotmp_1 = add_vv(in1y_22_pack_5, in1y_22_pack_4);
      V16S in1y_22_0_cotmp_2 = add_vv(in1y_22_0_cotmp_1, in1y_22_pack_3);
      V16S in1y_22_0_cotmp_3 = add_vv(in1y_22_0_cotmp_2, in1y_22_pack_2);
      V16S in1y_22_0_cotmp_4 = add_vv(in1y_22_0_cotmp_3, in1y_22_pack_1);
      V16S in1y_22_0_cotmp_5 = add_vv(in1y_22_0_cotmp_4, in1y_22_pack_0);
      V16S in1y_22_0 = in1y_22_0_cotmp_5;

      V16S in1y_23_pack_0 = in1y_22_0;
      // max in1y_23_0 <= (in1y_23_pack_1 , in1y_23_pack_0)
      V16S in1y_23_0_cotmp_1 = max_vv(in1y_23_pack_1, in1y_23_pack_0);
      V16S in1y_23_0 = in1y_23_0_cotmp_1;

      V16S in1y_24_pack_0 = in1y_23_0;
      // min in1y_24_0 <= (in1y_24_pack_1 , in1y_24_pack_0)
      V16S in1y_24_0_cotmp_1 = min_vv(in1y_24_pack_1, in1y_24_pack_0);
      V16S in1y_24_0 = in1y_24_0_cotmp_1;

      V16S Wxx_32_0 = Wxx_31_0;
      V16S Wxx_33_0 = rshift_vv(Wxx_32_0, Wxx_18_0);
      V16S Wxx_34_pack_0 = Wxx_33_0;
      // max Wxx_34_0 <= (Wxx_34_pack_1 , Wxx_34_pack_0)
      V16S Wxx_34_0_cotmp_1 = max_vv(Wxx_34_pack_1, Wxx_34_pack_0);
      V16S Wxx_34_0 = Wxx_34_0_cotmp_1;

      V16S Wxx_35_pack_0 = Wxx_34_0;
      // min Wxx_35_0 <= (Wxx_35_pack_1 , Wxx_35_pack_0)
      V16S Wxx_35_0_cotmp_1 = min_vv(Wxx_35_pack_1, Wxx_35_pack_0);
      V16S Wxx_35_0 = Wxx_35_0_cotmp_1;

      V16S Wxx_36_0 = Wxx_35_0;
      V16S sobel_3_1 = in1y_24_0;
      V16S Wyy_21_0 = sobel_3_1;
      V16S Wxy_19_0 = mult_vv(Wxx_30_0, Wyy_21_0);
      V16S Wyy_22_0 = mult_vv(Wyy_21_0, Wyy_21_0);
      V16S Wyy_23_0 = Wyy_22_0;
      V16S Wyy_24_0 = rshift_vv(Wyy_23_0, Wxx_18_0);
      V16S Wyy_25_pack_0 = Wyy_24_0;
      // max Wyy_25_0 <= (Wyy_25_pack_1 , Wyy_25_pack_0)
      V16S Wyy_25_0_cotmp_1 = max_vv(Wyy_25_pack_1, Wyy_25_pack_0);
      V16S Wyy_25_0 = Wyy_25_0_cotmp_1;

      V16S Wyy_26_pack_0 = Wyy_25_0;
      // min Wyy_26_0 <= (Wyy_26_pack_1 , Wyy_26_pack_0)
      V16S Wyy_26_0_cotmp_1 = min_vv(Wyy_26_pack_1, Wyy_26_pack_0);
      V16S Wyy_26_0 = Wyy_26_0_cotmp_1;

      V16S Wyy_27_0 = Wyy_26_0;
      V16S TrSq_21_0 = add_vv(Wxx_36_0, Wyy_27_0);
      V16S TrSq_22_0 = TrSq_21_0;
      V16S TrSq_23_0 = rshift_vv(TrSq_22_0, in1x_17_0);
      V16S TrSq_24_0 = mult_vv(TrSq_23_0, TrSq_23_0);
      V16S TrSq_25_0 = rshift_vv(TrSq_24_0, TrSq_12_0);
      V16S TrSq_26_0 = TrSq_25_0;
      V16S Resp1_7_0 = mult_vv(tap_K_0, TrSq_26_0);
      V16S Det_25_0 = mult_vv(Wxx_36_0, Wyy_27_0);
      V16S Det_26_0 = Det_25_0;
      V16S Det_27_0 = rshift_vv(Det_26_0, in1x_17_0);
      V16S Wxy_20_0 = Wxy_19_0;
      V16S Wxy_21_0 = rshift_vv(Wxy_20_0, Wxx_18_0);
      V16S Wxy_22_pack_0 = Wxy_21_0;
      // max Wxy_22_0 <= (Wxy_22_pack_1 , Wxy_22_pack_0)
      V16S Wxy_22_0_cotmp_1 = max_vv(Wxy_22_pack_1, Wxy_22_pack_0);
      V16S Wxy_22_0 = Wxy_22_0_cotmp_1;

      V16S Wxy_23_pack_0 = Wxy_22_0;
      // min Wxy_23_0 <= (Wxy_23_pack_1 , Wxy_23_pack_0)
      V16S Wxy_23_0_cotmp_1 = min_vv(Wxy_23_pack_1, Wxy_23_pack_0);
      V16S Wxy_23_0 = Wxy_23_0_cotmp_1;

      V16S Wxy_24_0 = Wxy_23_0;
      V16S Det_28_0 = mult_vv(Wxy_24_0, Wxy_24_0);
      V16S Det_29_0 = Det_28_0;
      V16S Det_30_0 = rshift_vv(Det_29_0, in1x_17_0);
      V16S Det_31_0 = sub_vv(Det_27_0, Det_30_0);
      V16S Det_32_0 = Det_31_0;
      V16S Resp1_8_0 = sub_vv(Det_32_0, Resp1_7_0);
      V16S Resp_17_pack_0 = Resp1_8_0;
      // max Resp_17_0 <= (Resp_17_pack_1 , Resp_17_pack_0)
      V16S Resp_17_0_cotmp_1 = max_vv(Resp_17_pack_1, Resp_17_pack_0);
      V16S Resp_17_0 = Resp_17_0_cotmp_1;

      V16S Resp_18_pack_0 = Resp_17_0;
      // min Resp_18_0 <= (Resp_18_pack_1 , Resp_18_pack_0)
      V16S Resp_18_0_cotmp_1 = min_vv(Resp_18_pack_1, Resp_18_pack_0);
      V16S Resp_18_0 = Resp_18_0_cotmp_1;

      out_ptr[y*IN_WIDTH*OUT_CHANNELS + x*OUT_CHANNELS + 0] = Resp_18_0;
    }
    for(int x = IN_WIDTH - 1; x < IN_WIDTH; x++){
      // on X boundry
      // shift the stencil window, and load the new input pixel
      downCast_38_pp_0_2 = downCast_38_pp_1_2;
      downCast_38_pp_0_1 = downCast_38_pp_1_1;
      downCast_38_pp_0_0 = downCast_38_pp_1_0;
      downCast_38_pp_1_2 = downCast_38_pp_2_2;
      downCast_38_pp_1_1 = downCast_38_pp_2_1;
      downCast_38_pp_1_0 = downCast_38_pp_2_0;
      
      // load the update stencil
      downCast_38_pp_2_2 = in_ptr[(y+2)*IN_WIDTH*IN_CHANNELS + (x + 1 - IN_WIDTH)*IN_CHANNELS + 0];
      downCast_38_pp_2_2 = getr_vv(downCast_38_pp_2_2);
      downCast_38_pp_2_1 = in_ptr[(y+1)*IN_WIDTH*IN_CHANNELS + (x + 1 - IN_WIDTH)*IN_CHANNELS + 0];
      downCast_38_pp_2_1 = getr_vv(downCast_38_pp_2_1);
      downCast_38_pp_2_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (x + 1 - IN_WIDTH)*IN_CHANNELS + 0];
      downCast_38_pp_2_0 = getr_vv(downCast_38_pp_2_0);
      
      // Start operation
      V16S in1_27_0 = downCast_38_pp_0_0;
      V16S TrSq_12_0 = c_7_0;
      V16S Resp_11_0 = c_127_0;
      V16S Wyy_26_pack_1 = Resp_11_0;
      V16S in1_30_0 = downCast_38_pp_2_1;
      V16S in1y_22_pack_3 = in1_27_0;
      V16S Resp_12_0 = inv_vv(Resp_11_0);
      V16S in1x_51_pack_1 = Resp_12_0;
      V16S in1_28_0 = downCast_38_pp_2_2;
      V16S in1x_52_pack_1 = Resp_11_0;
      V16S Wyy_25_pack_1 = Resp_12_0;
      V16S in1y_23_pack_1 = Resp_12_0;
      V16S in1_25_0 = downCast_38_pp_0_2;
      V16S Resp_17_pack_1 = Resp_12_0;
      V16S in1x_42_0 = inv_vv(in1_25_0);
      V16S in1x_47_0 = inv_vv(in1_28_0);
      V16S in1y_22_pack_0 = in1x_42_0;
      V16S Wxy_22_pack_1 = Resp_12_0;
      V16S in1x_46_0 = inv_vv(in1_27_0);
      V16S in1x_50_pack_2 = in1x_46_0;
      V16S in1x_50_pack_0 = in1x_42_0;
      V16S Wxx_18_0 = c_8_0;
      V16S Resp_18_pack_1 = Resp_11_0;
      V16S in1x_48_0 = in1_30_0;
      V16S in1_29_0 = downCast_38_pp_2_0;
      V16S in1y_22_pack_5 = in1_29_0;
      V16S in1x_50_pack_5 = in1_29_0;
      V16S Wxx_34_pack_1 = Resp_12_0;
      V16S in1_31_0 = downCast_38_pp_1_2;
      V16S Wxy_23_pack_1 = Resp_11_0;
      V16S in1x_53_0 = in1_31_0;
      V16S in1x_50_pack_3 = in1_28_0;
      V16S in1_26_0 = downCast_38_pp_0_1;
      V16S in1x_43_0 = in1_26_0;
      V16S in1y_24_pack_1 = Resp_11_0;
      V16S Wxx_35_pack_1 = Resp_11_0;
      V16S in1_32_0 = downCast_38_pp_1_0;
      V16S in1x_54_0 = in1_32_0;
      V16S in1y_22_pack_2 = in1x_47_0;
      V16S in1x_17_0 = c_1_0;
      V16S in1y_19_0 = lshift_vv(in1x_53_0, in1x_17_0);
      V16S in1y_21_0 = lshift_vv(in1x_54_0, in1x_17_0);
      V16S in1y_22_pack_4 = in1y_21_0;
      V16S in1x_49_0 = lshift_vv(in1x_48_0, in1x_17_0);
      V16S in1x_50_pack_4 = in1x_49_0;
      V16S in1x_44_0 = lshift_vv(in1x_43_0, in1x_17_0);
      V16S in1x_45_0 = inv_vv(in1x_44_0);
      V16S in1x_50_pack_1 = in1x_45_0;
      // add in1x_50_0 <= (in1x_50_pack_5 , in1x_50_pack_4 , in1x_50_pack_3 , in1x_50_pack_2 , in1x_50_pack_1 , in1x_50_pack_0)
      V16S in1x_50_0_cotmp_1 = add_vv(in1x_50_pack_5, in1x_50_pack_4);
      V16S in1x_50_0_cotmp_2 = add_vv(in1x_50_0_cotmp_1, in1x_50_pack_3);
      V16S in1x_50_0_cotmp_3 = add_vv(in1x_50_0_cotmp_2, in1x_50_pack_2);
      V16S in1x_50_0_cotmp_4 = add_vv(in1x_50_0_cotmp_3, in1x_50_pack_1);
      V16S in1x_50_0_cotmp_5 = add_vv(in1x_50_0_cotmp_4, in1x_50_pack_0);
      V16S in1x_50_0 = in1x_50_0_cotmp_5;

      V16S in1x_51_pack_0 = in1x_50_0;
      // max in1x_51_0 <= (in1x_51_pack_1 , in1x_51_pack_0)
      V16S in1x_51_0_cotmp_1 = max_vv(in1x_51_pack_1, in1x_51_pack_0);
      V16S in1x_51_0 = in1x_51_0_cotmp_1;

      V16S in1x_52_pack_0 = in1x_51_0;
      // min in1x_52_0 <= (in1x_52_pack_1 , in1x_52_pack_0)
      V16S in1x_52_0_cotmp_1 = min_vv(in1x_52_pack_1, in1x_52_pack_0);
      V16S in1x_52_0 = in1x_52_0_cotmp_1;

      V16S sobel_3_0 = in1x_52_0;
      V16S Wxx_30_0 = sobel_3_0;
      V16S Wxx_31_0 = mult_vv(Wxx_30_0, Wxx_30_0);
      V16S in1y_20_0 = inv_vv(in1y_19_0);
      V16S in1y_22_pack_1 = in1y_20_0;
      // add in1y_22_0 <= (in1y_22_pack_5 , in1y_22_pack_4 , in1y_22_pack_3 , in1y_22_pack_2 , in1y_22_pack_1 , in1y_22_pack_0)
      V16S in1y_22_0_cotmp_1 = add_vv(in1y_22_pack_5, in1y_22_pack_4);
      V16S in1y_22_0_cotmp_2 = add_vv(in1y_22_0_cotmp_1, in1y_22_pack_3);
      V16S in1y_22_0_cotmp_3 = add_vv(in1y_22_0_cotmp_2, in1y_22_pack_2);
      V16S in1y_22_0_cotmp_4 = add_vv(in1y_22_0_cotmp_3, in1y_22_pack_1);
      V16S in1y_22_0_cotmp_5 = add_vv(in1y_22_0_cotmp_4, in1y_22_pack_0);
      V16S in1y_22_0 = in1y_22_0_cotmp_5;

      V16S in1y_23_pack_0 = in1y_22_0;
      // max in1y_23_0 <= (in1y_23_pack_1 , in1y_23_pack_0)
      V16S in1y_23_0_cotmp_1 = max_vv(in1y_23_pack_1, in1y_23_pack_0);
      V16S in1y_23_0 = in1y_23_0_cotmp_1;

      V16S in1y_24_pack_0 = in1y_23_0;
      // min in1y_24_0 <= (in1y_24_pack_1 , in1y_24_pack_0)
      V16S in1y_24_0_cotmp_1 = min_vv(in1y_24_pack_1, in1y_24_pack_0);
      V16S in1y_24_0 = in1y_24_0_cotmp_1;

      V16S Wxx_32_0 = Wxx_31_0;
      V16S Wxx_33_0 = rshift_vv(Wxx_32_0, Wxx_18_0);
      V16S Wxx_34_pack_0 = Wxx_33_0;
      // max Wxx_34_0 <= (Wxx_34_pack_1 , Wxx_34_pack_0)
      V16S Wxx_34_0_cotmp_1 = max_vv(Wxx_34_pack_1, Wxx_34_pack_0);
      V16S Wxx_34_0 = Wxx_34_0_cotmp_1;

      V16S Wxx_35_pack_0 = Wxx_34_0;
      // min Wxx_35_0 <= (Wxx_35_pack_1 , Wxx_35_pack_0)
      V16S Wxx_35_0_cotmp_1 = min_vv(Wxx_35_pack_1, Wxx_35_pack_0);
      V16S Wxx_35_0 = Wxx_35_0_cotmp_1;

      V16S Wxx_36_0 = Wxx_35_0;
      V16S sobel_3_1 = in1y_24_0;
      V16S Wyy_21_0 = sobel_3_1;
      V16S Wxy_19_0 = mult_vv(Wxx_30_0, Wyy_21_0);
      V16S Wyy_22_0 = mult_vv(Wyy_21_0, Wyy_21_0);
      V16S Wyy_23_0 = Wyy_22_0;
      V16S Wyy_24_0 = rshift_vv(Wyy_23_0, Wxx_18_0);
      V16S Wyy_25_pack_0 = Wyy_24_0;
      // max Wyy_25_0 <= (Wyy_25_pack_1 , Wyy_25_pack_0)
      V16S Wyy_25_0_cotmp_1 = max_vv(Wyy_25_pack_1, Wyy_25_pack_0);
      V16S Wyy_25_0 = Wyy_25_0_cotmp_1;

      V16S Wyy_26_pack_0 = Wyy_25_0;
      // min Wyy_26_0 <= (Wyy_26_pack_1 , Wyy_26_pack_0)
      V16S Wyy_26_0_cotmp_1 = min_vv(Wyy_26_pack_1, Wyy_26_pack_0);
      V16S Wyy_26_0 = Wyy_26_0_cotmp_1;

      V16S Wyy_27_0 = Wyy_26_0;
      V16S TrSq_21_0 = add_vv(Wxx_36_0, Wyy_27_0);
      V16S TrSq_22_0 = TrSq_21_0;
      V16S TrSq_23_0 = rshift_vv(TrSq_22_0, in1x_17_0);
      V16S TrSq_24_0 = mult_vv(TrSq_23_0, TrSq_23_0);
      V16S TrSq_25_0 = rshift_vv(TrSq_24_0, TrSq_12_0);
      V16S TrSq_26_0 = TrSq_25_0;
      V16S Resp1_7_0 = mult_vv(tap_K_0, TrSq_26_0);
      V16S Det_25_0 = mult_vv(Wxx_36_0, Wyy_27_0);
      V16S Det_26_0 = Det_25_0;
      V16S Det_27_0 = rshift_vv(Det_26_0, in1x_17_0);
      V16S Wxy_20_0 = Wxy_19_0;
      V16S Wxy_21_0 = rshift_vv(Wxy_20_0, Wxx_18_0);
      V16S Wxy_22_pack_0 = Wxy_21_0;
      // max Wxy_22_0 <= (Wxy_22_pack_1 , Wxy_22_pack_0)
      V16S Wxy_22_0_cotmp_1 = max_vv(Wxy_22_pack_1, Wxy_22_pack_0);
      V16S Wxy_22_0 = Wxy_22_0_cotmp_1;

      V16S Wxy_23_pack_0 = Wxy_22_0;
      // min Wxy_23_0 <= (Wxy_23_pack_1 , Wxy_23_pack_0)
      V16S Wxy_23_0_cotmp_1 = min_vv(Wxy_23_pack_1, Wxy_23_pack_0);
      V16S Wxy_23_0 = Wxy_23_0_cotmp_1;

      V16S Wxy_24_0 = Wxy_23_0;
      V16S Det_28_0 = mult_vv(Wxy_24_0, Wxy_24_0);
      V16S Det_29_0 = Det_28_0;
      V16S Det_30_0 = rshift_vv(Det_29_0, in1x_17_0);
      V16S Det_31_0 = sub_vv(Det_27_0, Det_30_0);
      V16S Det_32_0 = Det_31_0;
      V16S Resp1_8_0 = sub_vv(Det_32_0, Resp1_7_0);
      V16S Resp_17_pack_0 = Resp1_8_0;
      // max Resp_17_0 <= (Resp_17_pack_1 , Resp_17_pack_0)
      V16S Resp_17_0_cotmp_1 = max_vv(Resp_17_pack_1, Resp_17_pack_0);
      V16S Resp_17_0 = Resp_17_0_cotmp_1;

      V16S Resp_18_pack_0 = Resp_17_0;
      // min Resp_18_0 <= (Resp_18_pack_1 , Resp_18_pack_0)
      V16S Resp_18_0_cotmp_1 = min_vv(Resp_18_pack_1, Resp_18_pack_0);
      V16S Resp_18_0 = Resp_18_0_cotmp_1;

      out_ptr[y*IN_WIDTH*OUT_CHANNELS + x*OUT_CHANNELS + 0] = Resp_18_0;
    }
  }
  
  // End SAIF power toggle data capture
  set_power_toggle(POWER_TOGGLE_OFF);
} // END Resp_5


void downCast_15(const Image<V16S>& in, Image<V16S>& out
	, signed int tap_G1_0_s
	, signed int tap_G0_0_s
	, signed int tap_G2_0_s
	, signed int tap_G4_0_s
	, signed int tap_G3_0_s
	, unsigned int tap_R_0_s
)
{
  // Set up the tap values
  const register V16S tap_G1_0 = mv_sv(tap_G1_0_s);
  const register V16S tap_G0_0 = mv_sv(tap_G0_0_s);
  const register V16S tap_G2_0 = mv_sv(tap_G2_0_s);
  const register V16S tap_G4_0 = mv_sv(tap_G4_0_s);
  const register V16S tap_G3_0 = mv_sv(tap_G3_0_s);
  const register V16S tap_R_0 = mv_sv(tap_R_0_s);
  
  // Set up the constant values
  const register V16S c_0_0 = mv_sv(0);
  const register V16S c_255_0 = mv_sv(255);
  
  const V16S *in_ptr = in.mData; // use direct access to speed up inner loop
  V16S *out_ptr = out.mData; // use direct access to speed up inner loop
  const int IN_WIDTH = in.width();
  const int IN_HEIGHT = in.height();
  const int IN_CHANNELS = 1; // use static value to allow more compiler optimization
  const int OUT_CHANNELS = 1; /// use static value to allow more compiler optimization
  
  // Turn on SAIF power toggle data capture
  set_power_toggle(POWER_TOGGLE_ON);
  for(int y = 0; y < in.height(); y++){
    // DEBUG: y_min=0, y_max=0, y_padding_ofst=0
    // declare the registers storing the stencil window
    register V16S downCast_20_pp_4_0;
    register V16S downCast_20_pp_3_0;
    register V16S downCast_20_pp_2_0;
    register V16S downCast_20_pp_1_0;
    register V16S downCast_20_pp_0_0;
    
    // load the stencil window for each scan of row
    downCast_20_pp_1_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -2)*IN_CHANNELS + 0];
    downCast_20_pp_1_0 = getl_vv(downCast_20_pp_1_0);
    downCast_20_pp_2_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -1)*IN_CHANNELS + 0];
    downCast_20_pp_2_0 = getl_vv(downCast_20_pp_2_0);
    downCast_20_pp_3_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (0)*IN_CHANNELS + 0];
    downCast_20_pp_4_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (1)*IN_CHANNELS + 0];
    
    for(int x = 0; x < IN_WIDTH - 2; x++){
      // not on X boundry, common case
      // shift the stencil window, and load the new input pixel
      downCast_20_pp_0_0 = downCast_20_pp_1_0;
      downCast_20_pp_1_0 = downCast_20_pp_2_0;
      downCast_20_pp_2_0 = downCast_20_pp_3_0;
      downCast_20_pp_3_0 = downCast_20_pp_4_0;
      
      // load the update stencil
      downCast_20_pp_4_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (x+2)*IN_CHANNELS + 0];
      
      // Start operation
      V16S upCast_40_0 = downCast_20_pp_0_0;
      V16S convolve_1_5__93_0 = mult_vv(upCast_40_0, tap_G0_0);
      V16S upCast_38_0 = downCast_20_pp_4_0;
      V16S convolve_1_5__91_0 = mult_vv(upCast_38_0, tap_G4_0);
      V16S convolve_1_5__94_pack_4 = convolve_1_5__91_0;
      V16S Wxx_14_0 = c_0_0;
      V16S convolve_1_5__75_0 = c_255_0;
      V16S upCast_39_0 = downCast_20_pp_3_0;
      V16S convolve_1_5__98_pack_1 = convolve_1_5__75_0;
      V16S convolve_1_5__94_pack_0 = convolve_1_5__93_0;
      V16S convolve_1_5__72_0 = tap_R_0;
      V16S convolve_1_5__97_pack_1 = Wxx_14_0;
      V16S upCast_37_0 = downCast_20_pp_2_0;
      V16S convolve_1_5__90_0 = mult_vv(upCast_37_0, tap_G2_0);
      V16S convolve_1_5__94_pack_2 = convolve_1_5__90_0;
      V16S convolve_1_5__92_0 = mult_vv(upCast_39_0, tap_G3_0);
      V16S convolve_1_5__94_pack_3 = convolve_1_5__92_0;
      V16S upCast_36_0 = downCast_20_pp_1_0;
      V16S convolve_1_5__89_0 = mult_vv(upCast_36_0, tap_G1_0);
      V16S convolve_1_5__94_pack_1 = convolve_1_5__89_0;
      // add convolve_1_5__94_0 <= (convolve_1_5__94_pack_4 , convolve_1_5__94_pack_3 , convolve_1_5__94_pack_2 , convolve_1_5__94_pack_1 , convolve_1_5__94_pack_0)
      V16S convolve_1_5__94_0_cotmp_1 = add_vv(convolve_1_5__94_pack_4, convolve_1_5__94_pack_3);
      V16S convolve_1_5__94_0_cotmp_2 = add_vv(convolve_1_5__94_0_cotmp_1, convolve_1_5__94_pack_2);
      V16S convolve_1_5__94_0_cotmp_3 = add_vv(convolve_1_5__94_0_cotmp_2, convolve_1_5__94_pack_1);
      V16S convolve_1_5__94_0_cotmp_4 = add_vv(convolve_1_5__94_0_cotmp_3, convolve_1_5__94_pack_0);
      V16S convolve_1_5__94_0 = convolve_1_5__94_0_cotmp_4;

      V16S convolve_1_5__95_0 = convolve_1_5__94_0;
      V16S convolve_1_5__96_0 = rshift_vv(convolve_1_5__95_0, convolve_1_5__72_0);
      V16S convolve_1_5__97_pack_0 = convolve_1_5__96_0;
      // max convolve_1_5__97_0 <= (convolve_1_5__97_pack_1 , convolve_1_5__97_pack_0)
      V16S convolve_1_5__97_0_cotmp_1 = max_vv(convolve_1_5__97_pack_1, convolve_1_5__97_pack_0);
      V16S convolve_1_5__97_0 = convolve_1_5__97_0_cotmp_1;

      V16S convolve_1_5__98_pack_0 = convolve_1_5__97_0;
      // min convolve_1_5__98_0 <= (convolve_1_5__98_pack_1 , convolve_1_5__98_pack_0)
      V16S convolve_1_5__98_0_cotmp_1 = min_vv(convolve_1_5__98_pack_1, convolve_1_5__98_pack_0);
      V16S convolve_1_5__98_0 = convolve_1_5__98_0_cotmp_1;

      V16S convolve_1_5__99_0 = convolve_1_5__98_0;
      V16S downCast_38_0 = convolve_1_5__99_0;
      out_ptr[y*IN_WIDTH*OUT_CHANNELS + x*OUT_CHANNELS + 0] = downCast_38_0;
    }
    for(int x = IN_WIDTH - 2; x < IN_WIDTH; x++){
      // on X boundry
      // shift the stencil window, and load the new input pixel
      downCast_20_pp_0_0 = downCast_20_pp_1_0;
      downCast_20_pp_1_0 = downCast_20_pp_2_0;
      downCast_20_pp_2_0 = downCast_20_pp_3_0;
      downCast_20_pp_3_0 = downCast_20_pp_4_0;
      
      // load the update stencil
      downCast_20_pp_4_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (x + 2 - IN_WIDTH)*IN_CHANNELS + 0];
      downCast_20_pp_4_0 = getr_vv(downCast_20_pp_4_0);
      
      // Start operation
      V16S upCast_40_0 = downCast_20_pp_0_0;
      V16S convolve_1_5__93_0 = mult_vv(upCast_40_0, tap_G0_0);
      V16S upCast_38_0 = downCast_20_pp_4_0;
      V16S convolve_1_5__91_0 = mult_vv(upCast_38_0, tap_G4_0);
      V16S convolve_1_5__94_pack_4 = convolve_1_5__91_0;
      V16S Wxx_14_0 = c_0_0;
      V16S convolve_1_5__75_0 = c_255_0;
      V16S upCast_39_0 = downCast_20_pp_3_0;
      V16S convolve_1_5__98_pack_1 = convolve_1_5__75_0;
      V16S convolve_1_5__94_pack_0 = convolve_1_5__93_0;
      V16S convolve_1_5__72_0 = tap_R_0;
      V16S convolve_1_5__97_pack_1 = Wxx_14_0;
      V16S upCast_37_0 = downCast_20_pp_2_0;
      V16S convolve_1_5__90_0 = mult_vv(upCast_37_0, tap_G2_0);
      V16S convolve_1_5__94_pack_2 = convolve_1_5__90_0;
      V16S convolve_1_5__92_0 = mult_vv(upCast_39_0, tap_G3_0);
      V16S convolve_1_5__94_pack_3 = convolve_1_5__92_0;
      V16S upCast_36_0 = downCast_20_pp_1_0;
      V16S convolve_1_5__89_0 = mult_vv(upCast_36_0, tap_G1_0);
      V16S convolve_1_5__94_pack_1 = convolve_1_5__89_0;
      // add convolve_1_5__94_0 <= (convolve_1_5__94_pack_4 , convolve_1_5__94_pack_3 , convolve_1_5__94_pack_2 , convolve_1_5__94_pack_1 , convolve_1_5__94_pack_0)
      V16S convolve_1_5__94_0_cotmp_1 = add_vv(convolve_1_5__94_pack_4, convolve_1_5__94_pack_3);
      V16S convolve_1_5__94_0_cotmp_2 = add_vv(convolve_1_5__94_0_cotmp_1, convolve_1_5__94_pack_2);
      V16S convolve_1_5__94_0_cotmp_3 = add_vv(convolve_1_5__94_0_cotmp_2, convolve_1_5__94_pack_1);
      V16S convolve_1_5__94_0_cotmp_4 = add_vv(convolve_1_5__94_0_cotmp_3, convolve_1_5__94_pack_0);
      V16S convolve_1_5__94_0 = convolve_1_5__94_0_cotmp_4;

      V16S convolve_1_5__95_0 = convolve_1_5__94_0;
      V16S convolve_1_5__96_0 = rshift_vv(convolve_1_5__95_0, convolve_1_5__72_0);
      V16S convolve_1_5__97_pack_0 = convolve_1_5__96_0;
      // max convolve_1_5__97_0 <= (convolve_1_5__97_pack_1 , convolve_1_5__97_pack_0)
      V16S convolve_1_5__97_0_cotmp_1 = max_vv(convolve_1_5__97_pack_1, convolve_1_5__97_pack_0);
      V16S convolve_1_5__97_0 = convolve_1_5__97_0_cotmp_1;

      V16S convolve_1_5__98_pack_0 = convolve_1_5__97_0;
      // min convolve_1_5__98_0 <= (convolve_1_5__98_pack_1 , convolve_1_5__98_pack_0)
      V16S convolve_1_5__98_0_cotmp_1 = min_vv(convolve_1_5__98_pack_1, convolve_1_5__98_pack_0);
      V16S convolve_1_5__98_0 = convolve_1_5__98_0_cotmp_1;

      V16S convolve_1_5__99_0 = convolve_1_5__98_0;
      V16S downCast_38_0 = convolve_1_5__99_0;
      out_ptr[y*IN_WIDTH*OUT_CHANNELS + x*OUT_CHANNELS + 0] = downCast_38_0;
    }
  }
  
  // End SAIF power toggle data capture
  set_power_toggle(POWER_TOGGLE_OFF);
} // END downCast_15


void NMS_10(const Image<V16S>& in, Image<V16S>& out
	, signed int tap_Peak_0_s
)
{
  // Set up the tap values
  const register V16S tap_Peak_0 = mv_sv(tap_Peak_0_s);
  
  // Set up the constant values
  const register V16S c_0_0 = mv_sv(0);
  const register V16S c_255_0 = mv_sv(255);
  
  const V16S *in_ptr = in.mData; // use direct access to speed up inner loop
  V16S *out_ptr = out.mData; // use direct access to speed up inner loop
  const int IN_WIDTH = in.width();
  const int IN_HEIGHT = in.height();
  const int IN_CHANNELS = 1; // use static value to allow more compiler optimization
  const int OUT_CHANNELS = 1; /// use static value to allow more compiler optimization
  
  // Turn on SAIF power toggle data capture
  set_power_toggle(POWER_TOGGLE_ON);
  for(int y = 0; y < in.height(); y++){
    // DEBUG: y_min=-1, y_max=1, y_padding_ofst=1
    // declare the registers storing the stencil window
    register V16S Resp_18_pp_2_2;
    register V16S Resp_18_pp_2_1;
    register V16S Resp_18_pp_2_0;
    register V16S Resp_18_pp_1_2;
    register V16S Resp_18_pp_1_1;
    register V16S Resp_18_pp_1_0;
    register V16S Resp_18_pp_0_2;
    register V16S Resp_18_pp_0_1;
    register V16S Resp_18_pp_0_0;
    
    // load the stencil window for each scan of row
    Resp_18_pp_1_2 = in_ptr[(y+2)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -1)*IN_CHANNELS + 0];
    Resp_18_pp_1_2 = getl_vv(Resp_18_pp_1_2);
    Resp_18_pp_1_1 = in_ptr[(y+1)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -1)*IN_CHANNELS + 0];
    Resp_18_pp_1_1 = getl_vv(Resp_18_pp_1_1);
    Resp_18_pp_1_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -1)*IN_CHANNELS + 0];
    Resp_18_pp_1_0 = getl_vv(Resp_18_pp_1_0);
    Resp_18_pp_2_2 = in_ptr[(y+2)*IN_WIDTH*IN_CHANNELS + (0)*IN_CHANNELS + 0];
    Resp_18_pp_2_1 = in_ptr[(y+1)*IN_WIDTH*IN_CHANNELS + (0)*IN_CHANNELS + 0];
    Resp_18_pp_2_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (0)*IN_CHANNELS + 0];
    
    for(int x = 0; x < IN_WIDTH - 1; x++){
      // not on X boundry, common case
      // shift the stencil window, and load the new input pixel
      Resp_18_pp_0_2 = Resp_18_pp_1_2;
      Resp_18_pp_0_1 = Resp_18_pp_1_1;
      Resp_18_pp_0_0 = Resp_18_pp_1_0;
      Resp_18_pp_1_2 = Resp_18_pp_2_2;
      Resp_18_pp_1_1 = Resp_18_pp_2_1;
      Resp_18_pp_1_0 = Resp_18_pp_2_0;
      
      // load the update stencil
      Resp_18_pp_2_2 = in_ptr[(y+2)*IN_WIDTH*IN_CHANNELS + (x+1)*IN_CHANNELS + 0];
      Resp_18_pp_2_1 = in_ptr[(y+1)*IN_WIDTH*IN_CHANNELS + (x+1)*IN_CHANNELS + 0];
      Resp_18_pp_2_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (x+1)*IN_CHANNELS + 0];
      
      // Start operation
      V16S convolve_1_5__100_0 = c_255_0;
      V16S P_4_0 = gt_vv(Resp_18_pp_1_1, tap_Peak_0);
      V16S PN_4_0 = gt_vv(Resp_18_pp_1_1, Resp_18_pp_1_2);
      V16S PW_4_0 = gte_vv(Resp_18_pp_1_1, Resp_18_pp_0_1);
      V16S PE_4_0 = gt_vv(Resp_18_pp_1_1, Resp_18_pp_2_1);
      V16S PS_4_0 = gte_vv(Resp_18_pp_1_1, Resp_18_pp_1_0);
      V16S Pk_13_0 = and_vv(P_4_0, PW_4_0);
      V16S Pk_14_0 = and_vv(Pk_13_0, PE_4_0);
      V16S Pk_15_0 = and_vv(Pk_14_0, PS_4_0);
      V16S Wxx_37_0 = c_0_0;
      V16S Pk_16_0 = and_vv(Pk_15_0, PN_4_0);
      V16S NMS_8_0 = mux_vv(Pk_16_0, convolve_1_5__100_0, Wxx_37_0);
      V16S NMS_9_0 = NMS_8_0;
      out_ptr[y*IN_WIDTH*OUT_CHANNELS + x*OUT_CHANNELS + 0] = NMS_9_0;
    }
    for(int x = IN_WIDTH - 1; x < IN_WIDTH; x++){
      // on X boundry
      // shift the stencil window, and load the new input pixel
      Resp_18_pp_0_2 = Resp_18_pp_1_2;
      Resp_18_pp_0_1 = Resp_18_pp_1_1;
      Resp_18_pp_0_0 = Resp_18_pp_1_0;
      Resp_18_pp_1_2 = Resp_18_pp_2_2;
      Resp_18_pp_1_1 = Resp_18_pp_2_1;
      Resp_18_pp_1_0 = Resp_18_pp_2_0;
      
      // load the update stencil
      Resp_18_pp_2_2 = in_ptr[(y+2)*IN_WIDTH*IN_CHANNELS + (x + 1 - IN_WIDTH)*IN_CHANNELS + 0];
      Resp_18_pp_2_2 = getr_vv(Resp_18_pp_2_2);
      Resp_18_pp_2_1 = in_ptr[(y+1)*IN_WIDTH*IN_CHANNELS + (x + 1 - IN_WIDTH)*IN_CHANNELS + 0];
      Resp_18_pp_2_1 = getr_vv(Resp_18_pp_2_1);
      Resp_18_pp_2_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (x + 1 - IN_WIDTH)*IN_CHANNELS + 0];
      Resp_18_pp_2_0 = getr_vv(Resp_18_pp_2_0);
      
      // Start operation
      V16S convolve_1_5__100_0 = c_255_0;
      V16S P_4_0 = gt_vv(Resp_18_pp_1_1, tap_Peak_0);
      V16S PN_4_0 = gt_vv(Resp_18_pp_1_1, Resp_18_pp_1_2);
      V16S PW_4_0 = gte_vv(Resp_18_pp_1_1, Resp_18_pp_0_1);
      V16S PE_4_0 = gt_vv(Resp_18_pp_1_1, Resp_18_pp_2_1);
      V16S PS_4_0 = gte_vv(Resp_18_pp_1_1, Resp_18_pp_1_0);
      V16S Pk_13_0 = and_vv(P_4_0, PW_4_0);
      V16S Pk_14_0 = and_vv(Pk_13_0, PE_4_0);
      V16S Pk_15_0 = and_vv(Pk_14_0, PS_4_0);
      V16S Wxx_37_0 = c_0_0;
      V16S Pk_16_0 = and_vv(Pk_15_0, PN_4_0);
      V16S NMS_8_0 = mux_vv(Pk_16_0, convolve_1_5__100_0, Wxx_37_0);
      V16S NMS_9_0 = NMS_8_0;
      out_ptr[y*IN_WIDTH*OUT_CHANNELS + x*OUT_CHANNELS + 0] = NMS_9_0;
    }
  }
  
  // End SAIF power toggle data capture
  set_power_toggle(POWER_TOGGLE_OFF);
} // END NMS_10


void convertToIllum_10(const Image<V16S>& in, Image<V16S>& out
	, unsigned int tap_Green_to_Lum_0_s
	, unsigned int tap_Blue_to_Lum_0_s
	, unsigned int tap_Red_to_Lum_0_s
	, unsigned int tap_R_0_s
)
{
  // Set up the tap values
  const register V16S tap_Green_to_Lum_0 = mv_sv(tap_Green_to_Lum_0_s);
  const register V16S tap_Blue_to_Lum_0 = mv_sv(tap_Blue_to_Lum_0_s);
  const register V16S tap_Red_to_Lum_0 = mv_sv(tap_Red_to_Lum_0_s);
  const register V16S tap_R_0 = mv_sv(tap_R_0_s);
  
  // Set up the constant values
  const register V16S c_0_0 = mv_sv(0);
  const register V16S c_255_0 = mv_sv(255);
  
  const V16S *in_ptr = in.mData; // use direct access to speed up inner loop
  V16S *out_ptr = out.mData; // use direct access to speed up inner loop
  const int IN_WIDTH = in.width();
  const int IN_HEIGHT = in.height();
  const int IN_CHANNELS = 3; // use static value to allow more compiler optimization
  const int OUT_CHANNELS = 1; /// use static value to allow more compiler optimization
  
  // Turn on SAIF power toggle data capture
  set_power_toggle(POWER_TOGGLE_ON);
  for(int y = 0; y < in.height(); y++){
    // DEBUG: y_min=0, y_max=0, y_padding_ofst=0
    // declare the registers storing the stencil window
    register V16S cropSpecial0Node_7_pp_0_0_2;
    register V16S cropSpecial0Node_7_pp_0_0_1;
    register V16S cropSpecial0Node_7_pp_0_0_0;
    
    // load the stencil window for each scan of row
    
    for(int x = 0; x < IN_WIDTH - 0; x++){
      // not on X boundry, common case
      // shift the stencil window, and load the new input pixel
      
      // load the update stencil
      cropSpecial0Node_7_pp_0_0_2 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (x+0)*IN_CHANNELS + 2];
      cropSpecial0Node_7_pp_0_0_1 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (x+0)*IN_CHANNELS + 1];
      cropSpecial0Node_7_pp_0_0_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (x+0)*IN_CHANNELS + 0];
      
      // Start operation
      V16S convertToIllum_49_0 = cropSpecial0Node_7_pp_0_0_0;
      V16S convertToIllum_50_0 = convertToIllum_49_0;
      V16S convertToIllum_51_0 = mult_vv(convertToIllum_50_0, tap_Red_to_Lum_0);
      V16S Wxx_12_0 = c_0_0;
      V16S convertToIllum_43_0 = cropSpecial0Node_7_pp_0_0_1;
      V16S convertToIllum_44_0 = convertToIllum_43_0;
      V16S convertToIllum_45_0 = mult_vv(convertToIllum_44_0, tap_Green_to_Lum_0);
      V16S convertToIllum_52_pack_1 = convertToIllum_45_0;
      V16S convolve_1_5__29_0 = c_255_0;
      V16S convertToIllum_55_pack_1 = convolve_1_5__29_0;
      V16S convertToIllum_52_pack_0 = convertToIllum_51_0;
      V16S convertToIllum_46_0 = cropSpecial0Node_7_pp_0_0_2;
      V16S convertToIllum_47_0 = convertToIllum_46_0;
      V16S convertToIllum_48_0 = mult_vv(convertToIllum_47_0, tap_Blue_to_Lum_0);
      V16S convertToIllum_52_pack_2 = convertToIllum_48_0;
      // add convertToIllum_52_0 <= (convertToIllum_52_pack_2 , convertToIllum_52_pack_1 , convertToIllum_52_pack_0)
      V16S convertToIllum_52_0_cotmp_1 = add_vv(convertToIllum_52_pack_2, convertToIllum_52_pack_1);
      V16S convertToIllum_52_0_cotmp_2 = add_vv(convertToIllum_52_0_cotmp_1, convertToIllum_52_pack_0);
      V16S convertToIllum_52_0 = convertToIllum_52_0_cotmp_2;

      V16S convertToIllum_53_0 = rshift_vv(convertToIllum_52_0, tap_R_0);
      V16S convertToIllum_54_pack_0 = convertToIllum_53_0;
      V16S convertToIllum_54_pack_1 = Wxx_12_0;
      // max convertToIllum_54_0 <= (convertToIllum_54_pack_1 , convertToIllum_54_pack_0)
      V16S convertToIllum_54_0_cotmp_1 = max_vv(convertToIllum_54_pack_1, convertToIllum_54_pack_0);
      V16S convertToIllum_54_0 = convertToIllum_54_0_cotmp_1;

      V16S convertToIllum_55_pack_0 = convertToIllum_54_0;
      // min convertToIllum_55_0 <= (convertToIllum_55_pack_1 , convertToIllum_55_pack_0)
      V16S convertToIllum_55_0_cotmp_1 = min_vv(convertToIllum_55_pack_1, convertToIllum_55_pack_0);
      V16S convertToIllum_55_0 = convertToIllum_55_0_cotmp_1;

      out_ptr[y*IN_WIDTH*OUT_CHANNELS + x*OUT_CHANNELS + 0] = convertToIllum_55_0;
    }
  }
  
  // End SAIF power toggle data capture
  set_power_toggle(POWER_TOGGLE_OFF);
} // END convertToIllum_10


void scheduledIRNode_19(const Image<V16S>& in, Image<V16S>& out
)
{
  // Set up the tap values
  
  // Set up the constant values
  
  const V16S *in_ptr = in.mData; // use direct access to speed up inner loop
  V16S *out_ptr = out.mData; // use direct access to speed up inner loop
  const int IN_WIDTH = in.width();
  const int IN_HEIGHT = in.height();
  const int IN_CHANNELS = 3; // use static value to allow more compiler optimization
  const int OUT_CHANNELS = 3; /// use static value to allow more compiler optimization
  
  // Turn on SAIF power toggle data capture
  set_power_toggle(POWER_TOGGLE_ON);
  for(int y = 0; y < in.height(); y++){
    // DEBUG: y_min=0, y_max=0, y_padding_ofst=0
    // declare the registers storing the stencil window
    register V16S special0_pp_0_0_2;
    register V16S special0_pp_0_0_1;
    register V16S special0_pp_0_0_0;
    
    // load the stencil window for each scan of row
    
    for(int x = 0; x < IN_WIDTH - 0; x++){
      // not on X boundry, common case
      // shift the stencil window, and load the new input pixel
      
      // load the update stencil
      special0_pp_0_0_2 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (x+0)*IN_CHANNELS + 2];
      special0_pp_0_0_1 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (x+0)*IN_CHANNELS + 1];
      special0_pp_0_0_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (x+0)*IN_CHANNELS + 0];
      
      // Start operation
      V16S cropSpecial0Node_7_0 = special0_pp_0_0_0;
      V16S cropSpecial0Node_7_1 = special0_pp_0_0_1;
      V16S cropSpecial0Node_7_2 = special0_pp_0_0_2;
      out_ptr[y*IN_WIDTH*OUT_CHANNELS + x*OUT_CHANNELS + 2] = cropSpecial0Node_7_2;
      out_ptr[y*IN_WIDTH*OUT_CHANNELS + x*OUT_CHANNELS + 1] = cropSpecial0Node_7_1;
      out_ptr[y*IN_WIDTH*OUT_CHANNELS + x*OUT_CHANNELS + 0] = cropSpecial0Node_7_0;
    }
  }
  
  // End SAIF power toggle data capture
  set_power_toggle(POWER_TOGGLE_OFF);
} // END scheduledIRNode_19


