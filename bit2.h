#pragma once

#ifndef BIT2_H
#define BIT2_H


#include "bit.h"

class CGPolyLine : public CBit {
public:

	unsigned char padTop[0x40-0x3B-4];

	int field_40;
	CVector field_44;
	
	unsigned char field_50;
	unsigned char field_51;
	unsigned char field_52;
	unsigned char field_53;

	unsigned char padAfter53[0x3];


	unsigned char field_57;
};

void validate_CGPolyLine(void);

#endif
