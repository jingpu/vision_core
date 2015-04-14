################################################################################
#        Customer ID=3146; Build=0x556cf; Copyright (c) 2008-2014 by Tensilica Inc.  ALL RIGHTS RESERVED.       #
# These coded instructions, statements, and computer programs are the          #
# copyrighted works and confidential proprietary information of Tensilica Inc. #
# They may not be modified, copied, reproduced, distributed, or disclosed to   #
# third parties in any manner, medium, or form, in whole or in part, without   #
# the prior written consent of Tensilica Inc.                                  #
################################################################################

proc compile_command {incr scan timing retime power advanced spg} {
  define_proc_attributes compile_command -info "Generalized compile command to save script space" -define_args { \
					 {incr "perform incremental mapping" incr string required} \
					 {scan "perform scan replacement" scan string required} \
					 {timing "perform timing_high_effort_script for compile_ultra" timing string required} \
					 {retime "perform adaptive retiming" retime string required} \
					 {power "perform automatic clock-gate insertion" power string required} \
					 {advanced "allow sequential phase inversion" advanced string required} \
					 {spg "allow physical guidance flow" spg string required}}

  set command_option_string "compile_ultra -no_autoungroup"
  if {$incr == 1} {
    lappend command_option_string -incremental
  }
  if {$scan == 1} {
    lappend command_option_string -scan
  }
  if {$timing == "speed"} {
    lappend command_option_string -timing_high_effort_script
  } else {
    lappend command_option_string -area_high_effort_script
  }
  if {$retime == 1} {
    lappend command_option_string -retime
  }
  if {$power == 1} {
    lappend command_option_string -gate_clock
  }
  if {$advanced == 0} {
    lappend command_option_string -no_seq_output_inversion
  }
  if {$spg == 1} {
    lappend command_option_string -spg
  }

  echo "running command: $command_option_string"
  eval $command_option_string
}

proc make_snapshot {tag_name {last_time 0}} {
  define_proc_attributes make_snapshot -info "Generate QOR snapshot for given design" -define_args { \
				       {tag_name "timestamp name" tag_name string required} \
				       {last_time "last saved time" last_time int optional}}

  report_qor
  report_constraint -nosplit
  report_timing -nosplit
  report_area -physical -hierarchy -designware -nosplit
  report_reference -hier -nosplit
  set ELAPSED_TIME [expr [cputime] - $last_time]
  set TIMESTAMP [cputime]
  echo [format "%s%s%s" $tag_name { elapsed time is } $ELAPSED_TIME]
  echo [format "%s%s%s" $tag_name { total time is } $TIMESTAMP]
  echo [format "%s%s%s" $tag_name { memory is } [mem]]
  return $TIMESTAMP
}

proc collection_to_list {input_collection} {
  define_proc_attributes collection_to_list -info "Create a list from a collection" -define_args { \
					    {input_collection "input collection" input_collection string required}}

  set output_list [list]
  foreach_in_collection ic $input_collection {
    lappend output_list [get_object_name $ic]
  }
  return $output_list
}

proc test_scan_chain_complete {max_length {memory_list [list]}} {
  define_proc_attributes test_scan_chain_complete -info "Test that all flops are in scan chains" -define_args { \
			{max_length "maximum length of all scan chains" max_length int required} \
			{memory_list "list of memory libcells" memory_list string optional}}

  dft_drc
  set RUN_FAILED 0
  set CHAIN_COUNT [get_scan_chains]
  set DESIGN_FLOP_COUNT [sizeof_collection [all_registers -cells -edge_triggered]]
  set MEM_MACRO_COUNT 0
  foreach ml $memory_list {
    set MEM_MACRO_COUNT [expr $MEM_MACRO_COUNT + [sizeof_collection [get_references -hier -quiet $ml]]]
  }
  set DESIGN_FLOP_COUNT [expr $DESIGN_FLOP_COUNT - $MEM_MACRO_COUNT]
  set TOTAL_SCAN_FLOP_COUNT 0
  while {$CHAIN_COUNT > 0} {
    set SINGLE_CHAIN_LENGTH [sizeof_collection [get_scan_cells_of_chain -chain $CHAIN_COUNT]]
    if {$max_length > 0} {
      if {$SINGLE_CHAIN_LENGTH > $max_length} {
	echo [format "%s%s%s%s%s%s%s" "Err" "or: In scan chain " $CHAIN_COUNT " there are " $SINGLE_CHAIN_LENGTH " flops, when the maximum allowed is " $max_length]
	set RUN_FAILED 1
      } else {
	echo [format "%s%s%s%s%s%s" "Check passed: scan chain " $CHAIN_COUNT " has " $SINGLE_CHAIN_LENGTH " flops out of a maximum of " $max_length]
      }
    }
    set TOTAL_SCAN_FLOP_COUNT [expr $TOTAL_SCAN_FLOP_COUNT + $SINGLE_CHAIN_LENGTH]
    set CHAIN_COUNT [expr $CHAIN_COUNT - 1]
  }
  if {$TOTAL_SCAN_FLOP_COUNT >= $DESIGN_FLOP_COUNT} {
    echo {Check passed: total number of flops in scan chains is greater than or equal to the total design flop count}
  } else {
    set DISCREPANCY [expr $DESIGN_FLOP_COUNT - $TOTAL_SCAN_FLOP_COUNT]
    echo [format "%s%s%s%s" "Err" "or: There are " $DISCREPANCY " design flops not assigned to any scan chains"]
    set RUN_FAILED 1
  }
  if {$RUN_FAILED == 1} {
    redirect failed_dft_insertion.report {dft_drc -verbose}
    change_names -rules verilog -hier
    write -hier -f verilog -o failed_dft_insertion.v
    redirect failed_dft_insertion.scanchains {report_scan_path -view existing_dft -cell all}
    redirect failed_dft_insertion.ref {report_reference -hier -nosplit}
    quit
  }
}

proc ungroup_all_except_these {ungroup_design_list} {
  define_proc_attributes ungroup_all_except_these -info "Ungroup all top-level hierarchy except specified designs" -define_args { \
			 {ungroup_design_list "list of designs not to ungroup" ungroup_design_list string required}}

  if {[llength $ungroup_design_list] != 0} {
    foreach udl $ungroup_design_list {
      set_dont_touch [find design [format "%s%s" $udl "*"] -hier] true
    }
    ungroup -flatten -all
    foreach udl $ungroup_design_list {
      set_dont_touch [find design [format "%s%s" $udl "*"] -hier] false
      set_ungroup [find design [format "%s%s" $udl "*"] -hier] false
    }
  } else {
    ungroup -flatten -all
  }
}

proc ungroup_selected_subdesigns {sub_list prefix top_design} {
  define_proc_attributes ungroup_selected_subdesigns -info "Ungroup specified subdesigns" -define_args { \
			 {sub_list "list of subdesigns to be ungrouped" sub_list string required} \
			 {prefix "subdesign name prefix" prefix string required} \
			 {top_design "top level design name" top_design string required}}

  if {[llength $sub_list] != 0} {
    current_design $top_design
    foreach sl $sub_list {
      if {$sl eq "xtscflop_cg_mem_staging_register"} {
        foreach_in_collection xmsr [get_designs -hier -quiet [format "%s%s%s" "*" $sl "*"]] {
	  current_design [get_object_name $xmsr]
	  ungroup -flatten -all
	  current_design $top_design
        }
      } else {
	current_design [get_designs -hier -quiet [format "%s%s" $prefix $sl]]
	ungroup -flatten -all
	current_design $top_design
      }
    }
  }
}

proc tag_retention_flop_pins {} {
  define_proc_attributes tag_retention_flop_pins -info "Tags the pins of cells mapped to retention flops with a user defined attribute"

  set TOTAL_SEQUENTIAL_COUNT [sizeof_collection [all_registers]]
  set EDGE_TRIG_COUNT [sizeof_collection [all_registers -edge_triggered]]
  set COMPUTED_LATCH_COUNT [expr $TOTAL_SEQUENTIAL_COUNT - $EDGE_TRIG_COUNT]
  set LEVEL_SENS_COUNT [sizeof_collection [filter_collection [all_registers -level_sensitive] undefined(retention_cell)]]

  if {$COMPUTED_LATCH_COUNT == $LEVEL_SENS_COUNT} {
    echo [format "%s%s" "Check passed: the computed and measured latch counts match with " $COMPUTED_LATCH_COUNT]
  } else {
    echo [format "%s%s%s%s" "Warn" "ing: The computed latch count of " $COMPUTED_LATCH_COUNT " does not match"]
    echo [format "%s%s%s" "Warn" "ing: the measured latch count of " $LEVEL_SENS_COUNT]
  }

  set RETENTION_CELL_LIST [filter_collection [all_registers -level_sensitive] defined(retention_cell)]
  foreach_in_collection RCL $RETENTION_CELL_LIST {
    redirect /dev/null {set_attribute [get_pins -quiet -of_objects [get_object_name $RCL]] is_a_ret_cell_pin true}
  }
}

proc check_for_comb_timing_loops {} {
  define_proc_attributes check_for_comb_timing_loops -info "Runs report_timing -loops and errors out if loops are detected"

  redirect combinational_loops.txt {report_timing -loops -enable_preset_clear_arcs -nosplit}
  if {[sh (grep "Timing loop detected." combinational_loops.txt | wc -l)] > 0} {
    echo [format "%s%s" "Err" "or: combinational loops detected - see combinational_loops.txt file."]
    quit
  } else {
    echo "Check passed: there are no combinational timing loops in the design."
    sh rm combinational_loops.txt
  }
}

proc report_single_cycle_loops {} {
  define_proc_attributes report_single_cycle_loops -info "Reports all flops (including between bits of the same bank) whose inputs and outputs are connected"

  redirect exact_single_cycle_loops.txt {echo [format "%-100s%-10s" "Single Cycle Loop Flop" "Slack"]}
  redirect -append exact_single_cycle_loops.txt {echo [string repeat - 110]}
  redirect partial_single_cycle_loops.txt {echo [format "%-100s%-100s%-10s" "Startpoint" "Endpoint" "Slack"]}
  redirect -append partial_single_cycle_loops.txt {echo [string repeat - 210]}
  set ALL_FLOP_OUTPUTS [all_registers -edge_triggered -output_pins]
  set TOTAL_OUTPUT_COUNT [sizeof_collection $ALL_FLOP_OUTPUTS]
  set HEARTBEAT_COUNT 0
  foreach_in_collection AFO $ALL_FLOP_OUTPUTS {
    incr HEARTBEAT_COUNT
    set CURRENT_STARTPOINT [file dirname [get_object_name $AFO]]
    set START_MATCH [join [lreplace [split $CURRENT_STARTPOINT _] end-1 end] _]
    set FANOUT_ENDPOINTS [all_fanout -from [get_object_name $AFO] -endpoints_only -flat]
    foreach_in_collection FE $FANOUT_ENDPOINTS {
      set CURRENT_ENDPOINT [file dirname [get_object_name $FE]]
      set END_MATCH [join [lreplace [split $CURRENT_ENDPOINT _] end-1 end] _]
      if {$START_MATCH eq $END_MATCH} {
	set SLACK_VAL [get_attribute [get_timing_paths -from [get_object_name $AFO] -to [get_object_name $FE]] slack]
	if {$SLACK_VAL < 0.0} {
	  if {$CURRENT_STARTPOINT eq $CURRENT_ENDPOINT} {
	    redirect -append exact_single_cycle_loops.txt {echo [format "%-100s%-10s" $CURRENT_STARTPOINT $SLACK_VAL]}
	  } else {
	    redirect -append partial_single_cycle_loops.txt {echo [format "%-100s%-100s%-10s" $CURRENT_STARTPOINT $CURRENT_ENDPOINT $SLACK_VAL]}
	  }
	}
      }
    }
    if {[expr $HEARTBEAT_COUNT % 500] == 0} {
      echo [format "%s%s%s%s%s" "Processed " $HEARTBEAT_COUNT " out of " $TOTAL_OUTPUT_COUNT " output ports"]
    }
  }
}
