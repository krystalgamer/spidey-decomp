#pragma once

#ifndef TWEAK_H
#define TWEAK_H

#include "export.h"

// @FIXME
// bro wtf is this shit
EXPORT extern i16 gGameState[30];

//#define G_GAMESTATE (gGameState)
#define G_GAMESTATE (reinterpret_cast<i16*>(0x006B4814))

EXPORT void Tweak_Init(void);

#endif
