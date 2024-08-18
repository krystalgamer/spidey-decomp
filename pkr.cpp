#include "pkr.h"
#include "zlib.h"

#include "validate.h"

#define PKRFILE_UNCOMPRESSED -2
#define PKRFILE_COMPRESSED_ZLIB 2

// @NB: the original was built as library and built in debug mode, I won't do the same
// too much hassle for little gain

u8 PKR_UnlockFile(FILE** fp)
{
	if (*fp)
	{
		fclose(*fp);
		*fp = 0;
		return 1;
	}

	return 0;
}

// @Ok
u8* decompressZLIB(u8* src, u32 srcLen, u32 dstLen)
{
	u8* dst = new u8[dstLen];

	if (dst)
	{
		i32 rcode = uncompress(
				dst,
				reinterpret_cast<unsigned long*>(&dstLen),
				src,
				srcLen);
		if (rcode)
		{
			delete[] dst;

			switch (rcode)
			{
				case Z_BUF_ERROR:
					printf("decompressZLIB(): Decompressed data buffer is too small!\n");
					break;
				case Z_MEM_ERROR:
					printf("decompressZLIB(): Out of memory in ZLIB uncompress() routine!\n");
					break;
				case Z_DATA_ERROR:
					printf("decompressZLIB(): ZLIB uncompress() routine says data is invalid!\n");
					break;
				default:
					printf("decompressZLIB(): Unexpected rcode = %i\n", rcode);
					break;
			}

		}
	}

	return dst;
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
u8* PKRComp_DecompressFile(PKR_FILEINFO* pFile, u8* buf, i32 deleteBuf)
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

void validate_PKR_FILEINFO(void)
{
	VALIDATE_SIZE(PKR_FILEINFO, 0x34);

	VALIDATE(PKR_FILEINFO, name, 0x0);
	VALIDATE(PKR_FILEINFO, crc, 0x20);
	VALIDATE(PKR_FILEINFO, compressed, 0x24);
	VALIDATE(PKR_FILEINFO, fileOffset, 0x28);
	VALIDATE(PKR_FILEINFO, uncompressedSize, 0x2C);
	VALIDATE(PKR_FILEINFO, compressedSize, 0x30);
}

void validate_PKR_FOOTER(void)
{
	VALIDATE_SIZE(PKR_FOOTER, 0xC);

	VALIDATE(PKR_FOOTER, field_0, 0x0);
	VALIDATE(PKR_FOOTER, numDirs, 0x4);
	VALIDATE(PKR_FOOTER, numFiles, 0x8);
}
