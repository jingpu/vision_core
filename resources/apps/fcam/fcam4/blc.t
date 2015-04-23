
-- black level correction block

import "orion"

-- import definitions and global settings
terralib.require("defs")
terralib.require("settings")

-- add local block settings
settings.blc 				= {}
settings.blc.bypass 		= 0;
settings.blc.inBitRes		= 10;
settings.blc.procBitRes	= 10;
settings.blc.outBitRes	= 10;
settings.blc.gainGr    	= tap(oUint(settings.blc.procBitRes),560,"blc_gainGR");	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.blc.gainR   		= tap(oUint(settings.blc.procBitRes),560,"blc_gainR");	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.blc.gainB   		= tap(oUint(settings.blc.procBitRes),560,"blc_gainB");	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.blc.gainGb   	= tap(oUint(settings.blc.procBitRes),560,"blc_gainGb");	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.blc.offsetGr 	= tap(oInt(settings.blc.procBitRes+1),-8,"blc_offsetGr");	-- procBitRes+1 bits [-(1 << procBitRes)..(1 << procBitRes)-1]
settings.blc.offsetR  	= tap(oInt(settings.blc.procBitRes+1),-8,"blc_offsetR");	-- procBitRes+1 bits [-(1 << procBitRes)..(1 << procBitRes)-1]
settings.blc.offsetB  	= tap(oInt(settings.blc.procBitRes+1),-6,"blc_offsetB");	-- procBitRes+1 bits [-(1 << procBitRes)..(1 << procBitRes)-1]
settings.blc.offsetGb 	= tap(oInt(settings.blc.procBitRes+1),-8,"blc_offsetGb");	-- procBitRes+1 bits [-(1 << procBitRes)..(1 << procBitRes)-1]
settings.blc.shift   		= tap(oUint(5),0,"blc_shift");	-- 5 bits [0..31]
settings.blc.limit   		= tap(oUint(settings.blc.procBitRes),1023,"blc_limit");	-- procBitRes bits [0..(1 << procBitRes)-1]

function blc(inImg)
	return im calcBlc(x,y): cropSame , int16
		let
			-- find offset and gain according to the pixel's color
      offset = defs.grPix(x,y)*settings.blc.offsetGr+defs.rPix(x,y)*settings.blc.offsetR+defs.bPix(x,y)*settings.blc.offsetB+defs.gbPix(x,y)*settings.blc.offsetGb;
			gain 	= defs.grPix(x,y)*settings.blc.gainGr+defs.rPix(x,y)*settings.blc.gainR+defs.bPix(x,y)*settings.blc.gainB+defs.gbPix(x,y)*settings.blc.gainGb;
				  
			-- apply offset and gain
			pix 	= defs.clip(inImg(x,y)+offset, 0, defs.maxPix);
			pix2 	= (((pix*gain) << [settings.blc.shift]) + (1 << ([settings.blc.procBitRes]-2))/2) >> (settings.blc.procBitRes-1);
			pix3 	= orion.min(pix2, [settings.blc.limit]);
			in pix3
	end
end