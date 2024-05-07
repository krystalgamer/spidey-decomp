#pragma once
#include "export.h"
#include "vector.h"
#include "bit.h"
#include "ps2funcs.h"

static unsigned char * const Regions = (unsigned char*)0x006B2449;
static int *** const CItemRelatedList = (int***)0x006B2454;

class CItem  
{
public: 
	
	unsigned short mFlags;
	CVector mPos;
	CSVector mAngles;

	unsigned short mModel;

	unsigned char pad1[3];
	unsigned char mRegion;


	CItem *field_20;
	unsigned char padAfterRegion[0x4];

	__int16 field_28;
	__int16 field_2A;
	__int16 field_2C;

	unsigned char padAfter2C[0x34-0x2C - 2];

	CItem *field_34;
	unsigned char padAfter34[4];


	int field_3C;



	EXPORT void * operator new(unsigned int size);

	EXPORT CItem();
	EXPORT virtual ~CItem();

	EXPORT void InitItem(const char *);
};


class CBody : public CItem {

public:
	CBody **field_40;

	unsigned __int16 field_44;
	unsigned __int16 mCBodyFlags;

	unsigned char pad1[0x38 - 0x20];
	CVector mAccellorVel;
	CVector gVec;

	unsigned char field_78;
	unsigned char field_79;
	unsigned char field_7A;


	int field_7C;
	int field_80;
	int field_84;

	CSVector csVector1;
	CSVector field_8E;
	unsigned char padAfter8E[0x98-0x8E-sizeof(CSVector)];

	int field_98;
	int field_9C;
	int field_A0;

	unsigned char padAfterA0[0xB8-0xA0-4];

	CVector bodyVector;

	unsigned char pad2[0x8];
	
	CQuadBit *bodyQuadBit;

	unsigned __int16 field_D0;
	unsigned __int16 field_D2;
	unsigned __int16 field_D4;

	unsigned char moreBottomPad[0x4+1];

	__int16 field_DC;

	unsigned char stopPPPad[0x4];

	__int16 field_E2;

	unsigned char padAfterE2[0xF8-0xE2-2-4];



	EXPORT int IsDead(void) const;
	EXPORT void Die(void);
	EXPORT void ShadowOn(void);
	EXPORT void KillShadow(void);
	EXPORT void EveryFrame(void);

	EXPORT void UpdateShadow(void);
	EXPORT void AttachTo(CBody**);

	EXPORT void InterleaveAI(void);
	EXPORT int* SquirtPos(int*);
	EXPORT __int16* SquirtAngles(__int16*);
	EXPORT void AttachXA(int, int);
	EXPORT void StopMyXA(void);
	EXPORT void UnSuspend(void);
	EXPORT void DeleteFrom(CBody**);
	EXPORT void Suspend(CBody**);
};

class CSuper : public CBody {
public:

	EXPORT CSuper();
	EXPORT void OutlineOff(void);
	EXPORT void OutlineOn(void);
	EXPORT void SetOutlineSemiTransparent(void);
	EXPORT void SetOutlineRGB(unsigned char a2, unsigned char a3, unsigned char a4);
	EXPORT void UpdateFrame(void);
	EXPORT void CycleAnim(int a2, char a3);
	EXPORT void ApplyPose(__int16 *a2);
	EXPORT void RunAnim(int, int, int);


	int padTopUnkn;

	int field_F8;
	int field_FC;
	int field_100;
	int field_104;
	int field_108;

	int field_10C;
	unsigned char padB[0x10-4];
	int SNbrFaces;
	int alsoOutlineRelated;
	unsigned char outlineR;
	unsigned char outlineG;
	unsigned char outlineB;


	__int16 field_128;
	unsigned __int16 field_12A;

	int outlineRelated;
	unsigned char padA[0xE];

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
	MATRIX field_164;
	unsigned char padAfter188[0x4];

	int field_188;
	unsigned char padEE[0x4];
	__int16 *actualcsuperend;
};


void validate_CItem(void);
void validate_CBody(void);
void validate_CSuper(void);

static CSuper *globalSuper = (CSuper*)0x006A9038;
