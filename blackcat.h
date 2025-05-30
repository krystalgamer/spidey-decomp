#pragma once

#include "export.h"
#include "baddy.h"
#include "reloc.h"

class CBlackCat : public CBaddy {
public:
	
	EXPORT CBlackCat(i16*, i32);
	EXPORT virtual ~CBlackCat(void);

	EXPORT void Shouldnt_DoPhysics_Be_Virtual(void);
	EXPORT void DoPhysics(void);
	EXPORT void KillAllCommandBlocks(void);
	EXPORT int* KillCommandBlock(int*);

	EXPORT void AI(void) OVERRIDE;
	EXPORT void DoMGSShadow(void);
	EXPORT i32* GetNewCommandBlock(u32);
	EXPORT void KillCommandBlockByID(i32);
	EXPORT void SynthesizeAnalogueInput(void);

	i32 field_324;
	i32 field_328;
	i32 field_32C;

	PADDING(0x33C-0x32C-4);

	// @FIXME guess type
	void *field_33C;

	u8 field_340;
	i32 field_344;

	u8 field_348;

	i32 field_34C;
	i32* field_350;
};

void validate_CBlackCat(void);
EXPORT void BlackCat_CreateBlackCat(const u32 *stack, u32 *result);
EXPORT void BlackCat_RelocatableModuleClear(void);
EXPORT void BlackCat_RelocatableModuleInit(reloc_mod*);
