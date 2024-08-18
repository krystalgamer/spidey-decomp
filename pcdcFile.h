#pragma once

#ifndef PCDCFILE_H
#define PCDCFILE_H

#include "export.h"

#ifdef _WIN32
#include <windows.h>
#endif

EXPORT void closeFilePKR(i32);
EXPORT void closePKR(void);
EXPORT void findFilePKR(char *,char const *);
EXPORT void nextFile(void);
EXPORT void openFilePKR(char *,char const *);
EXPORT void openPKR(void);
EXPORT void readFilePKR(i32,char *,i32);
EXPORT void seekFilePKR(i32,i32,i32);
EXPORT void tellFilePKR(i32);

EXPORT i32 gdFsInit(void);

#endif
