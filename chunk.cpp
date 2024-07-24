#include "chunk.h"
#include "baddy.h"
#include "mem.h"

#include "validate.h"

extern CBaddy* ControlBaddyList;

// @Ok
CChunkControl::~CChunkControl(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&ControlBaddyList));

	if (this->field_FC)
		Mem_Delete(this->field_FC);
}

// @Ok
CChunkControl::CChunkControl(CVector* a2, u16 a3)
{
	this->mPos = *a2;
	this->AttachTo(reinterpret_cast<CBody**>(&ControlBaddyList));

	this->field_F8 = a3;
	if (this->field_F8)
		this->field_FC = DCMem_New(32 * this->field_F8, 0, 1, 0, 1);
}

// @Ok
void Chunk_MakeItemDisappear(CItem* item)
{
	item->mFlags |= 0x21;
}

void validate_CChunkControl(void)
{
	VALIDATE_SIZE(CChunkControl, 0x100);

	VALIDATE(CChunkControl, field_F8, 0xF8);
	VALIDATE(CChunkControl, field_FC, 0xFC);
}
