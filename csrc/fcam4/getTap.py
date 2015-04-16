import sys

taps = []

with open("tap_val", 'r') as f:
    for line in f:
        tokens = line.split()
        if not tokens:
            continue
        taps.append([tokens[0], tokens[1], tokens[2], tokens[3], 11111111111])

with open("conv_run.yml", 'r') as f:
    for line in f:
        tokens = line.split()
        if not tokens:
            continue
        value = tokens[1]
        name_slices = tokens[0].split('_')
        new_name = "{}_{}_{}_0".format(name_slices[0], name_slices[1], name_slices[2])
        success = False
        for elem in taps:
            if elem[3] == new_name:
                elem[4] = value
                success = True
                break
        if not success:
            print new_name, " not found match"
        

with open("tap_val_out", 'w') as f:
    for tokens in taps:
        f.write("{} {} {} {} = {};\n"
                  .format(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4]) )
