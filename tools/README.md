# compare.py

Shows an original game function and the reimplementation from the built dll
side by side, one instruction per line. Useful to check a function while
working on it, because the dll relocates strings, globals and call targets,
so the bytes never fully match even when the code is right.

## Usage

Build first, the script reads `Release/spider.dll`.

```
python tools/compare.py <function> [export]
```

`<function>` is a name from `tools/names.json` or the original address,
for example:

```
python tools/compare.py Utils_VblankProcessing
python tools/compare.py 0x4E5C10
python tools/compare.py 5135376
```

The script finds the dll export on its own. If it finds none or more than
one, pass the exact mangled export name as the second argument.

## Reading the output

Lines marked with `>>>` have a different instruction, that is a real
difference. Unmarked lines that only differ in numbers are relocated
addresses, which is fine.

Needs `pefile` and `iced-x86`, same as `differ.py` (see `requirements.txt`).
