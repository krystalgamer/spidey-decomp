#pragma once

#ifndef OB_H
#define  OB_H

#include "export.h"
#include "vector.h"
#include "bit.h"
#include "ps2funcs.h"
#include "mem.h"

EXPORT extern u8 gPsxItemsIndex;
EXPORT extern u32 SuspendedDistance;

EXPORT extern i32 gSuperItemRelated;
EXPORT extern f32 gFloatSuperRelated;

struct SHitInfo
{
	u8 field_0;
	u8 padAfter0[3];

	i32 field_4;
	i16 field_8;
	u8 padAfter8[2];

	CVector field_C;
	u8 bottomPad[4];
};

static unsigned char * const Regions = (unsigned char*)0x006B2449;
static int *** const CItemRelatedList = (int***)0x006B2454;


class CItem  
{
public: 
	
	unsigned short mFlags;
	u16 field_6;
	CVector mPos;
	CSVector mAngles;

	u16 mModel;

	unsigned char pad1[3];
	u8 mRegion;


	CItem *field_20;

	i32 field_24;
	__int16 field_28;
	i16 field_2A;
	__int16 field_2C;

	int field_30;

	CItem *field_34;
	unsigned __int16 field_38;
	unsigned char padAfter38[2];


	int field_3C;



	EXPORT void * operator new(size_t size);
	EXPORT void operator delete(void*);

	EXPORT CItem();
	EXPORT virtual ~CItem();

	EXPORT void InitItem(const char *);
};


class CBody : public CItem {

public:
	CBody **field_40;

	unsigned __int16 field_44;
	unsigned __int16 mCBodyFlags;

	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;

	CVector mAccellorVel;
	CVector gVec;

	CFriction field_78;

	int field_7C;

	// @FIXME is this really signed?
	int field_80;
	int field_84;

	CSVector csVector1;
	CSVector field_8E;

	unsigned char field_94;
	unsigned char field_95;
	unsigned char field_96;

	int field_98;
	int field_9C;
	int field_A0;
	int field_A4;
	CSVector field_A8;

	unsigned char padAfterAC[0xB8-0xAC-2];

	CVector bodyVector;
	__int16 field_C4;
	__int16 field_C6;
	__int16 field_C8;

	
	CQuadBit *bodyQuadBit;

	unsigned __int16 field_D0;
	unsigned __int16 field_D2;
	unsigned __int16 field_D4;

	int field_D8;

	u16 field_DC;

	unsigned __int16 field_DE;


	i16 field_E0;
	__int16 field_E2;

	u16 field_E4;

	CVector field_E8;


	EXPORT int IsDead(void) const;
	EXPORT virtual void Die(void);
	EXPORT virtual void AI(void);
	EXPORT virtual i32 Hit(SHitInfo*);
	EXPORT virtual void DeleteStuff(void);

	EXPORT void ShadowOn(void);
	EXPORT void KillShadow(void);
	EXPORT void EveryFrame(void);

	EXPORT void UpdateShadow(void);
	EXPORT void AttachTo(CBody**);

	EXPORT void InterleaveAI(void);

	// @FIXME
	// delete
	EXPORT i16* SquirtPos(i32*);

	EXPORT i16* SquirtPos(i16*);

	EXPORT i16* SquirtAngles(i16*);
	EXPORT void AttachXA(int, int);
	EXPORT void StopMyXA(void);
	EXPORT void UnSuspend(void);
	EXPORT void DeleteFrom(CBody**);
	EXPORT void Suspend(CBody**);
	EXPORT CBody* FindBodyByNode(i32, CBody*);

	EXPORT CBody();
	EXPORT ~CBody(void);
};

class CSuper : public CBody {
public:

	EXPORT CSuper();
	EXPORT ~CSuper(void);
	EXPORT void OutlineOff(void);
	EXPORT void OutlineOn(void);
	EXPORT void SetOutlineSemiTransparent(void);
	EXPORT void SetOutlineRGB(unsigned char a2, unsigned char a3, unsigned char a4);
	EXPORT void UpdateFrame(void);
	EXPORT void CycleAnim(int a2, char a3);
	EXPORT void ApplyPose(__int16 *a2);
	EXPORT void RunAnim(i32, i32, i32);


	int field_F4;

	unsigned __int16 field_F8;
	unsigned char padAfterF8[2];

	int field_FC;
	i32 field_100;
	SHandle field_104;

	SHandle field_10C;

	SHandle field_114;

	void* field_11C;
	int alsoOutlineRelated;
	unsigned char outlineR;
	unsigned char outlineG;
	unsigned char outlineB;


	__int16 field_128;
	unsigned __int16 field_12A;

	int outlineRelated;
	void* field_130;
	void* field_134;
	u8 padAfter134[0x6];

	unsigned char field_13E;
	unsigned char field_13F;

	unsigned char field_140;

	unsigned char field_141;
	unsigned char field_142;
	unsigned char field_143;


	__int16 field_144;
	__int16 field_146;
	__int16 gAnim;

	unsigned __int16 padAfte;

	int csuperend;


	__int16 field_150;
	__int16 field_152;
	__int16 field_154;


	unsigned char padVE[0x14-8];
	MATRIX mTransform;

	void *field_184;
	void* field_188;
	unsigned char padEE[0x4];
	__int16 *actualcsuperend;

	i32 field_194;
	i32 field_198;

	u8 padCsuperBottom[0x8];
};


void validate_CItem(void);
void validate_CBody(void);
void validate_CSuper(void);
void validate_SHitInfo(void);

static CSuper *globalSuper = (CSuper*)0x006A9038;
EXPORT extern CItem* EnviroList;
EXPORT extern CBody* EnvironmentalObjectList;
EXPORT extern CBody* SuspendedList;

EXPORT extern const char *gObjFile;

#endif
