#pragma once

#include "export.h"
#include "baddy.h"

class CPlatform : public CBaddy {
public:
	EXPORT void Shouldnt_DoPhysics_Be_Virtual(void);
	EXPORT void DoPhysics(void);

	EXPORT unsigned __int16 GetVariable(unsigned __int16);

	unsigned char padTop[0x338-0x324];

	unsigned __int16 field_338;

	unsigned char padBottom[0x35C-0x338-2];
};

void validate_CPlatform(void);
