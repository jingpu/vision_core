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
  const int width = 256;  // TODO change to match input image
  const int height = 256;  // TODO change to match input image
  const int channels = 1;  // TODO change to match input image
  Image<int> special0_ref(width, height, channels, 0);
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
  Image<vector32> special0_pad_v(width/N, height+0+0, 1, zero_v);
  special0_pad_v.padZeros(special0_v, 0, 0);
  special0_pad_v.dumpDAT("special0_pad_v_dat");
  Image<vector32> cropSpecial0Node_v(width/N, height, 1, zero_v);
  Image<int> cropSpecial0Node(width, height, 1, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  scheduledIRNode(special0_pad_v, cropSpecial0Node_v
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(cropSpecial0Node_v, cropSpecial0Node);
  //cropSpecial0Node.save("cropSpecial0Node.bmp");  // save image for debug
  cropSpecial0Node_v.dumpDAT("cropSpecial0Node_v_dat");
  
  Image<vector32> cropSpecial0Node_pad_v(width/N, height+0+0, 1, zero_v);
  cropSpecial0Node_pad_v.padZeros(cropSpecial0Node_v, 0, 0);
  cropSpecial0Node_pad_v.dumpDAT("cropSpecial0Node_pad_v_dat");
  Image<vector32> calcBlc_78_v(width/N, height, 1, zero_v);
  Image<int> calcBlc_78(width, height, 1, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  calcBlc_3(cropSpecial0Node_pad_v, calcBlc_78_v
  	, tap_blc_offsetGr_0
  	, tap_blc_offsetR_0
  	, tap_blc_offsetB_0
  	, tap_blc_offsetGb_0
  	, tap_blc_gainGR_0
  	, tap_blc_gainR_0
  	, tap_blc_gainB_0
  	, tap_blc_gainGb_0
  	, tap_blc_shift_0
  	, tap_blc_limit_0
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(calcBlc_78_v, calcBlc_78);
  //calcBlc_78.save("calcBlc_78.bmp");  // save image for debug
  calcBlc_78_v.dumpDAT("calcBlc_78_v_dat");
  
  Image<vector32> calcBlc_78_pad_v(width/N, height+2+2, 1, zero_v);
  calcBlc_78_pad_v.padZeros(calcBlc_78_v, 2, 2);
  calcBlc_78_pad_v.dumpDAT("calcBlc_78_pad_v_dat");
  Image<vector32> dpc_103_v(width/N, height, 1, zero_v);
  Image<int> dpc_103(width, height, 1, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  dpc_3(calcBlc_78_pad_v, dpc_103_v
  	, tap_dpc_edgeThrLow_0
  	, tap_dpc_edgeThrHigh_0
  	, tap_dpc_decisionThr_0
  	, tap_dpc_maxDiffRes_0
  	, tap_dpc_coldPixThr_0
  	, tap_dpc_coldPixFctr_0
  	, tap_dpc_hotPixThr_0
  	, tap_dpc_hotPixFctr_0
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(dpc_103_v, dpc_103);
  //dpc_103.save("dpc_103.bmp");  // save image for debug
  dpc_103_v.dumpDAT("dpc_103_v_dat");
  
  Image<vector32> dpc_103_pad_v(width/N, height+2+2, 1, zero_v);
  dpc_103_pad_v.padZeros(dpc_103_v, 2, 2);
  dpc_103_pad_v.dumpDAT("dpc_103_pad_v_dat");
  Image<vector32> calcXtk_116_v(width/N, height, 1, zero_v);
  Image<int> calcXtk_116(width, height, 1, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  calcXtk_3(dpc_103_pad_v, calcXtk_116_v
  	, tap_xtk_lowThr_0
  	, tap_xtk_highThr_0
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(calcXtk_116_v, calcXtk_116);
  //calcXtk_116.save("calcXtk_116.bmp");  // save image for debug
  calcXtk_116_v.dumpDAT("calcXtk_116_v_dat");
  
  Image<vector32> calcXtk_116_pad_v(width/N, height+2+2, 1, zero_v);
  calcXtk_116_pad_v.padZeros(calcXtk_116_v, 2, 2);
  calcXtk_116_pad_v.dumpDAT("calcXtk_116_pad_v_dat");
  Image<vector32> calcWbg_46_v(width/N, height, 1, zero_v);
  Image<int> calcWbg_46(width, height, 1, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  calcWbg_3(calcXtk_116_pad_v, calcWbg_46_v
  	, tap_den_spatWgt_0
  	, tap_den_lowThr_0
  	, tap_den_highThr_0
  	, tap_den_offsetY_0
  	, tap_den_crdShift_0
  	, tap_den_offsetX_0
  	, tap_den_radFctr_0
  	, tap_den_radShift_0
  	, tap_den_radOffset_0
  	, tap_den_radMin_0
  	, tap_den_radMax_0
  	, tap_den_dirDen_0
  	, tap_den_dirMtrThr_0
  	, tap_den_dFLow_0
  	, tap_den_dFHigh_0
  	, tap_den_dirShift_0
  	, tap_wbg_grainG_0
  	, tap_wbg_grainR_0
  	, tap_wbg_grainB_0
  	, tap_wbg_grainAll_0
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(calcWbg_46_v, calcWbg_46);
  //calcWbg_46.save("calcWbg_46.bmp");  // save image for debug
  calcWbg_46_v.dumpDAT("calcWbg_46_v_dat");
  
  Image<vector32> calcWbg_46_pad_v(width/N, height+3+3, 1, zero_v);
  calcWbg_46_pad_v.padZeros(calcWbg_46_v, 3, 3);
  calcWbg_46_pad_v.dumpDAT("calcWbg_46_pad_v_dat");
  Image<vector32> calcDem_324_v(width/N, height, 3, zero_v);
  Image<int> calcDem_324(width, height, 3, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  calcDem_3(calcWbg_46_pad_v, calcDem_324_v
  	, tap_dem_wg_0
  	, tap_dem_wc_0
  	, tap_dem_dirThr_0
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(calcDem_324_v, calcDem_324);
  //calcDem_324.save("calcDem_324.bmp");  // save image for debug
  calcDem_324_v.dumpDAT("calcDem_324_v_dat");
  
  Image<vector32> calcDem_324_pad_v(width/N, height+2+2, 3, zero_v);
  calcDem_324_pad_v.padZeros(calcDem_324_v, 2, 2);
  calcDem_324_pad_v.dumpDAT("calcDem_324_pad_v_dat");
  Image<vector32> srp_385_v(width/N, height, 3, zero_v);
  Image<int> srp_385(width, height, 3, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  srp_3(calcDem_324_pad_v, srp_385_v
  	, tap_srp_hfPwr_0
  	, tap_srp_minHfVal_0
  	, tap_srp_maxHfVal_0
  	, tap_srp_mfPwr_0
  	, tap_srp_minMfVal_0
  	, tap_srp_maxMfVal_0
  	, tap_srp_edgeThr_0
  	, tap_srp_edgeSlp_0
  	, tap_srp_edgeSft_0
  	, tap_srp_lslCntWgt_0
  	, tap_srp_hslCntWgt_0
  	, tap_srp_lshCntWgt_0
  	, tap_srp_hshCntWgt_0
  	, tap_srp_offsetY_0
  	, tap_srp_crdShift_0
  	, tap_srp_offsetX_0
  	, tap_srp_radFctr_0
  	, tap_srp_radShift_0
  	, tap_srp_radOffset_0
  	, tap_srp_radMin_0
  	, tap_srp_radMax_0
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(srp_385_v, srp_385);
  //srp_385.save("srp_385.bmp");  // save image for debug
  srp_385_v.dumpDAT("srp_385_v_dat");
  
  Image<vector32> srp_385_pad_v(width/N, height+1+1, 3, zero_v);
  srp_385_pad_v.padZeros(srp_385_v, 1, 1);
  srp_385_pad_v.dumpDAT("srp_385_pad_v_dat");
  Image<vector32> ccf_57_v(width/N, height, 3, zero_v);
  Image<int> ccf_57(width, height, 3, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  ccf_3(srp_385_pad_v, ccf_57_v
  	, tap_ccm_avgCFlag_0
  	, tap_ccm_colorSatLow_0
  	, tap_ccm_colorSatHigh_0
  	, tap_ccm_mat0_0
  	, tap_ccm_mat3_0
  	, tap_ccm_mat6_0
  	, tap_ccm_mat1_0
  	, tap_ccm_mat4_0
  	, tap_ccm_mat7_0
  	, tap_ccm_mat2_0
  	, tap_ccm_mat5_0
  	, tap_ccm_mat8_0
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(ccf_57_v, ccf_57);
  //ccf_57.save("ccf_57.bmp");  // save image for debug
  ccf_57_v.dumpDAT("ccf_57_v_dat");
  
  Image<vector32> ccf_57_pad_v(width/N, height+3+3, 3, zero_v);
  ccf_57_pad_v.padZeros(ccf_57_v, 3, 3);
  ccf_57_pad_v.dumpDAT("ccf_57_pad_v_dat");
  Image<vector32> srp_427_v(width/N, height, 3, zero_v);
  Image<int> srp_427(width, height, 3, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  cnr_3(ccf_57_pad_v, srp_427_v
  	, tap_cnr_denYChFlag_0
  	, tap_cnr_denYLowThr_0
  	, tap_cnr_denYHighThr_0
  	, tap_cnr_offsetY_0
  	, tap_cnr_crdShift_0
  	, tap_cnr_offsetX_0
  	, tap_cnr_radFctr_0
  	, tap_cnr_radShift_0
  	, tap_cnr_radOffset_0
  	, tap_cnr_radMin_0
  	, tap_cnr_radMax_0
  	, tap_cnr_useSigmaFilter0_0
  	, tap_cnr_denUVChsFlag_0
  	, tap_cnr_denUVLowThr_0
  	, tap_cnr_denUVHighThr_0
  	, tap_cnr_useSigmaFilter1_0
  	, tap_cnr_useSigmaFilter2_0
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(srp_427_v, srp_427);
  //srp_427.save("srp_427.bmp");  // save image for debug
  srp_427_v.dumpDAT("srp_427_v_dat");
  
  Image<vector32> srp_427_pad_v(width/N, height+0+0, 3, zero_v);
  srp_427_pad_v.padZeros(srp_427_v, 0, 0);
  srp_427_pad_v.dumpDAT("srp_427_pad_v_dat");
  Image<vector32> ct8_243_v(width/N, height, 3, zero_v);
  Image<int> ct8_243(width, height, 3, 0);
  xt_iss_switch_mode(XT_ISS_CYCLE_ACCURATE);
  xt_iss_client_command("isa_profile", "enable");
  ct8_3(srp_427_pad_v, ct8_243_v
  );
  xt_iss_client_command("isa_profile", "disable");
  xt_iss_switch_mode(XT_ISS_FUNCTIONAL);
  // save the output
  shuffle_v2s(ct8_243_v, ct8_243);
  //ct8_243.save("ct8_243.bmp");  // save image for debug
  ct8_243_v.dumpDAT("ct8_243_v_dat");
  
  
  // Create the output image in normal format
  ct8_243.save("result.bmp");
  
  /*********************************************
   * Construct the pipeline of reference kernels
   *********************************************/
  Image<int> cropSpecial0Node_ref(width, height, 1, 0);
  scheduledIRNode(special0_ref, cropSpecial0Node_ref
  );
  cropSpecial0Node_ref.equal(cropSpecial0Node);  // check results
  
  Image<int> calcBlc_78_ref(width, height, 1, 0);
  calcBlc_3(cropSpecial0Node_ref, calcBlc_78_ref
  	, tap_blc_offsetGr_0
  	, tap_blc_offsetR_0
  	, tap_blc_offsetB_0
  	, tap_blc_offsetGb_0
  	, tap_blc_gainGR_0
  	, tap_blc_gainR_0
  	, tap_blc_gainB_0
  	, tap_blc_gainGb_0
  	, tap_blc_shift_0
  	, tap_blc_limit_0
  );
  calcBlc_78_ref.equal(calcBlc_78);  // check results
  
  Image<int> dpc_103_ref(width, height, 1, 0);
  dpc_3(calcBlc_78_ref, dpc_103_ref
  	, tap_dpc_edgeThrLow_0
  	, tap_dpc_edgeThrHigh_0
  	, tap_dpc_decisionThr_0
  	, tap_dpc_maxDiffRes_0
  	, tap_dpc_coldPixThr_0
  	, tap_dpc_coldPixFctr_0
  	, tap_dpc_hotPixThr_0
  	, tap_dpc_hotPixFctr_0
  );
  dpc_103_ref.equal(dpc_103);  // check results
  
  Image<int> calcXtk_116_ref(width, height, 1, 0);
  calcXtk_3(dpc_103_ref, calcXtk_116_ref
  	, tap_xtk_lowThr_0
  	, tap_xtk_highThr_0
  );
  calcXtk_116_ref.equal(calcXtk_116);  // check results
  
  Image<int> calcWbg_46_ref(width, height, 1, 0);
  calcWbg_3(calcXtk_116_ref, calcWbg_46_ref
  	, tap_den_spatWgt_0
  	, tap_den_lowThr_0
  	, tap_den_highThr_0
  	, tap_den_offsetY_0
  	, tap_den_crdShift_0
  	, tap_den_offsetX_0
  	, tap_den_radFctr_0
  	, tap_den_radShift_0
  	, tap_den_radOffset_0
  	, tap_den_radMin_0
  	, tap_den_radMax_0
  	, tap_den_dirDen_0
  	, tap_den_dirMtrThr_0
  	, tap_den_dFLow_0
  	, tap_den_dFHigh_0
  	, tap_den_dirShift_0
  	, tap_wbg_grainG_0
  	, tap_wbg_grainR_0
  	, tap_wbg_grainB_0
  	, tap_wbg_grainAll_0
  );
  calcWbg_46_ref.equal(calcWbg_46);  // check results
  
  Image<int> calcDem_324_ref(width, height, 3, 0);
  calcDem_3(calcWbg_46_ref, calcDem_324_ref
  	, tap_dem_wg_0
  	, tap_dem_wc_0
  	, tap_dem_dirThr_0
  );
  calcDem_324_ref.equal(calcDem_324);  // check results
  
  Image<int> srp_385_ref(width, height, 3, 0);
  srp_3(calcDem_324_ref, srp_385_ref
  	, tap_srp_hfPwr_0
  	, tap_srp_minHfVal_0
  	, tap_srp_maxHfVal_0
  	, tap_srp_mfPwr_0
  	, tap_srp_minMfVal_0
  	, tap_srp_maxMfVal_0
  	, tap_srp_edgeThr_0
  	, tap_srp_edgeSlp_0
  	, tap_srp_edgeSft_0
  	, tap_srp_lslCntWgt_0
  	, tap_srp_hslCntWgt_0
  	, tap_srp_lshCntWgt_0
  	, tap_srp_hshCntWgt_0
  	, tap_srp_offsetY_0
  	, tap_srp_crdShift_0
  	, tap_srp_offsetX_0
  	, tap_srp_radFctr_0
  	, tap_srp_radShift_0
  	, tap_srp_radOffset_0
  	, tap_srp_radMin_0
  	, tap_srp_radMax_0
  );
  srp_385_ref.equal(srp_385);  // check results
  
  Image<int> ccf_57_ref(width, height, 3, 0);
  ccf_3(srp_385_ref, ccf_57_ref
  	, tap_ccm_avgCFlag_0
  	, tap_ccm_colorSatLow_0
  	, tap_ccm_colorSatHigh_0
  	, tap_ccm_mat0_0
  	, tap_ccm_mat3_0
  	, tap_ccm_mat6_0
  	, tap_ccm_mat1_0
  	, tap_ccm_mat4_0
  	, tap_ccm_mat7_0
  	, tap_ccm_mat2_0
  	, tap_ccm_mat5_0
  	, tap_ccm_mat8_0
  );
  ccf_57_ref.equal(ccf_57);  // check results
  
  Image<int> srp_427_ref(width, height, 3, 0);
  cnr_3(ccf_57_ref, srp_427_ref
  	, tap_cnr_denYChFlag_0
  	, tap_cnr_denYLowThr_0
  	, tap_cnr_denYHighThr_0
  	, tap_cnr_offsetY_0
  	, tap_cnr_crdShift_0
  	, tap_cnr_offsetX_0
  	, tap_cnr_radFctr_0
  	, tap_cnr_radShift_0
  	, tap_cnr_radOffset_0
  	, tap_cnr_radMin_0
  	, tap_cnr_radMax_0
  	, tap_cnr_useSigmaFilter0_0
  	, tap_cnr_denUVChsFlag_0
  	, tap_cnr_denUVLowThr_0
  	, tap_cnr_denUVHighThr_0
  	, tap_cnr_useSigmaFilter1_0
  	, tap_cnr_useSigmaFilter2_0
  );
  srp_427_ref.equal(srp_427);  // check results
  
  Image<int> ct8_243_ref(width, height, 3, 0);
  ct8_3(srp_427_ref, ct8_243_ref
  );
  ct8_243_ref.equal(ct8_243);  // check results
  
  return 0;
}
