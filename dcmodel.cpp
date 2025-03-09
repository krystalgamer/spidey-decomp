#include "dcmodel.h"
#include "PCTex.h"

#include "validate.h"

#include "non_win32.h"
#include <cmath>

EXPORT float gPreComputedColorRelated = -1.0f;
EXPORT u8 gConvertedColors[256];

EXPORT DCSkaterModel gSkaterModels[2];
EXPORT DCSkaterModel gGlobalSkaterModel;

// @Ok
// @Matching
DCSkaterModel::DCSkaterModel(void)
{
	this->field_28 = 0;
}

// @Ok
// @Matching
void DCClearSkater(void)
{
	if (!gGlobalSkaterModel.field_1C)
	{
		gSkaterModels[0].ClearSkaterModel();
		gSkaterModels[1].ClearSkaterModel();
	}
}

// @SMALLTODO
DCKeyFrame::~DCKeyFrame(void)
{
    printf("DCKeyFrame::~DCKeyFrame(void)");
}

// @Ok
// @Matching
DCMaterial::~DCMaterial(void)
{
	delete this->field_10;
	delete this->field_34;

	if (!this->field_3F && CheckValidTexture(this->field_38))
		PCTex_ReleaseTexture(this->field_38, true);
}

// @MEDIUMTODO
void DCModel_CreateFromSModel(DCModelData *,SModel *,i32,i32 *,bool,i32)
{
    printf("DCModel_CreateFromSModel(DCModelData *,SModel *,i32,i32 *,bool,i32)");
}

// @NotOk
// @Note: SEH shit
DCObject::~DCObject(void)
{
	delete this->field_4;

	delete this->field_E4;
	this->field_E4 = 0;

	delete this->field_E8;
	this->field_E8 = 0;

	if (this->field_D0)
	{
		DCKeyFrame *pKey = reinterpret_cast<DCKeyFrame*>(this->field_D0[11]);
		delete pKey;

		delete this->field_E0;
	}

	delete this->field_128;
	delete[] this->field_134;
	delete this->field_12C;

	this->field_E0 = 0;

	DCObjectList* pObjList = reinterpret_cast<DCObjectList*>(this->field_E4);
	delete pObjList;
}

// @SMALLTODO
INLINE DCObjectList::~DCObjectList(void)
{
}

// @Ok
// @Matching
INLINE void DCSkaterModel::ClearSkaterModel(void)
{
	if ( this->field_1C )
	{
		this->field_0 = 0;
		this->field_4 = 0;
		this->field_8 = 0;

		this->field_18 = 0;
		this->field_1C = 0;

		delete this->field_28;
		this->field_28 = 0;

		delete[] this->field_24;

		this->field_24 = 0;
		this->field_20 = 0;
	}
}

// @NotOk
// @Note: missing some SEH shit
DCSkaterModel::~DCSkaterModel(void)
{
	delete[] this->field_24;

	delete this->field_28;
}

// @Ok
// @Matching
DCStrip::~DCStrip(void)
{
	delete this->field_8;
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

void validate_DCMaterial(void)
{
	VALIDATE_SIZE(DCMaterial, 0x40);

	VALIDATE(DCMaterial, field_10, 0x10);

	VALIDATE(DCMaterial, field_34, 0x34);
	VALIDATE(DCMaterial, field_38, 0x38);

	VALIDATE(DCMaterial, field_3F, 0x3F);
}

void validate_DCObject(void)
{
	VALIDATE_SIZE(DCObject, 0x138);

	VALIDATE(DCObject, field_4, 0x4);

	VALIDATE(DCObject, field_D0, 0xD0);

	VALIDATE(DCObject, field_E0, 0xE0);
	VALIDATE(DCObject, field_E4, 0xE4);
	VALIDATE(DCObject, field_E8, 0xE8);

	VALIDATE(DCObject, field_128, 0x128);
	VALIDATE(DCObject, field_12C, 0x12C);

	VALIDATE(DCObject, field_134, 0x134);
}

void validate_DCStrip(void)
{
	VALIDATE_SIZE(DCStrip, 0xC);

	VALIDATE(DCStrip, field_8, 0x8);
}

void validate_DCObjectList(void)
{
	VALIDATE_SIZE(DCObjectList, sizeof(DCObject));
}
