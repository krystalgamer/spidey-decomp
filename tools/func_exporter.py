import idaapi
import idc
import idautils
import ida_kernwin
import ida_ua

def main():

    ea = idc.here()

    func = idaapi.get_func(ea)

    if not func:
        print("Couldn't find a function at {ea}")
        return

    out_path = ida_kernwin.ask_file(True, '*.asm', "Please select outfile")

    if not out_path:
        print('No file selected bye!')
        return


    code = []
    for head in idautils.Heads(func.start_ea, func.end_ea):
        addy = f'{head:08X}'.lstrip('0')
        code.append(f'loc_{addy}:\n')


        insn = ida_ua.insn_t()
        if ida_ua.decode_insn(insn, head) == 0:
            print('FAIL')
            return

        parts = []

        for i, op in enumerate(insn.ops):
            if op.type == ida_ua.o_void:
                break
            parts.append(idc.print_operand(head, i))


        code.append(idc.print_insn_mnem(head) + ' ' + ','.join(parts) + '\n')

    with open(out_path, 'w') as fp:
        fp.writelines(code)

if __name__ == '__main__':
    main()
