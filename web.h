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
	unsigned char padFull[0xC];
};

class CDome : public CBody {
public:
	unsigned char padFull[0x25];
};

class CDomeRing : public CBody {
public:
	unsigned char padFull[0x25 - 0xC];
};


class CWeb : public CBody {
public:
	unsigned char padFull[0x45];
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