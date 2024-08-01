#pragma once


#ifndef BULLET_H
#define BULLET_H

#include "export.h"
#include "ob.h"

class CBullet : public CBody
{
	public:
		EXPORT CBullet(void);
		EXPORT virtual ~CBullet(void);

		u8 padTop[0x10C-0xF4];

		void* field_10C;
		u8 padAfter10C[4];

		i32 field_114;
		i32 field_118;
		i32 field_11C;
		void *field_120;


		u8 padAfter120[0x130-0x120-4];

		i32 field_130;
		i32 field_134;
		i32 field_138;
};

void validate_CBullet(void);
#endif
