#pragma once

#ifndef RELOC_H
#define RELOC_H

#include "export.h"

EXPORT void Reloc_Unload(char*);
EXPORT void Reloc_Unload(unsigned int);
EXPORT void Reloc_CallUserFunction(const char*, u32, const u32*, u32*);

#endif
