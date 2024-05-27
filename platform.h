#pragma once

#include "export.h"
#include "baddy.h"

class CPlatform : public CBaddy {
public:
	EXPORT void Shouldnt_DoPhysics_Be_Virtual(void);
	EXPORT void DoPhysics(void);

	unsigned char platPat[0x38];
};

void validate_CPlatform(void);
