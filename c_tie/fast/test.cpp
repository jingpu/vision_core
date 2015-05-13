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
  const int width = 512;  // TODO change to match input image
  const int height = 512;  // TODO change to match input image
  const int channels = 3;  // TODO change to match input image
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
  scheduledIRNode_19(special0_pad_v, cropSpecial0Node_7_v
  );
  //xt_iss_client_command("isa_profile", "disable");
  //xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(cropSpecial0Node_7_v, cropSpecial0Node_7);
  //cropSpecial0Node_7.save("cropSpecial0Node_7.bmp");  // save image for debug
  cropSpecial0Node_7_v.dumpDAT("cropSpecial0Node_7_v_dat");
  
  Image<V16S> cropSpecial0Node_7_pad_v(width/N, height+0+0, 3, zero_v);
  cropSpecial0Node_7_pad_v.padZeros(cropSpecial0Node_7_v, 0, 0);
  cropSpecial0Node_7_pad_v.dumpDAT("cropSpecial0Node_7_pad_v_dat");
  Image<V16S> in1_43_v(width/N, height, 1, zero_v);
  Image<short> in1_43(width, height, 1, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  lambda_ast_9_v2lua_line35_10(cropSpecial0Node_7_pad_v, in1_43_v
  	, tap_Green_to_Lum_0
  	, tap_Blue_to_Lum_0
  	, tap_Red_to_Lum_0
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(in1_43_v, in1_43);
  //in1_43.save("in1_43.bmp");  // save image for debug
  in1_43_v.dumpDAT("in1_43_v_dat");
  
  Image<V16S> in1_43_pad_v(width/N, height+3+3, 1, zero_v);
  in1_43_pad_v.padZeros(in1_43_v, 3, 3);
  in1_43_pad_v.dumpDAT("in1_43_pad_v_dat");
  Image<V16S> lambda_ast_9_v2lua_line101_11_v(width/N, height, 1, zero_v);
  Image<short> lambda_ast_9_v2lua_line101_11(width, height, 1, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  lambda_ast_9_v2lua_line101_10(in1_43_pad_v, lambda_ast_9_v2lua_line101_11_v
  	, tap_DarkBlob_0
  	, tap_LightBlob_0
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(lambda_ast_9_v2lua_line101_11_v, lambda_ast_9_v2lua_line101_11);
  //lambda_ast_9_v2lua_line101_11.save("lambda_ast_9_v2lua_line101_11.bmp");  // save image for debug
  lambda_ast_9_v2lua_line101_11_v.dumpDAT("lambda_ast_9_v2lua_line101_11_v_dat");
  
  
  // Create the output image in normal format
  lambda_ast_9_v2lua_line101_11.save("result.bmp");
  
  /*********************************************
   * Construct the pipeline of reference kernels
   *********************************************/
  Image<short> cropSpecial0Node_7_ref(width, height, 3, 0);
  scheduledIRNode_19(special0_ref, cropSpecial0Node_7_ref
  );
  cropSpecial0Node_7_ref.equal(cropSpecial0Node_7);  // check results
  
  Image<short> in1_43_ref(width, height, 1, 0);
  lambda_ast_9_v2lua_line35_10(cropSpecial0Node_7_ref, in1_43_ref
  	, tap_Green_to_Lum_0
  	, tap_Blue_to_Lum_0
  	, tap_Red_to_Lum_0
  );
  in1_43_ref.equal(in1_43);  // check results
  
  Image<short> lambda_ast_9_v2lua_line101_11_ref(width, height, 1, 0);
  lambda_ast_9_v2lua_line101_10(in1_43_ref, lambda_ast_9_v2lua_line101_11_ref
  	, tap_DarkBlob_0
  	, tap_LightBlob_0
  );
  lambda_ast_9_v2lua_line101_11_ref.equal(lambda_ast_9_v2lua_line101_11);  // check results
  
  return 0;
}
