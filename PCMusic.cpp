#include "PCMusic.h"
#include "SpideyDX.h"
#include "my_bink.h"
#include "DXinit.h"
#include "pcdcFile.h"

EXPORT u8 gPcMusicInited;
EXPORT volatile HBINK gMusicBinkHandle;
EXPORT u8 gPcMusicStatusTwo;
EXPORT u8 gPcMusicStatusThree;
EXPORT u8 gPcMusicStatusFour;

EXPORT HANDLE gMusicFileHandle;

// @NotOk
// @Note: validate when used
INLINE void CloseMusicFile(void)
{
	if (gMusicBinkHandle)
	{
		BinkClose(gMusicBinkHandle);
		gdFsClose(gMusicFileHandle);
		gMusicBinkHandle = 0;
	}
}

// @SMALLTODO
void MusicThreadProc(void *)
{
    printf("MusicThreadProc(void *)");
}

// @SMALLTODO
void NextFrame(void)
{
    printf("NextFrame(void)");
}

// @SMALLTODO
void OpenMusicFile(char *,bool)
{
    printf("OpenMusicFile(char *,bool)");
}

// @Ok
// @Matching
void PCMUSIC_Finish(void)
{
	WinYield();
}

// @Ok
// @Matching
i32 PCMUSIC_GetStatus(void)
{
	if (gMusicBinkHandle)
	{
		if (gPcMusicStatusTwo || gPcMusicStatusThree && !gPcMusicStatusFour)
			return gMusicBinkHandle->FrameNum == gMusicBinkHandle->Frames;

		return 0;
	}

	return 1;
}

// @Ok
// @Matching
void PCMUSIC_Init(void)
{
	if (g_pDS)
	{
		if (!gPcMusicInited)
		{
			BinkSetSoundSystem(BinkOpenDirectSound, g_pDS);
			BinkSetIOSize(256);

			gPcMusicInited = 1;
		}
	}
}

// @SMALLTODO
void PCMUSIC_Pause(i32)
{
    printf("PCMUSIC_Pause(i32)");
}

// @SMALLTODO
void PCMUSIC_Play(i32)
{
    printf("PCMUSIC_Play(i32)");
}

// @Ok
// @Matching
void PCMUSIC_SetVolume(i32 vol)
{
	if (g_pDS)
	{
		if (vol < -179)
			vol = -179;

		f32 v1 = static_cast<f32>(vol);
		BinkSetVolume(
				gMusicBinkHandle,
				static_cast<i32>(((v1 + 179.0) / 179.0 * 49152.0)));
		BinkSetPan(gMusicBinkHandle, 0x8000);
	}
}

// @SMALLTODO
void PCMUSIC_Stop(void)
{
    printf("PCMUSIC_Stop(void)");
}
