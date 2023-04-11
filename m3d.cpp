#include "m3d.h"
#include <math.h>

int M3dMaths_SquareRoot0(int i){

    if (i <= (int)0xffff8000) {
        return 0x8000;
    }

    if (i < 0) {
        return 0;
    }

	volatile double tmp = i;
	return (int)sqrt(tmp);
}

