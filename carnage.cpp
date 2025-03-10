#include "carnage.h"
#include "validate.h"
#include "trig.h"
#include "panel.h"
#include "spool.h"
#include "effects.h"

extern const char *gObjFile;
extern CBaddy *BaddyList;
EXPORT u8 gObjFileRegion;

#define NUM_CARNAGE_GOOS 19

//@FIXME
EXPORT SSkinGooSource gCarnageSkinGooSource[NUM_CARNAGE_GOOS];

// @Ok
// @Matching
void Carnage_RelocatableModuleClear(void)
{
	CItem *pSearch = BaddyList;

	while (pSearch)
	{
		CItem *pNext = pSearch->field_20;

		if (pSearch->field_38 == 314)
			delete pSearch;

		pSearch = pNext;
	}
}

// @Ok
// @Matching
void SetTheCarnageGooSourcesChecksums(void)
{
	for (i32 i = 0; i < NUM_CARNAGE_GOOS; i++)
	{
		if (gCarnageSkinGooSource[i].field_4 == 0x45F3EC38)
		{
			gCarnageSkinGooSource[i].field_4 = Spool_FindTextureChecksum("carnage_bit04_32");
		}
		else if (gCarnageSkinGooSource[i].field_4 == 0xD291D41B)
		{
			gCarnageSkinGooSource[i].field_4 = Spool_FindTextureChecksum("carnage_bit03_32");
		}
		else if (gCarnageSkinGooSource[i].field_4 == 0x6CF38ACE)
		{
			gCarnageSkinGooSource[i].field_4 = Spool_FindTextureChecksum("carnage_bit01_32");
		}

		if (gCarnageSkinGooSource[i].field_8 == 0x45F3EC38)
		{
			gCarnageSkinGooSource[i].field_8 = Spool_FindTextureChecksum("carnage_bit04_32");
		}
		else if (gCarnageSkinGooSource[i].field_8 == 0xD291D41B)
		{
			gCarnageSkinGooSource[i].field_8 = Spool_FindTextureChecksum("carnage_bit03_32");
		}
		else if (gCarnageSkinGooSource[i].field_8 == 0x6CF38ACE)
		{
			gCarnageSkinGooSource[i].field_8 = Spool_FindTextureChecksum("carnage_bit01_32");
		}
	}
}

// @Ok
// @Matching
void Carnage_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = Carnage_RelocatableModuleClear;
	pMod->field_C[0] = Carnage_CreateCarnage;

	SetTheCarnageGooSourcesChecksums();
}

// @SMALLTODO
CCarnageHitSpark::CCarnageHitSpark(CVector*)
{
	printf("CCarnageHitSpark::CCarnageHitSpark(CVector*);");
}

// @Ok
CCarnageHitSpark::~CCarnageHitSpark(void)
{
}

// @Ok
CCarnage::~CCarnage(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));
	Panel_DestroyHealthBar();

	if (this->field_32C)
		delete reinterpret_cast<CItem*>(this->field_32C);

	if (this->field_344)
		Mem_Delete(this->field_344);
}

// @NotOk
// globals
CCarnage::CCarnage(int* a2, int a3)
{
	this->field_334 = 0;
	this->field_338 = 0;
	this->field_33C = 0;
	this->field_370 = 0;
	this->field_374 = 0;
	this->field_378 = 0;


	this->SquirtAngles(reinterpret_cast<i16*>(this->SquirtPos(a2)));
	this->InitItem("carnage");
	this->AttachTo(reinterpret_cast<CBody**>(0x56E9900));

	this->mFlags |= 0x480;
	this->field_3C = 0x548980;
	this->field_194 = 278528;

	this->field_38 = 314;
	this->field_31C.bothFlags = 1;

	this->field_E2 = 3000;
	this->field_DC = 160;
	this->field_21E = 100;
	this->field_35C = 1;
	this->field_354 = 241;

	unsigned __int16 *LinksPointer = reinterpret_cast<unsigned __int16*>(Trig_GetLinksPointer(a3));
	print_if_false(*LinksPointer == 1, "Error");
	this->field_358 = LinksPointer[1];
	Panel_CreateHealthBar(this, 314);
	CreateSonicBubbleVertexWobbler();
}

// @MEDIUMTODO
void CreateSonicBubbleVertexWobbler(void)
{}

// @Ok
void Carnage_CreateCarnage(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CCarnage(v2, v3));
}


// @NotOk
// globals
CSonicBubble::CSonicBubble(void)
{
	this->InitItem(gObjFile);

	this->mModel = Spool_GetModel(0xE9DD4877, gObjFileRegion);
	this->AttachTo(reinterpret_cast<CBody**>(0x56E9900));

	this->mCBodyFlags &= 0xFFFFFFEF;
	this->field_DC = 0;
}

// @Ok
void CSonicBubble::SetScale(int scale)
{
	this->field_28 = 0;
	this->field_2A = 0;
	this->field_2C = 0;
	this->mFlags |= 0x200;
}


extern CBaddy* BaddyList;

// @NotOk
// globals
CSonicBubble::~CSonicBubble(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));
}

// @Ok
void CCarnage::Shouldnt_DoPhysics_Be_Virtual(void)
{
	this->DoPhysics();
}

// @Ok
INLINE CCarnageElectrified::CCarnageElectrified(CSuper* pSuper)
{
	print_if_false(pSuper != 0, "NULL pSuper sent to CVenomWrap");
	print_if_false(pSuper->field_38 == 314, "Non carnage sent to CCarnageElectrified");

	this->field_3C = Mem_MakeHandle(pSuper);
}

// @Ok
CCarnageElectrified::~CCarnageElectrified(void)
{
}

// @BIGTODO
void CCarnage::DoPhysics(void)
{}

void validate_CCarnage(void){
	VALIDATE_SIZE(CCarnage, 0x37C);

	VALIDATE(CCarnage, field_32C, 0x32C);

	VALIDATE(CCarnage, field_334, 0x334);
	VALIDATE(CCarnage, field_338, 0x338);

	VALIDATE(CCarnage, field_33C, 0x33C);

	VALIDATE(CCarnage, field_344, 0x344);

	VALIDATE(CCarnage, field_354, 0x354);
	VALIDATE(CCarnage, field_358, 0x358);
	VALIDATE(CCarnage, field_35C, 0x35C);
	VALIDATE(CCarnage, field_36C, 0x36C);
	VALIDATE(CCarnage, field_370, 0x370);
	VALIDATE(CCarnage, field_374, 0x374);
	VALIDATE(CCarnage, field_378, 0x378);
}

void validate_CSonicBubble(void)
{
	VALIDATE_SIZE(CSonicBubble, 0xF8);

	VALIDATE(CSonicBubble, field_F4, 0xF4);
}

void validate_CCarnageElectrified(void)
{
	VALIDATE_SIZE(CCarnageElectrified, 0x48);

	VALIDATE(CCarnageElectrified, field_3C, 0x3C);
	VALIDATE(CCarnageElectrified, field_44, 0x44);
}

void validate_CCarnageHitSpark(void)
{
	VALIDATE_SIZE(CCarnageHitSpark, 0x84);
}
