#pragma once

#ifndef L5A5LSC_H
#define L5A5LSC_H

#include "export.h"

#include "reloc.h"

EXPORT extern u32 gL5A5Related;

EXPORT void L5A5LSC_DisplayProgressBar(u32 const *,u32 *);
EXPORT void L5A5LSC_RelocatableModuleInit(reloc_mod *);
EXPORT void L5A5LSC_RelocatableModuleClear(void);
EXPORT void L5A5LSC_WiggleSubwayCars(u32 const *,u32 *);

#endif
