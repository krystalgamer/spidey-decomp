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

	unsigned char pad1[0x38];
	int field_80;
	unsigned char pad3[0x34];

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
	EXPORT void OutlineOff(void);
	EXPORT void OutlineOn(void);
	EXPORT void SetOutlineSemiTransparent(void);
	EXPORT void SetOutlineRGB(unsigned char a2, unsigned char a3, unsigned char a4);
	EXPORT void UpdateFrame(void);
	EXPORT void CycleAnim(int a2, char a3);
	EXPORT void ApplyPose(__int16 *a2);

	unsigned char padB[0x28];
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

	__int16 field_144;
	__int16 field_146;
	__int16 gAnim;


	int csuperend;

	unsigned char padVE[0x38];

	int field_188;
	unsigned char padEE[0x4];
	__int16 *actualcsuperend;
};


void validate_CItem(void);
void validate_CBody(void);
void validate_CSuper(void);