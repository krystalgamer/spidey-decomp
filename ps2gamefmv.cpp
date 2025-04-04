#include "ps2gamefmv.h"
#include "ps2redbook.h"
#include "PCMovie.h"
#include "spidey.h"
#include "front.h"
#include "ps2pad.h"
#include "PCShell.h"
#include "tweak.h"

#include "validate.h"

EXPORT i32 GameFMV_Active;
EXPORT u8 GameFMV_CurrentTrack;

EXPORT i32 gGameFmvOne;
EXPORT u8 gGameFmvTwo;

EXPORT u16 GameFMV_Width;
EXPORT u16 GameFMV_Height;
EXPORT i32 GameFMV_EndFrame;

EXPORT i32 gGameFmvPad;


#define NUM_MOVIES 27

// @NotOk
// @FIXME
SMovieDetails movieDetails[NUM_MOVIES];

// @Ok
// @Matching
u8 GameFMV_PlayMovie(
		u8 a1,
		bool a2,
		bool a3,
		f32 a4)
{
	Redbook_XAStop();
	gSaveGame.field_88 |= 1 << a1;
	if (MechList)
		MechList->StopAlertMusic();

	GameFMV_StopFMV();

	gGameFmvPad = 0;

	if (PCMOVIE_Play(movieDetails[a1].name, a3))
	{
		GameFMV_Active = 1;
		Front_ClearScreen();

		i32 v4 = gGameState[11] * a4;
		if (v4 > 255)
			v4 = 255;
		PCMOVIE_SetVolume(v4);
		Pad_ClearTriggers(gSControl);

		while (PCMOVIE_NextFrame())
		{
			gGameFmvPad++;
			if (Pad_Update() ||
					a2 &&
					gGameFmvPad >= 60 &&
					PCSHELL_CheckTriggers(0x7000000, 1, 1))
			{
				gSControl[0].Start.Triggered = 0;
				break;
			}
		}


		PCMOVIE_Stop();
		Pad_ActuatorOff(0, 0);
		Pad_ActuatorOff(0, 1);
		Pad_ClearTriggers(gSControl);
		GameFMV_Active = 0;

		Front_ClearScreen();
		return 1;
	}

	return 0;
}

// @Ok
int GameFMV_GetNumMovies(void)
{
	return NUM_MOVIES;
}

// @Ok
int PShell_GetNumCostumePSXs(void)
{
	return 10;
}

// @Ok
// @Matching
void GameFMV_Init(void)
{
	PCMOVIE_Init();
}

// @Ok
// @Matching
void GameFMV_SetStartTrack(u8 track)
{
	if ( !GameFMV_Active )
	{
		print_if_false(track < 27u, "Bad track");
		print_if_false(GameFMV_Active == 0, "Track change when active");

		GameFMV_CurrentTrack = track;

		GameFMV_Width = movieDetails[track].width;
		GameFMV_Height = movieDetails[track].height;

		GameFMV_EndFrame = movieDetails[track].endframe;

		gGameFmvTwo = movieDetails[track].field_10;
		gGameFmvOne = movieDetails[track].field_14;
	}
}

// @Ok
// @Matching
INLINE void GameFMV_StopFMV(void)
{
	if (GameFMV_Active)
	{
		PCMOVIE_Stop();
		GameFMV_Active = 0;
	}
}

void validate_SMovieDetails(void)
{
	VALIDATE_SIZE(SMovieDetails, 0x18);

	VALIDATE(SMovieDetails, name, 0x0);

	VALIDATE(SMovieDetails, width, 0x4);
	VALIDATE(SMovieDetails, height, 0x6);
	VALIDATE(SMovieDetails, endframe, 0x8);

	VALIDATE(SMovieDetails, field_10, 0x10);
	VALIDATE(SMovieDetails, field_14, 0x14);
}
