#include "ps2redbook.h"


// @TODO
void Redbook_XAStop(void)
{
}

// @TODO
int Redbook_XAPlay(int, int, int)
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
