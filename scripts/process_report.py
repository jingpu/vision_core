#! /usr/bin/python

import sys

#fileName = "gate_power_downCast_15/power.hier5.rpt"
fileName = sys.argv[-1]
f = open(fileName, 'r')

topName = 'Xm_vision_sn32Xttop'
instNames = ['top',
             'LoadStore',
             'PCandIFetch',
             'TIE',
             'TIE_Regfile_vector32',
             '(xtregfile_3R1W_32_512_XTXm_vision_sn32)'
             ]

FUNames = ['inv16', 'mux16', 'mult16', 'add16', 'sub16', 'and16', 'or16',
           'gt16', 'lt16', 'gte16', 'lte16', 'lshift16', 'rshift16', 
           'min16', 'max16']

for FU in FUNames:
    instNames.append("TIE_semantic_slot0_{}_vv".format(FU))

datasheet = {}

report_start = False
for line in  f:
    tokens = line.split()
    if len(tokens) < 5:
        continue
    if report_start == False:
        if tokens[0] == 'Hierarchy':
            report_start = True
        else:
            continue

    instName = tokens[0]
    modName = tokens[1]
    if instName == topName:
        datasheet['top'] = ((float(tokens[1]) + float(tokens[2])), float(tokens[3]))
    
    if instName in instNames:
        datasheet[instName] = ((float(tokens[2]) + float(tokens[3])), float(tokens[4]))
    if modName in instNames:
        datasheet[modName] = ((float(tokens[2]) + float(tokens[3])), float(tokens[4]))


f.close()
    

for name in instNames:
    print name, '\t', datasheet[name][0]
