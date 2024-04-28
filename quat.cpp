#include "quat.h"
#include "validate.h"




void validate_CQuat(void){
	VALIDATE_SIZE(CQuat, 0x10);

	VALIDATE(CQuat, x, 0x0);
	VALIDATE(CQuat, y, 0x4);
	VALIDATE(CQuat, z, 0x8);
	VALIDATE(CQuat, w, 0xC);
}