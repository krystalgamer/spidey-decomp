#include "DXsound.h"

IDirectInputA* gDirectInputRelated;
EXPORT i32 gNumControllerButtons;

// @SMALLTODO
void DXINPUT_GetKeyName(u32, char*)
{
	printf("void DXINPUT_GetKeyName(u32, char*);");
}

// @SMALLTODO
u8 DXINPUT_GetControllerButtonState(u8)
{
    printf("DXINPUT_GetControllerButtonState(u8)");
	return (u8)0x24082024;
}

// @SMALLTODO
u8 DXINPUT_GetKeyState(u8)
{
    printf("DXINPUT_GetKeyState(u8)");
	return (u8)0x23082024;
}

// @SMALLTODO
u8 DXINPUT_GetMouseButtonState(u8)
{
	printf("u8 DXINPUT_GetMouseButtonState(u8)");
	return (u8)0x22082024;
}

// @Ok
// @Matching
i32 DXINPUT_GetNumControllerButtons(void)
{
	return gNumControllerButtons;
}

// @SMALLTODO
void DXINPUT_Initialize(IDirectInputA *,HWND)
{
    printf("DXINPUT_Initialize(IDirectInputA *,HWND)");
}

// @MEDIUMTODO
i32 DXINPUT_PollController(i32 *,i32 *,i32 *)
{
    printf("DXINPUT_PollController(i32 *,i32 *,i32 *)");
	return 0x24082024;
}

// @SMALLTODO
i32 DXINPUT_PollKeyboard(void)
{
    printf("DXINPUT_PollKeyboard(void)");
	return 0x23082024;
}

// @MEDIUMTODO
i32 DXINPUT_PollMouse(i32 *,i32 *)
{
    printf("DXINPUT_PollMouse(i32 *,i32 *)");
	return 0x23082024;
}

// @SMALLTODO
void DXINPUT_Release(void)
{
    printf("DXINPUT_Release(void)");
}

// @SMALLTODO
void DXINPUT_SetKeyState(u8,u8)
{
    printf("DXINPUT_SetKeyState(u8,u8)");
}

// @SMALLTODO
void DXINPUT_SetMouseButtonState(u8,u8)
{
    printf("DXINPUT_SetMouseButtonState(u8,u8)");
}

// @MEDIUMTODO
i32 DXINPUT_SetupController(void)
{
    printf("DXINPUT_SetupController(void)");
	return 0x23082024;
}

// @MEDIUMTODO
i32 DXINPUT_SetupForceFeedbackSineEffect(i32,float)
{
    printf("DXINPUT_SetupForceFeedbackSineEffect(i32,float)");
	return 0x24082024;
}

// @MEDIUMTODO
i32 DXINPUT_SetupKeyboard(i32,i32)
{
    printf("DXINPUT_SetupKeyboard(i32,i32)");
	return 0x23082024;
}

// @MEDIUMTODO
i32 DXINPUT_SetupMouse(i32)
{
    printf("DXINPUT_SetupMouse(i32)");
	return 0x23082024;
}

// @SMALLTODO
i32 DXINPUT_StartForceFeedbackEffect(void)
{
    printf("DXINPUT_StartForceFeedbackEffect(void)");
	return 0x23082024;
}

// @SMALLTODO
i32 DXINPUT_StopForceFeedbackEffect(void)
{
    printf("DXINPUT_StopForceFeedbackEffect(void)");
	return 0x23082024;
}

// @SMALLTODO
void DXPOLY_BeginScene(void)
{
    printf("DXPOLY_BeginScene(void)");
}

// @MEDIUMTODO
void DXPOLY_DrawPoly(_DXPOLY *,i32,i32,float)
{
    printf("DXPOLY_DrawPoly(_DXPOLY *,i32,i32,float)");
}

// @SMALLTODO
void DXPOLY_EnableTexAlpha(bool)
{
    printf("DXPOLY_EnableTexAlpha(bool)");
}

// @SMALLTODO
void DXPOLY_EndScene(bool)
{
    printf("DXPOLY_EndScene(bool)");
}

// @SMALLTODO
void DXPOLY_Flip(void)
{
    printf("DXPOLY_Flip(void)");
}

// @SMALLTODO
void DXPOLY_Init(u32)
{
    printf("DXPOLY_Init(u32)");
}

// @MEDIUMTODO
void DXPOLY_SaveScreen(void)
{
    printf("DXPOLY_SaveScreen(void)");
}

// @MEDIUMTODO
void DXPOLY_SaveSurfaceAsBMP(char *,void *,i32,i32,i32,_DDPIXELFORMAT *,bool)
{
    printf("DXPOLY_SaveSurfaceAsBMP(char *,void *,i32,i32,i32,_DDPIXELFORMAT *,bool)");
}

// @SMALLTODO
void DXPOLY_SetBackgroundColor(u32)
{
    printf("DXPOLY_SetBackgroundColor(u32)");
}

// @MEDIUMTODO
void DXPOLY_SetBlendMode(u32)
{
    printf("DXPOLY_SetBlendMode(u32)");
}

// @SMALLTODO
void DXPOLY_SetDepthCompare(u32)
{
    printf("DXPOLY_SetDepthCompare(u32)");
}

// @SMALLTODO
void DXPOLY_SetDepthWriting(bool)
{
    printf("DXPOLY_SetDepthWriting(bool)");
}

// @SMALLTODO
void DXPOLY_SetFilterMode(u32)
{
    printf("DXPOLY_SetFilterMode(u32)");
}

// @SMALLTODO
void DXPOLY_SetHUDOffset(i32)
{
    printf("DXPOLY_SetHUDOffset(i32)");
}

// @SMALLTODO
void DXPOLY_SetOutlineColor(u32)
{
    printf("DXPOLY_SetOutlineColor(u32)");
}

// @SMALLTODO
void DXPOLY_SetTexture(IDirectDrawSurface7 *)
{
    printf("DXPOLY_SetTexture(IDirectDrawSurface7 *)");
}

// @SMALLTODO
void DXSOUND_Close(i32)
{
    printf("DXSOUND_Close(i32)");
}

// @MEDIUMTODO
void DXSOUND_CreateDSBuffer(char *,i32)
{
    printf("DXSOUND_CreateDSBuffer(char *,i32)");
}

// @SMALLTODO
void DXSOUND_Init(void)
{
    printf("DXSOUND_Init(void)");
}

// @SMALLTODO
void DXSOUND_IsPlaying(i32)
{
    printf("DXSOUND_IsPlaying(i32)");
}

// @SMALLTODO
void DXSOUND_Load(char *)
{
    printf("DXSOUND_Load(char *)");
}

// @SMALLTODO
void DXSOUND_Open(i32,i32,i32)
{
    printf("DXSOUND_Open(i32,i32,i32)");
}

// @SMALLTODO
void DXSOUND_Play(i32,i32)
{
    printf("DXSOUND_Play(i32,i32)");
}

// @SMALLTODO
void DXSOUND_SetPan(i32,i32)
{
    printf("DXSOUND_SetPan(i32,i32)");
}

// @SMALLTODO
void DXSOUND_SetPitch(i32,i32)
{
    printf("DXSOUND_SetPitch(i32,i32)");
}

// @SMALLTODO
void DXSOUND_SetVolume(i32,i32)
{
    printf("DXSOUND_SetVolume(i32,i32)");
}

// @SMALLTODO
void DXSOUND_ShutDown(void)
{
    printf("DXSOUND_ShutDown(void)");
}

// @SMALLTODO
void DXSOUND_Stop(i32)
{
    printf("DXSOUND_Stop(i32)");
}

// @SMALLTODO
void DXSOUND_Unload(char *,i32)
{
    printf("DXSOUND_Unload(char *,i32)");
}

// @SMALLTODO
void EnumControllersCallback(DIDEVICEINSTANCEA const *,void *)
{
    printf("EnumControllersCallback(DIDEVICEINSTANCEA const *,void *)");
}

// @SMALLTODO
void ParseWavHeader(char *,tWAVEFORMATEX **,long *,u8 **)
{
    printf("ParseWavHeader(char *,tWAVEFORMATEX **,long *,u8 **)");
}

// @MEDIUMTODO
void initialSettings(void)
{
    printf("initialSettings(void)");
}

// @MEDIUMTODO
void loadWAV(char *,tWAVEFORMATEX *,long *)
{
    printf("loadWAV(char *,tWAVEFORMATEX *,long *)");
}

// @SMALLTODO
void renderScene(void)
{
    printf("renderScene(void)");
}

// @SMALLTODO
void stateLog(char const *,...)
{
    printf("stateLog(char const *,...)");
}
