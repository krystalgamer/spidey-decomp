#include "bitmap256.h"
#include "validate.h"
#include <cstring>
#include <new>


// @Ok
// @Matching
Bitmap256::Bitmap256(
		char *a2,
		u16* a3,
		i32 a4,
		i32 a5,
		i32 a6)
{
	this->field_21C = a4;
	this->field_220 = a5;
	
	this->field_0 = new u8[this->field_21C * this->field_220];

	memcpy(this->field_0, a2, this->field_21C * this->field_220);
	memcpy(this->field_4, a3, sizeof(this->field_4));
	memset(this->field_204, 0, sizeof(this->field_204));
	this->field_204[5] = a6;
}

// @SMALLTODO
Bitmap256::~Bitmap256(void)
{
    printf("Bitmap256::~Bitmap256(void)");
}

void validate_Bitmap256(void)
{
	VALIDATE_SIZE(Bitmap256, 0x224);

	VALIDATE(Bitmap256, field_0, 0x0);
	VALIDATE(Bitmap256, field_4, 0x4);
	VALIDATE(Bitmap256, field_204, 0x204);
	VALIDATE(Bitmap256, field_21C, 0x21C);
	VALIDATE(Bitmap256, field_220, 0x220);
}
