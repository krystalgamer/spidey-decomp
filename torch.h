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

	int field_324;
	int field_328;	
	int field_32C;
	int field_330;
	int field_334;
	int field_338;

	CQuadBit *gTorchQuadBit;

	unsigned char field_340;
	int field_344;
	unsigned char field_348;

	int field_34C;
	i32* field_350;
};


void validate_CTorch(void);
EXPORT void Torch_CreateTorch(const unsigned int *stack, unsigned int *result);
EXPORT void Torch_RelocatableModuleInit(reloc_mod *);
EXPORT void Torch_RelocatableModuleClear(void);

#endif 
