#pragma once

#ifndef DOCOCK_H
#define DOCOCK_H

#include "export.h"
#include "baddy.h"
#include "reloc.h"

class CDocOc : public CBaddy {

public:
	EXPORT CDocOc(i16*, i32);
	EXPORT virtual ~CDocOc(void);

	EXPORT void RenderClaws(void);
	EXPORT void PlaySingleAnim(unsigned int , int, int);
	EXPORT void Gloat(void);
	EXPORT void PlayIdleOrGloatAnim(void);
	EXPORT void KillAllCommandBlocks(void);
	EXPORT i32* GetNewCommandBlock(u32);

	EXPORT i32* KillCommandBlock(i32*);
	EXPORT void TakeHit(void);
	EXPORT void CalculateStage(void);
	EXPORT void HangAndGetBeaten(void);
	EXPORT void Initialise(void);
	EXPORT void ResolveSwitches(void);

	int field_324;
	int field_328;
	int field_32C;
	int field_330;
	CVector field_334[30];
	unsigned char padAfter334[0xC];

	int field_4A8;
	i32* field_4AC;
	u8 padAfter4AC[0x4B8-0x4AC-4];

	i32 field_4B8;
	u8 padAfter4B8[0x4C4-0x4B8-4];

	int field_4C4;
	unsigned char padAfter4C4[0x4EC-0x4C4-4];

	int field_4EC;
	u8 padAfter4EC[0x4F4-0x4EC-4];

	i32 field_4F4;
	u8 padAfter4F4[0x4FC-0x4F4-4];

	CBaddy* field_4FC[4];

	CVector field_50C;
	i32 field_518;
	unsigned char padAfter518[0x530-0x518-4];

	// @FIXME
	void* field_530[4];
	u8 padAfter530[0x10];

	i32 field_550;
	i32 field_554;
	u8 padAfter554[0x55C-0x554-4];

	i32 field_55C;
	u8 padAfter55C[0x570-0x55C-4];

	void* field_570[4];
	void* field_580[4];
};


void validate_CDocOc(void);
EXPORT void DocOck_CreateDocOck(const unsigned int *stack, unsigned int *result);
EXPORT void DocOck_RelocatableModuleClear(void);
EXPORT void DocOck_RelocatableModuleInit(reloc_mod *);

#endif
