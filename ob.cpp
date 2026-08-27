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
CVector ZeroVector;

// @Ok
u8 gWhatIf;

u32 SuspendedDistance;
u8 gPsxItemsIndex;
const char *gObjFile;
CBody* EnvironmentalObjectList;
CBody* SuspendedList;
CItem* EnviroList;

//#define G_SUSPENEDED_LIST (SuspendedList)
#define G_SUSPENEDED_LIST (*reinterpret_cast<CBody**>(0x0060DAB4))

CBody* RealMechList;

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
// @Matching
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
// @Matching
void* CItem::operator new(size_t size)
{
	void *pnew = Mem_New(size);

	// Ensure size is a multiple of 4.
	size = ( size + 3 ) & ~0x03;

	// Zero all the newly allocated memory
	u32 *p=(u32 *)pnew;
	for (i32 i=0; i<size/4; ++i) *p++=0;

	return pnew;
}

// @Ok
void CItem::operator delete(void *ptr)
{
	Mem_Delete(ptr);
}


// @Ok
// @Matching
CItem::CItem()
{
	this->mScale.Set(0x1000, 0x1000, 0x1000);

	this->mpLight = &M3d_DefaultLight;
}

// @Ok
// @Matching
CItem::~CItem()
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
// @Matching
void CItem::InitItem(const char * pName)
{
	this->mRegion = Spool_FindRegion(pName);
	this->mModel = 0;


	if (G_PSXREGION[this->mRegion].IsSuper)
	{
		SModel *pModel = G_PSXREGION[this->mRegion].ppModels[0];
		pModel->Radius = 0x64000;
		pModel->Box.vx = 0xFF9C0064;
		pModel->Box.vy = 0xFF9C0064;
		pModel->Box.vz = 0xFF9C0064;
	}
}



// @Ok
// @Matching
INLINE i32 CBody::IsDead(void) const
{
	if (this->mCBodyFlags & CBODY_ZOMBIE)
		return 1;
	return 0;
}
	


// @Ok
// @Matching
void CBody::Die(void)
{
	if(!this->IsDead())
	{
		this->mCBodyFlags |= CBODY_ZOMBIE;
	}
}

// @Ok
// @Matching
void CBody::ShadowOn(void){
	this->mCBodyFlags |= CBODY_HASSHADOW;
}


// @Ok
// @Matching
void CBody::KillShadow(void)
{
	this->mCBodyFlags &= ~(CBODY_HASSHADOW);
	if (this->mpShadow)
	{
		delete this->mpShadow;
		this->mpShadow = 0;
	}
}

// @Ok
// @Matching
void CBody::UpdateShadow(void)
{
	NOT_IMPLEMENTED;

	if(this->mCBodyFlags & 8){

		if(!this->mpShadow){

			TotalBitUsage = 0;
			this->mpShadow = new CQuadBit();;
			TotalBitUsage = 1;

			this->mpShadow->SetTexture(0, 0);
			this->mpShadow->SetSubtractiveTransparency();
			this->mpShadow->mFrigDeltaZ = 32;
			this->mpShadow->mProtected = 1;
		}

		CSVector vec;
		vec.Set(0, -4096, 0);

		this->mpShadow->OrientUsing(
				&this->mShadowPos,
				reinterpret_cast<SVECTOR*>(&vec),
				this->mShadowScale,
				this->mShadowScale);


		i32 trans = ((this->mShadowThreshold - this->mShadowDist) << 7) / this->mShadowThreshold;

		if(trans < 0)
		{
			trans = 0;
		}

		this->mpShadow->SetTransparency(trans);

	}
	else{
		   this->KillShadow();
	}

}


// @Ok
// @Matching
INLINE void CBody::AttachTo(CBody** ppList)
{
	this->mNextItem = *ppList;
	this->mPreviousItem = 0;

	*ppList = this;

	if (this->mNextItem)
		this->mNextItem->mPreviousItem = this;
}

// @Ok
// @Matching
INLINE void CBody::DeleteFrom(CBody **a2)
{

	if(this->mCBodyFlags & CBODY_SUSPENDED && a2 != &G_SUSPENEDED_LIST)
	{
		this->UnSuspend();
	}

	if (this->mNextItem)
		this->mNextItem->mPreviousItem = this->mPreviousItem;

	if (this->mPreviousItem)
		this->mPreviousItem->mNextItem = this->mNextItem;

	if (*a2 == this)
		*a2 = reinterpret_cast<CBody*>(this->mNextItem);
}

// @Ok
// @Matching
INLINE void CBody::UnSuspend(void)
{

	if (this->mCBodyFlags & CBODY_SUSPENDED)
	{
		this->DeleteFrom(&G_SUSPENEDED_LIST);
		this->AttachTo(this->mppOriginalList);
		this->mCBodyFlags &= ~CBODY_SUSPENDED;
	}
}

// @Ok
// @Matching
void CBody::Suspend(CBody **a2)
{
	ASSERT((this->mCBodyFlags & CBODY_SUSPENDED) == 0, "Suspended flag illegally set");
	ASSERT(a2 != 0, "woops");

	this->DeleteStuff();

	this->mppOriginalList = a2;
	this->DeleteFrom(a2);

	this->AttachTo(&G_SUSPENEDED_LIST);
	this->mCBodyFlags |= CBODY_SUSPENDED;
}




// @Ok
// @Matching
void CBody::InterleaveAI(void)
{
	if (this->mFlags & CBODY_RADIALSUSPENSION)
	{
		this->EveryFrame();
		CSuper *super = reinterpret_cast<CSuper*>(this);
		super->UpdateFrame();

		this->AI();
	}
	else
	{
		this->EveryFrame();
		this->AI();
	}
}

// @Ok
// @Matching
i16* CBody::SquirtPos(i16* p_info)
{
	i32 *walker = reinterpret_cast<i32*>(p_info);
	ASSERT(((i32)walker & 3) == 0, "Bad alignment");

	this->mPos.vx = *walker++ << 12;
	this->mPos.vy = *walker++ << 12;
	this->mPos.vz = *walker++ << 12;

	return reinterpret_cast<i16*>(walker);
}

// @Ok
// @Matching
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
	this->field_98 = G_VBLANKS;
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

// @Ok
// @Matching
CSuper::CSuper()
{
	this->mFlags |= 2u;
	this->mNumFrames = 1;
	this->mAnimFinished = 1;

	this->mAnimSpeed = 0x10000;
	this->field_13E = 100;
	this->field_13F = 94;
}

// @Ok
// @Matching
void CSuper::OutlineOff(void)
{
	this->mExtraFlags &= ~CSUPER_OUTLINE;
}

// @NotOk
// Missing most stuff, only used by CVenom and CDummy
void CSuper::OutlineOn(void){
	NOT_IMPLEMENTED;
	this->mExtraFlags |= CSUPER_OUTLINE;
	if (!this->field_11C){
	}

	this->outlineR = -1;
	this->outlineG = -1;
	this->outlineB = -1;
	this->alsoOutlineRelated = 0x50000000;
}


// @Ok
// @Matching
void CSuper::SetOutlineSemiTransparent(){
	this->alsoOutlineRelated |= 0x02000000;
}


// @Ok
// @Matching
void CSuper::SetOutlineRGB(
		u8 a2,
		u8 a3,
		u8 a4)
{
	this->outlineR = a2;
	this->outlineG = a3;
	this->outlineB = a4;
}

// @SMALLTODO
// Slightly different register allocation, edx and eax are swapped
void CSuper::UpdateFrame(void){

	typedef void (FASTCALL *func_ptr)(CSuper*, void*);
	
	func_ptr func = (func_ptr)0x00460DA0;
	func(this, 0);
	
	return;

	char v1; // bl
	i32 v2; // esi
	i32 v3; // edx
	i32 v4; // eax
	i32 v5; // edx
	i32 v6; // eax
	u16 v7; // dx


	if ( !this->field_80 )
	  this->field_80 = 2;
	v1 = this->mAnimDir;
	v2 = this->field_80 * this->mAnimSpeed / 2;
	v3 = (u16)this->mFrameFrac | (this->mFrame << 16);
	if ( this->mAnimDir == 1 )
	  v3 += v2;
	if ( v1 == -1 )
	  v3 -= v2;
	v4 = v3;
	this->mFrameFrac = v3;
	v5 = (u8)this->mAnimMode;
	v6 = v4 >> 16;
	this->mFrame = v6;

	if (v5) {
		if ( --v5 == 0)
		{
		  v7 = this->mNumFrames;
		  if ( (i16)v6 >= (int)v7 )
		  {
			  this->mFrame = v6 - v7;
        
		  }
		  else
		  {

			if ( (i16)(v6) < 0 )
			  this->mFrame = v6 + v7;
		  }
		}
	}
	else if( (this->mAnimDir == 1 && (i16)v6 >= this->mTargetFrame)
		||
		(v1 == -1 && (i16)v6 <= this->mTargetFrame)
		)
	{
		this->mFrame = this->mTargetFrame;
		this->mAnimFinished = 1;
	}
}


// @Ok
// @Matching
void CSuper::CycleAnim(i32 anim, i8 animdir)
{
	if (this->mAnim != anim)
	{
		this->mFrame = 0;
		this->mFrameFrac = 0;
		this->mAnim = anim;

		DoAssert(
			static_cast<u32>(anim & 0xFFFF) < G_PSXREGION[this->mRegion].pAnimFile[0],
			"Bad anim sent to CycleAnim");

		this->mNumFrames =
			reinterpret_cast<u16*>(G_PSXREGION[this->mRegion].pAnimFile)[4 + (4 * this->mAnim)];


		this->mAnimDir = animdir;
	}

	this->mAnimMode = 1;
	this->mAnimFinished = 0;
}


// @Ok
// @Matching
void CSuper::ApplyPose(i16 *a2){

	if (!this->mpJoints)
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


// @Ok
// @Matching
void CSuper::RunAnim(
		i32 anim,
		i32 from,
		i32 to)
{

	this->mAnim = anim;
	DoAssert(
			static_cast<u32>(anim & 0xFFFF) < PSXRegion[this->mRegion].pAnimFile[0],
			"Bad anim sent to RunAnim");
	u16 v6 = reinterpret_cast<u16*>(PSXRegion[this->mRegion].pAnimFile)[4 + (4 * this->mAnim)];

	this->mNumFrames = v6;
	if (from == -1)
	{
		from = v6 - 1;
	}

	if (to == -1)
	{
		to = v6 - 1;
	}

	if (from < 0 || from >= v6)
		from = 0;
	if (to < 0 || to >= v6)
		to = 0;

	this->mAnimMode = 0;

	i32 res;
	if (to > from)
	{
		res = 1;
	}
	else
	{
		res = (to >= from) ? 0 : -1;
	}

	this->mTargetFrame = to;
	this->mAnimDir = res;
	this->mFrame = from;
	this->mFrameFrac = 0;
	this->mAnimFinished = static_cast<u16>(from) == static_cast<u16>(to);
}

// @SMALLTODO
// @AlmostMatching: add esp, 8 happens 2 instructions later after DoAssert dunno why
void CBody::EveryFrame(void)
{

	typedef void (FASTCALL *func_ptr)(CBody*, void*);
	func_ptr func = (func_ptr)0x00460ED0;

	func(this, 0);

	return;
	if (this->mCBodyFlags & 4)
	{
		this->field_80 = 2;
		this->mCBodyFlags &= 0xFFFB;
		this->field_7C = gTimerRelated;
		this->field_84 = 0;
	}
	else
	{
		this->field_80 = gTimerRelated - this->field_7C;
		DoAssert(
				this->field_80 >= 0,
				"Timing error");

		this->field_7C = gTimerRelated;
		if (this->field_80 > 6)
		{
			this->field_80 = 6;
		}
	}

	this->field_84 += this->field_80;

	if (this->mFlags & 2)
	{
		CSuper *pSuper = reinterpret_cast<CSuper*>(this);
		pSuper->field_152 = pSuper->mFrame;
		pSuper->field_150 = pSuper->mFrame;
		pSuper->field_154 = pSuper->mAnim;
		pSuper->field_143 = pSuper->mAnimDir;
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
	if (this->mpPoseBuffer)
		Mem_Delete(this->mpPoseBuffer);

	if (this->mpJoints)
		Mem_Delete(this->mpJoints);

	if (this->mpDecompressedFrame)
		Mem_Delete(this->mpDecompressedFrame);

	if (this->mpCalculationOrder)
		Mem_Delete(this->mpCalculationOrder);

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

	VALIDATE(CItem, mDummyFrame, 0x1C);
	VALIDATE(CItem, mTintIndex, 0x1D);
	VALIDATE(CItem, mDummyAnim, 0x1E);

	VALIDATE(CItem, mRegion, 0x1F);

	VALIDATE(CItem, mNextItem, 0x20);


	VALIDATE(CItem, mRGB, 0x24);
	VALIDATE(CItem, mScale, 0x28);

	VALIDATE(CItem, mTRN, 0x30);
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

	VALIDATE(CBody, mCollision, 0xE0);
	VALIDATE(CBody, mHealth, 0xE2);

	VALIDATE(CBody, mPlayerDist, 0xE4);

	VALIDATE(CBody, field_E8, 0xE8);

	VALIDATE_VTABLE(CBody, Die, 1);
	VALIDATE_VTABLE(CBody, AI, 2);
	VALIDATE_VTABLE(CBody, Hit, 3);
	VALIDATE_VTABLE(CBody, DeleteStuff, 4);
}

void validate_CSuper(void)
{

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

	VALIDATE(CSuper, mFrame, 0x128);
	VALIDATE(CSuper, mAnim, 0x12A);

	VALIDATE(CSuper, mExtraFlags, 0x12C);

	VALIDATE(CSuper, mpCalculationOrder, 0x130);
	VALIDATE(CSuper, mpDecompressedFrame, 0x134);

	VALIDATE(CSuper, mRoot, 0x138);

	VALIDATE(CSuper, mDecompressedAnim, 0x13A);
	VALIDATE(CSuper, mDecompressedFrame, 0x13C);

	VALIDATE(CSuper, field_13E, 0x13E);
	VALIDATE(CSuper, field_13F, 0x13F);

	VALIDATE(CSuper, mAnimMode, 0x140);
	VALIDATE(CSuper, mAnimDir, 0x141);
	VALIDATE(CSuper, mAnimFinished, 0x142);
	VALIDATE(CSuper, field_143, 0x143);


	VALIDATE(CSuper, mTargetFrame, 0x144);	
	VALIDATE(CSuper, mFrameFrac, 0x146);	

	VALIDATE(CSuper, mNumFrames, 0x148);	
	VALIDATE(CSuper, mAnimSpeed, 0x14C);

	VALIDATE(CSuper, field_150, 0x150);
	VALIDATE(CSuper, field_152, 0x152);
	VALIDATE(CSuper, field_154, 0x154);

	VALIDATE(CSuper, field_158, 0x158);

	VALIDATE(CSuper, mTransform, 0x164);

	VALIDATE(CSuper, mpPoseBuffer, 0x184);
	VALIDATE(CSuper, mpJoints, 0x188);
	VALIDATE(CSuper, mpLinks, 0x18C);
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

#include "my_patch.h"

// @Bogus
void patch_CItem(void)
{
	PATCH_PUSH_RET(0x00460020, CItem::InitItem);
}

// @Bogus
void patch_CBody(void)
{
	PATCH_PUSH_RET(0x00460570, CBody::KillShadow);
	PATCH_PUSH_RET(0x00460F90, CBody::InterleaveAI);
	PATCH_PUSH_RET(0x004603A0, CBody::SquirtAngles);

	PATCH_PUSH_RET(0x00460260, CBody::AttachTo);
	PATCH_PUSH_RET(0x00460500, CBody::UnSuspend);

	PATCH_PUSH_RET(0x00460280, CBody::DeleteFrom);

	PATCH_PUSH_RET(0x004602F0, CBody::FindBodyByNode);

	PATCH_PUSH_RET(0x00460330, CBody::SquirtPos);
	PATCH_PUSH_RET(0x004603D0, CBody::AttachXA);
	PATCH_PUSH_RET(0x00460440, CBody::Suspend);

	PATCH_PUSH_RET(0x00460560, CBody::ShadowOn);
	PATCH_PUSH_RET_POLY(0x004606F0, CBody::Die, "?Die@CBody@@UAEXXZ");
	PATCH_PUSH_RET(0x00460700, CBody::IsDead);
}

// @Bogus
void patch_CSuper(void)
{
	PATCH_PUSH_RET(0x00460BC0, CSuper::OutlineOff);
	PATCH_PUSH_RET(0x00460BD0, CSuper::SetOutlineSemiTransparent);
	PATCH_PUSH_RET(0x00460BE0, CSuper::SetOutlineRGB);
	PATCH_PUSH_RET(0x00460D00, CSuper::CycleAnim);
	PATCH_PUSH_RET(0x00460E80, CSuper::ApplyPose);
}
