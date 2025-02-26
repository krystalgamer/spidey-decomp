#pragma once

#ifndef L6A2LSC_H
#define L6A2LSC_H

#include "export.h"
#include "reloc.h"

EXPORT void L6A2LSC_MonitorSpideyinWater(u32 const *,u32 *);
EXPORT void L6A2LSC_RelocatableModuleInit(reloc_mod *);
EXPORT void L6A2LSC_RelocatableModuleClear(void);

#endif
