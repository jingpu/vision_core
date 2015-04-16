#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "pipeline_ref.h"

int main(int argc, char* argv[])
{
  int width = 256;  // TODO change to match input image
  int height = 256;  // TODO change to match input image
  int channels = 1;  // TODO change to match input image
  Image<int> special0(width, height, channels, 0);
  special0.load(argv[1]);
  special0.save("input.bmp");
  
  // Construct the pipeline of kernels
  Image<int> cropSpecial0Node(width, height, 1, 0);
  scheduledIRNode(special0, cropSpecial0Node
  );
  
  Image<int> calcBlc_78(width, height, 1, 0);
  calcBlc_3(cropSpecial0Node, calcBlc_78
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
  
  Image<int> dpc_103(width, height, 1, 0);
  dpc_3(calcBlc_78, dpc_103
  	, tap_dpc_edgeThrLow_0
  	, tap_dpc_edgeThrHigh_0
  	, tap_dpc_decisionThr_0
  	, tap_dpc_maxDiffRes_0
  	, tap_dpc_coldPixThr_0
  	, tap_dpc_coldPixFctr_0
  	, tap_dpc_hotPixThr_0
  	, tap_dpc_hotPixFctr_0
  );
  
  Image<int> calcXtk_116(width, height, 1, 0);
  calcXtk_3(dpc_103, calcXtk_116
  	, tap_xtk_lowThr_0
  	, tap_xtk_highThr_0
  );
  
  Image<int> calcWbg_46(width, height, 1, 0);
  calcWbg_3(calcXtk_116, calcWbg_46
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
  
  Image<int> calcDem_324(width, height, 3, 0);
  calcDem_3(calcWbg_46, calcDem_324
  	, tap_dem_wg_0
  	, tap_dem_wc_0
  	, tap_dem_dirThr_0
  );
  
  Image<int> srp_385(width, height, 3, 0);
  srp_3(calcDem_324, srp_385
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
  
  Image<int> ccf_57(width, height, 3, 0);
  ccf_3(srp_385, ccf_57
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
  
  Image<int> srp_427(width, height, 3, 0);
  cnr_3(ccf_57, srp_427
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
  
  Image<int> ct8_243(width, height, 3, 0);
  ct8_3(srp_427, ct8_243
  );
  
  ct8_243.save("result.bmp");
  
  return(0);
}
