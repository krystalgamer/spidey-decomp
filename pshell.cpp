#include "pshell.h"
#include "mess.h"
#include "utils.h"
#include "spool.h"
#include "ps2lowsfx.h"
#include "shell.h"
#include "PCShell.h"

#include <cstring>

#include "validate.h"

EXPORT i32 JoelJewCheatCode;

SCheat gCheats[NUM_CHEATS] =
{
	{
			"WEAKNESS",
			"full health",
	},
	{
			"LEANEST",
			"everything",
	},
	{
			"GLANDS",
			"unlimited webbing",
	},
	{
			"EGOTRIP",
			"pulsating head",
	},
	{
			"RULUR",
			"J James Jewett",
	},
	{
			"SECRTWAR",
			"symbiote spidey costume",
	},
	{
			"MIGUELOH",
			"spidey 2099 costume",
	},
	{
			"TRISNTNL",
			"Captain Universe Costume",
	},
	{
			"SYNOPTIC",
			"Spidey Unlimited Costume",
	},
	{
			"XILRTRNS",
			"Scarlet Spider Costume",
	},
	{
			"KICK ME",
			"Amazing Bag Man Costume",
	},
	{
			"MRWATSON",
			"Peter Parker Costume",
	},
	{
			"SM LVIII",
			"Quick Change Costume",
	},
	{
			"ROBRTSON",
			"Storyboard Viewer",
	},
	{
			"KIRBYFAN",
			"Game Comic Covers",
	},
	{
			"MME WEB",
			"Level Select",
	},
	{
			"FANBOY",
			"Comic Collection",
	},
	{
			"CINEMA",
			"Movie Viewer",
	},
	{
			"RGSGLLRY",
			"Character Viewer",
	},
	{
			"UATUSEES",
			"What If Contest",
	},
	{
			"ADMNTIUM",
			"invulnerable",
	},
	{
			"CLUBNOIR",
			"Ben Reilly Costume",
	},
	{
			"STICKMAN",
			"Stick Spidey",
	},
	{
			"FUNKYTWN",
			"Toon Spidey",
	},
};

// @MEDIUMTODO
i32 ActivateCheat(i32)
{
    printf("ActivateCheat(i32)");
	//return 0x27092024;
	return 0;
}

// @Ok
// @NotMatching - those ++ are weird man
void DisplayScore(
		i32 a1,
		i32 a2,
		i32 a3,
		i32 a4)
{
	char v9[0x34];
	if (!a4)
	{
		i32 v4 = a3 / 6 / 600;
		i32 v5 = a3 / 6 % 600;

		if ( v4 > 99 )
			v4 = 99;

		char* v6 = &v9[0];
		if ( v4 > 9 )
		{
			v6 = &v9[1];
			v9[0] = v4 / 10 + '0';
		}

		*v6 = v4 % 10 + '0';
		char* v7 = v6 + 1;
		*v7++ = 58;
		*v7++ = (char)v5 / 100 + '0';
		*v7++ = v5 % 100 / 10 + '0';
		*v7++ = 46;

		*v7 = v5 % 100 % 10 + '0';
		v7[1] = 0;
		Mess_DrawText(a1, a2, v9, 0, 0x1000);
	}
	else
	{
		sprintf(v9, "%d", a3);
		Mess_DrawText(a1, a2, v9, 0, 0x1000);
	}
}

// @Ok
// @Matching
i32 PShell_ActivateCheat(char * pStr)
{
	i32 v1 = -1;

	for (i32 i = 0; i < NUM_CHEATS; i++)
	{
		if (Utils_CompareStrings(pStr, gCheats[i].pCode))
		{
			v1 = i;
			break;
		}
	}

	if (v1 == 4)
		return -1;

	if (ActivateCheat(v1))
		return v1;

	return -1;
}

// @SMALLTODO
void PShell_ApplyGameState(void)
{
    printf("PShell_ApplyGameState(void)");
}

// @Ok
// @Matching
void PShell_BigFont(void)
{
	Mess_SetCurrentFont("font_big.fnt");
}

// @SMALLTODO
void PShell_DrawHighlight(i32,i32,i32,i32)
{
    printf("PShell_DrawHighlight(i32,i32,i32,i32)");
}

// @SMALLTODO
void PShell_EndTrainingDisplay(void)
{
    printf("PShell_EndTrainingDisplay(void)");
}

// @MEDIUMTODO
void PShell_EndTrainingInit(void)
{
    printf("PShell_EndTrainingInit(void)");
}

// @MEDIUMTODO
void PShell_EndTrainingUpdate(void)
{
    printf("PShell_EndTrainingUpdate(void)");
}

// @MEDIUMTODO
void PShell_MaybeSaveGame(void)
{
    printf("PShell_MaybeSaveGame(void)");
}

// @MEDIUMTODO
void PShell_MaybeUnlockStuff(void)
{
    printf("PShell_MaybeUnlockStuff(void)");
}

// @Ok
// @Matching
i32 PShell_MoveTowards(
		i32 a1,
		i32 a2)
{
	i32 v2 = a2 - a1;
	if (!v2)
		return a1;

	if ((v2 & 0xFFFFFFFC) == 0 )
		return a1 + 1;

	return a1 + (v2 >> 2);
}

// @Ok
CExpandingBox::~CExpandingBox(void)
{
}


EXPORT int PShell_DrawMenuBox(int, int, int, int, int, int, int, int){
	return 69;
}


// @Ok
CExpandingBox::CExpandingBox(
		int a2,
		int a3,
		int a4,
		int a5,
		int a6,
		int a7,
		int a8,
		int a9,
		int a10)
{
	this->field_1C = a2;
	this->field_20 = a3;
	this->field_C = a4;
	this->field_10 = a5;
	this->field_4 = a6;
	this->field_8 = a7;
	this->field_14 = a8;
	this->field_18 = a9;
	this->field_24 = a10;
	this->field_2C = 28;
}



// @MEDIUMTODO
int CExpandingBox::Display(){

	/*
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
		*/
	return 0x14072024;
}

int expected(){ return 200;}
int not_expected() { return 69; }

// @BIGTODO
int CExpandingBox::ScrollBarHitTest(int a2, int a3){


	/*
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
  */
	return 0x14072024;
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

void validate_CExpandingBox(void)
{
	VALIDATE_SIZE(CExpandingBox, 0x34);

	VALIDATE(CExpandingBox, field_4, 0x4);
	VALIDATE(CExpandingBox, field_8, 0x8);
	VALIDATE(CExpandingBox, field_C, 0xC);
	VALIDATE(CExpandingBox, field_10, 0x10);
	VALIDATE(CExpandingBox, field_14, 0x14);
	VALIDATE(CExpandingBox, field_18, 0x18);
	VALIDATE(CExpandingBox, field_1C, 0x1C);

	VALIDATE(CExpandingBox, field_20, 0x20);
	VALIDATE(CExpandingBox, field_24, 0x24);

	VALIDATE(CExpandingBox, field_2C, 0x2C);
}

void validate_SCheat(void)
{
	VALIDATE_SIZE(SCheat, 0x8);

	VALIDATE(SCheat, pCode, 0x0);
	VALIDATE(SCheat, pDescription, 0x4);

	if (strcmp(gCheats[NUM_CHEATS-1].pCode, "FUNKYTWN"))
	{
		printf("MISMATCH IN CHEAT TABLE %s should be FUNKYTWN", gCheats[NUM_CHEATS-1].pCode);
	}


}
