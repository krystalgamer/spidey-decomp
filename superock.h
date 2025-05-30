#pragma once

#ifndef SUPEROCK_H
#define SUPEROCK_H

#include "export.h"
#include "baddy.h"
#include "reloc.h"


class CSuperDocOck : public CBaddy {

public:
	EXPORT CSuperDocOck(i16*, i32);
	EXPORT virtual ~CSuperDocOck(void);

	EXPORT void DoPhysics(void);
	EXPORT void RenderClaws(void);
	EXPORT void KillAllCommandBlocks(void);
	EXPORT i32* KillCommandBlock(i32*);
	EXPORT i32* GetNewCommandBlock(u32);

	EXPORT void PlaySingleAnim(u32, i32, i32);
	EXPORT void Initialise(void);
	EXPORT void Gloat(void);
	EXPORT void PlayIdleOrGloatAnim(void);

	EXPORT void CreateExplosion(i32, i32);
	EXPORT void HangAndGetBeaten(void);
	EXPORT void PlaySounds(void);

	EXPORT virtual void Shouldnt_DoPhysics_Be_Virtual(void);
	EXPORT virtual i32 Hit(SHitInfo*);

	PADDING(0x32C-0x324);

	CVector field_32C;

	u8 field_338;

	PADDING(0x344-0x338-4);

	i32 field_344;
	i32* field_348;

	PADDING(0x360-0x348-4);

	void* field_360;
	i32 field_364;
	i32 field_368;

	i32 field_36C;
	i32 field_370;
	i32 field_374;

	PADDING(0x39C-0x374-4);

	i32 field_39C;

	PADDING(0x3B4-0x39C-4);

	void* field_3B4[4];

	PADDING(0x11-4);

	i32 field_3D4;
	i32 field_3D8;

	PADDING(0x3E0-0x3D8-4);

	i32 field_3E0;

	PADDING(0x3F4-0x3E0-4);

	void* field_3F4[4];
	void* field_404[4];
};


void validate_CSuperDocOck(void);
EXPORT void SuperDocOck_CreateSuperDocOck(const u32 *stack, u32 *result);
EXPORT void SuperDocOck_RelocatableModuleInit(reloc_mod *);
EXPORT void SuperDocOck_RelocatableModuleClear(void);
EXPORT void SuperDocOck_DisplayProgressBars(const u32*, u32*);
#endif
