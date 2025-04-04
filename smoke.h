#pragma once

#ifndef SMOKE_H
#define SMOKE_H

#include "export.h"
#include "weapons.h"

class CSmokeJet : public CTexturedRibbon
{
	public:
		PADDING(0x125-40);
};

void validate_CSmokeJet(void);

#endif
