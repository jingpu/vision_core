import "orion"

-- import definitions and global settings
terralib.require("defs")
terralib.require("settings")

settings.gcc = {}
settings.gcc.lut = orion.tapLUT(orion.type.uint(16),17,"gcc_lut")

orion.setTapLUT(settings.gcc.lut,{32, 80, 120, 160, 220, 320, 480, 600, 720, 820, 880, 920, 952, 980, 1000, 1015, 1023})

function gcc(inImg)
  local lut = settings.gcc.lut
  return im gcc(x,y): cropSame , int32[3]
    let
      b = inImg[0](x,y)
      g = inImg[1](x,y)
      r = inImg[2](x,y)
      blue = ((lut[(b >> 6)+1]-lut[(b >> 6)])*(b-((b >> 6) << 6)) >> 6) + lut[(b >> 6)];
      green= ((lut[(g >> 6)+1]-lut[(g >> 6)])*(g-((g >> 6) << 6)) >> 6) + lut[(g >> 6)];
      red= ((lut[(r >> 6)+1]-lut[(r >> 6)])*(r-((r >> 6) << 6)) >> 6) + lut[(r >> 6)];
    in
      {defs.clip(blue, 0, defs.maxPix), defs.clip(green, 0, defs.maxPix), defs.clip(red, 0, defs.maxPix)}
  end
end