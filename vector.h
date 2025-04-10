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

		EXPORT INLINE void Set(i32 a1, i32 a2, i32 a3)
		{
			this->vx = a1;
			this->vy = a2;
			this->vz = a3;
		}

		EXPORT INLINE void Set(CVector *a1)
		{
			this->Set(a1->vx, a1->vy, a1->vz);
		}

		EXPORT INLINE void SetX(i32 val)
		{
			this->vx = val;
		}

		EXPORT INLINE void SetY(i32 val)
		{
			this->vy = val;
		}

		EXPORT INLINE void SetZ(i32 val)
		{
			this->vz = val;
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

		/*
		INLINE void operator=(const CSVector& other)
		{
            this->vx = other.vx;
            this->vy = other.vy;
            this->vz = other.vz;
        }
		*/

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
