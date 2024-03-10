#pragma once

#include "export.h"


struct MATRIX{
	__int16 m[3][3];
	int t[3];
};

void validate_MATRIX(void);
EXPORT void gte_SetRotMatrix(MATRIX*);