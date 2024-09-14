#include "dcfileio.h"
#include "ps2funcs.h"
#include "stubs.h"

#include "pcdcFile.h"

EXPORT void* gFileIoMemory;
EXPORT volatile i32 gFileIOStatus;
EXPORT u8 gFileIoInit;

// @SMALLTODO
void DebugPrintfX(char *,...)
{
    printf("DebugPrintfX(char *,...)");
}

// @Ok
// @Matching
u8 FileIO_FileExists(const char* pFileName)
{
	print_if_false(gFileIOStatus == 0, "Previous file not finished loading");
	HANDLE handle = gdFsOpen(pFileName, 0);
	if (!handle)
		return 0;
	gdFsClose(handle);
	return 1;
}

// @Ok
void FileIO_Init(void)
{
	if (!gFileIoInit)
	{
		gFileIoInit = 1;
		gFileIOStatus = 1;

		i32 iter = 8;
		i32 v1;
		do
		{
			v1 = gdFsInit();
			if (v1 == -29)
			{
				DebugPrintfX("GD Not ready.");
			}

			if (v1 != -23 && v1 != -33 && iter-- != 0 )
				continue;

			DCSetFatalError(2);
		}
		while (v1);

		gFileIoMemory = syMalloc(0x2000);
		print_if_false(gFileIoMemory != 0, "Out of system memory.");
	}
}

// @MEDIUMTODO
void FileIO_Load(void *)
{
    printf("FileIO_Load(void *)");
}

// @SMALLTODO
i32 FileIO_Open(const char*)
{
    printf("FileIO_Open(char const *)");
	return 0x19082024;
}

// @Ok
void FileIO_Sync(void)
{
	while (gFileIOStatus);
}
