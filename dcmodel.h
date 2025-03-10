#pragma once

#ifndef DCMODEL_H
#define DCMODEL_H

#include "export.h"

EXPORT void DCClearSkater(void);


class DCStrip
{
	public:
		u8 padTop[8];
		void* field_8;

		EXPORT ~DCStrip(void);
};

class DCKeyFrame
{
	public:
		u8 padTop[44];

		DCKeyFrame *pNext;
		EXPORT ~DCKeyFrame(void);
};

class DCMaterial
{
	public:

		u8 padTop[0x10];

		void *field_10;
		u8 padAfter10[0x34-0x10-4];

		void *field_34;
		i32 field_38;
		u8 padAfter38[0x3F-0x38-4];

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
		u8 padTop[4];


		void *field_4;
		u8 padAfter4[0xD0-0x4-4];

		DCKeyFrame *field_D0;
		u8 padAfterD0[0xE0-0xD0-4];

		void *field_E0;

		DCObjectList field_E4;

		DCObject *field_E8;
		u8 padAfterE8[0x128-0xE8-4];

		void *field_128;
		void *field_12C;
		u8 padAfter12C[4];

		DCStrip *field_134;

		EXPORT ~DCObject(void);
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
