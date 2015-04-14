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
  const short width = 256;  // TODO change to match input image
  const short height = 256;  // TODO change to match input image
  const short channels = 3;  // TODO change to match input image
  Image<short> special0_ref(width, height, channels, 0);
  special0_ref.load(argv[1]);  // load the input image from file
  
  // Create a vector zero
  vector32 zero_v = mv16_sv(0);
  
  // Create the input image in vector format
  Image<vector32> special0_v(width/N, height, channels, zero_v);
  shuffle_s2v(special0_ref, special0_v);
  special0_v.dumpDAT("special0_v_dat");
  
  /*********************************************
   * Construct the pipeline of kernels
   *********************************************/
  Image<vector32> special0_pad_v(width/N, height+0+0, 3, zero_v);
  special0_pad_v.padZeros(special0_v, 0, 0);
  special0_pad_v.dumpDAT("special0_pad_v_dat");
  Image<vector32> cropSpecial0Node_10_v(width/N, height, 3, zero_v);
  Image<short> cropSpecial0Node_10(width, height, 3, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  scheduledIRNode_28(special0_pad_v, cropSpecial0Node_10_v
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(cropSpecial0Node_10_v, cropSpecial0Node_10);
  //cropSpecial0Node_10.save("cropSpecial0Node_10.bmp");  // save image for debug
  cropSpecial0Node_10_v.dumpDAT("cropSpecial0Node_10_v_dat");
  
  Image<vector32> cropSpecial0Node_10_pad_v(width/N, height+0+0, 3, zero_v);
  cropSpecial0Node_10_pad_v.padZeros(cropSpecial0Node_10_v, 0, 0);
  cropSpecial0Node_10_pad_v.dumpDAT("cropSpecial0Node_10_pad_v_dat");
  Image<vector32> lambda_arris_v3lua_line43_51_v(width/N, height, 1, zero_v);
  Image<short> lambda_arris_v3lua_line43_51(width, height, 1, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  lambda_arris_v3lua_line43_10(cropSpecial0Node_10_pad_v, lambda_arris_v3lua_line43_51_v
  	, tap_Green_to_Lum_0
  	, tap_Blue_to_Lum_0
  	, tap_Red_to_Lum_0
  	, tap_R_0
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(lambda_arris_v3lua_line43_51_v, lambda_arris_v3lua_line43_51);
  //lambda_arris_v3lua_line43_51.save("lambda_arris_v3lua_line43_51.bmp");  // save image for debug
  lambda_arris_v3lua_line43_51_v.dumpDAT("lambda_arris_v3lua_line43_51_v_dat");
  
  Image<vector32> lambda_arris_v3lua_line43_51_pad_v(width/N, height+2+2, 1, zero_v);
  lambda_arris_v3lua_line43_51_pad_v.padZeros(lambda_arris_v3lua_line43_51_v, 2, 2);
  lambda_arris_v3lua_line43_51_pad_v.dumpDAT("lambda_arris_v3lua_line43_51_pad_v_dat");
  Image<vector32> downCast_20_v(width/N, height, 1, zero_v);
  Image<short> downCast_20(width, height, 1, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  downCast_13(lambda_arris_v3lua_line43_51_pad_v, downCast_20_v
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
  shuffle_v2s(downCast_20_v, downCast_20);
  //downCast_20.save("downCast_20.bmp");  // save image for debug
  downCast_20_v.dumpDAT("downCast_20_v_dat");
  
  Image<vector32> downCast_20_pad_v(width/N, height+0+0, 1, zero_v);
  downCast_20_pad_v.padZeros(downCast_20_v, 0, 0);
  downCast_20_pad_v.dumpDAT("downCast_20_pad_v_dat");
  Image<vector32> downCast_38_v(width/N, height, 1, zero_v);
  Image<short> downCast_38(width, height, 1, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  downCast_15(downCast_20_pad_v, downCast_38_v
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
  shuffle_v2s(downCast_38_v, downCast_38);
  //downCast_38.save("downCast_38.bmp");  // save image for debug
  downCast_38_v.dumpDAT("downCast_38_v_dat");
  
  Image<vector32> downCast_38_pad_v(width/N, height+1+1, 1, zero_v);
  downCast_38_pad_v.padZeros(downCast_38_v, 1, 1);
  downCast_38_pad_v.dumpDAT("downCast_38_pad_v_dat");
  Image<vector32> Resp_32_v(width/N, height, 1, zero_v);
  Image<short> Resp_32(width, height, 1, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  Resp_5(downCast_38_pad_v, Resp_32_v
  	, tap_K_0
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(Resp_32_v, Resp_32);
  //Resp_32.save("Resp_32.bmp");  // save image for debug
  Resp_32_v.dumpDAT("Resp_32_v_dat");
  
  Image<vector32> Resp_32_pad_v(width/N, height+1+1, 1, zero_v);
  Resp_32_pad_v.padZeros(Resp_32_v, 1, 1);
  Resp_32_pad_v.dumpDAT("Resp_32_pad_v_dat");
  Image<vector32> NMS_11_v(width/N, height, 1, zero_v);
  Image<short> NMS_11(width, height, 1, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  NMS_10(Resp_32_pad_v, NMS_11_v
  	, tap_Peak_0
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(NMS_11_v, NMS_11);
  //NMS_11.save("NMS_11.bmp");  // save image for debug
  NMS_11_v.dumpDAT("NMS_11_v_dat");
  
  
  // Create the output image in normal format
  NMS_11.save("result.bmp");
  
  /*********************************************
   * Construct the pipeline of reference kernels
   *********************************************/
  Image<short> cropSpecial0Node_10_ref(width, height, 3, 0);
  scheduledIRNode_28(special0_ref, cropSpecial0Node_10_ref
  );
  cropSpecial0Node_10_ref.equal(cropSpecial0Node_10);  // check results
  
  Image<short> lambda_arris_v3lua_line43_51_ref(width, height, 1, 0);
  lambda_arris_v3lua_line43_10(cropSpecial0Node_10_ref, lambda_arris_v3lua_line43_51_ref
  	, tap_Green_to_Lum_0
  	, tap_Blue_to_Lum_0
  	, tap_Red_to_Lum_0
  	, tap_R_0
  );
  lambda_arris_v3lua_line43_51_ref.equal(lambda_arris_v3lua_line43_51);  // check results
  
  Image<short> downCast_20_ref(width, height, 1, 0);
  downCast_13(lambda_arris_v3lua_line43_51_ref, downCast_20_ref
  	, tap_G1_0
  	, tap_G0_0
  	, tap_G2_0
  	, tap_G4_0
  	, tap_G3_0
  	, tap_R_0
  );
  downCast_20_ref.equal(downCast_20);  // check results
  
  Image<short> downCast_38_ref(width, height, 1, 0);
  downCast_15(downCast_20_ref, downCast_38_ref
  	, tap_G1_0
  	, tap_G0_0
  	, tap_G2_0
  	, tap_G4_0
  	, tap_G3_0
  	, tap_R_0
  );
  downCast_38_ref.equal(downCast_38);  // check results
  
  Image<short> Resp_32_ref(width, height, 1, 0);
  Resp_5(downCast_38_ref, Resp_32_ref
  	, tap_K_0
  );
  Resp_32_ref.equal(Resp_32);  // check results
  
  Image<short> NMS_11_ref(width, height, 1, 0);
  NMS_10(Resp_32_ref, NMS_11_ref
  	, tap_Peak_0
  );
  NMS_11_ref.equal(NMS_11);  // check results
  
  return 0;
}
