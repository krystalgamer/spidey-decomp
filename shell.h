#pragma once

#ifndef SHELL_H
#define SHELL_H

#include "ob.h"
#include "export.h"


class CWobblyGlow : public CGlow
{
	public:
		EXPORT virtual void Move(void);

		int field_5C[1]; // @TODO
		unsigned char padAfter5C[0x9C-0x5C-4];

		int field_9C;
		int field_A0;
};

class CShellMysterioHeadGlow : public CWobblyGlow
{
	public:
		EXPORT virtual void Move(void);

		unsigned __int16 field_A4;

		unsigned char padBottom[0xA8-0xA4-2];
};

class CRudeWordHitterSpidey : public CSuper {
public:
	EXPORT CRudeWordHitterSpidey(void);
	EXPORT void AI(void);

	u32 field_194;
	
	u8 padAfter194[0x1A4-0x194-4];

	i32 field_1A4;
	i32 field_1A8;

};

class CDummy : public CSuper {
public:
	EXPORT void FadeBack(void);
	EXPORT void FadeAway(void);
	EXPORT void SelectNewTrack(int);
	EXPORT void SelectNewAnim(void);
	unsigned char padStart[0x1A4-0x194];

	u16* field_1A4;
	u16* field_1A8;
	u16* field_1AC;

	u8 padAfter1AC[0x1B8-0x1AC-4];

	u16* field_1B8;
	u16* field_1BC;
	i32 field_1C0;

	u8 padAfter1BC[0x1F8-0x1C0-4];


	i32 field_1F8;
	i32 field_1FC;
	unsigned char padAfter1FC[0x240-0x1FC-4];

	CItem field_240;
	unsigned char padAfter240[0x288 - 0x240 - sizeof(CItem)];
	CItem field_288;
	unsigned char padAfter288[0x2d4 - 0x288 - sizeof(CItem)];


	CVector field_2D4[4];
	CVector field_304[23];
	CVector field_418[128];
};

class Spidey_CIcon : public CSuper
{
	public:
		EXPORT void AI(void);

		unsigned char pad[0x10];
};

class CShellSymBurn : public CSuper
{
	public:
		EXPORT CShellSymBurn(CVector*);
		EXPORT void AI(void);

		u8 padTop[0x10];

		i32 field_1A4;
};

class CShellVenomElectrified : public CNonRenderedBit
{
	public:
		EXPORT CShellVenomElectrified(CSuper*);
		EXPORT virtual void Move(void);

		SHandle field_3C;
		i32 field_44;
};

class CShellCarnageElectrified : public CNonRenderedBit
{
	public:
		EXPORT CShellCarnageElectrified(CSuper*);
		EXPORT virtual void Move(void);

		SHandle field_3C;
		i32 field_44;
};

class CShellSuperDocOckElectrified : public CNonRenderedBit
{
	public:
		EXPORT CShellSuperDocOckElectrified(CSuper*);
		EXPORT virtual void Move(void);

		SHandle field_3C;
		i32 field_44;
};

static const i32 INPUT_MAX_SIZE = 9;

EXPORT i32 Shell_DeRudify(char[INPUT_MAX_SIZE]);
EXPORT i32 Shell_ContainsSubString(const char*, const char*);

void validate_CRudeWordHitterSpidey(void);
void validate_CDummy(void);
void validate_CWobblyGlow(void);
void validate_CShellMysterioHeadGlow(void);
void validate_Spidey_CIcon(void);
void validate_CShellSymBurn(void);
void validate_CShellVenomElectrified(void);
void validate_CShellCarnageElectrified(void);
void validate_CShellSuperDocOckElectrified(void);

#endif
