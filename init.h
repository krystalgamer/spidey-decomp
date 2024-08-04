#pragma once

#ifndef INIT_H
#define INIT_H

#include "ob.h"
#include "export.h"
EXPORT void DeleteList(CBody *);
EXPORT void Init_AtEnd(void);
EXPORT void Init_AtStart(i32);
EXPORT void Init_Cleanup(i32);
EXPORT void Init_KillAll(void);

#endif
