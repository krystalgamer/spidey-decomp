#include "web.h"
#include "validate.h"

void validate_CImpactWeb(void){
	VALIDATE_SIZE(CImpactWeb, 0x8C);
}

void validate_CDomePiece(void){
	VALIDATE_SIZE(CDomePiece, 0x100);

	VALIDATE(CDomePiece, field_F8, 0xF8);
	VALIDATE(CDomePiece, field_FC, 0xFC);
}
void validate_CDome(void){
	VALIDATE_SIZE(CDome, 0x11C);
}

void validate_CDomeRing(void){
	VALIDATE_SIZE(CDomeRing, 0x110);

	VALIDATE(CDomeRing, field_F8, 0xF8);
	VALIDATE(CDomeRing, field_FC, 0xFC);
	VALIDATE(CDomeRing, field_100, 0x100);
	VALIDATE(CDomeRing, field_104, 0x104);
	VALIDATE(CDomeRing, field_108, 0x108);
}

void validate_CWeb(void){
	VALIDATE_SIZE(CWeb, 0x13C);


	VALIDATE(CWeb, field_108, 0x108);
	VALIDATE(CWeb, field_10C, 0x10C);
	VALIDATE(CWeb, field_110, 0x110);
	VALIDATE(CWeb, field_114, 0x114);
	VALIDATE(CWeb, field_118, 0x118);
	VALIDATE(CWeb, field_11C, 0x11C);
	VALIDATE(CWeb, field_120, 0x120);
	VALIDATE(CWeb, field_124, 0x124);
	VALIDATE(CWeb, field_128, 0x128);

}

void validate_CSwinger(void){
	VALIDATE_SIZE(CSwinger, 0x190);
}
