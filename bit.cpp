#include "export.h"
#include "bit.h"
#include <cstring>
#include <cstdlib>


CBit::CBit() {

	this->mPos.vx = 0;
	this->mPos.vy = 0;
	this->mPos.vz = 0;

	this->mVel.vx = 0;
	this->mVel.vy = 0;
	this->mVel.vz = 0;

	this->mAcc.vx = 0;
	this->mAcc.vy = 0;
	this->mAcc.vz = 0;

	//mFric is inited to 0 here but removed

	this->mFric.vx = 1;
	this->mFric.vy = 1;
	this->mFric.vz = 1;
}


CBit::~CBit(){
	this->mNext = NULL;
}
