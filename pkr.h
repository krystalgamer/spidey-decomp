#ifndef PKR_H
#define PKR_H

#pragma once

#include "export.h"

struct PKR_FILEINFO
{
	char name[0x20];
	u32 crc;
	i32 compressed;
	u32 fileOffset;
	u32 uncompressedSize;
	u32 compressedSize;
};

struct PKR_FOOTER
{
	i32 field_0;
	u32 numDirs;
	i32 numFiles;
};

struct PKR_DIRINFO
{
	char name[0x20];

	i32 field_20;
	i32 numFiles;
};

struct NODE_DIRINFO
{
	PKR_DIRINFO dirInfo;
	struct NODE_DIRINFO* mNext;
	struct NODE_DIRINFO* mPrev;
};

struct PKR_HEADER
{
	i32 pkrMagic;
	i32 dirOffset;
};

struct LIBPKR_HANDLE
{
	FILE* fp;
	char name[1];
	u8 padAfterName[0x108-4-1];


	i32 field_108;
	PKR_HEADER mHeader;
	PKR_FOOTER mFooter;

	NODE_DIRINFO* pDirInfo;

	u8 padBottom[0x12C-0x120-4];
};

EXPORT u8 fileCRCCheck(u8*, i32, u32);
EXPORT void PKR_ReportError(const char*, ...);

EXPORT u8* decompressZLIB(u8*, u32, u32);
EXPORT u8* PKRComp_DecompressFile(PKR_FILEINFO*, u8*, i32);
EXPORT u8 PKR_UnlockFile(LIBPKR_HANDLE* fp);
EXPORT u8 PKR_Open(LIBPKR_HANDLE**, const char*, i32);
EXPORT u8 PKR_GetLastError(char*);

EXPORT u8 dirAddToPKR(LIBPKR_HANDLE*, PKR_DIRINFO);
EXPORT u8 fileAddToPKR(LIBPKR_HANDLE*, PKR_FILEINFO, PKR_DIRINFO*, char*);

EXPORT extern LIBPKR_HANDLE* gDataPkr;

void validate_PKR_FILEINFO(void);
void validate_PKR_FOOTER(void);
void validate_PKR_DIRINFO(void);
void validate_LIBPKR_HANDLE(void);
void validate_NODE_DIRINFO(void);
void validate_PKR_HEADER(void);

#endif
