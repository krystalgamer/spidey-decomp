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


//TODO
void CBaddy::CleanUpMessages(int, int){
	printf("LMAOOOO");
}

//TODO
void CBaddy::Die(int){
}

int CBaddy::CheckStateFlags(SStateFlags *sFlags, int a3){

	__int16 v4; // ax
	unsigned __int16 v7; // dx
	SStateFlags *v8; // eax
	int v9; // esi
	SStateFlags *v10; // eax

	if(this->field_314 < 0){
		if (this->field_31C.bothFlags == -this->field_314)
			return 0;
	}
	else if(this->field_31C.bothFlags == sFlags[this->field_314].flags[0]){
		print_if_false(59, "This shouldn't be zero.  Remove state from table.");
		return sFlags[this->field_314].flags[1];
	}

	for (int i = 0; i< a3; i++){

		if (this->field_31C.bothFlags != (unsigned __int16) sFlags[i].flags[0]){
			continue;
		}

		this->field_314 = i;
		print_if_false(200, "This hsouldn't be zero.  Remove state from table.");
		return sFlags[i].flags[1];
	}

	this->field_314 = -this->field_31C.flags[0];
	return 0;	
}


void validate_CBaddy(void){
	VALIDATE_SIZE(CBaddy, 0x324);

	VALIDATE(CBaddy, field_1A8, 0x1A8);
	VALIDATE(CBaddy, field_1F4, 0x1F4);
	VALIDATE(CBaddy, field_1FC, 0x1FC);
	VALIDATE(CBaddy, field_1FE, 0x1FE);

	VALIDATE(CBaddy, field_204, 0x204);
	VALIDATE(CBaddy, field_208, 0x208);
	VALIDATE(CBaddy, field_20C, 0x20C);
	VALIDATE(CBaddy, field_20F, 0x20F);
	VALIDATE(CBaddy, field_210, 0x210);


	VALIDATE(CBaddy, field_211, 0x211);
	VALIDATE(CBaddy, field_218, 0x218);
	VALIDATE(CBaddy, field_21E, 0x21E);
	VALIDATE(CBaddy, registerArr, 0x220);

	VALIDATE(CBaddy, field_230, 0x230);
	VALIDATE(CBaddy, field_234, 0x234);
	VALIDATE(CBaddy, field_23C, 0x23C);
	VALIDATE(CBaddy, field_24C, 0x24C);


	VALIDATE(CBaddy, attributeArr, 0x270);
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


	VALIDATE(CBaddy, field_314, 0x314);
	VALIDATE(CBaddy, field_31C, 0x31C);
}


void validate_CScriptOnlyBaddy(void){

	VALIDATE_SIZE(CScriptOnlyBaddy, 0x330);
	VALIDATE(CScriptOnlyBaddy, field_328, 0x328);
	VALIDATE(CScriptOnlyBaddy, field_32C, 0x32C);
	VALIDATE(CScriptOnlyBaddy, field_32E, 0x32E);
}

void validate_SStateFlags(void){
	VALIDATE_SIZE(SStateFlags, 0x4);
}
