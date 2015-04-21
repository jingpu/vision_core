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

const int width = 512;  // TODO change to match input image
const int height = 512;  // TODO change to match input image


// global var for input/output data
vector32 in_img[width/N * (height + 4 ) * 1] __attribute__((section(".dram.data")));
vector32 out_img[width/N * height * 1] __attribute__((section(".dram.data")));

int main(int argc, char* argv[])
{
  setup_power_toggle();
  
  vector32 zero_v = mv16_sv(0);
  Image<vector32> lambda_arris_v3lua_line43_51_pad_v(in_img, width/N, height+4, 1, zero_v);
  Image<vector32> downCast_20_v(out_img, width/N, height, 1, zero_v);
  // load input data
  lambda_arris_v3lua_line43_51_pad_v.loadDAT(lambda_arris_v3lua_line43_51_pad_v_dat);
  
  #ifndef RTL_SIM
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_trace_level(6);
  xt_iss_client_command("isa_profile", "enable");
  #endif
  downCast_13(lambda_arris_v3lua_line43_51_pad_v, downCast_20_v
  	, tap_G1_0
  	, tap_G0_0
  	, tap_G2_0
  	, tap_G4_0
  	, tap_G3_0
  	, tap_R_0
  );
  #ifndef RTL_SIM
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_trace_level(0);
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  #endif
  
  // compare output data
  downCast_20_v.cmpDAT(downCast_20_v_dat);
  return 0;
}
