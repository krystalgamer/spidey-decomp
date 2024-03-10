#include "ps2funcs.h"
#include "validate.h"

static MATRIX gRotMatrix;
static int vertexRegister[3];


void validate_MATRIX(void){
	VALIDATE_SIZE(MATRIX, 0x20);
	VALIDATE(MATRIX, m, 0x0);
	VALIDATE(MATRIX, t, 0x14);
}

void gte_SetRotMatrix(MATRIX* a1){

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			gRotMatrix.m[i][j] = a1->m[i][j];
		}
	}
}

void gte_ldv0(const SVECTOR* a1){
	vertexRegister[0] = a1->vx;
	vertexRegister[1] = a1->vy;
	vertexRegister[2] = a1->vz;
}