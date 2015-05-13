#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "arch.h"
#include "helper.h"
#include "pipeline_ref.h"
#include "pipeline.h"
#include <xtensa/sim.h>
#include <xtensa/hal.h>
#include <xtensa/config/core.h>
#include <xtensa/config/system.h>
#include <xtensa/xt_reftb.h>
int main(int argc, char* argv[])
{
  setup_power_toggle();
  
  // delete the existing data file
  FILE * fp = fopen("data.h", "w");
  fclose(fp);
  fp = fopen("data_downCast_27.h", "w");
  fclose(fp);

  const int width = 512;
  const int height = 512;
  const int channels = 3;
  Image<short> special0_ref(width, height, channels, 0);
  special0_ref.load(argv[1]);  // load the input image from file
  
  
  // Create a vector zero
  V16S zero_v = mv_sv(0);
  
  // Create the input image in vector format
  Image<V16S> special0_v(width/N, height, channels, zero_v);
  shuffle_s2v(special0_ref, special0_v);
  special0_v.dumpDAT("special0_v_dat");
  
  /*********************************************
   * Construct the pipeline of kernels
   *********************************************/
  Image<V16S> special0_pad_v(width/N, height+0+0, 3, zero_v);
  special0_pad_v.padZeros(special0_v, 0, 0);
  special0_pad_v.dumpDAT("special0_pad_v_dat");
  Image<V16S> cropSpecial0Node_7_v(width/N, height, 3, zero_v);
  Image<short> cropSpecial0Node_7(width, height, 3, 0);
  //xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  //xt_iss_client_command("isa_profile", "enable");
  scheduledIRNode_20(special0_pad_v, cropSpecial0Node_7_v
  );
  //xt_iss_client_command("isa_profile", "disable");
  //xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(cropSpecial0Node_7_v, cropSpecial0Node_7);
  //cropSpecial0Node_7.save("cropSpecial0Node_7.bmp");  // save image for debug
  cropSpecial0Node_7_v.dumpDAT("cropSpecial0Node_7_v_dat");
  
  Image<V16S> cropSpecial0Node_7_pad_v(width/N, height+0+0, 3, zero_v);
  cropSpecial0Node_7_pad_v.padZeros(cropSpecial0Node_7_v, 0, 0);
  cropSpecial0Node_7_pad_v.dumpDAT("cropSpecial0Node_7_pad_v_dat", "data_lambda_canny_v3lua_line39_10.h");
  Image<V16S> lambda_canny_v3lua_line39_55_v(width/N, height, 1, zero_v);
  Image<short> lambda_canny_v3lua_line39_55(width, height, 1, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  lambda_canny_v3lua_line39_10(cropSpecial0Node_7_pad_v, lambda_canny_v3lua_line39_55_v
  	, tap_Green_to_Lum_0
  	, tap_Blue_to_Lum_0
  	, tap_Red_to_Lum_0
  	, tap_R_0
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(lambda_canny_v3lua_line39_55_v, lambda_canny_v3lua_line39_55);
  //lambda_canny_v3lua_line39_55.save("lambda_canny_v3lua_line39_55.bmp");  // save image for debug
  lambda_canny_v3lua_line39_55_v.dumpDAT("lambda_canny_v3lua_line39_55_v_dat", "data_lambda_canny_v3lua_line39_10.h");
  
  Image<V16S> lambda_canny_v3lua_line39_55_pad_v(width/N, height+2+2, 1, zero_v);
  lambda_canny_v3lua_line39_55_pad_v.padZeros(lambda_canny_v3lua_line39_55_v, 2, 2);
  lambda_canny_v3lua_line39_55_pad_v.dumpDAT("lambda_canny_v3lua_line39_55_pad_v_dat", "data_downCast_27.h");
  Image<V16S> downCast_32_v(width/N, height, 1, zero_v);
  Image<short> downCast_32(width, height, 1, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  downCast_27(lambda_canny_v3lua_line39_55_pad_v, downCast_32_v
  	, tap_G1_0
  	, tap_G0_0
  	, tap_G2_0
  	, tap_G4_0
  	, tap_G3_0
  	, tap_R_0
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(downCast_32_v, downCast_32);
  //downCast_32.save("downCast_32.bmp");  // save image for debug
  downCast_32_v.dumpDAT("downCast_32_v_dat", "data_downCast_27.h");
  
  Image<V16S> downCast_32_pad_v(width/N, height+0+0, 1, zero_v);
  downCast_32_pad_v.padZeros(downCast_32_v, 0, 0);
  downCast_32_pad_v.dumpDAT("downCast_32_pad_v_dat", "data_downCast_29.h");
  Image<V16S> downCast_50_v(width/N, height, 1, zero_v);
  Image<short> downCast_50(width, height, 1, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  downCast_29(downCast_32_pad_v, downCast_50_v
  	, tap_G1_0
  	, tap_G0_0
  	, tap_G2_0
  	, tap_G4_0
  	, tap_G3_0
  	, tap_R_0
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(downCast_50_v, downCast_50);
  //downCast_50.save("downCast_50.bmp");  // save image for debug
  downCast_50_v.dumpDAT("downCast_50_v_dat", "data_downCast_29.h");
  
  Image<V16S> downCast_50_pad_v(width/N, height+1+1, 1, zero_v);
  downCast_50_pad_v.padZeros(downCast_50_v, 1, 1);
  downCast_50_pad_v.dumpDAT("downCast_50_pad_v_dat", "data_lambda_canny_v3lua_line65_27.h");
  Image<V16S> lambda_canny_v3lua_line65_111_v(width/N, height, 3, zero_v);
  Image<short> lambda_canny_v3lua_line65_111(width, height, 3, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  lambda_canny_v3lua_line65_27(downCast_50_pad_v, lambda_canny_v3lua_line65_111_v
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(lambda_canny_v3lua_line65_111_v, lambda_canny_v3lua_line65_111);
  //lambda_canny_v3lua_line65_111.save("lambda_canny_v3lua_line65_111.bmp");  // save image for debug
  lambda_canny_v3lua_line65_111_v.dumpDAT("lambda_canny_v3lua_line65_111_v_dat", "data_lambda_canny_v3lua_line65_27.h");
  
  Image<V16S> lambda_canny_v3lua_line65_111_pad_v(width/N, height+1+1, 3, zero_v);
  lambda_canny_v3lua_line65_111_pad_v.padZeros(lambda_canny_v3lua_line65_111_v, 1, 1);
  lambda_canny_v3lua_line65_111_pad_v.dumpDAT("lambda_canny_v3lua_line65_111_pad_v_dat", "data_lambda_canny_v3lua_line114_61.h");
  Image<V16S> lambda_canny_v3lua_line114_742_v(width/N, height, 2, zero_v);
  Image<short> lambda_canny_v3lua_line114_742(width, height, 2, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  lambda_canny_v3lua_line114_61(lambda_canny_v3lua_line65_111_pad_v, lambda_canny_v3lua_line114_742_v
  	, tap_Peak_0
  	, tap_Hyst_0
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(lambda_canny_v3lua_line114_742_v, lambda_canny_v3lua_line114_742);
  //lambda_canny_v3lua_line114_742.save("lambda_canny_v3lua_line114_742.bmp");  // save image for debug
  lambda_canny_v3lua_line114_742_v.dumpDAT("lambda_canny_v3lua_line114_742_v_dat", "data_lambda_canny_v3lua_line114_61.h");
  
  Image<V16S> lambda_canny_v3lua_line114_742_pad_v(width/N, height+5+5, 2, zero_v);
  lambda_canny_v3lua_line114_742_pad_v.padZeros(lambda_canny_v3lua_line114_742_v, 5, 5);
  lambda_canny_v3lua_line114_742_pad_v.dumpDAT("lambda_canny_v3lua_line114_742_pad_v_dat", "data_in1_7.h");
  Image<V16S> in1_9135_v(width/N, height, 2, zero_v);
  Image<short> in1_9135(width, height, 2, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  in1_7(lambda_canny_v3lua_line114_742_pad_v, in1_9135_v
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(in1_9135_v, in1_9135);
  //in1_9135.save("in1_9135.bmp");  // save image for debug
  in1_9135_v.dumpDAT("in1_9135_v_dat", "data_in1_7.h");
  
  Image<V16S> in1_9135_pad_v(width/N, height+0+0, 2, zero_v);
  in1_9135_pad_v.padZeros(in1_9135_v, 0, 0);
  in1_9135_pad_v.dumpDAT("in1_9135_pad_v_dat", "data_lambda_canny_v3lua_line164_28.h");
  Image<V16S> lambda_canny_v3lua_line164_71_v(width/N, height, 3, zero_v);
  Image<short> lambda_canny_v3lua_line164_71(width, height, 3, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  lambda_canny_v3lua_line164_28(in1_9135_pad_v, lambda_canny_v3lua_line164_71_v
  	, tap_SuppressLowPeak_0
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(lambda_canny_v3lua_line164_71_v, lambda_canny_v3lua_line164_71);
  //lambda_canny_v3lua_line164_71.save("lambda_canny_v3lua_line164_71.bmp");  // save image for debug
  lambda_canny_v3lua_line164_71_v.dumpDAT("lambda_canny_v3lua_line164_71_v_dat", "data_lambda_canny_v3lua_line164_28.h");
  
  
  // Create the output image in normal format
  lambda_canny_v3lua_line164_71.save("result.bmp");
  
  /*********************************************
   * Construct the pipeline of reference kernels
   *********************************************/
  Image<short> cropSpecial0Node_7_ref(width, height, 3, 0);
  scheduledIRNode_20(special0_ref, cropSpecial0Node_7_ref
  );
  cropSpecial0Node_7_ref.equal(cropSpecial0Node_7);  // check results
  
  Image<short> lambda_canny_v3lua_line39_55_ref(width, height, 1, 0);
  lambda_canny_v3lua_line39_10(cropSpecial0Node_7_ref, lambda_canny_v3lua_line39_55_ref
  	, tap_Green_to_Lum_0
  	, tap_Blue_to_Lum_0
  	, tap_Red_to_Lum_0
  	, tap_R_0
  );
  lambda_canny_v3lua_line39_55_ref.equal(lambda_canny_v3lua_line39_55);  // check results
  
  Image<short> downCast_32_ref(width, height, 1, 0);
  downCast_27(lambda_canny_v3lua_line39_55_ref, downCast_32_ref
  	, tap_G1_0
  	, tap_G0_0
  	, tap_G2_0
  	, tap_G4_0
  	, tap_G3_0
  	, tap_R_0
  );
  downCast_32_ref.equal(downCast_32);  // check results
  
  Image<short> downCast_50_ref(width, height, 1, 0);
  downCast_29(downCast_32_ref, downCast_50_ref
  	, tap_G1_0
  	, tap_G0_0
  	, tap_G2_0
  	, tap_G4_0
  	, tap_G3_0
  	, tap_R_0
  );
  downCast_50_ref.equal(downCast_50);  // check results
  
  Image<short> lambda_canny_v3lua_line65_111_ref(width, height, 3, 0);
  lambda_canny_v3lua_line65_27(downCast_50_ref, lambda_canny_v3lua_line65_111_ref
  );
  lambda_canny_v3lua_line65_111_ref.equal(lambda_canny_v3lua_line65_111);  // check results
  
  Image<short> lambda_canny_v3lua_line114_742_ref(width, height, 2, 0);
  lambda_canny_v3lua_line114_61(lambda_canny_v3lua_line65_111_ref, lambda_canny_v3lua_line114_742_ref
  	, tap_Peak_0
  	, tap_Hyst_0
  );
  lambda_canny_v3lua_line114_742_ref.equal(lambda_canny_v3lua_line114_742);  // check results
  
  Image<short> in1_9135_ref(width, height, 2, 0);
  in1_7(lambda_canny_v3lua_line114_742_ref, in1_9135_ref
  );
  in1_9135_ref.equal(in1_9135);  // check results
  
  Image<short> lambda_canny_v3lua_line164_71_ref(width, height, 3, 0);
  lambda_canny_v3lua_line164_28(in1_9135_ref, lambda_canny_v3lua_line164_71_ref
  	, tap_SuppressLowPeak_0
  );
  lambda_canny_v3lua_line164_71_ref.equal(lambda_canny_v3lua_line164_71);  // check results
  
  return 0;
}
