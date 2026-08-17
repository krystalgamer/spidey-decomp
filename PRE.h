#pragma once

#ifndef PRE_H
#define PRE_H

#include "main.h"
#include "export.h"

class PREManager : CClass
{
	public:

		char *mPre[16];
		char mPreName[16][16];

		EXPORT char* getFile(const char *,i32 *);
		EXPORT char* parsePRE(char *,char *,i32 *);
};

EXPORT extern PREManager* gPreManager;
EXPORT extern i32 gPreFileSize;
EXPORT extern void* gPreFileBuf;

//#define G_PRE_MANAGER (gPreManager)
#define G_PRE_MANAGER (*reinterpret_cast<PREManager**>(0x0060FC7C))

//#define G_PRE_FILE_SIZE (gPreFileSize)
#define G_PRE_FILE_SIZE (*reinterpret_cast<i32*>(0x0057C414))

//#define G_PRE_FILE_BUF (gPreFileBuf)
#define G_PRE_FILE_BUF (*reinterpret_cast<void**>(0x0057C410))

void validate_PREManager(void);
#endif
