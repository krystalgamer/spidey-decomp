#pragma once

#ifndef TORCH_H
#define TORCH_H

#include "baddy.h"
#include "export.h"

#include "reloc.h"

class CTorch : public CBaddy {

public:

	EXPORT CTorch(i16*, i32);
	EXPORT ~CTorch(void);

	EXPORT void Shouldnt_DoPhysics_Be_Virtual(void);
	EXPORT void DoPhysics(void);
	EXPORT i32* KillCommandBlock(i32*);
	EXPORT i32* GetNewCommandBlock(u32);
	EXPORT void KillAllCommandBlocks(void);

	i32 field_324;
	i32 field_328;	
	i32 field_32C;
	i32 field_330;
	i32 field_334;
	i32 field_338;

	CQuadBit *gTorchQuadBit;

	u8 field_340;
	i32 field_344;
	u8 field_348;

	i32 field_34C;
	i32* field_350;
};


void validate_CTorch(void);
EXPORT void Torch_CreateTorch(const u32 *stack, u32 *result);
EXPORT void Torch_RelocatableModuleInit(reloc_mod *);
EXPORT void Torch_RelocatableModuleClear(void);

#endif 
