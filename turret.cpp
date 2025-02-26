#include "turret.h"
#include "validate.h"


// @Ok
// @Matching
void Turret_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = Turret_RelocatableModuleClear;
	pMod->field_C[0] = Turret_CreateTurret;
}

// @SMALLTODO
void Turret_CreateTurret(const u32 *,u32 *)
{
    printf("Turret_CreateTurret(u32 const *,u32 *)");
}

// @SMALLTODO
void Turret_RelocatableModuleClear(void)
{
    printf("Turret_RelocatableModuleClear(void)");
}

// @Ok
void INLINE CTurret::TargetLockAbsolute(const CVector &a1){
	this->field_344 = a1;
	this->field_218 |= 4;
}

// @Ok
void INLINE CTurret::TargetLockDynamic(CBody *a2)
{
	if ( !a2->IsDead() )
	{
		this->field_378 = a2;
		this->field_218 |= 0x10u;
	}
}

// @Ok
void CTurretLaser::SetDamage(int damage)
{
	this->field_4C = damage;
}

// @Ok
void INLINE CTurret::ClearTargetLock(void)
{
	this->field_218 &= 0xFFFFFFE3;
}

void validate_CTurret(void)
{
	VALIDATE_SIZE(CTurret, 0x37C);

	VALIDATE(CTurret, field_324, 0x324);
	VALIDATE(CTurret, field_344, 0x344);
	VALIDATE(CTurret, field_378, 0x378);
}

void validate_CTurretBase(void)
{
		VALIDATE_SIZE(CTurretBase, 0xFC);
}

void validate_CTurretLaser(void)
{
		VALIDATE_SIZE(CTurretLaser, 0x64);

		VALIDATE(CTurretLaser, topPad, 0x3C);
		VALIDATE(CTurretLaser, field_4C, 0x4C);

}

