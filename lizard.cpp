#include "lizard.h"
#include "validate.h"
#include "ps2m3d.h"


// @Ok
void CLizard::AI(void)
{
	__int16 v2 = this->field_44;
	if (v2 & 1)
	{
		this->field_44 = v2 & 0xFFFE;
		this->CycleAnim(this->field_12A == 0 ? 5 : 0, 1);
	}

	if (this->field_290)
	{
		this->CleanUpMessages(1, 0);
	}

	M3d_BuildTransform(this);
}

void validate_CLizard(void){
	VALIDATE_SIZE(CLizard, 0x324);
}
