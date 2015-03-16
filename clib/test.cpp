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
  int width = 256;  // TODO change to match input image
  int height = 256;  // TODO change to match input image
  int channels = 3;  // TODO change to match input image
  Image<int> special0(width, height, channels, 0);
  special0.load(argv[1]);  // load the input image from file
  
  // Set tap values
  unsigned int tap_Green_to_Lum_0 = 54; 	// TODO change in value
  unsigned int tap_Blue_to_Lum_0 =183; 	// TODO change in value
  unsigned int tap_Red_to_Lum_0 = 18; 	// TODO change in value
  unsigned int tap_G1_0 = 14; 	// TODO change in value
  unsigned int tap_G0_0 = 62; 	// TODO change in value
  unsigned int tap_G2_0 = 104; 	// TODO change in value
  unsigned int tap_G4_0 = 62; 	// TODO change in value
  unsigned int tap_G3_0 = 14; 	// TODO change in value
  unsigned int tap_R_0 = 8; 	// TODO change in value
  signed int tap_K_0 = 1; 	// TODO change in value
  signed int tap_Peak_0 = 128; 	// TODO change in value
  
  // Create a vector zero
  vector32 zero_v = mv32_sv(0);
  
  // Create the input image in vector format
  Image<vector32> special0_v(width/N, height, channels, zero_v);
  shuffle_s2v(special0, special0_v);
  special0_v.dumpDAT("special0_v.dat");
  
  // Construct the pipeline of kernels
  Image<vector32> cropSpecial0Node_10_v(width/N, height, 3, zero_v);
  Image<int> cropSpecial0Node_10(width, height, 3, 0);
  scheduledIRNode_28(special0_v, cropSpecial0Node_10_v);
  shuffle_v2s(cropSpecial0Node_10_v, cropSpecial0Node_10);
  //cropSpecial0Node_10.save("cropSpecial0Node_10.bmp");
  cropSpecial0Node_10_v.dumpDAT("cropSpecial0Node_10_v.dat");
  
  Image<vector32> lambda_arris_v3lua_line43_51_v(width/N, height, 1, zero_v);
  Image<int> lambda_arris_v3lua_line43_51(width, height, 1, 0);
  lambda_arris_v3lua_line43_10(cropSpecial0Node_10_v, lambda_arris_v3lua_line43_51_v
  	, tap_Green_to_Lum_0
  	, tap_Blue_to_Lum_0
  	, tap_Red_to_Lum_0  );
  shuffle_v2s(lambda_arris_v3lua_line43_51_v, lambda_arris_v3lua_line43_51);
  //lambda_arris_v3lua_line43_51.save("lambda_arris_v3lua_line43_51.bmp");
  lambda_arris_v3lua_line43_51_v.dumpDAT("lambda_arris_v3lua_line43_51_v.dat");
  
  Image<vector32> downCast_20_v(width/N, height, 1, zero_v);
  Image<int> downCast_20(width, height, 1, 0);
  downCast_13(lambda_arris_v3lua_line43_51_v, downCast_20_v
  	, tap_G1_0, tap_G0_0, tap_G2_0, tap_G4_0, tap_G3_0, tap_R_0 );
  shuffle_v2s(downCast_20_v, downCast_20);
  //downCast_20.save("downCast_20.bmp");
  downCast_20_v.dumpDAT("downCast_20_v.dat");
  
  Image<vector32> downCast_38_v(width/N, height, 1, zero_v);
  Image<int> downCast_38(width, height, 1, 0);

  setup_power_toggle();

  //xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  //xt_iss_client_command("isa_profile", "enable");
  downCast_15(downCast_20_v, downCast_38_v
  	, tap_G1_0
  	, tap_G0_0
  	, tap_G2_0
  	, tap_G4_0
  	, tap_G3_0
  	, tap_R_0
  );
  //xt_iss_client_command("isa_profile", "disable");
  //xt_iss_switch_mode(XT_ISS_FUNCTIONAL);

  shuffle_v2s(downCast_38_v, downCast_38);
  //downCast_38.save("downCast_38.bmp");
  downCast_38_v.dumpDAT("downCast_38_v.dat");  


  Image<vector32> Resp_32_v(width/N, height, 1, zero_v);
  Image<int> Resp_32(width, height, 1, 0);
  Resp_5(downCast_38_v, Resp_32_v, tap_K_0 );
  shuffle_v2s(Resp_32_v, Resp_32);
  //Resp_32.save("Resp_32.bmp");
  Resp_32_v.dumpDAT("Resp_32_v.dat");

  Image<vector32> NMS_11_v(width/N, height, 1, zero_v);
  Image<int> NMS_11(width, height, 1, 0);
  NMS_10(Resp_32_v, NMS_11_v, tap_Peak_0);
  shuffle_v2s(NMS_11_v, NMS_11);
  NMS_11.save("NMS_11.bmp");
  NMS_11_v.dumpDAT("NMS_11_v.dat");  
  
  // Create the output image in normal format


  // Construct the pipeline of reference kernels
  Image<int> cropSpecial0Node_10_ref(width, height, channels, 0);
  scheduledIRNode_28(special0, cropSpecial0Node_10_ref);

  Image<int> lambda_arris_v3lua_line43_51_ref(width, height, 1, 0);
  lambda_arris_v3lua_line43_10(cropSpecial0Node_10_ref, lambda_arris_v3lua_line43_51_ref
			       , tap_Green_to_Lum_0, tap_Blue_to_Lum_0, tap_Red_to_Lum_0);
  
  Image<int> downCast_20_ref(width, height, 1, 0);
  downCast_13(lambda_arris_v3lua_line43_51_ref, downCast_20_ref
	      , tap_G1_0, tap_G0_0, tap_G2_0, tap_G4_0, tap_G3_0, tap_R_0);

  Image<int> downCast_38_ref(width, height, 1, 0);
  downCast_15(downCast_20_ref, downCast_38_ref
	      , tap_G1_0, tap_G0_0, tap_G2_0, tap_G4_0, tap_G3_0, tap_R_0);
 

  Image<int> Resp_32_ref(width, height, 1, 0);
  Resp_5(downCast_38_ref, Resp_32_ref, tap_K_0);

  Image<int> NMS_11_ref(width, height, 1, 0);
  NMS_10(Resp_32_ref, NMS_11_ref, tap_Peak_0);

  // Check points
  cropSpecial0Node_10_ref.equal(cropSpecial0Node_10);
  lambda_arris_v3lua_line43_51_ref.equal(lambda_arris_v3lua_line43_51);
  downCast_20_ref.equal(downCast_20);
  downCast_38_ref.equal(downCast_38);
  Resp_32_ref.equal(Resp_32);
  NMS_11_ref.equal(NMS_11);
  NMS_11_ref.save("NMS_11_ref.bmp");
 


  return 0;
}
