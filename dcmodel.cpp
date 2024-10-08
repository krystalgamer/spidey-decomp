#include "dcmodel.h"

#include <cmath>

EXPORT float gPreComputedColorRelated = -1.0f;
EXPORT u8 gConvertedColors[256];

// @SMALLTODO
void DCClearSkater(void)
{
    printf("DCClearSkater(void)");
}

// @SMALLTODO
DCKeyFrame::~DCKeyFrame(void)
{
    printf("DCKeyFrame::~DCKeyFrame(void)");
}

// @SMALLTODO
DCMaterial::~DCMaterial(void)
{
    printf("DCMaterial::~DCMaterial(void)");
}

// @MEDIUMTODO
void DCModel_CreateFromSModel(DCModelData *,SModel *,i32,i32 *,bool,i32)
{
    printf("DCModel_CreateFromSModel(DCModelData *,SModel *,i32,i32 *,bool,i32)");
}

// @SMALLTODO
DCObject::~DCObject(void)
{
    printf("DCObject::~DCObject(void)");
}

// @SMALLTODO
DCObjectList::~DCObjectList(void)
{
    printf("DCObjectList::~DCObjectList(void)");
}

// @SMALLTODO
void DCSkaterModel::ClearSkaterModel(void)
{
    printf("DCSkaterModel::ClearSkaterModel(void)");
}

// @SMALLTODO
DCSkaterModel::~DCSkaterModel(void)
{
    printf("DCSkaterModel::~DCSkaterModel(void)");
}

// @SMALLTODO
DCStrip::~DCStrip(void)
{
    printf("DCStrip::~DCStrip(void)");
}

// @Ok
// @Matching
void PreComputeConvertedColors(float a1)
{
	for (i32 i = 0;
			i < 256;
			i++)
	{
		float v4 = (float)i / 255.0f;
		float v5 = pow(v4, a1);
		if (v5 > 1.0)
			v5 = 1.0;
		gConvertedColors[i] = (v5 * 255.0f);
	}

	gPreComputedColorRelated = a1;
}
