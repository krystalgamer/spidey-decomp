#pragma once
#include "export.h"
#include "vector.h"


class CItem  
{
public: 
	
	unsigned short mFlags;
	CVector mPos;
	int mAngles;

	unsigned char pad[0x02];

	unsigned short mModel;

	unsigned char pad1[3];
	unsigned char mRegion;




	EXPORT void * operator new(unsigned int size);

	EXPORT CItem();
	EXPORT virtual ~CItem();

	EXPORT void InitItem(const char *);
};


class CBody : public CItem {

public:
	unsigned char pad[0x26];
	unsigned __int16 mDead;


	EXPORT int IsDead(void) const;
	EXPORT void Die(void);

};

class CSuper : public CBody {

};

void validate_CItem(void);
void validate_CBody(void);