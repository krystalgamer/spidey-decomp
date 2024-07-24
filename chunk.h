#pragma once

#ifndef CHUNK_H
#define CHUNK_H

#include "export.h"
#include "ob.h"

struct SChunkEntry
{
	CItem* pItem;
	CVector field_4;
	u8 padAfter4[0x14-0x4-sizeof(CVector)];


	CSVector field_14;
	u8 padAfter14[0x1C-0x14-sizeof(CSVector)];

	u32 field_1C;
};

class CChunkControl : public CBody
{
	public:
		EXPORT CChunkControl(CVector*, u16);
		EXPORT virtual ~CChunkControl(void);
		EXPORT virtual void AI(void);

		u8 padTop[4];

		u16 field_F8;
		u16 field_FA;

		SChunkEntry *field_FC;
};

EXPORT void Chunk_MakeItemDisappear(CItem* item);

void validate_CChunkControl(void);
void validate_SChunkEntry(void);

#endif
