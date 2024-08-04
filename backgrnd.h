#pragma once

#ifndef BACKGRND_H
#define BACKGRND_H

#include "ob.h"
#include "export.h"

EXPORT void Backgrnd_On(unsigned __int16);
EXPORT void Backgrnd_Off(unsigned __int16);

class CBackground : public CBody
{
	public:
		EXPORT CBackground(u32, CSVector*);
		EXPORT virtual ~CBackground(void);

		EXPORT void AI(void) OVERRIDE;

		u8 padBottom[8];

};

void validate_CBackground(void);
#endif
