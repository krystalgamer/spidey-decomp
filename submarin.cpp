#include "submarin.h"
#include "validate.h"
#include "ps2m3d.h"


void CSubmariner::AI(void){
	if (*submarinerDieRelated){
		this->Die(0);
	}
	else{
		M3d_BuildTransform(this);
	}
}


void validate_CSubmariner(void){
	VALIDATE_SIZE(CSubmariner, 0x324);
}