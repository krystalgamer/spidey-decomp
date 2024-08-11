#include "dcshellutils.h"
#include "validate.h"

// @SMALLTODO
Sprite2::Sprite2(const char*, i32, i32, i32, u32)
{
	printf("Sprite2::Sprite2(const char*, i32, i32, i32, u32)");
}

// @BIGTODO
void Load8BitBMP2(char *a1, char **a2, int *a3, int *a4, unsigned __int16 *a5, bool a6)
{

	printf("void Load8BitBMP2(char *a1, char **a2, int *a3, int *a4, unsigned __int16 *a5, bool a6)");
}

void validate_Sprite2(void)
{
	VALIDATE_SIZE(Sprite2, 0x24);
}
