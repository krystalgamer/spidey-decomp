#pragma once

#ifndef DOCOCK_H
#define DOCOCK_H

#include "export.h"
#include "baddy.h"

class CDocOc : public CBaddy {

public:
	EXPORT CDocOc(int*, int);
	EXPORT void RenderClaws(void);
	EXPORT void PlaySingleAnim(unsigned int , int, int);
	EXPORT void Gloat(void);
	EXPORT void PlayIdleOrGloatAnim(void);
	EXPORT void KillAllCommandBlocks(void);
	EXPORT int* KillCommandBlock(int*);
	EXPORT void TakeHit(void);
	EXPORT void CalculateStage(void);

	int field_324;
	int field_328;
	int field_32C;
	int field_330;
	CVector field_334[30];
	unsigned char padAfter334[0xC];

	int field_4A8;
	int field_4AC;
	unsigned char padAfter4AC[0x4C4-0x4AC-4];

	int field_4C4;
	unsigned char padAfter4C4[0x4EC-0x4C4-4];

	int field_4EC;
	unsigned char padAfter4EC[0x1C];

	CVector field_50C;
	unsigned char padAfter50C[0x550-0x50C-sizeof(CVector)];

	i32 field_550;
	int field_554;
	unsigned char padAfter554[0x570-0x554-4];

	void* field_570;

	unsigned char padBottom[0x590-0x570-4];
};


void validate_CDocOc(void);
EXPORT void DocOck_CreateDocOck(const unsigned int *stack, unsigned int *result);

#endif
