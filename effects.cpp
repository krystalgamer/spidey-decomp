#include "effects.h"
#include "validate.h"

// @TODO
CElectrify::CElectrify(CSuper*, int)
{
}

extern int CurrentSuit;

// @Ok
void __inline Effects_UnElectrify(CSuper* pSuper)
{
	print_if_false(pSuper != 0, "NULL pSuper?");

	CItem *v2 = reinterpret_cast<CItem*>(Mem_RecoverPointer(&pSuper->field_114));
	if (v2)
		delete v2;
}

// @NotOk
// globals
void Effects_Electrify(CSuper* pSuper)
{
	print_if_false(pSuper != 0, "NULL pSuper?");
	Effects_UnElectrify(pSuper);

	if (pSuper->field_38 == 50)
	{
		if (CurrentSuit != 4)
		{
			new CElectrify(pSuper, 10);
		}
	}
	else
	{
		new CElectrify(pSuper, 20);
	}
}

void validate_CElectrify(void)
{
	VALIDATE_SIZE(CElectrify, 0x64);
}
