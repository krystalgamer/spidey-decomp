#include "PCInput.h"
#include "SpideyDX.h"
#include "DXsound.h"

static unsigned char gMouseStatus;

EXPORT i32 gMouseBoundOne;
EXPORT i32 gMouseBoundTwo;
EXPORT i32 gMouseBoundThree;
EXPORT i32 gMouseBoundFour;

EXPORT i32 gMouseX;
EXPORT i32 gMouseY;

EXPORT i32 gMouseHotSpotX;
EXPORT i32 gMouseHotSpotY;

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

// @SMALLTODO
void PCINPUT_GetKeyboardMappingForAction(u32,u32 *)
{
    printf("PCINPUT_GetKeyboardMappingForAction(u32,u32 *)");
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

// @SMALLTODO
void PCINPUT_RestoreDefaultKeyboardSettings(void)
{
    printf("PCINPUT_RestoreDefaultKeyboardSettings(void)");
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
