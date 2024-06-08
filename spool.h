#pragma once

#ifndef SPOOL_H
#define SPOOL_H


#include "export.h"
#include "texture.h"

struct SPSXRegion {
	// offset: 0000 (9 bytes)
	char Filename[9];
	// offset: 0009
	u8 IsSuper;
	// offset: 000A
	u8 Usable;
	// offset: 000B
	u8 Protected;
	// offset: 000C
	u32 *pModelChecksums;
	// offset: 0010 (36 bytes)
	void **ppModels; // SMode

	// offset: 0014
	/*
	u32 *pPSX;
	*/
	u32 **field_14;

	// offset: 0018
	u32 *pAnimFile;
	// offset: 001C
	u16 *pHierarchy;
	// offset: 0020 (8 bytes)
	struct SHook *pHooks;
	// offset: 0024
	u32 *pColourTable;
	// offset: 0028
	u32 *pTexWibData;
	// offset: 002C
	u32 *pColourPulseData;
	// offset: 0030
	i16 *mpAnimTranslation;
	// offset: 0034
	u16 NumParts;
	// offset: 0036
	u8 Fastable;
	// offset: 0037
	u8 TexturesInRAM;
	// offset: 0038
	u8 KeepTexturesInRAM;
	// offset: 0039
	u8 WhichHeap;

	u8 Pad;

	u8 LowRes;
	// offset: 003C
	int Size;
	u32 padBottom;
};


EXPORT int Spool_FindRegion(const char *);
EXPORT unsigned int Spool_GetModel(unsigned int, int);
EXPORT unsigned int *Spool_SkipPackets(unsigned int *);
EXPORT Texture*  Spool_FindTextureEntry(unsigned int);
EXPORT void Spool_ClearAllPSXs(void);
EXPORT void ClearRegion(int, int);
EXPORT void Spool_RemoveUnusedTextures(void);
EXPORT void Spool_ClearPSX(const char*);

void validate_SPSXRegion(void);

#endif
