#include "ps2redbook.h"


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

static bool gXAAllowed;

// @NotOk
// Globals
void Redbook_XAAllow(bool allowed)
{
	gXAAllowed = allowed;
}

// @MEDIUMTODO
void Redbook_XAReset(void)
{
}

// @BIGTODO
void Redbook_XAInit(void)
{}

// @Ok
void Redbook_XAInitAtStart(void)
{
	Redbook_XAReset();
	Redbook_XAInit();
}
