#ifndef SUBMARIN_H
#define SUBMARIN_H

#pragma once

#include "baddy.h"
#include "export.h"

class CSubmariner : public CBaddy {
	EXPORT CSubmariner(i16 *,i32);
	EXPORT ~CSubmariner(void);

	EXPORT virtual void AI(void);
};

EXPORT void Submariner_CreateSubmariner(u32 const *,u32 *);
EXPORT void Submariner_RelocatableModuleClear(void);

void validate_CSubmariner(void);

#endif
