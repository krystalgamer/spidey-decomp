#include "baddy.h"
#include "validate.h"
#include "utils.h"
#include "mem.h"


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

// Revisit
int CBaddy::TrapWeb(void){
	if(!(this->field_2A8 & 0x10000)){
		if (this->field_E2 > 0){
		return 1;
		}
	}

	

	return 0;
}

//Revisit

int CBaddy::TugWeb(void){
	if(!(this->field_2A8 & 0x10000)){
		if (this->field_E2 > 0){
		return 1;
		}
	}

	Mem_RecoverPointer((SHandle*)&this->field_10C);

	return 0;
}

void validate_CBaddy(void){
	VALIDATE(CBaddy, field_204, 0x204);
	VALIDATE(CBaddy, field_208, 0x208);
	VALIDATE(CBaddy, field_2A8, 0x2A8);
}