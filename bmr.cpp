#include "bmr.h"
#include "dcshellutils.h"
#include "utils.h"

EXPORT Sprite2* gLoadedBmp = 0;

// @SMALLTODO
void BMP_Draw(char const *)
{
    printf("BMP_Draw(char const *)");
}

// @SMALLTODO
void DeleteBMP(void)
{
    printf("DeleteBMP(void)");
}

// @SMALLTODO
void DrawBMP(void)
{
    printf("DrawBMP(void)");
}

// @Ok
void LoadBMP(const char * pName)
{
	print_if_false(gLoadedBmp == 0, "BMP already loaded");

	gLoadedBmp = new Sprite2(pName, 1, 0, 0, 3);
	Pause(2);
}
