import "orion"

terralib.require("defs")
terralib.require("settings")

function ccf(inImg)
   return im ccf(x,y): cropSame , int16[3]
  let 
  r = inImg[0](x,y)
  g = inImg[1](x,y)
  b = inImg[2](x,y)
  in
    {(r+2*g+b+2)>>2,(r-g)>>1,(b-g)>>1}
  end
end
