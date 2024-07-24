#pragma once

#ifndef WEAPONS_H
#define WEAPONS_H

#include "bit.h"
#include "export.h"

class CGouradRibbon : public CSpecialDisplay
{
	public:
		EXPORT CGouradRibbon(i32, i32);
};

void validate_CGouradRibbon(void);

#endif
