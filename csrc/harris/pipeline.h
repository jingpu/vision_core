#ifndef _PIPELINE_H_
#define _PIPELINE_H_

#include "image.h"
#include "arch.h"


// Set tap values
const unsigned int tap_Green_to_Lum_0 = 27;    // TODO change in value
const unsigned int tap_Blue_to_Lum_0 = 91;     // TODO change in value
const unsigned int tap_Red_to_Lum_0 = 9;      // TODO change in value
const unsigned int tap_G0_0 = 7;      // TODO change in value
const unsigned int tap_G1_0 = 31;      // TODO change in value
const unsigned int tap_G2_0 = 51;     // TODO change in value
const unsigned int tap_G3_0 = 31;      // TODO change in value
const unsigned int tap_G4_0 = 7;      // TODO change in value
const unsigned int tap_R_0 = 7;        // TODO change in value
const signed int tap_K_0 = 1;  // TODO change in value
const signed int tap_Peak_0 = 4;     // TODO change in value


void lambda_arris_v3lua_line43_10(const Image<vector32>& in, Image<vector32>& out
	, unsigned int tap_Green_to_Lum_0_s
	, unsigned int tap_Blue_to_Lum_0_s
	, unsigned int tap_Red_to_Lum_0_s
	, unsigned int tap_R_0_s
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
