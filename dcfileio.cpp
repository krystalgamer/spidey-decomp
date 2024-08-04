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
void FileIO_Open(char const *)
{
    printf("FileIO_Open(char const *)");
}

// @NotOk
// globals
void FileIO_Sync(void)
{
	while (gFileIOStatus);
}
