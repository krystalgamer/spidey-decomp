#include "pkr.h"
#include "zlib.h"

#include "validate.h"

#define PKRFILE_UNCOMPRESSED -2
#define PKRFILE_COMPRESSED_ZLIB 2

// @NB: the original was built as library and built in debug mode, I won't do the same
// too much hassle for little gain

// @SMALLTODO
u8* decompressZLIB(u8*, u32, u32)
{
	printf("u8* decompressZLIB(u8*, u32, u32)");
	return (u8*)0x18082024;
}

// @BIGTODO
void PKR_ReportError(const char*, ...)
{
	printf("void PKR_ReportError(const char*, ...)");
}

// @Ok
u8 fileCRCCheck(u8* buf, i32 size, u32 expected)
{
	u32 res = crc32(crc32(0,0,0), buf, size);

	if (res != expected)
	{
		PKR_ReportError("fileCRCCheck: Bad CRC. %08X bad. %08X correct. File is Damaged.", res, expected);
		return 0;
	}

	return 1;
}

// @Ok
u8* PKRComp_DecompressFile(PKRFile* pFile, u8* buf, i32 deleteBuf)
{
	if (pFile->compressed == PKRFILE_UNCOMPRESSED)
		return buf;

	// it's always zlib compressed
	// on the original code there's a array of decompressors but we don't need those
	u8* res = decompressZLIB(buf, pFile->compressedSize, pFile->uncompressedSize);
	if (deleteBuf)
		delete buf;

	return res;
}

void validate_PKRFile(void)
{
	VALIDATE_SIZE(PKRFile, 0x34);

	VALIDATE(PKRFile, name, 0x0);
	VALIDATE(PKRFile, crc, 0x20);
	VALIDATE(PKRFile, compressed, 0x24);
	VALIDATE(PKRFile, fileOffset, 0x28);
	VALIDATE(PKRFile, uncompressedSize, 0x2C);
	VALIDATE(PKRFile, compressedSize, 0x30);
}
