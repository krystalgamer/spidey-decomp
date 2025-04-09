#pragma once

#ifndef BIT_H
#define BIT_H

#include "main.h"
#include "vector.h"
#include "texture.h"
#include "ps2funcs.h"

// @Note: guessed name
struct SRibbonTexture
{
	u16 field_0;
	u16 field_2;

	u8 field_4;
	u8 field_5;
	u8 field_6;
	u8 field_7;
	u8 field_8;
	u8 field_9;
	u8 field_A;
	u8 field_B;

	u16 field_C;
	u16 field_E;

	u8 u0;
	u8 v0;

	u16 mClut;

	u8 u1;
	u8 v1;

	u16 mPage;

	u8 u2;
	u8 v2;

	u8 u3;
	u8 v3;

	u32 mTexWin;
};

class vector3d
{
	public:
		f32 field_0[3];

		EXPORT vector3d(f32, f32, f32);
};

class vector4d
{
	public:
		f32 field_0[4];

		// @Ok
		EXPORT vector4d(void)
		{
		}

		EXPORT vector4d(const vector3d&, f32);
		EXPORT vector4d& operator=(const vector4d&);
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
	u8 Width;
	u8 Height;
	Texture *pTexture;
};


EXPORT extern u32 SparkSize;
// @FIXME - is it really volatile?
EXPORT extern volatile i32 gTimerRelated;

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

		i16 mAge;
		u16 mLifetime;

		CVector mPos;
		CVector mVel;
		CVector mAcc;
		CFriction mFric;
		u8 mDead;

		u16 mFrigDeltaZ;
		u8 mProtected;
		u8 mType;

		EXPORT CBit();
		EXPORT virtual ~CBit();
		EXPORT virtual void Move(void);
		EXPORT void* operator new(size_t size);
		EXPORT void operator delete(void*);
		EXPORT void Die();
		EXPORT void AttachTo(void*);
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

	u32 field_68;

	u32 mTint;

	u32 field_70;

	u32 field_74;
	u32 field_78;
	u32 field_7C;
	u32 field_80;

	EXPORT CQuadBit(void);

	EXPORT void SetTint(u8 a2, u8 a3, u8 a4);
	EXPORT void SetSemiTransparent();
	EXPORT void SetOpaque();
	EXPORT void SetSubtractiveTransparency();
	EXPORT void SetCorners(const CVector &a2, const CVector &a3, const CVector &a4, const CVector &a5);
	EXPORT void SetTransparency(u8 a2);
	EXPORT void OrientUsing(CVector *, SVECTOR *, i32, i32);
	EXPORT void OrientUsing(CVector *, SVECTOR *, i32, i32, i32);
	EXPORT void SetTexture(i32, i32);
	EXPORT void SetTexture(u32);
	EXPORT void SetTexture(Texture*);
};

class CFT4Bit : public CBit
{
	public:
		EXPORT CFT4Bit(void);
		EXPORT virtual ~CFT4Bit();
		EXPORT void SetAnimSpeed(short);
		EXPORT void SetScale(u16);
		EXPORT void SetSemiTransparent();
		EXPORT void SetTransparency(u8 t);
		EXPORT void SetAnim(i32);
		EXPORT void IncFrameWithWrap(void);
		EXPORT void SetFrame(i32);
		EXPORT void SetTint(u8, u8, u8);
		EXPORT void SetTexture(Texture*);
		EXPORT void SetTexture(u32);
		EXPORT int Fade(i32);
		EXPORT void SetTransDecay(i32);
		EXPORT void IncFrame(void);

		u16 mTransDecay;
		u16 field_3E;
		u32 mCodeBGR;

		u8 mDeleteAnimOnDestruction;
		PADDING(0x3);

		SAnimFrame *mpPSXAnim;
		SAnimFrame *mpPSXFrame;
		u8 mBitFlags;

		u8 mNumFrames;
		i8 mFrame;
		u8 mFrameFrac;

		i16 mAnimSpeed;
		i16 mScale;
};

class CFlatBit : public CFT4Bit {

public:

	EXPORT CFlatBit(void);
	EXPORT virtual ~CFlatBit(void) OVERRIDE;
	i16 mAngle;
	i16 field_5A;

	PADDING(0x2);

	u16 mAngFric;
	u32 mPostScale;

	PADDING(1);
	u8 mSemiTransparencyRate;
};

class CNonRenderedBit : public CBit {
	public:
		EXPORT CNonRenderedBit(void);
		EXPORT virtual ~CNonRenderedBit(void) OVERRIDE;
};

class CSpecialDisplay : public CBit
{
	public:
		EXPORT CSpecialDisplay(void);
		EXPORT ~CSpecialDisplay(void) OVERRIDE;
};

class CSimpleTexturedRibbon : public CSpecialDisplay
{
	public:
		EXPORT void SetRGB(u8, u8, u8);
		EXPORT void SetSemiTransparent(void);

		EXPORT CSimpleTexturedRibbon(void);
		EXPORT CSimpleTexturedRibbon(i32);
		EXPORT void Display(void);
		EXPORT void SetNumFaces(i32);
		EXPORT void SetOpaque(void);
		EXPORT void SetTexture(Texture *);
		EXPORT void SetTexture(u32);
		EXPORT void SetTexturei(i32,Texture *);
		EXPORT void SetTexturei(i32,u32);
		EXPORT void SetWidth(u16);
		EXPORT void SetWidthi(i32,u16);
		EXPORT virtual ~CSimpleTexturedRibbon(void) OVERRIDE;

		u16 field_3C;

		u16 field_3E;

		SRibbonTexture *pTextures;

		void *field_44;

		u32 *field_48;
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

class CRibbon : public CNonRenderedBit
{
	public:
		EXPORT CRibbon(CVector*, i32, i32, i32, i32, i32, i32);
		EXPORT virtual ~CRibbon(void) OVERRIDE;
		EXPORT void SetScale(i32);

		i32 mNumBits;
		i32 mPointsPerBit;
		i32 mNumPoints;

		PADDING(4);

		CVector *mPoints;
		CRibbonBit **mBits;
};

class CSmokeTrail : public CRibbon
{
	public:

		EXPORT CSmokeTrail(CVector*, i32, i32, i32, i32);
		EXPORT virtual void Move(void) OVERRIDE;
		EXPORT virtual ~CSmokeTrail(void) OVERRIDE;

		i32 mFadeAway;
};


/*
class CTexturedRibbon : public CSpecialDisplay
{
	public:
		EXPORT void SetOuterRGBi(int, u8, u8, u8);
		u8 topPad[0x60-0x3C];
		i32* field_60;
};
*/

class CSimpleAnim : public CFlatBit
{
	public:
		EXPORT CSimpleAnim(CVector*, i32, u16, i32, i32, i32);
		EXPORT virtual ~CSimpleAnim(void) OVERRIDE;
		EXPORT virtual void Move(void) OVERRIDE;

		i32 mDie;
		i32 mDieFrame;
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
		EXPORT virtual ~CCombatImpactRing(void) OVERRIDE;
		EXPORT virtual void Move(void) OVERRIDE;

		i32 field_68;
		i32 field_6C;
		i32 field_70;
};

class CFrag : public CFlatBit
{
	public:
		EXPORT CFrag(CVector*, u8, u8, u8, i32, u16, i32, i32, i32, i32);
		EXPORT virtual ~CFrag(void) OVERRIDE;
		EXPORT virtual void Move(void) OVERRIDE;
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

		SVECTOR mPosA;
		SVECTOR mPosB;
		SVECTOR mPosC;
		SVECTOR mPosD;

		CVector mWorldPosA;
		CVector mWorldPosB;
		CVector mWorldPosC;
		CVector mWorldPosD;

		CSVector mAngles;
};

class CTextBox : public CBit
{
	public:
		EXPORT CTextBox(i32, i32, i32, i32, u32, CFriction*);
		EXPORT virtual ~CTextBox(void);

		i32 field_3C;
		PADDING(4);
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

		PADDING(0x88-0x7C-4);

		i32 field_88;

		PADDING(0x98-0x88-4);

};

class CGlassBit : public CBit
{
	public:
		EXPORT CGlassBit(CVector const *,CVector const *,i32,u8,u8,u8,i32,i32,i32);
		EXPORT virtual void Move(void) OVERRIDE;
		EXPORT virtual ~CGlassBit(void) OVERRIDE;

		CVector mPosA;
		CVector mPosB;
		CVector mPosC;

		i32 mGroundY;

		u8 mDefaultR;
		u8 mDefaultG;
		u8 mDefaultB;

		u8 mR;
		u8 mG;
		u8 mB;

		u8 mFadeRate;

		PADDING(1);
};

EXPORT extern CBit* GPolyLineList;

EXPORT i32 Bit_MakeSpriteRing(CVector*, i32, i32, i32, i32, i32, i32, i32);
EXPORT void MoveList(CBit *);
EXPORT void Bit_SetSparkRGB(u8, u8, u8);
EXPORT void Bit_SetSparkFadeRGB(u8, u8, u8);
EXPORT void Bit_SetSparkTrajectory(const CSVector *);
EXPORT void Bit_SetSparkTrajectoryCone(const CSVector *);
EXPORT void Bit_ReduceRGB(u32*, i32);
EXPORT void Bit_SetSparkSize(u32);
EXPORT void Bit_Init(void);
EXPORT void Bit_DeleteAll(void);
EXPORT void Bit_UpdateQuickAnimLookups(void);
EXPORT void RemoveDeadBits(CBit *);
EXPORT void Bit_RemoveDeadBits(void);

EXPORT void DeleteBitList(CBit*);

EXPORT extern CTextBox* TextBoxList;

#define NUM_ANIM_ENTRIES 0x1D
EXPORT extern SAnimFrame* gAnimTable[NUM_ANIM_ENTRIES];

EXPORT extern i32 TotalBitUsage;

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
void validate_vector4d(void);
void validate_CGlassBit(void);
void validate_SRibbonTexture(void);


EXPORT extern CBit* GLineList;
EXPORT extern CBit* PolyLineList;

#endif
