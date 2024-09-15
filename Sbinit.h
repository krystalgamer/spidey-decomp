#pragma once

#ifndef SBINIT_H
#define SBINIT_H

#include "export.h"

// @FIXME
typedef i32 KMDISPLAYMODE;

// @FIXME
typedef i32 KMBPPMODE;

EXPORT void sbExitSystem(void);
EXPORT void sbInitSystem(KMDISPLAYMODE,KMBPPMODE,i32);

#endif
