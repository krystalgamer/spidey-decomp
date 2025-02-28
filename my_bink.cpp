#include "my_bink.h"

void STDCALL BinkSetVolume(i32, i32)
{
	printf("void BinkSetVolume(i32, i32)");
}

void STDCALL BinkSetPan(i32, i32)
{
	printf("void BinkSetPan(i32, i32)");
}

void STDCALL BinkClose(i32)
{
	printf("void BinkClose(HANDLE)");
}

i32 STDCALL BinkWait(i32)
{
	printf("i32 BinkWait(i32)");
	return 0x28022024;
}
