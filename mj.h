#pragma once

#include "export.h"
#include "baddy.h"


class CMJ : public CBaddy {

public:
	EXPORT void AI(void);
	EXPORT CMJ(int*, __int16);
};


void validate_CMJ(void);
