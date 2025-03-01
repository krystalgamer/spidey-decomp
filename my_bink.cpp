#include "my_bink.h"
#include "validate.h"

void STDCALL BinkCopyToBuffer(HBINK, void*, u32, u32, u32, u32, u32)
{
	printf("void BinkCopyToBuffer(HBINK, void*, u32, u32, u32, u32, u32)");
}

void STDCALL BinkNextFrame(HBINK)
{
	printf("void STDCALL BinkNextFrame(HBINK)");
}

void STDCALL BinkDoFrame(HBINK)
{
	printf("void STDCALL BinkDoFrame(HBINK)");
}

void STDCALL BinkGetSummary(HBINK, BINKSUMMARY*)
{
	printf("void STDCALL BinkGetSummary(HBINK, BINKSUMMARY*)");
}

void STDCALL BinkSetVideoOnOff(HBINK, i32)
{
	printf("void STDCALL BinkSetVideoOnOff(HBINK, i32)");
}

HBINK STDCALL BinkOpen(void*, i32)
{
	printf("i32 STDCALL BinkOpen(const char*, i32)");
	return reinterpret_cast<HBINK>(0x03012025);
}

i32 STDCALL BinkDDSurfaceType(LPDIRECTDRAWSURFACE7)
{
	printf("void i32 STDCALL BinkDDSurfaceType(LPDIRECTDRAWSURFACE7)");
	return 0x030102025;
}

void STDCALL BinkSetIOSize(i32)
{
	printf("void STDCALL BinkSetIOSize(i32)");
}

void STDCALL BinkSetSoundSystem(void (STDCALL *fptr)(void), LPDIRECTSOUND8)
{
	printf("void STDCALL BinkSetSoundSystem((*fptr)(void), i32)");
}

void STDCALL BinkOpenDirectSound(void)
{
	printf("void STDCALL BinkOpenDirectSound(void)");
}

void STDCALL BinkSetVolume(HBINK, i32)
{
	printf("void BinkSetVolume(i32, i32)");
}

void STDCALL BinkSetPan(HBINK, i32)
{
	printf("void BinkSetPan(i32, i32)");
}

void STDCALL BinkClose(HBINK)
{
	printf("void BinkClose(HANDLE)");
}

i32 STDCALL BinkWait(HBINK)
{
	printf("i32 BinkWait(i32)");
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
