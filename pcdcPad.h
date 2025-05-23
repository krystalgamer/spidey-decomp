#pragma once

#ifndef PCDCPAD_H
#define PCDCPAD_H

#include "export.h"

struct SPdPadBig
{
	i32 field_0;

	PADDING(0x78-4);
};


struct SPdPadSmall
{
	PADDING(0x30);

	SPdPadBig *pBig;
};

EXPORT void pdInitPeripheral(void);
EXPORT void pdExitPeripheral(void);
EXPORT i32 pdTmrAlarm(i32, u8*);
EXPORT SPdPadSmall* pdGetPeripheral(u32);
EXPORT i32 pdVibMxStart(i32, u8*);
EXPORT i32 pdVibMxStop(i32);
EXPORT i32 pdVibMxIsReady(i32);

void validate_SPdPadBig(void);
void validate_SPdPadSmall(void);
#endif
