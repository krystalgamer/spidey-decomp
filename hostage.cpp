#include "hostage.h"
#include "validate.h"


// @Ok
void __inline CHostage::DisappearBitch(void)
{
	switch (this->dumbAssPad)
	{
		case 2:
			if (this->Die(2))
			{
				this->Die(3);
				this->dumbAssPad++;
			}
			else
			{
				this->SetHeight(0, 100, 600);
			}
			break;
		case 0:
			this->Neutralize();
			this->dumbAssPad++;
		case 1:
			this->mCBodyFlags &= 0xFFEF;
			this->field_2A8 |= 0x5000;
			this->field_DC = 0;
			this->Die(1);
			this->dumbAssPad++;
			break;
		case 3:
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @Ok
void __inline CHostage::GetUp(void)
{
	switch(this->dumbAssPad)
	{
		case 0:
			this->RunAnim(2, 0, -1);
			this->dumbAssPad++;
			break;
		case 1:
			if (this->field_142)
			{
				if (this->GetNextWaypoint())
				{
					this->field_324 = 2;
					this->dumbAssPad = 0;
				}
				else
				{
					this->field_324 = 5;
					this->dumbAssPad = 1;
				}
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

CHostage::CHostage(int* a2, int a3)
{
	__int16 *afterAngles = this->SquirtAngles(reinterpret_cast<__int16*>(this->SquirtPos(a2)));

	this->AttachTo(reinterpret_cast<CBody**>(0x56E9900));
	this->ShadowOn();

	int v6 = this->field_2A8 | 1;

	this->field_D0 = 48;
	this->field_1F4 = a3;
	this->field_DE = a3;
	this->field_DC = 128;
	this->field_230 = 0;
	this->field_216 = 32;

	this->field_D8 = 64;
	this->field_324 = 0;

	this->field_2A8 = v6;

	unsigned char * ptr = reinterpret_cast<unsigned char*>(0x551FF0);
	this->field_294.Bytes[0] = ptr[0];
	this->field_294.Bytes[1] = ptr[1];
	this->field_294.Bytes[2] = ptr[2];
	this->field_294.Bytes[3] = ptr[3];

	this->field_298.Bytes[0] = ptr[4];
	this->field_298.Bytes[1] = ptr[5];
	this->field_298.Bytes[2] = ptr[6];
	this->field_298.Bytes[3] = ptr[7];

	this->mCBodyFlags &= 0xFFEF;
	this->ParseScript(reinterpret_cast<unsigned __int16*>(afterAngles));
}

// @Ok
void Hostage_CreateHostage(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CHostage(v2, v3));
}

void validate_CHostage(void){
	VALIDATE_SIZE(CHostage, 0x334);


	VALIDATE(CHostage, field_324, 0x324);
	VALIDATE(CHostage, field_328, 0x328);
	VALIDATE(CHostage, field_32C, 0x32C);
}
