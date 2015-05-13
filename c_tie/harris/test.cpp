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
  Image<int> special0_ref(width, height, channels, 0);
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
  Image<int> cropSpecial0Node_7(width, height, 3, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  scheduledIRNode_19(special0_pad_v, cropSpecial0Node_7_v
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(cropSpecial0Node_7_v, cropSpecial0Node_7);
  //cropSpecial0Node_7.save("cropSpecial0Node_7.bmp");  // save image for debug
  cropSpecial0Node_7_v.dumpDAT("cropSpecial0Node_7_v_dat");
  
  Image<V16S> cropSpecial0Node_7_pad_v(width/N, height+0+0, 3, zero_v);
  cropSpecial0Node_7_pad_v.padZeros(cropSpecial0Node_7_v, 0, 0);
  cropSpecial0Node_7_pad_v.dumpDAT("cropSpecial0Node_7_pad_v_dat");
  Image<V16S> convertToIllum_55_v(width/N, height, 1, zero_v);
  Image<int> convertToIllum_55(width, height, 1, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  convertToIllum_10(cropSpecial0Node_7_pad_v, convertToIllum_55_v
  	, tap_Green_to_Lum_0
  	, tap_Blue_to_Lum_0
  	, tap_Red_to_Lum_0
  	, tap_R_0
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(convertToIllum_55_v, convertToIllum_55);
  //convertToIllum_55.save("convertToIllum_55.bmp");  // save image for debug
  convertToIllum_55_v.dumpDAT("convertToIllum_55_v_dat");
  
  Image<V16S> convertToIllum_55_pad_v(width/N, height+2+2, 1, zero_v);
  convertToIllum_55_pad_v.padZeros(convertToIllum_55_v, 2, 2);
  convertToIllum_55_pad_v.dumpDAT("convertToIllum_55_pad_v_dat");
  Image<V16S> downCast_20_v(width/N, height, 1, zero_v);
  Image<int> downCast_20(width, height, 1, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  downCast_13(convertToIllum_55_pad_v, downCast_20_v
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
  
  Image<V16S> downCast_20_pad_v(width/N, height+0+0, 1, zero_v);
  downCast_20_pad_v.padZeros(downCast_20_v, 0, 0);
  downCast_20_pad_v.dumpDAT("downCast_20_pad_v_dat");
  Image<V16S> downCast_38_v(width/N, height, 1, zero_v);
  Image<int> downCast_38(width, height, 1, 0);
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
  
  Image<V16S> downCast_38_pad_v(width/N, height+1+1, 1, zero_v);
  downCast_38_pad_v.padZeros(downCast_38_v, 1, 1);
  downCast_38_pad_v.dumpDAT("downCast_38_pad_v_dat");
  Image<V16S> Resp_18_v(width/N, height, 1, zero_v);
  Image<int> Resp_18(width, height, 1, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  Resp_5(downCast_38_pad_v, Resp_18_v
  	, tap_K_0
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(Resp_18_v, Resp_18);
  //Resp_18.save("Resp_18.bmp");  // save image for debug
  Resp_18_v.dumpDAT("Resp_18_v_dat");
  
  Image<V16S> Resp_18_pad_v(width/N, height+1+1, 1, zero_v);
  Resp_18_pad_v.padZeros(Resp_18_v, 1, 1);
  Resp_18_pad_v.dumpDAT("Resp_18_pad_v_dat");
  Image<V16S> NMS_9_v(width/N, height, 1, zero_v);
  Image<int> NMS_9(width, height, 1, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  NMS_10(Resp_18_pad_v, NMS_9_v
  	, tap_Peak_0
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(NMS_9_v, NMS_9);
  //NMS_9.save("NMS_9.bmp");  // save image for debug
  NMS_9_v.dumpDAT("NMS_9_v_dat");
  
  
  // Create the output image in normal format
  NMS_9.save("result.bmp");
  
  /*********************************************
   * Construct the pipeline of reference kernels
   *********************************************/
  Image<int> cropSpecial0Node_7_ref(width, height, 3, 0);
  scheduledIRNode_19(special0_ref, cropSpecial0Node_7_ref
  );
  cropSpecial0Node_7_ref.equal(cropSpecial0Node_7);  // check results
  
  Image<int> convertToIllum_55_ref(width, height, 1, 0);
  convertToIllum_10(cropSpecial0Node_7_ref, convertToIllum_55_ref
  	, tap_Green_to_Lum_0
  	, tap_Blue_to_Lum_0
  	, tap_Red_to_Lum_0
  	, tap_R_0
  );
  convertToIllum_55_ref.equal(convertToIllum_55);  // check results
  
  Image<int> downCast_20_ref(width, height, 1, 0);
  downCast_13(convertToIllum_55_ref, downCast_20_ref
  	, tap_G1_0
  	, tap_G0_0
  	, tap_G2_0
  	, tap_G4_0
  	, tap_G3_0
  	, tap_R_0
  );
  downCast_20_ref.equal(downCast_20);  // check results
  
  Image<int> downCast_38_ref(width, height, 1, 0);
  downCast_15(downCast_20_ref, downCast_38_ref
  	, tap_G1_0
  	, tap_G0_0
  	, tap_G2_0
  	, tap_G4_0
  	, tap_G3_0
  	, tap_R_0
  );
  downCast_38_ref.equal(downCast_38);  // check results
  
  Image<int> Resp_18_ref(width, height, 1, 0);
  Resp_5(downCast_38_ref, Resp_18_ref
  	, tap_K_0
  );
  Resp_18_ref.equal(Resp_18);  // check results
  
  Image<int> NMS_9_ref(width, height, 1, 0);
  NMS_10(Resp_18_ref, NMS_9_ref
  	, tap_Peak_0
  );
  NMS_9_ref.equal(NMS_9);  // check results
  
  return 0;
}
