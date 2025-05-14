#include "PCShell.h"
#include "dcshellutils.h"
#include "PCInput.h"
#include "SpideyDX.h"
#include "front.h"
#include "DXsound.h"
#include "pshell.h"
#include "PCGfx.h"
#include "shell.h"

#include <cstring>

#include "validate.h"

EXPORT Sprite2* gCursorSprite;

EXPORT i32 gShellMouseX;
EXPORT i32 gShellMouseY;

EXPORT i32 gShellMouseOffsetX;
EXPORT i32 gShellMouseOffsetY;

const i32 MOUSE_TRIGGER_COUNT = 18;
EXPORT u8 gMouseTriggerRelated[MOUSE_TRIGGER_COUNT];

const i32 ACTION_MAP_COUNT = 11;
EXPORT SActionMap gActionMaps[ACTION_MAP_COUNT];
EXPORT char gKeyNames[ACTION_MAP_COUNT][32];

EXPORT CMenu* gControllerMenu;
EXPORT CMenu* gControllerMenuTwo;

EXPORT i32 gActionMapRelated;

char* STR_KB_CONFIG = "keyboard configuration";
char* STR_JOY_CONFIG = "joystick configuration";

EXPORT i32 gShellTitleBarRelated;

// @MEDIUMTODO
u8 PCSHELL_CheckTriggers(u32,i32,i32)
{
    printf("PCSHELL_CheckTriggers(uint,i32,i32)");
	return (u8)0x28022025;
}

// @Ok
INLINE void PCSHELL_CoordsDCtoPC(i32* pX, i32* pY)
{
	*pX = (f64)*pX / 512.0 * (f64)gDxResolutionX;
	*pY = (f64)*pY / 240.0 * (f64)gDxResolutionY;
}

// @Ok
// @Matching
INLINE void PCSHELL_CoordsPCtoDC(i32* pX, i32* pY)
{
	*pX = (f32)(*pX * 512) / (f32)gDxResolutionX;
	*pY = (f32)(*pY * 240) / (f32)gDxResolutionY;
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

// @Ok
u8 PCSHELL_IsMouseOver(
		i32 a1,
		i32 a2,
		i32 a3,
		i32 a4)
{
	i32 s1 = a1;
	i32 s2 = a2;
	i32 s3 = a3;
	i32 s4 = a4;

	if (gRenderTest & 0x10)
		return 0;

	PCSHELL_CoordsDCtoPC(&s1, &s2);
	PCSHELL_CoordsDCtoPC(&s3, &s4);

	return PCINPUT_IsMouseOver(s1, s2, s3, s4);
}

// @SMALLTODO
void PCSHELL_IsMouseOverText(char const *,i32,i32,i32)
{
    printf("PCSHELL_IsMouseOverText(char const *,i32,i32,i32)");
}

// @Ok
// @Matching
i32 PCSHELL_MouseMoved(void)
{
	return gShellMouseOffsetX || gShellMouseOffsetY;
}

// @Ok
// @Matching
void PCSHELL_Relax(void)
{
	WinYield();
	Sleep(10);
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

// @Bogus
void shell_optimized_func(i32, i32, i32)
{
	printf("void shell_optimized_func(i32, i32, i32)");
}

// @Ok
void displayControllerScreen(void)
{
	if (!gSceneRelated)
		PCGfx_BeginScene(1, -1);

	PShell_NormalFont();

	gControllerMenu->Display();
	gControllerMenuTwo->Display();

	shell_optimized_func(384, 222, 0);


	char *configName = STR_KB_CONFIG;
	if (gActionMapRelated)
		configName = STR_JOY_CONFIG;

	Shell_DrawTitleBar(gShellTitleBarRelated, 25, configName, 1, 0, 150, -21, 29);
	Shell_DrawBackground();

	PCSHELL_DrawMouseCursor();

	if (gSceneRelated)
		PCGfx_EndScene(1);
}

// @NotOk
// missing last addentry
void initActionMaps(void)
{
	for (
			i32 i = 0;
			i < ACTION_MAP_COUNT; 
			i++)
	{
		SActionMap *pMap = &gActionMaps[i];
		PCINPUT_GetKeyboardMappingForAction(pMap->field_0, &pMap->field_14);
		PCINPUT_GetControllerMappingForAction(pMap->field_0, &pMap->field_18);
		gControllerMenu->AddEntry(pMap->field_4);

		if (!gActionMapRelated)
		{
			if (pMap->field_14 == 0x4000)
			{
				gControllerMenuTwo->SetNormalColor(i, 90, 20, 6);
				strcpy(gKeyNames[i], "none");
			}
			else
			{
				DXINPUT_GetKeyName(pMap->field_14, gKeyNames[i]);
			}
		}
		else
		{
			if (i < 4)
			{
				gControllerMenu->EntryEnable(i, 0);
				gControllerMenuTwo->EntryEnable(i, 0);
				strcpy(gKeyNames[i], pMap->field_4);
			}
			else
			{

				if (pMap->field_18 == 0x4000)
				{
					gControllerMenuTwo->SetNormalColor(i, 90, 20, 6);
					strcpy(gKeyNames[i], "none");
				}
				else
				{
					sprintf(gKeyNames[i], "button %i", pMap->field_18);
				}
			}
		}

		gControllerMenuTwo->AddEntry(gKeyNames[i]);
	}

	gControllerMenu->AddEntry("restore default settings");
	//@FIXME: figure out the string
	//gControllerMenuTwo->AddEntry("");
}

// @MEDIUMTODO
void processControllerScreen(void)
{
    printf("processControllerScreen(void)");
}

// @Ok
// @Matching
void resetActionMaps(bool a1)
{
	delete gControllerMenu;
	delete gControllerMenuTwo;

	gControllerMenu = new CMenu(30, 60, 1u, 256, 256, 15);
	gControllerMenuTwo = new CMenu(332, 60, 1u, 256, 256, 15);

	initActionMaps();

	gControllerMenuTwo->scrollbar_zero = 0;
	gControllerMenu->scrollbar_zero = 0;

	gControllerMenu->Zoom(0);
	gControllerMenuTwo->Zoom(0);
	
	gControllerMenuTwo->mLine = a1 != 0 ? 0 : 4;
	gControllerMenu->mLine = gControllerMenuTwo->mLine;
}

void validate_SActionMap(void)
{
	VALIDATE_SIZE(SActionMap, 0x1C);

	VALIDATE(SActionMap, field_0, 0x0);
	VALIDATE(SActionMap, field_4, 0x4);
	VALIDATE(SActionMap, field_14, 0x14);
	VALIDATE(SActionMap, field_18, 0x18);
}
