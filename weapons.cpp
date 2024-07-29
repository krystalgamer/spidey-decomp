#include "weapons.h"
#include "validate.h"
#include "mem.h"

// @Ok
CGouradRibbon::CGouradRibbon(i32 NumPoints, i32 LeaveTrail)
{
	print_if_false(NumPoints > 1, "NumPoints must be at least 2");
	print_if_false((u32)NumPoints <= 0x20, "NumPoints too big for buffer.");

	this->NumPoints = NumPoints;

	this->mpPoints = static_cast<SRibbonPoint *>(
			DCMem_New(
				sizeof(SRibbonPoint) * NumPoints,
				0,
				1,
				0,
				1));

	print_if_false(LeaveTrail == 0 || LeaveTrail == 1, "LeaveTrail must be 0 or 1");

	this->mTrail = LeaveTrail;
}

void validate_CGouradRibbon(void)
{
	VALIDATE_SIZE(CGouradRibbon, 0x48);

	VALIDATE(CGouradRibbon, mTrail, 0x3C);
	VALIDATE(CGouradRibbon, NumPoints, 0x40);
	VALIDATE(CGouradRibbon, mpPoints, 0x44);
}
