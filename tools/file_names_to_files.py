import sys
from pathlib import Path

def generate_cpp_content(name):
    return f'#include "{name}.h"'

def generate_h_content(name):

    upper = name.upper()
    return f'''#pragma once

#ifndef {upper}_H
#define {upper}_H

#endif'''

def main(argc, argv):

    ARG_NUM = 4
    if argc != ARG_NUM:
        if argc < ARG_NUM:
            print('Missing args')
        else:
            print('Too many args')
        return 1

    currentdir = Path(argv[1])
    names = Path(argv[2])
    outdir = Path(argv[3])

    if currentdir.is_dir() is False:
        print(f"currentdir must be a dir got {currentdir}")
        return 2

    if outdir.exists():
        if outdir.is_dir() is False:
            print(f"outdir must be a dir got {currentdir}")
            return 3
    else:
        outdir.mkdir(parents=True, exist_ok=True)

    allnames = None
    with open(names, 'r') as fp:
        allnames = fp.readlines()
        allnames = map(lambda x: x.strip(), allnames)
        allnames = set(allnames)


    
    existingnames = set()
    for entry in currentdir.iterdir():

        if entry.is_dir():
            continue

        if entry.suffix not in ('.cpp', '.h'):
            continue

        existingnames.add(entry.name.replace('.cpp', '').replace('.h', ''))


    missing = allnames - existingnames

    for entry in missing:
        cpp, h = generate_cpp_content(entry), generate_h_content(entry)

        with open(outdir / f'{entry}.cpp', 'w') as fp:
            fp.write(cpp)

        with open(outdir / f'{entry}.h', 'w') as fp:
            fp.write(h)

        print(f'Created {entry}')

    return 0

if __name__ == '__main__':
    sys.exit(main(len(sys.argv), sys.argv))
