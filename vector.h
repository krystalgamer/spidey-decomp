// vector.h: interface for the CVector class.
//
//////////////////////////////////////////////////////////////////////

#include "export.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CVector  
{
public:
	int vx;
	int vy;
	int vz;
	CVector();
	~CVector();
	EXPORT CVector* operator-=(const CVector& other);
	EXPORT CVector* operator>>=(const int& other);
	EXPORT CVector* operator<<=(const int& other);
	EXPORT CVector* operator*=(const CVector& other);
	EXPORT CVector* operator/=(const CVector& other);
	EXPORT CVector* operator+=(const CVector& other);
};
