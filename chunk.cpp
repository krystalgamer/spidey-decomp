#include "chunk.h"


void Chunk_MakeItemDisappear(CItem* item)
{
	item->mFlags |= 0x21;
}
