#include "chunk.h"
#include "baddy.h"
#include "mem.h"
#include "bit.h"
#include "utils.h"

#include "validate.h"


extern SSinCos rcossin_tbl[];

extern CBody* ControlBaddyList;

// @MEDIUMTODO
void Chunk_ChunkItemByChecksum(u32 Checksum)
{
	printf("void Chunk_ChunkItemByChecksum(u32 Checksum)");
}

// @Ok
// @Test
void CChunkControl::AddChunk(CItem* pItem)
{
	if ( this->field_FA < this->field_F8 )
	{
		SChunkEntry *entry = &this->field_FC[this->field_FA];
		this->field_FA++;
		entry->pItem = pItem;

		i32 v4 = Rnd(4096) & 0xFFF;
		i32 v5 = Rnd(32) + 32;

		entry->field_4.vx = v5 * rcossin_tbl[v4].sin;
		entry->field_4.vy = (-48 - Rnd(32)) << 12;
		entry->field_4.vz = v5 * rcossin_tbl[v4].cos;
		entry->field_14.vx = Rnd(512) - 256;
		entry->field_14.vy = Rnd(512) - 256;
		entry->field_14.vz = Rnd(512) - 256;
		entry->field_1C = Rnd(120) + 120;
	}
}

// @Ok
void CChunkControl::AI(void)
{
	i8 v1 = 1;
	for (u32 i = 0; i < this->field_FA; i++)
	{
		SChunkEntry *entry = &this->field_FC[i];

		if (entry->pItem)
		{
			if (entry->field_1C <= this->field_80)
			{
				Chunk_MakeItemDisappear(entry->pItem);
				entry->pItem = 0;
			}
			else
			{
				v1 = 0;
				entry->field_1C = entry->field_1C - this->field_80;
				entry->pItem->mPos = entry->field_4;

				entry->field_4.vy += 0x8000;

				entry->pItem->mAngles = entry->field_14;
			}
		}
	}

	if (v1)
	{
		this->Die();
	}
}

// @Ok
CChunkControl::~CChunkControl(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&ControlBaddyList));

	if (this->field_FC)
		Mem_Delete(static_cast<void*>(this->field_FC));
}

// @Ok
INLINE CChunkControl::CChunkControl(CVector* a2, u16 a3)
{
	this->mPos = *a2;
	this->AttachTo(reinterpret_cast<CBody**>(&ControlBaddyList));

	this->field_F8 = a3;
	if (this->field_F8)
		this->field_FC = static_cast<SChunkEntry*>(DCMem_New(32 * this->field_F8, 0, 1, 0, 1));
}

// @Ok
INLINE void Chunk_MakeItemDisappear(CItem* item)
{
	item->mFlags |= 0x21;
}

void validate_CChunkControl(void)
{
	VALIDATE_SIZE(CChunkControl, 0x100);

	VALIDATE(CChunkControl, field_F8, 0xF8);
	VALIDATE(CChunkControl, field_FA, 0xFA);
	VALIDATE(CChunkControl, field_FC, 0xFC);
}

void validate_SChunkEntry(void)
{
	VALIDATE_SIZE(SChunkEntry, 0x20);

	VALIDATE(SChunkEntry, pItem, 0x0);
	VALIDATE(SChunkEntry, field_4, 0x4);
	VALIDATE(SChunkEntry, field_14, 0x14);
	VALIDATE(SChunkEntry, field_1C, 0x1C);
}
