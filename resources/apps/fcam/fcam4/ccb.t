import "orion"

terralib.require("defs")
terralib.require("settings")

function ccb(inImg)
   return im ccb(x,y): cropNone , int16[3] -- Hack to get individual kernel to build
  let 
  l = inImg[0](x,y)
  u = inImg[1](x,y)
  v = inImg[2](x,y)
  b = defs.clip((2*l-u+3*v)/2,0,defs.maxPix)
  g = defs.clip((2*l-u-v+1)/2,0,defs.maxPix)
  r = defs.clip((2*l-v+3*u)/2,0,defs.maxPix)
  in
    {b,g,r}
  end
end
