#include "pcdcBkup.h"
#include "non_win32.h"

EXPORT CHAR gMemorycardPath[688];

// @Ok
// @Matching
i32 buInit(i32, i32, void*, void (*a4)(void))
{
	GetCurrentDirectoryA(0x104u, gMemorycardPath);
	strcat(gMemorycardPath, "\\save\\");
	CreateDirectoryA(gMemorycardPath, 0);
	a4();
	return 0;
}

i32 buSetCompleteCallback(i32 (*pFunc)(i32, i32, i32, u32))
{
	return 0;
}
