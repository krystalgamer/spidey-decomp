#include "submarin.h"
#include "validate.h"
#include "ps2m3d.h"


// @SMALLTODO
CSubmariner::CSubmariner(i16 *,i32)
{
    printf("CSubmariner::CSubmariner(i16 *,i32)");
}

// @SMALLTODO
CSubmariner::~CSubmariner(void)
{
    printf("CSubmariner::~CSubmariner(void)");
}

// @SMALLTODO
void Submariner_CreateSubmariner(u32 const *,u32 *)
{
    printf("Submariner_CreateSubmariner(ulong const *,u32 *)");
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
