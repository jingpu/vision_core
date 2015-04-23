
-- ccm block

import "orion"

-- import definitions and global settings
terralib.require("defs")
terralib.require("settings")

-- add local block settings
settings.ccm 				= {}
settings.ccm.procBitRes	= 10;
settings.ccm.colorSatLow	= tap(oUint(10),256,"ccm_colorSatLow");	-- 10 bits [0..1023]
settings.ccm.colorSatHigh	= tap(oUint(10),256,"ccm_colorSatHigh");	-- 10 bits [0..1023]
settings.ccm.avgCFlag		= tap(oUint(1),1,"ccm_avgCFlag");	-- 1 bit [0..1]
settings.ccm.ccmMat 		= {}
settings.ccm.ccmMat[0]   	= tap(oInt(11),378,"ccm_mat0");	-- 11 bits [-1024..1023]
settings.ccm.ccmMat[1]   	= tap(oInt(11),-53,"ccm_mat1");	-- 11 bits [-1024..1023]
settings.ccm.ccmMat[2]   	= tap(oInt(11),-69,"ccm_mat2");	-- 11 bits [-1024..1023]
settings.ccm.ccmMat[3]   	= tap(oInt(11),-9,"ccm_mat3");	-- 11 bits [-1024..1023]
settings.ccm.ccmMat[4]   	= tap(oInt(11),350,"ccm_mat4");	-- 11 bits [-1024..1023]
settings.ccm.ccmMat[5]   	= tap(oInt(11),-85,"ccm_mat5");	-- 11 bits [-1024..1023]
settings.ccm.ccmMat[6]   	= tap(oInt(11),-19,"ccm_mat6");	-- 11 bits [-1024..1023]
settings.ccm.ccmMat[7]   	= tap(oInt(11),-182,"ccm_mat7");	-- 11 bits [-1024..1023]
settings.ccm.ccmMat[8]   	= tap(oInt(11),457,"ccm_mat8");	-- 11 bits [-1024..1023]

function ccm(inImg)
	local satLow 	= {}
	local satHigh 	= {}
	local ccmMat 	= {}
	
	-- generate saturation matrices
	for k=0,8 do
	   satLow[k] 	= im(x,y) : cropNone , int16 (256-settings.ccm.colorSatLow) / 256 end;
	  satHigh[k] 	= im(x,y) : cropNone , int16 (256-settings.ccm.colorSatHigh) / 256 end;
		if k%4 == 0 
		then
		   satLow[k] = im(x,y) : cropNone , int16 ([satLow[k]] + settings.ccm.colorSatLow ) end;
		   satHigh[k] = im(x,y) : cropNone , int16 ([satHigh[k]] + settings.ccm.colorSatHigh) end;
		end
	end
	
	-- weight matrices
	local w = {};
	local w0 = {};
	local w1 = {};

  w1[0] = 1; w1[1] = 2; w1[2] = 1;
  w1[3] = 2; w1[4] = 4; w1[5] = 2;
  w1[6] = 1; w1[7] = 2; w1[8] = 1;
  
  w0[0] = 0; w0[1]	= 0;  w0[2] = 0;
  w0[3] = 0; w0[4]	= 16; w0[5] = 0;
  w0[6] = 0; w0[7]	= 0;  w0[8] = 0;

  for i=0,8 do
    w[i] = im(x,y) : cropNone if settings.ccm.avgCFlag == 1 then [w1[i]] else [w0[i]] end end
  end

  -------------------------------------------

	-- calculate local luminance level
	local function calcAvgs()
		local avgs = {}
		for k = 0,2 do
			avgs[k] = im(x,y) : cropNone, int16
				orion.sum(inImg(x-1,y-1)[k],2*inImg(x,y-1)[k],inImg(x+1,y-1)[k],
				 2*inImg(x-1,y)[k],4*inImg(x,y)[k],2*inImg(x+1,y)[k],
				 inImg(x-1,y+1)[k],2*inImg(x,y+1)[k],inImg(x+1,y+1)[k],8)>>4 end
		
		end
		return avgs;
	end
	
	local avgs = calcAvgs();
	local lum = im(x,y) : cropNone , int16 ([avgs[0]]+2*[avgs[1]]+[avgs[2]]+2) / 4 end
	
	-- update the ccm according to the saturation matrices and local signal
	local function updateCCM()
		ccm = {}
		for i = 0,2 do
			for j = 0,2 do
				ccm[3*j+i] = im(x,y) : cropNone , int16
        (([satLow[3*j+0]] + ((([satHigh[3*j+0]]-[satLow[3*j+0]])*lum(x,y) + (1 << (settings.ccm.procBitRes-1))) >> settings.ccm.procBitRes))*[settings.ccm.ccmMat[3*0+i]] +
         ([satLow[3*j+1]] + ((([satHigh[3*j+1]]-[satLow[3*j+1]])*lum(x,y) + (1 << (settings.ccm.procBitRes-1))) >> settings.ccm.procBitRes))*[settings.ccm.ccmMat[3*1+i]] +
         ([satLow[3*j+2]] + ((([satHigh[3*j+2]]-[satLow[3*j+2]])*lum(x,y) + (1 << (settings.ccm.procBitRes-1))) >> settings.ccm.procBitRes))*[settings.ccm.ccmMat[3*2+i]] + 128)>>8 end
				end
		end
		return ccm;
	end
	
	local ccm = updateCCM();
	
	-- calculate local average
	local m = {};
	for k=0,2 do
		m[k] = im(x,y) : cropNone , int16
			orion.sum(inImg(x-1,y-1)[k]*orion.int32([w[0]]) , inImg(x,y-1)[k]*orion.int32([w[1]]) , inImg(x+1,y-1)[k]*orion.int32([w[2]]) ,
			 inImg(x-1,y)[k]*orion.int32([w[3]])  , inImg(x,y)[k]*orion.int32([w[4]]) , inImg(x+1,y)[k]*orion.int32([w[5]])  ,
			 inImg(x-1,y+1)[k]*orion.int32([w[6]]) , inImg(x,y+1)[k]*orion.int32([w[7]]) , inImg(x+1,y+1)[k]*orion.int32([w[8]]) , 8) >> 4
        end
	end
  	
  return im ccm(x,y): cropNone , int16[3] -- Hack to get individual kernel to build
  {defs.clip(([m[2]]*orion.int32([ccm[6]]) + [m[1]]*orion.int32([ccm[7]]) + inImg(x,y)[0]*orion.int32([ccm[8]]) + 128)>>8, 0, defs.maxPix),
   defs.clip(([m[2]]*orion.int32([ccm[3]]) + inImg(x,y)[1]*orion.int32([ccm[4]]) + [m[0]]*orion.int32([ccm[5]]) + 128)>>8, 0, defs.maxPix),
   defs.clip((inImg(x,y)[2]*orion.int32([ccm[0]]) + [m[1]]*orion.int32([ccm[1]]) + [m[0]]*orion.int32([ccm[2]]) + 128)>>8, 0, defs.maxPix)}
	end
end