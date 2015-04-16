#ifndef _PIPELINE_REF_H_
#define _PIPELINE_REF_H_

#include "image.h"

// Set tap values
const signed int tap_blc_offsetGr_0 = -8;
const signed int tap_blc_offsetR_0 = -8;
const signed int tap_blc_offsetB_0 = -6;
const signed int tap_blc_offsetGb_0 = -8;
const unsigned int tap_blc_gainGR_0 = 560;
const unsigned int tap_blc_gainR_0 = 560;
const unsigned int tap_blc_gainB_0 = 560;
const unsigned int tap_blc_gainGb_0 = 560;
const unsigned int tap_blc_shift_0 = 0;
const unsigned int tap_blc_limit_0 = 1023;
const unsigned int tap_dpc_edgeThrLow_0 = 36;
const unsigned int tap_dpc_edgeThrHigh_0 = 176;
const unsigned int tap_dpc_decisionThr_0 = 20;
const unsigned int tap_dpc_maxDiffRes_0 = 4;
const unsigned int tap_dpc_coldPixThr_0 = 8;
const unsigned int tap_dpc_coldPixFctr_0 = 8;
const unsigned int tap_dpc_hotPixThr_0 = 8;
const unsigned int tap_dpc_hotPixFctr_0 = 8;
const unsigned int tap_xtk_lowThr_0 = 512;
const unsigned int tap_xtk_highThr_0 = 512;
const unsigned int tap_den_spatWgt_0 = 1;
const unsigned int tap_den_lowThr_0 = 10;
const unsigned int tap_den_highThr_0 = 64;
const signed int tap_den_offsetY_0 = 0;
const unsigned int tap_den_crdShift_0 = 3;
const signed int tap_den_offsetX_0 = 0;
const signed int tap_den_radFctr_0 = 8;
const unsigned int tap_den_radShift_0 = 11;
const unsigned int tap_den_radOffset_0 = 7;
const unsigned int tap_den_radMin_0 = 0;
const unsigned int tap_den_radMax_0 = 256;
const unsigned int tap_den_dirDen_0 = 1;
const unsigned int tap_den_dirMtrThr_0 = 64;
const unsigned int tap_den_dFLow_0 = 512;
const unsigned int tap_den_dFHigh_0 = 512;
const unsigned int tap_den_dirShift_0 = 7;
const unsigned int tap_wbg_grainG_0 = 512;
const unsigned int tap_wbg_grainR_0 = 602;
const unsigned int tap_wbg_grainB_0 = 879;
const unsigned int tap_wbg_grainAll_0 = 512;
const unsigned int tap_dem_wg_0 = 32;
const unsigned int tap_dem_wc_0 = 128;
const unsigned int tap_dem_dirThr_0 = 32;
const unsigned int tap_srp_hfPwr_0 = 64;
const unsigned int tap_srp_minHfVal_0 = 48;
const unsigned int tap_srp_maxHfVal_0 = 48;
const unsigned int tap_srp_mfPwr_0 = 16;
const unsigned int tap_srp_minMfVal_0 = 48;
const unsigned int tap_srp_maxMfVal_0 = 48;
const unsigned int tap_srp_edgeThr_0 = 128;
const unsigned int tap_srp_edgeSlp_0 = 8;
const unsigned int tap_srp_edgeSft_0 = 4;
const unsigned int tap_srp_lslCntWgt_0 = 12;
const unsigned int tap_srp_hslCntWgt_0 = 12;
const unsigned int tap_srp_lshCntWgt_0 = 96;
const unsigned int tap_srp_hshCntWgt_0 = 96;
const signed int tap_srp_offsetY_0 = 0;
const unsigned int tap_srp_crdShift_0 = 3;
const signed int tap_srp_offsetX_0 = 0;
const signed int tap_srp_radFctr_0 = -8;
const unsigned int tap_srp_radShift_0 = 12;
const unsigned int tap_srp_radOffset_0 = 7;
const unsigned int tap_srp_radMin_0 = 0;
const unsigned int tap_srp_radMax_0 = 256;
const unsigned int tap_ccm_avgCFlag_0 = 1;
const unsigned int tap_ccm_colorSatLow_0 = 256;
const unsigned int tap_ccm_colorSatHigh_0 = 256;
const signed int tap_ccm_mat0_0 = 378;
const signed int tap_ccm_mat1_0 = -53;
const signed int tap_ccm_mat2_0 = -69;
const signed int tap_ccm_mat3_0 = -9;
const signed int tap_ccm_mat4_0 = 350;
const signed int tap_ccm_mat5_0 = -85;
const signed int tap_ccm_mat6_0 = -19;
const signed int tap_ccm_mat7_0 = -182;
const signed int tap_ccm_mat8_0 = 457;
const unsigned int tap_cnr_denYChFlag_0 = 1;
const unsigned int tap_cnr_denYLowThr_0 = 0;
const unsigned int tap_cnr_denYHighThr_0 = 8;
const signed int tap_cnr_offsetY_0 = 0;
const unsigned int tap_cnr_crdShift_0 = 3;
const signed int tap_cnr_offsetX_0 = 0;
const signed int tap_cnr_radFctr_0 = 64;
const unsigned int tap_cnr_radShift_0 = 11;
const unsigned int tap_cnr_radOffset_0 = 7;
const unsigned int tap_cnr_radMin_0 = 0;
const unsigned int tap_cnr_radMax_0 = 256;
const unsigned int tap_cnr_useSigmaFilter0_0 = 0;
const unsigned int tap_cnr_denUVChsFlag_0 = 1;
const unsigned int tap_cnr_denUVLowThr_0 = 64;
const unsigned int tap_cnr_denUVHighThr_0 = 32;
const unsigned int tap_cnr_useSigmaFilter1_0 = 1;
const unsigned int tap_cnr_useSigmaFilter2_0 = 1;

void ct8_3(const Image<int>& in, Image<int>& out
);

void calcDem_3(const Image<int>& in, Image<int>& out
	, unsigned int tap_dem_wg_0_s
	, unsigned int tap_dem_wc_0_s
	, unsigned int tap_dem_dirThr_0_s
);

void cnr_3(const Image<int>& in, Image<int>& out
	, unsigned int tap_cnr_denYChFlag_0_s
	, unsigned int tap_cnr_denYLowThr_0_s
	, unsigned int tap_cnr_denYHighThr_0_s
	, signed int tap_cnr_offsetY_0_s
	, unsigned int tap_cnr_crdShift_0_s
	, signed int tap_cnr_offsetX_0_s
	, signed int tap_cnr_radFctr_0_s
	, unsigned int tap_cnr_radShift_0_s
	, unsigned int tap_cnr_radOffset_0_s
	, unsigned int tap_cnr_radMin_0_s
	, unsigned int tap_cnr_radMax_0_s
	, unsigned int tap_cnr_useSigmaFilter0_0_s
	, unsigned int tap_cnr_denUVChsFlag_0_s
	, unsigned int tap_cnr_denUVLowThr_0_s
	, unsigned int tap_cnr_denUVHighThr_0_s
	, unsigned int tap_cnr_useSigmaFilter1_0_s
	, unsigned int tap_cnr_useSigmaFilter2_0_s
);

void calcXtk_3(const Image<int>& in, Image<int>& out
	, unsigned int tap_xtk_lowThr_0_s
	, unsigned int tap_xtk_highThr_0_s
);

void scheduledIRNode(const Image<int>& in, Image<int>& out
);

void calcWbg_3(const Image<int>& in, Image<int>& out
	, unsigned int tap_den_spatWgt_0_s
	, unsigned int tap_den_lowThr_0_s
	, unsigned int tap_den_highThr_0_s
	, signed int tap_den_offsetY_0_s
	, unsigned int tap_den_crdShift_0_s
	, signed int tap_den_offsetX_0_s
	, signed int tap_den_radFctr_0_s
	, unsigned int tap_den_radShift_0_s
	, unsigned int tap_den_radOffset_0_s
	, unsigned int tap_den_radMin_0_s
	, unsigned int tap_den_radMax_0_s
	, unsigned int tap_den_dirDen_0_s
	, unsigned int tap_den_dirMtrThr_0_s
	, unsigned int tap_den_dFLow_0_s
	, unsigned int tap_den_dFHigh_0_s
	, unsigned int tap_den_dirShift_0_s
	, unsigned int tap_wbg_grainG_0_s
	, unsigned int tap_wbg_grainR_0_s
	, unsigned int tap_wbg_grainB_0_s
	, unsigned int tap_wbg_grainAll_0_s
);

void srp_3(const Image<int>& in, Image<int>& out
	, unsigned int tap_srp_hfPwr_0_s
	, unsigned int tap_srp_minHfVal_0_s
	, unsigned int tap_srp_maxHfVal_0_s
	, unsigned int tap_srp_mfPwr_0_s
	, unsigned int tap_srp_minMfVal_0_s
	, unsigned int tap_srp_maxMfVal_0_s
	, unsigned int tap_srp_edgeThr_0_s
	, unsigned int tap_srp_edgeSlp_0_s
	, unsigned int tap_srp_edgeSft_0_s
	, unsigned int tap_srp_lslCntWgt_0_s
	, unsigned int tap_srp_hslCntWgt_0_s
	, unsigned int tap_srp_lshCntWgt_0_s
	, unsigned int tap_srp_hshCntWgt_0_s
	, signed int tap_srp_offsetY_0_s
	, unsigned int tap_srp_crdShift_0_s
	, signed int tap_srp_offsetX_0_s
	, signed int tap_srp_radFctr_0_s
	, unsigned int tap_srp_radShift_0_s
	, unsigned int tap_srp_radOffset_0_s
	, unsigned int tap_srp_radMin_0_s
	, unsigned int tap_srp_radMax_0_s
);

void ccf_3(const Image<int>& in, Image<int>& out
	, unsigned int tap_ccm_avgCFlag_0_s
	, unsigned int tap_ccm_colorSatLow_0_s
	, unsigned int tap_ccm_colorSatHigh_0_s
	, signed int tap_ccm_mat0_0_s
	, signed int tap_ccm_mat3_0_s
	, signed int tap_ccm_mat6_0_s
	, signed int tap_ccm_mat1_0_s
	, signed int tap_ccm_mat4_0_s
	, signed int tap_ccm_mat7_0_s
	, signed int tap_ccm_mat2_0_s
	, signed int tap_ccm_mat5_0_s
	, signed int tap_ccm_mat8_0_s
);

void calcBlc_3(const Image<int>& in, Image<int>& out
	, signed int tap_blc_offsetGr_0_s
	, signed int tap_blc_offsetR_0_s
	, signed int tap_blc_offsetB_0_s
	, signed int tap_blc_offsetGb_0_s
	, unsigned int tap_blc_gainGR_0_s
	, unsigned int tap_blc_gainR_0_s
	, unsigned int tap_blc_gainB_0_s
	, unsigned int tap_blc_gainGb_0_s
	, unsigned int tap_blc_shift_0_s
	, unsigned int tap_blc_limit_0_s
);

void dpc_3(const Image<int>& in, Image<int>& out
	, unsigned int tap_dpc_edgeThrLow_0_s
	, unsigned int tap_dpc_edgeThrHigh_0_s
	, unsigned int tap_dpc_decisionThr_0_s
	, unsigned int tap_dpc_maxDiffRes_0_s
	, unsigned int tap_dpc_coldPixThr_0_s
	, unsigned int tap_dpc_coldPixFctr_0_s
	, unsigned int tap_dpc_hotPixThr_0_s
	, unsigned int tap_dpc_hotPixFctr_0_s
);

#endif
