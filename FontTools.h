#pragma once

#ifndef FONTTOOLS_H
#define FONTTOOLS_H

#include "export.h"

class Font
{
	public:
		EXPORT int GetCharMap(void);
		EXPORT int isEscapeChar(char);

		unsigned char pad[0x58];
		int field_58;



};

void validate_Font(void);
#endif
