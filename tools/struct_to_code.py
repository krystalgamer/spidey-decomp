import sys

DECL = False

def to_decl(name, ty):

    if ty == 'db':
        print(f'unsigned char {name};')
    elif ty == 'dw':
        print(f'__int16 {name};')
    elif ty == 'dd':
        print(f'int {name};')

def to_validate(name, cname, offset):
    print(f'VALIDATE({cname}, {name}, {offset});')

def main(argv, argc):

    if argc != 2:
        return 1

    file = argv[1]
    lines = None
    with open(file, 'r') as fp:
        lines = fp.readlines()

    lines = filter(lambda x: 'field_' in x, lines)
    lines = map(lambda x: x.strip(), lines)
    lines = map(lambda x: x.split(), lines)
    lines = map(lambda x: (x[1], x[2]), lines)

    lines = list(lines)

    for (name, ty) in lines:

        if DECL:
            to_decl(name, ty)
        else:
            offset = name.split('_')[1]
            offset = f'0x{offset}'

            to_validate(name, 'CSimby', offset)





    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv, len(sys.argv)))
