#pragma once

#ifndef CHAIN_H
#define CHAIN_H

#include "export.h"
#include "main.h"

// @Ok
class CChain : public CClass
{
	public:
		EXPORT void SetGroundY(int);

		unsigned char padTop[0x18-4];

		int field_18;
		int field_1C;

		unsigned char padBottom[0x28-0x1C-4];
};

void validate_CChain(void);
#endif
