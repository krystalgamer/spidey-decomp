#include "dcfileio.h"
#include "pcdcFile.h"

EXPORT volatile i32 gFileIOStatus;

// @SMALLTODO
void DebugPrintfX(char *,...)
{
    printf("DebugPrintfX(char *,...)");
}

// @Ok
// @Matching
u8 FileIO_FileExists(const char* pFileName)
{
	print_if_false(gFileIOStatus == 0, "Previous file not finished loading");
	HANDLE handle = gdFsOpen(pFileName, 0);
	if (!handle)
		return 0;
	gdFsClose(handle);
	return 1;
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
