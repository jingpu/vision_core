
-- common defines and functions used by the ISP blocks

import "orion"

defs = {}
-- input pixel bit resolution
defs.pixBitRes 	= 10
defs.maxPix 		= math.pow(2,defs.pixBitRes)-1

function oUint(prec)
  if prec <=8 then
    return orion.type.uint(8)
  elseif prec <=16 then
    return orion.type.uint(16)
  elseif prec <=32 then
    return orion.type.uint(32)
  else
    assert(false)
  end
end

function oInt(prec)
  if prec <=8 then
    return orion.type.int(8)
  elseif prec <=16 then
    return orion.type.int(16)
  else
    assert(false)
  end
end

function tap(ty,value,name)
  assert(orion.type.isType(ty))
  assert(type(value)=="number")
  assert(type(name)=="string")

  local r = orion.tap(ty,name)
  orion.setTap(r,value)
  return r
  --return value
end

-- x-offset for Bayer format
defs.offX = im(x,y) : cropNone
  let
  offXT : int32 = switch [settings.byrFormat] case GRBG -> 0 case GBRG -> 1 case RGGB -> 1 case BGGR -> 0 default -> 2 end
  in orion.assert(offXT,34,offXT~=2)
end

-- y-offset for Bayer format
defs.offY = im(x,y) : cropNone
  let
  offYT : int32 = switch [settings.byrFormat] case GRBG -> 0 case GBRG -> 1 case RGGB -> 0 case BGGR -> 1 default -> 2 end
  in orion.assert(offYT,344,offYT~=2)
end

-- 1 if the current pixel is GR, 0 otherwise
defs.grPix = im(x,y) : cropNone
  --      grPix = !((y+offY)&1) & !((x+offX)&1);
  let
  grPixT = not (((y+defs.offY(x,y))&1)~=0) and  not( ((x+defs.offX(x,y))&1) ~= 0);
  in if grPixT then 1 else 0 end
end

-- 1 if the current pixel is B, 0 otherwise
defs.bPix = im(x,y) : cropNone
  --      bPix  =  ((y+offY)&1) & !((x+offX)&1);
  let
  bPixT  =  (((y+defs.offY(x,y))&1) ~= 0) and not ( ((x+defs.offX(x,y))&1) ~=0);
  in if bPixT then 1 else 0 end
end

-- 1 if the current pixel is R, 0 otherwise
defs.rPix = im(x,y) : cropNone
    --      rPix  = !((y+offY)&1) &  ((x+offX)&1);
  let
  rPixT  = not (((y+defs.offY(x,y))&1)~=0) and  (((x+defs.offX(x,y))&1)~=0);
  in if rPixT then 1 else 0 end
end

-- 1 if the current pixel is GB, 0 otherwise
defs.gbPix = im(x,y) : cropNone
    --      gbPix =  ((y+offY)&1) &  ((x+offX)&1);
  let
  gbPixT =  (((y+defs.offY(x,y))&1)~=0) and  (((x+defs.offX(x,y))&1)~=0);
  in if gbPixT then 1 else 0 end
end

-- returns the pixel type in a Bayer format
im pix(x,y) : cropNone
  if defs.grPix(x,y)==1 then GR
  else if defs.gbPix(x,y)==1 then GB
  else if defs.rPix(x,y)==1 then R
  else B end end end
end

-- clip x to be a <= x <= b 
function defs.clip(thisast,inp,minV,maxV)
  assert(orion.ast.isAST(thisast))
  assert(orion.ast.isAST(inp))
  assert(orion.ast.isAST(minV))
  assert(orion.ast.isAST(maxV))

  return orion.min(thisast,orion.max(thisast,inp,minV),maxV)
end

-- -1 if x < 0, 1 otherwise
function defs.sign(thisast, xinp)
  assert(orion.ast.isAST(xinp))
  return im(x,y) : cropNone if xinp(x,y)<0 then -1 else 1 end end
end

function defs.thr(thisast, diff, t)
  assert(orion.ast.isAST(thisast))
  assert(orion.ast.isAST(diff))
  assert(orion.ast.isAST(t))
  
  return im(x,y) : cropNone
    let
      t = orion.max(0, t)
      diff1 = if diff  >  t then ( if diff  >  2*t then 0 else  2*t-diff  end ) else diff  end
      diff2 = if diff1 < -t then ( if diff1 < -2*t then 0 else -2*t-diff1 end ) else diff1 end
    in diff2
  end
end