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
	VALIDATE(CBaddy, field_1A8, 0x1A8);
	VALIDATE(CBaddy, field_1F4, 0x1F4);
	VALIDATE(CBaddy, field_204, 0x204);
	VALIDATE(CBaddy, field_208, 0x208);
	VALIDATE(CBaddy, field_20C, 0x20C);


	VALIDATE(CBaddy, field_211, 0x211);
	VALIDATE(CBaddy, field_21E, 0x21E);

	VALIDATE(CBaddy, field_230, 0x230);
	VALIDATE(CBaddy, field_234, 0x234);
	VALIDATE(CBaddy, field_24C, 0x24C);
	VALIDATE(CBaddy, field_27C, 0x27C);

	VALIDATE(CBaddy, field_290, 0x290);
	VALIDATE(CBaddy, field_294, 0x294);
	VALIDATE(CBaddy, field_295, 0x295);
	VALIDATE(CBaddy, field_296, 0x296);
	VALIDATE(CBaddy, field_297, 0x297);
	VALIDATE(CBaddy, field_298, 0x298);

	VALIDATE(CBaddy, field_2A8, 0x2A8);
	VALIDATE(CBaddy, field_2AC, 0x2AC);

	VALIDATE(CBaddy, field_2B0, 0x2B0);
	VALIDATE(CBaddy, field_2B4, 0x2B4);
	VALIDATE(CBaddy, field_2B8, 0x2B8);
	VALIDATE(CBaddy, field_2D0, 0x2D0);

	VALIDATE(CBaddy, field_2F0, 0x2F0);
	VALIDATE(CBaddy, field_2F4, 0x2F4);
	VALIDATE(CBaddy, field_2FC, 0x2FC);
}