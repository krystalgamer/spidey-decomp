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
