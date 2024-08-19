#include "pkr.h"
#include "zlib.h"

#include "validate.h"
#include <cstring>
#include <cstdlib>

#define PKRFILE_UNCOMPRESSED -2
#define PKRFILE_COMPRESSED_ZLIB 2

LIBPKR_HANDLE* gGlobalPkr;

// @NB: the original was built as library and built in debug mode, I won't do the same
// too much hassle for little gain

// @Ok
u8 dirAddToPkr(LIBPKR_HANDLE* pHandle, PKR_DIRINFO dirInfo)
{
	NODE_DIRINFO* newNode = new NODE_DIRINFO;
	if (!newNode)
	{
		PKR_ReportError("dirAddToPKR: Cannot allocate new dir node.");
		return 0;
	}

	memset(newNode, 0, sizeof(NODE_DIRINFO));
	memcpy(newNode, &dirInfo, sizeof(PKR_DIRINFO));

	if (!pHandle->pDirInfo)
	{
		pHandle->pDirInfo = newNode;
	}
	else
	{
		NODE_DIRINFO* pNode;
		for (pNode = pHandle->pDirInfo;
				pNode->mNext;
				pNode = pNode->mNext)
		{
			if (!strcmp(pNode->dirInfo.name, newNode->dirInfo.name))
			{
				PKR_ReportError("dirAddToPKR: Dir already added.");
				delete newNode;
				return 0;
			}
		}

		if (!strcmp(pNode->dirInfo.name, newNode->dirInfo.name))
		{
			PKR_ReportError("dirAddToPKR: Dir already added.");
			delete newNode;
			return 0;
		}

		pNode->mNext = newNode;
		newNode->mPrev = pNode;
		newNode->mNext = 0;
	}

	pHandle->footer.numDirs++;
	return 1;
}

// @BIGTODO
u8 PKR_GetLastError(char*)
{
	printf("u8 PKR_GetLastError(char*)");
	return (u8)0x18082024;
}

// @MEDIUMTODO
u8 PKR_Open(LIBPKR_HANDLE**, const char*, i32)
{
	printf("u8 PKR_Open(LIBPKR_HANDLE*, const char*, i32)");
	return (u8)0x18082024;
}

// @Ok
u8 PKR_UnlockFile(LIBPKR_HANDLE* hPkr)
{
	if (hPkr->fp)
	{
		fclose(hPkr->fp);
		hPkr->fp = 0;
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

void validate_PKR_DIRINFO(void)
{
	VALIDATE_SIZE(PKR_DIRINFO, 0x28);

	VALIDATE(PKR_DIRINFO, name, 0x0);
	VALIDATE(PKR_DIRINFO, field_20, 0x20);
	VALIDATE(PKR_DIRINFO, numFiles, 0x24);
}

void validate_LIBPKR_HANDLE(void)
{
	VALIDATE_SIZE(LIBPKR_HANDLE, 0x12C);

	VALIDATE(LIBPKR_HANDLE, fp, 0x0);
	VALIDATE(LIBPKR_HANDLE, name, 0x4);

	VALIDATE(LIBPKR_HANDLE, field_108, 0x108);
	VALIDATE(LIBPKR_HANDLE, pkrMagic, 0x10C);
	VALIDATE(LIBPKR_HANDLE, dirOffset, 0x110);

	VALIDATE(LIBPKR_HANDLE, footer, 0x114);
	VALIDATE(LIBPKR_HANDLE, pDirInfo, 0x120);
}

void validate_NODE_DIRINFO(void)
{
	VALIDATE_SIZE(NODE_DIRINFO, 0x30);

	VALIDATE(NODE_DIRINFO, dirInfo, 0x0);
	VALIDATE(NODE_DIRINFO, mNext, 0x28);
	VALIDATE(NODE_DIRINFO, mPrev, 0x2C);
}
