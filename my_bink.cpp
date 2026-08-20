#include "my_bink.h"
#include "validate.h"

static HMODULE hBink = 0;

#define LOCK_ROUTINE { while(1); }

static INLINE void init_module(void)
{
#ifdef _WIN32
	if (!hBink)
	{
		hBink = GetModuleHandleA("binkw32_.dll");
	}
#endif
}

void STDCALL BinkService(HBINK)
{
	printf("void STDCALL BinkService(HBINK)");
	LOCK_ROUTINE;
}

void STDCALL BinkPause(HBINK, i32)
{
	printf("void STDCALL BinkPause(HBINK, i32)");
	LOCK_ROUTINE;
}

void STDCALL BinkCopyToBuffer(HBINK, void*, u32, u32, u32, u32, u32)
{
	printf("void BinkCopyToBuffer(HBINK, void*, u32, u32, u32, u32, u32)");
	LOCK_ROUTINE;
}

void STDCALL BinkNextFrame(HBINK)
{
	printf("void STDCALL BinkNextFrame(HBINK)");
	LOCK_ROUTINE;
}

void STDCALL BinkDoFrame(HBINK)
{
	printf("void STDCALL BinkDoFrame(HBINK)");
	LOCK_ROUTINE;
}

void STDCALL BinkGetSummary(HBINK, BINKSUMMARY*)
{
	printf("void STDCALL BinkGetSummary(HBINK, BINKSUMMARY*)");
	LOCK_ROUTINE;
}

void STDCALL BinkSetVideoOnOff(HBINK, i32)
{
	printf("void STDCALL BinkSetVideoOnOff(HBINK, i32)");
	LOCK_ROUTINE;
}

HBINK STDCALL BinkOpen(void*, i32)
{
	printf("i32 STDCALL BinkOpen(const char*, i32)");
	LOCK_ROUTINE;
	return reinterpret_cast<HBINK>(0x03012025);
}

i32 STDCALL BinkDDSurfaceType(LPDIRECTDRAWSURFACE7)
{
	printf("void i32 STDCALL BinkDDSurfaceType(LPDIRECTDRAWSURFACE7)");
	LOCK_ROUTINE;
	return 0x030102025;
}

void STDCALL BinkSetIOSize(u32 a1)
{
#ifdef _WIN32
	init_module();

	typedef void (STDCALL *func_ptr)(u32);
	static func_ptr func = (func_ptr)GetProcAddress(hBink, "_BinkSetIOSize@4");
	func(a1);
#endif
}

i32 STDCALL BinkSetSoundSystem(i32 (STDCALL *fptr)(void*), LPDIRECTSOUND8 a2)
{
#ifdef _WIN32
	init_module();

	typedef i32 (STDCALL *func_ptr)(i32 (STDCALL *_ignore)(void*), LPDIRECTSOUND8);
	static func_ptr func = (func_ptr)GetProcAddress(hBink, "_BinkSetSoundSystem@8");

	i32 res = func(fptr, a2);

	return res;
#endif

	return 0;
}

i32 STDCALL BinkOpenDirectSound(void* a1)
{
#ifdef _WIN32
	init_module();


	typedef i32 (STDCALL *func_ptr)(void*);
	static func_ptr func = (func_ptr)GetProcAddress(hBink, "_BinkOpenDirectSound@4");

	i32 res = func(a1);

	return res;
#endif

	return 0;
}

void STDCALL BinkSetVolume(HBINK, i32)
{
	printf("void BinkSetVolume(i32, i32)");
	LOCK_ROUTINE;
}

void STDCALL BinkSetPan(HBINK, i32)
{
	printf("void BinkSetPan(i32, i32)");
	LOCK_ROUTINE;
}

void STDCALL BinkClose(HBINK)
{
	printf("void BinkClose(HANDLE)");
	LOCK_ROUTINE;
}

i32 STDCALL BinkWait(HBINK)
{
	printf("i32 BinkWait(i32)");
	LOCK_ROUTINE;
	return 0x28022024;
}

void validate_BINKSUMMARY(void)
{
	VALIDATE_SIZE(BINKSUMMARY, 0x7C);

	VALIDATE(BINKSUMMARY, Width, 0x0);
	VALIDATE(BINKSUMMARY, Height, 0x4);
}

void validate_BINK(void)
{
	VALIDATE(BINK, Width, 0x0);
	VALIDATE(BINK, Height, 0x4);
	VALIDATE(BINK, Frames, 0x8);
	VALIDATE(BINK, FrameNum, 0xC);
}
