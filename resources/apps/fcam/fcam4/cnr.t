
-- cnr block

import "orion"

-- import definitions and global settings
terralib.require("defs")
terralib.require("settings")

-- add local block settings
settings.cnr 						= {}
settings.cnr.bypass 				= 0;
settings.cnr.inBitRes				= 10;
settings.cnr.procBitRes			= 10;
settings.cnr.outBitRes			= 10;
settings.cnr.denYChFlag			= tap(oUint(1),1,"cnr_denYChFlag"); 	-- 1 bit [0..1]
settings.cnr.denUVChsFlag			= tap(oUint(1),1,"cnr_denUVChsFlag");	-- 1 bit [0..1]
settings.cnr.useSigmaFilter		= {};
settings.cnr.useSigmaFilter[0]	= tap(oUint(1),0,"cnr_useSigmaFilter0");	-- 1 bit [0..1]
settings.cnr.useSigmaFilter[1]	= tap(oUint(1),1,"cnr_useSigmaFilter1");	-- 1 bit [0..1]
settings.cnr.useSigmaFilter[2]	= tap(oUint(1),1,"cnr_useSigmaFilter2");	-- 1 bit [0..1]
settings.cnr.denYLowThr			= tap(oUint(settings.cnr.procBitRes),0,"cnr_denYLowThr");	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.cnr.denYHighThr			= tap(oUint(settings.cnr.procBitRes),8,"cnr_denYHighThr")	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.cnr.denUVLowThr			= tap(oUint(settings.cnr.procBitRes),64,"cnr_denUVLowThr");	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.cnr.denUVHighThr			= tap(oUint(settings.cnr.procBitRes),32,"cnr_denUVHighThr");	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.cnr.radFctr				= tap(oInt(10),64,"cnr_radFctr");	-- 10 bits [-512..511]
settings.cnr.offsetX				= tap(oInt(13),0,"cnr_offsetX");	-- 13 bits [-4096..4095]
settings.cnr.offsetY				= tap(oInt(13),0,"cnr_offsetY");	-- 13 bits [-4096..4095]
settings.cnr.crdShift				= tap(oUint(4),3,"cnr_crdShift");	-- 4 bits  [0..15]
settings.cnr.radShift				= tap(oUint(4),11,"cnr_radShift");	-- 4 bits  [0..15]
settings.cnr.radOffset			= tap(oUint(3),7,"cnr_radOffset");	-- 3 bits [0..7]
settings.cnr.radMax				= tap(oUint(9),256,"cnr_radMax");	-- 9 bits [0..511]
settings.cnr.radMin				= tap(oUint(9),0,"cnr_radMin");	-- 9 bits [0..511]

function cnr(inImg, W, H)
  assert(orion.ast.isAST(inImg))
  assert(type(W)=="number")
  assert(type(H)=="number")

	-- calculate luminance values
	local function calcLum()
    local lumTab = {{1,4,6,4,1},{4,16,24,16,4},{6,24,36,24,6},{4,16,24,16,4},{1,4,6,4,1}}
    local partial = {}

    for j=-2,2 do -- y
      for i=-2,2 do -- x
        table.insert(partial, im(x,y) : cropNone [lumTab[j+3][i+3]]*inImg[0](x+i,y+j) end)
      end
    end

    return im(x,y) : cropNone ([orion.sum(partial[1], unpack(partial))]+128)>>8 end
	end	
	
	local lum = calcLum();	

  local im xCenter(x,y) : cropNone , int16 orion.abs(x+settings.cnr.offsetX-W/2) >> settings.cnr.crdShift end
  local im yCenter(x,y) : cropNone , int16 orion.abs(y+settings.cnr.offsetY-H/2) >> settings.cnr.crdShift end
  local im radPwr1(x,y) : cropNone , int16 ((yCenter*yCenter+xCenter*xCenter)*settings.cnr.radFctr >> settings.cnr.radShift) + (1 << settings.cnr.radOffset) end
  local im radPwr2(x,y) : cropNone , int16 defs.clip(radPwr1, settings.cnr.radMin, settings.cnr.radMax) end
  
  local denThr = {}
  denThr[0] = im(x,y) : cropNone , int16 settings.cnr.denYLowThr + (((settings.cnr.denYHighThr-settings.cnr.denYLowThr)*lum)>> settings.cnr.procBitRes) end
  denThr[0] = im(x,y) : cropNone , int16 ([denThr[0]]*radPwr2 + (1 << (settings.cnr.radOffset-1))) >> settings.cnr.radOffset end
  denThr[1] = im(x,y) : cropNone , int16 settings.cnr.denUVLowThr + (((orion.int32(settings.cnr.denUVHighThr)-orion.int32(settings.cnr.denUVLowThr))*lum)>> settings.cnr.procBitRes) end
  denThr[1] = im(x,y) : cropNone , int16 ([denThr[1]]*radPwr2 + (1 << (settings.cnr.radOffset-1))) >> settings.cnr.radOffset end
  denThr[2] = denThr[1]

  local rsTable = {{1,6,15,20,15,6,1},{6,36,90,120,90,36,6},{15,90,225,300,225,90,15},{20,120,300,400,300,120,20},{15,90,225,300,225,90,15},{6,36,90,120,90,36,6},{1,6,15,20,15,6,1}}

  local function thrX(thisast, diff, t)
    assert(orion.ast.isAST(thisast))
    assert(orion.ast.isAST(diff))
    assert(orion.ast.isAST(t))
  
    return im(x,y) : cropNone , int16 
      let
        t = orion.max(0, t);
      in
        if diff > -t and diff < t then  diff else 0 end
    end
  end

  local function thrXCnt(thisast, diff, t)
    assert(orion.ast.isAST(thisast))
    assert(orion.ast.isAST(diff))
    assert(orion.ast.isAST(t))
  
    return im(x,y) : cropNone , int16 
      let
        t = orion.max(0, t);
      in
        if diff > -t and diff < t then  1 else 0 end
    end
  end

  local rs = {}
  for k=0,2 do
    local partialSigma1 = {}
    local partialSigma1Cnt = {}
    local partialSigma0 = {}

    local denThrK = denThr[k]

    for j=-3,3 do -- y
      for i=-3,3 do -- x
        table.insert(partialSigma1, im(x,y) : cropNone , int16
      --               thrX(inImg[k](x+i,y+j)-inImg[k](x,y), [denThr[k]]) 
                     let
                     diff = inImg[k](x+i,y+j)-inImg[k](x,y)
                     t = orion.max(0,denThrK)
                     in
                       if diff > -t and diff < t then  diff else 0 end
      end)
        table.insert(partialSigma1Cnt, im(x,y) : cropNone , int16
                     --thrXCnt(inImg[k](x+i,y+j)-inImg[k](x,y), [denThr[k]]) 
                     let 
                     diff = inImg[k](x+i,y+j)-inImg[k](x,y)
                     t = orion.max(0,denThrK)
                     in
                       if diff > -t and diff < t then  1 else 0 end
                     end)
      table.insert(partialSigma0, im(x,y) : cropNone , int16  ( [rsTable[j+4][i+4]]*defs.thr(inImg[k](x+i,y+j)-inImg[k](x,y) , denThrK)) end)
      end
    end

    rs[k] = im(x,y) : cropNone , int16
      let
        numPix = [orion.sum(partialSigma1Cnt[1], unpack(partialSigma1Cnt))]
      in
      if [settings.cnr.useSigmaFilter[k]]==1 then
        if numPix ~=0 then
          ([orion.sum(partialSigma1[1], unpack(partialSigma1))]+(numPix >> 1))/(if numPix==0 then 1 else numPix end)
        else
          0
        end
      else
        ([orion.sum(partialSigma0[1], unpack(partialSigma0))]+2048)>>12
      end
    end
  end

  return im cnr(x,y): cropSame , int16[3]
  	let
      -- output
    b = if settings.cnr.denYChFlag==1 then defs.clip(inImg[0](x,y)+[rs[0]], 0, defs.maxPix) else defs.clip(inImg[0](x,y), 0, defs.maxPix) end
      g = if settings.cnr.denUVChsFlag==1 then defs.clip(inImg[1](x,y)+[rs[1]], -(1 << (defs.pixBitRes-1)), (1 << (defs.pixBitRes-1))-1) else
        defs.clip(inImg[1](x,y), -(1 << (defs.pixBitRes-1)), (1 << (defs.pixBitRes-1))-1) end
      r = if settings.cnr.denUVChsFlag==1 then defs.clip(inImg[2](x,y)+[rs[2]], -(1 << (defs.pixBitRes-1)), (1 << (defs.pixBitRes-1))-1) else
        defs.clip(inImg[2](x,y), -(1 << (defs.pixBitRes-1)), (1 << (defs.pixBitRes-1))-1) end
      in 
        {b,g,r}
  end	
		
end