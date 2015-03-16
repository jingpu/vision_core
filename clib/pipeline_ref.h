#include <stdio.h>
#include <stdlib.h>
#include "image.h"


void lambda_arris_v3lua_line43_10(const Image<int>& in, Image<int>& out
	, unsigned int tap_Green_to_Lum_0
	, unsigned int tap_Blue_to_Lum_0
	, unsigned int tap_Red_to_Lum_0
)
{
  for(int y = 0; y < in.height(); y++){
    for(int x = 0; x < in.width(); x++){
      unsigned int cropSpecial0Node_10_pp_0_0_2 = in(x+0, y+0, 2);
      unsigned int cropSpecial0Node_10_pp_0_0_1 = in(x+0, y+0, 1);
      unsigned int cropSpecial0Node_10_pp_0_0_0 = in(x+0, y+0, 0);
      const float c_0_0 = 0;
      const float c_32767_0 = 32767;
      
      signed int Wxx_8_0 = c_0_0;
      unsigned int lambda_arris_v3lua_line43_46_0 = cropSpecial0Node_10_pp_0_0_0;
      unsigned int lambda_arris_v3lua_line43_47_0 = lambda_arris_v3lua_line43_46_0;
      unsigned int lambda_arris_v3lua_line43_48_0 = lambda_arris_v3lua_line43_47_0 * tap_Red_to_Lum_0;
      unsigned int lambda_arris_v3lua_line43_40_0 = cropSpecial0Node_10_pp_0_0_1;
      unsigned int lambda_arris_v3lua_line43_41_0 = lambda_arris_v3lua_line43_40_0;
      signed int Resp_17_0 = c_32767_0;
      unsigned int lambda_arris_v3lua_line43_51_pack_1 = Resp_17_0;
      unsigned int lambda_arris_v3lua_line43_42_0 = lambda_arris_v3lua_line43_41_0 * tap_Green_to_Lum_0;
      unsigned int lambda_arris_v3lua_line43_49_pack_1 = lambda_arris_v3lua_line43_42_0;
      unsigned int lambda_arris_v3lua_line43_49_pack_0 = lambda_arris_v3lua_line43_48_0;
      unsigned int lambda_arris_v3lua_line43_50_pack_1 = Wxx_8_0;
      unsigned int lambda_arris_v3lua_line43_43_0 = cropSpecial0Node_10_pp_0_0_2;
      unsigned int lambda_arris_v3lua_line43_44_0 = lambda_arris_v3lua_line43_43_0;
      unsigned int lambda_arris_v3lua_line43_45_0 = lambda_arris_v3lua_line43_44_0 * tap_Blue_to_Lum_0;
      unsigned int lambda_arris_v3lua_line43_49_pack_2 = lambda_arris_v3lua_line43_45_0;
      unsigned int lambda_arris_v3lua_line43_49_0 = lambda_arris_v3lua_line43_49_pack_2 + lambda_arris_v3lua_line43_49_pack_1 + lambda_arris_v3lua_line43_49_pack_0;
      unsigned int lambda_arris_v3lua_line43_50_pack_0 = lambda_arris_v3lua_line43_49_0;
      // max lambda_arris_v3lua_line43_50_0 <= (lambda_arris_v3lua_line43_50_pack_1 , lambda_arris_v3lua_line43_50_pack_0)
      unsigned int lambda_arris_v3lua_line43_50_0_cotmp_1 = (lambda_arris_v3lua_line43_50_pack_1 > lambda_arris_v3lua_line43_50_pack_0) ? lambda_arris_v3lua_line43_50_pack_1 : lambda_arris_v3lua_line43_50_pack_0;
      unsigned int lambda_arris_v3lua_line43_50_0 = lambda_arris_v3lua_line43_50_0_cotmp_1;

      unsigned int lambda_arris_v3lua_line43_51_pack_0 = lambda_arris_v3lua_line43_50_0;
      // min lambda_arris_v3lua_line43_51_0 <= (lambda_arris_v3lua_line43_51_pack_1 , lambda_arris_v3lua_line43_51_pack_0)
      unsigned int lambda_arris_v3lua_line43_51_0_cotmp_1 = (lambda_arris_v3lua_line43_51_pack_1 < lambda_arris_v3lua_line43_51_pack_0) ? lambda_arris_v3lua_line43_51_pack_1 : lambda_arris_v3lua_line43_51_pack_0;
      unsigned int lambda_arris_v3lua_line43_51_0 = lambda_arris_v3lua_line43_51_0_cotmp_1;

      out(x,y,0) = lambda_arris_v3lua_line43_51_0;
    }
  }
} // END lambda_arris_v3lua_line43_10


void Resp_5(const Image<int>& in, Image<int>& out
	, signed int tap_K_0
)
{
  for(int y = 0; y < in.height(); y++){
    for(int x = 0; x < in.width(); x++){
      signed int downCast_38_pp_2_2 = in(x+1, y+1, 0);
      signed int downCast_38_pp_2_1 = in(x+1, y+0, 0);
      signed int downCast_38_pp_2_0 = in(x+1, y+-1, 0);
      signed int downCast_38_pp_1_2 = in(x+0, y+1, 0);
      signed int downCast_38_pp_1_1 = in(x+0, y+0, 0);
      signed int downCast_38_pp_1_0 = in(x+0, y+-1, 0);
      signed int downCast_38_pp_0_2 = in(x+-1, y+1, 0);
      signed int downCast_38_pp_0_1 = in(x+-1, y+0, 0);
      signed int downCast_38_pp_0_0 = in(x+-1, y+-1, 0);
      const float c_1_0 = 1;
      const float c_32767_0 = 32767;
      const float c_16_0 = 16;
      const float c_15_0 = 15;
      
      signed int in1_29_0 = downCast_38_pp_2_0;
      signed int in1y_22_pack_5 = in1_29_0;
      signed int in1_31_0 = downCast_38_pp_1_2;
      signed int in1_26_0 = downCast_38_pp_0_1;
      signed int in1_27_0 = downCast_38_pp_0_0;
      signed int in1y_22_pack_3 = in1_27_0;
      signed int Resp_22_0 = c_32767_0;
      signed int Wxx_24_pack_1 = Resp_22_0;
      signed int Resp_31_pack_1 = Resp_22_0;
      signed int Wyy_19_pack_1 = Resp_22_0;
      signed int Resp_23_0 = -Resp_22_0;
      signed int Wxy_15_pack_1 = Resp_23_0;
      signed int Resp_30_pack_1 = Resp_23_0;
      signed int in1x_33_0 = -in1_27_0;
      signed int Wxx_11_0 = c_16_0;
      signed int in1x_12_0 = c_1_0;
      signed int in1x_31_0 = in1_26_0 << in1x_12_0;
      signed int in1_32_0 = downCast_38_pp_1_0;
      signed int Wxy_16_pack_1 = Resp_22_0;
      signed int TrSq_9_0 = c_15_0;
      signed int in1x_36_pack_2 = in1x_33_0;
      signed int in1_28_0 = downCast_38_pp_2_2;
      signed int in1x_38_pack_1 = Resp_22_0;
      signed int in1x_37_pack_1 = Resp_23_0;
      signed int in1_30_0 = downCast_38_pp_2_1;
      signed int in1x_35_0 = in1_30_0 << in1x_12_0;
      signed int in1x_36_pack_4 = in1x_35_0;
      signed int in1x_36_pack_5 = in1_29_0;
      signed int in1y_23_pack_1 = Resp_23_0;
      signed int in1x_32_0 = -in1x_31_0;
      signed int in1x_36_pack_1 = in1x_32_0;
      signed int in1y_21_0 = in1_32_0 << in1x_12_0;
      signed int in1y_22_pack_4 = in1y_21_0;
      signed int in1x_36_pack_3 = in1_28_0;
      signed int in1_25_0 = downCast_38_pp_0_2;
      signed int in1y_19_0 = in1_31_0 << in1x_12_0;
      signed int in1y_24_pack_1 = Resp_22_0;
      signed int in1x_30_0 = -in1_25_0;
      signed int in1x_36_pack_0 = in1x_30_0;
      signed int in1x_36_0 = in1x_36_pack_5 + in1x_36_pack_4 + in1x_36_pack_3 + in1x_36_pack_2 + in1x_36_pack_1 + in1x_36_pack_0;

      signed int in1x_37_pack_0 = in1x_36_0;
      signed int in1y_22_pack_0 = in1x_30_0;
      signed int in1x_34_0 = -in1_28_0;
      signed int in1y_22_pack_2 = in1x_34_0;
      signed int Wxx_23_pack_1 = Resp_23_0;
      signed int Wyy_18_pack_1 = Resp_23_0;
      // max in1x_37_0 <= (in1x_37_pack_1 , in1x_37_pack_0)
      signed int in1x_37_0_cotmp_1 = (in1x_37_pack_1 > in1x_37_pack_0) ? in1x_37_pack_1 : in1x_37_pack_0;
      signed int in1x_37_0 = in1x_37_0_cotmp_1;

      signed int in1x_38_pack_0 = in1x_37_0;
      // min in1x_38_0 <= (in1x_38_pack_1 , in1x_38_pack_0)
      signed int in1x_38_0_cotmp_1 = (in1x_38_pack_1 < in1x_38_pack_0) ? in1x_38_pack_1 : in1x_38_pack_0;
      signed int in1x_38_0 = in1x_38_0_cotmp_1;

      signed int sobel_3_0 = in1x_38_0;
      signed int Wxx_20_0 = sobel_3_0;
      signed int Wxx_21_0 = Wxx_20_0 * Wxx_20_0;
      signed int Wxx_22_0 = Wxx_21_0 >> Wxx_11_0;
      signed int Wxx_23_pack_0 = Wxx_22_0;
      // max Wxx_23_0 <= (Wxx_23_pack_1 , Wxx_23_pack_0)
      signed int Wxx_23_0_cotmp_1 = (Wxx_23_pack_1 > Wxx_23_pack_0) ? Wxx_23_pack_1 : Wxx_23_pack_0;
      signed int Wxx_23_0 = Wxx_23_0_cotmp_1;

      signed int Wxx_24_pack_0 = Wxx_23_0;
      // min Wxx_24_0 <= (Wxx_24_pack_1 , Wxx_24_pack_0)
      signed int Wxx_24_0_cotmp_1 = (Wxx_24_pack_1 < Wxx_24_pack_0) ? Wxx_24_pack_1 : Wxx_24_pack_0;
      signed int Wxx_24_0 = Wxx_24_0_cotmp_1;

      signed int in1y_20_0 = -in1y_19_0;
      signed int in1y_22_pack_1 = in1y_20_0;
      signed int in1y_22_0 = in1y_22_pack_5 + in1y_22_pack_4 + in1y_22_pack_3 + in1y_22_pack_2 + in1y_22_pack_1 + in1y_22_pack_0;
      signed int in1y_23_pack_0 = in1y_22_0;
      // max in1y_23_0 <= (in1y_23_pack_1 , in1y_23_pack_0)
      signed int in1y_23_0_cotmp_1 = (in1y_23_pack_1 > in1y_23_pack_0) ? in1y_23_pack_1 : in1y_23_pack_0;
      signed int in1y_23_0 = in1y_23_0_cotmp_1;

      signed int in1y_24_pack_0 = in1y_23_0;
      // min in1y_24_0 <= (in1y_24_pack_1 , in1y_24_pack_0)
      signed int in1y_24_0_cotmp_1 = (in1y_24_pack_1 < in1y_24_pack_0) ? in1y_24_pack_1 : in1y_24_pack_0;
      signed int in1y_24_0 = in1y_24_0_cotmp_1;

      signed int sobel_3_1 = in1y_24_0;
      signed int Wyy_15_0 = sobel_3_1;
      signed int Wxy_13_0 = Wxx_20_0 * Wyy_15_0;
      signed int Wyy_16_0 = Wyy_15_0 * Wyy_15_0;
      signed int Wxy_14_0 = Wxy_13_0 >> Wxx_11_0;
      signed int Wxy_15_pack_0 = Wxy_14_0;
      // max Wxy_15_0 <= (Wxy_15_pack_1 , Wxy_15_pack_0)
      signed int Wxy_15_0_cotmp_1 = (Wxy_15_pack_1 > Wxy_15_pack_0) ? Wxy_15_pack_1 : Wxy_15_pack_0;
      signed int Wxy_15_0 = Wxy_15_0_cotmp_1;

      signed int Wxy_16_pack_0 = Wxy_15_0;
      // min Wxy_16_0 <= (Wxy_16_pack_1 , Wxy_16_pack_0)
      signed int Wxy_16_0_cotmp_1 = (Wxy_16_pack_1 < Wxy_16_pack_0) ? Wxy_16_pack_1 : Wxy_16_pack_0;
      signed int Wxy_16_0 = Wxy_16_0_cotmp_1;

      signed int Det_18_0 = Wxy_16_0 * Wxy_16_0;
      signed int Det_19_0 = Det_18_0 >> in1x_12_0;
      signed int Wyy_17_0 = Wyy_16_0 >> Wxx_11_0;
      signed int Wyy_18_pack_0 = Wyy_17_0;
      // max Wyy_18_0 <= (Wyy_18_pack_1 , Wyy_18_pack_0)
      signed int Wyy_18_0_cotmp_1 = (Wyy_18_pack_1 > Wyy_18_pack_0) ? Wyy_18_pack_1 : Wyy_18_pack_0;
      signed int Wyy_18_0 = Wyy_18_0_cotmp_1;

      signed int Wyy_19_pack_0 = Wyy_18_0;
      // min Wyy_19_0 <= (Wyy_19_pack_1 , Wyy_19_pack_0)
      signed int Wyy_19_0_cotmp_1 = (Wyy_19_pack_1 < Wyy_19_pack_0) ? Wyy_19_pack_1 : Wyy_19_pack_0;
      signed int Wyy_19_0 = Wyy_19_0_cotmp_1;

      signed int Det_16_0 = Wxx_24_0 * Wyy_19_0;
      signed int Det_17_0 = Det_16_0 >> in1x_12_0;
      signed int TrSq_15_0 = Wxx_24_0 + Wyy_19_0;
      signed int TrSq_16_0 = TrSq_15_0 >> in1x_12_0;
      signed int TrSq_17_0 = TrSq_16_0 * TrSq_16_0;
      signed int TrSq_18_0 = TrSq_17_0 >> TrSq_9_0;
      signed int Resp1_7_0 = tap_K_0 * TrSq_18_0;
      signed int Det_20_0 = Det_17_0 - Det_19_0;
      signed int Resp1_8_0 = Det_20_0 - Resp1_7_0;
      signed int Resp_30_pack_0 = Resp1_8_0;
      // max Resp_30_0 <= (Resp_30_pack_1 , Resp_30_pack_0)
      signed int Resp_30_0_cotmp_1 = (Resp_30_pack_1 > Resp_30_pack_0) ? Resp_30_pack_1 : Resp_30_pack_0;
      signed int Resp_30_0 = Resp_30_0_cotmp_1;

      signed int Resp_31_pack_0 = Resp_30_0;
      // min Resp_31_0 <= (Resp_31_pack_1 , Resp_31_pack_0)
      signed int Resp_31_0_cotmp_1 = (Resp_31_pack_1 < Resp_31_pack_0) ? Resp_31_pack_1 : Resp_31_pack_0;
      signed int Resp_31_0 = Resp_31_0_cotmp_1;

      signed int Resp_32_0 = Resp_31_0;
      out(x,y,0) = Resp_32_0;
    }
  }
} // END Resp_5


void scheduledIRNode_28(const Image<int>& in, Image<int>& out
)
{
  for(int y = 0; y < in.height(); y++){
    for(int x = 0; x < in.width(); x++){
      unsigned int special0_pp_0_0_2 = in(x+0, y+0, 2);
      unsigned int special0_pp_0_0_1 = in(x+0, y+0, 1);
      unsigned int special0_pp_0_0_0 = in(x+0, y+0, 0);
      
      unsigned int cropSpecial0Node_10_0 = special0_pp_0_0_0;
      unsigned int cropSpecial0Node_10_1 = special0_pp_0_0_1;
      unsigned int cropSpecial0Node_10_2 = special0_pp_0_0_2;
      out(x,y,2) = cropSpecial0Node_10_2;
      out(x,y,1) = cropSpecial0Node_10_1;
      out(x,y,0) = cropSpecial0Node_10_0;
    }
  }
} // END scheduledIRNode_28


void downCast_15(const Image<int>& in, Image<int>& out
	, unsigned int tap_G1_0
	, unsigned int tap_G0_0
	, unsigned int tap_G2_0
	, unsigned int tap_G4_0
	, unsigned int tap_G3_0
	, unsigned int tap_R_0
)
{
  for(int y = 0; y < in.height(); y++){
    for(int x = 0; x < in.width(); x++){
      signed int downCast_20_pp_4_0 = in(x+2, y+0, 0);
      signed int downCast_20_pp_3_0 = in(x+1, y+0, 0);
      signed int downCast_20_pp_2_0 = in(x+0, y+0, 0);
      signed int downCast_20_pp_1_0 = in(x+-1, y+0, 0);
      signed int downCast_20_pp_0_0 = in(x+-2, y+0, 0);
      const float c_32767_0 = 32767;
      
      signed int convolve_1_5__68_0 = tap_G2_0;
      signed int convolve_1_5__72_0 = tap_G3_0;
      signed int upCast_37_0 = downCast_20_pp_2_0;
      signed int convolve_1_5__89_0 = upCast_37_0 * convolve_1_5__68_0;
      signed int Resp_20_0 = c_32767_0;
      signed int convolve_1_5__64_0 = tap_G1_0;
      signed int upCast_39_0 = downCast_20_pp_3_0;
      signed int convolve_1_5__70_0 = tap_G4_0;
      signed int convolve_1_5__93_pack_2 = convolve_1_5__89_0;
      signed int convolve_1_5__75_0 = tap_R_0;
      signed int Resp_21_0 = -Resp_20_0;
      signed int upCast_38_0 = downCast_20_pp_4_0;
      signed int convolve_1_5__90_0 = upCast_38_0 * convolve_1_5__70_0;
      signed int convolve_1_5__93_pack_4 = convolve_1_5__90_0;
      signed int upCast_36_0 = downCast_20_pp_1_0;
      signed int convolve_1_5__96_pack_1 = Resp_20_0;
      signed int convolve_1_5__95_pack_1 = Resp_21_0;
      signed int convolve_1_5__91_0 = upCast_39_0 * convolve_1_5__72_0;
      signed int convolve_1_5__93_pack_3 = convolve_1_5__91_0;
      signed int convolve_1_5__88_0 = upCast_36_0 * convolve_1_5__64_0;
      signed int convolve_1_5__93_pack_1 = convolve_1_5__88_0;
      signed int upCast_40_0 = downCast_20_pp_0_0;
      signed int convolve_1_5__66_0 = tap_G0_0;
      signed int convolve_1_5__92_0 = upCast_40_0 * convolve_1_5__66_0;
      signed int convolve_1_5__93_pack_0 = convolve_1_5__92_0;
      signed int convolve_1_5__93_0 = convolve_1_5__93_pack_4 + convolve_1_5__93_pack_3 + convolve_1_5__93_pack_2 + convolve_1_5__93_pack_1 + convolve_1_5__93_pack_0;
      signed int convolve_1_5__94_0 = convolve_1_5__93_0 >> convolve_1_5__75_0;
      signed int convolve_1_5__95_pack_0 = convolve_1_5__94_0;
      // max convolve_1_5__95_0 <= (convolve_1_5__95_pack_1 , convolve_1_5__95_pack_0)
      signed int convolve_1_5__95_0_cotmp_1 = (convolve_1_5__95_pack_1 > convolve_1_5__95_pack_0) ? convolve_1_5__95_pack_1 : convolve_1_5__95_pack_0;
      signed int convolve_1_5__95_0 = convolve_1_5__95_0_cotmp_1;

      signed int convolve_1_5__96_pack_0 = convolve_1_5__95_0;
      // min convolve_1_5__96_0 <= (convolve_1_5__96_pack_1 , convolve_1_5__96_pack_0)
      signed int convolve_1_5__96_0_cotmp_1 = (convolve_1_5__96_pack_1 < convolve_1_5__96_pack_0) ? convolve_1_5__96_pack_1 : convolve_1_5__96_pack_0;
      signed int convolve_1_5__96_0 = convolve_1_5__96_0_cotmp_1;

      signed int downCast_38_0 = convolve_1_5__96_0;
      out(x,y,0) = downCast_38_0;
    }
  }
} // END downCast_15


void NMS_10(const Image<int>& in, Image<int>& out
	, signed int tap_Peak_0
)
{
  for(int y = 0; y < in.height(); y++){
    for(int x = 0; x < in.width(); x++){
      signed int Resp_32_pp_2_2 = in(x+1, y+1, 0);
      signed int Resp_32_pp_2_1 = in(x+1, y+0, 0);
      signed int Resp_32_pp_2_0 = in(x+1, y+-1, 0);
      signed int Resp_32_pp_1_2 = in(x+0, y+1, 0);
      signed int Resp_32_pp_1_1 = in(x+0, y+0, 0);
      signed int Resp_32_pp_1_0 = in(x+0, y+-1, 0);
      signed int Resp_32_pp_0_2 = in(x+-1, y+1, 0);
      signed int Resp_32_pp_0_1 = in(x+-1, y+0, 0);
      signed int Resp_32_pp_0_0 = in(x+-1, y+-1, 0);
      const float c_0_0 = 0;
      const float c_255_0 = 255;
      
      bool PE_4_0 = Resp_32_pp_1_1 > Resp_32_pp_2_1;
      signed int NMS_5_0 = c_255_0;
      signed int P_7_0 = Resp_32_pp_1_1;
      bool P_8_0 = P_7_0 > tap_Peak_0;
      bool PS_4_0 = Resp_32_pp_1_1 >= Resp_32_pp_1_0;
      bool PW_4_0 = Resp_32_pp_1_1 >= Resp_32_pp_0_1;
      bool Pk_13_0 = P_8_0 & PW_4_0;
      bool Pk_14_0 = Pk_13_0 & PE_4_0;
      bool Pk_15_0 = Pk_14_0 & PS_4_0;
      bool PN_4_0 = Resp_32_pp_1_1 > Resp_32_pp_1_2;
      bool Pk_16_0 = Pk_15_0 & PN_4_0;
      signed int Wxx_25_0 = c_0_0;
      signed int NMS_10_0 = Pk_16_0 ? NMS_5_0 : Wxx_25_0;
      unsigned int NMS_11_0 = NMS_10_0;
      out(x,y,0) = NMS_11_0;
    }
  }
} // END NMS_10


void downCast_13(const Image<int>& in, Image<int>& out
	, unsigned int tap_G1_0
	, unsigned int tap_G0_0
	, unsigned int tap_G2_0
	, unsigned int tap_G4_0
	, unsigned int tap_G3_0
	, unsigned int tap_R_0
)
{
  for(int y = 0; y < in.height(); y++){
    for(int x = 0; x < in.width(); x++){
      unsigned int lambda_arris_v3lua_line43_51_pp_0_4 = in(x+0, y+2, 0);
      unsigned int lambda_arris_v3lua_line43_51_pp_0_3 = in(x+0, y+1, 0);
      unsigned int lambda_arris_v3lua_line43_51_pp_0_2 = in(x+0, y+0, 0);
      unsigned int lambda_arris_v3lua_line43_51_pp_0_1 = in(x+0, y+-1, 0);
      unsigned int lambda_arris_v3lua_line43_51_pp_0_0 = in(x+0, y+-2, 0);
      const float c_32767_0 = 32767;
      
      signed int convolve_1_5__35_0 = tap_G2_0;
      signed int convolve_1_5__37_0 = tap_G3_0;
      signed int upCast_22_0 = lambda_arris_v3lua_line43_51_pp_0_2;
      signed int convolve_1_5__56_0 = upCast_22_0 * convolve_1_5__35_0;
      signed int Resp_18_0 = c_32767_0;
      signed int convolve_1_5__31_0 = tap_G1_0;
      signed int upCast_24_0 = lambda_arris_v3lua_line43_51_pp_0_1;
      signed int convolve_1_5__39_0 = tap_G4_0;
      signed int convolve_1_5__60_pack_2 = convolve_1_5__56_0;
      signed int convolve_1_5__42_0 = tap_R_0;
      signed int Resp_19_0 = -Resp_18_0;
      signed int upCast_23_0 = lambda_arris_v3lua_line43_51_pp_0_0;
      signed int convolve_1_5__57_0 = upCast_23_0 * convolve_1_5__39_0;
      signed int convolve_1_5__60_pack_4 = convolve_1_5__57_0;
      signed int upCast_21_0 = lambda_arris_v3lua_line43_51_pp_0_3;
      signed int convolve_1_5__63_pack_1 = Resp_18_0;
      signed int convolve_1_5__62_pack_1 = Resp_19_0;
      signed int convolve_1_5__58_0 = upCast_24_0 * convolve_1_5__37_0;
      signed int convolve_1_5__60_pack_3 = convolve_1_5__58_0;
      signed int convolve_1_5__55_0 = upCast_21_0 * convolve_1_5__31_0;
      signed int convolve_1_5__60_pack_1 = convolve_1_5__55_0;
      signed int upCast_25_0 = lambda_arris_v3lua_line43_51_pp_0_4;
      signed int convolve_1_5__33_0 = tap_G0_0;
      signed int convolve_1_5__59_0 = upCast_25_0 * convolve_1_5__33_0;
      signed int convolve_1_5__60_pack_0 = convolve_1_5__59_0;
      signed int convolve_1_5__60_0 = convolve_1_5__60_pack_4 + convolve_1_5__60_pack_3 + convolve_1_5__60_pack_2 + convolve_1_5__60_pack_1 + convolve_1_5__60_pack_0;
      signed int convolve_1_5__61_0 = convolve_1_5__60_0 >> convolve_1_5__42_0;
      signed int convolve_1_5__62_pack_0 = convolve_1_5__61_0;
      // max convolve_1_5__62_0 <= (convolve_1_5__62_pack_1 , convolve_1_5__62_pack_0)
      signed int convolve_1_5__62_0_cotmp_1 = (convolve_1_5__62_pack_1 > convolve_1_5__62_pack_0) ? convolve_1_5__62_pack_1 : convolve_1_5__62_pack_0;
      signed int convolve_1_5__62_0 = convolve_1_5__62_0_cotmp_1;

      signed int convolve_1_5__63_pack_0 = convolve_1_5__62_0;
      // min convolve_1_5__63_0 <= (convolve_1_5__63_pack_1 , convolve_1_5__63_pack_0)
      signed int convolve_1_5__63_0_cotmp_1 = (convolve_1_5__63_pack_1 < convolve_1_5__63_pack_0) ? convolve_1_5__63_pack_1 : convolve_1_5__63_pack_0;
      signed int convolve_1_5__63_0 = convolve_1_5__63_0_cotmp_1;

      signed int downCast_20_0 = convolve_1_5__63_0;
      out(x,y,0) = downCast_20_0;
    }
  }
} // END downCast_13
