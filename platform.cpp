#include "platform.h"
#include "validate.h"

// @Ok
void CPlatform::Shouldnt_DoPhysics_Be_Virtual(void)
{
	this->DoPhysics();
}

// @TODO
void CPlatform::DoPhysics(void)
{}

void validate_CPlatform(void){
	VALIDATE_SIZE(CPlatform, 0x35C);
}

