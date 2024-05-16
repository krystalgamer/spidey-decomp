#pragma once

#include "export.h"
#include "baddy.h"

class CLizard : public CBaddy {
public:
	EXPORT CLizard(int*, __int16);
	EXPORT void AI(void);
};


void validate_CLizard(void);
