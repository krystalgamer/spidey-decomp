#include "backgrnd.h"
#include "spool.h"

#include "validate.h"

CSuper* BackgroundList;
EXPORT i16 gBackgroundIndex = 0;

// @Ok
// @Matching
void CBackground::AI(void)
{
	this->mAngles += this->csVector1;
}

// @Ok
// @Matching
CBackground::CBackground(
		u32 checksum,
		CSVector* ang_vel)
{
	this->InitItem(gObjFile);
	this->mModel = Spool_GetModel(checksum, this->mRegion);
	this->mFlags &= ~2u;
	this->mCBodyFlags &= ~2u;
	this->field_38 = 502;
	this->AttachTo(reinterpret_cast<CBody**>(&BackgroundList));
	this->field_F8 = gBackgroundIndex++;
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

	VALIDATE(CBackground, field_F8, 0xF8);
}
