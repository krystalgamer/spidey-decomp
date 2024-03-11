#pragma once
#include "shell.h"
#include "validate.h"

void validate_CRudeWordHitterSpidey(void){
	VALIDATE_SIZE(CRudeWordHitterSpidey, 0x1AC);
}

void validate_CDummy(void){
	VALIDATE_SIZE(CDummy, 0xA18);

	VALIDATE(CDummy, field_240, 0x240);
	VALIDATE(CDummy, field_288, 0x288);

	VALIDATE(CDummy, field_2D4, 0x2D4);
	VALIDATE(CDummy, field_304, 0x304);
	VALIDATE(CDummy, field_418, 0x418);
}
