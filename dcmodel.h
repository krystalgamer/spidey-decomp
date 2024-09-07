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

#endif
