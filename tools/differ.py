import sys
import json
import pefile
import pathlib
import functools
import pydemangler


class ExeFile(object):

    def __init__(self, path):
        self.exe = pefile.PE(path, fast_load=True)

    @functools.cached_property
    def _text_section(self):
        for section in self.exe.sections:
            no_zero = filter(lambda x: x != 0, section.Name)
            name = ''.join(map(lambda x: chr(x), no_zero))
            if name == '.text':
                return section

    def export_symbols_generator(self):

        text_section = self._text_section
        if text_section is None:
            print('Couldnt find text section quitting')
            return

        self.exe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_EXPORT']])
        for symbol in self.exe.DIRECTORY_ENTRY_EXPORT.symbols:
            name = symbol.name.decode()
            yield (name, symbol)

    def get_function_data(self, address, size):
        orig_address = address - self._text_section.section_min_addr
        return self._text_section_data[orig_address:orig_address+size]

    @functools.cached_property
    def image_base(self):
        return self.exe.OPTIONAL_HEADER.ImageBase

    @functools.cached_property
    def _text_section_data(self):
        return self._text_section.get_data()

def name_generator(json_path):

    functions = None
    with open(json_path, 'r') as fp:
        functions = json.load(fp)['functions']

    for k,v in functions.items():
        yield (v['name'], k)


def function_loader_creator(path):
    def function_loader(name):
        with open(path / f'{name}.bin', 'rb') as fp:
            return fp.read()
    return function_loader

def main():

    base_path = pathlib.Path(sys.argv[0]).resolve()
    tools_path = base_path.parents[0]
    proj_path = base_path.parents[1]

    exe = ExeFile(proj_path / 'Release' / 'spider.exe')

    export_symbols = dict(exe.export_symbols_generator())
    names_and_addresses = dict(name_generator(tools_path / 'names.json'))

    exported_but_missing = []
    to_compare = []


    for entry in export_symbols.keys():
        if entry not in names_and_addresses:
            exported_but_missing.append(entry)
        else:
            to_compare.append(entry)

    if exported_but_missing:
        print('There are missing symbols')
        for entry in exported_but_missing:
            print(f"{entry} - but doesn't exist - {pydemangler.demangle(entry)}")
        print('\n\n\n\n')

    if not to_compare:
        print('Nothing to compare')
        return

    function_loader = function_loader_creator(tools_path / 'functions')
    print('Starting comparison')

    not_match = []
    for entry in to_compare:
        exe_address = export_symbols[entry].address
        orig_func_data = function_loader(names_and_addresses[entry])
        decomp_func_data = exe.get_function_data(exe_address, len(orig_func_data))

        if orig_func_data != decomp_func_data:
            print(f'{entry} - {pydemangler.demangle(entry)} - does not match')
            not_match.append(entry)

    print(f'Match ratio is {len(not_match)/len(to_compare)*100:.2f}% out of {len(to_compare)} functions')
    return


if __name__ == '__main__':
    main()
