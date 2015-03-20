
./soc_go -vcs -lib64 -pluscomp="-ld gcc-4.4" -clock_period 10 -power -user_power -prog ../verification/RefTestbench/example/example_power.out -rundir tmp 

./soc_go -vcs -lib64 -pluscomp="-ld gcc-4.4" -gate ../my_xda/layout_icc/Xttop_routed.v -clock_period 10 -power -user_power -prog ../verification/RefTestbench/example/example_power.out -csf ../my_xda/CadSetup.file

./scripts/gate_level_power/Gate_Level_Power.pl -netlist layout_icc/Xttop_routed.v -csf ./CadSetup.file  -prog ../verification/RefTestbench/example/example_power.out -rundir ../scripts/soc_results_gate  -spef layout_icc/Xttop_routed.spef.max.gz

===========

./soc_go -vcs -lib64 -pluscomp="-ld gcc-4.4" -clock_period 10  -cyclmt 2000000 -power -user_power -trace -prog ~/projects/vision_core/clib/downcast_15_O3 -rundir my_rtl_downcast_15_O3


./soc_go -vcs -lib64 -pluscomp="-ld gcc-4.4"  -gate ../my_xda_500_hier/layout_icc/Xttop_routed.v  -clock_period 10 -power -user_power  -csf ../my_xda_500_hier/CadSetup.file  -cyclmt 2000000 -prog ~/projects/vision_core/clib/downcast_15_O3 -rundir my_gate_downcast_15_O3


./scripts/gate_level_power/Gate_Level_Power.pl -netlist layout_icc/Xttop_routed.v -csf ./CadSetup.file  -prog ~/projects/vision_core/clib/downcast_15_O3 -rundir ../scripts/my_gate_downcast_15_O3  -spef layout_icc/Xttop_routed.spef.max.gz