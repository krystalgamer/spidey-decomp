#define WINDOWS_LEAN_AND_MEAN

#include <windows.h>
#include "vector.h"
#include "friction.h"

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
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR lpCmdLine, int nCmdShow)
{
	compile_time_assertions();
    return 0;
}