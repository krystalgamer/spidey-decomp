#pragma once

#ifndef PSX_TYPES_H
#define PSX_TYPES_H

#include "my_types.h"

struct POLY_F3 
{
	// offset: 0000
	u32 tag;
	// offset: 0004
	u8 r0;
	// offset: 0005
	u8 g0;
	// offset: 0006
	u8 b0;
	// offset: 0007
	u8 code;
	// offset: 0008
	i16 x0;
	// offset: 000A
	i16 y0;
	// offset: 000C
	i16 x1;
	// offset: 000E
	i16 y1;
	// offset: 0010
	i16 x2;
	// offset: 0012
	i16 y2;
};

void validate_POLY_F3(void);

#endif
