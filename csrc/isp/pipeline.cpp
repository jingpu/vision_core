#include <stdio.h>
#include <stdlib.h>
#include "image.h"
void lambda_isp_oldlua_line1282_33(const Image<int>& in, Image<int>& out
)
{
  for(int y = 0; y < in.height(); y++){
    for(int x = 0; x < in.width(); x++){
      unsigned int cropSpecial0Node_5_pp_0_0_2 = in(x+0, y+0, 2);
      unsigned int cropSpecial0Node_5_pp_0_0_1 = in(x+0, y+0, 1);
      unsigned int cropSpecial0Node_5_pp_0_0_0 = in(x+0, y+0, 0);
      const float c_0_0 = 0;
      const float c_1023_0 = 1023;
      const float c_719_0 = 719;
      const float c_2_0 = 2;
      const float c_1_0 = 1;
      const float c_3_0 = 3;
      const float c_4_0 = 4;
      const float c_344_0 = 344;
      const float c_34_0 = 34;
      const float c_n64_0 = -64;
      const float c_512_0 = 512;
      const float c_10_0 = 10;
      
      int centroid_pos_0 = x;
      int centroid_pos_1 = y;
      signed int clap_472_0 = c_1023_0;
      signed int lambda_isp_oldlua_line1329_1329_0 = c_0_0;
      signed int lambda_isp_oldlua_line502_64_0 = c_512_0;
      signed int lambda_isp_oldlua_line1329_1332_0 = c_0_0;
      signed int lambda_isp_oldlua_line1240_341_0 = c_1_0;
      signed int clap_480_pack_1 = clap_472_0;
      signed int offY_4163_0 = c_4_0;
      signed int lambda_isp_oldlua_line881_53_0 = c_n64_0;
      signed int offY_4166_0 = c_3_0;
      signed int lambda_isp_oldlua_line1329_1322_0 = c_0_0;
      signed int offY_4173_0 = c_344_0;
      signed int lambda_isp_oldlua_line1240_342_0 = c_2_0;
      bool offY_4167_0 = lambda_isp_oldlua_line1240_342_0 == offY_4166_0;
      bool offY_4169_0 = lambda_isp_oldlua_line1240_342_0 == lambda_isp_oldlua_line1240_342_0;
      signed int lambda_isp_oldlua_line881_64_0 = c_10_0;
      signed int lambda_isp_oldlua_line881_69_0 = lambda_isp_oldlua_line881_64_0 - lambda_isp_oldlua_line1240_341_0;
      signed int lambda_isp_oldlua_line881_65_0 = lambda_isp_oldlua_line881_64_0 - lambda_isp_oldlua_line1240_342_0;
      signed int lambda_isp_oldlua_line881_66_0 = lambda_isp_oldlua_line1240_341_0 << lambda_isp_oldlua_line881_65_0;
      signed int lambda_isp_oldlua_line881_67_0 = lambda_isp_oldlua_line881_66_0 >> lambda_isp_oldlua_line1240_341_0;
      signed int clap_471_0 = c_0_0;
      signed int clap_479_pack_1 = clap_471_0;
      signed int lambda_isp_oldlua_line881_95_pack_0 = clap_471_0;
      signed int lambda_isp_oldlua_line881_100_pack_1 = clap_472_0;
      bool offY_4164_0 = lambda_isp_oldlua_line1240_342_0 == offY_4163_0;
      signed int offY_4165_0 = offY_4164_0 ? lambda_isp_oldlua_line1240_341_0 : lambda_isp_oldlua_line1240_342_0;
      signed int offY_4168_0 = offY_4167_0 ? clap_471_0 : offY_4165_0;
      signed int offX_2256_0 = offY_4164_0 ? clap_471_0 : lambda_isp_oldlua_line1240_342_0;
      signed int offX_2257_0 = offY_4167_0 ? lambda_isp_oldlua_line1240_341_0 : offX_2256_0;
      signed int offX_2258_0 = offY_4169_0 ? lambda_isp_oldlua_line1240_341_0 : offX_2257_0;
      unsigned int lambda_isp_oldlua_line1261_6_0 = cropSpecial0Node_5_pp_0_0_0;
      signed int lambda_isp_oldlua_line1261_7_0 = lambda_isp_oldlua_line1261_6_0;
      bool offY_4171_0 = lambda_isp_oldlua_line1240_342_0 == lambda_isp_oldlua_line1240_341_0;
      signed int offX_2259_0 = offY_4171_0 ? clap_471_0 : offX_2258_0;
      bool offX_2261_0 = offX_2259_0 != lambda_isp_oldlua_line1240_342_0;
      signed int offX_2260_0 = c_34_0;
      signed int lambda_isp_oldlua_line881_94_pack_0 = clap_472_0;
      signed int lambda_isp_oldlua_line1329_1333_0 = centroid_pos_0 + lambda_isp_oldlua_line1329_1332_0;
      signed int offY_4170_0 = offY_4169_0 ? lambda_isp_oldlua_line1240_341_0 : offY_4168_0;
      signed int offY_4172_0 = offY_4171_0 ? clap_471_0 : offY_4170_0;
      bool offY_4174_0 = offY_4172_0 != lambda_isp_oldlua_line1240_342_0;
      signed int lambda_isp_oldlua_line1329_1325_0 = c_0_0;
      signed int lambda_isp_oldlua_line1329_1334_0 = lambda_isp_oldlua_line1329_1333_0 + lambda_isp_oldlua_line1329_1325_0;
      signed int grPix_3901_0 = lambda_isp_oldlua_line1329_1334_0 + offX_2259_0;
      signed int grPix_3902_0 = grPix_3901_0 & lambda_isp_oldlua_line1240_341_0;
      bool grPix_3903_0 = grPix_3902_0 != clap_471_0;
      bool grPix_3904_0 = !grPix_3903_0;
      signed int lambda_isp_oldlua_line1329_1327_0 = c_719_0;
      signed int lambda_isp_oldlua_line1329_1328_0 = lambda_isp_oldlua_line1329_1327_0 - centroid_pos_1;
      signed int lambda_isp_oldlua_line1329_1330_0 = lambda_isp_oldlua_line1329_1328_0 + lambda_isp_oldlua_line1329_1329_0;
      signed int lambda_isp_oldlua_line1329_1331_0 = lambda_isp_oldlua_line1329_1330_0 + lambda_isp_oldlua_line1329_1322_0;
      signed int grPix_3897_0 = lambda_isp_oldlua_line1329_1331_0 + offY_4172_0;
      signed int grPix_3898_0 = grPix_3897_0 & lambda_isp_oldlua_line1240_341_0;
      bool grPix_3899_0 = grPix_3898_0 != clap_471_0;
      bool gbPix_825_0 = grPix_3899_0 & grPix_3903_0;
      signed int gbPix_826_0 = gbPix_825_0 ? lambda_isp_oldlua_line1240_341_0 : clap_471_0;
      signed int lambda_isp_oldlua_line881_91_0 = gbPix_826_0 * lambda_isp_oldlua_line881_53_0;
      bool bPix_15_0 = grPix_3899_0 & grPix_3904_0;
      bool grPix_3900_0 = !grPix_3899_0;
      bool rPix_825_0 = grPix_3900_0 & grPix_3903_0;
      signed int rPix_826_0 = rPix_825_0 ? lambda_isp_oldlua_line1240_341_0 : clap_471_0;
      signed int lambda_isp_oldlua_line881_88_0 = rPix_826_0 * lambda_isp_oldlua_line881_53_0;
      signed int lambda_isp_oldlua_line881_92_pack_1 = lambda_isp_oldlua_line881_88_0;
      bool grPix_3905_0 = grPix_3900_0 & grPix_3904_0;
      signed int lambda_isp_oldlua_line502_72_0 = rPix_826_0 * lambda_isp_oldlua_line502_64_0;
      signed int lambda_isp_oldlua_line881_92_pack_3 = lambda_isp_oldlua_line881_91_0;
      signed int lambda_isp_oldlua_line502_77_0 = gbPix_826_0 * lambda_isp_oldlua_line502_64_0;
      signed int bPix_16_0 = bPix_15_0 ? lambda_isp_oldlua_line1240_341_0 : clap_471_0;
      signed int lambda_isp_oldlua_line881_90_0 = bPix_16_0 * lambda_isp_oldlua_line881_53_0;
      signed int lambda_isp_oldlua_line881_92_pack_2 = lambda_isp_oldlua_line881_90_0;
      signed int lambda_isp_oldlua_line502_75_0 = bPix_16_0 * lambda_isp_oldlua_line502_64_0;
      signed int grPix_3906_0 = grPix_3905_0 ? lambda_isp_oldlua_line1240_341_0 : clap_471_0;
      signed int lambda_isp_oldlua_line502_73_0 = grPix_3906_0 * lambda_isp_oldlua_line502_64_0;
      signed int lambda_isp_oldlua_line502_74_0 = lambda_isp_oldlua_line502_73_0 + lambda_isp_oldlua_line502_72_0;
      signed int lambda_isp_oldlua_line502_76_0 = lambda_isp_oldlua_line502_74_0 + lambda_isp_oldlua_line502_75_0;
      signed int lambda_isp_oldlua_line502_78_0 = lambda_isp_oldlua_line502_76_0 + lambda_isp_oldlua_line502_77_0;
      signed int lambda_isp_oldlua_line881_89_0 = grPix_3906_0 * lambda_isp_oldlua_line881_53_0;
      signed int lambda_isp_oldlua_line881_92_pack_0 = lambda_isp_oldlua_line881_89_0;
      signed int lambda_isp_oldlua_line881_92_0 = lambda_isp_oldlua_line881_92_pack_3 + lambda_isp_oldlua_line881_92_pack_2 + lambda_isp_oldlua_line881_92_pack_1 + lambda_isp_oldlua_line881_92_pack_0;
      signed int lambda_isp_oldlua_line881_93_0 = lambda_isp_oldlua_line1261_7_0 + lambda_isp_oldlua_line881_92_0;
      signed int lambda_isp_oldlua_line881_94_pack_1 = lambda_isp_oldlua_line881_93_0;
      // min lambda_isp_oldlua_line881_94_0 <= (lambda_isp_oldlua_line881_94_pack_1 , lambda_isp_oldlua_line881_94_pack_0)
      signed int lambda_isp_oldlua_line881_94_0_cotmp_1 = (lambda_isp_oldlua_line881_94_pack_1 < lambda_isp_oldlua_line881_94_pack_0) ? lambda_isp_oldlua_line881_94_pack_1 : lambda_isp_oldlua_line881_94_pack_0;
      signed int lambda_isp_oldlua_line881_94_0 = lambda_isp_oldlua_line881_94_0_cotmp_1;

      signed int lambda_isp_oldlua_line881_95_pack_1 = lambda_isp_oldlua_line881_94_0;
      // max lambda_isp_oldlua_line881_95_0 <= (lambda_isp_oldlua_line881_95_pack_1 , lambda_isp_oldlua_line881_95_pack_0)
      signed int lambda_isp_oldlua_line881_95_0_cotmp_1 = (lambda_isp_oldlua_line881_95_pack_1 > lambda_isp_oldlua_line881_95_pack_0) ? lambda_isp_oldlua_line881_95_pack_1 : lambda_isp_oldlua_line881_95_pack_0;
      signed int lambda_isp_oldlua_line881_95_0 = lambda_isp_oldlua_line881_95_0_cotmp_1;

      signed int lambda_isp_oldlua_line881_96_0 = lambda_isp_oldlua_line881_95_0 * lambda_isp_oldlua_line502_78_0;
      signed int lambda_isp_oldlua_line881_97_0 = lambda_isp_oldlua_line881_96_0 << clap_471_0;
      signed int lambda_isp_oldlua_line881_98_0 = lambda_isp_oldlua_line881_97_0 + lambda_isp_oldlua_line881_67_0;
      signed int lambda_isp_oldlua_line881_99_0 = lambda_isp_oldlua_line881_98_0 >> lambda_isp_oldlua_line881_69_0;
      signed int lambda_isp_oldlua_line881_100_pack_0 = lambda_isp_oldlua_line881_99_0;
      // min lambda_isp_oldlua_line881_100_0 <= (lambda_isp_oldlua_line881_100_pack_1 , lambda_isp_oldlua_line881_100_pack_0)
      signed int lambda_isp_oldlua_line881_100_0_cotmp_1 = (lambda_isp_oldlua_line881_100_pack_1 < lambda_isp_oldlua_line881_100_pack_0) ? lambda_isp_oldlua_line881_100_pack_1 : lambda_isp_oldlua_line881_100_pack_0;
      signed int lambda_isp_oldlua_line881_100_0 = lambda_isp_oldlua_line881_100_0_cotmp_1;

      signed int clap_479_pack_0 = lambda_isp_oldlua_line881_100_0;
      // max clap_479_0 <= (clap_479_pack_1 , clap_479_pack_0)
      signed int clap_479_0_cotmp_1 = (clap_479_pack_1 > clap_479_pack_0) ? clap_479_pack_1 : clap_479_pack_0;
      signed int clap_479_0 = clap_479_0_cotmp_1;

      signed int clap_480_pack_0 = clap_479_0;
      // min clap_480_0 <= (clap_480_pack_1 , clap_480_pack_0)
      signed int clap_480_0_cotmp_1 = (clap_480_pack_1 < clap_480_pack_0) ? clap_480_pack_1 : clap_480_pack_0;
      signed int clap_480_0 = clap_480_0_cotmp_1;

      unsigned int lambda_isp_oldlua_line1282_727_0 = clap_480_0;
      out(x,y,0) = lambda_isp_oldlua_line1282_727_0;
    }
  }
} // END lambda_isp_oldlua_line1282_33


void lambda_isp_oldlua_line1282_35(const Image<int>& in, Image<int>& out
)
{
  for(int y = 0; y < in.height(); y++){
    for(int x = 0; x < in.width(); x++){
      unsigned int lambda_isp_oldlua_line1282_727_pp_4_4 = in(x+2, y+2, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_4_3 = in(x+2, y+1, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_4_2 = in(x+2, y+0, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_4_1 = in(x+2, y+-1, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_4_0 = in(x+2, y+-2, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_3_4 = in(x+1, y+2, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_3_3 = in(x+1, y+1, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_3_2 = in(x+1, y+0, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_3_1 = in(x+1, y+-1, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_3_0 = in(x+1, y+-2, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_2_4 = in(x+0, y+2, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_2_3 = in(x+0, y+1, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_2_2 = in(x+0, y+0, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_2_1 = in(x+0, y+-1, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_2_0 = in(x+0, y+-2, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_1_4 = in(x+-1, y+2, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_1_3 = in(x+-1, y+1, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_1_2 = in(x+-1, y+0, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_1_1 = in(x+-1, y+-1, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_1_0 = in(x+-1, y+-2, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_0_4 = in(x+-2, y+2, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_0_3 = in(x+-2, y+1, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_0_2 = in(x+-2, y+0, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_0_1 = in(x+-2, y+-1, 0);
      unsigned int lambda_isp_oldlua_line1282_727_pp_0_0 = in(x+-2, y+-2, 0);
      const float c_1023_0 = 1023;
      const float c_4_0 = 4;
      const float c_3_0 = 3;
      const float c_100000_0 = 100000;
      const float c_36_0 = 36;
      const float c_176_0 = 176;
      const float c_20_0 = 20;
      const float c_1_0 = 1;
      const float c_0_0 = 0;
      const float c_2_0 = 2;
      const float c_40_0 = 40;
      const float c_8_0 = 8;
      
      signed int lambda_isp_oldlua_line1269_772_0 = lambda_isp_oldlua_line1282_727_pp_0_0;
      signed int clap_481_0 = c_1023_0;
      signed int lambda_isp_oldlua_line1269_776_0 = lambda_isp_oldlua_line1282_727_pp_0_3;
      signed int clap_482_0 = c_0_0;
      signed int lambda_isp_oldlua_line1240_345_0 = c_8_0;
      signed int lambda_isp_oldlua_line1269_778_0 = lambda_isp_oldlua_line1282_727_pp_1_3;
      signed int lambda_isp_oldlua_line1269_790_0 = lambda_isp_oldlua_line1282_727_pp_1_4;
      signed int mean3_68_pack_0 = lambda_isp_oldlua_line1269_790_0;
      signed int lambda_isp_oldlua_line1269_791_0 = lambda_isp_oldlua_line1282_727_pp_3_4;
      signed int lambda_isp_oldlua_line1269_770_0 = lambda_isp_oldlua_line1282_727_pp_0_2;
      signed int lambda_isp_oldlua_line394_285_pack_0 = lambda_isp_oldlua_line1269_770_0;
      signed int lambda_isp_oldlua_line1269_773_0 = lambda_isp_oldlua_line1282_727_pp_2_0;
      signed int lambda_isp_oldlua_line468_205_pack_1 = clap_482_0;
      signed int lambda_isp_oldlua_line394_278_pack_1 = lambda_isp_oldlua_line1269_773_0;
      signed int mean2_50_pack_1 = lambda_isp_oldlua_line1269_791_0;
      signed int lambda_isp_oldlua_line468_65_0 = c_40_0;
      signed int clap_487_pack_1 = clap_482_0;
      signed int offY_4176_0 = c_4_0;
      signed int lambda_isp_oldlua_line1269_783_0 = lambda_isp_oldlua_line1282_727_pp_0_1;
      signed int mean3_56_pack_0 = lambda_isp_oldlua_line1269_783_0;
      signed int mean3_68_pack_1 = lambda_isp_oldlua_line1269_791_0;
      signed int lambda_isp_oldlua_line1269_781_0 = lambda_isp_oldlua_line1282_727_pp_1_2;
      signed int mean2_50_pack_2 = lambda_isp_oldlua_line1269_781_0;
      signed int mean2_47_pack_1 = lambda_isp_oldlua_line1269_781_0;
      signed int lambda_isp_oldlua_line468_206_pack_1 = clap_481_0;
      signed int mean3_53_pack_0 = lambda_isp_oldlua_line1269_776_0;
      signed int lambda_isp_oldlua_line1269_787_0 = lambda_isp_oldlua_line1282_727_pp_4_1;
      signed int mean3_64_pack_5 = lambda_isp_oldlua_line1269_787_0;
      signed int mean3_61_pack_1 = lambda_isp_oldlua_line1269_787_0;
      // min mean3_68_0 <= (mean3_68_pack_1 , mean3_68_pack_0)
      signed int mean3_68_0_cotmp_1 = (mean3_68_pack_1 < mean3_68_pack_0) ? mean3_68_pack_1 : mean3_68_pack_0;
      signed int mean3_68_0 = mean3_68_0_cotmp_1;

      signed int mean3_57_pack_0 = lambda_isp_oldlua_line1269_783_0;
      signed int clap_488_pack_1 = clap_481_0;
      signed int mean1_10_pack_6 = lambda_isp_oldlua_line1269_773_0;
      signed int lambda_isp_oldlua_line394_119_0 = c_36_0;
      signed int lambda_isp_oldlua_line394_152_0 = c_20_0;
      signed int lambda_isp_oldlua_line394_335_pack_1 = lambda_isp_oldlua_line394_152_0;
      signed int lambda_isp_oldlua_line394_322_0 = lambda_isp_oldlua_line1269_790_0 - lambda_isp_oldlua_line1269_781_0;
      signed int lambda_isp_oldlua_line394_323_0 = (lambda_isp_oldlua_line394_322_0 >= 0) ? lambda_isp_oldlua_line394_322_0 : (-lambda_isp_oldlua_line394_322_0);
      signed int mean3_58_pack_1 = lambda_isp_oldlua_line1269_787_0;
      signed int lambda_isp_oldlua_line394_324_pack_0 = lambda_isp_oldlua_line394_323_0;
      signed int lambda_isp_oldlua_line394_140_0 = c_176_0;
      signed int offY_4177_0 = c_3_0;
      signed int lambda_isp_oldlua_line1269_786_0 = lambda_isp_oldlua_line1282_727_pp_3_1;
      signed int mean1_10_pack_5 = lambda_isp_oldlua_line1269_772_0;
      signed int mean3_64_pack_3 = lambda_isp_oldlua_line1269_783_0;
      signed int lambda_isp_oldlua_line1269_788_0 = lambda_isp_oldlua_line1282_727_pp_3_0;
      signed int mean2_41_pack_1 = lambda_isp_oldlua_line1269_788_0;
      signed int mean3_67_pack_1 = lambda_isp_oldlua_line1269_791_0;
      signed int lambda_isp_oldlua_line1269_784_0 = lambda_isp_oldlua_line1282_727_pp_2_1;
      signed int lambda_isp_oldlua_line394_311_0 = lambda_isp_oldlua_line1269_784_0 - lambda_isp_oldlua_line1269_787_0;
      signed int lambda_isp_oldlua_line394_312_0 = (lambda_isp_oldlua_line394_311_0 >= 0) ? lambda_isp_oldlua_line394_311_0 : (-lambda_isp_oldlua_line394_311_0);
      signed int lambda_isp_oldlua_line394_313_pack_7 = lambda_isp_oldlua_line394_312_0;
      signed int mean3_57_pack_1 = lambda_isp_oldlua_line1269_784_0;
      // min mean3_57_0 <= (mean3_57_pack_1 , mean3_57_pack_0)
      signed int mean3_57_0_cotmp_1 = (mean3_57_pack_1 < mean3_57_pack_0) ? mean3_57_pack_1 : mean3_57_pack_0;
      signed int mean3_57_0 = mean3_57_0_cotmp_1;

      signed int lambda_isp_oldlua_line1269_775_0 = lambda_isp_oldlua_line1282_727_pp_4_2;
      signed int lambda_isp_oldlua_line394_286_0 = lambda_isp_oldlua_line1269_770_0 + lambda_isp_oldlua_line1269_775_0;
      signed int lambda_isp_oldlua_line394_285_pack_1 = lambda_isp_oldlua_line1269_775_0;
      signed int lambda_isp_oldlua_line1269_767_0 = lambda_isp_oldlua_line1282_727_pp_2_2;
      signed int lambda_isp_oldlua_line394_276_0 = lambda_isp_oldlua_line1269_767_0 - lambda_isp_oldlua_line1269_773_0;
      signed int lambda_isp_oldlua_line394_277_0 = (lambda_isp_oldlua_line394_276_0 >= 0) ? lambda_isp_oldlua_line394_276_0 : (-lambda_isp_oldlua_line394_276_0);
      signed int lambda_isp_oldlua_line394_271_0 = -lambda_isp_oldlua_line1269_767_0;
      signed int lambda_isp_oldlua_line394_324_pack_5 = lambda_isp_oldlua_line394_277_0;
      signed int lambda_isp_oldlua_line394_283_0 = lambda_isp_oldlua_line1269_767_0 - lambda_isp_oldlua_line1269_775_0;
      signed int mean2_44_pack_1 = lambda_isp_oldlua_line1269_781_0;
      signed int mean3_64_pack_4 = lambda_isp_oldlua_line1269_784_0;
      signed int lambda_isp_oldlua_line1269_782_0 = lambda_isp_oldlua_line1282_727_pp_3_2;
      signed int lambda_isp_oldlua_line394_318_0 = lambda_isp_oldlua_line1269_782_0 - lambda_isp_oldlua_line1269_788_0;
      signed int lambda_isp_oldlua_line394_319_0 = (lambda_isp_oldlua_line394_318_0 >= 0) ? lambda_isp_oldlua_line394_318_0 : (-lambda_isp_oldlua_line394_318_0);
      signed int mean2_42_pack_0 = lambda_isp_oldlua_line1269_782_0;
      signed int lambda_isp_oldlua_line394_297_0 = lambda_isp_oldlua_line1269_781_0 - lambda_isp_oldlua_line1269_782_0;
      signed int lambda_isp_oldlua_line394_298_0 = (lambda_isp_oldlua_line394_297_0 >= 0) ? lambda_isp_oldlua_line394_297_0 : (-lambda_isp_oldlua_line394_297_0);
      signed int lambda_isp_oldlua_line394_313_pack_3 = lambda_isp_oldlua_line394_298_0;
      signed int mean2_40_pack_0 = lambda_isp_oldlua_line1269_782_0;
      signed int lambda_isp_oldlua_line394_284_0 = (lambda_isp_oldlua_line394_283_0 >= 0) ? lambda_isp_oldlua_line394_283_0 : (-lambda_isp_oldlua_line394_283_0);
      signed int lambda_isp_oldlua_line394_313_pack_4 = lambda_isp_oldlua_line394_284_0;
      signed int lambda_isp_oldlua_line1269_777_0 = lambda_isp_oldlua_line1282_727_pp_2_3;
      signed int lambda_isp_oldlua_line394_303_0 = lambda_isp_oldlua_line1269_777_0 - lambda_isp_oldlua_line1269_784_0;
      signed int lambda_isp_oldlua_line394_304_0 = (lambda_isp_oldlua_line394_303_0 >= 0) ? lambda_isp_oldlua_line394_303_0 : (-lambda_isp_oldlua_line394_303_0);
      signed int lambda_isp_oldlua_line394_324_pack_4 = lambda_isp_oldlua_line394_304_0;
      signed int mean3_53_pack_1 = lambda_isp_oldlua_line1269_777_0;
      signed int mean3_64_pack_1 = lambda_isp_oldlua_line1269_777_0;
      signed int lambda_isp_oldlua_line394_290_0 = lambda_isp_oldlua_line1269_776_0 - lambda_isp_oldlua_line1269_777_0;
      signed int lambda_isp_oldlua_line1269_779_0 = lambda_isp_oldlua_line1282_727_pp_3_3;
      signed int lambda_isp_oldlua_line394_309_0 = lambda_isp_oldlua_line1269_779_0 - lambda_isp_oldlua_line1269_786_0;
      signed int lambda_isp_oldlua_line394_299_0 = lambda_isp_oldlua_line1269_779_0 - lambda_isp_oldlua_line1269_782_0;
      signed int mean3_52_pack_1 = lambda_isp_oldlua_line1269_777_0;
      // min mean3_53_0 <= (mean3_53_pack_1 , mean3_53_pack_0)
      signed int mean3_53_0_cotmp_1 = (mean3_53_pack_1 < mean3_53_pack_0) ? mean3_53_pack_1 : mean3_53_pack_0;
      signed int mean3_53_0 = mean3_53_0_cotmp_1;

      signed int mean3_55_pack_0 = mean3_53_0;
      signed int lambda_isp_oldlua_line1269_769_0 = lambda_isp_oldlua_line1282_727_pp_4_4;
      signed int mean1_10_pack_2 = lambda_isp_oldlua_line1269_769_0;
      signed int mean3_61_pack_0 = mean3_57_0;
      // min mean3_61_0 <= (mean3_61_pack_1 , mean3_61_pack_0)
      signed int mean3_61_0_cotmp_1 = (mean3_61_pack_1 < mean3_61_pack_0) ? mean3_61_pack_1 : mean3_61_pack_0;
      signed int mean3_61_0 = mean3_61_0_cotmp_1;

      signed int lambda_isp_oldlua_line394_274_0 = lambda_isp_oldlua_line1269_770_0 - lambda_isp_oldlua_line1269_767_0;
      signed int lambda_isp_oldlua_line394_275_0 = (lambda_isp_oldlua_line394_274_0 >= 0) ? lambda_isp_oldlua_line394_274_0 : (-lambda_isp_oldlua_line394_274_0);
      signed int lambda_isp_oldlua_line394_313_pack_2 = lambda_isp_oldlua_line394_275_0;
      signed int mean4_10_pack_0 = lambda_isp_oldlua_line1269_778_0;
      signed int mean3_62_pack_1 = mean3_61_0;
      signed int mean2_50_pack_5 = lambda_isp_oldlua_line1269_788_0;
      signed int mean2_47_pack_0 = mean3_68_0;
      // min mean2_47_0 <= (mean2_47_pack_1 , mean2_47_pack_0)
      signed int mean2_47_0_cotmp_1 = (mean2_47_pack_1 < mean2_47_pack_0) ? mean2_47_pack_1 : mean2_47_pack_0;
      signed int mean2_47_0 = mean2_47_0_cotmp_1;

      signed int lambda_isp_oldlua_line1269_774_0 = lambda_isp_oldlua_line1282_727_pp_4_0;
      signed int mean1_10_pack_7 = lambda_isp_oldlua_line1269_774_0;
      signed int lambda_isp_oldlua_line394_301_0 = lambda_isp_oldlua_line1269_783_0 - lambda_isp_oldlua_line1269_784_0;
      signed int lambda_isp_oldlua_line394_302_0 = (lambda_isp_oldlua_line394_301_0 >= 0) ? lambda_isp_oldlua_line394_301_0 : (-lambda_isp_oldlua_line394_301_0);
      signed int lambda_isp_oldlua_line394_313_pack_5 = lambda_isp_oldlua_line394_302_0;
      signed int mean3_64_pack_0 = lambda_isp_oldlua_line1269_776_0;
      signed int mean2_50_pack_3 = lambda_isp_oldlua_line1269_782_0;
      signed int lambda_isp_oldlua_line394_292_0 = lambda_isp_oldlua_line1269_778_0 - lambda_isp_oldlua_line1269_779_0;
      signed int lambda_isp_oldlua_line394_293_0 = (lambda_isp_oldlua_line394_292_0 >= 0) ? lambda_isp_oldlua_line394_292_0 : (-lambda_isp_oldlua_line394_292_0);
      signed int mean1_10_pack_3 = lambda_isp_oldlua_line1269_770_0;
      signed int mean2_48_pack_0 = mean2_47_0;
      signed int lambda_isp_oldlua_line1269_785_0 = lambda_isp_oldlua_line1282_727_pp_1_1;
      signed int mean4_10_pack_2 = lambda_isp_oldlua_line1269_785_0;
      signed int lambda_isp_oldlua_line394_305_0 = lambda_isp_oldlua_line1269_778_0 - lambda_isp_oldlua_line1269_785_0;
      signed int lambda_isp_oldlua_line394_306_0 = (lambda_isp_oldlua_line394_305_0 >= 0) ? lambda_isp_oldlua_line394_305_0 : (-lambda_isp_oldlua_line394_305_0);
      signed int lambda_isp_oldlua_line394_307_0 = lambda_isp_oldlua_line1269_785_0 - lambda_isp_oldlua_line1269_786_0;
      signed int lambda_isp_oldlua_line394_308_0 = (lambda_isp_oldlua_line394_307_0 >= 0) ? lambda_isp_oldlua_line394_307_0 : (-lambda_isp_oldlua_line394_307_0);
      signed int lambda_isp_oldlua_line394_313_pack_6 = lambda_isp_oldlua_line394_308_0;
      signed int mean2_43_pack_1 = lambda_isp_oldlua_line1269_788_0;
      signed int lambda_isp_oldlua_line1269_768_0 = lambda_isp_oldlua_line1282_727_pp_2_4;
      signed int lambda_isp_oldlua_line394_279_0 = lambda_isp_oldlua_line1269_768_0 + lambda_isp_oldlua_line1269_773_0;
      signed int lambda_isp_oldlua_line394_278_pack_0 = lambda_isp_oldlua_line1269_768_0;
      // max lambda_isp_oldlua_line394_278_0 <= (lambda_isp_oldlua_line394_278_pack_1 , lambda_isp_oldlua_line394_278_pack_0)
      signed int lambda_isp_oldlua_line394_278_0_cotmp_1 = (lambda_isp_oldlua_line394_278_pack_1 > lambda_isp_oldlua_line394_278_pack_0) ? lambda_isp_oldlua_line394_278_pack_1 : lambda_isp_oldlua_line394_278_pack_0;
      signed int lambda_isp_oldlua_line394_278_0 = lambda_isp_oldlua_line394_278_0_cotmp_1;

      signed int lambda_isp_oldlua_line394_272_0 = lambda_isp_oldlua_line1269_768_0 - lambda_isp_oldlua_line1269_767_0;
      signed int lambda_isp_oldlua_line394_273_0 = (lambda_isp_oldlua_line394_272_0 >= 0) ? lambda_isp_oldlua_line394_272_0 : (-lambda_isp_oldlua_line394_272_0);
      // max lambda_isp_oldlua_line394_285_0 <= (lambda_isp_oldlua_line394_285_pack_1 , lambda_isp_oldlua_line394_285_pack_0)
      signed int lambda_isp_oldlua_line394_285_0_cotmp_1 = (lambda_isp_oldlua_line394_285_pack_1 > lambda_isp_oldlua_line394_285_pack_0) ? lambda_isp_oldlua_line394_285_pack_1 : lambda_isp_oldlua_line394_285_pack_0;
      signed int lambda_isp_oldlua_line394_285_0 = lambda_isp_oldlua_line394_285_0_cotmp_1;

      signed int lambda_isp_oldlua_line1269_789_0 = lambda_isp_oldlua_line1282_727_pp_1_0;
      signed int mean2_50_pack_4 = lambda_isp_oldlua_line1269_789_0;
      signed int lambda_isp_oldlua_line394_320_0 = lambda_isp_oldlua_line1269_781_0 - lambda_isp_oldlua_line1269_789_0;
      signed int lambda_isp_oldlua_line394_321_0 = (lambda_isp_oldlua_line394_320_0 >= 0) ? lambda_isp_oldlua_line394_320_0 : (-lambda_isp_oldlua_line394_320_0);
      signed int lambda_isp_oldlua_line394_324_pack_2 = lambda_isp_oldlua_line394_321_0;
      signed int mean2_40_pack_1 = lambda_isp_oldlua_line1269_789_0;
      // max mean2_40_0 <= (mean2_40_pack_1 , mean2_40_pack_0)
      signed int mean2_40_0_cotmp_1 = (mean2_40_pack_1 > mean2_40_pack_0) ? mean2_40_pack_1 : mean2_40_pack_0;
      signed int mean2_40_0 = mean2_40_0_cotmp_1;

      signed int mean2_41_pack_0 = mean2_40_0;
      // max mean2_41_0 <= (mean2_41_pack_1 , mean2_41_pack_0)
      signed int mean2_41_0_cotmp_1 = (mean2_41_pack_1 > mean2_41_pack_0) ? mean2_41_pack_1 : mean2_41_pack_0;
      signed int mean2_41_0 = mean2_41_0_cotmp_1;

      signed int mean2_45_pack_1 = mean2_41_0;
      signed int mean3_52_pack_0 = lambda_isp_oldlua_line1269_776_0;
      signed int lambda_isp_oldlua_line1240_344_0 = c_2_0;
      signed int mean2_50_pack_8 = lambda_isp_oldlua_line1240_344_0;
      signed int mean3_64_pack_8 = lambda_isp_oldlua_line1240_344_0;
      signed int mean1_10_pack_8 = offY_4176_0;
      signed int lambda_isp_oldlua_line394_324_pack_3 = lambda_isp_oldlua_line394_273_0;
      signed int lambda_isp_oldlua_line1269_771_0 = lambda_isp_oldlua_line1282_727_pp_0_4;
      signed int mean1_10_pack_0 = lambda_isp_oldlua_line1269_771_0;
      signed int lambda_isp_oldlua_line394_291_0 = (lambda_isp_oldlua_line394_290_0 >= 0) ? lambda_isp_oldlua_line394_290_0 : (-lambda_isp_oldlua_line394_290_0);
      signed int lambda_isp_oldlua_line394_313_pack_0 = lambda_isp_oldlua_line394_291_0;
      signed int lambda_isp_oldlua_line394_324_pack_1 = lambda_isp_oldlua_line394_306_0;
      signed int mean1_10_pack_4 = lambda_isp_oldlua_line1269_775_0;
      signed int mean1_10_pack_1 = lambda_isp_oldlua_line1269_768_0;
      signed int lambda_isp_oldlua_line394_335_pack_2 = lambda_isp_oldlua_line394_271_0;
      signed int mean2_50_pack_0 = lambda_isp_oldlua_line1269_790_0;
      signed int lambda_isp_oldlua_line394_93_0 = c_100000_0;
      signed int lambda_isp_oldlua_line394_94_0 = -lambda_isp_oldlua_line394_93_0;
      signed int lambda_isp_oldlua_line394_324_pack_8 = lambda_isp_oldlua_line394_319_0;
      signed int lambda_isp_oldlua_line1240_343_0 = c_1_0;
      signed int lambda_isp_oldlua_line224_6_0 = -lambda_isp_oldlua_line1240_343_0;
      signed int lambda_isp_oldlua_line394_280_0 = lambda_isp_oldlua_line394_279_0 + lambda_isp_oldlua_line1240_343_0;
      signed int lambda_isp_oldlua_line394_167_0 = lambda_isp_oldlua_line1240_343_0 << offY_4176_0;
      signed int lambda_isp_oldlua_line394_348_pack_1 = lambda_isp_oldlua_line394_167_0;
      signed int lambda_isp_oldlua_line394_287_0 = lambda_isp_oldlua_line394_286_0 + lambda_isp_oldlua_line1240_343_0;
      signed int lambda_isp_oldlua_line394_288_pack_0 = lambda_isp_oldlua_line394_287_0;
      signed int lambda_isp_oldlua_line394_288_0 = lambda_isp_oldlua_line394_288_pack_0;
      signed int lambda_isp_oldlua_line394_289_0 = lambda_isp_oldlua_line394_288_0 >> lambda_isp_oldlua_line1240_343_0;
      signed int lambda_isp_oldlua_line394_344_pack_1 = lambda_isp_oldlua_line394_167_0;
      signed int mean2_42_pack_1 = lambda_isp_oldlua_line1269_789_0;
      // min mean2_42_0 <= (mean2_42_pack_1 , mean2_42_pack_0)
      signed int mean2_42_0_cotmp_1 = (mean2_42_pack_1 < mean2_42_pack_0) ? mean2_42_pack_1 : mean2_42_pack_0;
      signed int mean2_42_0 = mean2_42_0_cotmp_1;

      signed int mean2_43_pack_0 = mean2_42_0;
      // min mean2_43_0 <= (mean2_43_pack_1 , mean2_43_pack_0)
      signed int mean2_43_0_cotmp_1 = (mean2_43_pack_1 < mean2_43_pack_0) ? mean2_43_pack_1 : mean2_43_pack_0;
      signed int mean2_43_0 = mean2_43_0_cotmp_1;

      signed int mean2_48_pack_1 = mean2_43_0;
      // min mean2_48_0 <= (mean2_48_pack_1 , mean2_48_pack_0)
      signed int mean2_48_0_cotmp_1 = (mean2_48_pack_1 < mean2_48_pack_0) ? mean2_48_pack_1 : mean2_48_pack_0;
      signed int mean2_48_0 = mean2_48_0_cotmp_1;

      signed int mean2_49_0 = -mean2_48_0;
      signed int mean2_50_pack_7 = mean2_49_0;
      // max mean3_52_0 <= (mean3_52_pack_1 , mean3_52_pack_0)
      signed int mean3_52_0_cotmp_1 = (mean3_52_pack_1 > mean3_52_pack_0) ? mean3_52_pack_1 : mean3_52_pack_0;
      signed int mean3_52_0 = mean3_52_0_cotmp_1;

      signed int mean3_54_pack_0 = mean3_52_0;
      signed int mean4_10_pack_1 = lambda_isp_oldlua_line1269_779_0;
      signed int lambda_isp_oldlua_line1269_780_0 = lambda_isp_oldlua_line1282_727_pp_4_3;
      signed int mean3_54_pack_1 = lambda_isp_oldlua_line1269_780_0;
      signed int lambda_isp_oldlua_line394_294_0 = lambda_isp_oldlua_line1269_777_0 - lambda_isp_oldlua_line1269_780_0;
      signed int mean3_55_pack_1 = lambda_isp_oldlua_line1269_780_0;
      // min mean3_55_0 <= (mean3_55_pack_1 , mean3_55_pack_0)
      signed int mean3_55_0_cotmp_1 = (mean3_55_pack_1 < mean3_55_pack_0) ? mean3_55_pack_1 : mean3_55_pack_0;
      signed int mean3_55_0 = mean3_55_0_cotmp_1;

      signed int mean3_62_pack_0 = mean3_55_0;
      // min mean3_62_0 <= (mean3_62_pack_1 , mean3_62_pack_0)
      signed int mean3_62_0_cotmp_1 = (mean3_62_pack_1 < mean3_62_pack_0) ? mean3_62_pack_1 : mean3_62_pack_0;
      signed int mean3_62_0 = mean3_62_0_cotmp_1;

      signed int mean3_63_0 = -mean3_62_0;
      signed int mean3_64_pack_7 = mean3_63_0;
      signed int lambda_isp_oldlua_line394_295_0 = (lambda_isp_oldlua_line394_294_0 >= 0) ? lambda_isp_oldlua_line394_294_0 : (-lambda_isp_oldlua_line394_294_0);
      signed int lambda_isp_oldlua_line394_296_0 = lambda_isp_oldlua_line394_293_0 + lambda_isp_oldlua_line394_295_0;
      signed int lambda_isp_oldlua_line394_313_pack_1 = lambda_isp_oldlua_line394_296_0;
      signed int lambda_isp_oldlua_line394_313_0 = lambda_isp_oldlua_line394_313_pack_7 + lambda_isp_oldlua_line394_313_pack_6 + lambda_isp_oldlua_line394_313_pack_5 + lambda_isp_oldlua_line394_313_pack_4 + lambda_isp_oldlua_line394_313_pack_3 + lambda_isp_oldlua_line394_313_pack_2 + lambda_isp_oldlua_line394_313_pack_1 + lambda_isp_oldlua_line394_313_pack_0;
      signed int lambda_isp_oldlua_line394_316_0 = lambda_isp_oldlua_line394_119_0 - lambda_isp_oldlua_line394_313_0;
      signed int lambda_isp_oldlua_line394_343_pack_1 = lambda_isp_oldlua_line394_316_0;
      bool lambda_isp_oldlua_line394_314_0 = lambda_isp_oldlua_line394_313_0 < lambda_isp_oldlua_line394_119_0;
      signed int lambda_isp_oldlua_line394_317_0 = lambda_isp_oldlua_line394_313_0 - lambda_isp_oldlua_line394_140_0;
      bool lambda_isp_oldlua_line394_315_0 = lambda_isp_oldlua_line394_313_0 > lambda_isp_oldlua_line394_140_0;
      signed int lambda_isp_oldlua_line394_347_pack_0 = lambda_isp_oldlua_line394_317_0;
      signed int mean3_64_pack_2 = lambda_isp_oldlua_line1269_780_0;
      // max mean3_54_0 <= (mean3_54_pack_1 , mean3_54_pack_0)
      signed int mean3_54_0_cotmp_1 = (mean3_54_pack_1 > mean3_54_pack_0) ? mean3_54_pack_1 : mean3_54_pack_0;
      signed int mean3_54_0 = mean3_54_0_cotmp_1;

      signed int mean3_59_pack_0 = mean3_54_0;
      signed int mean1_10_0 = mean1_10_pack_8 + mean1_10_pack_7 + mean1_10_pack_6 + mean1_10_pack_5 + mean1_10_pack_4 + mean1_10_pack_3 + mean1_10_pack_2 + mean1_10_pack_1 + mean1_10_pack_0;
      signed int mean1_11_0 = mean1_10_0 >> offY_4177_0;
      signed int mean1_12_0 = clap_481_0 - mean1_11_0;
      signed int lambda_isp_oldlua_line256_4_0 = lambda_isp_oldlua_line1269_767_0 + mean1_12_0;
      signed int lambda_isp_oldlua_line468_156_0 = lambda_isp_oldlua_line256_4_0 - mean1_12_0;
      signed int lambda_isp_oldlua_line254_4_0 = lambda_isp_oldlua_line1269_775_0 + mean1_12_0;
      signed int lambda_isp_oldlua_line468_166_pack_1 = lambda_isp_oldlua_line254_4_0;
      signed int lambda_isp_oldlua_line252_4_0 = lambda_isp_oldlua_line1269_773_0 + mean1_12_0;
      signed int lambda_isp_oldlua_line250_4_0 = lambda_isp_oldlua_line1269_770_0 + mean1_12_0;
      signed int lambda_isp_oldlua_line248_4_0 = lambda_isp_oldlua_line1269_768_0 + mean1_12_0;
      signed int lambda_isp_oldlua_line468_157_pack_0 = lambda_isp_oldlua_line248_4_0;
      signed int lambda_isp_oldlua_line468_159_pack_0 = lambda_isp_oldlua_line248_4_0;
      signed int lambda_isp_oldlua_line468_163_pack_0 = lambda_isp_oldlua_line252_4_0;
      signed int lambda_isp_oldlua_line468_158_pack_1 = lambda_isp_oldlua_line250_4_0;
      signed int lambda_isp_oldlua_line468_160_pack_1 = lambda_isp_oldlua_line250_4_0;
      signed int lambda_isp_oldlua_line468_165_pack_0 = lambda_isp_oldlua_line252_4_0;
      signed int lambda_isp_oldlua_line468_164_pack_1 = lambda_isp_oldlua_line254_4_0;
      signed int lambda_isp_oldlua_line394_310_0 = (lambda_isp_oldlua_line394_309_0 >= 0) ? lambda_isp_oldlua_line394_309_0 : (-lambda_isp_oldlua_line394_309_0);
      signed int lambda_isp_oldlua_line394_324_pack_7 = lambda_isp_oldlua_line394_310_0;
      signed int mean4_10_pack_3 = lambda_isp_oldlua_line1269_786_0;
      signed int mean4_10_0 = mean4_10_pack_3 + mean4_10_pack_2 + mean4_10_pack_1 + mean4_10_pack_0;
      signed int mean4_11_0 = mean4_10_0 >> lambda_isp_oldlua_line1240_344_0;
      signed int mean4_12_0 = clap_481_0 - mean4_11_0;
      signed int lambda_isp_oldlua_line272_4_0 = lambda_isp_oldlua_line1269_786_0 + mean4_12_0;
      signed int lambda_isp_oldlua_line468_163_pack_1 = lambda_isp_oldlua_line272_4_0;
      signed int lambda_isp_oldlua_line468_165_pack_1 = lambda_isp_oldlua_line272_4_0;
      signed int lambda_isp_oldlua_line270_4_0 = lambda_isp_oldlua_line1269_785_0 + mean4_12_0;
      // min lambda_isp_oldlua_line468_163_0 <= (lambda_isp_oldlua_line468_163_pack_1 , lambda_isp_oldlua_line468_163_pack_0)
      signed int lambda_isp_oldlua_line468_163_0_cotmp_1 = (lambda_isp_oldlua_line468_163_pack_1 < lambda_isp_oldlua_line468_163_pack_0) ? lambda_isp_oldlua_line468_163_pack_1 : lambda_isp_oldlua_line468_163_pack_0;
      signed int lambda_isp_oldlua_line468_163_0 = lambda_isp_oldlua_line468_163_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_161_pack_1 = lambda_isp_oldlua_line270_4_0;
      // max lambda_isp_oldlua_line468_165_0 <= (lambda_isp_oldlua_line468_165_pack_1 , lambda_isp_oldlua_line468_165_pack_0)
      signed int lambda_isp_oldlua_line468_165_0_cotmp_1 = (lambda_isp_oldlua_line468_165_pack_1 > lambda_isp_oldlua_line468_165_pack_0) ? lambda_isp_oldlua_line468_165_pack_1 : lambda_isp_oldlua_line468_165_pack_0;
      signed int lambda_isp_oldlua_line468_165_0 = lambda_isp_oldlua_line468_165_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_166_pack_0 = lambda_isp_oldlua_line468_165_0;
      // max lambda_isp_oldlua_line468_166_0 <= (lambda_isp_oldlua_line468_166_pack_1 , lambda_isp_oldlua_line468_166_pack_0)
      signed int lambda_isp_oldlua_line468_166_0_cotmp_1 = (lambda_isp_oldlua_line468_166_pack_1 > lambda_isp_oldlua_line468_166_pack_0) ? lambda_isp_oldlua_line468_166_pack_1 : lambda_isp_oldlua_line468_166_pack_0;
      signed int lambda_isp_oldlua_line468_166_0 = lambda_isp_oldlua_line468_166_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_162_pack_1 = lambda_isp_oldlua_line270_4_0;
      signed int lambda_isp_oldlua_line266_4_0 = lambda_isp_oldlua_line1269_778_0 + mean4_12_0;
      signed int lambda_isp_oldlua_line468_159_pack_1 = lambda_isp_oldlua_line266_4_0;
      signed int lambda_isp_oldlua_line468_169_pack_0 = lambda_isp_oldlua_line468_166_0;
      signed int lambda_isp_oldlua_line468_164_pack_0 = lambda_isp_oldlua_line468_163_0;
      // min lambda_isp_oldlua_line468_164_0 <= (lambda_isp_oldlua_line468_164_pack_1 , lambda_isp_oldlua_line468_164_pack_0)
      signed int lambda_isp_oldlua_line468_164_0_cotmp_1 = (lambda_isp_oldlua_line468_164_pack_1 < lambda_isp_oldlua_line468_164_pack_0) ? lambda_isp_oldlua_line468_164_pack_1 : lambda_isp_oldlua_line468_164_pack_0;
      signed int lambda_isp_oldlua_line468_164_0 = lambda_isp_oldlua_line468_164_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_167_pack_0 = lambda_isp_oldlua_line468_164_0;
      signed int lambda_isp_oldlua_line468_157_pack_1 = lambda_isp_oldlua_line266_4_0;
      // min lambda_isp_oldlua_line468_157_0 <= (lambda_isp_oldlua_line468_157_pack_1 , lambda_isp_oldlua_line468_157_pack_0)
      signed int lambda_isp_oldlua_line468_157_0_cotmp_1 = (lambda_isp_oldlua_line468_157_pack_1 < lambda_isp_oldlua_line468_157_pack_0) ? lambda_isp_oldlua_line468_157_pack_1 : lambda_isp_oldlua_line468_157_pack_0;
      signed int lambda_isp_oldlua_line468_157_0 = lambda_isp_oldlua_line468_157_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_158_pack_0 = lambda_isp_oldlua_line468_157_0;
      // min lambda_isp_oldlua_line468_158_0 <= (lambda_isp_oldlua_line468_158_pack_1 , lambda_isp_oldlua_line468_158_pack_0)
      signed int lambda_isp_oldlua_line468_158_0_cotmp_1 = (lambda_isp_oldlua_line468_158_pack_1 < lambda_isp_oldlua_line468_158_pack_0) ? lambda_isp_oldlua_line468_158_pack_1 : lambda_isp_oldlua_line468_158_pack_0;
      signed int lambda_isp_oldlua_line468_158_0 = lambda_isp_oldlua_line468_158_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_161_pack_0 = lambda_isp_oldlua_line468_158_0;
      // min lambda_isp_oldlua_line468_161_0 <= (lambda_isp_oldlua_line468_161_pack_1 , lambda_isp_oldlua_line468_161_pack_0)
      signed int lambda_isp_oldlua_line468_161_0_cotmp_1 = (lambda_isp_oldlua_line468_161_pack_1 < lambda_isp_oldlua_line468_161_pack_0) ? lambda_isp_oldlua_line468_161_pack_1 : lambda_isp_oldlua_line468_161_pack_0;
      signed int lambda_isp_oldlua_line468_161_0 = lambda_isp_oldlua_line468_161_0_cotmp_1;

      signed int lambda_isp_oldlua_line268_4_0 = lambda_isp_oldlua_line1269_779_0 + mean4_12_0;
      signed int lambda_isp_oldlua_line468_169_pack_1 = lambda_isp_oldlua_line268_4_0;
      // max lambda_isp_oldlua_line468_159_0 <= (lambda_isp_oldlua_line468_159_pack_1 , lambda_isp_oldlua_line468_159_pack_0)
      signed int lambda_isp_oldlua_line468_159_0_cotmp_1 = (lambda_isp_oldlua_line468_159_pack_1 > lambda_isp_oldlua_line468_159_pack_0) ? lambda_isp_oldlua_line468_159_pack_1 : lambda_isp_oldlua_line468_159_pack_0;
      signed int lambda_isp_oldlua_line468_159_0 = lambda_isp_oldlua_line468_159_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_168_pack_0 = lambda_isp_oldlua_line468_161_0;
      // max lambda_isp_oldlua_line468_169_0 <= (lambda_isp_oldlua_line468_169_pack_1 , lambda_isp_oldlua_line468_169_pack_0)
      signed int lambda_isp_oldlua_line468_169_0_cotmp_1 = (lambda_isp_oldlua_line468_169_pack_1 > lambda_isp_oldlua_line468_169_pack_0) ? lambda_isp_oldlua_line468_169_pack_1 : lambda_isp_oldlua_line468_169_pack_0;
      signed int lambda_isp_oldlua_line468_169_0 = lambda_isp_oldlua_line468_169_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_170_pack_1 = lambda_isp_oldlua_line468_169_0;
      signed int lambda_isp_oldlua_line468_167_pack_1 = lambda_isp_oldlua_line268_4_0;
      // min lambda_isp_oldlua_line468_167_0 <= (lambda_isp_oldlua_line468_167_pack_1 , lambda_isp_oldlua_line468_167_pack_0)
      signed int lambda_isp_oldlua_line468_167_0_cotmp_1 = (lambda_isp_oldlua_line468_167_pack_1 < lambda_isp_oldlua_line468_167_pack_0) ? lambda_isp_oldlua_line468_167_pack_1 : lambda_isp_oldlua_line468_167_pack_0;
      signed int lambda_isp_oldlua_line468_167_0 = lambda_isp_oldlua_line468_167_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_168_pack_1 = lambda_isp_oldlua_line468_167_0;
      // min lambda_isp_oldlua_line468_168_0 <= (lambda_isp_oldlua_line468_168_pack_1 , lambda_isp_oldlua_line468_168_pack_0)
      signed int lambda_isp_oldlua_line468_168_0_cotmp_1 = (lambda_isp_oldlua_line468_168_pack_1 < lambda_isp_oldlua_line468_168_pack_0) ? lambda_isp_oldlua_line468_168_pack_1 : lambda_isp_oldlua_line468_168_pack_0;
      signed int lambda_isp_oldlua_line468_168_0 = lambda_isp_oldlua_line468_168_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_177_pack_0 = lambda_isp_oldlua_line468_168_0;
      signed int lambda_isp_oldlua_line468_160_pack_0 = lambda_isp_oldlua_line468_159_0;
      // max lambda_isp_oldlua_line468_160_0 <= (lambda_isp_oldlua_line468_160_pack_1 , lambda_isp_oldlua_line468_160_pack_0)
      signed int lambda_isp_oldlua_line468_160_0_cotmp_1 = (lambda_isp_oldlua_line468_160_pack_1 > lambda_isp_oldlua_line468_160_pack_0) ? lambda_isp_oldlua_line468_160_pack_1 : lambda_isp_oldlua_line468_160_pack_0;
      signed int lambda_isp_oldlua_line468_160_0 = lambda_isp_oldlua_line468_160_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_162_pack_0 = lambda_isp_oldlua_line468_160_0;
      // max lambda_isp_oldlua_line468_162_0 <= (lambda_isp_oldlua_line468_162_pack_1 , lambda_isp_oldlua_line468_162_pack_0)
      signed int lambda_isp_oldlua_line468_162_0_cotmp_1 = (lambda_isp_oldlua_line468_162_pack_1 > lambda_isp_oldlua_line468_162_pack_0) ? lambda_isp_oldlua_line468_162_pack_1 : lambda_isp_oldlua_line468_162_pack_0;
      signed int lambda_isp_oldlua_line468_162_0 = lambda_isp_oldlua_line468_162_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_170_pack_0 = lambda_isp_oldlua_line468_162_0;
      // max lambda_isp_oldlua_line468_170_0 <= (lambda_isp_oldlua_line468_170_pack_1 , lambda_isp_oldlua_line468_170_pack_0)
      signed int lambda_isp_oldlua_line468_170_0_cotmp_1 = (lambda_isp_oldlua_line468_170_pack_1 > lambda_isp_oldlua_line468_170_pack_0) ? lambda_isp_oldlua_line468_170_pack_1 : lambda_isp_oldlua_line468_170_pack_0;
      signed int lambda_isp_oldlua_line468_170_0 = lambda_isp_oldlua_line468_170_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_179_pack_0 = lambda_isp_oldlua_line468_170_0;
      signed int lambda_isp_oldlua_line394_281_pack_0 = lambda_isp_oldlua_line394_280_0;
      signed int lambda_isp_oldlua_line394_281_0 = lambda_isp_oldlua_line394_281_pack_0;
      signed int lambda_isp_oldlua_line394_282_0 = lambda_isp_oldlua_line394_281_0 >> lambda_isp_oldlua_line1240_343_0;
      signed int mean3_56_pack_1 = lambda_isp_oldlua_line1269_784_0;
      // max mean3_56_0 <= (mean3_56_pack_1 , mean3_56_pack_0)
      signed int mean3_56_0_cotmp_1 = (mean3_56_pack_1 > mean3_56_pack_0) ? mean3_56_pack_1 : mean3_56_pack_0;
      signed int mean3_56_0 = mean3_56_0_cotmp_1;

      signed int mean3_58_pack_0 = mean3_56_0;
      // max mean3_58_0 <= (mean3_58_pack_1 , mean3_58_pack_0)
      signed int mean3_58_0_cotmp_1 = (mean3_58_pack_1 > mean3_58_pack_0) ? mean3_58_pack_1 : mean3_58_pack_0;
      signed int mean3_58_0 = mean3_58_0_cotmp_1;

      signed int mean3_59_pack_1 = mean3_58_0;
      // max mean3_59_0 <= (mean3_59_pack_1 , mean3_59_pack_0)
      signed int mean3_59_0_cotmp_1 = (mean3_59_pack_1 > mean3_59_pack_0) ? mean3_59_pack_1 : mean3_59_pack_0;
      signed int mean3_59_0 = mean3_59_0_cotmp_1;

      signed int mean3_60_0 = -mean3_59_0;
      signed int mean3_64_pack_6 = mean3_60_0;
      signed int mean3_64_0 = mean3_64_pack_8 + mean3_64_pack_7 + mean3_64_pack_6 + mean3_64_pack_5 + mean3_64_pack_4 + mean3_64_pack_3 + mean3_64_pack_2 + mean3_64_pack_1 + mean3_64_pack_0;
      signed int mean3_65_0 = mean3_64_0 >> lambda_isp_oldlua_line1240_344_0;
      signed int mean3_66_0 = clap_481_0 - mean3_65_0;
      signed int lambda_isp_oldlua_line262_4_0 = lambda_isp_oldlua_line1269_777_0 + mean3_66_0;
      signed int lambda_isp_oldlua_line468_174_pack_0 = lambda_isp_oldlua_line262_4_0;
      signed int lambda_isp_oldlua_line264_4_0 = lambda_isp_oldlua_line1269_784_0 + mean3_66_0;
      signed int lambda_isp_oldlua_line468_173_pack_1 = lambda_isp_oldlua_line264_4_0;
      signed int lambda_isp_oldlua_line468_172_pack_0 = lambda_isp_oldlua_line262_4_0;
      signed int lambda_isp_oldlua_line468_175_pack_1 = lambda_isp_oldlua_line264_4_0;
      signed int lambda_isp_oldlua_line394_300_0 = (lambda_isp_oldlua_line394_299_0 >= 0) ? lambda_isp_oldlua_line394_299_0 : (-lambda_isp_oldlua_line394_299_0);
      signed int lambda_isp_oldlua_line394_324_pack_6 = lambda_isp_oldlua_line394_300_0;
      signed int lambda_isp_oldlua_line394_324_0 = lambda_isp_oldlua_line394_324_pack_8 + lambda_isp_oldlua_line394_324_pack_7 + lambda_isp_oldlua_line394_324_pack_6 + lambda_isp_oldlua_line394_324_pack_5 + lambda_isp_oldlua_line394_324_pack_4 + lambda_isp_oldlua_line394_324_pack_3 + lambda_isp_oldlua_line394_324_pack_2 + lambda_isp_oldlua_line394_324_pack_1 + lambda_isp_oldlua_line394_324_pack_0;
      signed int lambda_isp_oldlua_line394_346_0 = lambda_isp_oldlua_line394_119_0 - lambda_isp_oldlua_line394_324_0;
      bool lambda_isp_oldlua_line394_329_0 = lambda_isp_oldlua_line394_324_0 < lambda_isp_oldlua_line394_119_0;
      bool lambda_isp_oldlua_line394_325_0 = lambda_isp_oldlua_line394_324_0 > lambda_isp_oldlua_line394_140_0;
      bool lambda_isp_oldlua_line394_330_0 = lambda_isp_oldlua_line394_329_0 & lambda_isp_oldlua_line394_315_0;
      signed int lambda_isp_oldlua_line394_342_0 = lambda_isp_oldlua_line394_324_0 - lambda_isp_oldlua_line394_140_0;
      signed int lambda_isp_oldlua_line394_343_pack_0 = lambda_isp_oldlua_line394_342_0;
      // min lambda_isp_oldlua_line394_343_0 <= (lambda_isp_oldlua_line394_343_pack_1 , lambda_isp_oldlua_line394_343_pack_0)
      signed int lambda_isp_oldlua_line394_343_0_cotmp_1 = (lambda_isp_oldlua_line394_343_pack_1 < lambda_isp_oldlua_line394_343_pack_0) ? lambda_isp_oldlua_line394_343_pack_1 : lambda_isp_oldlua_line394_343_pack_0;
      signed int lambda_isp_oldlua_line394_343_0 = lambda_isp_oldlua_line394_343_0_cotmp_1;

      signed int lambda_isp_oldlua_line394_344_pack_0 = lambda_isp_oldlua_line394_343_0;
      // min lambda_isp_oldlua_line394_344_0 <= (lambda_isp_oldlua_line394_344_pack_1 , lambda_isp_oldlua_line394_344_pack_0)
      signed int lambda_isp_oldlua_line394_344_0_cotmp_1 = (lambda_isp_oldlua_line394_344_pack_1 < lambda_isp_oldlua_line394_344_pack_0) ? lambda_isp_oldlua_line394_344_pack_1 : lambda_isp_oldlua_line394_344_pack_0;
      signed int lambda_isp_oldlua_line394_344_0 = lambda_isp_oldlua_line394_344_0_cotmp_1;

      signed int lambda_isp_oldlua_line394_347_pack_1 = lambda_isp_oldlua_line394_346_0;
      // min lambda_isp_oldlua_line394_347_0 <= (lambda_isp_oldlua_line394_347_pack_1 , lambda_isp_oldlua_line394_347_pack_0)
      signed int lambda_isp_oldlua_line394_347_0_cotmp_1 = (lambda_isp_oldlua_line394_347_pack_1 < lambda_isp_oldlua_line394_347_pack_0) ? lambda_isp_oldlua_line394_347_pack_1 : lambda_isp_oldlua_line394_347_pack_0;
      signed int lambda_isp_oldlua_line394_347_0 = lambda_isp_oldlua_line394_347_0_cotmp_1;

      signed int lambda_isp_oldlua_line394_348_pack_0 = lambda_isp_oldlua_line394_347_0;
      // min lambda_isp_oldlua_line394_348_0 <= (lambda_isp_oldlua_line394_348_pack_1 , lambda_isp_oldlua_line394_348_pack_0)
      signed int lambda_isp_oldlua_line394_348_0_cotmp_1 = (lambda_isp_oldlua_line394_348_pack_1 < lambda_isp_oldlua_line394_348_pack_0) ? lambda_isp_oldlua_line394_348_pack_1 : lambda_isp_oldlua_line394_348_pack_0;
      signed int lambda_isp_oldlua_line394_348_0 = lambda_isp_oldlua_line394_348_0_cotmp_1;

      bool lambda_isp_oldlua_line394_326_0 = lambda_isp_oldlua_line394_314_0 & lambda_isp_oldlua_line394_325_0;
      bool lambda_isp_oldlua_line394_339_0 = lambda_isp_oldlua_line394_330_0 | lambda_isp_oldlua_line394_326_0;
      signed int lambda_isp_oldlua_line394_327_0 = lambda_isp_oldlua_line394_326_0 ? lambda_isp_oldlua_line394_285_0 : lambda_isp_oldlua_line394_94_0;
      signed int lambda_isp_oldlua_line394_328_0 = lambda_isp_oldlua_line394_326_0 ? lambda_isp_oldlua_line394_289_0 : lambda_isp_oldlua_line394_94_0;
      signed int lambda_isp_oldlua_line394_336_0 = lambda_isp_oldlua_line394_330_0 ? lambda_isp_oldlua_line394_282_0 : lambda_isp_oldlua_line394_328_0;
      signed int lambda_isp_oldlua_line394_340_0 = lambda_isp_oldlua_line394_339_0 ? clap_482_0 : lambda_isp_oldlua_line1240_343_0;
      bool lambda_isp_oldlua_line394_341_0 = lambda_isp_oldlua_line394_340_0 == lambda_isp_oldlua_line1240_343_0;
      signed int lambda_isp_oldlua_line394_337_pack_0 = lambda_isp_oldlua_line394_336_0;
      signed int lambda_isp_oldlua_line394_331_0 = lambda_isp_oldlua_line394_330_0 ? lambda_isp_oldlua_line394_278_0 : lambda_isp_oldlua_line394_327_0;
      signed int lambda_isp_oldlua_line394_334_0 = lambda_isp_oldlua_line394_331_0 << lambda_isp_oldlua_line1240_343_0;
      signed int lambda_isp_oldlua_line394_335_pack_0 = lambda_isp_oldlua_line394_334_0;
      signed int lambda_isp_oldlua_line394_335_0 = lambda_isp_oldlua_line394_335_pack_2 + lambda_isp_oldlua_line394_335_pack_1 + lambda_isp_oldlua_line394_335_pack_0;
      signed int lambda_isp_oldlua_line394_332_0 = lambda_isp_oldlua_line394_331_0 + lambda_isp_oldlua_line394_152_0;
      bool lambda_isp_oldlua_line394_333_0 = lambda_isp_oldlua_line1269_767_0 > lambda_isp_oldlua_line394_332_0;
      signed int lambda_isp_oldlua_line394_337_pack_1 = lambda_isp_oldlua_line394_335_0;
      // max lambda_isp_oldlua_line394_337_0 <= (lambda_isp_oldlua_line394_337_pack_1 , lambda_isp_oldlua_line394_337_pack_0)
      signed int lambda_isp_oldlua_line394_337_0_cotmp_1 = (lambda_isp_oldlua_line394_337_pack_1 > lambda_isp_oldlua_line394_337_pack_0) ? lambda_isp_oldlua_line394_337_pack_1 : lambda_isp_oldlua_line394_337_pack_0;
      signed int lambda_isp_oldlua_line394_337_0 = lambda_isp_oldlua_line394_337_0_cotmp_1;

      signed int lambda_isp_oldlua_line394_338_0 = lambda_isp_oldlua_line394_333_0 ? lambda_isp_oldlua_line394_337_0 : lambda_isp_oldlua_line1269_767_0;
      signed int lambda_isp_oldlua_line394_345_0 = lambda_isp_oldlua_line394_326_0 ? lambda_isp_oldlua_line394_344_0 : lambda_isp_oldlua_line394_94_0;
      signed int lambda_isp_oldlua_line394_349_0 = lambda_isp_oldlua_line394_330_0 ? lambda_isp_oldlua_line394_348_0 : lambda_isp_oldlua_line394_345_0;
      signed int lambda_isp_oldlua_line394_351_0 = lambda_isp_oldlua_line394_167_0 - lambda_isp_oldlua_line394_349_0;
      signed int lambda_isp_oldlua_line394_350_0 = lambda_isp_oldlua_line394_338_0 * lambda_isp_oldlua_line394_349_0;
      signed int lambda_isp_oldlua_line394_352_0 = lambda_isp_oldlua_line394_351_0 * lambda_isp_oldlua_line1269_767_0;
      signed int lambda_isp_oldlua_line394_353_0 = lambda_isp_oldlua_line394_350_0 + lambda_isp_oldlua_line394_352_0;
      signed int lambda_isp_oldlua_line394_354_0 = lambda_isp_oldlua_line394_353_0 >> offY_4176_0;
      signed int lambda_isp_oldlua_line394_355_0 = lambda_isp_oldlua_line394_354_0 - lambda_isp_oldlua_line1269_767_0;
      signed int lambda_isp_oldlua_line394_356_0 = lambda_isp_oldlua_line394_341_0 ? clap_482_0 : lambda_isp_oldlua_line394_355_0;
      signed int lambda_isp_oldlua_line468_198_pack_0 = lambda_isp_oldlua_line394_356_0;
      bool lambda_isp_oldlua_line224_15_0 = lambda_isp_oldlua_line394_356_0 < clap_482_0;
      signed int lambda_isp_oldlua_line468_197_pack_0 = lambda_isp_oldlua_line394_356_0;
      signed int lambda_isp_oldlua_line224_16_0 = lambda_isp_oldlua_line224_15_0 ? lambda_isp_oldlua_line224_6_0 : lambda_isp_oldlua_line1240_343_0;
      bool lambda_isp_oldlua_line468_171_0 = lambda_isp_oldlua_line224_16_0 == lambda_isp_oldlua_line1240_343_0;
      signed int mean3_67_pack_0 = lambda_isp_oldlua_line1269_790_0;
      // max mean3_67_0 <= (mean3_67_pack_1 , mean3_67_pack_0)
      signed int mean3_67_0_cotmp_1 = (mean3_67_pack_1 > mean3_67_pack_0) ? mean3_67_pack_1 : mean3_67_pack_0;
      signed int mean3_67_0 = mean3_67_0_cotmp_1;

      signed int mean2_44_pack_0 = mean3_67_0;
      // max mean2_44_0 <= (mean2_44_pack_1 , mean2_44_pack_0)
      signed int mean2_44_0_cotmp_1 = (mean2_44_pack_1 > mean2_44_pack_0) ? mean2_44_pack_1 : mean2_44_pack_0;
      signed int mean2_44_0 = mean2_44_0_cotmp_1;

      signed int mean2_45_pack_0 = mean2_44_0;
      // max mean2_45_0 <= (mean2_45_pack_1 , mean2_45_pack_0)
      signed int mean2_45_0_cotmp_1 = (mean2_45_pack_1 > mean2_45_pack_0) ? mean2_45_pack_1 : mean2_45_pack_0;
      signed int mean2_45_0 = mean2_45_0_cotmp_1;

      signed int mean2_46_0 = -mean2_45_0;
      signed int mean2_50_pack_6 = mean2_46_0;
      signed int mean2_50_0 = mean2_50_pack_8 + mean2_50_pack_7 + mean2_50_pack_6 + mean2_50_pack_5 + mean2_50_pack_4 + mean2_50_pack_3 + mean2_50_pack_2 + mean2_50_pack_1 + mean2_50_pack_0;
      signed int mean2_51_0 = mean2_50_0 >> lambda_isp_oldlua_line1240_344_0;
      signed int mean2_52_0 = clap_481_0 - mean2_51_0;
      signed int lambda_isp_oldlua_line258_4_0 = lambda_isp_oldlua_line1269_781_0 + mean2_52_0;
      signed int lambda_isp_oldlua_line468_174_pack_1 = lambda_isp_oldlua_line258_4_0;
      signed int lambda_isp_oldlua_line468_172_pack_1 = lambda_isp_oldlua_line258_4_0;
      signed int lambda_isp_oldlua_line260_4_0 = lambda_isp_oldlua_line1269_782_0 + mean2_52_0;
      signed int lambda_isp_oldlua_line468_176_pack_1 = lambda_isp_oldlua_line260_4_0;
      signed int lambda_isp_oldlua_line468_178_pack_1 = lambda_isp_oldlua_line260_4_0;
      // max lambda_isp_oldlua_line468_174_0 <= (lambda_isp_oldlua_line468_174_pack_1 , lambda_isp_oldlua_line468_174_pack_0)
      signed int lambda_isp_oldlua_line468_174_0_cotmp_1 = (lambda_isp_oldlua_line468_174_pack_1 > lambda_isp_oldlua_line468_174_pack_0) ? lambda_isp_oldlua_line468_174_pack_1 : lambda_isp_oldlua_line468_174_pack_0;
      signed int lambda_isp_oldlua_line468_174_0 = lambda_isp_oldlua_line468_174_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_175_pack_0 = lambda_isp_oldlua_line468_174_0;
      // max lambda_isp_oldlua_line468_175_0 <= (lambda_isp_oldlua_line468_175_pack_1 , lambda_isp_oldlua_line468_175_pack_0)
      signed int lambda_isp_oldlua_line468_175_0_cotmp_1 = (lambda_isp_oldlua_line468_175_pack_1 > lambda_isp_oldlua_line468_175_pack_0) ? lambda_isp_oldlua_line468_175_pack_1 : lambda_isp_oldlua_line468_175_pack_0;
      signed int lambda_isp_oldlua_line468_175_0 = lambda_isp_oldlua_line468_175_0_cotmp_1;

      // min lambda_isp_oldlua_line468_172_0 <= (lambda_isp_oldlua_line468_172_pack_1 , lambda_isp_oldlua_line468_172_pack_0)
      signed int lambda_isp_oldlua_line468_172_0_cotmp_1 = (lambda_isp_oldlua_line468_172_pack_1 < lambda_isp_oldlua_line468_172_pack_0) ? lambda_isp_oldlua_line468_172_pack_1 : lambda_isp_oldlua_line468_172_pack_0;
      signed int lambda_isp_oldlua_line468_172_0 = lambda_isp_oldlua_line468_172_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_173_pack_0 = lambda_isp_oldlua_line468_172_0;
      signed int lambda_isp_oldlua_line468_178_pack_0 = lambda_isp_oldlua_line468_175_0;
      // max lambda_isp_oldlua_line468_178_0 <= (lambda_isp_oldlua_line468_178_pack_1 , lambda_isp_oldlua_line468_178_pack_0)
      signed int lambda_isp_oldlua_line468_178_0_cotmp_1 = (lambda_isp_oldlua_line468_178_pack_1 > lambda_isp_oldlua_line468_178_pack_0) ? lambda_isp_oldlua_line468_178_pack_1 : lambda_isp_oldlua_line468_178_pack_0;
      signed int lambda_isp_oldlua_line468_178_0 = lambda_isp_oldlua_line468_178_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_179_pack_1 = lambda_isp_oldlua_line468_178_0;
      // max lambda_isp_oldlua_line468_179_0 <= (lambda_isp_oldlua_line468_179_pack_1 , lambda_isp_oldlua_line468_179_pack_0)
      signed int lambda_isp_oldlua_line468_179_0_cotmp_1 = (lambda_isp_oldlua_line468_179_pack_1 > lambda_isp_oldlua_line468_179_pack_0) ? lambda_isp_oldlua_line468_179_pack_1 : lambda_isp_oldlua_line468_179_pack_0;
      signed int lambda_isp_oldlua_line468_179_0 = lambda_isp_oldlua_line468_179_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_194_pack_1 = lambda_isp_oldlua_line468_179_0;
      // min lambda_isp_oldlua_line468_173_0 <= (lambda_isp_oldlua_line468_173_pack_1 , lambda_isp_oldlua_line468_173_pack_0)
      signed int lambda_isp_oldlua_line468_173_0_cotmp_1 = (lambda_isp_oldlua_line468_173_pack_1 < lambda_isp_oldlua_line468_173_pack_0) ? lambda_isp_oldlua_line468_173_pack_1 : lambda_isp_oldlua_line468_173_pack_0;
      signed int lambda_isp_oldlua_line468_173_0 = lambda_isp_oldlua_line468_173_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_176_pack_0 = lambda_isp_oldlua_line468_173_0;
      // min lambda_isp_oldlua_line468_176_0 <= (lambda_isp_oldlua_line468_176_pack_1 , lambda_isp_oldlua_line468_176_pack_0)
      signed int lambda_isp_oldlua_line468_176_0_cotmp_1 = (lambda_isp_oldlua_line468_176_pack_1 < lambda_isp_oldlua_line468_176_pack_0) ? lambda_isp_oldlua_line468_176_pack_1 : lambda_isp_oldlua_line468_176_pack_0;
      signed int lambda_isp_oldlua_line468_176_0 = lambda_isp_oldlua_line468_176_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_177_pack_1 = lambda_isp_oldlua_line468_176_0;
      // min lambda_isp_oldlua_line468_177_0 <= (lambda_isp_oldlua_line468_177_pack_1 , lambda_isp_oldlua_line468_177_pack_0)
      signed int lambda_isp_oldlua_line468_177_0_cotmp_1 = (lambda_isp_oldlua_line468_177_pack_1 < lambda_isp_oldlua_line468_177_pack_0) ? lambda_isp_oldlua_line468_177_pack_1 : lambda_isp_oldlua_line468_177_pack_0;
      signed int lambda_isp_oldlua_line468_177_0 = lambda_isp_oldlua_line468_177_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_188_pack_1 = lambda_isp_oldlua_line468_177_0;
      signed int lambda_isp_oldlua_line468_180_0 = lambda_isp_oldlua_line468_179_0 - lambda_isp_oldlua_line468_177_0;
      signed int lambda_isp_oldlua_line468_181_0 = lambda_isp_oldlua_line1240_345_0 * lambda_isp_oldlua_line468_180_0;
      signed int lambda_isp_oldlua_line468_182_0 = lambda_isp_oldlua_line468_181_0 >> offY_4176_0;
      signed int lambda_isp_oldlua_line468_183_0 = lambda_isp_oldlua_line468_65_0 + lambda_isp_oldlua_line468_182_0;
      signed int lambda_isp_oldlua_line468_184_0 = lambda_isp_oldlua_line468_177_0 - lambda_isp_oldlua_line468_183_0;
      signed int lambda_isp_oldlua_line468_186_0 = lambda_isp_oldlua_line468_184_0 << lambda_isp_oldlua_line1240_343_0;
      signed int lambda_isp_oldlua_line468_187_0 = lambda_isp_oldlua_line468_186_0 - lambda_isp_oldlua_line256_4_0;
      signed int lambda_isp_oldlua_line468_188_pack_0 = lambda_isp_oldlua_line468_187_0;
      // min lambda_isp_oldlua_line468_188_0 <= (lambda_isp_oldlua_line468_188_pack_1 , lambda_isp_oldlua_line468_188_pack_0)
      signed int lambda_isp_oldlua_line468_188_0_cotmp_1 = (lambda_isp_oldlua_line468_188_pack_1 < lambda_isp_oldlua_line468_188_pack_0) ? lambda_isp_oldlua_line468_188_pack_1 : lambda_isp_oldlua_line468_188_pack_0;
      signed int lambda_isp_oldlua_line468_188_0 = lambda_isp_oldlua_line468_188_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_190_0 = lambda_isp_oldlua_line468_179_0 + lambda_isp_oldlua_line468_183_0;
      signed int lambda_isp_oldlua_line468_192_0 = lambda_isp_oldlua_line468_190_0 << lambda_isp_oldlua_line1240_343_0;
      signed int lambda_isp_oldlua_line468_193_0 = lambda_isp_oldlua_line468_192_0 - lambda_isp_oldlua_line256_4_0;
      signed int lambda_isp_oldlua_line468_194_pack_0 = lambda_isp_oldlua_line468_193_0;
      // max lambda_isp_oldlua_line468_194_0 <= (lambda_isp_oldlua_line468_194_pack_1 , lambda_isp_oldlua_line468_194_pack_0)
      signed int lambda_isp_oldlua_line468_194_0_cotmp_1 = (lambda_isp_oldlua_line468_194_pack_1 > lambda_isp_oldlua_line468_194_pack_0) ? lambda_isp_oldlua_line468_194_pack_1 : lambda_isp_oldlua_line468_194_pack_0;
      signed int lambda_isp_oldlua_line468_194_0 = lambda_isp_oldlua_line468_194_0_cotmp_1;

      bool lambda_isp_oldlua_line468_191_0 = lambda_isp_oldlua_line256_4_0 > lambda_isp_oldlua_line468_190_0;
      bool lambda_isp_oldlua_line468_185_0 = lambda_isp_oldlua_line256_4_0 < lambda_isp_oldlua_line468_184_0;
      signed int lambda_isp_oldlua_line468_189_0 = lambda_isp_oldlua_line468_185_0 ? lambda_isp_oldlua_line468_188_0 : lambda_isp_oldlua_line256_4_0;
      signed int lambda_isp_oldlua_line468_195_0 = lambda_isp_oldlua_line468_191_0 ? lambda_isp_oldlua_line468_194_0 : lambda_isp_oldlua_line468_189_0;
      signed int lambda_isp_oldlua_line468_196_0 = lambda_isp_oldlua_line468_195_0 - lambda_isp_oldlua_line256_4_0;
      bool lambda_isp_oldlua_line224_17_0 = lambda_isp_oldlua_line468_196_0 < clap_482_0;
      signed int lambda_isp_oldlua_line468_197_pack_1 = lambda_isp_oldlua_line468_196_0;
      // min lambda_isp_oldlua_line468_197_0 <= (lambda_isp_oldlua_line468_197_pack_1 , lambda_isp_oldlua_line468_197_pack_0)
      signed int lambda_isp_oldlua_line468_197_0_cotmp_1 = (lambda_isp_oldlua_line468_197_pack_1 < lambda_isp_oldlua_line468_197_pack_0) ? lambda_isp_oldlua_line468_197_pack_1 : lambda_isp_oldlua_line468_197_pack_0;
      signed int lambda_isp_oldlua_line468_197_0 = lambda_isp_oldlua_line468_197_0_cotmp_1;

      signed int lambda_isp_oldlua_line224_18_0 = lambda_isp_oldlua_line224_17_0 ? lambda_isp_oldlua_line224_6_0 : lambda_isp_oldlua_line1240_343_0;
      signed int lambda_isp_oldlua_line468_198_pack_1 = lambda_isp_oldlua_line468_196_0;
      // max lambda_isp_oldlua_line468_198_0 <= (lambda_isp_oldlua_line468_198_pack_1 , lambda_isp_oldlua_line468_198_pack_0)
      signed int lambda_isp_oldlua_line468_198_0_cotmp_1 = (lambda_isp_oldlua_line468_198_pack_1 > lambda_isp_oldlua_line468_198_pack_0) ? lambda_isp_oldlua_line468_198_pack_1 : lambda_isp_oldlua_line468_198_pack_0;
      signed int lambda_isp_oldlua_line468_198_0 = lambda_isp_oldlua_line468_198_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_199_0 = lambda_isp_oldlua_line468_171_0 ? lambda_isp_oldlua_line468_198_0 : lambda_isp_oldlua_line468_197_0;
      signed int lambda_isp_oldlua_line468_202_0 = lambda_isp_oldlua_line394_356_0 + lambda_isp_oldlua_line468_196_0;
      signed int lambda_isp_oldlua_line468_200_0 = lambda_isp_oldlua_line224_16_0 * lambda_isp_oldlua_line224_18_0;
      bool lambda_isp_oldlua_line468_201_0 = lambda_isp_oldlua_line468_200_0 != lambda_isp_oldlua_line1240_343_0;
      signed int lambda_isp_oldlua_line468_203_0 = lambda_isp_oldlua_line468_201_0 ? lambda_isp_oldlua_line468_202_0 : lambda_isp_oldlua_line468_199_0;
      signed int lambda_isp_oldlua_line468_204_0 = lambda_isp_oldlua_line468_156_0 + lambda_isp_oldlua_line468_203_0;
      signed int lambda_isp_oldlua_line468_205_pack_0 = lambda_isp_oldlua_line468_204_0;
      // max lambda_isp_oldlua_line468_205_0 <= (lambda_isp_oldlua_line468_205_pack_1 , lambda_isp_oldlua_line468_205_pack_0)
      signed int lambda_isp_oldlua_line468_205_0_cotmp_1 = (lambda_isp_oldlua_line468_205_pack_1 > lambda_isp_oldlua_line468_205_pack_0) ? lambda_isp_oldlua_line468_205_pack_1 : lambda_isp_oldlua_line468_205_pack_0;
      signed int lambda_isp_oldlua_line468_205_0 = lambda_isp_oldlua_line468_205_0_cotmp_1;

      signed int lambda_isp_oldlua_line468_206_pack_0 = lambda_isp_oldlua_line468_205_0;
      // min lambda_isp_oldlua_line468_206_0 <= (lambda_isp_oldlua_line468_206_pack_1 , lambda_isp_oldlua_line468_206_pack_0)
      signed int lambda_isp_oldlua_line468_206_0_cotmp_1 = (lambda_isp_oldlua_line468_206_pack_1 < lambda_isp_oldlua_line468_206_pack_0) ? lambda_isp_oldlua_line468_206_pack_1 : lambda_isp_oldlua_line468_206_pack_0;
      signed int lambda_isp_oldlua_line468_206_0 = lambda_isp_oldlua_line468_206_0_cotmp_1;

      signed int clap_487_pack_0 = lambda_isp_oldlua_line468_206_0;
      // max clap_487_0 <= (clap_487_pack_1 , clap_487_pack_0)
      signed int clap_487_0_cotmp_1 = (clap_487_pack_1 > clap_487_pack_0) ? clap_487_pack_1 : clap_487_pack_0;
      signed int clap_487_0 = clap_487_0_cotmp_1;

      signed int clap_488_pack_0 = clap_487_0;
      // min clap_488_0 <= (clap_488_pack_1 , clap_488_pack_0)
      signed int clap_488_0_cotmp_1 = (clap_488_pack_1 < clap_488_pack_0) ? clap_488_pack_1 : clap_488_pack_0;
      signed int clap_488_0 = clap_488_0_cotmp_1;

      unsigned int lambda_isp_oldlua_line1282_805_0 = clap_488_0;
      out(x,y,0) = lambda_isp_oldlua_line1282_805_0;
    }
  }
} // END lambda_isp_oldlua_line1282_35


void lambda_isp_oldlua_line1282_37(const Image<int>& in, Image<int>& out
)
{
  for(int y = 0; y < in.height(); y++){
    for(int x = 0; x < in.width(); x++){
      unsigned int lambda_isp_oldlua_line1282_805_pp_4_4 = in(x+2, y+2, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_4_3 = in(x+2, y+1, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_4_2 = in(x+2, y+0, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_4_1 = in(x+2, y+-1, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_4_0 = in(x+2, y+-2, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_3_4 = in(x+1, y+2, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_3_3 = in(x+1, y+1, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_3_2 = in(x+1, y+0, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_3_1 = in(x+1, y+-1, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_3_0 = in(x+1, y+-2, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_2_4 = in(x+0, y+2, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_2_3 = in(x+0, y+1, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_2_2 = in(x+0, y+0, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_2_1 = in(x+0, y+-1, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_2_0 = in(x+0, y+-2, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_1_4 = in(x+-1, y+2, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_1_3 = in(x+-1, y+1, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_1_2 = in(x+-1, y+0, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_1_1 = in(x+-1, y+-1, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_1_0 = in(x+-1, y+-2, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_0_4 = in(x+-2, y+2, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_0_3 = in(x+-2, y+1, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_0_2 = in(x+-2, y+0, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_0_1 = in(x+-2, y+-1, 0);
      unsigned int lambda_isp_oldlua_line1282_805_pp_0_0 = in(x+-2, y+-2, 0);
      const float c_2_0 = 2;
      const float c_1_0 = 1;
      const float c_4_0 = 4;
      const float c_14_0 = 14;
      const float c_7_0 = 7;
      const float c_64_0 = 64;
      const float c_10_0 = 10;
      const float c_0_0 = 0;
      const float c_719_0 = 719;
      const float c_n4_0 = -4;
      const float c_3_0 = 3;
      const float c_344_0 = 344;
      const float c_34_0 = 34;
      const float c_1023_0 = 1023;
      const float c_512_0 = 512;
      const float c_9_0 = 9;
      
      int centroid_pos_0 = x;
      int centroid_pos_1 = y;
      signed int offY_4178_0 = c_4_0;
      signed int lambda_isp_oldlua_line1269_821_0 = lambda_isp_oldlua_line1282_805_pp_3_3;
      signed int lambda_isp_oldlua_line627_119_pack_1 = lambda_isp_oldlua_line1269_821_0;
      signed int lambda_isp_oldlua_line1269_831_0 = lambda_isp_oldlua_line1282_805_pp_0_4;
      signed int lambda_isp_oldlua_line627_122_pack_0 = lambda_isp_oldlua_line1269_831_0;
      signed int lambda_isp_oldlua_line1269_828_0 = lambda_isp_oldlua_line1282_805_pp_0_2;
      signed int lambda_isp_oldlua_line627_122_pack_3 = lambda_isp_oldlua_line1269_828_0;
      signed int clap_489_0 = c_0_0;
      signed int lambda_isp_oldlua_line1269_826_0 = lambda_isp_oldlua_line1282_805_pp_2_4;
      signed int lambda_isp_oldlua_line502_79_0 = c_512_0;
      signed int lambda_isp_oldlua_line1329_1341_0 = c_719_0;
      signed int lambda_isp_oldlua_line627_56_0 = c_14_0;
      signed int lambda_isp_oldlua_line627_58_0 = c_7_0;
      signed int lambda_isp_oldlua_line1269_823_0 = lambda_isp_oldlua_line1282_805_pp_3_1;
      signed int lambda_isp_oldlua_line1329_1342_0 = lambda_isp_oldlua_line1329_1341_0 - centroid_pos_1;
      signed int lambda_isp_oldlua_line627_122_pack_1 = lambda_isp_oldlua_line1269_826_0;
      signed int lambda_isp_oldlua_line1269_820_0 = lambda_isp_oldlua_line1282_805_pp_2_2;
      signed int lambda_isp_oldlua_line627_122_pack_4 = lambda_isp_oldlua_line1269_820_0;
      signed int lambda_isp_oldlua_line627_122_pack_9 = offY_4178_0;
      signed int lambda_isp_oldlua_line627_154_pack_1 = clap_489_0;
      signed int lambda_isp_oldlua_line627_62_0 = c_64_0;
      signed int lambda_isp_oldlua_line1269_824_0 = lambda_isp_oldlua_line1282_805_pp_1_3;
      signed int lambda_isp_oldlua_line627_119_pack_0 = lambda_isp_oldlua_line1269_824_0;
      signed int lambda_isp_oldlua_line1240_346_0 = c_2_0;
      bool offY_4179_0 = lambda_isp_oldlua_line1240_346_0 == offY_4178_0;
      signed int lambda_isp_oldlua_line627_119_pack_4 = lambda_isp_oldlua_line1240_346_0;
      bool offY_4184_0 = lambda_isp_oldlua_line1240_346_0 == lambda_isp_oldlua_line1240_346_0;
      signed int clap_490_0 = c_1023_0;
      signed int clap_506_pack_1 = clap_490_0;
      signed int clap_504_pack_1 = clap_490_0;
      signed int lambda_isp_oldlua_line1329_1343_0 = c_4_0;
      signed int lambda_isp_oldlua_line627_119_pack_3 = lambda_isp_oldlua_line1269_823_0;
      signed int lambda_isp_oldlua_line1329_1336_0 = c_n4_0;
      signed int offX_2267_0 = c_34_0;
      signed int lambda_isp_oldlua_line1329_1344_0 = lambda_isp_oldlua_line1329_1342_0 + lambda_isp_oldlua_line1329_1343_0;
      signed int lambda_isp_oldlua_line627_155_pack_1 = clap_490_0;
      signed int lambda_isp_oldlua_line1329_1346_0 = c_4_0;
      signed int offY_4188_0 = c_344_0;
      signed int lambda_isp_oldlua_line1240_347_0 = c_1_0;
      signed int lambda_isp_oldlua_line627_125_pack_2 = lambda_isp_oldlua_line1240_347_0;
      signed int lambda_isp_oldlua_line627_127_pack_2 = lambda_isp_oldlua_line1240_347_0;
      bool offY_4186_0 = lambda_isp_oldlua_line1240_346_0 == lambda_isp_oldlua_line1240_347_0;
      signed int lambda_isp_oldlua_line1329_1345_0 = lambda_isp_oldlua_line1329_1344_0 + lambda_isp_oldlua_line1329_1336_0;
      signed int lambda_isp_oldlua_line881_101_0 = c_10_0;
      signed int lambda_isp_oldlua_line502_88_0 = c_9_0;
      signed int lambda_isp_oldlua_line1269_822_0 = lambda_isp_oldlua_line1282_805_pp_1_1;
      signed int lambda_isp_oldlua_line627_119_pack_2 = lambda_isp_oldlua_line1269_822_0;
      signed int lambda_isp_oldlua_line502_114_pack_1 = clap_490_0;
      signed int offX_2263_0 = offY_4179_0 ? clap_489_0 : lambda_isp_oldlua_line1240_346_0;
      signed int lambda_isp_oldlua_line1269_830_0 = lambda_isp_oldlua_line1282_805_pp_0_0;
      signed int lambda_isp_oldlua_line627_63_0 = lambda_isp_oldlua_line627_62_0 - lambda_isp_oldlua_line627_62_0;
      signed int lambda_isp_oldlua_line1269_832_0 = lambda_isp_oldlua_line1282_805_pp_2_0;
      signed int lambda_isp_oldlua_line627_122_pack_7 = lambda_isp_oldlua_line1269_832_0;
      signed int lambda_isp_oldlua_line627_119_0 = lambda_isp_oldlua_line627_119_pack_4 + lambda_isp_oldlua_line627_119_pack_3 + lambda_isp_oldlua_line627_119_pack_2 + lambda_isp_oldlua_line627_119_pack_1 + lambda_isp_oldlua_line627_119_pack_0;
      signed int lambda_isp_oldlua_line627_120_0 = lambda_isp_oldlua_line627_119_0 >> lambda_isp_oldlua_line1240_346_0;
      signed int lambda_isp_oldlua_line627_121_0 = -lambda_isp_oldlua_line627_120_0;
      signed int lambda_isp_oldlua_line627_127_pack_1 = lambda_isp_oldlua_line627_120_0;
      signed int lambda_isp_oldlua_line627_125_pack_1 = lambda_isp_oldlua_line627_121_0;
      signed int lambda_isp_oldlua_line1269_827_0 = lambda_isp_oldlua_line1282_805_pp_4_4;
      signed int lambda_isp_oldlua_line1329_1339_0 = c_n4_0;
      signed int offY_4181_0 = c_3_0;
      bool offY_4182_0 = lambda_isp_oldlua_line1240_346_0 == offY_4181_0;
      signed int offX_2264_0 = offY_4182_0 ? lambda_isp_oldlua_line1240_347_0 : offX_2263_0;
      signed int lambda_isp_oldlua_line1269_829_0 = lambda_isp_oldlua_line1282_805_pp_4_2;
      signed int lambda_isp_oldlua_line627_122_pack_5 = lambda_isp_oldlua_line1269_829_0;
      signed int lambda_isp_oldlua_line1269_825_0 = lambda_isp_oldlua_line1282_805_pp_4_0;
      signed int lambda_isp_oldlua_line627_122_pack_8 = lambda_isp_oldlua_line1269_825_0;
      signed int lambda_isp_oldlua_line627_122_pack_2 = lambda_isp_oldlua_line1269_827_0;
      signed int offX_2265_0 = offY_4184_0 ? lambda_isp_oldlua_line1240_347_0 : offX_2264_0;
      signed int offX_2266_0 = offY_4186_0 ? clap_489_0 : offX_2265_0;
      bool offX_2268_0 = offX_2266_0 != lambda_isp_oldlua_line1240_346_0;
      signed int lambda_isp_oldlua_line1329_1347_0 = centroid_pos_0 + lambda_isp_oldlua_line1329_1346_0;
      signed int lambda_isp_oldlua_line1329_1348_0 = lambda_isp_oldlua_line1329_1347_0 + lambda_isp_oldlua_line1329_1339_0;
      signed int grPix_3921_0 = lambda_isp_oldlua_line1329_1348_0 + offX_2266_0;
      signed int grPix_3922_0 = grPix_3921_0 & lambda_isp_oldlua_line1240_347_0;
      bool grPix_3923_0 = grPix_3922_0 != clap_489_0;
      bool grPix_3924_0 = !grPix_3923_0;
      signed int clap_505_pack_1 = clap_489_0;
      signed int clap_503_pack_1 = clap_489_0;
      signed int offY_4180_0 = offY_4179_0 ? lambda_isp_oldlua_line1240_347_0 : lambda_isp_oldlua_line1240_346_0;
      signed int offY_4183_0 = offY_4182_0 ? clap_489_0 : offY_4180_0;
      signed int offY_4185_0 = offY_4184_0 ? lambda_isp_oldlua_line1240_347_0 : offY_4183_0;
      signed int offY_4187_0 = offY_4186_0 ? clap_489_0 : offY_4185_0;
      signed int grPix_3917_0 = lambda_isp_oldlua_line1329_1345_0 + offY_4187_0;
      bool offY_4189_0 = offY_4187_0 != lambda_isp_oldlua_line1240_346_0;
      signed int grPix_3918_0 = grPix_3917_0 & lambda_isp_oldlua_line1240_347_0;
      bool grPix_3919_0 = grPix_3918_0 != clap_489_0;
      bool gbPix_829_0 = grPix_3919_0 & grPix_3923_0;
      bool grPix_3920_0 = !grPix_3919_0;
      bool bPix_19_0 = grPix_3919_0 & grPix_3924_0;
      bool grPix_3925_0 = grPix_3920_0 & grPix_3924_0;
      signed int grPix_3926_0 = grPix_3925_0 ? lambda_isp_oldlua_line1240_347_0 : clap_489_0;
      bool lambda_isp_oldlua_line627_149_0 = grPix_3926_0 == clap_489_0;
      signed int gbPix_830_0 = gbPix_829_0 ? lambda_isp_oldlua_line1240_347_0 : clap_489_0;
      bool lambda_isp_oldlua_line627_150_0 = gbPix_830_0 == clap_489_0;
      bool rPix_829_0 = grPix_3920_0 & grPix_3923_0;
      signed int rPix_830_0 = rPix_829_0 ? lambda_isp_oldlua_line1240_347_0 : clap_489_0;
      signed int lambda_isp_oldlua_line502_102_0 = grPix_3926_0 * lambda_isp_oldlua_line502_79_0;
      signed int bPix_20_0 = bPix_19_0 ? lambda_isp_oldlua_line1240_347_0 : clap_489_0;
      signed int lambda_isp_oldlua_line502_104_0 = gbPix_830_0 * lambda_isp_oldlua_line502_79_0;
      signed int lambda_isp_oldlua_line502_103_0 = bPix_20_0 * lambda_isp_oldlua_line502_79_0;
      signed int lambda_isp_oldlua_line502_105_0 = rPix_830_0 * lambda_isp_oldlua_line502_79_0;
      signed int lambda_isp_oldlua_line502_106_0 = lambda_isp_oldlua_line502_102_0 + lambda_isp_oldlua_line502_105_0;
      signed int lambda_isp_oldlua_line502_107_0 = lambda_isp_oldlua_line502_106_0 + lambda_isp_oldlua_line502_103_0;
      signed int lambda_isp_oldlua_line502_108_0 = lambda_isp_oldlua_line502_107_0 + lambda_isp_oldlua_line502_104_0;
      signed int lambda_isp_oldlua_line502_109_0 = lambda_isp_oldlua_line502_108_0 * lambda_isp_oldlua_line502_79_0;
      signed int lambda_isp_oldlua_line502_110_0 = lambda_isp_oldlua_line502_109_0 >> lambda_isp_oldlua_line502_88_0;
      bool lambda_isp_oldlua_line627_151_0 = lambda_isp_oldlua_line627_149_0 & lambda_isp_oldlua_line627_150_0;
      signed int lambda_isp_oldlua_line502_113_pack_1 = clap_489_0;
      signed int lambda_isp_oldlua_line627_122_pack_6 = lambda_isp_oldlua_line1269_830_0;
      signed int lambda_isp_oldlua_line627_122_0 = lambda_isp_oldlua_line627_122_pack_9 + lambda_isp_oldlua_line627_122_pack_8 + lambda_isp_oldlua_line627_122_pack_7 + lambda_isp_oldlua_line627_122_pack_6 + lambda_isp_oldlua_line627_122_pack_5 + lambda_isp_oldlua_line627_122_pack_4 + lambda_isp_oldlua_line627_122_pack_3 + lambda_isp_oldlua_line627_122_pack_2 + lambda_isp_oldlua_line627_122_pack_1 + lambda_isp_oldlua_line627_122_pack_0;
      signed int lambda_isp_oldlua_line627_123_0 = lambda_isp_oldlua_line627_122_0 * lambda_isp_oldlua_line627_56_0;
      signed int lambda_isp_oldlua_line627_124_0 = lambda_isp_oldlua_line627_123_0 >> lambda_isp_oldlua_line627_58_0;
      signed int lambda_isp_oldlua_line627_127_pack_0 = lambda_isp_oldlua_line627_124_0;
      signed int lambda_isp_oldlua_line627_127_0 = lambda_isp_oldlua_line627_127_pack_2 + lambda_isp_oldlua_line627_127_pack_1 + lambda_isp_oldlua_line627_127_pack_0;
      signed int lambda_isp_oldlua_line627_125_pack_0 = lambda_isp_oldlua_line627_124_0;
      signed int lambda_isp_oldlua_line627_125_0 = lambda_isp_oldlua_line627_125_pack_2 + lambda_isp_oldlua_line627_125_pack_1 + lambda_isp_oldlua_line627_125_pack_0;
      signed int lambda_isp_oldlua_line627_126_0 = lambda_isp_oldlua_line627_125_0 >> lambda_isp_oldlua_line1240_347_0;
      signed int lambda_isp_oldlua_line627_128_0 = lambda_isp_oldlua_line627_127_0 >> lambda_isp_oldlua_line1240_347_0;
      signed int lambda_isp_oldlua_line627_129_0 = lambda_isp_oldlua_line627_63_0 * lambda_isp_oldlua_line627_128_0;
      signed int lambda_isp_oldlua_line627_130_0 = lambda_isp_oldlua_line627_129_0 >> lambda_isp_oldlua_line881_101_0;
      signed int lambda_isp_oldlua_line627_131_0 = lambda_isp_oldlua_line627_62_0 + lambda_isp_oldlua_line627_130_0;
      signed int lambda_isp_oldlua_line627_142_0 = -lambda_isp_oldlua_line627_131_0;
      signed int lambda_isp_oldlua_line627_133_0 = lambda_isp_oldlua_line627_131_0 << lambda_isp_oldlua_line1240_347_0;
      bool lambda_isp_oldlua_line627_135_0 = lambda_isp_oldlua_line627_126_0 > lambda_isp_oldlua_line627_133_0;
      signed int lambda_isp_oldlua_line627_138_0 = -lambda_isp_oldlua_line627_133_0;
      bool lambda_isp_oldlua_line627_132_0 = lambda_isp_oldlua_line627_126_0 > lambda_isp_oldlua_line627_131_0;
      signed int lambda_isp_oldlua_line627_134_0 = lambda_isp_oldlua_line627_133_0 - lambda_isp_oldlua_line627_126_0;
      signed int lambda_isp_oldlua_line627_136_0 = lambda_isp_oldlua_line627_135_0 ? clap_489_0 : lambda_isp_oldlua_line627_134_0;
      signed int lambda_isp_oldlua_line627_137_0 = lambda_isp_oldlua_line627_132_0 ? lambda_isp_oldlua_line627_136_0 : lambda_isp_oldlua_line627_126_0;
      bool lambda_isp_oldlua_line627_140_0 = lambda_isp_oldlua_line627_137_0 < lambda_isp_oldlua_line627_138_0;
      signed int lambda_isp_oldlua_line627_139_0 = lambda_isp_oldlua_line627_138_0 - lambda_isp_oldlua_line627_137_0;
      signed int lambda_isp_oldlua_line627_141_0 = lambda_isp_oldlua_line627_140_0 ? clap_489_0 : lambda_isp_oldlua_line627_139_0;
      bool lambda_isp_oldlua_line627_143_0 = lambda_isp_oldlua_line627_137_0 < lambda_isp_oldlua_line627_142_0;
      signed int lambda_isp_oldlua_line627_144_0 = lambda_isp_oldlua_line627_143_0 ? lambda_isp_oldlua_line627_141_0 : lambda_isp_oldlua_line627_137_0;
      signed int lambda_isp_oldlua_line627_152_0 = lambda_isp_oldlua_line627_151_0 ? clap_489_0 : lambda_isp_oldlua_line627_144_0;
      signed int lambda_isp_oldlua_line627_153_0 = lambda_isp_oldlua_line1269_820_0 - lambda_isp_oldlua_line627_152_0;
      signed int lambda_isp_oldlua_line627_154_pack_0 = lambda_isp_oldlua_line627_153_0;
      // max lambda_isp_oldlua_line627_154_0 <= (lambda_isp_oldlua_line627_154_pack_1 , lambda_isp_oldlua_line627_154_pack_0)
      signed int lambda_isp_oldlua_line627_154_0_cotmp_1 = (lambda_isp_oldlua_line627_154_pack_1 > lambda_isp_oldlua_line627_154_pack_0) ? lambda_isp_oldlua_line627_154_pack_1 : lambda_isp_oldlua_line627_154_pack_0;
      signed int lambda_isp_oldlua_line627_154_0 = lambda_isp_oldlua_line627_154_0_cotmp_1;

      signed int lambda_isp_oldlua_line627_155_pack_0 = lambda_isp_oldlua_line627_154_0;
      // min lambda_isp_oldlua_line627_155_0 <= (lambda_isp_oldlua_line627_155_pack_1 , lambda_isp_oldlua_line627_155_pack_0)
      signed int lambda_isp_oldlua_line627_155_0_cotmp_1 = (lambda_isp_oldlua_line627_155_pack_1 < lambda_isp_oldlua_line627_155_pack_0) ? lambda_isp_oldlua_line627_155_pack_1 : lambda_isp_oldlua_line627_155_pack_0;
      signed int lambda_isp_oldlua_line627_155_0 = lambda_isp_oldlua_line627_155_0_cotmp_1;

      signed int clap_503_pack_0 = lambda_isp_oldlua_line627_155_0;
      // max clap_503_0 <= (clap_503_pack_1 , clap_503_pack_0)
      signed int clap_503_0_cotmp_1 = (clap_503_pack_1 > clap_503_pack_0) ? clap_503_pack_1 : clap_503_pack_0;
      signed int clap_503_0 = clap_503_0_cotmp_1;

      signed int clap_504_pack_0 = clap_503_0;
      // min clap_504_0 <= (clap_504_pack_1 , clap_504_pack_0)
      signed int clap_504_0_cotmp_1 = (clap_504_pack_1 < clap_504_pack_0) ? clap_504_pack_1 : clap_504_pack_0;
      signed int clap_504_0 = clap_504_0_cotmp_1;

      unsigned int lambda_isp_oldlua_line1285_7_0 = clap_504_0;
      signed int lambda_isp_oldlua_line1269_834_0 = lambda_isp_oldlua_line1285_7_0;
      signed int lambda_isp_oldlua_line502_111_0 = lambda_isp_oldlua_line1269_834_0 * lambda_isp_oldlua_line502_110_0;
      signed int lambda_isp_oldlua_line502_112_0 = lambda_isp_oldlua_line502_111_0 >> lambda_isp_oldlua_line502_88_0;
      signed int lambda_isp_oldlua_line502_113_pack_0 = lambda_isp_oldlua_line502_112_0;
      // max lambda_isp_oldlua_line502_113_0 <= (lambda_isp_oldlua_line502_113_pack_1 , lambda_isp_oldlua_line502_113_pack_0)
      signed int lambda_isp_oldlua_line502_113_0_cotmp_1 = (lambda_isp_oldlua_line502_113_pack_1 > lambda_isp_oldlua_line502_113_pack_0) ? lambda_isp_oldlua_line502_113_pack_1 : lambda_isp_oldlua_line502_113_pack_0;
      signed int lambda_isp_oldlua_line502_113_0 = lambda_isp_oldlua_line502_113_0_cotmp_1;

      signed int lambda_isp_oldlua_line502_114_pack_0 = lambda_isp_oldlua_line502_113_0;
      // min lambda_isp_oldlua_line502_114_0 <= (lambda_isp_oldlua_line502_114_pack_1 , lambda_isp_oldlua_line502_114_pack_0)
      signed int lambda_isp_oldlua_line502_114_0_cotmp_1 = (lambda_isp_oldlua_line502_114_pack_1 < lambda_isp_oldlua_line502_114_pack_0) ? lambda_isp_oldlua_line502_114_pack_1 : lambda_isp_oldlua_line502_114_pack_0;
      signed int lambda_isp_oldlua_line502_114_0 = lambda_isp_oldlua_line502_114_0_cotmp_1;

      signed int clap_505_pack_0 = lambda_isp_oldlua_line502_114_0;
      // max clap_505_0 <= (clap_505_pack_1 , clap_505_pack_0)
      signed int clap_505_0_cotmp_1 = (clap_505_pack_1 > clap_505_pack_0) ? clap_505_pack_1 : clap_505_pack_0;
      signed int clap_505_0 = clap_505_0_cotmp_1;

      signed int clap_506_pack_0 = clap_505_0;
      // min clap_506_0 <= (clap_506_pack_1 , clap_506_pack_0)
      signed int clap_506_0_cotmp_1 = (clap_506_pack_1 < clap_506_pack_0) ? clap_506_pack_1 : clap_506_pack_0;
      signed int clap_506_0 = clap_506_0_cotmp_1;

      unsigned int lambda_isp_oldlua_line1282_848_0 = clap_506_0;
      out(x,y,0) = lambda_isp_oldlua_line1282_848_0;
    }
  }
} // END lambda_isp_oldlua_line1282_37


void lambda_isp_oldlua_line1329_18(const Image<int>& in, Image<int>& out
)
{
  for(int y = 0; y < in.height(); y++){
    for(int x = 0; x < in.width(); x++){
      unsigned int lambda_isp_oldlua_line1274_169_pp_2_2_2 = in(x+1, y+1, 2);
      unsigned int lambda_isp_oldlua_line1274_169_pp_2_2_1 = in(x+1, y+1, 1);
      unsigned int lambda_isp_oldlua_line1274_169_pp_2_2_0 = in(x+1, y+1, 0);
      unsigned int lambda_isp_oldlua_line1274_169_pp_2_1_2 = in(x+1, y+0, 2);
      unsigned int lambda_isp_oldlua_line1274_169_pp_2_1_1 = in(x+1, y+0, 1);
      unsigned int lambda_isp_oldlua_line1274_169_pp_2_1_0 = in(x+1, y+0, 0);
      unsigned int lambda_isp_oldlua_line1274_169_pp_2_0_2 = in(x+1, y+-1, 2);
      unsigned int lambda_isp_oldlua_line1274_169_pp_2_0_1 = in(x+1, y+-1, 1);
      unsigned int lambda_isp_oldlua_line1274_169_pp_2_0_0 = in(x+1, y+-1, 0);
      unsigned int lambda_isp_oldlua_line1274_169_pp_1_2_2 = in(x+0, y+1, 2);
      unsigned int lambda_isp_oldlua_line1274_169_pp_1_2_1 = in(x+0, y+1, 1);
      unsigned int lambda_isp_oldlua_line1274_169_pp_1_2_0 = in(x+0, y+1, 0);
      unsigned int lambda_isp_oldlua_line1274_169_pp_1_1_2 = in(x+0, y+0, 2);
      unsigned int lambda_isp_oldlua_line1274_169_pp_1_1_1 = in(x+0, y+0, 1);
      unsigned int lambda_isp_oldlua_line1274_169_pp_1_1_0 = in(x+0, y+0, 0);
      unsigned int lambda_isp_oldlua_line1274_169_pp_1_0_2 = in(x+0, y+-1, 2);
      unsigned int lambda_isp_oldlua_line1274_169_pp_1_0_1 = in(x+0, y+-1, 1);
      unsigned int lambda_isp_oldlua_line1274_169_pp_1_0_0 = in(x+0, y+-1, 0);
      unsigned int lambda_isp_oldlua_line1274_169_pp_0_2_2 = in(x+-1, y+1, 2);
      unsigned int lambda_isp_oldlua_line1274_169_pp_0_2_1 = in(x+-1, y+1, 1);
      unsigned int lambda_isp_oldlua_line1274_169_pp_0_2_0 = in(x+-1, y+1, 0);
      unsigned int lambda_isp_oldlua_line1274_169_pp_0_1_2 = in(x+-1, y+0, 2);
      unsigned int lambda_isp_oldlua_line1274_169_pp_0_1_1 = in(x+-1, y+0, 1);
      unsigned int lambda_isp_oldlua_line1274_169_pp_0_1_0 = in(x+-1, y+0, 0);
      unsigned int lambda_isp_oldlua_line1274_169_pp_0_0_2 = in(x+-1, y+-1, 2);
      unsigned int lambda_isp_oldlua_line1274_169_pp_0_0_1 = in(x+-1, y+-1, 1);
      unsigned int lambda_isp_oldlua_line1274_169_pp_0_0_0 = in(x+-1, y+-1, 0);
      const float c_1_0 = 1;
      const float c_2_0 = 2;
      const float c_4_0 = 4;
      const float c_8_0 = 8;
      const float c_n19_0 = -19;
      const float c_n182_0 = -182;
      const float c_457_0 = 457;
      const float c_128_0 = 128;
      const float c_0_0 = 0;
      const float c_1023_0 = 1023;
      const float c_n9_0 = -9;
      const float c_350_0 = 350;
      const float c_n85_0 = -85;
      const float c_378_0 = 378;
      const float c_n53_0 = -53;
      const float c_n69_0 = -69;
      const float c_10_0 = 10;
      
      signed int lambda_isp_oldlua_line1266_82_2 = lambda_isp_oldlua_line1274_169_pp_0_2_2;
      signed int lambda_isp_oldlua_line1266_82_1 = lambda_isp_oldlua_line1274_169_pp_0_2_1;
      signed int lambda_isp_oldlua_line1266_82_0 = lambda_isp_oldlua_line1274_169_pp_0_2_0;
      signed int lambda_isp_oldlua_line1266_80_1 = lambda_isp_oldlua_line1274_169_pp_2_1_1;
      signed int lambda_isp_oldlua_line1266_80_2 = lambda_isp_oldlua_line1274_169_pp_2_1_2;
      signed int lambda_isp_oldlua_line1266_80_0 = lambda_isp_oldlua_line1274_169_pp_2_1_0;
      signed int lambda_isp_oldlua_line791_215_0 = lambda_isp_oldlua_line1266_80_0;
      signed int lambda_isp_oldlua_line1266_79_2 = lambda_isp_oldlua_line1274_169_pp_0_1_2;
      signed int lambda_isp_oldlua_line1266_79_1 = lambda_isp_oldlua_line1274_169_pp_0_1_1;
      signed int lambda_isp_oldlua_line1266_79_0 = lambda_isp_oldlua_line1274_169_pp_0_1_0;
      signed int lambda_isp_oldlua_line1266_81_0 = lambda_isp_oldlua_line1274_169_pp_0_0_0;
      signed int lambda_isp_oldlua_line791_221_0 = lambda_isp_oldlua_line1266_81_0;
      signed int lambda_isp_oldlua_line1266_83_0 = lambda_isp_oldlua_line1274_169_pp_1_0_0;
      signed int lambda_isp_oldlua_line1266_83_1 = lambda_isp_oldlua_line1274_169_pp_1_0_1;
      signed int lambda_isp_oldlua_line1266_83_2 = lambda_isp_oldlua_line1274_169_pp_1_0_2;
      signed int offY_4256_0 = c_4_0;
      signed int lambda_isp_oldlua_line1266_76_2 = lambda_isp_oldlua_line1274_169_pp_2_0_2;
      signed int lambda_isp_oldlua_line791_187_0 = lambda_isp_oldlua_line1266_76_2;
      signed int lambda_isp_oldlua_line881_102_0 = c_10_0;
      signed int lambda_isp_oldlua_line1266_84_1 = lambda_isp_oldlua_line1274_169_pp_1_1_1;
      signed int lambda_isp_oldlua_line1240_360_0 = c_2_0;
      signed int lambda_isp_oldlua_line791_213_0 = lambda_isp_oldlua_line1266_80_1;
      signed int lambda_isp_oldlua_line1266_84_0 = lambda_isp_oldlua_line1274_169_pp_1_1_0;
      signed int clap_557_0 = c_0_0;
      signed int lambda_isp_oldlua_line1266_78_0 = lambda_isp_oldlua_line1274_169_pp_2_2_0;
      signed int lambda_isp_oldlua_line1266_78_1 = lambda_isp_oldlua_line1274_169_pp_2_2_1;
      signed int lambda_isp_oldlua_line791_201_0 = lambda_isp_oldlua_line1266_78_1;
      signed int lambda_isp_oldlua_line1266_78_2 = lambda_isp_oldlua_line1274_169_pp_2_2_2;
      signed int lambda_isp_oldlua_line791_223_0 = lambda_isp_oldlua_line1266_82_2;
      signed int lambda_isp_oldlua_line1266_76_0 = lambda_isp_oldlua_line1274_169_pp_2_0_0;
      signed int lambda_isp_oldlua_line1266_76_1 = lambda_isp_oldlua_line1274_169_pp_2_0_1;
      signed int lambda_isp_oldlua_line791_189_0 = lambda_isp_oldlua_line1266_76_1;
      signed int lambda_isp_oldlua_line791_205_0 = lambda_isp_oldlua_line1266_79_2;
      signed int lambda_isp_oldlua_line791_225_0 = lambda_isp_oldlua_line1266_82_1;
      signed int lambda_isp_oldlua_line804_49_0 = c_n19_0;
      signed int lambda_isp_oldlua_line791_203_0 = lambda_isp_oldlua_line1266_78_0;
      signed int lambda_isp_oldlua_line804_115_pack_1 = clap_557_0;
      signed int lambda_isp_oldlua_line791_229_0 = lambda_isp_oldlua_line1266_83_2;
      signed int lambda_isp_oldlua_line791_230_0 = lambda_isp_oldlua_line791_229_0 * lambda_isp_oldlua_line1240_360_0;
      signed int lambda_isp_oldlua_line791_237_pack_7 = lambda_isp_oldlua_line791_230_0;
      signed int lambda_isp_oldlua_line1240_359_0 = c_1_0;
      signed int lambda_isp_oldlua_line791_190_0 = lambda_isp_oldlua_line791_189_0 * lambda_isp_oldlua_line1240_359_0;
      signed int lambda_isp_oldlua_line881_103_0 = lambda_isp_oldlua_line881_102_0 - lambda_isp_oldlua_line1240_359_0;
      signed int lambda_isp_oldlua_line791_224_0 = lambda_isp_oldlua_line791_223_0 * lambda_isp_oldlua_line1240_359_0;
      signed int lambda_isp_oldlua_line791_237_pack_0 = lambda_isp_oldlua_line791_224_0;
      signed int lambda_isp_oldlua_line1240_365_0 = lambda_isp_oldlua_line1240_359_0 << lambda_isp_oldlua_line881_103_0;
      signed int lambda_isp_oldlua_line791_188_0 = lambda_isp_oldlua_line791_187_0 * lambda_isp_oldlua_line1240_359_0;
      signed int lambda_isp_oldlua_line791_231_0 = lambda_isp_oldlua_line1266_83_1;
      signed int lambda_isp_oldlua_line791_239_0 = lambda_isp_oldlua_line1266_84_1;
      signed int lambda_isp_oldlua_line791_202_0 = lambda_isp_oldlua_line791_201_0 * lambda_isp_oldlua_line1240_359_0;
      signed int lambda_isp_oldlua_line1266_81_1 = lambda_isp_oldlua_line1274_169_pp_0_0_1;
      signed int lambda_isp_oldlua_line791_219_0 = lambda_isp_oldlua_line1266_81_1;
      signed int lambda_isp_oldlua_line791_237_pack_8 = lambda_isp_oldlua_line791_188_0;
      signed int lambda_isp_oldlua_line1266_81_2 = lambda_isp_oldlua_line1274_169_pp_0_0_2;
      signed int lambda_isp_oldlua_line1266_77_0 = lambda_isp_oldlua_line1274_169_pp_1_2_0;
      signed int lambda_isp_oldlua_line791_197_0 = lambda_isp_oldlua_line1266_77_0;
      signed int lambda_isp_oldlua_line791_198_0 = lambda_isp_oldlua_line791_197_0 * lambda_isp_oldlua_line1240_360_0;
      signed int lambda_isp_oldlua_line791_245_pack_1 = lambda_isp_oldlua_line791_198_0;
      signed int lambda_isp_oldlua_line1266_77_1 = lambda_isp_oldlua_line1274_169_pp_1_2_1;
      signed int lambda_isp_oldlua_line791_195_0 = lambda_isp_oldlua_line1266_77_1;
      signed int lambda_isp_oldlua_line791_196_0 = lambda_isp_oldlua_line791_195_0 * lambda_isp_oldlua_line1240_360_0;
      signed int lambda_isp_oldlua_line1266_77_2 = lambda_isp_oldlua_line1274_169_pp_1_2_2;
      signed int lambda_isp_oldlua_line791_193_0 = lambda_isp_oldlua_line1266_77_2;
      signed int lambda_isp_oldlua_line791_194_0 = lambda_isp_oldlua_line791_193_0 * lambda_isp_oldlua_line1240_360_0;
      signed int lambda_isp_oldlua_line791_237_pack_1 = lambda_isp_oldlua_line791_194_0;
      signed int lambda_isp_oldlua_line791_207_0 = lambda_isp_oldlua_line1266_79_1;
      signed int lambda_isp_oldlua_line791_220_0 = lambda_isp_oldlua_line791_219_0 * lambda_isp_oldlua_line1240_359_0;
      signed int lambda_isp_oldlua_line804_66_0 = c_n69_0;
      signed int lambda_isp_oldlua_line804_63_0 = c_n53_0;
      signed int lambda_isp_oldlua_line791_199_0 = lambda_isp_oldlua_line1266_78_2;
      signed int lambda_isp_oldlua_line791_200_0 = lambda_isp_oldlua_line791_199_0 * lambda_isp_oldlua_line1240_359_0;
      signed int lambda_isp_oldlua_line791_237_pack_2 = lambda_isp_oldlua_line791_200_0;
      signed int lambda_isp_oldlua_line791_209_0 = lambda_isp_oldlua_line1266_79_0;
      signed int lambda_isp_oldlua_line804_39_0 = c_350_0;
      signed int lambda_isp_oldlua_line791_241_pack_8 = lambda_isp_oldlua_line791_190_0;
      signed int lambda_isp_oldlua_line804_37_0 = c_n9_0;
      signed int lambda_isp_oldlua_line791_210_0 = lambda_isp_oldlua_line791_209_0 * lambda_isp_oldlua_line1240_360_0;
      signed int lambda_isp_oldlua_line791_241_pack_2 = lambda_isp_oldlua_line791_202_0;
      signed int lambda_isp_oldlua_line791_206_0 = lambda_isp_oldlua_line791_205_0 * lambda_isp_oldlua_line1240_360_0;
      signed int lambda_isp_oldlua_line791_204_0 = lambda_isp_oldlua_line791_203_0 * lambda_isp_oldlua_line1240_359_0;
      signed int lambda_isp_oldlua_line791_191_0 = lambda_isp_oldlua_line1266_76_0;
      signed int lambda_isp_oldlua_line791_192_0 = lambda_isp_oldlua_line791_191_0 * lambda_isp_oldlua_line1240_359_0;
      signed int lambda_isp_oldlua_line791_245_pack_3 = lambda_isp_oldlua_line791_210_0;
      signed int lambda_isp_oldlua_line1266_84_2 = lambda_isp_oldlua_line1274_169_pp_1_1_2;
      signed int lambda_isp_oldlua_line791_237_pack_3 = lambda_isp_oldlua_line791_206_0;
      signed int lambda_isp_oldlua_line791_241_pack_6 = lambda_isp_oldlua_line791_220_0;
      signed int lambda_isp_oldlua_line791_226_0 = lambda_isp_oldlua_line791_225_0 * lambda_isp_oldlua_line1240_359_0;
      signed int lambda_isp_oldlua_line791_241_pack_0 = lambda_isp_oldlua_line791_226_0;
      signed int lambda_isp_oldlua_line804_54_0 = c_457_0;
      signed int lambda_isp_oldlua_line1228_6090_0 = c_128_0;
      signed int lambda_isp_oldlua_line804_127_pack_1 = clap_557_0;
      signed int lambda_isp_oldlua_line791_232_0 = lambda_isp_oldlua_line791_231_0 * lambda_isp_oldlua_line1240_360_0;
      signed int lambda_isp_oldlua_line804_51_0 = c_n182_0;
      signed int lambda_isp_oldlua_line791_217_0 = lambda_isp_oldlua_line1266_81_2;
      signed int lambda_isp_oldlua_line791_218_0 = lambda_isp_oldlua_line791_217_0 * lambda_isp_oldlua_line1240_359_0;
      signed int lambda_isp_oldlua_line791_237_pack_6 = lambda_isp_oldlua_line791_218_0;
      signed int lambda_isp_oldlua_line791_245_pack_8 = lambda_isp_oldlua_line791_192_0;
      signed int lambda_isp_oldlua_line791_240_0 = lambda_isp_oldlua_line791_239_0 * offY_4256_0;
      signed int lambda_isp_oldlua_line791_241_pack_4 = lambda_isp_oldlua_line791_240_0;
      signed int lambda_isp_oldlua_line791_211_0 = lambda_isp_oldlua_line1266_80_2;
      signed int lambda_isp_oldlua_line791_212_0 = lambda_isp_oldlua_line791_211_0 * lambda_isp_oldlua_line1240_360_0;
      signed int lambda_isp_oldlua_line791_241_pack_1 = lambda_isp_oldlua_line791_196_0;
      signed int clap_583_pack_1 = clap_557_0;
      signed int lambda_isp_oldlua_line791_235_0 = lambda_isp_oldlua_line1266_84_2;
      signed int lambda_isp_oldlua_line791_236_0 = lambda_isp_oldlua_line791_235_0 * offY_4256_0;
      signed int lambda_isp_oldlua_line791_237_pack_4 = lambda_isp_oldlua_line791_236_0;
      signed int lambda_isp_oldlua_line804_121_pack_1 = clap_557_0;
      signed int lambda_isp_oldlua_line791_222_0 = lambda_isp_oldlua_line791_221_0 * lambda_isp_oldlua_line1240_359_0;
      signed int lambda_isp_oldlua_line791_241_pack_7 = lambda_isp_oldlua_line791_232_0;
      signed int lambda_isp_oldlua_line804_109_0 = lambda_isp_oldlua_line791_239_0 * lambda_isp_oldlua_line804_39_0;
      signed int lambda_isp_oldlua_line791_233_0 = lambda_isp_oldlua_line1266_83_0;
      signed int lambda_isp_oldlua_line791_234_0 = lambda_isp_oldlua_line791_233_0 * lambda_isp_oldlua_line1240_360_0;
      signed int lambda_isp_oldlua_line791_245_pack_7 = lambda_isp_oldlua_line791_234_0;
      signed int lambda_isp_oldlua_line791_208_0 = lambda_isp_oldlua_line791_207_0 * lambda_isp_oldlua_line1240_360_0;
      signed int lambda_isp_oldlua_line791_241_pack_3 = lambda_isp_oldlua_line791_208_0;
      signed int lambda_isp_oldlua_line791_227_0 = lambda_isp_oldlua_line1266_82_0;
      signed int lambda_isp_oldlua_line791_228_0 = lambda_isp_oldlua_line791_227_0 * lambda_isp_oldlua_line1240_359_0;
      signed int lambda_isp_oldlua_line804_61_0 = c_378_0;
      signed int lambda_isp_oldlua_line804_104_0 = lambda_isp_oldlua_line791_235_0 * lambda_isp_oldlua_line804_61_0;
      signed int lambda_isp_oldlua_line791_214_0 = lambda_isp_oldlua_line791_213_0 * lambda_isp_oldlua_line1240_360_0;
      signed int lambda_isp_oldlua_line791_245_pack_2 = lambda_isp_oldlua_line791_204_0;
      signed int clap_586_pack_1 = clap_557_0;
      signed int clap_580_pack_1 = clap_557_0;
      signed int lambda_isp_oldlua_line791_243_0 = lambda_isp_oldlua_line1266_84_0;
      signed int lambda_isp_oldlua_line791_244_0 = lambda_isp_oldlua_line791_243_0 * offY_4256_0;
      signed int lambda_isp_oldlua_line791_245_pack_4 = lambda_isp_oldlua_line791_244_0;
      signed int lambda_isp_oldlua_line791_237_pack_5 = lambda_isp_oldlua_line791_212_0;
      signed int lambda_isp_oldlua_line791_241_pack_5 = lambda_isp_oldlua_line791_214_0;
      signed int lambda_isp_oldlua_line791_245_pack_6 = lambda_isp_oldlua_line791_222_0;
      signed int clap_558_0 = c_1023_0;
      signed int lambda_isp_oldlua_line804_122_pack_1 = clap_558_0;
      signed int clap_587_pack_1 = clap_558_0;
      signed int clap_584_pack_1 = clap_558_0;
      signed int lambda_isp_oldlua_line804_116_pack_1 = clap_558_0;
      signed int clap_581_pack_1 = clap_558_0;
      signed int lambda_isp_oldlua_line804_128_pack_1 = clap_558_0;
      signed int lambda_isp_oldlua_line804_42_0 = c_n85_0;
      signed int lambda_isp_oldlua_line791_216_0 = lambda_isp_oldlua_line791_215_0 * lambda_isp_oldlua_line1240_360_0;
      signed int lambda_isp_oldlua_line791_245_pack_5 = lambda_isp_oldlua_line791_216_0;
      signed int lambda_isp_oldlua_line1240_361_0 = c_8_0;
      signed int lambda_isp_oldlua_line791_241_pack_9 = lambda_isp_oldlua_line1240_361_0;
      signed int lambda_isp_oldlua_line791_245_pack_9 = lambda_isp_oldlua_line1240_361_0;
      signed int lambda_isp_oldlua_line791_241_0 = lambda_isp_oldlua_line791_241_pack_9 + lambda_isp_oldlua_line791_241_pack_8 + lambda_isp_oldlua_line791_241_pack_7 + lambda_isp_oldlua_line791_241_pack_6 + lambda_isp_oldlua_line791_241_pack_5 + lambda_isp_oldlua_line791_241_pack_4 + lambda_isp_oldlua_line791_241_pack_3 + lambda_isp_oldlua_line791_241_pack_2 + lambda_isp_oldlua_line791_241_pack_1 + lambda_isp_oldlua_line791_241_pack_0;
      signed int lambda_isp_oldlua_line791_242_0 = lambda_isp_oldlua_line791_241_0 >> offY_4256_0;
      signed int lambda_isp_oldlua_line804_107_0 = lambda_isp_oldlua_line791_242_0 * lambda_isp_oldlua_line804_63_0;
      signed int lambda_isp_oldlua_line804_108_0 = lambda_isp_oldlua_line804_104_0 + lambda_isp_oldlua_line804_107_0;
      signed int lambda_isp_oldlua_line804_105_0 = lambda_isp_oldlua_line791_242_0 * lambda_isp_oldlua_line804_51_0;
      signed int lambda_isp_oldlua_line791_237_pack_9 = lambda_isp_oldlua_line1240_361_0;
      signed int lambda_isp_oldlua_line791_237_0 = lambda_isp_oldlua_line791_237_pack_9 + lambda_isp_oldlua_line791_237_pack_8 + lambda_isp_oldlua_line791_237_pack_7 + lambda_isp_oldlua_line791_237_pack_6 + lambda_isp_oldlua_line791_237_pack_5 + lambda_isp_oldlua_line791_237_pack_4 + lambda_isp_oldlua_line791_237_pack_3 + lambda_isp_oldlua_line791_237_pack_2 + lambda_isp_oldlua_line791_237_pack_1 + lambda_isp_oldlua_line791_237_pack_0;
      signed int lambda_isp_oldlua_line791_238_0 = lambda_isp_oldlua_line791_237_0 >> offY_4256_0;
      signed int lambda_isp_oldlua_line804_102_0 = lambda_isp_oldlua_line791_238_0 * lambda_isp_oldlua_line804_49_0;
      signed int lambda_isp_oldlua_line804_103_0 = lambda_isp_oldlua_line791_238_0 * lambda_isp_oldlua_line804_37_0;
      signed int lambda_isp_oldlua_line804_110_0 = lambda_isp_oldlua_line804_103_0 + lambda_isp_oldlua_line804_109_0;
      signed int lambda_isp_oldlua_line804_106_0 = lambda_isp_oldlua_line804_102_0 + lambda_isp_oldlua_line804_105_0;
      signed int lambda_isp_oldlua_line1240_368_0 = lambda_isp_oldlua_line1240_359_0 << lambda_isp_oldlua_line1240_361_0;
      signed int lambda_isp_oldlua_line1240_369_0 = lambda_isp_oldlua_line1240_368_0 - lambda_isp_oldlua_line1240_359_0;
      signed int lambda_isp_oldlua_line1240_410_pack_1 = lambda_isp_oldlua_line1240_369_0;
      signed int lambda_isp_oldlua_line1240_422_pack_1 = lambda_isp_oldlua_line1240_369_0;
      signed int lambda_isp_oldlua_line1240_416_pack_1 = lambda_isp_oldlua_line1240_369_0;
      signed int lambda_isp_oldlua_line804_111_0 = lambda_isp_oldlua_line791_243_0 * lambda_isp_oldlua_line804_54_0;
      signed int lambda_isp_oldlua_line804_112_0 = lambda_isp_oldlua_line804_106_0 + lambda_isp_oldlua_line804_111_0;
      signed int lambda_isp_oldlua_line804_113_0 = lambda_isp_oldlua_line804_112_0 + lambda_isp_oldlua_line1228_6090_0;
      signed int lambda_isp_oldlua_line804_114_0 = lambda_isp_oldlua_line804_113_0 >> lambda_isp_oldlua_line1240_361_0;
      signed int lambda_isp_oldlua_line804_115_pack_0 = lambda_isp_oldlua_line804_114_0;
      // max lambda_isp_oldlua_line804_115_0 <= (lambda_isp_oldlua_line804_115_pack_1 , lambda_isp_oldlua_line804_115_pack_0)
      signed int lambda_isp_oldlua_line804_115_0_cotmp_1 = (lambda_isp_oldlua_line804_115_pack_1 > lambda_isp_oldlua_line804_115_pack_0) ? lambda_isp_oldlua_line804_115_pack_1 : lambda_isp_oldlua_line804_115_pack_0;
      signed int lambda_isp_oldlua_line804_115_0 = lambda_isp_oldlua_line804_115_0_cotmp_1;

      signed int lambda_isp_oldlua_line804_116_pack_0 = lambda_isp_oldlua_line804_115_0;
      // min lambda_isp_oldlua_line804_116_0 <= (lambda_isp_oldlua_line804_116_pack_1 , lambda_isp_oldlua_line804_116_pack_0)
      signed int lambda_isp_oldlua_line804_116_0_cotmp_1 = (lambda_isp_oldlua_line804_116_pack_1 < lambda_isp_oldlua_line804_116_pack_0) ? lambda_isp_oldlua_line804_116_pack_1 : lambda_isp_oldlua_line804_116_pack_0;
      signed int lambda_isp_oldlua_line804_116_0 = lambda_isp_oldlua_line804_116_0_cotmp_1;

      signed int lambda_isp_oldlua_line804_129_0 = lambda_isp_oldlua_line804_116_0;
      signed int clap_579_0 = lambda_isp_oldlua_line804_129_0;
      signed int lambda_isp_oldlua_line791_245_pack_0 = lambda_isp_oldlua_line791_228_0;
      signed int lambda_isp_oldlua_line791_245_0 = lambda_isp_oldlua_line791_245_pack_9 + lambda_isp_oldlua_line791_245_pack_8 + lambda_isp_oldlua_line791_245_pack_7 + lambda_isp_oldlua_line791_245_pack_6 + lambda_isp_oldlua_line791_245_pack_5 + lambda_isp_oldlua_line791_245_pack_4 + lambda_isp_oldlua_line791_245_pack_3 + lambda_isp_oldlua_line791_245_pack_2 + lambda_isp_oldlua_line791_245_pack_1 + lambda_isp_oldlua_line791_245_pack_0;
      signed int lambda_isp_oldlua_line791_246_0 = lambda_isp_oldlua_line791_245_0 >> offY_4256_0;
      signed int lambda_isp_oldlua_line804_123_0 = lambda_isp_oldlua_line791_246_0 * lambda_isp_oldlua_line804_66_0;
      signed int lambda_isp_oldlua_line804_117_0 = lambda_isp_oldlua_line791_246_0 * lambda_isp_oldlua_line804_42_0;
      signed int lambda_isp_oldlua_line804_118_0 = lambda_isp_oldlua_line804_110_0 + lambda_isp_oldlua_line804_117_0;
      signed int lambda_isp_oldlua_line804_124_0 = lambda_isp_oldlua_line804_108_0 + lambda_isp_oldlua_line804_123_0;
      signed int lambda_isp_oldlua_line804_125_0 = lambda_isp_oldlua_line804_124_0 + lambda_isp_oldlua_line1228_6090_0;
      signed int lambda_isp_oldlua_line804_126_0 = lambda_isp_oldlua_line804_125_0 >> lambda_isp_oldlua_line1240_361_0;
      signed int lambda_isp_oldlua_line804_127_pack_0 = lambda_isp_oldlua_line804_126_0;
      // max lambda_isp_oldlua_line804_127_0 <= (lambda_isp_oldlua_line804_127_pack_1 , lambda_isp_oldlua_line804_127_pack_0)
      signed int lambda_isp_oldlua_line804_127_0_cotmp_1 = (lambda_isp_oldlua_line804_127_pack_1 > lambda_isp_oldlua_line804_127_pack_0) ? lambda_isp_oldlua_line804_127_pack_1 : lambda_isp_oldlua_line804_127_pack_0;
      signed int lambda_isp_oldlua_line804_127_0 = lambda_isp_oldlua_line804_127_0_cotmp_1;

      signed int lambda_isp_oldlua_line804_128_pack_0 = lambda_isp_oldlua_line804_127_0;
      // min lambda_isp_oldlua_line804_128_0 <= (lambda_isp_oldlua_line804_128_pack_1 , lambda_isp_oldlua_line804_128_pack_0)
      signed int lambda_isp_oldlua_line804_128_0_cotmp_1 = (lambda_isp_oldlua_line804_128_pack_1 < lambda_isp_oldlua_line804_128_pack_0) ? lambda_isp_oldlua_line804_128_pack_1 : lambda_isp_oldlua_line804_128_pack_0;
      signed int lambda_isp_oldlua_line804_128_0 = lambda_isp_oldlua_line804_128_0_cotmp_1;

      signed int lambda_isp_oldlua_line804_129_2 = lambda_isp_oldlua_line804_128_0;
      signed int clap_585_0 = lambda_isp_oldlua_line804_129_2;
      signed int clap_586_pack_0 = clap_585_0;
      // max clap_586_0 <= (clap_586_pack_1 , clap_586_pack_0)
      signed int clap_586_0_cotmp_1 = (clap_586_pack_1 > clap_586_pack_0) ? clap_586_pack_1 : clap_586_pack_0;
      signed int clap_586_0 = clap_586_0_cotmp_1;

      signed int lambda_isp_oldlua_line804_119_0 = lambda_isp_oldlua_line804_118_0 + lambda_isp_oldlua_line1228_6090_0;
      signed int lambda_isp_oldlua_line804_120_0 = lambda_isp_oldlua_line804_119_0 >> lambda_isp_oldlua_line1240_361_0;
      signed int lambda_isp_oldlua_line804_121_pack_0 = lambda_isp_oldlua_line804_120_0;
      // max lambda_isp_oldlua_line804_121_0 <= (lambda_isp_oldlua_line804_121_pack_1 , lambda_isp_oldlua_line804_121_pack_0)
      signed int lambda_isp_oldlua_line804_121_0_cotmp_1 = (lambda_isp_oldlua_line804_121_pack_1 > lambda_isp_oldlua_line804_121_pack_0) ? lambda_isp_oldlua_line804_121_pack_1 : lambda_isp_oldlua_line804_121_pack_0;
      signed int lambda_isp_oldlua_line804_121_0 = lambda_isp_oldlua_line804_121_0_cotmp_1;

      signed int lambda_isp_oldlua_line804_122_pack_0 = lambda_isp_oldlua_line804_121_0;
      // min lambda_isp_oldlua_line804_122_0 <= (lambda_isp_oldlua_line804_122_pack_1 , lambda_isp_oldlua_line804_122_pack_0)
      signed int lambda_isp_oldlua_line804_122_0_cotmp_1 = (lambda_isp_oldlua_line804_122_pack_1 < lambda_isp_oldlua_line804_122_pack_0) ? lambda_isp_oldlua_line804_122_pack_1 : lambda_isp_oldlua_line804_122_pack_0;
      signed int lambda_isp_oldlua_line804_122_0 = lambda_isp_oldlua_line804_122_0_cotmp_1;

      signed int lambda_isp_oldlua_line804_129_1 = lambda_isp_oldlua_line804_122_0;
      signed int clap_582_0 = lambda_isp_oldlua_line804_129_1;
      signed int clap_583_pack_0 = clap_582_0;
      // max clap_583_0 <= (clap_583_pack_1 , clap_583_pack_0)
      signed int clap_583_0_cotmp_1 = (clap_583_pack_1 > clap_583_pack_0) ? clap_583_pack_1 : clap_583_pack_0;
      signed int clap_583_0 = clap_583_0_cotmp_1;

      signed int clap_584_pack_0 = clap_583_0;
      signed int clap_587_pack_0 = clap_586_0;
      // min clap_587_0 <= (clap_587_pack_1 , clap_587_pack_0)
      signed int clap_587_0_cotmp_1 = (clap_587_pack_1 < clap_587_pack_0) ? clap_587_pack_1 : clap_587_pack_0;
      signed int clap_587_0 = clap_587_0_cotmp_1;

      signed int clap_588_2 = clap_587_0;
      unsigned int lambda_isp_oldlua_line1277_6_2 = clap_588_2;
      unsigned int lambda_isp_oldlua_line1240_405_0 = lambda_isp_oldlua_line1277_6_2;
      signed int lambda_isp_oldlua_line1240_406_0 = lambda_isp_oldlua_line1240_405_0;
      signed int lambda_isp_oldlua_line1240_407_0 = lambda_isp_oldlua_line1240_406_0 << lambda_isp_oldlua_line1240_361_0;
      signed int lambda_isp_oldlua_line1240_408_0 = lambda_isp_oldlua_line1240_407_0 + lambda_isp_oldlua_line1240_365_0;
      signed int lambda_isp_oldlua_line1240_409_0 = lambda_isp_oldlua_line1240_408_0 >> lambda_isp_oldlua_line881_102_0;
      signed int lambda_isp_oldlua_line1240_410_pack_0 = lambda_isp_oldlua_line1240_409_0;
      // min lambda_isp_oldlua_line1240_410_0 <= (lambda_isp_oldlua_line1240_410_pack_1 , lambda_isp_oldlua_line1240_410_pack_0)
      signed int lambda_isp_oldlua_line1240_410_0_cotmp_1 = (lambda_isp_oldlua_line1240_410_pack_1 < lambda_isp_oldlua_line1240_410_pack_0) ? lambda_isp_oldlua_line1240_410_pack_1 : lambda_isp_oldlua_line1240_410_pack_0;
      signed int lambda_isp_oldlua_line1240_410_0 = lambda_isp_oldlua_line1240_410_0_cotmp_1;

      signed int lambda_isp_oldlua_line1240_423_0 = lambda_isp_oldlua_line1240_410_0;
      unsigned int lambda_isp_oldlua_line1240_424_0 = lambda_isp_oldlua_line1240_423_0;
      unsigned int lambda_isp_oldlua_line1329_1421_0 = lambda_isp_oldlua_line1240_424_0;
      // min clap_584_0 <= (clap_584_pack_1 , clap_584_pack_0)
      signed int clap_584_0_cotmp_1 = (clap_584_pack_1 < clap_584_pack_0) ? clap_584_pack_1 : clap_584_pack_0;
      signed int clap_584_0 = clap_584_0_cotmp_1;

      signed int clap_588_1 = clap_584_0;
      unsigned int lambda_isp_oldlua_line1277_6_1 = clap_588_1;
      unsigned int lambda_isp_oldlua_line1240_411_0 = lambda_isp_oldlua_line1277_6_1;
      signed int lambda_isp_oldlua_line1240_412_0 = lambda_isp_oldlua_line1240_411_0;
      signed int lambda_isp_oldlua_line1240_413_0 = lambda_isp_oldlua_line1240_412_0 << lambda_isp_oldlua_line1240_361_0;
      signed int lambda_isp_oldlua_line1240_414_0 = lambda_isp_oldlua_line1240_413_0 + lambda_isp_oldlua_line1240_365_0;
      signed int lambda_isp_oldlua_line1240_415_0 = lambda_isp_oldlua_line1240_414_0 >> lambda_isp_oldlua_line881_102_0;
      signed int lambda_isp_oldlua_line1240_416_pack_0 = lambda_isp_oldlua_line1240_415_0;
      // min lambda_isp_oldlua_line1240_416_0 <= (lambda_isp_oldlua_line1240_416_pack_1 , lambda_isp_oldlua_line1240_416_pack_0)
      signed int lambda_isp_oldlua_line1240_416_0_cotmp_1 = (lambda_isp_oldlua_line1240_416_pack_1 < lambda_isp_oldlua_line1240_416_pack_0) ? lambda_isp_oldlua_line1240_416_pack_1 : lambda_isp_oldlua_line1240_416_pack_0;
      signed int lambda_isp_oldlua_line1240_416_0 = lambda_isp_oldlua_line1240_416_0_cotmp_1;

      signed int lambda_isp_oldlua_line1240_423_1 = lambda_isp_oldlua_line1240_416_0;
      unsigned int lambda_isp_oldlua_line1240_424_1 = lambda_isp_oldlua_line1240_423_1;
      unsigned int lambda_isp_oldlua_line1329_1421_1 = lambda_isp_oldlua_line1240_424_1;
      signed int clap_580_pack_0 = clap_579_0;
      // max clap_580_0 <= (clap_580_pack_1 , clap_580_pack_0)
      signed int clap_580_0_cotmp_1 = (clap_580_pack_1 > clap_580_pack_0) ? clap_580_pack_1 : clap_580_pack_0;
      signed int clap_580_0 = clap_580_0_cotmp_1;

      signed int clap_581_pack_0 = clap_580_0;
      // min clap_581_0 <= (clap_581_pack_1 , clap_581_pack_0)
      signed int clap_581_0_cotmp_1 = (clap_581_pack_1 < clap_581_pack_0) ? clap_581_pack_1 : clap_581_pack_0;
      signed int clap_581_0 = clap_581_0_cotmp_1;

      signed int clap_588_0 = clap_581_0;
      unsigned int lambda_isp_oldlua_line1277_6_0 = clap_588_0;
      unsigned int lambda_isp_oldlua_line1240_417_0 = lambda_isp_oldlua_line1277_6_0;
      signed int lambda_isp_oldlua_line1240_418_0 = lambda_isp_oldlua_line1240_417_0;
      signed int lambda_isp_oldlua_line1240_419_0 = lambda_isp_oldlua_line1240_418_0 << lambda_isp_oldlua_line1240_361_0;
      signed int lambda_isp_oldlua_line1240_420_0 = lambda_isp_oldlua_line1240_419_0 + lambda_isp_oldlua_line1240_365_0;
      signed int lambda_isp_oldlua_line1240_421_0 = lambda_isp_oldlua_line1240_420_0 >> lambda_isp_oldlua_line881_102_0;
      signed int lambda_isp_oldlua_line1240_422_pack_0 = lambda_isp_oldlua_line1240_421_0;
      // min lambda_isp_oldlua_line1240_422_0 <= (lambda_isp_oldlua_line1240_422_pack_1 , lambda_isp_oldlua_line1240_422_pack_0)
      signed int lambda_isp_oldlua_line1240_422_0_cotmp_1 = (lambda_isp_oldlua_line1240_422_pack_1 < lambda_isp_oldlua_line1240_422_pack_0) ? lambda_isp_oldlua_line1240_422_pack_1 : lambda_isp_oldlua_line1240_422_pack_0;
      signed int lambda_isp_oldlua_line1240_422_0 = lambda_isp_oldlua_line1240_422_0_cotmp_1;

      signed int lambda_isp_oldlua_line1240_423_2 = lambda_isp_oldlua_line1240_422_0;
      unsigned int lambda_isp_oldlua_line1240_424_2 = lambda_isp_oldlua_line1240_423_2;
      unsigned int lambda_isp_oldlua_line1329_1421_2 = lambda_isp_oldlua_line1240_424_2;
      out(x,y,2) = lambda_isp_oldlua_line1329_1421_2;
      out(x,y,1) = lambda_isp_oldlua_line1329_1421_1;
      out(x,y,0) = lambda_isp_oldlua_line1329_1421_0;
    }
  }
} // END lambda_isp_oldlua_line1329_18


void lambda_isp_oldlua_line1274_220(const Image<int>& in, Image<int>& out
)
{
  for(int y = 0; y < in.height(); y++){
    for(int x = 0; x < in.width(); x++){
      unsigned int lambda_isp_oldlua_line1282_848_pp_6_6 = in(x+3, y+3, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_6_5 = in(x+3, y+2, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_6_4 = in(x+3, y+1, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_6_3 = in(x+3, y+0, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_6_2 = in(x+3, y+-1, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_6_1 = in(x+3, y+-2, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_6_0 = in(x+3, y+-3, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_5_6 = in(x+2, y+3, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_5_5 = in(x+2, y+2, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_5_4 = in(x+2, y+1, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_5_3 = in(x+2, y+0, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_5_2 = in(x+2, y+-1, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_5_1 = in(x+2, y+-2, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_5_0 = in(x+2, y+-3, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_4_6 = in(x+1, y+3, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_4_5 = in(x+1, y+2, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_4_4 = in(x+1, y+1, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_4_3 = in(x+1, y+0, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_4_2 = in(x+1, y+-1, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_4_1 = in(x+1, y+-2, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_4_0 = in(x+1, y+-3, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_3_6 = in(x+0, y+3, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_3_5 = in(x+0, y+2, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_3_4 = in(x+0, y+1, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_3_3 = in(x+0, y+0, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_3_2 = in(x+0, y+-1, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_3_1 = in(x+0, y+-2, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_3_0 = in(x+0, y+-3, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_2_6 = in(x+-1, y+3, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_2_5 = in(x+-1, y+2, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_2_4 = in(x+-1, y+1, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_2_3 = in(x+-1, y+0, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_2_2 = in(x+-1, y+-1, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_2_1 = in(x+-1, y+-2, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_2_0 = in(x+-1, y+-3, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_1_6 = in(x+-2, y+3, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_1_5 = in(x+-2, y+2, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_1_4 = in(x+-2, y+1, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_1_3 = in(x+-2, y+0, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_1_2 = in(x+-2, y+-1, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_1_1 = in(x+-2, y+-2, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_1_0 = in(x+-2, y+-3, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_0_6 = in(x+-3, y+3, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_0_5 = in(x+-3, y+2, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_0_4 = in(x+-3, y+1, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_0_3 = in(x+-3, y+0, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_0_2 = in(x+-3, y+-1, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_0_1 = in(x+-3, y+-2, 0);
      unsigned int lambda_isp_oldlua_line1282_848_pp_0_0 = in(x+-3, y+-3, 0);
      const float c_0_0 = 0;
      const float c_70_0 = 70;
      const float c_719_0 = 719;
      const float c_7_0 = 7;
      const float c_n7_0 = -7;
      const float c_2_0 = 2;
      const float c_1_0 = 1;
      const float c_3_0 = 3;
      const float c_4_0 = 4;
      const float c_344_0 = 344;
      const float c_34_0 = 34;
      const float c_80_0 = 80;
      const float c_60_0 = 60;
      const float c_50_0 = 50;
      const float c_0x1_0 = 0x1;
      const float c_1023_0 = 1023;
      const float c_128_0 = 128;
      const float c_0x0_0 = 0x0;
      const float c_n6_0 = -6;
      const float c_n8_0 = -8;
      const float c_5_0 = 5;
      const float c_16_0 = 16;
      const float c_8_0 = 8;
      
      int centroid_pos_0 = x;
      int centroid_pos_1 = y;
      signed int lambda_isp_oldlua_line1269_894_0 = lambda_isp_oldlua_line1282_848_pp_3_5;
      signed int pix_3015_0 = c_60_0;
      signed int lambda_isp_oldlua_line1329_1353_0 = c_n7_0;
      signed int lambda_isp_oldlua_line1329_1377_0 = c_n6_0;
      signed int lambda_isp_oldlua_line1329_1400_0 = c_7_0;
      signed int pix_2988_0 = c_50_0;
      signed int lambda_isp_oldlua_line1269_905_0 = lambda_isp_oldlua_line1282_848_pp_1_2;
      signed int lambda_isp_oldlua_line1329_1416_0 = c_7_0;
      signed int lambda_isp_oldlua_line1269_897_0 = lambda_isp_oldlua_line1282_848_pp_5_3;
      signed int lambda_isp_oldlua_line1329_1365_0 = c_n7_0;
      signed int lambda_isp_oldlua_line1240_353_0 = c_2_0;
      signed int Rv_8380_pack_8 = lambda_isp_oldlua_line1240_353_0;
      signed int lambda_isp_oldlua_line1269_901_0 = lambda_isp_oldlua_line1282_848_pp_3_6;
      signed int pix_2972_0 = c_80_0;
      signed int lambda_isp_oldlua_line1240_350_0 = c_1_0;
      signed int clap_514_0 = c_1023_0;
      signed int Gh_2006_pack_1 = clap_514_0;
      signed int lambda_isp_oldlua_line1329_1403_0 = c_719_0;
      signed int lambda_isp_oldlua_line1269_907_0 = lambda_isp_oldlua_line1282_848_pp_6_3;
      signed int pix_2975_0 = c_60_0;
      bool Rv_8165_0 = c_0x0_0;
      signed int lambda_isp_oldlua_line1329_1350_0 = c_n7_0;
      signed int clap_507_0 = c_0_0;
      signed int Rh_4234_pack_1 = clap_507_0;
      signed int pix_3001_0 = c_70_0;
      signed int offX_2302_0 = c_34_0;
      signed int lambda_isp_oldlua_line1329_1381_0 = c_7_0;
      signed int lambda_isp_oldlua_line1240_348_0 = c_1_0;
      signed int Rv_8309_pack_2 = lambda_isp_oldlua_line1240_348_0;
      signed int Gh_1974_0 = lambda_isp_oldlua_line1269_897_0 << lambda_isp_oldlua_line1240_348_0;
      signed int Rv_8345_pack_2 = lambda_isp_oldlua_line1240_350_0;
      signed int clap_511_0 = c_0_0;
      signed int Bv_3028_pack_1 = clap_511_0;
      signed int Rv_8407_pack_1 = clap_511_0;
      signed int Rv_8389_0 = -lambda_isp_oldlua_line1269_905_0;
      signed int Rv_8391_0 = -lambda_isp_oldlua_line1269_907_0;
      signed int lambda_isp_oldlua_line1329_1408_0 = c_7_0;
      signed int Rh_4223_pack_9 = Rv_8391_0;
      signed int lambda_isp_oldlua_line1329_1405_0 = c_7_0;
      signed int lambda_isp_oldlua_line1329_1409_0 = centroid_pos_0 + lambda_isp_oldlua_line1329_1408_0;
      signed int clap_513_0 = c_0_0;
      signed int offX_2274_0 = c_34_0;
      signed int offY_4214_0 = c_344_0;
      signed int offY_4253_0 = c_344_0;
      signed int pix_2971_0 = c_70_0;
      signed int pix_3011_0 = c_70_0;
      signed int Gh_2005_pack_1 = clap_513_0;
      signed int lambda_isp_oldlua_line1329_1395_0 = c_719_0;
      signed int Rv_8371_pack_5 = lambda_isp_oldlua_line1240_353_0;
      signed int pix_2991_0 = c_70_0;
      signed int Gh_1975_0 = -Gh_1974_0;
      signed int lambda_isp_oldlua_line1329_1379_0 = c_719_0;
      signed int lambda_isp_oldlua_line1269_890_0 = lambda_isp_oldlua_line1282_848_pp_3_4;
      signed int Bh_3020_pack_1 = lambda_isp_oldlua_line1269_890_0;
      signed int Rv_8309_pack_0 = lambda_isp_oldlua_line1269_890_0;
      signed int Rh_4206_pack_1 = lambda_isp_oldlua_line1269_890_0;
      signed int Bh_3035_pack_0 = lambda_isp_oldlua_line1269_890_0;
      signed int Rv_8305_0 = -lambda_isp_oldlua_line1269_890_0;
      signed int Bv_2982_pack_3 = Rv_8305_0;
      signed int Rh_4223_pack_0 = lambda_isp_oldlua_line1269_890_0;
      signed int lambda_isp_oldlua_line1269_896_0 = lambda_isp_oldlua_line1282_848_pp_1_3;
      signed int Rv_8348_0 = -lambda_isp_oldlua_line1269_896_0;
      signed int Gh_1976_pack_4 = Rv_8348_0;
      signed int lambda_isp_oldlua_line1269_885_0 = lambda_isp_oldlua_line1282_848_pp_4_3;
      signed int Rv_8375_pack_3 = lambda_isp_oldlua_line1269_885_0;
      signed int offY_4246_0 = c_3_0;
      signed int pix_2992_0 = c_80_0;
      signed int Rv_8357_pack_9 = Rv_8305_0;
      signed int Rv_8370_0 = -lambda_isp_oldlua_line1269_901_0;
      signed int Rv_8375_pack_9 = Rv_8370_0;
      signed int Bv_2994_pack_3 = Rv_8370_0;
      signed int Rv_8371_pack_3 = Rv_8370_0;
      signed int offY_4243_0 = c_4_0;
      signed int Bv_2997_pack_4 = lambda_isp_oldlua_line1240_353_0;
      signed int Bh_3046_pack_1 = clap_507_0;
      signed int lambda_isp_oldlua_line1228_6087_pack_1 = clap_507_0;
      signed int Rv_8329_0 = -lambda_isp_oldlua_line1269_894_0;
      signed int Bh_3022_pack_2 = lambda_isp_oldlua_line1269_905_0;
      signed int lambda_isp_oldlua_line1329_1417_0 = centroid_pos_0 + lambda_isp_oldlua_line1329_1416_0;
      signed int lambda_isp_oldlua_line1329_1418_0 = lambda_isp_oldlua_line1329_1417_0 + lambda_isp_oldlua_line1329_1377_0;
      signed int offY_4233_0 = c_3_0;
      signed int Bh_3033_pack_0 = lambda_isp_oldlua_line1269_890_0;
      signed int lambda_isp_oldlua_line1329_1401_0 = centroid_pos_0 + lambda_isp_oldlua_line1329_1400_0;
      signed int lambda_isp_oldlua_line1329_1402_0 = lambda_isp_oldlua_line1329_1401_0 + lambda_isp_oldlua_line1329_1365_0;
      signed int Bv_2994_pack_5 = lambda_isp_oldlua_line1240_353_0;
      signed int Rh_4216_pack_3 = Rv_8391_0;
      signed int offY_4191_0 = c_4_0;
      signed int offY_4194_0 = c_3_0;
      signed int Bv_2997_pack_3 = lambda_isp_oldlua_line1269_885_0;
      signed int Rh_4221_pack_0 = lambda_isp_oldlua_line1269_890_0;
      signed int offY_4230_0 = c_4_0;
      signed int lambda_isp_oldlua_line1269_886_0 = lambda_isp_oldlua_line1282_848_pp_4_4;
      signed int Bh_3006_pack_1 = lambda_isp_oldlua_line1269_886_0;
      signed int Rh_4180_pack_1 = lambda_isp_oldlua_line1269_886_0;
      signed int Rh_4188_pack_1 = lambda_isp_oldlua_line1269_886_0;
      signed int Rv_8288_0 = -lambda_isp_oldlua_line1269_886_0;
      signed int Rh_4184_pack_4 = Rv_8288_0;
      signed int Rv_8323_pack_4 = Rv_8288_0;
      signed int lambda_isp_oldlua_line1269_902_0 = lambda_isp_oldlua_line1282_848_pp_4_5;
      signed int Rv_8375_pack_1 = lambda_isp_oldlua_line1269_902_0;
      signed int Bv_2997_pack_1 = lambda_isp_oldlua_line1269_902_0;
      signed int lambda_isp_oldlua_line1269_899_0 = lambda_isp_oldlua_line1282_848_pp_2_1;
      signed int Rv_8362_pack_2 = lambda_isp_oldlua_line1269_899_0;
      signed int Bv_2985_pack_2 = lambda_isp_oldlua_line1269_899_0;
      signed int Gh_2001_pack_1 = clap_507_0;
      signed int pix_2978_0 = c_50_0;
      signed int Rh_4199_pack_1 = lambda_isp_oldlua_line1269_897_0;
      signed int pix_3005_0 = c_60_0;
      signed int lambda_isp_oldlua_line1240_357_0 = c_1_0;
      signed int Rv_8351_0 = lambda_isp_oldlua_line1269_897_0 << lambda_isp_oldlua_line1240_357_0;
      signed int Rh_4221_pack_5 = Rv_8351_0;
      signed int Rh_4223_pack_5 = Rv_8351_0;
      signed int Bh_3033_pack_6 = Rv_8351_0;
      signed int Gh_1990_0 = lambda_isp_oldlua_line1269_907_0 << lambda_isp_oldlua_line1240_357_0;
      signed int Gh_1991_0 = -Gh_1990_0;
      signed int Rh_4199_pack_2 = lambda_isp_oldlua_line1240_357_0;
      signed int Rv_8286_0 = lambda_isp_oldlua_line1269_885_0 << lambda_isp_oldlua_line1240_357_0;
      signed int Rh_4223_pack_8 = Rv_8286_0;
      signed int Rh_4216_pack_1 = Rv_8351_0;
      signed int lambda_isp_oldlua_line1329_1404_0 = lambda_isp_oldlua_line1329_1403_0 - centroid_pos_1;
      bool offY_4223_0 = lambda_isp_oldlua_line1240_353_0 == lambda_isp_oldlua_line1240_353_0;
      signed int clap_554_pack_1 = clap_507_0;
      signed int Rh_4219_pack_3 = Rv_8305_0;
      signed int Rh_4182_pack_1 = lambda_isp_oldlua_line1269_885_0;
      signed int lambda_isp_oldlua_line1329_1396_0 = lambda_isp_oldlua_line1329_1395_0 - centroid_pos_1;
      signed int Bh_3030_pack_3 = Rv_8391_0;
      signed int lambda_isp_oldlua_line1269_895_0 = lambda_isp_oldlua_line1282_848_pp_3_1;
      signed int Rv_8345_pack_1 = lambda_isp_oldlua_line1269_895_0;
      signed int lambda_isp_oldlua_line1269_898_0 = lambda_isp_oldlua_line1282_848_pp_3_0;
      signed int Bv_2982_pack_4 = lambda_isp_oldlua_line1269_898_0;
      signed int lambda_isp_oldlua_line1329_1356_0 = c_n6_0;
      signed int lambda_isp_oldlua_line1329_1368_0 = c_n7_0;
      signed int Rv_8333_0 = -lambda_isp_oldlua_line1269_895_0;
      signed int Rh_4186_pack_0 = lambda_isp_oldlua_line1269_896_0;
      signed int lambda_isp_oldlua_line1269_888_0 = lambda_isp_oldlua_line1282_848_pp_4_2;
      signed int Bh_3006_pack_3 = lambda_isp_oldlua_line1269_888_0;
      signed int Rh_4180_pack_3 = lambda_isp_oldlua_line1269_888_0;
      signed int Bh_3004_pack_3 = lambda_isp_oldlua_line1269_888_0;
      signed int Rv_8299_0 = lambda_isp_oldlua_line1269_888_0 << lambda_isp_oldlua_line1240_357_0;
      signed int Rh_4219_pack_1 = Rv_8299_0;
      signed int Bh_3030_pack_1 = Rv_8351_0;
      signed int clap_516_0 = c_1023_0;
      signed int Bh_3057_pack_1 = clap_516_0;
      signed int offY_4217_0 = c_4_0;
      bool offY_4218_0 = lambda_isp_oldlua_line1240_353_0 == offY_4217_0;
      signed int offX_2284_0 = offY_4218_0 ? clap_511_0 : lambda_isp_oldlua_line1240_353_0;
      signed int Rh_4216_pack_2 = Rv_8286_0;
      signed int offX_2288_0 = c_34_0;
      bool Rv_8079_0 = c_0x0_0;
      signed int lambda_isp_oldlua_line1240_351_0 = c_2_0;
      signed int Bv_2982_pack_5 = lambda_isp_oldlua_line1240_351_0;
      signed int Rv_8360_pack_7 = lambda_isp_oldlua_line1240_351_0;
      signed int Rv_8362_pack_8 = lambda_isp_oldlua_line1240_351_0;
      signed int Bv_2985_pack_4 = lambda_isp_oldlua_line1240_351_0;
      signed int Bv_2985_pack_1 = lambda_isp_oldlua_line1269_885_0;
      signed int lambda_isp_oldlua_line1269_900_0 = lambda_isp_oldlua_line1282_848_pp_4_1;
      signed int Rv_8362_pack_3 = lambda_isp_oldlua_line1269_900_0;
      signed int Bv_2985_pack_3 = lambda_isp_oldlua_line1269_900_0;
      signed int Rh_4204_pack_5 = Rv_8389_0;
      signed int lambda_isp_oldlua_line1269_909_0 = lambda_isp_oldlua_line1282_848_pp_5_2;
      signed int Bh_3035_pack_3 = lambda_isp_oldlua_line1269_909_0;
      signed int Rh_4223_pack_3 = lambda_isp_oldlua_line1269_909_0;
      signed int Rh_4221_pack_3 = lambda_isp_oldlua_line1269_909_0;
      signed int Rv_8393_0 = -lambda_isp_oldlua_line1269_909_0;
      signed int Rh_4219_pack_6 = Rv_8393_0;
      signed int Bh_3033_pack_3 = lambda_isp_oldlua_line1269_909_0;
      signed int lambda_isp_oldlua_line1329_1362_0 = c_n8_0;
      signed int Rh_4239_pack_1 = clap_513_0;
      signed int clap_508_0 = c_1023_0;
      signed int Rv_8398_pack_1 = clap_508_0;
      signed int Rh_4235_pack_1 = clap_508_0;
      signed int lambda_isp_oldlua_line1228_6088_pack_1 = clap_508_0;
      signed int clap_555_pack_1 = clap_508_0;
      signed int Gh_2002_pack_1 = clap_508_0;
      signed int Bh_3047_pack_1 = clap_508_0;
      signed int clap_552_pack_1 = clap_508_0;
      signed int Bv_3013_pack_1 = clap_508_0;
      signed int lambda_isp_oldlua_line1269_903_0 = lambda_isp_oldlua_line1282_848_pp_2_5;
      signed int Rv_8377_0 = -lambda_isp_oldlua_line1269_903_0;
      signed int Bv_2997_pack_0 = lambda_isp_oldlua_line1269_903_0;
      signed int Rh_4182_pack_2 = lambda_isp_oldlua_line1240_348_0;
      signed int Rv_8304_0 = lambda_isp_oldlua_line1269_890_0 << lambda_isp_oldlua_line1240_348_0;
      signed int Bv_2976_pack_0 = Rv_8304_0;
      signed int Rh_4184_pack_0 = Rv_8304_0;
      signed int Bh_3003_0 = -Rv_8304_0;
      signed int Bh_3004_pack_7 = Bh_3003_0;
      signed int Rv_8334_pack_4 = Rv_8304_0;
      signed int Rh_4188_pack_10 = Rv_8348_0;
      signed int offY_4220_0 = c_3_0;
      bool offY_4221_0 = lambda_isp_oldlua_line1240_353_0 == offY_4220_0;
      signed int lambda_isp_oldlua_line1329_1359_0 = c_n7_0;
      bool Rv_8065_0 = c_0x1_0;
      signed int lambda_isp_oldlua_line1329_1397_0 = c_7_0;
      signed int Bv_3012_pack_1 = clap_507_0;
      signed int lambda_isp_oldlua_line1329_1392_0 = c_7_0;
      signed int Bv_2976_pack_3 = Rv_8329_0;
      signed int lambda_isp_oldlua_line1240_355_0 = c_1_0;
      signed int Gh_1972_0 = lambda_isp_oldlua_line1269_885_0 << lambda_isp_oldlua_line1240_355_0;
      signed int Rv_8349_0 = lambda_isp_oldlua_line1269_896_0 << lambda_isp_oldlua_line1240_355_0;
      signed int Bh_3017_pack_0 = Rv_8349_0;
      signed int Rh_4186_pack_2 = lambda_isp_oldlua_line1240_355_0;
      signed int Bh_3010_pack_4 = Rv_8348_0;
      signed int Rv_8378_pack_7 = lambda_isp_oldlua_line1240_353_0;
      signed int offX_2281_0 = c_34_0;
      signed int Rv_8291_0 = lambda_isp_oldlua_line1269_886_0 << lambda_isp_oldlua_line1240_357_0;
      signed int Rh_4219_pack_0 = Rv_8291_0;
      signed int lambda_isp_oldlua_line1329_1413_0 = c_7_0;
      signed int Gv_1024_pack_1 = clap_508_0;
      signed int offY_4207_0 = c_3_0;
      signed int lambda_isp_oldlua_line1269_887_0 = lambda_isp_oldlua_line1282_848_pp_2_2;
      signed int Rv_8292_0 = -lambda_isp_oldlua_line1269_887_0;
      signed int Rh_4180_pack_2 = lambda_isp_oldlua_line1269_887_0;
      signed int Rh_4184_pack_5 = Rv_8292_0;
      signed int Bh_3004_pack_2 = lambda_isp_oldlua_line1269_887_0;
      signed int Rv_8323_pack_5 = Rv_8292_0;
      signed int Rv_8293_0 = lambda_isp_oldlua_line1269_887_0 << lambda_isp_oldlua_line1240_350_0;
      signed int Rv_8360_pack_0 = Rv_8293_0;
      signed int Rh_4188_pack_2 = lambda_isp_oldlua_line1269_887_0;
      signed int lambda_isp_oldlua_line1329_1411_0 = c_719_0;
      signed int lambda_isp_oldlua_line1329_1412_0 = lambda_isp_oldlua_line1329_1411_0 - centroid_pos_1;
      signed int lambda_isp_oldlua_line1329_1414_0 = lambda_isp_oldlua_line1329_1412_0 + lambda_isp_oldlua_line1329_1413_0;
      signed int clap_551_pack_1 = clap_507_0;
      signed int Bh_3004_pack_1 = lambda_isp_oldlua_line1269_886_0;
      signed int Rh_4174_0 = -Rv_8299_0;
      signed int Bh_3033_pack_8 = Rh_4174_0;
      signed int Rh_4223_pack_7 = Rh_4174_0;
      signed int Rh_4221_pack_7 = Rh_4174_0;
      signed int Rv_8378_pack_3 = Rv_8377_0;
      signed int lambda_isp_oldlua_line1269_892_0 = lambda_isp_oldlua_line1282_848_pp_2_3;
      signed int Bv_2985_pack_0 = lambda_isp_oldlua_line1269_892_0;
      signed int Bv_2997_pack_2 = lambda_isp_oldlua_line1269_892_0;
      signed int Rv_8319_0 = lambda_isp_oldlua_line1269_892_0 << lambda_isp_oldlua_line1240_355_0;
      signed int Bh_3022_pack_9 = Rv_8319_0;
      signed int Rv_8314_0 = lambda_isp_oldlua_line1269_892_0 << lambda_isp_oldlua_line1240_348_0;
      signed int Gh_1976_pack_0 = Rv_8314_0;
      signed int Rh_4180_pack_4 = Rv_8314_0;
      signed int Bh_3004_pack_5 = Rv_8314_0;
      signed int Rv_8323_pack_0 = Rv_8314_0;
      signed int Rh_4188_pack_4 = Rv_8314_0;
      signed int Bh_3010_pack_0 = Rv_8314_0;
      signed int lambda_isp_oldlua_line1329_1374_0 = c_n7_0;
      signed int lambda_isp_oldlua_line1329_1398_0 = lambda_isp_oldlua_line1329_1396_0 + lambda_isp_oldlua_line1329_1397_0;
      signed int lambda_isp_oldlua_line1269_891_0 = lambda_isp_oldlua_line1282_848_pp_3_2;
      signed int Bh_3035_pack_2 = lambda_isp_oldlua_line1269_891_0;
      signed int Rh_4221_pack_2 = lambda_isp_oldlua_line1269_891_0;
      signed int Bh_3033_pack_2 = lambda_isp_oldlua_line1269_891_0;
      signed int Bh_3022_pack_3 = lambda_isp_oldlua_line1269_891_0;
      signed int Bv_2994_pack_4 = lambda_isp_oldlua_line1269_891_0;
      signed int Rv_8312_0 = lambda_isp_oldlua_line1269_891_0 << lambda_isp_oldlua_line1240_351_0;
      signed int Rv_8313_0 = -lambda_isp_oldlua_line1269_891_0;
      signed int Rv_8375_pack_10 = Rv_8313_0;
      signed int Rv_8371_pack_4 = Rv_8313_0;
      signed int Rv_8308_0 = lambda_isp_oldlua_line1269_891_0 << lambda_isp_oldlua_line1240_348_0;
      signed int Rh_4179_0 = -Rv_8308_0;
      signed int Rh_4180_pack_7 = Rh_4179_0;
      signed int Bh_3004_pack_8 = Rh_4179_0;
      signed int Rh_4184_pack_1 = Rv_8308_0;
      signed int Bv_2970_pack_6 = Rv_8308_0;
      signed int Rh_4188_pack_7 = Rh_4179_0;
      signed int Rv_8311_0 = lambda_isp_oldlua_line1269_891_0 << lambda_isp_oldlua_line1240_350_0;
      signed int Rh_4206_pack_3 = lambda_isp_oldlua_line1269_891_0;
      signed int clap_549_pack_1 = clap_508_0;
      signed int Rh_4204_pack_6 = Rv_8313_0;
      signed int Rv_8316_pack_4 = Rv_8304_0;
      signed int Rh_4204_pack_4 = Rv_8305_0;
      signed int lambda_isp_oldlua_line1269_908_0 = lambda_isp_oldlua_line1282_848_pp_5_4;
      signed int Bh_3035_pack_1 = lambda_isp_oldlua_line1269_908_0;
      signed int Rh_4223_pack_1 = lambda_isp_oldlua_line1269_908_0;
      signed int Bh_3033_pack_1 = lambda_isp_oldlua_line1269_908_0;
      signed int Rv_8392_0 = -lambda_isp_oldlua_line1269_908_0;
      signed int Rh_4219_pack_4 = Rv_8392_0;
      signed int Rh_4221_pack_1 = lambda_isp_oldlua_line1269_908_0;
      signed int Bh_3022_pack_5 = Rv_8349_0;
      signed int pix_2981_0 = c_70_0;
      signed int Rv_8338_pack_1 = Rv_8308_0;
      signed int Rv_8353_pack_3 = Rv_8305_0;
      signed int Bh_3001_0 = -Rv_8291_0;
      signed int Bh_3033_pack_7 = Bh_3001_0;
      signed int clap_515_0 = c_0_0;
      signed int Bh_3056_pack_1 = clap_515_0;
      signed int Gh_2009_pack_1 = clap_515_0;
      signed int Rv_8338_pack_0 = Rv_8304_0;
      signed int Bh_3022_pack_1 = lambda_isp_oldlua_line1269_890_0;
      signed int Rv_8360_pack_2 = Rv_8312_0;
      signed int Rv_8297_0 = lambda_isp_oldlua_line1269_888_0 << lambda_isp_oldlua_line1240_350_0;
      signed int Rv_8360_pack_1 = Rv_8297_0;
      signed int Rv_8347_0 = lambda_isp_oldlua_line1269_895_0 << lambda_isp_oldlua_line1240_350_0;
      signed int Rv_8362_pack_5 = Rv_8347_0;
      signed int Bv_2985_pack_6 = Rv_8347_0;
      signed int Bv_2982_pack_1 = Rv_8347_0;
      signed int Rv_8353_pack_1 = Rv_8347_0;
      signed int Rv_8350_0 = -lambda_isp_oldlua_line1269_897_0;
      signed int Rh_4188_pack_9 = Rv_8350_0;
      signed int Bh_3010_pack_3 = Rv_8350_0;
      signed int clap_509_0 = c_0_0;
      signed int Bv_3020_pack_1 = clap_509_0;
      signed int Rv_8402_pack_1 = clap_509_0;
      signed int lambda_isp_oldlua_line1228_5778_0 = c_16_0;
      bool offY_4208_0 = lambda_isp_oldlua_line1240_351_0 == offY_4207_0;
      signed int Rh_4206_pack_2 = lambda_isp_oldlua_line1269_905_0;
      signed int lambda_isp_oldlua_line1228_5776_0 = c_5_0;
      signed int Bh_3020_pack_3 = lambda_isp_oldlua_line1269_891_0;
      bool offY_4212_0 = lambda_isp_oldlua_line1240_351_0 == lambda_isp_oldlua_line1240_350_0;
      bool Rv_8130_0 = c_0x0_0;
      signed int Gv_1029_pack_1 = clap_509_0;
      signed int pix_2982_0 = c_80_0;
      signed int pix_3002_0 = c_80_0;
      signed int clap_548_pack_1 = clap_507_0;
      signed int Rh_4193_pack_4 = Rv_8348_0;
      signed int Gh_1976_pack_3 = Gh_1975_0;
      signed int Bh_3006_pack_7 = Bh_3003_0;
      signed int Rh_4206_pack_4 = Rv_8349_0;
      signed int lambda_isp_oldlua_line1228_6081_pack_1 = clap_507_0;
      signed int lambda_isp_oldlua_line1228_6082_pack_1 = clap_508_0;
      signed int Bv_2970_pack_3 = lambda_isp_oldlua_line1269_888_0;
      signed int Bh_3020_pack_5 = Rv_8349_0;
      signed int Rv_8334_pack_2 = lambda_isp_oldlua_line1269_887_0;
      signed int lambda_isp_oldlua_line1228_6007_pack_2 = lambda_isp_oldlua_line1240_348_0;
      signed int Rv_8316_pack_5 = Rv_8308_0;
      signed int Rv_8330_pack_0 = lambda_isp_oldlua_line1269_894_0;
      signed int lambda_isp_oldlua_line1269_889_0 = lambda_isp_oldlua_line1282_848_pp_2_4;
      signed int Bh_3006_pack_0 = lambda_isp_oldlua_line1269_889_0;
      signed int Rh_4180_pack_0 = lambda_isp_oldlua_line1269_889_0;
      signed int Rh_4188_pack_0 = lambda_isp_oldlua_line1269_889_0;
      signed int Bh_3004_pack_0 = lambda_isp_oldlua_line1269_889_0;
      signed int Rv_8316_pack_0 = lambda_isp_oldlua_line1269_889_0;
      signed int Rv_8334_pack_0 = lambda_isp_oldlua_line1269_889_0;
      signed int Rv_8300_0 = -lambda_isp_oldlua_line1269_889_0;
      signed int Rh_4184_pack_3 = Rv_8300_0;
      signed int Rv_8323_pack_3 = Rv_8300_0;
      signed int Gh_1992_pack_1 = Rv_8351_0;
      signed int lambda_isp_oldlua_line1240_349_0 = c_2_0;
      signed int Bh_3006_pack_4 = lambda_isp_oldlua_line1240_349_0;
      signed int Gh_1976_pack_5 = lambda_isp_oldlua_line1240_349_0;
      signed int Rh_4180_pack_8 = lambda_isp_oldlua_line1240_349_0;
      signed int Rh_4177_0 = lambda_isp_oldlua_line1269_890_0 << lambda_isp_oldlua_line1240_349_0;
      signed int Rh_4178_0 = -Rh_4177_0;
      signed int Rh_4180_pack_6 = Rh_4178_0;
      signed int Rh_4188_pack_6 = Rh_4178_0;
      signed int Rv_8323_pack_7 = lambda_isp_oldlua_line1240_349_0;
      bool offY_4199_0 = lambda_isp_oldlua_line1240_349_0 == lambda_isp_oldlua_line1240_348_0;
      bool offY_4195_0 = lambda_isp_oldlua_line1240_349_0 == offY_4194_0;
      bool offY_4192_0 = lambda_isp_oldlua_line1240_349_0 == offY_4191_0;
      signed int Bh_3004_pack_4 = lambda_isp_oldlua_line1240_349_0;
      signed int Rh_4188_pack_11 = lambda_isp_oldlua_line1240_349_0;
      signed int Bh_3010_pack_5 = lambda_isp_oldlua_line1240_349_0;
      signed int Rh_4184_pack_7 = lambda_isp_oldlua_line1240_349_0;
      signed int Rv_8357_pack_11 = lambda_isp_oldlua_line1240_351_0;
      signed int Rv_8353_pack_2 = Rv_8311_0;
      signed int Rv_8316_pack_8 = lambda_isp_oldlua_line1240_349_0;
      signed int Rh_4223_pack_2 = lambda_isp_oldlua_line1269_891_0;
      signed int Rv_8334_pack_11 = lambda_isp_oldlua_line1240_349_0;
      signed int lambda_isp_oldlua_line1228_5757_0 = c_128_0;
      signed int Bh_3035_pack_9 = Rv_8286_0;
      bool offY_4197_0 = lambda_isp_oldlua_line1240_349_0 == lambda_isp_oldlua_line1240_349_0;
      signed int Bh_3006_pack_10 = Rv_8350_0;
      signed int lambda_isp_oldlua_line1329_1406_0 = lambda_isp_oldlua_line1329_1404_0 + lambda_isp_oldlua_line1329_1405_0;
      signed int offX_2270_0 = offY_4192_0 ? clap_507_0 : lambda_isp_oldlua_line1240_349_0;
      signed int offX_2271_0 = offY_4195_0 ? lambda_isp_oldlua_line1240_348_0 : offX_2270_0;
      signed int offX_2272_0 = offY_4197_0 ? lambda_isp_oldlua_line1240_348_0 : offX_2271_0;
      signed int offX_2273_0 = offY_4199_0 ? clap_507_0 : offX_2272_0;
      bool offX_2275_0 = offX_2273_0 != lambda_isp_oldlua_line1240_349_0;
      signed int Bh_3035_pack_7 = Bh_3001_0;
      bool offY_4210_0 = lambda_isp_oldlua_line1240_351_0 == lambda_isp_oldlua_line1240_351_0;
      signed int Rv_8375_pack_11 = lambda_isp_oldlua_line1240_353_0;
      signed int lambda_isp_oldlua_line1329_1387_0 = c_719_0;
      signed int Rh_4244_pack_1 = clap_515_0;
      signed int offY_4227_0 = c_344_0;
      signed int Bh_3051_pack_1 = clap_513_0;
      signed int Rv_8380_pack_2 = lambda_isp_oldlua_line1269_892_0;
      signed int Rv_8316_pack_2 = lambda_isp_oldlua_line1269_887_0;
      signed int Rv_8374_0 = -lambda_isp_oldlua_line1269_902_0;
      signed int Rv_8378_pack_4 = Rv_8374_0;
      signed int Rv_8353_pack_5 = lambda_isp_oldlua_line1240_351_0;
      signed int clap_512_0 = c_1023_0;
      signed int Bv_3029_pack_1 = clap_512_0;
      signed int Rv_8408_pack_1 = clap_512_0;
      signed int Rv_8303_0 = lambda_isp_oldlua_line1269_889_0 << lambda_isp_oldlua_line1240_355_0;
      signed int Rh_4204_pack_0 = Rv_8303_0;
      signed int Bh_3002_0 = -Rv_8303_0;
      signed int Bh_3020_pack_7 = Bh_3002_0;
      signed int lambda_isp_oldlua_line1240_358_0 = c_2_0;
      signed int Bh_3035_pack_4 = lambda_isp_oldlua_line1240_358_0;
      bool offY_4249_0 = lambda_isp_oldlua_line1240_358_0 == lambda_isp_oldlua_line1240_358_0;
      bool offY_4247_0 = lambda_isp_oldlua_line1240_358_0 == offY_4246_0;
      bool offY_4244_0 = lambda_isp_oldlua_line1240_358_0 == offY_4243_0;
      signed int Rh_4221_pack_8 = lambda_isp_oldlua_line1240_358_0;
      bool offY_4251_0 = lambda_isp_oldlua_line1240_358_0 == lambda_isp_oldlua_line1240_357_0;
      signed int Rv_8287_0 = lambda_isp_oldlua_line1269_885_0 << lambda_isp_oldlua_line1240_358_0;
      signed int Rh_4219_pack_2 = Rv_8287_0;
      signed int Bh_3033_pack_4 = lambda_isp_oldlua_line1240_358_0;
      signed int Bh_3030_pack_5 = lambda_isp_oldlua_line1240_358_0;
      signed int offY_4245_0 = offY_4244_0 ? lambda_isp_oldlua_line1240_357_0 : lambda_isp_oldlua_line1240_358_0;
      signed int offY_4248_0 = offY_4247_0 ? clap_515_0 : offY_4245_0;
      signed int offY_4250_0 = offY_4249_0 ? lambda_isp_oldlua_line1240_357_0 : offY_4248_0;
      signed int offY_4252_0 = offY_4251_0 ? clap_515_0 : offY_4250_0;
      bool offY_4254_0 = offY_4252_0 != lambda_isp_oldlua_line1240_358_0;
      signed int Rh_4223_pack_11 = lambda_isp_oldlua_line1240_358_0;
      signed int offX_2298_0 = offY_4244_0 ? clap_515_0 : lambda_isp_oldlua_line1240_358_0;
      signed int offX_2299_0 = offY_4247_0 ? lambda_isp_oldlua_line1240_357_0 : offX_2298_0;
      signed int Rh_4216_pack_5 = lambda_isp_oldlua_line1240_358_0;
      signed int Rh_4193_pack_5 = lambda_isp_oldlua_line1240_349_0;
      signed int Rv_8380_pack_0 = lambda_isp_oldlua_line1269_903_0;
      signed int Bh_3006_pack_8 = Rh_4179_0;
      signed int lambda_isp_oldlua_line1329_1407_0 = lambda_isp_oldlua_line1329_1406_0 + lambda_isp_oldlua_line1329_1368_0;
      signed int Rh_4193_pack_3 = Rv_8350_0;
      signed int lambda_isp_oldlua_line1240_352_0 = c_1_0;
      signed int Rv_8301_0 = lambda_isp_oldlua_line1269_889_0 << lambda_isp_oldlua_line1240_352_0;
      signed int offX_2285_0 = offY_4221_0 ? lambda_isp_oldlua_line1240_352_0 : offX_2284_0;
      signed int offX_2286_0 = offY_4223_0 ? lambda_isp_oldlua_line1240_352_0 : offX_2285_0;
      bool offY_4225_0 = lambda_isp_oldlua_line1240_353_0 == lambda_isp_oldlua_line1240_352_0;
      signed int offX_2287_0 = offY_4225_0 ? clap_511_0 : offX_2286_0;
      signed int Rv_8378_pack_0 = Rv_8301_0;
      signed int Rv_8306_0 = lambda_isp_oldlua_line1269_890_0 << lambda_isp_oldlua_line1240_352_0;
      signed int Rv_8371_pack_2 = Rv_8306_0;
      signed int Bv_2994_pack_2 = Rv_8306_0;
      signed int Rv_8332_0 = lambda_isp_oldlua_line1269_894_0 << lambda_isp_oldlua_line1240_352_0;
      signed int Rv_8371_pack_0 = Rv_8332_0;
      signed int Bv_2994_pack_0 = Rv_8332_0;
      signed int Bv_2997_pack_5 = Rv_8332_0;
      bool offX_2289_0 = offX_2287_0 != lambda_isp_oldlua_line1240_353_0;
      signed int grPix_4001_0 = lambda_isp_oldlua_line1329_1402_0 + offX_2287_0;
      signed int grPix_4002_0 = grPix_4001_0 & lambda_isp_oldlua_line1240_352_0;
      signed int offY_4219_0 = offY_4218_0 ? lambda_isp_oldlua_line1240_352_0 : lambda_isp_oldlua_line1240_353_0;
      signed int offY_4222_0 = offY_4221_0 ? clap_511_0 : offY_4219_0;
      signed int offY_4224_0 = offY_4223_0 ? lambda_isp_oldlua_line1240_352_0 : offY_4222_0;
      signed int offY_4226_0 = offY_4225_0 ? clap_511_0 : offY_4224_0;
      signed int Rv_8330_pack_2 = lambda_isp_oldlua_line1240_352_0;
      signed int Rv_8302_0 = -Rv_8301_0;
      signed int Bv_2997_pack_7 = Rv_8302_0;
      signed int Gh_1992_pack_3 = Gh_1991_0;
      signed int Rv_8380_pack_4 = Rv_8332_0;
      signed int Gh_1992_pack_5 = lambda_isp_oldlua_line1240_358_0;
      signed int Rh_4219_pack_5 = Rv_8313_0;
      signed int Rh_4182_pack_0 = lambda_isp_oldlua_line1269_892_0;
      signed int Rh_4182_0 = Rh_4182_pack_2 + Rh_4182_pack_1 + Rh_4182_pack_0;
      signed int Rh_4183_0 = Rh_4182_0 >> lambda_isp_oldlua_line1240_348_0;
      signed int Bv_2976_pack_1 = Rv_8308_0;
      signed int Gv_1035_pack_1 = clap_511_0;
      signed int Bh_3022_pack_7 = Bh_3002_0;
      signed int Gv_1036_pack_1 = clap_512_0;
      signed int lambda_isp_oldlua_line1329_1380_0 = lambda_isp_oldlua_line1329_1379_0 - centroid_pos_1;
      signed int Rv_8334_pack_9 = Rv_8329_0;
      signed int Rv_8307_0 = lambda_isp_oldlua_line1269_890_0 << lambda_isp_oldlua_line1240_353_0;
      signed int Rv_8378_pack_2 = Rv_8307_0;
      signed int Bh_3035_pack_10 = Rv_8391_0;
      signed int clap_510_0 = c_1023_0;
      signed int Bv_3021_pack_1 = clap_510_0;
      signed int Gv_1030_pack_1 = clap_510_0;
      signed int Rv_8403_pack_1 = clap_510_0;
      signed int Bv_2970_pack_5 = Rv_8304_0;
      signed int Rv_8334_pack_5 = Rv_8308_0;
      signed int Rv_8334_pack_3 = lambda_isp_oldlua_line1269_888_0;
      signed int Bv_2976_pack_5 = lambda_isp_oldlua_line1240_349_0;
      signed int Rv_8334_pack_10 = Rv_8333_0;
      signed int Rv_8338_pack_3 = Rv_8329_0;
      signed int Rv_8356_0 = -lambda_isp_oldlua_line1269_899_0;
      signed int Rv_8360_pack_5 = Rv_8356_0;
      signed int Rv_8338_pack_5 = lambda_isp_oldlua_line1240_349_0;
      signed int Rh_4208_pack_8 = Rv_8319_0;
      signed int Bh_3035_pack_8 = Rh_4174_0;
      signed int Bh_3006_pack_11 = Rv_8348_0;
      signed int Rh_4193_pack_0 = Rv_8314_0;
      signed int Rh_4208_pack_4 = Rv_8349_0;
      signed int Bh_3035_pack_6 = Rv_8351_0;
      signed int Gh_1983_pack_2 = Rv_8319_0;
      signed int Rh_4188_pack_3 = lambda_isp_oldlua_line1269_888_0;
      signed int lambda_isp_oldlua_line1240_354_0 = c_8_0;
      signed int Rv_8296_0 = -lambda_isp_oldlua_line1269_888_0;
      signed int Rh_4184_pack_6 = Rv_8296_0;
      signed int Rv_8323_pack_6 = Rv_8296_0;
      signed int Bh_3052_pack_1 = clap_514_0;
      signed int Bv_2976_pack_4 = lambda_isp_oldlua_line1269_895_0;
      signed int Rv_8316_pack_1 = lambda_isp_oldlua_line1269_886_0;
      signed int Bv_2970_pack_0 = lambda_isp_oldlua_line1269_889_0;
      signed int Rv_8318_0 = -lambda_isp_oldlua_line1269_892_0;
      signed int Rh_4223_pack_10 = Rv_8318_0;
      signed int Rv_8360_pack_3 = Rv_8318_0;
      signed int Bh_3030_pack_4 = Rv_8318_0;
      signed int Rv_8378_pack_5 = Rv_8318_0;
      signed int Rh_4216_pack_4 = Rv_8318_0;
      signed int Bh_3035_pack_11 = Rv_8318_0;
      signed int pix_3018_0 = c_50_0;
      signed int Rh_4208_pack_2 = lambda_isp_oldlua_line1269_905_0;
      signed int Rv_8316_pack_3 = lambda_isp_oldlua_line1269_888_0;
      signed int Rv_8295_0 = lambda_isp_oldlua_line1269_887_0 << lambda_isp_oldlua_line1240_355_0;
      signed int Rh_4204_pack_1 = Rv_8295_0;
      signed int Rh_4173_0 = -Rv_8295_0;
      signed int Bh_3022_pack_8 = Rh_4173_0;
      signed int Rh_4206_pack_7 = Rh_4173_0;
      signed int Bh_3020_pack_8 = Rh_4173_0;
      signed int lambda_isp_oldlua_line1329_1371_0 = c_n8_0;
      signed int lambda_isp_oldlua_line1329_1410_0 = lambda_isp_oldlua_line1329_1409_0 + lambda_isp_oldlua_line1329_1371_0;
      signed int Rv_8283_0 = lambda_isp_oldlua_line1269_885_0 << lambda_isp_oldlua_line1240_348_0;
      signed int Bh_3006_pack_6 = Rv_8283_0;
      signed int Gh_1976_pack_1 = Rv_8283_0;
      signed int Bh_3004_pack_6 = Rv_8283_0;
      signed int Rh_4188_pack_5 = Rv_8283_0;
      signed int Rv_8323_pack_1 = Rv_8283_0;
      signed int Bh_3010_pack_1 = Rv_8283_0;
      signed int Rv_8284_0 = -Rv_8283_0;
      signed int Rv_8316_pack_7 = Rv_8284_0;
      signed int Rh_4180_pack_5 = Rv_8283_0;
      signed int Rh_4180_0 = Rh_4180_pack_8 + Rh_4180_pack_7 + Rh_4180_pack_6 + Rh_4180_pack_5 + Rh_4180_pack_4 + Rh_4180_pack_3 + Rh_4180_pack_2 + Rh_4180_pack_1 + Rh_4180_pack_0;
      signed int Rh_4193_pack_1 = Rv_8283_0;
      signed int Rv_8334_pack_7 = Rv_8284_0;
      signed int Bh_3004_0 = Bh_3004_pack_8 + Bh_3004_pack_7 + Bh_3004_pack_6 + Bh_3004_pack_5 + Bh_3004_pack_4 + Bh_3004_pack_3 + Bh_3004_pack_2 + Bh_3004_pack_1 + Bh_3004_pack_0;
      signed int Bh_3005_0 = Bh_3004_0 >> lambda_isp_oldlua_line1240_349_0;
      signed int Bv_2970_pack_8 = Rv_8284_0;
      signed int lambda_isp_oldlua_line1329_1388_0 = lambda_isp_oldlua_line1329_1387_0 - centroid_pos_1;
      signed int lambda_isp_oldlua_line1240_356_0 = c_2_0;
      bool offY_4231_0 = lambda_isp_oldlua_line1240_356_0 == offY_4230_0;
      signed int Rh_4175_0 = lambda_isp_oldlua_line1269_889_0 << lambda_isp_oldlua_line1240_356_0;
      bool offY_4236_0 = lambda_isp_oldlua_line1240_356_0 == lambda_isp_oldlua_line1240_356_0;
      signed int offY_4232_0 = offY_4231_0 ? lambda_isp_oldlua_line1240_355_0 : lambda_isp_oldlua_line1240_356_0;
      bool offY_4234_0 = lambda_isp_oldlua_line1240_356_0 == offY_4233_0;
      signed int Gh_1983_pack_5 = lambda_isp_oldlua_line1240_356_0;
      signed int Bh_3017_pack_5 = lambda_isp_oldlua_line1240_356_0;
      signed int offY_4235_0 = offY_4234_0 ? clap_513_0 : offY_4232_0;
      signed int offY_4237_0 = offY_4236_0 ? lambda_isp_oldlua_line1240_355_0 : offY_4235_0;
      signed int Bh_3022_pack_4 = lambda_isp_oldlua_line1240_356_0;
      signed int Rh_4204_pack_7 = lambda_isp_oldlua_line1240_356_0;
      signed int Rh_4201_pack_5 = lambda_isp_oldlua_line1240_356_0;
      signed int Rv_8320_0 = lambda_isp_oldlua_line1269_892_0 << lambda_isp_oldlua_line1240_356_0;
      signed int Bh_3017_pack_2 = Rv_8320_0;
      signed int Rh_4204_pack_2 = Rv_8320_0;
      signed int offX_2291_0 = offY_4231_0 ? clap_513_0 : lambda_isp_oldlua_line1240_356_0;
      signed int offX_2292_0 = offY_4234_0 ? lambda_isp_oldlua_line1240_355_0 : offX_2291_0;
      signed int offX_2293_0 = offY_4236_0 ? lambda_isp_oldlua_line1240_355_0 : offX_2292_0;
      signed int Rh_4206_pack_8 = lambda_isp_oldlua_line1240_356_0;
      signed int Bh_3020_pack_4 = lambda_isp_oldlua_line1240_356_0;
      signed int Gh_1992_pack_2 = Rv_8286_0;
      signed int Bv_2970_pack_2 = lambda_isp_oldlua_line1269_887_0;
      signed int lambda_isp_oldlua_line1329_1393_0 = centroid_pos_0 + lambda_isp_oldlua_line1329_1392_0;
      signed int lambda_isp_oldlua_line1329_1394_0 = lambda_isp_oldlua_line1329_1393_0 + lambda_isp_oldlua_line1329_1359_0;
      signed int Gh_1992_pack_4 = Rv_8318_0;
      signed int Rv_8357_pack_8 = Rv_8311_0;
      signed int Rv_8397_pack_1 = clap_507_0;
      signed int Rh_4171_0 = lambda_isp_oldlua_line1269_886_0 << lambda_isp_oldlua_line1240_358_0;
      signed int Rh_4172_0 = -Rh_4171_0;
      signed int Rh_4221_pack_6 = Rh_4172_0;
      signed int Rh_4223_pack_6 = Rh_4172_0;
      signed int Bv_2970_pack_4 = lambda_isp_oldlua_line1240_349_0;
      signed int Rv_8380_pack_3 = lambda_isp_oldlua_line1269_885_0;
      signed int lambda_isp_oldlua_line1329_1382_0 = lambda_isp_oldlua_line1329_1380_0 + lambda_isp_oldlua_line1329_1381_0;
      signed int lambda_isp_oldlua_line1329_1383_0 = lambda_isp_oldlua_line1329_1382_0 + lambda_isp_oldlua_line1329_1350_0;
      signed int lambda_isp_oldlua_line1329_1399_0 = lambda_isp_oldlua_line1329_1398_0 + lambda_isp_oldlua_line1329_1362_0;
      signed int grPix_3997_0 = lambda_isp_oldlua_line1329_1399_0 + offY_4226_0;
      signed int grPix_3998_0 = grPix_3997_0 & lambda_isp_oldlua_line1240_352_0;
      bool grPix_3999_0 = grPix_3998_0 != clap_511_0;
      bool grPix_4000_0 = !grPix_3999_0;
      signed int Rv_8380_pack_1 = lambda_isp_oldlua_line1269_902_0;
      bool grPix_4003_0 = grPix_4002_0 != clap_511_0;
      bool rPix_845_0 = grPix_4000_0 & grPix_4003_0;
      bool gbPix_845_0 = grPix_3999_0 & grPix_4003_0;
      signed int gbPix_846_0 = gbPix_845_0 ? lambda_isp_oldlua_line1240_352_0 : clap_511_0;
      bool pix_3034_0 = gbPix_846_0 == lambda_isp_oldlua_line1240_352_0;
      signed int rPix_846_0 = rPix_845_0 ? lambda_isp_oldlua_line1240_352_0 : clap_511_0;
      bool pix_3035_0 = rPix_846_0 == lambda_isp_oldlua_line1240_352_0;
      signed int pix_3036_0 = pix_3035_0 ? pix_2992_0 : pix_2991_0;
      bool grPix_4004_0 = !grPix_4003_0;
      signed int Rv_8357_pack_2 = lambda_isp_oldlua_line1269_899_0;
      signed int Rh_4208_pack_11 = lambda_isp_oldlua_line1240_356_0;
      signed int lambda_isp_oldlua_line1269_904_0 = lambda_isp_oldlua_line1282_848_pp_0_3;
      signed int Rv_8388_0 = -lambda_isp_oldlua_line1269_904_0;
      signed int Gh_1983_pack_4 = Rv_8388_0;
      signed int Bh_3022_pack_11 = Rv_8388_0;
      signed int Bh_3017_pack_4 = Rv_8388_0;
      signed int Rh_4201_pack_4 = Rv_8388_0;
      signed int Rh_4208_pack_10 = Rv_8388_0;
      signed int offY_4240_0 = c_344_0;
      signed int Rv_8357_pack_0 = lambda_isp_oldlua_line1269_892_0;
      signed int Bh_3030_pack_2 = Rv_8287_0;
      signed int Rh_4181_0 = Rh_4180_0 >> lambda_isp_oldlua_line1240_349_0;
      signed int Bh_3020_pack_2 = lambda_isp_oldlua_line1269_905_0;
      signed int Gv_1023_pack_1 = clap_507_0;
      signed int lambda_isp_oldlua_line1228_6085_pack_1 = clap_508_0;
      signed int Rv_8375_pack_2 = lambda_isp_oldlua_line1269_892_0;
      signed int Rv_8380_pack_6 = Rv_8302_0;
      signed int Rv_8315_0 = -Rv_8314_0;
      signed int Rv_8316_pack_6 = Rv_8315_0;
      signed int Rv_8334_pack_6 = Rv_8315_0;
      signed int Rv_8316_0 = Rv_8316_pack_8 + Rv_8316_pack_7 + Rv_8316_pack_6 + Rv_8316_pack_5 + Rv_8316_pack_4 + Rv_8316_pack_3 + Rv_8316_pack_2 + Rv_8316_pack_1 + Rv_8316_pack_0;
      signed int Rv_8317_0 = Rv_8316_0 >> lambda_isp_oldlua_line1240_349_0;
      signed int Rv_8362_pack_1 = lambda_isp_oldlua_line1269_885_0;
      signed int Rh_4201_pack_0 = Rv_8349_0;
      signed int Rv_8359_0 = -lambda_isp_oldlua_line1269_900_0;
      signed int Rv_8360_pack_6 = Rv_8359_0;
      signed int Rv_8338_pack_4 = Rv_8333_0;
      signed int Rh_4201_pack_2 = Rv_8319_0;
      signed int Rv_8289_0 = lambda_isp_oldlua_line1269_886_0 << lambda_isp_oldlua_line1240_352_0;
      signed int Rv_8378_pack_1 = Rv_8289_0;
      signed int Rv_8290_0 = -Rv_8289_0;
      signed int Rv_8375_pack_7 = Rv_8290_0;
      signed int Bv_2997_pack_8 = Rv_8290_0;
      signed int Rv_8380_pack_7 = Rv_8290_0;
      signed int offY_4193_0 = offY_4192_0 ? lambda_isp_oldlua_line1240_348_0 : lambda_isp_oldlua_line1240_349_0;
      signed int offY_4196_0 = offY_4195_0 ? clap_507_0 : offY_4193_0;
      signed int offY_4198_0 = offY_4197_0 ? lambda_isp_oldlua_line1240_348_0 : offY_4196_0;
      signed int offY_4200_0 = offY_4199_0 ? clap_507_0 : offY_4198_0;
      bool offY_4202_0 = offY_4200_0 != lambda_isp_oldlua_line1240_349_0;
      signed int Rh_4208_pack_7 = Rh_4173_0;
      signed int lambda_isp_oldlua_line1269_893_0 = lambda_isp_oldlua_line1282_848_pp_3_3;
      signed int Rv_8321_0 = lambda_isp_oldlua_line1269_893_0 << lambda_isp_oldlua_line1240_348_0;
      signed int Gh_1976_pack_2 = Rv_8321_0;
      signed int Rh_4199_pack_0 = lambda_isp_oldlua_line1269_893_0;
      signed int Gh_1976_0 = Gh_1976_pack_5 + Gh_1976_pack_4 + Gh_1976_pack_3 + Gh_1976_pack_2 + Gh_1976_pack_1 + Gh_1976_pack_0;
      signed int Gh_1977_0 = Gh_1976_0 >> lambda_isp_oldlua_line1240_349_0;
      signed int Bh_3006_pack_9 = Rv_8321_0;
      signed int Rv_8345_pack_0 = lambda_isp_oldlua_line1269_893_0;
      signed int Rh_4188_pack_8 = Rv_8321_0;
      signed int Rv_8345_0 = Rv_8345_pack_2 + Rv_8345_pack_1 + Rv_8345_pack_0;
      signed int Rv_8346_0 = Rv_8345_0 >> lambda_isp_oldlua_line1240_350_0;
      signed int Rv_8328_0 = lambda_isp_oldlua_line1269_893_0 << lambda_isp_oldlua_line1240_357_0;
      signed int Bh_3035_pack_5 = Rv_8328_0;
      signed int Rh_4221_pack_4 = Rv_8328_0;
      signed int Rh_4223_pack_4 = Rv_8328_0;
      signed int Rh_4221_0 = Rh_4221_pack_8 + Rh_4221_pack_7 + Rh_4221_pack_6 + Rh_4221_pack_5 + Rh_4221_pack_4 + Rh_4221_pack_3 + Rh_4221_pack_2 + Rh_4221_pack_1 + Rh_4221_pack_0;
      signed int Rh_4222_0 = Rh_4221_0 >> lambda_isp_oldlua_line1240_358_0;
      signed int Gh_1978_0 = Rv_8065_0 ? Gh_1977_0 : Rh_4183_0;
      signed int Bh_3033_pack_5 = Rv_8328_0;
      signed int Bh_3033_0 = Bh_3033_pack_8 + Bh_3033_pack_7 + Bh_3033_pack_6 + Bh_3033_pack_5 + Bh_3033_pack_4 + Bh_3033_pack_3 + Bh_3033_pack_2 + Bh_3033_pack_1 + Bh_3033_pack_0;
      signed int Rh_4188_0 = Rh_4188_pack_11 + Rh_4188_pack_10 + Rh_4188_pack_9 + Rh_4188_pack_8 + Rh_4188_pack_7 + Rh_4188_pack_6 + Rh_4188_pack_5 + Rh_4188_pack_4 + Rh_4188_pack_3 + Rh_4188_pack_2 + Rh_4188_pack_1 + Rh_4188_pack_0;
      signed int Bh_3034_0 = Bh_3033_0 >> lambda_isp_oldlua_line1240_358_0;
      signed int Rh_4216_pack_0 = Rv_8328_0;
      signed int Rh_4216_0 = Rh_4216_pack_5 + Rh_4216_pack_4 + Rh_4216_pack_3 + Rh_4216_pack_2 + Rh_4216_pack_1 + Rh_4216_pack_0;
      signed int Rh_4217_0 = Rh_4216_0 >> lambda_isp_oldlua_line1240_358_0;
      signed int Rv_8326_0 = lambda_isp_oldlua_line1269_893_0 << lambda_isp_oldlua_line1240_352_0;
      signed int Rv_8375_pack_5 = Rv_8326_0;
      signed int Bv_2997_pack_6 = Rv_8326_0;
      signed int Bv_2997_0 = Bv_2997_pack_8 + Bv_2997_pack_7 + Bv_2997_pack_6 + Bv_2997_pack_5 + Bv_2997_pack_4 + Bv_2997_pack_3 + Bv_2997_pack_2 + Bv_2997_pack_1 + Bv_2997_pack_0;
      signed int Bv_2998_0 = Bv_2997_0 >> lambda_isp_oldlua_line1240_353_0;
      signed int Bv_2994_pack_1 = Rv_8326_0;
      signed int Bv_2994_0 = Bv_2994_pack_5 + Bv_2994_pack_4 + Bv_2994_pack_3 + Bv_2994_pack_2 + Bv_2994_pack_1 + Bv_2994_pack_0;
      signed int Bv_2995_0 = Bv_2994_0 >> lambda_isp_oldlua_line1240_353_0;
      signed int Rh_4186_pack_1 = lambda_isp_oldlua_line1269_893_0;
      signed int Rv_8325_0 = lambda_isp_oldlua_line1269_893_0 << lambda_isp_oldlua_line1240_350_0;
      signed int Bv_2982_pack_0 = Rv_8325_0;
      signed int Bv_2985_pack_5 = Rv_8325_0;
      signed int Rv_8362_pack_4 = Rv_8325_0;
      signed int Rv_8353_pack_0 = Rv_8325_0;
      signed int Bh_3030_pack_0 = Rv_8328_0;
      signed int Bh_3030_0 = Bh_3030_pack_5 + Bh_3030_pack_4 + Bh_3030_pack_3 + Bh_3030_pack_2 + Bh_3030_pack_1 + Bh_3030_pack_0;
      signed int Bh_3031_0 = Bh_3030_0 >> lambda_isp_oldlua_line1240_358_0;
      signed int Rh_4223_0 = Rh_4223_pack_11 + Rh_4223_pack_10 + Rh_4223_pack_9 + Rh_4223_pack_8 + Rh_4223_pack_7 + Rh_4223_pack_6 + Rh_4223_pack_5 + Rh_4223_pack_4 + Rh_4223_pack_3 + Rh_4223_pack_2 + Rh_4223_pack_1 + Rh_4223_pack_0;
      signed int Rh_4224_0 = Rh_4223_0 >> lambda_isp_oldlua_line1240_358_0;
      signed int Rh_4225_0 = Rv_8165_0 ? Rh_4224_0 : Rh_4222_0;
      signed int Rh_4193_pack_2 = Rv_8321_0;
      signed int Rh_4193_0 = Rh_4193_pack_5 + Rh_4193_pack_4 + Rh_4193_pack_3 + Rh_4193_pack_2 + Rh_4193_pack_1 + Rh_4193_pack_0;
      signed int Rh_4194_0 = Rh_4193_0 >> lambda_isp_oldlua_line1240_349_0;
      signed int Bv_2976_pack_2 = Rv_8321_0;
      signed int Bv_2976_0 = Bv_2976_pack_5 + Bv_2976_pack_4 + Bv_2976_pack_3 + Bv_2976_pack_2 + Bv_2976_pack_1 + Bv_2976_pack_0;
      signed int Bv_2977_0 = Bv_2976_0 >> lambda_isp_oldlua_line1240_349_0;
      signed int Rh_4189_0 = Rh_4188_0 >> lambda_isp_oldlua_line1240_349_0;
      signed int Rh_4190_0 = Rv_8065_0 ? Rh_4189_0 : Rh_4181_0;
      signed int Rv_8334_pack_8 = Rv_8321_0;
      signed int Rv_8338_pack_2 = Rv_8321_0;
      signed int Rv_8338_0 = Rv_8338_pack_5 + Rv_8338_pack_4 + Rv_8338_pack_3 + Rv_8338_pack_2 + Rv_8338_pack_1 + Rv_8338_pack_0;
      signed int Rv_8339_0 = Rv_8338_0 >> lambda_isp_oldlua_line1240_349_0;
      signed int Rv_8327_0 = lambda_isp_oldlua_line1269_893_0 << lambda_isp_oldlua_line1240_355_0;
      signed int Bh_3017_pack_1 = Rv_8327_0;
      signed int Bh_3022_pack_6 = Rv_8327_0;
      signed int Rh_4206_pack_5 = Rv_8327_0;
      signed int Bh_3035_0 = Bh_3035_pack_11 + Bh_3035_pack_10 + Bh_3035_pack_9 + Bh_3035_pack_8 + Bh_3035_pack_7 + Bh_3035_pack_6 + Bh_3035_pack_5 + Bh_3035_pack_4 + Bh_3035_pack_3 + Bh_3035_pack_2 + Bh_3035_pack_1 + Bh_3035_pack_0;
      signed int Bh_3036_0 = Bh_3035_0 >> lambda_isp_oldlua_line1240_358_0;
      signed int Bh_3037_0 = Rv_8165_0 ? Bh_3036_0 : Bh_3034_0;
      signed int Bh_3020_pack_6 = Rv_8327_0;
      signed int Rv_8330_pack_1 = lambda_isp_oldlua_line1269_893_0;
      signed int Rv_8330_0 = Rv_8330_pack_2 + Rv_8330_pack_1 + Rv_8330_pack_0;
      signed int Rv_8331_0 = Rv_8330_0 >> lambda_isp_oldlua_line1240_352_0;
      signed int Rh_4199_0 = Rh_4199_pack_2 + Rh_4199_pack_1 + Rh_4199_pack_0;
      signed int Rh_4186_0 = Rh_4186_pack_2 + Rh_4186_pack_1 + Rh_4186_pack_0;
      signed int Rh_4187_0 = Rh_4186_0 >> lambda_isp_oldlua_line1240_355_0;
      signed int Rh_4201_pack_1 = Rv_8327_0;
      signed int Rv_8371_pack_1 = Rv_8326_0;
      signed int Rv_8371_0 = Rv_8371_pack_5 + Rv_8371_pack_4 + Rv_8371_pack_3 + Rv_8371_pack_2 + Rv_8371_pack_1 + Rv_8371_pack_0;
      signed int Rv_8372_0 = Rv_8371_0 >> lambda_isp_oldlua_line1240_353_0;
      signed int Rv_8380_pack_5 = Rv_8326_0;
      signed int Rv_8380_0 = Rv_8380_pack_8 + Rv_8380_pack_7 + Rv_8380_pack_6 + Rv_8380_pack_5 + Rv_8380_pack_4 + Rv_8380_pack_3 + Rv_8380_pack_2 + Rv_8380_pack_1 + Rv_8380_pack_0;
      signed int Rv_8381_0 = Rv_8380_0 >> lambda_isp_oldlua_line1240_353_0;
      signed int Gh_1983_pack_1 = Rv_8327_0;
      signed int Bv_2996_0 = Rv_8130_0 ? Bv_2995_0 : Rv_8331_0;
      signed int Gh_1992_pack_0 = Rv_8328_0;
      signed int Rv_8357_pack_4 = Rv_8325_0;
      signed int Rv_8322_0 = lambda_isp_oldlua_line1269_893_0 << lambda_isp_oldlua_line1240_349_0;
      signed int Rh_4184_pack_2 = Rv_8322_0;
      signed int Rv_8323_pack_2 = Rv_8322_0;
      signed int Rv_8323_0 = Rv_8323_pack_7 + Rv_8323_pack_6 + Rv_8323_pack_5 + Rv_8323_pack_4 + Rv_8323_pack_3 + Rv_8323_pack_2 + Rv_8323_pack_1 + Rv_8323_pack_0;
      signed int Rv_8324_0 = Rv_8323_0 >> lambda_isp_oldlua_line1240_349_0;
      signed int Rh_4184_0 = Rh_4184_pack_7 + Rh_4184_pack_6 + Rh_4184_pack_5 + Rh_4184_pack_4 + Rh_4184_pack_3 + Rh_4184_pack_2 + Rh_4184_pack_1 + Rh_4184_pack_0;
      signed int Bh_3010_pack_2 = Rv_8322_0;
      signed int Bh_3010_0 = Bh_3010_pack_5 + Bh_3010_pack_4 + Bh_3010_pack_3 + Bh_3010_pack_2 + Bh_3010_pack_1 + Bh_3010_pack_0;
      signed int Bh_3011_0 = Bh_3010_0 >> lambda_isp_oldlua_line1240_349_0;
      signed int Bh_3012_0 = Rv_8065_0 ? Bh_3011_0 : Rh_4183_0;
      signed int Rh_4185_0 = Rh_4184_0 >> lambda_isp_oldlua_line1240_349_0;
      signed int Rh_4208_pack_5 = Rv_8327_0;
      signed int pix_3012_0 = c_80_0;
      signed int lambda_isp_oldlua_line1329_1389_0 = c_7_0;
      signed int lambda_isp_oldlua_line1329_1390_0 = lambda_isp_oldlua_line1329_1388_0 + lambda_isp_oldlua_line1329_1389_0;
      signed int lambda_isp_oldlua_line1329_1391_0 = lambda_isp_oldlua_line1329_1390_0 + lambda_isp_oldlua_line1329_1356_0;
      signed int lambda_isp_oldlua_line1228_6015_pack_2 = lambda_isp_oldlua_line1240_348_0;
      signed int Rh_4208_pack_3 = lambda_isp_oldlua_line1269_891_0;
      signed int lambda_isp_oldlua_line1329_1415_0 = lambda_isp_oldlua_line1329_1414_0 + lambda_isp_oldlua_line1329_1374_0;
      signed int grPix_4017_0 = lambda_isp_oldlua_line1329_1415_0 + offY_4252_0;
      signed int grPix_4018_0 = grPix_4017_0 & lambda_isp_oldlua_line1240_357_0;
      bool grPix_4019_0 = grPix_4018_0 != clap_515_0;
      bool grPix_4020_0 = !grPix_4019_0;
      bool Rv_8155_0 = c_0x0_0;
      signed int lambda_isp_oldlua_line1269_906_0 = lambda_isp_oldlua_line1282_848_pp_1_4;
      signed int Bh_3020_pack_0 = lambda_isp_oldlua_line1269_906_0;
      signed int Rv_8390_0 = -lambda_isp_oldlua_line1269_906_0;
      signed int Rh_4204_pack_3 = Rv_8390_0;
      signed int Rh_4204_0 = Rh_4204_pack_7 + Rh_4204_pack_6 + Rh_4204_pack_5 + Rh_4204_pack_4 + Rh_4204_pack_3 + Rh_4204_pack_2 + Rh_4204_pack_1 + Rh_4204_pack_0;
      signed int Rh_4205_0 = Rh_4204_0 >> lambda_isp_oldlua_line1240_356_0;
      signed int Bh_3020_0 = Bh_3020_pack_8 + Bh_3020_pack_7 + Bh_3020_pack_6 + Bh_3020_pack_5 + Bh_3020_pack_4 + Bh_3020_pack_3 + Bh_3020_pack_2 + Bh_3020_pack_1 + Bh_3020_pack_0;
      signed int Bh_3021_0 = Bh_3020_0 >> lambda_isp_oldlua_line1240_356_0;
      signed int Rh_4208_pack_0 = lambda_isp_oldlua_line1269_906_0;
      signed int Bh_3022_pack_0 = lambda_isp_oldlua_line1269_906_0;
      bool offY_4228_0 = offY_4226_0 != lambda_isp_oldlua_line1240_353_0;
      signed int pix_2998_0 = c_50_0;
      signed int Bv_2970_pack_1 = lambda_isp_oldlua_line1269_886_0;
      bool grPix_4005_0 = grPix_4000_0 & grPix_4004_0;
      signed int grPix_4006_0 = grPix_4005_0 ? lambda_isp_oldlua_line1240_352_0 : clap_511_0;
      bool pix_3033_0 = grPix_4006_0 == lambda_isp_oldlua_line1240_352_0;
      bool offY_4238_0 = lambda_isp_oldlua_line1240_356_0 == lambda_isp_oldlua_line1240_355_0;
      signed int offY_4239_0 = offY_4238_0 ? clap_513_0 : offY_4237_0;
      signed int grPix_4007_0 = lambda_isp_oldlua_line1329_1407_0 + offY_4239_0;
      bool offY_4241_0 = offY_4239_0 != lambda_isp_oldlua_line1240_356_0;
      signed int offX_2294_0 = offY_4238_0 ? clap_513_0 : offX_2293_0;
      bool offX_2296_0 = offX_2294_0 != lambda_isp_oldlua_line1240_356_0;
      signed int grPix_4011_0 = lambda_isp_oldlua_line1329_1410_0 + offX_2294_0;
      signed int grPix_4012_0 = grPix_4011_0 & lambda_isp_oldlua_line1240_355_0;
      signed int grPix_4008_0 = grPix_4007_0 & lambda_isp_oldlua_line1240_355_0;
      bool grPix_4009_0 = grPix_4008_0 != clap_513_0;
      bool grPix_4010_0 = !grPix_4009_0;
      bool grPix_4013_0 = grPix_4012_0 != clap_513_0;
      bool gbPix_847_0 = grPix_4009_0 & grPix_4013_0;
      bool rPix_847_0 = grPix_4010_0 & grPix_4013_0;
      signed int gbPix_848_0 = gbPix_847_0 ? lambda_isp_oldlua_line1240_355_0 : clap_513_0;
      bool grPix_4014_0 = !grPix_4013_0;
      bool grPix_4015_0 = grPix_4010_0 & grPix_4014_0;
      signed int grPix_4016_0 = grPix_4015_0 ? lambda_isp_oldlua_line1240_355_0 : clap_513_0;
      bool pix_3039_0 = grPix_4016_0 == lambda_isp_oldlua_line1240_355_0;
      signed int rPix_848_0 = rPix_847_0 ? lambda_isp_oldlua_line1240_355_0 : clap_513_0;
      bool pix_3041_0 = rPix_848_0 == lambda_isp_oldlua_line1240_355_0;
      signed int pix_3042_0 = pix_3041_0 ? pix_3002_0 : pix_3001_0;
      bool pix_3040_0 = gbPix_848_0 == lambda_isp_oldlua_line1240_355_0;
      signed int pix_3043_0 = pix_3040_0 ? pix_3005_0 : pix_3042_0;
      signed int Rh_4245_pack_1 = clap_516_0;
      signed int Rv_8285_0 = -lambda_isp_oldlua_line1269_885_0;
      signed int Bh_3017_pack_3 = Rv_8285_0;
      signed int Rv_8360_pack_4 = Rv_8285_0;
      signed int Bh_3022_pack_10 = Rv_8285_0;
      signed int Rv_8378_pack_6 = Rv_8285_0;
      signed int Rv_8360_0 = Rv_8360_pack_7 + Rv_8360_pack_6 + Rv_8360_pack_5 + Rv_8360_pack_4 + Rv_8360_pack_3 + Rv_8360_pack_2 + Rv_8360_pack_1 + Rv_8360_pack_0;
      signed int Rv_8361_0 = Rv_8360_0 >> lambda_isp_oldlua_line1240_351_0;
      signed int Bh_3022_0 = Bh_3022_pack_11 + Bh_3022_pack_10 + Bh_3022_pack_9 + Bh_3022_pack_8 + Bh_3022_pack_7 + Bh_3022_pack_6 + Bh_3022_pack_5 + Bh_3022_pack_4 + Bh_3022_pack_3 + Bh_3022_pack_2 + Bh_3022_pack_1 + Bh_3022_pack_0;
      signed int Bh_3023_0 = Bh_3022_0 >> lambda_isp_oldlua_line1240_356_0;
      signed int Bh_3024_0 = Rv_8155_0 ? Bh_3023_0 : Bh_3021_0;
      signed int Bh_3017_0 = Bh_3017_pack_5 + Bh_3017_pack_4 + Bh_3017_pack_3 + Bh_3017_pack_2 + Bh_3017_pack_1 + Bh_3017_pack_0;
      signed int Bh_3018_0 = Bh_3017_0 >> lambda_isp_oldlua_line1240_356_0;
      signed int Bh_3019_0 = Rv_8155_0 ? Bh_3018_0 : Rh_4187_0;
      signed int Rv_8378_0 = Rv_8378_pack_7 + Rv_8378_pack_6 + Rv_8378_pack_5 + Rv_8378_pack_4 + Rv_8378_pack_3 + Rv_8378_pack_2 + Rv_8378_pack_1 + Rv_8378_pack_0;
      signed int Rv_8379_0 = Rv_8378_0 >> lambda_isp_oldlua_line1240_353_0;
      signed int Rh_4208_pack_9 = Rv_8285_0;
      signed int Rv_8298_0 = -Rv_8297_0;
      signed int Rv_8362_pack_7 = Rv_8298_0;
      signed int Bv_2985_pack_8 = Rv_8298_0;
      signed int Rv_8357_pack_7 = Rv_8298_0;
      signed int lambda_isp_oldlua_line1228_6084_pack_1 = clap_507_0;
      signed int Bv_2982_pack_2 = Rv_8311_0;
      signed int Bv_2982_0 = Bv_2982_pack_5 + Bv_2982_pack_4 + Bv_2982_pack_3 + Bv_2982_pack_2 + Bv_2982_pack_1 + Bv_2982_pack_0;
      signed int Rh_4176_0 = -Rh_4175_0;
      signed int Rh_4206_pack_6 = Rh_4176_0;
      signed int Rh_4208_pack_6 = Rh_4176_0;
      signed int Rv_8373_0 = Rv_8130_0 ? Rv_8372_0 : Rv_8331_0;
      signed int Rh_4208_pack_1 = lambda_isp_oldlua_line1269_890_0;
      signed int Rh_4208_0 = Rh_4208_pack_11 + Rh_4208_pack_10 + Rh_4208_pack_9 + Rh_4208_pack_8 + Rh_4208_pack_7 + Rh_4208_pack_6 + Rh_4208_pack_5 + Rh_4208_pack_4 + Rh_4208_pack_3 + Rh_4208_pack_2 + Rh_4208_pack_1 + Rh_4208_pack_0;
      signed int Rh_4209_0 = Rh_4208_0 >> lambda_isp_oldlua_line1240_356_0;
      signed int Rv_8352_0 = -lambda_isp_oldlua_line1269_898_0;
      signed int Rv_8357_pack_10 = Rv_8352_0;
      signed int Rv_8353_pack_4 = Rv_8352_0;
      signed int Rv_8353_0 = Rv_8353_pack_5 + Rv_8353_pack_4 + Rv_8353_pack_3 + Rv_8353_pack_2 + Rv_8353_pack_1 + Rv_8353_pack_0;
      signed int Rv_8354_0 = Rv_8353_0 >> lambda_isp_oldlua_line1240_351_0;
      signed int Rv_8355_0 = Rv_8079_0 ? Rv_8354_0 : Rv_8346_0;
      signed int Rh_4200_0 = Rh_4199_0 >> lambda_isp_oldlua_line1240_357_0;
      signed int Bh_3032_0 = Rv_8165_0 ? Bh_3031_0 : Rh_4200_0;
      signed int Rh_4218_0 = Rv_8165_0 ? Rh_4217_0 : Rh_4200_0;
      signed int offX_2300_0 = offY_4249_0 ? lambda_isp_oldlua_line1240_357_0 : offX_2299_0;
      signed int offX_2301_0 = offY_4251_0 ? clap_515_0 : offX_2300_0;
      bool offX_2303_0 = offX_2301_0 != lambda_isp_oldlua_line1240_358_0;
      signed int grPix_4021_0 = lambda_isp_oldlua_line1329_1418_0 + offX_2301_0;
      signed int grPix_4022_0 = grPix_4021_0 & lambda_isp_oldlua_line1240_357_0;
      bool grPix_4023_0 = grPix_4022_0 != clap_515_0;
      bool rPix_849_0 = grPix_4020_0 & grPix_4023_0;
      bool gbPix_849_0 = grPix_4019_0 & grPix_4023_0;
      signed int gbPix_850_0 = gbPix_849_0 ? lambda_isp_oldlua_line1240_357_0 : clap_515_0;
      signed int rPix_850_0 = rPix_849_0 ? lambda_isp_oldlua_line1240_357_0 : clap_515_0;
      bool pix_3046_0 = gbPix_850_0 == lambda_isp_oldlua_line1240_357_0;
      bool grPix_4024_0 = !grPix_4023_0;
      bool pix_3047_0 = rPix_850_0 == lambda_isp_oldlua_line1240_357_0;
      signed int pix_3048_0 = pix_3047_0 ? pix_3012_0 : pix_3011_0;
      signed int pix_3049_0 = pix_3046_0 ? pix_3015_0 : pix_3048_0;
      bool grPix_4025_0 = grPix_4020_0 & grPix_4024_0;
      signed int grPix_4026_0 = grPix_4025_0 ? lambda_isp_oldlua_line1240_357_0 : clap_515_0;
      bool pix_3045_0 = grPix_4026_0 == lambda_isp_oldlua_line1240_357_0;
      signed int pix_3050_0 = pix_3045_0 ? pix_3018_0 : pix_3049_0;
      bool Gv_1040_0 = pix_3050_0 == pix_3018_0;
      bool Gv_1039_0 = pix_3050_0 == pix_3015_0;
      bool Bv_3031_0 = pix_3050_0 == pix_3011_0;
      signed int Bh_3053_0 = Bv_3031_0 ? lambda_isp_oldlua_line1269_885_0 : Bh_3037_0;
      signed int Bh_3054_0 = Gv_1039_0 ? Bh_3032_0 : Bh_3053_0;
      signed int Gh_1992_0 = Gh_1992_pack_5 + Gh_1992_pack_4 + Gh_1992_pack_3 + Gh_1992_pack_2 + Gh_1992_pack_1 + Gh_1992_pack_0;
      signed int Gh_1993_0 = Gh_1992_0 >> lambda_isp_oldlua_line1240_358_0;
      signed int offY_4204_0 = c_4_0;
      bool offY_4205_0 = lambda_isp_oldlua_line1240_351_0 == offY_4204_0;
      signed int offY_4206_0 = offY_4205_0 ? lambda_isp_oldlua_line1240_350_0 : lambda_isp_oldlua_line1240_351_0;
      signed int offY_4209_0 = offY_4208_0 ? clap_509_0 : offY_4206_0;
      signed int offY_4211_0 = offY_4210_0 ? lambda_isp_oldlua_line1240_350_0 : offY_4209_0;
      signed int offY_4213_0 = offY_4212_0 ? clap_509_0 : offY_4211_0;
      bool offY_4215_0 = offY_4213_0 != lambda_isp_oldlua_line1240_351_0;
      signed int grPix_3987_0 = lambda_isp_oldlua_line1329_1391_0 + offY_4213_0;
      signed int grPix_3988_0 = grPix_3987_0 & lambda_isp_oldlua_line1240_350_0;
      bool grPix_3989_0 = grPix_3988_0 != clap_509_0;
      bool grPix_3990_0 = !grPix_3989_0;
      signed int offX_2277_0 = offY_4205_0 ? clap_509_0 : lambda_isp_oldlua_line1240_351_0;
      signed int offX_2278_0 = offY_4208_0 ? lambda_isp_oldlua_line1240_350_0 : offX_2277_0;
      signed int offX_2279_0 = offY_4210_0 ? lambda_isp_oldlua_line1240_350_0 : offX_2278_0;
      signed int offX_2280_0 = offY_4212_0 ? clap_509_0 : offX_2279_0;
      bool offX_2282_0 = offX_2280_0 != lambda_isp_oldlua_line1240_351_0;
      signed int grPix_3991_0 = lambda_isp_oldlua_line1329_1394_0 + offX_2280_0;
      signed int grPix_3992_0 = grPix_3991_0 & lambda_isp_oldlua_line1240_350_0;
      bool grPix_3993_0 = grPix_3992_0 != clap_509_0;
      bool gbPix_843_0 = grPix_3989_0 & grPix_3993_0;
      bool rPix_843_0 = grPix_3990_0 & grPix_3993_0;
      signed int rPix_844_0 = rPix_843_0 ? lambda_isp_oldlua_line1240_350_0 : clap_509_0;
      bool pix_3029_0 = rPix_844_0 == lambda_isp_oldlua_line1240_350_0;
      signed int pix_3030_0 = pix_3029_0 ? pix_2982_0 : pix_2981_0;
      bool grPix_3994_0 = !grPix_3993_0;
      bool grPix_3995_0 = grPix_3990_0 & grPix_3994_0;
      signed int grPix_3996_0 = grPix_3995_0 ? lambda_isp_oldlua_line1240_350_0 : clap_509_0;
      bool pix_3027_0 = grPix_3996_0 == lambda_isp_oldlua_line1240_350_0;
      signed int gbPix_844_0 = gbPix_843_0 ? lambda_isp_oldlua_line1240_350_0 : clap_509_0;
      bool pix_3028_0 = gbPix_844_0 == lambda_isp_oldlua_line1240_350_0;
      signed int Rh_4240_pack_1 = clap_514_0;
      signed int lambda_isp_oldlua_line1228_6011_pack_2 = lambda_isp_oldlua_line1240_348_0;
      signed int Rv_8309_pack_1 = lambda_isp_oldlua_line1269_891_0;
      signed int Rv_8309_0 = Rv_8309_pack_2 + Rv_8309_pack_1 + Rv_8309_pack_0;
      signed int Rv_8310_0 = Rv_8309_0 >> lambda_isp_oldlua_line1240_348_0;
      signed int Bv_2978_0 = Rv_8065_0 ? Bv_2977_0 : Rv_8310_0;
      signed int Rv_8340_0 = Rv_8065_0 ? Rv_8339_0 : Rv_8310_0;
      signed int Rv_8357_pack_3 = lambda_isp_oldlua_line1269_900_0;
      signed int Rh_4241_0 = Bv_3031_0 ? Rh_4225_0 : lambda_isp_oldlua_line1269_885_0;
      signed int pix_2995_0 = c_60_0;
      signed int pix_3037_0 = pix_3034_0 ? pix_2995_0 : pix_3036_0;
      signed int pix_3038_0 = pix_3033_0 ? pix_2998_0 : pix_3037_0;
      bool Gv_1031_0 = pix_3038_0 == pix_2995_0;
      bool Bv_3024_0 = pix_3038_0 == pix_2991_0;
      bool Gv_1033_0 = pix_3038_0 == pix_2998_0;
      bool Bv_3022_0 = pix_3038_0 == pix_2992_0;
      signed int Gh_1983_pack_0 = Rv_8349_0;
      signed int Bh_3006_pack_5 = Rv_8314_0;
      signed int Rv_8375_pack_8 = Rv_8306_0;
      signed int pix_2985_0 = c_60_0;
      signed int pix_3031_0 = pix_3028_0 ? pix_2985_0 : pix_3030_0;
      signed int pix_3032_0 = pix_3027_0 ? pix_2988_0 : pix_3031_0;
      bool Bv_3014_0 = pix_3032_0 == pix_2982_0;
      bool Gv_1025_0 = pix_3032_0 == pix_2985_0;
      signed int Gv_1026_0 = Gv_1025_0 ? lambda_isp_oldlua_line1269_891_0 : Rv_8355_0;
      bool Gv_1027_0 = pix_3032_0 == pix_2988_0;
      signed int Gv_1028_0 = Gv_1027_0 ? lambda_isp_oldlua_line1269_891_0 : Gv_1026_0;
      signed int Gv_1029_pack_0 = Gv_1028_0;
      // max Gv_1029_0 <= (Gv_1029_pack_1 , Gv_1029_pack_0)
      signed int Gv_1029_0_cotmp_1 = (Gv_1029_pack_1 > Gv_1029_pack_0) ? Gv_1029_pack_1 : Gv_1029_pack_0;
      signed int Gv_1029_0 = Gv_1029_0_cotmp_1;

      signed int Gv_1030_pack_0 = Gv_1029_0;
      // min Gv_1030_0 <= (Gv_1030_pack_1 , Gv_1030_pack_0)
      signed int Gv_1030_0_cotmp_1 = (Gv_1030_pack_1 < Gv_1030_pack_0) ? Gv_1030_pack_1 : Gv_1030_pack_0;
      signed int Gv_1030_0 = Gv_1030_0_cotmp_1;

      bool Bv_3016_0 = pix_3032_0 == pix_2981_0;
      signed int Bv_2970_pack_7 = Rv_8315_0;
      signed int Bv_2970_0 = Bv_2970_pack_8 + Bv_2970_pack_7 + Bv_2970_pack_6 + Bv_2970_pack_5 + Bv_2970_pack_4 + Bv_2970_pack_3 + Bv_2970_pack_2 + Bv_2970_pack_1 + Bv_2970_pack_0;
      signed int Bv_2971_0 = Bv_2970_0 >> lambda_isp_oldlua_line1240_349_0;
      signed int offY_4201_0 = c_344_0;
      signed int Gv_1032_0 = Gv_1031_0 ? lambda_isp_oldlua_line1269_890_0 : Rv_8373_0;
      signed int Gv_1034_0 = Gv_1033_0 ? lambda_isp_oldlua_line1269_890_0 : Gv_1032_0;
      signed int Gv_1035_pack_0 = Gv_1034_0;
      // max Gv_1035_0 <= (Gv_1035_pack_1 , Gv_1035_pack_0)
      signed int Gv_1035_0_cotmp_1 = (Gv_1035_pack_1 > Gv_1035_pack_0) ? Gv_1035_pack_1 : Gv_1035_pack_0;
      signed int Gv_1035_0 = Gv_1035_0_cotmp_1;

      signed int Gv_1036_pack_0 = Gv_1035_0;
      // min Gv_1036_0 <= (Gv_1036_pack_1 , Gv_1036_pack_0)
      signed int Gv_1036_0_cotmp_1 = (Gv_1036_pack_1 < Gv_1036_pack_0) ? Gv_1036_pack_1 : Gv_1036_pack_0;
      signed int Gv_1036_0 = Gv_1036_0_cotmp_1;

      signed int Rv_8362_pack_0 = lambda_isp_oldlua_line1269_892_0;
      signed int Rh_4201_pack_3 = Rv_8285_0;
      signed int Rh_4201_0 = Rh_4201_pack_5 + Rh_4201_pack_4 + Rh_4201_pack_3 + Rh_4201_pack_2 + Rh_4201_pack_1 + Rh_4201_pack_0;
      signed int Rh_4202_0 = Rh_4201_0 >> lambda_isp_oldlua_line1240_356_0;
      signed int Rh_4203_0 = Rv_8155_0 ? Rh_4202_0 : Rh_4187_0;
      signed int Rh_4206_pack_0 = lambda_isp_oldlua_line1269_906_0;
      signed int Rh_4206_0 = Rh_4206_pack_8 + Rh_4206_pack_7 + Rh_4206_pack_6 + Rh_4206_pack_5 + Rh_4206_pack_4 + Rh_4206_pack_3 + Rh_4206_pack_2 + Rh_4206_pack_1 + Rh_4206_pack_0;
      signed int Rh_4207_0 = Rh_4206_0 >> lambda_isp_oldlua_line1240_356_0;
      signed int Rh_4210_0 = Rv_8155_0 ? Rh_4209_0 : Rh_4207_0;
      signed int lambda_isp_oldlua_line1329_1384_0 = c_7_0;
      signed int lambda_isp_oldlua_line1329_1385_0 = centroid_pos_0 + lambda_isp_oldlua_line1329_1384_0;
      signed int lambda_isp_oldlua_line1329_1386_0 = lambda_isp_oldlua_line1329_1385_0 + lambda_isp_oldlua_line1329_1353_0;
      signed int grPix_3981_0 = lambda_isp_oldlua_line1329_1386_0 + offX_2273_0;
      signed int grPix_3982_0 = grPix_3981_0 & lambda_isp_oldlua_line1240_348_0;
      bool grPix_3983_0 = grPix_3982_0 != clap_507_0;
      bool grPix_3984_0 = !grPix_3983_0;
      signed int Gh_1994_0 = Rv_8165_0 ? Gh_1993_0 : Rh_4200_0;
      signed int Gh_2007_0 = Gv_1039_0 ? lambda_isp_oldlua_line1269_885_0 : Gh_1994_0;
      signed int Gh_2008_0 = Gv_1040_0 ? lambda_isp_oldlua_line1269_885_0 : Gh_2007_0;
      signed int Gh_2009_pack_0 = Gh_2008_0;
      // max Gh_2009_0 <= (Gh_2009_pack_1 , Gh_2009_pack_0)
      signed int Gh_2009_0_cotmp_1 = (Gh_2009_pack_1 > Gh_2009_pack_0) ? Gh_2009_pack_1 : Gh_2009_pack_0;
      signed int Gh_2009_0 = Gh_2009_0_cotmp_1;

      signed int Gh_2010_pack_0 = Gh_2009_0;
      signed int Bh_3006_pack_2 = lambda_isp_oldlua_line1269_887_0;
      signed int Bh_3006_0 = Bh_3006_pack_11 + Bh_3006_pack_10 + Bh_3006_pack_9 + Bh_3006_pack_8 + Bh_3006_pack_7 + Bh_3006_pack_6 + Bh_3006_pack_5 + Bh_3006_pack_4 + Bh_3006_pack_3 + Bh_3006_pack_2 + Bh_3006_pack_1 + Bh_3006_pack_0;
      signed int Bh_3007_0 = Bh_3006_0 >> lambda_isp_oldlua_line1240_349_0;
      signed int Bh_3008_0 = Rv_8065_0 ? Bh_3007_0 : Bh_3005_0;
      signed int Rv_8357_pack_1 = lambda_isp_oldlua_line1269_885_0;
      signed int Rv_8294_0 = -Rv_8293_0;
      signed int Rv_8362_pack_6 = Rv_8294_0;
      signed int Rv_8362_0 = Rv_8362_pack_8 + Rv_8362_pack_7 + Rv_8362_pack_6 + Rv_8362_pack_5 + Rv_8362_pack_4 + Rv_8362_pack_3 + Rv_8362_pack_2 + Rv_8362_pack_1 + Rv_8362_pack_0;
      signed int Rv_8363_0 = Rv_8362_0 >> lambda_isp_oldlua_line1240_351_0;
      signed int Bv_2985_pack_7 = Rv_8294_0;
      signed int Bv_2985_0 = Bv_2985_pack_8 + Bv_2985_pack_7 + Bv_2985_pack_6 + Bv_2985_pack_5 + Bv_2985_pack_4 + Bv_2985_pack_3 + Bv_2985_pack_2 + Bv_2985_pack_1 + Bv_2985_pack_0;
      signed int Bv_2986_0 = Bv_2985_0 >> lambda_isp_oldlua_line1240_351_0;
      signed int Rv_8357_pack_6 = Rv_8294_0;
      signed int Rv_8375_pack_0 = lambda_isp_oldlua_line1269_903_0;
      signed int Gh_1973_0 = -Gh_1972_0;
      signed int Gh_1983_pack_3 = Gh_1973_0;
      signed int Gh_1983_0 = Gh_1983_pack_5 + Gh_1983_pack_4 + Gh_1983_pack_3 + Gh_1983_pack_2 + Gh_1983_pack_1 + Gh_1983_pack_0;
      signed int Gh_1984_0 = Gh_1983_0 >> lambda_isp_oldlua_line1240_356_0;
      signed int Gh_1985_0 = Rv_8155_0 ? Gh_1984_0 : Rh_4187_0;
      signed int grPix_3977_0 = lambda_isp_oldlua_line1329_1383_0 + offY_4200_0;
      signed int grPix_3978_0 = grPix_3977_0 & lambda_isp_oldlua_line1240_348_0;
      bool grPix_3979_0 = grPix_3978_0 != clap_507_0;
      bool grPix_3980_0 = !grPix_3979_0;
      bool rPix_841_0 = grPix_3980_0 & grPix_3983_0;
      signed int rPix_842_0 = rPix_841_0 ? lambda_isp_oldlua_line1240_348_0 : clap_507_0;
      bool pix_3023_0 = rPix_842_0 == lambda_isp_oldlua_line1240_348_0;
      signed int pix_3024_0 = pix_3023_0 ? pix_2972_0 : pix_2971_0;
      bool gbPix_841_0 = grPix_3979_0 & grPix_3983_0;
      signed int gbPix_842_0 = gbPix_841_0 ? lambda_isp_oldlua_line1240_348_0 : clap_507_0;
      bool pix_3022_0 = gbPix_842_0 == lambda_isp_oldlua_line1240_348_0;
      signed int pix_3025_0 = pix_3022_0 ? pix_2975_0 : pix_3024_0;
      bool grPix_3985_0 = grPix_3980_0 & grPix_3984_0;
      signed int grPix_3986_0 = grPix_3985_0 ? lambda_isp_oldlua_line1240_348_0 : clap_507_0;
      bool pix_3021_0 = grPix_3986_0 == lambda_isp_oldlua_line1240_348_0;
      signed int pix_3026_0 = pix_3021_0 ? pix_2978_0 : pix_3025_0;
      bool Bv_3006_0 = pix_3026_0 == pix_2972_0;
      bool Gv_1021_0 = pix_3026_0 == pix_2978_0;
      bool Gv_1019_0 = pix_3026_0 == pix_2975_0;
      signed int Gh_1999_0 = Gv_1019_0 ? lambda_isp_oldlua_line1269_893_0 : Gh_1978_0;
      signed int Gh_2000_0 = Gv_1021_0 ? lambda_isp_oldlua_line1269_893_0 : Gh_1999_0;
      signed int Gh_2001_pack_0 = Gh_2000_0;
      // max Gh_2001_0 <= (Gh_2001_pack_1 , Gh_2001_pack_0)
      signed int Gh_2001_0_cotmp_1 = (Gh_2001_pack_1 > Gh_2001_pack_0) ? Gh_2001_pack_1 : Gh_2001_pack_0;
      signed int Gh_2001_0 = Gh_2001_0_cotmp_1;

      signed int Gh_2002_pack_0 = Gh_2001_0;
      signed int Gv_1020_0 = Gv_1019_0 ? lambda_isp_oldlua_line1269_893_0 : Rv_8340_0;
      // min Gh_2002_0 <= (Gh_2002_pack_1 , Gh_2002_pack_0)
      signed int Gh_2002_0_cotmp_1 = (Gh_2002_pack_1 < Gh_2002_pack_0) ? Gh_2002_pack_1 : Gh_2002_pack_0;
      signed int Gh_2002_0 = Gh_2002_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6011_pack_0 = Gh_2002_0;
      signed int Gv_1022_0 = Gv_1021_0 ? lambda_isp_oldlua_line1269_893_0 : Gv_1020_0;
      signed int Gv_1023_pack_0 = Gv_1022_0;
      // max Gv_1023_0 <= (Gv_1023_pack_1 , Gv_1023_pack_0)
      signed int Gv_1023_0_cotmp_1 = (Gv_1023_pack_1 > Gv_1023_pack_0) ? Gv_1023_pack_1 : Gv_1023_pack_0;
      signed int Gv_1023_0 = Gv_1023_0_cotmp_1;

      signed int Gv_1024_pack_0 = Gv_1023_0;
      // min Gv_1024_0 <= (Gv_1024_pack_1 , Gv_1024_pack_0)
      signed int Gv_1024_0_cotmp_1 = (Gv_1024_pack_1 < Gv_1024_pack_0) ? Gv_1024_pack_1 : Gv_1024_pack_0;
      signed int Gv_1024_0 = Gv_1024_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6011_pack_1 = Gv_1024_0;
      signed int lambda_isp_oldlua_line1228_6028_0 = Gv_1024_0 - Gv_1036_0;
      signed int lambda_isp_oldlua_line1228_6029_0 = (lambda_isp_oldlua_line1228_6028_0 >= 0) ? lambda_isp_oldlua_line1228_6028_0 : (-lambda_isp_oldlua_line1228_6028_0);
      signed int lambda_isp_oldlua_line1228_6017_0 = Gv_1024_0 - Gv_1030_0;
      signed int lambda_isp_oldlua_line1228_6018_0 = (lambda_isp_oldlua_line1228_6017_0 >= 0) ? lambda_isp_oldlua_line1228_6017_0 : (-lambda_isp_oldlua_line1228_6017_0);
      signed int lambda_isp_oldlua_line1228_6021_pack_0 = lambda_isp_oldlua_line1228_6018_0;
      signed int lambda_isp_oldlua_line1228_6032_pack_0 = lambda_isp_oldlua_line1228_6029_0;
      signed int lambda_isp_oldlua_line1228_6011_0 = lambda_isp_oldlua_line1228_6011_pack_2 + lambda_isp_oldlua_line1228_6011_pack_1 + lambda_isp_oldlua_line1228_6011_pack_0;
      signed int lambda_isp_oldlua_line1228_6012_0 = lambda_isp_oldlua_line1228_6011_0 >> lambda_isp_oldlua_line1240_348_0;
      bool Bv_3008_0 = pix_3026_0 == pix_2971_0;
      signed int Bh_3043_0 = Bv_3008_0 ? lambda_isp_oldlua_line1269_893_0 : Bh_3008_0;
      signed int Bh_3044_0 = Gv_1019_0 ? Bh_3012_0 : Bh_3043_0;
      signed int Bh_3045_0 = Gv_1021_0 ? Rh_4185_0 : Bh_3044_0;
      signed int Bh_3046_pack_0 = Bh_3045_0;
      signed int Rh_4231_0 = Bv_3008_0 ? Rh_4190_0 : lambda_isp_oldlua_line1269_893_0;
      signed int Rh_4232_0 = Gv_1019_0 ? Rh_4185_0 : Rh_4231_0;
      signed int Rh_4219_pack_7 = lambda_isp_oldlua_line1240_358_0;
      signed int Rh_4219_0 = Rh_4219_pack_7 + Rh_4219_pack_6 + Rh_4219_pack_5 + Rh_4219_pack_4 + Rh_4219_pack_3 + Rh_4219_pack_2 + Rh_4219_pack_1 + Rh_4219_pack_0;
      signed int Rh_4220_0 = Rh_4219_0 >> lambda_isp_oldlua_line1240_358_0;
      signed int Rh_4242_0 = Gv_1039_0 ? Rh_4220_0 : Rh_4241_0;
      signed int Bh_3055_0 = Gv_1040_0 ? Rh_4220_0 : Bh_3054_0;
      signed int Bh_3056_pack_0 = Bh_3055_0;
      signed int Rh_4243_0 = Gv_1040_0 ? Rh_4218_0 : Rh_4242_0;
      signed int Rh_4244_pack_0 = Rh_4243_0;
      // max Rh_4244_0 <= (Rh_4244_pack_1 , Rh_4244_pack_0)
      signed int Rh_4244_0_cotmp_1 = (Rh_4244_pack_1 > Rh_4244_pack_0) ? Rh_4244_pack_1 : Rh_4244_pack_0;
      signed int Rh_4244_0 = Rh_4244_0_cotmp_1;

      signed int Rh_4245_pack_0 = Rh_4244_0;
      // min Rh_4245_0 <= (Rh_4245_pack_1 , Rh_4245_pack_0)
      signed int Rh_4245_0_cotmp_1 = (Rh_4245_pack_1 < Rh_4245_pack_0) ? Rh_4245_pack_1 : Rh_4245_pack_0;
      signed int Rh_4245_0 = Rh_4245_0_cotmp_1;

      // max Bh_3056_0 <= (Bh_3056_pack_1 , Bh_3056_pack_0)
      signed int Bh_3056_0_cotmp_1 = (Bh_3056_pack_1 > Bh_3056_pack_0) ? Bh_3056_pack_1 : Bh_3056_pack_0;
      signed int Bh_3056_0 = Bh_3056_0_cotmp_1;

      signed int Bh_3057_pack_0 = Bh_3056_0;
      // min Bh_3057_0 <= (Bh_3057_pack_1 , Bh_3057_pack_0)
      signed int Bh_3057_0_cotmp_1 = (Bh_3057_pack_1 < Bh_3057_pack_0) ? Bh_3057_pack_1 : Bh_3057_pack_0;
      signed int Bh_3057_0 = Bh_3057_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6068_0 = Rh_4245_0 - Bh_3057_0;
      signed int lambda_isp_oldlua_line1228_6069_0 = (lambda_isp_oldlua_line1228_6068_0 >= 0) ? lambda_isp_oldlua_line1228_6068_0 : (-lambda_isp_oldlua_line1228_6068_0);
      signed int lambda_isp_oldlua_line1228_6070_pack_1 = lambda_isp_oldlua_line1228_6069_0;
      signed int Rv_8375_pack_6 = Rv_8302_0;
      // max Bh_3046_0 <= (Bh_3046_pack_1 , Bh_3046_pack_0)
      signed int Bh_3046_0_cotmp_1 = (Bh_3046_pack_1 > Bh_3046_pack_0) ? Bh_3046_pack_1 : Bh_3046_pack_0;
      signed int Bh_3046_0 = Bh_3046_0_cotmp_1;

      signed int Bh_3047_pack_0 = Bh_3046_0;
      // min Bh_3047_0 <= (Bh_3047_pack_1 , Bh_3047_pack_0)
      signed int Bh_3047_0_cotmp_1 = (Bh_3047_pack_1 < Bh_3047_pack_0) ? Bh_3047_pack_1 : Bh_3047_pack_0;
      signed int Bh_3047_0 = Bh_3047_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6059_0 = Bh_3047_0 - Bh_3057_0;
      signed int lambda_isp_oldlua_line1228_6007_pack_0 = Bh_3047_0;
      signed int lambda_isp_oldlua_line1228_6060_0 = (lambda_isp_oldlua_line1228_6059_0 >= 0) ? lambda_isp_oldlua_line1228_6059_0 : (-lambda_isp_oldlua_line1228_6059_0);
      signed int lambda_isp_oldlua_line1228_6061_pack_1 = lambda_isp_oldlua_line1228_6060_0;
      signed int Rv_8357_pack_5 = Rv_8347_0;
      signed int Rv_8357_0 = Rv_8357_pack_11 + Rv_8357_pack_10 + Rv_8357_pack_9 + Rv_8357_pack_8 + Rv_8357_pack_7 + Rv_8357_pack_6 + Rv_8357_pack_5 + Rv_8357_pack_4 + Rv_8357_pack_3 + Rv_8357_pack_2 + Rv_8357_pack_1 + Rv_8357_pack_0;
      signed int Rv_8358_0 = Rv_8357_0 >> lambda_isp_oldlua_line1240_351_0;
      signed int Rv_8364_0 = Rv_8079_0 ? Rv_8358_0 : Rv_8363_0;
      signed int Rv_8399_0 = Bv_3016_0 ? Rv_8364_0 : lambda_isp_oldlua_line1269_891_0;
      signed int Rv_8400_0 = Gv_1025_0 ? Rv_8355_0 : Rv_8399_0;
      signed int Bv_2987_0 = Rv_8079_0 ? Rv_8358_0 : Bv_2986_0;
      signed int Bv_3015_0 = Bv_3014_0 ? Bv_2987_0 : clap_509_0;
      signed int Bv_3017_0 = Bv_3016_0 ? lambda_isp_oldlua_line1269_891_0 : Bv_3015_0;
      signed int Bv_3018_0 = Gv_1025_0 ? Rv_8361_0 : Bv_3017_0;
      signed int Rv_8401_0 = Gv_1027_0 ? Rv_8361_0 : Rv_8400_0;
      signed int Rv_8402_pack_0 = Rv_8401_0;
      // max Rv_8402_0 <= (Rv_8402_pack_1 , Rv_8402_pack_0)
      signed int Rv_8402_0_cotmp_1 = (Rv_8402_pack_1 > Rv_8402_pack_0) ? Rv_8402_pack_1 : Rv_8402_pack_0;
      signed int Rv_8402_0 = Rv_8402_0_cotmp_1;

      signed int Rv_8403_pack_0 = Rv_8402_0;
      // min Rv_8403_0 <= (Rv_8403_pack_1 , Rv_8403_pack_0)
      signed int Rv_8403_0_cotmp_1 = (Rv_8403_pack_1 < Rv_8403_pack_0) ? Rv_8403_pack_1 : Rv_8403_pack_0;
      signed int Rv_8403_0 = Rv_8403_0_cotmp_1;

      signed int pix_3008_0 = c_50_0;
      signed int pix_3044_0 = pix_3039_0 ? pix_3008_0 : pix_3043_0;
      bool Gv_1037_0 = pix_3044_0 == pix_3005_0;
      bool Gv_1038_0 = pix_3044_0 == pix_3008_0;
      signed int Gh_2003_0 = Gv_1037_0 ? lambda_isp_oldlua_line1269_892_0 : Gh_1985_0;
      signed int Gh_2004_0 = Gv_1038_0 ? lambda_isp_oldlua_line1269_892_0 : Gh_2003_0;
      signed int Gh_2005_pack_0 = Gh_2004_0;
      bool Bv_3030_0 = pix_3044_0 == pix_3001_0;
      signed int Bh_3048_0 = Bv_3030_0 ? lambda_isp_oldlua_line1269_892_0 : Bh_3024_0;
      signed int Bh_3049_0 = Gv_1037_0 ? Bh_3019_0 : Bh_3048_0;
      signed int Bh_3050_0 = Gv_1038_0 ? Rh_4205_0 : Bh_3049_0;
      signed int Bh_3051_pack_0 = Bh_3050_0;
      // max Bh_3051_0 <= (Bh_3051_pack_1 , Bh_3051_pack_0)
      signed int Bh_3051_0_cotmp_1 = (Bh_3051_pack_1 > Bh_3051_pack_0) ? Bh_3051_pack_1 : Bh_3051_pack_0;
      signed int Bh_3051_0 = Bh_3051_0_cotmp_1;

      signed int Bh_3052_pack_0 = Bh_3051_0;
      // min Bh_3052_0 <= (Bh_3052_pack_1 , Bh_3052_pack_0)
      signed int Bh_3052_0_cotmp_1 = (Bh_3052_pack_1 < Bh_3052_pack_0) ? Bh_3052_pack_1 : Bh_3052_pack_0;
      signed int Bh_3052_0 = Bh_3052_0_cotmp_1;

      signed int Rh_4236_0 = Bv_3030_0 ? Rh_4210_0 : lambda_isp_oldlua_line1269_892_0;
      signed int Rh_4237_0 = Gv_1037_0 ? Rh_4205_0 : Rh_4236_0;
      signed int Rh_4238_0 = Gv_1038_0 ? Rh_4203_0 : Rh_4237_0;
      signed int Rh_4239_pack_0 = Rh_4238_0;
      // max Rh_4239_0 <= (Rh_4239_pack_1 , Rh_4239_pack_0)
      signed int Rh_4239_0_cotmp_1 = (Rh_4239_pack_1 > Rh_4239_pack_0) ? Rh_4239_pack_1 : Rh_4239_pack_0;
      signed int Rh_4239_0 = Rh_4239_0_cotmp_1;

      signed int Rh_4240_pack_0 = Rh_4239_0;
      // min Rh_4240_0 <= (Rh_4240_pack_1 , Rh_4240_pack_0)
      signed int Rh_4240_0_cotmp_1 = (Rh_4240_pack_1 < Rh_4240_pack_0) ? Rh_4240_pack_1 : Rh_4240_pack_0;
      signed int Rh_4240_0 = Rh_4240_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6054_0 = Rh_4240_0 - Bh_3052_0;
      signed int lambda_isp_oldlua_line1228_6055_0 = (lambda_isp_oldlua_line1228_6054_0 >= 0) ? lambda_isp_oldlua_line1228_6054_0 : (-lambda_isp_oldlua_line1228_6054_0);
      signed int lambda_isp_oldlua_line1228_6056_pack_1 = lambda_isp_oldlua_line1228_6055_0;
      signed int lambda_isp_oldlua_line1228_6048_0 = Bh_3047_0 - Bh_3052_0;
      signed int lambda_isp_oldlua_line1228_6049_0 = (lambda_isp_oldlua_line1228_6048_0 >= 0) ? lambda_isp_oldlua_line1228_6048_0 : (-lambda_isp_oldlua_line1228_6048_0);
      signed int lambda_isp_oldlua_line1228_6050_pack_1 = lambda_isp_oldlua_line1228_6049_0;
      // max Gh_2005_0 <= (Gh_2005_pack_1 , Gh_2005_pack_0)
      signed int Gh_2005_0_cotmp_1 = (Gh_2005_pack_1 > Gh_2005_pack_0) ? Gh_2005_pack_1 : Gh_2005_pack_0;
      signed int Gh_2005_0 = Gh_2005_0_cotmp_1;

      signed int Gh_2006_pack_0 = Gh_2005_0;
      // min Gh_2006_0 <= (Gh_2006_pack_1 , Gh_2006_pack_0)
      signed int Gh_2006_0_cotmp_1 = (Gh_2006_pack_1 < Gh_2006_pack_0) ? Gh_2006_pack_1 : Gh_2006_pack_0;
      signed int Gh_2006_0 = Gh_2006_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6046_0 = Gh_2002_0 - Gh_2006_0;
      signed int lambda_isp_oldlua_line1228_6047_0 = (lambda_isp_oldlua_line1228_6046_0 >= 0) ? lambda_isp_oldlua_line1228_6046_0 : (-lambda_isp_oldlua_line1228_6046_0);
      signed int lambda_isp_oldlua_line1228_6050_pack_0 = lambda_isp_oldlua_line1228_6047_0;
      // max lambda_isp_oldlua_line1228_6050_0 <= (lambda_isp_oldlua_line1228_6050_pack_1 , lambda_isp_oldlua_line1228_6050_pack_0)
      signed int lambda_isp_oldlua_line1228_6050_0_cotmp_1 = (lambda_isp_oldlua_line1228_6050_pack_1 > lambda_isp_oldlua_line1228_6050_pack_0) ? lambda_isp_oldlua_line1228_6050_pack_1 : lambda_isp_oldlua_line1228_6050_pack_0;
      signed int lambda_isp_oldlua_line1228_6050_0 = lambda_isp_oldlua_line1228_6050_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6053_pack_0 = lambda_isp_oldlua_line1228_6050_0;
      signed int offX_2295_0 = c_34_0;
      signed int Gh_2010_pack_1 = clap_516_0;
      // min Gh_2010_0 <= (Gh_2010_pack_1 , Gh_2010_pack_0)
      signed int Gh_2010_0_cotmp_1 = (Gh_2010_pack_1 < Gh_2010_pack_0) ? Gh_2010_pack_1 : Gh_2010_pack_0;
      signed int Gh_2010_0 = Gh_2010_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6057_0 = Gh_2002_0 - Gh_2010_0;
      signed int lambda_isp_oldlua_line1228_6058_0 = (lambda_isp_oldlua_line1228_6057_0 >= 0) ? lambda_isp_oldlua_line1228_6057_0 : (-lambda_isp_oldlua_line1228_6057_0);
      signed int lambda_isp_oldlua_line1228_6061_pack_0 = lambda_isp_oldlua_line1228_6058_0;
      // max lambda_isp_oldlua_line1228_6061_0 <= (lambda_isp_oldlua_line1228_6061_pack_1 , lambda_isp_oldlua_line1228_6061_pack_0)
      signed int lambda_isp_oldlua_line1228_6061_0_cotmp_1 = (lambda_isp_oldlua_line1228_6061_pack_1 > lambda_isp_oldlua_line1228_6061_pack_0) ? lambda_isp_oldlua_line1228_6061_pack_1 : lambda_isp_oldlua_line1228_6061_pack_0;
      signed int lambda_isp_oldlua_line1228_6061_0 = lambda_isp_oldlua_line1228_6061_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6064_pack_0 = lambda_isp_oldlua_line1228_6061_0;
      signed int Bv_2983_0 = Bv_2982_0 >> lambda_isp_oldlua_line1240_351_0;
      signed int Bv_2984_0 = Rv_8079_0 ? Bv_2983_0 : Rv_8346_0;
      signed int Bv_3019_0 = Gv_1027_0 ? Bv_2984_0 : Bv_3018_0;
      signed int Bv_3020_pack_0 = Bv_3019_0;
      // max Bv_3020_0 <= (Bv_3020_pack_1 , Bv_3020_pack_0)
      signed int Bv_3020_0_cotmp_1 = (Bv_3020_pack_1 > Bv_3020_pack_0) ? Bv_3020_pack_1 : Bv_3020_pack_0;
      signed int Bv_3020_0 = Bv_3020_0_cotmp_1;

      signed int Bv_3021_pack_0 = Bv_3020_0;
      // min Bv_3021_0 <= (Bv_3021_pack_1 , Bv_3021_pack_0)
      signed int Bv_3021_0_cotmp_1 = (Bv_3021_pack_1 < Bv_3021_pack_0) ? Bv_3021_pack_1 : Bv_3021_pack_0;
      signed int Bv_3021_0 = Bv_3021_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6025_0 = Rv_8403_0 - Bv_3021_0;
      signed int lambda_isp_oldlua_line1228_6026_0 = (lambda_isp_oldlua_line1228_6025_0 >= 0) ? lambda_isp_oldlua_line1228_6025_0 : (-lambda_isp_oldlua_line1228_6025_0);
      signed int lambda_isp_oldlua_line1228_6027_pack_1 = lambda_isp_oldlua_line1228_6026_0;
      signed int Rv_8334_pack_1 = lambda_isp_oldlua_line1269_886_0;
      signed int Rv_8334_0 = Rv_8334_pack_11 + Rv_8334_pack_10 + Rv_8334_pack_9 + Rv_8334_pack_8 + Rv_8334_pack_7 + Rv_8334_pack_6 + Rv_8334_pack_5 + Rv_8334_pack_4 + Rv_8334_pack_3 + Rv_8334_pack_2 + Rv_8334_pack_1 + Rv_8334_pack_0;
      signed int Rv_8335_0 = Rv_8334_0 >> lambda_isp_oldlua_line1240_349_0;
      signed int Bv_2972_0 = Rv_8065_0 ? Rv_8335_0 : Bv_2971_0;
      signed int Rv_8336_0 = Rv_8065_0 ? Rv_8335_0 : Rv_8317_0;
      signed int Bv_3007_0 = Bv_3006_0 ? Bv_2972_0 : clap_507_0;
      signed int Bv_3009_0 = Bv_3008_0 ? lambda_isp_oldlua_line1269_893_0 : Bv_3007_0;
      signed int Bv_3010_0 = Gv_1019_0 ? Rv_8324_0 : Bv_3009_0;
      signed int Bv_3011_0 = Gv_1021_0 ? Bv_2978_0 : Bv_3010_0;
      signed int Bv_3012_pack_0 = Bv_3011_0;
      // max Bv_3012_0 <= (Bv_3012_pack_1 , Bv_3012_pack_0)
      signed int Bv_3012_0_cotmp_1 = (Bv_3012_pack_1 > Bv_3012_pack_0) ? Bv_3012_pack_1 : Bv_3012_pack_0;
      signed int Bv_3012_0 = Bv_3012_0_cotmp_1;

      signed int Bv_3013_pack_0 = Bv_3012_0;
      // min Bv_3013_0 <= (Bv_3013_pack_1 , Bv_3013_pack_0)
      signed int Bv_3013_0_cotmp_1 = (Bv_3013_pack_1 < Bv_3013_pack_0) ? Bv_3013_pack_1 : Bv_3013_pack_0;
      signed int Bv_3013_0 = Bv_3013_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6019_0 = Bv_3013_0 - Bv_3021_0;
      signed int lambda_isp_oldlua_line1228_6020_0 = (lambda_isp_oldlua_line1228_6019_0 >= 0) ? lambda_isp_oldlua_line1228_6019_0 : (-lambda_isp_oldlua_line1228_6019_0);
      signed int lambda_isp_oldlua_line1228_6021_pack_1 = lambda_isp_oldlua_line1228_6020_0;
      // max lambda_isp_oldlua_line1228_6021_0 <= (lambda_isp_oldlua_line1228_6021_pack_1 , lambda_isp_oldlua_line1228_6021_pack_0)
      signed int lambda_isp_oldlua_line1228_6021_0_cotmp_1 = (lambda_isp_oldlua_line1228_6021_pack_1 > lambda_isp_oldlua_line1228_6021_pack_0) ? lambda_isp_oldlua_line1228_6021_pack_1 : lambda_isp_oldlua_line1228_6021_pack_0;
      signed int lambda_isp_oldlua_line1228_6021_0 = lambda_isp_oldlua_line1228_6021_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6024_pack_0 = lambda_isp_oldlua_line1228_6021_0;
      signed int lambda_isp_oldlua_line1228_6007_pack_1 = Bv_3013_0;
      signed int lambda_isp_oldlua_line1228_6007_0 = lambda_isp_oldlua_line1228_6007_pack_2 + lambda_isp_oldlua_line1228_6007_pack_1 + lambda_isp_oldlua_line1228_6007_pack_0;
      signed int lambda_isp_oldlua_line1228_6008_0 = lambda_isp_oldlua_line1228_6007_0 >> lambda_isp_oldlua_line1240_348_0;
      signed int Rv_8394_0 = Bv_3008_0 ? Rv_8336_0 : lambda_isp_oldlua_line1269_893_0;
      signed int Rv_8395_0 = Gv_1019_0 ? Rv_8340_0 : Rv_8394_0;
      signed int Rv_8396_0 = Gv_1021_0 ? Rv_8324_0 : Rv_8395_0;
      signed int Rv_8397_pack_0 = Rv_8396_0;
      // max Rv_8397_0 <= (Rv_8397_pack_1 , Rv_8397_pack_0)
      signed int Rv_8397_0_cotmp_1 = (Rv_8397_pack_1 > Rv_8397_pack_0) ? Rv_8397_pack_1 : Rv_8397_pack_0;
      signed int Rv_8397_0 = Rv_8397_0_cotmp_1;

      signed int Rv_8398_pack_0 = Rv_8397_0;
      // min Rv_8398_0 <= (Rv_8398_pack_1 , Rv_8398_pack_0)
      signed int Rv_8398_0_cotmp_1 = (Rv_8398_pack_1 < Rv_8398_pack_0) ? Rv_8398_pack_1 : Rv_8398_pack_0;
      signed int Rv_8398_0 = Rv_8398_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6009_0 = Rv_8398_0 - Bv_3013_0;
      signed int lambda_isp_oldlua_line1228_6010_0 = (lambda_isp_oldlua_line1228_6009_0 >= 0) ? lambda_isp_oldlua_line1228_6009_0 : (-lambda_isp_oldlua_line1228_6009_0);
      signed int lambda_isp_oldlua_line1228_6022_0 = Rv_8398_0 - Rv_8403_0;
      signed int lambda_isp_oldlua_line1228_6023_0 = (lambda_isp_oldlua_line1228_6022_0 >= 0) ? lambda_isp_oldlua_line1228_6022_0 : (-lambda_isp_oldlua_line1228_6022_0);
      signed int lambda_isp_oldlua_line1228_6027_pack_0 = lambda_isp_oldlua_line1228_6010_0;
      // max lambda_isp_oldlua_line1228_6027_0 <= (lambda_isp_oldlua_line1228_6027_pack_1 , lambda_isp_oldlua_line1228_6027_pack_0)
      signed int lambda_isp_oldlua_line1228_6027_0_cotmp_1 = (lambda_isp_oldlua_line1228_6027_pack_1 > lambda_isp_oldlua_line1228_6027_pack_0) ? lambda_isp_oldlua_line1228_6027_pack_1 : lambda_isp_oldlua_line1228_6027_pack_0;
      signed int lambda_isp_oldlua_line1228_6027_0 = lambda_isp_oldlua_line1228_6027_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6024_pack_1 = lambda_isp_oldlua_line1228_6023_0;
      signed int lambda_isp_oldlua_line1228_6015_pack_1 = Rv_8398_0;
      signed int lambda_isp_oldlua_line1228_6041_pack_0 = lambda_isp_oldlua_line1228_6027_0;
      // max lambda_isp_oldlua_line1228_6024_0 <= (lambda_isp_oldlua_line1228_6024_pack_1 , lambda_isp_oldlua_line1228_6024_pack_0)
      signed int lambda_isp_oldlua_line1228_6024_0_cotmp_1 = (lambda_isp_oldlua_line1228_6024_pack_1 > lambda_isp_oldlua_line1228_6024_pack_0) ? lambda_isp_oldlua_line1228_6024_pack_1 : lambda_isp_oldlua_line1228_6024_pack_0;
      signed int lambda_isp_oldlua_line1228_6024_0 = lambda_isp_oldlua_line1228_6024_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6036_pack_0 = lambda_isp_oldlua_line1228_6024_0;
      signed int Rh_4195_0 = Rv_8065_0 ? Rh_4194_0 : Rh_4183_0;
      signed int Rh_4233_0 = Gv_1021_0 ? Rh_4195_0 : Rh_4232_0;
      signed int Rh_4234_pack_0 = Rh_4233_0;
      // max Rh_4234_0 <= (Rh_4234_pack_1 , Rh_4234_pack_0)
      signed int Rh_4234_0_cotmp_1 = (Rh_4234_pack_1 > Rh_4234_pack_0) ? Rh_4234_pack_1 : Rh_4234_pack_0;
      signed int Rh_4234_0 = Rh_4234_0_cotmp_1;

      signed int Rh_4235_pack_0 = Rh_4234_0;
      // min Rh_4235_0 <= (Rh_4235_pack_1 , Rh_4235_pack_0)
      signed int Rh_4235_0_cotmp_1 = (Rh_4235_pack_1 < Rh_4235_pack_0) ? Rh_4235_pack_1 : Rh_4235_pack_0;
      signed int Rh_4235_0 = Rh_4235_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6062_0 = Rh_4235_0 - Rh_4245_0;
      signed int lambda_isp_oldlua_line1228_6063_0 = (lambda_isp_oldlua_line1228_6062_0 >= 0) ? lambda_isp_oldlua_line1228_6062_0 : (-lambda_isp_oldlua_line1228_6062_0);
      signed int lambda_isp_oldlua_line1228_6064_pack_1 = lambda_isp_oldlua_line1228_6063_0;
      signed int lambda_isp_oldlua_line1228_6051_0 = Rh_4235_0 - Rh_4240_0;
      signed int lambda_isp_oldlua_line1228_6052_0 = (lambda_isp_oldlua_line1228_6051_0 >= 0) ? lambda_isp_oldlua_line1228_6051_0 : (-lambda_isp_oldlua_line1228_6051_0);
      signed int lambda_isp_oldlua_line1228_6053_pack_1 = lambda_isp_oldlua_line1228_6052_0;
      // max lambda_isp_oldlua_line1228_6064_0 <= (lambda_isp_oldlua_line1228_6064_pack_1 , lambda_isp_oldlua_line1228_6064_pack_0)
      signed int lambda_isp_oldlua_line1228_6064_0_cotmp_1 = (lambda_isp_oldlua_line1228_6064_pack_1 > lambda_isp_oldlua_line1228_6064_pack_0) ? lambda_isp_oldlua_line1228_6064_pack_1 : lambda_isp_oldlua_line1228_6064_pack_0;
      signed int lambda_isp_oldlua_line1228_6064_0 = lambda_isp_oldlua_line1228_6064_0_cotmp_1;

      // max lambda_isp_oldlua_line1228_6053_0 <= (lambda_isp_oldlua_line1228_6053_pack_1 , lambda_isp_oldlua_line1228_6053_pack_0)
      signed int lambda_isp_oldlua_line1228_6053_0_cotmp_1 = (lambda_isp_oldlua_line1228_6053_pack_1 > lambda_isp_oldlua_line1228_6053_pack_0) ? lambda_isp_oldlua_line1228_6053_pack_1 : lambda_isp_oldlua_line1228_6053_pack_0;
      signed int lambda_isp_oldlua_line1228_6053_0 = lambda_isp_oldlua_line1228_6053_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6065_pack_0 = lambda_isp_oldlua_line1228_6053_0;
      signed int lambda_isp_oldlua_line1228_6015_pack_0 = Rh_4235_0;
      signed int lambda_isp_oldlua_line1228_6015_0 = lambda_isp_oldlua_line1228_6015_pack_2 + lambda_isp_oldlua_line1228_6015_pack_1 + lambda_isp_oldlua_line1228_6015_pack_0;
      signed int lambda_isp_oldlua_line1228_6016_0 = lambda_isp_oldlua_line1228_6015_0 >> lambda_isp_oldlua_line1240_348_0;
      signed int lambda_isp_oldlua_line1228_6013_0 = Rh_4235_0 - Bh_3047_0;
      signed int lambda_isp_oldlua_line1228_6014_0 = (lambda_isp_oldlua_line1228_6013_0 >= 0) ? lambda_isp_oldlua_line1228_6013_0 : (-lambda_isp_oldlua_line1228_6013_0);
      signed int lambda_isp_oldlua_line1228_6056_pack_0 = lambda_isp_oldlua_line1228_6014_0;
      // max lambda_isp_oldlua_line1228_6056_0 <= (lambda_isp_oldlua_line1228_6056_pack_1 , lambda_isp_oldlua_line1228_6056_pack_0)
      signed int lambda_isp_oldlua_line1228_6056_0_cotmp_1 = (lambda_isp_oldlua_line1228_6056_pack_1 > lambda_isp_oldlua_line1228_6056_pack_0) ? lambda_isp_oldlua_line1228_6056_pack_1 : lambda_isp_oldlua_line1228_6056_pack_0;
      signed int lambda_isp_oldlua_line1228_6056_0 = lambda_isp_oldlua_line1228_6056_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6070_pack_0 = lambda_isp_oldlua_line1228_6056_0;
      // max lambda_isp_oldlua_line1228_6070_0 <= (lambda_isp_oldlua_line1228_6070_pack_1 , lambda_isp_oldlua_line1228_6070_pack_0)
      signed int lambda_isp_oldlua_line1228_6070_0_cotmp_1 = (lambda_isp_oldlua_line1228_6070_pack_1 > lambda_isp_oldlua_line1228_6070_pack_0) ? lambda_isp_oldlua_line1228_6070_pack_1 : lambda_isp_oldlua_line1228_6070_pack_0;
      signed int lambda_isp_oldlua_line1228_6070_0 = lambda_isp_oldlua_line1228_6070_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6071_0 = lambda_isp_oldlua_line1228_5778_0 * lambda_isp_oldlua_line1228_6070_0;
      signed int lambda_isp_oldlua_line1228_6072_0 = lambda_isp_oldlua_line1228_6071_0 >> lambda_isp_oldlua_line1240_354_0;
      signed int lambda_isp_oldlua_line1228_6065_pack_1 = lambda_isp_oldlua_line1228_6064_0;
      // max lambda_isp_oldlua_line1228_6065_0 <= (lambda_isp_oldlua_line1228_6065_pack_1 , lambda_isp_oldlua_line1228_6065_pack_0)
      signed int lambda_isp_oldlua_line1228_6065_0_cotmp_1 = (lambda_isp_oldlua_line1228_6065_pack_1 > lambda_isp_oldlua_line1228_6065_pack_0) ? lambda_isp_oldlua_line1228_6065_pack_1 : lambda_isp_oldlua_line1228_6065_pack_0;
      signed int lambda_isp_oldlua_line1228_6065_0 = lambda_isp_oldlua_line1228_6065_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6066_0 = lambda_isp_oldlua_line1228_5757_0 * lambda_isp_oldlua_line1228_6065_0;
      signed int lambda_isp_oldlua_line1228_6067_0 = lambda_isp_oldlua_line1228_6066_0 >> lambda_isp_oldlua_line1228_5776_0;
      signed int lambda_isp_oldlua_line1228_6073_0 = lambda_isp_oldlua_line1228_6067_0 + lambda_isp_oldlua_line1228_6072_0;
      signed int lambda_isp_oldlua_line1228_6074_0 = lambda_isp_oldlua_line1228_6073_0 + clap_507_0;
      signed int Rv_8375_pack_4 = Rv_8332_0;
      signed int Rv_8375_0 = Rv_8375_pack_11 + Rv_8375_pack_10 + Rv_8375_pack_9 + Rv_8375_pack_8 + Rv_8375_pack_7 + Rv_8375_pack_6 + Rv_8375_pack_5 + Rv_8375_pack_4 + Rv_8375_pack_3 + Rv_8375_pack_2 + Rv_8375_pack_1 + Rv_8375_pack_0;
      signed int Rv_8376_0 = Rv_8375_0 >> lambda_isp_oldlua_line1240_353_0;
      signed int Rv_8382_0 = Rv_8130_0 ? Rv_8376_0 : Rv_8381_0;
      signed int Rv_8404_0 = Bv_3024_0 ? Rv_8382_0 : lambda_isp_oldlua_line1269_890_0;
      signed int Rv_8405_0 = Gv_1031_0 ? Rv_8373_0 : Rv_8404_0;
      signed int Rv_8406_0 = Gv_1033_0 ? Rv_8379_0 : Rv_8405_0;
      signed int Rv_8407_pack_0 = Rv_8406_0;
      signed int Bv_2999_0 = Rv_8130_0 ? Rv_8376_0 : Bv_2998_0;
      signed int Bv_3023_0 = Bv_3022_0 ? Bv_2999_0 : clap_511_0;
      signed int Bv_3025_0 = Bv_3024_0 ? lambda_isp_oldlua_line1269_890_0 : Bv_3023_0;
      signed int Bv_3026_0 = Gv_1031_0 ? Rv_8379_0 : Bv_3025_0;
      signed int Bv_3027_0 = Gv_1033_0 ? Bv_2996_0 : Bv_3026_0;
      signed int Bv_3028_pack_0 = Bv_3027_0;
      // max Bv_3028_0 <= (Bv_3028_pack_1 , Bv_3028_pack_0)
      signed int Bv_3028_0_cotmp_1 = (Bv_3028_pack_1 > Bv_3028_pack_0) ? Bv_3028_pack_1 : Bv_3028_pack_0;
      signed int Bv_3028_0 = Bv_3028_0_cotmp_1;

      signed int Bv_3029_pack_0 = Bv_3028_0;
      // min Bv_3029_0 <= (Bv_3029_pack_1 , Bv_3029_pack_0)
      signed int Bv_3029_0_cotmp_1 = (Bv_3029_pack_1 < Bv_3029_pack_0) ? Bv_3029_pack_1 : Bv_3029_pack_0;
      signed int Bv_3029_0 = Bv_3029_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6030_0 = Bv_3013_0 - Bv_3029_0;
      signed int lambda_isp_oldlua_line1228_6031_0 = (lambda_isp_oldlua_line1228_6030_0 >= 0) ? lambda_isp_oldlua_line1228_6030_0 : (-lambda_isp_oldlua_line1228_6030_0);
      signed int lambda_isp_oldlua_line1228_6032_pack_1 = lambda_isp_oldlua_line1228_6031_0;
      // max lambda_isp_oldlua_line1228_6032_0 <= (lambda_isp_oldlua_line1228_6032_pack_1 , lambda_isp_oldlua_line1228_6032_pack_0)
      signed int lambda_isp_oldlua_line1228_6032_0_cotmp_1 = (lambda_isp_oldlua_line1228_6032_pack_1 > lambda_isp_oldlua_line1228_6032_pack_0) ? lambda_isp_oldlua_line1228_6032_pack_1 : lambda_isp_oldlua_line1228_6032_pack_0;
      signed int lambda_isp_oldlua_line1228_6032_0 = lambda_isp_oldlua_line1228_6032_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6035_pack_0 = lambda_isp_oldlua_line1228_6032_0;
      // max Rv_8407_0 <= (Rv_8407_pack_1 , Rv_8407_pack_0)
      signed int Rv_8407_0_cotmp_1 = (Rv_8407_pack_1 > Rv_8407_pack_0) ? Rv_8407_pack_1 : Rv_8407_pack_0;
      signed int Rv_8407_0 = Rv_8407_0_cotmp_1;

      signed int Rv_8408_pack_0 = Rv_8407_0;
      // min Rv_8408_0 <= (Rv_8408_pack_1 , Rv_8408_pack_0)
      signed int Rv_8408_0_cotmp_1 = (Rv_8408_pack_1 < Rv_8408_pack_0) ? Rv_8408_pack_1 : Rv_8408_pack_0;
      signed int Rv_8408_0 = Rv_8408_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6039_0 = Rv_8408_0 - Bv_3029_0;
      signed int lambda_isp_oldlua_line1228_6040_0 = (lambda_isp_oldlua_line1228_6039_0 >= 0) ? lambda_isp_oldlua_line1228_6039_0 : (-lambda_isp_oldlua_line1228_6039_0);
      signed int lambda_isp_oldlua_line1228_6033_0 = Rv_8398_0 - Rv_8408_0;
      signed int lambda_isp_oldlua_line1228_6034_0 = (lambda_isp_oldlua_line1228_6033_0 >= 0) ? lambda_isp_oldlua_line1228_6033_0 : (-lambda_isp_oldlua_line1228_6033_0);
      signed int lambda_isp_oldlua_line1228_6035_pack_1 = lambda_isp_oldlua_line1228_6034_0;
      signed int lambda_isp_oldlua_line1228_6041_pack_1 = lambda_isp_oldlua_line1228_6040_0;
      // max lambda_isp_oldlua_line1228_6041_0 <= (lambda_isp_oldlua_line1228_6041_pack_1 , lambda_isp_oldlua_line1228_6041_pack_0)
      signed int lambda_isp_oldlua_line1228_6041_0_cotmp_1 = (lambda_isp_oldlua_line1228_6041_pack_1 > lambda_isp_oldlua_line1228_6041_pack_0) ? lambda_isp_oldlua_line1228_6041_pack_1 : lambda_isp_oldlua_line1228_6041_pack_0;
      signed int lambda_isp_oldlua_line1228_6041_0 = lambda_isp_oldlua_line1228_6041_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6042_0 = lambda_isp_oldlua_line1228_5778_0 * lambda_isp_oldlua_line1228_6041_0;
      signed int lambda_isp_oldlua_line1228_6043_0 = lambda_isp_oldlua_line1228_6042_0 >> lambda_isp_oldlua_line1240_354_0;
      // max lambda_isp_oldlua_line1228_6035_0 <= (lambda_isp_oldlua_line1228_6035_pack_1 , lambda_isp_oldlua_line1228_6035_pack_0)
      signed int lambda_isp_oldlua_line1228_6035_0_cotmp_1 = (lambda_isp_oldlua_line1228_6035_pack_1 > lambda_isp_oldlua_line1228_6035_pack_0) ? lambda_isp_oldlua_line1228_6035_pack_1 : lambda_isp_oldlua_line1228_6035_pack_0;
      signed int lambda_isp_oldlua_line1228_6035_0 = lambda_isp_oldlua_line1228_6035_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6036_pack_1 = lambda_isp_oldlua_line1228_6035_0;
      // max lambda_isp_oldlua_line1228_6036_0 <= (lambda_isp_oldlua_line1228_6036_pack_1 , lambda_isp_oldlua_line1228_6036_pack_0)
      signed int lambda_isp_oldlua_line1228_6036_0_cotmp_1 = (lambda_isp_oldlua_line1228_6036_pack_1 > lambda_isp_oldlua_line1228_6036_pack_0) ? lambda_isp_oldlua_line1228_6036_pack_1 : lambda_isp_oldlua_line1228_6036_pack_0;
      signed int lambda_isp_oldlua_line1228_6036_0 = lambda_isp_oldlua_line1228_6036_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6037_0 = lambda_isp_oldlua_line1228_5757_0 * lambda_isp_oldlua_line1228_6036_0;
      signed int lambda_isp_oldlua_line1228_6038_0 = lambda_isp_oldlua_line1228_6037_0 >> lambda_isp_oldlua_line1228_5776_0;
      signed int lambda_isp_oldlua_line1228_6044_0 = lambda_isp_oldlua_line1228_6038_0 + lambda_isp_oldlua_line1228_6043_0;
      bool lambda_isp_oldlua_line1228_6075_0 = lambda_isp_oldlua_line1228_6044_0 > lambda_isp_oldlua_line1228_6074_0;
      signed int lambda_isp_oldlua_line1228_6076_0 = lambda_isp_oldlua_line1228_6075_0 ? Bh_3047_0 : lambda_isp_oldlua_line1228_6008_0;
      signed int lambda_isp_oldlua_line1228_6078_0 = lambda_isp_oldlua_line1228_6075_0 ? Rh_4235_0 : lambda_isp_oldlua_line1228_6016_0;
      signed int lambda_isp_oldlua_line1228_6077_0 = lambda_isp_oldlua_line1228_6075_0 ? Gh_2002_0 : lambda_isp_oldlua_line1228_6012_0;
      signed int lambda_isp_oldlua_line1228_6045_0 = lambda_isp_oldlua_line1228_6044_0 + clap_507_0;
      bool lambda_isp_oldlua_line1228_6079_0 = lambda_isp_oldlua_line1228_6073_0 > lambda_isp_oldlua_line1228_6045_0;
      signed int lambda_isp_oldlua_line1228_6086_0 = lambda_isp_oldlua_line1228_6079_0 ? Rv_8398_0 : lambda_isp_oldlua_line1228_6078_0;
      signed int lambda_isp_oldlua_line1228_6087_pack_0 = lambda_isp_oldlua_line1228_6086_0;
      // max lambda_isp_oldlua_line1228_6087_0 <= (lambda_isp_oldlua_line1228_6087_pack_1 , lambda_isp_oldlua_line1228_6087_pack_0)
      signed int lambda_isp_oldlua_line1228_6087_0_cotmp_1 = (lambda_isp_oldlua_line1228_6087_pack_1 > lambda_isp_oldlua_line1228_6087_pack_0) ? lambda_isp_oldlua_line1228_6087_pack_1 : lambda_isp_oldlua_line1228_6087_pack_0;
      signed int lambda_isp_oldlua_line1228_6087_0 = lambda_isp_oldlua_line1228_6087_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6088_pack_0 = lambda_isp_oldlua_line1228_6087_0;
      // min lambda_isp_oldlua_line1228_6088_0 <= (lambda_isp_oldlua_line1228_6088_pack_1 , lambda_isp_oldlua_line1228_6088_pack_0)
      signed int lambda_isp_oldlua_line1228_6088_0_cotmp_1 = (lambda_isp_oldlua_line1228_6088_pack_1 < lambda_isp_oldlua_line1228_6088_pack_0) ? lambda_isp_oldlua_line1228_6088_pack_1 : lambda_isp_oldlua_line1228_6088_pack_0;
      signed int lambda_isp_oldlua_line1228_6088_0 = lambda_isp_oldlua_line1228_6088_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6089_2 = lambda_isp_oldlua_line1228_6088_0;
      signed int clap_553_0 = lambda_isp_oldlua_line1228_6089_2;
      signed int clap_554_pack_0 = clap_553_0;
      // max clap_554_0 <= (clap_554_pack_1 , clap_554_pack_0)
      signed int clap_554_0_cotmp_1 = (clap_554_pack_1 > clap_554_pack_0) ? clap_554_pack_1 : clap_554_pack_0;
      signed int clap_554_0 = clap_554_0_cotmp_1;

      signed int clap_555_pack_0 = clap_554_0;
      signed int lambda_isp_oldlua_line1228_6080_0 = lambda_isp_oldlua_line1228_6079_0 ? Bv_3013_0 : lambda_isp_oldlua_line1228_6076_0;
      signed int lambda_isp_oldlua_line1228_6081_pack_0 = lambda_isp_oldlua_line1228_6080_0;
      // max lambda_isp_oldlua_line1228_6081_0 <= (lambda_isp_oldlua_line1228_6081_pack_1 , lambda_isp_oldlua_line1228_6081_pack_0)
      signed int lambda_isp_oldlua_line1228_6081_0_cotmp_1 = (lambda_isp_oldlua_line1228_6081_pack_1 > lambda_isp_oldlua_line1228_6081_pack_0) ? lambda_isp_oldlua_line1228_6081_pack_1 : lambda_isp_oldlua_line1228_6081_pack_0;
      signed int lambda_isp_oldlua_line1228_6081_0 = lambda_isp_oldlua_line1228_6081_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6082_pack_0 = lambda_isp_oldlua_line1228_6081_0;
      // min lambda_isp_oldlua_line1228_6082_0 <= (lambda_isp_oldlua_line1228_6082_pack_1 , lambda_isp_oldlua_line1228_6082_pack_0)
      signed int lambda_isp_oldlua_line1228_6082_0_cotmp_1 = (lambda_isp_oldlua_line1228_6082_pack_1 < lambda_isp_oldlua_line1228_6082_pack_0) ? lambda_isp_oldlua_line1228_6082_pack_1 : lambda_isp_oldlua_line1228_6082_pack_0;
      signed int lambda_isp_oldlua_line1228_6082_0 = lambda_isp_oldlua_line1228_6082_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6089_0 = lambda_isp_oldlua_line1228_6082_0;
      signed int clap_547_0 = lambda_isp_oldlua_line1228_6089_0;
      signed int clap_548_pack_0 = clap_547_0;
      // max clap_548_0 <= (clap_548_pack_1 , clap_548_pack_0)
      signed int clap_548_0_cotmp_1 = (clap_548_pack_1 > clap_548_pack_0) ? clap_548_pack_1 : clap_548_pack_0;
      signed int clap_548_0 = clap_548_0_cotmp_1;

      signed int clap_549_pack_0 = clap_548_0;
      // min clap_549_0 <= (clap_549_pack_1 , clap_549_pack_0)
      signed int clap_549_0_cotmp_1 = (clap_549_pack_1 < clap_549_pack_0) ? clap_549_pack_1 : clap_549_pack_0;
      signed int clap_549_0 = clap_549_0_cotmp_1;

      signed int clap_556_0 = clap_549_0;
      // min clap_555_0 <= (clap_555_pack_1 , clap_555_pack_0)
      signed int clap_555_0_cotmp_1 = (clap_555_pack_1 < clap_555_pack_0) ? clap_555_pack_1 : clap_555_pack_0;
      signed int clap_555_0 = clap_555_0_cotmp_1;

      unsigned int lambda_isp_oldlua_line1274_169_0 = clap_556_0;
      signed int lambda_isp_oldlua_line1228_6083_0 = lambda_isp_oldlua_line1228_6079_0 ? Gv_1024_0 : lambda_isp_oldlua_line1228_6077_0;
      signed int lambda_isp_oldlua_line1228_6084_pack_0 = lambda_isp_oldlua_line1228_6083_0;
      // max lambda_isp_oldlua_line1228_6084_0 <= (lambda_isp_oldlua_line1228_6084_pack_1 , lambda_isp_oldlua_line1228_6084_pack_0)
      signed int lambda_isp_oldlua_line1228_6084_0_cotmp_1 = (lambda_isp_oldlua_line1228_6084_pack_1 > lambda_isp_oldlua_line1228_6084_pack_0) ? lambda_isp_oldlua_line1228_6084_pack_1 : lambda_isp_oldlua_line1228_6084_pack_0;
      signed int lambda_isp_oldlua_line1228_6084_0 = lambda_isp_oldlua_line1228_6084_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6085_pack_0 = lambda_isp_oldlua_line1228_6084_0;
      // min lambda_isp_oldlua_line1228_6085_0 <= (lambda_isp_oldlua_line1228_6085_pack_1 , lambda_isp_oldlua_line1228_6085_pack_0)
      signed int lambda_isp_oldlua_line1228_6085_0_cotmp_1 = (lambda_isp_oldlua_line1228_6085_pack_1 < lambda_isp_oldlua_line1228_6085_pack_0) ? lambda_isp_oldlua_line1228_6085_pack_1 : lambda_isp_oldlua_line1228_6085_pack_0;
      signed int lambda_isp_oldlua_line1228_6085_0 = lambda_isp_oldlua_line1228_6085_0_cotmp_1;

      signed int lambda_isp_oldlua_line1228_6089_1 = lambda_isp_oldlua_line1228_6085_0;
      signed int clap_550_0 = lambda_isp_oldlua_line1228_6089_1;
      signed int clap_551_pack_0 = clap_550_0;
      // max clap_551_0 <= (clap_551_pack_1 , clap_551_pack_0)
      signed int clap_551_0_cotmp_1 = (clap_551_pack_1 > clap_551_pack_0) ? clap_551_pack_1 : clap_551_pack_0;
      signed int clap_551_0 = clap_551_0_cotmp_1;

      signed int clap_552_pack_0 = clap_551_0;
      // min clap_552_0 <= (clap_552_pack_1 , clap_552_pack_0)
      signed int clap_552_0_cotmp_1 = (clap_552_pack_1 < clap_552_pack_0) ? clap_552_pack_1 : clap_552_pack_0;
      signed int clap_552_0 = clap_552_0_cotmp_1;

      signed int clap_556_1 = clap_552_0;
      unsigned int lambda_isp_oldlua_line1274_169_1 = clap_556_1;
      signed int clap_556_2 = clap_555_0;
      unsigned int lambda_isp_oldlua_line1274_169_2 = clap_556_2;
      out(x,y,2) = lambda_isp_oldlua_line1274_169_2;
      out(x,y,1) = lambda_isp_oldlua_line1274_169_1;
      out(x,y,0) = lambda_isp_oldlua_line1274_169_0;
    }
  }
} // END lambda_isp_oldlua_line1274_220


void scheduledIRNode_13(const Image<int>& in, Image<int>& out
)
{
  for(int y = 0; y < in.height(); y++){
    for(int x = 0; x < in.width(); x++){
      unsigned int special0_pp_0_0_2 = in(x+0, y+0, 2);
      unsigned int special0_pp_0_0_1 = in(x+0, y+0, 1);
      unsigned int special0_pp_0_0_0 = in(x+0, y+0, 0);
      
      unsigned int cropSpecial0Node_5_0 = special0_pp_0_0_0;
      unsigned int cropSpecial0Node_5_1 = special0_pp_0_0_1;
      unsigned int cropSpecial0Node_5_2 = special0_pp_0_0_2;
      out(x,y,2) = cropSpecial0Node_5_2;
      out(x,y,1) = cropSpecial0Node_5_1;
      out(x,y,0) = cropSpecial0Node_5_0;
    }
  }
} // END scheduledIRNode_13


int main(int argc, char* argv[])
{
  int width = 1280;  // TODO change to match input image
  int height = 720;  // TODO change to match input image
  int channels = 3;  // TODO change to match input image
  Image<int> special0(width, height, channels, 0);
  special0.load(argv[1]);
  
  // Set tap values
  
  // Construct the pipeline of kernels
  Image<int> cropSpecial0Node_5(width, height, 3, 0);
  scheduledIRNode_13(special0, cropSpecial0Node_5
  );
  
  Image<int> lambda_isp_oldlua_line1282_727(width, height, 1, 0);
  lambda_isp_oldlua_line1282_33(cropSpecial0Node_5, lambda_isp_oldlua_line1282_727
  );
  
  Image<int> lambda_isp_oldlua_line1282_805(width, height, 1, 0);
  lambda_isp_oldlua_line1282_35(lambda_isp_oldlua_line1282_727, lambda_isp_oldlua_line1282_805
  );
  
  Image<int> lambda_isp_oldlua_line1282_848(width, height, 1, 0);
  lambda_isp_oldlua_line1282_37(lambda_isp_oldlua_line1282_805, lambda_isp_oldlua_line1282_848
  );
  
  Image<int> lambda_isp_oldlua_line1274_169(width, height, 3, 0);
  lambda_isp_oldlua_line1274_220(lambda_isp_oldlua_line1282_848, lambda_isp_oldlua_line1274_169
  );
  
  Image<int> lambda_isp_oldlua_line1329_1421(width, height, 3, 0);
  lambda_isp_oldlua_line1329_18(lambda_isp_oldlua_line1274_169, lambda_isp_oldlua_line1329_1421
  );
  
  lambda_isp_oldlua_line1329_1421.save("result.bmp");
  return(0);
}
