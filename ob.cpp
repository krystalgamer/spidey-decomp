#include "ob.h"
#include "mem.h"
#include "spool.h"
#include <cstring>
#include "validate.h"
#include "ps2redbook.h"
#include "ps2m3d.h"
#include "m3dutils.h"
#include "spool.h"

u32 SuspendedDistance;
u8 gPsxItemsIndex;
const char *gObjFile;
CBody* EnvironmentalObjectList;
CBody* SuspendedList;
CItem* EnviroList;

void CBody::DeleteStuff(void)
{
	printf("CBody::DeleteStuff");
}

// @Ok
CBody* CBody::FindBodyByNode(
		i32 type,
		CBody* pBody)
{
	for (CBody *cur = pBody; cur; cur = reinterpret_cast<CBody*>(cur->field_20))
	{
		if (cur->field_DE == type)
			return cur;
	}

	return 0;
}

// @Ok
// Random move from global to eax and test eax, eax that doesn't change shit
void* CItem::operator new(size_t size) {

  void *result = DCMem_New(size, 0, 1, 0, 1);

  unsigned int adjusted_size = ((size + 3) & 0xFFFFFFFC) >> 2;
  if ( adjusted_size )
    memset(result, 0, 4 * adjusted_size);

  return result;
}

// @Ok
void CItem::operator delete(void *ptr)
{
	Mem_Delete(ptr);
}


/// @NotOk
// missing 3C assignement need to understand what it is
__inline CItem::CItem()
{
	this->mPos.vx = 0;
	this->mPos.vy = 0;
	this->mPos.vz = 0;


	this->mAngles.vx = 0;
	this->mAngles.vy = 0;
	this->mAngles.vz = 0;

	//this->field_2C = 0;

	this->field_28 = 0x1000;
	this->field_2A = 0x1000;
	this->field_2C = 0x1000;

	///this->field_3C = ???;
}

// @Ok
// First part is for delete[]
// second is for delete, nothing to do
INLINE CItem::~CItem()
{
}

// @Ok
void CBody::AI(void)
{
}

// @Ok
int CBody::Hit(SHitInfo*)
{
	return 1;
}

// @Ok
void CItem::InitItem(const char * a1)
{

	int Region = Spool_FindRegion(a1);
	this->mRegion = Region;
	this->mModel = 0;


	if (PSXRegion[Region].Filename[9])
	{
		u32 *tmp = *reinterpret_cast<u32**>(PSXRegion[Region].ppModels);
		tmp[2] = 0x64000;
		tmp[3] = 0xFF9C0064;
		tmp[4] = 0xFF9C0064;
		tmp[5] = 0xFF9C0064;
	}
}



// @Ok
// has weird xor eax, eax at the top
int __inline CBody::IsDead(void) const{
	return (this->mCBodyFlags >> 6) & 1;
}
	


// @Ok
void CBody::Die(void){
	int isDead = this->IsDead();
	if(!isDead)
	{
		this->mCBodyFlags |= 0x40;
	}
}

// @Ok
void CBody::ShadowOn(void){
	this->mCBodyFlags |= 8;
}


// @NotOk
// dessutrctor
void __inline CBody::KillShadow(void){

  this->mCBodyFlags &= ~8u;
  if ( this->bodyQuadBit )
  {
    //result = (**somethingWithVtableDestructor)(somethingWithVtableDestructor, 1);
    this->bodyQuadBit = 0;
  }
}

// @NotOk
// Inlined KillShadow and weird part where we store data but it's just xor eax, eax
void CBody::UpdateShadow(void){

	__int16 flags = this->mCBodyFlags;

	if(flags & 8){

		if(!this->bodyQuadBit){

			CQuadBit *quad = new CQuadBit();
			this->bodyQuadBit = quad;

			quad->SetTexture(0, 0);
			this->bodyQuadBit->SetSubtractiveTransparency();
			this->bodyQuadBit->mFrigDeltaZ = 32;
			this->bodyQuadBit->mProtected = 1;
		}

		SVector vec;
		vec.vx = 0;
		vec.vy = -4096;
		vec.vz = 0;

		unsigned __int16 lastParam = this->field_D0;
		this->bodyQuadBit->OrientUsing(&this->bodyVector, reinterpret_cast<SVECTOR*>(&vec), lastParam, lastParam);


		__int8 trans = ((this->field_D4 - this->field_D2) << 7) / this->field_D4;

		if(trans < 0){
			trans = 0;
		}

		this->bodyQuadBit->SetTransparency(trans);

	}
	else{
		   this->KillShadow();
	}

}


// @Ok
void __inline CBody::AttachTo(CBody** a1)
{

	CBody *v2 = *a1;
	this->field_34 = 0;
	this->field_20 = v2;

	*a1 = this;

	CItem *v3 = this->field_20;
	if (v3)
		v3->field_34 = this;

}

// @NotOk
// remove constants
void __inline CBody::DeleteFrom(CBody **a2)
{

	if(this->mCBodyFlags & 1 && a2 != reinterpret_cast<CBody**>(0x60DAB4))
	{
		this->UnSuspend();
	}

	CItem *v6 = this->field_20;
	if (v6)
		v6->field_34 = this->field_34;

	CItem *r = this->field_34;
	if (r)
		r->field_20 = this->field_20;

	if (*a2 == this)
		*a2 = reinterpret_cast<CBody*>(this->field_20);
}

// @NotOk
// looks good, but I think the constants are fucking it up
void __inline CBody::UnSuspend(void)
{

	if (this->mCBodyFlags & 1)
	{
		this->DeleteFrom(reinterpret_cast<CBody**>(0x60DAB4));
		this->AttachTo(this->field_40);
		this->mCBodyFlags &= 0xFFFE;
	}
}

// @NotOk
// removed constants
void CBody::Suspend(CBody **a2)
{
	print_if_false((this->mCBodyFlags & 1) == 0, "Suspended flag illegally set");
	print_if_false(a2 != 0, "woops");

	this->DeleteStuff();

	this->field_40 = a2;
	this->DeleteFrom(a2);

	this->AttachTo(reinterpret_cast<CBody**>(0x60DAB4));
	this->mCBodyFlags |= 1;
}




// @Ok
void CBody::InterleaveAI(void)
{
	if (this->mFlags & 2)
	{
		this->EveryFrame();
		CSuper *super = reinterpret_cast<CSuper*>(this);
		super->UpdateFrame();
	}
	else
	{
		this->EveryFrame();
	}

	this->AI();
}

// @Ok
// @Test
i16* CBody::SquirtPos(i16* p_info)
{
	i32 *walker = reinterpret_cast<i32*>(p_info);
	print_if_false(((i32)walker & 3) == 0, "Bad alignment");

	this->mPos.vx = *walker++ << 12;

	this->mPos.vy = *walker++ << 12;

	this->mPos.vz = *walker++ << 12;

	return reinterpret_cast<i16*>(walker);
}

// @FIXME
// this should be deleted
i16* CBody::SquirtPos(i32 *params)
{
	return this->SquirtPos(reinterpret_cast<i16*>(params));
}

// @Ok
i16* CBody::SquirtAngles(i16* p_info)
{
	this->mAngles.vx = *p_info++;
	this->mAngles.vy = *p_info++;
	this->mAngles.vz = *p_info++;

	return p_info;
}

static int * const dword_6B4CA0 = (int*)0x6B4CA0;

// @NotOk
// replace dword_
void CBody::AttachXA(int a2, int a3)
{
	this->field_98 = *dword_6B4CA0;
	this->field_9C = a2;
	this->field_A0 = a3;
}

static int * const dword_681D1C = (int*)0x681D1C;
static int * const dword_6612C0 = (int*)0x6612C0;

// @NotOk
// Replace dword_
void CBody::StopMyXA(void)
{
	if ( (unsigned int)(*dword_6B4CA0 - this->field_98) < 0x12C
			&& *dword_681D1C == this->field_9C
			&& *dword_6612C0 == this->field_A0)
	{
		Redbook_XAStop();
	}
}

// @NotOk
// field reassignement + missing vtable
// need to understand whether the default constructor is called by default and then overriden
CBody::CBody()
{
	this->field_48 = 0;
	this->field_4C = 0;
	this->field_50 = 0;
	this->field_54 = 0;
	this->field_58 = 0;
	this->field_5C = 0;

	this->mAccellorVel.vx = 0;
	this->mAccellorVel.vy = 0;
	this->mAccellorVel.vz = 0;


	this->gVec.vx = 0;
	this->gVec.vy = 0;
	this->gVec.vz = 0;

	this->field_78 = 0;
	this->field_79 = 0;
	this->field_7A = 0;


	this->csVector1.vx = 0;
	this->csVector1.vy = 0;
	this->csVector1.vz = 0;

	this->field_8E.vx = 0;
	this->field_8E.vy = 0;
	this->field_8E.vz = 0;

	this->field_94 = 0;
	this->field_95 = 0;
	this->field_96 = 0;

	this->field_A8.vx = 0;
	this->field_A8.vy = 0;
	this->field_A8.vz = 0;

	this->bodyVector.vx = 0;
	this->bodyVector.vy = 0;
	this->bodyVector.vz = 0;

	this->field_C4 = 0;
	this->field_C6 = 0;
	this->field_C8 = 0;

	this->field_E8.vx = 0;
	this->field_E8.vy = 0;
	this->field_E8.vz = 0;

	this->field_78 = 1;
	this->field_79 = 1;
	this->field_7A = 1;

	this->field_94 = 1;
	this->field_95 = 1;
	this->field_96 = 1;
	this->mCBodyFlags |= 0x16;

	this->field_D8 = 10;
	this->field_A4 = 0;
	this->field_DE = -1;
	this->field_D0 = 32;
	this->field_D4 = 200;
}

// @NotOk
// code is matching but make sure vtable is also
CSuper::CSuper()
{
	this->mFlags |= 2u;
	this->gAnim = 1;
	this->field_142 = 1;
	//this->cbody.citem.vtable = (int)&off_53BBE8;
	this->csuperend = 0x10000;
	this->field_13E = 100;
	this->field_13F = 94;
}

// @Ok
void CSuper::OutlineOff(void){
	this->outlineRelated &= 0xFFFFFFFB;
}

// @NotOk
// Missing most stuff, only used by CVenom and CDummy
void CSuper::OutlineOn(void){
	this->outlineRelated |= 4;
	if (!this->field_11C){
	}

	this->outlineR = -1;
	this->outlineG = -1;
	this->outlineB = -1;
	this->alsoOutlineRelated = 0x50000000;
}


// @Ok
void CSuper::SetOutlineSemiTransparent(){
	this->alsoOutlineRelated |= 0x20000000;
}


// @Ok
void CSuper::SetOutlineRGB(unsigned char a2, unsigned char a3, unsigned char a4){
	this->outlineR = a2;
	this->outlineG = a3;
	this->outlineB = a4;
}

// @Ok
// Slightly different register allocation, edx and eax are swapped
void CSuper::UpdateFrame(void){
	char v1; // bl
	int v2; // esi
	int v3; // edx
	int v4; // eax
	int v5; // edx
	int v6; // eax
	unsigned __int16 v7; // dx


	if ( !this->field_80 )
	  this->field_80 = 2;
	v1 = this->field_141;
	v2 = this->field_80 * this->csuperend / 2;
	v3 = (unsigned __int16)this->field_146 | (this->field_128 << 16);
	if ( this->field_141 == 1 )
	  v3 += v2;
	if ( v1 == -1 )
	  v3 -= v2;
	v4 = v3;
	this->field_146 = v3;
	v5 = (unsigned __int8)this->field_140;
	v6 = v4 >> 16;
	this->field_128 = v6;

	if (v5) {
		if ( --v5 == 0)
		{
		  v7 = this->gAnim;
		  if ( (__int16)v6 >= (int)v7 )
		  {
			  this->field_128 = v6 - v7;
        
		  }
		  else
		  {

			if ( (__int16)(v6) < 0 )
			  this->field_128 = v6 + v7;
		  }
		}
	}
	else if( (this->field_141 == 1 && (__int16)v6 >= this->field_144)
		||
		(v1 == -1 && (__int16)v6 <= this->field_144)
		){
		this->field_128 = this->field_144;
		this->field_142 = 1;
	}
}


// @NotOk
// Revisit
void CSuper::CycleAnim(int a2, char a3){
  if (this->field_12A != a2 )
  {
    this->field_128 = 0;
	this->field_146 = 0;
	this->field_12A = a2;
    int mRegion = (unsigned __int8)this->mRegion;

	print_if_false(
      (unsigned int)(unsigned __int16)a2 < *(unsigned int *)Animations[17 * mRegion],
      "Bad anim sent to CycleAnim");
    this->gAnim = *(__int16 *)(Animations[17 * (unsigned __int8)this->mRegion]
                           + 8 * (unsigned __int16)this->field_12A
                           + 8);

    
    this->field_141 = a3;
  }
  this->field_140 = 1;
  this->field_142 = 0;
}


// @Ok
void CSuper::ApplyPose(__int16 *a2){

	if (!this->field_188)
	{
		M3dUtils_ReadLinksPacket(this, reinterpret_cast<void*>(a2));
		this->actualcsuperend = a2;
	}

	M3dUtils_InBetween(this);

	if ((this->mFlags & 4) != 0)
	{
		M3d_BuildTransform(this);
		M3dUtils_BuildPose(this);
	}
}


// @NotOk
// slightly different register allocation
// relies on global Animations
void CSuper::RunAnim(
		i32 a2,
		i32 a3,
		i32 a4)
{
	int mRegion; // ecx
	unsigned __int16 v6; // dx
	int v7; // eax
	int v8; // ecx
	char v9; // dl

	mRegion = this->mRegion;
	this->field_12A = a2;

	print_if_false((unsigned int)a2 < *(unsigned int *)Animations[17 * mRegion], "Bad anim sent to RunAnim");
	v6 = *(unsigned __int16 *)(Animations[17 * (unsigned char)this->mRegion] + 8 * (unsigned __int16)this->field_12A + 8);
	v7 = a3;
	this->gAnim = v6;
	if ( a3 == -1 )
		v7 = v6 - 1;
	v8 = a4;
	if ( a4 == -1 )
		v8 = v6 - 1;
	if ( v7 < 0 || v7 >= v6 )
		v7 = 0;
	if ( v8 < 0 || v8 >= v6 )
		v8 = 0;
	this->field_140 = 0;

	if ( v8 > v7 )
		v9 = 1;
	else
		v9 = (v8 >= v7) - 1;

	this->field_144 = v8;
	this->field_141 = v9;
	this->field_128 = v7;
	this->field_146 = 0;
	this->field_142 = (unsigned __int16)v7 == (unsigned __int16)v8;
}

// @NotOk
// timerRelated needs to be fixed and call to print_if_false looks wrong
void CBody::EveryFrame(void)
{
	int v3; // edx
	int v4; // ecx
	__int16 v6; // ax
	__int16 v7; // cx
	char v8; // dl
	bool v9; // [esp-8h] [ebp-Ch]

	if ( (this->mCBodyFlags & 4) != 0 )
	{
		this->field_80 = 2;
		this->mCBodyFlags &= 0xFFFB;
		this->field_7C = gTimerRelated;
		this->field_84 = 0;
	}
	else
	{
		v3 = this->field_7C;
		v9 = gTimerRelated - v3 >= 0;
		this->field_80 = gTimerRelated - v3;
		print_if_false(v9, "Timing error");
		v4 = this->field_80;
		this->field_7C = gTimerRelated;
		if ( v4 > 6 )
		this->field_80 = 6;
	}

	this->field_84 += this->field_80;
	if ( (this->mFlags & 2) != 0 )
	{
		CSuper *super = reinterpret_cast<CSuper*>(this);
		v6 = super->field_128;
		v7 = super->field_12A;
		v8 = super->field_141;
		super->field_152 = v6;
		super->field_150 = v6;
		super->field_154 = v7;
		super->field_143 = v8;
	}

}

// @Ok
INLINE CBody::~CBody(void)
{
	if (this->bodyQuadBit)
		delete this->bodyQuadBit;
}

// @Ok
CSuper::~CSuper(void)
{
	if (this->field_184)
		Mem_Delete(this->field_184);

	if (this->field_188)
		Mem_Delete(this->field_188);

	if (this->field_134)
		Mem_Delete(this->field_134);

	if (this->field_130)
		Mem_Delete(this->field_130);

	CItem *first = reinterpret_cast<CItem*>(
			Mem_RecoverPointer(&this->field_104));

	if (first)
		delete first;

	CItem *second = reinterpret_cast<CItem*>(
			Mem_RecoverPointer(&this->field_10C));

	if (second)
		delete second;

	if (this->field_11C)
		Mem_Delete(this->field_11C);

	this->field_11C = 0;
}

void validate_CItem(void){

	VALIDATE_SIZE(CItem, 0x40);

	VALIDATE(CItem, mFlags, 0x4);
	VALIDATE(CItem, field_6, 0x6);
	VALIDATE(CItem, mPos, 0x8);
	VALIDATE(CItem, mAngles, 0x14);
	VALIDATE(CItem, mModel, 0x1A);
	VALIDATE(CItem, mRegion, 0x1F);

	VALIDATE(CItem, field_20, 0x20);


	VALIDATE(CItem, field_24, 0x24);
	VALIDATE(CItem, field_28, 0x28);
	VALIDATE(CItem, field_2A, 0x2A);
	VALIDATE(CItem, field_2C, 0x2C);

	VALIDATE(CItem, field_30, 0x30);
	VALIDATE(CItem, field_34, 0x34);
	VALIDATE(CItem, field_38, 0x38);
	VALIDATE(CItem, field_3C, 0x3C);

}


void validate_CBody(void){

	VALIDATE_SIZE(CBody, 0xF4);
	
	VALIDATE(CBody, field_40, 0x40);

	VALIDATE(CBody, field_44, 0x44);
	VALIDATE(CBody, mCBodyFlags, 0x46);
	VALIDATE(CBody, mAccellorVel, 0x60);

	VALIDATE(CBody, field_48, 0x48);
	VALIDATE(CBody, field_4C, 0x4C);
	VALIDATE(CBody, field_50, 0x50);
	VALIDATE(CBody, field_54, 0x54);
	VALIDATE(CBody, field_58, 0x58);
	VALIDATE(CBody, field_5C, 0x5C);

	VALIDATE(CBody, mAccellorVel, 0x60);
	VALIDATE(CBody, gVec, 0x6C);

	VALIDATE(CBody, field_78, 0x78);
	VALIDATE(CBody, field_79, 0x79);
	VALIDATE(CBody, field_7A, 0x7A);


	VALIDATE(CBody, field_7C, 0x7C);

	VALIDATE(CBody, field_80, 0x80);
	VALIDATE(CBody, field_84, 0x84);

	VALIDATE(CBody, csVector1, 0x88);

	VALIDATE(CBody, field_8E, 0x8E);

	VALIDATE(CBody, field_94, 0x94);
	VALIDATE(CBody, field_95, 0x95);
	VALIDATE(CBody, field_96, 0x96);

	VALIDATE(CBody, field_98, 0x98);
	VALIDATE(CBody, field_9C, 0x9C);
	VALIDATE(CBody, field_A0, 0xA0);

	VALIDATE(CBody, field_A4, 0xA4);
	VALIDATE(CBody, field_A8, 0xA8);

	VALIDATE(CBody, bodyVector, 0xB8);

	VALIDATE(CBody, field_C4, 0xC4);
	VALIDATE(CBody, field_C6, 0xC6);
	VALIDATE(CBody, field_C8, 0xC8);


	VALIDATE(CBody, bodyQuadBit, 0xCC);
	VALIDATE(CBody, field_D0, 0xD0);
	VALIDATE(CBody, field_D2, 0xD2);
	VALIDATE(CBody, field_D4, 0xD4);

	VALIDATE(CBody, field_D8, 0xD8);

	VALIDATE(CBody, field_DC, 0xDC);

	VALIDATE(CBody, field_DE, 0xDE);

	VALIDATE(CBody, field_E0, 0xE0);
	VALIDATE(CBody, field_E2, 0xE2);

	VALIDATE(CBody, field_E4, 0xE4);

	VALIDATE(CBody, field_E8, 0xE8);

	VALIDATE_VTABLE(CBody, Die, 1);
	VALIDATE_VTABLE(CBody, AI, 2);
	VALIDATE_VTABLE(CBody, Hit, 3);
	VALIDATE_VTABLE(CBody, DeleteStuff, 4);
}

void validate_CSuper(void){

	/*
		unsigned char field_13E;
	unsigned char field_13F;
	unsigned char field_142;
	__int16 field_148;
	*/

	VALIDATE_SIZE(CSuper, 0x1A4);
	
	VALIDATE(CSuper, field_F4, 0xF4);
	VALIDATE(CSuper, field_F8, 0xF8);
	VALIDATE(CSuper, field_FC, 0xFC);
	VALIDATE(CSuper, field_100, 0x100);
	VALIDATE(CSuper, field_104, 0x104);

	VALIDATE(CSuper, field_10C, 0x10C);
	VALIDATE(CSuper, field_114, 0x114);
	VALIDATE(CSuper, field_11C, 0x11C);
	VALIDATE(CSuper, alsoOutlineRelated, 0x120);
	VALIDATE(CSuper, outlineR, 0x124);
	VALIDATE(CSuper, outlineG, 0x125);
	VALIDATE(CSuper, outlineB, 0x126);

	VALIDATE(CSuper, field_128, 0x128);
	VALIDATE(CSuper, field_12A, 0x12A);
	VALIDATE(CSuper, field_141, 0x141);
	VALIDATE(CSuper, field_143, 0x143);
	VALIDATE(CSuper, field_150, 0x150);
	VALIDATE(CSuper, field_152, 0x152);
	VALIDATE(CSuper, field_154, 0x154);


	VALIDATE(CSuper, field_128, 0x128);

	VALIDATE(CSuper, field_12A, 0x12A);
	VALIDATE(CSuper, outlineRelated, 0x12C);

	VALIDATE(CSuper, field_130, 0x130);
	VALIDATE(CSuper, field_134, 0x134);

	VALIDATE(CSuper, field_13E, 0x13E);
	VALIDATE(CSuper, field_13F, 0x13F);

	VALIDATE(CSuper, field_140, 0x140);
	VALIDATE(CSuper, field_141, 0x141);
	VALIDATE(CSuper, field_142, 0x142);

	VALIDATE(CSuper, field_144, 0x144);	
	VALIDATE(CSuper, field_146, 0x146);	

	VALIDATE(CSuper, gAnim, 0x148);	
	VALIDATE(CSuper, csuperend, 0x14C);

	VALIDATE(CSuper, field_164, 0x164);

	VALIDATE(CSuper, field_184, 0x184);
	VALIDATE(CSuper, field_188, 0x188);
	VALIDATE(CSuper, actualcsuperend, 0x190);
}

void validate_SHitInfo(void)
{
	VALIDATE_SIZE(SHitInfo, 0x1C);

	VALIDATE(SHitInfo, field_0, 0x0);
	VALIDATE(SHitInfo, field_4, 0x4);
	VALIDATE(SHitInfo, field_8, 0x8);
	VALIDATE(SHitInfo, field_C, 0xC);
}
