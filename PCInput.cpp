#include "PCInput.h"
#include "SpideyDX.h"
#include "DXsound.h"

#include "validate.h"

static unsigned char gMouseStatus;

EXPORT i32 gMouseBoundOne;
EXPORT i32 gMouseBoundTwo;
EXPORT i32 gMouseBoundThree;
EXPORT i32 gMouseBoundFour;

EXPORT i32 gMouseX;
EXPORT i32 gMouseY;

EXPORT i32 gMouseHotSpotX;
EXPORT i32 gMouseHotSpotY;

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

static unsigned char gControllerAxesRelatedOne;
static int gControllerAxesRelatedTwo = -1;

// @NotOk
// Globals
void PCINPUT_FreezeControllerAxes(void)
{
	gControllerAxesRelatedOne = 1;
	gControllerAxesRelatedTwo = -1;
}

// @Ok
// @Matching
void PCINPUT_ClearKeyState(u8 a1)
{
	DXINPUT_SetKeyState(a1, 0);
}

// @NotOk
// re-check couldn't find it
void PCINPUT_ClearMouseState(u8 a1)
{
	DXINPUT_SetMouseButtonState(a1, 0);
}

// @SMALLTODO
void PCINPUT_GetControllerDirections(void)
{
    printf("PCINPUT_GetControllerDirections(void)");
}

// @SMALLTODO
void PCINPUT_GetControllerMappingForAction(u32,u32 *)
{
    printf("PCINPUT_GetControllerMappingForAction(u32,u32 *)");
}

// @Ok
void PCINPUT_GetKeyboardMappingForAction(
		u32 a1,
		u32* a2)
{
	SKeyboardMapping* mappings = reinterpret_cast<SKeyboardMapping*>(gKeyboardMappings);
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

// @SMALLTODO
void PCINPUT_GetMappedStates(u32 *,u32 *)
{
    printf("PCINPUT_GetMappedStates(u32 *,u32 *)");
}

// @SMALLTODO
void PCINPUT_GetMouseHotspotPosition(i32 *,i32 *)
{
    printf("PCINPUT_GetMouseHotspotPosition(i32 *,i32 *)");
}

// @Ok
i32 PCINPUT_GetNumControllerButtons(void)
{
	return DXINPUT_GetNumControllerButtons();
}

// @SMALLTODO
void PCINPUT_Initialize(void)
{
    printf("PCINPUT_Initialize(void)");
}

// @SMALLTODO
void PCINPUT_IsControllerButtonPressed(u8,i32)
{
    printf("PCINPUT_IsControllerButtonPressed(u8,i32)");
}

// @SMALLTODO
void PCINPUT_IsKeyPressed(u8,i32)
{
    printf("PCINPUT_IsKeyPressed(u8,i32)");
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

// @SMALLTODO
void PCINPUT_PollController(void)
{
    printf("PCINPUT_PollController(void)");
}

// @SMALLTODO
void PCINPUT_PollKeyboard(void)
{
    printf("PCINPUT_PollKeyboard(void)");
}

// @SMALLTODO
void PCINPUT_RestoreDefaultControllerSettings(void)
{
    printf("PCINPUT_RestoreDefaultControllerSettings(void)");
}

// @Ok
// @Matching
void PCINPUT_RestoreDefaultKeyboardSettings(void)
{
	memcpy(gKeyboardMappings, gDefaultKeyboardMappings, sizeof(gKeyboardMappings));
}

// @SMALLTODO
void PCINPUT_SetControllerMappingForAction(u32,u32)
{
    printf("PCINPUT_SetControllerMappingForAction(u32,u32)");
}

// @SMALLTODO
void PCINPUT_SetKeyboardMappingForAction(u32,u32)
{
    printf("PCINPUT_SetKeyboardMappingForAction(u32,u32)");
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
void PCINPUT_SetMousePosition(
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
	if ( newMouseY < gMouseBoundTwo )
		adjustedY = gMouseBoundTwo;

	gMouseX = adjustedX;
	gMouseY = gMouseBoundFour;
	if ( adjustedY <= gMouseBoundFour )
		gMouseY = adjustedY;
}

// @SMALLTODO
void PCINPUT_SetupForceFeedbackSineEffect(i32,float)
{
    printf("PCINPUT_SetupForceFeedbackSineEffect(i32,float)");
}

// @SMALLTODO
void PCINPUT_Shutdown(void)
{
    printf("PCINPUT_Shutdown(void)");
}

// @SMALLTODO
void PCINPUT_StartForceFeedbackEffect(void)
{
    printf("PCINPUT_StartForceFeedbackEffect(void)");
}

// @SMALLTODO
void PCINPUT_StopForceFeedbackEffect(void)
{
    printf("PCINPUT_StopForceFeedbackEffect(void)");
}

// @SMALLTODO
void PCINPUT_UpdateMouse(void)
{
    printf("PCINPUT_UpdateMouse(void)");
}

// @SMALLTODO
void checkDebugKeypress(void)
{
    printf("checkDebugKeypress(void)");
}

void validate_SKeyboardMapping(void)
{
	VALIDATE_SIZE(SKeyboardMapping, 0x8);

	VALIDATE(SKeyboardMapping, field_0, 0x0);
	VALIDATE(SKeyboardMapping, field_4, 0x4);
}
