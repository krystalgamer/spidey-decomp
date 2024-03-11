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


void validate_CImpactWeb(void);
void validate_CDomePiece(void);