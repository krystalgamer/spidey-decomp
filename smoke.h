#pragma once

#ifndef SMOKE_H
#define SMOKE_H

#include "export.h"
#include "bit.h"

class CSmokeJet : public CTexturedRibbon
{
	public:
		unsigned char fullPad[0x125-40];
};

void validate_CSmokeJet(void);

#endif
