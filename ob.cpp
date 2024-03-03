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

void validate_CItem(void){

	VALIDATE(CItem, mFlags, 0x4);
	VALIDATE(CItem, mPos, 0x8);
	VALIDATE(CItem, mAngles, 0x14);
	VALIDATE(CItem, mModel, 0x1A);
	VALIDATE(CItem, mRegion, 0x1F);

}


void validate_CBody(void){
	VALIDATE(CBody, mCBodyFlags, 0x46);
	VALIDATE(CBody, bodyQuadBit, 0xCC);
	VALIDATE(CBody, field_D0, 0xD0);
	VALIDATE(CBody, field_D2, 0xD2);
	VALIDATE(CBody, field_D4, 0xD4);
	VALIDATE(CBody, bodyVector, 0xB8);
}