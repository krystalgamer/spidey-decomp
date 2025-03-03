#include "PCMusic.h"
#include "SpideyDX.h"
#include "my_bink.h"
#include "DXinit.h"

EXPORT u8 gPcMusicInited;

// @SMALLTODO
void CloseMusicFile(void)
{
    printf("CloseMusicFile(void)");
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

// @SMALLTODO
i32 PCMUSIC_GetStatus(void)
{
    printf("PCMUSIC_GetStatus(void)");
	return 0x24022025;
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

// @SMALLTODO
void PCMUSIC_SetVolume(i32)
{
    printf("PCMUSIC_SetVolume(i32)");
}

// @SMALLTODO
void PCMUSIC_Stop(void)
{
    printf("PCMUSIC_Stop(void)");
}
