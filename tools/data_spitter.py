import idc
import pathlib
from idautils import Segments, Functions
from ida_kernwin import ask_file

def data_generator():
    for segment in Segments():
        for funcea in Functions(segment, idc.get_segm_end(idc.INF_LONG_DN)):
            flags = idc.get_func_flags(funcea)
            if (flags & (idc.FUNC_LIB | idc.FUNC_THUNK)) != 0:
                continue
            func_end = idc.find_func_end(funcea)
            yield (str(funcea), idc.get_bytes(funcea, func_end-funcea))

def main():

    path = ask_file(1, "*", "Output functions and names")
    if path is None:
        print('Cancelled')
        return

    path = pathlib.Path(path).parents[0]
    data = dict(data_generator())

    for k,v in data.items():
        with open(path / f'{k}.bin', 'wb') as fp:
            fp.write(v)
    print('Done')

    
if __name__ == '__main__':
    main()

