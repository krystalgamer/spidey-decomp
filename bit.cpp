#include "export.h"
#include "bit.h"
#include "mem.h"
#include <cstring>
#include <cstdlib>


volatile static int BitCount = 0;
static int TotalBitUsage = 0;

CBit::CBit() {

	this->mPos.vx = 0;
	this->mPos.vy = 0;
	this->mPos.vz = 0;

	this->mVel.vx = 0;
	this->mVel.vy = 0;
	this->mVel.vz = 0;

	this->mAcc.vx = 0;
	this->mAcc.vy = 0;
	this->mAcc.vz = 0;

	//mFric is inited to 0 here but removed

	this->mFric.vx = 1;
	this->mFric.vy = 1;
	this->mFric.vz = 1;
	BitCount++;
}

/*
 * With optimizations the >>=2 expression is removed
 * taking a look at THPS2 it shows it's due
 * to it storing the result in a global variable. For some reason
 * both PC and MAC remove the store
 */
void* CBit::operator new(unsigned int size) {

	void *result;
	if (TotalBitUsage == 0)
		result = DCMem_New(size, 0, 1, 0, 1);
	else
		result = DCMem_New(size, 0, 1, 0, 1);

	unsigned int quarter = size + 3;
	quarter &= 0xFFFFFFFC;
	/*
	TotalBitUsage += 4 + quarter;
	*/
	quarter >>= 2; // optimized out 

	if (quarter)
		memset(result, 0, 4 * quarter);

	return result;
}

CBit::~CBit(){
	this->mNext = NULL;
}

void CBit::Die(void){
	print_if_false(this->mProtected == 0, "A protected bit die");
	this->mDead = 1;
}

CBit* CBit::AttachTo(CBit** to){

	CBit* tmp;
	CBit* result;
	tmp = *to;

	this->mPrevious = NULL;
	this->mNext = tmp;
	*to = this;

	result = this->mNext;
	if (result)
		result->mPrevious = this;
	return result;
}

int CBit::SetPos(const CVector &pos){

	CVector &mPos = this->mPos;
	mPos.vx = pos.vx;
	mPos.vy = pos.vy;
	return mPos.vz = pos.vz;
}
