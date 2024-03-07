#include "baddy.h"
#include "validate.h"
#include "utils.h"


int CBaddy::DistanceToPlayer(int a2){
	int v3; // eax	
	int result; // eax
	v3 = this->field_208;

	int dwordRead = *dword_5FCCF4;

	if ( v3 && dwordRead - v3 <= a2 )
		return this->field_204;

	this->field_208 = dwordRead;
	result = Utils_CrapXZDist(this->mPos, globalSuper->mPos);
	this->field_204 = result;
	return result;
}

void validate_CBaddy(void){
	VALIDATE(CBaddy, field_204, 0x204);
	VALIDATE(CBaddy, field_208, 0x208);
}