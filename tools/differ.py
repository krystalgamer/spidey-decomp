import os
import sys
import json
import pefile
import pathlib
import functools
import pydemangler
import iced_x86
import difflib
import hashlib


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
        yield (v['name'], int(k))


def function_loader_creator(path):
    def function_loader(name):
        with open(path / f'{name}.bin', 'rb') as fp:
            return fp.read()
    return function_loader


def create_enum_dict(module):
    return {module.__dict__[key]:key for key in module.__dict__ if isinstance(module.__dict__[key], int)}


MNEMONICS = create_enum_dict(iced_x86.Mnemonic)
def get_mnemonic(value):
    return MNEMONICS[value]


FORMATTER = iced_x86.Formatter(iced_x86.FormatterSyntax.NASM)

def decode_func(data, address):
    decoder = iced_x86.Decoder(32, data, ip=address)
    res = []
    for instr in decoder:

        content = None
        mnemonic = get_mnemonic(instr.mnemonic)
        if mnemonic == 'CALL':
            content = 'CALL XXXXXXXX'
        else:
            content = FORMATTER.format(instr)
        n = f'{instr.ip:016X} {content}\n'
        res.append(n)
    return res


def equal_functions(orig_data, decomp_data, orig_address, function_overrides, show_diff=False):

    if orig_data == decomp_data:
        return (True, None)

    decomp_hash = hashlib.md5(decomp_data).hexdigest()
    if orig_address in function_overrides:
        if decomp_hash == function_overrides[orig_address]:
            return (True, None)

    decoded_orig = decode_func(orig_data, orig_address)
    decoded_decomp = decode_func(decomp_data, orig_address)

    if decoded_orig == decoded_decomp:
        return (True, None)

    output = []

    if show_diff:
        res = difflib.Differ()
        for entry in res.compare(decoded_orig, decoded_decomp):
            if entry.startswith('  '):
                continue
            elif entry.startswith('- '):
                output.append(entry)
            elif entry.startswith('+ '):
                output.append(entry)
            elif entry.startswith('? '):
                output.append(entry)

    return (False, ''.join(output))

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

    function_overrides = {}
    function_overrides_path = tools_path / 'overrides.json'
    if os.path.exists(function_overrides_path):
        with open(function_overrides_path, 'r') as fp:
            for k,v in json.load(fp).items():
                function_overrides[int(k)] = v

    function_loader = function_loader_creator(tools_path / 'functions')
    print('Starting comparison')

    not_match = []
    for entry in to_compare:
        exe_address = export_symbols[entry].address
        orig_address = names_and_addresses[entry]
        orig_func_data = function_loader(orig_address)
        decomp_func_data = exe.get_function_data(exe_address, len(orig_func_data))

        equal, resp_str = equal_functions(orig_func_data, decomp_func_data, orig_address, function_overrides=function_overrides)
        if not equal:
            print(f'{entry} - {pydemangler.demangle(entry)} - {orig_address} - does not match')
            if resp_str != '':
                print(resp_str)
            not_match.append(entry)

    print(f'Match ratio is {(len(to_compare)-len(not_match))/len(to_compare)*100:.2f}% out of {len(to_compare)} functions')
    return


if __name__ == '__main__':
    main()
