#include "non_win32.h"


#ifndef _WIN32

u32 GetTickCount()
{
	return 0x69696969;
}

void Sleep(u32)
{
}

i32 GetDriveTypeA(char*)
{
	return 69;
}

void GetCurrentDirectoryA(u32, char*)
{
}

void CreateDirectoryA(char*, i32)
{
}

void MessageBeep(u32)
{
}

void strlwr(char* inp)
{
	// @TODO later date
}

#endif
