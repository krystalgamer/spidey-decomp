// vector.cpp: implementation of the CVector class.
//
//////////////////////////////////////////////////////////////////////

#include "vector.h"
#include <cstdio>
#include "validate.h"
#include "ps2funcs.h"

/*
CVector::CVector(void)
{
}
*/

// @Ok
// @Matching
i32 CVector::LengthSquared(void)
{
	CVector tmp;

	tmp.vx = this->vx >> 12;
	tmp.vy = this->vy >> 12;
	tmp.vz = this->vz >> 12;

	gte_ldlvl(reinterpret_cast<VECTOR*>(&tmp));
	gte_sqr0();
	gte_stlvnl(reinterpret_cast<VECTOR*>(&tmp));

	return tmp.vx + tmp.vy + tmp.vz;
}

// @Ok
// @Matching
i32 CVector::operator!=(const CVector& other)
{
	return this->vx != other.vx || this->vy != other.vy || this->vz != other.vz;
}

// @Ok
CVector operator<<(const CVector& lhs, const i32& other){

	CVector res;

	res.vx = lhs.vx << other;
	res.vy = lhs.vy << other;
	res.vz = lhs.vz << other;

	return res;
}

// @Ok
void CSVector::KillSmall(void){

    if (this->vx >= -1 && this->vx <= 1)
    {
        this->vx = 0;
    }

    if (this->vy >= -1 && this->vy <= 1)
    {
        this->vy = 0;
    }

    if (this->vz >= -1 && this->vz <= 1)
    {
        this->vz = 0;
    }
}

// @Ok
void CSVector::Mask(void)
{
	this->vx &= 0xFFF;
	this->vy &= 0xFFF;
	this->vz &= 0xFFF;
}

// @Ok
CSVector* CSVector::operator+=(const CSVector& other){
	this->vx += other.vx;
	this->vy += other.vy;
	this->vz += other.vz;
	return this;
}


// @Ok
void CVector::KillSmall(){

    if (this->vx >= -2048 && this->vx <= 2048)
    {
        this->vx = 0;
    }

    if (this->vy >= -2048 && this->vy <= 2048)
    {
        this->vy = 0;
    }

    if (this->vz >= -2048 && this->vz <= 2048)
    {
        this->vz = 0;
    }
}

// @Ok
CVector* CVector::operator-=(const CVector& other){
	this->vx -= other.vx;
	this->vy -= other.vy;
	this->vz -= other.vz;
	return this;
}

// @Ok
CVector* CVector::operator>>=(const int& other){
	this->vx >>= other;
	this->vy >>= other;
	this->vz >>= other;
	return this;
}

// @Ok
CVector* CVector::operator<<=(const int& other){
	this->vx <<= other;
	this->vy <<= other;
	this->vz <<= other;
	return this;
}

// @Ok
CVector* CVector::operator*=(const int& other){
	this->vx *= other;
	this->vy *= other;
	this->vz *= other;
	return this;
}

// @Ok
CVector* CVector::operator/=(const int& other){
	this->vx /= other;
	this->vy /= other;
	this->vz /= other;
	return this;
}

// @Ok
CVector* CVector::operator+=(const CVector& other){
	this->vx += other.vx;
	this->vy += other.vy;
	this->vz += other.vz;
	return this;
}

// @Ok
CVector* CVector::operator%=(const CFriction& other){
	this->vx -= this->vx >> other.vx;
	this->vy -= this->vy >> other.vy;
	this->vz -= this->vz >> other.vz;
	return this;
}

// @Ok
CVector operator-(const CVector& lhs, const CVector& other)
{
	CVector res;

	res.vx = lhs.vx - other.vx;
	res.vy = lhs.vy - other.vy;
	res.vz = lhs.vz - other.vz;

	return res;
}

// @Ok
CVector operator/(const CVector& lhs, const int& other){

	CVector res;

	res.vx = lhs.vx / other;
	res.vy = lhs.vy / other;
	res.vz = lhs.vz / other;

	return res;
}

// @Ok
CVector operator*(const CVector& lhs, const int& other)
{
	CVector res;

	res.vx = lhs.vx * other;
	res.vy = lhs.vy * other;
	res.vz = lhs.vz * other;

	return res;
}

// @Ok
CVector operator*(const int& lhs, const CVector& other)
{
	CVector res;

	res.vx = lhs * other.vx;
	res.vy = lhs * other.vy;
	res.vz = lhs * other.vz;

	return res;
}

// @Ok
CVector operator*(const CVector& lhs, const CVector& other){

	CVector res;

	res.vx = lhs.vx * other.vx;
	res.vy = lhs.vx * other.vy;
	res.vz = lhs.vx * other.vz;

	return res;
}

// @Ok
CVector operator>>(const CVector& lhs, const int& other)
{
	CVector res;

	res.vx = lhs.vx >> other;
	res.vy = lhs.vy >> other;
	res.vz = lhs.vz >> other;

	return res;
}

// @Ok
CVector operator+(const CVector& lhs, const CVector& other){

	CVector res;

	res.vx = lhs.vx + other.vx;
	res.vy = lhs.vx + other.vy;
	res.vz = lhs.vx + other.vz;

	return res;
}


// @Ok
// @Test
int CVector::Length(void)
{
	CVector v4;

	v4.vx = this->vx >> 12;
	v4.vy = this->vy >> 12;
	v4.vz = this->vz >> 12;

	gte_ldlvl(reinterpret_cast<VECTOR*>(&v4));
	gte_sqr0();
	gte_stlvnl(reinterpret_cast<VECTOR*>(&v4));

	return M3dMaths_SquareRoot0(v4.vx + v4.vy + v4.vz);
}

// @Bogus
void CVector::Zero(void)
{
	this->vx = 0;
	this->vy = 0;
	this->vz = 0;
}


void validate_CVector(void)
{
	VALIDATE(CVector, vx, 0);
	VALIDATE(CVector, vy, 4);
	VALIDATE(CVector, vz, 8);
}

void validate_CSVector(void)
{
	VALIDATE(CSVector, vx, 0);
	VALIDATE(CSVector, vy, 2);
	VALIDATE(CSVector, vz, 4);
}

void validate_SVector(void){
	VALIDATE(SVector, vx, 0);
	VALIDATE(SVector, vy, 2);
	VALIDATE(SVector, vz, 4);
}
