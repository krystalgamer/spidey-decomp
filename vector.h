// vector.h: interface for the CVector class.
//
//////////////////////////////////////////////////////////////////////
#pragma once

#ifndef VECTOR_H
#define VECTOR_H


#include "export.h"
#include "friction.h"

class CVector  
{
public: 

	i32 vx;
	i32 vy;
	i32 vz;

	EXPORT INLINE CVector(i32 x, i32 y, i32 z)
	{
		this->vx = x;
		this->vy = y;
		this->vz = z;
	}

	EXPORT INLINE CVector(void)
	{
		this->vx = 0;
		this->vy = 0;
		this->vz = 0;
	}

	//EXPORT CVector(i32, i32, i32);
	EXPORT void KillSmall();
	EXPORT CVector* operator-=(const CVector& other);
	EXPORT CVector* operator>>=(const int& other);
	EXPORT CVector* operator<<=(const int& other);
	EXPORT CVector* operator*=(const int& other);
	EXPORT CVector* operator/=(const int& other);
	EXPORT CVector* operator+=(const CVector& other);
	EXPORT CVector* operator%=(const CFriction& other);
	EXPORT i32 operator!=(const CVector& other);
	EXPORT void Zero(void);

	EXPORT i32 LengthSquared(void);

	EXPORT const CVector& operator=(const CVector& rhs) {

		this->vx = rhs.vx;
		this->vy = rhs.vy;
		this->vz = rhs.vz;

		return *this;
	}
	EXPORT int Length(void);
};

EXPORT CVector operator/(const CVector& lhs, const int& other);
EXPORT CVector operator-(const CVector& lhs, const CVector& other);
EXPORT CVector operator*(const CVector& lhs, const int& other);
EXPORT CVector operator*(const CVector& lhs, const CVector& other);
EXPORT CVector operator>>(const CVector& lhs, const int& other);
EXPORT CVector operator+(const CVector& lhs, const CVector& other);

EXPORT CVector operator*(const int& lhs, const CVector& other);

EXPORT CVector operator<<(const CVector& lhs, const i32& other);




class CSVector{

public:
	i16 vx;
	i16 vy;
	i16 vz;

	// @Ok
	EXPORT INLINE CSVector(void)
	{
		this->vx = 0;
		this->vy = 0;
		this->vz = 0;
	}

	// @Ok
	// Note: Guessed the name
	EXPORT INLINE void Set(i16 a1, i16 a2, i16 a3)
	{
		this->vx = a1;
		this->vy = a2;
		this->vz = a3;
	}

	EXPORT CSVector* operator+=(const CSVector& other);
	EXPORT void Mask(void);
	EXPORT void KillSmall(void);
};

struct SVector {
	i16 vx, vy, vz;

};

void validate_CVector(void);
void validate_CSVector(void);
void validate_SVector(void);

#endif
