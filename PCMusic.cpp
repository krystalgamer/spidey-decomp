#include "PCMusic.h"
#include "SpideyDX.h"
#include "my_bink.h"
#include "DXinit.h"
#include "pcdcFile.h"

#ifdef _WIN32
#include "process.h"
#else
void _beginthread(void*, i32, i32)
{
}
#endif

EXPORT u8 gPcMusicInited;
EXPORT volatile HBINK gMusicBinkHandle;
EXPORT u8 gPcMusicStatusTwo;
EXPORT u8 gPcMusicStatusThree;
EXPORT u8 gPcMusicStatusFour;

EXPORT HANDLE gMusicFileHandle;

// @Ok
// @Matching
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

// @NotOk
// @Note: validate when inlined
INLINE i32 OpenMusicFile(char *pName, bool a2)
{
	char v2[256];

	strcpy(v2, "Voice\\");
	strcat(v2, pName);
	DXERR_printf("\t\tMUSIC PLAYING %s\r\n", pName);

	gMusicFileHandle = gdFsOpen(v2, 0);
	gMusicBinkHandle = BinkOpen(gMusicFileHandle, BINKFILEHANDLE);

	if (!gMusicBinkHandle)
		return 0;

	if (a2)
		BinkSetVideoOnOff(gMusicBinkHandle, 0);
	else
		BinkSetVideoOnOff(gMusicBinkHandle, 1);
	return 1;
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

// @Ok
// @Matching
void PCMUSIC_Pause(i32 a1)
{
	if (gMusicBinkHandle)
	{
		BinkPause(gMusicBinkHandle, a1);
		if (gPcMusicStatusThree)
		{
			if ( a1 )
			{
				if (!gPcMusicStatusTwo)
				{
					gPcMusicStatusTwo = 1;
					gPcMusicStatusFour = 1;
					do
						Sleep(0xA);
					while (gPcMusicStatusThree);
					gPcMusicStatusThree = 1;
				}
			}
			else if (gPcMusicStatusTwo)
			{
				gPcMusicStatusTwo = 0;
				gPcMusicStatusFour = 0;
				_beginthread(MusicThreadProc, 0, 0);
				WinYield();
			}

		}
	}
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

// @Ok
// @Matching
INLINE void PCMUSIC_Stop(void)
{
	if (gPcMusicStatusThree)
	{
		if (gPcMusicStatusTwo)
		{
			gPcMusicStatusTwo = 0;
			gPcMusicStatusThree = 0;
			gPcMusicStatusFour = 0;
			CloseMusicFile();
		}
		else
		{
			gPcMusicStatusFour = 1;
			do
				Sleep(10);
			while (gPcMusicStatusThree);
		}
	}
}
