
-- cross-talk (green-imbalance) correction block

import "orion"

-- import definitions and global settings
terralib.require("defs")
terralib.require("settings")

-- add local block settings
settings.xtk 				= {}
settings.xtk.bypass 		= 0;
settings.xtk.inBitRes		= 10;
settings.xtk.procBitRes	= 10;
settings.xtk.outBitRes	= 10;
settings.xtk.lowThr    	= tap(oUint(settings.xtk.procBitRes),512,"xtk_lowThr"); -- procBitRes bits [0..(1 << procBitRes)-1]
settings.xtk.highThr  	= tap(oUint(settings.xtk.procBitRes),512,"xtk_highThr");	-- procBitRes bits [0..(1 << procBitRes)-1]

function xtk(inImg)
	return im calcXtk(x,y): cropSame , int16 
		let
			-- grgb is 1 if the middle pixel is green
			grgb = if defs.grPix(x,y) == 0 and defs.gbPix(x,y) == 0 
			then 
				0
			else
				let
					-- calculate average of g1
--					g1Avg = orion.int32(
--              (orion.float32(
--                inImg(x-2,y-2)+inImg(x,y-2)+
--                inImg(x+2,y-2)+inImg(x-2,y)+
--                inImg(x,y)+inImg(x+2,y)+
--                inImg(x-2,y+2)+inImg(x,y+2)+
--                inImg(x+2,y+2))+4.5)/9);

					g1Avg = orion.int32(
            (8*orion.sum(inImg(x-2,y-2),inImg(x,y-2),
                inImg(x+2,y-2),inImg(x-2,y),
                inImg(x,y),inImg(x+2,y),
                inImg(x-2,y+2),inImg(x,y+2),
                  inImg(x+2,y+2))+36)/72);
					-- calculate average of g2
					g2Avg = orion.sum(inImg(x-1,y-1),inImg(x+1,y-1),inImg(x-1,y+1),inImg(x+1,y+1),2)/4;
					-- calculate average of g1 and g2
					g1g2Avg = (g1Avg+g2Avg+1)/2;
					-- update threshold
					thr = settings.xtk.lowThr + ((settings.xtk.highThr-settings.xtk.lowThr)*g1g2Avg >> settings.xtk.procBitRes);
					-- calculate local difference between greens
					grgb1 = (g1Avg-g2Avg+1)/2;
					-- compare difference to threshold and choose output
					grgb2 = if (grgb1 > thr)
					then
						if (grgb1 > 2*thr) 
						then 
							0
						else 
							(2*thr-grgb1)
						end
					else 
						grgb1
					end
					in 
						if (grgb2 < -thr) 
						then 
							if (grgb2 < -2*thr) 
							then 
								0
							else 
								(-2*thr-grgb2)
							end
						else 
							grgb2
						end
			end
		in defs.clip(inImg(x,y) - grgb, 0, defs.maxPix)
	end
end