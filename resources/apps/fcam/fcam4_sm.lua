import "orion"
require "os"

local _CONVGEN = os.getenv("CONVGEN")
if not _CONVGEN then
   _CONVGEN = "/horowitz/users/jbrunhav/ConvEngine/Conv-Gen8/Stanford-SEEC-Convolution-Engine/HW"
end

package.path = package.path..";" .. _CONVGEN .. "/src-Stencil-Path/experiments/2014_10_24_Bigger/Apps/fcam4/?.t"

inImg = _CONVGEN .. "/../orion/examples/n900.jjm"
--inImg = _CONVGEN .. "/src-Stencil-Path/experiments/2013_12_16_SIGGRAPH/fcam_orion/n900_smsm.jjm"
--inImg = _CONVGEN .. "/src-Stencil-Path/experiments/2013_12_16_SIGGRAPH/fcam_orion/n900_sm.jjm"
--inImg = _CONVGEN .. "/../orion/examples/n900.pgm"


terralib.require("settings")
terralib.require("blc")
terralib.require("lsc")
terralib.require("dpc")
terralib.require("xtk")
terralib.require("gcc")
terralib.require("wbg")
terralib.require("dem")
terralib.require("den")
terralib.require("cnr")
terralib.require("srp")
terralib.require("ccm")
terralib.require("ccf")
terralib.require("ccb")

--W = 3264
--H = 2448

W = 2592
H = 1968

--W = 256 
--H = 256


settings.ct8 = {}
settings.ct8.inBitRes = 10
settings.ct8.outBitRes = 8

function ct8(inImg)
   return im ct8(x,y) : cropSame, uint8[3]
   {
      orion.min( ((inImg(x,y)[0] << settings.ct8.outBitRes) + (1 << (settings.ct8.inBitRes-1))) >> settings.ct8.inBitRes, (1 << settings.ct8.outBitRes)-1),
      orion.min( ((inImg(x,y)[1] << settings.ct8.outBitRes) + (1 << (settings.ct8.inBitRes-1))) >> settings.ct8.inBitRes, (1 << settings.ct8.outBitRes)-1),
      orion.min( ((inImg(x,y)[2] << settings.ct8.outBitRes) + (1 << (settings.ct8.inBitRes-1))) >> settings.ct8.inBitRes, (1 << settings.ct8.outBitRes)-1)
   }
end

end

function makeCampipe(tmp, settings)
   tmp = blc(tmp) -- [JB] Cleared
   --   tmp = im(x,y): cropSame , uint16[3] { tmp(x,y) , x , 2*y }  end  -- TEST TO VERIFY IMAGES
   --  tmp = lin(tmp) -- unused
   --tmp = lsc(tmp,W,H) -- a few bits are off in the LSC block --[JB]removed for now, LUT
   tmp = dpc(tmp) -- [JB] Cleared
   tmp = xtk(tmp) -- [JB] Debug --> Some issues at the image boundary
   tmp = den(tmp,W,H) -- [JB] Debug
   tmp = wbg(tmp) -- [JB] Debug CropSame int16 (single pixel ) works
   tmp = dem(tmp) -- [JB] CropSam int32 (stencil) works
   tmp = srp(tmp,W,H) -- [JB]  CropSame , int16 ( stencil ) works 
   tmp = ccm(tmp) -- [JB]  CropNone , int16 ( stencil ) works
   --tmp = gcc(tmp) -- [JB] removed for now, LUT
   tmp = ccf(tmp) -- [JB] CropSame, int16[3] output ( singple pixel ) works
   --tmp = cnr(tmp,W,H) -- [JB] cropSame, int16[3] output ( big stencil ) works ) --> cropNone causes out of memory error  (Removed for sm
   tmp = ccb(tmp) -- [JB] cropNone , int16[3] output ( single pixle ) works
   tmp = ct8(tmp) -- [JB] cropSame , uint8[3] output ( single pixel ) works
   
   return tmp
end

os.execute( "mkdir orion_out" )

--sensor = orion.loadRaw("img3.raw", W, H, 10)
--sensor = orion.loadRaw(inImg, W, H, 10, 17, true)
sensor = orion.load( inImg )
--sensor:save( "orion_out/raw.jjm" )

campipe = makeCampipe(sensor, settings)

if arg[1]=="conv" then

   print("Compiling DPDA")

   local yfile,yrfile = orion.compile({campipe},{verbose=false,debug=false,platform="convolution",printstage=false,fastmath=true})
   
   local file = io.open("orion_out/conv.yml","w")
   file:write(yfile)
   file:close()
   
   local rfile = io.open("orion_out/conv_run.yml","w")
   rfile:write(yrfile)
   rfile:write("    bindings: \n")
   rfile:write("        DEFAULT: src-Stencil-Path/experiments/2013_12_16_SIGGRAPH/fcam_orion/orion_out/fcam4.jjm\n" )
   --  rfile:write("        DEFAULT: src-Stencil-Path/experiments/2013_12_16_SIGGRAPH/fcam_orion/orion_out/fcam4.bmp\n" )
   rfile:write("    inputImages: \n") 
   rfile:write("        special0: src-Stencil-Path/experiments/2013_12_16_SIGGRAPH/fcam_orion/orion_out/raw.jjm\n" )
   rfile:close()
   
else
   print("HERE")
   local runit = orion.compile({campipe},{verbose=false,debug=false,printruntime=false,printstage=false,fastmath=true})
   local loadit = orion.compile({sensor},{verbose=false,debug=false,printruntime=false,printstage=false,fastmath=true})

   os.execute( "mkdir orion_out" )
   terra run()
   var res = runit()
   var inp = loadit()

   if true then
      inp:flip()
      inp:save("orion_out/raw.jjm" )
      res:flip() -- noy's loadRaw function loads Y flipped of what we expect
      res:save("orion_out/fcam4.jjm")
      res:save("orion_out/fcam4.bmp")
   else
      res:saveRaw("out/fcam4.raw",10)
   end
end

run()

end