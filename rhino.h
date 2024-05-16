#pragma once

#include "export.h"
#include "baddy.h"

class CRhino : public CBaddy {
public:
	EXPORT CRhino(int*, int);
	EXPORT CRhino(void);

	unsigned char padTop[0x344 - 0x324];
	int field_344;
	unsigned char padAfter344[0x424-0x344-4];
};

void validate_CRhino(void);
EXPORT void Rhino_CreateRhino(const unsigned int *stack, unsigned int *result);
