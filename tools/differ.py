import sys
import pefile
import pydemangler


def get_text_section(exe):
    for section in exe.sections:
        no_zero = filter(lambda x: x != 0, section.Name)
        name = ''.join(map(lambda x: chr(x), no_zero))
        if name == '.text':
            return section

def main():

    if len(sys.argv) != 2:
        print(f'Expected format is {sys.argv[0]} EXE JSON')
        return

    exe = pefile.PE(sys.argv[1], fast_load=True)

    text_section = get_text_section(exe)
    if text_section is None:
        print('Couldnt find text section quitting')
        return

    exe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_EXPORT']])

    for entry in exe.DIRECTORY_ENTRY_EXPORT.symbols:
        name = entry.name.decode()
        print(f"'{name}' '{pydemangler.demangle(name)}' {hex(entry.address)}")
    


    return


if __name__ == '__main__':
    main()
