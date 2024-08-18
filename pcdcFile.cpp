#include "pcdcFile.h"
#include "PCMovie.h"

#ifdef _WIN32
EXPORT TCHAR gCurrentDir[260];
#endif

EXPORT char gFsBase[260];

// @Ok
EXPORT i32 gdFsInit(void)
{
#ifdef _WIN32
	GetCurrentDirectoryA(260, gCurrentDir);
#endif

	strcpy(gFsBase, "data\\");
	openPKR();

	PCMOVIE_InitOnce();
	PCMOVIE_OpenPKR();

	return 0;
}

// @SMALLTODO
void closeFilePKR(i32)
{
    printf("closeFilePKR(i32)");
}

// @SMALLTODO
void closePKR(void)
{
    printf("closePKR(void)");
}

// @SMALLTODO
void findFilePKR(char *,char const *)
{
    printf("findFilePKR(char *,char const *)");
}

// @SMALLTODO
void nextFile(void)
{
    printf("nextFile(void)");
}

// @SMALLTODO
void openFilePKR(char *,char const *)
{
    printf("openFilePKR(char *,char const *)");
}

// @SMALLTODO
void openPKR(void)
{
    printf("openPKR(void)");
}

// @SMALLTODO
void readFilePKR(i32,char *,i32)
{
    printf("readFilePKR(i32,char *,i32)");
}

// @SMALLTODO
void seekFilePKR(i32,i32,i32)
{
    printf("seekFilePKR(i32,i32,i32)");
}

// @SMALLTODO
void tellFilePKR(i32)
{
    printf("tellFilePKR(i32)");
}
