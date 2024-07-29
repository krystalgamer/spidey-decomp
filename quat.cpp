#include "quat.h"
#include "validate.h"
#include "ps2funcs.h"


// @SMALLTODO
void QToM(CQuat*, MATRIX*)
{
	printf("void QToM(CQuat*, MATRIX*)");
}

// @MEDIUMTODO
void Quat_Slerp (CQuat& a1, CQuat const & a2, int a3, CQuat& a4)
{
	printf("void Quat_Slerp (CQuat& a1, CQuat const & a2, int a3, CQuat& a4)");
}


void validate_CQuat(void){
	VALIDATE_SIZE(CQuat, 0x10);

	VALIDATE(CQuat, x, 0x0);
	VALIDATE(CQuat, y, 0x4);
	VALIDATE(CQuat, z, 0x8);
	VALIDATE(CQuat, w, 0xC);
}
