#include "pcdcFile.h"
#include "PCMovie.h"
#include "pkr.h"
#include "SpideyDX.h"
#include "validate.h"

#include <cstring>

#ifdef _WIN32
EXPORT TCHAR gCurrentDir[260];
#endif

EXPORT char gFsBase[260];

const i32 MAX_OPEN_FILE_COUNT = 5;
EXPORT SGDOpenFile gOpenFiles[MAX_OPEN_FILE_COUNT];

EXPORT HANDLE gOpenFile;

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
	if (!gOpenFiles[index].mBuf)
		return 0;

	i32 mOffset = gOpenFiles[index].mOffset;
	i32 mEnd = gOpenFiles[index].mEnd;
	if (mOffset + size > mEnd)
		size = mEnd - mOffset;

	memcpy(pBuf, &gOpenFiles[index].mBuf[mOffset], size);
	gOpenFiles[index].mOffset += size;
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
	strcpy(buf, gFsBase);
	strcat(buf, pFileName);

	if (!strchr(pFileName, '\\'))
		return reinterpret_cast<HANDLE>(openFilePKR(gFsBase, pFileName));

	char v16[32];
	strcpy(v16, pFileName);

	char localName[32];
	strcpy(localName, strchr(pFileName, '\\') + 1);
	strchr(v16, '\\')[1] = 0;

	char v15[32];
	strcpy(v15, gFsBase);
	strcat(v15, v16);
	if (!strstr(localName, ".bik"))
		return reinterpret_cast<HANDLE>(openFilePKR(v15, localName));

	char FileName[512];
	strcpy(FileName, gDataPkr->name);

	i32 id = findFilePKR(v15, localName);
	if ( !id )
		return 0;

	PKR_UnlockFile(gDataPkr);

#if _WIN32
	gOpenFile = CreateFileA(FileName, GENERIC_READ, 1, 0, 3, 1, 0);
#else
	gOpenFile = INVALID_HANDLE_VALUE;
#endif
	if (gOpenFile == INVALID_HANDLE_VALUE)
	{
		PKR_LockFile(gDataPkr);
		gOpenFile = 0;
		return 0;
	}

#if _WIN32
	SetFilePointer(gOpenFile, gOpenFiles[(id ^ 0xFF) - 1].mOffset, 0, 0);
#endif
	return gOpenFile;
}

// @Ok
// @Matching
void gdFsClose(HANDLE handle)
{
	if (handle != gOpenFile)
	{
		// @FIXME: portability issues
		closeFilePKR(reinterpret_cast<i32>(handle));
		return;
	}

#ifdef _WIN32
	CloseHandle(gOpenFile);
#endif
	PKR_LockFile(gDataPkr);
}

// @Ok
EXPORT i32 gdFsInit(void)
{
#ifdef _WIN32
	GetCurrentDirectoryA(260, gCurrentDir);
#endif

	strcpy(gFsBase, "data\\");
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
	if (gOpenFiles[i].mBuf)
	{
		delete gOpenFiles[i].mBuf;
		gOpenFiles[i].mBuf = 0;
		gOpenFiles[i].mOffset = 0;
		gOpenFiles[i].mEnd = 0;
	}
}

// @Ok
INLINE void closePKR(void)
{
	char v0[512]; // [esp+0h] [ebp-200h] BYREF

	if (gDataPkr)
	{
		if (!PKR_Close(gDataPkr))
		{
			if (PKR_GetLastError(v0))
				error("PKR\t: %s\r\n", v0);
		}

		gDataPkr = 0;
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
	if (!PKR_GetFileInfo(gDataPkr, a1, a2, &fileInfo))
	{
		char buf[512];
		if(PKR_GetLastError(buf))
			error("PKR\t: %s%s - %s\r\n", a1, a2, buf);

		return 0;
	}

	gOpenFiles[nFile].mOffset = fileInfo.fileOffset;
	return (nFile + 1) ^ 0xFF;
}

// @Ok
INLINE i32 nextFile(void)
{
	for (i32 i = 0;
			i < MAX_OPEN_FILE_COUNT;
			i++)
	{
		if (gOpenFiles[i].mBuf)
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
				gDataPkr,
				a1,
				a2,
				reinterpret_cast<void**>(&gOpenFiles[nFile].mBuf),
				&gOpenFiles[nFile].mEnd))
	{
		char buf[512];
		if (PKR_GetLastError(buf))
			error("PKR\t: %s%s - %s\r\n", a1, a2, buf);

		return 0;
	}

	gOpenFiles[nFile].mOffset = 0;
	return (nFile + 1) ^ 0xFF;
}

// @Ok
INLINE void openPKR(void)
{
	char error[512];

	if (!gDataPkr)
	{
		if (!PKR_Open(&gDataPkr, "data.pkr", 1))
		{
			if (PKR_GetLastError(error))
			{
				DXERR_printf("PKR\t: %s\r\n", error);
			}
		}
		else
		{
			DXERR_printf("PKR\t: Name       : %s\r\n", gDataPkr->name);
			DXERR_printf("PKR\t: N.O. Dir   : %i\r\n", gDataPkr->mFooter.numDirs);
			DXERR_printf("PKR\t: N.O. Files : %i\r\n", gDataPkr->mFooter.numFiles);
		}
	}
	else
	{
		DXERR_printf("PKR\t: PKR %s already open\r\n", gDataPkr->name);
	}
}

// @Ok
INLINE i32 seekFilePKR(
		i32 a1,
		i32 seekOffset,
		i32 seekType)
{
	i32 index = (a1 ^ 0xFF) - 1;

	if (!gOpenFiles[index].mBuf)
		return 0;

	switch (seekType)
	{
		case 0:
			gOpenFiles[index].mOffset = seekOffset;
			break;
		case 1:
			gOpenFiles[index].mOffset += seekOffset;
			break;
		case 2:
			gOpenFiles[index].mOffset = gOpenFiles[index].mEnd - seekOffset;
			break;
	}

	return gOpenFiles[index].mOffset;
}

// @Ok
INLINE i32 tellFilePKR(i32 a1)
{
	return gOpenFiles[(a1 ^ 0xFF) - 1].mOffset;
}

void validate_SGDOpenFile(void)
{
	VALIDATE_SIZE(SGDOpenFile, 0xC);
	VALIDATE(SGDOpenFile, mBuf, 0x0);
	VALIDATE(SGDOpenFile, mOffset, 0x4);
	VALIDATE(SGDOpenFile, mEnd, 0x8);
}
