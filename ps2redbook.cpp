#include "ps2redbook.h"
#include "utils.h"
#include "stubs.h"
#include "dcfileio.h"

#include <cstring>


EXPORT i32 gADXT;
EXPORT bool gXAAllowed;

u8 gCarnageXaRelated = 1;
u32 gCarnageXaRelatedTwo;

// @Ok
i32 gRedbookXaRelatedOne;
// @Ok
i32 gRedbookXaRelatedTwo;

// handle from ADXT_Create, same global Redbook_XAStat uses
//#define G_ADXT (gADXT)
#define G_ADXT (*reinterpret_cast<i32*>(0x00681D2C))
// set by Redbook_XAAllow, forced back to 1 on every reset
//#define G_XA_ALLOWED (gXAAllowed)
#define G_XA_ALLOWED (*reinterpret_cast<u8*>(0x00550D80))
// -1 when nothing plays
//#define G_REDBOOK_XA_CURRENT_PRIORITY (Redbook_XACurrentPriority)
#define G_REDBOOK_XA_CURRENT_PRIORITY (*reinterpret_cast<i32*>(0x00550D7C))
// set while the redbook device is busy
//#define G_REDBOOK_BUSY (gRedbookBusy)
#define G_REDBOOK_BUSY (*reinterpret_cast<u8*>(0x00682770))
// his IDB names 0x682771 Redbook_XAPaused
//#define G_REDBOOK_XA_PAUSED (Redbook_XAPaused)
#define G_REDBOOK_XA_PAUSED (*reinterpret_cast<u8*>(0x00682771))
// cleared on reset, no known reader yet
//#define G_REDBOOK_RELATED_ONE (gRedbookRelatedOne)
#define G_REDBOOK_RELATED_ONE (*reinterpret_cast<u8*>(0x00682772))
//#define G_REDBOOK_RELATED_TWO (gRedbookRelatedTwo)
#define G_REDBOOK_RELATED_TWO (*reinterpret_cast<u32*>(0x00682774))
//#define G_REDBOOK_RELATED_THREE (gRedbookRelatedThree)
#define G_REDBOOK_RELATED_THREE (*reinterpret_cast<u32*>(0x00682778))
// set once Redbook_XAInit created the ADXT handle
//#define G_ADXT_INITIALIZED (gAdxtInitialized)
#define G_ADXT_INITIALIZED (*reinterpret_cast<u8*>(0x0068277C))
// pending Redbook_XAPlay arguments
//#define G_PENDING_XA_ONE (gPendingXAOne)
#define G_PENDING_XA_ONE (*reinterpret_cast<i32*>(0x00681D3C))
//#define G_PENDING_XA_TWO (gPendingXATwo)
#define G_PENDING_XA_TWO (*reinterpret_cast<i32*>(0x00681D40))
//#define G_PENDING_XA_THREE (gPendingXAThree)
#define G_PENDING_XA_THREE (*reinterpret_cast<i32*>(0x00681D44))
// last error text from the CRI callback, 0x100 bytes
//#define G_REDBOOK_ERROR_MSG (gRedbookErrorMsg)
#define G_REDBOOK_ERROR_MSG (reinterpret_cast<char*>(0x006612E4))
// speech.str partition directory for ADXF_LoadPartition, 0x4F0 bytes
//#define G_ADXF_PARTITION_INFO (gAdxfPartitionInfo)
#define G_ADXF_PARTITION_INFO (reinterpret_cast<void*>(0x00681D74))
// work memory for ADXT_Create, 0x208C4 bytes
//#define G_ADXT_WORK (gAdxtWork)
#define G_ADXT_WORK (reinterpret_cast<void*>(0x006613E4))
// 16 ids per track into speech.str, -1 means no XA there
//#define G_XA_TRACK_IDS (gXATrackIds)
#define G_XA_TRACK_IDS (reinterpret_cast<i16*>(0x0055039C))
// XA voice volume setting, 0 to 255
//#define G_XA_VOLUME (gXAVolume)
#define G_XA_VOLUME (*reinterpret_cast<i16*>(0x006B482E))
// fields of gSbInitRelated (0x2E09BE0 in his IDB), two semaphore handles and an enable flag
//#define G_SB_SEMAPHORE_ONE (gSbInitRelated.mSemaphoreOne)
#define G_SB_SEMAPHORE_ONE (*reinterpret_cast<i32*>(0x02E09BE4))
//#define G_SB_SEMAPHORE_TWO (gSbInitRelated.mSemaphoreTwo)
#define G_SB_SEMAPHORE_TWO (*reinterpret_cast<i32*>(0x02E09BE8))
//#define G_SB_USE_SEMAPHORES (gSbInitRelated.mUseSemaphores)
#define G_SB_USE_SEMAPHORES (*reinterpret_cast<i32*>(0x02E09BEC))
// copies of the file local macros in dcfileio.cpp and ps2gamefmv.cpp
//#define G_FILE_IO_STATUS (gFileIOStatus)
#define G_FILE_IO_STATUS (*reinterpret_cast<volatile i32*>(0x0057C400))
//#define G_GAME_FMV_ACTIVE (GameFMV_Active)
#define G_GAME_FMV_ACTIVE (*reinterpret_cast<i32*>(0x006151F8))


// @Ok
// @Matching
void RedBook_MwErrFunc(void* obj, char* msg)
{
	strncpy(G_REDBOOK_ERROR_MSG, msg, 0x100);
	printf_fancy("Redbook Error: Code %p, Msg: %s", obj, G_REDBOOK_ERROR_MSG);
}

// @Ok
// @Matching
void Redbook_XAExit(void)
{
	if (!G_ADXT_INITIALIZED)
		return;

	if (G_SB_USE_SEMAPHORES)
		Sb_SemWait(G_SB_SEMAPHORE_ONE);

	ADXT_Stop(G_ADXT);

	if (G_SB_USE_SEMAPHORES)
		Sb_SemSignal(G_SB_SEMAPHORE_ONE);

	ADXT_Destroy(G_ADXT);

	if (G_SB_USE_SEMAPHORES)
		Sb_SemSignal(G_SB_SEMAPHORE_ONE);

	ADXT_Finish();
	G_ADXT_INITIALIZED = 0;
}

// @Ok
// @Matching
void Redbook_XAPause(bool pause)
{
	if (G_REDBOOK_BUSY != 1)
		return;

	if (pause)
	{
		if (G_REDBOOK_XA_PAUSED)
			return;

		G_REDBOOK_XA_PAUSED = 1;

		if (G_SB_USE_SEMAPHORES)
			Sb_SemWait(G_SB_SEMAPHORE_ONE);

		ADXT_Pause(G_ADXT, 1);

		if (G_SB_USE_SEMAPHORES)
			Sb_SemSignal(G_SB_SEMAPHORE_TWO); // the original signals the wrong semaphore here
	}
	else
	{
		if (G_REDBOOK_XA_PAUSED != 1)
			return;

		G_REDBOOK_XA_PAUSED = 0;

		if (G_SB_USE_SEMAPHORES)
			Sb_SemWait(G_SB_SEMAPHORE_ONE);

		ADXT_Pause(G_ADXT, 0);

		if (G_SB_USE_SEMAPHORES)
			Sb_SemSignal(G_SB_SEMAPHORE_ONE);
	}
}

// @Ok
// @Matching
void Redbook_XASetVol(i32 vol)
{
	print_if_false(G_ADXT_INITIALIZED, "ADXT not initialized.");
	print_if_false(vol >= 0 && vol <= 0xFF, "Strange XA Volume.");

	if (vol == 0)
	{
		ADXT_SetOutVol(G_ADXT, -999);
		return;
	}

	f32 v = static_cast<f32>(0x100 - vol);
	v *= 0.7f;
	ADXT_SetOutVol(G_ADXT, -static_cast<i32>(v));
}

// @Ok
// @Matching
i32 Redbook_XAStat(void)
{
	return ADXT_GetStat(G_ADXT);
}

EXPORT i32 gPlayPosOne;
EXPORT i32 gPlayPosTwo;
EXPORT i32 gRedbookVblanks;

// @Ok
// @Matching
u8 Redbook_XAPlayPos(i32 a1, i32 a2, CVector* a3, i32 a4)
{
	if (Redbook_XAPlay(a1, a2, a4) )
	{
		gPlayPosOne = a1;
		gPlayPosTwo = a2;
		gRedbookVblanks = Vblanks;
		return 1;
	}

	return 0;
}

// @Ok
// @Matching
void Redbook_XAStop(void)
{
	if (G_ADXT_INITIALIZED)
	{
		if (G_SB_USE_SEMAPHORES)
			Sb_SemWait(G_SB_SEMAPHORE_ONE);

		ADXT_Stop(G_ADXT);

		if (G_SB_USE_SEMAPHORES)
			Sb_SemSignal(G_SB_SEMAPHORE_ONE);
	}

	if (!G_REDBOOK_BUSY)
	{
		if (G_PENDING_XA_THREE | G_PENDING_XA_TWO | G_PENDING_XA_ONE)
		{
			G_PENDING_XA_THREE = 0;
			G_PENDING_XA_TWO = 0;
			G_PENDING_XA_ONE = 0;
		}
	}

	G_REDBOOK_XA_PAUSED = 0;
	G_REDBOOK_BUSY = 0;
	G_CARNAGE_XA_RELATED = 1;
	G_REDBOOK_XA_CURRENT_PRIORITY = -1;
	G_CARNAGE_XA_RELATED_TWO = 30;
}

// @BIGTODO
u8 Redbook_XAPlay(int a1, int, int)
{
	return 0x1235959;
}

// @Ok
// @Matching
void Redbook_XAAllow(bool allowed)
{
	G_XA_ALLOWED = allowed;
}

// @Ok
// @Matching
void Redbook_XAReset(void)
{
	G_REDBOOK_XA_RELATED_ONE = 0;
	G_REDBOOK_XA_RELATED_TWO = 0;
	G_REDBOOK_XA_CURRENT_PRIORITY = -1;
	G_CARNAGE_XA_RELATED_TWO = 0;
	G_PENDING_XA_THREE = 0;
	G_PENDING_XA_TWO = 0;
	G_PENDING_XA_ONE = 0;
	G_XA_ALLOWED = 1;
	G_REDBOOK_BUSY = 0;
	G_CARNAGE_XA_RELATED = 1;
	G_REDBOOK_XA_PAUSED = 0;
	G_REDBOOK_RELATED_ONE = 0;
	G_REDBOOK_RELATED_TWO = 0;
	G_REDBOOK_RELATED_THREE = 0;
}

// @Ok
// @Matching
void Redbook_XAInit(void)
{
	if (G_ADXT_INITIALIZED)
		return;

	Redbook_XAReset();

	if (G_SB_USE_SEMAPHORES)
		Sb_SemWait(G_SB_SEMAPHORE_ONE);

	ADXT_Init();

	if (G_SB_USE_SEMAPHORES)
		Sb_SemSignal(G_SB_SEMAPHORE_ONE);

	ADXERR_EntryErrFunc(RedBook_MwErrFunc, 0);

	if (G_SB_USE_SEMAPHORES)
		Sb_SemWait(G_SB_SEMAPHORE_ONE);

	ADXF_LoadPartition(0, "speech.str", G_ADXF_PARTITION_INFO, 0x4F0);
	FileIO_Sync();

	if (G_SB_USE_SEMAPHORES)
		Sb_SemSignal(G_SB_SEMAPHORE_ONE);

	G_ADXT = ADXT_Create(2, G_ADXT_WORK, 0x208C4);

	if (G_SB_USE_SEMAPHORES)
		Sb_SemSignal(G_SB_SEMAPHORE_ONE);

	G_ADXT_INITIALIZED = 1;
}

// @Ok
// @Matching
void Redbook_XAInitAtStart(void)
{
	Redbook_XAReset();
	Redbook_XAInit();
}
