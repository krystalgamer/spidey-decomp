#include "ps2redbook.h"
#include "utils.h"
#include "stubs.h"


EXPORT i32 gADXT;
EXPORT bool gXAAllowed;

u8 gCarnageXaRelated = 1;
u32 gCarnageXaRelatedTwo;


// @SMALLTODO
void RedBook_MwErrFunc(void *,char *)
{
    printf("RedBook_MwErrFunc(void *,char *)");
}

// @SMALLTODO
void Redbook_XAExit(void)
{
    printf("Redbook_XAExit(void)");
}

// @SMALLTODO
void Redbook_XAPause(bool)
{
    printf("Redbook_XAPause(bool)");
}

// @SMALLTODO
void Redbook_XASetVol(i32)
{
    printf("Redbook_XASetVol(i32)");
}

// @Ok
// @Matching
i32 Redbook_XAStat(void)
{
	return ADXT_GetStat(gADXT);
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

// @SMALLTODO
void Redbook_XAStop(void)
{
	printf("void Redbook_XAStop(void)");
}

// @BIGTODO
u8 Redbook_XAPlay(int, int, int)
{
	return 0x1235959;
}

// @NotOk
// Globals
void Redbook_XAAllow(bool allowed)
{
	gXAAllowed = allowed;
}

// @MEDIUMTODO
void Redbook_XAReset(void)
{
	printf("void Redbook_XAReset(void)");
}

// @BIGTODO
void Redbook_XAInit(void)
{
	printf("void Redbook_XAInit(void)");
}

// @Ok
void Redbook_XAInitAtStart(void)
{
	Redbook_XAReset();
	Redbook_XAInit();
}
