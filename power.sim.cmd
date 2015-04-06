
./soc_go -vcs -lib64 -pluscomp="-ld gcc-4.4" -clock_period 10 -power -user_power -prog ../verification/RefTestbench/example/example_power.out -rundir tmp 

./soc_go -vcs -lib64 -pluscomp="-ld gcc-4.4" -gate ../my_xda/layout_icc/Xttop_routed.v -clock_period 10 -power -user_power -prog ../verification/RefTestbench/example/example_power.out -csf ../my_xda/CadSetup.file

./scripts/gate_level_power/Gate_Level_Power.pl -netlist layout_icc/Xttop_routed.v -csf ./CadSetup.file  -prog ../verification/RefTestbench/example/example_power.out -rundir ../scripts/soc_results_gate  -spef layout_icc/Xttop_routed.spef.max.gz

===========

./soc_go -vcs -lib64 -pluscomp="-ld gcc-4.4" -clock_period 10 -power -user_power -trace -cyclmt 3000000 -prog ~/projects/vision_core/clib/test_nms.rtl -rundir my_rtl_sim_test_nms


./soc_go -vcs -lib64 -pluscomp="-ld gcc-4.4"  -gate ../my_xda_500/layout_icc/Xttop_routed.v  -clock_period 10 -power -user_power  -csf ../my_xda_500/CadSetup.file  -cyclmt 3000000 -prog ~/projects/vision_core/clib/test_nms.rtl -rundir my_gate_sim_test_nms

./scripts/gate_level_power/Gate_Level_Power.pl -netlist layout_icc/Xttop_routed.v -csf ./CadSetup.file  -spef layout_icc/Xttop_routed.spef.max.gz  -prog ~/projects/vision_core/clib/test_cast13.rtl -rundir ../scripts/my_gate_sim_test_cast13 -resultsdir ./gate_power_test_cast13