#include "backgrnd.h"
#include "ob.h"

static CSuper* BackgroundList;

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
