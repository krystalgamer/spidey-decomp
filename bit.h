#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "vector.h"

class CBit
{
	public:
		CBit* mPrevious;
		CBit* mNext;

		int unk;

		CVector mPos;
		CVector mVel;
		CVector mAcc;
		CFriction mFric;
		unsigned char mDead;
		unsigned char pad[2];
		unsigned char mProtected;

		EXPORT CBit();
		virtual ~CBit();
		EXPORT void* operator new(unsigned int size);
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

	EXPORT void SetTint(unsigned char a2, unsigned char a3, unsigned char a4);
	EXPORT void SetSemiTransparent();
	EXPORT void SetOpaque();
	EXPORT void SetSubtractiveTransparency();
	EXPORT void SetCorners(const CVector &a2, const CVector &a3, const CVector &a4, const CVector &a5);
	EXPORT void SetTransparency(unsigned char a2);

};

class CFT4Bit : public CBit {

public:
	EXPORT virtual ~CFT4Bit();
	EXPORT void SetAnimSpeed(short);
	EXPORT void SetScale(unsigned short);
	EXPORT void SetSemiTransparent();
	EXPORT void SetTransparency(unsigned char t);

	unsigned short mTransDecay;
	unsigned short mScaleDelay;
	unsigned int mCodeBGR;


	unsigned char pad[0x10];
	short mAnimSpeed;
	short mScale;
};

class CFlatBit : public CFT4Bit {

public:

	unsigned char pad[0x6];
	unsigned short mSemiTransparencyRate;
	unsigned int mPostScale;
	unsigned char pad1;
	unsigned char mAngFric;


};


void validate_CFlatBit(void);
void validate_CFT4Bit(void);
void validate_CQuadBit(void);
void validate_CBit(void);