#include "scorpion.h"
#include "validate.h"

// @Ok
void __inline CScorpion::NextRoom(void)
{
	this->field_218 &= 0xFFFFFFE7;
}

// @Ok
__inline void* CScorpion::GetCurrentTarget(void)
{
	if (!this->field_BF8)
	{
		return NULL;
	}

	return Mem_RecoverPointer(&this->field_BF0);
}

// @Ok
void Scorpion_GetCurrentTarget(unsigned int* pScorp, unsigned int* pTarget)
{
	*pTarget = reinterpret_cast<unsigned int>((*reinterpret_cast<CScorpion**>(pScorp))->GetCurrentTarget());
}

void validate_CScorpion(void){
	VALIDATE_SIZE(CScorpion, 0xC28);

	VALIDATE(CScorpion, field_BF0, 0xBF0);
	VALIDATE(CScorpion, field_BF8, 0xBF8);
}
