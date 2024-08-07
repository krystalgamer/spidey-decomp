#pragma once

#ifndef PCDCFILE_H
#define PCDCFILE_H

#include "export.h"
EXPORT void closeFilePKR(i32);
EXPORT void closePKR(void);
EXPORT void findFilePKR(char *,char const *);
EXPORT void nextFile(void);
EXPORT void openFilePKR(char *,char const *);
EXPORT void openPKR(void);
EXPORT void readFilePKR(i32,char *,i32);
EXPORT void seekFilePKR(i32,i32,i32);
EXPORT void tellFilePKR(i32);

#endif
