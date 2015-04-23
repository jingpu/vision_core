
-- sharpening block

import "orion"

-- import definitions and global settings
terralib.require("defs")
terralib.require("settings")

-- add local block settings
settings.srp 				= {}
settings.srp.bypass 		= 0;
settings.srp.inBitRes		= 10;
settings.srp.procBitRes	= 10;
settings.srp.outBitRes	= 10;
settings.srp.radShift		= tap(oUint(4),12,"srp_radShift");	-- 4 bits [0..15]
settings.srp.radFctr		= tap(oInt(10),-8,"srp_radFctr");	-- 10 bits [-512..511]
settings.srp.crdShift		= tap(oUint(4),3,"srp_crdShift");	-- 4 bits [0..15]
settings.srp.radOffset	= tap(oUint(3),7,"srp_radOffset");	-- 3 bits [0..7]
settings.srp.radMax   	= tap(oUint(9),256,"srp_radMax");	-- 9 bits [0..511]
settings.srp.radMin   	= tap(oUint(9),0,"srp_radMin");	-- 9 bits [0..511]
settings.srp.offsetX		= tap(oInt(13),0,"srp_offsetX"); 	-- 13 bits [-4096..4095]
settings.srp.offsetY		= tap(oInt(13),0,"srp_offsetY"); 	-- 13 bits [-4096..4095]
settings.srp.edgeThr		= tap(oUint(settings.srp.procBitRes),128,"srp_edgeThr");	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.srp.edgeSlp		= tap(oUint(16),8,"srp_edgeSlp");	-- 16 bits
settings.srp.edgeSft		= tap(oUint(4),4,"srp_edgeSft");	-- 4 bits [0..15]
settings.srp.hfPwr		= tap(oUint(8),64,"srp_hfPwr");	-- 8 bits [0..255]
settings.srp.mfPwr		= tap(oUint(8),16,"srp_mfPwr");	-- 8 bits [0..255]
settings.srp.minHfVal		= tap(oUint(settings.srp.procBitRes),48,"srp_minHfVal");	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.srp.minMfVal		= tap(oUint(settings.srp.procBitRes),48,"srp_minMfVal");	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.srp.maxHfVal		= tap(oUint(settings.srp.procBitRes),48,"srp_maxHfVal");	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.srp.maxMfVal		= tap(oUint(settings.srp.procBitRes),48,"srp_maxMfVal");	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.srp.lslCntWgt	= tap(oUint(8),12,"srp_lslCntWgt");	-- 8 bits [0..255]
settings.srp.hslCntWgt	= tap(oUint(8),12,"srp_hslCntWgt");	-- 8 bits [0..255]
settings.srp.lshCntWgt	= tap(oUint(8),96,"srp_lshCntWgt");	-- 8 bits [0..255]
settings.srp.hshCntWgt	= tap(oUint(8),96,"srp_hshCntWgt");	-- 8 bits [0..255]
--settings.srp.width 		= 3264;
--settings.srp.height 		= 2448;

function srp(inImg,W,H)
  assert(orion.ast.isAST(inImg))
  assert(type(W)=="number")
  assert(type(H)=="number")

	-- calculate luminance values
	local function calcLum()
		local lum = {}
    local lumT = {}

    for j=-2,2 do -- y
      lum[j] = {}
      for i=-2,2 do -- x
	 lum[j][i] = im(x,y) : cropNone , int16
          (inImg(x+i,y+j)[0]+2*inImg(x+i,y+j)[1]+inImg(x+i,y+j)[2]+2)>>2
        end
        table.insert(lumT,lum[j][i])
			end
		end
		return lum, lumT;
	end
	
	local lum, lumT = calcLum();
					
	local minLum, maxLum = orion.min(lumT[1], unpack(lumT)), orion.max(lumT[1], unpack(lumT))

	local function calcLocalLumAvg()
		return
		   im localLumAvg(x,y) : cropNone , int32 -- [JB] must be 32 bit 
    orion.sum([lum[-1][-1]](x,y),2*[lum[-1][0]](x,y),[lum[-1][1]](x,y),
     2*[lum[0][-1]](x,y), 4*[lum[0][0]](x,y), 2*[lum[0][1]](x,y),
     [lum[1][-1]](x,y), 2*[lum[1][0]](x,y), [lum[1][1]](x,y), 8)>>4
    end
	end
	
	local localLumAvg = calcLocalLumAvg();
	
	local function calcWeights()
		return
			im cntWeight(x,y) : cropNone , int16
        let
				ltmp = settings.srp.lslCntWgt + ((localLumAvg(x,y)*(settings.srp.hslCntWgt-settings.srp.lslCntWgt) + (1 << (settings.srp.procBitRes-1))) >> settings.srp.procBitRes);
				htmp = settings.srp.lshCntWgt + ((localLumAvg(x,y)*(settings.srp.hshCntWgt-settings.srp.lshCntWgt) + (1 << (settings.srp.procBitRes-1))) >> settings.srp.procBitRes);
				in 
					ltmp + (((maxLum(x,y)-minLum(x,y))*(htmp-ltmp) + (1 << (settings.srp.procBitRes-1))) >> settings.srp.procBitRes)
			end
	end
	
	local cntWeight = calcWeights();
	
	local function calcEdgeVal()
		return
			im edgeVal(x,y) : cropNone
        let
        horzEdge = orion.abs(1*[lum[-2][-2]]+2*[lum[-2][-1]]+2*[lum[-2][0]]+2*[lum[-2][1]]+1*[lum[-2][2]]-1*[lum[2][-2]]-2*[lum[2][-1]]-2*[lum[2][0]]-2*[lum[2][1]]-1*[lum[2][2]])
        vertEdge = orion.abs(1*[lum[-2][-2]]+2*[lum[-1][-2]]+2*[lum[0][-2]]+2*[lum[1][-2]]+1*[lum[2][-2]]-1*[lum[-2][2]]-2*[lum[-1][2]]-2*[lum[0][2]]-2*[lum[1][2]]-1*[lum[2][2]])
        in 
          (orion.max(horzEdge, vertEdge)+4)>>3
			end
	end
	
	local edgeVal = calcEdgeVal();

	return im srp(x,y): cropSame , int16[3]
    let 
	  edgeWeight =  if edgeVal <= settings.srp.edgeThr 
					   then
							256
					   else
							defs.clip(256-(((edgeVal-settings.srp.edgeThr)*settings.srp.edgeSlp + (1<<(settings.srp.edgeSft-1))) >> settings.srp.edgeSft), 0, 256)
					   end

		-- calculate the radial dependency
		xCenter = orion.abs(x+settings.srp.offsetX-W/2) >> settings.srp.crdShift;
		yCenter = orion.abs(y+settings.srp.offsetY-H/2) >> settings.srp.crdShift;
		radPwr1 = (((yCenter*yCenter+xCenter*xCenter)*settings.srp.radFctr) >> settings.srp.radShift) + (1 << settings.srp.radOffset);
		radPwr2 = defs.clip(radPwr1, settings.srp.radMin, settings.srp.radMax);
		
		highFreq = defs.clip([lum[0][0]]-localLumAvg, -orion.int16(settings.srp.minHfVal), settings.srp.maxHfVal);

		medFreq	 = defs.clip(orion.sum(-1*[lum[-2][-2]],-4*[lum[-2][-1]],-6*[lum[-2][0]],-4*[lum[-2][1]],-1*[lum[-2][2]],
                          -4*[lum[-1][-2]],0*[lum[-1][-1]],8*[lum[-1][0]],0*[lum[-1][1]],-4*[lum[-1][2]],
                          -6*[lum[0][-2]],8*[lum[0][-1]],28*[lum[0][0]],8*[lum[0][1]],-6*[lum[0][2]],
                          -4*[lum[1][-2]],0*[lum[1][-1]],8*[lum[1][0]],0*[lum[1][1]],-4*[lum[1][2]],
                          -1*[lum[2][-2]],-4*[lum[2][-1]],-6*[lum[2][0]],-4*[lum[2][1]],-1*[lum[2][2]], 128) >> 8, -orion.int16(settings.srp.minMfVal), settings.srp.maxMfVal);

		deltaSrp1 = (settings.srp.hfPwr*highFreq + settings.srp.mfPwr*medFreq) >> 6;
		deltaSrp2 = (deltaSrp1*edgeWeight+128) >> 8;
		deltaSrp3 = (deltaSrp2*cntWeight+16) >> 5;
		deltaSrp4 = (deltaSrp3*radPwr2 + (1 << (settings.srp.radOffset-1))) >> settings.srp.radOffset;
		
		finalLum = [lum[0][0]]+deltaSrp4;
		cb = inImg(x,y)[1]-inImg(x,y)[2];
		cr = inImg(x,y)[1]-inImg(x,y)[0];
		b = defs.clip((4*finalLum-3*cr+cb + 2) >> 2, 0, defs.maxPix);
		g = defs.clip((4*finalLum+cr+cb + 2) >> 2, 0, defs.maxPix);
		r = defs.clip((4*finalLum-3*cb+cr + 2) >> 2, 0, defs.maxPix);
	  in
      {b,g,r}
--      {highFreq, medFreq,finalLum}
--      {
    -- in finalLum, but not edgeWeight,cntWeight,radPwr2}

  end
end