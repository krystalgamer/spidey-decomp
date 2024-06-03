#pragma once

#ifndef RHINO_H
#define RHINO_H

#include "export.h"
#include "baddy.h"

class CRhino : public CBaddy {
public:
	EXPORT CRhino(int*, int);
	EXPORT CRhino(void);

	unsigned char padTop[0x344 - 0x324];
	int field_344;
	unsigned char padAfter344[0x424-0x344-4];
};

class CRhinoNasalSteam : public CFlatBit
{
	public:
		EXPORT CRhinoNasalSteam(CVector*, CVector*);
};

void validate_CRhino(void);
void validate_CRhinoNasalSteam(void);
EXPORT void Rhino_CreateRhino(const unsigned int *stack, unsigned int *result);


#endif
