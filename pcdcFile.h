#pragma once

#ifndef PCDCFILE_H
#define PCDCFILE_H

#include "export.h"

#ifdef _WIN32
#include <windows.h>
#else
typedef void* HANDLE;
#endif


struct SGDOpenFile
{
	void* field_0;
	i32 field_4;
	i32 field_8;
};

EXPORT void closeFilePKR(i32);
EXPORT void closePKR(void);
EXPORT i32 findFilePKR(char *,const char *);
EXPORT i32 nextFile(void);
EXPORT i32 openFilePKR(char *,const char*);
EXPORT void openPKR(void);
EXPORT void readFilePKR(i32,char *,i32);
EXPORT i32 seekFilePKR(i32,i32,i32);
EXPORT i32 tellFilePKR(i32);

EXPORT void gdFsClose(HANDLE);
EXPORT HANDLE gdFsOpen(const char*, i32);
EXPORT i32 gdFsGetFileSize(i32, i32*);
EXPORT i32 gdFsInit(void);

void validate_SGDOpenFile(void);

#endif
