import os
import idc
import json
from idautils import Segments, Functions
from ida_kernwin import ask_file
from collections import defaultdict
import idaapi
import json

def function_name_generator():
    for segment in Segments():
        for funcea in Functions(segment, idc.get_segm_end(idc.INF_LONG_DN)):
            #func_name = idc.get_func_name(funcea)
            func_name = idaapi.get_ea_name(funcea, idaapi.GN_SHORT|idaapi.GN_DEMANGLED)
            yield (funcea, func_name, idc.find_func_end(funcea)-funcea)

def main():

    path = ask_file(1, "*.json", "Output functions and names")
    if path is None:
        print('Cancelled')
        return
    
    with open(path, 'w') as fp:

        functions = function_name_generator()
        functions = filter(lambda x: x[1].startswith('sub_') is False, functions)
        functions = list(functions)
        functions.sort(reverse=True, key= lambda x: x[0])

        total_counter = 0
        counter = 0
        size = 0
        current_file = None
        file_to_funcs = defaultdict(lambda: dict())
        for _, name, func_size in functions:

            if name.startswith('.__sinit'):

                if current_file is not None:
                    print(f'{current_file} has {counter} functions ({size} bytes)')

                counter = 0
                size = 0
                current_file = '_'.join(name.replace('.__sinit_', '').split('_')[:-1])
                continue
            
            if current_file is not None:
                counter += 1
                size += func_size
                total_counter += 1

                file_to_funcs[current_file][name] = func_size

        if counter > 0:
            print(f'{current_file} has {counter} functions ({size} bytes)')

        print(total_counter)

        json.dump(file_to_funcs, fp, indent=2)




    '''
    old_names = None
    if os.path.exists(path):
        with open(path, "r") as fp:
            old_names = json.load(fp)['functions']

    if old_names is not None:
        for k,v in old_names.items():

            old_name = v['name']
            new_name = new_names[k]['name']

            if old_name != new_name:
                print(f'{old_name} has been replaced with {new_name}')


    with open(path, 'w') as fp:
        json.dump({'functions': new_names}, fp)
    '''

    print('Done')

    
if __name__ == '__main__':
    main()
