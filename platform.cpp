#include "platform.h"
#include "validate.h"

// @Ok
void CPlatform::Shouldnt_DoPhysics_Be_Virtual(void)
{
	this->DoPhysics();
}

// @BIGTODO
void CPlatform::DoPhysics(void)
{}

// @Ok
unsigned __int16 CPlatform::GetVariable(unsigned __int16 a2)
{
	if (a2 != (unsigned __int16)0x2200)
	{
		return CBaddy::GetVariable(a2);
	}

	return this->field_338;
}

void validate_CPlatform(void){
	VALIDATE_SIZE(CPlatform, 0x35C);

	VALIDATE(CPlatform, field_338, 0x338);
}

