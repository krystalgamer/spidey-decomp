#pragma once

#ifndef DCFILEIO_H
#define DCFILEIO_H

#include "export.h"

EXPORT void FileIO_Sync(void);
EXPORT void DebugPrintfX(char *,...);
EXPORT u8 FileIO_FileExists(const char *);
EXPORT void FileIO_Init(void);
EXPORT void FileIO_Load(void *);
EXPORT i32 FileIO_Open(const char *);

#endif
