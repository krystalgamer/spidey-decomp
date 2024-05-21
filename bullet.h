#pragma once


#ifndef BULLET_H
#define BULLET_H

#include "export.h"
#include "ob.h"

class CBullet : public CBody
{
	public:
		EXPORT CBullet(void);

		unsigned char padTop[0x114-0xF4];

		int field_114;
		int field_118;
		int field_11C;
		unsigned char padAfter11C[0x130-0x11C-4];

		int field_130;
		int field_134;
		int field_138;
};

void validate_CBullet(void);
#endif
