import "orion"


local _CONVGEN = os.getenv("CONVGEN")
if not _CONVGEN then
   _CONVGEN = "/horowitz/users/jbrunhav/ConvEngine/Conv-Gen8/Stanford-SEEC-Convolution-Engine/HW"
end

package.path = package.path..";" .. _CONVGEN .. "/src-Stencil-Path/experiments/2013_12_16_SIGGRAPH/fcam_orion" .. "/fcam4/?.t"

--inImg = _CONVGEN .. "/../orion/examples/n900.jjm"
InpImg = _CONVGEN .. "/src-Stencil-Path/experiments/2013_12_16_SIGGRAPH/fcam_orion/n900_sm.jjm"
--InpImg = _CONVGEN .. "/src-Stencil-Path/experiments/2013_12_16_SIGGRAPH/fcam_orion/n900_smsm.jjm"
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

--W = 2592
--H = 1968

W = 256 
H = 256

settings.ct8 = {}
settings.ct8.inBitRes = 10
settings.ct8.outBitRes = 8

function ct8(inImg)
  return im ct8(x,y) : cropSame , uint8[3]
    {
      orion.min( ((inImg(x,y)[0] << settings.ct8.outBitRes) + (1 << (settings.ct8.inBitRes-1))) >> settings.ct8.inBitRes, (1 << settings.ct8.outBitRes)-1),
      orion.min( ((inImg(x,y)[1] << settings.ct8.outBitRes) + (1 << (settings.ct8.inBitRes-1))) >> settings.ct8.inBitRes, (1 << settings.ct8.outBitRes)-1),
      orion.min( ((inImg(x,y)[2] << settings.ct8.outBitRes) + (1 << (settings.ct8.inBitRes-1))) >> settings.ct8.inBitRes, (1 << settings.ct8.outBitRes)-1)
    }
  end

end

function cr(inp)
   return im cr(x,y) : cropSame inp(x,y) end 
end


function prePipe(tmp, settings)
   tmp = blc(tmp) -- [JB] Cleared
   -- tmp = lin(tmp) -- unused
   -- tmp = lsc(tmp,W,H) -- a few bits are off in the LSC block --[JB]removed for now, LUT
   tmp = dpc(tmp) 
   tmp = xtk(tmp) 
   tmp = den(tmp,W,H) 
   tmp = wbg(tmp)
   tmp = dem(tmp) 
   tmp = srp(tmp,W,H) 
   tmp = ccm(tmp) 
   --tmp = gcc(tmp) -- [JB] removed for now, LUT
   tmp = ccf(tmp) 
   tmp = cnr(tmp,W,H)
   tmp = ccb(tmp) 
   tmp = ct8(tmp) 
   return tmp
end


function dut(tmp, settings)
   tmp = blc(tmp) -- [JB] Cleared
--   tmp = im(x,y): cropSame , uint16[3] { tmp(x,y) , x , 2*y }  end  -- TEST TO VERIFY IMAGES
--  tmp = lin(tmp) -- unused
  --tmp = lsc(tmp,W,H) -- a few bits are off in the LSC block --[JB]removed for now, LUT
     tmp = dpc(tmp) -- [JB] Cleared
     tmp = xtk(tmp) -- [JB] Debug --> Some issues at the image boundary
     tmp = den(tmp,W,H) -- [JB] Debug
--     tmp = wbg(tmp) -- [JB] Debug
--     tmp = dem(tmp) -- [JB] Debug
--     tmp = srp(tmp,W,H) -- [JB] Debug
--     tmp = ccm(tmp) -- [JB] Debug
  --tmp = gcc(tmp) -- [JB] removed for now, LUT
--    tmp = ccf(tmp) -- [JB] Debug
--     tmp = cnr(tmp,W,H) -- [JB] Debug
--     tmp = ccb(tmp) -- [JB] Debug
--     tmp = ct8(tmp) -- [JB] Debug
  
  return tmp
end

function convKern( k , name , j )
   print("Compiling DPDA for " .. name )
   
   os.execute( "mkdir orion_out_" .. name )

   local yfile,yrfile = orion.compile({k},{verbose=false,debug=false,platform="convolution",printstage=false,fastmath=true})
   local file = io.open("orion_out_"..name.."/conv.yml","w")
   file:write(yfile)
   file:close()
   
   local rfile = io.open("orion_out_"..name.."/conv_run.yml","w")
   rfile:write(yrfile)
   rfile:write("    bindings: \n")
   rfile:write("        DEFAULT: src-Stencil-Path/experiments/2013_12_16_SIGGRAPH/fcam_orion/orion_out_"..name.."/out.jjm\n" )
   rfile:write("    inputImages: \n") 
   rfile:write("        special"..j..": src-Stencil-Path/experiments/2013_12_16_SIGGRAPH/fcam_orion/orion_out_"..name.."/inp.jjm\n" )
   rfile:close()
end

local frame0  = orion.image(orion.type.uint(16),W,H)
local frame1  = orion.image(orion.type.int(16),W,H) -- blc -> dpc   int16
local frame2  = orion.image(orion.type.int(16),W,H) -- blc -> dpc   int16
local frame3  = orion.image(orion.type.int(32),W,H) -- dpc -> xtk   int32
local frame4  = orion.image(orion.type.int(16),W,H) -- xtk -> den   int16
local frame5  = orion.image(orion.type.int(16),W,H) -- den -> wbg   int16
local frame6  = orion.image(orion.type.int(16),W,H) -- wbg -> dem   int16
local frame7  = orion.image(orion.type.array(orion.type.int(32),3),W,H) -- dem -> srp int32
local frame8  = orion.image(orion.type.array(orion.type.int(16),3),W,H) -- srp -> ccm int16
local frame9  = orion.image(orion.type.array(orion.type.int(16),3),W,H) -- ccm -> gcc int16
local frame10 = orion.image(orion.type.array(orion.type.int(16),3),W,H) -- ccm -> ccf int16
local frame11 = orion.image(orion.type.array(orion.type.int(16),3),W,H) -- ccf -> cnr int16
local frame12 = orion.image(orion.type.array(orion.type.int(16),3),W,H) -- cnr -> ccb
local frame13 = orion.image(orion.type.array(orion.type.int(16),3),W,H) -- ccb -> ct8
local frame14 = orion.image(orion.type.array(orion.type.uint(8),3),W,H) -- ct8 ... 

local frame0id  = frame0:id()
local frame1id  = frame1:id()
local frame2id  = frame2:id()
local frame3id  = frame3:id()
local frame4id  = frame4:id()
local frame5id  = frame5:id()
local frame6id  = frame6:id()
local frame7id  = frame7:id()
local frame8id  = frame8:id()
local frame9id  = frame9:id()
local frame10id = frame10:id()
local frame11id = frame11:id()
local frame12id = frame12:id()
local frame13id = frame13:id()
local frame14id = frame14:id()

if arg[1]=="conv" then

   convKern( blc(frame0) , "blc" , "0" )
   --convKern( lsc(frame1,W,H) , "lsc" ) -- [JB] LUT
   convKern( dpc(frame2) , "dpc" , "2" )
   convKern( xtk(frame3) , "xtk" , "3" )
   convKern( den(frame4,W,H) , "den" , "4" )
   convKern( wbg(frame5) , "wbg"  , "5" )
   convKern( dem(frame6) , "dem" , "6"  )
   convKern( srp(frame7,W,H) , "srp"  , "7" )
   convKern( ccm(frame8) , "ccm"  , "8" )
   --convKern( gcc(frame9) , "gcc" ) -- [JB] LUT
   convKern( ccf(frame10) , "ccf"  , "10" )
   convKern( cnr(frame11,W,H) , "cnr"  , "11" )
   convKern( ccb(frame12) , "ccb"  , "12" )
   convKern( ct8(frame13) , "ct8"  , "13" )

else

   k_blc = orion.compile({cr(blc(frame0))}     ,{schedule="materialize",verbose=false,debug=false,printruntime=false,printstage=false,fastmath=true})
   --k_lsc = orion.compile({lsc(frame1,W,H)},{verbose=false,debug=false,printruntime=false,printstage=false,fastmath=true}) --[JB] LUT
   k_dpc = orion.compile({cr(dpc(frame2))}     ,{schedule="materialize",verbose=false,debug=false,printruntime=false,printstage=false,fastmath=true})
   k_xtk = orion.compile({cr(xtk(frame3))}     ,{schedule="materialize",verbose=false,debug=false,printruntime=false,printstage=false,fastmath=true})
   k_den = orion.compile({cr(den(frame4,W,H))} ,{schedule="materialize",verbose=false,debug=false,printruntime=false,printstage=false,fastmath=true})
   k_wbg = orion.compile({cr(wbg(frame5))}     ,{schedule="materialize",verbose=false,debug=false,printruntime=false,printstage=false,fastmath=true})
   k_dem = orion.compile({cr(dem(frame6))}     ,{schedule="materialize",verbose=false,debug=false,printruntime=false,printstage=false,fastmath=true})
   k_srp = orion.compile({cr(srp(frame7,W,H))} ,{schedule="materialize",verbose=false,debug=false,printruntime=false,printstage=false,fastmath=true})
   k_ccm = orion.compile({cr(ccm(frame8))}     ,{schedule="materialize",verbose=false,debug=false,printruntime=false,printstage=false,fastmath=true})
   --k_gcc = orion.compile({gcc(frame9)},{verbose=false,debug=false,printruntime=false,printstage=false,fastmath=true}) -- [JB] LUT
   k_ccf = orion.compile({cr(ccf(frame10))}    ,{schedule="materialize",verbose=false,debug=false,printruntime=false,printstage=false,fastmath=true})
   k_cnr = orion.compile({cr(cnr(frame11,W,H))},{schedule="materialize",verbose=false,debug=false,printruntime=false,printstage=false,fastmath=true})
   k_ccb = orion.compile({cr(ccb(frame12))}    ,{schedule="materialize",verbose=false,debug=false,printruntime=false,printstage=false,fastmath=true})
   k_ct8 = orion.compile({cr(ct8(frame13))}    ,{schedule="materialize",verbose=false,debug=false,printruntime=false,printstage=false,fastmath=true})
   

   terra jrun()

      --Load
      var iter0Image = [&Image](cstdlib.malloc(sizeof(Image)))
      iter0Image:initWithFile( InpImg )
      --BLC 
      orion.bindImage( frame0id , iter0Image )
      var iter1Image = k_blc()
      --LSC 
      --orion.bindImage( frame1id , &iter1Image )
      --var iter2Image = k_lsc()
      --DPC 
      orion.bindImage( frame2id , &iter1Image ) --SKIP LSC
      var iter3Image = k_dpc()
      --XTK 
      orion.bindImage( frame3id , &iter3Image )
      var iter4Image = k_xtk()
      --DEN 
      orion.bindImage( frame4id , &iter4Image )
      var iter5Image = k_den()
      --WBG 
      orion.bindImage( frame5id , &iter5Image )
      var iter6Image = k_wbg()
      --DEM 
      orion.bindImage( frame6id , &iter6Image )
      var iter7Image = k_dem()
      --SRP 
      orion.bindImage( frame7id , &iter7Image )
      var iter8Image = k_srp()
      --CCM 
      orion.bindImage( frame8id , &iter8Image )
      var iter9Image = k_ccm()
      --GCC 
      --orion.bindImage( frame9id , &iter9Image ) --SKIP GCC
      --var iter10Image = k_gcc()
      --CCF 
      orion.bindImage( frame10id , &iter9Image )
      var iter11Image = k_ccf()
      --CNR 
      orion.bindImage( frame11id , &iter11Image )
      var iter12Image = k_cnr()
      --CCB 
      orion.bindImage( frame12id , &iter12Image )
      var iter13Image = k_ccb()
      --CT8 
      orion.bindImage( frame13id , &iter13Image )
      var iter14Image = k_ct8()
      
      iter0Image:flip()
      --BLC 
      iter0Image:save("orion_out_blc/inp.jjm")
      iter1Image:flip()
      iter1Image:save("orion_out_blc/out.jjm")
      --LSC 
      --iter1Image:save("orion_out_lsc/inp.jjm")
      --iter2Image:flip()
      --iter2Image:save("orion_out_lsc/out.jjm")
      --DPC 
      --iter2Image:save("orion_out_dpc/inp.jjm")
      iter1Image:save("orion_out_dpc/inp.jjm")
      iter3Image:flip()
      iter3Image:save("orion_out_dpc/out.jjm")
      --XTK 
      iter3Image:save("orion_out_xtk/inp.jjm")
      iter4Image:flip()
      iter4Image:save("orion_out_xtk/out.jjm")
      --DEN 
      iter4Image:save("orion_out_den/inp.jjm")
      iter5Image:flip()
      iter5Image:save("orion_out_den/out.jjm")
      --WBG 
      iter5Image:save("orion_out_wbg/inp.jjm")
      iter6Image:flip()
      iter6Image:save("orion_out_wbg/out.jjm")
      --DEM 
      iter6Image:save("orion_out_dem/inp.jjm")
      iter7Image:flip()
      iter7Image:save("orion_out_dem/out.jjm")
      --SRP 
      iter7Image:save("orion_out_srp/inp.jjm")
      iter8Image:flip()
      iter8Image:save("orion_out_srp/out.jjm")
      --CCM 
      iter8Image:save("orion_out_ccm/inp.jjm")
      iter9Image:flip()
      iter9Image:save("orion_out_ccm/out.jjm")
      --GCC 
      --iter9Image:save("orion_out_gcc/inp.jjm")
      --iter10Image:flip()
      --iter10Image:save("orion_out_gcc/out.jjm")
      --CCF 
      --iter10Image:save("orion_out_ccf/inp.jjm")
      iter9Image:save("orion_out_ccf/inp.jjm")
      iter11Image:flip()
      iter11Image:save("orion_out_ccf/out.jjm")
      --CNR 
      iter11Image:save("orion_out_cnr/inp.jjm")
      iter12Image:flip()
      iter12Image:save("orion_out_cnr/out.jjm")
      --CCB 
      iter12Image:save("orion_out_ccb/inp.jjm")
      iter13Image:flip()
      iter13Image:save("orion_out_ccb/out.jjm")
      --CT8 
      iter13Image:save("orion_out_ct8/inp.jjm")
      iter14Image:flip()
      iter14Image:save("orion_out_ct8/out.jjm")

   end

   jrun()

end


