#include "ob.h"
#include "mem.h"
#include "spool.h"
#include <cstring>
#include "validate.h"
#include "ps2redbook.h"
#include "ps2m3d.h"
#include "m3dutils.h"
#include "spool.h"
#include "utils.h"
#include "my_assert.h"

// @Ok
u8 gWhatIf;

u32 SuspendedDistance;
u8 gPsxItemsIndex;
const char *gObjFile;
CBody* EnvironmentalObjectList;
CBody* SuspendedList;
CItem* EnviroList;

i32 gSuperItemRelated = 1;
f32 gFloatSuperRelated = 1.0f;

// @Ok
EXPORT SLight M3d_DefaultLight =
{
  { { -2896, -2896, 0 }, { 3277, -2458, 0 }, { 1737, 3277, 1737 } },
  0,
  { { 2800, 1900, 1000 }, { 1900, 1900, 1500 }, { 1500, 2800, 1000 } },
  0,
  { 512, 512, 512 }
};


// @Ok
// @Matching
void CBody::DeleteStuff(void)
{
}

// @Ok
CBody* CBody::FindBodyByNode(
		i32 type,
		CBody* pBody)
{
	for (CBody *cur = pBody; cur; cur = reinterpret_cast<CBody*>(cur->mNextItem))
	{
		if (cur->mNode == type)
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


// @Ok
// @Matching
INLINE CItem::CItem()
{
	this->mScale.Set(0x1000, 0x1000, 0x1000);

	this->mpLight = &M3d_DefaultLight;
}

// @Ok
// @Matching
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
INLINE void CBody::KillShadow(void){

	this->mCBodyFlags &= ~8u;
	if (this->mpShadow)
	{
		delete this->mpShadow;
		this->mpShadow = 0;
	}
}

// @NotOk
// Inlined KillShadow and weird part where we store data but it's just xor eax, eax
void CBody::UpdateShadow(void){

	__int16 flags = this->mCBodyFlags;

	if(flags & 8){

		if(!this->mpShadow){

			CQuadBit *quad = new CQuadBit();
			this->mpShadow = quad;

			quad->SetTexture(0, 0);
			this->mpShadow->SetSubtractiveTransparency();
			this->mpShadow->mFrigDeltaZ = 32;
			this->mpShadow->mProtected = 1;
		}

		SVector vec;
		vec.vx = 0;
		vec.vy = -4096;
		vec.vz = 0;

		u16 lastParam = this->mShadowScale;
		this->mpShadow->OrientUsing(&this->mShadowPos, reinterpret_cast<SVECTOR*>(&vec), lastParam, lastParam);


		__int8 trans = ((this->mShadowThreshold - this->mShadowDist) << 7) / this->mShadowThreshold;

		if(trans < 0){
			trans = 0;
		}

		this->mpShadow->SetTransparency(trans);

	}
	else{
		   this->KillShadow();
	}

}


// @Ok
INLINE void CBody::AttachTo(CBody** a1)
{

	CBody *v2 = *a1;
	this->mPreviousItem = 0;
	this->mNextItem = v2;

	*a1 = this;

	CItem *v3 = this->mNextItem;
	if (v3)
		v3->mPreviousItem = this;

}

// @Ok
// @Matching
INLINE void CBody::DeleteFrom(CBody **a2)
{

	if(this->mCBodyFlags & 1 && a2 != &SuspendedList)
	{
		this->UnSuspend();
	}

	CItem *v6 = this->mNextItem;
	if (v6)
		v6->mPreviousItem = this->mPreviousItem;

	CItem *r = this->mPreviousItem;
	if (r)
		r->mNextItem = this->mNextItem;

	if (*a2 == this)
		*a2 = reinterpret_cast<CBody*>(this->mNextItem);
}

// @Ok
// @Matching
INLINE void CBody::UnSuspend(void)
{

	if (this->mCBodyFlags & 1)
	{
		this->DeleteFrom(&SuspendedList);
		this->AttachTo(this->mppOriginalList);
		this->mCBodyFlags &= 0xFFFE;
	}
}

// @Ok
// @Matching
void CBody::Suspend(CBody **a2)
{
	print_if_false((this->mCBodyFlags & 1) == 0, "Suspended flag illegally set");
	print_if_false(a2 != 0, "woops");

	this->DeleteStuff();

	this->mppOriginalList = a2;
	this->DeleteFrom(a2);

	this->AttachTo(&SuspendedList);
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

// @Ok
// @Matching
void CBody::AttachXA(i32 a2, i32 a3)
{
	this->field_98 = Vblanks;
	this->field_9C = a2;
	this->field_A0 = a3;
}

// @Ok
// @Matching
void CBody::StopMyXA(void)
{
	if ((Vblanks - this->field_98) < 0x12C
			&& gRedbookXaRelatedOne == this->field_9C
			&& gRedbookXaRelatedTwo == this->field_A0)
	{
		Redbook_XAStop();
	}
}

// @Ok
// @AlmostMatching: vtable is moved later than expected for some reason
CBody::CBody(void)
{
	this->mFric.vx = 1;
	this->mFric.vy = 1;
	this->mFric.vz = 1;

	this->mAngFric.vx = 1;
	this->mAngFric.vy = 1;
	this->mAngFric.vz = 1;
	this->mCBodyFlags |= 0x16;

	this->mPushVal = 10;
	this->field_A4 = 0;
	this->mNode = 0xFFFF;
	this->mShadowScale = 32;
	this->mShadowThreshold = 200;
}

// @NotOk
// code is matching but make sure vtable is also
CSuper::CSuper()
{
	this->mFlags |= 2u;
	this->gAnim = 1;
	this->field_142 = 1;
	//this->cbody.citem.vtable = (int)&off_53BBE8;
	this->mAnimSpeed = 0x10000;
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
	v1 = this->mAnimDir;
	v2 = this->field_80 * this->mAnimSpeed / 2;
	v3 = (unsigned __int16)this->field_146 | (this->field_128 << 16);
	if ( this->mAnimDir == 1 )
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
	else if( (this->mAnimDir == 1 && (__int16)v6 >= this->field_144)
		||
		(v1 == -1 && (__int16)v6 <= this->field_144)
		){
		this->field_128 = this->field_144;
		this->field_142 = 1;
	}
}


// @NotOk
// Revisit
void CSuper::CycleAnim(i32 anim, i8 animdir){
	if (this->mAnim != anim )
	{
		this->field_128 = 0;
		this->field_146 = 0;
		this->mAnim = anim;
		int mRegion = (unsigned __int8)this->mRegion;

		DoAssert(
			(unsigned int)(unsigned __int16)anim < *(unsigned int *)Animations[17 * mRegion],
			"Bad anim sent to CycleAnim");
		this->gAnim = *(__int16 *)(Animations[17 * (unsigned __int8)this->mRegion]
			+ 8 * (unsigned __int16)this->mAnim
			+ 8);


		this->mAnimDir = animdir;
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
	this->mAnim = a2;

	print_if_false((unsigned int)a2 < *(unsigned int *)Animations[17 * mRegion], "Bad anim sent to RunAnim");
	v6 = *(unsigned __int16 *)(Animations[17 * (unsigned char)this->mRegion] + 8 * (unsigned __int16)this->mAnim + 8);
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
	this->mAnimDir = v9;
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
		v7 = super->mAnim;
		v8 = super->mAnimDir;
		super->field_152 = v6;
		super->field_150 = v6;
		super->field_154 = v7;
		super->field_143 = v8;
	}

}

// @Ok
// @Matching
INLINE CBody::~CBody(void)
{
	delete this->mpShadow;
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

void validate_CItem(void)
{
	VALIDATE_SIZE(CItem, 0x40);

	VALIDATE(CItem, mFlags, 0x4);
	VALIDATE(CItem, mInquiry, 0x6);
	VALIDATE(CItem, mPos, 0x8);
	VALIDATE(CItem, mAngles, 0x14);
	VALIDATE(CItem, mModel, 0x1A);
	VALIDATE(CItem, mRegion, 0x1F);

	VALIDATE(CItem, mNextItem, 0x20);


	VALIDATE(CItem, mRGB, 0x24);
	VALIDATE(CItem, mScale, 0x28);

	VALIDATE(CItem, field_30, 0x30);
	VALIDATE(CItem, mPreviousItem, 0x34);
	VALIDATE(CItem, mType, 0x38);
	VALIDATE(CItem, mpLight, 0x3C);

}


void validate_CBody(void){

	VALIDATE_SIZE(CBody, 0xF4);
	
	VALIDATE(CBody, mppOriginalList, 0x40);

	VALIDATE(CBody, mInputFlags, 0x44);
	VALIDATE(CBody, mCBodyFlags, 0x46);

	VALIDATE(CBody, field_48, 0x48);

	VALIDATE(CBody, field_54, 0x54);

	VALIDATE(CBody, mVel, 0x60);
	VALIDATE(CBody, mAcc, 0x6C);

	VALIDATE(CBody, mFric, 0x78);


	VALIDATE(CBody, field_7C, 0x7C);

	VALIDATE(CBody, field_80, 0x80);
	VALIDATE(CBody, field_84, 0x84);

	VALIDATE(CBody, mAngVel, 0x88);
	VALIDATE(CBody, mAngAcc, 0x8E);

	VALIDATE(CBody, mAngFric, 0x94);

	VALIDATE(CBody, field_98, 0x98);
	VALIDATE(CBody, field_9C, 0x9C);
	VALIDATE(CBody, field_A0, 0xA0);

	VALIDATE(CBody, field_A4, 0xA4);
	VALIDATE(CBody, field_A8, 0xA8);

	VALIDATE(CBody, mShadowPos, 0xB8);
	VALIDATE(CBody, mShadowNormal, 0xC4);
	VALIDATE(CBody, mpShadow, 0xCC);

	VALIDATE(CBody, mShadowScale, 0xD0);
	VALIDATE(CBody, mShadowDist, 0xD2);
	VALIDATE(CBody, mShadowThreshold, 0xD4);

	VALIDATE(CBody, mPushVal, 0xD8);

	VALIDATE(CBody, mRMinor, 0xDC);

	VALIDATE(CBody, mNode, 0xDE);

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
	VALIDATE(CSuper, mAnim, 0x12A);

	VALIDATE(CSuper, outlineRelated, 0x12C);

	VALIDATE(CSuper, field_130, 0x130);
	VALIDATE(CSuper, field_134, 0x134);

	VALIDATE(CSuper, field_13E, 0x13E);
	VALIDATE(CSuper, field_13F, 0x13F);

	VALIDATE(CSuper, field_140, 0x140);
	VALIDATE(CSuper, mAnimDir, 0x141);
	VALIDATE(CSuper, field_142, 0x142);
	VALIDATE(CSuper, field_143, 0x143);
	VALIDATE(CSuper, field_150, 0x150);
	VALIDATE(CSuper, field_152, 0x152);
	VALIDATE(CSuper, field_154, 0x154);


	VALIDATE(CSuper, field_144, 0x144);	
	VALIDATE(CSuper, field_146, 0x146);	

	VALIDATE(CSuper, gAnim, 0x148);	
	VALIDATE(CSuper, mAnimSpeed, 0x14C);

	VALIDATE(CSuper, mTransform, 0x164);

	VALIDATE(CSuper, field_184, 0x184);
	VALIDATE(CSuper, field_188, 0x188);
	VALIDATE(CSuper, actualcsuperend, 0x190);
}

void validate_SHitInfo(void)
{
	VALIDATE_SIZE(SHitInfo, 0x1C);

	VALIDATE(SHitInfo, field_0, 0x0);
	VALIDATE(SHitInfo, field_1, 0x1);

	VALIDATE(SHitInfo, field_4, 0x4);
	VALIDATE(SHitInfo, field_8, 0x8);
	VALIDATE(SHitInfo, field_C, 0xC);

	VALIDATE(SHitInfo, field_18, 0x18);
	VALIDATE(SHitInfo, field_1A, 0x1A);
}

void validate_SLight(void)
{
	VALIDATE_SIZE(SLight, 0x34);

	VALIDATE(SLight, LightMatrix, 0x0);

	VALIDATE(SLight, ColorMatrix, 0x14);

	VALIDATE(SLight, BackColor, 0x28);
}
