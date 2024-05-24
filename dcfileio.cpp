#include "dcfileio.h"


static volatile int gFileIOStatus;

// @NotOk
// globals
void FileIO_Sync(void)
{
	while (gFileIOStatus);
}
