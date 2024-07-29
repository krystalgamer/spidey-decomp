#pragma once

#ifndef WEAPONS_H
#define WEAPONS_H

#include "bit.h"
#include "export.h"

class CGouradRibbon : public CSpecialDisplay
{
	public:
		EXPORT CGouradRibbon(i32, i32);

		i32 mTrail;
		i32 NumPoints;
		SRibbonPoint* mpPoints;
};

void validate_CGouradRibbon(void);

#endif
