#include "pshell.h"
#include "mess.h"


EXPORT int __cdecl PShell_DrawMenuBox(int, int, int, int, int, int, int, int){
	return 69;
}


// @TODO
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



// @TODO
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

int expected(){ return 200;}
int not_expected() { return 69; }

// @NotOk
// check
int CExpandingBox::ScrollBarHitTest(int a2, int a3){


	int v4; // r11
  int v5; // r8
  int v6; // r9
  int v7; // r7
  int v8; // r4
  unsigned __int16 v9; // r3

  if ( !this->unk_9|| !this->unk_12 )
    return 0;
  v4 = 0;
  v5 = (unsigned __int16)this->unk_8;
  v7 = (unsigned __int16)(this->unk_7 - 14);

  //int v10 = (unsigned __int16)(v5 - 3);
  if ( a2 >= v7
    && a2 <= v7 + 14
    && a3 >= (unsigned __int16)(v5 - 3)
    && (v6 = (unsigned __int16) this->unk_2, a3 <= (unsigned __int16)(v5 - 3) + (unsigned __int16)((unsigned __int16)v6 + 6) ))
  {
    v8 = this->unk_11;
    v9 = v5 + ((this->unk_10 * (this->unk_2 - 8 - v8)) >> 8) + 4;

	if ( a3 <= (unsigned __int16)(v5 + 7) ){
		v4 = 1;
	}
	else{

      if ( a3 >= (unsigned __int16)(v5 + v6 - 5) )
      {
		  v4 = 2;
        
      }
      else
      {
        if ( a3 < v9 )
        {
			 v4 = 4;
       
        }
        else
        {
			v4 = ( a3 > v9 + (unsigned __int16)v8 ) ? 5 : 3;
        }
      }
    }
  }
  return v4;
}

static unsigned char gCheatRelatedOne;
static int gCheatRelatedTwo;
static int gCheatRelatedThree;
static int gCheatRelatedFour;
static int gCheatRelatedFive;
static int gCheatRelatedSix;
static unsigned char gCheatRelatedSeven;

// @NotOk
// Globals
void PShell_BigCheat(void)
{
      gCheatRelatedOne = 1;
      gCheatRelatedTwo = -1;
      gCheatRelatedThree = -1;
      gCheatRelatedFour = -1;
      gCheatRelatedFive = -1;
      gCheatRelatedSix = -1;
      gCheatRelatedSeven = 1;
}

CExpandingBox::~CExpandingBox(){}

// @Ok
void PShell_NormalFont(void)
{
	Mess_SetScale(256);
	Mess_SetCurrentFont("sp_fnt00.fnt");
}

// @Ok
void PShell_DefaultText(void)
{
	PShell_NormalFont();
	Mess_SetTextJustify(0);
	Mess_SetRGB(0x80, 0x80, 0x80, 0);
	Mess_SetRGBBottom(0x45, 60, 107);
}

// @Ok
void PShell_SmallFont(void)
{
	Mess_SetScale(256);
	Mess_SetCurrentFont("sp_fnt02.fnt");
}

// @Ok
void PShell_InstructionalText(void)
{
	PShell_SmallFont();
	Mess_SetTextJustify(0);
	Mess_SetRGB(0x45u, 0x3Cu, 0x6Bu, 0);
	Mess_SetRGBBottom(0x28u, 35, 62);
}
