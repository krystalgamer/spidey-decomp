import os
import idc
import json
from idautils import Segments, Functions
from ida_kernwin import ask_file
import idaapi

def function_and_name_generator():
    for segment in Segments():
        for funcea in Functions(segment, idc.get_segm_end(idc.INF_LONG_DN)):
            func_name = idc.get_func_name(funcea)
            yield (str(funcea), {'name': func_name, 'address': funcea})

def main():

    path = ask_file(False, "*.json", "Input functions and names")
    if path is None:
        print('Cancelled')
        return

    old_names = dict(function_and_name_generator())

    new_names = None
    if os.path.exists(path):
        with open(path, "r") as fp:
            new_names = json.load(fp)['functions']

    if new_names is not None:
        for k,v in new_names.items():

            old_name = old_names[k]['name']
            new_name = v['name']

            if old_name != new_name:
                print(f'{old_name} has been replaced with {new_name}')
                idaapi.set_name(int(v['address']), new_name, idaapi.SN_FORCE)


    print('Done')

    
if __name__ == '__main__':
    main()
