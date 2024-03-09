#pragma once

#include "baddy.h"
#include "export.h"

class CTorch : public CBaddy {

public:


	int field_324;
	int field_328;	
	int field_32C;
	int field_330;
	int field_334;
	int field_338;

	CQuadBit *gTorchQuadBit;

	unsigned char field_340;
	int field_344;
	unsigned char field_348;

	int field_34C;
	int field_350;
};


void validate_CTorch(void);