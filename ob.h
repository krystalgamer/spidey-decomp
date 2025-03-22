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

struct SLight
{
	// offset: 0000 (18 bytes)
	i16 LightMatrix[3][3];
	// offset: 0012
	u16 Pad1;
	// offset: 0014 (18 bytes)
	i16 ColorMatrix[3][3];
	// offset: 0026
	u16 Pad2;
	// offset: 0028 (12 bytes)
	i32 BackColor[3];
};

struct SHitInfo
{
	u8 field_0;
	u8 field_1;
	u8 padAfter1[2];


	i32 field_4;
	u16 field_8;
	u8 padAfter8[2];

	CVector field_C;

	i16 field_18;
	u16 field_1A;
};

static unsigned char * const Regions = (unsigned char*)0x006B2449;
static int *** const CItemRelatedList = (int***)0x006B2454;


class CItem  
{
	public: 
		
		u16 mFlags;
		u16 mInquiry;
		CVector mPos;
		CSVector mAngles;

		u16 mModel;

		unsigned char pad1[3];
		u8 mRegion;


		CItem *mNextItem;

		u32 mRGB;
		CSVector mScale;

		i32 field_30;

		CItem *mPreviousItem;
		u16 mType;
		unsigned char padAfter38[2];


		SLight *mpLight;


		EXPORT void * operator new(size_t size);
		EXPORT void operator delete(void*);

		EXPORT CItem();
		EXPORT virtual ~CItem();

		EXPORT void InitItem(const char *);
};


class CBody : public CItem {

public:
	CBody **mppOriginalList;

	u16 mInputFlags;
	u16 mCBodyFlags;

	CVector field_48;

	CVector field_54;

	CVector mAccellorVel;
	CVector gVec;

	CFriction mFric;

	int field_7C;

	// @FIXME is this really signed?
	int field_80;
	int field_84;

	CSVector csVector1;
	CSVector field_8E;

	CFriction field_94;

	int field_98;
	int field_9C;
	int field_A0;
	int field_A4;
	CSVector field_A8;

	unsigned char padAfterAC[0xB8-0xAC-2];

	CVector bodyVector;
	CSVector field_C4;

	
	CQuadBit *mpShadow;

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

	EXPORT CBody(void);
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
void validate_SLight(void);

EXPORT extern CItem* EnviroList;
EXPORT extern CBody* EnvironmentalObjectList;
EXPORT extern CBody* SuspendedList;

EXPORT extern const char *gObjFile;
EXPORT extern u8 gWhatIf;

#endif
