#include "platform.h"
#include "validate.h"

// @MEDIUMTODO
void CPlatform::AI(void)
{
    printf("CPlatform::AI(void)");
}

// @SMALLTODO
void CPlatform::AdjustBruceHealth(void)
{
    printf("CPlatform::AdjustBruceHealth(void)");
}

// @SMALLTODO
CPlatform::CPlatform(i16 *,i32)
{
    printf("CPlatform::CPlatform(i16 *,i32)");
}

// @MEDIUMTODO
i32 CPlatform::ExecuteCommand(u16)
{
    printf("CPlatform::ExecuteCommand(u16)");
    return 0x04082024;
}

// @SMALLTODO
i32 CPlatform::Hit(SHitInfo *)
{
    printf("CPlatform::Hit(SHitInfo *)");
    return 0x04082024;
}

// @SMALLTODO
void CPlatform::MoveTo(CVector *)
{
    printf("CPlatform::MoveTo(CVector *)");
}

// @SMALLTODO
void CPlatform::NotifyTrodUpon(CBody *,CVector const *,CSVector const *)
{
    printf("CPlatform::NotifyTrodUpon(CBody *,CVector const *,CSVector const *)");
}

// @MEDIUMTODO
void CPlatform::SetVariable(u16)
{
    printf("CPlatform::SetVariable(u16)");
}

// @SMALLTODO
CPlatform::~CPlatform(void)
{
    printf("CPlatform::~CPlatform(void)");
}
// @Ok
void CPlatform::Shouldnt_DoPhysics_Be_Virtual(void)
{
	this->DoPhysics();
}

// @BIGTODO
void CPlatform::DoPhysics(void)
{
	printf("void CPlatform::DoPhysics(void)");
}

// @Ok
u16 CPlatform::GetVariable(u16 a2)
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

