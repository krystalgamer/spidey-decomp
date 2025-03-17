#include "chain.h"
#include "mem.h"

#include "validate.h"

// @MEDIUMTODO
void CChain::Move(CVector *pVec)
{
	this->field_4->field_18 = this->field_4->field_0;
	this->field_4->field_0 = *pVec;

	this->field_4->field_C = *pVec - this->field_4->field_18;

	for (i32 i = 1; i < this->field_8; i++)
	{
		this->field_4[i].field_18 = this->field_4[i].field_0;

		this->field_4[i].field_C = (this->field_4[i].field_C * this->field_20) >> 12;
		this->field_4[i].field_C.vy = this->field_14;

		this->field_4[i].field_0 += this->field_4[i].field_C;
		if ( this->field_1C )
		{
			if (this->field_4[i].field_0.vy > this->field_18)
			{
				this->field_4[i].field_0.vy = this->field_18;
				this->field_4[i].field_C.vy = 0;
			}
		}
	}

	for (i32 j = 1; j < this->field_8; j++)
	{
		CVector v12 = this->field_4[j].field_0 - this->field_4[j-1].field_0;
	}

}

// @NotOk
// @Test
CChain::CChain(
		CVector* a2,
		i32 a3,
		i32 a4,
		i32 a5,
		i32 a6,
		i32 a7)
{ 
	this->field_8 = a3;
	SChainData* v8 = static_cast<SChainData*>(DCMem_New(sizeof(SChainData) * a3, 0, 1, 0, 1));
	this->field_4 = v8;
	this->field_C = a4;
	this->field_10 = a4 * a4;
	this->field_14 = a5;
	this->field_24 = a7;
	this->field_20 = a6;

	for (i32 i = 0; i < this->field_8; i++)
	{
		v8[i].field_24 = i == 0;
		v8[i].field_0 = a2[i];

		v8[i].field_18 = v8[i].field_0;

		v8[i].field_C.vz = 0;
		v8[i].field_C.vy = 0;
		v8[i].field_C.vx = 0;
	}
}

// @Ok
CChain::~CChain(void)
{
	if (this->field_4)
		Mem_Delete(this->field_4);
}

// @Ok
void CChain::SetGroundY(i32 a2)
{
	this->field_1C = 1;
	this->field_18 = a2;
}

void validate_CChain(void)
{
	VALIDATE_SIZE(CChain, 0x28);

	VALIDATE(CChain, field_4, 0x4);
	VALIDATE(CChain, field_8, 0x8);
	VALIDATE(CChain, field_C, 0xC);
	VALIDATE(CChain, field_10, 0x10);
	VALIDATE(CChain, field_14, 0x14);
	VALIDATE(CChain, field_18, 0x18);
	VALIDATE(CChain, field_1C, 0x1C);
	VALIDATE(CChain, field_20, 0x20);
	VALIDATE(CChain, field_24, 0x24);
}

void validate_SChainData(void)
{
	VALIDATE_SIZE(SChainData, 0x28);

	VALIDATE(SChainData, field_0, 0x0);
	VALIDATE(SChainData, field_C, 0xC);
	VALIDATE(SChainData, field_18, 0x18);
	VALIDATE(SChainData, field_24, 0x24);
}
