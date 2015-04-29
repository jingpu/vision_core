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


InpImg = "../../images/lenna_512x512.bmp"

opts = getopt( arg , "i" )

if not opts["i"] then
   opts["i"] = InpImg
end

os.execute( "mkdir -p orion_out" )
sensor = orion.load( opts["i"] )
sensor:save( "orion_out/inp.bmp" )


-- #define clip(x, a, b)   (min2(max2((x), (a)), (b)))
function clip(thisast,inp,minV,maxV)
  assert(orion.ast.isAST(inp))
  assert(orion.ast.isAST(minV))
  assert(orion.ast.isAST(maxV))
  return orion.min(thisast,orion.max(thisast,inp,minV),maxV)
end


function convertToIllum( I_0 , I_1 , I_2 , R, in1 )
   local im convertToIllum(x,y) : cropSame , uint16 clip( (orion.sum( in1(x,y)[0]*I_0 , in1(x,y)[1]*I_1 , in1(x,y)[2]*I_2 )) >> R, 0 , 255 ) end 
   return convertToIllum
end


-- 7 ops
function convolve_1_5_( G_0 , G_1 , G_2 , G_3 , G_4 , R , in1 )
   local im upCast(x,y) :        cropNone , int16 in1(x,y) end 
   local im convolve_1_5_(x,y) : cropNone , int16 clip( (orion.sum( upCast(x,y-2)*G_0,upCast(x,y-1)*G_1,upCast(x,y)*G_2,upCast(x,y+1)*G_3,upCast(x,y+2)*G_4 ) >> R ) , 0 , 255 ) end
   local im downCast(x,y) :      cropSame , uint8 convolve_1_5_(x,y) end 
   return downCast
end
-- 7 ops
function convolve_5_1_( G_0 , G_1 , G_2 , G_3 , G_4 , R , in1 )
   local im upCast(x,y) :        cropNone , int16 in1(x,y) end 
   local im convolve_1_5_(x,y) : cropNone , int16 clip( (orion.sum( upCast(x-2,y)*G_0,upCast(x-1,y)*G_1,upCast(x,y)*G_2,upCast(x+1,y)*G_3,upCast(x+2,y)*G_4 ) >> R ) , 0 , 255 ) end
   local im downCast(x,y) :      cropSame , uint8 convolve_1_5_(x,y) end 
   return downCast
end

function sobel( R, in0 )
   -- TODO -> Convert sobel mask to taps 
   local im in1(x,y)   : cropNone , int16 in0(x,y) end
   local im in1y(x,y)  : cropNone , int16 clip( orion.sum( -in1(x-1,y-1),-(in1(x,y-1)<<1),-in1(x+1,y-1),in1(x-1,y+1),in1(x,y+1)<<1,in1(x+1,y+1) ) , -127 , 127 ) end -- Sobel Y
   local im in1x(x,y)  : cropNone , int16 clip( orion.sum( -in1(x-1,y-1),-(in1(x-1,y)<<1),-in1(x-1,y+1),in1(x+1,y-1),in1(x+1,y)<<1,in1(x+1,y+1) ) , -127 , 127 ) end -- Sobel X
   local im sobel(x,y) : cropNone , int16[2] {  in1x(x,y) , in1y(x,y) } end
   return sobel 
end


function response( T , K , in1 )

   local im Wxx(x,y)  : cropNone , int16 clip( ((in1(x,y)[0] * in1(x,y)[0]) >> (8)) , -127 , 127) end 
   local im Wyy(x,y)  : cropNone , int16 clip( ((in1(x,y)[1] * in1(x,y)[1]) >> (8)) , -127 , 127) end 
   local im Wxy(x,y)  : cropNone , int16 clip( ((in1(x,y)[0] * in1(x,y)[1]) >> (8)) , -127 , 127) end 
   local im Det(x,y)  : cropNone , int16 ((Wxx(x,y)*Wyy(x,y))>>1)-((Wxy(x,y)*Wxy(x,y))>>1) end 
   local im TrSq(x,y) : cropNone , int16 ((Wxx(x,y)+Wyy(x,y))>>1)*((Wxx(x,y)+Wyy(x,y))>>1)>>7 end 
   local im Resp1(x,y): cropNone , int16 Det(x,y) - K*TrSq(x,y) end 
   local im Resp(x,y) : cropSame , int16 clip( Resp1(x,y) , -127 , 127 ) end
   return Resp

end



function  nms(  T , P1 , in1 )

   local im PN(x,y)  : cropNone , bool in1(x,y) >  in1(x,y-1) end 
   local im PS(x,y)  : cropNone , bool in1(x,y) >= in1(x,y+1) end 
   local im PE(x,y)  : cropNone , bool in1(x,y) >  in1(x+1,y) end 
   local im PW(x,y)  : cropNone , bool in1(x,y) >= in1(x-1,y) end 
   local im P(x,y)   : cropNone , bool in1(x,y) >  P1 end 
   local im Pk(x,y)  : cropNone , bool  ( P(x,y) and PW(x,y) and PE(x,y) and PS(x,y) and PN(x,y) ) end
   local im NMS(x,y) : cropSame , uint8 if Pk(x,y) then 255 else 0 end end

   return NMS 

end


function harris(in1)
   
   local P  = orion.tap(orion.type.int(16), "Peak")
   orion.setTap( P , 4 )
   local K  = orion.tap(orion.type.int(16), "K")
   orion.setTap( K , 1 )
   local I  = { 27 , 91 , 9 } 
   local G  = {7 , 31 , 51 , 31 , 7}

   local I_0 = orion.tap( orion.type.uint(16) , "Red_to_Lum" )
   local I_1 = orion.tap( orion.type.uint(16) , "Green_to_Lum" )
   local I_2 = orion.tap( orion.type.uint(16) , "Blue_to_Lum" )  
   orion.setTap( I_0 , I[1] )
   orion.setTap( I_1 , I[2] )
   orion.setTap( I_2 , I[3] )

   local G_0 = orion.tap( orion.type.int(16) , "G0" )
   local G_1 = orion.tap( orion.type.int(16) , "G1" )
   local G_2 = orion.tap( orion.type.int(16) , "G2" )  
   local G_3 = orion.tap( orion.type.int(16) , "G3" )  
   local G_4 = orion.tap( orion.type.int(16) , "G4" )  
   orion.setTap( G_0 , G[1] )
   orion.setTap( G_1 , G[2] )
   orion.setTap( G_2 , G[3] )
   orion.setTap( G_3 , G[4] )
   orion.setTap( G_4 , G[5] )

   local R = orion.tap( orion.type.uint(16) , "R" )
   orion.setTap( R , 7 )

   in1 = convertToIllum( I_0 , I_1 , I_2 , R, in1 )            -- Convert to illuminance
   in1 = convolve_1_5_( G_0 , G_1 , G_2 , G_3 , G_4 , R , in1 ) -- 1x5 Gauss
   in1 = convolve_5_1_( G_0 , G_1 , G_2 , G_3 , G_4 , R , in1 ) -- 5x1 Gauss
   in1 = sobel( 8 , in1 )             -- Sobel
   in1 = response( 8 , K  , in1 )     -- Calc det/trace
   in1 = nms( 8 , P , in1 )           -- Non Maximal Suppression

   return in1 
end


buildRun(  harris(sensor) , opts["i"]  )