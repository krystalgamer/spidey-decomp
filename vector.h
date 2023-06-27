// vector.h: interface for the CVector class.
//
//////////////////////////////////////////////////////////////////////


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "export.h"
#include "friction.h"

class CVector  
{
public: 
	int vx;
	int vy;
	int vz;
	EXPORT void KillSmall();
	EXPORT CVector* operator-=(const CVector& other);
	EXPORT CVector* operator>>=(const int& other);
	EXPORT CVector* operator<<=(const int& other);
	EXPORT CVector* operator*=(const int& other);
	EXPORT CVector* operator/=(const int& other);
	EXPORT CVector* operator+=(const CVector& other);
	EXPORT CVector* operator%=(const CFriction& other);
};
