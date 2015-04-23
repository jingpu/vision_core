
import "orion"
require "os"

local _CONVGEN = os.getenv("CONVGEN")
if not _CONVGEN then
   _CONVGEN = "/horowitz/users/jbrunhav/ConvEngine/Conv-Gen8/Stanford-SEEC-Convolution-Engine/HW"
end

local argSet = {}

-- Add run wrapper to path 
terralib.require "buildRun"
terralib.require "getOpt" 


-- Load the input arguments into dictionary
opts = getopt( arg , "i" )
local InpImg
--InpImg = _CONVGEN .. "/imgs/ramp_bayer.ppm"
--InpImg = "/nobackup/jbrunhav/images/pExamples/bonsai_1280x720_raw.ppm"
InpImg = "../../images/bonsai_1280x720_raw.bmp"
if not opts["i"] then
   opts["i"] = InpImg
end
InpImg = opts["i"]

local c3to1
c3to1 = true 


-- Local Variables for input images
local InpImg3Ch
local InpImg1Ch
local ChOut
local ChIn
local c3to1 
local ChRead 
local Raw

Raw = false

RGB = 0
GRBG = 1
GBRG = 2
RGGB = 3
BGGR = 4
GR = 50
GB = 60
B = 70
R = 80

settings={}
settings.format    = GBRG ;
settings.blc = {}
settings.blc.bypass = 0;
settings.blc.gainGr    = 512;
settings.blc.gainR   = 512;
settings.blc.gainB   = 512;
settings.blc.gainGb    = 512;
settings.blc.offsetGr  = -64;
settings.blc.offsetR   = -64;
settings.blc.offsetB   = -64;
settings.blc.offsetGb  = -64;
settings.blc.shift   = 0;
settings.blc.limit   = 1023;
settings.blc.procBitRes   = 10;
settings.dem = {}
settings.dem.dirThr = 0;
settings.dem.wg = 128;
settings.dem.wc = 16;
settings.ct8 = {}
settings.ct8.inBitRes = 10
settings.ct8.outBitRes = 8
settings.ccm = {}
settings.ccm.colorSat    = 256;
settings.ccm.avgColorsFlag = true;
settings.ccm.ccmMat = {}
settings.ccm.ccmMat[0]   = 378;
settings.ccm.ccmMat[1]   = -53;
settings.ccm.ccmMat[2]   = -69;
settings.ccm.ccmMat[3]   = -9;
settings.ccm.ccmMat[4]   = 350;
settings.ccm.ccmMat[5]   = -85;
settings.ccm.ccmMat[6]   = -19;
settings.ccm.ccmMat[7]   = -182;
settings.ccm.ccmMat[8]   = 457;
settings.xtk = {}
settings.xtk.format    = GRBG;
settings.xtk.lowThr    = 64;
settings.xtk.highThr   = 64;
settings.xtk.procBitRes   = 10;
settings.wbg = {}
settings.wbg.format= GRBG;
settings.wbg.gainR= 512;
settings.wbg.gainG= 512;
settings.wbg.gainB= 512;
settings.wbg.gainAll= 512;
settings.dpc = {}
settings.dpc.format= GRBG;
settings.dpc.edgeThrHigh = 176;
settings.dpc.edgeThrLow= 36;
settings.dpc.decisionThr= 20;
settings.dpc.maxDiffRes= 4;
settings.dpc.hotPixThr= 40;
settings.dpc.coldPixThr= 40;
settings.dpc.hotPixFctr= 8;
settings.dpc.coldPixFctr= 8;

maxPix = math.pow(2,10)-1

im offX(x,y) : cropNone
  let
  offXT : int32 = switch settings.format case GRBG -> 0 case GBRG -> 1 case RGGB -> 1 case BGGR -> 0 default -> 2 end
  in orion.assert(offXT,34,offXT~=2)
end

im offY(x,y) : cropNone
  let
  offYT : int32 = switch settings.format case GRBG -> 0 case GBRG -> 1 case RGGB -> 0 case BGGR -> 1 default -> 2 end
  in orion.assert(offYT,344,offYT~=2)
end

im grPix(x,y) : cropNone
  --      grPix = !((y+offY)&1) & !((x+offX)&1);
  let
  grPixT = not (((y+offY(x,y))&1)~=0) and  not( ((x+offX(x,y))&1) ~= 0);
  in if grPixT then 1 else 0 end
end

im bPix(x,y) : cropNone
  --      bPix  =  ((y+offY)&1) & !((x+offX)&1);
  let
  bPixT  =  (((y+offY(x,y))&1) ~= 0) and not ( ((x+offX(x,y))&1) ~=0);
  in if bPixT then 1 else 0 end
end

im rPix(x,y) : cropNone
    --      rPix  = !((y+offY)&1) &  ((x+offX)&1);
  let
  rPixT  = not (((y+offY(x,y))&1)~=0) and  (((x+offX(x,y))&1)~=0);
  in if rPixT then 1 else 0 end
end

im gbPix(x,y) : cropNone
    --      gbPix =  ((y+offY)&1) &  ((x+offX)&1);
  let
  gbPixT =  (((y+offY(x,y))&1)~=0) and  (((x+offX(x,y))&1)~=0);
  in if gbPixT then 1 else 0 end
end

im pix(x,y) : cropNone
  if grPix(x,y)==1 then GR
  else if gbPix(x,y)==1 then GB
  else if rPix(x,y)==1 then R
  else B end end end
end

function max3(thisast,a,b,c)
  assert(orion.ast.isAST(a))
  assert(orion.ast.isAST(b))
  assert(orion.ast.isAST(c))
  local tmp = orion.max(thisast,a,b)
  return orion.max(thisast,tmp,c)
end

function max4(thisast,a,b,c,d)
  assert(orion.ast.isAST(a))
  assert(orion.ast.isAST(b))
  assert(orion.ast.isAST(c))
  assert(orion.ast.isAST(d))
  local tmp = orion.max(thisast,a,b)
  local tmp2 = orion.max(thisast,tmp,c)
  return orion.max(thisast,tmp2,d)
end

function min4(thisast,a,b,c,d)
  assert(orion.ast.isAST(a))
  assert(orion.ast.isAST(b))
  assert(orion.ast.isAST(c))
  assert(orion.ast.isAST(d))
  local tmp = orion.min(thisast,a,b)
  local tmp2 = orion.min(thisast,tmp,c)
  return orion.min(thisast,tmp2,d)
end

function min3(thisast,a,b,c)
  assert(orion.ast.isAST(a))
  assert(orion.ast.isAST(b))
  assert(orion.ast.isAST(c))
  local tmp = orion.min(thisast,a,b)
  return orion.min(thisast,tmp,c)
end

-- #define clip(x, a, b)   (min2(max2((x), (a)), (b)))
function clip(thisast,inp,minV,maxV)
  assert(orion.ast.isAST(inp))
  assert(orion.ast.isAST(minV))
  assert(orion.ast.isAST(maxV))
  return orion.min(thisast,orion.max(thisast,inp,minV),maxV)
end

--#define sign(x)(((x) < 0) ? (-1) : (1))
function sign(thisast, xinp)
  assert(orion.ast.isAST(xinp))

--[[
  local m1 = orion.ast.new({kind="value",value=-1}):copyMetadataFrom(thisast)  
  local p1 = orion.ast.new({kind="value",value=1}):copyMetadataFrom(thisast)  
  local z = orion.ast.new({kind="value",value=0}):copyMetadataFrom(thisast)  

  local cond = orion.ast.new({kind="binop",op="<",lhs=x,rhs=z}):copyMetadataFrom(thisast)  

  return orion.ast.new({kind="select",cond=cond,a=m1,b=p1}):copyMetadataFrom(thisast)  
  ]]

  return im(x,y) : cropNone if xinp(x,y)<0 then -1 else 1 end end
end


function localWB(inImg, maxVal)
--int localWB(int &uull, int &uul, int &uu, int &uur, int &uurr,
--            int &ull,  int &ul,  int &u,  int &ur,  int &urr,
--            int &ll,   int &l,   int &c,  int &r,   int &rr, 
--            int &dll,  int &dl,  int &d,  int &dr,  int &drr,
--            int &ddll, int &ddl, int &dd, int &ddr, int &ddrr, int maxVal)
--{

--  int mean1 = maxVal - (uull+uu+uurr+ll+rr+ddll+dd+ddrr+4)/8;
   local im mean1(x,y) : cropNone maxVal - (orion.sum(inImg(x-2,y-2),inImg(x,y-2),inImg(x+2,y-2),inImg(x-2,y),inImg(x+2,y),inImg(x-2,y+2),inImg(x,y+2),inImg(x+2,y+2),4)>>3) end
--  int mean2 = maxVal - (uul+uur+l+r+ddl+ddr-max(max3(uul, uur, l), max3(r, ddl, ddr))-min(min3(uul, uur, l), min3(r, ddl, ddr))+2)/4;
   local im mean2(x,y) : cropNone maxVal - (orion.sum(inImg(x-1,y-2),inImg(x+1,y-2),inImg(x-1,y),inImg(x+1,y),inImg(x-1,y+2),inImg(x+1,y+2),-orion.max(max3(inImg(x-1,y-2), inImg(x+1,y-2), inImg(x-1,y)), max3(inImg(x+1,y), inImg(x-1,y+2), inImg(x+1,y+2))),-orion.min(min3(inImg(x-1,y-2), inImg(x+1,y-2), inImg(x-1,y)), min3(inImg(x+1,y), inImg(x-1,y+2), inImg(x+1,y+2))),2)>>2) end
--  int mean3 = maxVal - (ull+u+urr+dll+d+drr-max(max3(ull, u, urr), max3(dll, d, drr))-min(min3(ull, u, urr), min3(dll, d, drr))+2)/4;
   local im mean3(x,y) : cropNone maxVal - (orion.sum(inImg(x-2,y-1),inImg(x,y-1),inImg(x+2,y-1),inImg(x-2,y+1),inImg(x,y+1),inImg(x+2,y+1),-orion.max(max3(inImg(x-2,y-1), inImg(x,y-1), inImg(x+2,y-1)), max3(inImg(x-2,y+1), inImg(x,y+1), inImg(x+2,y+1))),-orion.min(min3(inImg(x-2,y-1), inImg(x,y-1), inImg(x+2,y-1)), min3(inImg(x-2,y+1), inImg(x,y+1), inImg(x+2,y+1))),2)>>2) end
--  int mean4 = maxVal - (ul+ur+dl+dr)/4;
   local im mean4(x,y) : cropNone maxVal - (orion.sum(inImg(x-1,y-1),inImg(x+1,y-1),inImg(x-1,y+1),inImg(x+1,y+1))>>2) end
--  // correct only required pixels


--  uu += mean1;
return im(x,y) : cropNone inImg(x,y-2) + mean1(x,y) end,
--  ll += mean1;
im(x,y) : cropNone inImg(x-2,y) + mean1(x,y) end,
--  dd += mean1;
im(x,y) : cropNone inImg(x,y+2) + mean1(x,y) end,
--  rr += mean1;
im(x,y) : cropNone inImg(x+2,y) + mean1(x,y) end,
--  c  += mean1;
im(x,y) : cropNone inImg(x,y) + mean1(x,y) end,
--  l  += mean2;
im(x,y) : cropNone inImg(x-1,y) + mean2(x,y) end,
--  r  += mean2;
im(x,y) : cropNone inImg(x+1,y) + mean2(x,y) end,
--  u  += mean3;
im(x,y) : cropNone inImg(x,y-1) + mean3(x,y) end,
--  d  += mean3;
im(x,y) : cropNone inImg(x,y+1) + mean3(x,y) end,
--  ul += mean4;
im(x,y) : cropNone inImg(x-1,y-1) + mean4(x,y) end,
--  ur += mean4;
im(x,y) : cropNone inImg(x+1,y-1) + mean4(x,y) end,
--  dl += mean4;
im(x,y) : cropNone inImg(x-1,y+1) + mean4(x,y) end,
--  dr += mean4;
im(x,y) : cropNone inImg(x+1,y+1) + mean4(x,y) end,
--  return mean1;
  mean1

end


function calcDiffFromGrad(inImg, edgeThrHigh, edgeThrLow, decisionThr, maxDiffRes)
  assert(orion.ast.isAST(inImg))
  assert(type(edgeThrHigh)=="number")
  assert(type(edgeThrLow)=="number")
  assert(type(decisionThr)=="number")
  assert(type(maxDiffRes)=="number")

--int calcDiffFromGrad(int uul, int uu, int uur,
--                      int ull, int ul, int u,  int ur, int urr,
--                       int ll,  int l,  int c,  int r,  int rr,
--                        int dll, int dl, int d,  int dr, int drr,
--                         int ddl, int dd, int ddr, int edgeThrHigh, 
--                         int edgeThrLow, int decisionThr, int maxDiffRes)
--{
  local im uul(x,y) : cropNone inImg(x-1,y-2) end
local im uu(x,y) : cropNone inImg(x,y-2) end
local im uur(x,y) : cropNone inImg(x+1,y-1) end

local im ull(x,y) : cropNone inImg(x-2,y-1) end
local im ul(x,y) : cropNone inImg(x-1,y-1) end
local im u(x,y) : cropNone inImg(x,y-1) end
local im ur(x,y) : cropNone inImg(x+1,y-1) end
local im urr(x,y) : cropNone inImg(x+2,y-1) end

local im ll(x,y) : cropNone inImg(x-2,y) end
local im l(x,y) : cropNone inImg(x-1,y) end
local im c(x,y) : cropNone inImg(x,y) end
local im r(x,y) : cropNone inImg(x+1,y) end
local im rr(x,y) : cropNone inImg(x+2,y) end

local im dll(x,y) : cropNone inImg(x-2,y+1) end
local im dl(x,y) : cropNone inImg(x-1,y+1) end
local im d(x,y) : cropNone inImg(x,y+1) end
local im dr(x,y) : cropNone inImg(x+1,y+1) end
local im drr(x,y) : cropNone inImg(x+2,y+1) end

local im ddl(x,y) : cropNone inImg(x-1,y+2) end
local im dd(x,y) : cropNone inImg(x,y+2) end
local im ddr(x,y) : cropNone inImg(x+1,y+2) end

local abs = orion.abs

  return im(x,y) : cropNone
--  int diffVal, minGradDiff;
--  int meanVal, maxVal;
    let 
--  int vGrad = abs(uul-l)+abs(ul-dl)+abs(l-ddl)+
    vGrad = orion.sum( abs(uul(x,y)-l(x,y)),abs(ul(x,y)-dl(x,y)),abs(l(x,y)-ddl(x,y)),
--    abs(uu-c)+abs(u-d)+abs(c-dd)+
      abs(uu(x,y)-c(x,y)),abs(u(x,y)-d(x,y)),abs(c(x,y)-dd(x,y)),
--    abs(uur-r)+abs(ur-dr)+abs(r-ddr);
      abs(uur(x,y)-r(x,y)),abs(ur(x,y)-dr(x,y)),abs(r(x,y)-ddr(x,y)));
--  int hGrad = abs(ull-u)+abs(ul-ur)+abs(u-urr)+
hGrad =  orion.sum( abs(ull(x,y)-u(x,y)),abs(ul(x,y)-ur(x,y))+abs(u(x,y)-urr(x,y)),
--    abs(ll-c)+abs(l-r)+abs(c-rr)+
abs(ll(x,y)-c(x,y)),abs(l(x,y)-r(x,y)),abs(c(x,y)-rr(x,y)),
--    abs(dll-d)+abs(dl-dr)+abs(d-drr);
abs(dll(x,y)-d(x,y)),abs(dl(x,y)-dr(x,y)),abs(d(x,y)-drr(x,y)))
  
--  if (vGrad < edgeThrLow && hGrad > edgeThrHigh)
--  {
--    // local horizontal edge
--    meanVal = (uu+dd+1)/2;
--    maxVal= max2(uu, dd);
--    minGradDiff = min3(hGrad-edgeThrHigh, edgeThrLow-vGrad, 1 << maxDiffRes);
--  } 
--  else if (hGrad < edgeThrLow && vGrad > edgeThrHigh)
--    {
--      // local vertical edge
--      meanVal = (ll+rr+1)/2;
--      maxVal= max2(ll, rr);
--      minGradDiff = min3(vGrad-edgeThrHigh, edgeThrLow-hGrad, 1 << maxDiffRes);
--      
meanVal = if (vGrad < edgeThrLow and hGrad > edgeThrHigh) then (orion.sum(uu(x,y)+dd(x,y)+1)>>1)
else
 if (hGrad < edgeThrLow and vGrad > edgeThrHigh)
 then (orion.sum(ll(x,y)+rr(x,y)+1)>>1) else -100000 end end

maxVal = if (vGrad < edgeThrLow and hGrad > edgeThrHigh) then orion.max(uu(x,y), dd(x,y))
else
 if (hGrad < edgeThrLow and vGrad > edgeThrHigh)
 then orion.max(ll(x,y), rr(x,y)) else -100000 end end

minGradDiff = if (vGrad < edgeThrLow and hGrad > edgeThrHigh) then
min3(hGrad-edgeThrHigh, edgeThrLow-vGrad, 1 << maxDiffRes)
else
 if (hGrad < edgeThrLow and vGrad > edgeThrHigh)
 then
min3(vGrad-edgeThrHigh, edgeThrLow-hGrad, 1 << maxDiffRes)
else -100000 end end


--    }
--    else
--      {
--        diffVal = 0;
--        return diffVal;
earlyOut = if (vGrad < edgeThrLow and hGrad > edgeThrHigh) or (hGrad < edgeThrLow and vGrad > edgeThrHigh) then 0 else 1 end
--      }


--      if (c > maxVal+decisionThr)
--      {
 diffVal = if (c(x,y) > maxVal+decisionThr) then orion.max( meanVal, orion.sum( (maxVal<<1),decisionThr,-c(x,y)) ) else c(x,y) end

--        diffVal = max2(meanVal, 2*maxVal+decisionThr-c);
--      }
--      else
--        {
--          diffVal  = c;
--        }

--        diffVal = ((diffVal*minGradDiff + ((1 << maxDiffRes)-minGradDiff)*c) >> maxDiffRes) - c;
   diffVal2 = ((diffVal*minGradDiff + ((1 << maxDiffRes)-minGradDiff)*c(x,y)) >> maxDiffRes) - c(x,y);
        in (if earlyOut==1 then 0 else diffVal2 end)
  end
--        return diffVal;
--        }
end

function dpc(inImg, settings)

  local uu,ll,dd,rr,c,l,r,u,d,ul,ur,dl,dr, meanVal = localWB( inImg, maxPix )

  return im(x,y): cropNone , int32
--      // calculate local gradients
--      int diff = calcDiffFromGrad(uul, uu, uur,
--                                  ull, ul, u,  ur, urr,
--                                  ll,  l,  c,  r,  rr, 
--                                  dll, dl, d,  dr, drr,
--                                  ddl, dd, ddr, 
--                                  params->edgeThrHigh, params->edgeThrLow, 
--                                  params->decisionThr, params->maxDiffRes);
  let
  diff = [calcDiffFromGrad(inImg,settings.edgeThrHigh, settings.edgeThrLow, settings.decisionThr, settings.maxDiffRes)]

--      // local white-balance
--      int meanVal = localWB(uull, uul, uu, uur, uurr,
--                              ull,  ul,  u,  ur,  urr,
--                                ll,   l,   c,  r,   rr, 
--                                  dll,  dl,  d,  dr,  drr,
--                                  ddll, ddl, dd, ddr, ddrr, maxPix);

--      // find local maximum/minimum (center is not used)
--      int localMax = max3(max4(uu, ul, ll, dl), max4(dd, dr, rr, ur), max4(u, l, d, r));
  localMax = max3(max4(uu(x,y), ul(x,y), ll(x,y), dl(x,y)), max4(dd(x,y), dr(x,y), rr(x,y), ur(x,y)), max4(u(x,y), l(x,y), d(x,y), r(x,y)));
--      int localMin = min3(min4(uu, ul, ll, dl), min4(dd, dr, rr, ur), min4(u, l, d, r));
  localMin = min3(min4(uu(x,y), ul(x,y), ll(x,y), dl(x,y)), min4(dd(x,y), dr(x,y), rr(x,y), ur(x,y)), min4(u(x,y), l(x,y), d(x,y), r(x,y)));

--      int thrCold = params->coldPixThr + (params->coldPixFctr*(localMax-localMin) >> 4);
  thrCold = settings.coldPixThr + (settings.coldPixFctr*(localMax-localMin) >> 4);
--      int thrHot= params->hotPixThr + (params->hotPixFctr*(localMax-localMin) >> 4);
  thrHot= settings.hotPixThr + (settings.hotPixFctr*(localMax-localMin) >> 4);
--      int corrVal = c;
  corrVal = if (c(x,y) > (localMax+thrHot)) then
--      if (corrVal > (localMax+thrHot))
--      {
--        corrVal = max2(2*(localMax+thrHot)-corrVal, localMax);
     orion.max(((localMax+thrHot)<<1)-c(x,y), localMax)
  else if (c(x,y) < localMin-thrCold) then
--      }
--      else if (corrVal < localMin-thrCold) 
--        {
--          corrVal = min2(2*(localMin-thrCold)-corrVal, localMin);
	orion.min(((localMin-thrCold)<<1)-c(x,y), localMin)
       else c(x,y) end end
--        }
        
--        int diff2 = corrVal-c;
  diff2 = corrVal-c(x,y);
--        int finalDiff;
  finalDiff = if (sign(diff)*sign(diff2) ~= 1) then
    diff + diff2
  else
    if (sign(diff) == 1) then (orion.max(diff, diff2)) else (orion.min(diff, diff2)) end
  end
--        if (sign(diff)*sign(diff2) != 1)
--        {
--          finalDiff = diff + diff2;
--        }
--        else
--          {
--            finalDiff = (sign(diff) == 1) ? (max2(diff, diff2)) : (min2(diff, diff2));
--          }
          
--          // output
--          outImg[y*width+x] = clip(c-meanVal+finalDiff, 0, maxPix);
    in clip(c(x,y) - meanVal(x,y)+finalDiff, 0, maxPix)
--  in finalDiff
  end
end

function wbg(inImg, settings)
--  register int y, x;
--  intpix;
--  boolgrPix, rPix, bPix, gbPix;
--  intgain;
--  // no line buffers are required - per-pixel processing 
--  for (y = 0; y < height; y++)
--  {
--    for (x = 0; x < width; x++)
--    {
  return im(x,y): cropNone , int32
--      // calculate pixel color
--      grPix = !((y+offY)&1) & !((x+offX)&1);
--      bPix  =  ((y+offY)&1) & !((x+offX)&1);
--      rPix  = !((y+offY)&1) &  ((x+offX)&1);
--      gbPix =  ((y+offY)&1) &  ((x+offX)&1);
--
--      // find gain according to color
  let
  gain = ((grPix(x,y)*settings.gainG + rPix(x,y)*settings.gainR + bPix(x,y)*settings.gainB + gbPix(x,y)*settings.gainG)*settings.gainAll) >> 9;
--      gain= ((grPix*params->gainG+rPix*params->gainR+bPix*params->gainB+gbPix*params->gainG)*params->gainAll) >> 9;

--      // apply gain
--      pix = inImg[y*width+x];
--      pix = (pix*gain >> 9);
    pix = (inImg(x,y)*gain >> 9)
    in clip(pix, 0, maxPix)
--      // output
--      outImg[y*width+x] = clip(pix, 0, maxPix);
--    }
--  }
  end
end

function xtk(inImg, settings)

  --register int y, x;
  --// loop over image lines
  --for (y = 0; y < height; y++)
  --{
  --  // define 5 line buffers
  --  int* uuLB;
  --  int* uLB;
  --  int* cLB;
  --  int* dLB;
  --  int* ddLB;

  --  // mechanism to replicate borders (rows) - using mirror replication
  --  if (y < XTK_PAD_SIZE)
  --  {
  --    uuLB= inImg+(XTK_PAD_SIZE-y)*width;
  --    uLB= inImg+(XTK_PAD_SIZE-y-1)*width;
  --    cLB= inImg+y*width;
  --    dLB= inImg+(y+1)*width;
  --    ddLB= inImg+(y+2)*width;
  --  }
  --  else if (y > height-1-XTK_PAD_SIZE)
  --    {
  --      uuLB= inImg+(y-2)*width;
  --      uLB= inImg+(y-1)*width;
  --      cLB= inImg+y*width;
  --      dLB= inImg+(2*(height-1)-(y+XTK_PAD_SIZE-1))*width;
  --      ddLB= inImg+(2*(height-1)-(y+XTK_PAD_SIZE))*width;
  --    }
  --    else
  --      {
  --        uuLB= inImg+(y-2)*width;
  --        uLB= inImg+(y-1)*width;
  --        cLB= inImg+(y+0)*width;
  --        dLB= inImg+(y+1)*width;
  --        ddLB= inImg+(y+2)*width;
  --      }

  --      // loop over pixels in line
  --      for (x = 0; x < width; x++)
  --      {
  --        // pixel local environment
  --        int uull,uul,uu,uur,uurr;
  --        int ull,ul,u,ur,urr;
  --        int ll,l,c,r,rr;
  --        int dll,dl,d,dr,drr;
  --        int ddll,ddl,dd,ddr,ddrr;
  --        // mechanism to replicate borders (columns) - using mirror replication
  --        if (x < XTK_PAD_SIZE)
  --        {
  --          uull = *(uuLB+XTK_PAD_SIZE-x);uul = *(uuLB+XTK_PAD_SIZE-x-1); uu = *(uuLB+x); uur = *(uuLB+x+1); uurr = *(uuLB+x+2);
  --          ull = *(uLB+XTK_PAD_SIZE-x);ul= *(uLB+XTK_PAD_SIZE-x-1);u  = *(uLB+x);  ur  = *(uLB+x+1);  urr  = *(uLB+x+2);
  --          ll = *(cLB+XTK_PAD_SIZE-x);l= *(cLB+XTK_PAD_SIZE-x-1);c  = *(cLB+x);  r= *(cLB+x+1);  rr   = *(cLB+x+2);
  --          dll = *(dLB+XTK_PAD_SIZE-x);dl= *(dLB+XTK_PAD_SIZE-x-1);d  = *(dLB+x);  dr  = *(dLB+x+1);  drr  = *(dLB+x+2);
  --          ddll = *(ddLB+XTK_PAD_SIZE-x);ddl = *(ddLB+XTK_PAD_SIZE-x-1); dd = *(ddLB+x); ddr = *(ddLB+x+1); ddrr = *(ddLB+x+2);
  --        }
  --        else if (x > width-1-XTK_PAD_SIZE)
  --          {
  --            uull = *(uuLB+x-2);uul = *(uuLB+x-1); uu = *(uuLB+x); uur = *(uuLB+(2*(width-1)-(x+XTK_PAD_SIZE-1))); uurr = *(uuLB+(2*(width-1)-(x+XTK_PAD_SIZE)));
  --            ull = *(uLB+x-2);ul= *(uLB+x-1);  u  = *(uLB+x);  ur  = *(uLB+(2*(width-1)-(x+XTK_PAD_SIZE-1)));  urr  = *(uLB+(2*(width-1)-(x+XTK_PAD_SIZE)));
  --            ll = *(cLB+x-2);l= *(cLB+x-1);  c  = *(cLB+x);  r   = *(cLB+(2*(width-1)-(x+XTK_PAD_SIZE-1)));  rr   = *(cLB+(2*(width-1)-(x+XTK_PAD_SIZE)));
  --            dll = *(dLB+x-2);dl= *(dLB+x-1);  d  = *(dLB+x);  dr  = *(dLB+(2*(width-1)-(x+XTK_PAD_SIZE-1)));  drr  = *(dLB+(2*(width-1)-(x+XTK_PAD_SIZE)));
  --            ddll = *(ddLB+x-2);ddl = *(ddLB+x-1); dd = *(ddLB+x); ddr = *(ddLB+(2*(width-1)-(x+XTK_PAD_SIZE-1))); ddrr = *(ddLB+(2*(width-1)-(x+XTK_PAD_SIZE)));
  --          }
  --          else
  --            {
  --              uull = *(uuLB+x-2);uul = *(uuLB+x-1); uu = *(uuLB+x); uur = *(uuLB+x+1); uurr = *(uuLB+x+2);
  --              ull = *(uLB+x-2);ul= *(uLB+x-1);  u  = *(uLB+x);  ur  = *(uLB+x+1);  urr  = *(uLB+x+2);
  --              ll = *(cLB+x-2);l= *(cLB+x-1);  c  = *(cLB+x);  r   = *(cLB+x+1);  rr   = *(cLB+x+2);
  --              dll = *(dLB+x-2);dl= *(dLB+x-1);  d  = *(dLB+x);  dr  = *(dLB+x+1);  drr  = *(dLB+x+2);
  --              ddll = *(ddLB+x-2);ddl = *(ddLB+x-1); dd = *(ddLB+x); ddr = *(ddLB+x+1); ddrr = *(ddLB+x+2);
  --            }

  return im(x,y): cropNone , int32
    --          bool grPix;
    --          bool bPix;
    --          bool rPix;
    --          bool gbPix;

    --          grPix= !((y+offY)&1) & !((x+offX)&1);
    --          bPix=  ((y+offY)&1)& !((x+offX)&1);
    --          rPix= !((y+offY)&1) &  ((x+offX)&1);
    --          gbPix=  ((y+offY)&1)&  ((x+offX)&1);

    --          if (!grPix & !gbPix)
    let 
    grgb = if grPix(x,y)==0 and gbPix(x,y)==0 then
    --          {
    --            grgb = 0;
               0
    --          } 
    else

      let
    --            {
    --              int g1Avg= (int) ((float)(uull+uu+uurr+ll+c+rr+ddll+dd+ddrr)+4.5)/9;
    -- JB -- chnaged kernel to remove the division 
      g1Avg = ( orion.sum(inImg(x-2,y-2),inImg(x,y-2),inImg(x+2,y-2),inImg(x-2,y),inImg(x,y),inImg(x+2,y),inImg(x-2,y+2),inImg(x,y+2),inImg(x+2,y+2),4) * 14 ) >> 7
    --              int g2Avg= (ul+ur+dl+dr+2)/4;
      g2Avg= orion.sum(inImg(x-1,y-1),inImg(x+1,y-1),inImg(x-1,y+1),inImg(x+1,y+1),2)>>2;
    --              int g1g2Avg = (g1Avg+g2Avg+1)/2;
      g1g2Avg = orion.sum(g1Avg,g2Avg,1)>>1;
    --              
    --              int thr = params->lowThr + ((params->highThr-params->lowThr)*g1g2Avg >> params->procBitRes);
      thr = settings.lowThr + ((settings.highThr-settings.lowThr)*g1g2Avg >> settings.procBitRes);
    --              grgb = (g1Avg-g2Avg+1)/2;

      grgb1 = orion.sum(g1Avg,-g2Avg,1)>>1;
    --              grgb = (grgb > thr) ? ((grgb > 2*thr)? 0:(2*thr-grgb)) : grgb;
      grgb2 = if (grgb1 > thr) then  ( if (grgb1 > (thr<<1)) then 0 else ((thr<<1)-grgb1) end) else grgb1 end;
    --              grgb = (grgb < -thr) ? ((grgb < -2*thr)? 0:(-2*thr-grgb)) : grgb;
          in 
            if (grgb2 < -thr) then ( if (grgb2 < -(thr<<1)) then 0 else (-(thr<<1)-grgb2) end) else grgb2 end

    end -- if
    --            }
    --            // output
    --            outImg[y*width+x] = clip(c-grgb, 0, maxPix);
    --            }

    in clip( inImg(x,y) - grgb, 0, maxPix )
  end
--}
end


function ccm(inImg, settings)
	--register int	y, x, k, i, j;
	--int				*uLB, *cLB, *dLB;
	--int				sat[9];
  local sat = {}
	--int				ccmMat[9];
  local ccmMat = {}

	--// generate a saturation matrix
	--for (k = 0; k < 9; k++)
  for k=0,8 do
	--{		
	--	sat[k] = (256-params->colorSat) >> 10;
    -- integer devision does a floor
    sat[k] = math.floor((256-settings.colorSat) / math.pow(2,10))
	--	if (!(k%4))
    if k%4==0 then
	--	{
	--		sat[k] += params->colorSat;
      sat[k] = sat[k] + settings.colorSat
	--	}
    end
	--}
	end

	--// update the ccm
	--int tmp = 0;
  local tmp = 0
	--for(i = 0; i < 3; i++)
  for i=0,2 do
	--{
	--	for(j = 0; j < 3; j++)
    for j=0,2 do
	--	{
	--		for(k = 0; k < 3; k++)
      for k=0,2 do
	--		{
	--			tmp += sat[3*j+k]*params->ccmMat[3*k+i];
        tmp = tmp + sat[3*j+k]*settings.ccmMat[3*k+i]
	--		}
      end
	--		ccmMat[3*j+i]	= ((tmp+128) >> 8);
      ccmMat[3*j+i] = math.floor((tmp+128) / math.pow(2,8))
	--		tmp				= 0;
      tmp = 0
	--	}
    end
	--}
  end

	--// determine the weight matrix
	--int w[9];
  local w = {}
	--if (params->avgColorsFlag)
  if settings.avgColorsFlag then
	--{
		w[0] = 1; w[1] = 2; w[2] = 1;
		w[3] = 2; w[4] = 4; w[5] = 2;
		w[6] = 1; w[7] = 2; w[8] = 1;
	--}
  else
	--else
	--{
		w[0] = 0; w[1]	= 0;  w[2] = 0;
		w[3] = 0; w[4]	= 16; w[5] = 0;
		w[6] = 0; w[7]	= 0;  w[8] = 0;
	--}
  end

  --print("CCMMAT",ccmMat[0], ccmMat[1], ccmMat[2], ccmMat[3], ccmMat[4], ccmMat[5], ccmMat[6], ccmMat[7], ccmMat[8])

	--// apply the ccm
	--for (y = 0; y < height; y++)
	--{
	--	if (y < CCM_PAD_SIZE)
	--	{
	--		uLB	= inImg+(CCM_PAD_SIZE-y-1)*3*width;
	--		cLB	= inImg+y*3*width;
	--		dLB	= inImg+(y+1)*3*width;
	--	}
	--	else if (y > height-1-CCM_PAD_SIZE)
	--	{
	--		uLB	= inImg+(y-1)*3*width;
	--		cLB	= inImg+y*3*width;
	--		dLB	= inImg+(2*(height-1)-(y+CCM_PAD_SIZE-1))*3*width;
	--	}
	--	else
	--	{
	--		uLB	= inImg+(y-1)*3*width;
	--		cLB	= inImg+(y+0)*3*width;
	--		dLB	= inImg+(y+1)*3*width;
	--	}

	--	for (x = 0; x < width; x++)
	--	{
	--		// pixel local environment
	--		int ul[3],	u[3], ur[3];
	--		int l[3],	c[3], r[3];
	--		int dl[3],	d[3], dr[3];
	--		// mechanism to replicate borders (columns) - using mirror replication
	--		if (x < CCM_PAD_SIZE)
	--		{				

	--			for (k = 0; k < 3; k++)
	--			{
	--				ul[k]	= *(uLB+3*(CCM_PAD_SIZE-x-1)+k);
	--				u[k]	= *(uLB+3*x+k);
	--				ur[k]	= *(uLB+3*(x+1)+k);
	--				l[k]	= *(cLB+3*(CCM_PAD_SIZE-x-1)+k);
	--				c[k]	= *(cLB+3*x+k);  
	--				r[k]	= *(cLB+3*(x+1)+k);
	--				dl[k]	= *(dLB+3*(CCM_PAD_SIZE-x-1)+k);
	--				d[k]	= *(dLB+3*x+k);  
	--				dr[k]	= *(dLB+3*(x+1)+k);
	--			}
	--		}
	--		else if (x > width-1-CCM_PAD_SIZE)
	--		{
	--			for (k = 0; k < 3; k++)
	--			{
	--				ul[k]	= *(uLB+3*(x-1)+k);
	--				u[k]	= *(uLB+3*x+k);
	--				ur[k]	= *(uLB+3*(2*(width-1)-(x+CCM_PAD_SIZE-1))+k);
	--				l[k]	= *(cLB+3*(x-1)+k);
	--				c[k]	= *(cLB+3*x+k);  
	--				r[k]	= *(cLB+3*(2*(width-1)-(x+CCM_PAD_SIZE-1))+k);
	--				dl[k]	= *(dLB+3*(x-1)+k);
	--				d[k]	= *(dLB+3*x+k);  
	--				dr[k]	= *(dLB+3*(2*(width-1)-(x+CCM_PAD_SIZE-1))+k);
	--			}
	--		}
	--		else
	--		{
	--			for (k = 0; k < 3; k++)
	--			{
	--				ul[k]	= *(uLB+3*(x-1)+k);
	--				u[k]	= *(uLB+3*x+k);
	--				ur[k]	= *(uLB+3*(x+1)+k);
	--				l[k]	= *(cLB+3*(x-1)+k);
	--				c[k]	= *(cLB+3*x+k);  
	--				r[k]	= *(cLB+3*(x+1)+k);
	--				dl[k]	= *(dLB+3*(x-1)+k);
	--				d[k]	= *(dLB+3*x+k);  
	--				dr[k]	= *(dLB+3*(x+1)+k);
	--			}
	--		}


	--		int m[3];


  local m = {}
  --for (k = 0; k < 3; k++)
	--		{
  for k=0,2 do
    m[k] = im(x,y) : cropNone
    orion.sum(inImg(x-1,y-1)[k]*orion.int32([w[0]]) , inImg(x,y-1)[k]*orion.int32([w[1]]) , inImg(x+1,y-1)[k]*orion.int32([w[2]]) ,
     inImg(x-1,y)[k]*orion.int32([w[3]])  , inImg(x,y)[k]*orion.int32([w[4]]) , inImg(x+1,y)[k]*orion.int32([w[5]])  ,
     inImg(x-1,y+1)[k]*orion.int32([w[6]]) , inImg(x,y+1)[k]*orion.int32([w[7]]) , inImg(x+1,y+1)[k]*orion.int32([w[8]]) , 8)>>4
            end
  end
	--		}

  return im(x,y): cropNone , int32[3]
    -- outImg[3*(y*width+x)+2] = clip((c[2]*ccmMat[0] + m[1]*ccmMat[1] + m[0]*ccmMat[2] + 128)>>8, 0, maxPix);
    -- outImg[3*(y*width+x)+1] = clip((m[2]*ccmMat[3] + c[1]*ccmMat[4] + m[0]*ccmMat[5] + 128)>>8, 0, maxPix);
    -- outImg[3*(y*width+x)+0] = clip((m[2]*ccmMat[6] + m[1]*ccmMat[7] + c[0]*ccmMat[8] + 128)>>8, 0, maxPix);
  -- notice we had to reorder these to keep functionality the same
  { clip(([m[2]]*orion.int32([ccmMat[6]]) + [m[1]]*orion.int32([ccmMat[7]]) + inImg(x,y)[0]*orion.int32([ccmMat[8]]) + 128)>>8, 0, maxPix),
    clip(([m[2]]*orion.int32([ccmMat[3]]) + inImg(x,y)[1]*orion.int32([ccmMat[4]]) + [m[0]]*orion.int32([ccmMat[5]]) + 128)>>8, 0, maxPix),
    clip((inImg(x,y)[2]*orion.int32([ccmMat[0]]) + [m[1]]*orion.int32([ccmMat[1]]) + [m[0]]*orion.int32([ccmMat[2]]) + 128)>>8, 0, maxPix)}

  end
	--	}
	--}

end

function blc(inImg, settings)
  --int height= params->height;
  --int width= params->width;
  --int maxPix = (1 << params->procBitRes)-1;
  
  --// different proc resolution
  --if (params->inBitRes != params->procBitRes)
  --{
  --  for(register int k = 0; k < width*height; k++)
  --  {
  --    inImg[k] = min2(((inImg[k] << params->procBitRes) + (1 << (params->inBitRes-1))) >> params->inBitRes, (1 << params->procBitRes)-1);
  --  }
  --}

  return im(x,y): cropNone , int32
    let

    --  int offX, offY;
    --  switch(params->format)
    --  {
    --    case GRBG:
    --    offX = 0;
    --    offY = 0;
    --    break;
    --    case GBRG:
    --    offX = 1;
    --    offY = 1;
    --    break;
    --    case RGGB:
    --    offX = 1;
    --    offY = 0;
    --    break;
    --    case BGGR:
    --    offX = 0;
    --    offY = 1;
    --    break;
    --    default:
    --    cout << "error in dem.cpp - expecting BAYER format." << endl;
    --    exit(-1);
    --  }

    --register int y, x;
    --int pix;
    --bool grPix, rPix, bPix, gbPix;
    --int offset, gain;
    --// no line buffers are required - per-pixel processing 
    --for (y = 0; y < height; y++)
    ---{
    --for (x = 0; x < width; x++)
    --    {
    --      // calculate pixel color


    --      // find offset and gain according to color
    --      offset= grPix*params->offsetGr+rPix*params->offsetR+bPix*params->offsetB+gbPix*params->offsetGb;
    offset = orion.sum(grPix(x,y)*settings.offsetGr,rPix(x,y)*settings.offsetR,bPix(x,y)*settings.offsetB,gbPix(x,y)*settings.offsetGb);
    --      gain= grPix*params->gainGr+rPix*params->gainR+bPix*params->gainB+gbPix*params->gainGb;
    gain = grPix(x,y)*settings.gainGr+rPix(x,y)*settings.gainR+bPix(x,y)*settings.gainB+gbPix(x,y)*settings.gainGb;
          
    --      // apply offset and gain
    --      pix = inImg[y*width+x];
    --      pix = max2(0, min2(maxPix, pix + offset));
    pix = orion.max(0, orion.min(maxPix, inImg(x,y) + offset));
    --      pix = (((pix*gain) << params->shift) + (1 << (params->procBitRes-2))/2) >> (params->procBitRes-1);
    pix2 = (((pix*gain) << settings.shift) + ((1 << (settings.procBitRes-2))>>1)) >> (settings.procBitRes-1);
--          pix = min2(pix, params->limit);
    pix3 = orion.min(pix2, settings.limit);
--          // output
--          outImg[y*width+x] = pix;
--        }
    in pix3
  end
--  }

--  if (params->procBitRes != params->outBitRes)
--  {
--    for(register int k = 0; k < width*height; k++)
--    {
--      outImg[k] = min2(((outImg[k] << params->outBitRes) + (1 << (params->procBitRes-1))) >> params->procBitRes, (1 << params->outBitRes)-1);
--    }
--  }
end

function dem(inImg, settings)
--void intHV(int& Bh, int& Gh, int& Rh, int& Bv, int& Gv, int& Rv, 
--              int c, int u, int d, int l, int r, int ul, int ur, int dl, int dr, int uu, int dd, int ll, int rr, 
--              int y, int x, int format, int maxPix, int offX, int offY, bool drv)
--{
  
--  bool grPix;
--  bool bPix;
--  bool rPix;
--  bool gbPix;

--  grPix= !((y+offY)&1) & !((x+offX)&1);
--  bPix=  ((y+offY)&1)& !((x+offX)&1);
--  rPix= !((y+offY)&1) &  ((x+offX)&1);
--  gbPix=  ((y+offY)&1)&  ((x+offX)&1);

--  if (grPix)
--  {
--    Gh = c;
--    Gv = c;
--    Bh = (u+d+1)/2 + (4*c-ul-ur-dl-dr+2)/4;
--    Bv = (u+d+1)/2 + (drv ? (2*c-uu-dd+2)/4 : 0);
--    Rh = (l+r+1)/2 + (drv ? (2*c-rr-ll+2)/4 : 0);
--    Rv = (l+r+1)/2 + (4*c-ul-ur-dl-dr+2)/4;
--  } else if (gbPix)
--    {
--      Gh = c;
--      Gv = c;
--      Bh = (l+r+1)/2 + (drv ? (2*c-rr-ll+2)/4 : 0);
--      Bv = (l+r+1)/2 + (4*c-ul-ur-dl-dr+2)/4;
--      Rh = (u+d+1)/2 + (4*c-ul-ur-dl-dr+2)/4;
--      Rv = (u+d+1)/2 + (drv ? (2*c-uu-dd+2)/4 : 0);
--    } else if (bPix)
--      {
--        Gh = (l+r+1)/2 + (drv ? (2*c-rr-ll+2)/4 : 0);
--        Gv = (u+d+1)/2 + (drv ? (2*c-uu-dd+2)/4 : 0);
--        Bh = c;
--        Bv = c;
--        Rh = (ul+ur+dl+dr+2)/4 + (l+r-u-d+2)/2 + (drv ? (2*c-rr-ll+2)/4 : 0);
--        Rv = (ul+ur+dl+dr+2)/4 + (u+d-l-r+2)/2 + (drv ? (2*c-uu-dd+2)/4 : 0);
--      }
--      else
--        {
--          Gh = (l+r+1)/2 + (drv ? (2*c-rr-ll+2)/4 : 0);
--          Gv = (u+d+1)/2 + (drv ? (2*c-uu-dd+2)/4 : 0);
--          Bh = (ul+ur+dl+dr+2)/4 + (l+r-u-d+2)/2 + (drv ? (2*c-rr-ll+2)/4 : 0);
--          Bv = (ul+ur+dl+dr+2)/4 + (u+d-l-r+2)/2 + (drv ? (2*c-uu-dd+2)/4 : 0);
--          Rh = c;
--          Rv = c;
--        }
--        // clip values to range
--        Gh = clip(Gh, 0, maxPix); Gv = clip(Gv, 0, maxPix); 
--        Bh = clip(Bh, 0, maxPix); Bv = clip(Bv, 0, maxPix); 
--        Rh = clip(Rh, 0, maxPix); Rv = clip(Rv, 0, maxPix);
--        }

  local function Make(drv)
    return im Gh(x,y) : cropNone
      clip(
        switch pix(x,y)
          case GR -> inImg(x,y)
          case GB -> inImg(x,y)
          default -> if drv then orion.sum(inImg(x-1,y)<<1,inImg(x+1,y)<<1, inImg(x,y)<<1,-(inImg(x+2,y)<<1),-inImg(x-2,y),2)>>2
                            else orion.sum(inImg(x-1,y),inImg(x+1,y),1)>>1 end
        end,0,maxPix)
--      clip(pix(x,y),0,maxPix)
    end,
    im Gv(x,y) : cropNone
      clip(
        switch pix(x,y)
          case GR -> inImg(x,y)
          case GB -> inImg(x,y)
          default -> if drv then (orion.sum( inImg(x,y-1)<<1,inImg(x,y+1)<<1,inImg(x,y)<<1,-inImg(x,y-2),-inImg(x,y+2),2) >> 2)
                            else (orion.sum( inImg(x,y-1)   ,inImg(x,y+1)   , 1 ) >> 1 )
                     end
        end,
      0,maxPix)
    end,
    im Bh(x,y) : cropNone
      clip(switch pix(x,y)
        -- (u+d+1)/2 + (4*c-ul-ur-dl-dr+2)/4;
        case GR -> orion.sum(inImg(x,y-1)<<1,inImg(x,y+1)<<1,inImg(x,y)<<2,-inImg(x-1,y-1),-inImg(x+1,y-1),-inImg(x-1,y+1),-inImg(x+1,y+1),2)>>2;
        -- (l+r+1)/2 + (drv ? (2*c-rr-ll+2)/4 : 0);
        case GB -> if drv then orion.sum(inImg(x-1,y)<<1,inImg(x+1,y)<<1, inImg(x,y)<<2,-inImg(x+2,y),-inImg(x-2,y),2)>>2 
                          else orion.sum(inImg(x-1,y),inImg(x+1,y),1)>>1 end ;
        case B -> inImg(x,y)
        -- (ul+ur+dl+dr+2)/4 + (l+r-u-d+2)/2 + (drv ? (2*c-rr-ll+2)/4 : 0);
        default -> if drv then orion.sum(inImg(x-1,y-1),inImg(x+1,y-1),inImg(x-1,y+1),inImg(x+1,y+1),2, 
                                         inImg(x-1,y)<<1,inImg(x+1,y)<<1,-(inImg(x,y-1)<<1),-(inImg(x,y+1)<<1),  
                                         inImg(x,y)<<1,-inImg(x+2,y),-inImg(x-2,y))>>2
	                  else orion.sum(inImg(x-1,y-1),inImg(x+1,y-1),inImg(x-1,y+1),inImg(x+1,y+1),2, 
                                         inImg(x-1,y)<<1,inImg(x+1,y)<<1,-(inImg(x,y-1)<<1),-(inImg(x,y+1)<<1))>>2  end;
          end,0,maxPix)
--      clip(pix(x,y),0,maxPix)
    end,
    im Bv(x,y) : cropNone
      clip(switch pix(x,y)
        -- (u+d+1)/2 + (drv ? (2*c-uu-dd+2)/4 : 0);
        case GR -> if drv then orion.sum( inImg(x,y-1)<<1,inImg(x,y+1)<<1 , inImg(x,y)<<1,-inImg(x,y-2),inImg(x,y+2),2)>>2
                          else orion.sum( inImg(x,y-1),inImg(x,y+1),1)>>1 end ;
        -- (l+r+1)/2 + (4*c-ul-ur-dl-dr+2)/4;
        case GB -> orion.sum( inImg(x-1,y)<<1,inImg(x+1,y)<<1,inImg(x,y)<<2,-inImg(x-1,y-1),-inImg(x+1,y-1),-inImg(x-1,y+1),-inImg(x+1,y+1),2)>>2;
        case B -> inImg(x,y)
        -- (ul+ur+dl+dr+2)/4 + (u+d-l-r+2)/2 + (drv ? (2*c-uu-dd+2)/4 : 0);
        case R ->  if drv then orion.sum( inImg(x-1,y-1),inImg(x+1,y-1),inImg(x-1,y+1),inImg(x+1,y+1), 
                                          inImg(x,y-1)<<1,inImg(x,y+1)<<1,-(inImg(x-1,y)<<1),-(inImg(x+1,y)<<1), 
                                          inImg(x,y)<<1,-inImg(x,y-2),-inImg(x,y+2),2)>>2
                          else orion.sum(inImg(x-1,y-1),inImg(x+1,y-1),inImg(x-1,y+1),inImg(x+1,y+1),2, 
                                          inImg(x,y-1)<<1,inImg(x,y+1)<<1,-(inImg(x-1,y)<<1),-(inImg(x+1,y)<<1))>>2 end ;                             
        default -> 0
      end,0,maxPix)
    end,
    im Rh(x,y) : cropNone
      clip(switch pix(x,y)
	   case GR -> if drv then (orion.sum(inImg(x-1,y)<<1,inImg(x+1,y)<<1,(inImg(x,y)<<1),-inImg(x+2,y),-inImg(x-2,y),2)>>2) 
		             else (orion.sum(inImg(x-1,y)   ,inImg(x+1,y)   , 1)>>1) end ;
           case GB -> (orion.sum( inImg(x,y-1)<<1,inImg(x,y+1)<<1,(inImg(x,y)<<2),-inImg(x-1,y-1),-inImg(x+1,y-1),-inImg(x-1,y+1),-inImg(x+1,y+1),2 )>>2)
           case B  -> if drv then (orion.sum(  inImg(x-1,y-1),inImg(x+1,y-1),inImg(x-1,y+1),inImg(x+1,y+1),
                                              (inImg(x-1,y)<<1),inImg(x+1,y)<<1,-(inImg(x,y-1)<<2),-(inImg(x,y+1)<<1), 
                                              (inImg(x,y)<<1),-inImg(x+2,y),-inImg(x-2,y),2) >> 2 )
                             else (orion.sum(  inImg(x-1,y-1),inImg(x+1,y-1),inImg(x-1,y+1),inImg(x+1,y+1),
                                              (inImg(x-1,y)<<1),inImg(x+1,y)<<1,-(inImg(x,y-1)<<2),-(inImg(x,y+1)<<1),2) >> 2 )end ;  
        default -> inImg(x,y)
      end,0,maxPix)
    end,
    im Rv(x,y) : cropNone
      clip(switch pix(x,y)
	   case GR -> (orion.sum( inImg(x-1,y)<<1,inImg(x+1,y)<<1,inImg(x,y)<<2,-inImg(x-1,y-1),-inImg(x+1,y-1),-inImg(x-1,y+1),-inImg(x+1,y+1),2)>>2);
           case GB -> if drv then (orion.sum(inImg(x,y-1)<<1,inImg(x,y+1)<<1,(inImg(x,y)<<1),-inImg(x,y-2),-inImg(x,y+2),2)>>2)
		             else (orion.sum(inImg(x,y-1)   ,inImg(x,y+1)   , 1 ) >>1 )  end ;
	   case B  -> if drv then (orion.sum( inImg(x-1,y-1),inImg(x+1,y-1),inImg(x-1,y+1),inImg(x+1,y+1),
                                              inImg(x,y-1)<<1,inImg(x,y+1)<<1,-(inImg(x-1,y)<<1),-(inImg(x+1,y)<<1),
                                              (inImg(x,y)<<1),-inImg(x,y-2),-inImg(x,y+2),2)>>2)  
                             else (orion.sum( inImg(x-1,y-1),inImg(x+1,y-1),inImg(x-1,y+1),inImg(x+1,y+1),
                                              inImg(x,y-1)<<1,inImg(x,y+1)<<1,-(inImg(x-1,y)<<1),-(inImg(x+1,y)<<1),2)>>2) end ;
        default -> inImg(x,y)
      end,0,maxPix)
    end
  end

  local Gh, Gv, Bh, Bv, Rh, Rv = Make(false)
  local GhDrv, GvDrv, BhDrv, BvDrv, RhDrv, RvDrv = Make(true)

--  int height= params->height;
--  int width= params->width;
--  int maxPix= (1 << params->procBitRes)-1;

--  intoffX, offY;
--  switch(params->format)
--  {
--    case GRBG:
--    offX = 0;
--    offY = 0;
--    break;
--    case GBRG:
--    offX = 1;
--    offY = 1;
--    break;
--    case RGGB:
--    offX = 1;
--    offY = 0;
--    break;
--    case BGGR:
--    offX = 0;
--    offY = 1;
--    break;
--    default:
--    cout << "error in dem.cpp - expecting BAYER format." << endl;
--    exit(-1);
--  }

--  // different proc resolution
--  if (params->inBitRes != params->procBitRes)
--  {
---    for(register int k = 0; k < width*height; k++)
--    {
--      inImg[k] = min2(((inImg[k] << params->procBitRes) + (1 << (params->inBitRes-1))) >> params->inBitRes, (1 << params->procBitRes)-1);
--    }
--  }

--  register int y, x;
--  // define 5 line buffers
--  int *uuLB, *uLB, *cLB, *dLB, *ddLB;

--  // loop over image lines
--  for (y = 0; y < height; y++)
--  {
--    // mechanism to replicate borders (rows) - using mirror replication
--    if (y < DEM_PAD_SIZE)
--    {
--      uuLB= inImg+(DEM_PAD_SIZE-y)*width;
--      uLB= inImg+(DEM_PAD_SIZE-y-1)*width;
--      cLB= inImg+y*width;
--      dLB= inImg+(y+1)*width;
--      ddLB= inImg+(y+2)*width;
--    }
--    else if (y > height-1-DEM_PAD_SIZE)
--      {
--        uuLB= inImg+(y-2)*width;
--        uLB= inImg+(y-1)*width;
--        cLB= inImg+y*width;
--        dLB= inImg+(2*(height-1)-(y+DEM_PAD_SIZE-1))*width;
--        ddLB= inImg+(2*(height-1)-(y+DEM_PAD_SIZE))*width;
--      }
--      else
--        {
--          uuLB= inImg+(y-2)*width;
--          uLB= inImg+(y-1)*width;
--          cLB= inImg+(y+0)*width;
--          dLB= inImg+(y+1)*width;
--          ddLB= inImg+(y+2)*width;
--        }
        
--        // loop over pixels in line
--        for (x = 0; x < width; x++)
  return im(x,y): cropNone , int32[3]
    let
--        {
--          // pixel local environment
--          int uull,uul,uu,uur,uurr;
--          int ull,ul,u,ur,urr;
--          int ll,l,c,r,rr;
--          int dll,dl,d,dr,drr;
--          int ddll,ddl,dd,ddr,ddrr;
--          // mechanism to replicate borders (columns) - using mirror replication
--          if (x < DEM_PAD_SIZE)
--          {
--            uull = *(uuLB+DEM_PAD_SIZE-x);uul = *(uuLB+DEM_PAD_SIZE-x-1); uu = *(uuLB+x); uur = *(uuLB+x+1); uurr = *(uuLB+x+2);
--            ull = *(uLB+DEM_PAD_SIZE-x);ul= *(uLB+DEM_PAD_SIZE-x-1);u  = *(uLB+x);  ur  = *(uLB+x+1);  urr  = *(uLB+x+2);
--            ll = *(cLB+DEM_PAD_SIZE-x);l= *(cLB+DEM_PAD_SIZE-x-1);c  = *(cLB+x);  r= *(cLB+x+1);  rr   = *(cLB+x+2);
--            dll = *(dLB+DEM_PAD_SIZE-x);dl= *(dLB+DEM_PAD_SIZE-x-1);d  = *(dLB+x);  dr  = *(dLB+x+1);  drr  = *(dLB+x+2);
--            ddll = *(ddLB+DEM_PAD_SIZE-x);ddl = *(ddLB+DEM_PAD_SIZE-x-1); dd = *(ddLB+x); ddr = *(ddLB+x+1); ddrr = *(ddLB+x+2);
--          }
--          else if (x > width-1-DEM_PAD_SIZE)
--            {
--              uull = *(uuLB+x-2);uul = *(uuLB+x-1); uu = *(uuLB+x); uur = *(uuLB+(2*(width-1)-(x+DEM_PAD_SIZE-1))); uurr = *(uuLB+(2*(width-1)-(x+DEM_PAD_SIZE)));
--              ull = *(uLB+x-2);ul= *(uLB+x-1);  u  = *(uLB+x);  ur  = *(uLB+(2*(width-1)-(x+DEM_PAD_SIZE-1)));  urr  = *(uLB+(2*(width-1)-(x+DEM_PAD_SIZE)));
--              ll = *(cLB+x-2);l= *(cLB+x-1);  c  = *(cLB+x);  r   = *(cLB+(2*(width-1)-(x+DEM_PAD_SIZE-1)));  rr   = *(cLB+(2*(width-1)-(x+DEM_PAD_SIZE)));
--              dll = *(dLB+x-2);dl= *(dLB+x-1);  d  = *(dLB+x);  dr  = *(dLB+(2*(width-1)-(x+DEM_PAD_SIZE-1)));  drr  = *(dLB+(2*(width-1)-(x+DEM_PAD_SIZE)));
--              ddll = *(ddLB+x-2);ddl = *(ddLB+x-1); dd = *(ddLB+x); ddr = *(ddLB+(2*(width-1)-(x+DEM_PAD_SIZE-1))); ddrr = *(ddLB+(2*(width-1)-(x+DEM_PAD_SIZE)));
--            }
--            else
--              {
--                uull = *(uuLB+x-2);uul = *(uuLB+x-1); uu = *(uuLB+x); uur = *(uuLB+x+1); uurr = *(uuLB+x+2);
--                ull = *(uLB+x-2);ul= *(uLB+x-1);  u  = *(uLB+x);  ur  = *(uLB+x+1);  urr  = *(uLB+x+2);
--                ll = *(cLB+x-2);l= *(cLB+x-1);  c  = *(cLB+x);  r   = *(cLB+x+1);  rr   = *(cLB+x+2);
--                dll = *(dLB+x-2);dl= *(dLB+x-1);  d  = *(dLB+x);  dr  = *(dLB+x+1);  drr  = *(dLB+x+2);
--                ddll = *(ddLB+x-2);ddl = *(ddLB+x-1); dd = *(ddLB+x); ddr = *(ddLB+x+1); ddrr = *(ddLB+x+2);
--              }

--              // a. calculate horizontal and vertical interpolations for the 5 middle pixels in the support
--              int Bch, Gch, Rch, Bcv, Gcv, Rcv;
--              int Buh, Guh, Ruh, Buv, Guv, Ruv;
--              int Bdh, Gdh, Rdh, Bdv, Gdv, Rdv;
--              int Blh, Glh, Rlh, Blv, Glv, Rlv;
--              int Brh, Grh, Rrh, Brv, Grv, Rrv;
--              // center pixel
--              intHV(Bch, Gch, Rch, Bcv, Gcv, Rcv, c, u, d, l, r, ul, ur, dl, dr, 
--                    uu, dd, ll, rr, y, x, params->format, maxPix, offX, offY, true);
--              // up pixel
--              intHV(Buh, Guh, Ruh, Buv, Guv, Ruv, u, uu, c, ul, ur, uul, uur, l, r, 
--                    0, 0, 0, 0, y-1, x, params->format, maxPix, offX, offY, false);
--              // down pixel
--              intHV(Bdh, Gdh, Rdh, Bdv, Gdv, Rdv, d, c, dd, dl, dr, l, r, ddl, ddr, 
--                    0, 0, 0, 0, y+1, x, params->format, maxPix, offX, offY, false);
--              // left pixel
--              intHV(Blh, Glh, Rlh, Blv, Glv, Rlv, l, ul, dl, ll, c, ull, u, dll, d, 
--                    0, 0, 0, 0, y, x-1, params->format, maxPix, offX, offY, false);
--              // right pixel
--              intHV(Brh, Grh, Rrh, Brv, Grv, Rrv, r, ur, dr, c, rr, u, urr, d, drr, 
--                    0, 0, 0, 0, y, x+1, params->format, maxPix, offX, offY, false);
              
--              // b. calculate horizontal and vertical gradients
--              int hGrad, vGrad;
--              hGrad = max2(max3(abs(Gch-Glh), abs(Bch-Blh), abs(Rch-Rlh)),
--                           max3(abs(Gch-Grh), abs(Bch-Brh), abs(Rch-Rrh)));
    hGrad = orion.max(max3(orion.abs(GhDrv(x,y)-Gh(x-1,y)), orion.abs(BhDrv(x,y)-Bh(x-1,y)), orion.abs(RhDrv(x,y)-Rh(x-1,y))),
                      max3(orion.abs(GhDrv(x,y)-Gh(x+1,y)), orion.abs(BhDrv(x,y)-Bh(x+1,y)), orion.abs(RhDrv(x,y)-Rh(x+1,y))));
--              vGrad = max2(max3(abs(Gcv-Guv), abs(Bcv-Buv), abs(Rcv-Ruv)),
--                           max3(abs(Gcv-Gdv), abs(Bcv-Bdv), abs(Rcv-Rdv)));
    vGrad = orion.max(max3(orion.abs(GvDrv(x,y)-Gv(x,y+1)), orion.abs(BvDrv(x,y)-Bv(x,y+1)), orion.abs(RvDrv(x,y)-Rv(x,y+1))),
                      max3(orion.abs(GvDrv(x,y)-Gv(x,y-1)), orion.abs(BvDrv(x,y)-Bv(x,y-1)), orion.abs(RvDrv(x,y)-Rv(x,y-1))));
              
--              // c. calculate horizontal and vertical color grades
--              int hColorGrade, vColorGrade;
--              hColorGrade = max3(abs(Rch-Bch), abs(Rlh-Blh), abs(Rrh-Brh));
    hColorGrade = max3(orion.abs(RhDrv(x,y)-BhDrv(x,y)), orion.abs(Rh(x-1,y)-Bh(x-1,y)), orion.abs(Rh(x+1,y)-Bh(x+1,y)));
--              vColorGrade = max3(abs(Rcv-Bcv), abs(Ruv-Buv), abs(Rdv-Bdv));
    vColorGrade = max3(orion.abs(RvDrv(x,y)-BvDrv(x,y)), orion.abs(Rv(x,y+1)-Bv(x,y+1)), orion.abs(Rv(x,y-1)-Bv(x,y-1)));
--              
--              // d. combine gradients and color grades
--              int horz = (params->wg*hGrad >> 5) + (params->wc*hColorGrade >> 8);
    horz = (settings.wg*hGrad >> 5) + (settings.wc*hColorGrade >> 8);
--              int vert = (params->wg*vGrad >> 5) + (params->wc*vColorGrade >> 8);
    vert = (settings.wg*vGrad >> 5) + (settings.wc*vColorGrade >> 8);
              
--              // e. combine interpolation directions
--              int Bc, Gc, Rc;
--              if (horz > vert + params->dirThr)
--              {
--                Bc = Bcv;
--                Gc = Gcv;
--                Rc = Rcv;
--              } else if(vert > horz + params->dirThr)
--                {
--                  Bc = Bch;
--                  Gc = Gch;
--                  Rc = Rch;
--                } else
--                  {
--                    Bc = (Bch+Bcv+1)/2;
--                    Gc = (Gch+Gcv+1)/2;
--                    Rc = (Rch+Rcv+1)/2;
--                  }
                  
    Bc = if (horz > vert + settings.dirThr) then BvDrv(x,y)
    else if (vert > horz + settings.dirThr) then BhDrv(x,y)
         else (orion.sum(BhDrv(x,y),BvDrv(x,y),1)>>1) end end

    Gc = if (horz > vert + settings.dirThr) then GvDrv(x,y)
    else if (vert > horz + settings.dirThr) then GhDrv(x,y)
         else (orion.sum(GhDrv(x,y),GvDrv(x,y),1)>>1) end end

    Rc = if (horz > vert + settings.dirThr) then RvDrv(x,y)
    else if (vert > horz + settings.dirThr) then RhDrv(x,y)
         else (orion.sum(RhDrv(x,y),RvDrv(x,y),1)>>1) end end

--                  outImg[3*(y*width+x)+0] = clip(Bc, 0, maxPix);
--                  outImg[3*(y*width+x)+1] = clip(Gc, 0, maxPix);
--                  outImg[3*(y*width+x)+2] = clip(Rc, 0, maxPix);
--                  }
--} 

    in {clip(Bc,0,maxPix), clip(Gc,0,maxPix), clip(Rc,0,maxPix)} -- 

  end
end

function ct8(inImg, settings)
   return im(x,y): cropNone , uint16[3]
    {
      -- notice that we're flippling R and B here, b/c RGB is the order our image save fn expects
      --     outImg[3*k+0] = min2(((inImg[3*k+0] << params->outBitRes) + (1 << (params->inBitRes-1))) >> params->inBitRes, (1 << params->outBitRes)-1);
      orion.min( ((inImg(x,y)[2] << settings.outBitRes) + (1 << (settings.inBitRes-1))) >> settings.inBitRes, (1 << settings.outBitRes)-1),
      orion.min( ((inImg(x,y)[1] << settings.outBitRes) + (1 << (settings.inBitRes-1))) >> settings.inBitRes, (1 << settings.outBitRes)-1),
      orion.min( ((inImg(x,y)[0] << settings.outBitRes) + (1 << (settings.inBitRes-1))) >> settings.inBitRes, (1 << settings.outBitRes)-1)
    }
  end

end

function convertToUint8( tmp )
   return im( x, y ) : uint8 tmp(x,y) end 
end

function convertTo3Uint8( tmp )
   return im( x, y ) : uint8[3] tmp(x,y) end 
end

function convertToInt32( tmp )
   return im( x, y ) : int32[3] tmp(x,y) end
end

function convertToSInt32( tmp )
   return im( x, y ) : int32 tmp(x,y) end
end

function convert3To1( tmp )
   return im( x, y ) : cropNone, int32 tmp(x,y)[0] end
end

--Helpers to reduce line buffer size and arithmetic size 
function convert3to3_32(tmp)
   return im( x, y ) : cropNone, int32[3] tmp(x,y) end
end
function convert1to1_32(tmp)
   return im( x, y ) : cropNone, int32 tmp(x,y) end
end
function convert3to3_16(tmp)
   local im  clap(x,y) : cropNone, int32[3]  { clip(tmp(x,y)[0],0,maxPix), clip(tmp(x,y)[1],0,maxPix), clip(tmp(x,y)[2],0,maxPix) }  end
   return      im(x,y) : cropSame, uint16[3] clap(x,y)  end
end
function convert3to3_16n(tmp)
   local im  clap(x,y) : cropNone, int32[3]  { clip(tmp(x,y)[0],0,maxPix), clip(tmp(x,y)[1],0,maxPix), clip(tmp(x,y)[2],0,maxPix) }  end
   return      im(x,y) : cropNone, uint16[3] clap(x,y)  end
end
function convert1to1_16(tmp)
   local  im clap(x,y) : cropNone, int32  clip(tmp(x,y),0,maxPix) end
   return      im(x,y) : cropSame, uint16 clap(x,y) end
end
function convert1to1_16n(tmp)
   local  im clap(x,y) : cropNone, int32  clip(tmp(x,y),0,maxPix) end
   return      im(x,y) : cropNone, uint16 clap(x,y) end
end

  --local tmp2 = convertToUint8( tmp )
  --tmp2:save("conv_out/noy_inp.bmp")

  --tmp = dem(tmp, settings.dem)
  
  --local tmp3 = convertTo3Uint8( tmp ) 
  --tmp3:save("conv_out/noy_out.bmp")


function makeCampipe(tmp, settings)

      tmp = convert3To1( tmp ) 

      tmp = convert1to1_32( tmp ) 
      tmp = blc(tmp, settings.blc)
      tmp = convert1to1_16( tmp )

      tmp = convert1to1_32( tmp )
      tmp = dpc(tmp, settings.dpc)
      tmp = convert1to1_16( tmp )

      tmp = convert1to1_32(tmp)
      tmp = xtk(tmp, settings.xtk)
      tmp = convert1to1_16n(tmp) --wbg is single pixel

      tmp = convert1to1_32(tmp)
      tmp = wbg(tmp, settings.wbg)
      tmp = convert1to1_16(tmp)

      tmp = convert1to1_32(tmp)
      tmp = dem(tmp, settings.dem)
      tmp = convert3to3_16(tmp)

      tmp = convert3to3_32(tmp)
      tmp = ccm(tmp,settings.ccm)
      tmp = convert3to3_16n(tmp) -- ct8 is single pixel

      tmp = ct8( tmp, settings.ct8) --ct8 is 16 bit already

      return im(x,y) : cropSame , uint8[3] tmp(x,y) end 

end


--sensor = orion.loadRaw("/home/john/Research/StencilGen7_AppWork/Stanford-SEEC-Convolution-Engine/orion/examples/img3.raw", 3264,2448,10)
--sensor:save("orion_out/noy_raw_bayer.bmp")

local sensor

if Raw == true then
   sensor = orion.loadRaw( InpImg , 3264,2448,10)
else
   sensor = orion.load( InpImg )
end

os.execute( "mkdir orion_out" )
sensor:save( "orion_out/inp.bmp" )

campipe = makeCampipe(sensor, settings)
 
buildRun(campipe,InpImg)