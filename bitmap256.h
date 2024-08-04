#pragma once

#ifndef BITMAP256_H
#define BITMAP256_H

#include "export.h"

class Bitmap256
{
	public:
		EXPORT Bitmap256(char *,u16 *,i32,i32,i32);
		EXPORT ~Bitmap256(void);
};

void validate_Bitmap256(void);

#endif
