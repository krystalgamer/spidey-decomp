#ifndef MJ_H
#define MJ_H
#pragma once

#include "export.h"
#include "baddy.h"

#include "reloc.h"


class CMJ : public CBaddy {

public:
	EXPORT void AI(void);
	EXPORT CMJ(int*, __int16);
	EXPORT ~CMJ(void) OVERRIDE;
};


void validate_CMJ(void);
EXPORT void MJ_CreateMJ(const unsigned int *, unsigned int *);
EXPORT void MJ_RelocatableModuleClear(void);
EXPORT void MJ_RelocatableModuleInit(reloc_mod*);
#endif
