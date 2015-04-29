

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

os.execute("mkdir -p orion_out")
InpImg = _CONVGEN .. "/imgs/Lenna_256.jjm"
--InpImg = "/nobackup/jbrunhav/images/pExamples/bonsai_1280x720.jjm"

local width  = 256
local height = 256



local n   = 4 -- should be 2,4,8,16, was 8
local nl2 = 2 -- should be 1,2,3,4, was 3
local nm  = 3 -- should be 1,3,7,15, was 7
local r   = 6 -- Should be ten, was 10
local a1  = 64
local a2  = 128
local s   = 256
local sl2 = 8




opts = getopt( arg , "i" )

if not opts["i"] then
   opts["i"] = InpImg
end

sensor = orion.load( opts["i"] )


function colorSpaceAndSetup( in1 , n , nl2 , nm )


   local im setup(x,y) : cropSame ,  uint8[10]
   let 

   myR = in1(x,y)[0] -- This Pixel's Red
   myG = in1(x,y)[1] -- This Pixel's Green
   myB = in1(x,y)[2] -- This Pixel's Blue
   
   myX_off = 0 -- If this is centroid, x offset of centroid position
   myY_off = 0 -- If this is centroid, y offset of centroid poition
   
   myRc = if (x&nm)==0 and (y&nm)==0 then myR else 0 end -- If this is centroid, mean R pixel of cluster 
   myGc = if (x&nm)==0 and (y&nm)==0 then myG else 0 end -- If this is centroid, mean G pixel of cluster 
   myBc = if (x&nm)==0 and (y&nm)==0 then myB else 0 end -- If this is centroid, mean B pixel of cluster 
   
   myLx = if (x&nm)==0 and (y&nm)==0 then orion.uint8( x >>nl2) else 0 end -- The label for this pixel to a centroid
   myLy = if (x&nm)==0 and (y&nm)==0 then orion.uint8( y >>nl2) else 0 end -- The label for this pixel to a centroid

   in ( { myR , myG , myB , myX_off , myY_off , myRc , myGc , myBc , myLx , myLy } ) 
   end

   return setup

end 



function label( in1 , n , nl2 , nm ) 

   local im labeling(x,y) : cropSame , uint8[10]
   let 

   --in1 = orion.array10int16( in1 ) 

   -- Find our relevant cluster centers 
   c_0 = orion.array10int16( orion.gather( in1(x,y) ,   -((x&nm))  ,   -((y&nm))  , n , n , false  ))
   c_1 = orion.array10int16( orion.gather( in1(x,y) ,   -((x&nm))  , (n-((y&nm))) , n , n , false  ))
   c_2 = orion.array10int16( orion.gather( in1(x,y) , (n-((x&nm))) ,   -((y&nm))  , n , n , false  ))
   c_3 = orion.array10int16( orion.gather( in1(x,y) , (n-((x&nm))) , (n-((y&nm))) , n , n , false  ))
   p   = orion.array10int16( in1( x,y ) )

   -- What are the label for these centers
   l_0 = orion.array2uint8( { ( x-((x&nm))    ) >> nl2 , ( y-((y&nm))    ) >> nl2 } )
   l_1 = orion.array2uint8( { ( x-((x&nm))    ) >> nl2 , ( y+(n-((y&nm)))) >> nl2 } )
   l_2 = orion.array2uint8( { ( x+(n-((x&nm)))) >> nl2 , ( y-((y&nm))    ) >> nl2 } )
   l_3 = orion.array2uint8( { ( x+(n-((x&nm)))) >> nl2 , ( y+(n-((y&nm)))) >> nl2 } )

   -- Calculate the distance components
   d_0 = orion.array5int16({ c_0[5] - p[0] ,
			     c_0[6] - p[1] ,
			     c_0[7] - p[2] ,
			     c_0[3] - ( (x&nm) ) ,  
			     c_0[4] - ( (y&nm) )       })
   d_1 = orion.array5int16({ c_1[5] - p[0] ,
	        	     c_1[6] - p[1] ,
			     c_1[7] - p[2] ,
			     c_1[3] - ( (x&nm) ) ,  
			     c_1[4] - ( (y&nm) - n )   } )
   d_2 = orion.array5int16({ c_2[5] - p[0] ,
			     c_2[6] - p[1] ,
			     c_2[7] - p[2] ,
			     c_2[3] - ( (x&nm) - n ) ,  
			     c_2[4] - ( (y&nm) )       } )
   d_3 = orion.array5int16({ c_3[5] - p[0] ,
			     c_3[6] - p[1] ,
			     c_3[7] - p[2] ,
			     c_3[3] - ( (x&nm) - n ) ,  
			     c_3[4] - ( (y&nm) - n )   })

   -- Calculate distance squared components 
   dd_0 =  orion.array5int16( { d_0[0] * d_0[0] , d_0[1] * d_0[1] , d_0[2] * d_0[2] , d_0[3] * d_0[3] , d_0[4] * d_0[4] } )
   dd_1 =  orion.array5int16( { d_1[0] * d_1[0] , d_1[1] * d_1[1] , d_1[2] * d_1[2] , d_1[3] * d_1[3] , d_1[4] * d_1[4] } )
   dd_2 =  orion.array5int16( { d_2[0] * d_2[0] , d_2[1] * d_2[1] , d_2[2] * d_2[2] , d_2[3] * d_2[3] , d_2[4] * d_2[4] } )
   dd_3 =  orion.array5int16( { d_3[0] * d_3[0] , d_3[1] * d_3[1] , d_3[2] * d_3[2] , d_3[3] * d_3[3] , d_3[4] * d_3[4] } )
   
   -- Sum for the distance squared 
   --ddd_0 = orion.sum( dd_0[0],dd_0[1],dd_0[2],dd_0[3],dd_0[4] )
   --ddd_1 = orion.sum( dd_1[0],dd_1[1],dd_1[2],dd_1[3],dd_1[4] )
   --ddd_2 = orion.sum( dd_2[0],dd_2[1],dd_2[2],dd_2[3],dd_2[4] )
   --ddd_3 = orion.sum( dd_3[0],dd_3[1],dd_3[2],dd_3[3],dd_3[4] )
   ddd_0 = orion.int16( orion.sum( dd_0[0] , dd_0[1] , dd_0[2] , ( dd_0[3] + dd_0[4] ) * ( 256 / (n<<4) ) ) )
   ddd_1 = orion.int16( orion.sum( dd_1[0] , dd_1[1] , dd_1[2] , ( dd_1[3] + dd_1[4] ) * ( 256 / (n<<4) ) ) )
   ddd_2 = orion.int16( orion.sum( dd_2[0] , dd_2[1] , dd_2[2] , ( dd_2[3] + dd_2[4] ) * ( 256 / (n<<4) ) ) )
   ddd_3 = orion.int16( orion.sum( dd_3[0] , dd_3[1] , dd_3[2] , ( dd_3[3] + dd_3[4] ) * ( 256 / (n<<4) ) ) )

   sel_0 = ddd_0 <= ddd_1 and ddd_0 <= ddd_2 and ddd_0 <= ddd_3
   sel_1 = ddd_1 <  ddd_0 and ddd_1 <= ddd_2 and ddd_1 <  ddd_3
   sel_2 = ddd_2 <  ddd_1 and ddd_2 <  ddd_0 and ddd_2 <= ddd_3

   myR = in1(x,y)[0]
   myG = in1(x,y)[1]
   myB = in1(x,y)[2]

   myX_off = in1(x,y)[3]
   myY_off = in1(x,y)[4]

   myRc = in1(x,y)[5]
   myGc = in1(x,y)[6]
   myBc = in1(x,y)[7]
   
   myLx = if sel_0 then l_0[0] else 
           if sel_1 then l_1[0] else
            if sel_2 then l_2[0] else
                           l_3[0]
            end
           end
          end
   --myLx2 = if (x&nm)==0 and (y&nm)==0 then in1(x,y)[8] else myLx end
   myLx2 = myLx

   myLy = if sel_0 then l_0[1] else 
           if sel_1 then l_1[1] else
            if sel_2 then l_2[1] else
                           l_3[1]
            end
           end
          end
   --myLy2 = if (x&nm)==0 and (y&nm)==0 then in1(x,y)[9] else myLy end
   myLy2 = myLy

   in { myR , myG , myB , myX_off , myY_off , myRc , myGc , myBc , myLx2 , myLy2 }
   end 
    
   return labeling

end



function estimate( in1 , n , nl2 , nm ) 


  -- Accumulate RGB X Y  that match the label for this cluster center
  local im out0(x,y) : cropNone , int16[6]
    map ii=-n,n jj=-n,n reduce( sum )
    if  ( (x&nm)==0 and (y&nm)==0 and (x>>nl2)==in1(x+ii,y+jj)[8] and (y>>nl2)==in1(x+ii,y+jj)[9] ) 
        then
	   orion.array6int16({in1(x+ii,y+jj)[0],in1(x+ii,y+jj)[1],in1(x+ii,y+jj)[2],ii,jj,1}) else orion.array6int16({0,0,0,0,0,0}) end  
    end
  end 

  local im estimate(x,y) : cropSame , uint8[10]
  let 
   
   myR = in1(x,y)[0]
   myG = in1(x,y)[1]
   myB = in1(x,y)[2]

   den = orion.int16( if (out0(x,y)[5]~=0 ) then out0(x,y)[5] else 1 end )

   myX_off = if ( (x&nm)==0 and (y&nm)==0 and out0(x,y)[5]~=0 ) then orion.int16( out0(x,y)[3] / den ) else 0 end
   myY_off = if ( (x&nm)==0 and (y&nm)==0 and out0(x,y)[5]~=0 ) then orion.int16( out0(x,y)[4] / den ) else 0 end

   myRc = if ( (x&nm)==0 and (y&nm)==0 ) then 
            if (out0(x,y)[5]~=0 ) then   
	       orion.int16(out0(x,y)[0] / den)
            else 
              myR 
            end
          else
            0 
          end
   myGc = if ( (x&nm)==0 and (y&nm)==0 ) then 
            if (out0(x,y)[5]~=0 ) then   
              out0(x,y)[1] / den 
            else 
              myG 
            end
          else
            0 
          end
   myBc = if ( (x&nm)==0 and (y&nm)==0 ) then 
            if (out0(x,y)[5]~=0 ) then   
              out0(x,y)[2] / den 
            else 
              myB 
            end
          else
            0 
          end
  
   myLx = in1(x,y)[8]
   myLy = in1(x,y)[9]

   in  { myR , myG , myB , myX_off , myY_off , myRc , myGc , myBc , myLx , myLy }
   end 

   return estimate

end

local DrawEdge = orion.tap( orion.type.uint(8) , "DrawEdge" )
orion.setTap( DrawEdge , 0 )


function composite( in1 , n , nl2 , nm , a1 , a2 , s , sl2 ) 
--- Composite the cluster color to my color using a1, if I am an edge use a2 

   local im composite(x,y) : cropSame , uint8[3]
   let 

   -- Find our relevant centers 
   c_0 = orion.gather( in1(x,y) ,   -((x&nm))  ,   -((y&nm))  , n , n , false  )
   c_1 = orion.gather( in1(x,y) ,   -((x&nm))  , (n-((y&nm))) , n , n , false  )
   c_2 = orion.gather( in1(x,y) , (n-((x&nm))) ,   -((y&nm))  , n , n , false  )
   c_3 = orion.gather( in1(x,y) , (n-((x&nm))) , (n-((y&nm))) , n , n , false  )
   p   = in1( x   , y   )
   u   = in1( x   , y+1 )
   d   = in1( x   , y-1 )
   l   = in1( x-1 , y   )
   r   = in1( x+1 , y   )

   l_0 = orion.array2uint8( { ( x-((x&nm))    ) >> nl2 , ( y-((y&nm))    ) >> nl2 } )
   l_1 = orion.array2uint8( { ( x-((x&nm))    ) >> nl2 , ( y+(n-((y&nm)))) >> nl2 } )
   l_2 = orion.array2uint8( { ( x+(n-((x&nm)))) >> nl2 , ( y-((y&nm))    ) >> nl2 } )
   l_3 = orion.array2uint8( { ( x+(n-((x&nm)))) >> nl2 , ( y+(n-((y&nm)))) >> nl2 } )

   sel_0 = l_0[0]==p[8] and l_0[1]==p[9]
   sel_1 = l_1[0]==p[8] and l_1[1]==p[9]
   sel_2 = l_2[0]==p[8] and l_2[1]==p[9]
   sel_3 = l_3[0]==p[8] and l_3[1]==p[9]

--   edge = u[8]~=p[8] or u[9]~=p[9] or 
--          d[8]~=p[8] or d[9]~=p[9] or 
--          r[8]~=p[8] or r[9]~=p[9] or 
--          l[8]~=p[8] or l[9]~=p[9]  
   edge = u[8]~=p[8] or u[9]~=p[9] or 
          r[8]~=p[8] or r[9]~=p[9] 

--   a = if edge then a2 else a1 end 

   myCc = orion.vectorSelect( { sel_0, sel_0, sel_0 } , { c_0[5] ,c_0[6] ,c_0[7] } , 
           orion.vectorSelect( { sel_1, sel_1, sel_1 } , { c_1[5] ,c_1[6] ,c_1[7] } ,
            orion.vectorSelect( { sel_2, sel_2, sel_2 } , { c_2[5] ,c_2[6] ,c_2[7] } ,
             orion.vectorSelect(  { sel_3, sel_3, sel_3 } , { c_3[5] ,c_3[6] ,c_3[7] } ,
				  { 255 , 0 , 0 } ))))
 
-- TODO -> Add tap to let you change edge color
-- TODO -> Add tap to let you turn on centroid color 

--   myR = if edge then 255 else ( myCc[0] * a + ( s - a ) * p[0] ) >> sl2 end
--   myG = if edge then   0 else ( myCc[1] * a + ( s - a ) * p[1] ) >> sl2 end
--   myB = if edge then   0 else ( myCc[1] * a + ( s - a ) * p[2] ) >> sl2 end

-- use tap to let you turn edges off
   myR = if (edge and DrawEdge==1) then 255 else  myCc[0] end
   myG = if (edge and DrawEdge==1) then 255 else  myCc[1] end
   myB = if (edge and DrawEdge==1) then 255 else  myCc[2] end

   in  { myR , myG , myB }
   end

   return composite

end



function kmeans( in1 )
   
   in1 = colorSpaceAndSetup( in1 , n , nl2 , nm )

   for i=1,r do
      in1 = label( in1 , n , nl2 , nm ) 
      in1 = estimate( in1 , n , nl2 , nm ) 
   end

   in1 = composite( in1 , n , nl2 , nm , a1 , a2 , s , sl2 ) 

   return in1 

end

function kmeansPre( in1 )
   return colorSpaceAndSetup( in1 , n , nl2  , nm)
end

function kmeansIter1( in1 )
   in1 = label( in1 , n , nl2 , nm ) 
   return in1 
end

function kmeansIter2( in1 )
   in1 = estimate( in1 , n , nl2 , nm ) 
   return in1 
end

function kmeansFinal( in1 ) 
   return composite( in1 , n , nl2 , nm , a1 , a2 , s , sl2 ) 
end

-- HW --
print "Compiling for HW"
local yfile,yrfile = orion.compile({kmeans(sensor)},{verbose=false,debug=false,platform="convolution", printruntime=true,fastmath=false})
print "Finished Compiling for HW"    

local file = io.open("orion_out/conv.yml","w")
file:write(yfile)
file:close()
   
-- hack
local rfile = io.open("orion_out/conv_run.yml","w")
rfile:write("test_top:\n")
rfile:write("   inputImages: \n") 
rfile:write("      special0: src-Stencil-Path/experiments/2014_03_19_HierFlow/SLIC_orion/orion_out/inp.jjm\n" )
rfile:write("   bindings: \n")
rfile:write("      DEFAULT: src-Stencil-Path/experiments/2014_03_19_HierFlow/SLIC_orion/orion_out/out.jjm\n" )
rfile:write("   taps: []\n") 
   
rfile:write(yrfile)
rfile:close()   
-- HW --

local frame0 = orion.image(orion.type.array(orion.type.uint(8),3),width,height)
local frame1 = orion.image(orion.type.array(orion.type.uint(8),10),width,height)
local frame2 = orion.image(orion.type.array(orion.type.uint(8),10),width,height)
local frame3 = orion.image(orion.type.array(orion.type.uint(8),10),width,height)

local frame0id = frame0:id()
local frame1id = frame1:id()
local frame2id = frame2:id()
local frame3id = frame3:id()

print "Compiling for SW"
init  = orion.compile( {kmeansPre(   im(x,y): uint8[3] , cropSame frame0(x,y) end ) } , {schedule="materialize",debug=false, verbose=false,fastmath=false})
iter1 = orion.compile( {kmeansIter1( im(x,y): uint8[10] , cropSame frame1(x,y) end )} , {schedule="materialize",debug=false, verbose=false,fastmath=false})
iter2 = orion.compile( {kmeansIter2( im(x,y): uint8[10] , cropSame frame2(x,y) end )} , {schedule="materialize",debug=false, verbose=false,fastmath=false})
final = orion.compile( {kmeansFinal( im(x,y): uint8[10] , cropSame frame3(x,y) end )} , {schedule="materialize",debug=false, verbose=false,fastmath=false})
print "Finished compiling for SW"

terra j_run()
  -- 
  -- 

  -- Init Input 
  var frame0_tr = [&Image](cstdlib.malloc(sizeof(Image)))
  frame0_tr:initWithFile( InpImg )

  orion.bindImage( frame0id , frame0_tr )
  var iter1Image = init()

  orion.bindImage( frame1id , &iter1Image )  
  var iter2Image = iter1()
  orion.bindImage( frame2id , &iter2Image )  
  iter1Image = iter2()

  for i=0,r do
     orion.bindImage( frame1id , &iter1Image )  
     iter2Image = iter1()
     orion.bindImage( frame2id , &iter2Image )  
     iter1Image = iter2()
  end

  orion.bindImage( frame3id , &iter1Image )
  
  var finImage = final()
  finImage:flip()
  finImage:save("orion_out/out.bmp")
  frame0_tr:flip()
  frame0_tr:save("orion_out/inp.bmp")
end

j_run()

--local runit = orion.compile({kmeans(sensor)},{verbose=true,debug=false,printruntime=true})
--local terra j_run()
--  var res = runit()
--  res:save("orion_out/out.bmp")
--end
--j_run()
