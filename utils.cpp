#include "utils.h"
#include <cstdlib>


int Utils_CrapDist(const CVector& a,const CVector& b){

	
	int dX = a.vx - b.vx;
	int dY = a.vy - b.vy;
	int dZ = a.vz - b.vz;

    if (dX < 0) {
        dX = -dX;
    }

    if (dY < 0) {
        dY = -dY;
    }

    if (dZ < 0) {
        dZ = -dZ;
    }

    if (dX < dY){

        if (dY < dZ){
			return (dZ + (dX >>2) + (dY >>1)) >> 12;
		}

		if(dZ < dX){
			return ((dZ >> 2) + (dX >> 1) + dY) >> 12;
		}

		return ((dZ >> 1) + (dX >> 2) + dY) >> 12;
    }

    if (dX < dZ){
        return (dZ + (dX >>1) + (dY >>2)) >> 12;
    }

    if (dZ < dY){
        return ((dZ >> 2) + dX + (dY >>1)) >> 12;
    }

    return ((dZ >> 1) + dX + (dY >>2)) >> 12;
}

int Utils_CrapXZDist(const CVector& a,const CVector& b) {
    CVector tmp = a;
    tmp.vy = b.vy;
    return Utils_CrapDist(tmp, b);
}

int Utils_CompareStrings(const char* left, const char* right) {

    if (left == NULL && right == NULL){
        return 1;
    }

	if (left == NULL || right == NULL){
		return 0;
	}




    if (right != NULL){

        char currLeft = *left;
        char currRight = *right;
        if (currLeft >= 'A' && currLeft <= 'Z'){
            currLeft += ' ';
        }
        if (currRight >= 'A' && currRight <= 'Z'){
            currRight += ' ';
        }

        while (currLeft == currRight){

            if (currLeft != 0 && currRight != 0) {
                    currLeft = *++left;
                    currRight = *++right;

                    if (currLeft >= 'A' && currLeft <= 'Z'){
                        currLeft += ' ';
                    }
                    if (currRight >= 'A' && currRight <= 'Z'){
                        currRight += ' ';
                    }
            }
            else{
                break;
            }

        }

        if (currLeft == 0 && currRight == 0){
            return 1;
        }
    }

    return 0;
}
