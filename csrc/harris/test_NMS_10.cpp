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
vector32 in_img[width/N * (height + 2 ) * 1] __attribute__((section(".dram.data")));
vector32 out_img[width/N * height * 1] __attribute__((section(".dram.data")));

int main(int argc, char* argv[])
{
  setup_power_toggle();
  
  vector32 zero_v = mv16_sv(0);
  Image<vector32> Resp_32_pad_v(in_img, width/N, height+2, 1, zero_v);
  Image<vector32> NMS_11_v(out_img, width/N, height, 1, zero_v);
  // load input data
  Resp_32_pad_v.loadDAT(Resp_32_pad_v_dat);
  
  #ifndef RTL_SIM
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_trace_level(6);
  xt_iss_client_command("isa_profile", "enable");
  #endif
  NMS_10(Resp_32_pad_v, NMS_11_v
  	, tap_Peak_0
  );
  #ifndef RTL_SIM
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_trace_level(0);
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  #endif
  
  // compare output data
  NMS_11_v.cmpDAT(NMS_11_v_dat);
  return 0;
}
