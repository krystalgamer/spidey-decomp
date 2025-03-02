#pragma once

#ifndef BIT_H
#define BIT_H

#include "main.h"
#include "vector.h"
#include "texture.h"
#include "ps2funcs.h"

struct vector3d
{
};

struct SFringeQuad
{
	u32 Width;
	u32 CodeBGR;
};

struct SSection
{
	u32 Radius;
	u32 PadBGR;
};

struct SAnimFrame
{
	char OffX;
	char OffY;
	unsigned char Width;
	unsigned char Height;
	Texture *pTexture;
};


EXPORT extern u32 SparkSize;
EXPORT extern i32 gTimerRelated;

struct SRibbonPoint {
	// offset: 0000 (12 bytes)
	CVector Pos;
	// offset: 000C
	u8 r;
	// offset: 000D
	u8 g;
	// offset: 000E
	u8 b;
	// offset: 0010
	u16 Width;
	// offset: 0012
	u16 WidthB;
	// offset: 0014
	u8 rB;
	// offset: 0015
	u8 gB;
	// offset: 0016
	u8 bB;
	// offset: 0018
	i32 Last1Scr;
	// offset: 001C
	i32 Last2Scr;
	// offset: 0020
	i32 Last3Scr;
};

class CBit
{
	public:
		CBit* mPrevious;
		CBit* mNext;

		__int16 field_C;
		u16 field_E;

		CVector mPos;
		CVector mVel;
		CVector mAcc;
		CFriction mFric;
		unsigned char mDead;
		unsigned __int16 mFrigDeltaZ;
		unsigned char mProtected;
		u8 mType;

		EXPORT CBit();
		EXPORT virtual ~CBit();
		EXPORT virtual void Move(void);
		EXPORT void* operator new(size_t size);
		EXPORT void operator delete(void*);
		EXPORT void Die();
		EXPORT CBit* AttachTo(CBit** to);
		EXPORT void SetPos(const CVector &pos);
		EXPORT void DeleteFrom(CBit **lst);
};

class CQuadBit : public CBit {

public:
	CVector mPosB;
	CVector mPosC;
	CVector mPosD;
	Texture* mpTexture;
	u32 mCodeBGR;
	unsigned pad;
	u32 mTint;
	u8 padAfter6C[4];

	u32 field_74;
	u32 field_78;
	u32 field_7C;
	u32 field_80;

	EXPORT void SetTint(unsigned char a2, unsigned char a3, unsigned char a4);
	EXPORT void SetSemiTransparent();
	EXPORT void SetOpaque();
	EXPORT void SetSubtractiveTransparency();
	EXPORT void SetCorners(const CVector &a2, const CVector &a3, const CVector &a4, const CVector &a5);
	EXPORT void SetTransparency(unsigned char a2);
	EXPORT void OrientUsing(CVector *, SVECTOR *, i32, i32);
	EXPORT void OrientUsing(CVector *, SVECTOR *, i32, i32, i32);
	EXPORT void SetTexture(int, int);
	EXPORT void SetTexture(u32);
	EXPORT void SetTexture(Texture*);
};

struct SCFT4BitTexture
{
	unsigned char field_0;
	unsigned char field_1;
	unsigned char field_2;
	unsigned char field_3;
	Texture *field_4;
};

class CFT4Bit : public CBit
{
	public:
		EXPORT CFT4Bit(void);
		EXPORT virtual ~CFT4Bit();
		EXPORT void SetAnimSpeed(short);
		EXPORT void SetScale(unsigned short);
		EXPORT void SetSemiTransparent();
		EXPORT void SetTransparency(unsigned char t);
		EXPORT void SetAnim(int);
		EXPORT void IncFrameWithWrap(void);
		EXPORT void SetFrame(int);
		EXPORT void SetTint(unsigned char, unsigned char, unsigned char);
		EXPORT void SetTexture(Texture*);
		EXPORT void SetTexture(unsigned int);
		EXPORT int Fade(int);
		EXPORT void SetTransDecay(int);

		u16 mTransDecay;
		u16 field_3E;
		unsigned int mCodeBGR;

		unsigned char mDeleteAnimOnDestruction;
		unsigned char padAfterDeleteAnim[0x3];

		SCFT4BitTexture *mPSXAnim;
		SCFT4BitTexture *field_4C;
		unsigned char padAfteranimRelated5[0x1];

		unsigned char field_51;
		i8 field_52;
		unsigned char field_53;

		short mAnimSpeed;
		short mScale;
};

class CFlatBit : public CFT4Bit {

public:

	EXPORT CFlatBit(void);
	EXPORT ~CFlatBit(void);
	i16 field_58;
	i16 field_5A;
	unsigned char padAfter5A[0x2];
	unsigned short field_5E;
	unsigned int mPostScale;
	unsigned char pad1;
	unsigned char mAngFric;
};

class CNonRenderedBit : public CBit {
	public:
};

class CRibbon : public CNonRenderedBit
{
	public:
		EXPORT CRibbon(CVector*, i32, i32, i32, i32, i32, i32);
		EXPORT void SetScale(i32);
};

class CSmokeTrail : public CRibbon
{
	public:
		unsigned char pad[24];

		i32 field_54;

		EXPORT CSmokeTrail(CVector*, i32, i32, i32, i32);
};

class CSpecialDisplay : public CBit
{
	public:
		EXPORT CSpecialDisplay(void);
};

class CSimpleTexturedRibbon : public CSpecialDisplay
{
	public:
		EXPORT void SetRGB(unsigned char, unsigned char, unsigned char);

		u16 field_3C;
		u8 padAfter3C[0x48-0x3C-2];
		i32* field_48;
};

class CGlow : public CBit
{
	public:
		EXPORT CGlow(u32, u32);
		EXPORT CGlow(CVector*, i32, i32, u8, u8, u8, u8, u8, u8);

		EXPORT virtual ~CGlow(void);

		EXPORT void SetCentreRGB(u8, u8, u8);
		EXPORT void SetRadius(i32);
		EXPORT void SetRGB(u8, u8, u8);

		EXPORT void SetFringeWidth(u32, u32);
		EXPORT void SetFringeRGB(u32, u8, u8, u8);

		SSection* mpSections;
		SFringeQuad* mpFringes;

		u32 mNumSections;
		u32 mNumFringes;
		u32 mCentreCodeBGR;
		i16 mStepAngle;
		u8 mSkipTriangles;

		u16 mAngle;
		u32 mMask;
};

class CLinked2EndedBit : public CFT4Bit
{
	public:
		EXPORT CLinked2EndedBit(void);
		CVector field_58;
		CVector field_64;
};

class CRibbonBit : public CLinked2EndedBit
{
	public:
		EXPORT virtual void Move(void);
};

/*
class CTexturedRibbon : public CSpecialDisplay
{
	public:
		EXPORT void SetOuterRGBi(int, unsigned char, unsigned char, unsigned char);
		u8 topPad[0x60-0x3C];
		i32* field_60;
};
*/

class CSimpleAnim : public CFlatBit
{
	public:
		EXPORT CSimpleAnim(CVector*, i32, u16, i32, i32, i32);
};

class CMotionBlur : public CFlatBit
{
	public:
		EXPORT CMotionBlur(CVector*, CVector*, i32,i32,i32,i32);
		EXPORT virtual void Move(void);
};

class CCombatImpactRing : public CFlatBit
{
	public:
		EXPORT CCombatImpactRing(CVector*, u8, u8, u8, i32, i32, i32);
		EXPORT virtual ~CCombatImpactRing(void);

		u8 padBottom[0xC];
};

class CFrag : public CFlatBit
{
	public:
		EXPORT CFrag(CVector*, u8, u8, u8, i32, u16, i32, i32, i32, i32);
};

class CPixel : public CBit
{
	public:
		EXPORT CPixel(void);
		EXPORT virtual ~CPixel(void);
};

struct SBitServerEntry
{
	void** field_0;
	void (*field_4)(void**);
};

class CBitServer : public CClass
{
	public:
		EXPORT CBitServer(void);
		EXPORT virtual ~CBitServer(void);
		EXPORT u32 RegisterSlot(void**, void (*)(void**));
		EXPORT void DisplayRegisteredSlots(void);

		u32 mNumEntries;
		SBitServerEntry mEntry[0x20];
};

class CChunkBit : public CBit
{
	public:
		EXPORT CChunkBit(CSVector*, CSVector*, CSVector*);
		EXPORT virtual ~CChunkBit(void);
};

class CTextBox : public CBit
{
	public:
		EXPORT CTextBox(i32, i32, i32, i32, u32, CFriction*);
		EXPORT virtual ~CTextBox(void);

		i32 field_3C;
		u8 padBottom[4];
};

class CFireyExplosion : public CNonRenderedBit
{
	public:
		EXPORT CFireyExplosion(CVector*);
		EXPORT virtual ~CFireyExplosion(void);
};

class CGouraudRibbon : public CSpecialDisplay
{
	public:
		EXPORT CGouraudRibbon(i32, i32);
		EXPORT void Display(void);
		EXPORT void SetRGB(u8,u8,u8);
		EXPORT void SetWidth(u16);
		EXPORT ~CGouraudRibbon(void);

		i32 mTrail;
		i32 mNumPoints;
		SRibbonPoint* mpPoints;
};

class CWibbly : public CGouraudRibbon
{
	public:
		EXPORT CWibbly(u8,u8,u8,i32,i32,i32,i32,i32,i32,i32,i32,i32,i32);
		EXPORT void Move(void) OVERRIDE;
		EXPORT void SetCore(u8,u8,u8,i32);
		EXPORT void SetEndPoints(CVector *,CVector *);
		EXPORT virtual ~CWibbly(void);

		CGouraudRibbon* field_48;
		CVector field_4C;
		CVector field_58;
		CVector field_64;
		CVector field_70;
		i32 field_7C;
		u8 padAfter7C[0x88-0x7C-4];

		i32 field_88;
		u8 padBottom[0x98-0x88-4];


};

EXPORT extern CBit* GPolyLineList;
EXPORT extern CVector gGlobalNormal;

EXPORT int Bit_MakeSpriteRing(CVector*, int, int, int, int, int, int, int);
EXPORT void MoveList(CBit *);
EXPORT void Bit_SetSparkRGB(unsigned char, unsigned char, unsigned char);
EXPORT void Bit_SetSparkFadeRGB(unsigned char, unsigned char, unsigned char);
EXPORT void Bit_SetSparkTrajectory(const CSVector *);
EXPORT void Bit_SetSparkTrajectoryCone(const CSVector *);
EXPORT void Bit_ReduceRGB(unsigned int*, int);
EXPORT void Bit_SetSparkSize(u32);
EXPORT void Bit_Init(void);
EXPORT void Bit_DeleteAll(void);
EXPORT void Bit_UpdateQuickAnimLookups(void);

EXPORT extern CTextBox* TextBoxList;

EXPORT extern SAnimFrame* gAnimTable[0x1D];

void validate_CFlatBit(void);
void validate_CFT4Bit(void);
void validate_CQuadBit(void);
void validate_CBit(void);
void validate_CNonRenderedBit(void);
void validate_CSmokeTrail(void);
void validate_CGlow(void);
void validate_CLinked2EndedBit(void);
void validate_CRibbonBit(void);
//void validate_CTexturedRibbon(void);
void validate_CSimpleTexturedRibbon(void);
void validate_CSimpleAnim(void);
void validate_SCFT4BitTexture(void);
void validate_CMotionBlur(void);
void validate_CSpecialDisplay(void);
void validate_SFlatBitVelocity(void);
void validate_CRibbon(void);
void validate_CCombatImpactRing(void);
void validate_SRibbonPoint(void);
void validate_CFrag(void);
void validate_CPixel(void);
void validate_CBitServer(void);
void validate_CChunkBit(void);
void validate_CTextBox(void);
void validate_CFireyExplosion(void);
void validate_CWibbly(void);
void validate_SBitServerEntry(void);
void validate_SSection(void);
void validate_SFringeQuad(void);
void validate_vector3d(void);


#endif
