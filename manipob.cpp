#include "manipob.h"
#include "utils.h"
#include "validate.h"
#include "trig.h"
#include "mem.h"
#include "spool.h"
#include "baddy.h"

static i16 * const word_610C48 = (i16*)0x610C48;
extern const char *gObjFile;
extern CBody* EnvironmentalObjectList;

// @Ok
// @Matching
void CManipOb::GetAttachPoint(CVector *a2)
{
	*a2 = this->mPos + this->field_110;
}

// @Ok
// @AlmostMatching: vector assingment is zero based on the og for mVel
void CManipOb::Drop(CVector *a2)
{
	this->mFlags &= 0xF7FFu;
	this->field_10C |= 1u;
	this->field_10C &= 0xFFFFFFF7;

	this->mVel = *a2;

	this->mAcc.vy = 4096;
	this->mAngVel.vx = Rnd(32) + 64;
}

// @Ok
CManipOb::~CManipOb(void)
{
	this->DeleteFrom(&EnvironmentalObjectList);

	if (this->pVectors)
	{
		Mem_Delete(reinterpret_cast<void*>(this->pVectors));
		this->pVectors = 0;
	}
}

// @Ok
CManipOb::CManipOb(
		i16* a2,
		i32 a3)
{
	this->InitItem(gObjFile);
	this->AttachTo(&EnvironmentalObjectList);

	this->mFlags = this->mFlags & 0x0FFFD | 0x10;
	this->mType = 401;

	this->mNode = a3;

	this->mFric.vx = 12;
	this->mFric.vy = 12;
	this->mFric.vz = 12;

	u32* v6 = reinterpret_cast<u32*>(
			(reinterpret_cast<u32>(
								   this->SquirtAngles(reinterpret_cast<i16*>(this->SquirtPos(a2)))) + 3)
			& 0xFFFFFFFC);

	i32 *v8 = reinterpret_cast<i32*>(v6 + 1);
	this->mModel = Spool_GetModel(*v6, gObjFileRegion);

	if (*v8)
	{
		this->field_11C = Spool_FindEnviroItem(*v8++);
	}

	this->field_120 = reinterpret_cast<i32>(v8);

	i32 *v10 = v8;
	while (*v10++);

	u16 v12 = *reinterpret_cast<u16*>(v10);

	if (*reinterpret_cast<u16*>(v10) & 1)
		this->field_10C |= 8;


	if (v12 & 2)
	{
		this->field_10C |= 0x20;
	}

	this->field_108 = *(reinterpret_cast<u16*>(v10) + 1);
	this->field_104 = *(reinterpret_cast<u16*>(v10) + 2);

}

// @NotOk
// @Test
// Globals
void CManipOb::CalculateThrowPositionArray(CVector* pVector, int NumVectors)
{

	this->mNumVectors = NumVectors;

	i32 v15 = (pVector->vx - this->mPos.vx) / NumVectors;
	i32 v16 = (pVector->vy - this->mPos.vy) / NumVectors;
	i32 v1 = (pVector->vz - this->mPos.vz) / NumVectors;

	this->pVectors = reinterpret_cast<CVector*>(DCMem_New(12 * NumVectors, 0, 1, 0, 1));


	i32 v9 = v15 + this->mPos.vx;
	i32 v10 = v16 + this->mPos.vy;
	i32 v11 = v1 + this->mPos.vz;

	i32 v17 = 2048 / (this->mNumVectors - 1);
	i32 v14 = 0;

	i32 index = 0;
	while (index < this->mNumVectors)
	{
		this->pVectors[index].vx = v9;
		this->pVectors[index].vy = v10 - (word_610C48[2 * (v14 & 0xFFF)] << 8);
		this->pVectors[index].vz = v11;

		v9 += v15;
		v10 += v16;
		v11 += v1;
		v14 += v17;
		index++;
	}

	this->field_100 = 0;
}

// @Ok
void CManipOb::ThrowPos(CVector *a2, int a3)
{
	this->CalculateThrowPositionArray(a2, a3);

	this->mFlags &= 0xF7FF;
	this->field_10C |= 1;
	this->mAngVel.vx = Rnd(32) + 64;
}

// @Ok
void CManipOb::Throw(CVector *a2)
{
	this->mFlags &= 0xF7FF;
	this->field_10C |= 1;
	this->mVel = *a2;
	this->mAcc.vy = 4096;
	this->mAngVel.vx = Rnd(32) + 64;
}

// @NotOk
// Revisit because of weird decomp
void CManipOb::Smash(void)
{
	CVector v3;
	v3.vx = 0;
	v3.vy = 4096;
	v3.vz = 0;

	SLineInfo v4;
	v4.StartCoords.vx = 0;
	v4.StartCoords.vy = 0;
	v4.StartCoords.vz = 0;
	v4.EndCoords.vx = 0;
	v4.EndCoords.vy = 0;
	v4.EndCoords.vz = 0;

	v4.MinCoords.vx = 0;
	v4.MinCoords.vy = 0;
	v4.MinCoords.vz = 0;

	v4.MaxCoords.vx = 0;
	v4.MaxCoords.vy = 0;
	v4.MaxCoords.vz = 0;

	v4.Position.vx = 0;
	v4.Position.vy = 0;
	v4.Position.vz = 0;

	v4.Normal.vx = 0;
	v4.Normal.vy = (i16)0xF000;
	v4.Normal.vz = 0;

	this->mVel.vx = 0;
	this->mVel.vy = 0x20000;
	this->mVel.vz = 0x20000;

	this->Chunk(&v4, &v3);
	this->TurnOffShadow();
	this->SendPulse();

	this->Die();
}

// @BIGTODO
void CManipOb::Chunk(SLineInfo*, CVector*)
{
	printf("void CManipOb::Chunk(SLineInfo*, CVector*)");
}

// @Ok
INLINE void CManipOb::TurnOffShadow(void)
{
	CItem *v1 = this->field_11C;
	if (v1)
	{
		CItem *res = reinterpret_cast<CItem*>(PSXRegion[v1->mRegion].ppModels[v1->mModel]);
		res->mFlags |= 0x20;
	}
}

// @Ok
INLINE void CManipOb::SendPulse(void)
{
	if(!this->field_124)
	{
		this->field_124 = 1;
		Trig_SendPulseToNode(reinterpret_cast<i32>(Trig_GetLinksPointer(this->mNode)));
	}
}

// @Ok
void CManipOb::Pickup(void)
{
	this->mFlags |= 0x20;
	this->mFlags |= 0x800;

	this->TurnOffShadow();
	this->SendPulse();
}

void validate_CManipOb(void)
{
	VALIDATE_SIZE(CManipOb, 0x128);

	VALIDATE(CManipOb, mNumVectors, 0xF8);
	VALIDATE(CManipOb, pVectors, 0xFC);
	VALIDATE(CManipOb, field_100, 0x100);

	VALIDATE(CManipOb, field_104, 0x104);
	VALIDATE(CManipOb, field_108, 0x108);

	VALIDATE(CManipOb, field_10C, 0x10C);

	VALIDATE(CManipOb, field_110, 0x110);

	VALIDATE(CManipOb, field_11C, 0x11C);
	VALIDATE(CManipOb, field_120, 0x120);
	VALIDATE(CManipOb, field_124, 0x124);

	VALIDATE_VTABLE(CManipOb, Smash, 5);
}
