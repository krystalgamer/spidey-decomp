#pragma once

#ifndef BIT_H
#define BIT_H

#include "vector.h"
#include "texture.h"
#include "ps2funcs.h"

#define FLATBIT_VELOCITIES_SIZE (4096)
#define FLATBIT_VELOCITIES_MAX_INDEX (FLATBIT_VELOCITIES_SIZE-1)

struct SFlatBitVelocity
{
	i16 vxVel;
	i16 vzVel;
};

class CBit
{
	public:
		CBit* mPrevious;
		CBit* mNext;

		__int16 field_C;
		__int16 field_E;

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
	EXPORT void OrientUsing(CVector *a2, SVector *a3, int a4, int a5);
	EXPORT void OrientUsing(CVector *, SVECTOR *, i32, i32, i32);
	EXPORT void SetTexture(int, int);
	EXPORT void SetTexture(u32);
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
	unsigned char field_65;


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
		unsigned char pad[28];

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
		EXPORT void SetCentreRGB(u8, u8, u8);
		EXPORT void SetRadius(i32);
		EXPORT void SetRGB(u8, u8, u8);

		int* field_3C;
		unsigned char padAfter3C[0x44-0x3C-4];

		unsigned int field_44;
		unsigned char padAfter44[0x4C-0x44-4];

		int field_4C;
		unsigned char padAfter4C[0x54-0x4C-4];

		unsigned __int16 field_54;

		unsigned char padBottom[0x5C-0x54-2];
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

class CTexturedRibbon : public CSpecialDisplay
{
	public:
		EXPORT void SetOuterRGBi(int, unsigned char, unsigned char, unsigned char);
		u8 topPad[0x60-0x3C];
		i32* field_60;
};

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
};

EXPORT int Bit_MakeSpriteRing(CVector*, int, int, int, int, int, int, int);
EXPORT void MoveList(CBit *);
EXPORT void Bit_SetSparkRGB(unsigned char, unsigned char, unsigned char);
EXPORT void Bit_SetSparkFadeRGB(unsigned char, unsigned char, unsigned char);
EXPORT void Bit_SetSparkTrajectory(const CSVector *);
EXPORT void Bit_SetSparkTrajectoryCone(const CSVector *);
EXPORT void Bit_ReduceRGB(unsigned int*, int);

void validate_CFlatBit(void);
void validate_CFT4Bit(void);
void validate_CQuadBit(void);
void validate_CBit(void);
void validate_CNonRenderedBit(void);
void validate_CSmokeTrail(void);
void validate_CGlow(void);
void validate_CLinked2EndedBit(void);
void validate_CRibbonBit(void);
void validate_CTexturedRibbon(void);
void validate_CSimpleTexturedRibbon(void);
void validate_CSimpleAnim(void);
void validate_SCFT4BitTexture(void);
void validate_CMotionBlur(void);
void validate_CSpecialDisplay(void);
void validate_SFlatBitVelocity(void);
void validate_CRibbon(void);
void validate_CCombatImpactRing(void);

#endif
