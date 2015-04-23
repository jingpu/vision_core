
-- denoising block

import "orion"

-- import definitions and global settings
terralib.require("defs")
terralib.require("settings")

-- add local block settings
settings.den 				= {}
settings.den.bypass 		= 0;
settings.den.inBitRes		= 10;
settings.den.procBitRes	= 10;
settings.den.outBitRes	= 10;
settings.den.radShift    	= tap(oUint(4),11,"den_radShift");	-- 4 bits [0..15]
settings.den.radFctr  	= tap(oInt(10),8,"den_radFctr");	-- 10 bits [-512..511]
settings.den.crdShift  	= tap(oUint(4),3,"den_crdShift");	-- 4 bits [0..15]
settings.den.radOffset	= tap(oUint(3),7,"den_radOffset");	-- 3 bits [0..7]
settings.den.radMax		= tap(oUint(9),256,"den_radMax");	-- 9 bits [0..511]
settings.den.radMin		= tap(oUint(9),0,"den_radMin");	-- 9 bits [0..511]
settings.den.offsetX		= tap(oInt(13),0,"den_offsetX"); 	-- 13 bits [-4096..4095]
settings.den.offsetY		= tap(oInt(13),0,"den_offsetY"); 	-- 13 bits [-4096..4095]
settings.den.lowThr		= tap(oUint(settings.den.procBitRes),10,"den_lowThr");	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.den.highThr		= tap(oUint(settings.den.procBitRes),64,"den_highThr");	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.den.dirDen		= tap(oUint(1),1,"den_dirDen");	-- 1 bit [0..1]
settings.den.dFLow		= tap(oUint(settings.den.procBitRes),512,"den_dFLow");	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.den.dFHigh 		= tap(oUint(settings.den.procBitRes),512,"den_dFHigh");	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.den.dirShift		= tap(oUint(4),7,"den_dirShift");	-- 4 bits [0..15]
settings.den.spatWgt		= tap(oUint(1),1,"den_spatWgt");	-- 1 bits [0..3]
settings.den.dirMtrThr	= tap(oUint(settings.den.procBitRes),64,"den_dirMtrThr");	-- procBitRes bits [0..(1 << procBitRes)-1]

function den(inImg,W,H)
  assert(orion.ast.isAST(inImg))
  assert(type(W)=="number")
  assert(type(H)=="number")

  -- this is basically a combination of localWB and the stuff that comes after it
  -- b/c localWB modifies the ul, ulls etc
	local function localWBEtc(ast, denThr, dirFctr)
    assert(orion.ast.isAST(ast))
    assert(orion.ast.isAST(denThr))
    assert(orion.ast.isAST(dirFctr))

    -- calculate local averages in a window
    local function calcLocalAvgs()
      local uull = im(x,y) : cropNone, int16 inImg(x-2,y-2) end
      local uul = im(x,y) : cropNone, int16 inImg(x-1,y-2) end
      local uu = im(x,y) : cropNone, int16 inImg(x,y-2) end
      local uur = im(x,y) : cropNone, int16 inImg(x+1,y-2) end
      local uurr = im(x,y) : cropNone, int16 inImg(x+2,y-2) end

      local ull = im(x,y) : cropNone, int16 inImg(x-2,y-1) end
      local ul = im(x,y) : cropNone, int16 inImg(x-1,y-1) end
      local u = im(x,y) : cropNone, int16 inImg(x,y-1) end
      local ur = im(x,y) : cropNone, int16 inImg(x+1,y-1) end
      local urr = im(x,y) : cropNone, int16 inImg(x+2,y-1) end

      local ll = im(x,y) : cropNone, int16 inImg(x-2,y) end
      local l = im(x,y) : cropNone , int16 inImg(x-1,y) end
      local c = im(x,y) : cropNone, int16 inImg(x,y) end
      local r = im(x,y) : cropNone, int16 inImg(x+1,y) end
      local rr = im(x,y) : cropNone, int16 inImg(x+2,y) end

      local dll = im(x,y) : cropNone, int16 inImg(x-2,y+1) end
      local dl = im(x,y) : cropNone, int16 inImg(x-1,y+1) end
      local d = im(x,y) : cropNone, int16 inImg(x,y+1) end
      local dr = im(x,y) : cropNone, int16 inImg(x+1,y+1) end
      local drr = im(x,y) : cropNone, int16 inImg(x+2,y+1) end

      local ddll = im(x,y) : cropNone, int16 inImg(x-2,y+2) end
      local ddl = im(x,y) : cropNone, int16 inImg(x-1,y+2) end
      local dd = im(x,y) : cropNone, int16 inImg(x,y+2) end
      local ddr = im(x,y) : cropNone, int16 inImg(x+1,y+2) end
      local ddrr = im(x,y) : cropNone, int16 inImg(x+2,y+2) end

		  return
			im mG(x,y) : cropNone, int16
				switch pix(x,y)
          case GR -> orion.sum(uull,uu,uurr,ul,((ul+1)>>1),ur,((ur+1)>>1),ll,2*c,rr,dl,((dl+1)>>1),dr,((dr+1)>>1),ddll,dd,ddrr,8) >> 4
					case GB -> orion.sum(uull,uu,uurr,ul,((ul+1)>>1),ur,((ur+1)>>1),ll,2*c,rr,dl,((dl+1)>>1),dr,((dr+1)>>1),ddll,dd,ddrr,8) >> 4
					case B 	-> orion.sum(uul,uur,ull,2*u,urr,2*l,2*r,dll,2*d,drr,ddl,ddr,8) >> 4
					default	-> orion.sum(uul,uur,ull,2*u,urr,2*l,2*r,dll,2*d,drr,ddl,ddr,8) >> 4
				end
			end,
			im mR(x,y) : cropNone, int16
				switch pix(x,y)
          case GR -> orion.sum(uul,uur,2*l,2*r,ddl,ddr,4) >> 3
          case GB -> orion.sum(ull,2*u,urr,dll,2*d,drr,4) >> 3
          case B 	-> orion.sum(ul,ur,dl,dr,2) >> 2
          default	-> orion.sum(uull,uu,uurr,ll,c,rr,ddll,dd,ddrr,-((uull+uurr+ddll+ddrr+2) >> 2)) >> 3
				end
			end,
			im mB(x,y) : cropNone, int16
				switch pix(x,y)
        case GR -> orion.sum(ull,2*u,urr,dll,2*d,drr,4) >> 3
        case GB -> orion.sum(uul,uur,2*l,2*r,ddl,ddr,4) >> 3
        case B 	-> orion.sum(uull,uu,uurr,ll,c,rr,ddll,dd,ddrr-((uull+uurr+ddll+ddrr+2) >> 2)) >> 3
        default	-> orion.sum(ul,ur,dl,dr,2) >> 2
				end
			end
    end
	
    local mG, mR, mB = calcLocalAvgs();

    -- calculate offsets from averages
    local function getOffsets()
      local maxAvg = orion.max(mG, mR, mB);
      return 
        im offsetG(x,y) : cropNone, int16
          switch (maxAvg(x,y))
          case mG(x,y)-> 0;
          case mR(x,y)-> mR(x,y)-mG(x,y);
					default-> mB(x,y)-mG(x,y);
        end
			end,
			im offsetR(x,y) : cropNone, int16
				switch (maxAvg(x,y))
					case mG(x,y)-> mG(x,y)-mR(x,y);
					case mR(x,y)-> 0;
					default-> mB(x,y)-mR(x,y);
				end
			end,
			im offsetB(x,y) : cropNone, int16
				switch (maxAvg(x,y))
					case mG(x,y) -> mG(x,y)-mB(x,y);
					case mR(x,y) -> mR(x,y)-mB(x,y);
					default -> 0;
				end
			end
    end
	
	  local offsetG, offsetR, offsetB = getOffsets();

    local function calcCenterOffset()
		  return 
        im offsetC(x,y) : cropNone, int16
				switch (pix(x,y))
					case GR->offsetG(x,y);
					case GB->offsetG(x,y);
					case R->offsetR(x,y);
					default->offsetB(x,y);
      end
      end
    end
	
    local offsetC = calcCenterOffset();

    local weightsDenDiff0 = {{1,2,2,2,1},{2,4,4,4,2},{2,4,4,4,2},{2,4,4,4,2},{1,2,2,2,1}};
    local weightsDenDiff1 = {{1,4,6,4,1},{4,16,24,16,4},{6,24,36,24,6},{4,16,24,16,4},{1,4,6,4,1}};
    local weightsDirDenV = {1,2,2,2,1};
    local weightsDirDenH = {1,2,2,2,1};

		local offsetsGR_T = {{offsetG, offsetR, offsetG, offsetR, offsetG},
                         {offsetB, offsetG, offsetB, offsetG, offsetB},
                         {offsetG, offsetR, offsetG, offsetR, offsetG},
                         {offsetB, offsetG, offsetB, offsetG, offsetB},
                         {offsetG, offsetR, offsetG, offsetR, offsetG}};
    local offsetsGB_T = {{offsetG, offsetB, offsetG, offsetB, offsetG},
                         {offsetR, offsetG, offsetR, offsetG, offsetR},
                         {offsetG, offsetB, offsetG, offsetB, offsetG},
                         {offsetR, offsetG, offsetR, offsetG, offsetR},
                         {offsetG, offsetB, offsetG, offsetB, offsetG}};
    local offsetsR_T = {{offsetR, offsetG, offsetR, offsetG, offsetR},
                        {offsetG, offsetB, offsetG, offsetB, offsetG},
                        {offsetR, offsetG, offsetR, offsetG, offsetR},
                        {offsetG, offsetB, offsetG, offsetB, offsetG},
                        {offsetR, offsetG, offsetR, offsetG, offsetR}};
    local offsetsB_T = {{offsetB, offsetG, offsetB, offsetG, offsetB},
                        {offsetG, offsetR, offsetG, offsetR, offsetG},
                        {offsetB, offsetG, offsetB, offsetG, offsetB},
                        {offsetG, offsetR, offsetG, offsetR, offsetG},
                        {offsetB, offsetG, offsetB, offsetG, offsetB}};

		local partialDenDiff = {};
		local partialDirDenV = {};
		local partialDirDenH = {};

    local wbInImg = {}
		for i=-2,2 do -- x
			for j=-2,2 do -- y
        wbInImg[j] = wbInImg[j] or {}
        wbInImg[j][i] = im(x,y) : cropNone, int16
          switch pix(x,y)
            case GR -> inImg(x+i,y+j) + [offsetsGR_T[j+3][i+3]]
            case GB -> inImg(x+i,y+j) + [offsetsGB_T[j+3][i+3]]
            case B -> inImg(x+i,y+j) + [offsetsB_T[j+3][i+3]]
            default -> inImg(x+i,y+j) + [offsetsR_T[j+3][i+3]]
          end
        end
      end
    end

    -- calculate an estimator for the local direction
    local dirDen = settings.den.dirDen
    local im horz(x,y) : cropNone if dirDen==1 then orion.max(orion.abs([wbInImg[0][0]]-[wbInImg[1][0]]), orion.abs([wbInImg[0][0]]-[wbInImg[-1][0]])) else 0 end end
    local im vert(x,y) : cropNone if dirDen==1 then orion.max(orion.abs([wbInImg[0][0]]-[wbInImg[0][-1]]), orion.abs([wbInImg[0][0]]-[wbInImg[0][1]])) else 0 end end
    local im dirThr(x,y) : cropNone if dirDen==1 then ((vert-horz)*dirFctr >> settings.den.dirShift) else 0 end end

		for j=-2,2 do
			table.insert(partialDirDenV,
				im(x,y) : cropNone 
        [weightsDirDenV[j+3]]*defs.thr([wbInImg[j][0]]-[wbInImg[0][0]], denThr+dirThr)
				end);
    end 

    local im dirDenV(x,y) : cropNone , int16
      if dirDen==1 then ([orion.sum(partialDirDenV[1],unpack(partialDirDenV))]+2) >> 2 else 0 end
    end

		for i=-2,2 do
			table.insert(partialDirDenH,
				im(x,y) : cropNone 
        [weightsDirDenH[i+3]]*defs.thr([wbInImg[0][i]]-[wbInImg[0][0]], denThr-dirThr)
				end);
    end

    local im dirDenH(x,y) : cropNone , int16
      if dirDen==1 then ([orion.sum(partialDirDenH[1],unpack(partialDirDenH))]+2) >> 2 else 0 end
    end

    local spatWgt = settings.den.spatWgt

		for i=-2,2 do -- x
			for j=-2,2 do -- y
				table.insert(partialDenDiff, im(x,y) : cropNone 
                     (if spatWgt == 0 then [weightsDenDiff0[j+3][i+3]] else [weightsDenDiff1[j+3][i+3]] end)*
                       defs.thr([wbInImg[j][i]]-[wbInImg[0][0]], denThr)
        end)
			end
    end

    local im denDiff(x,y) : cropNone , int16
      let
        a = if spatWgt==0 then 32 else 128 end
        b = if spatWgt==0 then 6 else 8 end
          in ([orion.sum(partialDenDiff[1],unpack(partialDenDiff))]+a) >> b
    end

    local im denDiff(x,y) : cropNone , int16
      let
        dirDiffVal = vert-horz
      in
        if ((dirDen==1) and (dirDiffVal > settings.den.dirMtrThr)) then
          denDiff + dirDenV
        else if ((dirDen==1) and (dirDiffVal < -orion.int32(settings.den.dirMtrThr))) then
          denDiff + dirDenH
        else
          denDiff + denDiff
        end end
    end

    return im(x,y) : cropNone defs.clip([wbInImg[0][0]]-offsetC+denDiff/2, 0, defs.maxPix) end
  end

	return im den(x,y) : cropSame , int16 -- Hack to get individual kernel to build
	
		let
			-- calculate the radial dependency
			-- TODO: check if using x and y like this is valid
			xCenter = orion.abs(x+settings.den.offsetX-W/2) >> settings.den.crdShift;
			yCenter = orion.abs(y+settings.den.offsetY-H/2) >> settings.den.crdShift;
			radPwr1 = ((yCenter*yCenter+xCenter*xCenter)*settings.den.radFctr >> settings.den.radShift) + (1 << settings.den.radOffset);
			radPwr2 = defs.clip(radPwr1, settings.den.radMin, settings.den.radMax);
			
			-- estimate local signal level and update denoising thresholds
			lum	= (inImg(x-1,y-1)+inImg(x-1,y+1)+inImg(x+1,y-1)+inImg(x+1,y+1)+
				   2*(inImg(x-1,y)+inImg(x+1,y)+inImg(x,y-1)+inImg(x,y+1))+4*inImg(x,y)+8) >> 4;
			denThr1 = settings.den.lowThr + ((lum*(settings.den.highThr-settings.den.lowThr) + (1 << (settings.den.procBitRes-1))) >> settings.den.procBitRes);
			dirFctr = settings.den.dFLow + ((lum*(settings.den.dFHigh-settings.den.dFLow) + (1 << (settings.den.procBitRes-1))) >> settings.den.procBitRes);
			-- apply radial gain to threshold
			denThr2	= ((denThr1*radPwr2 + (1 << (settings.den.radOffset-1))) >> settings.den.radOffset);
  			-- calculate local white balance
		in
      localWBEtc(denThr2, dirFctr)
	end
end
