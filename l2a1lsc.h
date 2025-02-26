#pragma once

#ifndef L2A1LSC_H
#define L2A1LSC_H

#include "export.h"

#include "reloc.h"

EXPORT void L2A1LSC_DisplayProgressBar(u32 const *,u32 *);
EXPORT void L2A1LSC_MonitorTimer(u32 const *,u32 *);
EXPORT void L2A1LSC_RelocatableModuleInit(reloc_mod *);
EXPORT void L2A1LSC_RelocatableModuleClear(void);

#endif
