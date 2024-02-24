#include "pshell.h"


EXPORT int __cdecl PShell_DrawMenuBox(int, int, int, int, int, int, int, int){
	return 69;
}


CExpandingBox::CExpandingBox(int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9,int a10){
	  this->unk_7 = a2;
	  this->unk_8 = a3;
	  this->unk_3 = a4;
	  this->unk_4 = a5;
	  this->unk_1 = a6;
	  this->unk_2 = a7;
	  this->unk_5 = a8;
	  this->unk_6 = a9;
	  this->unk_9 = a10;
	  this->unk_11 = 28;
}



CExpandingBox::Display(){

	int unk_3; // ebx
	int v2; // eax
	int unk_4; // eax
	int v4; // edx
	int unk_1; // edi
	unk_3 = this->unk_3;
	v2 = this->unk_5 + this->unk_1;
	this->unk_1 = v2;
	if ( v2 > unk_3 )
		this->unk_1 = unk_3;
	unk_4 = this->unk_4;
	v4 = this->unk_6 + this->unk_2;
	this->unk_2 = v4;
	if ( v4 > unk_4 )
		this->unk_2 = unk_4;
	unk_1 = this->unk_1;
	if ( unk_1 == unk_3 && this->unk_2 == unk_4 )
	this->unk_12 = 1;

	return PShell_DrawMenuBox(
		this->unk_7 + unk_3 / 2 - unk_1 / 2,
		this->unk_8 + unk_4 / 2 - this->unk_2 / 2,
		unk_1,
		this->unk_2,
		1,
		this->unk_9,
		this->unk_10,
		this->unk_11);

}

CExpandingBox::~CExpandingBox(){}