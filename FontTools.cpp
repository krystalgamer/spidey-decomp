#include "FontTools.h"
#include "validate.h"

// @Ok
int Font::isEscapeChar(char a1)
{
	if (a1 == ']')
		return 254;
	else if (a1 == '[')
		return 253;
	else if (a1 == '}')
		return 254;
	else if (a1 == '{')
		return 252;
	else if (a1 == '>')
		return 254;
	else if (a1 == '<')
		return 251;
	else if (a1 == '|')
		return 249;
	else if (a1 == '~')
		return 248;

	return ((a1 != 0x5E) - 1) & 0x000000FA;
}

// @Ok
int __inline Font::GetCharMap(void)
{
	return this->field_58;
}

void validate_Font(void)
{
	VALIDATE_SIZE(Font, 0x5C);

	VALIDATE(Font, field_58, 0x58);
}
