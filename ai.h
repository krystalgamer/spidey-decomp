#pragma once

#ifndef AI_H
#define AI_H

#include "export.h"
#include "main.h"

class CAIProc : public CClass
{
	public:
		EXPORT int Wait(void);

		unsigned char topPad[0x8];
		int field_C;
		int field_10;
};

class CAIProc_LookAt : public CAIProc
{
	public:
};


void validate_CAIProc(void);
void validate_CAIProc_LookAt(void);

#endif
