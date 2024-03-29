#include "export.h"
#include "bit.h"
#include "mem.h"
#include <cstring>
#include <cstdlib>
#include "validate.h"


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

void CBit::SetPos(const CVector &pos){

	this->mPos = pos;
}


void CBit::DeleteFrom(CBit **lst){
	
	CBit* next = this->mNext;
	if(next != NULL){
		next->mPrevious = this->mPrevious;
	}

	CBit* prev = this->mPrevious;
	if(prev != NULL){
		prev->mNext = this->mNext;
	}

	if(*lst == this){
		*lst = this->mNext;
	}
}

void CQuadBit::SetTint(unsigned char a2, unsigned char a3, unsigned char a4)
{
  this->mTint = a2 | ((a4 << 16) & 0xFF0000 | (a3 << 8) & 0xFF00) & 0xFFFFFF00;
}


void CQuadBit::SetSemiTransparent()
{
	this->mCodeBGR = (this->mCodeBGR & 0xFFFFFFFE) | 0x2C0;
}

void CQuadBit::SetOpaque(){
	this->mCodeBGR = (this->mCodeBGR & 0xFFFFFDBF) | 0x80;
}


void CQuadBit::SetSubtractiveTransparency(){
	this->mCodeBGR = (this->mCodeBGR & 0xFFFFFF7F) | 0x340;
}

void CQuadBit::SetCorners(const CVector &a2, const CVector &a3, const CVector &a4, const CVector &a5)
{
	this->mPos = a2;
	this->mPosB = a3;
	this->mPosC = a4;
	this->mPosD = a5;
}

void CQuadBit::SetTransparency(unsigned char a2){
	this->mTint = a2 | ((a2 | (a2 << 8)) << 8);
}

void CQuadBit::OrientUsing(CVector *a2, SVector *a3, int a4, int a5){
}

void CQuadBit::SetTexture(int a, int b){
	
}

CFT4Bit::~CFT4Bit() {}


void CFT4Bit::SetAnimSpeed(short s){
	this->mAnimSpeed = s;
}

void CFT4Bit::SetScale(unsigned short s){
	this->mScale = s;
}


void CFT4Bit::SetSemiTransparent(){
	this->mCodeBGR |= 0x2000000;
}

void CFT4Bit::SetTransparency(unsigned char t){
	this->mCodeBGR = t | this->mCodeBGR & 0xFF000000 | ((t | (t << 8)) << 8);
}

static int * const gAnimTable = (int*)0x0056EA64;
static const unsigned int maxANimTableEntry = 0x1D;

void CFT4Bit::SetAnim(int a2){

	char v5; // cl

	print_if_false(a2 >= 0 && !((unsigned int)a2 >= maxANimTableEntry), "Bad lookup value sent to SetAnim");
	print_if_false(this->mDeleteAnimOnDestruction == 0, "mDeleteAnimOnDestruction set?");

	int v4 = gAnimTable[a2];
	this->animRelated1 = v4;
	v5 = *(char *)(v4 - 4);
	this->animRelated2 = 0;
	this->animRelated3 = v5;
	this->animRelated4 = 0;
	this->animRelated5 = this->animRelated1;
}



void validate_CFlatBit(void){
	VALIDATE(CFlatBit, field_58, 0x58);
	VALIDATE(CFlatBit, field_5A, 0x5A);
	VALIDATE(CFlatBit, mSemiTransparencyRate, 0x5E);
	VALIDATE(CFlatBit, mPostScale, 0x60);
	VALIDATE(CFlatBit, mAngFric, 0x65);

}

void validate_CFT4Bit(void){
	VALIDATE(CFT4Bit, mCodeBGR, 0x40);

	VALIDATE(CFT4Bit, mDeleteAnimOnDestruction, 0x44);
	VALIDATE(CFT4Bit, animRelated1, 0x48);
	VALIDATE(CFT4Bit, animRelated5, 0x4C);

	VALIDATE(CFT4Bit, animRelated3, 0x51);
	VALIDATE(CFT4Bit, animRelated4, 0x52);
	VALIDATE(CFT4Bit, animRelated2, 0x53);

	VALIDATE(CFT4Bit, mAnimSpeed, 0x54);
	VALIDATE(CFT4Bit, mScale, 0x56);
}

void validate_CQuadBit(void)
{
	VALIDATE(CQuadBit, mPosB, 0x3C);
	VALIDATE(CQuadBit, mPosC, 0x48);
	VALIDATE(CQuadBit, mPosD, 0x54);
	VALIDATE(CQuadBit, mpTexture, 0x60);
	VALIDATE(CQuadBit, mCodeBGR, 0x64);
	VALIDATE(CQuadBit, mTint, 0x6C);
}

void validate_CBit(void)
{
	VALIDATE(CBit, mPrevious, 0x4);
	VALIDATE(CBit, mNext, 0x8);

	VALIDATE(CBit, field_E, 0xE);

	VALIDATE(CBit, mPos, 0x10);
	VALIDATE(CBit, mVel, 0x1C);
	VALIDATE(CBit, mAcc, 0x28);
	VALIDATE(CBit, mProtected, 0x3A);
	VALIDATE(CBit, mDead, 0x37);
	VALIDATE(CBit, mFrigDeltaZ, 0x38);
}
