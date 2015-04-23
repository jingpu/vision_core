-- dpc block

import "orion"

-- import definitions and global settings
terralib.require("defs")
terralib.require("settings")

-- add local block settings
settings.dpc 				= {}
settings.dpc.bypass 		= 0;
settings.dpc.inBitRes		= 10;
settings.dpc.procBitRes	= 10;
settings.dpc.outBitRes	= 10;
settings.dpc.edgeThrHigh	= tap(oUint(settings.dpc.procBitRes),176,"dpc_edgeThrHigh"); 	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.dpc.edgeThrLow	= tap(oUint(settings.dpc.procBitRes),36,"dpc_edgeThrLow"); 	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.dpc.decisionThr	= tap(oUint(settings.dpc.procBitRes),20,"dpc_decisionThr"); 	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.dpc.hotPixThr	= tap(oUint(settings.dpc.procBitRes),8,"dpc_hotPixThr"); 	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.dpc.coldPixThr	= tap(oUint(settings.dpc.procBitRes),8,"dpc_coldPixThr"); 	-- procBitRes bits [0..(1 << procBitRes)-1]
settings.dpc.maxDiffRes	= tap(oUint(4),4,"dpc_maxDiffRes"); 	-- 4 bits [0..15]
settings.dpc.hotPixFctr	= tap(oUint(4),8,"dpc_hotPixFctr"); 	-- 4 bits [0..15]
settings.dpc.coldPixFctr	= tap(oUint(4),8,"dpc_coldPixFctr"); 	-- 4 bits [0..15]

function dpc(inImg)

  local uull = im(x,y) : cropNone inImg(x-2,y-2) end
  local uul = im(x,y) : cropNone inImg(x-1,y-2) end
  local uu = im(x,y) : cropNone inImg(x,y-2) end
  local uur = im(x,y) : cropNone inImg(x+1,y-2) end
  local uurr = im(x,y) : cropNone inImg(x+2,y-2) end

  local ull = im(x,y) : cropNone inImg(x-2,y-1) end
  local ul = im(x,y) : cropNone inImg(x-1,y-1) end
  local u = im(x,y) : cropNone inImg(x,y-1) end
  local ur = im(x,y) : cropNone inImg(x+1,y-1) end
  local urr = im(x,y) : cropNone inImg(x+2,y-1) end

  local ll = im(x,y) : cropNone inImg(x-2,y) end
  local l = im(x,y) : cropNone inImg(x-1,y) end
  local c = im(x,y) : cropNone inImg(x,y) end
  local r = im(x,y) : cropNone inImg(x+1,y) end
  local rr = im(x,y) : cropNone inImg(x+2,y) end

  local dll = im(x,y) : cropNone inImg(x-2,y+1) end
  local dl = im(x,y) : cropNone inImg(x-1,y+1) end
  local d = im(x,y) : cropNone inImg(x,y+1) end
  local dr = im(x,y) : cropNone inImg(x+1,y+1) end
  local drr = im(x,y) : cropNone inImg(x+2,y+1) end

  local ddll = im(x,y) : cropNone inImg(x-2,y+2) end
  local ddl = im(x,y) : cropNone inImg(x-1,y+2) end
  local dd = im(x,y) : cropNone inImg(x,y+2) end
  local ddr = im(x,y) : cropNone inImg(x+1,y+2) end
  local ddrr = im(x,y) : cropNone inImg(x+2,y+2) end

	local function calcDiffFromGrad()
		return im(x,y) : cropNone
			let 
      vGrad = orion.abs(uul-l)+orion.abs(ul-dl)+orion.abs(l-ddl)+
        orion.abs(uu-c)+orion.abs(u-d)+orion.abs(c-dd)+
        orion.abs(uur-r)+orion.abs(ur-dr)+orion.abs(r-ddr);

      hGrad = orion.abs(ull-u)+orion.abs(ul-ur)+orion.abs(u-urr)+
        orion.abs(ll-c)+orion.abs(l-r)+orion.abs(c-rr)+
        orion.abs(dll-d)+orion.abs(dl-dr)+orion.abs(d-drr);

				meanVal = 
					if (vGrad < settings.dpc.edgeThrLow and hGrad > settings.dpc.edgeThrHigh) 
					then 
						(uu+dd+1)>>1
					else
						if (hGrad < settings.dpc.edgeThrLow and vGrad > settings.dpc.edgeThrHigh)
						then
							(ll+rr+1)>>1
						else
							0
            end
					end
				maxVal = 
					if (vGrad < settings.dpc.edgeThrLow and hGrad > settings.dpc.edgeThrHigh) 
					then 
						orion.max(uu,dd)
					else
						if (hGrad < settings.dpc.edgeThrLow and vGrad > settings.dpc.edgeThrHigh)
						then
							orion.max(ll,rr)
						else
							0
            end
					end
				minGradDiff = 
					if (vGrad < settings.dpc.edgeThrLow and hGrad > settings.dpc.edgeThrHigh) 
					then 
						orion.min(hGrad-settings.dpc.edgeThrHigh, settings.dpc.edgeThrLow-vGrad, 1 << settings.dpc.maxDiffRes)
					else
						if (hGrad < settings.dpc.edgeThrLow and vGrad > settings.dpc.edgeThrHigh)
						then
							orion.min(vGrad-settings.dpc.edgeThrHigh, settings.dpc.edgeThrLow-hGrad, 1 << settings.dpc.maxDiffRes)
						else
							0
            end
					end
				
				diffVal1 = 
					if (c > maxVal+settings.dpc.decisionThr)
					then
						orion.max(meanVal, 2*maxVal+settings.dpc.decisionThr-inImg(x,y))
					else
						inImg(x,y)
					end
					
				diffVal2 = 
					if (meanVal == 0)
					then
						0
					else
						((diffVal1*minGradDiff + ((1 << settings.dpc.maxDiffRes)-minGradDiff)*inImg(x,y)) >> settings.dpc.maxDiffRes)-inImg(x,y)
          end
				in diffVal2
     end
	end

	local diff = calcDiffFromGrad();

	local function localWB()
		local im mean1(x,y) : cropNone 
    defs.maxPix - (uull+uu+uurr+ll+rr+ddll+dd+ddrr+4)/8
				end					
		local im mean2(x,y) : cropNone 
    defs.maxPix - (uul+uur+l+r+ddl+ddr-orion.max(uul, uur, l, r, ddl, ddr)-orion.min(uul, uur, l, r, ddl, ddr)+2)/4
				end
		local im mean3(x,y) : cropNone 
    defs.maxPix - (ull+u+urr+dll+d+drr-orion.max(ull, u, urr, dll, d, drr)-orion.min(ull, u, urr, dll, d, drr)+2)/4
				end
		local im mean4(x,y) : cropNone 
    defs.maxPix - (ul+ur+dl+dr)/4
				end
		return
			im uu(x,y) : cropNone 
				uu + mean1(x,y)
			end,
			im ll(x,y) : cropNone 
        ll + mean1(x,y)
			end,
			im dd(x,y) : cropNone 
				dd + mean1(x,y)
			end,
			im rr(x,y) : cropNone
				rr + mean1(x,y)
			end,
			im c(x,y) : cropNone 
				c + mean1(x,y)
			end,
			im l(x,y) : cropNone 
				l + mean2(x,y)
			end,
			im r(x,y) : cropNone 
				r + mean2(x,y)
			end,
			im u(x,y) : cropNone 
				u + mean3(x,y)
			end,
			im d(x,y) : cropNone 
				d + mean3(x,y)
			end,
			im ul(x,y) : cropNone 
				ul + mean4(x,y)
			end,
			im ur(x,y) : cropNone 
				ur + mean4(x,y)
			end,
			im dl(x,y) : cropNone 
				dl + mean4(x,y)
			end,
			im dr(x,y) : cropNone 
				dr + mean4(x,y)
			end,
			mean1
	end
	
	local uu,ll,dd,rr,c,l,r,u,d,ul,ur,dl,dr, meanVal = localWB();
	
	return im dpc(x,y): cropSame , int32
 	let
    localMax = orion.max(uu(x,y), ul(x,y), ll(x,y), dl(x,y), dd(x,y), dr(x,y), rr(x,y), ur(x,y), u(x,y), l(x,y), d(x,y), r(x,y));
		localMin = orion.min(uu(x,y), ul(x,y), ll(x,y), dl(x,y), dd(x,y), dr(x,y), rr(x,y), ur(x,y), u(x,y), l(x,y), d(x,y), r(x,y));
		
		thrCold = settings.dpc.coldPixThr + (settings.dpc.coldPixFctr*(localMax-localMin) >> 4);
		thrHot	= settings.dpc.hotPixThr + (settings.dpc.hotPixFctr*(localMax-localMin) >> 4);
		
		corrVal = 
			if c > localMax+thrHot
			then
				orion.max(2*(localMax+thrHot)-c, localMax)
			else
				if (c < localMin-thrCold)
				then
				   orion.min(2*(localMin-thrCold)-c, localMin)
				else
				   c
				end
			end

			diff2 = corrVal-c;
			finalDiff = 
				if (defs.sign(diff2) ~= defs.sign(diff(x,y)))
				then
					diff(x,y)+diff2
				else
					if (defs.sign(diff(x,y)) == 1)
					then
						orion.max(diff(x,y), diff2)
					else
						orion.min(diff(x,y), diff2)
					end
				end
        in defs.clip(c-meanVal(x,y)+finalDiff, 0, defs.maxPix)
  end
end	