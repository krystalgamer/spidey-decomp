#include "pcdcFile.h"
#include "PCMovie.h"
#include "pkr.h"
#include "SpideyDX.h"
#include "validate.h"
#include "my_debug.h"

#include <cstring>

#ifdef _WIN32
EXPORT TCHAR gCurrentDir[260];
#endif

EXPORT char gFsBase[260];

const i32 MAX_OPEN_FILE_COUNT = 5;
EXPORT SGDOpenFile gOpenFiles[MAX_OPEN_FILE_COUNT];

EXPORT HANDLE gOpenFile;

//#define G_CURRENT_DIR (gCurrentDir)
#define G_CURRENT_DIR (reinterpret_cast<TCHAR*>(0x006BC1F4))

//#define G_OPEN_FILES (gOpenFiles)
#define G_OPEN_FILES (reinterpret_cast<SGDOpenFile*>(0x006BC2F8))

//#define G_FS_BASE (gFsBase)
#define G_FS_BASE (reinterpret_cast<char*>(0x006BC334))

//#define G_OPEN_FILE (gOpenFile)
#define G_OPEN_FILE (*reinterpret_cast<HANDLE*>(0x006BC438))

// @Ok
// @Matching
void gdFsFinish(void)
{
	closePKR();
	PCMOVIE_ClosePKR();
}

// @Ok
INLINE i32 readFilePKR(
		i32 id,
		u8* pBuf,
		i32 size)
{

	i32 index = (id ^ 0xFF) - 1;
	if (!G_OPEN_FILES[index].mBuf)
		return 0;

	i32 mOffset = G_OPEN_FILES[index].mOffset;
	i32 mEnd = G_OPEN_FILES[index].mEnd;
	if (mOffset + size > mEnd)
		size = mEnd - mOffset;

	memcpy(pBuf, &G_OPEN_FILES[index].mBuf[mOffset], size);
	G_OPEN_FILES[index].mOffset += size;
	return size;

}

// @Ok
// @Matching
i32 gdFsRead(
		i32 a1,
		i32 a2,
		u8* a3)
{
	readFilePKR(a1, a3, a2 << 11);
	return 0;
}

// @Ok
i32 gdFsGetFileSize(i32 a1, i32* pSize)
{
	i32 curPos = tellFilePKR(a1);
	seekFilePKR(a1, 0, 2);

	*pSize = tellFilePKR(a1);
	seekFilePKR(a1, curPos, 0);
	return 1;
}

// @NotOk
// validate later :P
HANDLE gdFsOpen(
		const char* pFileName,
		i32)
{
	char buf[512];
	strcpy(buf, G_FS_BASE);
	strcat(buf, pFileName);

	if (!strchr(pFileName, '\\'))
		return reinterpret_cast<HANDLE>(openFilePKR(G_FS_BASE, pFileName));

	char v16[32];
	strcpy(v16, pFileName);

	char localName[32];
	strcpy(localName, strchr(pFileName, '\\') + 1);
	strchr(v16, '\\')[1] = 0;

	char v15[32];
	strcpy(v15, G_FS_BASE);
	strcat(v15, v16);
	if (!strstr(localName, ".bik"))
		return reinterpret_cast<HANDLE>(openFilePKR(v15, localName));

	char FileName[512];
	strcpy(FileName, G_DATA_PKR->name);

	i32 id = findFilePKR(v15, localName);
	if ( !id )
		return 0;

	PKR_UnlockFile(G_DATA_PKR);

#if _WIN32
	G_OPEN_FILE = CreateFileA(FileName, GENERIC_READ, 1, 0, 3, 1, 0);
#else
	G_OPEN_FILE = INVALID_HANDLE_VALUE;
#endif
	if (G_OPEN_FILE == INVALID_HANDLE_VALUE)
	{
		PKR_LockFile(G_DATA_PKR);
		G_OPEN_FILE = 0;
		return 0;
	}

#if _WIN32
	SetFilePointer(G_OPEN_FILE, G_OPEN_FILES[(id ^ 0xFF) - 1].mOffset, 0, 0);
#endif
	return G_OPEN_FILE;
}

// @Ok
// @Matching
void gdFsClose(HANDLE handle)
{
	if (handle != G_OPEN_FILE)
	{
		// @FIXME: portability issues
		closeFilePKR(reinterpret_cast<i32>(handle));
		return;
	}

#ifdef _WIN32
	CloseHandle(G_OPEN_FILE);
#endif
	PKR_LockFile(G_DATA_PKR);
}

// @Ok
EXPORT i32 gdFsInit(void)
{
#ifdef _WIN32
	GetCurrentDirectoryA(260, G_CURRENT_DIR);
#endif

	strcpy(G_FS_BASE, "data\\");
	openPKR();

	PCMOVIE_InitOnce();
	PCMOVIE_OpenPKR();

	return 0;
}

// @Ok
// @Matching
INLINE void closeFilePKR(i32 id)
{
	i32 i = (id ^ 0xFF);
	i--;
	if (G_OPEN_FILES[i].mBuf)
	{
		delete G_OPEN_FILES[i].mBuf;
		G_OPEN_FILES[i].mBuf = 0;
		G_OPEN_FILES[i].mOffset = 0;
		G_OPEN_FILES[i].mEnd = 0;
	}
}

// @Ok
INLINE void closePKR(void)
{
	char v0[512]; // [esp+0h] [ebp-200h] BYREF

	if (G_DATA_PKR)
	{
		if (!PKR_Close(G_DATA_PKR))
		{
			if (PKR_GetLastError(v0))
				error("PKR\t: %s\r\n", v0);
		}

		G_DATA_PKR = 0;
	}
	else
	{
		error("PKR\t: No PKR currently open.\r\n");
	}
}

// @Ok
INLINE i32 findFilePKR(
		char* a1,
		const char* a2)
{
	i32 nFile = nextFile();
	if (nFile == -1)
		return 0;

	PKR_FILEINFO fileInfo;
	if (!PKR_GetFileInfo(G_DATA_PKR, a1, a2, &fileInfo))
	{
		char buf[512];
		if(PKR_GetLastError(buf))
			error("PKR\t: %s%s - %s\r\n", a1, a2, buf);

		return 0;
	}

	G_OPEN_FILES[nFile].mOffset = fileInfo.fileOffset;
	return (nFile + 1) ^ 0xFF;
}

// @Ok
INLINE i32 nextFile(void)
{
	for (i32 i = 0;
			i < MAX_OPEN_FILE_COUNT;
			i++)
	{
		if (G_OPEN_FILES[i].mBuf == 0)
			return i;
	}

	error("PKR\t: TOO MANY OPEN FILES\r\n");
	return -1;
}

// @Ok
INLINE i32 openFilePKR(char * a1,const char* a2)
{
	i32 nFile = nextFile();
	if (nFile == -1)
		return 0;

	if (!PKR_ReadFile(
				G_DATA_PKR,
				a1,
				a2,
				reinterpret_cast<void**>(&G_OPEN_FILES[nFile].mBuf),
				&G_OPEN_FILES[nFile].mEnd))
	{
		char buf[512];
		if (PKR_GetLastError(buf))
			error("PKR\t: %s%s - %s\r\n", a1, a2, buf);

		return 0;
	}

	G_OPEN_FILES[nFile].mOffset = 0;
	return (nFile + 1) ^ 0xFF;
}

// @Ok
INLINE void openPKR(void)
{
	char error[512];

	if (!G_DATA_PKR)
	{
		if (!PKR_Open(&G_DATA_PKR, "data.pkr", 1))
		{
			if (PKR_GetLastError(error))
			{
				DXERR_printf("PKR\t: %s\r\n", error);
			}
		}
		else
		{
			DXERR_printf("PKR\t: Name       : %s\r\n", G_DATA_PKR->name);
			DXERR_printf("PKR\t: N.O. Dir   : %i\r\n", G_DATA_PKR->mFooter.numDirs);
			DXERR_printf("PKR\t: N.O. Files : %i\r\n", G_DATA_PKR->mFooter.numFiles);
		}
	}
	else
	{
		DXERR_printf("PKR\t: PKR %s already open\r\n", G_DATA_PKR->name);
	}
}

// @Ok
INLINE i32 seekFilePKR(
		i32 a1,
		i32 seekOffset,
		i32 seekType)
{
	i32 index = (a1 ^ 0xFF) - 1;

	if (!G_OPEN_FILES[index].mBuf)
		return 0;

	switch (seekType)
	{
		case 0:
			G_OPEN_FILES[index].mOffset = seekOffset;
			break;
		case 1:
			G_OPEN_FILES[index].mOffset += seekOffset;
			break;
		case 2:
			G_OPEN_FILES[index].mOffset = G_OPEN_FILES[index].mEnd - seekOffset;
			break;
	}

	return G_OPEN_FILES[index].mOffset;
}

// @Ok
INLINE i32 tellFilePKR(i32 a1)
{
	return G_OPEN_FILES[(a1 ^ 0xFF) - 1].mOffset;
}

void validate_SGDOpenFile(void)
{
	VALIDATE_SIZE(SGDOpenFile, 0xC);
	VALIDATE(SGDOpenFile, mBuf, 0x0);
	VALIDATE(SGDOpenFile, mOffset, 0x4);
	VALIDATE(SGDOpenFile, mEnd, 0x8);
}
