#include "chain.h"
#include "validate.h"

void CChain::SetGroundY(int a2)
{
	this->field_1C = 1;
	this->field_18 = a2;
}

void validate_CChain(void)
{
	VALIDATE_SIZE(CChain, 0x28);

	VALIDATE(CChain, field_18, 0x18);
	VALIDATE(CChain, field_1C, 0x1C);
}
