#pragma once

#ifndef DCMODEL_H
#define DCMODEL_H

#include "export.h"

EXPORT void DCClearSkater(void);

class DCKeyFrame
{
	public:
		EXPORT ~DCKeyFrame(void);
};

class DCMaterial
{
	public:
		EXPORT DCMaterial::~DCMaterial(void);
};

class DCObject
{
	EXPORT ~DCObject(void);
};

class DCObjectList
{
	public:
		EXPORT ~DCObjectList(void);
};

class DCSkaterModel
{
	public:

		i32 field_0;

		u8 field_4;
		u8 padAfter4[3];

		u8 field_8;
		u8 padAfter8[0x18-0x8-1];

		i32 field_18;
		i32 field_1C;
		i32 field_20;
		i32 field_24;
		i32 field_28;

		EXPORT DCSkaterModel(void);


		EXPORT void ClearSkaterModel(void);
		EXPORT ~DCSkaterModel(void);
};


class DCStrip
{
	EXPORT ~DCStrip(void);
};

struct DCModelData;
struct SModel;

EXPORT void DCModel_CreateFromSModel(DCModelData *,SModel *,i32,i32 *,bool,i32);
EXPORT void PreComputeConvertedColors(float);

void validate_DCSkaterModel(void);

#endif
