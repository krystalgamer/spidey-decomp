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

// @SMALLTODO
HANDLE gdFsOpen(const char*, i32)
{
	printf("HANDLE gdFsOpen(const char*)");
	return reinterpret_cast<HANDLE>(0x21082024);
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
	if (gOpenFiles[i].field_0)
	{
		delete gOpenFiles[i].field_0;
		gOpenFiles[i].field_0 = 0;
		gOpenFiles[i].field_4 = 0;
		gOpenFiles[i].field_8 = 0;
	}
}

// @Ok
void closePKR(void)
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

	PCMOVIE_ClosePKR();
}

// @Ok
i32 findFilePKR(
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

	gOpenFiles[nFile].field_4 = fileInfo.fileOffset;
	return (nFile + 1) ^ 0xFF;
}

// @Ok
INLINE i32 nextFile(void)
{
	for (i32 i = 0;
			i < MAX_OPEN_FILE_COUNT;
			i++)
	{
		if (gOpenFiles[i].field_0)
			return i;
	}

	error("PKR\t: TOO MANY OPEN FILES\r\n");
	return -1;
}

// @Ok
i32 openFilePKR(char * a1,const char* a2)
{
	i32 nFile = nextFile();
	if (nFile == -1)
		return 0;

	if (!PKR_ReadFile(
				gDataPkr,
				a1,
				a2,
				&gOpenFiles[nFile].field_0,
				&gOpenFiles[nFile].field_8))
	{
		char buf[512];
		if (PKR_GetLastError(buf))
			error("PKR\t: %s%s - %s\r\n", a1, a2, buf);

		return 0;
	}

	gOpenFiles[nFile].field_4 = 0;
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

// @SMALLTODO
void readFilePKR(i32,char *,i32)
{
    printf("readFilePKR(i32,char *,i32)");
}

// @SMALLTODO
void seekFilePKR(i32,i32,i32)
{
    printf("seekFilePKR(i32,i32,i32)");
}

// @Ok
i32 tellFilePKR(i32 a1)
{
	return gOpenFiles[(a1 ^ 0xFF) -1].field_4;
}

void validate_SGDOpenFile(void)
{
	VALIDATE_SIZE(SGDOpenFile, 0xC);
	VALIDATE(SGDOpenFile, field_0, 0x0);
	VALIDATE(SGDOpenFile, field_4, 0x4);
	VALIDATE(SGDOpenFile, field_8, 0x8);
}
