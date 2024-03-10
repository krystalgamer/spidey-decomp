#include "ps2funcs.h"
#include "validate.h"

static MATRIX gRotMatrix;

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