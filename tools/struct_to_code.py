import sys

DECL = True
Debug = False

def to_decl(name, ty):

    if ty == 'db':
        print(f'unsigned char {name};')
        return
    elif ty == 'dw':
        print(f'__int16 {name};')
        return
    elif ty == 'dd':
        print(f'int {name};')
        return

    raise Exception(f"FUCK {name} {ty}")

def to_validate(name, cname, offset):
    print(f'VALIDATE({cname}, {name}, {offset});')

def ida_filter(line):

    if 'dd' in line:
        return True
    if 'dw' in line:
        return True
    if 'db' in line:
        return True

    return False


def main(argv, argc):

    if argc != 2:
        return 1

    file = argv[1]
    lines = None
    with open(file, 'r') as fp:
        lines = fp.readlines()

    lines = filter(ida_filter, lines)
    lines = map(lambda x: x.strip(), lines)
    lines = map(lambda x: x.split(), lines)
    lines = map(lambda x: (x[1], x[2], int(x[0], 16)), lines)

    lines = list(lines)

    for (name, ty, offset) in lines:

        if Debug:
            print(name, ty, offset)
            continue


        if DECL:
            to_decl(name, ty)
        else:
            h = f'{offset:x}'.upper()
            to_validate(name, 'Image', f'0x{h}')





    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv, len(sys.argv)))
