#pragma once

#ifndef CHUNK_H
#define CHUNK_H

#include "export.h"
#include "ob.h"


class CChunkControl : public CBody
{
	public:
		EXPORT CChunkControl(CVector*, u16);
		u8 padTop[4];

		u16 field_F8;
		u8 padAfterF8[2];

		void *field_FC;
};

EXPORT void Chunk_MakeItemDisappear(CItem* item);

void validate_CChunkControl(void);

#endif
