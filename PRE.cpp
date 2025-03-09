#include "PRE.h"

#include "validate.h"

#include <cstring>

PREManager* gPreManager;
i32 gPreFileSize;
void* gPreFileBuf;

// @Ok
// @Test
char* PREManager::getFile(
		const char *filename,
		i32 *size)
{
	char v18[16];

	for (i32 i = 0; ;i++)
	{
		char cur = filename[i];

		v18[i] = cur;
		if (cur >= 'A' && cur <= 'Z')
			v18[i] = cur + 32;

		if (!cur)
			break;
	}

	char *result = 0;
	for (i32 j = 0; j < 16; j++ )
	{
		char *pre = this->mPre[j];
		if (pre)
			result = this->parsePRE(pre, v18, size);
		if (result)
			break;
	}

	return result;
}

// @Ok
// @Test
INLINE char* PREManager::parsePRE(
		char *pre,
		char *filename,
		i32 *size)
{
    printf("PREManager::getFile(char *,i32 *)");
	return (void*)0x18092024;
}

void validate_PREManager(void)
{
	VALIDATE_SIZE(PREManager, 0x144);

	VALIDATE(PREManager, mPre, 0x4);
	VALIDATE(PREManager, mPreName, 0x44);
}
