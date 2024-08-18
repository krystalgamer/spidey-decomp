#ifndef PKR_H
#define PKR_H

#pragma once

#include "export.h"

struct PKRFile
{
	char name[0x20];
	u32 crc;
	i32 compressed;
	u32 fileOffset;
	u32 uncompressedSize;
	u32 compressedSize;
};

EXPORT u8 fileCRCCheck(u8*, i32, u32);
EXPORT void PKR_ReportError(const char*, ...);

EXPORT u8* decompressZLIB(u8*, u32, u32);
EXPORT u8* PKRComp_DecompressFile(PKRFile*, u8*, i32);

void validate_PKRFile(void);

#endif
