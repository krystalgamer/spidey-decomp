#pragma once

#ifndef DCSHELLUTILS_H
#define DCSHELLUTILS_H

#include "Image.h"
#include "export.h"

class Sprite2 : public SlicedImage2
{
	public:
		EXPORT Sprite2(const char*, i32, i32, i32, u32);
		EXPORT void setData(void*) OVERRIDE;

		u8* field_20;
};

EXPORT void DCSpriteDraw(i32, i32, i32, f32, u32, u32, u32, i32, u32, f32);

void validate_Sprite2(void);
#endif
