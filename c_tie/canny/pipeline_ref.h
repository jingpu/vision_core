#ifndef _PIPELINE_REF_H_
#define _PIPELINE_REF_H_

#include <stdio.h>
#include <stdlib.h>
#include "image.h"
void downCast_29(const Image<short>& in, Image<short>& out
	, unsigned short tap_G1_0
	, unsigned short tap_G0_0
	, unsigned short tap_G2_0
	, unsigned short tap_G4_0
	, unsigned short tap_G3_0
	, unsigned short tap_R_0
		 );

void in1_7(const Image<short>& in, Image<short>& out
	   );

void downCast_27(const Image<short>& in, Image<short>& out
	, unsigned short tap_G1_0
	, unsigned short tap_G0_0
	, unsigned short tap_G2_0
	, unsigned short tap_G4_0
	, unsigned short tap_G3_0
	, unsigned short tap_R_0
		 );

void scheduledIRNode_20(const Image<short>& in, Image<short>& out);

void lambda_canny_v3lua_line164_28(const Image<short>& in, Image<short>& out
	, unsigned short tap_SuppressLowPeak_0
				   );

void lambda_canny_v3lua_line65_27(const Image<short>& in, Image<short>& out
				  );

void lambda_canny_v3lua_line114_61(const Image<short>& in, Image<short>& out
	, signed short tap_Peak_0
	, signed short tap_Hyst_0
				   );

void lambda_canny_v3lua_line39_10(const Image<short>& in, Image<short>& out
	, unsigned short tap_Green_to_Lum_0
	, unsigned short tap_Blue_to_Lum_0
	, unsigned short tap_Red_to_Lum_0
	, unsigned short tap_R_0
				  );
#endif
