#ifndef _PIPELINE_H_
#define _PIPELINE_H_

#include "image.h"
#include "arch.h"

// Set tap values
const unsigned short tap_Green_to_Lum_0 = 91;
const unsigned short tap_Blue_to_Lum_0 = 9;
const unsigned short tap_Red_to_Lum_0 = 27;
const signed short tap_DarkBlob_0 = 16;
const signed short tap_LightBlob_0 = -16;

void lambda_ast_9_v2lua_line101_10(const Image<V16S>& in, Image<V16S>& out
	, signed int tap_DarkBlob_0_s
	, signed int tap_LightBlob_0_s
);

void lambda_ast_9_v2lua_line35_10(const Image<V16S>& in, Image<V16S>& out
	, signed int tap_Green_to_Lum_0_s
	, signed int tap_Blue_to_Lum_0_s
	, signed int tap_Red_to_Lum_0_s
);

void scheduledIRNode_19(const Image<V16S>& in, Image<V16S>& out
);

#endif
