#include "PCShell.h"
#include "dcshellutils.h"
#include "PCInput.h"
#include "SpideyDX.h"

EXPORT Sprite2* gCursorSprite;

EXPORT i32 gShellMouseX;
EXPORT i32 gShellMouseY;

// @MEDIUMTODO
void PCSHELL_CheckTriggers(u32,i32,i32)
{
    printf("PCSHELL_CheckTriggers(uint,i32,i32)");
}

// @SMALLTODO
void PCSHELL_CoordsDCtoPC(i32 *,i32 *)
{
    printf("PCSHELL_CoordsDCtoPC(i32 *,i32 *)");
}

// @SMALLTODO
void PCSHELL_CoordsPCtoDC(i32 *,i32 *)
{
    printf("PCSHELL_CoordsPCtoDC(i32 *,i32 *)");
}

// @SMALLTODO
void PCSHELL_DoControllerConfig(bool)
{
    printf("PCSHELL_DoControllerConfig(bool)");
}

// @MEDIUMTODO
void PCSHELL_DoDisplayOptions(void)
{
    printf("PCSHELL_DoDisplayOptions(void)");
}

// @SMALLTODO
void PCSHELL_DrawMouseCursor(void)
{
    printf("PCSHELL_DrawMouseCursor(void)");
}

// @Ok
void PCSHELL_Initialize(void)
{
	if (!gCursorSprite)
	{
		gCursorSprite = new Sprite2("lti\\cursor.bmp", 0, 0, 0, 33);

		PCINPUT_SetMouseHotspot(15, 15);
		PCINPUT_SetMouseBounds(0, 0, gDxResolutionX - 32, gDxResolutionY - 32);
		PCINPUT_SetMousePosition((gDxResolutionX - 32) >> 1, (gDxResolutionY - 32) >> 1);
	}

	PCINPUT_GetMousePosition(&gShellMouseX, &gShellMouseY);
	PCSHELL_CoordsPCtoDC(&gShellMouseX, &gShellMouseY);
}

// @SMALLTODO
void PCSHELL_IsMouseOver(i32,i32,i32,i32)
{
    printf("PCSHELL_IsMouseOver(i32,i32,i32,i32)");
}

// @SMALLTODO
void PCSHELL_IsMouseOverText(char const *,i32,i32,i32)
{
    printf("PCSHELL_IsMouseOverText(char const *,i32,i32,i32)");
}

// @SMALLTODO
void PCSHELL_MouseMoved(void)
{
    printf("PCSHELL_MouseMoved(void)");
}

// @SMALLTODO
void PCSHELL_Relax(void)
{
    printf("PCSHELL_Relax(void)");
}

// @SMALLTODO
void PCSHELL_Shutdown(void)
{
    printf("PCSHELL_Shutdown(void)");
}

// @SMALLTODO
void PCSHELL_UpdateMouse(void)
{
    printf("PCSHELL_UpdateMouse(void)");
}

// @SMALLTODO
void displayControllerScreen(void)
{
    printf("displayControllerScreen(void)");
}

// @SMALLTODO
void initActionMaps(void)
{
    printf("initActionMaps(void)");
}

// @MEDIUMTODO
void processControllerScreen(void)
{
    printf("processControllerScreen(void)");
}

// @SMALLTODO
void resetActionMaps(bool)
{
    printf("resetActionMaps(bool)");
}
