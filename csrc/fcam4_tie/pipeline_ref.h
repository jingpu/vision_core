#ifndef _PIPELINE_REF_H_
#define _PIPELINE_REF_H_

#include "image.h"

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
