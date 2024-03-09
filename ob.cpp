#include "ob.h"
#include "mem.h"
#include <cstring>
#include "validate.h"


void* CItem::operator new(unsigned int size) {

  void *result = DCMem_New(size, 0, 1, 0, 1);

  unsigned int adjusted_size = ((size + 3) & 0xFFFFFFFC) >> 2;
  if ( adjusted_size )
    memset(result, 0, 4 * adjusted_size);

  return result;
}


CItem::CItem(){}

CItem::~CItem(){}

//TODO
void CItem::InitItem(const char *)
{

	this->mRegion = 69;
	this->mModel = 0;
}



int __inline CBody::IsDead(void) const{
	return (this->mCBodyFlags >> 6) & 1;
}
	

void CBody::Die(void){
	int isDead = this->IsDead();
	if(!isDead)
	{
		this->mCBodyFlags |= 0x40;
	}
}

void CBody::ShadowOn(void){
	this->mCBodyFlags |= 8;
}


void __inline CBody::KillShadow(void){

  this->mCBodyFlags &= ~8u;
  if ( this->bodyQuadBit )
  {
    //result = (**somethingWithVtableDestructor)(somethingWithVtableDestructor, 1);
    this->bodyQuadBit = 0;
  }
}

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
		this->bodyQuadBit->OrientUsing(&this->bodyVector, &vec, lastParam, lastParam);


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


CSuper::CSuper(){
  this->gAnim = 1;
  this->field_142 = 1;
  this->field_13E = 100;
  this->field_13F = 94;

}

void CSuper::OutlineOff(void){
	this->outlineRelated &= 0xFFFFFFFB;
}

// NEED TO FINISH
void CSuper::OutlineOn(void){
	this->outlineRelated |= 4;
	if (!this->SNbrFaces){
	}

	this->outlineR = -1;
	this->outlineG = -1;
	this->outlineB = -1;
	this->alsoOutlineRelated = 0x50000000;
}


void CSuper::SetOutlineSemiTransparent(){
	this->alsoOutlineRelated |= 0x20000000;
}

void CSuper::SetOutlineRGB(unsigned char a2, unsigned char a3, unsigned char a4){
	this->outlineR = a2;
	this->outlineG = a3;
	this->outlineB = a4;
}

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


//Revisit
void CSuper::ApplyPose(__int16 *a2){

	if (!this->field_188){
		this->actualcsuperend = a2;
	}

	if ((this->mFlags & 4) != 0){
		this->field_13E = 69;
	}
}


//TODO
void CSuper::RunAnim(int, int, int){
}

void validate_CItem(void){

	VALIDATE(CItem, mFlags, 0x4);
	VALIDATE(CItem, mPos, 0x8);
	VALIDATE(CItem, mAngles, 0x14);
	VALIDATE(CItem, mModel, 0x1A);
	VALIDATE(CItem, mRegion, 0x1F);

}


void validate_CBody(void){
	VALIDATE(CBody, field_44, 0x44);
	VALIDATE(CBody, mCBodyFlags, 0x46);
	VALIDATE(CBody, mAccellorVel, 0x60);
	VALIDATE(CBody, field_80, 0x80);
	VALIDATE(CBody, field_8E, 0x8E);
	VALIDATE(CBody, bodyVector, 0xB8);
	VALIDATE(CBody, bodyQuadBit, 0xCC);
	VALIDATE(CBody, field_D0, 0xD0);
	VALIDATE(CBody, field_D2, 0xD2);
	VALIDATE(CBody, field_D4, 0xD4);
	VALIDATE(CBody, field_DC, 0xDC);
	VALIDATE(CBody, field_E2, 0xE2);
}

void validate_CSuper(void){

	/*
		unsigned char field_13E;
	unsigned char field_13F;
	unsigned char field_142;
	__int16 field_148;
	*/
	

	VALIDATE(CSuper, field_10C, 0x10C);
	VALIDATE(CSuper, SNbrFaces, 0x11C);
	VALIDATE(CSuper, alsoOutlineRelated, 0x120);
	VALIDATE(CSuper, outlineR, 0x124);
	VALIDATE(CSuper, outlineG, 0x125);
	VALIDATE(CSuper, outlineB, 0x126);

	VALIDATE(CSuper, field_128, 0x128);

	VALIDATE(CSuper, field_12A, 0x12A);
	VALIDATE(CSuper, outlineRelated, 0x12C);

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

	VALIDATE(CSuper, field_188, 0x188);
	VALIDATE(CSuper, actualcsuperend, 0x190);
}
