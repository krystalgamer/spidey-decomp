#include "my_debug.h"
#include <cstdio>
#include <stdarg.h>
#include <cstring>
#include "non_win32.h"

#define DEBUG_LOG

void my_debug_print(const char* format, ...)
{
	static char output_string[1024];

	memset(output_string, 0, sizeof(output_string));
	va_list args;
	va_start(args, format);
	vsprintf(output_string, format, args);

#ifdef _WIN32
	OutputDebugStringA(output_string);
#endif
	printf(output_string);
}
