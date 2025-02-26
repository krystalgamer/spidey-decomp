#pragma once

#ifndef L5A7LSC_H
#define L5A7LSC_H

#include "export.h"
#include "reloc.h"

EXPORT void L5A7LSC_MonitorSpideyinWater(const u32 *,u32 *);
EXPORT void L5A7LSC_RelocatableModuleInit(reloc_mod *);
EXPORT void L5A7LSC_RelocatableModuleClear(void);


#endif
