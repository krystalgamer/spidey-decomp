#ifndef SUBMARIN_H
#define SUBMARIN_H

#pragma once

#include "baddy.h"
#include "export.h"

class CSubmariner : public CBaddy
{
	public:
		EXPORT CSubmariner(i16 *,i32);
		EXPORT ~CSubmariner(void);

		EXPORT void AI(void) OVERRIDE;
};

EXPORT void Submariner_CreateSubmariner(u32 *,u32 *);
EXPORT void Submariner_RelocatableModuleClear(void);

void validate_CSubmariner(void);

#endif
