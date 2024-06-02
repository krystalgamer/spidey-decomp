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

static CSuper* BaddyList;

// @NotOk
// globals
CSuper* CScorpion::FindJonah(void)
{
	if (this->field_BEC)
		return field_BEC;


	for (CSuper* cur = BaddyList; cur; cur = reinterpret_cast<CSuper*>(cur->field_20))
	{
		if (cur->field_38 == 316)
		{
			this->field_BEC = cur;
			return this->field_BEC;
		}
	}

	return NULL;
}

void validate_CScorpion(void){
	VALIDATE_SIZE(CScorpion, 0xC28);

	VALIDATE(CScorpion, field_BEC, 0xBEC);

	VALIDATE(CScorpion, field_BF0, 0xBF0);
	VALIDATE(CScorpion, field_BF8, 0xBF8);
}
