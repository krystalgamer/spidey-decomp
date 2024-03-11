#include "ob.h"
#include "export.h"


class CRudeWordHitterSpidey : public CSuper {
public:
	unsigned char fullPad[24];
};

class CDummy : public CSuper {
public:
	unsigned char padStart[0x240-0x194];

	CItem field_240;
	unsigned char padAfter240[0x288 - 0x240 - sizeof(CItem)];
	CItem field_288;
	unsigned char fullPad[0xA18 - 0x288 - sizeof(CItem)];
};

void validate_CRudeWordHitterSpidey(void);
void validate_CDummy(void);
