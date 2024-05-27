#pragma once

#ifndef SUPEROCK_H
#define SUPEROCK_H

#include "export.h"
#include "baddy.h"


class CSuperDocOck : public CBaddy {

public:
	EXPORT CSuperDocOck(int*, int);
	EXPORT void Shouldnt_DoPhysics_Be_Virtual(void);
	EXPORT void DoPhysics(void);
	unsigned char padTop[0x32C-0x324];

	int field_32C;
	int field_330;
	int field_334;
	unsigned char padAfter334[0x344-0x334-4];

	int field_344;
	unsigned char padAfter344[0x36C-0x344-4];

	int field_36C;
	int field_370;
	int field_374;
	unsigned char padAfter374[0x3D8-0x374-4];

	int field_3D8;

	unsigned char padBottom[0x414-0x3D8-4];
};


void validate_CSuperDocOck(void);
EXPORT void SuperDocOck_CreateSuperDocOck(const unsigned int *stack, unsigned int *result);
#endif
