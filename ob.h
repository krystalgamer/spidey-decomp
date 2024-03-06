#pragma once
#include "export.h"
#include "vector.h"
#include "bit.h"


class CItem  
{
public: 
	
	unsigned short mFlags;
	CVector mPos;
	int mAngles;

	unsigned char pad[0x02];

	unsigned short mModel;

	unsigned char pad1[3];
	unsigned char mRegion;




	EXPORT void * operator new(unsigned int size);

	EXPORT CItem();
	EXPORT virtual ~CItem();

	EXPORT void InitItem(const char *);
};


class CBody : public CItem {

public:
	unsigned char pad[0x26];

	unsigned __int16 mCBodyFlags;

	unsigned char pad1[0x70];

	CVector bodyVector;

	unsigned char pad2[0x8];
	
	CQuadBit *bodyQuadBit;

	unsigned __int16 field_D0;
	unsigned __int16 field_D2;
	unsigned __int16 field_D4;

	unsigned char bottomPad[0x1C];


	EXPORT int IsDead(void) const;
	EXPORT void Die(void);
	EXPORT void ShadowOn(void);
	EXPORT void KillShadow(void);

	EXPORT void UpdateShadow(void);


};

class CSuper : public CBody {
public:

	EXPORT CSuper();

	unsigned char pad[0x4A];
	unsigned char field_13E;
	unsigned char field_13F;

	unsigned __int16 pad1;

	unsigned char field_142;

	int pad2;

	__int16 field_148;
	

};


void validate_CItem(void);
void validate_CBody(void);
void validate_CSuper(void);