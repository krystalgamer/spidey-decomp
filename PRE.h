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

void validate_PREManager(void);
#endif
