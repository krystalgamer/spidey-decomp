import os
import idc
import json
from idautils import Segments, Functions
from ida_kernwin import ask_file

def function_and_name_generator():
    for segment in Segments():
        for funcea in Functions(segment, idc.get_segm_end(idc.INF_LONG_DN)):
            func_name = idc.get_func_name(funcea)
            yield (str(funcea), {'name': func_name, 'address': funcea})

def main():

    path = ask_file(1, "*.json", "Output functions and names")
    if path is None:
        print('Cancelled')
        return

    new_names = dict(function_and_name_generator())

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

    print('Done')

    
if __name__ == '__main__':
    main()
