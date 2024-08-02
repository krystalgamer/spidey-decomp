#include "export.h"
#include "bit.h"
#include "mem.h"
#include <cstring>
#include <cstdlib>
#include "validate.h"
#include "spool.h"


EXPORT CChunkBit* ChunkBitList;
EXPORT CGlow* GlowList;
EXPORT CTextBox* TextBoxList;

volatile static i32 BitCount = 0;
EXPORT i32 TotalBitUsage = 0;

EXPORT CFlatBit *FlatBitList;
EXPORT CSpecialDisplay *SpecialDisplayList;

EXPORT SFlatBitVelocity FlatBitVelocities[FLATBIT_VELOCITIES_SIZE];

EXPORT CPixel* PixelList;

// @SMALLTODO
CTextBox::CTextBox(i32, i32, i32, i32, u32, CVECTOR*)
{
	printf("CTextBox::CTextBox(i32, i32, i32, i32, u32, CVECTOR*)");
}

CTextBox::~CTextBox(void)
{
	this->DeleteFrom(reinterpret_cast<CBit**>(&TextBoxList));
}

// @SMALLTODO
CChunkBit::CChunkBit(CSVector*, CSVector*, CSVector*)
{
	printf("CChunkBit::CChunkBit(CSVector*, CSVector*, CSVector*)");
}

// @Ok
CChunkBit::~CChunkBit(void)
{
	this->DeleteFrom(reinterpret_cast<CBit**>(&ChunkBitList));
}


// @SMALLTODO
CBitServer::CBitServer(void)
{
}

// @Ok
CBitServer::~CBitServer(void)
{
}

// @Ok
CPixel::~CPixel(void)
{
	this->DeleteFrom(reinterpret_cast<CBit**>(&PixelList));
}

// @Ok
CPixel::CPixel(void)
{
	this->AttachTo(reinterpret_cast<CBit**>(&PixelList));
}

// @SMALLTODO
CFrag::CFrag(CVector*, u8, u8, u8, i32, u16, i32, i32, i32, i32)
{
	printf("CFrag::CFrag(CVector*, u8, u8, u8, i32, u16, i32, i32, i32, i32);");
}

// @SMALLTODO
void CGlow::SetFringeWidth(u32, u32)
{
	printf("CGlow::SetFringeWidth(u32, u32)");
}

// @SMALLTODO
void CGlow::SetFringeRGB(u32, u8, u8, u8)
{
	printf("void CGlow::SetFringeRGB(u32, u8, u8, u8)");
}

// @SMALLTODO
CCombatImpactRing::CCombatImpactRing(CVector*, u8, u8, u8, i32, i32, i32)
{
	printf("CCombatImpactRing::CCombatImpactRing(CVector*, u8, u8, u8, i32, i32, i32)");
}

// @SMALLTODO
CSimpleAnim::CSimpleAnim(CVector*, i32, u16, i32, i32, i32)
{
	printf("CSimpleAnim::CSimpleAnim(CVector*, i32, u16, i32, i32, i32)");
}

// @SMALLTODO
void CRibbon::SetScale(i32)
{
	printf("void CRibbon:SetScale(i32)");
}

// @SMALLTODO
CRibbon::CRibbon(CVector*, i32, i32, i32, i32, i32, i32)
{
	printf("CRibbon::CRibbon(CVector*, i32, i32, i32, i32, i32, i32)");
}

// @SMALLTODO
CSmokeTrail::CSmokeTrail(
		CVector* a2,
		i32 a3,
		i32, i32, i32)
	: CRibbon(a2, a3, 2, 2, 2, 400, 1)
{
	printf("CSmokeTrail::CSmokeTrail(CVector*, i32, i32, i32, i32)");
}

// @SMALLTODO
CGlow::CGlow(u32 a1, u32 a2)
{
}

// @Ok
CGlow::~CGlow(void)
{
	Mem_Delete(static_cast<void*>(this->field_3C));
	this->DeleteFrom(reinterpret_cast<CBit**>(&GlowList));
}

// @MEDIUMTODO
void CQuadBit::OrientUsing(CVector *, SVECTOR *, i32, i32, i32)
{
	printf("CQuadBit::OrientUsing(CVector *, SVECTOR *, i32, i32, i32)");
}

// @NotOk
// @Test
// remove reinterpret cast, understand whta devs did
void CQuadBit::SetTexture(u32 checksum)
{
	Texture *pTexture = Spool_FindTextureEntry(checksum);
	this->mpTexture = pTexture;

	if (pTexture)
	{
		if (pTexture->Usage & 0xF0)
			this->mCodeBGR |= 0x20;

		// @FIXME
		u32* arr = reinterpret_cast<u32*>(pTexture);
		this->field_74 = arr[0];
		this->field_74 = arr[1];
		this->field_74 = arr[2];
		this->field_80 = pTexture->TexWin;
	}
}

// @MEDIUMTODO
CGlow::CGlow(
		CVector* pVector,
		i32 a3,
		i32 a4,
		u8 a5,
		u8 a6,
		u8 a7,
		u8 a8,
		u8 a9,
		u8 a10)
{
	printf("CGlow::CGlow");
}

// @Ok
CFlatBit::~CFlatBit(void)
{
	this->DeleteFrom(reinterpret_cast<CBit**>(&FlatBitList));
}

// @Ok
// @Test
void CMotionBlur::Move(void)
{
	this->mPos.vx += this->mVel.vx;
	this->mPos.vy += this->mVel.vy;
	this->mPos.vz += this->mVel.vz;

	this->mScale -= this->field_3E;
	if (this->mScale < 0)
	{
		this->mScale = 0;
		this->Die();
		return;
	}

    u8 mCodeBGR = this->mCodeBGR;
    i16 mTransDecay = this->mTransDecay;

    u32 v10 = this->mCodeBGR >> 8;
    u32 mCodeBGR_high = (this->mCodeBGR >> 16);

	u8 v18;
    if ( mTransDecay > mCodeBGR )
      v18 = 0;
    else
      v18 = mCodeBGR - (this->mTransDecay & 0xFF);

	u8 v12;
    if ( mTransDecay > (u8)v10 )
      v12 = 0;
    else
      v12 = v10 - (this->mTransDecay & 0xFF);

	u8 v13;
    if ( mTransDecay > (u8)mCodeBGR_high )
      v13 = 0;
    else
      v13 = mCodeBGR_high - (this->mTransDecay & 0xFF);

	u16 v14 = (v13 << 8) | v12;
    this->mCodeBGR = v18 | this->mCodeBGR & 0xFF000000 | (v14 << 8);

	if (!(this->mCodeBGR & 0xFFFFFF))
	{
		this->Die();
		return;
	}

	if ( ++this->field_C & 1)
	{
		if ( ++this->field_52 >= this->field_51 )
			this->field_52 = 0;
	}

	this->field_4C = &this->mPSXAnim[this->field_52];
}

// @Ok
CMotionBlur::CMotionBlur(
		CVector* a2,
		CVector* a3,
		i32 a4,
		i32 a5,
		i32 a6,
		i32 a7)
{
	this->mPos = *a2;
	this->mVel = *a3;
	this->SetAnim(a4);
	this->SetSemiTransparent();
	this->mScale = a5;
	this->field_3E = a6;
	this->mTransDecay = a7;
}

// @Ok
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
void* CBit::operator new(size_t size) {

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

// @NotOk
// revisit, there's a weird mem_delete
CBit::~CBit()
{
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
INLINE void CBit::DeleteFrom(CBit **lst){
	
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

// @Ok
void CQuadBit::SetTransparency(unsigned char a2){
	this->mTint = a2 | ((a2 | (a2 << 8)) << 8);
}

// @MEDIUMTODO
void CQuadBit::OrientUsing(CVector *a2, SVECTOR *a3, int a4, int a5)
{
}

// @MEDIUMTODO
void CQuadBit::SetTexture(int a, int b){
	
}

// @Ok
CFT4Bit::~CFT4Bit()
{
	if (this->mDeleteAnimOnDestruction)
		Mem_Delete(reinterpret_cast<void*>(this->mPSXAnim));
}


// @Ok
void CFT4Bit::SetAnimSpeed(short s){
	this->mAnimSpeed = s;
}

// @Ok
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
void CFT4Bit::SetTexture(Texture* pTexture)
{
	int v4; // ecx
	int v5; // eax
	int v6; // edx
	int v7; // ecx

	print_if_false(this->mPSXAnim == 0, "mpPSXAnim already set?");
	print_if_false(pTexture != 0, "No Texture for SetTexture");

	this->mPSXAnim = (SCFT4BitTexture *)DCMem_New(8, 0, 1, 0, 1);

	this->mDeleteAnimOnDestruction = 1;

	v4 = (unsigned __int8)pTexture->field_9;
	v5 = (unsigned __int8)pTexture->field_4 - (unsigned __int8)pTexture->field_0;
	v6 = (unsigned __int8)pTexture->field_1;

	this->mPSXAnim->field_2 = v5;

	v7 = v4 - v6;
	this->mPSXAnim->field_3 = v7;
	this->mPSXAnim->field_0 = v5 / -2;
	this->mPSXAnim->field_1 = v7 / -2;
	this->mPSXAnim->field_4 = pTexture;
	this->field_4C = this->mPSXAnim;

	this->field_51 = 1;
}

// @Ok
void CFT4Bit::SetTexture(unsigned int Checksum)
{
	int v4; // ecx
	int v5; // eax
	int v6; // edx
	int v7; // ecx

	print_if_false(this->mPSXAnim == 0, "mpPSXAnim already set?");

	Texture *pTexture = Spool_FindTextureEntry(Checksum);
	print_if_false(pTexture != 0, "Bad checksum sent to SetTexture");

	this->mPSXAnim = (SCFT4BitTexture *)DCMem_New(8, 0, 1, 0, 1);

	this->mDeleteAnimOnDestruction = 1;

	v4 = (unsigned __int8)pTexture->field_9;
	v5 = (unsigned __int8)pTexture->field_4 - (unsigned __int8)pTexture->field_0;
	v6 = (unsigned __int8)pTexture->field_1;

	this->mPSXAnim->field_2 = v5;

	v7 = v4 - v6;
	this->mPSXAnim->field_3 = v7;
	this->mPSXAnim->field_0 = v5 / -2;
	this->mPSXAnim->field_1 = v7 / -2;
	this->mPSXAnim->field_4 = pTexture;
	this->field_4C = this->mPSXAnim;

	this->field_51 = 1;
}

// @Ok
// not matching becausae they assign all mCodeBGR at beggining
int CFT4Bit::Fade(int a2)
{
	int mCodeBGR = this->mCodeBGR;

	if (!(mCodeBGR & 0xFFFFFF))
	{
		this->Die();
		return 1;
	}

	unsigned __int16 v6 = this->mTransDecay;
	unsigned char v10;
	if (v6 > (unsigned __int16)(this->mCodeBGR & 0xFF))
		v10 = 0;
	else
		v10 = (this->mCodeBGR & 0xFF) - (this->mTransDecay & 0xFF);

	unsigned char v7;
	if (v6 > (unsigned __int16)((this->mCodeBGR & 0xFF00) >> 8))
		v7 = 0;
	else
		v7 = ((this->mCodeBGR & 0xFF00) >> 8) - (this->mTransDecay & 0xFF);

	unsigned char v8;
	if (v6 > (unsigned __int16)((this->mCodeBGR & 0xFF0000) >> 16))
		v8 = 0;
	else
		v8 = ((this->mCodeBGR & 0xFFFF00) >> 16) - (this->mTransDecay & 0xFF);


	this->mCodeBGR = (mCodeBGR & 0xFF000000) | (((v8 << 8) | v7) << 8) | v10;

	return 0;
}

// @MEDIUMTODO
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

// @Ok
CSpecialDisplay::CSpecialDisplay(void)
{
	this->AttachTo(reinterpret_cast<CBit**>(SpecialDisplayList));
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

// @MEDIUMTODO
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

// @MEDIUMTODO
void Bit_ReduceRGB(unsigned int*, int)
{
	printf("Bit_ReduceRGB");
}

// @Ok
void CFT4Bit::SetFrame(int a2)
{
	print_if_false(a2 >= 0 && a2 < this->field_51, "Bad frame sent to SetFrame");
	print_if_false(this->mPSXAnim != 0, "SetFrame called before SetAnim");

	this->field_52 = a2;
	this->field_53 = 0;

	this->field_4C = &this->mPSXAnim[(char)a2];
}

// @Ok
void CFT4Bit::SetTransDecay(int decay)
{
	this->mTransDecay = decay;
}

// @NotOk
// Globals
CFlatBit::CFlatBit(void)
{
	this->AttachTo(reinterpret_cast<CBit**>(0x56EA50));

	this->mAngFric = 0x32;
	this->field_5E = 1;
	this->mPostScale = 0x10001000;
}

void validate_CFlatBit(void){
	VALIDATE(CFlatBit, field_58, 0x58);
	VALIDATE(CFlatBit, field_5A, 0x5A);
	VALIDATE(CFlatBit, field_5E, 0x5E);
	VALIDATE(CFlatBit, mPostScale, 0x60);
	VALIDATE(CFlatBit, mAngFric, 0x65);
}

void validate_CFT4Bit(void){
	VALIDATE(CFT4Bit, mTransDecay, 0x3C);
	VALIDATE(CFT4Bit, field_3E, 0x3E);

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
	VALIDATE_SIZE(CQuadBit, 0x84);

	VALIDATE(CQuadBit, mPosB, 0x3C);
	VALIDATE(CQuadBit, mPosC, 0x48);
	VALIDATE(CQuadBit, mPosD, 0x54);
	VALIDATE(CQuadBit, mpTexture, 0x60);
	VALIDATE(CQuadBit, mCodeBGR, 0x64);
	VALIDATE(CQuadBit, mTint, 0x6C);

	VALIDATE(CQuadBit, field_74, 0x74);
	VALIDATE(CQuadBit, field_78, 0x78);
	VALIDATE(CQuadBit, field_7C, 0x7C);
	VALIDATE(CQuadBit, field_80, 0x80);
}



void validate_CBit(void)
{
	VALIDATE_SIZE(CBit, 0x3C);
	VALIDATE(CBit, mPrevious, 0x4);
	VALIDATE(CBit, mNext, 0x8);

	VALIDATE(CBit, field_E, 0xE);

	VALIDATE(CBit, mPos, 0x10);
	VALIDATE(CBit, mVel, 0x1C);
	VALIDATE(CBit, mAcc, 0x28);
	VALIDATE(CBit, mDead, 0x37);
	VALIDATE(CBit, mFrigDeltaZ, 0x38);
	VALIDATE(CBit, mProtected, 0x3A);
	VALIDATE(CBit, mType, 0x3B);
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

void validate_CNonRenderedBit(void)
{
	VALIDATE_SIZE(CNonRenderedBit, 0x3C);
}

void validate_CMotionBlur(void)
{
	VALIDATE_SIZE(CMotionBlur, 0x68);
}

void validate_CSpecialDisplay(void)
{
	VALIDATE_SIZE(CSpecialDisplay, 0x3C);
}

void validate_SFlatBitVelocity(void)
{
	VALIDATE_SIZE(SFlatBitVelocity, 0x4);

	VALIDATE(SFlatBitVelocity, vxVel, 0x0);
	VALIDATE(SFlatBitVelocity, vzVel, 0x2);
}

void validate_CCombatImpactRing(void)
{
	VALIDATE_SIZE(CCombatImpactRing, 0x74);
}

void validate_SRibbonPoint(void)
{
	VALIDATE_SIZE(SRibbonPoint, 0x24);

	VALIDATE(SRibbonPoint, Pos, 0x0);
	VALIDATE(SRibbonPoint, r, 0xC);
	VALIDATE(SRibbonPoint, g, 0xD);
	VALIDATE(SRibbonPoint, b, 0xE);
	VALIDATE(SRibbonPoint, Width, 0x10);
	VALIDATE(SRibbonPoint, WidthB, 0x12);
	VALIDATE(SRibbonPoint, rB, 0x14);
	VALIDATE(SRibbonPoint, gB, 0x15);
	VALIDATE(SRibbonPoint, bB, 0x16);
	VALIDATE(SRibbonPoint, Last1Scr, 0x18);
	VALIDATE(SRibbonPoint, Last2Scr, 0x1C);
	VALIDATE(SRibbonPoint, Last3Scr, 0x20);
}

void validate_CFrag(void)
{
	VALIDATE_SIZE(CFrag, 0x68);
}

void validate_CPixel(void)
{
	VALIDATE_SIZE(CPixel, 0x3C);
}

void validate_CBitServer(void)
{
	VALIDATE_SIZE(CBitServer, 0x108);
}

void validate_CChunkBit(void)
{
}

void validate_CTextBox(void)
{
	VALIDATE_SIZE(CTextBox, 0x44);
}
