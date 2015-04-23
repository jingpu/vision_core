
-- demosaicing block

import "orion"

-- import definitions and global settings
terralib.require("defs")
terralib.require("settings")

-- add local block settings
settings.dem 				= {}
settings.dem.bypass 		= 0;
settings.dem.inBitRes		= 10;
settings.dem.procBitRes	= 10;
settings.dem.outBitRes	= 10;
settings.dem.dirThr 		= tap(oUint(settings.dem.procBitRes),32,"dem_dirThr");	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.dem.wg 			= tap(oUint(8),32,"dem_wg"); 	-- 8 bits [0..255]
settings.dem.wc 			= tap(oUint(8),128,"dem_wc");	-- 8 bits [0..255]

function dem(inImg, s)
		
	-- calculate local horizontal and vertical interpolations
	local function demInterp(drv)
		return
			im Gh(x,y) : cropNone ,int32
				defs.clip(switch pix(x,y)
						case GR -> inImg(x,y);
						case GB -> inImg(x,y);
						default -> (inImg(x-1,y)+inImg(x+1,y)+1)/2 + (if drv then (2*inImg(x,y)-inImg(x+2,y)-inImg(x-2,y)+2)/4 else 0 end);
					 end, 
				0, defs.maxPix)
			end,
			im Gv(x,y) : cropNone ,int32
				defs.clip(switch pix(x,y)
						case GR -> inImg(x,y)
						case GB -> inImg(x,y)
						default -> (inImg(x,y-1)+inImg(x,y+1)+1)/2 + (if drv then (2*inImg(x,y)-inImg(x,y-2)-inImg(x,y+2)+2)/4 else 0 end)
					 end,
				0, defs.maxPix)
			end,
			im Bh(x,y) : cropNone ,int32
				defs.clip(switch pix(x,y)
						case GR -> (inImg(x,y-1)+inImg(x,y+1)+1)/2 + (4*inImg(x,y)-inImg(x-1,y-1)-inImg(x+1,y-1)-inImg(x-1,y+1)-inImg(x+1,y+1)+2)/4;
						case GB -> (inImg(x-1,y)+inImg(x+1,y)+1)/2 + (if drv then (2*inImg(x,y)-inImg(x+2,y)-inImg(x-2,y)+2)/4 else 0 end);
						case B -> inImg(x,y)
						default -> (inImg(x-1,y-1)+inImg(x+1,y-1)+inImg(x-1,y+1)+inImg(x+1,y+1)+2)/4 + 
								   (inImg(x-1,y)+inImg(x+1,y)-inImg(x,y-1)-inImg(x,y+1)+2)/2 + 
								   (if drv then (2*inImg(x,y)-inImg(x+2,y)-inImg(x-2,y)+2)/4 else 0 end)
						end,
				0, defs.maxPix)
			end,
			im Bv(x,y) : cropNone ,int32
				defs.clip(switch pix(x,y)
						case GR -> (inImg(x,y-1)+inImg(x,y+1)+1)/2 + (if drv then (2*inImg(x,y)-inImg(x,y-2)-inImg(x,y+2)+2)/4 else 0 end);							
						case GB -> (inImg(x-1,y)+inImg(x+1,y)+1)/2 + (4*inImg(x,y)-inImg(x-1,y-1)-inImg(x+1,y-1)-inImg(x-1,y+1)-inImg(x+1,y+1)+2)/4;
						case B -> inImg(x,y)
						case R -> (inImg(x-1,y-1)+inImg(x+1,y-1)+inImg(x-1,y+1)+inImg(x+1,y+1)+2)/4 + 
								  (inImg(x,y-1)+inImg(x,y+1)-inImg(x-1,y)-inImg(x+1,y)+2)/2 + 
								  (if drv then (2*inImg(x,y)-inImg(x,y-2)-inImg(x,y+2)+2)/4 else 0 end);
						default -> 0
						end,
				0, defs.maxPix)
			end,
			im Rh(x,y) : cropNone ,int32
				defs.clip(switch pix(x,y)
						case GR -> (inImg(x-1,y)+inImg(x+1,y)+1)/2 + (if drv then (2*inImg(x,y)-inImg(x+2,y)-inImg(x-2,y)+2)/4 else 0 end);
						case GB -> (inImg(x,y-1)+inImg(x,y+1)+1)/2 + 
								   (4*inImg(x,y)-inImg(x-1,y-1)-inImg(x+1,y-1)-inImg(x-1,y+1)-inImg(x+1,y+1)+2)/4;
						case B -> (inImg(x-1,y-1)+inImg(x+1,y-1)+inImg(x-1,y+1)+inImg(x+1,y+1)+2)/4 + 
								  (inImg(x-1,y)+inImg(x+1,y)-inImg(x,y-1)-inImg(x,y+1)+2)/2 + 
								  (if drv then (2*inImg(x,y)-inImg(x+2,y)-inImg(x-2,y)+2)/4 else 0 end);
						default -> inImg(x,y);
						end,
				0, defs.maxPix)
			end,
			im Rv(x,y) : cropNone ,int32
				defs.clip(switch pix(x,y)
						case GR -> (inImg(x-1,y)+inImg(x+1,y)+1)/2 + 
								   (4*inImg(x,y)-inImg(x-1,y-1)-inImg(x+1,y-1)-inImg(x-1,y+1)-inImg(x+1,y+1)+2)/4;
						case GB -> (inImg(x,y-1)+inImg(x,y+1)+1)/2 + 
								   (if drv then (2*inImg(x,y)-inImg(x,y-2)-inImg(x,y+2)+2)/4 else 0 end);
						case B -> (inImg(x-1,y-1)+inImg(x+1,y-1)+inImg(x-1,y+1)+inImg(x+1,y+1)+2)/4 + 
								  (inImg(x,y-1)+inImg(x,y+1)-inImg(x-1,y)-inImg(x+1,y)+2)/2 + 
								  (if drv then (2*inImg(x,y)-inImg(x,y-2)-inImg(x,y+2)+2)/4 else 0 end);
						default -> inImg(x,y)
					end,
				0, defs.maxPix)
      end
	end
	
	local Gh, Gv, Bh, Bv, Rh, Rv = demInterp(false);
	local GhDrv, GvDrv, BhDrv, BvDrv, RhDrv, RvDrv = demInterp(true);
	
	return im calcDem(x,y) : cropSame , int32[3]
		let
			hGrad = orion.max(orion.max(orion.abs(Gh(x,y)-Gh(x-1,y)), orion.abs(Bh(x,y)-Bh(x-1,y)), orion.abs(Rh(x,y)-Rh(x-1,y))),
							  orion.max(orion.abs(Gh(x,y)-Gh(x+1,y)), orion.abs(Bh(x,y)-Bh(x+1,y)), orion.abs(Rh(x,y)-Rh(x+1,y))));
			vGrad = orion.max(orion.max(orion.abs(Gv(x,y)-Gv(x,y-1)), orion.abs(Bv(x,y)-Bv(x,y-1)), orion.abs(Rv(x,y)-Rv(x,y-1))),
							  orion.max(orion.abs(Gv(x,y)-Gv(x,y+1)), orion.abs(Bv(x,y)-Bv(x,y+1)), orion.abs(Rv(x,y)-Rv(x,y+1))));
							  
			hColorGrade = orion.max(orion.abs(Rh(x,y)-Bh(x,y)), orion.abs(Rh(x-1,y)-Bh(x-1,y)), orion.abs(Rh(x+1,y)-Bh(x+1,y)));
			vColorGrade = orion.max(orion.abs(Rv(x,y)-Bv(x,y)), orion.abs(Rv(x,y-1)-Bv(x,y-1)), orion.abs(Rv(x,y+1)-Bv(x,y+1)));
			
			horz = (settings.dem.wg*hGrad >> 5) + (settings.dem.wc*hColorGrade >> 8);
			vert = (settings.dem.wg*vGrad >> 5) + (settings.dem.wc*vColorGrade >> 8);
			
			-- combine directions
			Bc = if (horz > vert + settings.dem.dirThr) 
				 then 
					BvDrv(x,y)
				 else 
					if (vert > horz + settings.dem.dirThr) 
					then 
						BhDrv(x,y)
					else 
						(BhDrv(x,y)+BvDrv(x,y)+1)/2
					end 
				 end

			Gc = if (horz > vert + settings.dem.dirThr) 
				 then 
					GvDrv(x,y)
				 else 
					if (vert > horz + settings.dem.dirThr) 
					then 
						GhDrv(x,y)
					else 
						(GhDrv(x,y)+GvDrv(x,y)+1)/2
					end
				 end

			Rc = if (horz > vert + settings.dem.dirThr)
				 then 
					RvDrv(x,y)
				 else 
					if (vert > horz + settings.dem.dirThr) 
					then 
						RhDrv(x,y)
					else 
						(RhDrv(x,y)+RvDrv(x,y)+1)/2
					end
				 end

    in {defs.clip(Bc, 0, defs.maxPix), defs.clip(Gc, 0, defs.maxPix), defs.clip(Rc, 0, defs.maxPix)} 
			
	end
end