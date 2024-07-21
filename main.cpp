#define WINDOWS_LEAN_AND_MEAN

#ifdef _WIN32
#include <windows.h>
#else
#define WINAPI
#define HINSTANCE int
#define PSTR char*
#endif


#include "main.h"
#include "ob.h"
#include "vector.h"
#include "friction.h"
#include "bit.h"
#include "front.h"
#include "pshell.h"
#include "baddy.h"
#include "mj.h"
#include "submarin.h"
#include "venom.h"
#include "ps2funcs.h"
#include "blackcat.h"
#include "torch.h"
#include "hostage.h"
#include "cop.h"
#include "carnage.h"
#include "chopper.h"
#include "docock.h"
#include "jonah.h"
#include "lizard.h"
#include "lizman.h"
#include "mysterio.h"
#include "platform.h"
#include "rhino.h"
#include "scorpion.h"
#include "simby.h"
#include "spclone.h"
#include "superock.h"
#include "thug.h"
#include "turret.h"
#include "shell.h"
#include "web.h"
#include "bit2.h"
#include "camera.h"
#include "quat.h"
#include "mem.h"
#include "exp.h"
#include "m3dcolij.h"
#include "m3dinit.h"
#include "spidey.h"
#include "message.h"
#include "bullet.h"
#include "trig.h"
#include "effects.h"
#include "FontTools.h"
#include "wire.h"
#include "powerup.h"
#include "switch.h"
#include "chain.h"
#include "Image.h"
#include "ps2pad.h"
#include "bitmap256.h"
#include "PCTex.h"
#include "smoke.h"
#include "panel.h"
#include "manipob.h"
#include "mess.h"
#include "ai.h"
#include <cstring>
#include "spool.h"
#include "l1a3bomb.h"

// @Ok
void* CClass::operator new(size_t size)
{
	void *result = DCMem_New(size, 0, 1, 0, 1);

	unsigned int adjusted_size = ((size + 3) & 0xFFFFFFFC) >> 2;
	if ( adjusted_size )
		memset(result, 0, 4 * adjusted_size);

	return result;
}

// @Ok
void CClass::operator delete(void *ptr)
{
	Mem_Delete(ptr);
}

// @Ok
CClass::~CClass()
{
}

template<bool b>

struct StaticAssert{};



template<>

struct StaticAssert<true>

{

	static void assert() {}
};

void compile_time_assertions(){
	StaticAssert<sizeof(CVector)==12>::assert();
	StaticAssert<sizeof(CFriction)==3>::assert();
	//StaticAssert<sizeof(CBit) == 0x38>::assert();

	//StaticAssert<sizeof(CMenu)==0x53C>::assert();

	//StaticAssert<sizeof(CExpandingBox)==52>::assert();

	StaticAssert<sizeof(CSVector)==6>::assert();

	StaticAssert<sizeof(SVector)==6>::assert();

	StaticAssert<sizeof(CQuadBit)==0x84>::assert();

	//StaticAssert<sizeof(CMJ)==0x324>::assert();

	StaticAssert<sizeof(MATRIX)==0x20>::assert();

	StaticAssert<sizeof(u32)==4>::assert();
	StaticAssert<sizeof(u16)==2>::assert();
	StaticAssert<sizeof(u8)==1>::assert();

	StaticAssert<sizeof(i32)==4>::assert();
	StaticAssert<sizeof(i16)==2>::assert();
	StaticAssert<sizeof(i8)==1>::assert();
}

extern int FAIL_VALIDATION;

#ifdef _OLD_WINDOWS
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR lpCmdLine, int nCmdShow)
#else
int main()
#endif
{
	compile_time_assertions();


#ifdef _OLD_WINDOWS
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
#endif



	puts("[*] Starting validation");



	validate_CItem();

	validate_CVector();

	validate_CSVector();

	validate_CBit();

	validate_CQuadBit();

	validate_CFT4Bit();

	validate_CFlatBit();

	validate_CBody();

	validate_SVector();

	validate_CSuper();

	validate_CBaddy();

	validate_CMJ();

	validate_CSubmariner();

	validate_CVenom();

	validate_CBlackCat();

	validate_CTorch();

	validate_CHostage();

	validate_CScriptOnlyBaddy();

	validate_CCop();

	validate_CCarnage();

	validate_CChopper();

	validate_CDocOc();

	validate_CJonah();

	validate_CLizard();

	validate_CLizMan();

	validate_CMystFoot();

	validate_CMysterio();

	validate_CSoftSpot();

	validate_CPlatform();

	validate_CRhino();

	validate_CScorpion();

	validate_CPunchOb();

	validate_CSimby();

	validate_CSimbyBase();

	validate_CSpClone();

	validate_CSuperDocOck();

	validate_CThug();

	validate_CTurret();

	validate_MATRIX();

	validate_CRudeWordHitterSpidey();

	validate_CBulletFrag();

	validate_CImpactWeb();

	validate_CDomePiece();

	validate_CDome();

	validate_CDomeRing();

	validate_CWeb();

	validate_CSwinger();

	validate_CTurretBase();

	validate_CDummy();

	validate_CSniperSplat();

	validate_SStateFlags();
	validate_CGPolyLine();
	validate_CCamera();
	validate_CQuat();
	validate_SBlockHeader();
	validate_SHandle();
	validate_CItemFrag();
	validate_SLineInfo();
	validate_STexWibItemInfo();
	validate_CPlayer();
	validate_CSmokeTrail();
	validate_CMessage();
	validate_CTrapWebEffect();
	validate_CMenu();
	validate_SEntry();
	validate_CBullet();
	validate_SLinkInfo();
	validate_CElectrify();
	validate_CSimbySlimeBase();
	validate_CMysterioLaser();
	validate_Font();
	validate_CTurretLaser();
	validate_CLaserFence();
	validate_CGoldFish();
	validate_CPowerUp();
	validate_CSwitch();
	validate_CChain();
	validate_CGLine();
	validate_SlicedImage();
	validate_Image();
	validate_SControl();
	validate_Bitmap256();
	validate_WeirdTextureHolder();
	validate_CPolyLine();
	validate_CSonicBubble();
	validate_CGlow();
	validate_CLinked2EndedBit();
	validate_CRibbonBit();
	validate_CSniperTarget();
	validate_CVenomWrap();
	validate_CSmokeJet();
	validate_CTexturedRibbon();
	validate_CDomeShockWave();
	validate_CMysterioHeadCircle();
	validate_SAnimFrame();
	validate_CFadePalettes();
	validate_CSimpleTexturedRibbon();
	validate_CManipOb();
	validate_SimpleMessage();
	validate_CShellMysterioHeadGlow();
	validate_CWobblyGlow();
	validate_CSimpleAnim();
	validate_CCopPing();
	validate_SHook();
	validate_Spidey_CIcon();
	validate_CEmber();
	validate_CThugPing();
	validate_CAIProc();
	validate_CAIProc_LookAt();
	validate_Texture();
	validate_SCFT4BitTexture();
	validate_CRhinoNasalSteam();
	validate_CAIProc_RotY();
	validate_CAIProc_Fall();
	validate_CAIProc_StateSwitchSendMessage();
	validate_CAIProc_MonitorAttack();
	validate_CAIProc_AccZ();
	validate_SMoveToInfo();
	validate_CAIProc_MoveTo();
	validate_CNonRenderedBit();
	validate_SPSXRegion();
	validate_CSimbyShot();
	validate_CVenomElectrified();
	validate_CCarnageElectrified();
	validate_CConstantLaser();
	validate_CShellSymBurn();
	validate_CExpandingBox();
	validate_CL1A3Bomb();
	validate_CMotionBlur();
	validate_SHitInfo();
	validate_SCommandPoint();
	validate_PendingListEntry();
	validate_CSpecialDisplay();
	validate_CSkidMark();
	validate_TextureEntry();
	validate_CShellVenomElectrified();
	validate_CSkinGoo();
	validate_SSkinGooSource();
	validate_SSkinGooSource2();
	validate_SSkinGooParams();
	validate_CShellCarnageElectrified();
	validate_CShellSuperDocOckElectrified();
	validate_CShellRhinoNasalSteam();
	validate_CShellEmber();
	validate_CShellSimbyMeltSplat();
	validate_CShellSimbyFireDeath();
	validate_CShellGoldFish();

	puts("[*] Validation done!");


#ifdef _OLD_WINDOWS
	CItem* items = new CItem[1];
	__asm {

		      //int 3

			 }
	while(1){}
#endif



    return FAIL_VALIDATION;
}
