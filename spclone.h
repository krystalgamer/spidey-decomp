#pragma once

#ifndef SPCLONE_H
#define SPCLONE_H

#include "export.h"
#include "baddy.h"

#include "reloc.h"

class CSpClone : public CBaddy {
	public:
		EXPORT void AI(void);
		EXPORT CSpClone(i16 *,i32);
		EXPORT void DoMGSShadow(void);
		EXPORT i32* GetNewCommandBlock(u32);
		EXPORT void KillCommandBlockByID(i32);
		EXPORT void SynthesizeAnalogueInput(void);
		EXPORT ~CSpClone(void);
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

		unsigned char padAfter338[0x348-0x338-4];

		i32 field_348;
		i32* field_34C;
};

void validate_CSpClone(void);
EXPORT void SpClone_CreateSpClone(const u32 *,u32 *);
EXPORT void SpClone_RelocatableModuleClear(void);
EXPORT void SpClone_RelocatableModuleInit(reloc_mod *);

#endif
