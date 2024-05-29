#include "lizman.h"
#include "validate.h"



// @Ok
void __inline CLizMan::PlaySingleAnim(__int16 a1, int a2, int a3)
{
	this->field_340 = 0;
	this->RunAnim(a1, a2, a3);
}

// @Ok
void __inline CLizMan::StandStill(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->Neutralize();
			this->PlaySingleAnim(19, 0, -1);
			this->dumbAssPad++;
			break;
		case 1:
			print_if_false(0, "Unknown substate.");
			break;
	}
}

// @TODO
void CLizMan::SwitchFromMatrixToEuler(void)
{}

// @Ok
void CLizMan::StopClimbing(void)
{
	this->SwitchFromMatrixToEuler();
	this->field_390 = 0;
}

// @TODO
void CLizMan::FlyAcrossRoom(void)
{
	switch(this->dumbAssPad)
	{
		case 3:
			if (this->IsSafeToSwitchToFollowWaypoints())
			{
				this->field_31C.bothFlags = 2;
			}
			else
			{
				this->field_31C.bothFlags = 1;
			}
			this->dumbAssPad = 0;

	}
}

// @Ok
int __inline CLizMan::IsSafeToSwitchToFollowWaypoints(void)
{
	if (this->field_1F0 || this->field_1F4 > 0)
		return 1;
	return 0;
}

void validate_CLizMan(void){
	VALIDATE_SIZE(CLizMan, 0x3B8);


	VALIDATE(CLizMan, field_328, 0x328);
	VALIDATE(CLizMan, field_32C, 0x32C);
	VALIDATE(CLizMan, field_338, 0x338);
	VALIDATE(CLizMan, field_340, 0x340);

	VALIDATE(CLizMan, field_374, 0x374);
	VALIDATE(CLizMan, field_390, 0x390);
	VALIDATE(CLizMan, field_398, 0x398);
	VALIDATE(CLizMan, field_3AC, 0x3AC);
}
