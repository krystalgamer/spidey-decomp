#pragma once

#ifndef POST_H
#define POST_H

#include "export.h"

EXPORT void Post_DoPauseDisplayListProcessing(void);
EXPORT void Post_DoPausePaletteProcessing(void);
EXPORT void Post_PostProcessEffects(void);
EXPORT void Post_SpideyLogo(void);
EXPORT void Post_UndoPausePaletteProcessing(void);
EXPORT void Post_WaterEffect(void);

#endif
