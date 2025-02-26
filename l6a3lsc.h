#pragma once

#ifndef L6A3LSC_H
#define L6A3LSC_H

#include "export.h"
#include "reloc.h"

EXPORT void L6A3LSC_MonitorSpideyinWater(const u32 *,u32 *);
EXPORT void L6A3LSC_RelocatableModuleInit(reloc_mod *);
EXPORT void L6A3LSC_RelocatableModuleClear(void);

#endif
