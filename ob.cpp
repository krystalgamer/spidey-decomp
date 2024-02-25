#include "ob.h"
#include "mem.h"
#include <cstring>
#include "validate.h"


void* CItem::operator new(unsigned int size) {

  void *result = DCMem_New(size, 0, 1, 0, 1);

  unsigned int adjusted_size = ((size + 3) & 0xFFFFFFFC) >> 2;
  if ( adjusted_size )
    memset(result, 0, 4 * adjusted_size);

  return result;
}


CItem::CItem(){}

CItem::~CItem(){}

//TODO
void CItem::InitItem(const char *)
{

	this->mRegion = 69;
	this->mModel = 0;
}


void validate_CItem(void){

	VALIDATE(CItem, mFlags, 0x4);
	VALIDATE(CItem, mPos, 0x8);
	VALIDATE(CItem, mAngles, 0x14);
	VALIDATE(CItem, mModel, 0x1A);
	VALIDATE(CItem, mRegion, 0x1F);

}