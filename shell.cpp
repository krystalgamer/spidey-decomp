#pragma once
#include "shell.h"
#include "validate.h"

// @Ok
void __inline CDummy::FadeBack(void)
{
	this->field_1FC = 1;
	this->field_1F8 = 0;
}

static const __int16 *word_610C48 = (__int16*)0x610C48;

// @Not
// Global
void __inline CWobblyGlow::Move(void)
{
	for (unsigned int i = 0; i < this->field_44; i++)
	{
		this->field_5C[8+i] += this->field_5C[i];
		int v3 = this->field_5C[8+i];
		this->field_3C[2*i] = this->field_A0 + this->field_9C * word_610C48[2 * (v3 & 0xFFF)] / 4096;
	}
}

// @Ok
void CShellMysterioHeadGlow::Move(void)
{
	CWobblyGlow::Move();
	this->field_54 += this->field_A4;
}

void validate_CRudeWordHitterSpidey(void){
	VALIDATE_SIZE(CRudeWordHitterSpidey, 0x1AC);
}

void validate_CDummy(void){
	VALIDATE_SIZE(CDummy, 0xA18);

	VALIDATE(CDummy, field_1F8, 0x1F8);
	VALIDATE(CDummy, field_1FC, 0x1FC);

	VALIDATE(CDummy, field_240, 0x240);
	VALIDATE(CDummy, field_288, 0x288);

	VALIDATE(CDummy, field_2D4, 0x2D4);
	VALIDATE(CDummy, field_304, 0x304);
	VALIDATE(CDummy, field_418, 0x418);
}

void validate_CShellMysterioHeadGlow(void)
{
	VALIDATE_SIZE(CShellMysterioHeadGlow, 0xA8);

	VALIDATE(CShellMysterioHeadGlow, field_A4, 0xA4);
}


void validate_CWobblyGlow(void)
{
	VALIDATE_SIZE(CWobblyGlow, 0xA4);

	VALIDATE(CWobblyGlow, field_5C, 0x5C);

	VALIDATE(CWobblyGlow, field_9C, 0x9C);
	VALIDATE(CWobblyGlow, field_A0, 0xA0);
}
