#pragma once

#ifndef PRE_H
#define PRE_H

#include "main.h"
#include "export.h"

class PREManager : CClass
{
	public:
		EXPORT void* getFile(const char *,i32 *);
		EXPORT i32 parsePRE(char *,char *,i32 *);
};

EXPORT extern PREManager* gPreManager;
EXPORT extern i32 gPreFileSize;
EXPORT extern void* gPreFileBuf;
#endif
