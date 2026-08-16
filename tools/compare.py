import sys
import json
import pathlib
import itertools

import pefile
from iced_x86 import Decoder, Formatter, FormatterSyntax

USAGE = """\
usage: python tools/compare.py <function> [export]

  <function>  function name from tools/names.json or its original address
              (e.g. Spool_GetPalette, 0x4C97B0 or 5019568)
  <export>    exact mangled export name from the built dll, only needed
              when the automatic match finds none or more than one

Build first, the script reads Release/spider.dll.
It prints the original function and the reimplementation side by side,
one instruction per line. Lines marked with >>> have a different
instruction. Unmarked lines that only differ in numbers are relocated
addresses (strings, globals, call targets), which is fine."""


def fail(message):
    print(message)
    sys.exit(1)


def load_names(path):
    with open(path, 'r') as fp:
        return {int(k): v['name'] for k, v in json.load(fp)['functions'].items()}


def resolve_address(arg, names):
    try:
        return int(arg, 0)
    except ValueError:
        pass
    for address, name in names.items():
        if name == arg:
            return address
    fail(f'{arg} is not an address and not a name in tools/names.json')


def find_export(pe, text, wanted, plain_name):
    pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_EXPORT']])
    text_end = text.VirtualAddress + text.Misc_VirtualSize
    symbols = [s for s in pe.DIRECTORY_ENTRY_EXPORT.symbols
               if s.name and text.VirtualAddress <= s.address < text_end]

    if wanted:
        for symbol in symbols:
            if symbol.name.decode() == wanted:
                return symbol
        fail(f'{wanted} is not a function export of the dll')

    matches = [s for s in symbols if plain_name in s.name.decode()]
    if len(matches) == 1:
        return matches[0]
    if not matches:
        fail(f'no export contains "{plain_name}", pass the mangled name as second argument')
    candidates = '\n  '.join(s.name.decode() for s in matches)
    fail(f'several exports contain "{plain_name}", pass one of them as second argument:\n  {candidates}')


def disassemble(data, ip):
    formatter = Formatter(FormatterSyntax.INTEL)
    return [formatter.format(instruction) for instruction in Decoder(32, data, ip=ip)]


def main():
    if len(sys.argv) not in (2, 3):
        fail(USAGE)

    tools_path = pathlib.Path(sys.argv[0]).resolve().parents[0]
    proj_path = tools_path.parents[0]

    names = load_names(tools_path / 'names.json')
    address = resolve_address(sys.argv[1], names)
    plain_name = names.get(address, sys.argv[1])

    dump_path = tools_path / 'functions' / f'{address}.bin'
    if not dump_path.exists():
        fail(f'no original dump for {plain_name} (0x{address:X}) in tools/functions')
    original = dump_path.read_bytes()

    dll_path = proj_path / 'Release' / 'spider.dll'
    if not dll_path.exists():
        fail('Release/spider.dll not found, build first')
    pe = pefile.PE(str(dll_path), fast_load=True)
    text = next(s for s in pe.sections if s.Name.rstrip(b'\x00') == b'.text')

    wanted = sys.argv[2] if len(sys.argv) == 3 else None
    symbol = find_export(pe, text, wanted, plain_name)

    mine = text.get_data()[symbol.address - text.VirtualAddress:][:len(original)]

    print(f'{plain_name} (0x{address:X}) vs {symbol.name.decode()}')
    print(f'byte-identical: {original == mine}')

    left = disassemble(original, address)
    right = disassemble(mine, address)
    for a, b in itertools.zip_longest(left, right, fillvalue=''):
        mark = '   ' if a.split(' ') == b.split(' ') else '>>>'
        print(f'{mark} {a:<46} | {b}')


if __name__ == '__main__':
    main()
