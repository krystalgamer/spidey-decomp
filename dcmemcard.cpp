#include "dcmemcard.h"
#include "pcdcBkup.h"

#include <cstring>


EXPORT u8 gCardData[8];
EXPORT u8 gCardInit;
EXPORT u8 gCardInitTwo;

// @SMALLTODO
i32 DCCard_BupComplete(i32,i32,i32,u32)
{
    printf("DCCard_BupComplete(i32,i32,i32,u32)");
	return 0;
}

// @SMALLTODO
void DCCard_CurTime(void)
{
    printf("DCCard_CurTime(void)");
}

// @SMALLTODO
void DCCard_Exists(i32)
{
    printf("DCCard_Exists(i32)");
}

// @SMALLTODO
void DCCard_First(void)
{
    printf("DCCard_First(void)");
}

// @SMALLTODO
void DCCard_HappyBeep(i32,u32)
{
    printf("DCCard_HappyBeep(i32,u32)");
}

// @Ok
void DCCard_InitCallback(void)
{
	buSetCompleteCallback(DCCard_BupComplete);
}

// @SMALLTODO
void DCCard_SadBeep(i32,u32)
{
    printf("DCCard_SadBeep(i32,u32)");
}

// @SMALLTODO
void DCCard_StartBeep(i32)
{
    printf("DCCard_StartBeep(i32)");
}

// @SMALLTODO
void DCCard_StopBeep(i32)
{
    printf("DCCard_StopBeep(i32)");
}

// @SMALLTODO
void DCCard_Wait(i32,i32)
{
    printf("DCCard_Wait(i32,i32)");
}

// @Ok
void MemCardInit(i32)
{
	print_if_false(gCardInit == 0, "card already initialized");
	memset(gCardData, 0, sizeof(gCardData));
	print_if_false(buInit(122, 255, NULL, DCCard_InitCallback) == 0, "bu init failed");

	gCardInit = 1;
	gCardInitTwo = 1;
}

// @SMALLTODO
void MemCardStop(void)
{
    printf("MemCardStop(void)");
}
