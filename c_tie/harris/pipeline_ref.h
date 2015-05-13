#ifndef _PIPELINE_REF_H_
#define _PIPELINE_REF_H_

#include <stdio.h>
#include <stdlib.h>
#include "image.h"

void downCast_13(const Image<int>& in, Image<int>& out
	, signed short tap_G1_0
	, signed short tap_G0_0
	, signed short tap_G2_0
	, signed short tap_G4_0
	, signed short tap_G3_0
	, unsigned short tap_R_0
		 );

void Resp_5(const Image<int>& in, Image<int>& out
	, signed short tap_K_0
	    );

void downCast_15(const Image<int>& in, Image<int>& out
	, signed short tap_G1_0
	, signed short tap_G0_0
	, signed short tap_G2_0
	, signed short tap_G4_0
	, signed short tap_G3_0
	, unsigned short tap_R_0
		 );

void NMS_10(const Image<int>& in, Image<int>& out
	, signed short tap_Peak_0
	    );


void convertToIllum_10(const Image<int>& in, Image<int>& out
	, unsigned short tap_Green_to_Lum_0
	, unsigned short tap_Blue_to_Lum_0
	, unsigned short tap_Red_to_Lum_0
	, unsigned short tap_R_0
		       );

void scheduledIRNode_19(const Image<int>& in, Image<int>& out
			);


#endif
