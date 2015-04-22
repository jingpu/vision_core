
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
--InpImg = _CONVGEN .. "/imgs/Lenna_256.ppm"
--InpImg = "/nobackup/jbrunhav/images/pExamples/bonsai_1280x720.ppm"

opts = getopt( arg , "i" )

if not opts["i"] then
   opts["i"] = InpImg
end

os.execute( "mkdir orion_out" )
sensor = orion.load( opts["i"] )
sensor:save( "orion_out/inp.bmp" )


function convertToIllum( I_0 , I_1 , I_2 , in1 )
   im in1( x,y )  : cropNone , int16[3] in1(x,y) end 
   im in1( x,y )  : cropNone , int16    orion.sum( in1(x,y)[0]*I_0 , in1(x,y)[1]*I_1 , in1(x,y)[2]*I_2 ) >> 8 end 
   return im(x,y) : cropSame , int16    in1(x,y)  end 
end


function shift( h )
   local im h2(x,y): cropNone , bool[16] { h(x,y)[1]  , h(x,y)[2]  , h(x,y)[3]  , h(x,y)[4]  , 
                                           h(x,y)[5]  , h(x,y)[6]  , h(x,y)[7]  , h(x,y)[8]  , 
                                           h(x,y)[9]  , h(x,y)[10] , h(x,y)[11] , h(x,y)[12] , 
                                           h(x,y)[13] , h(x,y)[14] , h(x,y)[15] , h(x,y)[0] } end
   return h2 
end

function seq( N , h )

   local im h2(x,y): cropNone , bool[16] h(x,y) end 

   for i=0,N do
      h = shift( h ) 
      im h2(x,y): cropNone , bool[16] { h2(x,y)[0]  and h(x,y)[0]  ,  h2(x,y)[1]  and h(x,y)[1] , 
                                        h2(x,y)[2]  and h(x,y)[2]  ,  h2(x,y)[3]  and h(x,y)[3] , 
                                        h2(x,y)[4]  and h(x,y)[4]  ,  h2(x,y)[5]  and h(x,y)[5] , 
                                        h2(x,y)[6]  and h(x,y)[6]  ,  h2(x,y)[7]  and h(x,y)[7] , 
                                        h2(x,y)[8]  and h(x,y)[8]  ,  h2(x,y)[9]  and h(x,y)[9] , 
                                        h2(x,y)[10] and h(x,y)[10] ,  h2(x,y)[11] and h(x,y)[11] , 
                                        h2(x,y)[12] and h(x,y)[12] ,  h2(x,y)[13] and h(x,y)[13] , 
                                        h2(x,y)[14] and h(x,y)[14] ,  h2(x,y)[15] and h(x,y)[15] } end                               
   end		     

   return h2

end


function fast( K1 , K2 , in1 )
   -- Create the circle of 16 pixels
   local im c(x,y) : cropNone , int16[16] { in1(x+2,y+2) , in1(x+3,y+1) , in1(x+3,y+0) , in1(x+3,y-1) ,
				            in1(x+2,y-2) , in1(x+1,y-3) , in1(x+0,y-3) , in1(x-1,y-3) ,
					    in1(x-2,y-2) , in1(x-3,y-1) , in1(x-3,y+0) , in1(x-3,y+1) ,
					    in1(x-2,y+2) , in1(x-1,y+3) , in1(x+0,y+3) , in1(x+1,y+3) } end 
   -- Subtract the center pixel from the ring
   local im d(x,y) : cropNone , int16[16] { c(x,y)[0] -in1(x,y),c(x,y)[1] -in1(x,y),c(x,y)[2] -in1(x,y),c(x,y)[3] -in1(x,y), 
                                            c(x,y)[4] -in1(x,y),c(x,y)[5] -in1(x,y),c(x,y)[6] -in1(x,y),c(x,y)[7] -in1(x,y), 
                                            c(x,y)[8] -in1(x,y),c(x,y)[9] -in1(x,y),c(x,y)[10]-in1(x,y),c(x,y)[11]-in1(x,y), 
                                            c(x,y)[12]-in1(x,y),c(x,y)[13]-in1(x,y),c(x,y)[14]-in1(x,y),c(x,y)[15]-in1(x,y) } end 
   -- Determine if the difference is greater or lower than the threshold
   local im h(x,y) : cropNone , bool[16] { d(x,y)[0]  > K1 , d(x,y)[1]  > K1 , d(x,y)[2]  > K1 ,d(x,y)[3]  > K1 , 
                                           d(x,y)[4]  > K1 , d(x,y)[5]  > K1 , d(x,y)[6]  > K1 ,d(x,y)[7]  > K1 , 
                                           d(x,y)[8]  > K1 , d(x,y)[9]  > K1 , d(x,y)[10] > K1 ,d(x,y)[11] > K1 , 
                                           d(x,y)[12] > K1 , d(x,y)[13] > K1 , d(x,y)[14] > K1 ,d(x,y)[15] > K1 } end 
   local im l(x,y) : cropNone , bool[16] { d(x,y)[0]  < K2 , d(x,y)[1]  < K2 , d(x,y)[2]  < K2 ,d(x,y)[3]  < K2 , 
                                           d(x,y)[4]  < K2 , d(x,y)[5]  < K2 , d(x,y)[6]  < K2 ,d(x,y)[7]  < K2 , 
                                           d(x,y)[8]  < K2 , d(x,y)[9]  < K2 , d(x,y)[10] < K2 ,d(x,y)[11] < K2 , 
                                           d(x,y)[12] < K2 , d(x,y)[13] < K2 , d(x,y)[14] < K2 ,d(x,y)[15] < K2 } end 
   -- See if there is a sequnce of 9 1's 
   h = seq(9,h)
   l = seq(9,l)

   local im fast(x,y) : cropNone , bool ( h(x,y)[0]  or h(x,y)[1]  or h(x,y)[2]  or h(x,y)[3]  or 
                                          h(x,y)[4]  or h(x,y)[5]  or h(x,y)[6]  or h(x,y)[7]  or 
                                          h(x,y)[8]  or h(x,y)[9]  or h(x,y)[10] or h(x,y)[11] or 
                                          h(x,y)[12] or h(x,y)[13] or h(x,y)[14] or h(x,y)[15] or 
                                          l(x,y)[0]  or l(x,y)[1]  or l(x,y)[2]  or l(x,y)[3]  or 
                                          l(x,y)[4]  or l(x,y)[5]  or l(x,y)[6]  or l(x,y)[7]  or 
                                          l(x,y)[8]  or l(x,y)[9]  or l(x,y)[10] or l(x,y)[11] or 
                                          l(x,y)[12] or l(x,y)[13] or l(x,y)[14] or l(x,y)[15] ) end 

   return im(x,y) : cropSame , uint8  if fast(x,y) then 255 else 0 end end
end

function fast9(in1)

   local I  = { 54 , 183 , 18 } 
   local K1 =  16
   local K2 = -16

   local I_0 = orion.tap( orion.type.int(16) , "Red_to_Lum" )
   local I_1 = orion.tap( orion.type.int(16) , "Green_to_Lum" )
   local I_2 = orion.tap( orion.type.int(16) , "Blue_to_Lum" )  
   orion.setTap( I_0 , I[1] )
   orion.setTap( I_1 , I[2] )
   orion.setTap( I_2 , I[3] )

   local K_0 = orion.tap( orion.type.int(16) , "DarkBlob" )
   local K_1 = orion.tap( orion.type.int(16) , "LightBlob" )
   orion.setTap( K_0 , K1 )
   orion.setTap( K_1 , K2 )
   
   in1 = convertToIllum( I_0 , I_1 , I_2 , in1 )            -- Convert to illuminance
   in1 = fast( K_0 , K_1 , in1 )

   return in1 
end


buildRun(  fast9(sensor) , opts["i"]  )