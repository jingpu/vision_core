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
vector32 in_img[width/N * (height + 0 ) * 3] __attribute__((section(".dram.data")));
vector32 out_img[width/N * height * 3] __attribute__((section(".dram.data")));

int main(int argc, char* argv[])
{
  setup_power_toggle();
  
  vector32 zero_v = mv16_sv(0);
  Image<vector32> special0_pad_v(in_img, width/N, height+0, 3, zero_v);
  Image<vector32> cropSpecial0Node_10_v(out_img, width/N, height, 3, zero_v);
  // load input data
  special0_pad_v.loadDAT(special0_pad_v_dat);
  
  #ifndef RTL_SIM
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_trace_level(6);
  xt_iss_client_command("isa_profile", "enable");
  #endif
  scheduledIRNode_28(special0_pad_v, cropSpecial0Node_10_v
  );
  #ifndef RTL_SIM
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_trace_level(0);
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  #endif
  
  // compare output data
  cropSpecial0Node_10_v.cmpDAT(cropSpecial0Node_10_v_dat);
  return 0;
}
