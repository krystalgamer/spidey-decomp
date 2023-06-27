// vector.cpp: implementation of the CVector class.
//
//////////////////////////////////////////////////////////////////////

#include "vector.h"
#include <cstdio>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

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

CVector* CVector::operator-=(const CVector& other){
	this->vx -= other.vx;
	this->vy -= other.vy;
	this->vz -= other.vz;
	return this;
}

CVector* CVector::operator>>=(const int& other){
	this->vx >>= other;
	this->vy >>= other;
	this->vz >>= other;
	return this;
}

CVector* CVector::operator<<=(const int& other){
	this->vx <<= other;
	this->vy <<= other;
	this->vz <<= other;
	return this;
}

CVector* CVector::operator*=(const int& other){
	this->vx *= other;
	this->vy *= other;
	this->vz *= other;
	return this;
}

CVector* CVector::operator/=(const int& other){
	this->vx /= other;
	this->vy /= other;
	this->vz /= other;
	return this;
}

CVector* CVector::operator+=(const CVector& other){
	this->vx += other.vx;
	this->vy += other.vy;
	this->vz += other.vz;
	return this;
}

CVector* CVector::operator%=(const CFriction& other){
	this->vx -= this->vx >> other.vx;
	this->vy -= this->vy >> other.vy;
	this->vz -= this->vz >> other.vz;
	return this;
}
