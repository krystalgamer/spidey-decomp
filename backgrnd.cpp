#include "backgrnd.h"

#include "validate.h"

EXPORT CSuper* BackgroundList;
EXPORT i16 gBackgroundIndex = 0;

// @SMALLTODO
void CBackground::AI(void)
{
    printf("CBackground::AI(void)");
}

// @SMALLTODO
CBackground::CBackground(u32, CSVector*)
{
	printf("CBackground::CBackground(u32, CSVector*)");
}

// @Ok
CBackground::~CBackground(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&BackgroundList));
	print_if_false(gBackgroundIndex != 0, "Background index error");
	--gBackgroundIndex;
}

// @NotOk
// global
void Backgrnd_On(unsigned __int16 a1)
{

	CSuper* cur = BackgroundList;
	if (cur)
	{
		while (cur)
		{
			if (cur->field_F8 != a1)
			{
				cur = reinterpret_cast<CSuper*>(cur->field_20);
			}
			else
			{
				cur->mFlags &= 0xFFFE;
				break;
			}
		}
	}
}

// @NotOk
// global
void Backgrnd_Off(unsigned __int16 a1)
{

	CSuper* cur = BackgroundList;
	if (cur)
	{
		while (cur)
		{
			if (cur->field_F8 != a1)
			{
				cur = reinterpret_cast<CSuper*>(cur->field_20);
			}
			else
			{
				cur->mFlags |= 1;
				break;
			}
		}
	}
}

void validate_CBackground(void)
{
	VALIDATE_SIZE(CBackground, 0xFC);
}
