#pragma once


#ifndef EFFECTS_H
#define EFFECTS_H

#include "ob.h"
#include "export.h"

class CElectrify : public CSimpleTexturedRibbon
{
	public:
		unsigned char pad[37];

		EXPORT CElectrify(CSuper*, int);
};

void validate_CElectrify(void);
EXPORT void Effects_Electrify(CSuper*);
EXPORT void Effects_UnElectrify(CSuper*);

#endif
