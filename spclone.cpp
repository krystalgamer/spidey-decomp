#include "spclone.h"
#include "validate.h"

// @MEDIUMTODO
void CSpClone::AI(void)
{
    printf("CSpClone::AI(void)");
}

// @SMALLTODO
CSpClone::CSpClone(i16 *,i32)
{
    printf("CSpClone::CSpClone(i16 *,i32)");
}

// @MEDIUMTODO
void CSpClone::DoMGSShadow(void)
{
    printf("CSpClone::DoMGSShadow(void)");
}

// @SMALLTODO
void CSpClone::GetNewCommandBlock(u32)
{
    printf("CSpClone::GetNewCommandBlock(u32)");
}

// @SMALLTODO
void CSpClone::KillCommandBlockByID(i32)
{
    printf("CSpClone::KillCommandBlockByID(i32)");
}

// @MEDIUMTODO
void CSpClone::SynthesizeAnalogueInput(void)
{
    printf("CSpClone::SynthesizeAnalogueInput(void)");
}

// @SMALLTODO
CSpClone::~CSpClone(void)
{
    printf("CSpClone::~CSpClone(void)");
}

// @SMALLTODO
void SpClone_CreateSpClone(u32 const *,u32 *)
{
    printf("SpClone_CreateSpClone(u32 const *,u32 *)");
}

// @SMALLTODO
void SpClone_RelocatableModuleClear(void)
{
    printf("SpClone_RelocatableModuleClear(void)");
}

// @Ok
void CSpClone::Shouldnt_DoPhysics_Be_Virtual(void)
{
	this->DoPhysics();
}

// @BIGTODO
void CSpClone::DoPhysics(void)
{}

// @BIGTODO
__inline int* CSpClone::KillCommandBlock(int*)
{
	return (int*)0x02062024;
}

// @NotOk
// Revisit
void CSpClone::KillAllCommandBlocks(void)
{
	for (int* cur = reinterpret_cast<int*>(this->field_34C); cur; cur = this->KillCommandBlock(cur));
	this->field_34C = 0;
}

void validate_CSpClone(void){
	VALIDATE_SIZE(CSpClone, 0x350);

	VALIDATE(CSpClone, field_328, 0x328);
	VALIDATE(CSpClone, field_32C, 0x32C);
	VALIDATE(CSpClone, field_330, 0x330);
	VALIDATE(CSpClone, field_334, 0x334);
	VALIDATE(CSpClone, field_338, 0x338);
	VALIDATE(CSpClone, field_34C, 0x34C);
}
