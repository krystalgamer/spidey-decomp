#include "ob.h"
#include "export.h"


class CRudeWordHitterSpidey : public CSuper {
public:
	unsigned char fullPad[24];
};

class CDummy : public CSuper {
public:
	EXPORT void FadeBack(void);
	unsigned char padStart[0x1F8-0x194];

	int field_1F8;
	int field_1FC;
	unsigned char padAfter1FC[0x240-0x1FC-4];

	CItem field_240;
	unsigned char padAfter240[0x288 - 0x240 - sizeof(CItem)];
	CItem field_288;
	unsigned char padAfter288[0x2d4 - 0x288 - sizeof(CItem)];


	CVector field_2D4[4];
	CVector field_304[23];
	CVector field_418[128];
};

void validate_CRudeWordHitterSpidey(void);
void validate_CDummy(void);
