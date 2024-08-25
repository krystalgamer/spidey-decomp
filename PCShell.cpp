#include "PCShell.h"
#include "dcshellutils.h"
#include "PCInput.h"
#include "SpideyDX.h"

EXPORT Sprite2* gCursorSprite;

EXPORT i32 gShellMouseX;
EXPORT i32 gShellMouseY;

EXPORT i32 gShellMouseOffsetX;
EXPORT i32 gShellMouseOffsetY;

const i32 MOUSE_TRIGGER_COUNT = 18;
EXPORT u8 gMouseTriggerRelated[MOUSE_TRIGGER_COUNT];

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

// @Ok
void PCSHELL_DrawMouseCursor(void)
{
	if (!(gRenderTest & 0x10) && gCursorSprite)
	{
		gCursorSprite->draw(gShellMouseX, gShellMouseY, 0, 0);
	}
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

// @Ok
// @Matching
void PCSHELL_Shutdown(void)
{
	if (gCursorSprite)
	{
		delete gCursorSprite;
		gCursorSprite = 0;
	}
}

// @Ok
u8 PCSHELL_UpdateMouse(void)
{
	for (i32 i = 0;
			i < MOUSE_TRIGGER_COUNT;
			i++)
	{
		gMouseTriggerRelated[i] = 0;
	}

	if (!(gRenderTest & 0x10))
	{
		if (PCINPUT_UpdateMouse())
		{
			i32 oldMouseX = gShellMouseX;
			i32 oldMouseY = gShellMouseY;

			PCINPUT_GetMousePosition(&gShellMouseX, &gShellMouseY);
			PCSHELL_CoordsPCtoDC(&gShellMouseX, &gShellMouseY);
			
			gShellMouseOffsetX = gShellMouseX - oldMouseX;
			gShellMouseOffsetY = gShellMouseY - oldMouseY;

			return 1;
		}
		else
		{
			gShellMouseOffsetX = 0;
			gShellMouseOffsetY = 0;
		}
	}
	
	return 0;
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
