#include "PCInput.h"
#include "SpideyDX.h"
#include "DXsound.h"
#include "non_win32.h"
#include "DXinit.h"

#include <cstring>

#include "validate.h"

EXPORT u8 gMouseStatus;

EXPORT i32 gMouseBoundOne;
EXPORT i32 gMouseBoundTwo;
EXPORT i32 gMouseBoundThree;
EXPORT i32 gMouseBoundFour;

EXPORT i32 gMouseX;
EXPORT i32 gMouseY;

EXPORT i32 gMouseHotSpotX;
EXPORT i32 gMouseHotSpotY;

EXPORT u32 gPcInputTickRelated;

EXPORT i32 gOldMouseX;
EXPORT i32 gOldMouseY;

EXPORT i32 gControllerX;
EXPORT i32 gControllerY;

EXPORT u8 gDefaultKeyboardMappings[0x70] =
{
  0x01, 0x00, 0x00, 0x00, 0xC8, 0x00, 0x00, 0x00, 0x02, 0x00, 
  0x00, 0x00, 0xD0, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 
  0xCB, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0xCD, 0x00, 
  0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 
  0x20, 0x00, 0x00, 0x00, 0x4D, 0x00, 0x00, 0x00, 0x40, 0x00, 
  0x00, 0x00, 0x4B, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 
  0x48, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x47, 0x00, 
  0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x51, 0x00, 0x00, 0x00, 
  0x00, 0x04, 0x00, 0x00, 0x49, 0x00, 0x00, 0x00, 0x00, 0x10, 
  0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 
  0x0F, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00
};

EXPORT u8 gKeyboardMappings[0x70] =
{
  0x01, 0x00, 0x00, 0x00, 0xC8, 0x00, 0x00, 0x00, 0x02, 0x00, 
  0x00, 0x00, 0xD0, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 
  0xCB, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0xCD, 0x00, 
  0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 
  0x20, 0x00, 0x00, 0x00, 0x4D, 0x00, 0x00, 0x00, 0x40, 0x00, 
  0x00, 0x00, 0x4B, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 
  0x48, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x47, 0x00, 
  0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x51, 0x00, 0x00, 0x00, 
  0x00, 0x04, 0x00, 0x00, 0x49, 0x00, 0x00, 0x00, 0x00, 0x10, 
  0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 
  0x0F, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00
};

EXPORT u8 gControllerMappings[0x70] =
{
  0x01, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x02, 0x00, 
  0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 
  0x00, 0x40, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x40, 
  0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 
  0x20, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x40, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 
  0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x06, 0x00, 
  0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 
  0x00, 0x04, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x10, 
  0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 
  0x00, 0x40, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00
};

EXPORT u8 gDefaultControllerMappings[0x70] =
{
  0x01, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x02, 0x00, 
  0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 
  0x00, 0x40, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x40, 
  0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 
  0x20, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x40, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 
  0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x06, 0x00, 
  0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 
  0x00, 0x04, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x10, 
  0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 
  0x00, 0x40, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00
};

// @NotOk
// Globals
int PCINPUT_GetMouseStatus(void)
{
	return gMouseStatus;
}


// @NotOk
// Globals
void PCINPUT_SetMouseBounds(int a1, int a2, int a3, int a4)
{
	gMouseBoundOne = a1;
	gMouseBoundTwo = a2;
	gMouseBoundThree = a3;
	gMouseBoundFour = a4;
}

// @NotOk
// Globals
void PCINPUT_GetMousePosition(int *x, int *y)
{
	*x = gMouseX;
	*y = gMouseY;
}

EXPORT u8 gControllerAxesRelatedOne;
EXPORT i32 gControllerAxesRelatedTwo = -1;

// @NotOk
// Globals
void PCINPUT_FreezeControllerAxes(void)
{
	gControllerAxesRelatedOne = 1;
	gControllerAxesRelatedTwo = -1;
}

// @Ok
// @Matching
INLINE void PCINPUT_ClearKeyState(u8 a1)
{
	DXINPUT_SetKeyState(a1, 0);
}

// @NotOk
// re-check couldn't find it
void PCINPUT_ClearMouseState(u8 a1)
{
	DXINPUT_SetMouseButtonState(a1, 0);
}

// @Ok
u8 PCINPUT_GetControllerDirections(void)
{
  u8 result = 0;

  if (!gControllerAxesRelatedOne)
  {
    if (gControllerX < -250)
      result = 4;
    if (gControllerX > 250)
      result |= 8u;
    if (gControllerY < -250)
      result |= 1u;
    if (gControllerY > 250)
      result |= 2u;
  }

  if (gControllerAxesRelatedTwo != -1)
  {
    if (gControllerAxesRelatedTwo > 18000)
      result |= 4u;

    if (gControllerAxesRelatedTwo > 0 && gControllerAxesRelatedTwo < 18000)
      result |= 8u;

    if (gControllerAxesRelatedTwo < 9000 || gControllerAxesRelatedTwo > 27000)
      result |= 1u;

    if (gControllerAxesRelatedTwo > 9000 && gControllerAxesRelatedTwo < 27000)
      result |= 2;
  }

  return result;
}

// @Ok
void PCINPUT_GetControllerMappingForAction(u32 a1, u32* a2)
{
	SMapping* mappings = reinterpret_cast<SMapping*>(gControllerMappings);
	for(i32 i = 0;; i++)
	{
		if (mappings[i].field_0 == 0x8000)
			break;

		if (a1 == mappings[i].field_0)
		{
			*a2 = mappings[i].field_4;
			return;
		}
	}

	*a2 = 0x4000;
}

// @Ok
void PCINPUT_GetKeyboardMappingForAction(
		u32 a1,
		u32* a2)
{
	SMapping* mappings = reinterpret_cast<SMapping*>(gKeyboardMappings);
	for(i32 i = 0;; i++)
	{
		if (mappings[i].field_0 == 0x8000)
			break;

		if (a1 == mappings[i].field_0)
		{
			*a2 = mappings[i].field_4;
			return;
		}
	}

	*a2 = 0x4000;
}

// @NotOk
// @Test
// Thw original code uses array of ints and the code is nasty
// I've simplified with a structure that significantly changes the code gen
void PCINPUT_GetMappedStates(u32* a1, u32* a2)
{
	SMapping* kbMappings = reinterpret_cast<SMapping*>(gKeyboardMappings);
	if (PCINPUT_PollKeyboard())
	{
		for (i32 i = 0; ; i++)
		{
			if (kbMappings[i].field_0 == 0x8000)
				break;
			
			if (kbMappings[i].field_4 == 0x4000)
				continue;

			if (PCINPUT_IsKeyPressed(kbMappings[i].field_4, 0))
			{
				*a1 = kbMappings[i].field_0;
			}

			if (PCINPUT_IsKeyPressed(kbMappings[i].field_4, 1))
			{
				*a2 = kbMappings[i].field_0;
			}
		}
	}

	SMapping* controllerMappings = reinterpret_cast<SMapping*>(gControllerMappings);
	if (PCINPUT_PollController())
	{
		for (i32 j = 0; ; j++)
		{
			if (controllerMappings[j].field_0 == 0x8000)
				break;
			
			if (controllerMappings[j].field_4 == 0x4000)
				continue;

			if (PCINPUT_IsControllerButtonPressed(controllerMappings[j].field_4, 0))
			{
				*a1 = controllerMappings[j].field_0;
			}

			if (PCINPUT_IsControllerButtonPressed(controllerMappings[j].field_4, 1))
			{
				*a2 = controllerMappings[j].field_0;
			}
		}
	}
}

// @Ok
// @Matching
void PCINPUT_GetMouseHotspotPosition(i32* a1, i32* a2)
{
	*a1 = gMouseX + gMouseHotSpotX * gGameResolutionX / 640;
	*a2 = gMouseY + gMouseHotSpotY * gGameResolutionY / 480;
}

// @Ok
i32 PCINPUT_GetNumControllerButtons(void)
{
	return DXINPUT_GetNumControllerButtons();
}

// @Ok
u8 PCINPUT_Initialize(void)
{
	DXINPUT_Initialize(gDirectInputRelated, gHwnd);
	if (!DXINPUT_SetupKeyboard((gRenderTest & 1) == 0, 1))
	{
		DXERR_printf("A keyboard device could not be set up.\n");
		return 0;
	}

	if ((gRenderTest & 0x10) == 0)
	{
		if (!DXINPUT_SetupMouse((gRenderTest & 1) == 0))
		{
			DXERR_printf("A mouse device could not be set up.\n");
			return 0;
		}

		gMouseStatus = 1;
	}

	if (!DXINPUT_SetupController())
		DXERR_printf("A game controller device could not be set up.\n");

	return 1;
}

// @Ok
// @Matching
i32 PCINPUT_IsControllerButtonPressed(u8 a1, i32 a2)
{
	if (a2)
		return DXINPUT_GetControllerButtonState(a1) == 255;
	else
		return DXINPUT_GetControllerButtonState(a1) & 0x7F;
}

// @Ok
// @Matching
INLINE i32 PCINPUT_IsKeyPressed(u8 a1, i32 a2)
{
	if (a2)
		return DXINPUT_GetKeyState(a1) == 255;
	else
		return DXINPUT_GetKeyState(a1) & 0x7F;
}

// @Ok
// @Matching
i32 PCINPUT_IsMouseButtonPressed(u8 a1, i32 a2)
{
	if ( a2 )
		return DXINPUT_GetMouseButtonState(a1) == -1;
	else
		return DXINPUT_GetMouseButtonState(a1) & 0x7F;
}

// @Ok
// @Matching
i32 PCINPUT_IsMouseButtonReleased(u8 button)
{
	return DXINPUT_GetMouseButtonState(button) == 0x80;
}

// @Ok
// @Matching
i32 PCINPUT_IsMouseOver(
		i32 a1,
		i32 a2,
		i32 a3,
		i32 a4)
{
	i32 mouseX = gMouseX + gMouseHotSpotX * gGameResolutionX / 640;
	i32 mouseY = gMouseY + gMouseHotSpotY * gGameResolutionY / 480;

	return mouseX > a1 && mouseX < a3 && mouseY > a2 && mouseY < a4;
}

// @Ok
INLINE u8 PCINPUT_PollController(void)
{
	if (!DXINPUT_PollController(&gControllerX, &gControllerY, &gControllerAxesRelatedTwo))
		return 0;

	if (gControllerAxesRelatedOne &&
			gControllerX < 250 &&
			gControllerX > -250 &&
			gControllerY < 250 &&
			gControllerY > -250)
	{
		gControllerAxesRelatedOne = 0;
	}

	return 1;
}

// @Ok
// @Matching
INLINE u8 PCINPUT_PollKeyboard(void)
{
	if (DXINPUT_PollKeyboard() < 0)
		return 0;

	checkDebugKeypress();
	return 1;
}

// @Ok
void PCINPUT_RestoreDefaultControllerSettings(void)
{
	memcpy(gControllerMappings, gDefaultControllerMappings, sizeof(gControllerMappings));
}

// @Ok
// @Matching
void PCINPUT_RestoreDefaultKeyboardSettings(void)
{
	memcpy(gKeyboardMappings, gDefaultKeyboardMappings, sizeof(gKeyboardMappings));
}

// @Ok
void PCINPUT_SetControllerMappingForAction(u32 a1, u32 a2)
{
	SMapping* mappings = reinterpret_cast<SMapping*>(gControllerMappings);
	for(i32 i = 0;; i++)
	{
		if (mappings[i].field_0 == 0x8000)
			break;

		if (a1 == mappings[i].field_0)
		{
			mappings[i].field_4 = a2;
			return;
		}
	}
}

// @Ok
void PCINPUT_SetKeyboardMappingForAction(u32 a1, u32 a2)
{
	SMapping* mappings = reinterpret_cast<SMapping*>(gKeyboardMappings);
	for(i32 i = 0;; i++)
	{
		if (mappings[i].field_0 == 0x8000)
			break;

		if (a1 == mappings[i].field_0)
		{
			mappings[i].field_4 = a2;
			return;
		}
	}
}

// @Ok
// @Matching
void PCINPUT_SetMouseHotspot(
		i32 a1,
		i32 a2)
{
	gMouseHotSpotX = a1;
	gMouseHotSpotY = a2;
}

// @Ok
INLINE void PCINPUT_SetMousePosition(
		i32 newMouseX,
		i32 newMouseY)
{
	i32 adjustedX;
	i32 adjustedY;

	adjustedX = newMouseX;
	if ( newMouseX < gMouseBoundOne )
		adjustedX = gMouseBoundOne;
	if ( adjustedX > gMouseBoundThree )
		adjustedX = gMouseBoundThree;

	adjustedY = newMouseY;
	if ( adjustedY < gMouseBoundTwo )
		adjustedY = gMouseBoundTwo;
	if ( adjustedY > gMouseBoundFour )
		adjustedY = gMouseBoundFour;

	gMouseX = adjustedX;
	gMouseY = adjustedY;
}

// @Ok
// @Matching
u8 PCINPUT_SetupForceFeedbackSineEffect(i32 a1, f32 a2)
{
	if (gRenderTest & 0x20)
		return 1;

	return DXINPUT_SetupForceFeedbackSineEffect(a1, a2) != 0;
}

// @Ok
void PCINPUT_Shutdown(void)
{
	DXINPUT_Release();
}

// @Ok
// @Matching
u8 PCINPUT_StartForceFeedbackEffect(void)
{
	if (gRenderTest & 0x20)
		return 1;

	return DXINPUT_StartForceFeedbackEffect() != 0;
}

// @Ok
// @Matching
u8 PCINPUT_StopForceFeedbackEffect(void)
{
	if (gRenderTest & 0x20)
		return 1;

	return DXINPUT_StopForceFeedbackEffect() != 0;
}

EXPORT f32 ONE_FLOAT = 1.0f;

// @Ok
u8 PCINPUT_UpdateMouse(void)
{
	i32 v5 = 0;
	i32 v6 = 0;
	if ( !gMouseStatus || !DXINPUT_PollMouse(&v5, &v6) )
		return 0;

	gOldMouseX = gMouseX;
	gOldMouseY = gMouseY;

	gMouseX += (i32)(v6 * ONE_FLOAT);
	gMouseY += (i32)(v5 * ONE_FLOAT);

	PCINPUT_SetMousePosition(gMouseX, gMouseY);

	return gOldMouseX != gMouseX || gOldMouseY != gMouseY;
}

// @Ok
// @Matching
INLINE void checkDebugKeypress(void)
{
	if (GetTickCount() >= gPcInputTickRelated &&
			PCINPUT_IsKeyPressed(0x43, 0))
	{
		DXPOLY_SaveScreen();
		PCINPUT_ClearKeyState(0x1F);
		gPcInputTickRelated = GetTickCount() + 500;
	}
}

void validate_SMapping(void)
{
	VALIDATE_SIZE(SMapping, 0x8);

	VALIDATE(SMapping, field_0, 0x0);
	VALIDATE(SMapping, field_4, 0x4);
}
