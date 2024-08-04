#include "PCInput.h"

static unsigned char gMouseStatus;

// @NotOk
// Globals
int PCINPUT_GetMouseStatus(void)
{
	return gMouseStatus;
}

static int gMouseBoundOne;
static int gMouseBoundTwo;
static int gMouseBoundThree;
static int gMouseBoundFour;


// @NotOk
// Globals
void PCINPUT_SetMouseBounds(int a1, int a2, int a3, int a4)
{
	gMouseBoundOne = a1;
	gMouseBoundTwo = a2;
	gMouseBoundThree = a3;
	gMouseBoundFour = a4;
}

static int gMouseX;
static int gMouseY;

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

// @SMALLTODO
void PCINPUT_ClearKeyState(u8)
{
    printf("PCINPUT_ClearKeyState(u8)");
}

// @SMALLTODO
void PCINPUT_ClearMouseState(u8)
{
    printf("PCINPUT_ClearMouseState(u8)");
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

// @SMALLTODO
void PCINPUT_GetNumControllerButtons(void)
{
    printf("PCINPUT_GetNumControllerButtons(void)");
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

// @SMALLTODO
void PCINPUT_IsMouseButtonPressed(u8,i32)
{
    printf("PCINPUT_IsMouseButtonPressed(u8,i32)");
}

// @SMALLTODO
void PCINPUT_IsMouseButtonReleased(u8)
{
    printf("PCINPUT_IsMouseButtonReleased(u8)");
}

// @SMALLTODO
void PCINPUT_IsMouseOver(i32,i32,i32,i32)
{
    printf("PCINPUT_IsMouseOver(i32,i32,i32,i32)");
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

// @SMALLTODO
void PCINPUT_SetMouseHotspot(i32,i32)
{
    printf("PCINPUT_SetMouseHotspot(i32,i32)");
}

// @SMALLTODO
void PCINPUT_SetMousePosition(i32,i32)
{
    printf("PCINPUT_SetMousePosition(i32,i32)");
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
