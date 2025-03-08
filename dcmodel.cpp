#include "dcmodel.h"

#include "validate.h"

#include <cmath>

EXPORT float gPreComputedColorRelated = -1.0f;
EXPORT u8 gConvertedColors[256];

// @Ok
// @Matching
DCSkaterModel::DCSkaterModel(void)
{
	this->field_28 = 0;
}

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

void validate_DCSkaterModel(void)
{
	VALIDATE_SIZE(DCSkaterModel, 0x2C);

	VALIDATE(DCSkaterModel, field_0, 0x0);

	VALIDATE(DCSkaterModel, field_4, 0x4);

	VALIDATE(DCSkaterModel, field_8, 0x8);

	VALIDATE(DCSkaterModel, field_18, 0x18);
	VALIDATE(DCSkaterModel, field_1C, 0x1C);

	VALIDATE(DCSkaterModel, field_20, 0x20);
	VALIDATE(DCSkaterModel, field_24, 0x24);
	VALIDATE(DCSkaterModel, field_28, 0x28);
}
