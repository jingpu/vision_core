import "orion"

-- import definitions and global settings
terralib.require("defs")
terralib.require("settings")

local SH_PWR_RES = 7
local GAIN_RES = 8
local COEFF_RES = 9
local GAIN_CONST_RES = 10
local NCTRL_POINTS_X = 7
local NCTRL_POINTS_Y = 7
local BLK_CNT_RES = 20

settings.lsc = {}
settings.lsc.gainR = tap(oUint(10),350,"lsc_gainR") -- 10 bits [0..1023]
settings.lsc.gainGr = tap(oUint(10),256,"lsc_gainGr") -- 10 bits [0..1023]
settings.lsc.gainGb = tap(oUint(10),256,"lsc_gainGb") -- 10 bits [0..1023]
settings.lsc.gainB = tap(oUint(10),232,"lsc_gainB") -- 10 bits [0..1023]
settings.lsc.shPwr = tap(oUint(9),32,"lsc_shPwr") -- 8 bits [0..255]
settings.lsc.blkStepX = tap(oUint(BLK_CNT_RES),2427,"lsc_blkStepX") -- BLK_CNT_RES bits [0..2^BLK_CNT_RES-1]
settings.lsc.blkStepY = tap(oUint(BLK_CNT_RES),3196,"lsc_blkStepY") -- BLK_CNT_RES bits [0..2^BLK_CNT_RES-1]
settings.lsc.maxGain = tap(oUint(12),4095,"lsc_maxGain") -- 12 bits [0..4095]
settings.lsc.ctrlPtsGr = orion.tapLUT(orion.type.uint(16),NCTRL_POINTS_X*NCTRL_POINTS_Y,"ctrlPtsGr")
settings.lsc.ctrlPtsGb = orion.tapLUT(orion.type.uint(16),NCTRL_POINTS_X*NCTRL_POINTS_Y,"ctrlPtsGb")
settings.lsc.ctrlPtsR = orion.tapLUT(orion.type.uint(16),NCTRL_POINTS_X*NCTRL_POINTS_Y,"ctrlPtsR")
settings.lsc.ctrlPtsB = orion.tapLUT(orion.type.uint(16),NCTRL_POINTS_X*NCTRL_POINTS_Y,"ctrlPtsB")

local ctrlPtsGr = {2304, 1664, 1280, 1152, 1280, 1664, 2304, 1664, 1024, 640, 512, 640, 1024, 1664, 1280, 640, 256, 128, 256, 640, 1280, 1152, 512, 128, 0, 128, 512, 1152, 1280, 640, 256, 128, 256, 640, 1280, 1664, 1024, 640, 512, 640, 1024, 1664, 2304, 1664, 1280, 1152, 1280, 1664, 2304}
local ctrlPtsGb = {2304, 1664, 1280, 1152, 1280, 1664, 2304, 1664, 1024, 640, 512, 640, 1024, 1664, 1280, 640, 256, 128, 256, 640, 1280, 1152, 512, 128, 0, 128, 512, 1152, 1280, 640, 256, 128, 256, 640, 1280, 1664, 1024, 640, 512, 640, 1024, 1664, 2304, 1664, 1280, 1152, 1280, 1664, 2304}
local ctrlPtsR = {2304, 1664, 1280, 1152, 1280, 1664, 2304, 1664, 1024, 640, 512, 640, 1024, 1664, 1280, 640, 256, 128, 256, 640, 1280, 1152, 512, 128, 0, 128, 512, 1152, 1280, 640, 256, 128, 256, 640, 1280, 1664, 1024, 640, 512, 640, 1024, 1664, 2304, 1664, 1280, 1152, 1280, 1664, 2304}
local ctrlPtsB = {2304, 1664, 1280, 1152, 1280, 1664, 2304, 1664, 1024, 640, 512, 640, 1024, 1664, 1280, 640, 256, 128, 256, 640, 1280, 1152, 512, 128, 0, 128, 512, 1152, 1280, 640, 256, 128, 256, 640, 1280, 1664, 1024, 640, 512, 640, 1024, 1664, 2304, 1664, 1280, 1152, 1280, 1664,2304}

orion.setTapLUT(settings.lsc.ctrlPtsGr,ctrlPtsGr)
orion.setTapLUT(settings.lsc.ctrlPtsGb,ctrlPtsGb)
orion.setTapLUT(settings.lsc.ctrlPtsR,ctrlPtsR)
orion.setTapLUT(settings.lsc.ctrlPtsB,ctrlPtsB)


--int calcLocalGain(const int *ctrlPt, int inBlkCntX, int inBlkCntY, 
--                    int blkSizeX, int blkSizeY, int idxStartX, 
--                    int idxEndX, int idxStartY, int idxEndY, int maxGain)
--{
function calcLocalGain(W,H)
  assert(type(W)=="number")
  assert(type(H)=="number")

  -- calculate blocks sizes
  local blkSizeX = W/(NCTRL_POINTS_X-1);
  local blkSizeY = H/(NCTRL_POINTS_Y-1);

  local im blkCntX(x,y) : cropNone (x)/(blkSizeX) end
  local im blkCntY(x,y) : cropNone (y)/(blkSizeY) end

  local im inBlkCntX(x,y) : cropNone ((x)%(blkSizeX))*orion.int32(settings.lsc.blkStepX) end
  local im inBlkCntY(x,y) : cropNone ((y)%(blkSizeY))*orion.int32(settings.lsc.blkStepY) end

  local idxStartX = blkCntX
  local idxStartY = blkCntY
  local idxEndX = im(x,y) : cropNone blkCntX+1 end
  local idxEndY = im(x,y) : cropNone blkCntY+1 end

  local function ctrlPt(thisast,idx)
    return im(x,y) : cropNone, int32
      switch pix(x,y)
        case GR -> settings.lsc.ctrlPtsGr[idx]
        case GB -> settings.lsc.ctrlPtsGb[idx]
        case R -> settings.lsc.ctrlPtsR[idx]
        default -> settings.lsc.ctrlPtsB[idx]
      end
    end
  end

  local maxGain = settings.lsc.maxGain

  -- read four points from table
  return im(x,y) : cropNone, int32
    let
      ul = ctrlPt(idxStartY*(NCTRL_POINTS_X)+idxStartX)
      ur = ctrlPt(idxStartY*(NCTRL_POINTS_X)+idxEndX)
      dl = ctrlPt(idxEndY*(NCTRL_POINTS_X)+idxStartX)
      dr = ctrlPt(idxEndY*(NCTRL_POINTS_X)+idxEndX)

      -- calculate differences in x direction and scale by the x position inside a block
      tmp1 : int64 = (orion.int64(ur-ul)*orion.int64(inBlkCntX)) >> orion.int64(BLK_CNT_RES+COEFF_RES-GAIN_CONST_RES)
      tmp2 : int64 = (orion.int64(dr-dl)*orion.int64(inBlkCntX)) >> (BLK_CNT_RES+COEFF_RES-GAIN_CONST_RES);
      -- calculate up and down values
      up : int32 = tmp1 + (ul << (GAIN_CONST_RES-COEFF_RES));
      down : int32 = tmp2 + (dl << (GAIN_CONST_RES-COEFF_RES));
      -- scale by the y position inside a block
      tmp3 : int64 = (orion.int64(down-up)*orion.int64(inBlkCntY)) >> (BLK_CNT_RES);
      gain = tmp3 + up;
    in
      if gain < 0 then 0 else (if gain > maxGain then maxGain else gain end) end
--      inBlkCntX/3000
  end
end


function lsc(inImg, W, H)
  assert(orion.ast.isAST(inImg))
  assert(type(W)=="number")
  assert(type(H)=="number")

  -- calculate gains
  local im grGainFctr(x,y) : cropNone (settings.lsc.gainGr*settings.lsc.shPwr) >> SH_PWR_RES end
  local im gbGainFctr(x,y) : cropNone (settings.lsc.gainGb*settings.lsc.shPwr) >> SH_PWR_RES end
  local im rGainFctr(x,y) : cropNone (settings.lsc.gainR*settings.lsc.shPwr) >> SH_PWR_RES end
  local im bGainFctr(x,y) : cropNone (settings.lsc.gainB*settings.lsc.shPwr) >> SH_PWR_RES end
  
  local gainSrfcFctr = calcLocalGain(W,H)
  
  return im lsc(x,y): cropSame , int32
    let
      gainFctr = switch pix(x,y) case GR -> grGainFctr case R -> rGainFctr case B -> bGainFctr default -> gbGainFctr end
      pixGain = (gainSrfcFctr*gainFctr >> GAIN_RES) + (1 << GAIN_CONST_RES);
      in 
        defs.clip(pixGain*inImg(x,y) >> GAIN_CONST_RES, 0, defs.maxPix)
--        gainSrfcFctr
  end
end