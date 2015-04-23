################################################################################
#        Customer ID=3146; Build=0x55baf; Copyright (c) 2008-2014 by Tensilica Inc.  ALL RIGHTS RESERVED.       #
# These coded instructions, statements, and computer programs are the          #
# copyrighted works and confidential proprietary information of Tensilica Inc. #
# They may not be modified, copied, reproduced, distributed, or disclosed to   #
# third parties in any manner, medium, or form, in whole or in part, without   #
# the prior written consent of Tensilica Inc.                                  #
################################################################################
lappend search_path . .. ../scripts/dc
source -echo -verbose DC_generic_define.tcl

set NETLIST_SOURCE [getenv POWER_NETLIST]
set LOADFILE_SOURCE [getenv POWER_SETLOAD]
set SPEF_SOURCE [getenv POWER_SPEF]
set MEM_MACRO_SOURCE [getenv POWER_MACROS]
set DIAG_PATH_LIST [getenv ABSOLUTE_DIAG_PATHS]
set POWER_REPORT [getenv POWER_OUTPUT_FILE]
set STATISTICAL [getenv DO_STATISTICAL]
set USE_TYPICAL_CORNER [getenv USE_TYPICAL_CORNER]
set SCRIPTDIR [getenv SCRIPT_DIR]

lappend search_path [format "%s%s" $SCRIPTDIR {/../dc}]

if {$USE_MEMORY_MACROS == 1} {
  set FILE_NAME_PREFIX "Xtmem"
  set TESTBENCH_INSTANCE_NAME "Testbench/Xtmem"
} else {
  set FILE_NAME_PREFIX "Xttop"
  set TESTBENCH_INSTANCE_NAME "Testbench/Xtmem/Xttop"
}

if {$USE_TYPICAL_CORNER != 0} {
  set DC_LIB $DC_TYP_LIB
  set LIB_DONT_USE $TYP_LIB_DONT_USE
  set LIB_PREFER $TYP_LIB_PREFER
  set BOUNDARY_LOAD $TYP_BOUNDARY_LOAD
  set OPERATING_CONDITION $TYP_OPERATING_CONDITION
}
set MAY_REQUIRE_POWER_LICENSE 1
source -echo -verbose DC_generic_libsetup.tcl
remove_attribute $LIB_SCAN_FLOPS dont_use
redirect /dev/null {set_dont_use $LIB_DONT_USE}

if {($USE_PSO == 0) && ($LOW_POWER_FLOW == 0)} {
  while {[get_license {"Power-Optimization"}] == 0} {
    echo {Waiting for Power-Optimization license...}
    sh sleep 120
  }
  set power_keep_license_after_power_commands true
}
if {$STATISTICAL == 0} {
  saif_map -start
} 

while {[get_license {"HDL-Compiler"}] == 0} {
  echo {Waiting for HDL-Compiler license...}
  sh sleep 120
}
read_file -f verilog $NETLIST_SOURCE
current_design $TOP_DESIGN
set LINK_STATUS [link]
if {$LINK_STATUS == 0} {
  echo [concat [format "%s%s" [join [concat "Err" "or"] ""] {: unresolved references. Exiting ...}]]
  quit
}
remove_license [list "HDL-Compiler"]
if {$USE_MEMORY_MACROS == 1} {
  source -echo -verbose $MEM_MACRO_SOURCE
}
source -echo -verbose DC_Xtensa_cons.tcl
source -echo -verbose DC_generic_derate.tcl

if {$LOADFILE_SOURCE != "{}"} {
  redirect /dev/null {source -echo -verbose $LOADFILE_SOURCE}
}
if {$SPEF_SOURCE != "{}"} {
  redirect /dev/null {read_parasitics -arnoldi -complete_with wlm -verbose $SPEF_SOURCE}
}

set_aspect_ratio $Fplan_AspectRatio
set_utilization $Fplan_CoreUtilization
set high_fanout_net_threshold 0

foreach SAIF_FILE $DIAG_PATH_LIST {
  if {$STATISTICAL == 0} {
    reset_switching_activity
    read_saif -input $SAIF_FILE -instance_name $TESTBENCH_INSTANCE_NAME -auto_map_names -verbose
  } else {
    infer_switching_activity -apply -nosplit -verbose
  }
  redirect -append $POWER_REPORT {echo {++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++}}
  redirect -append $POWER_REPORT {echo $SAIF_FILE}
  redirect -append $POWER_REPORT {report_power -flat -nosplit -analysis_effort medium -net -cell -include_input_nets}
  redirect -append $POWER_REPORT {report_power -nosplit -analysis_effort medium -include_input_nets -verbose}
   report_power -analysis_effort high  -nosplit  -hier -levels 5 > power.hier5.rpt
   report_power -analysis_effort high  -nosplit -hier -levels 3 > power.hier3.rpt
   report_power -analysis_effort high  -nosplit -hier -levels 2 > power.hier2.rpt
   report_area -hier > area.hier.rpt
  redirect -append $POWER_REPORT {echo {++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++}}
  echo [concat {Total time after report_power for diag } $SAIF_FILE [format "%s%s" { is } [cputime]]]
  echo [format "%s%s" {Peak memory used so far is } [mem]]
}

quit
