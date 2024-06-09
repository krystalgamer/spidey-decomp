#include "thug.h"
#include "validate.h"
#include "trig.h"
#include "m3dutils.h"

// @NotOk
// Globals
// also a little out of order with the v6 | 1 thing :(
CThug::CThug(int *a2, int a3)
{
	__int16 *v5 = this->SquirtAngles(reinterpret_cast<__int16*>(this->SquirtPos(a2)));

	this->field_3B8 = Trig_GetLevelId();

	this->ShadowOn();
	this->field_D0 = 50;
	this->field_3B0 = *dword_5FCCF4;
	this->AttachTo(reinterpret_cast<CBody**>(0x56E990));

	int v6 = this->field_2A8;
	this->field_1F4 = a3;
	this->field_DE = a3;

	__int16 v7 = this->field_38;
	this->field_230 = 0;
	this->field_216 = 32;
	this->field_2A8 = v6 | 1;

	this->field_DC = v7 != 304 ? 150 : 96;
	this->field_D8 = 64;
	this->field_380 = v7 != 304 ? 400 : 300;
	this->field_31C.bothFlags = 0;


	this->field_370 = 3500;
	this->field_374 = 400;
	this->field_378 = 2047;
	this->field_37C = 100;
	this->field_384 = 1500;
	this->field_388 = 10;
	this->field_38C = 10;

	this->field_1FC = 10;
	this->field_394 = 2000;
	this->ParseScript(reinterpret_cast<unsigned __int16*>(v5));
	this->field_212 = 60;
}

// @Ok
void Thug_CreateTHug(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CThug(v2, v3));
}

// @Ok
void __inline CThugPing::SetPosition(void)
{
	CSuper* v2 = reinterpret_cast<CSuper*>(Mem_RecoverPointer(&this->field_70));

	if (!v2)
		this->Die();
	else
		M3dUtils_GetDynamicHookPosition(
				reinterpret_cast<VECTOR*>(&this->mPos),
				v2,
				&this->field_78);
}

// @Ok
void CThugPing::Move(void)
{
	this->SetPosition();
	Bit_ReduceRGB(&this->mCodeBGR, 7);

	if ((this->mCodeBGR & 0xFFFFFF) == 0)
		this->Die();
}

static CThug* gGlobalThug;
static unsigned char gAttackFlagRelated;

// @Ok
void CThug::ClearAttackFlags(void)
{

	if ( gGlobalThug == this )
	{
		gGlobalThug = 0;
	}
	else if (this->field_3BC & 2)
	{
		gAttackFlagRelated &= ~this->field_3BD;
	}

	this->field_3BC = 0;
	this->field_3BD = 0;
}

static i32 gThugTypeRelatedFirstFirst;
static i32 gThugTypeRelatedFirstSecond;
static u8 gThugTypeRelatedFirstThird;

static i32 gThugTypeRelatedSecondFirst;
static i32 gThugTypeRelatedSecondSecond;
static u8 gThugTypeRelatedSecondThird;

// @NotOk
// globals
void CThug::SetThugType(int type)
{
	this->field_38 = type;
	switch (type)
	{
		case 304:
			this->InitItem("thug");
			this->field_21E = 100;

			this->field_294.Int = gThugTypeRelatedFirstFirst;
			this->field_298.Int = gThugTypeRelatedFirstSecond;
			M3dUtils_ReadHooksPacket(this, &gThugTypeRelatedFirstThird);

			break;
		case 312:
			if (Trig_GetLevelId() == 513)
				this->InitItem("henchngt");
			else
				this->InitItem("henchman");

			this->field_294.Int = gThugTypeRelatedSecondFirst;
			this->field_298.Int = gThugTypeRelatedSecondSecond;
			M3dUtils_ReadHooksPacket(this, &gThugTypeRelatedSecondThird);
			break;
		default:
			print_if_false(0, "Unknown thug type!");
	}

}

void validate_CThug(void){

	VALIDATE_SIZE(CThug, 0x3C0);

	VALIDATE(CThug, field_370, 0x370);
	VALIDATE(CThug, field_374, 0x374);
	VALIDATE(CThug, field_378, 0x378);
	VALIDATE(CThug, field_37C, 0x37C);
	VALIDATE(CThug, field_380, 0x380);
	VALIDATE(CThug, field_384, 0x384);
	VALIDATE(CThug, field_388, 0x388);
	VALIDATE(CThug, field_38C, 0x38C);

	VALIDATE(CThug, field_394, 0x394);
	VALIDATE(CThug, field_3B0, 0x3B0);
	VALIDATE(CThug, field_3B8, 0x3B8);

	VALIDATE_SIZE(IntToBytes, 0x4);
}

void validate_CThugPing(void)
{
	VALIDATE_SIZE(CThugPing, 0x80);

	VALIDATE(CThugPing, field_70, 0x70);
	VALIDATE(CThugPing, field_78, 0x78);
}
