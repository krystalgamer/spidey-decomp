#pragma once

#ifndef FLASH_H
#define FLASH_H

#include "export.h"

EXPORT i32 Flash_FadeFinished(void);
EXPORT void Flash_Display(void);
EXPORT void Flash_Reset(void);
EXPORT void Flash_Screen(u8,u8,u8,i32,u8,i32);
EXPORT void Flash_Update(void);

#endif
