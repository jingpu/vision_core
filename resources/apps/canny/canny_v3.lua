

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

os.execute( "mkdir orion_out" )
sensor = orion.load( opts["i"] )
sensor:save( "orion_out/inp.bmp" )


-- #define clip(x, a, b)   (min2(max2((x), (a)), (b)))
function clip(thisast,inp,minV,maxV)
  assert(orion.ast.isAST(inp))
  assert(orion.ast.isAST(minV))
  assert(orion.ast.isAST(maxV))
  return orion.min(thisast,orion.max(thisast,inp,minV),maxV)
end

-- 6 ops 
function convertToIllum( I_0 , I_1 , I_2 , in1 )
   return im(x,y) : cropSame , uint16 clip( orion.sum( in1(x,y)[0]*I_0 , in1(x,y)[1]*I_1 , in1(x,y)[2]*I_2 ) , 0 , 32767 ) end 
end

-- 7 ops
function convolve_1_5_( G_0 , G_1 , G_2 , G_3 , G_4 , R , in1 )
   -- TODO -> Convert T to tap 
   local im upCast(x,y) :        cropNone , int32 in1(x,y) end 
   local im convolve_1_5_(x,y) : cropNone , int32 clip( (orion.sum( upCast(x,y-2)*G_0,upCast(x,y-1)*G_1,upCast(x,y)*G_2,upCast(x,y+1)*G_3,upCast(x,y+2)*G_4 ) >> R ) , -32767 , 32767 ) end
   local im downCast(x,y) :      cropSame , int16 convolve_1_5_(x,y) end 
   return downCast
end
-- 7 ops
function convolve_5_1_( G_0 , G_1 , G_2 , G_3 , G_4 , R , in1 )
   -- TODO -> Convert T to tap 
   local im upCast(x,y) :        cropNone , int32 in1(x,y) end 
   local im convolve_1_5_(x,y) : cropNone , int32 clip( (orion.sum( upCast(x-2,y)*G_0,upCast(x-1,y)*G_1,upCast(x,y)*G_2,upCast(x+1,y)*G_3,upCast(x+2,y)*G_4 ) >> R ) , -32767 , 32767 ) end
   local im downCast(x,y) :      cropSame , int16 convolve_1_5_(x,y) end 
   return downCast
end

-- 18
function sobel( R, in0 )
   -- TODO -> Convert sobel mask to taps 
   local im in1(x,y)  : cropNone , int32 in0(x,y) end
   local im in1y(x,y) : cropNone , int32 clip( orion.sum( -in1(x-1,y-1),-(in1(x,y-1)<<1),-in1(x+1,y-1),in1(x-1,y+1),in1(x,y+1)<<1,in1(x+1,y+1) ) , -32767 , 32767 ) end -- Sobel Y
   local im in1x(x,y) : cropNone , int32 clip( orion.sum( -in1(x-1,y-1),-(in1(x-1,y)<<1),-in1(x-1,y+1),in1(x+1,y-1),in1(x+1,y)<<1,in1(x+1,y+1) ) , -32767 , 32767 ) end -- Sobel X
   local im in1M(x,y) : cropNone , int32 clip( ( in1x(x,y)*in1x(x,y) + in1y(x,y)*in1y(x,y) ) >> 16 , -32767 , 32767 )   end -- Sx^2 + Sy^2
   return im(x,y) : cropSame, int16[3] { in1x(x,y) , in1y(x,y) , in1M(x,y) } end
end

--40sih
function  nms(  T , P1 , P2 , in1 )
   -- 
   --
   
   local tan22 =  math.floor(0.404 * math.pow( 2 , T ))
   local tan66 =  math.floor(2.47  * math.pow( 2 , T ))

   -- W  202 ,  158 , ( -1 ,  0 )    0.404 * -x >  y > -0.404 * -x
   -- NW 158 ,  112 , ( -1 ,  1 )    2.47  * -x >  y >  0.404 * -x 
   -- N  112 ,   66 , (  0 ,  1 )    y > 2.47 * -x or y > 2.47 * x
   -- NE  66 ,   22 , (  1 ,  1 )    2.47  * x >  y >  0.404 * x 
   -- E   22 ,  -22 , (  1 ,  0 )    0.404 * x >  y > -0.404 * x   
   -- SE -22 ,  -66 , (  1 , -1 )   -0.404 * x >  y > -2.47  * x
   -- S  -66 , -112 , (  0 , -1 )    y > -2.47 * -x or y > -2.47 * x
   -- SW -112 , -156 , ( -1 , -1 )   -2.47  * -x >  y >  -0.404 * -x 

   im in1(x,y) : cropNone ,  int32[3] ( { in1(x,y)[0] , in1(x,y)[1]<<T , in1(x,y)[2]  }) end

   local im dir_W(x,y)  : cropNone , bool (  tan22 * -in1(x,y)[0]> in1(x,y)[1] and in1(x,y)[1] > -tan22 * -in1(x,y)[0]) end 
   local im dir_NW (x,y): cropNone , bool (  tan66 * -in1(x,y)[0]> in1(x,y)[1] and in1(x,y)[1] >  tan22 * -in1(x,y)[0]) end 
   local im dir_NE(x,y) : cropNone , bool (  tan66 *  in1(x,y)[0]> in1(x,y)[1] and in1(x,y)[1] >  tan22 *  in1(x,y)[0]) end 
   local im dir_E(x,y)  : cropNone , bool (  tan22 *  in1(x,y)[0]> in1(x,y)[1] and in1(x,y)[1] > -tan22 *  in1(x,y)[0]) end 
   local im dir_SE(x,y) : cropNone , bool ( -tan22 *  in1(x,y)[0]> in1(x,y)[1] and in1(x,y)[1] > -tan66 *  in1(x,y)[0]) end 
   local im dir_SW(x,y) : cropNone , bool ( -tan66 * -in1(x,y)[0]> in1(x,y)[1] and in1(x,y)[1] > -tan22 * -in1(x,y)[0]) end 

   local im dir_S(x,y)  : cropNone , bool ( in1(x,y)[1] < 0 and ( in1(x,y)[1] <  tan66 *  in1(x,y)[0]  or in1(x,y)[1] < -tan66 * in1(x,y)[0] ) ) end 
   local im dir_N(x,y)  : cropNone , bool ( in1(x,y)[1] > 0 and ( in1(x,y)[1] >  tan66 * -in1(x,y)[0]  or in1(x,y)[1] >  tan66 * in1(x,y)[0] ) ) end 

   local im dir_N_S(x,y)    : cropNone , bool ( dir_S(x,y)  or dir_N(x,y) ) end
   local im dir_E_W(x,y)    : cropNone , bool ( dir_E(x,y)  or dir_W(x,y) ) end
   local im dir_NE_SW(x,y)  : cropNone , bool ( dir_SW(x,y) or dir_NE(x,y) ) end
   local im dir_SE_NW(x,y)  : cropNone , bool ( dir_SE(x,y) or dir_NW(x,y) ) end

   local im dir_N_S_peak(x,y)   : cropNone , bool (  in1(x,y)[2] > in1(x+1,y  )[2] and in1(x,y)[2] >= in1(x-1,y  )[2] and dir_E_W(x,y)   ) end
   local im dir_E_W_peak(x,y)   : cropNone , bool (  in1(x,y)[2] > in1(x  ,y+1)[2] and in1(x,y)[2] >= in1(x  ,y-1)[2] and dir_N_S(x,y)   ) end
   local im dir_NE_SW_peak(x,y) : cropNone , bool (  in1(x,y)[2] > in1(x-1,y-1)[2] and in1(x,y)[2] >= in1(x+1,y+1)[2] and dir_NE_SW(x,y) ) end
   local im dir_SE_NW_peak(x,y) : cropNone , bool (  in1(x,y)[2] > in1(x+1,y-1)[2] and in1(x,y)[2] >= in1(x-1,y+1)[2] and dir_SE_NW(x,y) ) end

   local im peak(x,y) : cropNone , bool ( dir_N_S_peak(x,y) or dir_E_W_peak(x,y) or dir_NE_SW_peak(x,y) or dir_SE_NW_peak(x,y) ) end 

   local im true_peak(x,y) : cropNone , bool ( (in1(x,y)[2] > P1) and peak(x,y) ) end
   local im hyst_peak(x,y) : cropNone , bool ( (in1(x,y)[2] > P2) and peak(x,y) ) end

   return im(x,y) : cropSame , bool[2]  { true_peak(x,y) , hyst_peak(x,y) } end
end

-- 30 ops in total
--function hyst( in1P , in1H , both )
function hyst( in1 , both )
  
      im in1(x,y) : cropNone , bool[2]{ in1(x,y)[1] and (    in1(x+1,y+1)[0] or in1(x+1,y  )[0] or in1(x+1,y-1)[0] 
                                                          or in1(x  ,y+1)[0] or in1(x  ,y-1)[0] or in1(x-1,y+1)[0] 
	                                                  or in1(x-1,y  )[0] or in1(x-1,y-1)[0] )  , 
                                        in1(x,y)[1] or false }end
      im in1(x,y) : cropNone , bool[2]{ in1(x,y)[1] and (    in1(x+1,y+1)[0] or in1(x+1,y  )[0] or in1(x+1,y-1)[0] 
                                                          or in1(x  ,y+1)[0] or in1(x  ,y-1)[0] or in1(x-1,y+1)[0] 
	                                                  or in1(x-1,y  )[0] or in1(x-1,y-1)[0] )  , 
                                        in1(x,y)[1] or false }end
      im in1(x,y) : cropNone , bool[2]{ in1(x,y)[1] and (    in1(x+1,y+1)[0] or in1(x+1,y  )[0] or in1(x+1,y-1)[0] 
                                                          or in1(x  ,y+1)[0] or in1(x  ,y-1)[0] or in1(x-1,y+1)[0] 
	                                                  or in1(x-1,y  )[0] or in1(x-1,y-1)[0] )  , 
                                        in1(x,y)[1] or false }end
      im in1(x,y) : cropNone , bool[2]{ in1(x,y)[1] and (    in1(x+1,y+1)[0] or in1(x+1,y  )[0] or in1(x+1,y-1)[0] 
                                                          or in1(x  ,y+1)[0] or in1(x  ,y-1)[0] or in1(x-1,y+1)[0] 
	                                                  or in1(x-1,y  )[0] or in1(x-1,y-1)[0] )  , 
                                        in1(x,y)[1] or false }end
      im in1(x,y) : cropSame , bool[2]{ in1(x,y)[1] and (    in1(x+1,y+1)[0] or in1(x+1,y  )[0] or in1(x+1,y-1)[0] 
                                                          or in1(x  ,y+1)[0] or in1(x  ,y-1)[0] or in1(x-1,y+1)[0] 
                                                or in1(x-1,y  )[0] or in1(x-1,y-1)[0] )  , 
                                     in1(x,y)[1] or false }end
   return in1 
end

function convertToChar( T , in1 )
   return im(x,y) : uint8 (in1(x,y) >> T) end
end

function convertTo3Char( T , in1  )
   return im(x,y) : uint8[3] ( in1(x,y) >> T ) end
end


function convertToPeakImage( in1P , in1H )
   return im(x,y) : uint8[3] ( { if in1P(x,y) then 255 else 0 end ,  if in1H(x,y) then 255 else 0 end , 0 }) end
   --return im(x,y) : uint8[3]   ({ in1(x,y)[0] ,  in1(x,y)[1] , 0 }) end
   --return im(x,y) : uint8  if in1P(x,y) then 255 else 0 end end
end
function convertToPeakImage3( in1 , Suppress )
   return im(x,y) : uint8[3] ( { 
				  if in1(x,y)[0] then 255 else 0 end ,  
                                  if (in1(x,y)[1] and Suppress==0) or (in1(x,y)[0] and Suppress==1) then 255 else 0 end ,  
                                  if (in1(x,y)[0] and Suppress==1) then 255 else 0 end     }) end
   --return im(x,y) : uint8[3]   ({ in1(x,y)[0] ,  in1(x,y)[1] , 0 }) end
   --return im(x,y) : uint8  if in1P(x,y) then 255 else 0 end end
end
function convertToPeakImage2( in1P )
   --return im(x,y) : uint8[3] ( { if in1P(x,y) then 255 else 0 end ,  if in1H(x,y) then 255 else 0 end , 0 }) end
   --return im(x,y) : uint8[3]   ({ in1(x,y)[0] ,  in1(x,y)[1] , 0 }) end
   return im(x,y) : uint8  if in1P(x,y) then 255 else 0 end end
end


function canny(in1)
   
   local I  = { 54 , 183 , 18 } 
   local G  = {14 , 62 , 104 , 62 , 14}
   local Gh = {{14 , 62 , 104 , 62 , 14}}
   local Gv = {{14},{62},{104},{62},{14}}
   local N  = 10

   local in1P,in1H

   local P = orion.tap(orion.type.int(32), "Peak")
   local H = orion.tap(orion.type.int(32), "Hyst")
   orion.setTap( P , 3000 )
   orion.setTap( H , 1000 ) 

   local I_0 = orion.tap( orion.type.uint(16) , "Red_to_Lum" )
   local I_1 = orion.tap( orion.type.uint(16) , "Green_to_Lum" )
   local I_2 = orion.tap( orion.type.uint(16) , "Blue_to_Lum" )  
   orion.setTap( I_0 , I[1] )
   orion.setTap( I_1 , I[2] )
   orion.setTap( I_2 , I[3] )

   local G_0 = orion.tap( orion.type.uint(16) , "G0" )
   local G_1 = orion.tap( orion.type.uint(16) , "G1" )
   local G_2 = orion.tap( orion.type.uint(16) , "G2" )  
   local G_3 = orion.tap( orion.type.uint(16) , "G3" )  
   local G_4 = orion.tap( orion.type.uint(16) , "G4" )  
   orion.setTap( G_0 , G[1] )
   orion.setTap( G_1 , G[2] )
   orion.setTap( G_2 , G[3] )
   orion.setTap( G_3 , G[4] )
   orion.setTap( G_4 , G[5] )

   local R = orion.tap( orion.type.uint(16) , "R" )
   orion.setTap( R , 8 )

   local Suppress = orion.tap( orion.type.uint(8) , "SuppressLowPeak" )
   orion.setTap( Suppress , 1 )

   in1 = convertToIllum( I_0 , I_1 , I_2 ,in1 )            -- Convert to illuminance, Implied up shift by 8 bits 
   in1 = convolve_1_5_( G_0 , G_1 , G_2 , G_3 , G_4 , R , in1 ) -- 1x5 Gauss
   in1 = convolve_5_1_( G_0 , G_1 , G_2 , G_3 , G_4 , R , in1 ) -- 5x1 Gauss
   in1 = sobel( 8 , in1 )                     -- Sobel
   in1 = nms( 8 , P , H , in1 )  -- Non Maximal Suppression

   for i=1,(N/5)-1 do 
      in1 = hyst( in1 , true )
   end

   --Convert to single kernel that calculates magnitude as well

   -- in1 = convertToChar( 8 , in1 )  -- Down shift by 8 bits and convert to uint8
   -- in1 = convertTo3Char( 8 , in1_t )
   -- in1 = convertToPeakImage( in1P , in1H  )
   -- in1 = convertToPeakImage2( in1P )
   -- in1 = convertToPeakImage2( in1 )

   in1 = convertToPeakImage3( in1 , Suppress )

   return in1 
end


buildRun(  canny(sensor) , opts["i"]  )