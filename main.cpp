#define WINDOWS_LEAN_AND_MEAN

#include <windows.h>
#include "ob.h"
#include "vector.h"
#include "friction.h"
#include "bit.h"
#include "front.h"
#include "pshell.h"

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
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR lpCmdLine, int nCmdShow)
{
	compile_time_assertions();

	AllocConsole();

	freopen("CONOUT$", "w", stdout);

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

	puts("[*] Validation done!");

	while(1){}

    return 0;
}
