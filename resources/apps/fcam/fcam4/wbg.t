
-- white-balance gains block

import "orion"

-- import definitions and global settings
terralib.require("defs")
terralib.require("settings")

-- add local block settings
settings.wbg 				= {}
settings.wbg.bypass 		= 0;
settings.wbg.inBitRes		= 10;
settings.wbg.procBitRes	= 10;
settings.wbg.outBitRes	= 10;
settings.wbg.gainR    	= tap(oUint(12),602,"wbg_grainR");	-- 12bit [0..4095]
settings.wbg.gainG  		= tap(oUint(12),512,"wbg_grainG");	-- 12bit [0..4095]
settings.wbg.gainB  		= tap(oUint(12),879,"wbg_grainB");	-- 12bit [0..4095]
settings.wbg.gainAll		= tap(oUint(12),512,"wbg_grainAll");	-- 12bit [0..4095]

function wbg(inImg, s)
	return im calcWbg(x,y) : cropSame , int16
		let
  			-- calculate the current pixel gain
			gain = ((defs.grPix(x,y)*settings.wbg.gainG + 
					 defs.rPix(x,y)*settings.wbg.gainR + 
					 defs.bPix(x,y)*settings.wbg.gainB + 
					 defs.gbPix(x,y)*settings.wbg.gainG)*settings.wbg.gainAll) >> 9;
			-- apply gain
			pix = (inImg(x,y)*gain >> 9);
		in defs.clip(pix, 0, defs.maxPix)
	end
end