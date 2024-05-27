#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "vector.h"

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

		EXPORT CBit();
		EXPORT virtual ~CBit();
		EXPORT virtual void Move(void);
		EXPORT void* operator new(unsigned int size);
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
	void* mpTexture;
	unsigned int mCodeBGR;
	unsigned pad;
	unsigned int mTint;
	unsigned char quadPad[0x14];

	EXPORT void SetTint(unsigned char a2, unsigned char a3, unsigned char a4);
	EXPORT void SetSemiTransparent();
	EXPORT void SetOpaque();
	EXPORT void SetSubtractiveTransparency();
	EXPORT void SetCorners(const CVector &a2, const CVector &a3, const CVector &a4, const CVector &a5);
	EXPORT void SetTransparency(unsigned char a2);
	EXPORT void OrientUsing(CVector *a2, SVector *a3, int a4, int a5);
	EXPORT void SetTexture(int, int);

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

		unsigned short mTransDecay;
		unsigned short mScaleDelay;
		unsigned int mCodeBGR;

		unsigned char mDeleteAnimOnDestruction;
		unsigned char padAfterDeleteAnim[0x3];

		int animRelated1;
		int animRelated5;
		unsigned char padAfteranimRelated5[0x1];

		unsigned char animRelated3;
		unsigned char animRelated4;
		unsigned char animRelated2;

		short mAnimSpeed;
		short mScale;
};

class CFlatBit : public CFT4Bit {

public:

	__int16 field_58;
	__int16 field_5A;
	unsigned char padAfter5A[0x2];
	unsigned short mSemiTransparencyRate;
	unsigned int mPostScale;
	unsigned char pad1;
	unsigned char mAngFric;


};

class CNonRenderedBit : public CBit {
public:
};

class CSmokeTrail : public CNonRenderedBit
{
	public:
		unsigned char pad[28];

		EXPORT CSmokeTrail(CVector*, int, int, int ,int)
		{}
};

class CSpecialDisplay : public CBit
{
	public:
		EXPORT CSpecialDisplay(void);
};

class CSimpleTexturedRibbon : public CSpecialDisplay
{
	public:
};

class CGlow : public CBit
{
	public:
		EXPORT void SetCentreRGB(unsigned char, unsigned char, unsigned char);
		unsigned char padTop[0x10];

		int field_4C;
		unsigned char padBottom[0x5C-0x4C-4];
};

class CLinked2EndedBit : public CFT4Bit
{
	public:
		EXPORT CLinked2EndedBit(void);
		CVector field_58;
		CVector field_64;
};

EXPORT int Bit_MakeSpriteRing(CVector*, int, int, int, int, int, int, int);
EXPORT void MoveList(CBit *);
EXPORT void Bit_SetSparkRGB(unsigned char, unsigned char, unsigned char);
EXPORT void Bit_SetSparkFadeRGB(unsigned char, unsigned char, unsigned char);
EXPORT void Bit_SetSparkTrajectory(const CSVector *);
EXPORT void Bit_SetSparkTrajectoryCone(const CSVector *);

void validate_CFlatBit(void);
void validate_CFT4Bit(void);
void validate_CQuadBit(void);
void validate_CBit(void);
void validate_CNonRenderedBit(void);
void validate_CSmokeTrail(void);
void validate_CGlow(void);
void validate_CLinked2EndedBit(void);
