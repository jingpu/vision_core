#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "arch.h"
#include "pipeline.h"
#include "data.h"
#include <xtensa/sim.h>
#include <xtensa/hal.h>
#include <xtensa/config/core.h>
#include <xtensa/config/system.h>
#include <xtensa/xt_reftb.h>


int main(int argc, char* argv[])
{

  int width = 256;  // TODO change to match input image
  int height = 256/16;  // TODO change to match input image
  int channels = 3;  // TODO change to match input image

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

  Image<vector32> downCast_20_v(width/N, height, 1, zero_v);  
  Image<vector32> downCast_38_v(width/N, height, 1, zero_v); 


  setup_power_toggle();




#ifndef RTL_SIM
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
#endif

  // touch output data, to workaround dcache miss
  downCast_38_v.loadDAT(downCast_38_v_dat);
  // load input data
  downCast_20_v.loadDAT(downCast_20_v_dat);
  

#ifndef RTL_SIM
  xt_iss_trace_level(6);
  xt_iss_client_command("isa_profile", "enable");
#endif

  downCast_15(downCast_20_v, downCast_38_v
	      , tap_G1_0, tap_G0_0, tap_G2_0, tap_G4_0, tap_G3_0, tap_R_0);

#ifndef RTL_SIM
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_trace_level(0);
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
#endif

  downCast_38_v.cmpDAT(downCast_38_v_dat);  


  return 0;
}
