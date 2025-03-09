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
	char *v6 = pre + 4;
	i32 v7 = 0;

	i32 v13 = *reinterpret_cast<i32*>(pre);
	while (v7 < v13)
	{
		i32 *v9 = reinterpret_cast<i32*>(&v6[(strlen(v6) + 4) & 0xFFFFFFFC]);
		i32 v12 = v9[0];
		char *v10 = reinterpret_cast<char*>(&v9[1]);
		if (!strcmp(v6, filename))
		{
			*size = v12;
			return v10;
		}

		v7++;
		v6 = &v10[((v12 + 3) & 0xFFFFFFFC)];
	}

	return 0;
}

void validate_PREManager(void)
{
	VALIDATE_SIZE(PREManager, 0x144);

	VALIDATE(PREManager, mPre, 0x4);
	VALIDATE(PREManager, mPreName, 0x44);
}
