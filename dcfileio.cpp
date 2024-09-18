#include "dcfileio.h"
#include "ps2funcs.h"
#include "stubs.h"
#include "pre.h"
#include "ps2redbook.h"
#include "ps2gamefmv.h"

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

EXPORT i32 gFileIoSize;
EXPORT i32 gFileIoOldSize;
EXPORT i32 gFileIoInPre;
EXPORT HANDLE gFileIoWeirdHandle;
EXPORT char gFileIoFileName[64];

// @Ok
// @Matching
i32 FileIO_Open(const char* pName)
{
	print_if_false(gFileIOStatus == 0, "Previous file not finished loading");
	gFileIoOldSize = 0;
	gFileIoInPre = 0;

	if (gPreManager && (gPreFileBuf = gPreManager->getFile(pName, &gPreFileSize)))
	{
		gFileIoInPre = 1;
		gFileIoSize = gPreFileSize;
		return gPreFileSize;
	}

	if (gFileIoWeirdHandle)
	{
		gdFsClose(gFileIoWeirdHandle);
		gFileIoWeirdHandle = 0;
	}

	Redbook_XAStop();
	GameFMV_StopFMV();

	strcpy(gFileIoFileName, pName);
	gFileIoWeirdHandle = gdFsOpen(gFileIoFileName, 0);
	if (!gFileIoWeirdHandle)
	{
		DebugPrintfX("unable to open file %s", pName);
		return 0;
	}

	gFileIOStatus = 0;
	gdFsGetFileSize(
			reinterpret_cast<i32>(gFileIoWeirdHandle),
			&gFileIoSize);
	return gFileIoSize;
}

// @Ok
void FileIO_Sync(void)
{
	while (gFileIOStatus);
}
