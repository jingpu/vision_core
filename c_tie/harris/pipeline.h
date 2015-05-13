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
const signed int tap_K_0 = 1;
const signed int tap_Peak_0 = 4;

void downCast_13(const Image<V16S>& in, Image<V16S>& out
	, signed int tap_G1_0_s
	, signed int tap_G0_0_s
	, signed int tap_G2_0_s
	, signed int tap_G4_0_s
	, signed int tap_G3_0_s
	, unsigned int tap_R_0_s
);

void Resp_5(const Image<V16S>& in, Image<V16S>& out
	, signed int tap_K_0_s
);

void downCast_15(const Image<V16S>& in, Image<V16S>& out
	, signed int tap_G1_0_s
	, signed int tap_G0_0_s
	, signed int tap_G2_0_s
	, signed int tap_G4_0_s
	, signed int tap_G3_0_s
	, unsigned int tap_R_0_s
);

void NMS_10(const Image<V16S>& in, Image<V16S>& out
	, signed int tap_Peak_0_s
);

void convertToIllum_10(const Image<V16S>& in, Image<V16S>& out
	, unsigned int tap_Green_to_Lum_0_s
	, unsigned int tap_Blue_to_Lum_0_s
	, unsigned int tap_Red_to_Lum_0_s
	, unsigned int tap_R_0_s
);

void scheduledIRNode_19(const Image<V16S>& in, Image<V16S>& out
);

#endif
