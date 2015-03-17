#ifndef _PIPELINE_H_
#define _PIPELINE_H_

#include "image.h"
#include "arch.h"

void lambda_arris_v3lua_line43_10(const Image<vector32>& in, Image<vector32>& out
	, unsigned int tap_Green_to_Lum_0_s
	, unsigned int tap_Blue_to_Lum_0_s
	, unsigned int tap_Red_to_Lum_0_s
);

void Resp_5(const Image<vector32>& in, Image<vector32>& out
	, signed int tap_K_0_s
);

void scheduledIRNode_28(const Image<vector32>& in, Image<vector32>& out
);

void downCast_15(const Image<vector32>& in, Image<vector32>& out
	, unsigned int tap_G1_0_s
	, unsigned int tap_G0_0_s
	, unsigned int tap_G2_0_s
	, unsigned int tap_G4_0_s
	, unsigned int tap_G3_0_s
	, unsigned int tap_R_0_s
);

void NMS_10(const Image<vector32>& in, Image<vector32>& out
	, signed int tap_Peak_0_s
);

void downCast_13(const Image<vector32>& in, Image<vector32>& out
	, unsigned int tap_G1_0_s
	, unsigned int tap_G0_0_s
	, unsigned int tap_G2_0_s
	, unsigned int tap_G4_0_s
	, unsigned int tap_G3_0_s
	, unsigned int tap_R_0_s
);

#endif
