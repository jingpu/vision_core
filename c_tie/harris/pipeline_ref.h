#ifndef _PIPELINE_REF_H_
#define _PIPELINE_REF_H_

#include <stdio.h>
#include <stdlib.h>
#include "image.h"


void lambda_arris_v3lua_line43_10(const Image<short>& in, Image<short>& out
	, unsigned short tap_Green_to_Lum_0
	, unsigned short tap_Blue_to_Lum_0
	, unsigned short tap_Red_to_Lum_0
	, unsigned short tap_R_0
				  );

void Resp_5(const Image<short>& in, Image<short>& out
	, signed short tap_K_0
	    );

void scheduledIRNode_28(const Image<short>& in, Image<short>& out
			);

void downCast_15(const Image<short>& in, Image<short>& out
	, unsigned short tap_G1_0
	, unsigned short tap_G0_0
	, unsigned short tap_G2_0
	, unsigned short tap_G4_0
	, unsigned short tap_G3_0
	, unsigned short tap_R_0
		 );
void NMS_10(const Image<short>& in, Image<short>& out
	, signed short tap_Peak_0
	    );

void downCast_13(const Image<short>& in, Image<short>& out
	, unsigned short tap_G1_0
	, unsigned short tap_G0_0
	, unsigned short tap_G2_0
	, unsigned short tap_G4_0
	, unsigned short tap_G3_0
	, unsigned short tap_R_0
		 );
#endif
