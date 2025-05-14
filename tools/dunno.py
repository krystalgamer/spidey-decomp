import sys
import glob
import tree_sitter_cpp as tscpp # tree_sitter_cpp binary wheel
from tree_sitter import Language, Parser # tree_sitter python binding
from dataclasses import dataclass

@dataclass
class FunctionStatus:
    ok: bool = False
    not_ok: bool = False
    smalltodo: bool = False
    mediumtodo: bool = False
    bigtodo: bool = False
    bogus: bool = False

    def total(self):
        return int(self.ok) + int(self.not_ok) + int(self.smalltodo) + int(self.mediumtodo) + int(self.bigtodo) + int(self.bogus)

    def is_valid(self):
        return self.total() == 1


def get_all_comments_of_node(node):
    assert node.type == 'function_definition'

    cur = node.prev_sibling


    while cur is not None and cur.type == 'comment':
        yield cur

        cur = cur.prev_sibling



def get_all_function_defs(node):

    for child in node.children:
        if child.type == 'function_definition':
            yield child

        get_all_function_defs(child)

def ts_get_child_by_type(node, typ):

    for child in node.children:
        if child.type == typ:
            return child

    return None

def validate_all_functions_have_comment(root):

    function_defs = list(get_all_function_defs(root))

    validated = True
    for entry in function_defs:

        entry_content = entry.text.decode()
        comments = list(get_all_comments_of_node(entry))

        declarator = ts_get_child_by_type(entry, 'function_declarator')
        if declarator is None:
            declarator = ts_get_child_by_type(entry, 'pointer_declarator')

            if declarator is None:
                declarator = ts_get_child_by_type(entry, 'qualified_identifier')

                if declarator is None:
                    declarator = ts_get_child_by_type(entry, 'reference_declarator')

        '''
        if declarator is None:
            for a in entry.children:
                print(a.type, a.text)
                '''
        assert declarator is not None, entry.text
        declarator_text = declarator.text.decode()
        if declarator_text.startswith('validate_'):
            continue

        if len(comments) == 0:

            # HOTFIX
            if declarator_text.startswith('CWibbling3DExplosion::~CWibbling3DExplosion(void)'):
                continue

            print(f'[!] Missing comment for {entry.text}')
            validated = False
            continue
    
        func_status = FunctionStatus()
        for comment in comments:

            comment = comment.text.decode()
            comment = comment.lstrip('//').strip().lower()

            if comment == '@ok':
                func_status.ok = True
            elif comment == '@notok':
                func_status.not_ok = True
            elif comment == '@smalltodo':
                func_status.smalltodo = True
            elif comment == '@mediumtodo':
                func_status.mediumtodo = True
            elif comment == '@bigtodo':
                func_status.bigtodo = True
            elif comment == '@bogus':
                func_status.bogus = True

        if not func_status.is_valid():
            print(f'[!] Got invalid status for {entry.text}')
            validated = False

    return validated

def handle_file(parser, file_name):

    content = None
    with open(file_name, 'r') as fp:
        content = fp.read()

    tree = parser.parse(bytes(content, 'utf8'))

    return validate_all_functions_have_comment(tree.root_node)

def main():

    CPP_LANGUAGE = Language(tscpp.language())
    parser = Parser(CPP_LANGUAGE)

    num_args = len(sys.argv)
    if num_args > 1:
        print('[!] Too many arguments')
        return 1

    result = 0
    for file in glob.glob('*.cpp'):
        
        if file.endswith('validate.cpp'):
            continue
        if file.endswith('my_bink.cpp'):
            continue
        if file.endswith('my_debug.cpp'):
            continue
        print(f'Doing {file}')
        if not handle_file(parser, file):
            result = 3
    # handle_file(parser, 'bit.cpp')

    return result

if __name__ == '__main__':
    sys.exit(main())
