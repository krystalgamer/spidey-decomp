#include "non_win32.h"


#ifndef _WIN32

u32 GetTickCount()
{
	return 0x69696969;
}

void Sleep(u32)
{
}

#endif
