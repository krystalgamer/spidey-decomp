#pragma once

#ifndef TRAINING_H
#define TRAINING_H

#include "export.h"
#include "reloc.h"

EXPORT void Training_RelocatableModuleInit(reloc_mod *);
EXPORT void Training_RelocatableModuleClear(void);
#endif
