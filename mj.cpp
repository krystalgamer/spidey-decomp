#include "mj.h"
#include "validate.h"
#include "ps2m3d.h"


void CMJ::AI(void){
	if (this->field_290){
		this->CleanUpMessages(1, 0);
	}

	if(this->field_44 & 1){
		this->field_44 &= 0xFFFE;
		this->CycleAnim(1 - this->field_12A, 1);
	}

	M3d_BuildTransform(this);
}

void validate_CMJ(void){
	VALIDATE_SIZE(CMJ, 0x324);
}