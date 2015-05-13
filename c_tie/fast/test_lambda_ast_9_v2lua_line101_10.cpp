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

const int width = 256;  // TODO change to match input image
const int height = 256;  // TODO change to match input image


// global var for input/output data
V16S in_img[width/N * (height + 6 ) * 1] __attribute__((section(".dram.data")));
V16S out_img[width/N * height * 1] __attribute__((section(".dram.data")));

int main(int argc, char* argv[])
{
  setup_power_toggle();
  
  V16S zero_v = mv_sv(0);
  Image<V16S> in1_43_pad_v(in_img, width/N, height+6, 1, zero_v);
  Image<V16S> lambda_ast_9_v2lua_line101_11_v(out_img, width/N, height, 1, zero_v);
  // load input data
  in1_43_pad_v.loadDAT(in1_43_pad_v_dat);
  
  #ifndef RTL_SIM
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_trace_level(6);
  xt_iss_client_command("isa_profile", "enable");
  #endif
  lambda_ast_9_v2lua_line101_10(in1_43_pad_v, lambda_ast_9_v2lua_line101_11_v
  	, tap_DarkBlob_0
  	, tap_LightBlob_0
  );
  #ifndef RTL_SIM
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_trace_level(0);
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  #endif
  
  // compare output data
  lambda_ast_9_v2lua_line101_11_v.cmpDAT(lambda_ast_9_v2lua_line101_11_v_dat);
  return 0;
}
