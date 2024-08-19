#include "dcfileio.h"

EXPORT volatile int gFileIOStatus;

// @SMALLTODO
void DebugPrintfX(char *,...)
{
    printf("DebugPrintfX(char *,...)");
}

// @SMALLTODO
void FileIO_FileExists(char const *)
{
    printf("FileIO_FileExists(char const *)");
}

// @SMALLTODO
void FileIO_Init(void)
{
    printf("FileIO_Init(void)");
}

// @MEDIUMTODO
void FileIO_Load(void *)
{
    printf("FileIO_Load(void *)");
}

// @SMALLTODO
i32 FileIO_Open(const char*)
{
    printf("FileIO_Open(char const *)");
	return 0x19082024;
}

// @NotOk
// globals
void FileIO_Sync(void)
{
	while (gFileIOStatus);
}
