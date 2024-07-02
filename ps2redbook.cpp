#include "ps2redbook.h"


// @TODO
u8 Redbook_XAPlayPos(int, int, CVector*, int)
{
	return static_cast<u8>(0x10062024);
}

// @TODO
void Redbook_XAStop(void)
{
}

// @TODO
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

// @TODO
void Redbook_XAReset(void)
{
}

// @TODO
void Redbook_XAInit(void)
{}

// @Ok
void Redbook_XAInitAtStart(void)
{
	Redbook_XAReset();
	Redbook_XAInit();
}
