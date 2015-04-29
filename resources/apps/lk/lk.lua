import "orion"

local _CONVGEN = os.getenv("CONVGEN")
if not _CONVGEN then
   _CONVGEN = "/horowitz/users/jbrunhav/ConvEngine/Conv-Gen8/Stanford-SEEC-Convolution-Engine/HW"
end

package.path = package.path..";".._CONVGEN.."/../orion/examples/?.lua"
package.path = package.path..";".._CONVGEN.."/../orion/examples/?.t"
terralib.require "common"

--inImg = _CONVGEN .. "/src-Stencil-Path/experiments/2013_12_16_SIGGRAPH/lk_int_orion/lkinp.jjm"
inImg = _CONVGEN .. "/src-Stencil-Path/experiments/2013_12_16_SIGGRAPH/lk_int_orion/lkinp_sm.jjm"
--inImg = _CONVGEN .. "/src-Stencil-Path/experiments/2013_12_16_SIGGRAPH/lk_int_orion/lkinp_smsm.jjm"
local width  = 256
local height = 256
--local width  = 64
--local height = 64





windowRadius = 2 -- was 2 
iterations = 3 -- was 3 -- iterations per level
clamp = true
-- flow is stored as int8. 128/ofRange (so ofRange=10 means there are 10 subpixels)
ofRange = 8 -- was 8
logOfRange = math.log(ofRange)/math.log(2)
rescale = 4

-- The determinant will be stored using a precision equal to the difference between these two bit widths (I think)
determinantPrecisionHigh = 20
determinantPrecisionLow = 5
-- I think the final matrix multiply ends up being a difference of two, large, similar numbers.
-- to give this extra precision (so that the subtract doesn't kill the precision), we multiply
-- the inputs by a bit. But don't go too far or it will overflow!
extraPrec = 2

function log2(inp)
  -- assume input is uint32
  local im maxv(x,y) : uint32, cropNone ((1 << 31)-1)+(1<<31) end

  return im(x,y): uint8, cropNone
      map i=1,31 reduce(max) -- was i=1,31
        let
        thisv : uint32 = maxv - ((orion.uint32(1) << orion.uint32(i))-orion.uint32(1))
        in
          if (inp(x,y)&thisv)~=orion.uint32(0) then orion.uint8(i) else orion.uint8(0) end
      end
    end
end

function sign(inp)
  return im(x,y) : int8,cropNone if inp(x,y)>0 then 1 else (-1) end end
end

-- see here for ref: http://www.cs.ucf.edu/~mikel/Research/Optical_Flow.htm
function makeLK(frame)
  assert(orion.ast.isAST(frame))

  local im frame1(x,y) : cropSame, int32 frame(x,y)[0] end
  local im frame2(x,y) : cropSame, int32 frame(x,y)[1] end 

  local im vectorField(x,y) : cropNone, int8[2] {0,0} end

  -- calculate stuff that we will use every iteration
  -- such as derivatives, matrix A^-1 of image gradients, weights.
  -- were calling frame1 F and frame2 G, as in the original LK paper
    
  -- calculate derivatives
  local im Fx(x,y) : cropSame, int32 (frame1(x+1,y)-frame1(x-1,y)) >> orion.uint8(1) end
  local im Fy(x,y) : cropSame, int32 (frame1(x,y+1)-frame1(x,y-1)) >> orion.uint8(1) end

  local im Gx(x,y) : cropNone, int32 (frame2(x+1,y)-frame2(x-1,y)) >> orion.uint8(1) end
  local im Gy(x,y) : cropNone, int32 (frame2(x,y+1)-frame2(x,y-1)) >> orion.uint8(1) end

  -- calculate A^-1

  local im Atemp0(x,y) : cropNone, int32
    map wx = -windowRadius, windowRadius wy = -windowRadius, windowRadius reduce(sum)
    Fx(x+wx,y+wy)*Fx(x+wx,y+wy)
    end 
  end

  local im Atemp1(x,y) : cropNone, int32
    map wx = -windowRadius, windowRadius wy = -windowRadius, windowRadius reduce(sum)
      Fx(x+wx,y+wy)*Fy(x+wx,y+wy)
    end 
  end

  local Atemp2 = Atemp1

  local im Atemp3(x,y) : cropNone, int32
    map wx = -windowRadius, windowRadius wy = -windowRadius, windowRadius reduce(sum)
      Fy(x+wx,y+wy)*Fy(x+wx,y+wy)
    end 
  end

  local p = math.pow(2,determinantPrecisionHigh)
  local im denom(x,y) : cropNone, int32 (Atemp0(x,y)*Atemp3(x,y)-Atemp1(x,y)*Atemp2(x,y)) end

  --[=[
  -- I attempted to adjust the determinant precision per pixel based on the value of the denomenator.
  -- but, this didn't seem to really provide a benefit over just setting it to a constant
  -- remember: log2 will tell you the highest bit in the number
  -- local det_sign = sign(denom)
  -- local im abs_denom(x,y) : cropNone, uint32 orion.abs(denom) end
  -- local det_exp = log2(abs_denom)
  -- local im detPrec(x,y) : cropNone,uint8 orion.max(det_exp(x,y)-determinantPrecisionHigh+5,5) end
  -- ]=] 


  local im detPrec(x,y) : cropNone, uint8 determinantPrecisionLow end
  local im denom(x,y) : cropNone, int32 if denom(x,y)<(1 << detPrec(x,y)) then (1 << detPrec(x,y)) else denom(x,y) end end

  local im det(x,y) : cropNone, int32 p/(denom(x,y) >> detPrec(x,y)) end
                
  -- Atemp are using 16 bits                
  local im A0(x,y) : cropSame (det(x,y)*Atemp3(x,y)) << extraPrec end
  local im A1(x,y) : cropSame (-det(x,y)*Atemp1(x,y)) << extraPrec end
  local im A2(x,y) : cropSame (-det(x,y)*Atemp2(x,y)) << extraPrec end
  local im A3(x,y) : cropSame (det(x,y)*Atemp0(x,y)) << extraPrec end
      
  -- do LK calculation
  -- Notice: instead of iterating the same # of times for each pixel,
  -- we could instead iterate a different # of times for each pixel 
  -- (until the error < epsilon for ex). This would prob make for better
  -- results, but wouldn't be parallelizable

  for i=1,iterations do
  
    local im xcoord(x,y) : cropNone  vectorField(x,y)[0] end
    local im ycoord(x,y) : cropNone  vectorField(x,y)[1] end
  
    local G = im(x,y) : cropSame [resampleBilinearInt(clamp,frame2,orion.type.uint(8),ofRange, ofRange, xcoord, ycoord)] end

    -- bump up the precision a bit in later rounds b/c the delta will be smaller
    -- actually, this doesn't seem to work b/c it overflows or something
    local EP = {0,0,0,0,0}
    im vectorField(x,y) : cropSame, int8[2]
      let
      -- loop over search window
      b = (map  wx = -windowRadius, windowRadius wy = -windowRadius, windowRadius reduce(sum)
            let 
              dx = Fx (x+wx, y+wy)
              dy = Fy (x+wx, y+wy)
              F = frame1 (x+wx, y+wy)
            in
              {orion.int32(dx*(G(x+wx,y+wy)-F)),orion.int32(dy*(G(x+wx,y+wy)-F))}
          end) << [extraPrec+EP[i]]
    in
      -- result = Ainv * (-b)
      -- b is about 16 bits
      {((((A0(x,y)*(-b[0]) >> (determinantPrecisionHigh+detPrec(x,y)))+(A1(x,y)*(-b[1]) >> (determinantPrecisionHigh+detPrec(x,y)))) << logOfRange) >> [extraPrec+extraPrec+EP[i]])+xcoord,
       ((((A2(x,y)*(-b[0]) >> (determinantPrecisionHigh+detPrec(x,y)))+(A3(x,y)*(-b[1]) >> (determinantPrecisionHigh+detPrec(x,y)))) << logOfRange) >> [extraPrec+extraPrec+EP[i]])+ycoord}
    end

  end

  -- rescale this for display
  return im(x,y) : uint8[3] {orion.int32(vectorField[0](x,y))*rescale+128,orion.int32(vectorField[1](x,y))*rescale+128,0} end
end

local frame0 = orion.image(orion.type.array(orion.type.uint(8),2),width,height)
local frame0id = frame0:id()


--if arg[1]=="conv" then
  local yfile, yrfile = orion.compile( {makeLK(frame0)}, 
                                       {platform="convolution", 
                                        debug=false, 
                                        calcPerfModel=false,
                                        straighten=true})
  os.execute( "mkdir -p orion_out" )

  local file = io.open("orion_out/conv.yml","w")
  file:write(yfile)
  file:close()
  
  local rfile = io.open("orion_out/conv_run.yml","w")
  rfile:write(yrfile)
  rfile:write("test_top:\n")
  rfile:write("   inputImages: \n") 
  rfile:write("      special0: orion_out/inp.jjm\n" )
  rfile:write("   bindings: \n")
  rfile:write("      DEFAULT: orion_out/out.jjm\n" )
  rfile:write("   taps: []\n") 
  rfile:close()

--else
  local lkFn = orion.compile( {makeLK(frame0)},  {debug=false, verbose=false, printstage=false, printloopir=false, schedule="materialize",  calcPerfModel = false, printruntime = false})

  os.execute( "mkdir -p orion_out" )

  terra run()

    var frame0_tr = [&Image](cstdlib.malloc(sizeof(Image)))
    frame0_tr:initWithFile( inImg )

    orion.bindImage( frame0id , frame0_tr )
    var res = lkFn()
  
    res:flip()
    res:save("orion_out/out.bmp")
    frame0_tr:flip()
    frame0_tr:save("orion_out/inp.bmp")

  end

  run()
--end