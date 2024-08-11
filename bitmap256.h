#pragma once

#ifndef BITMAP256_H
#define BITMAP256_H

#include "export.h"

class Bitmap256
{
	public:
		EXPORT Bitmap256(char *,u16 *,i32,i32,i32);
		EXPORT ~Bitmap256(void);

		void* field_0;
		u8 field_4[0x200];
		i32 field_204[6];

		i32 field_21C;
		i32 field_220;
};

void validate_Bitmap256(void);

#endif
