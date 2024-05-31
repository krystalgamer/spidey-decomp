#pragma once

#ifndef MANIPOB_H
#define MANIPOB_H

#include "export.h"
#include "ob.h"

class CManipOb : public CBody
{
	public:
		EXPORT void CalculateThrowPosition(CVector*, int);
		EXPORT void ThrowPos(CVector *, int);

		unsigned char padTop[0x10C-0xF4];
		int field_10C;
		unsigned char padBottom[0x128-0x10C-4];

};

void validate_CManipOb(void);

#endif
