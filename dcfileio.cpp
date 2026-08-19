#include "dcfileio.h"
#include "ps2funcs.h"
#include "stubs.h"
#include "PRE.h"
#include "ps2redbook.h"
#include "ps2gamefmv.h"
#include "mem.h"
#include "my_debug.h"
#include "pcdcMem.h"
#include "my_assert.h"
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

//#define G_FILE_IO_SIZE (gFileIoSize)
#define G_FILE_IO_SIZE (*reinterpret_cast<i32*>(0x0057C420))

//#define G_FILE_IO_OLD_SIZE (gFileIoOldSize)
#define G_FILE_IO_OLD_SIZE (*reinterpret_cast<i32*>(0x0057C404))

//#define G_FILE_IO_IN_PRE (gFileIoInPre)
#define G_FILE_IO_IN_PRE (*reinterpret_cast<i32*>(0x0057C40C))

//#define G_FILE_IO_WEIRD_HANDLE (gFileIoWeirdHandle)
#define G_FILE_IO_WEIRD_HANDLE (*reinterpret_cast<HANDLE*>(0x0057C418))

//#define G_FILE_IO_FILE_NAME (gFileIoFileName)
#define G_FILE_IO_FILE_NAME (reinterpret_cast<char*>(0x0056FC80))

//#define G_FILE_IO_MEMORY (gFileIoMemory)
#define G_FILE_IO_MEMORY (*reinterpret_cast<void**>(0x0057AD30))

//#define G_FILE_IO_STATUS (gFileIOStatus)
#define G_FILE_IO_STATUS (*reinterpret_cast<volatile i32*>(0x0057C400))

//#define G_FILE_IO_INIT (gFileIoInit)
#define G_FILE_IO_INIT (*reinterpret_cast<u8*>(0x0057C424))

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
	DoAssert(G_FILE_IO_STATUS == 0, "Previous file not finished loading");
	HANDLE handle = gdFsOpen(pFileName, 0);
	if (!handle)
		return 0;
	gdFsClose(handle);
	return 1;
}

// @Ok
void FileIO_Init(void)
{
	if (!G_FILE_IO_INIT)
	{
		G_FILE_IO_INIT = 1;
		G_FILE_IO_STATUS = 0;

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

		G_FILE_IO_MEMORY = syMalloc(0x2000);
		print_if_false(G_FILE_IO_MEMORY != 0, "Out of system memory.");
	}
}

// @Ok
void FileIO_Load(void *where)
{
	print_if_false(!G_FILE_IO_STATUS && G_FILE_IO_WEIRD_HANDLE, "No file has been opened yet");
	G_FILE_IO_STATUS = 3;
	G_FILE_IO_OLD_SIZE = G_FILE_IO_SIZE;
	if (G_PRE_MANAGER && G_FILE_IO_IN_PRE)
	{
		Mem_Copy(where, G_PRE_FILE_BUF, G_PRE_FILE_SIZE);
		G_FILE_IO_STATUS = 0;
		return;
	}

	u8* dstBuf = static_cast<u8*>(where);
	print_if_false(where != 0, "Reading to NULL pointer");
	print_if_false(G_FILE_IO_SIZE > 0, "Empty file");

	i32 v4 = G_FILE_IO_SIZE;

	if ( G_FILE_IO_SIZE > 2048 )
	{
		if (!(reinterpret_cast<u32>(dstBuf) & 0x1F))
		{
			i32 v5 = G_FILE_IO_SIZE / 2048;
			gdFsRead(
					reinterpret_cast<i32>(G_FILE_IO_WEIRD_HANDLE),
					v5,
					dstBuf);
			v5 <<= 11;
			v4 -= v5;
			dstBuf += v5;
		}

		while (v4 > 2048)
		{
			i32 v6 = gdFsRead(
					reinterpret_cast<i32>(G_FILE_IO_WEIRD_HANDLE),
					1,
					static_cast<u8*>(G_FILE_IO_MEMORY));
			if (v6)
			{
				DebugPrintfX(
						"error reading %s (%d), errnum: %d",
						G_FILE_IO_FILE_NAME,
						G_FILE_IO_SIZE - v4,
						v6);
				return;
			}
			v4 -= 2048;
			memcpy(dstBuf, G_FILE_IO_MEMORY, 2048);
			dstBuf += 2048;
		}
	}

	if (v4)
	{
		i32 v6 = gdFsRead(
				reinterpret_cast<i32>(G_FILE_IO_WEIRD_HANDLE),
				1,
				static_cast<u8*>(G_FILE_IO_MEMORY));
		if (v6)
		{
			DebugPrintfX(
					"error reading %s (%d), errnum: %d",
					G_FILE_IO_FILE_NAME,
					G_FILE_IO_SIZE - v4,
					v6);
			return;
		}

		for (i32 i = 0; i < v4; i++)
		{
			dstBuf[i] = static_cast<u8*>(G_FILE_IO_MEMORY)[i];
		}
	}

	G_FILE_IO_STATUS = 0;
}

// @Ok
// @Matching
i32 FileIO_Open(const char* pName)
{
	print_if_false(G_FILE_IO_STATUS == 0, "Previous file not finished loading");
	G_FILE_IO_OLD_SIZE = 0;
	G_FILE_IO_IN_PRE = 0;

	if (G_PRE_MANAGER && (G_PRE_FILE_BUF = G_PRE_MANAGER->getFile(pName, &G_PRE_FILE_SIZE)))
	{
		G_FILE_IO_IN_PRE = 1;
		G_FILE_IO_SIZE = G_PRE_FILE_SIZE;
		return G_PRE_FILE_SIZE;
	}

	if (G_FILE_IO_WEIRD_HANDLE)
	{
		gdFsClose(G_FILE_IO_WEIRD_HANDLE);
		G_FILE_IO_WEIRD_HANDLE = 0;
	}

	Redbook_XAStop();
	GameFMV_StopFMV();

	strcpy(G_FILE_IO_FILE_NAME, pName);
	G_FILE_IO_WEIRD_HANDLE = gdFsOpen(G_FILE_IO_FILE_NAME, 0);
	if (!G_FILE_IO_WEIRD_HANDLE)
	{
		DebugPrintfX("unable to open file %s", pName);
		return 0;
	}

	G_FILE_IO_STATUS = 0;
	gdFsGetFileSize(
			reinterpret_cast<i32>(G_FILE_IO_WEIRD_HANDLE),
			&G_FILE_IO_SIZE);
	return G_FILE_IO_SIZE;
}

// @Ok
// @Matching
void* FileIO_Unk(const char* pName, i32 *size)
{
	DoAssert(G_FILE_IO_STATUS == 0, "Previous file not finished loading");
	FileIO_Sync();

	i32 s = FileIO_Open(pName);
	*size = s;

	if (!s)
	{
		return 0;
	}

	void *buf = syMalloc(s);
	DoAssert(!!buf, "Out of system memory.");
	FileIO_Load(buf);
	return buf;
}

// @Ok
// @Matching
void FileIO_Unk2(void *p)
{
	ASSERT(!!p, "Cannot free null pointer");
	syFree(p);
}

// @Ok
// @Matching
INLINE void FileIO_Sync(void)
{
	while (G_FILE_IO_STATUS);
}


#include "my_patch.h"


// @Bogus
void patch_dcfileio(void)
{
	PATCH_PUSH_RET(0x00430CC0, FileIO_Sync);
	PATCH_PUSH_RET(0x00430CA0, FileIO_Unk2);
}
