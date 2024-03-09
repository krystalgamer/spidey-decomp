#include "simby.h"
#include "validate.h"


void validate_CPunchOb(void){
	VALIDATE_SIZE(CPunchOb, 0x32C);
}

void validate_CSimby(void){
	VALIDATE_SIZE(CSimby, 0x460);
}

void validate_CSimbyBase(void){
	VALIDATE_SIZE(CSimbyBase, 0x334);
}