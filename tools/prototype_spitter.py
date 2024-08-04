import sys
import json

def get_func_type(name):
    func_type = 'void '
    if '~' in name:
        func_type = ''

    if '::' in name:
        i = name.index('::')

        class_name = name[:i]
        second_part = name[i+2:]
        second_part = second_part[:second_part.index('(')]

        if class_name == second_part:
            func_type = ''

    return func_type

def generate_header(name):
    func_type = get_func_type(name)

    print(f'EXPORT {func_type}{name};')

def generate_body(name, size):
    tag = '// @SMALLTODO'
    if size > 900:
        tag = '// @BIGTODO'
    if size > 450:
        tag = '// @MEDIUMTODO'

    func_type = get_func_type(name)

    print(f'''
{tag}
{func_type}{name}
{{
    printf("{name}");
}}''')

def replace_type(orig, width, string):
    return string.replace(f'({orig})', f'({width})').replace(f',{orig})', f',{width})').replace(f'({orig},', f'({width},').replace(f',{orig},',f',{width},').replace(f'{orig} *', f'{width} *').replace(f'{orig} ', f'{width} ')

def set_widthed_type(entry):
    '''
    entry = entry.replace('(int)', '(i32)').replace(',int)', ',i32)').replace('(int,', '(i32,').replace(',int,',',i32,')
    entry = entry.replace('(uchar)', '(u8)').replace(',uchar)', ',u8)').replace('(uchar,', '(u8,').replace(',uchar,',',u8,')
    entry = entry.replace('(ulong)', '(u32)').replace(',ulong)', ',u32)').replace('(ulong,', '(u32,').replace(',ulong,',',u32,')
    '''
    entry = replace_type('ulong', 'u32', entry)
    entry = replace_type('uint', 'u32', entry)
    entry = replace_type('ushort', 'u16', entry)
    entry = replace_type('int', 'i32', entry)
    entry = replace_type('short', 'i16', entry)
    entry = replace_type('uchar', 'u8', entry)


    entry = entry.replace('&', '*')
    entry = entry.replace('((', '(').replace('))',')')
    return entry

def does_func_exist(entry, base):
    if entry.startswith('nullsub'):
        return True

    if entry.startswith('.'):
        return True

    name = entry[:entry.index('(')].strip()
    res = name in base

    '''
    if res:
        print(f'Will remove {entry} {name}')
    '''

    return res

def main():

    prototype_def = None
    entry = sys.argv[2]
    base_file = None
    with open(sys.argv[1], 'r') as fp:
        prototype_def = json.load(fp)
    try:
        with open(sys.argv[3], 'r') as fp:
            base_file = fp.read()
    except IndexError:
        base_file = ''

    if entry not in prototype_def:
        print(f'{entry} not part of prototypes')
        return 1

    functions = list(prototype_def[entry].items())
    functions.sort(key=lambda x: x[0])
    functions = map(lambda x: (set_widthed_type(x[0]), x[1]), functions)
    functions = map(lambda x: (set_widthed_type(x[0]), x[1]), functions)
    functions = map(lambda x: (set_widthed_type(x[0]), x[1]), functions)
    functions = filter(lambda x: does_func_exist(x[0], base_file) == False, functions)
    functions = list(functions)

    class_prefix = None
    for name, _ in functions:
        if '::' not in name:
            if class_prefix is not None:
                print('')
            class_prefix = None
        else:
            current_prefix = name[:name.index('::')]

            if class_prefix != current_prefix:
                print('')
                class_prefix = current_prefix


        generate_header(name)

    for name, size in functions:
        generate_body(name, size)


    return 0



if __name__ == '__main__':
    sys.exit(main())
