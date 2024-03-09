#include "torch.h"
#include "export.h"
#include "validate.h"


void validate_CTorch(void){
	VALIDATE_SIZE(CTorch, 0x354);

	VALIDATE(CTorch, field_324, 0x324);
	VALIDATE(CTorch, field_328, 0x328);
	VALIDATE(CTorch, field_32C, 0x32C);
	VALIDATE(CTorch, field_330, 0x330);
	VALIDATE(CTorch, field_334, 0x334);
	VALIDATE(CTorch, field_338, 0x338);


	VALIDATE(CTorch, gTorchQuadBit, 0x33C);

	VALIDATE(CTorch, field_340, 0x340);
	VALIDATE(CTorch, field_344, 0x344);
	VALIDATE(CTorch, field_348, 0x348);

	VALIDATE(CTorch, field_34C, 0x34C);
	VALIDATE(CTorch, field_350, 0x350);


}