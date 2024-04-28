#pragma once
#include "bit.h"
#include "export.h"
#include "ob.h"


class CImpactWeb : public CFlatBit{
public:
	unsigned char padFull[0x24];
};


class CDomePiece : public CBody {
public:
	int padBeforeF8;
	int field_F8;
	int field_FC;
};

class CDome : public CBody {
public:
	unsigned char padFull[0x25];
};

class CDomeRing : public CBody {
public:

	int padCDomeRing;

	int field_F8;
	int field_FC;
	int field_100;
	int field_104;
	int field_108;

	unsigned char lastCDomeRing;
};


class CWeb : public CBody {
public:

	unsigned char padTop[0x108-0xF4];

	int field_108;
	int field_10C;
	int field_110;
	int field_114;
	int field_118;
	int field_11C;
	int field_120;
	int field_124;
	int field_128;


	unsigned char padBottom[0x13C-0x128-4];
};

class CSwinger : public CBody {
public:
	unsigned char padFull[0x99];
};

class CSplat : public CQuadBit {
public:
};



void validate_CImpactWeb(void);
void validate_CDomePiece(void);
void validate_CDome(void);
void validate_CDomeRing(void);
void validate_CWeb(void);
void validate_CSwinger(void);
void validate_CSplat(void);
