#include "m3dinit.h"
#include "m3dcolij.h"
#include "validate.h"

void M3dColij_InitLineInfo(SLineInfo *)
{
}

void validate_SLineInfo(void)
{
	VALIDATE_SIZE(SLineInfo, 0xC * 2);

	VALIDATE(SLineInfo, vec_0, 0x0);
	VALIDATE(SLineInfo, vec_C, 0xC);
}
