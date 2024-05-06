#pragma once

#ifndef M3DCOLIJ_H
#define M3DCOLIJ_H


#include "export.h"
#include "vector.h"

struct SLineInfo
{
	CVector vec_0;
	CVector vec_C;
};


void validate_SLineInfo(void);
EXPORT void M3dColij_InitLineInfo(SLineInfo *);

#endif
