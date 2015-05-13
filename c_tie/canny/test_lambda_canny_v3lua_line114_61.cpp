#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "arch.h"
#include "pipeline.h"
#include "data_lambda_canny_v3lua_line114_61.h"
#include <xtensa/sim.h>
#include <xtensa/hal.h>
#include <xtensa/config/core.h>
#include <xtensa/config/system.h>
#include <xtensa/xt_reftb.h>

const int width = 512;  // TODO change to match input image
const int height = 512;  // TODO change to match input image


// global var for input/output data
V16S in_img[width/N * (height + 2 ) * 3] __attribute__((section(".dram.data")));
V16S out_img[width/N * height * 2] __attribute__((section(".dram.data")));

int main(int argc, char* argv[])
{
  setup_power_toggle();
  
  V16S zero_v = mv_sv(0);
  Image<V16S> lambda_canny_v3lua_line65_111_pad_v(in_img, width/N, height+2, 3, zero_v);
  Image<V16S> lambda_canny_v3lua_line114_742_v(out_img, width/N, height, 2, zero_v);
  // load input data
  lambda_canny_v3lua_line65_111_pad_v.loadDAT(lambda_canny_v3lua_line65_111_pad_v_dat);
  
  #ifndef RTL_SIM
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_trace_level(6);
  xt_iss_client_command("isa_profile", "enable");
  #endif
  lambda_canny_v3lua_line114_61(lambda_canny_v3lua_line65_111_pad_v, lambda_canny_v3lua_line114_742_v
  	, tap_Peak_0
  	, tap_Hyst_0
  );
  #ifndef RTL_SIM
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_trace_level(0);
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  #endif
  
  // compare output data
  lambda_canny_v3lua_line114_742_v.cmpDAT(lambda_canny_v3lua_line114_742_v_dat);
  return 0;
}
