import idautils
import ida_kernwin

def main():
    ret = ida_kernwin.ask_str("", 6, "Choose type")

    if ret is None:
        return

    ret = ret.replace('*', '').strip()

    sid = None
    for (_, csid, name) in idautils.Structs():
        if name == ret:
            sid = csid
            break

    if sid is None:
        print(f"Couldn't find {ret}")
        return

    print(sid)

    return



if __name__ == '__main__':
    main()
