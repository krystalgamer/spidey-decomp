#include "utils.h"
#include <cstdlib>
#include <cmath>


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

const float FOUR_NINETY_SIX = 4096.0;
const float TWO_FOURTY_EIGHT = 2048.0;
const float PI = 3.1415927;

int Utils_ArcCos(int val){
	float inp = val;
	float res = acos(inp / FOUR_NINETY_SIX);
	return (res * TWO_FOURTY_EIGHT / PI);
}



// @Ok
// Matching
int Utils_CopyString(const char* src, char* dst, int maxSize)
{
	int total = 0;

	if (*src)
	{
		while (*src){

			if (total >= maxSize)
				break;

			*dst++ = *src++;
			total++;

		}
	}

	print_if_false(total < maxSize, "Dest buffer overflow in Utils_CopyString");
	*dst = 0;
	return total;
}

// @TODO
CBody* Utils_CheckObjectCollision(CVector*, CVector*, CBody*, CBody*)
{
	return reinterpret_cast<CBody*>(0x13052024);
}

// @TODO
int Utils_GetGroundHeight(CVector*, int, int, CBody**)
{
	return 0x14052024;
}

// @TODO
int Utils_LineOfSight(CVector*, CVector*, CVector*, int)
{
	return 0x15052024;
}

int catan(int a1)
{
	 return (atan((double)a1 / 4096.0) * 651.0006103515625);
}

// @Ok
int Utils_CalcAim(CSVector* a1, CVector* a2, CVector* a3)
{
	int x,y,z;
	x = (a3->vx - a2->vx) >> 12;
	y = (a3->vy - a2->vy) >> 12;
	z = (a3->vz - a2->vz) >> 12;

	if (z)
	{
		if (z > 0)
		{
			a1->vy = catan(-((x << 12) / z));
		}
		else
		{
			a1->vy = catan((x << 12) / z);
		}
	}
	else
	{
		if (x > 0)
		{
			a1->vy = -1024;
		}
		else
		{
			a1->vy = 1024;
		}
	}

	int v7 = M3dMaths_SquareRoot0(x*x + z*z);
	if (v7)
	{
		if (y > 0)
		{
			a1->vx = catan((y<<12) / v7);
		}
		else
		{
			a1->vx = -catan(-4096 * y / v7);
		}
	}
	else
	{
		a1->vx = y > 0 ? 1024 : -1024;
	}

	a1->vx &= 0xFFF;
	a1->vy &= 0xFFF;
	a1->vz = 0;
	return v7;
}

// @TODO
int Utils_GetValueFromDifficultyLevel(int, int, int, int)
{
	return 0x16052024;
}

static int gRndRelatedOne;
static int gRndRelatedTwo;
static int gRndRelatedThree;

// @Ok
void Utils_InitialRand(int a)
{
	gRndRelatedTwo = 0x12B9B0A1;
	gRndRelatedOne = a;
	gRndRelatedThree = 0xAA2FB3F;
}

// @Ok
int Rnd(int n)
{
	int result; // eax
	gRndRelatedOne = gRndRelatedThree + gRndRelatedOne * gRndRelatedTwo;
	gRndRelatedTwo = (gRndRelatedOne >> 4) + (gRndRelatedOne ^ gRndRelatedTwo);
	result = (n * (unsigned __int16)gRndRelatedOne) >> 16;
	gRndRelatedThree = gRndRelatedThree + (gRndRelatedOne >> 3) - 0x10101010;
	return result;
}

// @TODO
unsigned int Utils_GenerateCRC(const char*)
{
	return 0x29052024;
}

// @TODO
int Utils_LinearFilter(int, int, int)
{
	return 0x31052024;
}
