#include "scorpion.h"
#include "validate.h"

// @Ok
void __inline CScorpion::NextRoom(void)
{
	this->field_218 &= 0xFFFFFFE7;
}

void validate_CScorpion(void){
	VALIDATE_SIZE(CScorpion, 0xC28);
}
