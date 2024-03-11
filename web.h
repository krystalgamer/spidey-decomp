#pragma once
#include "bit.h"
#include "export.h"


class CImpactWeb : public CFlatBit{
public:
	unsigned char padFull[0x24];
};

void validate_CImpactWeb(void);