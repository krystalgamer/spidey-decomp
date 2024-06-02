#pragma once

#ifndef SPCLONE_H
#define SPCLONE_H

#include "export.h"
#include "baddy.h"


class CSpClone : public CBaddy {
public:
	EXPORT void Shouldnt_DoPhysics_Be_Virtual(void);
	EXPORT void DoPhysics(void);
	EXPORT void KillAllCommandBlocks(void);
	EXPORT int* KillCommandBlock(int*);

	int padTop;

	int field_328;
	int field_32C;
	int field_330;
	int field_334;
	CQuadBit *field_338;

	unsigned char padAfter338[0x34C-0x338-4];

	int* field_34C;
};

void validate_CSpClone(void);

#endif
