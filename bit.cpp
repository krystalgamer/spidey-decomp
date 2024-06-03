#include "export.h"
#include "bit.h"
#include "mem.h"
#include <cstring>
#include <cstdlib>
#include "validate.h"
#include "panel.h"


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


// @Ok
void CBit::operator delete(void* ptr)
{
	Mem_Delete(ptr);
}

CBit::~CBit(){
}

// @Ok
void CBit::Die(void){
	print_if_false(this->mProtected == 0, "A protected bit die");
	this->mDead = 1;
}

// @Ok
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

// @Ok
void CBit::SetPos(const CVector &pos){

	this->mPos = pos;
}


// @Ok
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

// @Ok
void CQuadBit::SetTint(unsigned char a2, unsigned char a3, unsigned char a4)
{
  this->mTint = a2 | ((a4 << 16) & 0xFF0000 | (a3 << 8) & 0xFF00) & 0xFFFFFF00;
}


// @Ok
void CQuadBit::SetSemiTransparent()
{
	this->mCodeBGR = (this->mCodeBGR & 0xFFFFFFFE) | 0x2C0;
}

// @Ok
void CQuadBit::SetOpaque(){
	this->mCodeBGR = (this->mCodeBGR & 0xFFFFFDBF) | 0x80;
}


// @Ok
void CQuadBit::SetSubtractiveTransparency(){
	this->mCodeBGR = (this->mCodeBGR & 0xFFFFFF7F) | 0x340;
}

// @Ok
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


// @Ok
void CFT4Bit::SetSemiTransparent(){
	this->mCodeBGR |= 0x2000000;
}

// @Ok
void CFT4Bit::SetTransparency(unsigned char t){
	this->mCodeBGR = t | this->mCodeBGR & 0xFF000000 | ((t | (t << 8)) << 8);
}

static int * const gAnimTable = (int*)0x0056EA64;
static const unsigned int maxANimTableEntry = 0x1D;

// @Ok
void CFT4Bit::SetAnim(int a2){

	char v5; // cl

	print_if_false(a2 >= 0 && !((unsigned int)a2 >= maxANimTableEntry), "Bad lookup value sent to SetAnim");
	print_if_false(this->mDeleteAnimOnDestruction == 0, "mDeleteAnimOnDestruction set?");

	int v4 = gAnimTable[a2];
	this->mPSXAnim = reinterpret_cast<SCFT4BitTexture*>(v4);
	v5 = *(char *)(v4 - 4);
	this->field_53 = 0;
	this->field_51 = v5;
	this->field_52 = 0;
	this->field_4C = this->mPSXAnim;
}

// @Ok
void CFT4Bit::SetTint(unsigned char a2, unsigned char a3, unsigned char a4)
{
	int tmp = this->mCodeBGR & 0xFF000000;
	this->mCodeBGR = a2 | tmp | (((a4 << 8) | a3) << 8);
}

// @Ok
void CFT4Bit::SetTexture(Texture* a2)
{
	int v4; // ecx
	int v5; // eax
	int v6; // edx
	int v7; // ecx

	print_if_false(this->mPSXAnim == 0, "mpPSXAnim already set?");
	print_if_false(a2 != 0, "No Texture for SetTexture");

	this->mPSXAnim = (SCFT4BitTexture *)DCMem_New(8, 0, 1, 0, 1);

	this->mDeleteAnimOnDestruction = 1;

	v4 = (unsigned __int8)a2->field_9;
	v5 = (unsigned __int8)a2->field_4 - (unsigned __int8)a2->field_0;
	v6 = (unsigned __int8)a2->field_1;

	this->mPSXAnim->field_2 = v5;

	v7 = v4 - v6;
	this->mPSXAnim->field_3 = v7;
	this->mPSXAnim->field_0 = v5 / -2;
	this->mPSXAnim->field_1 = v7 / -2;
	this->mPSXAnim->field_4 = (int)a2;
	this->field_4C = this->mPSXAnim;

	this->field_51 = 1;
}

// @TODO
int Bit_MakeSpriteRing(CVector*, int, int, int, int, int, int, int)
{
	return 0x420690;
}

// @Ok
void CBit::Move(void)
{
}

// @Ok
void MoveList(CBit *pBit)
{
	for (CBit *p = pBit; p; p = p->mNext)
	{
		if (!p->mDead)
			p->Move();
	}
}

static unsigned char gSparkR;
static unsigned char gSparkG;
static unsigned char gSparkB;

// @NotOk
// Globals
void Bit_SetSparkRGB(unsigned char r, unsigned char g, unsigned char b)
{
	gSparkR = r;
	gSparkG = g;
	gSparkB = b;
}

static unsigned char gSparkFadeR;
static unsigned char gSparkFadeG;
static unsigned char gSparkFadeB;

// @NotOk
// Globals
void Bit_SetSparkFadeRGB(unsigned char r, unsigned char g, unsigned char b)
{
	gSparkFadeR = r;
	gSparkFadeG = g;
	gSparkFadeB = b;
}

// @NotOk
// globals
CSpecialDisplay::CSpecialDisplay(void)
{
	this->AttachTo(reinterpret_cast<CBit**>(0x56EB34));
}

// @Ok
void CGlow::SetCentreRGB(unsigned char a2, unsigned char a3, unsigned char a4)
{
	this->field_4C = 0x32000000 | (((a4 << 8) | a3) << 8) | a2;
}

static CSVector gSparkTrajectory;

// @NotOk
// global
void Bit_SetSparkTrajectory(const CSVector *pVec)
{
	gSparkTrajectory = *pVec;
}

static CSVector gSparkTrajectoryCone;

// @NotOk
// global
void Bit_SetSparkTrajectoryCone(const CSVector *pVec)
{
	gSparkTrajectoryCone = *pVec;
}

// @Ok
CFT4Bit::CFT4Bit(void)
{
	this->mAnimSpeed = 0x80;
	this->mScale = 400;
	this->mCodeBGR = 0x2C808080;
}

// @NotOk
// globals
CLinked2EndedBit::CLinked2EndedBit(void)
{
	this->field_58.Zero();
	this->field_64.Zero();

	this->AttachTo(reinterpret_cast<CBit**>(0x56EB40));
}

// @Ok
void CRibbonBit::Move(void)
{
	this->IncFrameWithWrap();
}

// @TODO
void CFT4Bit::IncFrameWithWrap(void)
{
}

// @Ok
void CTexturedRibbon::SetOuterRGBi(int index, unsigned char a3, unsigned char a4, unsigned char a5)
{
	this->field_60[index+1] = (a3 | (((a5 << 8) | a4) << 8));
}

// @NotOk
// understand what 3C is
void CGlow::SetRadius(int radius)
{
	for (int i = 0; i < this->field_44; i++)
	{
		this->field_3C[2*i] = radius;
	}
}

// @Ok
// slightly different register allocation
void CSimpleTexturedRibbon::SetRGB(unsigned char r, unsigned char g, unsigned char b)
{
	int value = (r | (((b << 8) | g) << 8));
	int *ptr = this->field_48;

	int i = 0;
	for (i = 0; i < this->field_3C + 1; i++)
		ptr[i] = value;
}

// @Ok
void CGlow::SetRGB(unsigned char r, unsigned char g, unsigned char b)
{
	int value = (r | (((b << 8) | g) << 8));

	for (unsigned int i = 0; i < this->field_44; i++)
	{
		this->field_3C[(2*i)+1] = value;
	}
}

// @TODO
void Bit_ReduceRGB(unsigned int*, int)
{}

// @Ok
void CFT4Bit::SetFrame(int a2)
{
	print_if_false(a2 >= 0 && a2 < this->field_51, "Bad frame sent to SetFrame");
	print_if_false(this->mPSXAnim != 0, "SetFrame called before SetAnim");

	this->field_52 = a2;
	this->field_53 = 0;

	this->field_4C = &this->mPSXAnim[(char)a2];
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
	VALIDATE(CFT4Bit, mPSXAnim, 0x48);
	VALIDATE(CFT4Bit, field_4C, 0x4C);

	VALIDATE(CFT4Bit, field_51, 0x51);
	VALIDATE(CFT4Bit, field_52, 0x52);
	VALIDATE(CFT4Bit, field_53, 0x53);

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
	VALIDATE(CBit, mDead, 0x37);
	VALIDATE(CBit, mFrigDeltaZ, 0x38);
	VALIDATE(CBit, mProtected, 0x3A);
}

void validate_CSmokeTrail(void)
{
	VALIDATE_SIZE(CSmokeTrail, 0x58);
}

void validate_CGlow(void)
{
	VALIDATE_SIZE(CGlow, 0x5C);

	VALIDATE(CGlow, field_3C, 0x3C);
	VALIDATE(CGlow, field_44, 0x44);

	VALIDATE(CGlow, field_4C, 0x4C);

	VALIDATE(CGlow, field_54, 0x54);
}

void validate_CLinked2EndedBit(void)
{
	VALIDATE_SIZE(CLinked2EndedBit, 0x70);

	VALIDATE(CLinked2EndedBit, field_58, 0x58);
	VALIDATE(CLinked2EndedBit, field_64, 0x64);
}

void validate_CRibbonBit(void)
{
	VALIDATE_SIZE(CRibbonBit, 0x70);
}

void validate_CTexturedRibbon(void)
{
	VALIDATE(CTexturedRibbon, field_60, 0x60);
}

void validate_CSimpleTexturedRibbon(void)
{
	VALIDATE_SIZE(CSimpleTexturedRibbon, 0x4C);

	VALIDATE(CSimpleTexturedRibbon, field_3C, 0x3C);
	VALIDATE(CSimpleTexturedRibbon, field_48, 0x48);
}

void validate_CSimpleAnim(void)
{
}

void validate_SCFT4BitTexture(void)
{
	VALIDATE_SIZE(SCFT4BitTexture, 0x8);

	VALIDATE(SCFT4BitTexture, field_0, 0x0);
	VALIDATE(SCFT4BitTexture, field_1, 0x1);
	VALIDATE(SCFT4BitTexture, field_2, 0x2);
	VALIDATE(SCFT4BitTexture, field_3, 0x3);

	VALIDATE(SCFT4BitTexture, field_4, 0x4);
}
