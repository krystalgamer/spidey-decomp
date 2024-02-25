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
	unsigned char padding[0x24];
	void* mpTexture;
	unsigned int mCodeBGR;
	unsigned pad;
	unsigned int mTint;

	EXPORT void SetTint(unsigned char a2, unsigned char a3, unsigned char a4);

};


void validate_CQuadBit(void);
void validate_CBit(void);