#pragma once

#ifndef DCMODEL_H
#define DCMODEL_H

#include "export.h"

EXPORT void DCClearSkater(void);


class DCStrip
{
	public:
		PADDING(8);

		void* field_8;

		EXPORT ~DCStrip(void);
};

class DCKeyFrame
{
	public:
		PADDING(44);

		DCKeyFrame *pNext;
		EXPORT ~DCKeyFrame(void);
};

class DCMaterial
{
	public:

		PADDING(0x10);

		void *field_10;

		PADDING(0x34-0x10-4);

		void *field_34;
		i32 field_38;

		PADDING(0x3F-0x38-4);

		u8 field_3F;

		EXPORT DCMaterial::~DCMaterial(void);
};

class DCObject;

class DCObjectList
{
	public:
		DCObject *pObject;

		EXPORT ~DCObjectList(void);
};

class DCObject
{
	public:

		PADDING(4);

		void *field_4;

		PADDING(0xD0-0x4-4);

		DCKeyFrame *field_D0;

		PADDING(0xE0-0xD0-4);

		void *field_E0;

		DCObjectList field_E4;

		DCObject *field_E8;

		PADDING(0x128-0xE8-4);

		void *field_128;
		void *field_12C;

		PADDING(4);

		DCStrip *field_134;

		EXPORT ~DCObject(void);
};

class DCSkaterModel
{
	public:

		i32 field_0;

		u8 field_4;
		
		PADDING(3);

		u8 field_8;

		PADDING(0x18-0x8-1);

		i32 field_18;
		i32 field_1C;
		i32 field_20;
		DCMaterial *field_24;
		DCObjectList field_28;

		EXPORT DCSkaterModel(void);


		EXPORT void ClearSkaterModel(void);
		EXPORT ~DCSkaterModel(void);
};


struct DCModelData;
struct SModel;

EXPORT void DCModel_CreateFromSModel(DCModelData *,SModel *,i32,i32 *,bool,i32);
EXPORT void PreComputeConvertedColors(float);

void validate_DCSkaterModel(void);
void validate_DCMaterial(void);
void validate_DCObject(void);
void validate_DCStrip(void);
void validate_DCObjectList(void);
void validate_DCKeyFrame(void);

#endif
