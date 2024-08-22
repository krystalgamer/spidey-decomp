#pragma once

#ifndef DXSOUND_H
#define DXSOUND_H

#include "export.h"

#ifdef WIN32
#include <windows.h>
#else
typedef void* HWND;

//@FIXME
typedef i32 tWAVEFORMATEX;
#endif

//@FIXME
typedef void* IDirectInputA;
//@FIXME
typedef void* _DXPOLY;
//@FIXME
typedef void* _DDPIXELFORMAT;
//@FIXME
typedef void* IDirectDrawSurface7;
//@FIXME
typedef void* DIDEVICEINSTANCEA;

EXPORT void DXINPUT_GetControllerButtonState(u8);
EXPORT void DXINPUT_GetKeyState(u8);
EXPORT u8 DXINPUT_GetMouseButtonState(u8);
EXPORT i32 DXINPUT_GetNumControllerButtons(void);
EXPORT void DXINPUT_Initialize(IDirectInputA *,HWND);
EXPORT void DXINPUT_PollController(i32 *,i32 *,i32 *);
EXPORT void DXINPUT_PollKeyboard(void);
EXPORT void DXINPUT_PollMouse(i32 *,i32 *);
EXPORT void DXINPUT_Release(void);
EXPORT void DXINPUT_SetKeyState(u8,u8);
EXPORT void DXINPUT_SetMouseButtonState(u8,u8);
EXPORT void DXINPUT_SetupController(void);
EXPORT void DXINPUT_SetupForceFeedbackSineEffect(i32,float);
EXPORT void DXINPUT_SetupKeyboard(i32,i32);
EXPORT void DXINPUT_SetupMouse(i32);
EXPORT void DXINPUT_StartForceFeedbackEffect(void);
EXPORT void DXINPUT_StopForceFeedbackEffect(void);
EXPORT void DXPOLY_BeginScene(void);
EXPORT void DXPOLY_DrawPoly(_DXPOLY *,i32,i32,float);
EXPORT void DXPOLY_EnableTexAlpha(bool);
EXPORT void DXPOLY_EndScene(bool);
EXPORT void DXPOLY_Flip(void);
EXPORT void DXPOLY_Init(u32);
EXPORT void DXPOLY_SaveScreen(void);
EXPORT void DXPOLY_SaveSurfaceAsBMP(char *,void *,i32,i32,i32,_DDPIXELFORMAT *,bool);
EXPORT void DXPOLY_SetBackgroundColor(u32);
EXPORT void DXPOLY_SetBlendMode(u32);
EXPORT void DXPOLY_SetDepthCompare(u32);
EXPORT void DXPOLY_SetDepthWriting(bool);
EXPORT void DXPOLY_SetFilterMode(u32);
EXPORT void DXPOLY_SetHUDOffset(i32);
EXPORT void DXPOLY_SetOutlineColor(u32);
EXPORT void DXPOLY_SetTexture(IDirectDrawSurface7 *);
EXPORT void DXSOUND_Close(i32);
EXPORT void DXSOUND_CreateDSBuffer(char *,i32);
EXPORT void DXSOUND_Init(void);
EXPORT void DXSOUND_IsPlaying(i32);
EXPORT void DXSOUND_Load(char *);
EXPORT void DXSOUND_Open(i32,i32,i32);
EXPORT void DXSOUND_Play(i32,i32);
EXPORT void DXSOUND_SetPan(i32,i32);
EXPORT void DXSOUND_SetPitch(i32,i32);
EXPORT void DXSOUND_SetVolume(i32,i32);
EXPORT void DXSOUND_ShutDown(void);
EXPORT void DXSOUND_Stop(i32);
EXPORT void DXSOUND_Unload(char *,i32);
EXPORT void EnumControllersCallback(DIDEVICEINSTANCEA const *,void *);
EXPORT void ParseWavHeader(char *,tWAVEFORMATEX **,long *,u8 **);
EXPORT void initialSettings(void);
EXPORT void loadWAV(char *,tWAVEFORMATEX *,long *);
EXPORT void renderScene(void);
EXPORT void stateLog(char const *,...);

#endif
