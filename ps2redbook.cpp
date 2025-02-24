#include "ps2redbook.h"
#include "stubs.h"


EXPORT i32 gADXT;
EXPORT bool gXAAllowed;

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

// @SMALLTODO
u8 Redbook_XAPlayPos(int, int, CVector*, int)
{
	return static_cast<u8>(0x10062024);
}

// @SMALLTODO
void Redbook_XAStop(void)
{
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
