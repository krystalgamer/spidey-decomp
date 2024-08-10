#pragma once

#ifndef SPOOL_H
#define SPOOL_H


#include "export.h"
#include "texture.h"
#include "ob.h"

struct SAnimFrame;

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

	u32 padAfterChecksum;

	// offset: 0010 (36 bytes)
	void **ppModels; // SMode

	// offset: 0014
	/*
	u32 *pPSX;
	*/
	u32 *pPSX;

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
	/*
	// offset: 0036
	u8 Fastable;
	// offset: 0037
	u8 TexturesInRAM;
	// offset: 0038
	u8 KeepTexturesInRAM;
	// offset: 0039
	u8 WhichHeap;
	*/

	u8 Pad;

	u8 LowRes;

	// offset: 003C
	int Size;
	u32 padBottom;
};


EXPORT int Spool_FindRegion(const char *);
EXPORT unsigned int Spool_GetModel(unsigned int, int);
EXPORT unsigned int *Spool_SkipPackets(unsigned int *);
EXPORT void Spool_ClearAllPSXs(void);
EXPORT void ClearRegion(int, int);
EXPORT void Spool_RemoveUnusedTextures(void);
EXPORT void Spool_ClearPSX(const char*);
EXPORT CItem* Spool_FindEnviroItem(u32);
EXPORT Texture* Spool_FindTextureEntry(u32);
EXPORT Texture* Spool_FindTextureEntry(char *);
EXPORT u32 Spool_FindTextureChecksum(char *);
EXPORT u32 Spool_GetModelChecksum(CItem *);

EXPORT void DecrementTextureUsage(i32);
EXPORT char* GetNextLine(char *);
EXPORT void GotoStartOfTextureList(void);
EXPORT void NewTextureEntry(u32);
EXPORT Texture* NextTexture(void);
EXPORT void PreProcessAnimPacket(u32 *,u32 *);
EXPORT void ProcessNewPSX(i32);
EXPORT void RemoveAnimPacket(u32 *);
EXPORT void RemoveTextureEntry(Texture *);
EXPORT void Spool_AddEnvModelsToHashTable(void);
EXPORT void Spool_AnimAccess(char *,SAnimFrame **);
EXPORT void Spool_ClearEnvironmentRegions(void);
EXPORT void Spool_FindAnim(char *,i32);
EXPORT void Spool_GetEnvIndex(i32);
EXPORT void Spool_GetPalette(u32,i32);
EXPORT void Spool_Init(void);
EXPORT void Spool_InitialiseEnvModelHashTable(void);
EXPORT void Spool_MaskFaceFlags(i32,u32,u32);
EXPORT void Spool_ReloadAll(void);
EXPORT void Spool_RemoveAccess(void **,i32);
EXPORT void Spool_Sync(void);
EXPORT void Spool_TextureAccess(u32,Texture **);
EXPORT void SwapPSXFile(u32 *);
EXPORT void SwapPSXPacketData(u32 *);
EXPORT void SwapPSXTextureData(u32 *,Texture **,u32 *);
EXPORT void accessLog(char *,...);
EXPORT void addAccess(void **,u32,u32,i32);
EXPORT void restoreRegionAccess(i32);
EXPORT void texClearChecksums(char *);
EXPORT void texLoadChecksums(char *);

void validate_SPSXRegion(void);
void validate_TextureEntry(void);

#endif
