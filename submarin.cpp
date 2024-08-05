#include "submarin.h"
#include "validate.h"
#include "ps2m3d.h"

extern CBaddy* BaddyList;

// @SMALLTODO
CSubmariner::CSubmariner(i16 *,i32)
{
    printf("CSubmariner::CSubmariner(i16 *,i32)");
}

// @Ok
CSubmariner::~CSubmariner(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));
}

// @Ok
void Submariner_CreateSubmariner(u32 * a2,u32 * a3)
{
	i16* v2 = reinterpret_cast<i16*>(a2[0]);
	i32 v3 = static_cast<i32>(a2[1]);

	*a3 = reinterpret_cast<u32>(new CSubmariner(v2, v3));
}

// @SMALLTODO
void Submariner_RelocatableModuleClear(void)
{
    printf("Submariner_RelocatableModuleClear(void)");
}

// @Ok
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
