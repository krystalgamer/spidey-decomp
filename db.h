#pragma once

#ifndef DB_H
#define DB_H

#include "export.h"

EXPORT void Db_CreateOTsAndPolyBuffers(void);
EXPORT void Db_DefaultScreenOffsets(void);
EXPORT void Db_DeleteOTsAndPolyBuffers(void);
EXPORT void Db_FlipClear(void);
EXPORT void Db_Init(void);
EXPORT void Db_UpdateSky(void);

#endif
