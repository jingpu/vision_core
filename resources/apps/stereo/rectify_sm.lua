import "orion"

local _CONVGEN = os.getenv("CONVGEN")
if not _CONVGEN then
   _CONVGEN = "/horowitz/users/jbrunhav/ConvEngine/Conv-Gen8/Stanford-SEEC-Convolution-Engine/HW"
end

InpImg = "../../images/stereo_inp_256.bmp"

local W,H = 256,256


terralib.loadfile( _CONVGEN .. "/../orion/examples/common.t")()

function clamp(i)
    return im(x,y) : int8 if i > 127 then 127 else (if i < -128 then -128 else i end) end end
end 


function makeOF(searchRadius,windowRadius,inp)
  local frame1 = im(x,y) : cropNone , int16 inp(x,y)[0] end --[JB] This int16 cast was required to make sure that the sub doesn't overflow
  local frame2 = im(x,y) : cropNone , int16 inp(x,y)[1] end --[JB] This int16 cast was required to make sure that the sub doesn't overflow

  local SAD = {}
  for i = 0, 2*searchRadius do
      local tmp = {}
      for ii=-windowRadius, windowRadius do
        for jj=-windowRadius, windowRadius do
          table.insert(tmp, im(x,y) : cropNone , int16 orion.abs(frame1(x+ii,y+jj)-frame2(x+[i+ii],y+jj)) end)
        end
      end
      table.insert(SAD,orion.sum(tmp[1], unpack(tmp)))
  end

  local theMin = orion.min(SAD[1],unpack(SAD))
  print(#SAD)
  local coordCheck = {}
  local count = 0
  for i = 0,2*searchRadius do
    local isme = im(x,y) : cropNone if [SAD[#coordCheck + 1]] == theMin then i else 2*searchRadius + 1 end end
    table.insert(coordCheck, isme)
    count = count + 1
  end

  local offset = im(x,y) [orion.min(coordCheck[1],unpack(coordCheck))] end
  return im(x,y) : cropSame , uint8 offset * 255.0/count end

end

local sensor  = orion.load( InpImg )
--local vectors = makeOF(40,4,sensor)
local vectors = makeOF(32,3,sensor) -- was 40 and 4
--local vectors = makeOF(16,2,sensor) 
--local vectors = makeOF(10,1,sensor)

os.execute( "mkdir orion_out" ) 


--if arg[1]=="conv" then

   print("Compiling DPDA")

   local yfile,yrfile = orion.compile({vectors},{verbose=false,debug=false,platform="convolution",printstage=false,fastmath=true})
  
   local file = io.open("orion_out/conv.yml","w")
   file:write(yfile)
   file:close()
  
   local rfile = io.open("orion_out/conv_run.yml","w")
   rfile:write(yrfile)  
   rfile:write("    bindings: \n")
   rfile:write("        DEFAULT:  /orion_out/out.jjm\n" )
   rfile:write("    inputImages: \n") 
   rfile:write("        special0: /orion_out/inp.jjm\n" )
   rfile:close()

--else

   print("Compiling Reference Code")

   local runit = orion.compile({vectors},{schedule="materialize",verbose=false,debug=false,printruntime=false,printstage=false,fastmath=true})
   local loadit = orion.compile({sensor},{verbose=false,debug=false,printruntime=false,printstage=false,fastmath=true})

   terra run()
      var res = runit()
      var inp = loadit()

      inp:flip()
      inp:save("orion_out/inp.bmp" )
      res:flip() 
      res:save("orion_out/out.bmp")
   end

   print("Runnin Reference Code")

   run()

--end