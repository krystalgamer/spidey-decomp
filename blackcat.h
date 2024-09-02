#pragma once

#include "export.h"
#include "baddy.h"

class CBlackCat : public CBaddy {
public:
	
	EXPORT CBlackCat(int*, int);
	EXPORT virtual ~CBlackCat(void);

	EXPORT void Shouldnt_DoPhysics_Be_Virtual(void);
	EXPORT void DoPhysics(void);
	EXPORT void KillAllCommandBlocks(void);
	EXPORT int* KillCommandBlock(int*);

	EXPORT void AI(void) OVERRIDE;
	EXPORT void DoMGSShadow(void);
	EXPORT void GetNewCommandBlock(u32);
	EXPORT void KillCommandBlockByID(i32);
	EXPORT void SynthesizeAnalogueInput(void);

	i32 field_324;
	i32 field_328;
	i32 field_32C;
	unsigned char padAfter32C[0x33C-0x32C-4];

	// @FIXME guess type
	void *field_33C;
	unsigned char field_340;
	int field_344;

	unsigned char field_348;

	int field_34C;
	i32* field_350;
};

void validate_CBlackCat(void);
EXPORT void BlackCat_CreateBlackCat(const unsigned int *stack, unsigned int *result);
EXPORT void BlackCat_RelocatableModuleClear(void);
