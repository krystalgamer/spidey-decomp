#pragma once

#ifndef PCINPUT_H
#define PCINPUT_H

#include "export.h"

EXPORT int PCINPUT_GetMouseStatus(void);
EXPORT void PCINPUT_GetMousePosition(int*, int*);
EXPORT void PCINPUT_FreezeControllerAxes(void);

EXPORT void PCINPUT_ClearKeyState(u8);
EXPORT void PCINPUT_ClearMouseState(u8);
EXPORT void PCINPUT_GetControllerDirections(void);
EXPORT void PCINPUT_GetControllerMappingForAction(u32,u32 *);
EXPORT void PCINPUT_GetKeyboardMappingForAction(u32,u32 *);
EXPORT void PCINPUT_GetMappedStates(u32 *,u32 *);
EXPORT void PCINPUT_GetMouseHotspotPosition(i32 *,i32 *);
EXPORT void PCINPUT_GetNumControllerButtons(void);
EXPORT void PCINPUT_Initialize(void);
EXPORT void PCINPUT_IsControllerButtonPressed(u8,i32);
EXPORT void PCINPUT_IsKeyPressed(u8,i32);
EXPORT i32 PCINPUT_IsMouseButtonPressed(u8,i32);
EXPORT i32 PCINPUT_IsMouseButtonReleased(u8);
EXPORT i32 PCINPUT_IsMouseOver(i32,i32,i32,i32);
EXPORT void PCINPUT_PollController(void);
EXPORT void PCINPUT_PollKeyboard(void);
EXPORT void PCINPUT_RestoreDefaultControllerSettings(void);
EXPORT void PCINPUT_RestoreDefaultKeyboardSettings(void);
EXPORT void PCINPUT_SetControllerMappingForAction(u32,u32);
EXPORT void PCINPUT_SetKeyboardMappingForAction(u32,u32);
EXPORT void PCINPUT_SetMouseBounds(i32,i32,i32,i32);
EXPORT void PCINPUT_SetMouseHotspot(i32,i32);
EXPORT void PCINPUT_SetMousePosition(i32,i32);
EXPORT void PCINPUT_SetupForceFeedbackSineEffect(i32,float);
EXPORT void PCINPUT_Shutdown(void);
EXPORT void PCINPUT_StartForceFeedbackEffect(void);
EXPORT void PCINPUT_StopForceFeedbackEffect(void);
EXPORT void PCINPUT_UpdateMouse(void);
EXPORT void checkDebugKeypress(void);

#endif
