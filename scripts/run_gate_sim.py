#! /usr/bin/python

import subprocess

apps = [ 'NMS_10',
	 'downCast_13',
	 'downCast_15', 'Resp_5',
	 'lambda_arris_v3lua_line43_10']

jsub = 'jsub  -q horowitz -l nodes=1:hotbox -l mem=4g -l ncpus=2 --'
cmd = jsub + ' ./soc_go'
common_args = '-vcs -lib64 -pluscomp="-ld gcc-4.4" -clock_period 10 -power -user_power -cyclmt 3000000'

rtl_args = ''
gate_args = ''
c_dir = '~/projects/vision_core/clib'
netlist = '-gate ../my_xda_500/layout_icc/Xttop_routed.v -csf ../my_xda_500/CadSetup.file'


for app in apps:
    prog_arg = "-prog {dir}/test_{app}.rtl".format(dir=c_dir, app=app)
    rtl_dir = "-rundir my_rtl_sim_{app}".format(app=app)
    gate_dir = "-rundir my_gate_sim_{app}".format(app=app)

    rtl_cmd = "{cmd} {args} -trace {prog} {dir}".format(cmd=cmd, args=common_args, prog=prog_arg, dir=rtl_dir)    
    print rtl_cmd
    #subprocess.call(rtl_cmd, shell=True)

    gate_cmd = "{cmd} {args} {net} {prog} {dir}".format(cmd=cmd, args=common_args, prog=prog_arg, dir=gate_dir, net=netlist)
    print gate_cmd
    #subprocess.call(gate_cmd, shell=True)

    rpt_cmd = '{jsub} ./scripts/gate_level_power/Gate_Level_Power.pl -netlist layout_icc/Xttop_routed.v -csf ./CadSetup.file  -spef layout_icc/Xttop_routed.spef.max.gz  {prog}  -rundir ../scripts/my_gate_sim_{app} -resultsdir ./gate_power_{app}'.format(jsub=jsub, app=app, prog=prog_arg)
    print rpt_cmd
    subprocess.call(rpt_cmd, shell=True)
