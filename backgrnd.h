#pragma once

#ifndef BACKGRND_H
#define BACKGRND_H

#include "ob.h"
#include "export.h"

EXPORT void Backgrnd_On(u16);
EXPORT void Backgrnd_Off(u16);

class CBackground : public CBody
{
	public:
		EXPORT CBackground(u32, CSVector*);
		EXPORT virtual ~CBackground(void);

		EXPORT void AI(void) OVERRIDE;

		PADDING(4);

		i16 field_F8;
		PADDING(2);
};

EXPORT extern CSuper* BackgroundList;
void validate_CBackground(void);
#endif
