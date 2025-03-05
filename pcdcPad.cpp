#include "pcdcPad.h"
#include "PCInput.h"

// @SMALLTODO
void pdInitPeripheral(void)
{
	printf("void pdInitPeripheral(void)");
}

// @Ok
void pdExitPeripheral(void)
{
	PCINPUT_Shutdown();
}

// @Ok
i32 pdTmrAlarm(i32, u8*)
{
	return 0;
}
