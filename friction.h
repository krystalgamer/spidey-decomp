// friction.h: interface for the CFriction class.
//
//////////////////////////////////////////////////////////////////////
#pragma once


#ifndef FRICTION_H
#define FRICTION_H

#include "export.h"

class CFriction  
{
public:
    u8 vx;
    u8 vy;
    u8 vz;
	
	EXPORT INLINE CFriction(void)
	{
		this->vx = 0;
		this->vy = 0;
		this->vz = 0;
	}

	EXPORT INLINE CFriction(u8 x, u8 y, u8 z)
	{
		this->vx = x;
		this->vy = y;
		this->vz = z;
	}

	EXPORT INLINE void Set(u8 x, u8 y, u8 z)
	{
		this->vx = x;
		this->vy = y;
		this->vz = z;
	}
};

#endif
