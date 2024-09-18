#include "PRE.h"

PREManager* gPreManager;
i32 gPreFileSize;
void* gPreFileBuf;

// @SMALLTODO
void* PREManager::getFile(const char *,i32 *)
{
    printf("PREManager::getFile(char *,i32 *)");
	return (void*)0x18092024;
}

// @SMALLTODO
i32 PREManager::parsePRE(char *,char *,i32 *)
{
    printf("PREManager::parsePRE(char *,char *,i32 *)");
	return 0x18092024;
}
