#ifndef _PIPELINE_H_
#define _PIPELINE_H_

#include "image.h"
#include "arch.h"

// Set tap values
const unsigned int tap_Green_to_Lum_0 = 27;
const unsigned int tap_Blue_to_Lum_0 = 91;
const unsigned int tap_Red_to_Lum_0 = 9;
const unsigned int tap_G0_0 = 7;
const unsigned int tap_G1_0 = 31;
const unsigned int tap_G2_0 = 51;
const unsigned int tap_G3_0 = 31;
const unsigned int tap_G4_0 = 7;
const unsigned int tap_R_0 = 7;
const signed int tap_Peak_0 = 4;
const signed int tap_Hyst_0 = 1;
const unsigned int tap_SuppressLowPeak_0 = 1;

void downCast_29(const Image<V16S>& in, Image<V16S>& out
	, unsigned int tap_G1_0_s
	, unsigned int tap_G0_0_s
	, unsigned int tap_G2_0_s
	, unsigned int tap_G4_0_s
	, unsigned int tap_G3_0_s
	, unsigned int tap_R_0_s
);

void scheduledIRNode_20(const Image<V16S>& in, Image<V16S>& out
);

void in1_7(const Image<V16S>& in, Image<V16S>& out
);

void downCast_27(const Image<V16S>& in, Image<V16S>& out
	, unsigned int tap_G1_0_s
	, unsigned int tap_G0_0_s
	, unsigned int tap_G2_0_s
	, unsigned int tap_G4_0_s
	, unsigned int tap_G3_0_s
	, unsigned int tap_R_0_s
);

void lambda_canny_v3lua_line164_28(const Image<V16S>& in, Image<V16S>& out
	, unsigned int tap_SuppressLowPeak_0_s
);

void lambda_canny_v3lua_line65_27(const Image<V16S>& in, Image<V16S>& out
);

void lambda_canny_v3lua_line114_61(const Image<V16S>& in, Image<V16S>& out
	, signed int tap_Peak_0_s
	, signed int tap_Hyst_0_s
);

void lambda_canny_v3lua_line39_10(const Image<V16S>& in, Image<V16S>& out
	, unsigned int tap_Green_to_Lum_0_s
	, unsigned int tap_Blue_to_Lum_0_s
	, unsigned int tap_Red_to_Lum_0_s
	, unsigned int tap_R_0_s
);

#endif
