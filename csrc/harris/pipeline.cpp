#include <stdio.h>
#include <stdlib.h>
#include "image.h"
void downCast_13(const Image<int>& in, Image<int>& out
	, signed int tap_G1_0
	, signed int tap_G0_0
	, signed int tap_G2_0
	, signed int tap_G4_0
	, signed int tap_G3_0
	, unsigned int tap_R_0
)
{
  for(int y = 0; y < in.height(); y++){
    for(int x = 0; x < in.width(); x++){
      unsigned int convertToIllum_55_pp_0_4 = in(x+0, y+2, 0);
      unsigned int convertToIllum_55_pp_0_3 = in(x+0, y+1, 0);
      unsigned int convertToIllum_55_pp_0_2 = in(x+0, y+0, 0);
      unsigned int convertToIllum_55_pp_0_1 = in(x+0, y+-1, 0);
      unsigned int convertToIllum_55_pp_0_0 = in(x+0, y+-2, 0);
      const float c_0_0 = 0;
      const float c_255_0 = 255;
      
      signed int upCast_25_0 = convertToIllum_55_pp_0_4;
      signed int convolve_1_5__58_0 = upCast_25_0 * tap_G0_0;
      signed int upCast_23_0 = convertToIllum_55_pp_0_0;
      signed int convolve_1_5__56_0 = upCast_23_0 * tap_G4_0;
      signed int convolve_1_5__59_pack_4 = convolve_1_5__56_0;
      signed int Wxx_13_0 = c_0_0;
      signed int convolve_1_5__40_0 = c_255_0;
      signed int upCast_24_0 = convertToIllum_55_pp_0_1;
      signed int convolve_1_5__63_pack_1 = convolve_1_5__40_0;
      signed int convolve_1_5__59_pack_0 = convolve_1_5__58_0;
      signed int convolve_1_5__37_0 = tap_R_0;
      signed int convolve_1_5__62_pack_1 = Wxx_13_0;
      signed int upCast_22_0 = convertToIllum_55_pp_0_2;
      signed int convolve_1_5__55_0 = upCast_22_0 * tap_G2_0;
      signed int convolve_1_5__59_pack_2 = convolve_1_5__55_0;
      signed int convolve_1_5__57_0 = upCast_24_0 * tap_G3_0;
      signed int convolve_1_5__59_pack_3 = convolve_1_5__57_0;
      signed int upCast_21_0 = convertToIllum_55_pp_0_3;
      signed int convolve_1_5__54_0 = upCast_21_0 * tap_G1_0;
      signed int convolve_1_5__59_pack_1 = convolve_1_5__54_0;
      signed int convolve_1_5__59_0 = convolve_1_5__59_pack_4 + convolve_1_5__59_pack_3 + convolve_1_5__59_pack_2 + convolve_1_5__59_pack_1 + convolve_1_5__59_pack_0;
      signed int convolve_1_5__60_0 = convolve_1_5__59_0;
      signed int convolve_1_5__61_0 = convolve_1_5__60_0 >> convolve_1_5__37_0;
      signed int convolve_1_5__62_pack_0 = convolve_1_5__61_0;
      // max convolve_1_5__62_0 <= (convolve_1_5__62_pack_1 , convolve_1_5__62_pack_0)
      signed int convolve_1_5__62_0_cotmp_1 = (convolve_1_5__62_pack_1 > convolve_1_5__62_pack_0) ? convolve_1_5__62_pack_1 : convolve_1_5__62_pack_0;
      signed int convolve_1_5__62_0 = convolve_1_5__62_0_cotmp_1;

      signed int convolve_1_5__63_pack_0 = convolve_1_5__62_0;
      // min convolve_1_5__63_0 <= (convolve_1_5__63_pack_1 , convolve_1_5__63_pack_0)
      signed int convolve_1_5__63_0_cotmp_1 = (convolve_1_5__63_pack_1 < convolve_1_5__63_pack_0) ? convolve_1_5__63_pack_1 : convolve_1_5__63_pack_0;
      signed int convolve_1_5__63_0 = convolve_1_5__63_0_cotmp_1;

      signed int convolve_1_5__64_0 = convolve_1_5__63_0;
      unsigned int downCast_20_0 = convolve_1_5__64_0;
      out(x,y,0) = downCast_20_0;
    }
  }
} // END downCast_13


void Resp_5(const Image<int>& in, Image<int>& out
	, signed int tap_K_0
)
{
  for(int y = 0; y < in.height(); y++){
    for(int x = 0; x < in.width(); x++){
      unsigned int downCast_38_pp_2_2 = in(x+1, y+1, 0);
      unsigned int downCast_38_pp_2_1 = in(x+1, y+0, 0);
      unsigned int downCast_38_pp_2_0 = in(x+1, y+-1, 0);
      unsigned int downCast_38_pp_1_2 = in(x+0, y+1, 0);
      unsigned int downCast_38_pp_1_1 = in(x+0, y+0, 0);
      unsigned int downCast_38_pp_1_0 = in(x+0, y+-1, 0);
      unsigned int downCast_38_pp_0_2 = in(x+-1, y+1, 0);
      unsigned int downCast_38_pp_0_1 = in(x+-1, y+0, 0);
      unsigned int downCast_38_pp_0_0 = in(x+-1, y+-1, 0);
      const float c_1_0 = 1;
      const float c_127_0 = 127;
      const float c_8_0 = 8;
      const float c_7_0 = 7;
      
      signed int in1_27_0 = downCast_38_pp_0_0;
      signed int TrSq_12_0 = c_7_0;
      signed int Resp_11_0 = c_127_0;
      signed int Wyy_26_pack_1 = Resp_11_0;
      signed int in1_30_0 = downCast_38_pp_2_1;
      signed int in1y_22_pack_3 = in1_27_0;
      signed int Resp_12_0 = -Resp_11_0;
      signed int in1x_51_pack_1 = Resp_12_0;
      signed int in1_28_0 = downCast_38_pp_2_2;
      signed int in1x_52_pack_1 = Resp_11_0;
      signed int Wyy_25_pack_1 = Resp_12_0;
      signed int in1y_23_pack_1 = Resp_12_0;
      signed int in1_25_0 = downCast_38_pp_0_2;
      signed int Resp_17_pack_1 = Resp_12_0;
      signed int in1x_42_0 = -in1_25_0;
      signed int in1x_47_0 = -in1_28_0;
      signed int in1y_22_pack_0 = in1x_42_0;
      signed int Wxy_22_pack_1 = Resp_12_0;
      signed int in1x_46_0 = -in1_27_0;
      signed int in1x_50_pack_2 = in1x_46_0;
      signed int in1x_50_pack_0 = in1x_42_0;
      signed int Wxx_18_0 = c_8_0;
      signed int Resp_18_pack_1 = Resp_11_0;
      signed int in1x_48_0 = in1_30_0;
      signed int in1_29_0 = downCast_38_pp_2_0;
      signed int in1y_22_pack_5 = in1_29_0;
      signed int in1x_50_pack_5 = in1_29_0;
      signed int Wxx_34_pack_1 = Resp_12_0;
      signed int in1_31_0 = downCast_38_pp_1_2;
      signed int Wxy_23_pack_1 = Resp_11_0;
      signed int in1x_53_0 = in1_31_0;
      signed int in1x_50_pack_3 = in1_28_0;
      signed int in1_26_0 = downCast_38_pp_0_1;
      signed int in1x_43_0 = in1_26_0;
      signed int in1y_24_pack_1 = Resp_11_0;
      signed int Wxx_35_pack_1 = Resp_11_0;
      signed int in1_32_0 = downCast_38_pp_1_0;
      signed int in1x_54_0 = in1_32_0;
      signed int in1y_22_pack_2 = in1x_47_0;
      signed int in1x_17_0 = c_1_0;
      signed int in1y_19_0 = in1x_53_0 << in1x_17_0;
      signed int in1y_21_0 = in1x_54_0 << in1x_17_0;
      signed int in1y_22_pack_4 = in1y_21_0;
      signed int in1x_49_0 = in1x_48_0 << in1x_17_0;
      signed int in1x_50_pack_4 = in1x_49_0;
      signed int in1x_44_0 = in1x_43_0 << in1x_17_0;
      signed int in1x_45_0 = -in1x_44_0;
      signed int in1x_50_pack_1 = in1x_45_0;
      signed int in1x_50_0 = in1x_50_pack_5 + in1x_50_pack_4 + in1x_50_pack_3 + in1x_50_pack_2 + in1x_50_pack_1 + in1x_50_pack_0;
      signed int in1x_51_pack_0 = in1x_50_0;
      // max in1x_51_0 <= (in1x_51_pack_1 , in1x_51_pack_0)
      signed int in1x_51_0_cotmp_1 = (in1x_51_pack_1 > in1x_51_pack_0) ? in1x_51_pack_1 : in1x_51_pack_0;
      signed int in1x_51_0 = in1x_51_0_cotmp_1;

      signed int in1x_52_pack_0 = in1x_51_0;
      // min in1x_52_0 <= (in1x_52_pack_1 , in1x_52_pack_0)
      signed int in1x_52_0_cotmp_1 = (in1x_52_pack_1 < in1x_52_pack_0) ? in1x_52_pack_1 : in1x_52_pack_0;
      signed int in1x_52_0 = in1x_52_0_cotmp_1;

      signed int sobel_3_0 = in1x_52_0;
      signed int Wxx_30_0 = sobel_3_0;
      signed int Wxx_31_0 = Wxx_30_0 * Wxx_30_0;
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

      signed int Wxx_32_0 = Wxx_31_0;
      signed int Wxx_33_0 = Wxx_32_0 >> Wxx_18_0;
      signed int Wxx_34_pack_0 = Wxx_33_0;
      // max Wxx_34_0 <= (Wxx_34_pack_1 , Wxx_34_pack_0)
      signed int Wxx_34_0_cotmp_1 = (Wxx_34_pack_1 > Wxx_34_pack_0) ? Wxx_34_pack_1 : Wxx_34_pack_0;
      signed int Wxx_34_0 = Wxx_34_0_cotmp_1;

      signed int Wxx_35_pack_0 = Wxx_34_0;
      // min Wxx_35_0 <= (Wxx_35_pack_1 , Wxx_35_pack_0)
      signed int Wxx_35_0_cotmp_1 = (Wxx_35_pack_1 < Wxx_35_pack_0) ? Wxx_35_pack_1 : Wxx_35_pack_0;
      signed int Wxx_35_0 = Wxx_35_0_cotmp_1;

      signed int Wxx_36_0 = Wxx_35_0;
      signed int sobel_3_1 = in1y_24_0;
      signed int Wyy_21_0 = sobel_3_1;
      signed int Wxy_19_0 = Wxx_30_0 * Wyy_21_0;
      signed int Wyy_22_0 = Wyy_21_0 * Wyy_21_0;
      signed int Wyy_23_0 = Wyy_22_0;
      signed int Wyy_24_0 = Wyy_23_0 >> Wxx_18_0;
      signed int Wyy_25_pack_0 = Wyy_24_0;
      // max Wyy_25_0 <= (Wyy_25_pack_1 , Wyy_25_pack_0)
      signed int Wyy_25_0_cotmp_1 = (Wyy_25_pack_1 > Wyy_25_pack_0) ? Wyy_25_pack_1 : Wyy_25_pack_0;
      signed int Wyy_25_0 = Wyy_25_0_cotmp_1;

      signed int Wyy_26_pack_0 = Wyy_25_0;
      // min Wyy_26_0 <= (Wyy_26_pack_1 , Wyy_26_pack_0)
      signed int Wyy_26_0_cotmp_1 = (Wyy_26_pack_1 < Wyy_26_pack_0) ? Wyy_26_pack_1 : Wyy_26_pack_0;
      signed int Wyy_26_0 = Wyy_26_0_cotmp_1;

      signed int Wyy_27_0 = Wyy_26_0;
      signed int TrSq_21_0 = Wxx_36_0 + Wyy_27_0;
      signed int TrSq_22_0 = TrSq_21_0;
      signed int TrSq_23_0 = TrSq_22_0 >> in1x_17_0;
      signed int TrSq_24_0 = TrSq_23_0 * TrSq_23_0;
      signed int TrSq_25_0 = TrSq_24_0 >> TrSq_12_0;
      signed int TrSq_26_0 = TrSq_25_0;
      signed int Resp1_7_0 = tap_K_0 * TrSq_26_0;
      signed int Det_25_0 = Wxx_36_0 * Wyy_27_0;
      signed int Det_26_0 = Det_25_0;
      signed int Det_27_0 = Det_26_0 >> in1x_17_0;
      signed int Wxy_20_0 = Wxy_19_0;
      signed int Wxy_21_0 = Wxy_20_0 >> Wxx_18_0;
      signed int Wxy_22_pack_0 = Wxy_21_0;
      // max Wxy_22_0 <= (Wxy_22_pack_1 , Wxy_22_pack_0)
      signed int Wxy_22_0_cotmp_1 = (Wxy_22_pack_1 > Wxy_22_pack_0) ? Wxy_22_pack_1 : Wxy_22_pack_0;
      signed int Wxy_22_0 = Wxy_22_0_cotmp_1;

      signed int Wxy_23_pack_0 = Wxy_22_0;
      // min Wxy_23_0 <= (Wxy_23_pack_1 , Wxy_23_pack_0)
      signed int Wxy_23_0_cotmp_1 = (Wxy_23_pack_1 < Wxy_23_pack_0) ? Wxy_23_pack_1 : Wxy_23_pack_0;
      signed int Wxy_23_0 = Wxy_23_0_cotmp_1;

      signed int Wxy_24_0 = Wxy_23_0;
      signed int Det_28_0 = Wxy_24_0 * Wxy_24_0;
      signed int Det_29_0 = Det_28_0;
      signed int Det_30_0 = Det_29_0 >> in1x_17_0;
      signed int Det_31_0 = Det_27_0 - Det_30_0;
      signed int Det_32_0 = Det_31_0;
      signed int Resp1_8_0 = Det_32_0 - Resp1_7_0;
      signed int Resp_17_pack_0 = Resp1_8_0;
      // max Resp_17_0 <= (Resp_17_pack_1 , Resp_17_pack_0)
      signed int Resp_17_0_cotmp_1 = (Resp_17_pack_1 > Resp_17_pack_0) ? Resp_17_pack_1 : Resp_17_pack_0;
      signed int Resp_17_0 = Resp_17_0_cotmp_1;

      signed int Resp_18_pack_0 = Resp_17_0;
      // min Resp_18_0 <= (Resp_18_pack_1 , Resp_18_pack_0)
      signed int Resp_18_0_cotmp_1 = (Resp_18_pack_1 < Resp_18_pack_0) ? Resp_18_pack_1 : Resp_18_pack_0;
      signed int Resp_18_0 = Resp_18_0_cotmp_1;

      out(x,y,0) = Resp_18_0;
    }
  }
} // END Resp_5


void downCast_15(const Image<int>& in, Image<int>& out
	, signed int tap_G1_0
	, signed int tap_G0_0
	, signed int tap_G2_0
	, signed int tap_G4_0
	, signed int tap_G3_0
	, unsigned int tap_R_0
)
{
  for(int y = 0; y < in.height(); y++){
    for(int x = 0; x < in.width(); x++){
      unsigned int downCast_20_pp_4_0 = in(x+2, y+0, 0);
      unsigned int downCast_20_pp_3_0 = in(x+1, y+0, 0);
      unsigned int downCast_20_pp_2_0 = in(x+0, y+0, 0);
      unsigned int downCast_20_pp_1_0 = in(x+-1, y+0, 0);
      unsigned int downCast_20_pp_0_0 = in(x+-2, y+0, 0);
      const float c_0_0 = 0;
      const float c_255_0 = 255;
      
      signed int upCast_40_0 = downCast_20_pp_0_0;
      signed int convolve_1_5__93_0 = upCast_40_0 * tap_G0_0;
      signed int upCast_38_0 = downCast_20_pp_4_0;
      signed int convolve_1_5__91_0 = upCast_38_0 * tap_G4_0;
      signed int convolve_1_5__94_pack_4 = convolve_1_5__91_0;
      signed int Wxx_14_0 = c_0_0;
      signed int convolve_1_5__75_0 = c_255_0;
      signed int upCast_39_0 = downCast_20_pp_3_0;
      signed int convolve_1_5__98_pack_1 = convolve_1_5__75_0;
      signed int convolve_1_5__94_pack_0 = convolve_1_5__93_0;
      signed int convolve_1_5__72_0 = tap_R_0;
      signed int convolve_1_5__97_pack_1 = Wxx_14_0;
      signed int upCast_37_0 = downCast_20_pp_2_0;
      signed int convolve_1_5__90_0 = upCast_37_0 * tap_G2_0;
      signed int convolve_1_5__94_pack_2 = convolve_1_5__90_0;
      signed int convolve_1_5__92_0 = upCast_39_0 * tap_G3_0;
      signed int convolve_1_5__94_pack_3 = convolve_1_5__92_0;
      signed int upCast_36_0 = downCast_20_pp_1_0;
      signed int convolve_1_5__89_0 = upCast_36_0 * tap_G1_0;
      signed int convolve_1_5__94_pack_1 = convolve_1_5__89_0;
      signed int convolve_1_5__94_0 = convolve_1_5__94_pack_4 + convolve_1_5__94_pack_3 + convolve_1_5__94_pack_2 + convolve_1_5__94_pack_1 + convolve_1_5__94_pack_0;
      signed int convolve_1_5__95_0 = convolve_1_5__94_0;
      signed int convolve_1_5__96_0 = convolve_1_5__95_0 >> convolve_1_5__72_0;
      signed int convolve_1_5__97_pack_0 = convolve_1_5__96_0;
      // max convolve_1_5__97_0 <= (convolve_1_5__97_pack_1 , convolve_1_5__97_pack_0)
      signed int convolve_1_5__97_0_cotmp_1 = (convolve_1_5__97_pack_1 > convolve_1_5__97_pack_0) ? convolve_1_5__97_pack_1 : convolve_1_5__97_pack_0;
      signed int convolve_1_5__97_0 = convolve_1_5__97_0_cotmp_1;

      signed int convolve_1_5__98_pack_0 = convolve_1_5__97_0;
      // min convolve_1_5__98_0 <= (convolve_1_5__98_pack_1 , convolve_1_5__98_pack_0)
      signed int convolve_1_5__98_0_cotmp_1 = (convolve_1_5__98_pack_1 < convolve_1_5__98_pack_0) ? convolve_1_5__98_pack_1 : convolve_1_5__98_pack_0;
      signed int convolve_1_5__98_0 = convolve_1_5__98_0_cotmp_1;

      signed int convolve_1_5__99_0 = convolve_1_5__98_0;
      unsigned int downCast_38_0 = convolve_1_5__99_0;
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
      signed int Resp_18_pp_2_2 = in(x+1, y+1, 0);
      signed int Resp_18_pp_2_1 = in(x+1, y+0, 0);
      signed int Resp_18_pp_2_0 = in(x+1, y+-1, 0);
      signed int Resp_18_pp_1_2 = in(x+0, y+1, 0);
      signed int Resp_18_pp_1_1 = in(x+0, y+0, 0);
      signed int Resp_18_pp_1_0 = in(x+0, y+-1, 0);
      signed int Resp_18_pp_0_2 = in(x+-1, y+1, 0);
      signed int Resp_18_pp_0_1 = in(x+-1, y+0, 0);
      signed int Resp_18_pp_0_0 = in(x+-1, y+-1, 0);
      const float c_0_0 = 0;
      const float c_255_0 = 255;
      
      signed int convolve_1_5__100_0 = c_255_0;
      bool P_4_0 = Resp_18_pp_1_1 > tap_Peak_0;
      bool PN_4_0 = Resp_18_pp_1_1 > Resp_18_pp_1_2;
      bool PW_4_0 = Resp_18_pp_1_1 >= Resp_18_pp_0_1;
      bool PE_4_0 = Resp_18_pp_1_1 > Resp_18_pp_2_1;
      bool PS_4_0 = Resp_18_pp_1_1 >= Resp_18_pp_1_0;
      bool Pk_13_0 = P_4_0 & PW_4_0;
      bool Pk_14_0 = Pk_13_0 & PE_4_0;
      bool Pk_15_0 = Pk_14_0 & PS_4_0;
      signed int Wxx_37_0 = c_0_0;
      bool Pk_16_0 = Pk_15_0 & PN_4_0;
      signed int NMS_8_0 = Pk_16_0 ? convolve_1_5__100_0 : Wxx_37_0;
      unsigned int NMS_9_0 = NMS_8_0;
      out(x,y,0) = NMS_9_0;
    }
  }
} // END NMS_10


void convertToIllum_10(const Image<int>& in, Image<int>& out
	, unsigned int tap_Green_to_Lum_0
	, unsigned int tap_Blue_to_Lum_0
	, unsigned int tap_Red_to_Lum_0
	, unsigned int tap_R_0
)
{
  for(int y = 0; y < in.height(); y++){
    for(int x = 0; x < in.width(); x++){
      unsigned int cropSpecial0Node_7_pp_0_0_2 = in(x+0, y+0, 2);
      unsigned int cropSpecial0Node_7_pp_0_0_1 = in(x+0, y+0, 1);
      unsigned int cropSpecial0Node_7_pp_0_0_0 = in(x+0, y+0, 0);
      const float c_0_0 = 0;
      const float c_255_0 = 255;
      
      unsigned int convertToIllum_49_0 = cropSpecial0Node_7_pp_0_0_0;
      unsigned int convertToIllum_50_0 = convertToIllum_49_0;
      unsigned int convertToIllum_51_0 = convertToIllum_50_0 * tap_Red_to_Lum_0;
      signed int Wxx_12_0 = c_0_0;
      unsigned int convertToIllum_43_0 = cropSpecial0Node_7_pp_0_0_1;
      unsigned int convertToIllum_44_0 = convertToIllum_43_0;
      unsigned int convertToIllum_45_0 = convertToIllum_44_0 * tap_Green_to_Lum_0;
      unsigned int convertToIllum_52_pack_1 = convertToIllum_45_0;
      signed int convolve_1_5__29_0 = c_255_0;
      unsigned int convertToIllum_55_pack_1 = convolve_1_5__29_0;
      unsigned int convertToIllum_52_pack_0 = convertToIllum_51_0;
      unsigned int convertToIllum_46_0 = cropSpecial0Node_7_pp_0_0_2;
      unsigned int convertToIllum_47_0 = convertToIllum_46_0;
      unsigned int convertToIllum_48_0 = convertToIllum_47_0 * tap_Blue_to_Lum_0;
      unsigned int convertToIllum_52_pack_2 = convertToIllum_48_0;
      unsigned int convertToIllum_52_0 = convertToIllum_52_pack_2 + convertToIllum_52_pack_1 + convertToIllum_52_pack_0;
      unsigned int convertToIllum_53_0 = convertToIllum_52_0 >> tap_R_0;
      unsigned int convertToIllum_54_pack_0 = convertToIllum_53_0;
      unsigned int convertToIllum_54_pack_1 = Wxx_12_0;
      // max convertToIllum_54_0 <= (convertToIllum_54_pack_1 , convertToIllum_54_pack_0)
      unsigned int convertToIllum_54_0_cotmp_1 = (convertToIllum_54_pack_1 > convertToIllum_54_pack_0) ? convertToIllum_54_pack_1 : convertToIllum_54_pack_0;
      unsigned int convertToIllum_54_0 = convertToIllum_54_0_cotmp_1;

      unsigned int convertToIllum_55_pack_0 = convertToIllum_54_0;
      // min convertToIllum_55_0 <= (convertToIllum_55_pack_1 , convertToIllum_55_pack_0)
      unsigned int convertToIllum_55_0_cotmp_1 = (convertToIllum_55_pack_1 < convertToIllum_55_pack_0) ? convertToIllum_55_pack_1 : convertToIllum_55_pack_0;
      unsigned int convertToIllum_55_0 = convertToIllum_55_0_cotmp_1;

      out(x,y,0) = convertToIllum_55_0;
    }
  }
} // END convertToIllum_10


void scheduledIRNode_19(const Image<int>& in, Image<int>& out
)
{
  for(int y = 0; y < in.height(); y++){
    for(int x = 0; x < in.width(); x++){
      unsigned int special0_pp_0_0_2 = in(x+0, y+0, 2);
      unsigned int special0_pp_0_0_1 = in(x+0, y+0, 1);
      unsigned int special0_pp_0_0_0 = in(x+0, y+0, 0);
      
      unsigned int cropSpecial0Node_7_0 = special0_pp_0_0_0;
      unsigned int cropSpecial0Node_7_1 = special0_pp_0_0_1;
      unsigned int cropSpecial0Node_7_2 = special0_pp_0_0_2;
      out(x,y,2) = cropSpecial0Node_7_2;
      out(x,y,1) = cropSpecial0Node_7_1;
      out(x,y,0) = cropSpecial0Node_7_0;
    }
  }
} // END scheduledIRNode_19


int main(int argc, char* argv[])
{
  int width = 512;  // TODO change to match input image
  int height = 512;  // TODO change to match input image
  int channels = 3;  // TODO change to match input image
  Image<int> special0(width, height, channels, 0);
  special0.load(argv[1]);
  
  // Set tap values
  const unsigned int tap_Green_to_Lum_0 = 27;    // TODO change in value
  const unsigned int tap_Blue_to_Lum_0 = 91;     // TODO change in value
  const unsigned int tap_Red_to_Lum_0 = 9;      // TODO change in value
  const unsigned int tap_G0_0 = 7;      // TODO change in value
  const unsigned int tap_G1_0 = 31;      // TODO change in value
  const unsigned int tap_G2_0 = 51;     // TODO change in value
  const unsigned int tap_G3_0 = 31;      // TODO change in value
  const unsigned int tap_G4_0 = 7;      // TODO change in value
  const unsigned int tap_R_0 = 7;        // TODO change in value
  const signed int tap_K_0 = 1;  // TODO change in value
  const signed int tap_Peak_0 = 4;     // TODO change in value
  
  // Construct the pipeline of kernels
  Image<int> cropSpecial0Node_7(width, height, 3, 0);
  scheduledIRNode_19(special0, cropSpecial0Node_7
  );
  
  Image<int> convertToIllum_55(width, height, 1, 0);
  convertToIllum_10(cropSpecial0Node_7, convertToIllum_55
  	, tap_Green_to_Lum_0
  	, tap_Blue_to_Lum_0
  	, tap_Red_to_Lum_0
  	, tap_R_0
  );
  
  Image<int> downCast_20(width, height, 1, 0);
  downCast_13(convertToIllum_55, downCast_20
  	, tap_G1_0
  	, tap_G0_0
  	, tap_G2_0
  	, tap_G4_0
  	, tap_G3_0
  	, tap_R_0
  );
  
  Image<int> downCast_38(width, height, 1, 0);
  downCast_15(downCast_20, downCast_38
  	, tap_G1_0
  	, tap_G0_0
  	, tap_G2_0
  	, tap_G4_0
  	, tap_G3_0
  	, tap_R_0
  );
  
  Image<int> Resp_18(width, height, 1, 0);
  Resp_5(downCast_38, Resp_18
  	, tap_K_0
  );
  
  Image<int> NMS_9(width, height, 1, 0);
  NMS_10(Resp_18, NMS_9
  	, tap_Peak_0
  );
  
  NMS_9.save("result.bmp");
  return(0);
}
