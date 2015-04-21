
void calcDem_3(const Image<vector32>& in, Image<vector32>& out
	, unsigned int tap_dem_wg_0_s
	, unsigned int tap_dem_wc_0_s
	, unsigned int tap_dem_dirThr_0_s
)
{
  // Set up the tap values
  const register vector32 tap_dem_wg_0 = mv16_sv(tap_dem_wg_0_s);
  const register vector32 tap_dem_wc_0 = mv16_sv(tap_dem_wc_0_s);
  const register vector32 tap_dem_dirThr_0 = mv16_sv(tap_dem_dirThr_0_s);
  
  // Set up the constant values
  const register vector32 c_2_0 = mv16_sv(2);
  const register vector32 c_1_0 = mv16_sv(1);
  const register vector32 c_0_0 = mv16_sv(0);
  const register vector32 c_0x1_0 = mv16_sv(0x1);
  const register vector32 c_255_0 = mv16_sv(255);
  const register vector32 c_9_0 = mv16_sv(9);
  const register vector32 c_n9_0 = mv16_sv(-9);
  const register vector32 c_0x0_0 = mv16_sv(0x0);
  const register vector32 c_344_0 = mv16_sv(344);
  const register vector32 c_34_0 = mv16_sv(34);
  const register vector32 c_3_0 = mv16_sv(3);
  const register vector32 c_1023_0 = mv16_sv(1023);
  const register vector32 c_n10_0 = mv16_sv(-10);
  const register vector32 c_n8_0 = mv16_sv(-8);
  const register vector32 c_5_0 = mv16_sv(5);
  const register vector32 c_8_0 = mv16_sv(8);
  
  const vector32 *in_ptr = in.mData; // use direct access to speed up inner loop
  vector32 *out_ptr = out.mData; // use direct access to speed up inner loop
  const int IN_WIDTH = in.width();
  const int IN_HEIGHT = in.height();
  const int IN_CHANNELS = 1; // use static value to allow more compiler optimization
  const int OUT_CHANNELS = 3; /// use static value to allow more compiler optimization
  
  // Turn on SAIF power toggle data capture
  set_power_toggle(POWER_TOGGLE_ON);
  for(int y = 0; y < in.height(); y++){
    // DEBUG: y_min=-3, y_max=3, y_padding_ofst=3
    // declare the registers storing the stencil window
    register vector32 calcWbg_46_pp_6_6;
    register vector32 calcWbg_46_pp_6_5;
    register vector32 calcWbg_46_pp_6_4;
    register vector32 calcWbg_46_pp_6_3;
    register vector32 calcWbg_46_pp_6_2;
    register vector32 calcWbg_46_pp_6_1;
    register vector32 calcWbg_46_pp_6_0;
    register vector32 calcWbg_46_pp_5_6;
    register vector32 calcWbg_46_pp_5_5;
    register vector32 calcWbg_46_pp_5_4;
    register vector32 calcWbg_46_pp_5_3;
    register vector32 calcWbg_46_pp_5_2;
    register vector32 calcWbg_46_pp_5_1;
    register vector32 calcWbg_46_pp_5_0;
    register vector32 calcWbg_46_pp_4_6;
    register vector32 calcWbg_46_pp_4_5;
    register vector32 calcWbg_46_pp_4_4;
    register vector32 calcWbg_46_pp_4_3;
    register vector32 calcWbg_46_pp_4_2;
    register vector32 calcWbg_46_pp_4_1;
    register vector32 calcWbg_46_pp_4_0;
    register vector32 calcWbg_46_pp_3_6;
    register vector32 calcWbg_46_pp_3_5;
    register vector32 calcWbg_46_pp_3_4;
    register vector32 calcWbg_46_pp_3_3;
    register vector32 calcWbg_46_pp_3_2;
    register vector32 calcWbg_46_pp_3_1;
    register vector32 calcWbg_46_pp_3_0;
    register vector32 calcWbg_46_pp_2_6;
    register vector32 calcWbg_46_pp_2_5;
    register vector32 calcWbg_46_pp_2_4;
    register vector32 calcWbg_46_pp_2_3;
    register vector32 calcWbg_46_pp_2_2;
    register vector32 calcWbg_46_pp_2_1;
    register vector32 calcWbg_46_pp_2_0;
    register vector32 calcWbg_46_pp_1_6;
    register vector32 calcWbg_46_pp_1_5;
    register vector32 calcWbg_46_pp_1_4;
    register vector32 calcWbg_46_pp_1_3;
    register vector32 calcWbg_46_pp_1_2;
    register vector32 calcWbg_46_pp_1_1;
    register vector32 calcWbg_46_pp_1_0;
    register vector32 calcWbg_46_pp_0_6;
    register vector32 calcWbg_46_pp_0_5;
    register vector32 calcWbg_46_pp_0_4;
    register vector32 calcWbg_46_pp_0_3;
    register vector32 calcWbg_46_pp_0_2;
    register vector32 calcWbg_46_pp_0_1;
    register vector32 calcWbg_46_pp_0_0;
    
    // load the stencil window for each scan of row
    calcWbg_46_pp_1_6 = in_ptr[(y+6)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -3)*IN_CHANNELS + 0];
    calcWbg_46_pp_1_6 = getl16_vv(calcWbg_46_pp_1_6);
    calcWbg_46_pp_1_5 = in_ptr[(y+5)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -3)*IN_CHANNELS + 0];
    calcWbg_46_pp_1_5 = getl16_vv(calcWbg_46_pp_1_5);
    calcWbg_46_pp_1_4 = in_ptr[(y+4)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -3)*IN_CHANNELS + 0];
    calcWbg_46_pp_1_4 = getl16_vv(calcWbg_46_pp_1_4);
    calcWbg_46_pp_1_3 = in_ptr[(y+3)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -3)*IN_CHANNELS + 0];
    calcWbg_46_pp_1_3 = getl16_vv(calcWbg_46_pp_1_3);
    calcWbg_46_pp_1_2 = in_ptr[(y+2)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -3)*IN_CHANNELS + 0];
    calcWbg_46_pp_1_2 = getl16_vv(calcWbg_46_pp_1_2);
    calcWbg_46_pp_1_1 = in_ptr[(y+1)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -3)*IN_CHANNELS + 0];
    calcWbg_46_pp_1_1 = getl16_vv(calcWbg_46_pp_1_1);
    calcWbg_46_pp_1_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -3)*IN_CHANNELS + 0];
    calcWbg_46_pp_1_0 = getl16_vv(calcWbg_46_pp_1_0);
    calcWbg_46_pp_2_6 = in_ptr[(y+6)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -2)*IN_CHANNELS + 0];
    calcWbg_46_pp_2_6 = getl16_vv(calcWbg_46_pp_2_6);
    calcWbg_46_pp_2_5 = in_ptr[(y+5)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -2)*IN_CHANNELS + 0];
    calcWbg_46_pp_2_5 = getl16_vv(calcWbg_46_pp_2_5);
    calcWbg_46_pp_2_4 = in_ptr[(y+4)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -2)*IN_CHANNELS + 0];
    calcWbg_46_pp_2_4 = getl16_vv(calcWbg_46_pp_2_4);
    calcWbg_46_pp_2_3 = in_ptr[(y+3)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -2)*IN_CHANNELS + 0];
    calcWbg_46_pp_2_3 = getl16_vv(calcWbg_46_pp_2_3);
    calcWbg_46_pp_2_2 = in_ptr[(y+2)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -2)*IN_CHANNELS + 0];
    calcWbg_46_pp_2_2 = getl16_vv(calcWbg_46_pp_2_2);
    calcWbg_46_pp_2_1 = in_ptr[(y+1)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -2)*IN_CHANNELS + 0];
    calcWbg_46_pp_2_1 = getl16_vv(calcWbg_46_pp_2_1);
    calcWbg_46_pp_2_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -2)*IN_CHANNELS + 0];
    calcWbg_46_pp_2_0 = getl16_vv(calcWbg_46_pp_2_0);
    calcWbg_46_pp_3_6 = in_ptr[(y+6)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -1)*IN_CHANNELS + 0];
    calcWbg_46_pp_3_6 = getl16_vv(calcWbg_46_pp_3_6);
    calcWbg_46_pp_3_5 = in_ptr[(y+5)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -1)*IN_CHANNELS + 0];
    calcWbg_46_pp_3_5 = getl16_vv(calcWbg_46_pp_3_5);
    calcWbg_46_pp_3_4 = in_ptr[(y+4)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -1)*IN_CHANNELS + 0];
    calcWbg_46_pp_3_4 = getl16_vv(calcWbg_46_pp_3_4);
    calcWbg_46_pp_3_3 = in_ptr[(y+3)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -1)*IN_CHANNELS + 0];
    calcWbg_46_pp_3_3 = getl16_vv(calcWbg_46_pp_3_3);
    calcWbg_46_pp_3_2 = in_ptr[(y+2)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -1)*IN_CHANNELS + 0];
    calcWbg_46_pp_3_2 = getl16_vv(calcWbg_46_pp_3_2);
    calcWbg_46_pp_3_1 = in_ptr[(y+1)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -1)*IN_CHANNELS + 0];
    calcWbg_46_pp_3_1 = getl16_vv(calcWbg_46_pp_3_1);
    calcWbg_46_pp_3_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (IN_WIDTH -1)*IN_CHANNELS + 0];
    calcWbg_46_pp_3_0 = getl16_vv(calcWbg_46_pp_3_0);
    calcWbg_46_pp_4_6 = in_ptr[(y+6)*IN_WIDTH*IN_CHANNELS + (0)*IN_CHANNELS + 0];
    calcWbg_46_pp_4_5 = in_ptr[(y+5)*IN_WIDTH*IN_CHANNELS + (0)*IN_CHANNELS + 0];
    calcWbg_46_pp_4_4 = in_ptr[(y+4)*IN_WIDTH*IN_CHANNELS + (0)*IN_CHANNELS + 0];
    calcWbg_46_pp_4_3 = in_ptr[(y+3)*IN_WIDTH*IN_CHANNELS + (0)*IN_CHANNELS + 0];
    calcWbg_46_pp_4_2 = in_ptr[(y+2)*IN_WIDTH*IN_CHANNELS + (0)*IN_CHANNELS + 0];
    calcWbg_46_pp_4_1 = in_ptr[(y+1)*IN_WIDTH*IN_CHANNELS + (0)*IN_CHANNELS + 0];
    calcWbg_46_pp_4_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (0)*IN_CHANNELS + 0];
    calcWbg_46_pp_5_6 = in_ptr[(y+6)*IN_WIDTH*IN_CHANNELS + (1)*IN_CHANNELS + 0];
    calcWbg_46_pp_5_5 = in_ptr[(y+5)*IN_WIDTH*IN_CHANNELS + (1)*IN_CHANNELS + 0];
    calcWbg_46_pp_5_4 = in_ptr[(y+4)*IN_WIDTH*IN_CHANNELS + (1)*IN_CHANNELS + 0];
    calcWbg_46_pp_5_3 = in_ptr[(y+3)*IN_WIDTH*IN_CHANNELS + (1)*IN_CHANNELS + 0];
    calcWbg_46_pp_5_2 = in_ptr[(y+2)*IN_WIDTH*IN_CHANNELS + (1)*IN_CHANNELS + 0];
    calcWbg_46_pp_5_1 = in_ptr[(y+1)*IN_WIDTH*IN_CHANNELS + (1)*IN_CHANNELS + 0];
    calcWbg_46_pp_5_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (1)*IN_CHANNELS + 0];
    calcWbg_46_pp_6_6 = in_ptr[(y+6)*IN_WIDTH*IN_CHANNELS + (2)*IN_CHANNELS + 0];
    calcWbg_46_pp_6_5 = in_ptr[(y+5)*IN_WIDTH*IN_CHANNELS + (2)*IN_CHANNELS + 0];
    calcWbg_46_pp_6_4 = in_ptr[(y+4)*IN_WIDTH*IN_CHANNELS + (2)*IN_CHANNELS + 0];
    calcWbg_46_pp_6_3 = in_ptr[(y+3)*IN_WIDTH*IN_CHANNELS + (2)*IN_CHANNELS + 0];
    calcWbg_46_pp_6_2 = in_ptr[(y+2)*IN_WIDTH*IN_CHANNELS + (2)*IN_CHANNELS + 0];
    calcWbg_46_pp_6_1 = in_ptr[(y+1)*IN_WIDTH*IN_CHANNELS + (2)*IN_CHANNELS + 0];
    calcWbg_46_pp_6_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (2)*IN_CHANNELS + 0];
    
    for(int x = 0; x < IN_WIDTH - 3; x++){
      // not on X boundry, common case
      // shift the stencil window, and load the new input pixel
      calcWbg_46_pp_0_6 = calcWbg_46_pp_1_6;
      calcWbg_46_pp_0_5 = calcWbg_46_pp_1_5;
      calcWbg_46_pp_0_4 = calcWbg_46_pp_1_4;
      calcWbg_46_pp_0_3 = calcWbg_46_pp_1_3;
      calcWbg_46_pp_0_2 = calcWbg_46_pp_1_2;
      calcWbg_46_pp_0_1 = calcWbg_46_pp_1_1;
      calcWbg_46_pp_0_0 = calcWbg_46_pp_1_0;
      calcWbg_46_pp_1_6 = calcWbg_46_pp_2_6;
      calcWbg_46_pp_1_5 = calcWbg_46_pp_2_5;
      calcWbg_46_pp_1_4 = calcWbg_46_pp_2_4;
      calcWbg_46_pp_1_3 = calcWbg_46_pp_2_3;
      calcWbg_46_pp_1_2 = calcWbg_46_pp_2_2;
      calcWbg_46_pp_1_1 = calcWbg_46_pp_2_1;
      calcWbg_46_pp_1_0 = calcWbg_46_pp_2_0;
      calcWbg_46_pp_2_6 = calcWbg_46_pp_3_6;
      calcWbg_46_pp_2_5 = calcWbg_46_pp_3_5;
      calcWbg_46_pp_2_4 = calcWbg_46_pp_3_4;
      calcWbg_46_pp_2_3 = calcWbg_46_pp_3_3;
      calcWbg_46_pp_2_2 = calcWbg_46_pp_3_2;
      calcWbg_46_pp_2_1 = calcWbg_46_pp_3_1;
      calcWbg_46_pp_2_0 = calcWbg_46_pp_3_0;
      calcWbg_46_pp_3_6 = calcWbg_46_pp_4_6;
      calcWbg_46_pp_3_5 = calcWbg_46_pp_4_5;
      calcWbg_46_pp_3_4 = calcWbg_46_pp_4_4;
      calcWbg_46_pp_3_3 = calcWbg_46_pp_4_3;
      calcWbg_46_pp_3_2 = calcWbg_46_pp_4_2;
      calcWbg_46_pp_3_1 = calcWbg_46_pp_4_1;
      calcWbg_46_pp_3_0 = calcWbg_46_pp_4_0;
      calcWbg_46_pp_4_6 = calcWbg_46_pp_5_6;
      calcWbg_46_pp_4_5 = calcWbg_46_pp_5_5;
      calcWbg_46_pp_4_4 = calcWbg_46_pp_5_4;
      calcWbg_46_pp_4_3 = calcWbg_46_pp_5_3;
      calcWbg_46_pp_4_2 = calcWbg_46_pp_5_2;
      calcWbg_46_pp_4_1 = calcWbg_46_pp_5_1;
      calcWbg_46_pp_4_0 = calcWbg_46_pp_5_0;
      calcWbg_46_pp_5_6 = calcWbg_46_pp_6_6;
      calcWbg_46_pp_5_5 = calcWbg_46_pp_6_5;
      calcWbg_46_pp_5_4 = calcWbg_46_pp_6_4;
      calcWbg_46_pp_5_3 = calcWbg_46_pp_6_3;
      calcWbg_46_pp_5_2 = calcWbg_46_pp_6_2;
      calcWbg_46_pp_5_1 = calcWbg_46_pp_6_1;
      calcWbg_46_pp_5_0 = calcWbg_46_pp_6_0;
      
      // load the update stencil
      calcWbg_46_pp_6_6 = in_ptr[(y+6)*IN_WIDTH*IN_CHANNELS + (x+3)*IN_CHANNELS + 0];
      calcWbg_46_pp_6_5 = in_ptr[(y+5)*IN_WIDTH*IN_CHANNELS + (x+3)*IN_CHANNELS + 0];
      calcWbg_46_pp_6_4 = in_ptr[(y+4)*IN_WIDTH*IN_CHANNELS + (x+3)*IN_CHANNELS + 0];
      calcWbg_46_pp_6_3 = in_ptr[(y+3)*IN_WIDTH*IN_CHANNELS + (x+3)*IN_CHANNELS + 0];
      calcWbg_46_pp_6_2 = in_ptr[(y+2)*IN_WIDTH*IN_CHANNELS + (x+3)*IN_CHANNELS + 0];
      calcWbg_46_pp_6_1 = in_ptr[(y+1)*IN_WIDTH*IN_CHANNELS + (x+3)*IN_CHANNELS + 0];
      calcWbg_46_pp_6_0 = in_ptr[(y+0)*IN_WIDTH*IN_CHANNELS + (x+3)*IN_CHANNELS + 0];
      
      // Start operation
      vector32 centroid_pos_0 = mv16_sv(x);
      vector32 centroid_pos_1 = mv16_sv(y);
      vector32 lambda_onfcam4dpct_line120_316_0 = c_1_0;
      vector32 lambda_onfcam4dpct_line120_324_0 = c_1_0;
      vector32 cnr_8_0 = c_1023_0;
      vector32 ct8_63_0 = c_1_0;
      vector32 ct8_90_0 = c_n9_0;
      vector32 ct8_71_0 = c_1_0;
      vector32 lambda_nfcam4defst_line56_68_0 = c_0x1_0;
      vector32 ct8_79_0 = c_0_0;
      vector32 Rh_486_0 = calcWbg_46_pp_3_1;
      vector32 Rh_581_pack_1 = ct8_79_0;
      vector32 ct8_127_0 = c_255_0;
      vector32 ct8_129_0 = c_9_0;
      vector32 Gh_60_pack_1 = cnr_8_0;
      vector32 ct8_65_0 = c_n10_0;
      vector32 ct8_105_0 = c_9_0;
      vector32 ct8_100_0 = c_9_0;
      vector32 Rh_425_0 = add16_vv(calcWbg_46_pp_3_4, calcWbg_46_pp_3_2);
      vector32 lambda_onfcam4dpct_line120_321_0 = c_1_0;
      vector32 lambda_nfcam4defst_line56_34_0 = c_344_0;
      vector32 srp_20_0 = c_3_0;
      vector32 Rh_472_0 = add16_vv(calcWbg_46_pp_1_3, calcWbg_46_pp_3_3);
      vector32 Rh_534_0 = calcWbg_46_pp_0_3;
      vector32 lambda_nfcam4defst_line56_37_0 = c_0x0_0;
      vector32 srp_10_0 = c_3_0;
      vector32 Rh_543_0 = add16_vv(calcWbg_46_pp_3_4, calcWbg_46_pp_5_4);
      vector32 Gh_59_pack_1 = ct8_79_0;
      vector32 Rh_505_0 = calcWbg_46_pp_3_6;
      vector32 cnr_5_0 = c_1023_0;
      vector32 Bh_94_pack_1 = cnr_5_0;
      vector32 Gh_56_pack_1 = cnr_5_0;
      vector32 Rh_577_pack_1 = cnr_5_0;
      vector32 Bh_97_pack_1 = cnr_5_0;
      vector32 calcDem_320_pack_1 = cnr_5_0;
      vector32 calcDem_323_pack_1 = cnr_5_0;
      vector32 Rv_113_0 = sub16_vv(Rh_425_0, calcWbg_46_pp_2_3);
      vector32 Rh_582_pack_1 = cnr_8_0;
      vector32 lambda_onfcam4dpct_line120_312_0 = c_1_0;
      vector32 lambda_onfcam4dpct_line120_314_0 = c_1_0;
      vector32 lambda_onfcam4dpct_line120_319_0 = c_1_0;
      vector32 Rv_175_pack_1 = cnr_5_0;
      vector32 ct8_54_0 = c_1_0;
      vector32 ct8_119_0 = c_255_0;
      vector32 srp_12_0 = c_2_0;
      vector32 ct8_87_0 = c_0_0;
      vector32 lambda_nfcam4defst_line49_33_0 = c_34_0;
      vector32 ct8_101_0 = add16_vv(centroid_pos_0, ct8_100_0);
      vector32 Gv_53_pack_1 = cnr_5_0;
      vector32 ct8_113_0 = c_9_0;
      vector32 ct8_85_0 = c_n10_0;
      vector32 lambda_nfcam4defst_line56_52_0 = c_344_0;
      vector32 Rh_586_pack_1 = ct8_87_0;
      vector32 lambda_nfcam4defst_line49_47_0 = c_34_0;
      vector32 ct8_116_0 = c_9_0;
      vector32 ct8_117_0 = add16_vv(centroid_pos_0, ct8_116_0);
      vector32 lambda_onfcam4dpct_line120_315_0 = c_1_0;
      vector32 lambda_onfcam4ccmt_line101_5_0 = c_2_0;
      vector32 srp_16_0 = c_3_0;
      vector32 calcDem_61_0 = tap_dem_dirThr_0;
      vector32 Rh_545_0 = calcWbg_46_pp_5_4;
      vector32 Rh_493_0 = add16_vv(calcWbg_46_pp_2_5, calcWbg_46_pp_4_5);
      vector32 Rh_494_0 = add16_vv(Rh_493_0, calcWbg_46_pp_2_3);
      vector32 ct8_78_0 = c_8_0;
      vector32 lambda_nfcam4defst_line56_43_0 = c_344_0;
      vector32 ct8_108_0 = c_9_0;
      vector32 ct8_109_0 = add16_vv(centroid_pos_0, ct8_108_0);
      vector32 Rh_495_0 = add16_vv(Rh_494_0, calcWbg_46_pp_4_3);
      vector32 lambda_onfcam4ccmt_line101_7_0 = c_2_0;
      vector32 srp_13_0 = c_2_0;
      vector32 lambda_nfcam4defst_line56_70_0 = c_344_0;
      vector32 lambda_onfcam4dpct_line120_320_0 = c_1_0;
      vector32 Rh_386_0 = calcWbg_46_pp_2_2;
      vector32 Rh_384_0 = calcWbg_46_pp_4_4;
      vector32 lambda_nfcam4defst_line56_59_0 = c_0x1_0;
      vector32 Rh_544_0 = add16_vv(Rh_543_0, calcWbg_46_pp_3_2);
      vector32 Rh_548_0 = add16_vv(Rh_544_0, calcWbg_46_pp_5_2);
      vector32 lambda_onfcam4dpct_line120_318_0 = c_1_0;
      vector32 Bh_102_pack_1 = cnr_8_0;
      vector32 Rh_379_0 = calcWbg_46_pp_2_4;
      vector32 Bv_105_pack_1 = cnr_5_0;
      vector32 srp_14_0 = c_2_0;
      vector32 ct8_57_0 = c_n9_0;
      vector32 lambda_nfcam4defst_line56_29_0 = c_0x0_0;
      vector32 Rh_553_0 = calcWbg_46_pp_5_2;
      vector32 ct8_95_0 = c_255_0;
      vector32 ct8_82_0 = c_n9_0;
      vector32 Rv_178_pack_1 = cnr_5_0;
      vector32 lambda_onfcam4ccmt_line101_6_0 = c_2_0;
      vector32 lambda_nfcam4defst_line56_38_0 = mux16_vv(lambda_nfcam4defst_line56_37_0, ct8_63_0, lambda_onfcam4ccmt_line101_6_0);
      vector32 Rh_517_0 = calcWbg_46_pp_3_0;
      vector32 Rh_507_0 = calcWbg_46_pp_2_1;
      vector32 ct8_96_0 = sub16_vv(ct8_95_0, centroid_pos_1);
      vector32 Rh_513_0 = calcWbg_46_pp_4_1;
      vector32 Rh_380_0 = add16_vv(calcWbg_46_pp_2_4, calcWbg_46_pp_4_4);
      vector32 Rh_381_0 = Rh_380_0;
      vector32 Rv_114_0 = sub16_vv(Rv_113_0, calcWbg_46_pp_4_3);
      vector32 Gv_56_pack_1 = cnr_5_0;
      vector32 Rh_473_0 = sub16_vv(Rh_472_0, calcWbg_46_pp_2_4);
      vector32 Rh_474_0 = sub16_vv(Rh_473_0, calcWbg_46_pp_2_2);
      vector32 Rh_475_0 = Rh_474_0;
      vector32 srp_19_0 = c_2_0;
      vector32 lambda_nfcam4defst_line56_64_0 = c_0x0_0;
      vector32 calcDem_317_pack_1 = cnr_5_0;
      vector32 ct8_97_0 = c_9_0;
      vector32 Bv_111_pack_1 = cnr_5_0;
      vector32 ct8_120_0 = sub16_vv(ct8_119_0, centroid_pos_1);
      vector32 Rh_528_0 = calcWbg_46_pp_1_2;
      vector32 Rv_115_0 = Rv_114_0;
      vector32 Rv_116_0 = add16_vv(Rv_115_0, lambda_onfcam4ccmt_line101_5_0);
      vector32 Rv_117_0 = rshift16_vv(Rv_116_0, lambda_onfcam4dpct_line120_316_0);
      vector32 calcDem_23_0 = tap_dem_wc_0;
      vector32 Rh_574_pack_1 = cnr_5_0;
      vector32 Rh_518_0 = add16_vv(calcWbg_46_pp_1_4, calcWbg_46_pp_3_4);
      vector32 Gh_53_pack_1 = cnr_5_0;
      vector32 Rh_478_0 = Rh_472_0;
      vector32 Rh_387_0 = add16_vv(calcWbg_46_pp_2_4, calcWbg_46_pp_2_2);
      vector32 lambda_onfcam4ccmt_line101_8_0 = c_2_0;
      vector32 Rh_476_0 = add16_vv(Rh_475_0, lambda_onfcam4ccmt_line101_8_0);
      vector32 Rh_477_0 = rshift16_vv(Rh_476_0, lambda_onfcam4dpct_line120_314_0);
      vector32 ct8_111_0 = c_255_0;
      vector32 ct8_80_0 = c_1_0;
      vector32 Rh_444_0 = calcWbg_46_pp_5_3;
      vector32 Rh_549_0 = Rh_548_0;
      vector32 ct8_76_0 = c_n9_0;
      vector32 ct8_118_0 = add16_vv(ct8_117_0, ct8_76_0);
      vector32 calcDem_21_0 = c_5_0;
      vector32 Rh_434_0 = calcWbg_46_pp_3_3;
      vector32 Rh_436_0 = lshift16_vv(Rh_434_0, srp_13_0);
      vector32 Rh_437_0 = sub16_vv(Rh_436_0, Rh_379_0);
      vector32 ct8_103_0 = c_255_0;
      vector32 lambda_nfcam4defst_line49_26_0 = c_34_0;
      vector32 srp_15_0 = c_2_0;
      vector32 ct8_62_0 = c_0_0;
      vector32 Rv_182_pack_1 = ct8_62_0;
      vector32 lambda_nfcam4defst_line49_29_0 = mux16_vv(lambda_nfcam4defst_line56_37_0, ct8_62_0, lambda_onfcam4ccmt_line101_6_0);
      vector32 lambda_nfcam4defst_line49_30_0 = mux16_vv(lambda_nfcam4defst_line56_37_0, ct8_63_0, lambda_nfcam4defst_line49_29_0);
      vector32 lambda_nfcam4defst_line56_39_0 = mux16_vv(lambda_nfcam4defst_line56_37_0, ct8_62_0, lambda_nfcam4defst_line56_38_0);
      vector32 lambda_nfcam4defst_line56_40_0 = mux16_vv(lambda_nfcam4defst_line56_37_0, ct8_63_0, lambda_nfcam4defst_line56_39_0);
      vector32 ct8_73_0 = c_n8_0;
      vector32 ct8_121_0 = c_9_0;
      vector32 ct8_122_0 = add16_vv(ct8_120_0, ct8_121_0);
      vector32 ct8_123_0 = add16_vv(ct8_122_0, ct8_82_0);
      vector32 ct8_70_0 = c_0_0;
      vector32 Rv_187_pack_1 = ct8_70_0;
      vector32 Rh_395_0 = calcWbg_46_pp_4_2;
      vector32 Rh_481_0 = calcWbg_46_pp_3_5;
      vector32 Rh_416_0 = calcWbg_46_pp_3_4;
      vector32 Gv_59_pack_1 = ct8_62_0;
      vector32 Rh_438_0 = sub16_vv(Rh_437_0, Rh_384_0);
      vector32 Rh_439_0 = sub16_vv(Rh_438_0, Rh_386_0);
      vector32 Rh_440_0 = sub16_vv(Rh_439_0, Rh_395_0);
      vector32 Rh_441_0 = add16_vv(Rh_440_0, lambda_onfcam4ccmt_line101_5_0);
      vector32 Rh_442_0 = rshift16_vv(Rh_441_0, srp_12_0);
      vector32 ct8_60_0 = c_n9_0;
      vector32 Rh_519_0 = calcWbg_46_pp_1_4;
      vector32 cnr_9_0 = c_1023_0;
      vector32 Rh_587_pack_1 = cnr_9_0;
      vector32 Bh_107_pack_1 = cnr_9_0;
      vector32 srp_22_0 = c_2_0;
      vector32 lambda_nfcam4defst_line56_55_0 = c_0x0_0;
      vector32 Rh_396_0 = add16_vv(calcWbg_46_pp_2_2, calcWbg_46_pp_4_2);
      vector32 Rh_397_0 = Rh_396_0;
      vector32 ct8_112_0 = sub16_vv(ct8_111_0, centroid_pos_1);
      vector32 ct8_114_0 = add16_vv(ct8_112_0, ct8_113_0);
      vector32 ct8_115_0 = add16_vv(ct8_114_0, ct8_73_0);
      vector32 Rh_411_0 = calcWbg_46_pp_4_3;
      vector32 Rh_414_0 = lshift16_vv(Rh_411_0, srp_14_0);
      vector32 Rh_419_0 = sub16_vv(Rh_414_0, Rh_416_0);
      vector32 lambda_nfcam4defst_line56_28_0 = c_0x1_0;
      vector32 Rh_487_0 = add16_vv(calcWbg_46_pp_3_3, calcWbg_46_pp_3_1);
      vector32 Rh_488_0 = Rh_487_0;
      vector32 Rh_489_0 = add16_vv(Rh_488_0, ct8_71_0);
      vector32 Rh_490_0 = rshift16_vv(Rh_489_0, lambda_onfcam4dpct_line120_320_0);
      vector32 Rh_385_0 = add16_vv(Rh_380_0, calcWbg_46_pp_2_2);
      vector32 Rh_398_0 = add16_vv(Rh_397_0, ct8_71_0);
      vector32 Rh_399_0 = rshift16_vv(Rh_398_0, lambda_onfcam4dpct_line120_316_0);
      vector32 Bh_106_pack_1 = ct8_87_0;
      vector32 Rh_546_0 = sub16_vv(Rh_419_0, Rh_545_0);
      vector32 ct8_98_0 = add16_vv(ct8_96_0, ct8_97_0);
      vector32 ct8_99_0 = add16_vv(ct8_98_0, ct8_57_0);
      vector32 Gh_63_pack_1 = ct8_87_0;
      vector32 Rh_522_0 = add16_vv(Rh_518_0, calcWbg_46_pp_1_2);
      vector32 Rh_523_0 = add16_vv(Rh_522_0, calcWbg_46_pp_3_2);
      vector32 Rh_524_0 = Rh_523_0;
      vector32 Rh_525_0 = add16_vv(Rh_524_0, lambda_onfcam4ccmt_line101_8_0);
      vector32 Rh_526_0 = rshift16_vv(Rh_525_0, srp_15_0);
      vector32 Rh_527_0 = add16_vv(Rh_526_0, Rh_477_0);
      vector32 Rh_455_0 = calcWbg_46_pp_1_3;
      vector32 Rh_446_0 = add16_vv(calcWbg_46_pp_3_3, calcWbg_46_pp_5_3);
      vector32 Rh_452_0 = Rh_446_0;
      vector32 Rh_447_0 = sub16_vv(Rh_446_0, calcWbg_46_pp_4_4);
      vector32 Rh_448_0 = sub16_vv(Rh_447_0, calcWbg_46_pp_4_2);
      vector32 Rh_449_0 = Rh_448_0;
      vector32 cnr_7_0 = c_1023_0;
      vector32 Gv_64_pack_1 = cnr_7_0;
      vector32 Rv_188_pack_1 = cnr_7_0;
      vector32 Bv_122_pack_1 = ct8_70_0;
      vector32 ct8_55_0 = c_0_0;
      vector32 calcDem_322_pack_1 = ct8_55_0;
      vector32 Rh_576_pack_1 = ct8_55_0;
      vector32 Bv_104_pack_1 = ct8_55_0;
      vector32 Gv_55_pack_1 = ct8_55_0;
      vector32 lambda_nfcam4defst_line49_22_0 = mux16_vv(lambda_nfcam4defst_line56_29_0, ct8_55_0, lambda_onfcam4ccmt_line101_5_0);
      vector32 Bh_93_pack_1 = ct8_55_0;
      vector32 Rv_174_pack_1 = ct8_55_0;
      vector32 Bv_110_pack_1 = ct8_55_0;
      vector32 calcDem_316_pack_1 = ct8_55_0;
      vector32 Rh_573_pack_1 = ct8_55_0;
      vector32 calcDem_319_pack_1 = ct8_55_0;
      vector32 Gv_52_pack_1 = ct8_55_0;
      vector32 Rv_177_pack_1 = ct8_55_0;
      vector32 Gh_52_pack_1 = ct8_55_0;
      vector32 Rh_407_0 = add16_vv(calcWbg_46_pp_2_3, calcWbg_46_pp_4_3);
      vector32 Rh_415_0 = sub16_vv(Rh_407_0, calcWbg_46_pp_3_4);
      vector32 Rh_420_0 = sub16_vv(Rh_415_0, calcWbg_46_pp_3_2);
      vector32 Rh_421_0 = Rh_420_0;
      vector32 Rh_422_0 = add16_vv(Rh_421_0, lambda_onfcam4ccmt_line101_5_0);
      vector32 Rh_506_0 = add16_vv(Rh_407_0, calcWbg_46_pp_2_1);
      vector32 Rh_423_0 = rshift16_vv(Rh_422_0, lambda_onfcam4dpct_line120_316_0);
      vector32 Rh_509_0 = add16_vv(Rh_506_0, calcWbg_46_pp_4_1);
      vector32 Rh_408_0 = Rh_407_0;
      vector32 lambda_nfcam4defst_line56_30_0 = mux16_vv(lambda_nfcam4defst_line56_29_0, ct8_54_0, lambda_onfcam4ccmt_line101_5_0);
      vector32 lambda_nfcam4defst_line49_31_0 = mux16_vv(lambda_nfcam4defst_line56_37_0, ct8_63_0, lambda_nfcam4defst_line49_30_0);
      vector32 Rh_400_0 = add16_vv(calcWbg_46_pp_4_4, calcWbg_46_pp_4_2);
      vector32 cnr_6_0 = c_1023_0;
      vector32 Gv_60_pack_1 = cnr_6_0;
      vector32 Rv_183_pack_1 = cnr_6_0;
      vector32 Bv_117_pack_1 = cnr_6_0;
      vector32 Rh_479_0 = add16_vv(Rh_478_0, ct8_80_0);
      vector32 Bv_123_pack_1 = cnr_7_0;
      vector32 lambda_nfcam4defst_line49_43_0 = mux16_vv(lambda_nfcam4defst_line56_55_0, ct8_79_0, lambda_onfcam4ccmt_line101_8_0);
      vector32 calcDem_4_0 = tap_dem_wg_0;
      vector32 Rh_391_0 = add16_vv(Rh_385_0, calcWbg_46_pp_4_2);
      vector32 Rh_392_0 = Rh_391_0;
      vector32 Rh_393_0 = add16_vv(Rh_392_0, lambda_onfcam4ccmt_line101_5_0);
      vector32 Rh_394_0 = rshift16_vv(Rh_393_0, srp_12_0);
      vector32 Rv_118_0 = add16_vv(Rh_394_0, Rv_117_0);
      vector32 lambda_nfcam4defst_line56_56_0 = mux16_vv(lambda_nfcam4defst_line56_55_0, ct8_80_0, lambda_onfcam4ccmt_line101_8_0);
      vector32 lambda_nfcam4defst_line56_57_0 = mux16_vv(lambda_nfcam4defst_line56_55_0, ct8_79_0, lambda_nfcam4defst_line56_56_0);
      vector32 lambda_nfcam4defst_line56_58_0 = mux16_vv(lambda_nfcam4defst_line56_55_0, ct8_80_0, lambda_nfcam4defst_line56_57_0);
      vector32 lambda_nfcam4defst_line56_60_0 = mux16_vv(lambda_nfcam4defst_line56_59_0, ct8_79_0, lambda_nfcam4defst_line56_58_0);
      vector32 lambda_nfcam4defst_line56_62_0 = ne16_vv(lambda_nfcam4defst_line56_60_0, lambda_onfcam4ccmt_line101_8_0);
      vector32 lambda_nfcam4defst_line64_141_0 = add16_vv(ct8_123_0, lambda_nfcam4defst_line56_60_0);
      vector32 lambda_onfcam4ccmt_line101_9_0 = c_2_0;
      vector32 lambda_nfcam4defst_line49_50_0 = mux16_vv(lambda_nfcam4defst_line56_64_0, ct8_87_0, lambda_onfcam4ccmt_line101_9_0);
      vector32 Rh_550_0 = add16_vv(Rh_549_0, lambda_onfcam4ccmt_line101_9_0);
      vector32 Rh_450_0 = add16_vv(Rh_449_0, lambda_onfcam4ccmt_line101_9_0);
      vector32 Rh_499_0 = calcWbg_46_pp_4_5;
      vector32 srp_21_0 = c_3_0;
      vector32 lambda_onfcam4dpct_line120_317_0 = c_1_0;
      vector32 Rh_417_0 = lshift16_vv(Rh_416_0, lambda_onfcam4dpct_line120_317_0);
      vector32 Rv_150_0 = sub16_vv(Rh_417_0, Rh_505_0);
      vector32 lambda_nfcam4defst_line56_46_0 = c_0x0_0;
      vector32 lambda_nfcam4defst_line49_36_0 = mux16_vv(lambda_nfcam4defst_line56_46_0, ct8_70_0, lambda_onfcam4ccmt_line101_7_0);
      vector32 lambda_nfcam4defst_line49_37_0 = mux16_vv(lambda_nfcam4defst_line56_46_0, ct8_71_0, lambda_nfcam4defst_line49_36_0);
      vector32 lambda_nfcam4defst_line49_38_0 = mux16_vv(lambda_nfcam4defst_line56_46_0, ct8_71_0, lambda_nfcam4defst_line49_37_0);
      vector32 lambda_onfcam4dpct_line120_323_0 = c_1_0;
      vector32 Rh_451_0 = rshift16_vv(Rh_450_0, lambda_onfcam4dpct_line120_323_0);
      vector32 Rh_496_0 = Rh_495_0;
      vector32 Rh_497_0 = add16_vv(Rh_496_0, lambda_onfcam4ccmt_line101_6_0);
      vector32 Rh_498_0 = rshift16_vv(Rh_497_0, srp_14_0);
      vector32 Rh_382_0 = add16_vv(Rh_381_0, ct8_63_0);
      vector32 Rh_383_0 = rshift16_vv(Rh_382_0, lambda_onfcam4dpct_line120_318_0);
      vector32 Rh_429_0 = calcWbg_46_pp_3_2;
      vector32 Rh_430_0 = lshift16_vv(Rh_429_0, lambda_onfcam4dpct_line120_314_0);
      vector32 Rh_431_0 = lshift16_vv(Rh_429_0, srp_15_0);
      vector32 Rh_547_0 = sub16_vv(Rh_546_0, Rh_429_0);
      vector32 Rh_554_0 = sub16_vv(Rh_547_0, Rh_553_0);
      vector32 Rv_119_0 = sub16_vv(Rh_430_0, Rh_416_0);
      vector32 Bv_116_pack_1 = ct8_62_0;
      vector32 ct8_88_0 = c_1_0;
      vector32 lambda_nfcam4defst_line56_65_0 = mux16_vv(lambda_nfcam4defst_line56_64_0, ct8_88_0, lambda_onfcam4ccmt_line101_9_0);
      vector32 lambda_nfcam4defst_line49_51_0 = mux16_vv(lambda_nfcam4defst_line56_64_0, ct8_88_0, lambda_nfcam4defst_line49_50_0);
      vector32 lambda_nfcam4defst_line49_52_0 = mux16_vv(lambda_nfcam4defst_line56_64_0, ct8_88_0, lambda_nfcam4defst_line49_51_0);
      vector32 lambda_nfcam4defst_line49_53_0 = mux16_vv(lambda_nfcam4defst_line56_68_0, ct8_87_0, lambda_nfcam4defst_line49_52_0);
      vector32 lambda_nfcam4defst_line49_55_0 = ne16_vv(lambda_nfcam4defst_line49_53_0, lambda_onfcam4ccmt_line101_9_0);
      vector32 lambda_nfcam4defst_line56_66_0 = mux16_vv(lambda_nfcam4defst_line56_64_0, ct8_87_0, lambda_nfcam4defst_line56_65_0);
      vector32 lambda_nfcam4defst_line56_67_0 = mux16_vv(lambda_nfcam4defst_line56_64_0, ct8_88_0, lambda_nfcam4defst_line56_66_0);
      vector32 srp_24_0 = c_2_0;
      vector32 ct8_132_0 = c_9_0;
      vector32 ct8_133_0 = add16_vv(centroid_pos_0, ct8_132_0);
      vector32 Rv_161_0 = sub16_vv(Rv_119_0, Rh_517_0);
      vector32 Rv_162_0 = add16_vv(Rv_161_0, lambda_onfcam4ccmt_line101_7_0);
      vector32 Rv_163_0 = rshift16_vv(Rv_162_0, srp_19_0);
      vector32 Bv_91_0 = mux16_vv(lambda_nfcam4defst_line56_46_0, Rv_163_0, ct8_70_0);
      vector32 lambda_nfcam4defst_line56_50_0 = c_0x1_0;
      vector32 lambda_nfcam4defst_line49_39_0 = mux16_vv(lambda_nfcam4defst_line56_50_0, ct8_70_0, lambda_nfcam4defst_line49_38_0);
      vector32 lambda_nfcam4defst_line64_135_0 = add16_vv(ct8_118_0, lambda_nfcam4defst_line49_39_0);
      vector32 lambda_nfcam4defst_line64_136_0 = and16_vv(lambda_nfcam4defst_line64_135_0, ct8_71_0);
      vector32 lambda_nfcam4defst_line64_137_0 = ne16_vv(lambda_nfcam4defst_line64_136_0, ct8_70_0);
      vector32 lambda_nfcam4defst_line64_138_0 = not16_vv(lambda_nfcam4defst_line64_137_0);
      vector32 Rh_453_0 = add16_vv(Rh_452_0, ct8_88_0);
      vector32 Rh_482_0 = add16_vv(calcWbg_46_pp_3_5, calcWbg_46_pp_3_3);
      vector32 Rv_122_0 = sub16_vv(Rh_482_0, calcWbg_46_pp_2_4);
      vector32 Rv_123_0 = sub16_vv(Rv_122_0, calcWbg_46_pp_4_4);
      vector32 Rh_483_0 = Rh_482_0;
      vector32 Rv_124_0 = Rv_123_0;
      vector32 Rv_125_0 = add16_vv(Rv_124_0, lambda_onfcam4ccmt_line101_6_0);
      vector32 Rv_126_0 = rshift16_vv(Rv_125_0, lambda_onfcam4dpct_line120_312_0);
      vector32 ct8_68_0 = c_n9_0;
      vector32 ct8_110_0 = add16_vv(ct8_109_0, ct8_68_0);
      vector32 Rv_151_0 = sub16_vv(Rv_150_0, Rh_429_0);
      vector32 Rv_152_0 = add16_vv(Rv_151_0, lambda_onfcam4ccmt_line101_6_0);
      vector32 Rv_153_0 = rshift16_vv(Rv_152_0, srp_15_0);
      vector32 Bv_82_0 = mux16_vv(lambda_nfcam4defst_line56_37_0, Rv_153_0, ct8_62_0);
      vector32 Gv_63_pack_1 = ct8_70_0;
      vector32 ct8_102_0 = add16_vv(ct8_101_0, ct8_60_0);
      vector32 lambda_nfcam4defst_line56_61_0 = c_344_0;
      vector32 lambda_nfcam4defst_line64_142_0 = and16_vv(lambda_nfcam4defst_line64_141_0, ct8_80_0);
      vector32 lambda_nfcam4defst_line64_143_0 = ne16_vv(lambda_nfcam4defst_line64_142_0, ct8_79_0);
      vector32 lambda_nfcam4defst_line64_144_0 = not16_vv(lambda_nfcam4defst_line64_143_0);
      vector32 Rv_143_0 = sub16_vv(Rh_487_0, calcWbg_46_pp_2_2);
      vector32 Rv_144_0 = sub16_vv(Rv_143_0, calcWbg_46_pp_4_2);
      vector32 Rv_145_0 = Rv_144_0;
      vector32 srp_17_0 = c_2_0;
      vector32 Rh_418_0 = lshift16_vv(Rh_416_0, srp_17_0);
      vector32 Rv_148_0 = add16_vv(Rh_498_0, Rv_126_0);
      vector32 Bv_83_0 = add16_vv(Rv_148_0, Bv_82_0);
      vector32 Rh_555_0 = add16_vv(Rh_554_0, lambda_onfcam4ccmt_line101_9_0);
      vector32 Rh_388_0 = Rh_387_0;
      vector32 Rh_389_0 = add16_vv(Rh_388_0, ct8_80_0);
      vector32 ct8_104_0 = sub16_vv(ct8_103_0, centroid_pos_1);
      vector32 ct8_106_0 = add16_vv(ct8_104_0, ct8_105_0);
      vector32 ct8_107_0 = add16_vv(ct8_106_0, ct8_65_0);
      vector32 Rh_484_0 = add16_vv(Rh_483_0, ct8_63_0);
      vector32 Rh_404_0 = calcWbg_46_pp_2_3;
      vector32 Rh_406_0 = lshift16_vv(Rh_404_0, srp_22_0);
      vector32 Rh_432_0 = sub16_vv(Rh_431_0, Rh_404_0);
      vector32 Rh_520_0 = sub16_vv(Rh_406_0, Rh_519_0);
      vector32 Rh_433_0 = sub16_vv(Rh_432_0, Rh_411_0);
      vector32 Rh_508_0 = sub16_vv(Rh_433_0, Rh_507_0);
      vector32 Rh_514_0 = sub16_vv(Rh_508_0, Rh_513_0);
      vector32 Rh_521_0 = sub16_vv(Rh_520_0, Rh_416_0);
      vector32 Rh_529_0 = sub16_vv(Rh_521_0, Rh_528_0);
      vector32 Rh_515_0 = add16_vv(Rh_514_0, lambda_onfcam4ccmt_line101_7_0);
      vector32 Rh_405_0 = lshift16_vv(Rh_404_0, lambda_onfcam4dpct_line120_321_0);
      vector32 Rh_412_0 = sub16_vv(Rh_405_0, Rh_411_0);
      vector32 Rh_535_0 = sub16_vv(Rh_412_0, Rh_534_0);
      vector32 Rh_536_0 = add16_vv(Rh_535_0, lambda_onfcam4ccmt_line101_8_0);
      vector32 Rh_537_0 = rshift16_vv(Rh_536_0, srp_14_0);
      vector32 Bh_72_0 = mux16_vv(lambda_nfcam4defst_line56_55_0, Rh_537_0, ct8_79_0);
      vector32 Bh_73_0 = add16_vv(Rh_527_0, Bh_72_0);
      vector32 Rh_530_0 = sub16_vv(Rh_529_0, Rh_429_0);
      vector32 Rh_531_0 = add16_vv(Rh_530_0, lambda_onfcam4ccmt_line101_8_0);
      vector32 Rh_532_0 = rshift16_vv(Rh_531_0, srp_15_0);
      vector32 Rh_413_0 = lshift16_vv(Rh_411_0, lambda_onfcam4dpct_line120_312_0);
      vector32 Rh_426_0 = Rh_425_0;
      vector32 Rh_427_0 = add16_vv(Rh_426_0, ct8_54_0);
      vector32 Rh_428_0 = rshift16_vv(Rh_427_0, lambda_onfcam4dpct_line120_314_0);
      vector32 ct8_124_0 = c_9_0;
      vector32 ct8_125_0 = add16_vv(centroid_pos_0, ct8_124_0);
      vector32 ct8_126_0 = add16_vv(ct8_125_0, ct8_85_0);
      vector32 Bh_96_pack_1 = ct8_55_0;
      vector32 Rh_510_0 = Rh_509_0;
      vector32 Rh_511_0 = add16_vv(Rh_510_0, lambda_onfcam4ccmt_line101_7_0);
      vector32 lambda_nfcam4defst_line49_23_0 = mux16_vv(lambda_nfcam4defst_line56_29_0, ct8_54_0, lambda_nfcam4defst_line49_22_0);
      vector32 lambda_nfcam4defst_line49_24_0 = mux16_vv(lambda_nfcam4defst_line56_29_0, ct8_54_0, lambda_nfcam4defst_line49_23_0);
      vector32 lambda_nfcam4defst_line49_25_0 = mux16_vv(lambda_nfcam4defst_line56_28_0, ct8_55_0, lambda_nfcam4defst_line49_24_0);
      vector32 lambda_nfcam4defst_line64_115_0 = add16_vv(ct8_102_0, lambda_nfcam4defst_line49_25_0);
      vector32 lambda_nfcam4defst_line49_27_0 = ne16_vv(lambda_nfcam4defst_line49_25_0, lambda_onfcam4ccmt_line101_5_0);
      vector32 lambda_nfcam4defst_line64_116_0 = and16_vv(lambda_nfcam4defst_line64_115_0, ct8_54_0);
      vector32 lambda_nfcam4defst_line64_117_0 = ne16_vv(lambda_nfcam4defst_line64_116_0, ct8_55_0);
      vector32 lambda_nfcam4defst_line64_118_0 = not16_vv(lambda_nfcam4defst_line64_117_0);
      vector32 srp_18_0 = c_2_0;
      vector32 Rh_516_0 = rshift16_vv(Rh_515_0, srp_18_0);
      vector32 Rv_160_0 = add16_vv(Rh_399_0, Rh_516_0);
      vector32 Rh_512_0 = rshift16_vv(Rh_511_0, srp_18_0);
      vector32 Rh_443_0 = add16_vv(Rh_428_0, Rh_442_0);
      vector32 lambda_nfcam4defst_line56_69_0 = mux16_vv(lambda_nfcam4defst_line56_68_0, ct8_87_0, lambda_nfcam4defst_line56_67_0);
      vector32 lambda_nfcam4defst_line56_71_0 = ne16_vv(lambda_nfcam4defst_line56_69_0, lambda_onfcam4ccmt_line101_9_0);
      vector32 lambda_onfcam4dpct_line120_313_0 = c_1_0;
      vector32 Rh_485_0 = rshift16_vv(Rh_484_0, lambda_onfcam4dpct_line120_313_0);
      vector32 Bv_87_0 = add16_vv(Rh_485_0, Bv_82_0);
      vector32 Rh_435_0 = lshift16_vv(Rh_434_0, lambda_onfcam4dpct_line120_313_0);
      vector32 Rv_121_0 = sub16_vv(Rh_435_0, Rh_481_0);
      vector32 Rh_480_0 = rshift16_vv(Rh_479_0, lambda_onfcam4dpct_line120_313_0);
      vector32 Bh_75_0 = add16_vv(Rh_480_0, Bh_72_0);
      vector32 Rh_445_0 = sub16_vv(Rh_435_0, Rh_444_0);
      vector32 Rh_456_0 = sub16_vv(Rh_445_0, Rh_455_0);
      vector32 Rh_457_0 = add16_vv(Rh_456_0, lambda_onfcam4ccmt_line101_5_0);
      vector32 srp_11_0 = c_2_0;
      vector32 lambda_nfcam4defst_line49_44_0 = mux16_vv(lambda_nfcam4defst_line56_55_0, ct8_80_0, lambda_nfcam4defst_line49_43_0);
      vector32 lambda_nfcam4defst_line49_45_0 = mux16_vv(lambda_nfcam4defst_line56_55_0, ct8_80_0, lambda_nfcam4defst_line49_44_0);
      vector32 Bv_96_0 = add16_vv(Rh_490_0, Bv_91_0);
      vector32 lambda_onfcam4dpct_line120_322_0 = c_1_0;
      vector32 lambda_nfcam4defst_line49_46_0 = mux16_vv(lambda_nfcam4defst_line56_59_0, ct8_79_0, lambda_nfcam4defst_line49_45_0);
      vector32 lambda_nfcam4defst_line64_145_0 = add16_vv(ct8_126_0, lambda_nfcam4defst_line49_46_0);
      vector32 lambda_nfcam4defst_line49_48_0 = ne16_vv(lambda_nfcam4defst_line49_46_0, lambda_onfcam4ccmt_line101_8_0);
      vector32 lambda_nfcam4defst_line64_146_0 = and16_vv(lambda_nfcam4defst_line64_145_0, ct8_80_0);
      vector32 lambda_nfcam4defst_line64_147_0 = ne16_vv(lambda_nfcam4defst_line64_146_0, ct8_79_0);
      vector32 lambda_nfcam4defst_line80_25_0 = and16_vv(lambda_nfcam4defst_line64_144_0, lambda_nfcam4defst_line64_147_0);
      vector32 lambda_nfcam4defst_line80_26_0 = mux16_vv(lambda_nfcam4defst_line80_25_0, ct8_80_0, ct8_79_0);
      vector32 lambda_nfcam4defst_line64_148_0 = not16_vv(lambda_nfcam4defst_line64_147_0);
      vector32 lambda_nfcam4defst_line64_149_0 = and16_vv(lambda_nfcam4defst_line64_144_0, lambda_nfcam4defst_line64_148_0);
      vector32 lambda_nfcam4defst_line64_150_0 = mux16_vv(lambda_nfcam4defst_line64_149_0, ct8_80_0, ct8_79_0);
      vector32 pix_65_0 = eq16_vv(lambda_nfcam4defst_line64_150_0, ct8_80_0);
      vector32 lambda_nfcam4defst_line88_29_0 = and16_vv(lambda_nfcam4defst_line64_143_0, lambda_nfcam4defst_line64_147_0);
      vector32 lambda_nfcam4defst_line88_30_0 = mux16_vv(lambda_nfcam4defst_line88_29_0, ct8_80_0, ct8_79_0);
      vector32 pix_61_0 = eq16_vv(lambda_nfcam4defst_line80_26_0, ct8_80_0);
      vector32 pix_62_0 = mux16_vv(pix_61_0, srp_21_0, lambda_onfcam4ccmt_line101_8_0);
      vector32 pix_63_0 = eq16_vv(lambda_nfcam4defst_line88_30_0, ct8_80_0);
      vector32 pix_64_0 = mux16_vv(pix_63_0, ct8_80_0, pix_62_0);
      vector32 pix_66_0 = mux16_vv(pix_65_0, ct8_79_0, pix_64_0);
      vector32 mB_151_0 = eq16_vv(pix_66_0, ct8_79_0);
      vector32 mB_150_0 = eq16_vv(pix_66_0, ct8_80_0);
      vector32 Gh_57_0 = mux16_vv(mB_150_0, Rh_404_0, Bh_75_0);
      vector32 Gh_58_0 = mux16_vv(mB_151_0, Rh_404_0, Gh_57_0);
      vector32 Gh_59_pack_0 = Gh_58_0;
      // max Gh_59_0 <= (Gh_59_pack_1 , Gh_59_pack_0)
      vector32 Gh_59_0_cotmp_1 = max16_vv(Gh_59_pack_1, Gh_59_pack_0);
      vector32 Gh_59_0 = Gh_59_0_cotmp_1;

      vector32 Gh_60_pack_0 = Gh_59_0;
      // min Gh_60_0 <= (Gh_60_pack_1 , Gh_60_pack_0)
      vector32 Gh_60_0_cotmp_1 = min16_vv(Gh_60_pack_1, Gh_60_pack_0);
      vector32 Gh_60_0 = Gh_60_0_cotmp_1;

      vector32 Rh_409_0 = add16_vv(Rh_408_0, ct8_54_0);
      vector32 Rh_410_0 = rshift16_vv(Rh_409_0, lambda_onfcam4dpct_line120_312_0);
      vector32 Rv_120_0 = add16_vv(Rh_410_0, Rh_442_0);
      vector32 Rh_558_0 = calcWbg_46_pp_6_3;
      vector32 Rh_559_0 = sub16_vv(Rh_413_0, Rh_558_0);
      vector32 Rh_560_0 = sub16_vv(Rh_559_0, Rh_404_0);
      vector32 Rh_561_0 = add16_vv(Rh_560_0, lambda_onfcam4ccmt_line101_9_0);
      vector32 Rh_562_0 = rshift16_vv(Rh_561_0, srp_24_0);
      vector32 Bh_80_0 = mux16_vv(lambda_nfcam4defst_line56_64_0, Rh_562_0, ct8_87_0);
      vector32 ct8_93_0 = c_n8_0;
      vector32 ct8_134_0 = add16_vv(ct8_133_0, ct8_93_0);
      vector32 lambda_nfcam4defst_line64_155_0 = add16_vv(ct8_134_0, lambda_nfcam4defst_line49_53_0);
      vector32 lambda_nfcam4defst_line64_156_0 = and16_vv(lambda_nfcam4defst_line64_155_0, ct8_88_0);
      vector32 lambda_nfcam4defst_line64_157_0 = ne16_vv(lambda_nfcam4defst_line64_156_0, ct8_87_0);
      vector32 lambda_nfcam4defst_line64_158_0 = not16_vv(lambda_nfcam4defst_line64_157_0);
      vector32 Rv_127_0 = sub16_vv(Rv_121_0, Rh_486_0);
      vector32 Rv_128_0 = add16_vv(Rv_127_0, lambda_onfcam4ccmt_line101_5_0);
      vector32 Rv_129_0 = rshift16_vv(Rv_128_0, srp_11_0);
      vector32 Rv_130_0 = mux16_vv(lambda_nfcam4defst_line56_28_0, Rv_129_0, ct8_55_0);
      vector32 Rv_133_0 = add16_vv(Rh_428_0, Rv_130_0);
      vector32 Bv_73_0 = mux16_vv(lambda_nfcam4defst_line56_29_0, Rv_129_0, ct8_55_0);
      vector32 Bv_78_0 = add16_vv(Rh_428_0, Bv_73_0);
      vector32 Rv_131_0 = add16_vv(Rv_118_0, Rv_130_0);
      vector32 Bv_74_0 = add16_vv(Rv_118_0, Bv_73_0);
      vector32 mB_149_0 = eq16_vv(pix_66_0, lambda_onfcam4ccmt_line101_8_0);
      vector32 Bh_98_0 = mux16_vv(mB_149_0, Rh_404_0, Bh_73_0);
      vector32 Bh_99_0 = mux16_vv(mB_150_0, Bh_75_0, Bh_98_0);
      vector32 Rh_578_0 = mux16_vv(mB_149_0, Bh_73_0, Rh_404_0);
      vector32 Rh_390_0 = rshift16_vv(Rh_389_0, lambda_onfcam4dpct_line120_322_0);
      vector32 Rh_533_0 = add16_vv(Rh_390_0, Rh_532_0);
      vector32 Rh_579_0 = mux16_vv(mB_150_0, Rh_533_0, Rh_578_0);
      vector32 Rh_580_0 = mux16_vv(mB_151_0, Bh_75_0, Rh_579_0);
      vector32 Rh_581_pack_0 = Rh_580_0;
      vector32 Rh_491_0 = calcWbg_46_pp_2_5;
      vector32 Rh_492_0 = sub16_vv(Rh_418_0, Rh_491_0);
      vector32 Rh_500_0 = sub16_vv(Rh_492_0, Rh_499_0);
      vector32 Rh_501_0 = sub16_vv(Rh_500_0, Rh_404_0);
      vector32 Rh_502_0 = sub16_vv(Rh_501_0, Rh_411_0);
      vector32 Rh_503_0 = add16_vv(Rh_502_0, lambda_onfcam4ccmt_line101_6_0);
      vector32 Rh_504_0 = rshift16_vv(Rh_503_0, srp_14_0);
      vector32 Rv_149_0 = add16_vv(Rh_383_0, Rh_504_0);
      vector32 srp_25_0 = c_3_0;
      vector32 lambda_nfcam4defst_line49_54_0 = c_34_0;
      vector32 ct8_128_0 = sub16_vv(ct8_127_0, centroid_pos_1);
      vector32 ct8_130_0 = add16_vv(ct8_128_0, ct8_129_0);
      vector32 ct8_131_0 = add16_vv(ct8_130_0, ct8_90_0);
      vector32 lambda_nfcam4defst_line64_151_0 = add16_vv(ct8_131_0, lambda_nfcam4defst_line56_69_0);
      vector32 lambda_nfcam4defst_line64_152_0 = and16_vv(lambda_nfcam4defst_line64_151_0, ct8_88_0);
      vector32 lambda_nfcam4defst_line64_153_0 = ne16_vv(lambda_nfcam4defst_line64_152_0, ct8_87_0);
      vector32 lambda_nfcam4defst_line64_154_0 = not16_vv(lambda_nfcam4defst_line64_153_0);
      vector32 lambda_nfcam4defst_line64_159_0 = and16_vv(lambda_nfcam4defst_line64_154_0, lambda_nfcam4defst_line64_158_0);
      vector32 lambda_nfcam4defst_line64_160_0 = mux16_vv(lambda_nfcam4defst_line64_159_0, ct8_88_0, ct8_87_0);
      vector32 pix_71_0 = eq16_vv(lambda_nfcam4defst_line64_160_0, ct8_88_0);
      vector32 lambda_nfcam4defst_line88_31_0 = and16_vv(lambda_nfcam4defst_line64_153_0, lambda_nfcam4defst_line64_157_0);
      vector32 lambda_nfcam4defst_line88_32_0 = mux16_vv(lambda_nfcam4defst_line88_31_0, ct8_88_0, ct8_87_0);
      vector32 pix_69_0 = eq16_vv(lambda_nfcam4defst_line88_32_0, ct8_88_0);
      vector32 srp_9_0 = c_2_0;
      vector32 Rh_458_0 = rshift16_vv(Rh_457_0, srp_9_0);
      vector32 Bh_64_0 = mux16_vv(lambda_nfcam4defst_line56_29_0, Rh_458_0, ct8_55_0);
      vector32 Bh_67_0 = add16_vv(Rh_410_0, Bh_64_0);
      vector32 Rh_459_0 = mux16_vv(lambda_nfcam4defst_line56_28_0, Rh_458_0, ct8_55_0);
      vector32 Rh_463_0 = add16_vv(Rh_410_0, Rh_459_0);
      vector32 Rh_454_0 = rshift16_vv(Rh_453_0, lambda_onfcam4dpct_line120_324_0);
      vector32 Bh_83_0 = add16_vv(Rh_454_0, Bh_80_0);
      vector32 srp_23_0 = c_2_0;
      vector32 Rh_551_0 = rshift16_vv(Rh_550_0, srp_23_0);
      vector32 Rh_556_0 = rshift16_vv(Rh_555_0, srp_23_0);
      vector32 lambda_nfcam4defst_line56_41_0 = c_0x1_0;
      vector32 lambda_nfcam4defst_line49_32_0 = mux16_vv(lambda_nfcam4defst_line56_41_0, ct8_62_0, lambda_nfcam4defst_line49_31_0);
      vector32 lambda_nfcam4defst_line64_125_0 = add16_vv(ct8_110_0, lambda_nfcam4defst_line49_32_0);
      vector32 lambda_nfcam4defst_line64_126_0 = and16_vv(lambda_nfcam4defst_line64_125_0, ct8_63_0);
      vector32 lambda_nfcam4defst_line64_127_0 = ne16_vv(lambda_nfcam4defst_line64_126_0, ct8_62_0);
      vector32 lambda_nfcam4defst_line64_128_0 = not16_vv(lambda_nfcam4defst_line64_127_0);
      vector32 lambda_nfcam4defst_line56_42_0 = mux16_vv(lambda_nfcam4defst_line56_41_0, ct8_62_0, lambda_nfcam4defst_line56_40_0);
      vector32 lambda_nfcam4defst_line64_121_0 = add16_vv(ct8_107_0, lambda_nfcam4defst_line56_42_0);
      vector32 lambda_nfcam4defst_line56_44_0 = ne16_vv(lambda_nfcam4defst_line56_42_0, lambda_onfcam4ccmt_line101_6_0);
      vector32 lambda_nfcam4defst_line49_34_0 = ne16_vv(lambda_nfcam4defst_line49_32_0, lambda_onfcam4ccmt_line101_6_0);
      vector32 lambda_nfcam4defst_line64_122_0 = and16_vv(lambda_nfcam4defst_line64_121_0, ct8_63_0);
      vector32 lambda_nfcam4defst_line64_123_0 = ne16_vv(lambda_nfcam4defst_line64_122_0, ct8_62_0);
      vector32 lambda_nfcam4defst_line88_25_0 = and16_vv(lambda_nfcam4defst_line64_123_0, lambda_nfcam4defst_line64_127_0);
      vector32 lambda_nfcam4defst_line88_26_0 = mux16_vv(lambda_nfcam4defst_line88_25_0, ct8_63_0, ct8_62_0);
      vector32 lambda_nfcam4defst_line64_124_0 = not16_vv(lambda_nfcam4defst_line64_123_0);
      vector32 lambda_nfcam4defst_line80_21_0 = and16_vv(lambda_nfcam4defst_line64_124_0, lambda_nfcam4defst_line64_127_0);
      vector32 lambda_nfcam4defst_line64_129_0 = and16_vv(lambda_nfcam4defst_line64_124_0, lambda_nfcam4defst_line64_128_0);
      vector32 lambda_nfcam4defst_line80_22_0 = mux16_vv(lambda_nfcam4defst_line80_21_0, ct8_63_0, ct8_62_0);
      vector32 pix_49_0 = eq16_vv(lambda_nfcam4defst_line80_22_0, ct8_63_0);
      vector32 pix_50_0 = mux16_vv(pix_49_0, srp_16_0, lambda_onfcam4ccmt_line101_6_0);
      vector32 lambda_nfcam4defst_line64_130_0 = mux16_vv(lambda_nfcam4defst_line64_129_0, ct8_63_0, ct8_62_0);
      vector32 pix_53_0 = eq16_vv(lambda_nfcam4defst_line64_130_0, ct8_63_0);
      vector32 pix_51_0 = eq16_vv(lambda_nfcam4defst_line88_26_0, ct8_63_0);
      vector32 pix_52_0 = mux16_vv(pix_51_0, ct8_63_0, pix_50_0);
      vector32 pix_54_0 = mux16_vv(pix_53_0, ct8_62_0, pix_52_0);
      vector32 mB_145_0 = eq16_vv(pix_54_0, ct8_62_0);
      vector32 mB_143_0 = eq16_vv(pix_54_0, lambda_onfcam4ccmt_line101_6_0);
      vector32 offsetC_19_0 = eq16_vv(pix_54_0, srp_16_0);
      vector32 Bv_112_0 = mux16_vv(offsetC_19_0, Bv_83_0, ct8_62_0);
      vector32 Bv_113_0 = mux16_vv(mB_143_0, Rh_416_0, Bv_112_0);
      vector32 mB_144_0 = eq16_vv(pix_54_0, ct8_63_0);
      vector32 Bv_114_0 = mux16_vv(mB_144_0, Rv_149_0, Bv_113_0);
      vector32 Bv_115_0 = mux16_vv(mB_145_0, Bv_87_0, Bv_114_0);
      vector32 Bv_116_pack_0 = Bv_115_0;
      vector32 Gv_57_0 = mux16_vv(mB_144_0, Rh_416_0, Bv_87_0);
      vector32 Gv_58_0 = mux16_vv(mB_145_0, Rh_416_0, Gv_57_0);
      vector32 Gv_59_pack_0 = Gv_58_0;
      // max Gv_59_0 <= (Gv_59_pack_1 , Gv_59_pack_0)
      vector32 Gv_59_0_cotmp_1 = max16_vv(Gv_59_pack_1, Gv_59_pack_0);
      vector32 Gv_59_0 = Gv_59_0_cotmp_1;

      vector32 Rv_179_0 = mux16_vv(mB_143_0, Bv_83_0, Rh_416_0);
      vector32 Rv_180_0 = mux16_vv(mB_144_0, Bv_87_0, Rv_179_0);
      vector32 Rv_181_0 = mux16_vv(mB_145_0, Rv_149_0, Rv_180_0);
      vector32 Rv_182_pack_0 = Rv_181_0;
      // max Rv_182_0 <= (Rv_182_pack_1 , Rv_182_pack_0)
      vector32 Rv_182_0_cotmp_1 = max16_vv(Rv_182_pack_1, Rv_182_pack_0);
      vector32 Rv_182_0 = Rv_182_0_cotmp_1;

      vector32 Rv_183_pack_0 = Rv_182_0;
      // min Rv_183_0 <= (Rv_183_pack_1 , Rv_183_pack_0)
      vector32 Rv_183_0_cotmp_1 = min16_vv(Rv_183_pack_1, Rv_183_pack_0);
      vector32 Rv_183_0 = Rv_183_0_cotmp_1;

      // max Bv_116_0 <= (Bv_116_pack_1 , Bv_116_pack_0)
      vector32 Bv_116_0_cotmp_1 = max16_vv(Bv_116_pack_1, Bv_116_pack_0);
      vector32 Bv_116_0 = Bv_116_0_cotmp_1;

      vector32 Bv_117_pack_0 = Bv_116_0;
      // min Bv_117_0 <= (Bv_117_pack_1 , Bv_117_pack_0)
      vector32 Bv_117_0_cotmp_1 = min16_vv(Bv_117_pack_1, Bv_117_pack_0);
      vector32 Bv_117_0 = Bv_117_0_cotmp_1;

      vector32 calcDem_262_0 = sub16_vv(Rv_183_0, Bv_117_0);
      vector32 calcDem_263_0 = abs16_vv(calcDem_262_0);
      vector32 calcDem_273_pack_1 = calcDem_263_0;
      vector32 Bh_100_0 = mux16_vv(mB_151_0, Rh_533_0, Bh_99_0);
      vector32 Bh_101_pack_0 = Bh_100_0;
      vector32 lambda_nfcam4defst_line56_47_0 = mux16_vv(lambda_nfcam4defst_line56_46_0, ct8_71_0, lambda_onfcam4ccmt_line101_7_0);
      vector32 lambda_nfcam4defst_line56_48_0 = mux16_vv(lambda_nfcam4defst_line56_46_0, ct8_70_0, lambda_nfcam4defst_line56_47_0);
      vector32 lambda_nfcam4defst_line56_49_0 = mux16_vv(lambda_nfcam4defst_line56_46_0, ct8_71_0, lambda_nfcam4defst_line56_48_0);
      vector32 lambda_nfcam4defst_line56_51_0 = mux16_vv(lambda_nfcam4defst_line56_50_0, ct8_70_0, lambda_nfcam4defst_line56_49_0);
      vector32 lambda_nfcam4defst_line56_53_0 = ne16_vv(lambda_nfcam4defst_line56_51_0, lambda_onfcam4ccmt_line101_7_0);
      vector32 lambda_nfcam4defst_line64_131_0 = add16_vv(ct8_115_0, lambda_nfcam4defst_line56_51_0);
      vector32 lambda_nfcam4defst_line64_132_0 = and16_vv(lambda_nfcam4defst_line64_131_0, ct8_71_0);
      vector32 lambda_nfcam4defst_line64_133_0 = ne16_vv(lambda_nfcam4defst_line64_132_0, ct8_70_0);
      vector32 lambda_nfcam4defst_line88_27_0 = and16_vv(lambda_nfcam4defst_line64_133_0, lambda_nfcam4defst_line64_137_0);
      vector32 lambda_nfcam4defst_line64_134_0 = not16_vv(lambda_nfcam4defst_line64_133_0);
      vector32 lambda_nfcam4defst_line64_139_0 = and16_vv(lambda_nfcam4defst_line64_134_0, lambda_nfcam4defst_line64_138_0);
      vector32 lambda_nfcam4defst_line64_140_0 = mux16_vv(lambda_nfcam4defst_line64_139_0, ct8_71_0, ct8_70_0);
      vector32 lambda_nfcam4defst_line88_28_0 = mux16_vv(lambda_nfcam4defst_line88_27_0, ct8_71_0, ct8_70_0);
      vector32 pix_57_0 = eq16_vv(lambda_nfcam4defst_line88_28_0, ct8_71_0);
      vector32 lambda_nfcam4defst_line80_23_0 = and16_vv(lambda_nfcam4defst_line64_134_0, lambda_nfcam4defst_line64_137_0);
      vector32 lambda_nfcam4defst_line80_24_0 = mux16_vv(lambda_nfcam4defst_line80_23_0, ct8_71_0, ct8_70_0);
      vector32 pix_55_0 = eq16_vv(lambda_nfcam4defst_line80_24_0, ct8_71_0);
      vector32 pix_56_0 = mux16_vv(pix_55_0, srp_20_0, lambda_onfcam4ccmt_line101_7_0);
      vector32 pix_58_0 = mux16_vv(pix_57_0, ct8_71_0, pix_56_0);
      vector32 pix_59_0 = eq16_vv(lambda_nfcam4defst_line64_140_0, ct8_71_0);
      vector32 pix_60_0 = mux16_vv(pix_59_0, ct8_70_0, pix_58_0);
      vector32 mB_147_0 = eq16_vv(pix_60_0, ct8_71_0);
      vector32 Gv_61_0 = mux16_vv(mB_147_0, Rh_429_0, Bv_96_0);
      vector32 mB_146_0 = eq16_vv(pix_60_0, lambda_onfcam4ccmt_line101_7_0);
      vector32 mB_148_0 = eq16_vv(pix_60_0, ct8_70_0);
      vector32 Gv_62_0 = mux16_vv(mB_148_0, Rh_429_0, Gv_61_0);
      vector32 Gv_63_pack_0 = Gv_62_0;
      // max Gv_63_0 <= (Gv_63_pack_1 , Gv_63_pack_0)
      vector32 Gv_63_0_cotmp_1 = max16_vv(Gv_63_pack_1, Gv_63_pack_0);
      vector32 Gv_63_0 = Gv_63_0_cotmp_1;

      vector32 Gv_64_pack_0 = Gv_63_0;
      // min Gv_64_0 <= (Gv_64_pack_1 , Gv_64_pack_0)
      vector32 Gv_64_0_cotmp_1 = min16_vv(Gv_64_pack_1, Gv_64_pack_0);
      vector32 Gv_64_0 = Gv_64_0_cotmp_1;

      vector32 offsetC_20_0 = eq16_vv(pix_60_0, srp_20_0);
      vector32 Rh_552_0 = add16_vv(Rh_551_0, Rh_451_0);
      vector32 Bh_81_0 = add16_vv(Rh_552_0, Bh_80_0);
      vector32 lambda_nfcam4defst_line49_40_0 = c_34_0;
      vector32 Bh_101_pack_1 = ct8_79_0;
      // max Bh_101_0 <= (Bh_101_pack_1 , Bh_101_pack_0)
      vector32 Bh_101_0_cotmp_1 = max16_vv(Bh_101_pack_1, Bh_101_pack_0);
      vector32 Bh_101_0 = Bh_101_0_cotmp_1;

      vector32 Bh_102_pack_0 = Bh_101_0;
      // min Bh_102_0 <= (Bh_102_pack_1 , Bh_102_pack_0)
      vector32 Bh_102_0_cotmp_1 = min16_vv(Bh_102_pack_1, Bh_102_pack_0);
      vector32 Bh_102_0 = Bh_102_0_cotmp_1;

      vector32 lambda_nfcam4defst_line56_31_0 = mux16_vv(lambda_nfcam4defst_line56_29_0, ct8_55_0, lambda_nfcam4defst_line56_30_0);
      vector32 lambda_nfcam4defst_line56_32_0 = mux16_vv(lambda_nfcam4defst_line56_29_0, ct8_54_0, lambda_nfcam4defst_line56_31_0);
      vector32 lambda_nfcam4defst_line56_33_0 = mux16_vv(lambda_nfcam4defst_line56_28_0, ct8_55_0, lambda_nfcam4defst_line56_32_0);
      vector32 lambda_nfcam4defst_line56_35_0 = ne16_vv(lambda_nfcam4defst_line56_33_0, lambda_onfcam4ccmt_line101_5_0);
      vector32 lambda_nfcam4defst_line64_111_0 = add16_vv(ct8_99_0, lambda_nfcam4defst_line56_33_0);
      vector32 lambda_nfcam4defst_line64_112_0 = and16_vv(lambda_nfcam4defst_line64_111_0, ct8_54_0);
      vector32 lambda_nfcam4defst_line64_113_0 = ne16_vv(lambda_nfcam4defst_line64_112_0, ct8_55_0);
      vector32 lambda_nfcam4defst_line64_114_0 = not16_vv(lambda_nfcam4defst_line64_113_0);
      vector32 lambda_nfcam4defst_line88_23_0 = and16_vv(lambda_nfcam4defst_line64_113_0, lambda_nfcam4defst_line64_117_0);
      vector32 lambda_nfcam4defst_line80_19_0 = and16_vv(lambda_nfcam4defst_line64_114_0, lambda_nfcam4defst_line64_117_0);
      vector32 lambda_nfcam4defst_line88_24_0 = mux16_vv(lambda_nfcam4defst_line88_23_0, ct8_54_0, ct8_55_0);
      vector32 lambda_nfcam4defst_line80_20_0 = mux16_vv(lambda_nfcam4defst_line80_19_0, ct8_54_0, ct8_55_0);
      vector32 pix_45_0 = eq16_vv(lambda_nfcam4defst_line88_24_0, ct8_54_0);
      vector32 lambda_nfcam4defst_line64_119_0 = and16_vv(lambda_nfcam4defst_line64_114_0, lambda_nfcam4defst_line64_118_0);
      vector32 lambda_nfcam4defst_line64_120_0 = mux16_vv(lambda_nfcam4defst_line64_119_0, ct8_54_0, ct8_55_0);
      vector32 pix_47_0 = eq16_vv(lambda_nfcam4defst_line64_120_0, ct8_54_0);
      vector32 pix_43_0 = eq16_vv(lambda_nfcam4defst_line80_20_0, ct8_54_0);
      vector32 pix_44_0 = mux16_vv(pix_43_0, srp_10_0, lambda_onfcam4ccmt_line101_5_0);
      vector32 pix_46_0 = mux16_vv(pix_45_0, ct8_54_0, pix_44_0);
      vector32 lambda_nfcam4defst_line80_27_0 = and16_vv(lambda_nfcam4defst_line64_154_0, lambda_nfcam4defst_line64_157_0);
      vector32 lambda_nfcam4defst_line80_28_0 = mux16_vv(lambda_nfcam4defst_line80_27_0, ct8_88_0, ct8_87_0);
      vector32 pix_67_0 = eq16_vv(lambda_nfcam4defst_line80_28_0, ct8_88_0);
      vector32 pix_68_0 = mux16_vv(pix_67_0, srp_25_0, lambda_onfcam4ccmt_line101_9_0);
      vector32 lambda_nfcam4defst_line49_41_0 = ne16_vv(lambda_nfcam4defst_line49_39_0, lambda_onfcam4ccmt_line101_7_0);
      // max Rh_581_0 <= (Rh_581_pack_1 , Rh_581_pack_0)
      vector32 Rh_581_0_cotmp_1 = max16_vv(Rh_581_pack_1, Rh_581_pack_0);
      vector32 Rh_581_0 = Rh_581_0_cotmp_1;

      vector32 Rh_582_pack_0 = Rh_581_0;
      // min Rh_582_0 <= (Rh_582_pack_1 , Rh_582_pack_0)
      vector32 Rh_582_0_cotmp_1 = min16_vv(Rh_582_pack_1, Rh_582_pack_0);
      vector32 Rh_582_0 = Rh_582_0_cotmp_1;

      vector32 calcDem_288_0 = sub16_vv(Rh_582_0, Bh_102_0);
      vector32 calcDem_289_0 = abs16_vv(calcDem_288_0);
      vector32 calcDem_299_pack_1 = calcDem_289_0;
      vector32 Rh_401_0 = Rh_400_0;
      vector32 Rh_402_0 = add16_vv(Rh_401_0, ct8_88_0);
      vector32 Rh_403_0 = rshift16_vv(Rh_402_0, lambda_onfcam4dpct_line120_316_0);
      vector32 Rh_557_0 = add16_vv(Rh_403_0, Rh_556_0);
      vector32 pix_48_0 = mux16_vv(pix_47_0, ct8_55_0, pix_46_0);
      vector32 mB_142_0 = eq16_vv(pix_48_0, ct8_55_0);
      vector32 offsetC_18_0 = eq16_vv(pix_48_0, srp_10_0);
      vector32 mB_140_0 = eq16_vv(pix_48_0, lambda_onfcam4ccmt_line101_5_0);
      vector32 mB_141_0 = eq16_vv(pix_48_0, ct8_54_0);
      vector32 Bv_100_0 = mux16_vv(offsetC_18_0, Rv_131_0, ct8_55_0);
      vector32 Bv_101_0 = mux16_vv(mB_140_0, Rh_434_0, Bv_100_0);
      vector32 Bv_106_0 = mux16_vv(offsetC_18_0, Bv_74_0, ct8_55_0);
      vector32 Gv_49_0 = mux16_vv(mB_141_0, Rh_434_0, Bv_78_0);
      vector32 Gv_50_0 = mux16_vv(mB_141_0, Rh_434_0, Rv_133_0);
      vector32 Gv_54_0 = mux16_vv(mB_142_0, Rh_434_0, Gv_50_0);
      vector32 Gv_55_pack_0 = Gv_54_0;
      vector32 Bv_107_0 = mux16_vv(mB_140_0, Rh_434_0, Bv_106_0);
      vector32 Bv_108_0 = mux16_vv(mB_141_0, Rv_120_0, Bv_107_0);
      vector32 Gv_51_0 = mux16_vv(mB_142_0, Rh_434_0, Gv_49_0);
      vector32 Gv_52_pack_0 = Gv_51_0;
      // max Gv_52_0 <= (Gv_52_pack_1 , Gv_52_pack_0)
      vector32 Gv_52_0_cotmp_1 = max16_vv(Gv_52_pack_1, Gv_52_pack_0);
      vector32 Gv_52_0 = Gv_52_0_cotmp_1;

      vector32 Gv_53_pack_0 = Gv_52_0;
      // min Gv_53_0 <= (Gv_53_pack_1 , Gv_53_pack_0)
      vector32 Gv_53_0_cotmp_1 = min16_vv(Gv_53_pack_1, Gv_53_pack_0);
      vector32 Gv_53_0 = Gv_53_0_cotmp_1;

      vector32 calcDem_276_0 = sub16_vv(Gv_53_0, Gv_64_0);
      vector32 calcDem_277_0 = abs16_vv(calcDem_276_0);
      vector32 calcDem_278_pack_0 = calcDem_277_0;
      vector32 Gh_49_0 = mux16_vv(mB_141_0, Rh_434_0, Bh_67_0);
      vector32 Gh_51_0 = mux16_vv(mB_142_0, Rh_434_0, Gh_49_0);
      vector32 Gh_52_pack_0 = Gh_51_0;
      // max Gh_52_0 <= (Gh_52_pack_1 , Gh_52_pack_0)
      vector32 Gh_52_0_cotmp_1 = max16_vv(Gh_52_pack_1, Gh_52_pack_0);
      vector32 Gh_52_0 = Gh_52_0_cotmp_1;

      vector32 Gh_53_pack_0 = Gh_52_0;
      // min Gh_53_0 <= (Gh_53_pack_1 , Gh_53_pack_0)
      vector32 Gh_53_0_cotmp_1 = min16_vv(Gh_53_pack_1, Gh_53_pack_0);
      vector32 Gh_53_0 = Gh_53_0_cotmp_1;

      vector32 Bv_102_0 = mux16_vv(mB_141_0, Rv_120_0, Bv_101_0);
      vector32 Bv_103_0 = mux16_vv(mB_142_0, Rv_133_0, Bv_102_0);
      vector32 Bv_104_pack_0 = Bv_103_0;
      // max Bv_104_0 <= (Bv_104_pack_1 , Bv_104_pack_0)
      vector32 Bv_104_0_cotmp_1 = max16_vv(Bv_104_pack_1, Bv_104_pack_0);
      vector32 Bv_104_0 = Bv_104_0_cotmp_1;

      vector32 Bv_105_pack_0 = Bv_104_0;
      // min Bv_105_0 <= (Bv_105_pack_1 , Bv_105_pack_0)
      vector32 Bv_105_0_cotmp_1 = min16_vv(Bv_105_pack_1, Bv_105_pack_0);
      vector32 Bv_105_0 = Bv_105_0_cotmp_1;

      vector32 Rv_170_0 = mux16_vv(mB_140_0, Rv_131_0, Rh_434_0);
      vector32 Rv_172_0 = mux16_vv(mB_141_0, Rv_133_0, Rv_170_0);
      vector32 Rv_176_0 = mux16_vv(mB_142_0, Rv_120_0, Rv_172_0);
      vector32 Rv_177_pack_0 = Rv_176_0;
      // max Rv_177_0 <= (Rv_177_pack_1 , Rv_177_pack_0)
      vector32 Rv_177_0_cotmp_1 = max16_vv(Rv_177_pack_1, Rv_177_pack_0);
      vector32 Rv_177_0 = Rv_177_0_cotmp_1;

      // max Gv_55_0 <= (Gv_55_pack_1 , Gv_55_pack_0)
      vector32 Gv_55_0_cotmp_1 = max16_vv(Gv_55_pack_1, Gv_55_pack_0);
      vector32 Gv_55_0 = Gv_55_0_cotmp_1;

      vector32 Gv_56_pack_0 = Gv_55_0;
      // min Gv_56_0 <= (Gv_56_pack_1 , Gv_56_pack_0)
      vector32 Gv_56_0_cotmp_1 = min16_vv(Gv_56_pack_1, Gv_56_pack_0);
      vector32 Gv_56_0 = Gv_56_0_cotmp_1;

      vector32 calcDem_290_0 = sub16_vv(Gh_53_0, Gh_60_0);
      vector32 calcDem_291_0 = abs16_vv(calcDem_290_0);
      vector32 calcDem_292_pack_0 = calcDem_291_0;
      vector32 Rv_169_0 = mux16_vv(mB_140_0, Bv_74_0, Rh_434_0);
      vector32 Rv_171_0 = mux16_vv(mB_141_0, Bv_78_0, Rv_169_0);
      vector32 Rv_173_0 = mux16_vv(mB_142_0, Rv_120_0, Rv_171_0);
      vector32 Rv_174_pack_0 = Rv_173_0;
      // max Rv_174_0 <= (Rv_174_pack_1 , Rv_174_pack_0)
      vector32 Rv_174_0_cotmp_1 = max16_vv(Rv_174_pack_1, Rv_174_pack_0);
      vector32 Rv_174_0 = Rv_174_0_cotmp_1;

      vector32 Rv_175_pack_0 = Rv_174_0;
      // min Rv_175_0 <= (Rv_175_pack_1 , Rv_175_pack_0)
      vector32 Rv_175_0_cotmp_1 = min16_vv(Rv_175_pack_1, Rv_175_pack_0);
      vector32 Rv_175_0 = Rv_175_0_cotmp_1;

      vector32 calcDem_260_0 = sub16_vv(Rv_175_0, Rv_183_0);
      vector32 calcDem_261_0 = abs16_vv(calcDem_260_0);
      vector32 calcDem_266_pack_2 = calcDem_261_0;
      vector32 Gh_50_0 = mux16_vv(mB_141_0, Rh_434_0, Rh_463_0);
      vector32 Gh_54_0 = mux16_vv(mB_142_0, Rh_434_0, Gh_50_0);
      vector32 Gh_55_pack_0 = Gh_54_0;
      vector32 Rv_178_pack_0 = Rv_177_0;
      // min Rv_178_0 <= (Rv_178_pack_1 , Rv_178_pack_0)
      vector32 Rv_178_0_cotmp_1 = min16_vv(Rv_178_pack_1, Rv_178_pack_0);
      vector32 Rv_178_0 = Rv_178_0_cotmp_1;

      vector32 Gh_55_pack_1 = ct8_55_0;
      // max Gh_55_0 <= (Gh_55_pack_1 , Gh_55_pack_0)
      vector32 Gh_55_0_cotmp_1 = max16_vv(Gh_55_pack_1, Gh_55_pack_0);
      vector32 Gh_55_0 = Gh_55_0_cotmp_1;

      vector32 Gh_56_pack_0 = Gh_55_0;
      // min Gh_56_0 <= (Gh_56_pack_1 , Gh_56_pack_0)
      vector32 Gh_56_0_cotmp_1 = min16_vv(Gh_56_pack_1, Gh_56_pack_0);
      vector32 Gh_56_0 = Gh_56_0_cotmp_1;

      vector32 calcDem_247_0 = add16_vv(Gh_56_0, Gv_56_0);
      vector32 calcDem_248_0 = add16_vv(calcDem_247_0, ct8_54_0);
      vector32 calcDem_249_0 = rshift16_vv(calcDem_248_0, lambda_onfcam4dpct_line120_315_0);
      vector32 Gv_60_pack_0 = Gv_59_0;
      // min Gv_60_0 <= (Gv_60_pack_1 , Gv_60_pack_0)
      vector32 Gv_60_0_cotmp_1 = min16_vv(Gv_60_pack_1, Gv_60_pack_0);
      vector32 Gv_60_0 = Gv_60_0_cotmp_1;

      vector32 calcDem_264_0 = sub16_vv(Gv_53_0, Gv_60_0);
      vector32 calcDem_265_0 = abs16_vv(calcDem_264_0);
      vector32 calcDem_266_pack_0 = calcDem_265_0;
      vector32 Bv_109_0 = mux16_vv(mB_142_0, Bv_78_0, Bv_108_0);
      vector32 Bv_110_pack_0 = Bv_109_0;
      // max Bv_110_0 <= (Bv_110_pack_1 , Bv_110_pack_0)
      vector32 Bv_110_0_cotmp_1 = max16_vv(Bv_110_pack_1, Bv_110_pack_0);
      vector32 Bv_110_0 = Bv_110_0_cotmp_1;

      vector32 Bv_111_pack_0 = Bv_110_0;
      // min Bv_111_0 <= (Bv_111_pack_1 , Bv_111_pack_0)
      vector32 Bv_111_0_cotmp_1 = min16_vv(Bv_111_pack_1, Bv_111_pack_0);
      vector32 Bv_111_0 = Bv_111_0_cotmp_1;

      vector32 calcDem_256_0 = sub16_vv(Rv_175_0, Bv_111_0);
      vector32 calcDem_257_0 = abs16_vv(calcDem_256_0);
      vector32 calcDem_258_0 = sub16_vv(Bv_111_0, Bv_117_0);
      vector32 calcDem_259_0 = abs16_vv(calcDem_258_0);
      vector32 calcDem_266_pack_1 = calcDem_259_0;
      // max calcDem_266_0 <= (calcDem_266_pack_2 , calcDem_266_pack_1 , calcDem_266_pack_0)
      vector32 calcDem_266_0_cotmp_1 = max16_vv(calcDem_266_pack_2, calcDem_266_pack_1);
      vector32 calcDem_266_0_cotmp_2 = max16_vv(calcDem_266_0_cotmp_1, calcDem_266_pack_0);
      vector32 calcDem_266_0 = calcDem_266_0_cotmp_2;

      vector32 calcDem_279_pack_0 = calcDem_266_0;
      vector32 calcDem_273_pack_0 = calcDem_257_0;
      vector32 pix_70_0 = mux16_vv(pix_69_0, ct8_88_0, pix_68_0);
      vector32 pix_72_0 = mux16_vv(pix_71_0, ct8_87_0, pix_70_0);
      vector32 mB_154_0 = eq16_vv(pix_72_0, ct8_87_0);
      vector32 mB_153_0 = eq16_vv(pix_72_0, ct8_88_0);
      vector32 Gh_61_0 = mux16_vv(mB_153_0, Rh_411_0, Bh_83_0);
      vector32 Gh_62_0 = mux16_vv(mB_154_0, Rh_411_0, Gh_61_0);
      vector32 mB_152_0 = eq16_vv(pix_72_0, lambda_onfcam4ccmt_line101_9_0);
      vector32 Rh_583_0 = mux16_vv(mB_152_0, Bh_81_0, Rh_411_0);
      vector32 Rh_584_0 = mux16_vv(mB_153_0, Rh_557_0, Rh_583_0);
      vector32 Rh_585_0 = mux16_vv(mB_154_0, Bh_83_0, Rh_584_0);
      vector32 Rh_586_pack_0 = Rh_585_0;
      vector32 Bh_103_0 = mux16_vv(mB_152_0, Rh_411_0, Bh_81_0);
      vector32 Bh_104_0 = mux16_vv(mB_153_0, Bh_83_0, Bh_103_0);
      // max Rh_586_0 <= (Rh_586_pack_1 , Rh_586_pack_0)
      vector32 Rh_586_0_cotmp_1 = max16_vv(Rh_586_pack_1, Rh_586_pack_0);
      vector32 Rh_586_0 = Rh_586_0_cotmp_1;

      vector32 Rh_587_pack_0 = Rh_586_0;
      vector32 Bh_105_0 = mux16_vv(mB_154_0, Rh_557_0, Bh_104_0);
      vector32 Bh_106_pack_0 = Bh_105_0;
      // max Bh_106_0 <= (Bh_106_pack_1 , Bh_106_pack_0)
      vector32 Bh_106_0_cotmp_1 = max16_vv(Bh_106_pack_1, Bh_106_pack_0);
      vector32 Bh_106_0 = Bh_106_0_cotmp_1;

      vector32 Bh_107_pack_0 = Bh_106_0;
      // min Bh_107_0 <= (Bh_107_pack_1 , Bh_107_pack_0)
      vector32 Bh_107_0_cotmp_1 = min16_vv(Bh_107_pack_1, Bh_107_pack_0);
      vector32 Bh_107_0 = Bh_107_0_cotmp_1;

      vector32 Gh_63_pack_0 = Gh_62_0;
      // max Gh_63_0 <= (Gh_63_pack_1 , Gh_63_pack_0)
      vector32 Gh_63_0_cotmp_1 = max16_vv(Gh_63_pack_1, Gh_63_pack_0);
      vector32 Gh_63_0 = Gh_63_0_cotmp_1;

      vector32 Gh_64_pack_0 = Gh_63_0;
      // min Rh_587_0 <= (Rh_587_pack_1 , Rh_587_pack_0)
      vector32 Rh_587_0_cotmp_1 = min16_vv(Rh_587_pack_1, Rh_587_pack_0);
      vector32 Rh_587_0 = Rh_587_0_cotmp_1;

      vector32 calcDem_297_0 = sub16_vv(Rh_587_0, Bh_107_0);
      vector32 calcDem_298_0 = abs16_vv(calcDem_297_0);
      vector32 calcDem_299_pack_2 = calcDem_298_0;
      vector32 Rh_424_0 = add16_vv(Rh_394_0, Rh_423_0);
      vector32 Bh_65_0 = add16_vv(Rh_424_0, Bh_64_0);
      vector32 Bh_89_0 = mux16_vv(mB_140_0, Rh_434_0, Bh_65_0);
      vector32 Bh_91_0 = mux16_vv(mB_141_0, Bh_67_0, Bh_89_0);
      vector32 Rh_460_0 = add16_vv(Rh_424_0, Rh_459_0);
      vector32 Rh_568_0 = mux16_vv(mB_140_0, Bh_65_0, Rh_434_0);
      vector32 Rh_569_0 = mux16_vv(mB_140_0, Rh_460_0, Rh_434_0);
      vector32 Rh_570_0 = mux16_vv(mB_141_0, Rh_443_0, Rh_568_0);
      vector32 Rh_572_0 = mux16_vv(mB_142_0, Bh_67_0, Rh_570_0);
      vector32 Rh_571_0 = mux16_vv(mB_141_0, Rh_443_0, Rh_569_0);
      vector32 Rh_575_0 = mux16_vv(mB_142_0, Rh_463_0, Rh_571_0);
      vector32 Rh_576_pack_0 = Rh_575_0;
      // max Rh_576_0 <= (Rh_576_pack_1 , Rh_576_pack_0)
      vector32 Rh_576_0_cotmp_1 = max16_vv(Rh_576_pack_1, Rh_576_pack_0);
      vector32 Rh_576_0 = Rh_576_0_cotmp_1;

      vector32 Rh_577_pack_0 = Rh_576_0;
      // min Rh_577_0 <= (Rh_577_pack_1 , Rh_577_pack_0)
      vector32 Rh_577_0_cotmp_1 = min16_vv(Rh_577_pack_1, Rh_577_pack_0);
      vector32 Rh_577_0 = Rh_577_0_cotmp_1;

      vector32 Rh_573_pack_0 = Rh_572_0;
      // max Rh_573_0 <= (Rh_573_pack_1 , Rh_573_pack_0)
      vector32 Rh_573_0_cotmp_1 = max16_vv(Rh_573_pack_1, Rh_573_pack_0);
      vector32 Rh_573_0 = Rh_573_0_cotmp_1;

      vector32 Rh_574_pack_0 = Rh_573_0;
      // min Rh_574_0 <= (Rh_574_pack_1 , Rh_574_pack_0)
      vector32 Rh_574_0_cotmp_1 = min16_vv(Rh_574_pack_1, Rh_574_pack_0);
      vector32 Rh_574_0 = Rh_574_0_cotmp_1;

      vector32 calcDem_286_0 = sub16_vv(Rh_574_0, Rh_582_0);
      vector32 calcDem_250_0 = add16_vv(Rh_577_0, Rv_178_0);
      vector32 calcDem_251_0 = add16_vv(calcDem_250_0, ct8_54_0);
      vector32 calcDem_252_0 = rshift16_vv(calcDem_251_0, lambda_onfcam4dpct_line120_315_0);
      vector32 calcDem_295_0 = sub16_vv(Rh_574_0, Rh_587_0);
      vector32 calcDem_296_0 = abs16_vv(calcDem_295_0);
      vector32 calcDem_304_pack_2 = calcDem_296_0;
      vector32 Bh_88_0 = mux16_vv(mB_140_0, Rh_434_0, Rh_460_0);
      vector32 Bh_90_0 = mux16_vv(mB_141_0, Rh_463_0, Bh_88_0);
      vector32 Bh_92_0 = mux16_vv(mB_142_0, Rh_443_0, Bh_90_0);
      vector32 Bh_93_pack_0 = Bh_92_0;
      // max Bh_93_0 <= (Bh_93_pack_1 , Bh_93_pack_0)
      vector32 Bh_93_0_cotmp_1 = max16_vv(Bh_93_pack_1, Bh_93_pack_0);
      vector32 Bh_93_0 = Bh_93_0_cotmp_1;

      vector32 Bh_94_pack_0 = Bh_93_0;
      // min Bh_94_0 <= (Bh_94_pack_1 , Bh_94_pack_0)
      vector32 Bh_94_0_cotmp_1 = min16_vv(Bh_94_pack_1, Bh_94_pack_0);
      vector32 Bh_94_0 = Bh_94_0_cotmp_1;

      vector32 calcDem_253_0 = add16_vv(Bh_94_0, Bv_105_0);
      vector32 calcDem_254_0 = add16_vv(calcDem_253_0, ct8_54_0);
      vector32 calcDem_255_0 = rshift16_vv(calcDem_254_0, lambda_onfcam4dpct_line120_315_0);
      vector32 calcDem_287_0 = abs16_vv(calcDem_286_0);
      vector32 calcDem_292_pack_2 = calcDem_287_0;
      vector32 Bh_95_0 = mux16_vv(mB_142_0, Rh_443_0, Bh_91_0);
      vector32 Bh_96_pack_0 = Bh_95_0;
      // max Bh_96_0 <= (Bh_96_pack_1 , Bh_96_pack_0)
      vector32 Bh_96_0_cotmp_1 = max16_vv(Bh_96_pack_1, Bh_96_pack_0);
      vector32 Bh_96_0 = Bh_96_0_cotmp_1;

      vector32 Bh_97_pack_0 = Bh_96_0;
      // min Bh_97_0 <= (Bh_97_pack_1 , Bh_97_pack_0)
      vector32 Bh_97_0_cotmp_1 = min16_vv(Bh_97_pack_1, Bh_97_pack_0);
      vector32 Bh_97_0 = Bh_97_0_cotmp_1;

      vector32 calcDem_293_0 = sub16_vv(Bh_97_0, Bh_107_0);
      vector32 calcDem_245_0 = sub16_vv(Rh_574_0, Bh_97_0);
      vector32 calcDem_284_0 = sub16_vv(Bh_97_0, Bh_102_0);
      vector32 calcDem_246_0 = abs16_vv(calcDem_245_0);
      vector32 calcDem_299_pack_0 = calcDem_246_0;
      // max calcDem_299_0 <= (calcDem_299_pack_2 , calcDem_299_pack_1 , calcDem_299_pack_0)
      vector32 calcDem_299_0_cotmp_1 = max16_vv(calcDem_299_pack_2, calcDem_299_pack_1);
      vector32 calcDem_299_0_cotmp_2 = max16_vv(calcDem_299_0_cotmp_1, calcDem_299_pack_0);
      vector32 calcDem_299_0 = calcDem_299_0_cotmp_2;

      vector32 calcDem_300_0 = mult16_vv(calcDem_23_0, calcDem_299_0);
      vector32 calcDem_301_0 = rshift16_vv(calcDem_300_0, ct8_78_0);
      vector32 calcDem_285_0 = abs16_vv(calcDem_284_0);
      vector32 calcDem_292_pack_1 = calcDem_285_0;
      vector32 calcDem_294_0 = abs16_vv(calcDem_293_0);
      vector32 calcDem_304_pack_1 = calcDem_294_0;
      // max calcDem_292_0 <= (calcDem_292_pack_2 , calcDem_292_pack_1 , calcDem_292_pack_0)
      vector32 calcDem_292_0_cotmp_1 = max16_vv(calcDem_292_pack_2, calcDem_292_pack_1);
      vector32 calcDem_292_0_cotmp_2 = max16_vv(calcDem_292_0_cotmp_1, calcDem_292_pack_0);
      vector32 calcDem_292_0 = calcDem_292_0_cotmp_2;

      vector32 calcDem_305_pack_0 = calcDem_292_0;
      vector32 Gh_64_pack_1 = cnr_9_0;
      // min Gh_64_0 <= (Gh_64_pack_1 , Gh_64_pack_0)
      vector32 Gh_64_0_cotmp_1 = min16_vv(Gh_64_pack_1, Gh_64_pack_0);
      vector32 Gh_64_0 = Gh_64_0_cotmp_1;

      vector32 calcDem_302_0 = sub16_vv(Gh_53_0, Gh_64_0);
      vector32 calcDem_303_0 = abs16_vv(calcDem_302_0);
      vector32 calcDem_304_pack_0 = calcDem_303_0;
      // max calcDem_304_0 <= (calcDem_304_pack_2 , calcDem_304_pack_1 , calcDem_304_pack_0)
      vector32 calcDem_304_0_cotmp_1 = max16_vv(calcDem_304_pack_2, calcDem_304_pack_1);
      vector32 calcDem_304_0_cotmp_2 = max16_vv(calcDem_304_0_cotmp_1, calcDem_304_pack_0);
      vector32 calcDem_304_0 = calcDem_304_0_cotmp_2;

      vector32 calcDem_305_pack_1 = calcDem_304_0;
      // max calcDem_305_0 <= (calcDem_305_pack_1 , calcDem_305_pack_0)
      vector32 calcDem_305_0_cotmp_1 = max16_vv(calcDem_305_pack_1, calcDem_305_pack_0);
      vector32 calcDem_305_0 = calcDem_305_0_cotmp_1;

      vector32 calcDem_306_0 = mult16_vv(calcDem_4_0, calcDem_305_0);
      vector32 calcDem_307_0 = rshift16_vv(calcDem_306_0, calcDem_21_0);
      vector32 calcDem_308_0 = add16_vv(calcDem_307_0, calcDem_301_0);
      vector32 calcDem_309_0 = add16_vv(calcDem_308_0, calcDem_61_0);
      vector32 Rv_146_0 = add16_vv(Rv_145_0, lambda_onfcam4ccmt_line101_7_0);
      vector32 Rv_147_0 = rshift16_vv(Rv_146_0, lambda_onfcam4dpct_line120_319_0);
      vector32 Rv_159_0 = add16_vv(Rh_512_0, Rv_147_0);
      vector32 Bv_92_0 = add16_vv(Rv_159_0, Bv_91_0);
      vector32 Bv_118_0 = mux16_vv(offsetC_20_0, Bv_92_0, ct8_70_0);
      vector32 Bv_119_0 = mux16_vv(mB_146_0, Rh_429_0, Bv_118_0);
      vector32 Bv_120_0 = mux16_vv(mB_147_0, Rv_160_0, Bv_119_0);
      vector32 Rv_184_0 = mux16_vv(mB_146_0, Bv_92_0, Rh_429_0);
      vector32 Bv_121_0 = mux16_vv(mB_148_0, Bv_96_0, Bv_120_0);
      vector32 Bv_122_pack_0 = Bv_121_0;
      // max Bv_122_0 <= (Bv_122_pack_1 , Bv_122_pack_0)
      vector32 Bv_122_0_cotmp_1 = max16_vv(Bv_122_pack_1, Bv_122_pack_0);
      vector32 Bv_122_0 = Bv_122_0_cotmp_1;

      vector32 Rv_185_0 = mux16_vv(mB_147_0, Bv_96_0, Rv_184_0);
      vector32 Rv_186_0 = mux16_vv(mB_148_0, Rv_160_0, Rv_185_0);
      vector32 Rv_187_pack_0 = Rv_186_0;
      // max Rv_187_0 <= (Rv_187_pack_1 , Rv_187_pack_0)
      vector32 Rv_187_0_cotmp_1 = max16_vv(Rv_187_pack_1, Rv_187_pack_0);
      vector32 Rv_187_0 = Rv_187_0_cotmp_1;

      vector32 Rv_188_pack_0 = Rv_187_0;
      // min Rv_188_0 <= (Rv_188_pack_1 , Rv_188_pack_0)
      vector32 Rv_188_0_cotmp_1 = min16_vv(Rv_188_pack_1, Rv_188_pack_0);
      vector32 Rv_188_0 = Rv_188_0_cotmp_1;

      vector32 calcDem_269_0 = sub16_vv(Rv_175_0, Rv_188_0);
      vector32 calcDem_270_0 = abs16_vv(calcDem_269_0);
      vector32 calcDem_278_pack_2 = calcDem_270_0;
      vector32 Bv_123_pack_0 = Bv_122_0;
      // min Bv_123_0 <= (Bv_123_pack_1 , Bv_123_pack_0)
      vector32 Bv_123_0_cotmp_1 = min16_vv(Bv_123_pack_1, Bv_123_pack_0);
      vector32 Bv_123_0 = Bv_123_0_cotmp_1;

      vector32 calcDem_267_0 = sub16_vv(Bv_111_0, Bv_123_0);
      vector32 calcDem_268_0 = abs16_vv(calcDem_267_0);
      vector32 calcDem_278_pack_1 = calcDem_268_0;
      // max calcDem_278_0 <= (calcDem_278_pack_2 , calcDem_278_pack_1 , calcDem_278_pack_0)
      vector32 calcDem_278_0_cotmp_1 = max16_vv(calcDem_278_pack_2, calcDem_278_pack_1);
      vector32 calcDem_278_0_cotmp_2 = max16_vv(calcDem_278_0_cotmp_1, calcDem_278_pack_0);
      vector32 calcDem_278_0 = calcDem_278_0_cotmp_2;

      vector32 calcDem_279_pack_1 = calcDem_278_0;
      // max calcDem_279_0 <= (calcDem_279_pack_1 , calcDem_279_pack_0)
      vector32 calcDem_279_0_cotmp_1 = max16_vv(calcDem_279_pack_1, calcDem_279_pack_0);
      vector32 calcDem_279_0 = calcDem_279_0_cotmp_1;

      vector32 calcDem_280_0 = mult16_vv(calcDem_4_0, calcDem_279_0);
      vector32 calcDem_281_0 = rshift16_vv(calcDem_280_0, calcDem_21_0);
      vector32 calcDem_271_0 = sub16_vv(Rv_188_0, Bv_123_0);
      vector32 calcDem_272_0 = abs16_vv(calcDem_271_0);
      vector32 calcDem_273_pack_2 = calcDem_272_0;
      // max calcDem_273_0 <= (calcDem_273_pack_2 , calcDem_273_pack_1 , calcDem_273_pack_0)
      vector32 calcDem_273_0_cotmp_1 = max16_vv(calcDem_273_pack_2, calcDem_273_pack_1);
      vector32 calcDem_273_0_cotmp_2 = max16_vv(calcDem_273_0_cotmp_1, calcDem_273_pack_0);
      vector32 calcDem_273_0 = calcDem_273_0_cotmp_2;

      vector32 calcDem_274_0 = mult16_vv(calcDem_23_0, calcDem_273_0);
      vector32 calcDem_275_0 = rshift16_vv(calcDem_274_0, ct8_78_0);
      vector32 calcDem_282_0 = add16_vv(calcDem_281_0, calcDem_275_0);
      vector32 calcDem_283_0 = add16_vv(calcDem_282_0, calcDem_61_0);
      vector32 calcDem_310_0 = gt16_vv(calcDem_282_0, calcDem_309_0);
      vector32 calcDem_311_0 = mux16_vv(calcDem_310_0, Bh_94_0, calcDem_255_0);
      vector32 calcDem_312_0 = mux16_vv(calcDem_310_0, Gh_56_0, calcDem_249_0);
      vector32 calcDem_313_0 = mux16_vv(calcDem_310_0, Rh_577_0, calcDem_252_0);
      vector32 calcDem_314_0 = gt16_vv(calcDem_308_0, calcDem_283_0);
      vector32 calcDem_315_0 = mux16_vv(calcDem_314_0, Bv_105_0, calcDem_311_0);
      vector32 calcDem_316_pack_0 = calcDem_315_0;
      vector32 calcDem_318_0 = mux16_vv(calcDem_314_0, Gv_56_0, calcDem_312_0);
      vector32 calcDem_319_pack_0 = calcDem_318_0;
      vector32 calcDem_321_0 = mux16_vv(calcDem_314_0, Rv_178_0, calcDem_313_0);
      vector32 calcDem_322_pack_0 = calcDem_321_0;
      // max calcDem_316_0 <= (calcDem_316_pack_1 , calcDem_316_pack_0)
      vector32 calcDem_316_0_cotmp_1 = max16_vv(calcDem_316_pack_1, calcDem_316_pack_0);
      vector32 calcDem_316_0 = calcDem_316_0_cotmp_1;

      // max calcDem_319_0 <= (calcDem_319_pack_1 , calcDem_319_pack_0)
      vector32 calcDem_319_0_cotmp_1 = max16_vv(calcDem_319_pack_1, calcDem_319_pack_0);
      vector32 calcDem_319_0 = calcDem_319_0_cotmp_1;

      vector32 calcDem_320_pack_0 = calcDem_319_0;
      // min calcDem_320_0 <= (calcDem_320_pack_1 , calcDem_320_pack_0)
      vector32 calcDem_320_0_cotmp_1 = min16_vv(calcDem_320_pack_1, calcDem_320_pack_0);
      vector32 calcDem_320_0 = calcDem_320_0_cotmp_1;

      vector32 calcDem_324_1 = calcDem_320_0;
      vector32 calcDem_317_pack_0 = calcDem_316_0;
      // min calcDem_317_0 <= (calcDem_317_pack_1 , calcDem_317_pack_0)
      vector32 calcDem_317_0_cotmp_1 = min16_vv(calcDem_317_pack_1, calcDem_317_pack_0);
      vector32 calcDem_317_0 = calcDem_317_0_cotmp_1;

      vector32 calcDem_324_0 = calcDem_317_0;
      // max calcDem_322_0 <= (calcDem_322_pack_1 , calcDem_322_pack_0)
      vector32 calcDem_322_0_cotmp_1 = max16_vv(calcDem_322_pack_1, calcDem_322_pack_0);
      vector32 calcDem_322_0 = calcDem_322_0_cotmp_1;

      vector32 calcDem_323_pack_0 = calcDem_322_0;
      // min calcDem_323_0 <= (calcDem_323_pack_1 , calcDem_323_pack_0)
      vector32 calcDem_323_0_cotmp_1 = min16_vv(calcDem_323_pack_1, calcDem_323_pack_0);
      vector32 calcDem_323_0 = calcDem_323_0_cotmp_1;

      vector32 calcDem_324_2 = calcDem_323_0;
      out_ptr[y*IN_WIDTH*OUT_CHANNELS + x*OUT_CHANNELS + 2] = calcDem_324_2;
      out_ptr[y*IN_WIDTH*OUT_CHANNELS + x*OUT_CHANNELS + 1] = calcDem_324_1;
      out_ptr[y*IN_WIDTH*OUT_CHANNELS + x*OUT_CHANNELS + 0] = calcDem_324_0;
    }
  }
  
  // End SAIF power toggle data capture
  set_power_toggle(POWER_TOGGLE_OFF);
} // END calcDem_3

