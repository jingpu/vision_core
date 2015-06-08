#! /usr/bin/python

import sys
import re

#fileName = "gate_power_downCast_15/power.hier5.rpt"
fileName = sys.argv[-1]
f = open(fileName, 'r')

#topName = 'Xm_vision2_3Xttop'
topName = 'Xm_vision2_nofusedXttop'
instNames = ['top',
             'LoadStore',
             'PCandIFetch',
             'TIE',
             'TIE_Regfile_vv',
            '(xtregfile_3R1W_32_512_XTXm_vision2_nofused)',
             'FU',
             ]
#'(xtregfile_3R1W_32_512_XTXm_vision2_3)',

p = re.compile('TIE_semantic_slot0_\w+_vv')

datasheet = {}

datasheet['FU'] = (0, 0)

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

    if p.match(instName):
        datasheet['FU'] = (datasheet['FU'][0] + (float(tokens[2]) + float(tokens[3])), datasheet['FU'][1] + float(tokens[4]))

f.close()
    

for name in instNames:
    print name, '\t', datasheet[name][0]
