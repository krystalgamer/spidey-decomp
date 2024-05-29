#pragma once

#ifndef SPOOL_H
#define SPOOL_H


#include "export.h"

EXPORT int Spool_FindRegion(const char *);
EXPORT unsigned int Spool_GetModel(unsigned int, int);
EXPORT unsigned int *Spool_SkipPackets(unsigned int *);

#endif
