#include "ob.h"
#include "mem.h"
#include <cstring>


void* CItem::operator new(unsigned int size) {

  void *result = DCMem_New(size, 0, 1, 0, 1);

  unsigned int adjusted_size = ((size + 3) & 0xFFFFFFFC) >> 2;
  if ( adjusted_size )
    memset(result, 0, 4 * adjusted_size);

  return result;
}