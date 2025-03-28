#include "dcfileio.h"
#include "ps2funcs.h"
#include "stubs.h"
#include "PRE.h"
#include "ps2redbook.h"
#include "ps2gamefmv.h"
#include "mem.h"
#include "my_debug.h"
#include "pcdcMem.h"

#include "pcdcFile.h"

#include <cstring>

EXPORT i32 gFileIoSize;
EXPORT i32 gFileIoOldSize;
EXPORT i32 gFileIoInPre;
EXPORT HANDLE gFileIoWeirdHandle;
EXPORT char gFileIoFileName[64];

EXPORT void* gFileIoMemory;
EXPORT volatile i32 gFileIOStatus;
EXPORT u8 gFileIoInit;

// @Ok
// @Matching
void FileIO_Continue(void)
{
}

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

// @Ok
void FileIO_Load(void *where)
{
	print_if_false(!gFileIOStatus && gFileIoWeirdHandle, "No file has been opened yet");
	gFileIOStatus = 3;
	gFileIoOldSize = gFileIoSize;
	if (gPreManager && gFileIoInPre)
	{
		Mem_Copy(where, gPreFileBuf, gPreFileSize);
		gFileIOStatus = 0;
		return;
	}

	u8* dstBuf = static_cast<u8*>(where);
	print_if_false(where != 0, "Reading to NULL pointer");
	print_if_false(gFileIoSize > 0, "Empty file");

	i32 v4 = gFileIoSize;

	if ( gFileIoSize > 2048 )
	{
		if (!(reinterpret_cast<u32>(dstBuf) & 0x1F))
		{
			i32 v5 = gFileIoSize / 2048;
			gdFsRead(
					reinterpret_cast<i32>(gFileIoWeirdHandle),
					v5,
					dstBuf);
			v5 <<= 11;
			v4 -= v5;
			dstBuf += v5;
		}

		while (v4 > 2048)
		{
			i32 v6 = gdFsRead(
					reinterpret_cast<i32>(gFileIoWeirdHandle),
					1,
					static_cast<u8*>(gFileIoMemory));
			if (v6)
			{
				DebugPrintfX(
						"error reading %s (%d), errnum: %d",
						gFileIoFileName,
						gFileIoSize - v4,
						v6);
				return;
			}
			v4 -= 2048;
			memcpy(dstBuf, gFileIoMemory, 2048);
			dstBuf += 2048;
		}
	}

	if (v4)
	{
		i32 v6 = gdFsRead(
				reinterpret_cast<i32>(gFileIoWeirdHandle),
				1,
				static_cast<u8*>(gFileIoMemory));
		if (v6)
		{
			DebugPrintfX(
					"error reading %s (%d), errnum: %d",
					gFileIoFileName,
					gFileIoSize - v4,
					v6);
			return;
		}

		for (i32 i = 0; i < v4; i++)
		{
			dstBuf[i] = static_cast<u8*>(gFileIoMemory)[i];
		}
	}

	gFileIOStatus = 0;
}

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
