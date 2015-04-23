
-- common settings

-- some general definitions 
RGB 		= 0
GRBG 		= 1
GBRG 		= 2
RGGB 		= 3
BGGR 		= 4
GR 			= 0
GB 			= 1
B 			= 2
R 			= 3

settings={}
settings.byrFormat    	= GRBG;

settings.dem = {}
settings.dem.dirThr = 0;
settings.dem.wg = 128;
settings.dem.wc = 16;
settings.ct8 = {}
settings.ct8.inBitRes = 10
settings.ct8.outBitRes = 8
settings.ccm = {}
settings.ccm.colorSat    = 256;
settings.ccm.avgColorsFlag = true;
settings.ccm.ccmMat = {}
settings.ccm.ccmMat[0]   = 378;
settings.ccm.ccmMat[1]   = -53;
settings.ccm.ccmMat[2]   = -69;
settings.ccm.ccmMat[3]   = -9;
settings.ccm.ccmMat[4]   = 350;
settings.ccm.ccmMat[5]   = -85;
settings.ccm.ccmMat[6]   = -19;
settings.ccm.ccmMat[7]   = -182;
settings.ccm.ccmMat[8]   = 457;
settings.dpc = {}
settings.dpc.format= GRBG;
settings.dpc.edgeThrHigh = 176;
settings.dpc.edgeThrLow= 36;
settings.dpc.decisionThr= 20;
settings.dpc.maxDiffRes= 4;
settings.dpc.hotPixThr= 40;
settings.dpc.coldPixThr= 40;
settings.dpc.hotPixFctr= 8;
settings.dpc.coldPixFctr= 8;

