#include "bit2.h"
#include "validate.h"


void validate_CGPolyLine(void){
	VALIDATE_SIZE(CGPolyLine, 0x58);

	VALIDATE(CGPolyLine, field_40, 0x40);
	VALIDATE(CGPolyLine, field_44, 0x44);

	VALIDATE(CGPolyLine, field_50, 0x50);
	VALIDATE(CGPolyLine, field_51, 0x51);
	VALIDATE(CGPolyLine, field_52, 0x52);
	VALIDATE(CGPolyLine, field_53, 0x53);

	VALIDATE(CGPolyLine, field_57, 0x57);
}
