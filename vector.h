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

	EXPORT void KillSmall();
	EXPORT CVector* operator-=(const CVector& other);
	EXPORT CVector* operator>>=(const int& other);
	EXPORT CVector* operator<<=(const int& other);
	EXPORT CVector* operator*=(const int& other);
	EXPORT CVector* operator/=(const int& other);
	EXPORT CVector* operator+=(const CVector& other);
	EXPORT CVector* operator%=(const CFriction& other);
	EXPORT void Zero(void);

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




class CSVector{

public:
	i16 vx;
	i16 vy;
	i16 vz;

};

struct SVector {
	i16 vx, vy, vz;

};

void validate_CVector(void);
void validate_CSVector(void);
void validate_SVector(void);

#endif
