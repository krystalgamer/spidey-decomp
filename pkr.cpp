#include "pkr.h"
#include "zlib.h"

#include "validate.h"
#include <cstring>
#include <cstdlib>

#define PKRFILE_UNCOMPRESSED -2
#define PKRFILE_COMPRESSED_ZLIB 2

LIBPKR_HANDLE* gDataPkr;

// @NB: the original was built as library and built in debug mode, I won't do the same
// too much hassle for little gain

// @Ok
u8 PKR_LockFile(LIBPKR_HANDLE* pHandle)
{
	if (pHandle->fp)
		return 1;

	pHandle->fp = fopen(pHandle->name, "rb+");
	if (pHandle->fp)
		return 1;

	PKR_ReportError("PKR_UnlockFile: Error cannot open %s", &pHandle->name);
	return 0;
}

// @SMALLTODO
u8 fileAddToPKR(LIBPKR_HANDLE*, PKR_FILEINFO, PKR_DIRINFO*, char*)
{
	printf("u8 fileAddToPkr(LIBPKR_HANDLE*, PKR_FILEINFO, PKR_DIRINFO*, char*)");
	return (u8)0x20082024;
}

// @Ok
u8 dirAddToPKR(LIBPKR_HANDLE* pHandle, PKR_DIRINFO dirInfo)
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

	pHandle->mFooter.numDirs++;
	return 1;
}

// @BIGTODO
u8 PKR_GetLastError(char*)
{
	printf("u8 PKR_GetLastError(char*)");
	return (u8)0x18082024;
}

// @Ok
u8 PKR_Open(
		LIBPKR_HANDLE** ppHandle,
		const char* name,
		i32 readOnly)
{
	LIBPKR_HANDLE* pHandle = new LIBPKR_HANDLE;
	if (!pHandle)
	{
		*ppHandle = 0;
		PKR_ReportError("PKR_Open: Cannot allocate handle");
		return 0;
	}

	memset(pHandle, 0, sizeof(LIBPKR_HANDLE));
	strcpy(pHandle->name, name);

	FILE* fp = fopen(name, "rb");
	if (!fp)
	{
		*ppHandle = 0;
		PKR_ReportError("PKR_Open: PKR file is not found at %s", name);
		return 0;
	}

	fclose(fp);
	if (readOnly)
		pHandle->fp = fopen(name, "rb");
	else
		pHandle->fp = fopen(name, "rb+");

	if (fread(&pHandle->mHeader, sizeof(PKR_HEADER), 1, pHandle->fp) != 1)
	{
		fclose(pHandle->fp);
		*ppHandle = 0;
		PKR_ReportError("PKR_Open: Error reading PKR_HEADER from %s", name);
		return 0;
	}

	if (pHandle->mHeader.pkrMagic != 0x33524B50)
	{
		fclose(pHandle->fp);
		*ppHandle = 0;
		PKR_ReportError(
			"PKR_Open: %s is not a valid PKR. Magic code %08X isn't correct, should be %08X",
			name,
			pHandle->mHeader.pkrMagic,
			0x33524B50);
		return 0;
	}

	fseek(pHandle->fp, pHandle->mHeader.dirOffset, SEEK_SET);

	if (fread(&pHandle->mFooter, sizeof(PKR_FOOTER), 1u, pHandle->fp) != 1)
	{
		fclose(pHandle->fp);
		*ppHandle = 0;
		PKR_ReportError("PKR_Open: Error reading PKR_FOOTER from %s", name);
		return 0;
	}

	u32 numDirs = pHandle->mFooter.numDirs;
	pHandle->mFooter.numDirs = 0;
	pHandle->mFooter.numFiles = 0;
	for (u32 i = 0; i < numDirs; i++)
	{
		PKR_DIRINFO dirInfo;
		if (fread(&dirInfo, sizeof(PKR_DIRINFO), 1, pHandle->fp) != 1)
		{
			fclose(pHandle->fp);
			*ppHandle = 0;
			PKR_ReportError("PKR_Open: Error reading PKR_DIRINFO %i from %s", i, name);
			return 0;
		}

		if (!dirAddToPKR(pHandle, dirInfo))
			return 0;
	}
	
	NODE_DIRINFO* pDirInfo = pHandle->pDirInfo;
	for (u32 dirNum = 0; dirNum < pHandle->mFooter.numDirs; dirNum++)
	{
		u32 numFiles = pDirInfo->dirInfo.numFiles;
		pDirInfo->dirInfo.numFiles = 0;
		for (u32 j = 0; j < numFiles; j++ )
		{
			PKR_FILEINFO fileInfo;
			if ( fread(&fileInfo, sizeof(PKR_FILEINFO), 1u, pHandle->fp) != 1 )
			{
				fclose(pHandle->fp);
				*ppHandle = 0;
				PKR_ReportError("PKR_Open: Error reading PKR_FILEINFO %i from %s", dirNum, name);
				return 0;
			}
			if (!fileAddToPKR(pHandle, fileInfo, &pDirInfo->dirInfo, 0))
				return 0;
		}

		pDirInfo = pDirInfo->mNext;
	}


	pHandle->field_108 = -2;
	*ppHandle = pHandle;
	return 1;
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
	VALIDATE(LIBPKR_HANDLE, mHeader, 0x10C);

	VALIDATE(LIBPKR_HANDLE, mFooter, 0x114);
	VALIDATE(LIBPKR_HANDLE, pDirInfo, 0x120);
}

void validate_NODE_DIRINFO(void)
{
	VALIDATE_SIZE(NODE_DIRINFO, 0x30);

	VALIDATE(NODE_DIRINFO, dirInfo, 0x0);
	VALIDATE(NODE_DIRINFO, mNext, 0x28);
	VALIDATE(NODE_DIRINFO, mPrev, 0x2C);
}

void validate_PKR_HEADER(void)
{
	VALIDATE(PKR_HEADER, pkrMagic, 0x0);
	VALIDATE(PKR_HEADER, dirOffset, 0x4);
}
