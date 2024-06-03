#pragma once

#ifndef SPOOL_H
#define SPOOL_H


#include "export.h"
#include "texture.h"

EXPORT int Spool_FindRegion(const char *);
EXPORT unsigned int Spool_GetModel(unsigned int, int);
EXPORT unsigned int *Spool_SkipPackets(unsigned int *);
EXPORT Texture*  Spool_FindTextureEntry(unsigned int);

#endif
