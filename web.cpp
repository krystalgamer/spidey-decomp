#include "web.h"
#include "validate.h"

void validate_CImpactWeb(void){
	VALIDATE_SIZE(CImpactWeb, 0x8C);
}

void validate_CDomePiece(void){
	VALIDATE_SIZE(CDomePiece, 0x100);
}
void validate_CDome(void){
	VALIDATE_SIZE(CDome, 0x11C);
}

void validate_CDomeRing(void){
	VALIDATE_SIZE(CDomeRing, 0x110);
}

void validate_CWeb(void){
	VALIDATE_SIZE(CWeb, 0x13C);
}

void validate_CSwinger(void){
	VALIDATE_SIZE(CSwinger, 0x190);
}