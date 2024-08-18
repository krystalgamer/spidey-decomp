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
	i32 numDirs;
	i32 numFiles;
};

struct PKR_DIRINFO
{
	char name[0x20];

	i32 field_20;
	i32 numFiles;
};

EXPORT u8 fileCRCCheck(u8*, i32, u32);
EXPORT void PKR_ReportError(const char*, ...);

EXPORT u8* decompressZLIB(u8*, u32, u32);
EXPORT u8* PKRComp_DecompressFile(PKR_FILEINFO*, u8*, i32);
EXPORT u8 PKR_UnlockFile(FILE** fp);

void validate_PKR_FILEINFO(void);
void validate_PKR_FOOTER(void);
void validate_PKR_DIRINFO(void);

#endif
