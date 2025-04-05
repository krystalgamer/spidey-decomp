#pragma once

#ifndef DXSOUND_H
#define DXSOUND_H

#include "export.h"

#include "non_win32.h"
#include "my_dx.h"

#ifndef _WIN32
/*
//@FIXME
typedef void* _DDPIXELFORMAT;
//@FIXME
typedef void* IDirectDrawSurface7;
//@FIXME
typedef void* IDirectInputA;
//@FIXME
typedef void* DIDEVICEINSTANCEA;
*/
#endif

struct SDXPolyField
{
	f32 field_0;
	f32 field_4;
	f32 field_8;
	f32 field_C;
	u32 field_10;
	f32 field_14;
	f32 field_18;
};

struct DXPOLY
{
	DXPOLY* pNext;
	LPDIRECTDRAWSURFACE7 field_4;
	u16 mBlendMode;
	u16 field_A;
	DWORD field_C;
	SDXPolyField field_10[4];

	PADDING(0x6D);
};

struct SDDXSoundHolder
{
	LPDIRECTSOUNDBUFFER pDSB;

	u32 mFrequency;

	u8 field_8;
	u8 field_9;

	PADDING(2);
};


EXPORT u8 DXINPUT_GetControllerButtonState(u8);
EXPORT u8 DXINPUT_GetKeyState(u8);
EXPORT u8 DXINPUT_GetMouseButtonState(u8);
EXPORT i32 DXINPUT_GetNumControllerButtons(void);
EXPORT void DXINPUT_Initialize(LPDIRECTINPUT8,HWND);
EXPORT i32 DXINPUT_PollController(i32 *,i32 *,i32 *);
EXPORT i32 DXINPUT_PollKeyboard(void);
EXPORT i32 DXINPUT_PollMouse(i32 *,i32 *);
EXPORT void DXINPUT_Release(void);
EXPORT void DXINPUT_SetKeyState(u8,u8);
EXPORT void DXINPUT_SetMouseButtonState(u8,u8);
EXPORT i32 DXINPUT_SetupController(void);
EXPORT i32 DXINPUT_SetupForceFeedbackSineEffect(i32,f32);
EXPORT i32 DXINPUT_SetupKeyboard(i32,i32);
EXPORT i32 DXINPUT_SetupMouse(i32);
EXPORT i32 DXINPUT_StartForceFeedbackEffect(void);
EXPORT i32 DXINPUT_StopForceFeedbackEffect(void);
EXPORT void DXINPUT_GetKeyName(u8, char*);

EXPORT void DXPOLY_BeginScene(void);
EXPORT void DXPOLY_DrawPoly(DXPOLY*,i32,i32,f32);
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
EXPORT void DXPOLY_SetTexture(LPDIRECTDRAWSURFACE7);
EXPORT void DXSOUND_Close(i32);
EXPORT void DXSOUND_CreateDSBuffer(char *,i32);
EXPORT void DXSOUND_Init(void);
EXPORT i32 DXSOUND_IsPlaying(i32);
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
EXPORT void gsub_514ED0(void);
EXPORT void DXPOLY_SetAddressUAndV(DWORD, DWORD);

EXPORT extern LPDIRECTINPUT8 g_pDI;

void validate_DXsound(void);
void validate_DXPOLY(void);
void validate_SDXPolyField(void);
void validate_SDXSoundHolder(void);

#endif
