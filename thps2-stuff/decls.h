#include "types.h"

// address: 0x800B4C08
// size: 0x2D4
extern short DefaultAnimations[362];

// address: 0x800D7D48
extern int GWins1;

// address: 0x800D7D4C
extern int GLosses1;

// address: 0x800D7D50
extern int GStreak1;

// address: 0x800D7D54
extern int GHighTags1;

// address: 0x800D7D58
extern int GWins2;

// address: 0x800D7D5C
extern int GLosses2;

// address: 0x800D7D60
extern int GStreak2;

// address: 0x800D7D64
extern int GHighTags2;

// address: 0x800D7D68
extern int Face_Air;

// address: 0x800D7D6C
extern int Face_Skateable;

// address: 0x800D7D70
extern int Face_WallRide;

// address: 0x800D7D74
extern int Face_Visible;

// address: 0x800D7D78
extern int Face_Terrain;

// address: 0x800D7D7C
extern int NumExtraAnims;

// address: 0x800D7CB4
// size: 0xC
extern struct CVector WorldGravity;

// address: 0x800D7CC0
// size: 0xC
extern struct CVector UpNormal;

// address: 0x800D7CB0
extern int SelectedControlScheme;

// address: 0x800D7CA0
extern int Cheat_StatsOverride;

// address: 0x800D7CA4
// size: 0xC
extern struct CVector WorldUp;

// address: 0x800D7CF4
extern short *pExtraAnim;

// address: 0x800D7EB8
extern char *pBMR;

// address: 0x800D7EB4
extern unsigned short *pCompressedBMR;

// address: 0x800B5494
// size: 0x12D0
extern struct SStats Stats[14];

// address: 0x800B6764
// size: 0x488
extern struct SLevel Levels[10];

// address: 0x800B5334
// size: 0x2C
extern char *HawkBio[11];

// address: 0x800B5360
// size: 0x44
extern char *MuskaBio[17];

// address: 0x800B53A4
// size: 0x14
extern char *MullenBio[5];

// address: 0x800B53B8
// size: 0x14
extern char *BurnquistBio[5];

// address: 0x800B53CC
// size: 0x14
extern char *RowleyBio[5];

// address: 0x800B53E0
// size: 0x14
extern char *LasekBio[5];

// address: 0x800B53F4
// size: 0x14
extern char *CampbellBio[5];

// address: 0x800B5408
// size: 0x14
extern char *ReynoldsBio[5];

// address: 0x800B541C
// size: 0x14
extern char *GlifbergBio[5];

// address: 0x800B5430
// size: 0x14
extern char *ThomasBio[5];

// address: 0x800B5444
// size: 0x14
extern char *SteamerBio[5];

// address: 0x800B5458
// size: 0x14
extern char *CaballeroBio[5];

// address: 0x800B546C
// size: 0x14
extern char *KostonBio[5];

// address: 0x800B5480
// size: 0x14
extern char *CustomBio[5];

// address: 0x800B04BC
// size: 0x1E
static char CARD_GTITLE[30];

// address: 0x800B04DC
// size: 0x1E
static char CARD_VTITLE[30];

// address: 0x800B04FC
// size: 0x20
static char Tape01IconPalette[32];

// address: 0x800B051C
// size: 0x80
static char Tape01IconTexture[128];

// address: 0x800B059C
// size: 0x20
static char Tony01IconPalette[32];

// address: 0x800B05BC
// size: 0x80
static char Tony01IconTexture[128];

// address: 0x800B6C24
// size: 0x3C
extern enum EFileType_duplicate_e1 FileType[15];

// address: 0x800B6C60
// size: 0x258
extern struct DIRENTRY SLOT_DIR[15];

// address: 0x800B6BEC
// size: 0x19
extern char CARD_FNAME[25];

// address: 0x800B6C08
// size: 0x19
extern char CARD_VNAME[25];

// address: 0x800D8BC4
extern int CardStatusTemp;

// address: 0x800D8BC8
extern int CardStatusMode;

// address: 0x800D8BCC
extern int TimeStamp;

// address: 0x800D8BD0
extern unsigned long ev0;

// address: 0x800D8BD4
extern unsigned long ev1;

// address: 0x800D8BD8
extern unsigned long ev2;

// address: 0x800D8BDC
extern unsigned long ev3;

// address: 0x800D8BE0
extern unsigned long ev10;

// address: 0x800D8BE4
extern unsigned long ev11;

// address: 0x800D8BE8
extern unsigned long ev12;

// address: 0x800D8BEC
extern unsigned long ev13;

// address: 0x800D8BF0
extern int EVENT_TIME_OUT;

// address: 0x800D8BF4
extern long FILE_DSCRPTR;

// address: 0x800D8B9C
extern int CardStatus;

// address: 0x800D8BA0
extern int CardLoadFlag;

// address: 0x800D8B98
extern int Card_Init_Called;

// address: 0x800B5138
// size: 0x14
extern struct SVideoRestart GVideoRestart;

// address: 0x800B514C
// size: 0xA5
extern char ASCIIName[11][15];

// address: 0x800B51F4
// size: 0x3C
extern char *VertMenuItem[15];

// address: 0x800B5230
// size: 0x3C
extern int VertMenuItemIndex[15];

// address: 0x800B526C
// size: 0xC8
extern struct SCachedBackground BGCache[10];

// address: 0x800D7EA0
// size: 0x4
extern enum ELoadAction GLoadAction;

// address: 0x800D7EA4
// size: 0x4
extern enum ESaveAction GSaveAction;

// address: 0x800D7EA8
// size: 0xB
extern char StoredCareerName[11];

// address: 0x800D7DFC
extern bool VideoToDisk;

// address: 0x800D7E4C
// size: 0x4
extern enum EMemCardState MCState;

// address: 0x800D7E00
extern int GHasCareerLoaded;

// address: 0x800D7E04
extern int GLoadedCareerIsSaved;

// address: 0x800D7E08
// size: 0xB
extern char SaveGameName[11];

// address: 0x800D7E14
extern int CursorPos;

// address: 0x800D7E18
extern int SizeUp;

// address: 0x800D7E1C
// size: 0xB
extern char LastCareerName[11];

// address: 0x800D7E28
// size: 0xB
extern char LastVideoName[11];

// address: 0x800D7E34
// size: 0x334
extern struct VerticalMenu *pVertMenu;

// address: 0x800D7E38
extern int NumVertMenuItems;

// address: 0x800D7E3C
extern int VertMenuTopIndex;

// address: 0x800D7E40
extern int VertMenuTopChanged;

// address: 0x800D7E44
extern int SelectedSkater;

// address: 0x800D7E48
extern int FreeSprite;

// address: 0x800D7E50
// size: 0x4
extern enum EMemCardState OldMCState;

// address: 0x800D7E54
extern int CheckingCardPause;

// address: 0x800D7E58
static int MCResolution;

// address: 0x800DC64C
// size: 0x18
static struct Sprite *Tri1;

// address: 0x800DC650
// size: 0x18
static struct Sprite *Tri2;

// address: 0x800DC654
static int SaveNeedBlocks;

// address: 0x800DC658
static int SaveFreeBlocks;

// address: 0x800DC65C
// size: 0x4
static enum EPausedStatus_duplicate_e2 GReturnToState;

// address: 0x800B71F8
// size: 0x28C
extern struct LocalText GameText;

// address: 0x800B4F80
// size: 0x1A0
extern struct GamePreferences GPreferences;

// address: 0x800B4F1C
// size: 0x64
extern char *DefaultHighScoreInitials[25];

// address: 0x800B5120
// size: 0x18
extern struct SCrowd Crowd[1];

// address: 0x800D7DE8
extern int Crowd_Bored;

// address: 0x800B0668
// size: 0x88
extern struct SSaveGame DefaultGameState;

// address: 0x800B7058
// size: 0x88
extern struct SSaveGame LastGameState;

// address: 0x800B70E0
// size: 0x88
extern struct SSaveGame StartupGameState;

// address: 0x800B7168
// size: 0x1E
extern char DemoName[30];

// address: 0x800B7188
// size: 0x20
extern int StatsLeft[8];

// address: 0x800B71A8
// size: 0x20
extern int StatsRight[8];

// address: 0x800B71C8
// size: 0x18
extern char soundBuf[24];

// address: 0x800B71E0
// size: 0x18
extern char musicBuf[24];

// address: 0x800B6FEC
// size: 0x6C
extern struct SFrontBackground FrontBackgrounds[3];

// address: 0x800B6EB8
// size: 0x14
extern struct CTape *GTape[5];

// address: 0x800B6ECC
// size: 0x120
extern struct FallingTextEffect GHorseFallingText;

// address: 0x800D8F34
extern int BackOut;

// address: 0x800D8F38
extern int StartScreen;

// address: 0x800D8F3C
extern int DemoTimer;

// address: 0x800D8F40
extern int Cheat_AllTapes;

// address: 0x800D8F44
extern int GHorseSounded;

// address: 0x800D8F48
extern int GHorseScale;

// address: 0x800D8F4C
extern int GCompoSounded;

// address: 0x800D8F50
extern int NextHorseMode;

// address: 0x800D8F54
extern int NextHorsePlayer;

// address: 0x800D8F58
extern int NextHorseScore;

// address: 0x800D8F5C
extern int NextHorseRestart;

// address: 0x800D8F60
// size: 0x8
extern int NextHorseLetters[2];

// address: 0x800D8F68
// size: 0xC
extern struct SONG_POS Paused_SongPos;

// address: 0x800D8F74
extern int Front_OnTime;

// address: 0x800D8F78
extern int StatsMode;

// address: 0x800D8F7C
extern int GStart1;

// address: 0x800D8F80
extern int GStart2;

// address: 0x800D8F84
extern unsigned int JudgeTimer;

// address: 0x800D8F88
extern unsigned int LadderTimer;

// address: 0x800D8F8C
extern unsigned int WinLoseTimer;

// address: 0x800D8CB0
// size: 0x180
extern struct CMenu *pYesNoMenu;

// address: 0x800D8C08
extern int TitleTimeout;

// address: 0x800D8C94
extern int GamePaused;

// address: 0x800D8CA4
extern int LeftRightAutoRepeatTimer;

// address: 0x800D8CAC
extern int VoiceLevelGotFocus;

// address: 0x800D8CA8
// size: 0x8
extern struct SAnimFrame *ButtonsAnim;

// address: 0x800D8C48
extern int CurrentFrontBackground;

// address: 0x800D8C00
extern int SFXLEVEL;

// address: 0x800D8C04
extern int XALEVEL;

// address: 0x800D8C18
extern int GSoftResetEnabled;

// address: 0x800D8C0C
extern bool GRollCredits;

// address: 0x800D8BF8
extern int GHorseContinue;

// address: 0x800D8BFC
extern int MIDILEVEL;

// address: 0x800D8C10
extern int GHighScoreLineIndex;

// address: 0x800D8C14
extern int GHighScoreInitialCursorPos;

// address: 0x800D8C1C
// size: 0x4
extern enum EPausedStatus_duplicate_e2 Status;

// address: 0x800D8C90
extern unsigned int *pSizeData;

// address: 0x800D8C98
static int WobbleAmplitude;

// address: 0x800D8C9C
static int WobbleT;

// address: 0x800D8CA0
static int UpDownAutoRepeatTimer;

// address: 0x800D8CB4
// size: 0x180
extern struct CMenu *pESMenu;

// address: 0x800D8CB8
// size: 0x180
extern struct CMenu *pVSMenu;

// address: 0x800D8CBC
// size: 0x180
extern struct CMenu *pVS2Menu;

// address: 0x800D8CC0
// size: 0x180
extern struct CMenu *pVS3Menu;

// address: 0x800D8CC4
// size: 0x180
extern struct CMenu *pEHMenu;

// address: 0x800D8CC8
// size: 0x180
extern struct CMenu *pERMMenu;

// address: 0x800D8CCC
// size: 0x180
extern struct CMenu *pSoundMenu;

// address: 0x800D8CD8
static int GaugeOn;

// address: 0x800D8CDC
static unsigned int TotalProgress;

// address: 0x800D8CE0
static unsigned int TotalSize;

// address: 0x800D8D00
// size: 0x180
static struct CMenu *pPausedMenu;

// address: 0x800D8D04
// size: 0x180
static struct CMenu *pRestartsMenu;

// address: 0x800DC678
static int soundVol;

// address: 0x800DC67C
static int musicVol;

// address: 0x800B75C4
// size: 0x168
extern struct FontInfo Font_table[10];

// address: 0x800B7484
// size: 0xA0
extern struct SMessageProg Messprog_Zoom[5];

// address: 0x800B7524
// size: 0xA0
extern struct SMessageProg Messprog_Goal[5];

// address: 0x800D94B2
extern unsigned short Clut;

// address: 0x800D94B4
extern unsigned char NewFont;

// address: 0x800D9490
// size: 0x1C
extern struct Message *pMessages;

// address: 0x800D9488
extern int Num_fonts;

// address: 0x800D948C
extern int Current_font;

// address: 0x800D9494
static unsigned char TextJustification;

// address: 0x800D9498
static unsigned int FlagsBGR;

// address: 0x800D949C
static unsigned short Scale;

// address: 0x800D949E
static unsigned short Sort;

// address: 0x800D94A0
extern int MessFade;

// address: 0x800DC680
static unsigned int LastFlagsBGR;

// address: 0x800D94B8
static unsigned char CurrentImportance;

// address: 0x800D94BC
static int FlashSort;

// address: 0x800D94C0
static int FlashCountdown;

// address: 0x800D94C4
static int Fading;

// address: 0x800D94C8
static int FadeCountdown;

// address: 0x800DC684
static unsigned int CurrentR;

// address: 0x800DC688
static unsigned int CurrentG;

// address: 0x800DC68C
static unsigned int CurrentB;

// address: 0x800DC690
static unsigned int dR;

// address: 0x800DC694
static unsigned int dG;

// address: 0x800DC698
static unsigned int dB;

// address: 0x800B772C
// size: 0x20
extern int XAGroupSectorLengths[8][1];

// address: 0x800D95B8
extern int Redbook_XAEndSector;

// address: 0x800D95BC
extern int Redbook_XACurrentSector;

// address: 0x800D95C0
// size: 0x8
extern unsigned char CdControlComeback[8];

// address: 0x800D956C
extern int Redbook_XACompleteTimer;

// address: 0x800D9570
extern bool Redbook_XACheckSectorOnVSync;

// address: 0x800D9574
extern bool Redbook_XAModeSet;

// address: 0x800D9560
// size: 0x4
extern int XAGroupStartingSector[1];

// address: 0x800D9564
extern int Redbook_XACurrentPriority;

// address: 0x800D9568
extern int Redbook_XAStartSector;

// address: 0x800D9578
extern int Redbook_XAPaused;

// address: 0x800D957C
extern bool Redbook_XAValid;

// address: 0x800D9580
extern int Redbook_XACurrentGroup;

// address: 0x800D9584
extern int Redbook_XACurrentChannel;

// address: 0x800D9588
extern int Redbook_XATryAgain;

// address: 0x800D958C
extern int Redbook_XASeeking;

// address: 0x800D9590
extern int Redbook_XAFadeScale;

// address: 0x800D9594
extern int Redbook_XAFading;

// address: 0x800DC6C4
static int RandSeed_addr_800DC6C4;

// address: 0x800DC6C8
static int RandA_addr_800DC6C8;

// address: 0x800DC6CC
static int RandB_addr_800DC6CC;

// address: 0x800B7834
// size: 0x974
extern struct SCareer GCareer;

// address: 0x800B81A8
// size: 0x16C
extern struct SControl TempPad;

// address: 0x800B774C
// size: 0x11
extern char HexDigits[17];

// address: 0x800B7760
// size: 0x20
extern struct SDemo pLittleDemo[4];

// address: 0x800B7780
// size: 0x14
extern struct SViewport ApocalypseViewport;

// address: 0x800B7794
// size: 0x14
extern struct SViewport LeftViewport;

// address: 0x800B77A8
// size: 0x14
extern struct SViewport RightViewport;

// address: 0x800B77BC
// size: 0x14
extern struct SViewport TopViewport;

// address: 0x800B77D0
// size: 0x14
extern struct SViewport BottomViewport;

// address: 0x800B77E4
// size: 0x14
extern struct SViewport TopLeftViewport;

// address: 0x800B77F8
// size: 0x14
extern struct SViewport BottomRightViewport;

// address: 0x800B780C
// size: 0x14
extern struct SViewport TopLeftBigViewport;

// address: 0x800B7820
// size: 0x14
extern struct SViewport BottomRightBigViewport;

// address: 0x800D97A8
extern void *OldSP;

// address: 0x800D97AC
extern int CurrentGameLevel;

// address: 0x800D97B0
extern int CurrentWaterDamage;

// address: 0x800D97B4
extern int CurrentDifficultyLevel;

// address: 0x800D97B8
extern int XFrames;

// address: 0x800D97BC
extern int TimeScale;

// address: 0x800D97C0
extern int TimeScaleSquared;

// address: 0x800D97C4
extern unsigned char *PolyBufferEnd;

// address: 0x800D97C8
extern int GState;

// address: 0x800D97CC
extern int GSpin;

// address: 0x800D97D0
extern int GSpinSpeed;

// address: 0x800D97D4
extern int GStartTime;

// address: 0x800D97D8
// size: 0x8
extern int GSkaterRegion[2];

// address: 0x800D97E0
extern int GHorsePlayer;

// address: 0x800D97E4
extern int GHorseMode;

// address: 0x800D97E8
extern int GHorseScore;

// address: 0x800D97EC
extern int GHorseDoneStart;

// address: 0x800D97F0
extern int GHorseRestart;

// address: 0x800D97F4
// size: 0x8
extern int GHorseLetters[2];

// address: 0x800D97FC
extern int GHorseCursorPos;

// address: 0x800D9800
extern int GHorseWaitTime;

// address: 0x800D9804
extern int GHorseClearInput2;

// address: 0x800D9808
extern char GVideoFlags;

// address: 0x800D980C
extern short *GTricksKeys;

// address: 0x800D9810
extern short *GGrindTricksList;

// address: 0x800D9814
extern short *GBailsList;

// address: 0x800D9818
// size: 0x8
extern struct CBruce_duplicate_s0 *GSkater[2];

// address: 0x800D9820
// size: 0x138
extern struct CPowerUp *GPowS;

// address: 0x800D9824
// size: 0x138
extern struct CPowerUp *GPowK;

// address: 0x800D9828
// size: 0x138
extern struct CPowerUp *GPowA;

// address: 0x800D982C
// size: 0x138
extern struct CPowerUp *GPowT;

// address: 0x800D9830
// size: 0x138
extern struct CPowerUp *GPowE;

// address: 0x800D9834
// size: 0x138
extern struct CPowerUp *GPowTape;

// address: 0x800D9838
extern int GClear1;

// address: 0x800D983C
extern int GClear2;

// address: 0x800D9840
extern int GRenderedInvisible;

// address: 0x800D9844
extern int GRenderedCulled;

// address: 0x800D9848
extern int GRenderedFast;

// address: 0x800D984C
extern int GRenderedNonRotated;

// address: 0x800D9850
extern int GRenderedRotated;

// address: 0x800D9854
extern int NumPolyF3;

// address: 0x800D9858
extern int NumPolyFT3;

// address: 0x800D985C
extern int NumPolyG3;

// address: 0x800D9860
extern int NumPolyGT3;

// address: 0x800D9864
extern int NumPolyF4;

// address: 0x800D9868
extern int NumPolyFT4;

// address: 0x800D986C
extern int NumPolyG4;

// address: 0x800D9870
extern int NumPolyGT4;

// address: 0x800D9874
extern int NumSetTile;

// address: 0x800D9878
extern int NumTile1;

// address: 0x800D987C
extern int NumOther;

// address: 0x800D9880
extern int CloseCam;

// address: 0x800D9884
extern int PrimitiveCount;

// address: 0x800D9888
extern int XFramesShifted;

// address: 0x800D988C
// size: 0xC
extern int FPS[3];

// address: 0x800D9898
extern int LastXblanks;

// address: 0x800D989C
extern int Profile_Bop;

// address: 0x800D98A0
// size: 0x18
extern struct Sprite *pScoreSprite;

// address: 0x800D98A4
// size: 0x18
extern struct Sprite *pSpecialSprite;

// address: 0x800D98A8
// size: 0x18
extern struct Sprite *pBarSprite;

// address: 0x800D98AC
// size: 0x18
extern struct Sprite *pPausedSprite;

// address: 0x800D98B0
extern int MemDumpLoop;

// address: 0x800D98B4
extern int DemoSize;

// address: 0x800D961C
// size: 0x4
extern enum EEndCode EndCode;

// address: 0x800D9620
extern int TTime;

// address: 0x800D9628
extern int Restart;

// address: 0x800D962C
extern int CurrentWaterLevel;

// address: 0x800D9630
extern int CurrentWaterLevel2;

// address: 0x800D9634
extern int CurrentDualShockLevel;

// address: 0x800D9674
// size: 0x10
extern struct VECTOR Zero;

// address: 0x800D966C
extern int PolyBufferBytesUsed;

// address: 0x800D95E0
extern int GNumberOfPlayers;

// address: 0x800D95DC
extern int GGame;

// address: 0x800D95E4
extern int GAutoTest;

// address: 0x800D95E8
extern int GAutoPlayer1;

// address: 0x800D95EC
extern int GAutoPlayer2;

// address: 0x800D95F0
extern int GAutoLevel;

// address: 0x800D95F4
extern int GAutoGame;

// address: 0x800D9608
extern int GHorseWordChosen;

// address: 0x800D95CC
extern short *GTricks;

// address: 0x800D95C8
extern int Cheat_FlipScreen;

// address: 0x800D95D0
// size: 0x9
extern char Code_String[9];

// address: 0x800D95F8
extern int GAutoPlayer1a;

// address: 0x800D95FC
extern int GAutoPlayer2a;

// address: 0x800D9600
extern int GAutoLevela;

// address: 0x800D9604
extern int GAutoGamea;

// address: 0x800D960C
extern int Mick_MapMode;

// address: 0x800D9610
extern int Mick_MapDoit;

// address: 0x800D9614
extern int SelectedSkater2;

// address: 0x800D9618
static char *pAutoTestRestartName;

// address: 0x800D9624
extern int EveryOther;

// address: 0x800D9638
extern int GameFrozen;

// address: 0x800D963C
extern int Cheat_PanelOn;

// address: 0x800D9640
extern int Cheat_L2KillsBaddies;

// address: 0x800D9644
extern int Cheat_LevelSelect;

// address: 0x800D9648
extern int Cheat_AutoTest;

// address: 0x800D964C
extern int Cheat_RestartSkip;

// address: 0x800D9650
extern int Cheat_GameInfo;

// address: 0x800D9654
extern int Cheat_FPS;

// address: 0x800D9658
extern int Cheat_Blood;

// address: 0x800D965C
extern int Cheat_SlowMo;

// address: 0x800D9660
extern int Cheat_BigHead;

// address: 0x800D9664
extern int Cheat_ScreenShots;

// address: 0x800D9668
extern int Cheat_Fire;

// address: 0x800D9670
extern int MusicStopped;

// address: 0x800D9684
extern int TotalCClassUsage;

// address: 0x800D9688
extern int Mick_Darkness;

// address: 0x800D968C
extern int ViewportMode;

// address: 0x800D9690
extern int PatchX;

// address: 0x800D9694
extern int PatchY;

// address: 0x800D969C
static unsigned int LoopTimer;

// address: 0x800D96A0
extern int FPSIndex;

// address: 0x800D96C0
extern int MemTotal;

// address: 0x800D9768
extern int DemoDiskMode;

// address: 0x800D94DC
// size: 0x108
extern struct CBody_duplicate_s1 *PowerUpList;

// address: 0x800D9548
// size: 0x6
static struct CSVector *pNormal;

// address: 0x800D954C
static int ShatterSound;

// address: 0x800DC6B8
static int VRAMClut;

// address: 0x800DC6BC
static int VRAMTPage;

// address: 0x800DC6C0
static unsigned char AverageR;

// address: 0x800DC6C1
static unsigned char AverageG;

// address: 0x800DC6C2
static unsigned char AverageB;

// address: 0x800DC6AC
// size: 0xC
static struct CVector ShatterCentre;

// address: 0x800DC69C
// size: 0xC
static struct CVector ShatterSoundPos;

// address: 0x800DC6D4
static unsigned short mInputFlagsCopy;

// address: 0x800D9AF4
extern int NumBaddies;

// address: 0x800D9B00
extern int NumZombies;

// address: 0x800D9B04
// size: 0x108
extern struct CBody_duplicate_s1 *BaddyList;

// address: 0x800D9AF8
extern int NumGenericBaddies;

// address: 0x800D9AFC
extern int NumHoverSWATS;

// address: 0x800B832C
// size: 0x18
extern struct SAnimFrame *QuickAnimLookup[6];

// address: 0x800B8314
// size: 0x18
static char *AnimNames[6];

// address: 0x800D9AB8
// size: 0x48
extern struct CNonRenderedBit *NonRenderedBitList;

// address: 0x800D9ABC
// size: 0x70
extern struct CFlatBit *FlatBitList;

// address: 0x800D9AC0
// size: 0x78
extern struct CLinked2EndedBit *Linked2EndedBitList;

// address: 0x800D9AC4
// size: 0x54
extern struct CPixel *PixelList;

// address: 0x800D9AC8
// size: 0x9C
extern struct CQuadBit *QuadBitList;

// address: 0x800D9ACC
// size: 0xC4
extern struct CGenPoly *GenPolyList;

// address: 0x800D9AD0
// size: 0xC0
extern struct CChunkBit *ChunkBitList;

// address: 0x800D9AD4
// size: 0x68
extern struct CGlow *GlowList;

// address: 0x800D9AD8
// size: 0x78
extern struct CGlassBit *GlassList;

// address: 0x800D9ADC
// size: 0x48
extern struct CSpecialDisplay *SpecialDisplayList;

// address: 0x800D9AE0
// size: 0x60
extern struct CPolyLine *PolyLineList;

// address: 0x800D9AE4
// size: 0x64
extern struct CGPolyLine *GPolyLineList;

// address: 0x800D9AE8
// size: 0x68
extern struct CGLine *GLineList;

// address: 0x800D9AEC
// size: 0x8
extern struct DR_TPAGE StoredTPagePrim;

// address: 0x800D9914
extern int BitCount;

// address: 0x800D994C
// size: 0x28
extern struct Texture *pShadowTexture;

// address: 0x800D9918
extern int UseCacheForBits;

// address: 0x800D9910
extern int TotalBitUsage;

// address: 0x800D9950
// size: 0x6
extern struct CSVector SparkTrajectory;

// address: 0x800D9958
// size: 0x6
extern struct CSVector SparkTrajectoryCone;

// address: 0x800D9960
extern unsigned int SparkSize;

// address: 0x800D9964
extern bool SparkSemiTrans;

// address: 0x800D9968
// size: 0x4
extern struct CVECTOR SparkRGB;

// address: 0x800D996C
// size: 0x4
extern struct CVECTOR SparkFadeRGB;

// address: 0x800D9B34
// size: 0xC
extern struct CVector ZeroVector;

// address: 0x800D9B40
// size: 0x6
extern struct CSVector ZeroSVector;

// address: 0x800D9B48
extern unsigned int SuspendDistance;

// address: 0x800D9B2C
// size: 0x108
extern struct CBody_duplicate_s1 *EnvironmentalObjectList;

// address: 0x800D9B30
// size: 0x108
extern struct CBody_duplicate_s1 *SuspendedList;

// address: 0x800B8F00
// size: 0xA0
extern char *MenuFilenamePointers[40];

// address: 0x800B8E60
// size: 0x50
extern char *CheatRestarts[20];

// address: 0x800B8EB0
// size: 0x50
extern char *HorseRestarts[20];

// address: 0x800B84E0
// size: 0x980
extern struct SGapTrick GapTricks[304];

// address: 0x800DA2C8
extern unsigned char CurrentObjFileRegion;

// address: 0x800DA2C9
extern unsigned char CurrentItemsFileRegion;

// address: 0x800DA2CA
extern unsigned char CurrentMedalsFileRegion;

// address: 0x800DA2CC
extern int TrigFileSize;

// address: 0x800DA278
extern short **OffsetList;

// address: 0x800DA274
extern int RestartNode;

// address: 0x800DA27C
extern int NumNodes;

// address: 0x800DA280
extern char *pCurrentObjFile;

// address: 0x800DA284
extern int NumTrigMenuEntries;

// address: 0x800DA268
extern int NumCheatRestarts;

// address: 0x800DA26C
extern int NumHorseRestarts;

// address: 0x800DA270
extern unsigned short *TrigFile;

// address: 0x800DA288
// size: 0x18
static struct SCommandPoint *CommandPoints;

// address: 0x800DA28C
extern int TotalCommandPointMemory;

// address: 0x800DA2C0
static unsigned int *pPSXDualBuffer;

// address: 0x800DCA8C
// size: 0x400
static struct SCommandPoint *HashTable[256];

// address: 0x800B8FA0
// size: 0x24
extern struct CVector ExplosionCentre[3];

// address: 0x800DA2F0
// size: 0xC
extern int ExplosionType[3];

// address: 0x800DA2FC
// size: 0xC
extern int ExplosionRadius[3];

// address: 0x800DA308
// size: 0xC
extern int ExplosionDamage[3];

// address: 0x800DA314
// size: 0xC
extern int ExplosionPriority[3];

// address: 0x800DA2D4
extern unsigned int GameFade;

// address: 0x800DA2D8
extern unsigned int Vblanks;

// address: 0x800DA2DC
extern unsigned int Xblanks;

// address: 0x800DA2E8
extern int DoVblankProcessing;

// address: 0x800DA2D0
extern int ExplosionStackIndex;

// address: 0x800DA2E0
extern unsigned int LastVblanks;

// address: 0x800DA2E4
extern int DoDisplayDraw;

// address: 0x800DA2EC
extern int VblankUpdateBar;

// address: 0x800DC6D8
static int RandSeed_addr_800DC6D8;

// address: 0x800DC6DC
static int RandA_addr_800DC6DC;

// address: 0x800DC6E0
static int RandB_addr_800DC6E0;

// address: 0x800B83AC
// size: 0x118
extern short SkaterHooks[10][14];

// address: 0x800B84C4
// size: 0x1C
extern short HeadBloodAtFrame[14];

// address: 0x800B8344
// size: 0x34
extern struct SLight Skater_DefaultLight;

// address: 0x800B8378
// size: 0x34
extern struct SLight Skater_MarsLight;

// address: 0x800D9B20
// size: 0xA
extern struct BoardStats GBoardStats[2];

// address: 0x800D9B0C
extern int NumMechs;

// address: 0x800D9B10
// size: 0x108
extern struct CBody_duplicate_s1 *MechList;

// address: 0x800D9B08
// size: 0x146C
extern struct CBruce_duplicate_s0 *pCurrentPlayer;

// address: 0x800BA878
// size: 0x200
extern char NumberStrings[512];

// address: 0x800BA778
// size: 0x100
extern unsigned char BigFont_Mapping[256];

// address: 0x800B9A78
// size: 0xC80
extern struct SString StringBuffer[100];

// address: 0x800BA6F8
// size: 0x80
extern unsigned char Mapping[128];

// address: 0x800DA3F4
// size: 0x20
extern struct SString *BufferPos;

// address: 0x800DA3F8
extern char *pNumberStrings;

// address: 0x800DA3D8
// size: 0x8
extern struct SAnimFrame *BigFontAnim;

// address: 0x800DA3D4
// size: 0x8
static struct SAnimFrame *FontAnim;

// address: 0x800DA3DC
static unsigned int CodeVal;

// address: 0x800BAA78
// size: 0x5800
extern char Directory[22528];

// address: 0x800DA46C
extern int FileIO_Size;

// address: 0x800DA470
extern char *Opening;

// address: 0x800DA474
extern int LastLoading;

// address: 0x800DA404
extern int Loading;

// address: 0x800DA3FC
extern char *Where;

// address: 0x800DA400
extern int CurrentPos;

// address: 0x800DA408
static char *FilePath;

// address: 0x800DA40C
static int FileOpen;

// address: 0x800DA410
static int SectorsPerFrame;

// address: 0x800DA414
static int ReadSyncFailures;

// address: 0x800DA418
extern bool SpoolerBlocksFileIO;

// address: 0x800DA41C
extern int LoadFromPRE;

// address: 0x800DA420
extern char *ThePREFile;

// address: 0x800DA424
extern int ThePREFileSize;

// address: 0x800DC6E4
// size: 0x10
static char FileSubDirName[16];

// address: 0x800DC6F4
static int FirstChar;

// address: 0x800DC6F8
static short FileID;

// address: 0x800DC6FC
static int FileSize;

// address: 0x800DC700
static int Remainder;

// address: 0x800DC704
static int NewLoad;

// address: 0x800DC708
static int WadStart;

// address: 0x800DC70C
// size: 0x4
static struct CdlLOC FileStart;

// address: 0x800DC710
static unsigned long *Dest;

// address: 0x800DC714
static int NumSectors;

// address: 0x800DC718
static int Start;

// address: 0x800DD098
// size: 0x32
static char FileName[50];

// address: 0x800DA4BC
// size: 0x8
extern int Used[2];

// address: 0x800DA4C4
// size: 0x8
extern struct SBlockHeader *FirstFreeBlock[2];

// address: 0x800DA488
// size: 0x10
extern unsigned int HeapDefs[2][2];

// address: 0x800DA498
extern int LowMemory;

// address: 0x800DA478
extern int Mem_NumNew;

// address: 0x800DA47C
extern int Mem_NumDelete;

// address: 0x800DA49C
static unsigned int CriticalBigHeapUsage;

// address: 0x800DA4A0
static unsigned int UniqueIndentifier;

// address: 0x800DA4B8
extern int ReturnAddress;

// address: 0x800DA36C
extern int ZapCalls;

// address: 0x800DA358
extern int Pack_NoBottom;

// address: 0x800DA35C
extern int Pack_NoRight;

// address: 0x800DA350
// size: 0x10
extern struct TSPack *Pack_pFull;

// address: 0x800DA34C
// size: 0x10
extern struct TSPack *Pack_pFree;

// address: 0x800DA354
extern int TotSlots;

// address: 0x800DA360
extern int Pack_Width;

// address: 0x800DA364
// size: 0x4
extern enum EPackInitType_duplicate_e1 LastPackInitType;

// address: 0x800DA368
extern int TotalPackUsage;

// address: 0x800B911C
// size: 0x100
extern unsigned char HasTrans16[256];

// address: 0x800B921C
// size: 0x4B
extern unsigned char HasTrans256[75];

// address: 0x800DA378
// size: 0x14
extern struct tag_S_Pal *pPaletteList;

// address: 0x800DA37C
extern int Pal16X;

// address: 0x800DA380
extern int Pal16Y;

// address: 0x800DA384
extern int Pal256X;

// address: 0x800DA388
extern int Pal256Y;

// address: 0x800DA370
extern bool TransparentPalForEditor;

// address: 0x800DA374
extern int TotalPaletteUsage;

// address: 0x800DCE8C
// size: 0x100
static unsigned char Free16Slots[256];

// address: 0x800DCF8C
// size: 0x4B
static unsigned char Free256Slots[75];

// address: 0x800B9290
// size: 0x300
extern unsigned int SFXArray[192];

// address: 0x800B9590
// size: 0x80
extern unsigned short SFXAliasArray[64];

// address: 0x800B9610
// size: 0x300
extern unsigned int SFXLevelSpecificArray[192];

// address: 0x800B9910
// size: 0x80
extern unsigned short SFXLevelSpecificAliasArray[64];

// address: 0x800B9990
// size: 0x60
extern unsigned int SFXFalloffArray[24];

// address: 0x800B99F0
// size: 0x88
extern char SoundRamMemoryManagementTable[136];

// address: 0x800B9268
// size: 0x28
static unsigned int reverbWorkspace[10];

// address: 0x800DA3CC
extern unsigned int SFX_ReverbDepthSetTimer;

// address: 0x800DA3D0
extern int SFX_v;

// address: 0x800DA38C
extern int TotalVabUsage;

// address: 0x800DA390
extern void *pSFXVABHeader;

// address: 0x800DA394
extern void *pLevelSpecificSFXVABHeader;

// address: 0x800DA398
static int SFXVABId;

// address: 0x800DA39C
static int LevelSpecificSFXVABId;

// address: 0x800DA3A0
extern bool SFXPaused;

// address: 0x800DA3A4
static unsigned int soundRAMOccupied;

// address: 0x800DA3A8
extern long nko_flag;

// address: 0x800DA3AC
extern long keyon_queue;

// address: 0x800DA3B0
extern unsigned long reverb_queue;

// address: 0x800DA3B4
extern long keyoff_queue;

// address: 0x800DA3B8
extern long voiceon_flag;

// address: 0x800DA3BC
extern long exp_flag;

// address: 0x800DA3C0
extern long loop_flag;

// address: 0x800DA3C4
extern long voicefree_flag;

// address: 0x800DA3C8
extern char reverb_changed;

// address: 0x800DCFD8
// size: 0x30
static unsigned short voicePitch[24];

// address: 0x800DD008
// size: 0x30
static unsigned short voiceVolume[24];

// address: 0x800DD038
// size: 0x30
static struct soundRAMentry soundRAMSlots[4];

// address: 0x800DD068
// size: 0x30
static unsigned short pitchPriorToPause[24];

// address: 0x800B8FC4
// size: 0x158
extern struct SDoubleBuffer DoubleBuffer[2];

// address: 0x800DA338
// size: 0xAC
extern struct SDoubleBuffer *pDoubleBuffer;

// address: 0x800DA33C
// size: 0xAC
extern struct SDoubleBuffer *pOtherBuffer;

// address: 0x800DA340
extern unsigned int *OrderingTable;

// address: 0x800DA344
extern unsigned int *pPoly;

// address: 0x800DA348
// size: 0xAC
extern struct SDoubleBuffer *pVB;

// address: 0x800DA320
extern int Db_Background;

// address: 0x800DA328
extern int POLYBUFFERSIZE;

// address: 0x800DA324
extern unsigned int Db_SkyColor;

// address: 0x800DA32C
extern int CurrentOTSize;

// address: 0x800C0390
// size: 0x8C
extern short CamPtNode[70];

// address: 0x800C0278
// size: 0x118
extern int CamModes[70];

// address: 0x800DA4CC
extern int CamPtIndex;

// address: 0x800DA51C
extern int TrickPlayer;

// address: 0x800DA520
extern int TrickScore;

// address: 0x800DA4E0
// size: 0x18
extern struct CTrickOb *TrickObList;

// address: 0x800DA4E4
// size: 0x6
extern unsigned short DarkenTimer[3];

// address: 0x800DA4EC
static int MapX;

// address: 0x800DA4F0
static int MapY;

// address: 0x800DA4F4
static int MapScale;

// address: 0x800DA4F8
extern int Missed;

// address: 0x800DA548
// size: 0x4
extern struct NodeSort *RailNodeLookup;

// address: 0x800DA54C
extern int TotalRailNodes;

// address: 0x800DA524
// size: 0x28
extern struct CRail *RailList;

// address: 0x800DA578
// size: 0x18
extern struct FP *FPBuf;

// address: 0x800DA57C
// size: 0x18
extern struct FP *CurrentFP;

// address: 0x800DA580
extern int NumUsedFps;

// address: 0x800C041C
// size: 0x30
extern struct Vector _14EditorOutModel_LightVect[4];

// address: 0x800C044C
// size: 0x30
extern struct Vector _14EditorOutModel_LightLoc[4];

// address: 0x800DA5DC
extern unsigned char *_14EditorOutModel_MixLookup;

// address: 0x800DA5E0
extern unsigned char *_14EditorOutModel_IntensityLookup;

// address: 0x800DA5E4
extern int _14EditorOutModel_FallOff;

// address: 0x800DA5E8
extern int _14EditorOutModel_LightIntensity;

// address: 0x800DA5EC
extern int _14EditorOutModel_DaMix;

// address: 0x800DA5F0
extern int _14EditorOutModel_CurrentFace;

// address: 0x800DA5F4
// size: 0x14
extern struct ModelFace2 *_14EditorOutModel_FaceBuf;

// address: 0x800DA5F8
extern bool _13EditorInModel_GameBuild;

// address: 0x800DA5FC
// size: 0x2C
extern struct ModelFace *_13EditorInModel_pMaxBufEntry;

// address: 0x800DA600
// size: 0x2C
extern struct ModelFace *_13EditorInModel_pPolyBufEntry;

// address: 0x800C047C
// size: 0x2400
extern struct GridCell _14LevelGenerator_GridTab[24][24];

// address: 0x800DA66C
extern int _14LevelGenerator_OutRegion;

// address: 0x800DA670
extern int _14LevelGenerator_GridCellHeight;

// address: 0x800DA674
extern int _14LevelGenerator_GridCellWidth;

// address: 0x800DA660
extern int GridSize;

// address: 0x800DA7EC
extern int HiresMode;

// address: 0x800DA760
extern int OT_entry;

// address: 0x800DA764
static int OT_half;

// address: 0x800C2B28
// size: 0xF0
extern struct SSoundCmd SoundCmd[30];

// address: 0x800C291C
// size: 0xC0
extern struct SVideoInfo GVInfo1;

// address: 0x800C29DC
// size: 0xC0
extern struct SVideoInfo GVInfo2;

// address: 0x800C2A9C
// size: 0x1C
static int PosBits[7];

// address: 0x800C2AB8
// size: 0x1C
static int EulerBits[7];

// address: 0x800C2AD4
// size: 0x1C
static int FlipAngleBits[7];

// address: 0x800C2AF0
// size: 0x1C
static int PrefixCode[7];

// address: 0x800C2B0C
// size: 0x1C
static int PrefixBits[7];

// address: 0x800DA800
extern int FirstEntry;

// address: 0x800DA804
extern int LastEntry;

// address: 0x800DA808
extern int Splat1;

// address: 0x800DA80C
extern int Splat2;

// address: 0x800DA810
extern int TrickOb1;

// address: 0x800DA814
extern int TrickOb2;

// address: 0x800DA818
extern int HighlightStartFrame;

// address: 0x800DA81C
extern int HighlightEndFrame;

// address: 0x800DA820
extern int HighlightStartY;

// address: 0x800DA824
extern int HighlightEndY;

// address: 0x800DA7F4
extern int GVideoReplay;

// address: 0x800DA7F0
extern int ReplaySoundLockout;

// address: 0x800DA7F8
extern int HLStartCalled;

// address: 0x800DA6C0
// size: 0x144
extern struct PREManager *PREMgr;

// address: 0x800C287C
// size: 0x80
extern char _11FontManager_FontName[16][8];

// address: 0x800C28FC
// size: 0x20
extern struct Font_duplicate_s0 *_11FontManager_FontTab[8];

// address: 0x800C2CCC
// size: 0x154
extern struct SQueue SpoolQ[20];

// address: 0x800C2E20
// size: 0xA00
extern struct SPSXRegion PSXRegion[40];

// address: 0x800C3820
// size: 0x800
extern struct Texture *TextureChecksumHashTable[512];

// address: 0x800C4020
// size: 0xA0
extern unsigned int *Memories[40];

// address: 0x800DAA24
// size: 0x8
extern unsigned int *EnvModelChecksums[2];

// address: 0x800DAA00
// size: 0x8
extern struct AnimPacket *AnimPackets;

// address: 0x800DA9F8
extern int SpoolPos;

// address: 0x800DA9DC
// size: 0x8
extern int EnvRegions[2];

// address: 0x800DA9F0
// size: 0x24
extern struct Item *EnviroList;

// address: 0x800DA9F4
extern int OtherEnvIndex;

// address: 0x800DA9E8
// size: 0x8
extern unsigned int *pTexWibPacket[2];

// address: 0x800DA9E4
static unsigned int *pCurrentTexWibPacket;

// address: 0x800DA9FC
static int FreePos;

// address: 0x800DAA04
extern int TotalTextureUsage;

// address: 0x800DC74C
static int HashIndex;

// address: 0x800DC750
// size: 0x28
static struct Texture *pCurrentTex;

// address: 0x800C40C0
// size: 0x2D8
extern struct SControl Pad[2];

// address: 0x800C4398
// size: 0x44
extern struct ControllerBuffer controllers[2];

// address: 0x800C43DC
// size: 0x40
extern struct ControllerData theControllers[8];

// address: 0x800DAA60
extern int Pad_IdleTime;

// address: 0x800DAA2C
extern int XMinL;

// address: 0x800DAA30
extern int XMaxL;

// address: 0x800DAA34
extern int YMinL;

// address: 0x800DAA38
extern int YMaxL;

// address: 0x800DAA3C
extern int XMinR;

// address: 0x800DAA40
extern int XMaxR;

// address: 0x800DAA44
extern int YMinR;

// address: 0x800DAA48
extern int YMaxR;

// address: 0x800DAA4C
extern int XCenterL;

// address: 0x800DAA50
extern int YCenterL;

// address: 0x800DAA54
extern int XCenterR;

// address: 0x800DAA58
extern int YCenterR;

// address: 0x800DAA5C
extern int WarningTimer;

// address: 0x800DAA64
// size: 0x6
static unsigned char align[6];

// address: 0x800DAA6C
static int ControlSystemInitialised;

// address: 0x800DAA70
// size: 0x50
static struct CTextWindow *WinList;

// address: 0x800C2C2C
// size: 0x38
extern int SkaterRegion[14];

// address: 0x800C2C18
// size: 0x14
extern struct SViewport HiResViewport;

// address: 0x800DA840
extern int GLevel;

// address: 0x800DA828
static int AutoRepeatTimer;

// address: 0x800DA878
extern int CarVol;

// address: 0x800C2C64
// size: 0x14
extern int Depreciation_Values[5];

// address: 0x800C2C78
// size: 0x18
extern int Spin_Mult_Values[6];

// address: 0x800C2C90
// size: 0x3C
extern int Num_Mult_Values[15];

// address: 0x800DA9D0
extern int GGameFont;

// address: 0x800DA9D4
extern unsigned int LastHoldingScore;

// address: 0x800DA9D8
extern bool prim_added;

// address: 0x800DA884
extern int LowMemoryIndicatorTimer;

// address: 0x800DA9CC
extern int Cheat_BigScore;

// address: 0x800DA87C
// size: 0x8
static struct SAnimFrame *PanelAnim;

// address: 0x800DA8F4
extern int TAPES_Display;

// address: 0x800DA8F8
extern int TAPES_Pos;

// address: 0x800DA8FC
extern int SKATE_Display;

// address: 0x800DA900
extern int SKATE_Pos;

// address: 0x800DAAAC
extern int NumContinues;

// address: 0x800DAA9C
extern char *TrigFileName;

// address: 0x800DAAA0
extern char *ContinueTRG;

// address: 0x800DAABC
// size: 0x10
extern struct _FrontPreInfo preInfo[2];

// address: 0x800C441C
// size: 0x84
extern int saturationCurve[33];

// address: 0x800C4588
// size: 0x438
extern struct CCreateTexSpec HeadSpec[15];

// address: 0x800C49C0
// size: 0x1F8
extern struct CCreateTexSpec UpperBodySpec[7];

// address: 0x800C4BB8
// size: 0x168
extern struct CCreateTexSpec LowerBodySpec[5];

// address: 0x800C44A0
// size: 0x18
extern struct _SCreateTexList DefaultFace[3];

// address: 0x800C44B8
// size: 0x18
extern struct _SCreateTexList BlackBald[3];

// address: 0x800C44D0
// size: 0x18
extern struct _SCreateTexList CurlyHair[3];

// address: 0x800C44E8
// size: 0x18
extern struct _SCreateTexList CapTop[3];

// address: 0x800C4500
// size: 0x18
extern struct _SCreateTexList DefaultThigh[3];

// address: 0x800C4518
// size: 0x28
extern struct _SCreateTexList DefaultShin[5];

// address: 0x800C4540
// size: 0x18
extern struct _SCreateTexList LongPantsFullLeg[3];

// address: 0x800C4558
// size: 0x18
extern struct _SCreateTexList KneepadShin[3];

// address: 0x800C4570
// size: 0x18
extern struct _SCreateTexList BaggyPantsFullLeg[3];

// address: 0x800DAB94
// size: 0x10
extern struct _SCreateTexList ShadowedFace[2];

// address: 0x800DAC18
// size: 0x10
extern struct _SCreateTexList HelmetTop[2];

// address: 0x800DAC40
// size: 0x10
extern struct _SCreateTexList HelmetFace[2];

// address: 0x800DAC94
// size: 0x10
extern struct _SCreateTexList BeanieTop[2];

// address: 0x800DACAC
// size: 0x10
extern struct _SCreateTexList AfroFace[2];

// address: 0x800DACD0
// size: 0x10
extern struct _SCreateTexList RastaFace[2];

// address: 0x800DACF4
// size: 0x10
extern struct _SCreateTexList SkinFace[2];

// address: 0x800DAD10
// size: 0x10
extern struct _SCreateTexList WhiteAfroFace[2];

// address: 0x800DAD38
// size: 0x10
extern struct _SCreateTexList GilliganTop[2];

// address: 0x800DAD54
// size: 0x10
extern struct _SCreateTexList AsianFace[2];

// address: 0x800DAD78
// size: 0x10
extern struct _SCreateTexList SlickFace[2];

// address: 0x800DADA0
// size: 0x10
extern struct _SCreateTexList GenericHand[2];

// address: 0x800DADC4
// size: 0x10
extern struct _SCreateTexList GenericShoe[2];

// address: 0x800DADE8
// size: 0x10
extern struct _SCreateTexList DefaultChest[2];

// address: 0x800DAE04
// size: 0x10
extern struct _SCreateTexList DefaultBicep[2];

// address: 0x800DAE28
// size: 0x10
extern struct _SCreateTexList DefaultForearm[2];

// address: 0x800DAE54
// size: 0x10
extern struct _SCreateTexList LongSleeveChest[2];

// address: 0x800DAE80
// size: 0x10
extern struct _SCreateTexList LongSleeveFullArm[2];

// address: 0x800DAEA8
// size: 0x10
extern struct _SCreateTexList NoShirtChest[2];

// address: 0x800DAED0
// size: 0x10
extern struct _SCreateTexList NoShirtFullArm[2];

// address: 0x800DAEF4
// size: 0x10
extern struct _SCreateTexList HoodyChest[2];

// address: 0x800DAF10
// size: 0x10
extern struct _SCreateTexList HoodyFullArm[2];

// address: 0x800DAF38
// size: 0x10
extern struct _SCreateTexList TanktopChest[2];

// address: 0x800DAF48
// size: 0x10
extern struct _SCreateTexList TanktopFullArm[2];

// address: 0x800DAF64
// size: 0x10
extern struct _SCreateTexList ElbowPadsChest[2];

// address: 0x800DAF84
// size: 0x10
extern struct _SCreateTexList ElbowPadsBicep[2];

// address: 0x800DAFA0
// size: 0x10
extern struct _SCreateTexList ElbowPadsForearm[2];

// address: 0x800DB088
// size: 0x10
extern struct _SCreateTexList KneepadThigh[2];

// address: 0x800C4DD4
// size: 0x960
extern struct SPart Part[120];

// address: 0x800C4D20
// size: 0x4C
extern char *BodyPart[19];

// address: 0x800C4D6C
// size: 0x20
extern struct SGroup Group[4];

// address: 0x800C4D8C
// size: 0x14
extern struct SViewport CreateViewport;

// address: 0x800C4DA0
// size: 0x34
static struct SLight Skater_CreateLight_addr_800C4DA0;

// address: 0x800DB364
// size: 0x10
extern struct SManualStitchPart ManualStitchPart[4];

// address: 0x800DB374
extern int PaletteSelected;

// address: 0x800DB378
extern int GFirstTime;

// address: 0x800DB37C
static int Create_NextBuildIndex;

// address: 0x800DB380
static int Create_IsSourceRegion;

// address: 0x800DB384
static int Create_IsBuildRegion;

// address: 0x800DB388
// size: 0x14
static struct SViewport *pViewport_addr_800DB388;

// address: 0x800DC77C
static int NextPart;

// address: 0x800DC780
static int Create_Parts;

// address: 0x800DC784
static char *pPSH;

// address: 0x800DD10C
// size: 0x734
static struct MySkater sMySkater;

// address: 0x800C61CC
// size: 0x2C
extern unsigned short *decodeSliceBuffer[11];

// address: 0x800C5D8C
// size: 0x60
extern struct CVector GameFMV_SoundSource[8];

// address: 0x800C5DEC
// size: 0x3C0
static struct SMovieDetails movieDetails[30];

// address: 0x800C61AC
// size: 0x1E
static char indices[30];

// address: 0x800DBD90
extern int GameFMV_CurrentFrame;

// address: 0x800DBD94
extern short GameFMV_StartX;

// address: 0x800DBD98
extern int GameFMV_StartSector;

// address: 0x800DBD9C
extern int GameFMV_EndFrame;

// address: 0x800DBDA0
extern unsigned int GameFMV_VLCBufferSize;

// address: 0x800DBDA4
extern unsigned int GameFMV_RingBufferSectors;

// address: 0x800DBDA8
extern unsigned char GameFMV_SliceBuffers;

// address: 0x800DBDAA
extern short GameFMV_StartY;

// address: 0x800DBDAC
extern unsigned short GameFMV_EndX;

// address: 0x800DBDAE
extern unsigned short GameFMV_Width;

// address: 0x800DBDB0
extern unsigned short GameFMV_Height;

// address: 0x800DBDB4
extern int GameFMV_NumSoundSources;

// address: 0x800DBDB8
extern unsigned char GameFMV_Is24Bit;

// address: 0x800DBDB9
extern unsigned char GameFMV_CurrentTrack;

// address: 0x800DBDBC
extern int GameFMV_MusicScale;

// address: 0x800DBDC0
// size: 0x8
extern struct RECT decodeSlice;

// address: 0x800DBDC8
// size: 0x8
extern unsigned int *vlcBuffer[2];

// address: 0x800DBBC4
extern int GameFMV_Active;

// address: 0x800DBBC8
extern int GameFMV_FrameBufferCopyActive;

// address: 0x800DBBBC
extern bool GameFMV_IsMovie;

// address: 0x800DBBC0
extern int GameFMV_RewindSwitch;

// address: 0x800DBBCC
static int currentDecodeBuffer;

// address: 0x800DBBD0
static int currentVlcBuffer;

// address: 0x800DBBD4
static int sendVLC;

// address: 0x800DBD84
extern int CycleTracks;

// address: 0x800DBD88
static int alreadyHandledPause;

// address: 0x800DC8C8
static unsigned long *pRingBuffer;

// address: 0x800C5948
// size: 0x24
extern struct SMedalMessage MedalMessage[3];

// address: 0x800C596C
// size: 0x130
extern struct CCompetition theCompetition;

// address: 0x800DB920
extern unsigned short HOLYCOW_PLACE;

// address: 0x800DB922
extern unsigned short FIRST_PLACE;

// address: 0x800DB924
extern unsigned short SECOND_PLACE;

// address: 0x800DB926
extern unsigned short THIRD_PLACE;

// address: 0x800DB928
extern unsigned short LAST_PLACE;

// address: 0x800DB9FC
// size: 0xC
static int next[3];

// address: 0x800B2EE0
// size: 0x21C
static struct CTrickTipText TRICKTIP[27];

// address: 0x800DB578
extern char *TEXT_TIP;

// address: 0x800DB588
extern char *TEXT_REMEMBER;

// address: 0x800DD840
// size: 0x114
static struct CTrickTipMonitor TrickTipMonitor;

// address: 0x800C5734
// size: 0x1E0
extern struct STapeMessage TapeMessage[30];

// address: 0x800DB90C
extern bool _5CTape_mOkayToDisplayContinueButton;

// address: 0x800DB910
extern bool _5CTape_mOkayToDisplayTitle;

// address: 0x800C5914
// size: 0x34
extern struct SLight Medal_DefaultLight;

// address: 0x800DBA28
// size: 0x108
extern struct CBody_duplicate_s1 *BackgroundList;

// address: 0x800DBA2C
static unsigned short CurrentIndex;

// address: 0x800DBA34
extern unsigned char InShell;

// address: 0x800DBA30
extern unsigned int CheatCheck;

// address: 0x800DC788
// size: 0x8
static struct DR_TPAGE tpage;

// address: 0x800DD954
// size: 0x18
static struct POLY_F4 pauseBox;

// address: 0x800C5B14
// size: 0x148
extern struct SCamera MikeCamera[2];

// address: 0x800C5C5C
// size: 0x20
extern struct MATRIX tm;

// address: 0x800C5A9C
// size: 0x3C
extern struct SPresetCamera Presets[5];

// address: 0x800C5AD8
// size: 0x14
extern struct CQuat testquat;

// address: 0x800C5AEC
// size: 0x14
extern struct CQuat testquat2;

// address: 0x800C5B00
// size: 0x14
extern struct CQuat testquat3;

// address: 0x800DBAAC
extern int NumCameras;

// address: 0x800DBAB0
// size: 0x108
extern struct CBody_duplicate_s1 *CameraList;

// address: 0x800DBAB4
extern unsigned int Camera_CurrentMikeCamera;

// address: 0x800DBA98
extern int Camera_CamPitch;

// address: 0x800DBA9C
extern int Camera_CamDist;

// address: 0x800DBAA0
// size: 0xC
extern struct CVector Camera_CamOffset;

// address: 0x800DBA38
extern int camDist;

// address: 0x800DBA3C
extern int camPitch;

// address: 0x800DBA40
extern int camYOffset;

// address: 0x800DBA44
static int camXZDistDeltaTimer;

// address: 0x800DBA48
static int camYDist;

// address: 0x800DBA4C
static int camYDistDeltaTimer;

// address: 0x800DBA50
static int camXOffset;

// address: 0x800DBA54
static int camXOffsetDeltaTimer;

// address: 0x800DBA58
static int camYOffsetDeltaTimer;

// address: 0x800DBA5C
static int camZOffset;

// address: 0x800DBA60
static int camZOffsetDeltaTimer;

// address: 0x800DBA64
static int Mick_CameraTweak;

// address: 0x800DBA68
extern int Camera_Preset;

// address: 0x800DBB24
extern short yangle;

// address: 0x800DC89C
static int camXZDistDelta;

// address: 0x800DC8A0
static int camYDistDelta;

// address: 0x800DC8A4
static int camAngleDelta;

// address: 0x800DC8A8
static int camAngleDeltaTimer;

// address: 0x800DC8AC
static int camAngleTarget;

// address: 0x800DC8B0
static int camXOffsetDelta;

// address: 0x800DC8B4
static int camYOffsetDelta;

// address: 0x800DC8B8
static int camZOffsetDelta;

// address: 0x800DC8BC
static int RandSeed_addr_800DC8BC;

// address: 0x800DC8C0
static int RandA_addr_800DC8C0;

// address: 0x800DC8C4
static int RandB_addr_800DC8C4;

// address: 0x800DC890
// size: 0xC
static struct CVector LoosePosition;

// address: 0x800DC880
// size: 0xC
static struct CVector LooseFocus;

// address: 0x800DC870
// size: 0xC
static struct CVector StartPosition;

// address: 0x800DC860
// size: 0xC
static struct CVector StartFocus;

// address: 0x800DC850
// size: 0xC
static struct CVector NormalPosition;

// address: 0x800DC840
// size: 0xC
static struct CVector NormalFocus;

// address: 0x800DC830
// size: 0xC
static struct CVector FarPosition;

// address: 0x800DC820
// size: 0xC
static struct CVector FarFocus;

// address: 0x800DC810
// size: 0xC
static struct CVector OverheadPosition;

// address: 0x800DC800
// size: 0xC
static struct CVector OverheadFocus;

// address: 0x800DC7F0
// size: 0xC
static struct CVector FlyFocus;

// address: 0x800DC7E0
// size: 0xC
static struct CVector DemoFocus;

// address: 0x800DC7D0
// size: 0x6
static struct CSVector BigShakeAmp;

// address: 0x800DC7C8
// size: 0x6
static struct CSVector MediumShakeAmp;

// address: 0x800DC7C0
// size: 0x6
static struct CSVector SmallShakeAmp;

// address: 0x800DC7B8
// size: 0x3
static struct CFriction LandShakeDecay;

// address: 0x800DC7B0
// size: 0x6
static struct CSVector LandShakeSpeed;

// address: 0x800DC7A0
// size: 0xC
static struct CVector UpDownPosition;

// address: 0x800C620C
// size: 0x38
extern int RotMap[2][7];

// address: 0x800DBEC4
extern unsigned char MainMenu_LastSelection;

// address: 0x800C82DC
// size: 0x14
extern int Floor1X1Piece[5];

// address: 0x800C82F0
// size: 0x14
extern int Floor1X2Piece[5];

// address: 0x800C8304
// size: 0x14
extern int Floor2X2Piece[5];

// address: 0x800C6244
// size: 0x1D7E
extern struct EditorPiece PieceMap[151];

// address: 0x800C7FE4
// size: 0x264
extern struct EditorCategory CategoryMap[18];

// address: 0x800C8248
// size: 0x91
extern unsigned char SaveMap[145];

// address: 0x800C7FC4
// size: 0x1E
extern struct PoolLinks PoolLinkMap[6];

// address: 0x800DBF40
extern int RiserPiece;

// address: 0x800DBF44
extern int NotInDemoPiece;

// address: 0x800DC8CC
static int Theme;

// address: 0x800DC17C
extern bool GenerateLevel;

// address: 0x800DC180
extern int PiecesRemaining;

// address: 0x800DBF48
extern int GenerateThemeNumber;

// address: 0x800C61F8
// size: 0x14
static struct SViewport CreateViewport1_addr_800C61F8;

// address: 0x800DBDD0
// size: 0x14
static struct SViewport *pViewport_addr_800DBDD0;

// address: 0x800DBDD4
static int SelectedLevel;

// address: 0x800DC520
extern int M3dElips_MinDotProd;

// address: 0x800C8514
// size: 0xA4
extern struct SLineInfo GColInfo;

// address: 0x800C85B8
// size: 0x20
extern struct MATRIX Tfm;

// address: 0x800C85D8
// size: 0x140
extern struct SColCache ItemCache[20];

// address: 0x800C8718
// size: 0x36B0
extern struct SFaceCache FaceCache[500];

// address: 0x800C84F0
// size: 0x24
extern struct SHit NearestHit;

// address: 0x800DC560
extern unsigned int M3dColij_ZeroMask;

// address: 0x800DC564
extern unsigned int M3dColij_OneMask;

// address: 0x800DC568
extern unsigned int M3dColij_ZeroOneMask;

// address: 0x800DC56C
// size: 0x108
extern struct CBody_duplicate_s1 *pBodyHit;

// address: 0x800DC570
extern int CollidedTriggerModel;

// address: 0x800DC528
extern int CameraCollisionCheck;

// address: 0x800DC52C
extern int BaddyCollisionCheck;

// address: 0x800DC530
extern int BulletCollisionCheck;

// address: 0x800DC534
extern int TriggerCollisionCheck;

// address: 0x800DC538
extern int LineOfSightCheck;

// address: 0x800DC524
extern unsigned short Inquiry;

// address: 0x800DC53C
extern int ItemCacheIndex;

// address: 0x800DC540
extern int ItemCacheStart;

// address: 0x800DC544
extern int FaceCacheIndex;

// address: 0x800DC548
extern int FaceCacheStart;

// address: 0x800DC54C
extern int BB_Hit;

// address: 0x800DC550
extern int BB_Miss;

// address: 0x800DC554
extern int BB_PolyHit;

// address: 0x800DC558
extern int BB_PolyMiss;

// address: 0x800DC55C
extern int DebugCol;

// address: 0x800CBDC8
// size: 0x2D0
extern struct SMatrix TweenBuffer[30];

// address: 0x800DC588
extern int LastDpqMax;

// address: 0x800DC58C
extern int LastDpqMin;

// address: 0x800DC590
extern int LastDpqShift;

// address: 0x800DC574
extern int GHeadPart;

// address: 0x800DC584
extern int GHeadUp;

// address: 0x800DC578
extern int GBoardPart;

// address: 0x800DC57C
extern int GWheel1Part;

// address: 0x800DC580
extern int GWheel2Part;

// address: 0x800CC098
// size: 0x660
extern struct SZone Zones[1];

// address: 0x800DC194
// size: 0x4
extern enum EWhichScreen WhichScreen;

// address: 0x800DC198
// size: 0x4
extern enum EWhichScreen LastScreen;

// address: 0x800DC19C
extern int FrontEnd2_GameMode;

// address: 0x800DC1A0
extern int FrontEnd2_SelectedLevel;

// address: 0x800DC1A4
extern bool FrontEnd2_TwoPlayer;

// address: 0x800DC1A8
extern int FrontEnd2_MusicLoopCurrentVol;

// address: 0x800DC1AC
extern int FrontEnd2_MusicLoopDesiredVol;

// address: 0x800DC184
extern int FrontEnd2_MusicLoopVoice;

// address: 0x800C8340
// size: 0x34
extern struct SLight Skater_CreditLight;

// address: 0x800DC1DC
// size: 0x8
extern int SCROLL_COUNT[2];

// address: 0x800DC208
static int Z_OVER_S;

// address: 0x800DC20C
static int Z_OVER_SY;

// address: 0x800DC210
static int SKATER_MID_POS;

// address: 0x800DC910
static int SKATER_Y_POS;

// address: 0x800C84D0
// size: 0x20
extern int MultiPlayerList[8];

// address: 0x800C8374
// size: 0x14
static struct SViewport CreateViewport1_addr_800C8374;

// address: 0x800C8388
// size: 0x34
static struct SLight Skater_CreateLight_addr_800C8388;

// address: 0x800C83BC
// size: 0x34
static struct SLight Skater_NotAvailableLight;

// address: 0x800C83F0
// size: 0xE0
extern struct ICON_INFO mIconInfo[8];

// address: 0x800DC2DC
extern int MultiPlayerListCount;

// address: 0x800DC2E0
extern int mCASTexturesSpooled;

// address: 0x800DC2E4
// size: 0x14
static struct SViewport *pViewport_addr_800DC2E4;

// address: 0x800CC72C
// size: 0x1900
extern struct SVertex Vertices[800];

// address: 0x800CE02C
// size: 0x800
extern short WibbleTables[1024];

// address: 0x800CE82C
// size: 0x50
extern struct SVECTOR FrustumNormals[10];

// address: 0x800CE87C
// size: 0x20
extern struct MATRIX FrustumMatrix1;

// address: 0x800CE89C
// size: 0x20
extern struct MATRIX FrustumMatrix2;

// address: 0x800CC6F8
// size: 0x34
extern struct SLight M3d_DefaultLight;

// address: 0x800DC5C0
extern int GModelVideoDisplayed;

// address: 0x800DC5C4
// size: 0x8
extern struct SProjectedVertex *ProjectedVertices;

// address: 0x800DC5C8
// size: 0x8
extern struct SRotatedVertex *RotatedVertices;

// address: 0x800DC5CC
extern int DpqMax;

// address: 0x800DC5D0
extern int DpqMin;

// address: 0x800DC5D4
extern int DpqShift;

// address: 0x800DC5D8
extern int DpqInterpTime;

// address: 0x800DC5DC
extern int DpqInterpDeltaMin;

// address: 0x800DC5E0
extern int DpqInterpDeltaMax;

// address: 0x800DC5E4
extern unsigned int M3d_FadeColour;

// address: 0x800DC5E8
extern unsigned int *pColourTable;

// address: 0x800DC5EC
// size: 0x14
extern struct SViewport *pCurrentViewport;

// address: 0x800DC5F0
// size: 0xA4
extern struct SCamera *pCurrentCamera;

// address: 0x800DC5F4
// size: 0x8
extern struct SVECTOR WaterNormal;

// address: 0x800DC5FC
extern unsigned int Xres;

// address: 0x800DC600
extern unsigned int Yres;

// address: 0x800DC604
extern int PixelAspectX;

// address: 0x800DC608
extern int PixelAspectY;

// address: 0x800DC60C
// size: 0x8
extern struct SProjectedVertex *FreeStitchVertex;

// address: 0x800DC610
extern unsigned int *CurrentOrderingTable;

// address: 0x800DC614
extern unsigned int RefMapClut;

// address: 0x800DC618
extern unsigned int RefMapTpage;

// address: 0x800DC61C
extern unsigned int RefMapU0V0;

// address: 0x800DC620
extern unsigned int XblanksNow;

// address: 0x800DC624
extern int SubObjectMasked;

// address: 0x800DC628
extern int TestTheWater;

// address: 0x800DC62C
extern int Fast;

// address: 0x800DC630
extern int Dewibble;

// address: 0x800DC634
extern int BasePhase;

// address: 0x800DC594
extern int M3d_WireframeMode;

// address: 0x800DC598
extern int M3d_WireframeLast;

// address: 0x800DC5A8
extern short M3d_OTPushback;

// address: 0x800DC5AA
extern short M3d_OTPushback2;

// address: 0x800DC5B8
extern short M3d_DefaultLODDistance;

// address: 0x800DC5AC
extern int M3d_Widescreen;

// address: 0x800DC59C
// size: 0x4
extern enum EWaterClip WaterClipValue;

// address: 0x800DC5A0
// size: 0x8
extern struct SVECTOR FarColor;

// address: 0x800DC5B0
extern unsigned int FrameNo;

// address: 0x800DC5B4
extern unsigned int XblanksThen;

// address: 0x800DC5BC
extern int ForceWireFrameColor;

// address: 0x800CE8BC
// size: 0x1800
extern unsigned short SqrtTable[3072];

// address: 0x80010000
// line start: 347
// line end:   354
void GetFaceFlags__FP9SLineInfo(struct SLineInfo *line_info) {
}


// address: 0x8001006C
// line start: 366
// line end:   373
int PingPong__Fiii(int a, int b, int fps) {
	// register: 5
	register int dif;
	// register: 6
	register int x;
}


// address: 0x800100B8
// line start: 386
// line end:   441
void TempTransform__6CBruce(struct CBruce_duplicate_s0 *this) {
	// address: 0xFFFFFF88
	// size: 0x20
	auto struct MATRIX SurfaceRotMatrix;
	// address: 0xFFFFFFA8
	// size: 0x8
	auto struct SVECTOR RotAngle;
	{
		{
			// address: 0xFFFFFFB0
			// size: 0x10
			auto struct VECTOR zero;
			// address: 0xFFFFFFC0
			// size: 0x10
			auto struct VECTOR v;
			// address: 0xFFFFFFD0
			// size: 0x10
			auto struct VECTOR v2;
			// address: 0xFFFFFFE0
			// size: 0x10
			auto struct VECTOR v3;
			{
				{
					// address: 0xFFFFFFB0
					// size: 0x20
					auto struct MATRIX Rail_RotMatrix;
					// address: 0xFFFFFFD0
					// size: 0x8
					auto struct SVECTOR RotAngle;
				}
			}
		}
	}
}


// address: 0x800102F4
// line start: 446
// line end:   448
void TempRestore__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x80010354
// line start: 453
// line end:   454
void Trick_PlayerInit__6CBruceUs(struct CBruce_duplicate_s0 *this, unsigned short player_num) {
}


// address: 0x8001037C
// line start: 459
// line end:   502
void Trick_TakeOff__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x80010418
// line start: 540
// line end:   565
void Trick_Trick__6CBrucePcii(struct CBruce_duplicate_s0 *this, char *pName, int Points, int Lock) {
	// register: 2
	register int Dep;
}


// address: 0x80010474
// line start: 569
// line end:   570
void Trick_HoldTrick__6CBrucei(struct CBruce_duplicate_s0 *this, int Points) {
}


// address: 0x80010494
// line start: 578
// line end:   582
void EndManual__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x800104BC
// line start: 591
// line end:   598
int Get180s__6CBruce(struct CBruce_duplicate_s0 *this) {
	// register: 5
	register int spins;
}


// address: 0x8001050C
// line start: 605
// line end:   695
void Trick_Land__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x80010730
// line start: 701
// line end:   755
void Trick_Bail__6CBruce(struct CBruce_duplicate_s0 *this) {
	// register: 17
	register int Speed;
	// register: 2
	register int Score;
}


// address: 0x80010800
// line start: 763
// line end:   777
void Vibrate__6CBruceiii(struct CBruce_duplicate_s0 *this, int time, int motor, int value) {
	// register: 8
	register int index;
}


// address: 0x80010890
// line start: 812
// line end:   877
void StateTransition__6CBruce13EPhysicsStatei(struct CBruce_duplicate_s0 *this, enum EPhysicsState_duplicate_e43 NewState, int line) {
	{
		{
			{
				{
					{
						{
							// address: 0xFFFFFFC0
							// size: 0xC
							auto struct CVector Temp;
							{
								// address: 0xFFFFFFC0
								// size: 0xC
								auto struct CVector Temp;
								{
									{
										{
											// address: 0xFFFFFFC0
											// size: 0xC
											auto struct CVector Temp;
											{
												// address: 0xFFFFFFC0
												// size: 0xC
												auto struct CVector Temp;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80010AE8
// line start: 886
// line end:   915
void MaybeFlipAnimationTransition__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x80010BEC
// line start: 920
// line end:   926
void Debug_RunAnim__6CBruceii(struct CBruce_duplicate_s0 *this, int x, int line) {
	{
		// register: 16
		// size: 0x190
		register struct CSuper *this;
		{
		}
	}
}


// address: 0x80010C40
// line start: 930
// line end:   936
void Debug_RunAnim1__6CBruceiii(struct CBruce_duplicate_s0 *this, int x, int y, int line) {
	{
		// register: 16
		// size: 0x190
		register struct CSuper *this;
		{
		}
	}
}


// address: 0x80010CA0
// line start: 940
// line end:   946
void Debug_RunAnim2__6CBruceiiii(struct CBruce_duplicate_s0 *this, int x, int y, int z, int line) {
	{
		// register: 16
		// size: 0x190
		register struct CSuper *this;
		{
		}
	}
}


// address: 0x80010D0C
// line start: 950
// line end:   956
void Debug_RunAnim3__6CBruceiiiii(struct CBruce_duplicate_s0 *this, int x, int y, int z, int zz, int line) {
	{
		// register: 16
		// size: 0x190
		register struct CSuper *this;
		{
		}
	}
}


// address: 0x80010D80
// line start: 981
// line end:   982
void ResetTrickBuffers__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x80010D88
// line start: 1014
// line end:   1106
void Bail__6CBrucei13ELimitBailVel(struct CBruce_duplicate_s0 *this, int BailNumber, enum ELimitBailVel_duplicate_e43 LimitBailVel) {
	// register: 5
	register int Offset;
	{
		{
			// register: 2
			register int Speed;
		}
	}
}


// address: 0x80010EB4
// line start: 1154
// line end:   1164
void ProjectCVectorToPlane__FP7CVectorG7SVECTOR(struct CVector *V, struct SVECTOR Normal) {
	// register: 16
	register int dot;
	// address: 0xFFFFFFE0
	// size: 0xC
	auto struct CVector N;
	{
		{
			{
				// register: 2
				register int _x;
				// register: 3
				register int _y;
				// register: 6
				register int _z;
			}
		}
	}
}


// address: 0x80010F50
// line start: 1180
// line end:   1205
void CVectorRotateToPlane__FP7CVectorP7SVECTORT0(struct CVector *InVector, struct SVECTOR *Normal, struct CVector *OutVector) {
	// address: 0xFFFFFFE8
	auto int OldMag;
	// address: 0xFFFFFFEC
	auto int NewMag;
}


// address: 0x80011070
// line start: 1214
// line end:   1323
void UberFrig__FP6CBruceG7CVectorPc(struct CBruce_duplicate_s0 *pSkater, struct CVector Pos, char *text) {
	// address: 0xFFFFFF40
	// size: 0xA4
	auto struct SLineInfo LInfo;
	{
		{
			{
				// register: 18
				register int OldX;
				// register: 20
				register int OldOldX;
				{
					// register: 5
					register int _x;
					// register: 3
					register int _y;
					// register: 6
					register int _z;
					{
						{
							{
								// register: 4
								register int _x;
								// register: 2
								register int _y;
								// register: 5
								register int _z;
								{
									// register: 2
									register int _y;
									// register: 4
									register int _z;
									{
										// register: 2
										register int _y;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8001131C
// line start: 1329
// line end:   1341
void FrigDarkenObject__6CBruce(struct CBruce_duplicate_s0 *this) {
	{
		{
			// register: 2
			register int Score;
		}
	}
}


// address: 0x80011378
// line start: 1347
// line end:   1397
void TrickObRail__6CBruce(struct CBruce_duplicate_s0 *this) {
	{
		{
		}
	}
}


// address: 0x80011388
// line start: 1401
// line end:   1430
void StartHandPlant__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x80011478
// line start: 1435
// line end:   1661
void StartGrind__6CBruce(struct CBruce_duplicate_s0 *this) {
	// address: 0xFFFFFFC0
	// size: 0xC
	auto struct CVector mSideVel;
	// register: 3
	register int temp;
	// register: 20
	register int FrontDot;
	// register: 18
	register int RightDot;
	// register: 2
	register int VelDot;
	// register: 19
	register int Direction;
	// register: 16
	register int RailTrick;
	// address: 0xFFFFFFD0
	// size: 0xC
	auto struct CVector Vel;
	{
		{
			// register: 16
			register int LastEvent;
			// register: 18
			register int FoundFirst;
			// register: 5
			register int Event;
		}
	}
}


// address: 0x80011A4C
// line start: 1682
// line end:   1834
void HandleStickToRail__6CBruce(struct CBruce_duplicate_s0 *this) {
	// register: 3
	register int Bailing;
	{
		{
			// register: 4
			register int bail;
		}
	}
}


// address: 0x80011CF8
// line start: 1839
// line end:   1881
void HandleBailOnLanding__6CBrucei(struct CBruce_duplicate_s0 *this, int line) {
	{
		{
			// register: 4
			register int Bailing;
		}
	}
}


// address: 0x80011E18
// line start: 1885
// line end:   2003
void HandleBailPerpendicular__6CBruceG7SVECTOR(struct CBruce_duplicate_s0 *this, struct SVECTOR Normal) {
	// address: 0xFFFFFF78
	// size: 0xC
	auto struct CVector InplaneVel;
	// register: 2
	register int Speed;
	// register: 2
	register int Dot;
	{
		{
			{
				{
					// address: 0xFFFFFF90
					// size: 0xC
					auto struct CVector PlaneUnitVector;
					// address: 0xFFFFFFA0
					// size: 0xC
					auto struct CVector InplaneFront;
					{
						{
							{
								{
									// register: 17
									register int RightDot;
									// address: 0xFFFFFFB0
									// size: 0x10
									auto struct VECTOR v;
									// address: 0xFFFFFFC0
									// size: 0xC
									auto struct CVector vv;
									{
										{
											{
												// register: 7
												register int _x;
												// register: 8
												register int _y;
												// register: 9
												register int _z;
												{
													// register: 4
													register int _x;
													// register: 2
													register int _y;
													// register: 5
													register int _z;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80012194
// line start: 2014
// line end:   2030
void TriggerTrick__6CBrucePs(struct CBruce_duplicate_s0 *this, short *pTrick) {
	{
		// register: 4
		// size: 0x190
		register struct CSuper *this;
		{
		}
	}
}


// address: 0x800121E0
// line start: 2040
// line end:   2043
void TriggerTrick__6CBrucei(struct CBruce_duplicate_s0 *this, int Trick) {
	// register: 5
	register int Offset;
}


// address: 0x80012238
// line start: 2058
// line end:   2081
void ButtonRecord__6CBruceUcUc(struct CBruce_duplicate_s0 *this, unsigned char Button, unsigned char Pressed) {
}


// address: 0x800122BC
// line start: 2157
// line end:   2175
void ButtonRemoveLast__6CBruceUcUc(struct CBruce_duplicate_s0 *this, unsigned char Button, unsigned char Pressed) {
	// register: 8
	register int Event;
}


// address: 0x80012344
// line start: 2183
// line end:   2219
int GetDirection__6CBruce(struct CBruce_duplicate_s0 *this) {
	// register: 3
	register int Direction;
	// address: 0x000002D4
	// size: 0x40
	static int DirectionMap[16];
}


// address: 0x800123D4
// line start: 2240
// line end:   2264
void UpdateButtons__6CBruce(struct CBruce_duplicate_s0 *this) {
	// register: 17
	register int Direction;
}


// address: 0x8001251C
// line start: 2272
// line end:   2294
void QueueTrick__6CBrucePsii(struct CBruce_duplicate_s0 *this, short *pTrick, int Button, int EventTime) {
	{
		{
			// register: 3
			register int Head;
		}
	}
}


// address: 0x800125B8
// line start: 2300
// line end:   2336
void UpdateQueue__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x800126BC
// line start: 2342
// line end:   2359
int ActionButtonHeld__6CBruce(struct CBruce_duplicate_s0 *this) {
	// register: 5
	register int Event;
}


// address: 0x80012768
// line start: 2366
// line end:   2388
int GetPreviousPressedEvent__6CBruceiiii(struct CBruce_duplicate_s0 *this, int Event, int Skip, int Time, int Top) {
}


// address: 0x800127FC
// line start: 2401
// line end:   2562
void MaybeTriggerTrick__6CBruce(struct CBruce_duplicate_s0 *this) {
	// register: 22
	register short *pKeys;
	{
		{
			{
				// register: 23
				register short NumButtons;
				// address: 0xFFFFFFC0
				auto short *pTrick;
				// register: 8
				register short Time;
				// register: 5
				register int Special;
				// address: 0xFFFFFFC4
				auto short *pKey;
				// address: 0xFFFFFFC8
				auto short ActionButton;
				// register: 30
				register short Button1;
				// register: 20
				register int LastEvent;
				// register: 19
				register unsigned int ActionButtonEventTime;
				{
					{
						// register: 16
						register int Event2;
						// register: 5
						register int Direction;
						// register: 17
						register int Event1;
						{
							// register: 16
							register int Event1;
							// register: 6
							register int Event2;
							// address: 0xFFFFFF98
							// size: 0x28
							auto int OtherButton[10];
							// register: 18
							register int OtherButtonIndex;
							{
								{
									// register: 16
									register int ButtonsLeft;
									// register: 5
									register int EventX;
									{
										{
											{
												{
													// register: 17
													register int i;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80012CE0
// line start: 2570
// line end:   2599
short GetScriptFrame__6CBrucei(struct CBruce_duplicate_s0 *this, int Frame) {
	// register: 5
	register int NewFrame;
}


// address: 0x80012D78
// line start: 2607
// line end:   3529
void UpdateScript__6CBruce(struct CBruce_duplicate_s0 *this) {
	// register: 20
	register int Done;
	{
		{
			{
				{
					// register: 4
					register char *pSkip;
					{
						// register: 4
						register int temp;
						{
							// register: 3
							register int Frames;
							{
								{
									{
										// register: 16
										register int Offset;
										{
											// register: 4
											register int Offset;
											{
												{
													// register: 4
													register int Offset;
													{
														// register: 4
														register int Offset;
														{
															// register: 4
															register int fps;
															{
																// register: 19
																// size: 0x190
																register struct CSuper *this;
																{
																	{
																		// address: 0xFFFFFFA8
																		// size: 0x8
																		auto struct SVECTOR RotAngle;
																		// address: 0xFFFFFFB0
																		// size: 0x20
																		auto struct MATRIX RotMatrix;
																		{
																			// register: 4
																			register int Offset;
																			{
																				// register: 4
																				register int Offset;
																				{
																					// register: 4
																					register int Offset;
																					{
																						// register: 4
																						register int Offset;
																						{
																							// register: 4
																							register int Offset;
																							{
																								// register: 6
																								register int Offset;
																								// register: 5
																								register int Flipped;
																								{
																									{
																										// register: 4
																										register int Offset;
																										{
																											{
																												// register: 4
																												register int Offset;
																												{
																													// register: 4
																													register int sfx;
																													{
																														// register: 4
																														register int sfx;
																														// register: 5
																														register int vol;
																														{
																															// register: 4
																															register int sfx;
																															// register: 5
																															register int vol;
																															// register: 6
																															register int pitch;
																															{
																																// register: 16
																																register int narg;
																																// register: 4
																																register int Offset;
																																{
																																	// register: 4
																																	register int Offset;
																																	{
																																		// register: 4
																																		register int Offset;
																																		{
																																			// address: 0xFFFFFFE0
																																			auto int side;
																																			// address: 0xFFFFFFA8
																																			// size: 0xC
																																			auto struct CVector sidevec;
																																			{
																																				// register: 4
																																				register int Offset;
																																				{
																																					// register: 16
																																					register int Value;
																																					// register: 17
																																					register int Offset;
																																					// register: 2
																																					register int Spd;
																																					{
																																						// register: 3
																																						register int Offset;
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80013B28
// line start: 3541
// line end:   3654
short *Trick_Skip__FPs(short *pTrick) {
	{
		{
			{
				// register: 4
				register char *pSkip;
				{
					// register: 2
					register int narg;
				}
			}
		}
	}
}


// address: 0x80013C04
// line start: 3674
// line end:   3686
int EnsureGTricksLoaded__Fv() {
}


// address: 0x80013C88
// line start: 3691
// line end:   3696
void UnloadGTricks__Fv() {
}


// address: 0x80013CD0
// line start: 3703
// line end:   3709
void ExtraAnims_Reset__Fv() {
}


// address: 0x80013D2C
// line start: 3714
// line end:   3719
void ExtraAnims_Add__Fs(short Anim) {
}


// address: 0x80013D54
// line start: 3724
// line end:   3734
void ExtraAnims_AddTrick__FPs(short *pTrick) {
}


// address: 0x80013DD4
// line start: 3741
// line end:   3748
void ExtraAnims_AddTrickTable__FPs(short *pKeys) {
	{
	}
}


// address: 0x80013E30
// line start: 3760
// line end:   3776
void ExtraAnims_AddSkatersAnims__Fv() {
	// register: 16
	register int Loaded;
}


// address: 0x80013EE4
// line start: 3783
// line end:   3795
void HandleTricksNew__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x80013F30
// line start: 3803
// line end:   3814
int InterpolateFrame__Fii(int Current, int Dest) {
	// register: 3
	register int Diff;
	// register: 5
	register int Sign;
}


// address: 0x80013F94
// line start: 3819
// line end:   3995
void CalcAnimLeanFrame__6CBruce(struct CBruce_duplicate_s0 *this) {
	// register: 17
	register int MaxLeanAngle;
	{
		{
			{
				{
					// register: 5
					register int Frame;
					{
						{
							{
								{
									// register: 5
									register int Frame;
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x800144F8
// line start: 4012
// line end:   4319
void HandleSpin__6CBruce(struct CBruce_duplicate_s0 *this) {
	// register: 20
	register int DeltaAngle;
	// register: 16
	register int MaxLeanAngle;
	// address: 0xFFFFFF70
	// size: 0x20
	auto struct MATRIX SurfaceRotMatrix;
	// address: 0xFFFFFF90
	// size: 0x8
	auto struct SVECTOR RotAngle;
	// register: 19
	register int LeftPressed;
	// register: 17
	register int RightPressed;
	{
		{
			// address: 0xFFFFFF98
			// size: 0xC
			auto int ActualRot[3];
			// address: 0xFFFFFFA8
			// size: 0x10
			auto struct VECTOR zero;
			// address: 0xFFFFFFB8
			// size: 0x10
			auto struct VECTOR v;
			// address: 0xFFFFFFC8
			// size: 0x10
			auto struct VECTOR v2;
			// address: 0xFFFFFFD8
			// size: 0x10
			auto struct VECTOR v3;
			{
				// register: 12
				register int i;
				{
					{
						{
							// register: 5
							register int Speed;
							// register: 3
							register int Sign;
							{
								{
									{
										{
											// register: 2
											register int Speed;
											{
												{
													// register: 6
													register int TargetAngle;
													{
														{
															// register: 2
															register int Diff;
															{
																{
																	// register: 2
																	register int Diff;
																	{
																		{
																			{
																				{
																					{
																						// register: 3
																						register int LeanBack;
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80014E7C
// line start: 4334
// line end:   4354
void AlignHeadingOnRail__6CBruce(struct CBruce_duplicate_s0 *this) {
	{
		// register: 18
		// size: 0xC
		register struct CVector *this;
		{
		}
	}
}


// address: 0x80014F58
// line start: 4363
// line end:   4380
void CreateRailSparks__6CBruce(struct CBruce_duplicate_s0 *this) {
	{
		{
			// address: 0xFFFFFFD0
			// size: 0x6
			auto struct CSVector cone;
			// address: 0xFFFFFFD8
			// size: 0xC
			auto struct CVector SparkPos;
			{
				// register: 5
				// size: 0x6
				register struct CSVector *this;
				{
					{
						{
							{
								// register: 16
								register int i;
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80015034
// line start: 4386
// line end:   4394
void TweakRailScore__6CBruce(struct CBruce_duplicate_s0 *this) {
	// address: 0xFFFFFFE8
	// size: 0xC
	auto struct CVector RailMove;
}


// address: 0x8001509C
// line start: 4399
// line end:   4428
void HandleGrindOffSound__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x8001513C
// line start: 4433
// line end:   4457
void LeaveRail__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x800151D0
// line start: 4466
// line end:   4818
void DoOnRailPhysics__6CBruce(struct CBruce_duplicate_s0 *this) {
	// address: 0xFFFFFE60
	// size: 0xC
	auto struct CVector SegStart;
	// address: 0xFFFFFE70
	// size: 0xC
	auto struct CVector SegEnd;
	// address: 0xFFFFFE80
	// size: 0xC
	auto struct CVector SegDir;
	// register: 17
	register int Speed;
	// register: 17
	register int LastSpeed;
	// register: 4
	register int RemainingSpeed;
	// register: 21
	register int NextSegment;
	// register: 19
	register int Length;
	// register: 18
	register int t;
	// register: 6
	register int MajorAxis;
	// address: 0xFFFFFFC4
	auto int FirstTimeThroughLoop;
	// address: 0xFFFFFE90
	// size: 0xC
	auto struct CVector Gravity;
	// address: 0xFFFFFEA0
	// size: 0x20
	auto struct MATRIX Rail_RotMatrix;
	// address: 0xFFFFFEC0
	// size: 0x8
	auto struct SVECTOR RotAngle;
	{
		{
			{
				{
					{
						{
							{
								// address: 0xFFFFFFC8
								// size: 0xC
								auto struct CVector *this;
								{
									{
										{
											{
												{
													{
														// register: 16
														register int AccMagnitude;
														{
															{
																// address: 0xFFFFFEA0
																// size: 0xC
																auto struct CVector Old;
																{
																	{
																		{
																			// register: 16
																			register int PreviousSegment;
																			{
																				{
																					// address: 0xFFFFFEA0
																					// size: 0xC
																					auto struct CVector SegStart2;
																					// address: 0xFFFFFEB0
																					// size: 0xC
																					auto struct CVector SegEnd2;
																					// address: 0xFFFFFEC0
																					// size: 0xC
																					auto struct CVector SegDir2;
																					{
																						{
																							{
																								{
																									{
																										{
																											{
																												{
																													{
																														// register: 16
																														register int NextSegment2;
																														{
																															{
																																// address: 0xFFFFFEA0
																																// size: 0xC
																																auto struct CVector SegStart2;
																																// address: 0xFFFFFEB0
																																// size: 0xC
																																auto struct CVector SegEnd2;
																																// address: 0xFFFFFEC0
																																// size: 0xC
																																auto struct CVector SegDir2;
																																{
																																	{
																																		{
																																			{
																																				{
																																					{
																																						{
																																							{
																																								// address: 0xFFFFFF10
																																								// size: 0xA4
																																								auto struct SLineInfo line_info;
																																								// address: 0xFFFFFEC8
																																								// size: 0xC
																																								auto struct CVector vMovement;
																																								{
																																									// register: 8
																																									register int _x;
																																									// register: 3
																																									register int _y;
																																									// register: 9
																																									register int _z;
																																									{
																																										// register: 10
																																										register int _x;
																																										// register: 2
																																										register int _y;
																																										// register: 11
																																										register int _z;
																																										{
																																											{
																																												// register: 4
																																												register int Speed;
																																												// register: 17
																																												register int OldBul;
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80015F04
// line start: 4828
// line end:   4859
void SkateOffGround__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x80015FA8
// line start: 4869
// line end:   4950
int CheckSide__6CBruceiii(struct CBruce_duplicate_s0 *this, int Side, int SideCol, int BounceOff) {
	// address: 0xFFFFFF10
	// size: 0xA4
	auto struct SLineInfo line_info;
	{
		{
			// address: 0xFFFFFFB8
			// size: 0xC
			auto struct CVector WallFloorNormal;
			{
				{
					{
						// register: 2
						register int _x;
						// register: 3
						register int _y;
						// register: 6
						register int _z;
						{
							{
								// address: 0xFFFFFFC8
								// size: 0xC
								auto struct CVector OldVel;
								// register: 17
								register int TurnAway;
								{
									{
										{
											{
												// address: 0xFFFFFFD8
												// size: 0xC
												auto struct CVector WallFloorNormal;
												{
													{
														{
															// register: 2
															register int _x;
															// register: 3
															register int _y;
															// register: 6
															register int _z;
															{
																{
																	{
																		// register: 3
																		register int _x;
																		// register: 4
																		register int _y;
																		// register: 5
																		register int _z;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x800162CC
// line start: 4958
// line end:   5032
void DoTerrainEffects__6CBruce(struct CBruce_duplicate_s0 *this) {
	// register: 17
	register int Speed;
	{
		{
			{
				{
					// address: 0xFFFFFFE0
					// size: 0x6
					auto struct CSVector cone;
					{
						// register: 5
						// size: 0x6
						register struct CSVector *this;
						{
							{
								{
									{
										// register: 16
										register int i;
										{
											{
												{
													// register: 2
													// size: 0x5C
													register struct CSpark *pSpark;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x800164FC
// line start: 5049
// line end:   5131
void DoManualPhysics__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x800169F4
// line start: 5143
// line end:   5217
void MoveOriginTo__6CBruceiii(struct CBruce_duplicate_s0 *this, int x, int y, int z) {
	// register: 19
	register int OldBul;
	// address: 0xFFFFFF40
	// size: 0xA4
	auto struct SLineInfo line_info;
}


// address: 0x80016BE4
// line start: 5221
// line end:   5230
void HandleTruckSqueakSound__6CBruce(struct CBruce_duplicate_s0 *this) {
	// register: 4
	register int stopped;
}


// address: 0x80016C68
// line start: 5246
// line end:   5994
void DoOnGroundPhysics__6CBruce(struct CBruce_duplicate_s0 *this) {
	// register: 18
	register int NewMag;
	// address: 0xFFFFFE78
	// size: 0xC
	auto struct CVector vMovement;
	// address: 0xFFFFFE88
	// size: 0xC
	auto struct CVector InplaneGravity;
	// register: 17
	register int Speed;
	// register: 16
	register int TurnAngle;
	// register: 16
	register int dot;
	// address: 0xFFFFFE98
	// size: 0xA4
	auto struct SLineInfo line_info;
	// address: 0xFFFFFFCC
	auto int OnInvisible;
	// address: 0xFFFFFFD0
	auto int AutoKickEnabled;
	// address: 0xFFFFFF40
	// size: 0xC
	auto struct CVector Gravity;
	// address: 0xFFFFFF50
	// size: 0xC
	auto struct CVector Old;
	{
		{
			{
				{
					{
						{
							{
								{
									{
										// register: 2
										register int _x;
										// register: 3
										register int _y;
										// register: 7
										register int _z;
										{
											// register: 8
											register int _x;
											// register: 9
											register int _y;
											// register: 10
											register int _z;
											{
												{
													{
														{
															// register: 16
															register int TurnAway;
															{
																{
																	// address: 0xFFFFFF60
																	// size: 0xC
																	auto struct CVector WallFloorNormal;
																	{
																		{
																			{
																				// register: 2
																				register int _x;
																				// register: 3
																				register int _y;
																				// register: 6
																				register int _z;
																				{
																					{
																						{
																							// address: 0xFFFFFF60
																							// size: 0xC
																							auto struct CVector WallFloorNormal;
																							{
																								{
																									{
																										// register: 2
																										register int _x;
																										// register: 3
																										register int _y;
																										// register: 6
																										register int _z;
																										{
																											{
																												{
																													{
																														{
																															// register: 3
																															register int _x;
																															// register: 2
																															register int _y;
																															// register: 5
																															register int _z;
																															{
																																{
																																	{
																																		// register: 7
																																		register int _x;
																																		// register: 8
																																		register int _y;
																																		// register: 9
																																		register int _z;
																																		{
																																			{
																																				// register: 2
																																				register int _x;
																																				// register: 3
																																				register int _y;
																																				// register: 4
																																				register int _z;
																																				{
																																					// address: 0xFFFFFF70
																																					// size: 0xC
																																					auto struct CVector OldVel;
																																					// register: 16
																																					register int TurnAway;
																																					{
																																						{
																																							// address: 0xFFFFFF80
																																							// size: 0xC
																																							auto struct CVector WallFloorNormal;
																																							{
																																								{
																																									{
																																										// register: 2
																																										register int _x;
																																										// register: 3
																																										register int _y;
																																										// register: 6
																																										register int _z;
																																										{
																																											{
																																												{
																																													{
																																														{
																																															{
																																																// register: 2
																																																register int _x;
																																																// register: 3
																																																register int _y;
																																																// register: 4
																																																register int _z;
																																																{
																																																	{
																																																		{
																																																			{
																																																				// register: 19
																																																				register int d;
																																																				// register: 16
																																																				register int CheckDist;
																																																				{
																																																					{
																																																						// address: 0xFFFFFF60
																																																						// size: 0xC
																																																						auto struct CVector TmpCV;
																																																						// address: 0xFFFFFF70
																																																						// size: 0xC
																																																						auto struct CVector LastNormal;
																																																						{
																																																							{
																																																								{
																																																									// register: 2
																																																									register int _x;
																																																									// register: 3
																																																									register int _y;
																																																									// register: 6
																																																									register int _z;
																																																									{
																																																										{
																																																											{
																																																												// register: 7
																																																												register int _x;
																																																												// register: 8
																																																												register int _y;
																																																												// register: 9
																																																												register int _z;
																																																												{
																																																													{
																																																														// address: 0xFFFFFF60
																																																														// size: 0xC
																																																														auto struct CVector Orig;
																																																														// address: 0xFFFFFF70
																																																														// size: 0xC
																																																														auto struct CVector Move;
																																																														{
																																																															{
																																																																{
																																																																	{
																																																																		{
																																																																			{
																																																																				// address: 0xFFFFFF80
																																																																				// size: 0x8
																																																																				auto struct SVECTOR Push;
																																																																				{
																																																																					// address: 0xFFFFFF80
																																																																					// size: 0xC
																																																																					auto struct CVector NewNormal;
																																																																					// address: 0xFFFFFF90
																																																																					// size: 0xC
																																																																					auto struct CVector VelNormal;
																																																																					// register: 4
																																																																					register int Angle;
																																																																					{
																																																																						{
																																																																							{
																																																																								// register: 2
																																																																								register int _x;
																																																																								// register: 3
																																																																								register int _y;
																																																																								// register: 5
																																																																								register int _z;
																																																																								{
																																																																									{
																																																																										{
																																																																											{
																																																																												{
																																																																													// register: 16
																																																																													register int UpDot;
																																																																													{
																																																																														{
																																																																															// address: 0xFFFFFF80
																																																																															// size: 0xC
																																																																															auto struct CVector TmpCV;
																																																																															// address: 0xFFFFFF90
																																																																															// size: 0xC
																																																																															auto struct CVector LastNormal;
																																																																															{
																																																																																{
																																																																																	{
																																																																																		// register: 2
																																																																																		register int _x;
																																																																																		// register: 3
																																																																																		register int _y;
																																																																																		// register: 6
																																																																																		register int _z;
																																																																																		{
																																																																																			{
																																																																																				{
																																																																																					// register: 7
																																																																																					register int _x;
																																																																																					// register: 8
																																																																																					register int _y;
																																																																																					// register: 9
																																																																																					register int _z;
																																																																																					{
																																																																																						{
																																																																																							{
																																																																																								{
																																																																																									{
																																																																																										// register: 2
																																																																																										register int _x;
																																																																																										// register: 3
																																																																																										register int _y;
																																																																																										// register: 4
																																																																																										register int _z;
																																																																																										{
																																																																																											{
																																																																																												{
																																																																																													{
																																																																																														{
																																																																																															{
																																																																																																{
																																																																																																	{
																																																																																																		// address: 0xFFFFFF60
																																																																																																		// size: 0xC
																																																																																																		auto struct CVector SideVelocity;
																																																																																																		// address: 0xFFFFFF70
																																																																																																		// size: 0xC
																																																																																																		auto struct CVector ForwardsVelocity;
																																																																																																		{
																																																																																																			{
																																																																																																				{
																																																																																																					{
																																																																																																					}
																																																																																																				}
																																																																																																			}
																																																																																																		}
																																																																																																	}
																																																																																																}
																																																																																															}
																																																																																														}
																																																																																													}
																																																																																												}
																																																																																											}
																																																																																										}
																																																																																									}
																																																																																								}
																																																																																							}
																																																																																						}
																																																																																					}
																																																																																				}
																																																																																			}
																																																																																		}
																																																																																	}
																																																																																}
																																																																															}
																																																																														}
																																																																													}
																																																																												}
																																																																											}
																																																																										}
																																																																									}
																																																																								}
																																																																							}
																																																																						}
																																																																					}
																																																																				}
																																																																			}
																																																																		}
																																																																	}
																																																																}
																																																															}
																																																														}
																																																													}
																																																												}
																																																											}
																																																										}
																																																									}
																																																								}
																																																							}
																																																						}
																																																					}
																																																				}
																																																			}
																																																		}
																																																	}
																																																}
																																															}
																																														}
																																													}
																																												}
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8001832C
// line start: 6044
// line end:   6052
int arccos__Fi(int a) {
}


// address: 0x80018334
// line start: 6056
// line end:   6088
void HandleLeaningBail__6CBruceG7SVECTOR(struct CBruce_duplicate_s0 *this, struct SVECTOR Normal) {
	// address: 0xFFFFFFA0
	// size: 0xC
	auto struct CVector TmpCV;
	{
		{
			{
				{
					{
						// register: 2
						register int _x;
						// register: 3
						register int _y;
						// register: 6
						register int _z;
						{
							{
								// address: 0xFFFFFFB0
								// size: 0xC
								auto struct CVector Temp;
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80018484
// line start: 6103
// line end:   6141
void HitAirPoly__6CBruceR9SLineInfo(struct CBruce_duplicate_s0 *this, struct SLineInfo *line_info) {
	// register: 16
	register int NewMag;
	{
		{
			{
				{
					// address: 0xFFFFFFE8
					// size: 0x8
					auto struct SVECTOR Push;
				}
			}
		}
	}
}


// address: 0x80018610
// line start: 6153
// line end:   6291
void MaybeManual__6CBruceii(struct CBruce_duplicate_s0 *this, int Time, int FromGround) {
	{
		{
			// register: 2
			register int Direction;
			// register: 16
			register int OtherDirection;
			// register: 18
			register int LastEvent;
			// register: 19
			register int FoundFirst;
			// register: 20
			register int FirstEvent;
			// register: 5
			register int Event;
		}
	}
}


// address: 0x80018BD8
// line start: 6304
// line end:   6928
void DoInAirPhysics__6CBruce(struct CBruce_duplicate_s0 *this) {
	// address: 0xFFFFFE70
	// size: 0xC
	auto struct CVector vMovement;
	// register: 6
	register int Speed;
	// register: 17
	register int TurnAngle;
	// address: 0xFFFFFE80
	// size: 0x20
	auto struct MATRIX SurfaceRotMatrix;
	// address: 0xFFFFFEA0
	// size: 0x8
	auto struct SVECTOR RotAngle;
	// address: 0xFFFFFEA8
	// size: 0xA4
	auto struct SLineInfo line_info;
	// address: 0xFFFFFF50
	// size: 0xC
	auto struct CVector Old;
	{
		{
			{
				{
					// address: 0xFFFFFF60
					// size: 0x10
					auto struct VECTOR zero;
					// address: 0xFFFFFF70
					// size: 0x10
					auto struct VECTOR v;
					// address: 0xFFFFFF80
					// size: 0x10
					auto struct VECTOR v2;
					// address: 0xFFFFFF90
					// size: 0x10
					auto struct VECTOR v3;
					{
						// register: 2
						register int _x;
						// register: 3
						register int _y;
						// register: 7
						register int _z;
						{
							// register: 8
							register int _x;
							// register: 9
							register int _y;
							// register: 10
							register int _z;
							{
								{
									{
										{
											// address: 0xFFFFFF60
											// size: 0xC
											auto struct CVector UnitVel;
											// address: 0xFFFFFF70
											// size: 0xC
											auto struct CVector FaceNormal;
											// register: 2
											register int VelNormal;
											{
												{
													{
														{
															{
																{
																	// address: 0xFFFFFF80
																	// size: 0xC
																	auto struct CVector WallRight;
																	{
																		// register: 2
																		register int _x;
																		// register: 3
																		register int _y;
																		// register: 4
																		register int _z;
																		{
																			// register: 7
																			register int _x;
																			// register: 8
																			register int _y;
																			// register: 9
																			register int _z;
																			{
																				{
																					{
																						{
																							{
																								{
																									{
																										// register: 2
																										register int _y;
																										{
																											{
																												{
																													// register: 2
																													register int _x;
																													// register: 3
																													register int _y;
																													// register: 5
																													register int _z;
																													{
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80019A34
// line start: 6937
// line end:   6955
void DoFootPlantPhysics__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x80019F4C
// line start: 6962
// line end:   7041
void DoHandPlantPhysics__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x8001A1C8
// line start: 7050
// line end:   7404
void DoWallRidePhysics__6CBruce(struct CBruce_duplicate_s0 *this) {
	// address: 0xFFFFFE90
	// size: 0xC
	auto struct CVector vMovement;
	// address: 0xFFFFFEA0
	// size: 0xC
	auto struct CVector InplaneGravity;
	// register: 6
	register int Speed;
	// register: 16
	register int TurnAngle;
	// address: 0xFFFFFEB0
	// size: 0xA4
	auto struct SLineInfo line_info;
	// register: 30
	register int OnInvisible;
	// address: 0xFFFFFF58
	// size: 0xC
	auto struct CVector Gravity;
	{
		{
			{
				{
					{
						{
							{
								{
									{
										// register: 2
										register int _x;
										// register: 3
										register int _y;
										// register: 7
										register int _z;
										{
											// register: 8
											register int _x;
											// register: 9
											register int _y;
											// register: 10
											register int _z;
											{
												{
													{
														{
															{
																{
																	{
																		// register: 2
																		register int _x;
																		// register: 3
																		register int _y;
																		// register: 4
																		register int _z;
																		{
																			{
																				{
																					// register: 2
																					register int _x;
																					// register: 3
																					register int _y;
																					// register: 4
																					register int _z;
																					{
																						// register: 7
																						register int _x;
																						// register: 8
																						register int _y;
																						// register: 9
																						register int _z;
																						{
																							{
																								{
																									// register: 3
																									register int d;
																									// register: 2
																									register int CheckDist;
																									{
																										{
																											{
																												{
																													{
																														// register: 2
																														register int _x;
																														// register: 3
																														register int _y;
																														// register: 4
																														register int _z;
																														{
																															{
																																{
																																	// register: 2
																																	register int _x;
																																	// register: 3
																																	register int _y;
																																	// register: 4
																																	register int _z;
																																	{
																																		// register: 7
																																		register int _x;
																																		// register: 8
																																		register int _y;
																																		// register: 9
																																		register int _z;
																																		{
																																			{
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8001AD9C
// line start: 7417
// line end:   7948
void HandleJump__6CBruce(struct CBruce_duplicate_s0 *this) {
	// register: 16
	register int Speed;
	{
		{
			{
				{
					{
						{
							// register: 5
							register int Boost;
							{
								{
									{
										{
											{
												{
													// register: 30
													register int LastPhysics;
													// register: 23
													register int playedGrindOffSound;
													// register: 4
													register int JumpBoost;
													{
														{
															// register: 5
															register int Rotate;
															{
																{
																	// address: 0xFFFFFFB0
																	// size: 0xC
																	auto struct CVector SurfaceNormal;
																	{
																		{
																			{
																				// register: 3
																				register int _x;
																				// register: 7
																				register int _y;
																				// register: 8
																				register int _z;
																				{
																					{
																						// register: 19
																						register int Time;
																						// register: 16
																						register int LastEvent;
																						// register: 18
																						register int FirstEvent;
																						// register: 21
																						register int SecondEvent;
																						// register: 5
																						register int Event;
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8001C368
// line start: 7953
// line end:   8139
void HandleKick__6CBruce(struct CBruce_duplicate_s0 *this) {
	// register: 18
	register int Speed;
	// register: 20
	register int AutoKickEnabled;
	// address: 0xFFFFFFC8
	// size: 0xC
	auto struct CVector mVel2;
	// register: 21
	register int x;
	{
		{
			{
				{
					{
						// register: 17
						// size: 0x190
						register struct CSuper *this;
						{
							{
								{
									{
										{
											{
												{
													{
														{
															{
																{
																	{
																		// register: 17
																		// size: 0x190
																		register struct CSuper *this;
																		{
																			{
																				{
																					// register: 16
																					register int KickVal;
																					{
																						{
																							// register: 3
																							register int s;
																							{
																								{
																									{
																										{
																											{
																												{
																													{
																														{
																															{
																																{
																																	{
																																		{
																																			// register: 17
																																			// size: 0x190
																																			register struct CSuper *this;
																																			{
																																				{
																																					{
																																						// register: 5
																																						register int KickVal;
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8001CA84
// line start: 8148
// line end:   8224
void RotateHeadingAndVelocity__6CBruceiii(struct CBruce_duplicate_s0 *this, int TurnAngle, int RotateVelocity, int SlipAngle) {
	// address: 0xFFFFFFD8
	auto int OldMag;
	// address: 0xFFFFFFDC
	auto int NewMag;
	// address: 0xFFFFFF30
	// size: 0x20
	auto struct MATRIX SurfaceRotMatrix;
	// address: 0xFFFFFF50
	// size: 0x8
	auto struct SVECTOR RotAngle;
	{
		{
			// address: 0xFFFFFF58
			// size: 0x20
			auto struct MATRIX m;
			// address: 0xFFFFFF78
			// size: 0x20
			auto struct MATRIX m2;
			// address: 0xFFFFFF98
			// size: 0xC
			auto struct CVector mv;
			// address: 0xFFFFFFA8
			// size: 0xC
			auto struct CVector NewVel1;
			{
				{
					{
						{
						}
					}
				}
			}
		}
	}
}


// address: 0x8001CCCC
// line start: 8232
// line end:   8373
void ReflectHeadingVelocityInPlane__6CBruceG7SVECTORi(struct CBruce_duplicate_s0 *this, struct SVECTOR Normal, int Angle) {
	// address: 0xFFFFFFA0
	// size: 0xC
	auto struct CVector TmpCV;
	// register: 17
	register int dot;
	// address: 0xFFFFFFB0
	// size: 0x20
	auto struct MATRIX SurfaceRotMatrix;
	{
		{
			{
				// register: 2
				register int _x;
				// register: 3
				register int _y;
				// register: 6
				register int _z;
				{
					{
						// register: 18
						register int sin;
						// register: 21
						register int cos;
						// register: 16
						register short *pShort;
						// address: 0xFFFFFFD0
						// size: 0x8
						auto struct SVECTOR RotAngle;
					}
				}
			}
		}
	}
}


// address: 0x8001CF9C
// line start: 8388
// line end:   8486
void AlignToFallLine__6CBrucei(struct CBruce_duplicate_s0 *this, int Amount) {
	// register: 16
	register int Speed;
	// register: 2
	register int dot;
	// register: 2
	register int PolyTilt;
	// register: 8
	register int angle;
	// address: 0xFFFFFF98
	// size: 0xC
	auto struct CVector FallLinePerp;
	// address: 0xFFFFFFA8
	// size: 0xC
	auto struct CVector FallLineUnit;
	// address: 0xFFFFFFB8
	// size: 0x10
	auto struct VECTOR mLPN;
	// address: 0xFFFFFFC8
	// size: 0xC
	auto struct CVector FrontInPlane;
	{
		{
			{
				{
					{
						// register: 2
						register int _x;
						// register: 3
						register int _y;
						// register: 4
						register int _z;
						{
							{
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8001D530
// line start: 8491
// line end:   8558
void UprightSideways__6CBruce(struct CBruce_duplicate_s0 *this) {
	// address: 0xFFFFFFA8
	// size: 0xC
	auto struct CVector TmpCV;
	// register: 2
	register int dot;
	// address: 0xFFFFFFB8
	// size: 0x20
	auto struct MATRIX SurfaceRotMatrix;
	// address: 0xFFFFFFD8
	// size: 0x8
	auto struct SVECTOR RotAngle;
	// address: 0xFFFFFFE0
	// size: 0x10
	auto struct VECTOR v;
	{
		{
			{
				// register: 2
				register int _x;
				// register: 3
				register int _y;
				// register: 6
				register int _z;
			}
		}
	}
}


// address: 0x8001D634
// line start: 8565
// line end:   8570
void FRUVectorsFromRotMatrix__6CBruce(struct CBruce_duplicate_s0 *this) {
	{
		// register: 3
		// size: 0xC
		register struct CVector *this;
		{
			{
				// register: 3
				// size: 0xC
				register struct CVector *this;
				{
					{
						// register: 4
						// size: 0xC
						register struct CVector *this;
						{
						}
					}
				}
			}
		}
	}
}


// address: 0x8001D68C
// line start: 8576
// line end:   8587
void RotMatrixFromFRUVectors__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x8001D6D8
// line start: 8595
// line end:   8606
void SetAnglesFromHeading__6CBruce(struct CBruce_duplicate_s0 *this) {
	// address: 0xFFFFFFF0
	// size: 0x8
	auto struct SVECTOR temp;
	{
		// register: 4
		register int _x;
		// register: 3
		register int _y;
		// register: 5
		register int _z;
	}
}


// address: 0x8001D764
// line start: 8615
// line end:   8900
void HandleContinuousSounds__6CBruce(struct CBruce_duplicate_s0 *this) {
	{
		{
			{
				{
					// register: 17
					register int Spd;
					// register: 3
					register unsigned short NewPitch;
					{
						{
							// register: 9
							register int Spd;
							// register: 18
							register int NewPitch;
							// register: 17
							register int NewVol;
						}
					}
				}
			}
		}
	}
}


// address: 0x8001E074
// line start: 8928
// line end:   8992
void OrientToNormal__6CBruce(struct CBruce_duplicate_s0 *this) {
	// address: 0xFFFFFFC0
	// size: 0x10
	auto struct VECTOR z1;
	// address: 0xFFFFFFD0
	// size: 0xC
	auto struct CVector normal;
	// address: 0xFFFFFFE0
	// size: 0xC
	auto struct CVector x1;
	{
		{
			{
				{
					{
						{
							{
								// register: 2
								register int _x;
								// register: 3
								register int _y;
								// register: 4
								register int _z;
								{
									// register: 2
									// size: 0xC
									register struct CVector *this;
									{
										{
											// register: 3
											register int _x;
											// register: 4
											register int _y;
											// register: 5
											register int _z;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8001E2A4
// line start: 8999
// line end:   9071
void HandlePlayerCollisions__6CBruce(struct CBruce_duplicate_s0 *this) {
	{
		{
			// address: 0xFFFFFFC8
			// size: 0xC
			auto struct CVector BetweenPlayers;
			{
				{
					// register: 17
					register int Direction1;
					// register: 2
					register int Direction2;
				}
			}
		}
	}
}


// address: 0x8001E3DC
// line start: 9095
// line end:   9139
void LimitFinalSpeed__6CBruce(struct CBruce_duplicate_s0 *this) {
	// register: 6
	register int Spd;
	// register: 2
	register int AutoKickEnabled;
}


// address: 0x8001E9B8
// line start: 9150
// line end:   9177
void CheckForTriggers__6CBruce(struct CBruce_duplicate_s0 *this) {
	// size: 0xC
	static struct CVector last_valid;
	// address: 0xFFFFFEF8
	// size: 0xC
	auto struct CVector check;
	{
		{
			{
				{
					// address: 0xFFFFFF08
					// size: 0xA4
					auto struct SLineInfo LInfo;
					// address: 0xFFFFFFB0
					// size: 0xC
					auto struct CVector unit;
					// address: 0xFFFFFFC0
					// size: 0xC
					auto struct CVector old;
					{
						{
							{
								// register: 2
								register int _x;
								// register: 3
								register int _y;
								// register: 5
								register int _z;
								{
									// register: 6
									register int _x;
									// register: 7
									register int _y;
									// register: 8
									register int _z;
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8001EB00
// line start: 9185
// line end:   9432
void HandleBailStates__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x8001EBF0
// line start: 9436
// line end:   9458
void CheckSideCollisions__6CBruce(struct CBruce_duplicate_s0 *this) {
	// address: 0xFFFFFFE0
	// size: 0xC
	auto struct CVector Debounce;
	// register: 16
	register int SideCol;
}


// address: 0x8001ECAC
// line start: 9500
// line end:   9618
void HandlePhysicsStates__6CBruce(struct CBruce_duplicate_s0 *this) {
	{
		{
			{
				{
					{
						// register: 5
						register int i;
					}
				}
			}
		}
	}
}


// address: 0x8001EF10
// line start: 9634
// line end:   9837
void HandleBraking__6CBruce(struct CBruce_duplicate_s0 *this) {
	// register: 19
	register int DownOnly;
	// register: 18
	register int BrakeVal;
	// register: 20
	register int Speed;
	// register: 4
	register int Angle;
	{
		{
			{
				{
					{
						{
							{
								{
									{
										{
											{
												{
													// register: 2
													register int temp;
													{
														{
															{
																{
																	// register: 2
																	register int temp;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8001F45C
// line start: 9840
// line end:   9858
void HandleFlips__6CBruce(struct CBruce_duplicate_s0 *this) {
	{
		{
			// register: 4
			register int old;
		}
	}
}


// address: 0x8001F4C0
// line start: 9866
// line end:   9889
void HandleTimer__6CBruce(struct CBruce_duplicate_s0 *this) {
	{
		{
			// register: 2
			register int ticks;
			{
				{
					{
						{
						}
					}
				}
			}
		}
	}
}


// address: 0x8001F5A8
// line start: 9899
// line end:   10281
void DoPhysics__6CBruce(struct CBruce_duplicate_s0 *this) {
	{
		{
			{
				// register: 4
				// size: 0xC
				register struct CVector *this;
				{
					{
						{
							// register: 2
							register int NewMag;
							{
								{
									// register: 20
									register int OldBul;
									{
										{
											// address: 0xFFFFFF30
											// size: 0xA4
											auto struct SLineInfo line_info;
											{
												{
													// register: 17
													register int MaxFrame;
													{
														{
															// address: 0xFFFFFF20
															// size: 0xA4
															auto struct SLineInfo line_info;
															{
																{
																	// register: 5
																	register int x;
																	// register: 6
																	register int y;
																	// register: 7
																	register int z;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80020164
// line start: 10291
// line end:   10291
void _GLOBAL__I_DefaultAnimations() {
	{
		{
			{
				{
					{
						{
						}
					}
				}
			}
		}
	}
}


// address: 0x80024410
// line start: 112
// line end:   122
void Card_SetSelectedFile__FPc(char *pPName) {
}


// address: 0x80024444
// line start: 130
// line end:   142
void SetSJISChecksum__FPcT0(char *SJISName, char *FName) {
	// register: 7
	register unsigned short *p;
	// register: 4
	register unsigned short val;
	// register: 3
	register unsigned short val2;
}


// address: 0x800244BC
// line start: 153
// line end:   161
short CalcChecksum__FPUlUl(unsigned long *pDataBuf, unsigned long DataSize) {
	// register: 7
	register short Checksum;
	{
		// register: 6
		register int i;
	}
}


// address: 0x800244F8
// line start: 170
// line end:   197
void Card_SetHeader__FP9SCardHeadiPcT2(struct SCardHead *Head, int NumBlocks, char *pClut, char *pIcon) {
	// register: 8
	register int i;
}


// address: 0x8002461C
// line start: 203
// line end:   222
int SyncToGoodState__Fv() {
	// register: 16
	register int timeout;
}


// address: 0x800246A0
// line start: 228
// line end:   265
int Card_FileExists__F9EFileType(enum EFileType_duplicate_e1 FileType) {
	// register: 2
	register int fd;
	// register: 16
	register char *FName;
	// address: 0xFFFFFDF8
	// size: 0x200
	auto struct SCardHead Headdy;
}


// address: 0x80024738
// line start: 272
// line end:   454
int Card_Write__F9EFileTypei(enum EFileType_duplicate_e1 FileType, int NumBlocks) {
	// register: 16
	register int fd;
	// register: 18
	register int i;
	// register: 22
	register int DataSize;
	// register: 23
	register int DataSize2;
	// address: 0xFFFFFFC8
	auto int HeaderSize;
	// address: 0xFFFFFFCC
	auto int HeaderSize2;
	// address: 0xFFFFFFD0
	auto unsigned long *pDataBuf;
	// address: 0xFFFFFFD4
	auto unsigned long *pDataBuf2;
	// register: 19
	register unsigned long *pHeaderBuf;
	// register: 20
	register unsigned long *pHeaderBuf2;
	// register: 17
	register char *pClut;
	// register: 16
	register char *pIcon;
	// register: 21
	register char *FName;
	{
		{
			{
				{
					{
						{
						}
					}
				}
			}
		}
	}
}


// address: 0x80024A30
// line start: 460
// line end:   551
int Card_WriteReplayToDisk__F9EFileTypePc(enum EFileType_duplicate_e1 FileType, char *save_name) {
	// register: 19
	register int DataSize;
	// register: 22
	register int DataSize2;
	// register: 30
	register int HeaderSize;
	// register: 21
	register unsigned long *pDataBuf;
	// register: 23
	register unsigned long *pDataBuf2;
	// register: 18
	register unsigned long *pHeaderBuf;
	// register: 16
	register unsigned long *pHeaderBuf2;
	// register: 17
	register unsigned short fileid;
}


// address: 0x80024BBC
// line start: 558
// line end:   716
int Card_Load__F9EFileTypePUlT1(enum EFileType_duplicate_e1 FileType, unsigned long *pBuf, unsigned long *pBuf2) {
	// register: 17
	register int fd;
	// register: 16
	register char *FName;
	// register: 18
	register int ReadSize;
	{
		{
			{
				{
					{
						// register: 16
						register int Chk1;
						// register: 3
						register int Chk2;
						{
							{
								{
									// register: 16
									register int Chk1;
									// register: 3
									register int Chk2;
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80024D6C
// line start: 757
// line end:   821
int Card_LoadReplayFromCD__FPUlT0Pc(unsigned long *pBuf, unsigned long *pBuf2, char *file_name) {
	// register: 16
	register unsigned long *pData;
	// register: 16
	register int Chk1;
}


// address: 0x80024E54
// line start: 828
// line end:   865
void Card_Init__Fl(long val) {
}


// address: 0x80024FE0
// line start: 897
// line end:   912
int _card_event__Fv() {
	// register: 16
	register int ret;
}


// address: 0x80025084
// line start: 932
// line end:   939
void _clear_event__Fv() {
}


// address: 0x800250CC
// line start: 945
// line end:   953
int _card_event_x__Fv() {
}


// address: 0x8002513C
// line start: 960
// line end:   968
void _clear_event_x__Fv() {
}


// address: 0x80025184
// line start: 989
// line end:   1024
int Card_ReadFileHeader__FPcP9SCardHead(char *FName, struct SCardHead *pHeader) {
	// register: 16
	register int fd;
	// address: 0xFFFFFFC8
	// size: 0x1E
	auto char FileName[30];
	{
		// register: 17
		register int i;
		{
			{
				{
					// register: 16
					register int len;
				}
			}
		}
	}
}


// address: 0x8002525C
// line start: 1030
// line end:   1086
int Card_GetDirAndFreeBlocks__Fii(int cnct, int slot) {
	// register: 4
	register long i;
	// register: 18
	register long size;
	// address: 0xFFFFFFC8
	// size: 0x20
	auto char key[32];
	// register: 16
	// size: 0x28
	register struct DIRENTRY *d;
}


// address: 0x80025370
// line start: 1100
// line end:   1199
int Card_CheckStatus__Fii(int cnct, int slot) {
	// register: 16
	register long chan;
	// register: 3
	register int ret;
}


// address: 0x8002556C
// line start: 1209
// line end:   1236
int Card_FormatCard__Fii(int cnct, int slot) {
	// register: 16
	register int fret;
	// register: 4
	register int ret;
	// address: 0xFFFFFFF0
	// size: 0x6
	auto char fs[6];
}


// address: 0x800255EC
// line start: 1342
// line end:   1390
void Card_GetNextTimeStamp__Fv() {
	// address: 0xFFFFF670
	// size: 0x974
	auto struct SCareer TmpCareer;
	{
		// register: 19
		register int i;
		{
			{
				{
					// register: 16
					register unsigned long *pTmp;
				}
			}
		}
	}
}


// address: 0x8002131C
// line start: 178
// line end:   181
void RGBRed__Fv() {
}


// address: 0x80021348
// line start: 185
// line end:   188
void RGBGreen__Fv() {
}


// address: 0x80021374
// line start: 194
// line end:   211
int GetUpDown__Fv() {
	// register: 5
	register int RetVal;
}


// address: 0x80021458
// line start: 245
// line end:   271
void Front_DirtyRectText__FiiPCc(int x, int y, char *pText) {
	// register: 17
	register int w;
	// register: 16
	register int h;
	// register: 19
	register int left;
	{
		// register: 7
		register int i;
	}
}


// address: 0x800215DC
// line start: 274
// line end:   279
void Front_RestoreBackground__Fv() {
	{
		// register: 20
		register int i;
	}
}


// address: 0x800216A4
// line start: 282
// line end:   288
void Front_FreeBackground__Fv() {
	{
		// register: 18
		register int i;
	}
}


// address: 0x80021734
// line start: 307
// line end:   312
void Front_InitMemCardMenus__Fi13EMemCardState13EPausedStatus(int Resolution, enum EMemCardState StartState, enum EPausedStatus_duplicate_e2 ReturnToState) {
}


// address: 0x80021750
// line start: 322
// line end:   323
void Front_SetLoadAction__F11ELoadAction(enum ELoadAction LoadAction) {
}


// address: 0x8002175C
// line start: 329
// line end:   330
void Front_SetSaveAction__F11ESaveAction(enum ESaveAction SaveAction) {
}


// address: 0x80021768
// line start: 405
// line end:   429
void Front_ExtractASCIINameFromSJIS__FPcT0(char *pSJIS, char *pASCII) {
	{
		// register: 3
		register int i;
	}
}


// address: 0x800217DC
// line start: 433
// line end:   474
void Front_SetSJISName__FPc(char *SJISName) {
	// register: 5
	register int i;
}


// address: 0x800218D0
// line start: 478
// line end:   490
void InitEnterName__Fv() {
}


// address: 0x80021930
// line start: 495
// line end:   692
void Front_MemCardDisplay__Fv() {
	// register: 16
	register int i;
	// register: 18
	register int XMid;
	{
		{
			{
				// address: 0xFFFFFFD0
				// size: 0x18
				auto char buf[24];
				{
					{
						{
							{
								// address: 0xFFFFFFD0
								// size: 0x3
								auto char tmp[3];
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80022178
// line start: 710
// line end:   954
void Front_MemCardHiResDisplay__Fv() {
	// register: 16
	register int i;
	// register: 18
	register int XMid;
	{
		{
			// register: 17
			register char *load;
			{
				// register: 16
				register int i;
				{
					// register: 16
					register int i;
					{
						{
							{
								// size: 0x20
								static char msg[32];
								{
									{
										{
											{
												// register: 5
												register int up;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x800227B0
// line start: 960
// line end:   974
int NameWasBlank__Fv() {
	{
		// register: 3
		register int i;
	}
}


// address: 0x800227FC
// line start: 978
// line end:   1005
void FillInDefaultName__Fv() {
	// address: 0x00000090
	static int Video;
	// address: 0x00000094
	static int Career;
}


// address: 0x80022910
// size: 0x4
// line start: 1018
// line end:   1028
enum EPausedStatus_duplicate_e2 SaveReturnState__Fv() {
}


// address: 0x80022960
// size: 0x4
// line start: 1035
// line end:   1925
enum EPausedStatus_duplicate_e2 Front_MemCardUpdate__Fv() {
	static int Delay;
	// address: 0x00000004
	static int Retries;
	// address: 0xFFFFFFC8
	auto int Activated;
	// address: 0xFFFFFFCC
	auto int GoBack;
	// address: 0xFFFFFFD0
	auto int AnyButton;
	// address: 0xFFFFFFD4
	auto int Start;
	{
		{
			{
				{
					{
						{
							{
								{
									{
										{
											{
												// register: 5
												register int i;
												{
													// register: 16
													register int UpDown;
													{
														{
															// register: 16
															// size: 0x4
															register enum EFileType_duplicate_e1 FileType;
															{
																{
																	{
																		// register: 16
																		register int WriteError;
																		{
																			{
																				{
																					{
																						{
																							{
																								{
																									// register: 5
																									register int i;
																									{
																										// address: 0xFFFFFDB8
																										// size: 0x10
																										auto char save_name[16];
																										{
																											{
																												{
																													// register: 22
																													// size: 0x4
																													register enum EFileType_duplicate_e1 WantedFileType;
																													// register: 6
																													register int Vids;
																													{
																														// register: 5
																														register int i;
																														{
																															{
																																// register: 17
																																register int m;
																																{
																																	// register: 16
																																	register int i;
																																	{
																																		{
																																			{
																																				// address: 0xFFFFFDC8
																																				// size: 0x200
																																				auto struct SCardHead CardHead;
																																				// register: 4
																																				register char *p;
																																				{
																																					// register: 6
																																					register int j;
																																					{
																																						{
																																							{
																																								{
																																									{
																																										{
																																											// register: 6
																																											register int i;
																																											{
																																												{
																																													// register: 4
																																													// size: 0x40
																																													register struct SVideoHead *VH;
																																													{
																																														// register: 7
																																														register int i;
																																														{
																																															// register: 16
																																															register unsigned long *pTmp;
																																														}
																																													}
																																												}
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80023B14
// line start: 1938
// line end:   1943
void Front_ClearGVideoRestartData__Fv() {
}


// address: 0x80023B38
// line start: 49
// line end:   218
unsigned char *DecompressStream__FPUcPsii(unsigned char *pSource, short *pDest, int StepSize, int StreamLength) {
	// register: 5
	register unsigned char Type;
	// register: 12
	register int Interval;
	// register: 15
	register int Segs;
	// register: 25
	register int RemainderLength;
	// register: 24
	register int Bits;
	// register: 10
	register int Val;
	// register: 11
	register int Off;
	{
		{
			{
				// register: 5
				register short v;
				{
					// register: 13
					register int i;
					{
						// register: 7
						register short NewVal;
						// register: 3
						register short Inc;
						{
							// register: 4
							register int j;
							{
								{
									// register: 10
									register short NewVal;
									// register: 3
									register short Inc;
									{
										// register: 4
										register int j;
										{
											// register: 14
											register int i;
											{
												// register: 7
												register int k;
												// register: 7
												register short NewVal;
												// register: 4
												register int d;
												// register: 5
												register short Inc;
												{
													// register: 3
													register int j;
													{
														{
															// register: 7
															register int k;
															// register: 7
															register short NewVal;
															// register: 3
															register int d;
															// register: 4
															register short Inc;
															{
																// register: 3
																register int j;
																{
																	// register: 3
																	register int i;
																	{
																		// register: 3
																		register int i;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80023ED0
// size: 0x18
// line start: 228
// line end:   448
struct SMatrix *Decomp_GetAnimTransform__FP6CSuper(struct CSuper *pSuper) {
	// register: 30
	// size: 0x40
	register struct SPSXRegion *pRegion;
	// register: 17
	register unsigned int *pAnimFile;
	// register: 19
	register unsigned int NumModels;
	// register: 5
	register unsigned int NumItems;
	// register: 22
	register int AnimNumber;
	{
		{
			// register: 4
			register int NewBuffer;
			// register: 7
			register unsigned int *pAnimHeader;
			// register: 6
			register int NewAnim;
			{
				{
					// register: 4
					register unsigned int *pHeader;
					// register: 7
					register int NumAnims;
					// register: 6
					register int MaxFrames;
					// register: 8
					register unsigned short *pParent;
					// register: 6
					register unsigned short *pChild;
					// register: 7
					register int c;
					{
						// register: 5
						register int i;
						{
							// register: 5
							register int i;
							{
								// register: 5
								register unsigned short *pHi;
								{
									// register: 4
									register int i;
									{
										{
											// register: 17
											register int NumFrames;
											// register: 18
											register int StepSize;
											// register: 4
											register unsigned char *pCompressedStream;
											// register: 16
											// size: 0xC
											register struct SEulerPivot *pEulerPivot;
											{
												// register: 20
												register int m;
												{
													{
														// register: 23
														// size: 0xC
														register struct SEulerPivot *pEulerPivots;
														// register: 18
														// size: 0x18
														register struct SMatrix *pMat;
														// register: 16
														// size: 0xC
														register struct SEulerPivot *pRootEuler;
														// register: 22
														register unsigned short *pModel;
														{
															// register: 20
															register int i;
															{
																// register: 17
																// size: 0x18
																register struct SMatrix *pParentMat;
																// register: 16
																// size: 0xC
																register struct SEulerPivot *pEulerPivot;
																{
																	{
																		// address: 0xFFFFFFD0
																		// size: 0x8
																		auto struct SVECTOR vec;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8002017C
// line start: 47
// line end:   70
void Career_Test__Fv() {
	{
		// register: 18
		register int i;
		{
			{
				// register: 16
				register int j;
			}
		}
	}
}


// address: 0x800202BC
// line start: 75
// line end:   127
void Career_Init__Fv() {
	// address: 0x00000058
	static char first_game;
	// register: 4
	register char *p;
	// register: 7
	register char **pHighScore;
	// register: 23
	register int HighScoreCount;
	{
		// register: 3
		register int i;
		{
			// address: 0xFFFFFFD0
			auto int Level;
			// register: 3
			register int i;
			{
				{
					// register: 16
					register int Score;
					{
						{
							// register: 4
							register int i;
						}
					}
				}
			}
		}
	}
}


// address: 0x800204A8
// line start: 131
// line end:   164
void Options_SetPreferences__Fv() {
	{
		// register: 8
		register int padNum;
		{
			// register: 5
			register int i;
			// register: 8
			register int padNum;
		}
	}
}


// address: 0x80020660
// line start: 199
// line end:   222
void Options_RemapControllers__Fv() {
	{
		// register: 13
		register int padNum;
		{
			{
				// register: 7
				register int i;
			}
		}
	}
}


// address: 0x8002073C
// line start: 226
// line end:   251
void Options_Init__Fv() {
	{
		// register: 12
		register int padNum;
	}
}


// address: 0x80020828
// line start: 257
// line end:   262
int Career_Got__Fi(int Goal) {
}


// address: 0x80020864
// line start: 268
// line end:   288
void Career_GiveTape__Fii(int Level, int Goal) {
	// register: 8
	register int t;
	{
		// register: 7
		register int j;
		{
			{
				// register: 4
				register int i;
			}
		}
	}
}


// address: 0x80020948
// line start: 294
// line end:   317
void Career_GiveMedal__Fi10EMedalType(int Level, enum EMedalType_duplicate_e2 medal) {
	// register: 10
	register int g;
	// register: 11
	register int s;
	// register: 12
	register int b;
	{
		// register: 8
		register int j;
	}
}


// address: 0x80020A48
// line start: 323
// line end:   328
int Career_LevelTapes__Fi(int Level) {
	// register: 7
	register int t;
	{
		// register: 6
		register int i;
	}
}


// address: 0x80020AAC
// line start: 40
// line end:   41
void Crowd_Init__Fv() {
}


// address: 0x80020AB4
// line start: 44
// line end:   59
void Crowd_Start__Fv() {
	{
		// register: 19
		register int i;
		{
		}
	}
}


// address: 0x80020BC4
// line start: 62
// line end:   72
void Crowd_Stop__Fv() {
	{
		// register: 17
		register int i;
	}
}


// address: 0x80020C64
// line start: 87
// line end:   106
int Crowd_MoveTowards__FRiii(int *Value, int Target, int Step) {
}


// address: 0x80020CC4
// line start: 112
// line end:   146
void Crowd_Update__Fv() {
	{
		// register: 30
		register int i;
	}
}


// address: 0x80020E98
// line start: 149
// line end:   211
void Crowd_Cheer__Fi(int Score) {
	// register: 5
	register int Volume;
	{
		{
			{
				{
					// register: 2
					register int Volume;
				}
			}
		}
	}
}


// address: 0x80021018
// line start: 214
// line end:   226
void Crowd_Oww__Fi(int Speed) {
	// register: 3
	register int Volume;
}


// address: 0x800210D8
// line start: 229
// line end:   268
void Crowd_Ahh__Fi(int Score) {
	// register: 16
	register int Volume;
	{
		{
			{
				{
					// register: 2
					register int Volume;
				}
			}
		}
	}
}


// address: 0x80021224
// line start: 271
// line end:   277
void Crowd_Boo__Fi(int Volume) {
}


// address: 0x800256FC
// size: 0x16C
// line start: 32
// line end:   79
struct CSmokeJet *__9CSmokeJetRC7CVectorRC8CSVectoriUsiiiiUcUi(struct CSmokeJet *this, struct CVector *BasePos, struct CSVector *Angles, int Length, int Duration, int Damage, int r, int g, int b, int ScrollSpeed, unsigned int Checksum) {
	{
		{
			{
				// register: 17
				register int i;
				{
					// register: 7
					register int scaledr;
					// register: 9
					register int scaledg;
					// register: 5
					register int scaledb;
				}
			}
		}
	}
}


// address: 0x80025A60
// line start: 83
// line end:   84
void ___9CSmokeJet(struct CSmokeJet *this, int __in_chrg) {
}


// address: 0x80025AB4
// line start: 88
// line end:   98
void SetPos__9CSmokeJetRC7CVector(struct CSmokeJet *this, struct CVector *Pos) {
	// address: 0xFFFFFFC0
	// size: 0xC
	auto struct CVector Off;
	// address: 0xFFFFFFD0
	// size: 0xC
	auto struct CVector pos;
	{
		{
			{
				// register: 18
				register int i;
			}
		}
	}
}


// address: 0x80025B74
// line start: 102
// line end:   179
void Move__9CSmokeJet(struct CSmokeJet *this) {
	{
		{
			// register: 4
			register int dx;
			// register: 3
			register int dz;
			// register: 2
			register int Dist;
			{
				// register: 10
				register int i;
				{
					// register: 21
					register int i;
					{
						{
							{
								{
									// address: 0xFFFFFFA0
									// size: 0xC
									auto struct CVector Start;
									// address: 0xFFFFFFB0
									// size: 0xC
									auto struct CVector End;
									// address: 0xFFFFFFC0
									// size: 0xC
									auto struct CVector Unit;
									// address: 0xFFFFFFD0
									// size: 0xC
									auto struct CVector dummy;
									// register: 2
									// size: 0x108
									register struct CBody_duplicate_s1 *pBody;
									{
										{
											{
												{
													// register: 2
													// size: 0x108
													register struct CBody_duplicate_s1 *pBody;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80025F94
// line start: 96
// line end:   97
void LoadingScreen_Main__Fv() {
}


// address: 0x80025F9C
// line start: 99
// line end:   100
void ClearSoftReset__Fv() {
}


// address: 0x80025FA4
// line start: 102
// line end:   103
void LoadingScreen_SetCurrentLevel__Fiii(int a, int b, int c) {
}


// address: 0x80025FAC
// line start: 108
// line end:   109
void FlickerSync__Fv() {
}


// address: 0x80025FB4
// line start: 263
// line end:   283
void Front_PrintDemo__Fv() {
	// address: 0x00000028
	static int demo_tick;
}


// address: 0x800260D0
// line start: 289
// line end:   303
int Front_DisplayScreen__FPc(char *pName) {
	// register: 16
	// size: 0x3C
	register struct Sprite2 *pBackground;
	{
		// register: 17
		register int i;
	}
}


// address: 0x800261A0
// line start: 361
// line end:   372
void Horse_Reset__Fv() {
}


// address: 0x80026200
// line start: 379
// line end:   415
void Horse_DisplayWords__FPi(int *pNumLetters) {
	{
		// register: 17
		register int i;
		{
			// address: 0xFFFFFFC0
			// size: 0x1E
			auto char Got[30];
			// register: 4
			register char *pLetter;
			// register: 3
			register char *pGot;
			// register: 5
			register int Letters;
		}
	}
}


// address: 0x80026370
// line start: 425
// line end:   430
void InitStatsSwisch__Fv() {
	{
		// register: 5
		register int i;
	}
}


// address: 0x800263C8
// line start: 438
// line end:   442
bool InCompetition__Fv() {
}


// address: 0x80026420
// size: 0x180
// line start: 545
// line end:   565
struct CMenu *__5CMenuiiUciii(struct CMenu *this, int x, int y, unsigned char Justification, int HiScale, int LowScale, int LineSep) {
	// register: 16
	// size: 0x4
	register struct CClass *this;
	{
		{
			// register: 24
			register int i;
		}
	}
}


// address: 0x80026534
// line start: 569
// line end:   571
void ___5CMenu(struct CMenu *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x80026564
// line start: 574
// line end:   585
void CentreY__5CMenu(struct CMenu *this) {
	// register: 7
	register int totalclearance;
	// register: 3
	register int numactivelines;
	// register: 3
	register int menuheight;
	{
		// register: 6
		register int i;
	}
}


// address: 0x800265EC
// line start: 589
// line end:   596
void SetLine__5CMenuUc(struct CMenu *this, unsigned char Line) {
	{
		// register: 3
		register int i;
	}
}


// address: 0x80026654
// line start: 611
// line end:   616
int FindEntry__5CMenuPCc(struct CMenu *this, char *pString) {
	{
		// register: 16
		register int i;
	}
}


// address: 0x800266D4
// line start: 620
// line end:   627
void AddEntry__5CMenuPCc(struct CMenu *this, char *pString) {
}


// address: 0x8002675C
// line start: 631
// line end:   633
void EntryOn__5CMenuPCc(struct CMenu *this, char *pString) {
}


// address: 0x80026798
// line start: 637
// line end:   639
void EntryOff__5CMenuPCc(struct CMenu *this, char *pString) {
}


// address: 0x800267D0
// line start: 643
// line end:   645
int IsEntryOn__5CMenuPCc(struct CMenu *this, char *pString) {
}


// address: 0x80026810
// line start: 675
// line end:   677
int ChoiceIs__5CMenuPCc(struct CMenu *this, char *pString) {
}


// address: 0x80026850
// line start: 704
// line end:   789
void Display__5CMenu(struct CMenu *this) {
	// register: 17
	register int y;
	{
		// register: 21
		register int i;
		{
			{
				{
					{
						{
							// register: 5
							register int length;
							{
								{
									// register: 5
									register int off;
									// register: 7
									// size: 0x14
									register struct POLY_F3 *leftpoly;
									// register: 8
									// size: 0x14
									register struct POLY_F3 *rightpoly;
									// register: 3
									register unsigned char *newppoly;
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80026CBC
// line start: 793
// line end:   862
void Update__5CMenu(struct CMenu *this) {
	{
		// register: 9
		register int i;
	}
}


// address: 0x80027044
// line start: 866
// line end:   875
void Front_ClearScreen__Fv() {
	// address: 0xFFFFFFF0
	// size: 0x8
	auto struct RECT screen;
}


// address: 0x800270DC
// line start: 888
// line end:   904
void Front_SavePreferences__FR12SPreferences(struct SPreferences *Pref) {
}


// address: 0x800270E4
// line start: 907
// line end:   936
void Front_SetPreferences__FRC12SPreferences(struct SPreferences *Pref) {
}


// address: 0x800270EC
// line start: 941
// line end:   1054
void Front_Init__Fv() {
}


// address: 0x80027874
// line start: 1233
// line end:   1244
void PrintPaused__Fv() {
}


// address: 0x800278C0
// line start: 1249
// line end:   1261
void Front_PrintGoBack__Fv() {
	// register: 2
	// size: 0x28
	register struct POLY_FT4 *pAPoly;
}


// address: 0x80027954
// line start: 1265
// line end:   1277
void Front_PrintSelect__Fv() {
	// register: 2
	// size: 0x28
	register struct POLY_FT4 *pAPoly;
}


// address: 0x800279E4
// line start: 1281
// line end:   1284
void Front_PrintGoBackSelect__Fv() {
}


// address: 0x80027A0C
// line start: 1288
// line end:   1298
void Front_PrintCentredPrompt__FPCc(char *Text) {
	// register: 2
	// size: 0x28
	register struct POLY_FT4 *pAPoly;
}


// address: 0x80027A98
// line start: 1307
// line end:   1332
int Graffiti_Stats__FP6CBruceiiiiiiiii(struct CBruce_duplicate_s0 *pSkater, int x, int y, int r, int g, int b, int Win, int Lose, int Streak, int High) {
	// address: 0xFFFFFFC8
	// size: 0xA
	auto char N[10];
}


// address: 0x80027D4C
// line start: 1339
// line end:   2353
void Front_Display__Fv() {
	// register: 19
	// size: 0x146C
	register struct CBruce_duplicate_s0 *pMan;
	// size: 0x14
	static char Score1[20];
	// address: 0x00000020
	// size: 0x14
	static char Score2[20];
	// size: 0x5
	static char Tapes[5];
	// address: 0x00000008
	// size: 0x8
	static char Tricks[8];
	// address: 0x00000010
	// size: 0x8
	static char Bails[8];
	// address: 0x00000040
	// size: 0x28
	static char BestCombo[40];
	// register: 18
	register int Line;
	{
		{
			// address: 0x00000090
			// size: 0x40
			static char highScoreBuf[64];
			// register: 17
			register int Level;
			{
				// register: 22
				register int NumTapes;
				{
					// register: 6
					register int i;
					{
						// register: 16
						register int i;
						{
							{
								{
									{
										// address: 0x00000070
										// size: 0x19
										static char GotATape[25];
										{
											// address: 0xFFFFFF68
											// size: 0x2
											auto char horseBuf[2];
											// register: 19
											register int termFound;
											{
												// register: 17
												register int i;
												{
													{
														// address: 0xFFFFFF70
														// size: 0xA
														auto char Score[10];
														{
															// register: 18
															register int i;
															{
																{
																	{
																		// register: 4
																		register char *p;
																		{
																			// register: 16
																			register int j;
																			{
																				// address: 0xFFFFFF68
																				// size: 0x2
																				auto char temp[2];
																				{
																					{
																						// register: 18
																						register int Line;
																						// register: 22
																						register int Level;
																						{
																							// register: 4
																							register int i;
																							{
																								// register: 4
																								register int i;
																								{
																									{
																										{
																											{
																												{
																													{
																														// address: 0xFFFFFF80
																														// size: 0x50
																														auto struct Font_duplicate_s0 Font1;
																														{
																															{
																																{
																																	// register: 19
																																	register int s1;
																																	// register: 18
																																	register int s2;
																																	{
																																		{
																																			// address: 0xFFFFFF68
																																			// size: 0x28
																																			auto char Score[40];
																																			{
																																				{
																																					{
																																						{
																																							{
																																								{
																																									{
																																										{
																																											// address: 0xFFFFFF90
																																											// size: 0x28
																																											auto char YouAre[40];
																																											{
																																												// address: 0xFFFFFF90
																																												// size: 0x20
																																												auto char buf[32];
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80029EAC
// line start: 2362
// line end:   2443
void Front_GetButtons__FRiN30(int *Activated, int *GoBack, int *AnyButton, int *Start) {
}


// address: 0x8002A140
// line start: 2447
// line end:   2461
void CommonSwitchOnMenuCode__Fv() {
}


// address: 0x8002A1D8
// line start: 2487
// line end:   2527
void Front_SwitchOnEndHeat__Fv() {
	// register: 4
	// size: 0x146C
	register struct CBruce_duplicate_s0 *pSkater;
	// register: 16
	// size: 0x146C
	register struct CBruce_duplicate_s0 *pSkater2;
}


// address: 0x8002A2C4
// line start: 2532
// line end:   2633
void Front_SwitchOnEndLevelMenu__Fv() {
	// register: 20
	// size: 0x146C
	register struct CBruce_duplicate_s0 *pSkater;
	// register: 16
	// size: 0x146C
	register struct CBruce_duplicate_s0 *pSkater2;
	{
		{
			{
				// register: 16
				register int i;
				{
					// register: 12
					register int Level;
					{
						{
							{
								// register: 3
								register int j;
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8002A630
// line start: 2647
// line end:   2651
void Front_SwitchOnStartLevelMenu__Fv() {
}


// address: 0x8002A658
// line start: 2655
// line end:   2659
void Front_PrintHorseLetters__Fv() {
}


// address: 0x8002A680
// line start: 2663
// line end:   2683
void Front_SwitchOnVideoScreen__Fv() {
	// register: 3
	// size: 0x4
	register enum EPausedStatus_duplicate_e2 VideoScreenMode;
}


// address: 0x8002A728
// line start: 2703
// line end:   2714
void RestartCompFrig__Fv() {
	{
		{
			// register: 16
			register int t;
		}
	}
}


// address: 0x8002A778
// line start: 2719
// line end:   4048
void Front_Update__Fv() {
	// register: 18
	register int SoundEffect;
	// register: 21
	register int SwitchOffPauseMode;
	// address: 0xFFFFFFD0
	auto int Activated;
	// address: 0xFFFFFFD4
	auto int GoBack;
	// address: 0xFFFFFFD8
	auto int AnyButton;
	// address: 0xFFFFFFDC
	auto int Start;
	// address: 0x00000274
	static int StartSelectPressed;
	// address: 0x00000278
	static unsigned int VblanksWhenStartSelectFirstPressed;
	{
		{
			{
				// register: 5
				// size: 0x146C
				register struct CBruce_duplicate_s0 *pSkater;
				// register: 16
				// size: 0x146C
				register struct CBruce_duplicate_s0 *pSkater2;
				// register: 6
				// size: 0xC0
				register struct SVideoInfo *VInfo;
				{
					{
						{
							{
								{
									{
										{
											{
												{
													// register: 17
													register int i;
													{
														// address: 0xFFFFFFC8
														// size: 0x4
														auto char head[4];
														{
															{
																{
																	// register: 2
																	// size: 0x180
																	register struct CMenu *this;
																	{
																		{
																			{
																				{
																					{
																						{
																							// register: 17
																							register int i;
																							{
																								// register: 18
																								register int UpDown;
																								// register: 16
																								register char lastAlpha;
																								// register: 17
																								register char firstAlpha;
																								{
																									// register: 4
																									register int i;
																									{
																										{
																											{
																												// register: 3
																												register int i;
																												{
																													{
																														{
																															{
																																// register: 16
																																register int Level;
																																// register: 18
																																register int UpDown;
																																{
																																	{
																																		// register: 5
																																		register int Level;
																																		{
																																			{
																																				{
																																					{
																																						{
																																							{
																																								{
																																									{
																																										{
																																											{
																																												{
																																													{
																																														{
																																															// register: 4
																																															// size: 0x146C
																																															register struct CBruce_duplicate_s0 *pSkater;
																																															// register: 16
																																															// size: 0x146C
																																															register struct CBruce_duplicate_s0 *pSkater2;
																																														}
																																													}
																																												}
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8002CC00
// size: 0x74
// line start: 4053
// line end:   4068
struct SLevel *Front_FindLevel__FPc(char *pTRGName) {
	// register: 19
	// size: 0x74
	register struct SLevel *pLevel;
	// register: 17
	register int k;
}


// address: 0x8002CCC0
// line start: 4073
// line end:   4116
void Front_SaveGameState__Fv() {
	// register: 6
	register char *pSource;
	// register: 5
	register char *pDest;
	// address: 0xFFFFFFE8
	// size: 0xC
	auto struct CVector Dummy;
	// register: 2
	// size: 0x6
	register struct CSVector *pAngles;
	// register: 3
	// size: 0x146C
	register struct CBruce_duplicate_s0 *pBruce;
	{
		{
		}
	}
}


// address: 0x8002CD9C
// line start: 4120
// line end:   4129
unsigned int Front_CalculateGameChecksum__FR9SSaveGame(struct SSaveGame *Game) {
	// register: 6
	register unsigned int chksum;
	{
		// register: 5
		register int i;
	}
}


// address: 0x8002CDC8
// line start: 4141
// line end:   4471
void Front_LoadGame__FP9SSaveGame(struct SSaveGame *pGame) {
	// register: 18
	register int r;
	// register: 20
	register int NumberOfOnscreenSkaters;
	// address: 0xFFFFFF78
	// size: 0x50
	auto struct Font_duplicate_s0 promptFont;
	// register: 17
	// size: 0x68
	register struct PromptScreenElement *pElement;
	// register: 19
	register unsigned int oldDb_SkyColor;
	// register: 16
	register int flash;
	{
		// register: 18
		register int i;
		{
			// register: 16
			register int selectedSkater;
			{
				{
					// register: 16
					// size: 0xA634
					register struct LevelGenerator *ed;
					// address: 0xFFFFFF68
					// size: 0xA
					auto char theme_name[10];
					// address: 0xFFFFFFD0
					auto int region;
					{
						{
							{
								// address: 0xFFFFFF68
								// size: 0x8
								auto struct RECT oldClipRect;
								// address: 0xFFFFFFC8
								// size: 0x8
								auto struct RECT newClipRect;
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8002D62C
// line start: 4471
// line end:   4471
void _GLOBAL__D_LoadingScreen_Main__Fv() {
}


// address: 0x8002D654
// line start: 4471
// line end:   4471
void _GLOBAL__I_LoadingScreen_Main__Fv() {
}


// address: 0x8002D678
// line start: 92
// line end:   92
void ___6CClass_addr_8002D678(struct CClass *this, int __in_chrg) {
}


// address: 0x8002D6A8
// line start: 220
// line end:   222
void Mess_SetTextJustify__FUc(unsigned char j) {
}


// address: 0x8002D6B4
// line start: 226
// line end:   237
void Mess_SetScale__Fi(int scale) {
}


// address: 0x8002D6E8
// line start: 240
// line end:   246
int Mess_GetScale__Fv() {
}


// address: 0x8002D71C
// line start: 250
// line end:   253
void Mess_SetSort__Fi(int sort) {
}


// address: 0x8002D728
// line start: 257
// line end:   270
void Mess_SetRGB__FUcUcUci(unsigned char r, unsigned char g, unsigned char b, int semitrans) {
}


// address: 0x8002D764
// line start: 332
// line end:   333
int Mess_DrawPanelText__FiiPCciUii(int x, int y, char *pMessage, int Angle, unsigned int FireRGB, int FireSquash) {
}


// address: 0x8002D798
// line start: 339
// line end:   358
int Mess_TextWidth2__FPCc(char *pMessage) {
	// register: 6
	register char *pScan;
	// register: 5
	register int Length;
	// register: 7
	register int NumLetters;
	{
		{
			{
				// register: 2
				register int frame;
			}
		}
	}
}


// address: 0x8002D8B8
// line start: 363
// line end:   380
int Mess_TextHeight2__FPCc(char *pMessage) {
	// register: 4
	register char *pScan;
	// register: 5
	register int Height;
	// register: 2
	register int temp;
	{
		{
			{
				// register: 2
				register int frame;
			}
		}
	}
}


// address: 0x8002D9C0
// line start: 384
// line end:   385
int Mess_TextHeightAboveBaseline2__FPCc(char *pMessage) {
}


// address: 0x8002D9E0
// line start: 389
// line end:   390
int Mess_TextHeightBelowBaseline2__FPCc(char *pMessage) {
}


// address: 0x8002D9E8
// size: 0x1C
// line start: 401
// line end:   410
struct Message *CreateMessage__Fv() {
	// register: 2
	// size: 0x1C
	register struct Message *pNew;
}


// address: 0x8002DA28
// line start: 415
// line end:   423
void Mess_DeleteMessage__FP7Message(struct Message *pMessage) {
}


// address: 0x8002DA94
// line start: 428
// line end:   439
void Mess_DeleteAll__Fv() {
	// register: 4
	// size: 0x1C
	register struct Message *pMessage;
	// register: 16
	// size: 0x1C
	register struct Message *pNext;
}


// address: 0x8002DADC
// size: 0x1C
// line start: 460
// line end:   472
struct Message *Mess_Message__FPCcP12SMessageProgbss(char *pText, struct SMessageProg *pProg, bool recenter, short xOffset, int yOffset) {
	// register: 3
	// size: 0x1C
	register struct Message *pNew;
}


// address: 0x8002DB54
// line start: 478
// line end:   506
void Mess_Update__Fv() {
	// register: 4
	// size: 0x1C
	register struct Message *pMess;
	// register: 16
	// size: 0x1C
	register struct Message *pNext;
}


// address: 0x8002DBFC
// line start: 513
// line end:   579
void Mess_Display__Fv() {
	// register: 17
	// size: 0x1C
	register struct Message *pMess;
	// register: 3
	register int i;
	// register: 19
	register int y_offset;
	{
		// register: 16
		// size: 0x20
		register struct SMessageProg *pProg;
		{
			{
				// register: 18
				register unsigned short Dur;
				// register: 6
				register int TextX;
				// register: 5
				register int TextY;
			}
		}
	}
}


// address: 0x8002DEDC
// line start: 624
// line end:   651
int Mess_TextWidth__FPCc(char *pMessage) {
	// register: 17
	register char *pScan;
	// register: 16
	register int Length;
	{
		// register: 6
		register int c;
	}
}


// address: 0x8002E02C
// line start: 656
// line end:   673
int Mess_TextHeightBelowBaseline__FPCc(char *pMessage) {
	// register: 16
	register char *pScan;
	// register: 17
	register int Height;
	// register: 5
	register int temph;
	{
		// register: 4
		register int c;
	}
}


// address: 0x8002E168
// line start: 678
// line end:   695
int Mess_TextHeightAboveBaseline__FPCc(char *pMessage) {
	// register: 16
	register char *pScan;
	// register: 17
	register int Height;
	// register: 3
	register int temph;
	{
		// register: 4
		register int c;
	}
}


// address: 0x8002E2A0
// line start: 700
// line end:   703
int Mess_TextHeight__FPCc(char *pMessage) {
}


// address: 0x8002E2EC
// line start: 710
// line end:   765
int GetCharIndex__Fc(char ch) {
}


// address: 0x8002E4E4
// line start: 772
// line end:   1061
int Mess_DrawText__FiiPCciUiib(int x, int y, char *pMessage, int DrawSolid, unsigned int FireRGB, int FireSquash, bool IsPanel) {
	// register: 19
	register char *pScan;
	// register: 16
	register int Off;
	// register: 30
	register int length;
	// address: 0xFFFFFFD0
	auto int currentScale;
	// register: 22
	register int useCurrentScale;
	// register: 18
	register int ScreenX;
	// register: 21
	register unsigned int shadow_off;
	// register: 4
	register int n;
	// register: 20
	register int char_count;
	{
		// register: 9
		// size: 0x34
		register struct POLY_GT4 *apoly;
		// register: 16
		// size: 0x28
		register struct POLY_FT4 *shadow;
		// register: 17
		// size: 0x28
		register struct POLY_FT4 *anothershadow;
		// register: 3
		register unsigned char *newppoly;
		// register: 15
		register unsigned int u0;
		// register: 11
		register unsigned int u1;
		// register: 12
		register unsigned short u2;
		// register: 10
		register unsigned short u3;
		// register: 2
		register unsigned char LargestRGB;
		{
			// register: 3
			register unsigned int w0;
			// register: 4
			register unsigned int w1;
			// register: 6
			register unsigned int w2;
			// register: 2
			register unsigned int w3;
		}
	}
}


// address: 0x8002EBC0
// line start: 1069
// line end:   1247
int Mess_LoadFont__FPcT0iii(char *filename, char *file_buffer, int char_sep, int shadow_offset, int width) {
	// register: 21
	register int this_font;
	// register: 19
	register int clutx;
	// register: 18
	register int cluty;
	// register: 17
	register unsigned short *clut;
	// address: 0xFFFFFFB0
	// size: 0x8
	auto struct RECT r;
	// register: 30
	register char *db;
	// address: 0xFFFFFFCC
	auto char *tb;
	// address: 0xFFFFFFC0
	auto int x;
	// address: 0xFFFFFFC4
	auto int y;
	{
		// register: 17
		register int the_font;
		{
			// register: 5
			register int i;
			// register: 17
			register int the_font;
			{
				// register: 22
				register int i;
				{
					// register: 19
					register int w;
					// register: 18
					register int h;
					// address: 0xFFFFFFB8
					// size: 0x8
					auto struct RECT r;
				}
			}
		}
	}
}


// address: 0x8002F1CC
// line start: 1251
// line end:   1262
int Mess_LoadFont__FPciii(char *filename, int char_sep, int shadow_offset, int width) {
	// register: 16
	register char *buf;
}


// address: 0x8002F258
// line start: 1267
// line end:   1279
void Mess_UnloadFont__Fv() {
	{
		// register: 17
		register int i;
	}
}


// address: 0x8002F3D4
// line start: 1296
// line end:   1299
void Mess_SetCurrentFont__Fi(int Font) {
}


// address: 0x8002F3E0
// line start: 1304
// line end:   1313
void Mess_SetCurrentFont__FPc(char *font_name) {
	// register: 16
	register int i;
}


// address: 0x8002F450
// line start: 1330
// line end:   1338
void Mess_SetFontScale__FUi(unsigned int scale) {
}


// address: 0x8002F4A4
// line start: 1341
// line end:   1344
int Mess_GetFontScale__Fv() {
}


// address: 0x8002F4E0
// line start: 1348
// line end:   1349
void Mess_SetNewFont__FUc(unsigned char which) {
}


// address: 0x8002F4EC
// line start: 23
// line end:   28
void Flash_Reset__Fv() {
}


// address: 0x8002F504
// line start: 32
// line end:   37
int Flash_FadeFinished__Fv() {
}


// address: 0x8002F510
// line start: 48
// line end:   65
void Flash_Screen__FUcUcUciUci(unsigned char StartR, unsigned char StartG, unsigned char StartB, int Frames, int Importance, int Sort) {
}


// address: 0x8002F594
// line start: 69
// line end:   76
void Flash_Fade__Fii(int Frames, int Sort) {
}


// address: 0x8002F5D0
// line start: 82
// line end:   120
void Flash_Update__Fv() {
}


// address: 0x8002F6A0
// line start: 124
// line end:   156
void Flash_Display__Fv() {
	{
		{
			// register: 9
			register unsigned int *OTPos;
			// register: 8
			// size: 0x18
			register struct POLY_F4 *aPoly;
			// register: 10
			// size: 0x8
			register struct DR_TPAGE *ptpage;
			// register: 3
			register unsigned char *newppoly;
		}
	}
}


// address: 0x8002F7F0
// size: 0x64
// line start: 13
// line end:   28
struct CLight *__6CLightRC7CVectoriiiiiUcUcUcUcUcUc(struct CLight *this, struct CVector *Pos, int Node, int ClipDist, int InnerRadius, int FringeRadius, int Amp, int r0, int g0, int b0, int r1, int g1, int b1) {
	{
		// register: 16
		// size: 0x64
		register struct CLight *this;
		{
		}
	}
}


// address: 0x8002F8F0
// line start: 32
// line end:   34
void ___6CLight(struct CLight *this, int __in_chrg) {
}


// address: 0x8002F964
// line start: 38
// line end:   82
void Move__6CLight(struct CLight *this) {
	// register: 4
	register int dx;
	// register: 3
	register int dz;
	// register: 17
	register int Dist;
}


// address: 0x80032890
// line start: 130
// line end:   134
void Redbook_InitialRand__Fi(int a) {
}


// address: 0x800328B4
// line start: 138
// line end:   143
int Redbook_Rnd__Fi(int n) {
}


// address: 0x80032910
// line start: 149
// line end:   156
void Redbook_SetXAMode__Fv() {
	// address: 0xFFFFFFF0
	auto unsigned char mode;
}


// address: 0x80032954
// line start: 163
// line end:   166
void Redbook_XAAllow__Fb(bool allow) {
}


// address: 0x8003295C
// line start: 171
// line end:   224
void Redbook_XAUpdateVolume__Fv() {
	// register: 5
	register int vl;
	// register: 6
	register int vr;
	// address: 0xFFFFFFF0
	// size: 0x4
	auto struct CdlATV atv;
}


// address: 0x80032A5C
// line start: 231
// line end:   266
void Redbook_XAInit__Fv() {
	// address: 0xFFFFFFE0
	// size: 0x18
	auto struct CdlFILE p_xa_file;
}


// address: 0x80032AE4
// line start: 298
// line end:   310
bool Redbook_XAPlayRandom__Fv() {
	// register: 6
	register int group;
	// register: 5
	register int channel;
	// register: 2
	register int track;
}


// address: 0x80032B60
// line start: 314
// line end:   365
bool Redbook_XASeek__Fv() {
	// address: 0xFFFFFFF0
	// size: 0x4
	auto struct CdlLOC pos;
	// register: 2
	register int diff;
}


// address: 0x80032C00
// line start: 369
// line end:   497
bool Redbook_XAPlay__Fii(int group, int channel) {
	// address: 0xFFFFFFE0
	// size: 0x4
	auto struct CdlFILTER filter;
	// address: 0xFFFFFFE8
	// size: 0x4
	auto struct CdlLOC pos;
	// address: 0x00000508
	bool try_again;
}


// address: 0x80032DB8
// line start: 501
// line end:   515
void Redbook_XAStop__Fv() {
}


// address: 0x80032DF4
// line start: 538
// line end:   560
void Redbook_XANextTrack__Fv() {
	// register: 6
	register int group;
	// register: 5
	register int channel;
}


// address: 0x80032E78
// line start: 564
// line end:   592
void Redbook_XAPause__Fb(bool pauseIt) {
	{
		{
			// address: 0xFFFFFFF0
			// size: 0x4
			auto struct CdlLOC pos;
		}
	}
}


// address: 0x80032F2C
// line start: 598
// line end:   694
void Redbook_XAUpdate__Fv() {
	{
		{
			// register: 16
			register int ret;
		}
	}
}


// address: 0x800330B8
// line start: 697
// line end:   700
void Redbook_XABeginFade__Fv() {
}


// address: 0x800330D0
// line start: 704
// line end:   708
void Redbook_XARemember__FP8SONG_POS(struct SONG_POS *pSongPos) {
}


// address: 0x800330EC
// line start: 712
// line end:   724
void Redbook_XARestore__FP8SONG_POS(struct SONG_POS *pSongPos) {
}


// address: 0x80033160
// line start: 15
// line end:   17
void PutHexDigit__FPcUi(char *p, unsigned int n) {
}


// address: 0x80033178
// line start: 21
// line end:   23
void PutHexByte__FPcUi(char *p, unsigned int n) {
}


// address: 0x800331B8
// line start: 27
// line end:   29
void PutHex2Byte__FPcUi(char *p, unsigned int n) {
}


// address: 0x800331F8
// line start: 33
// line end:   35
void PutHex4Byte__FPcUi(char *p, unsigned int n) {
}


// address: 0x80033238
// line start: 42
// line end:   60
unsigned int CheckSum_Calculate__FUiUci(unsigned int Score, unsigned char Random, int gs) {
	// register: 7
	register unsigned int c;
	// register: 9
	register unsigned int x;
	{
		// register: 8
		register int i;
	}
}


// address: 0x800332C4
// line start: 64
// line end:   66
void CheckSum_Encode__FUiUci(unsigned int Score, unsigned char Random, int gs) {
}


// address: 0x800332F0
// line start: 515
// line end:   539
void DumpAutoTest__Fv() {
	// address: 0xFFFFFEB0
	// size: 0x14
	auto struct DISPENV DispEnv;
	// address: 0xFFFFFEC8
	// size: 0x5C
	auto struct DRAWENV DrawEnv;
	// address: 0xFFFFFF28
	// size: 0xC8
	auto char Temp[200];
	// register: 18
	register int n;
}


// address: 0x800333EC
// line start: 588
// line end:   593
void ResetMainDemoTimer__Fv() {
}


// address: 0x800333F4
// line start: 676
// line end:   690
void *__nw__6CClassUi(unsigned int size) {
	// register: 6
	register void *pnew;
	// register: 4
	register unsigned int *p;
	{
		// register: 3
		register int i;
	}
}


// address: 0x80033468
// line start: 694
// line end:   698
void __dl__6CClassPv(void *p) {
	// register: 16
	register int Before;
}


// address: 0x800334AC
// line start: 703
// line end:   707
void CalcPolyBufferEnd__Fv() {
}


// address: 0x800334E0
// line start: 724
// line end:   725
void PollHost__Fv() {
}


// address: 0x800334E8
// line start: 730
// line end:   784
void Game_Over__Fv() {
}


// address: 0x8003368C
// line start: 1010
// line end:   1049
void Mick_Darken__Fv() {
	// register: 8
	// size: 0x18
	register struct POLY_F4 *aPoly;
	// register: 10
	// size: 0x8
	register struct DR_TPAGE *ptpage;
	// register: 3
	register unsigned char *newppoly;
}


// address: 0x800337A0
// line start: 1236
// line end:   1322
void DownloadBMP__FPciiii(char *pData, int x, int y, int ClutX, int ClutY) {
	// register: 17
	register int w;
	// register: 19
	register int h;
	// register: 18
	register int colors;
	// register: 20
	register int transparent_color;
	// address: 0xFFFFFDD0
	// size: 0x200
	auto unsigned short colorTab[256];
	// register: 10
	register char *pColor;
	// address: 0xFFFFFFD0
	// size: 0x8
	auto struct RECT r;
	// register: 16
	register int pad;
	// register: 18
	register char *data;
	// register: 4
	register char *in;
	// register: 5
	register char *out;
	{
		// register: 9
		register int i;
		{
			// register: 5
			register unsigned short r;
			// register: 3
			register unsigned short g;
			// register: 4
			register unsigned short b;
			{
				// register: 8
				register int j;
				// register: 9
				register int i;
				{
					{
						// register: 6
						register int i;
						{
							// register: 3
							register int i;
						}
					}
				}
			}
		}
	}
}


// address: 0x800339E4
// line start: 1330
// line end:   1366
void ReplaceTexture__FUiPc(unsigned int Checksum, char *pFile) {
	// register: 5
	// size: 0x28
	register struct Texture *pTexture;
	// register: 18
	register int X;
	// register: 19
	register int Y;
	// register: 20
	register int ClutX;
	// register: 17
	register int ClutY;
	// register: 16
	register char *buf;
}


// address: 0x80033AA4
// line start: 1482
// line end:   1590
void FlipPrimitives__Fv() {
	// register: 6
	// size: 0x8
	register struct P_TAG *pPrim;
	{
		{
			{
			}
		}
	}
}


// address: 0x80033C7C
// line start: 1912
// line end:   2044
int Display_Viewport__FP9SViewporti(struct SViewport *pViewport, int ViewportNumber) {
	// register: 18
	register int t1;
	// register: 17
	register int t2;
	{
		{
		}
	}
}


// address: 0x80033E6C
// line start: 2192
// line end:   2208
void Draw_Rect__Fiiiiiiiii(int X0, int Y0, int X1, int Y1, int X2, int Y2, int X3, int Y3, int c) {
	// register: 2
	// size: 0x18
	register struct POLY_F4 *pF4;
	// register: 16
	register unsigned char *newppoly;
}


// address: 0x80033F3C
// line start: 2213
// line end:   2215
void BlackOut__Fiiii(int x, int y, int w, int h) {
}


// address: 0x80033F7C
// line start: 2220
// line end:   2534
void Display__Fv() {
	{
		{
			// address: 0x000000D0
			static int Released;
			{
				{
					{
					}
				}
			}
		}
	}
}


// address: 0x800344E0
// line start: 2812
// line end:   2815
int FPS_Init__Fv() {
	{
		// register: 4
		register int i;
	}
}


// address: 0x8003451C
// line start: 2820
// line end:   2884
int FPS_Display__Fv() {
	// register: 5
	register int Total;
	{
		// register: 6
		register int i;
		{
			{
				static int FPS_Pulse;
				// size: 0x64
				static char tmp1[100];
			}
		}
	}
}


// address: 0x80034740
// line start: 2910
// line end:   3055
int PlayAway_Init__Fv() {
	// address: 0xFFFFFFD0
	// size: 0x20
	auto char tex[16][2];
	{
		// register: 4
		register int i;
	}
}


// address: 0x800348DC
// line start: 3059
// line end:   3081
void SetSkater__FP6CBrucePc(struct CBruce_duplicate_s0 *pBruce, char *filename) {
	{
		{
			// address: 0xFFFFFEE8
			// size: 0x80
			auto char *PSH_AnimHierarchy[32];
			// address: 0xFFFFFFE8
			auto int mAnimPartCount;
			// address: 0xFFFFFF68
			// size: 0x80
			auto char *PSH_ModelHierarchy[32];
			// address: 0xFFFFFFEC
			auto int mModelPartCount;
			// register: 17
			register char *pData1;
			// register: 16
			register char *pData2;
		}
	}
}


// address: 0x800349A4
// line start: 3086
// line end:   3153
void CreateSkatersAndCameras__Fv() {
	// register: 19
	register int NumberOfOnscreenSkaters;
	{
		// register: 17
		register int i;
		{
			// register: 16
			// size: 0x146C
			register struct CBruce_duplicate_s0 *pBruce;
			// register: 2
			// size: 0x684
			register struct CCamera *pCam;
			{
				// register: 2
				// size: 0x684
				register struct CCamera *this;
				{
				}
			}
		}
	}
}


// address: 0x80034C70
// line start: 3247
// line end:   3610
void Game_Init__Fv() {
	// register: 2
	register int XStart;
	{
		{
			// register: 2
			register int LoadError;
			{
				{
					{
						// register: 6
						register int i;
						{
							{
								{
									// register: 6
									register int i;
									{
										{
											// register: 4
											register int LoadError;
											{
												{
													// register: 4
													// size: 0x40
													register struct SVideoHead *VH;
													{
														// register: 7
														register int i;
														{
															{
																{
																	// register: 6
																	register int i;
																	{
																		{
																			// register: 4
																			// size: 0x146C
																			register struct CBruce_duplicate_s0 *pSkater;
																			// register: 16
																			// size: 0x146C
																			register struct CBruce_duplicate_s0 *pSkater2;
																			{
																				// register: 16
																				// size: 0x146C
																				register struct CBruce_duplicate_s0 *pSkater;
																				// register: 17
																				// size: 0x146C
																				register struct CBruce_duplicate_s0 *pSkater2;
																				{
																					// register: 16
																					register int i;
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80035450
// line start: 3615
// line end:   3672
void System_Logic__Fv() {
	// address: 0xFFFFFE88
	// size: 0x16C
	auto struct SControl TempPad;
}


// address: 0x800356DC
// line start: 3682
// line end:   3742
void CheckEndGame__Fv() {
}


// address: 0x80035920
// line start: 3750
// line end:   3770
void CheckSkatersStop__Fv() {
	{
		{
			{
				{
					// register: 17
					register int t;
					{
						{
							{
								{
									// register: 17
									register int t;
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80035A08
// line start: 3822
// line end:   4110
void Game_Logic__Fv() {
	// register: 4
	register int Frozen;
	{
		{
			// register: 17
			register int t;
		}
	}
}


// address: 0x80035F9C
// line start: 4115
// line end:   4151
void Game_Display__Fv() {
}


// address: 0x800360A0
// line start: 4160
// line end:   4188
int MainLoop_End__Fv() {
}


// address: 0x80036110
// line start: 4263
// line end:   4373
void PlayAway__Fv() {
}


// address: 0x800361D8
// line start: 4467
// line end:   4646
int main() {
	{
		// register: 17
		register int i;
	}
}


// address: 0x8003651C
// line start: 4669
// line end:   4844
int LaunchGame__Fv() {
	// register: 17
	register int Result;
	// address: 0xFFFFFF68
	// size: 0x88
	auto struct SSaveGame tmp;
	{
		{
			{
				{
					{
						// register: 17
						register int i;
					}
				}
			}
		}
	}
}


// address: 0x8002FB00
// size: 0x138
// line start: 51
// line end:   318
struct CPowerUp *__8CPowerUpUsRC7CVectorT2Uii(struct CPowerUp *this, unsigned short PowerupType, struct CVector *Pos, struct CVector *Vel, unsigned int Flags, int Lifetime) {
	{
		{
			{
				// register: 5
				// size: 0x3
				register struct CFriction *this;
				{
					{
						{
							{
								{
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8003018C
// line start: 322
// line end:   325
void ___8CPowerUp(struct CPowerUp *this, int __in_chrg) {
}


// address: 0x800301F4
// line start: 335
// line end:   340
void DontDisplay__8CPowerUp(struct CPowerUp *this) {
}


// address: 0x8003022C
// line start: 344
// line end:   347
void SetGravity__8CPowerUpii(struct CPowerUp *this, int g, int fric) {
}


// address: 0x80030238
// line start: 351
// line end:   385
void CreateBit__8CPowerUp(struct CPowerUp *this) {
}


// address: 0x8003024C
// line start: 389
// line end:   395
void DeleteStuff__8CPowerUp(struct CPowerUp *this) {
}


// address: 0x8003029C
// line start: 399
// line end:   402
void SetNode__8CPowerUpi(struct CPowerUp *this, int NodeIndex) {
}


// address: 0x800302AC
// line start: 406
// line end:   426
void Die__8CPowerUp(struct CPowerUp *this) {
}


// address: 0x800302EC
// line start: 429
// line end:   489
void DoPhysics__8CPowerUp(struct CPowerUp *this) {
	{
		{
			{
				{
					{
						{
							// register: 2
							register int ground;
							{
								{
									{
										{
											{
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80030530
// line start: 493
// line end:   525
void CheckAge__8CPowerUp(struct CPowerUp *this) {
	{
		{
			{
				{
					{
						// register: 16
						// size: 0x4C
						register struct CItem *this;
						{
							{
								{
									{
										{
											{
												// register: 16
												// size: 0x4C
												register struct CItem *this;
												{
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8003068C
// line start: 528
// line end:   709
void TakeEffect__8CPowerUpP6CBruce(struct CPowerUp *this, struct CBruce_duplicate_s0 *pMech) {
	// register: 19
	register int HadEffect;
	// register: 20
	register int sound;
	{
		{
			{
				{
					// register: 16
					register char *pMess;
					{
						{
							// register: 16
							register int Pong;
						}
					}
				}
			}
		}
	}
}


// address: 0x80030AAC
// line start: 712
// line end:   872
void AI__8CPowerUp(struct CPowerUp *this) {
	// register: 16
	register int width;
	{
		{
			// register: 3
			register int m;
			{
				{
					{
						{
							{
								{
									{
										// register: 16
										register int i;
										{
											// register: 16
											register int i;
											{
												// register: 16
												register int i;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80030F28
// size: 0x138
// line start: 883
// line end:   904
struct CPowerUp *PowerUp_Create__FUsRC7CVectorUiiR7CVector(unsigned short Type, struct CVector *Pos, unsigned int Flags, int LifeTime, struct CVector *Vel) {
	// register: 2
	// size: 0x138
	register struct CPowerUp *pNewPowerUp;
}


// address: 0x80030F94
// size: 0xCC
// line start: 40
// line end:   58
struct CShatterBit *__11CShatterBitRC8CSVectorN21RC7CVectori(struct CShatterBit *this, struct CSVector *a, struct CSVector *b, struct CSVector *c, struct CVector *pos, int Smoke) {
	{
		{
			{
				{
					{
						// register: 3
						// size: 0x6
						register struct CSVector *this;
						{
							{
								{
									// register: 3
									// size: 0x6
									register struct CSVector *this;
									{
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8003109C
// line start: 63
// line end:   65
void ___11CShatterBit(struct CShatterBit *this, int __in_chrg) {
}


// address: 0x80031110
// line start: 69
// line end:   89
void SetPos__11CShatterBitRC7CVector(struct CShatterBit *this, struct CVector *pos) {
	// address: 0xFFFFFFB0
	// size: 0xC
	auto struct CVector d;
	// address: 0xFFFFFFE4
	auto int Len;
	// register: 2
	register int Norm;
}


// address: 0x8003128C
// line start: 93
// line end:   108
void Move__11CShatterBit(struct CShatterBit *this) {
}


// address: 0x8003131C
// line start: 120
// line end:   225
void Split__FRC7CVectorN20iiiiiiUii(struct CVector *a, struct CVector *b, struct CVector *c, int au, int av, int bu, int bv, int cu, int cv, unsigned int TextureWindow, int n) {
	{
		{
			// address: 0xFFFFFF18
			// size: 0xC
			auto struct CVector p;
			// register: 18
			register int pu;
			// register: 17
			register int pv;
			// register: 17
			register int MaxLen;
			// register: 16
			register int Side;
			// register: 2
			register int Len;
			// address: 0xFFFFFFA0
			auto int Gamma;
			{
				{
					{
						// address: 0xFFFFFF18
						// size: 0xC
						auto struct CVector sa;
						// address: 0xFFFFFF28
						// size: 0xC
						auto struct CVector sb;
						// address: 0xFFFFFF38
						// size: 0xC
						auto struct CVector sc;
						// address: 0xFFFFFF48
						// size: 0xC
						auto struct CVector Centre;
						// address: 0xFFFFFF58
						// size: 0x6
						auto struct CSVector OffA;
						// address: 0xFFFFFF78
						// size: 0x6
						auto struct CSVector OffB;
						// address: 0xFFFFFF80
						// size: 0x6
						auto struct CSVector OffC;
						// register: 16
						// size: 0xCC
						register struct CShatterBit *pBit;
						{
							{
								{
									{
										{
											{
												{
													{
														{
															// register: 16
															// size: 0xC0
															register struct CChunkBit *this;
															// address: 0x00000024
															auto unsigned int TexWin;
															{
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80031AD0
// line start: 229
// line end:   234
void TransformVertex__FR7CVectorP7SVECTORPUci(struct CVector *a, struct SVECTOR *pVertices, unsigned char *pVertexNums, int Vertex) {
}


// address: 0x80031B2C
// line start: 248
// line end:   282
void CalcRGB__FiUiiPUi(int IsGouraud, unsigned int ColourInfo, int NumVertices, unsigned int *pColourTable) {
	{
		{
			// register: 6
			register unsigned int Col0;
			// register: 7
			register unsigned int Col1;
			// register: 8
			register unsigned int Col2;
			// register: 5
			register int TotalRed;
			// register: 9
			register int TotalGreen;
			// register: 6
			register int TotalBlue;
			{
				{
					// register: 3
					register unsigned int Col3;
				}
			}
		}
	}
}


// address: 0x80031CA4
// line start: 293
// line end:   460
int Shatter_Face__FP4ItemPUiiiiii(struct Item *pItem, unsigned int *pFace, int NumSplits, int MakeFlash, int UseFlags, int ModifyFlags, int TryToShatter) {
	// register: 4
	// size: 0x24
	register struct SModel *pModel;
	// register: 18
	// size: 0x8
	register struct SVECTOR *pVertices;
	// register: 6
	// size: 0x8
	register struct SVECTOR *pNormals;
	// register: 19
	register unsigned char *pVertexNums;
	// register: 16
	// size: 0x28
	register struct Texture *pTexture;
	// address: 0xFFFFFF60
	// size: 0x20
	auto struct MATRIX Transform;
	// address: 0xFFFFFF80
	// size: 0xC
	auto struct CVector a;
	// address: 0xFFFFFF90
	// size: 0xC
	auto struct CVector b;
	// address: 0xFFFFFFA0
	// size: 0xC
	auto struct CVector c;
	// address: 0xFFFFFFD0
	auto int retval;
	{
		{
			{
				{
					{
						{
							{
								{
									{
										{
											{
												{
													{
														{
															// address: 0xFFFFFFB0
															// size: 0xC
															auto struct CVector norm;
															{
																{
																	{
																		// register: 8
																		register unsigned int TextureWindow;
																		{
																			// address: 0xFFFFFFB0
																			// size: 0xC
																			auto struct CVector d;
																			{
																				{
																					{
																						{
																							{
																								{
																									// address: 0xFFFFFFC0
																									// size: 0xC
																									auto struct CVector norm;
																									{
																										{
																											{
																												// register: 17
																												register unsigned int TextureWindow;
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x800322BC
// line start: 469
// line end:   498
int Shatter_Item__FP4Itemii(struct Item *pItem, int UseFlags, int ModifyFlags) {
	// register: 7
	// size: 0x24
	register struct SModel *pModel;
	// register: 19
	register int NumFaces;
	// register: 16
	register unsigned int *pFace;
	// register: 18
	register int Shattered;
	// register: 20
	register int num;
	{
		// register: 17
		register int i;
		{
			// register: 2
			register int comeback;
		}
	}
}


// address: 0x800323F4
// line start: 511
// line end:   561
void Shatter_Glass__FiRC7CVectorN31UcUcUc(int n, struct CVector *p0, struct CVector *p1, struct CVector *p2, struct CVector *Normal, int r, int g, int b) {
	// address: 0xFFFFFE68
	// size: 0xC
	auto struct CVector middle;
	// address: 0xFFFFFE88
	// size: 0xA4
	auto struct SLineInfo ColInfo;
	// register: 30
	register int GroundY;
	// address: 0xFFFFFE78
	// size: 0xC
	auto struct CVector u;
	// address: 0xFFFFFF30
	// size: 0xC
	auto struct CVector v;
	{
		// register: 19
		register int i;
		{
			// address: 0xFFFFFFAC
			auto int alpha;
			// address: 0xFFFFFFB0
			auto int beta;
			// address: 0xFFFFFF40
			// size: 0xC
			auto struct CVector p;
			// address: 0xFFFFFF50
			// size: 0xC
			auto struct CVector a;
			{
				{
					// address: 0xFFFFFF40
					// size: 0xC
					auto struct CVector CamPos;
					{
						// register: 8
						register int a;
						// register: 9
						register int b;
						// register: 10
						register int c;
						{
						}
					}
				}
			}
		}
	}
}


// address: 0x80032838
// line start: 568
// line end:   578
void Shatter_MaybeMakeGlassShatterSound__Fv() {
}


// address: 0x80032888
// line start: 579
// line end:   579
void _GLOBAL__I___11CShatterBitRC8CSVectorN21RC7CVectori() {
	{
		{
			{
				{
				}
			}
		}
	}
}


// address: 0x8003E690
// size: 0x250
// line start: 20
// line end:   36
struct CPlatform *__9CPlatformPsi(struct CPlatform *this, short *p_info, int node_index) {
	{
		{
			{
				{
					{
						// register: 16
						// size: 0x250
						register struct CPlatform *this;
						{
							{
								// register: 16
								// size: 0x214
								register struct CBaddy *this;
								{
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8003E758
// line start: 62
// line end:   68
void ___9CPlatform(struct CPlatform *this, int __in_chrg) {
}


// address: 0x8003E7D8
// line start: 81
// line end:   161
void Bounce__9CPlatformP6CBruceRC7CVector(struct CPlatform *this, struct CBruce_duplicate_s0 *pSkater, struct CVector *Direction) {
	// register: 17
	register int Height;
	// register: 19
	register int Speed;
	// address: 0xFFFFFFD8
	// size: 0xC
	auto struct CVector Dir;
	{
		{
			{
				{
					{
						// register: 3
						// size: 0xC
						register struct CVector *this;
						// register: 2
						register int a;
						// register: 17
						register int b;
						// register: 4
						register int c;
						{
							{
								// register: 5
								// size: 0xC
								register struct CVector *this;
								// register: 2
								register int a;
								// register: 4
								register int c;
								{
									{
										// register: 4
										// size: 0xC
										register struct CVector *this;
										// register: 3
										register int a;
										// register: 5
										register int c;
										{
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8003EAB8
// line start: 194
// line end:   435
void BouncyAI__9CPlatform(struct CPlatform *this) {
	// address: 0xFFFFFEC0
	// size: 0x20
	auto struct MATRIX m;
	// address: 0xFFFFFEE0
	// size: 0xA4
	auto struct SLineInfo LInfo;
	// address: 0xFFFFFF88
	// size: 0xC
	auto struct CVector NewPos;
	// address: 0xFFFFFF98
	// size: 0xC
	auto struct CVector NewVel;
	// address: 0xFFFFFFA8
	// size: 0x3
	auto struct CFriction Fric;
	// register: 19
	register int ObjectExtent;
	// address: 0xFFFFFFB0
	// size: 0xC
	auto struct CVector Dir;
	// register: 17
	register int Speed;
	{
		{
			{
				{
					{
						{
							{
								{
									{
										{
											{
												// register: 20
												register int NumChecks;
												{
													// address: 0xFFFFFFC8
													// size: 0xC
													auto struct CVector Normal;
													// register: 16
													register int dot;
													{
														// register: 2
														register int _x;
														// register: 3
														register int _y;
														// register: 5
														register int _z;
														{
															// register: 6
															register int _x;
															// register: 7
															register int _y;
															// register: 8
															register int _z;
															{
																{
																	{
																		{
																			{
																				// register: 2
																				register int _x;
																				// register: 3
																				register int _y;
																				// register: 5
																				register int _z;
																				{
																					{
																						{
																							// register: 3
																							register int _x;
																							// register: 6
																							register int _y;
																							// register: 7
																							register int _z;
																							{
																								{
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8003F344
// line start: 441
// line end:   677
void AI__9CPlatform(struct CPlatform *this) {
	{
		{
			{
				{
					{
						{
							{
								// register: 2
								// size: 0xC
								register struct CVector *this;
								{
									{
										{
											{
												// address: 0xFFFFFFC0
												// size: 0x6
												auto struct CSVector ideal_angles;
												{
													{
														{
															{
																{
																	// address: 0xFFFFFFC0
																	// size: 0x6
																	auto struct CSVector ideal_angles;
																	// register: 3
																	register int ang_acc;
																	// register: 4
																	register short roll;
																	// register: 3
																	register short rolldiff;
																	{
																		{
																			{
																				{
																					{
																						// address: 0xFFFFFFC0
																						// size: 0x6
																						auto struct CSVector ideal_angles;
																						// register: 3
																						register int ang_acc;
																						{
																							{
																								{
																									{
																										{
																											// register: 4
																											register short rolldiff;
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8003F8EC
// line start: 682
// line end:   702
int Hit__9CPlatformiRC7CVectori(struct CPlatform *this, int damage, struct CVector *knock, int whathit) {
}


// address: 0x8003F98C
// line start: 711
// line end:   767
void DoPhysics__9CPlatform(struct CPlatform *this) {
	{
		{
			// register: 12
			register int vx;
			// register: 11
			register int vy;
			// register: 13
			register int vz;
			// register: 9
			register short sx;
			// register: 10
			register short sy;
			// register: 8
			register short sz;
		}
	}
}


// address: 0x8003FB90
// line start: 775
// line end:   781
void MoveTo__9CPlatformR7CVector(struct CPlatform *this, struct CVector *pos) {
}


// address: 0x8003FBF4
// line start: 812
// line end:   837
void ProcessPattern__9CPlatform(struct CPlatform *this) {
}


// address: 0x8003FBFC
// line start: 841
// line end:   1071
int ExecuteCommand__9CPlatformUs(struct CPlatform *this, unsigned short command) {
	{
		{
			{
				// register: 5
				// size: 0x24
				register struct SModel *m;
				// register: 6
				register short *pBox;
				{
					{
						{
							{
								// register: 4
								register short p;
								{
									// register: 4
									register short p;
									{
										// register: 4
										register short p;
										{
											// register: 4
											register short p;
											{
												{
													// register: 16
													register int *p_pos;
													// address: 0xFFFFFFD8
													// size: 0xC
													auto struct CVector pos;
													{
														{
															{
																// register: 5
																register unsigned short node;
																// address: 0xFFFFFFD8
																// size: 0xC
																auto struct CVector pos;
																{
																	{
																		{
																			// register: 16
																			register int *p_pos;
																			// address: 0xFFFFFFD8
																			// size: 0xC
																			auto struct CVector pos;
																			{
																				{
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x800403E8
// line start: 1077
// line end:   1142
void SetVariable__9CPlatformUs(struct CPlatform *this, unsigned short variable) {
	{
		{
			{
				// register: 16
				register unsigned int *p_checksum;
				{
					{
						// register: 3
						// size: 0xC
						register struct CVector *this;
						{
							{
								{
									// register: 3
									// size: 0x6
									register struct CSVector *this;
									{
										{
											{
												// register: 3
												// size: 0x6
												register struct CSVector *this;
												{
													{
														{
															// register: 3
															// size: 0x6
															register struct CSVector *this;
															{
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x800405B0
// line start: 1150
// line end:   1164
short GetVariable__9CPlatformUs(struct CPlatform *this, unsigned short variable) {
}


// address: 0x800405E8
// line start: 1183
// line end:   1238
void Platform_HandleBounce__FP6CBruce(struct CBruce_duplicate_s0 *pSkater) {
	// register: 16
	// size: 0x24
	register struct Item *pItem;
	// register: 2
	register int tmp;
	// register: 22
	register int LP1;
	// register: 21
	register int RP1;
	// register: 18
	register int FP1;
	// register: 17
	register int BP1;
	// register: 20
	register int UP1;
	// register: 19
	register int DP1;
	{
		{
			{
				{
					{
						{
							{
								{
									// register: 3
									// size: 0x24
									register struct SModel *m;
									// register: 5
									register short *pBox;
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8004080C
// size: 0x214
// line start: 243
// line end:   254
struct CBaddy *__6CBaddy(struct CBaddy *this) {
	{
		{
		}
	}
}


// address: 0x80040880
// line start: 261
// line end:   266
void ___6CBaddy(struct CBaddy *this, int __in_chrg) {
}


// address: 0x800408F4
// line start: 276
// line end:   286
void Die__6CBaddy(struct CBaddy *this) {
	{
		// register: 16
		// size: 0x4C
		register struct CItem *this;
		{
		}
	}
}


// address: 0x80040940
// line start: 302
// line end:   317
void SendDeathPulse__6CBaddy(struct CBaddy *this) {
}


// address: 0x8004099C
// line start: 457
// line end:   479
void SkipToEndif__6CBaddy(struct CBaddy *this) {
	// register: 5
	register unsigned short token;
	// register: 3
	register int conditionals;
}


// address: 0x800409F4
// line start: 484
// line end:   508
void ParseScript__6CBaddyPUs(struct CBaddy *this, unsigned short *p_script) {
	{
		// register: 5
		register unsigned short command;
		{
			// register: 16
			// size: 0x214
			register struct CBaddy *this;
			{
			}
		}
	}
}


// address: 0x80040AB4
// line start: 513
// line end:   1124
int ExecuteCommand__6CBaddyUs(struct CBaddy *this, unsigned short command) {
	{
		{
			{
				// register: 5
				register unsigned short type;
				// register: 16
				register int gravity;
				// register: 2
				// size: 0x138
				register struct CPowerUp *p_powerup;
				{
					// address: 0xFFFFFFC0
					// size: 0xC
					auto struct CVector pos;
					{
						{
							{
								{
									// register: 5
									register unsigned short node;
									{
										{
											{
												{
													{
														// register: 5
														register unsigned short shake;
														{
															{
																{
																	{
																		// register: 16
																		register unsigned int *p_checksum;
																		{
																			// register: 5
																			register unsigned short node;
																			// register: 2
																			register unsigned short *p_links;
																			{
																				// register: 17
																				register unsigned short node;
																				{
																					{
																						{
																							{
																								// register: 3
																								register char *p_string;
																								{
																									{
																										// register: 2
																										// size: 0xC
																										register struct CVector *this;
																										{
																											{
																												// register: 3
																												register char *p_string;
																												{
																													// register: 5
																													register unsigned short node;
																													// register: 2
																													register unsigned short *pNode;
																													// address: 0xFFFFFFC0
																													// size: 0xC
																													auto struct CVector dummy;
																													{
																														{
																															{
																																{
																																	// register: 5
																																	register unsigned short *p_return;
																																	{
																																		{
																																			{
																																				{
																																					{
																																						{
																																							{
																																								{
																																									// address: 0xFFFFFFD0
																																									// size: 0x10
																																									auto unsigned short dummy_script[8];
																																									// register: 19
																																									register int dummy_script_index;
																																									// register: 5
																																									register int var_id;
																																									// register: 17
																																									register unsigned short *p_start;
																																									// register: 20
																																									register int v0;
																																									// register: 5
																																									register int v1;
																																									{
																																										// register: 16
																																										register int v0;
																																										// register: 5
																																										register int v1;
																																										{
																																											// register: 16
																																											register int v0;
																																											// register: 5
																																											register int v1;
																																											{
																																												// register: 16
																																												register int v0;
																																												// register: 5
																																												register int v1;
																																												{
																																													{
																																														// register: 18
																																														// size: 0x214
																																														register struct CBaddy *this;
																																														{
																																															{
																																																{
																																																	{
																																																		{
																																																			// register: 18
																																																			// size: 0x4C
																																																			register struct CItem *this;
																																																			{
																																																				{
																																																					{
																																																						// register: 18
																																																						// size: 0x4C
																																																						register struct CItem *this;
																																																						{
																																																							{
																																																								{
																																																									{
																																																										// register: 17
																																																										register unsigned short sparks;
																																																										{
																																																											{
																																																												// address: 0xFFFFFFC0
																																																												// size: 0x6
																																																												auto struct CSVector cone;
																																																												{
																																																													// register: 2
																																																													// size: 0x6
																																																													register struct CSVector *this;
																																																													{
																																																														{
																																																															// register: 16
																																																															register int i;
																																																														}
																																																													}
																																																												}
																																																											}
																																																										}
																																																									}
																																																								}
																																																							}
																																																						}
																																																					}
																																																				}
																																																			}
																																																		}
																																																	}
																																																}
																																															}
																																														}
																																													}
																																												}
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8004194C
// line start: 1130
// line end:   1139
unsigned short GetScriptValue__6CBaddy(struct CBaddy *this) {
	// register: 5
	register unsigned short value;
}


// address: 0x800419A4
// line start: 1145
// line end:   1280
void SetVariable__6CBaddyUs(struct CBaddy *this, unsigned short variable) {
	{
		{
			{
				// register: 2
				register unsigned int *p_checksum;
				{
					// register: 16
					register unsigned int *p_checksum;
					{
						{
							{
								{
									{
										{
											{
												// register: 17
												// size: 0x214
												register struct CBaddy *this;
												{
													{
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80041C28
// line start: 1288
// line end:   1435
short GetVariable__6CBaddyUs(struct CBaddy *this, unsigned short variable) {
	{
		{
			{
				{
					{
						// register: 2
						register unsigned int dist;
						{
							{
								{
									// address: 0xFFFFFFE8
									// size: 0xC
									auto struct CVector eye_pos;
									{
										{
											// register: 6
											// size: 0x214
											register struct CBaddy *this;
											{
												{
													// register: 5
													register unsigned short node;
													// register: 2
													register unsigned short *p_links;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80041E80
// size: 0x22C
// line start: 1467
// line end:   1487
struct CScriptOnlyBaddy *__16CScriptOnlyBaddyPsi(struct CScriptOnlyBaddy *this, short *p_info, int node_index) {
	{
		// register: 16
		// size: 0x214
		register struct CBaddy *this;
		{
			{
				// register: 16
				// size: 0x4C
				register struct CItem *this;
				{
					{
						// register: 16
						// size: 0x108
						register struct CBody_duplicate_s1 *this;
						{
						}
					}
				}
			}
		}
	}
}


// address: 0x80041F38
// line start: 1493
// line end:   1508
void ___16CScriptOnlyBaddy(struct CScriptOnlyBaddy *this, int __in_chrg) {
	{
		{
			{
				// register: 16
				register int i;
				{
					// register: 2
					// size: 0x10
					register struct SRainEntry_duplicate_s0 *p_entry;
				}
			}
		}
	}
}


// address: 0x80042054
// line start: 1515
// line end:   1605
void AI__16CScriptOnlyBaddy(struct CScriptOnlyBaddy *this) {
	{
		// register: 19
		// size: 0x4C
		register struct CItem *this;
		{
			{
				{
					{
						{
							// register: 16
							register int t;
							{
								{
									// address: 0xFFFFFFD4
									auto int ground;
									{
										// register: 20
										register int i;
										{
											// register: 18
											// size: 0x10
											register struct SRainEntry_duplicate_s0 *p_entry;
											// address: 0xFFFFFF80
											// size: 0xC
											auto struct CVector pos;
											{
												{
													// address: 0xFFFFFF90
													// size: 0xC
													auto struct CVector offset;
													{
														{
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80042344
// line start: 1612
// line end:   1637
void SetVariable__16CScriptOnlyBaddyUs(struct CScriptOnlyBaddy *this, unsigned short variable) {
}


// address: 0x80042364
// line start: 1646
// line end:   1798
int ExecuteCommand__16CScriptOnlyBaddyUs(struct CScriptOnlyBaddy *this, unsigned short command) {
	{
		{
			{
				{
					{
						{
							{
								{
									// register: 19
									// size: 0x214
									register struct CBaddy *this;
									{
										{
											{
												// register: 19
												// size: 0x214
												register struct CBaddy *this;
												{
													{
														{
															// address: 0xFFFFFF80
															// size: 0xC
															auto struct CVector origin;
															{
																// register: 20
																register int i;
																{
																	// register: 18
																	// size: 0x10
																	register struct SRainEntry_duplicate_s0 *p_entry;
																	// address: 0xFFFFFF90
																	// size: 0xC
																	auto struct CVector offset;
																	// register: 17
																	// size: 0x64
																	register struct CGPolyLine *p_droplet;
																	{
																		{
																			{
																				// register: 18
																				// size: 0xC
																				register struct CVector *this;
																				{
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80036848
// size: 0x60
// line start: 20
// line end:   33
struct CPolyLine *__9CPolyLinei(struct CPolyLine *this, int numsegs) {
	{
		{
			{
				// register: 5
				register int i;
			}
		}
	}
}


// address: 0x80036928
// line start: 37
// line end:   41
void ___9CPolyLine(struct CPolyLine *this, int __in_chrg) {
}


// address: 0x800369B4
// line start: 45
// line end:   47
void SetSemiTransparent__9CPolyLine(struct CPolyLine *this) {
	{
		// register: 5
		register int i;
		{
			{
				// register: 4
				// size: 0x10
				register struct SLineSeg *this;
				{
				}
			}
		}
	}
}


// address: 0x80036A00
// size: 0x64
// line start: 73
// line end:   91
struct CGPolyLine *__10CGPolyLinei(struct CGPolyLine *this, int numsegs) {
	{
		{
			{
				// register: 5
				register int i;
			}
		}
	}
}


// address: 0x80036AF8
// line start: 95
// line end:   99
void ___10CGPolyLine(struct CGPolyLine *this, int __in_chrg) {
}


// address: 0x80036B84
// line start: 103
// line end:   106
void SetSemiTransparent__10CGPolyLine(struct CGPolyLine *this) {
	{
		// register: 5
		register int i;
		{
			{
				// register: 4
				// size: 0x10
				register struct SLineSeg *this;
				{
				}
			}
		}
	}
}


// address: 0x80036BDC
// line start: 149
// line end:   149
void ___15CSmokeGenerator(struct CSmokeGenerator *this, int __in_chrg) {
}


// address: 0x80036C2C
// line start: 153
// line end:   166
void Move__15CSmokeGenerator(struct CSmokeGenerator *this) {
	// address: 0xFFFFFFD8
	// size: 0xC
	auto struct CVector upvel;
	{
		// register: 2
		// size: 0xC
		register struct CVector *this;
		{
			{
				// register: 18
				register int i;
				{
					// register: 16
					// size: 0x70
					register struct CMotionBlur *foo;
					{
						// register: 16
						// size: 0x48
						register struct CBit *this;
						{
							{
								// register: 16
								// size: 0x70
								register struct CFlatBit *this;
								{
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80036D6C
// size: 0x68
// line start: 172
// line end:   175
struct CGLine *__6CGLine(struct CGLine *this) {
	{
		{
			{
				{
				}
			}
		}
	}
}


// address: 0x80036DC4
// line start: 179
// line end:   180
void ___6CGLine(struct CGLine *this, int __in_chrg) {
}


// address: 0x80036E24
// size: 0x78
// line start: 209
// line end:   233
struct CGrindSpark *__11CGrindSparkP5CBodyR7CVectoriii(struct CGrindSpark *this, struct CBody_duplicate_s1 *pParent, struct CVector *pos, int vel, int gravity, int life) {
	{
		{
			// register: 5
			register int vel2;
			{
				// register: 5
				// size: 0x3
				register struct CFriction *this;
				{
				}
			}
		}
	}
}


// address: 0x80036F88
// line start: 238
// line end:   239
void ___11CGrindSpark(struct CGrindSpark *this, int __in_chrg) {
}


// address: 0x80036FD8
// line start: 243
// line end:   295
void Move__11CGrindSpark(struct CGrindSpark *this) {
	// register: 7
	register int px;
	// register: 8
	register int py;
	// register: 6
	register int pz;
	// register: 17
	register int nx;
	// register: 18
	register int ny;
	// register: 25
	register int nz;
	// register: 13
	register int sx;
	// register: 14
	register int sy;
	// register: 15
	register int sz;
}


// address: 0x800370EC
// line start: 85
// line end:   101
long Transform__FRC7CVectorRi(struct CVector *Pos, int *yx) {
	// address: 0xFFFFFFF8
	auto long Zed;
	// address: 0xFFFFFFE8
	// size: 0xC
	auto struct CVector Temp;
	{
		{
		}
	}
}


// address: 0x80037198
// line start: 108
// line end:   136
void Bit_Init__Fv() {
	{
		// register: 18
		register int i;
	}
}


// address: 0x8003727C
// line start: 140
// line end:   158
void DeleteBitList__FP4CBit(struct CBit *pBitList) {
	// register: 4
	// size: 0x48
	register struct CBit *pList;
	// register: 16
	// size: 0x48
	register struct CBit *pNext;
}


// address: 0x800372E4
// line start: 163
// line end:   195
void Bit_DeleteAll__Fv() {
}


// address: 0x80037398
// line start: 205
// line end:   213
void RemoveDeadBits__FP4CBit(struct CBit *pBit) {
	// register: 16
	// size: 0x48
	register struct CBit *pNext;
}


// address: 0x80037400
// line start: 218
// line end:   234
void Bit_RemoveDeadBits__Fv() {
}


// address: 0x800374B4
// line start: 257
// line end:   284
void *__nw__4CBitUi(unsigned int size) {
	// register: 6
	register void *pnew;
	// register: 5
	register unsigned int *p;
	{
		// register: 3
		register int i;
	}
}


// address: 0x80037534
// line start: 288
// line end:   300
void __dl__4CBitPv(void *p) {
}


// address: 0x80037574
// line start: 306
// line end:   313
void AttachTo__4CBitPv(struct CBit *this, void *p) {
}


// address: 0x800375A0
// line start: 317
// line end:   324
void DeleteFrom__4CBitPv(struct CBit *this, void *p) {
	// register: 5
	// size: 0x48
	register struct CBit **pList;
}


// address: 0x800375FC
// line start: 328
// line end:   330
void Die__4CBit(struct CBit *this) {
}


// address: 0x80037608
// line start: 334
// line end:   335
void SetPos__4CBitRC7CVector(struct CBit *this, struct CVector *pos) {
}


// address: 0x80037628
// size: 0x48
// line start: 360
// line end:   363
struct CBit *__4CBit(struct CBit *this) {
	{
		{
			{
				{
					{
						{
							{
								{
									{
										{
											{
												// register: 5
												// size: 0x3
												register struct CFriction *this;
												{
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80037660
// line start: 367
// line end:   369
void ___4CBit(struct CBit *this, int __in_chrg) {
}


// address: 0x800376A0
// size: 0x48
// line start: 380
// line end:   382
struct CSpecialDisplay *__15CSpecialDisplay(struct CSpecialDisplay *this) {
}


// address: 0x800376E0
// line start: 386
// line end:   388
void ___15CSpecialDisplay(struct CSpecialDisplay *this, int __in_chrg) {
}


// address: 0x80037740
// size: 0x48
// line start: 392
// line end:   394
struct CNonRenderedBit *__15CNonRenderedBit(struct CNonRenderedBit *this) {
}


// address: 0x8003777C
// line start: 398
// line end:   400
void ___15CNonRenderedBit(struct CNonRenderedBit *this, int __in_chrg) {
}


// address: 0x800377D8
// size: 0x60
// line start: 404
// line end:   412
struct CFT4Bit *__7CFT4Bit(struct CFT4Bit *this) {
}


// address: 0x80037824
// line start: 416
// line end:   417
void ___7CFT4Bit(struct CFT4Bit *this, int __in_chrg) {
}


// address: 0x80037874
// line start: 425
// line end:   425
void SetScale__7CFT4BitUs(struct CFT4Bit *this, unsigned short s) {
}


// address: 0x8003787C
// line start: 427
// line end:   427
void SetSemiTransparent__7CFT4Bit(struct CFT4Bit *this) {
}


// address: 0x80037890
// line start: 430
// line end:   430
void SetTint__7CFT4BitUcUcUc(struct CFT4Bit *this, unsigned char r, unsigned char g, unsigned char b) {
}


// address: 0x800378C4
// line start: 433
// line end:   433
void SetTransDecay__7CFT4Biti(struct CFT4Bit *this, int decay) {
}


// address: 0x800378CC
// line start: 440
// line end:   445
void SetAnim__7CFT4BitPc(struct CFT4Bit *this, char *pName) {
}


// address: 0x8003790C
// line start: 461
// line end:   467
void SetFrame__7CFT4Biti(struct CFT4Bit *this, int frame) {
}


// address: 0x8003792C
// line start: 471
// line end:   476
void IncFrame__7CFT4Bit(struct CFT4Bit *this) {
}


// address: 0x8003798C
// line start: 480
// line end:   486
void IncFrameWithWrap__7CFT4Bit(struct CFT4Bit *this) {
}


// address: 0x80037A00
// line start: 500
// line end:   502
void ChooseRandomFrame__7CFT4Bit(struct CFT4Bit *this) {
}


// address: 0x80037A44
// line start: 506
// line end:   516
int Shrink__7CFT4Biti(struct CFT4Bit *this, int die) {
}


// address: 0x80037AA0
// line start: 521
// line end:   541
int Fade__7CFT4Biti(struct CFT4Bit *this, int die) {
	{
		{
			// register: 6
			register unsigned char r;
			// register: 4
			register unsigned char g;
			// register: 5
			register unsigned char b;
		}
	}
}


// address: 0x80037BA4
// size: 0x9C
// line start: 554
// line end:   556
struct CQuadBit *__8CQuadBit(struct CQuadBit *this) {
	{
		{
			{
				{
					{
						{
							{
								{
									{
										{
											{
												{
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80037BEC
// line start: 560
// line end:   561
void ___8CQuadBit(struct CQuadBit *this, int __in_chrg) {
}


// address: 0x80037C48
// line start: 575
// line end:   579
void SetTexture__8CQuadBitPci(struct CQuadBit *this, char *pAnimName, int Frame) {
}


// address: 0x80037C8C
// line start: 603
// line end:   604
void FlagOn__8CQuadBitUc(struct CQuadBit *this, unsigned char b) {
}


// address: 0x80037CA0
// line start: 613
// line end:   614
void SetSemiTransparent__8CQuadBit(struct CQuadBit *this) {
}


// address: 0x80037CB4
// line start: 623
// line end:   624
void SetTransparency__8CQuadBitUc(struct CQuadBit *this, unsigned char t) {
}


// address: 0x80037CE0
// line start: 634
// line end:   652
void OrientUsing__8CQuadBitRC7CVectorRC7SVECTORiii(struct CQuadBit *this, struct CVector *Position, struct SVECTOR *Normal, int dx, int dy, int Angle) {
	// address: 0xFFFFFF88
	// size: 0xC
	auto struct CVector b1;
	// address: 0xFFFFFF98
	// size: 0xC
	auto struct CVector b2;
	// address: 0xFFFFFFD8
	auto int l1;
	// address: 0xFFFFFFDC
	auto int l2;
	{
		{
			{
				{
				}
			}
		}
	}
}


// address: 0x80037F14
// line start: 685
// line end:   687
void ___8CGenPoly(struct CGenPoly *this, int __in_chrg) {
}


// address: 0x80037F70
// size: 0xC0
// line start: 789
// line end:   809
struct CChunkBit *__9CChunkBitRC8CSVectorN21(struct CChunkBit *this, struct CSVector *a, struct CSVector *b, struct CSVector *c) {
	{
		{
			{
				{
					{
						{
							{
								{
									{
										{
											// address: 0xFFFFFFA8
											// size: 0xC
											auto struct CVector ca;
											// address: 0xFFFFFFB8
											// size: 0xC
											auto struct CVector ba;
											// address: 0xFFFFFFC8
											// size: 0xC
											auto struct CVector cprod;
											// address: 0xFFFFFFD8
											// size: 0xC
											auto struct CVector norm;
											// register: 2
											register int mul;
											{
												// register: 4
												// size: 0xC
												register struct CVector *this;
												{
													{
														{
															{
																{
																	{
																		{
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80038168
// line start: 815
// line end:   817
void ___9CChunkBit(struct CChunkBit *this, int __in_chrg) {
}


// address: 0x800381C4
// line start: 823
// line end:   832
void SetRGB__9CChunkBitUcUcUc(struct CChunkBit *this, unsigned char r, unsigned char g, unsigned char b) {
	// register: 4
	register int mul;
}


// address: 0x80038318
// line start: 838
// line end:   843
void SetUVs__9CChunkBitUsUsUcUcUcUcUcUc(struct CChunkBit *this, unsigned short Clut, unsigned short TPage, unsigned char u0, int v0, int u1, int v1, int u2, int v2) {
}


// address: 0x80038368
// line start: 848
// line end:   869
void CalculateWorldCoords__9CChunkBit(struct CChunkBit *this) {
	// address: 0xFFFFFFD8
	// size: 0x20
	auto struct MATRIX Transform;
}


// address: 0x80038444
// size: 0x68
// line start: 901
// line end:   916
struct CGlow *__5CGlowUiUi(struct CGlow *this, unsigned int NumPoints, unsigned int NumFringes) {
	{
		// register: 6
		register int i;
	}
}


// address: 0x80038568
// size: 0x68
// line start: 920
// line end:   942
struct CGlow *__5CGlowRC7CVectoriiUcUcUcUcUcUc(struct CGlow *this, struct CVector *Pos, int InnerRadius, int FringeRadius, int r0, int g0, int b0, int r1, int g1, int b1) {
	// register: 4
	register unsigned int PadBGR;
	{
		// register: 5
		register int i;
		{
			// register: 5
			register int i;
			{
				// register: 5
				register int i;
			}
		}
	}
}


// address: 0x80038754
// line start: 946
// line end:   950
void ___5CGlow(struct CGlow *this, int __in_chrg) {
}


// address: 0x800387D4
// line start: 966
// line end:   968
void SetRadius__5CGlowi(struct CGlow *this, int Radius) {
	{
		// register: 6
		register int i;
	}
}


// address: 0x80038814
// line start: 972
// line end:   976
void SetFringeWidth__5CGlowUiUi(struct CGlow *this, unsigned int Fringe, unsigned int Width) {
	// register: 2
	// size: 0x8
	register struct SFringeQuad *pFringe;
	{
		// register: 7
		register int i;
	}
}


// address: 0x8003885C
// line start: 980
// line end:   984
void SetCentreRGB__5CGlowUcUcUc(struct CGlow *this, unsigned char r, unsigned char g, unsigned char b) {
}


// address: 0x80038888
// line start: 988
// line end:   991
void SetRGB__5CGlowUcUcUc(struct CGlow *this, unsigned char r, unsigned char g, unsigned char b) {
	// register: 7
	register unsigned int PadBGR;
	{
		// register: 8
		register int i;
	}
}


// address: 0x800388E4
// line start: 995
// line end:   1000
void SetFringeRGB__5CGlowUiUcUcUc(struct CGlow *this, unsigned int Fringe, unsigned char r, unsigned char g, int b) {
	// register: 3
	register unsigned int CodeBGR;
	// register: 2
	// size: 0x8
	register struct SFringeQuad *pFringe;
	{
		// register: 9
		register int i;
	}
}


// address: 0x80038950
// line start: 1004
// line end:   1014
void SetRadialRGB__5CGlowiUcUcUc(struct CGlow *this, int Spoke, unsigned char r, unsigned char g, int b) {
	// register: 6
	register unsigned int CodeBGR;
	// register: 5
	// size: 0x8
	register struct SFringeQuad *pFringe;
	{
		// register: 8
		register int i;
	}
}


// address: 0x800389C8
// size: 0xB0
// line start: 1034
// line end:   1043
struct CWobblyGlow *__11CWobblyGlowRC7CVectoriiiUcUcUcUcUcUc(struct CWobblyGlow *this, struct CVector *Pos, int InnerRadius, int FringeRadius, int Amp, int r0, int g0, int b0, int r1, int g1, int b1) {
	{
		// register: 18
		register int i;
	}
}


// address: 0x80038AAC
// line start: 1047
// line end:   1054
void Move__11CWobblyGlow(struct CWobblyGlow *this) {
	{
		// register: 7
		register int i;
	}
}


// address: 0x80038B48
// size: 0x70
// line start: 1058
// line end:   1067
struct CFlatBit *__8CFlatBit(struct CFlatBit *this) {
}


// address: 0x80038BA0
// line start: 1071
// line end:   1073
void ___8CFlatBit(struct CFlatBit *this, int __in_chrg) {
}


// address: 0x80038BFC
// size: 0x78
// line start: 1077
// line end:   1079
struct CLinked2EndedBit *__16CLinked2EndedBit(struct CLinked2EndedBit *this) {
	{
		{
			{
				{
				}
			}
		}
	}
}


// address: 0x80038C38
// line start: 1083
// line end:   1085
void ___16CLinked2EndedBit(struct CLinked2EndedBit *this, int __in_chrg) {
}


// address: 0x80038C94
// size: 0x54
// line start: 1089
// line end:   1091
struct CPixel *__6CPixel(struct CPixel *this) {
}


// address: 0x80038CD0
// line start: 1095
// line end:   1097
void ___6CPixel(struct CPixel *this, int __in_chrg) {
}


// address: 0x80038D2C
// line start: 1105
// line end:   1107
void Bit_SetSparkTrajectory__FRC8CSVector(struct CSVector *trajectory) {
}


// address: 0x80038D50
// line start: 1111
// line end:   1113
void Bit_SetSparkTrajectoryCone__FRC8CSVector(struct CSVector *cone) {
}


// address: 0x80038D74
// line start: 1117
// line end:   1123
void Bit_CalculateSparkVelocity__FR7CVectori(struct CVector *velocity, int magnitude) {
	// address: 0xFFFFFFE8
	// size: 0x6
	auto struct CSVector angles;
}


// address: 0x80038E6C
// line start: 1132
// line end:   1135
void Bit_SetSparkSize__FUi(unsigned int size) {
}


// address: 0x80038E80
// line start: 1139
// line end:   1143
void Bit_SetSparkRGB__FUcUcUc(unsigned char r, unsigned char g, unsigned char b) {
}


// address: 0x80038E94
// line start: 1147
// line end:   1151
void Bit_SetSparkFadeRGB__FUcUcUc(unsigned char r, unsigned char g, unsigned char b) {
}


// address: 0x80038EA8
// size: 0x5C
// line start: 1160
// line end:   1191
struct CSpark *__6CSparkR7CVectoriii(struct CSpark *this, struct CVector *pos, int vel, int gravity, int life) {
	{
		// register: 5
		// size: 0x3
		register struct CFriction *this;
		{
		}
	}
}


// address: 0x80038FE4
// line start: 1197
// line end:   1198
void ___6CSpark(struct CSpark *this, int __in_chrg) {
}


// address: 0x80039034
// line start: 1202
// line end:   1232
void Move__6CSpark(struct CSpark *this) {
	// register: 8
	register int x;
	// register: 4
	register int y;
	// register: 5
	register int z;
}


// address: 0x80039144
// line start: 1271
// line end:   1272
void ___11CSimpleAnim(struct CSimpleAnim *this, int __in_chrg) {
}


// address: 0x80039194
// line start: 1276
// line end:   1291
void Move__11CSimpleAnim(struct CSimpleAnim *this) {
	{
		{
			{
				{
					// register: 16
					// size: 0x60
					register struct CFT4Bit *this;
					{
						{
							{
								{
									// register: 16
									// size: 0x60
									register struct CFT4Bit *this;
									{
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8003922C
// size: 0x70
// line start: 1306
// line end:   1314
struct CMotionBlur *__11CMotionBlurRC7CVectorR7CVectorPciii(struct CMotionBlur *this, struct CVector *pos, struct CVector *vel, char *pAnimName, int initialscale, int scaledecay, int transdecay) {
}


// address: 0x800392F4
// line start: 1318
// line end:   1319
void ___11CMotionBlur(struct CMotionBlur *this, int __in_chrg) {
}


// address: 0x80039344
// line start: 1323
// line end:   1331
void Move__11CMotionBlur(struct CMotionBlur *this) {
}


// address: 0x800393A0
// line start: 1348
// line end:   1349
void ___19CMotionBlurImmortal(struct CMotionBlurImmortal *this, int __in_chrg) {
}


// address: 0x800393F0
// line start: 1353
// line end:   1361
void Move__19CMotionBlurImmortal(struct CMotionBlurImmortal *this) {
}


// address: 0x8003944C
// line start: 1389
// line end:   1390
void ___5CFrag(struct CFrag *this, int __in_chrg) {
}


// address: 0x8003949C
// line start: 1394
// line end:   1410
void Move__5CFrag(struct CFrag *this) {
}


// address: 0x80039590
// size: 0x78
// line start: 1685
// line end:   1686
struct CRibbonBit *__10CRibbonBit(struct CRibbonBit *this) {
}


// address: 0x800395C0
// line start: 1690
// line end:   1691
void ___10CRibbonBit(struct CRibbonBit *this, int __in_chrg) {
}


// address: 0x80039610
// line start: 1695
// line end:   1697
void Move__10CRibbonBit(struct CRibbonBit *this) {
}


// address: 0x80039630
// size: 0x60
// line start: 1703
// line end:   1727
struct CRibbon *__7CRibbonRC7CVectoriiPcT4ii(struct CRibbon *this, struct CVector *pos, int numbits, int pointsperbit, char *pMiddleAnimName, char *pEndAnimName, int scale, int semitrans) {
	{
		// register: 5
		register int i;
		{
			// register: 18
			register int i;
		}
	}
}


// address: 0x80039848
// line start: 1731
// line end:   1738
void ___7CRibbon(struct CRibbon *this, int __in_chrg) {
	{
		// register: 16
		register int i;
	}
}


// address: 0x80039948
// line start: 1742
// line end:   1744
void SetTint__7CRibbonUcUcUc(struct CRibbon *this, unsigned char r, unsigned char g, unsigned char b) {
	{
		// register: 16
		register int i;
	}
}


// address: 0x800399D8
// line start: 1748
// line end:   1750
void SetScale__7CRibboni(struct CRibbon *this, int Scale) {
	{
		// register: 16
		register int i;
	}
}


// address: 0x80039A48
// line start: 1754
// line end:   1767
void SetPos__7CRibbonR7CVector(struct CRibbon *this, struct CVector *pos) {
	// register: 6
	register int p;
	{
		// register: 7
		register int i;
	}
}


// address: 0x80039B4C
// size: 0x64
// line start: 1777
// line end:   1792
struct CSmokeTrail *__11CSmokeTrailR7CVectoriiii(struct CSmokeTrail *this, struct CVector *pos, int numbits, int r, int g, int b) {
	// register: 30
	register int decr;
	// register: 23
	register int decg;
	// register: 21
	register int decb;
	{
		// register: 16
		register int i;
		{
			// register: 7
			register int k;
		}
	}
}


// address: 0x80039CA4
// line start: 1796
// line end:   1797
void ___11CSmokeTrail(struct CSmokeTrail *this, int __in_chrg) {
}


// address: 0x80039CF4
// line start: 1801
// line end:   1810
void Move__11CSmokeTrail(struct CSmokeTrail *this) {
	{
		{
			// register: 18
			register int die;
			{
				// register: 16
				register int i;
			}
		}
	}
}


// address: 0x80039D8C
// size: 0x78
// line start: 1820
// line end:   1842
struct CGlassBit *__9CGlassBitRC7CVectorT1iUcUcUciii(struct CGlassBit *this, struct CVector *Pos, struct CVector *Vel, int GroundY, int r, int g, int b, int dx, int dy, int dz) {
	{
		{
			{
				{
					{
						{
							// register: 18
							register int u;
							// register: 19
							register int v;
							// register: 20
							register int w;
						}
					}
				}
			}
		}
	}
}


// address: 0x80039FD0
// line start: 1846
// line end:   1848
void ___9CGlassBit(struct CGlassBit *this, int __in_chrg) {
}


// address: 0x8003A02C
// line start: 1853
// line end:   1918
void Move__9CGlassBit(struct CGlassBit *this) {
	// register: 19
	register int vx;
	// register: 17
	register int vy;
	// register: 18
	register int vz;
}


// address: 0x8003A25C
// line start: 1933
// line end:   1940
void MoveList__FP4CBit(struct CBit *pBit) {
}


// address: 0x8003A2B8
// line start: 1945
// line end:   1959
void Bit_Move__Fv() {
}


// address: 0x8003A36C
// line start: 1991
// line end:   3450
void Bit_Display__Fv() {
	// address: 0xFFFFFE50
	// size: 0xC
	auto struct CVector Temp;
	// address: 0xFFFFFE60
	// size: 0xC
	auto struct CVector camera_pos;
	// address: 0xFFFFFF2C
	auto int GTEZedLimit;
	// register: 16
	// size: 0x48
	register struct CSpecialDisplay *pSpecial;
	// register: 19
	// size: 0x68
	register struct CGlow *pGlow;
	// register: 16
	// size: 0x64
	register struct CGPolyLine *pGPolyLine;
	// register: 16
	// size: 0x60
	register struct CPolyLine *pPolyLine;
	// register: 17
	// size: 0x70
	register struct CFlatBit *pFlatBit;
	// register: 8
	// size: 0x78
	register struct CGlassBit *pGlass;
	// register: 16
	// size: 0x68
	register struct CGLine *pGLine;
	// register: 18
	// size: 0x9C
	register struct CQuadBit *pQuad;
	// register: 16
	// size: 0xC0
	register struct CChunkBit *p_chunk;
	// register: 16
	// size: 0x54
	register struct CPixel *pPixel;
	// address: 0xFFFFFF74
	auto int Loop1x;
	// address: 0xFFFFFF78
	auto int Loop1y;
	// address: 0xFFFFFF7C
	auto int Loop2x;
	// address: 0xFFFFFF80
	auto int Loop2y;
	// address: 0xFFFFFF84
	auto int StoredA1x;
	// address: 0xFFFFFF88
	auto int StoredA1y;
	// address: 0xFFFFFF8C
	auto int StoredA2x;
	// address: 0xFFFFFF90
	auto int StoredA2y;
	// address: 0xFFFFFF94
	auto int StoredAx;
	// address: 0xFFFFFF98
	auto int StoredAy;
	// register: 4
	register int Broken;
	// register: 22
	// size: 0x78
	register struct CLinked2EndedBit *pLinked2EndedBit;
	{
		{
			{
				{
					{
						{
							// address: 0xFFFFFEA4
							auto unsigned int y0x0;
							// address: 0xFFFFFE70
							// size: 0x10
							auto struct VECTOR RotCoords;
							// address: 0xFFFFFE80
							// size: 0xC
							auto struct CVector Centre;
							// address: 0xFFFFFF30
							// size: 0x8
							auto struct DR_TPAGE *ptpage;
							// register: 4
							register unsigned char *newppoly;
							// register: 2
							register unsigned int a;
							// register: 3
							register unsigned int b;
							// address: 0xFFFFFF34
							auto int n;
							// address: 0xFFFFFF38
							auto int Step;
							// address: 0xFFFFFF3C
							auto int Ang;
							// address: 0xFFFFFF40
							// size: 0x8
							auto struct SSection *pSection;
							// address: 0xFFFFFF44
							auto short CentreX;
							// address: 0xFFFFFF48
							auto short CentreY;
							// register: 14
							register int RGBFade;
							// address: 0xFFFFFF4C
							auto unsigned int *OTPos;
							// address: 0xFFFFFF50
							// size: 0x4
							auto struct DVECTOR *pBufA;
							// register: 22
							// size: 0x4
							register struct DVECTOR *pBufB;
							// register: 3
							register int RadA;
							// address: 0xFFFFFF58
							auto int MSin;
							// address: 0xFFFFFF5C
							auto int MCos;
							// register: 5
							register int x;
							// register: 4
							register int y;
							// address: 0xFFFFFFC8
							auto int Rad;
							// register: 16
							// size: 0x8
							register struct SFringeQuad *pFringe;
							{
								// register: 8
								register int f;
								{
									{
										// address: 0xFFFFFF60
										auto int i;
										// register: 8
										register int f;
										{
											// address: 0xFFFFFF64
											auto int DoDisplay;
											// register: 2
											register unsigned int b;
											{
												{
													{
														{
															// register: 10
															// size: 0x1C
															register struct POLY_G3 *aGou;
															// register: 4
															register unsigned char *newppoly;
															{
																// register: 20
																register int f;
																{
																	{
																		{
																			// register: 13
																			// size: 0x24
																			register struct POLY_G4 *aGou;
																			// register: 4
																			register unsigned char *newppoly;
																			// register: 3
																			register unsigned int CodeBGR;
																			{
																				{
																					// register: 3
																					register unsigned int PadBGR;
																					{
																						// register: 19
																						register unsigned int LastBGR;
																						// register: 17
																						// size: 0x10
																						register struct SLineSeg *pSeg;
																						{
																							// register: 22
																							register int i;
																							{
																								// register: 20
																								register unsigned int NewBGR;
																								// register: 3
																								register int sort;
																								{
																									{
																										// register: 8
																										// size: 0x8
																										register struct DR_TPAGE *ptpage;
																										// register: 6
																										// size: 0x14
																										register struct LINE_G2 *aline;
																										// register: 4
																										register unsigned char *newppoly;
																										// register: 7
																										register unsigned int *otpos;
																										{
																											{
																												// register: 4
																												register unsigned int a;
																												// register: 2
																												register unsigned int b;
																												{
																													// register: 17
																													// size: 0x10
																													register struct SLineSeg *pSeg;
																													{
																														// register: 21
																														register int i;
																														{
																															// register: 18
																															register unsigned int CodeBGR;
																															// register: 5
																															register int sort;
																															{
																																{
																																	// register: 8
																																	// size: 0x8
																																	register struct DR_TPAGE *ptpage;
																																	// register: 7
																																	// size: 0x10
																																	register struct LINE_F2 *aline;
																																	// register: 3
																																	register unsigned char *newppoly;
																																	// register: 6
																																	register unsigned int *otpos;
																																	{
																																		{
																																			// register: 4
																																			register unsigned int a;
																																			// register: 2
																																			register unsigned int b;
																																			{
																																				{
																																					// address: 0xFFFFFEA8
																																					auto long zed;
																																					// address: 0xFFFFFEAC
																																					auto unsigned int y0x0;
																																					// register: 14
																																					// size: 0x28
																																					register struct POLY_FT4 *apoly;
																																					// register: 4
																																					register unsigned char *newppoly;
																																					// register: 11
																																					register unsigned int Scale;
																																					// register: 4
																																					// size: 0x28
																																					register struct Texture *stored;
																																					// register: 3
																																					register unsigned int foo1;
																																					// register: 6
																																					register unsigned int foo2;
																																					// register: 5
																																					register unsigned int foo3;
																																					// register: 4
																																					register unsigned short foo4;
																																					// register: 19
																																					register short Angle;
																																					// register: 18
																																					register unsigned int *ptr;
																																					// register: 21
																																					register unsigned char Flipped;
																																					// register: 5
																																					register int OffX;
																																					// register: 12
																																					register int OffY;
																																					// register: 13
																																					register unsigned int Width;
																																					// register: 10
																																					register unsigned int Height;
																																					// register: 2
																																					register unsigned int x_post_scale;
																																					// register: 4
																																					register unsigned int y_post_scale;
																																					{
																																						{
																																							// register: 3
																																							register int Y1;
																																							{
																																								// register: 4
																																								register int sin;
																																								// register: 3
																																								register int cos;
																																								// address: 0xFFFFFFC8
																																								auto int xsin;
																																								// register: 11
																																								register int ysin;
																																								// register: 6
																																								register int xcos;
																																								// register: 12
																																								register int ycos;
																																								// register: 20
																																								register int xwsin;
																																								// register: 16
																																								register int yhsin;
																																								// register: 9
																																								register int xwcos;
																																								// register: 19
																																								register int yhcos;
																																								// register: 10
																																								register unsigned int x_scale;
																																								// register: 13
																																								register unsigned int y_scale;
																																								{
																																									{
																																										// address: 0xFFFFFE70
																																										// size: 0x8
																																										auto struct SVECTOR STemp;
																																										// address: 0xFFFFFEB0
																																										auto long zed;
																																										// register: 7
																																										// size: 0x14
																																										register struct POLY_F3 *aGou;
																																										// register: 10
																																										// size: 0x8
																																										register struct DR_TPAGE *ptpage;
																																										// register: 3
																																										register unsigned char *newppoly;
																																										// register: 3
																																										register unsigned int a;
																																										// register: 4
																																										register unsigned int b;
																																										// register: 5
																																										register unsigned int *OTPos;
																																										{
																																											{
																																												// address: 0xFFFFFEBC
																																												auto unsigned int y0x01;
																																												// address: 0xFFFFFEC8
																																												auto unsigned int y0x02;
																																												// address: 0xFFFFFEB8
																																												auto long zed;
																																												// address: 0xFFFFFEC4
																																												auto long zed2;
																																												{
																																													{
																																														{
																																															{
																																																// register: 7
																																																// size: 0x14
																																																register struct LINE_G2 *aline;
																																																// register: 2
																																																register unsigned char *newppoly;
																																																{
																																																	{
																																																		// address: 0xFFFFFED8
																																																		auto long ZedB;
																																																		// address: 0xFFFFFEE0
																																																		auto long ZedC;
																																																		// address: 0xFFFFFEE8
																																																		auto long ZedD;
																																																		// address: 0xFFFFFED0
																																																		auto long MaxZed;
																																																		// register: 19
																																																		// size: 0x28
																																																		register struct Texture *stored;
																																																		// register: 16
																																																		// size: 0x28
																																																		register struct POLY_FT4 *apoly;
																																																		// register: 3
																																																		register unsigned char *newppoly;
																																																		// register: 2
																																																		register unsigned int foo1;
																																																		// register: 3
																																																		register unsigned int foo2;
																																																		// register: 4
																																																		register unsigned int foo3;
																																																		{
																																																			{
																																																				// register: 2
																																																				// size: 0xC
																																																				register struct DR_TWIN *p_overflow2;
																																																				// address: 0xFFFFFF0C
																																																				auto long opz;
																																																				// address: 0xFFFFFEEC
																																																				auto long ZedA;
																																																				// address: 0xFFFFFEF4
																																																				auto long ZedB;
																																																				// address: 0xFFFFFEFC
																																																				auto long ZedC;
																																																				// address: 0xFFFFFF04
																																																				auto long ZedD;
																																																				// register: 17
																																																				register long MaxZed;
																																																				// address: 0xFFFFFEF0
																																																				auto unsigned int y0x0A;
																																																				// address: 0xFFFFFEF8
																																																				auto unsigned int y0x0B;
																																																				// address: 0xFFFFFF00
																																																				auto unsigned int y0x0C;
																																																				// address: 0xFFFFFF08
																																																				auto unsigned int y0x0D;
																																																				// register: 5
																																																				// size: 0x20
																																																				register struct POLY_FT3 *aft3poly;
																																																				// register: 6
																																																				// size: 0xC
																																																				register struct DR_TWIN *pWinOff;
																																																				// address: 0xFFFFFF70
																																																				// size: 0xC
																																																				auto struct DR_TWIN *pWinOn;
																																																				// register: 2
																																																				register unsigned char *newppoly;
																																																				// register: 7
																																																				register unsigned int *pOTPos;
																																																				{
																																																					{
																																																						// address: 0xFFFFFE70
																																																						// size: 0x8
																																																						auto struct RECT win;
																																																						{
																																																							// address: 0xFFFFFF14
																																																							auto long zed;
																																																							// address: 0x000068E8
																																																							bool SKIPPIXEL;
																																																							{
																																																								{
																																																									// register: 8
																																																									// size: 0xC
																																																									register struct TILE_1 *atile;
																																																									// register: 4
																																																									register unsigned char *newppoly;
																																																									{
																																																										// register: 8
																																																										// size: 0x10
																																																										register struct TILE *atile;
																																																										// register: 4
																																																										register unsigned char *newppoly;
																																																										{
																																																											{
																																																												// register: 17
																																																												// size: 0x28
																																																												register struct Texture *stored;
																																																												// address: 0xFFFFFF1C
																																																												auto long zed;
																																																												// register: 18
																																																												register unsigned int Width;
																																																												// address: 0xFFFFFF9C
																																																												auto int dA;
																																																												// register: 30
																																																												register int Ax;
																																																												// address: 0xFFFFFFCC
																																																												auto int Ay;
																																																												// address: 0xFFFFFFA0
																																																												auto int NeedToTransformA;
																																																												// register: 16
																																																												// size: 0x28
																																																												register struct POLY_FT4 *apoly;
																																																												// register: 4
																																																												register unsigned char *newppoly;
																																																												// register: 2
																																																												register unsigned int foo1;
																																																												// register: 4
																																																												register unsigned int foo2;
																																																												// register: 3
																																																												register unsigned int foo3;
																																																												// address: 0xFFFFFF28
																																																												auto int By0x0;
																																																												// register: 20
																																																												register int Bx;
																																																												// register: 21
																																																												register int By;
																																																												// register: 19
																																																												register int dB;
																																																												// register: 9
																																																												register int A1x;
																																																												// register: 11
																																																												register int A1y;
																																																												// register: 8
																																																												register int A2x;
																																																												// register: 10
																																																												register int A2y;
																																																												// register: 4
																																																												register int B1x;
																																																												// register: 6
																																																												register int B1y;
																																																												// register: 3
																																																												register int B2x;
																																																												// register: 5
																																																												register int B2y;
																																																												// register: 17
																																																												register int dy;
																																																												// register: 18
																																																												register int dx;
																																																												// register: 6
																																																												register int d;
																																																												{
																																																													{
																																																														// address: 0xFFFFFF20
																																																														auto int Ay0x0;
																																																														{
																																																															{
																																																																// register: 3
																																																																register int dydA;
																																																																// register: 2
																																																																register int dxdA;
																																																																{
																																																																	{
																																																																		// register: 3
																																																																		register int dydB;
																																																																		// register: 2
																																																																		register int dxdB;
																																																																	}
																																																																}
																																																															}
																																																														}
																																																													}
																																																												}
																																																											}
																																																										}
																																																									}
																																																								}
																																																							}
																																																						}
																																																					}
																																																				}
																																																			}
																																																		}
																																																	}
																																																}
																																															}
																																														}
																																													}
																																												}
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8003D268
// line start: 3492
// line end:   3495
void ___14CGouraudRibbon(struct CGouraudRibbon *this, int __in_chrg) {
}


// address: 0x8003D2E0
// line start: 3516
// line end:   3545
void CalcScreenNormal__FP11SCalcBufferRiT1i(struct SCalcBuffer *pBuf, int *UnitX, int *UnitY, int ClosenessLimit) {
	// register: 5
	register int xa;
	// register: 6
	register int ya;
	// register: 3
	register int xb;
	// register: 4
	register int yb;
	// register: 3
	register int dx;
	// register: 4
	register int dy;
	// register: 5
	register int l;
}


// address: 0x8003D3F8
// line start: 3550
// line end:   3722
void Display__14CGouraudRibbon(struct CGouraudRibbon *this) {
	// register: 18
	// size: 0x24
	register struct SRibbonPoint *pPoint;
	// register: 17
	// size: 0x1C
	register struct SCalcBuffer *pBuf;
	// address: 0xFFFFFFC0
	auto int LastNormalX;
	// address: 0xFFFFFFC4
	auto int LastNormalY;
	// register: 18
	// size: 0x1C
	register struct SCalcBuffer *pLastBuf;
	// register: 2
	// size: 0x24
	register struct SRibbonPoint *pLastPoint;
	// register: 10
	register int x;
	// register: 8
	register int y;
	// register: 7
	register int dx;
	// register: 6
	register int dy;
	// address: 0xFFFFFFD0
	auto int LastTop;
	// register: 23
	register int LastBottom;
	// address: 0x000076B4
	bool SEEYA;
	{
		// register: 20
		register int i;
		{
			// register: 18
			register int i;
			{
				// address: 0xFFFFFFC8
				auto int TempX;
				// address: 0xFFFFFFCC
				auto int TempY;
				{
					// register: 20
					register int i;
					{
						// register: 9
						register unsigned int *pOTPos;
						{
							{
								// register: 24
								register int NewTop;
								// register: 10
								register int NewBottom;
								// register: 6
								// size: 0x24
								register struct POLY_G4 *pTopPoly;
								// register: 8
								// size: 0x24
								register struct POLY_G4 *pBottomPoly;
								// register: 25
								// size: 0x8
								register struct DR_TPAGE *ptpage;
								// register: 7
								register unsigned char *newppoly;
								// register: 2
								register unsigned int a;
								// register: 4
								register unsigned int b;
								{
									{
										// register: 3
										register unsigned char *newppoly;
										{
											{
												{
													// register: 6
													register int i;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8003D9E0
// size: 0x6C
// line start: 3733
// line end:   3743
struct CTexturedRibbon *__15CTexturedRibbonii(struct CTexturedRibbon *this, int NumPoints, int LeaveTrail) {
	{
		// register: 5
		register int i;
	}
}


// address: 0x8003DAA8
// line start: 3747
// line end:   3750
void ___15CTexturedRibbon(struct CTexturedRibbon *this, int __in_chrg) {
}


// address: 0x8003DB20
// line start: 3754
// line end:   3757
void SetTexture__15CTexturedRibbonUi(struct CTexturedRibbon *this, unsigned int Checksum) {
}


// address: 0x8003DB4C
// line start: 3787
// line end:   4008
void Display__15CTexturedRibbon(struct CTexturedRibbon *this) {
	// register: 19
	// size: 0x24
	register struct SRibbonPoint *pPoint;
	// register: 20
	// size: 0x1C
	register struct SCalcBuffer *pBuf;
	// register: 21
	register int LastNormalX;
	// register: 19
	register int LastNormalY;
	// address: 0xFFFFFFA0
	// size: 0x1C
	auto struct SCalcBuffer *pLastBuf;
	// register: 2
	// size: 0x24
	register struct SRibbonPoint *pLastPoint;
	// register: 8
	register int x;
	// register: 7
	register int y;
	// register: 6
	register int dx;
	// register: 14
	register int dy;
	// register: 11
	register int dxB;
	// register: 10
	register int dyB;
	// address: 0xFFFFFFA4
	auto int LastTop;
	// address: 0xFFFFFFA8
	auto int LastBottom;
	// address: 0xFFFFFFAC
	auto int LastTopB;
	// address: 0xFFFFFFB0
	auto int LastBottomB;
	// address: 0xFFFFFFB4
	auto int voff;
	{
		// register: 21
		register int i;
		{
			// register: 18
			register int i;
			{
				// address: 0xFFFFFFB8
				auto int i;
				{
					// register: 13
					register unsigned int *pOTPos;
					{
						{
							// register: 9
							register int MinZ;
							// address: 0xFFFFFFBC
							auto int NewTop;
							// register: 30
							register int NewBottom;
							// address: 0xFFFFFFC0
							auto int NewTopB;
							// address: 0xFFFFFFC4
							auto int NewBottomB;
							// register: 8
							// size: 0x34
							register struct POLY_GT4 *pTopPoly;
							// register: 10
							// size: 0x34
							register struct POLY_GT4 *pBottomPoly;
							// register: 9
							// size: 0x34
							register struct POLY_GT4 *pTopPolyB;
							// register: 11
							// size: 0x34
							register struct POLY_GT4 *pBottomPolyB;
							// register: 12
							// size: 0xC
							register struct DR_TWIN *pWinOn;
							// register: 7
							// size: 0xC
							register struct DR_TWIN *pWinOff;
							// register: 14
							// size: 0x8
							register struct DR_TPAGE *ptpage;
							// register: 3
							register unsigned char *newppoly;
							// address: 0xFFFFFF98
							// size: 0x8
							auto struct RECT win;
							// register: 5
							register int u;
							// register: 4
							register int v;
							// register: 4
							register unsigned int a;
							// register: 6
							register unsigned int b;
						}
					}
				}
			}
		}
	}
}


// address: 0x8003E620
// line start: 4009
// line end:   4009
void _GLOBAL__I_TotalBitUsage() {
	{
		{
			{
				{
				}
			}
		}
	}
}


// address: 0x8003E628
// line start: 436
// line end:   436
void ___11CWobblyGlow(struct CWobblyGlow *this, int __in_chrg) {
}


// address: 0x8003E678
// line start: 418
// line end:   418
void Move__5CGlow(struct CGlow *this) {
}


// address: 0x8003E680
// line start: 91
// line end:   91
void Display__15CSpecialDisplay(struct CSpecialDisplay *this) {
}


// address: 0x8003E688
// line start: 79
// line end:   79
void Move__4CBit(struct CBit *this) {
}


// address: 0x800441BC
// line start: 59
// line end:   76
void *__nw__5CItemUi(unsigned int size) {
	// register: 5
	register void *pnew;
	// register: 4
	register unsigned int *p;
	{
		// register: 3
		register int i;
	}
}


// address: 0x80044218
// line start: 80
// line end:   87
void __dl__5CItemPv(void *p) {
}


// address: 0x80044238
// size: 0x4C
// line start: 93
// line end:   96
struct CItem *__5CItem(struct CItem *this) {
	{
		{
			{
				{
					{
						{
							{
								// register: 5
								// size: 0x6
								register struct CSVector *this;
								{
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80044268
// line start: 100
// line end:   103
void ___5CItem(struct CItem *this, int __in_chrg) {
}


// address: 0x80044298
// line start: 111
// line end:   122
void InitItem__5CItemPc(struct CItem *this, char *pName) {
}


// address: 0x800442C8
// line start: 126
// line end:   161
void Flash__5CItemiUcUcUc(struct CItem *this, int frames, unsigned char r, unsigned char g, int b) {
}


// address: 0x80044408
// line start: 166
// line end:   186
void FlashUpdate__5CItem(struct CItem *this) {
	{
		{
			// register: 7
			register int r;
			// register: 3
			register int g;
			// register: 2
			register int b;
		}
	}
}


// address: 0x800444B4
// size: 0x108
// line start: 192
// line end:   208
struct CBody_duplicate_s1 *__5CBody(struct CBody_duplicate_s1 *this) {
	{
		{
			{
				{
					{
						{
							{
								{
									{
										{
											{
												{
													{
														{
															{
																{
																	{
																		{
																			{
																				{
																					{
																						{
																							{
																								{
																									{
																										{
																											{
																												{
																													{
																														{
																															{
																																{
																																	{
																																		// register: 3
																																		// size: 0x3
																																		register struct CFriction *this;
																																		{
																																			{
																																				// register: 5
																																				// size: 0x3
																																				register struct CFriction *this;
																																				{
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8004453C
// line start: 215
// line end:   218
void ___5CBody(struct CBody_duplicate_s1 *this, int __in_chrg) {
}


// address: 0x800445B4
// line start: 228
// line end:   234
void AttachTo__5CBodyPP5CBody(struct CBody_duplicate_s1 *this, struct CBody_duplicate_s1 **ppList) {
}


// address: 0x800445E0
// line start: 238
// line end:   260
void DeleteFrom__5CBodyPP5CBody(struct CBody_duplicate_s1 *this, struct CBody_duplicate_s1 **ppList) {
}


// address: 0x80044684
// line start: 266
// line end:   276
short *SquirtPos__5CBodyPs(struct CBody_duplicate_s1 *this, short *p_info) {
}


// address: 0x800446C4
// line start: 282
// line end:   288
short *SquirtAngles__5CBodyPs(struct CBody_duplicate_s1 *this, short *p_info) {
}


// address: 0x800446EC
// line start: 294
// line end:   309
void Suspend__5CBodyPP5CBody(struct CBody_duplicate_s1 *this, struct CBody_duplicate_s1 **ppOriginalList) {
}


// address: 0x80044754
// line start: 313
// line end:   329
void UnSuspend__5CBody(struct CBody_duplicate_s1 *this) {
}


// address: 0x800447B4
// line start: 360
// line end:   362
void ShadowOn__5CBody(struct CBody_duplicate_s1 *this) {
}


// address: 0x800447C8
// line start: 366
// line end:   372
void KillShadow__5CBody(struct CBody_duplicate_s1 *this) {
}


// address: 0x80044818
// line start: 377
// line end:   409
void UpdateShadow__5CBody(struct CBody_duplicate_s1 *this) {
	{
		{
			// address: 0xFFFFFFE8
			// size: 0x8
			auto struct SVECTOR up;
			// register: 3
			register int trans;
			{
				{
					{
						// register: 5
						// size: 0x48
						register struct CBit *this;
						{
						}
					}
				}
			}
		}
	}
}


// address: 0x80044974
// line start: 413
// line end:   418
void Die__5CBody(struct CBody_duplicate_s1 *this) {
}


// address: 0x800449B0
// line start: 421
// line end:   425
int IsDead__C5CBody(struct CBody_duplicate_s1 *this) {
}


// address: 0x800449C4
// line start: 429
// line end:   430
int Hit__5CBodyiRC7CVectori(struct CBody_duplicate_s1 *this, int Damage, struct CVector *knock, int whathit) {
}


// address: 0x800449CC
// size: 0x190
// line start: 434
// line end:   442
struct CSuper *__6CSuper(struct CSuper *this) {
}


// address: 0x80044A28
// line start: 454
// line end:   460
void ___6CSuper(struct CSuper *this, int __in_chrg) {
}


// address: 0x80044AD8
// line start: 466
// line end:   513
void RunAnim__6CSuperiiii(struct CSuper *this, int anim, int from, int to, int to2) {
}


// address: 0x80044BF4
// line start: 520
// line end:   532
void CycleAnim__6CSuperiSc(struct CSuper *this, int anim, char animdir) {
}


// address: 0x80044C40
// line start: 536
// line end:   661
void UpdateFrame__6CSuper(struct CSuper *this) {
	// register: 5
	register int AdjustedSpeed;
	// register: 3
	register int f;
	{
		{
			{
				{
					{
						{
							{
								{
									{
										// register: 6
										register int dif;
										{
											{
												// register: 4
												register int x;
												{
													// register: 4
													register int x;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80044F24
// line start: 697
// line end:   701
void SetAnimOrder__6CSuperUcUc(struct CSuper *this, unsigned char modelId, unsigned char animOrder) {
}


// address: 0x80044F3C
// line start: 705
// line end:   721
void CalculateAnimOrder__6CSuperPPciT1i(struct CSuper *this, char **pAnimHierarchy, int animPartCount, char **pModelHierarchy, int modelPartCount) {
	{
		// register: 18
		register int i;
		{
			{
				// register: 17
				register int j;
			}
		}
	}
}


// address: 0x80045014
// line start: 749
// line end:   818
void InterleaveAI__5CBody(struct CBody_duplicate_s1 *this) {
	{
		{
			{
				{
					{
						// register: 17
						// size: 0x190
						register struct CSuper *this;
						{
							{
								// register: 17
								// size: 0x190
								register struct CSuper *this;
								{
									{
										{
											{
												{
													{
														// register: 17
														// size: 0x190
														register struct CSuper *this;
														{
															{
																// register: 17
																// size: 0x190
																register struct CSuper *this;
																{
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80045394
// line start: 828
// line end:   839
void Ob_ClearInputFlags__FP5CBody(struct CBody_duplicate_s1 *pBody) {
	// register: 3
	// size: 0x108
	register struct CBody_duplicate_s1 *pNext;
}


// address: 0x800453CC
// line start: 851
// line end:   909
void Ob_AI__FPP5CBody(struct CBody_duplicate_s1 **ppBody) {
	// register: 16
	// size: 0x108
	register struct CBody_duplicate_s1 *pBody;
	{
		// register: 20
		// size: 0x108
		register struct CBody_duplicate_s1 *pNext;
		{
			{
				// register: 17
				register unsigned int dist;
				{
					{
						// register: 2
						register unsigned int dist2;
					}
				}
			}
		}
	}
}


// address: 0x80045540
// line start: 917
// line end:   950
void Ob_QuickAI__FPP5CBody(struct CBody_duplicate_s1 **ppBody) {
	// register: 4
	// size: 0x108
	register struct CBody_duplicate_s1 *pBody;
	// register: 16
	// size: 0x108
	register struct CBody_duplicate_s1 *pNext;
}


// address: 0x800455EC
// line start: 964
// line end:   988
void Ob_MaybeUnSuspendOrCull__Fv() {
	// register: 17
	// size: 0x108
	register struct CBody_duplicate_s1 *pBody;
	// register: 19
	// size: 0x108
	register struct CBody_duplicate_s1 *pNext;
	{
		{
			{
				// register: 16
				register unsigned int dist;
				{
					{
						// register: 2
						register unsigned int dist2;
					}
				}
			}
		}
	}
}


// address: 0x800456C4
// line start: 1036
// line end:   1036
void _GLOBAL__I_EnvironmentalObjectList() {
	{
		{
			{
				{
				}
			}
		}
	}
}


// address: 0x800456E4
// line start: 332
// line end:   332
void DeleteStuff__5CBody(struct CBody_duplicate_s1 *this) {
}


// address: 0x800456EC
// line start: 311
// line end:   311
void DoLightingSetup__5CBody(struct CBody_duplicate_s1 *this) {
}


// address: 0x800456F4
// line start: 305
// line end:   305
void EveryFrame__5CBody(struct CBody_duplicate_s1 *this) {
}


// address: 0x800456FC
// line start: 304
// line end:   304
void AI__5CBody(struct CBody_duplicate_s1 *this) {
}


// address: 0x80045704
// line start: 100
// line end:   102
void Trig_ClearTrigMenu__Fv() {
	{
		// register: 4
		register int i;
	}
}


// address: 0x80045730
// line start: 118
// line end:   138
void CreateCommandPoint__FUiUsPUs(unsigned int checksum, unsigned short node, unsigned short *pCommands) {
	// register: 2
	// size: 0x18
	register struct SCommandPoint *pNewCommandPoint;
}


// address: 0x800457D0
// line start: 142
// line end:   154
void Trig_DeleteCommandPoints__Fv() {
	// register: 16
	// size: 0x18
	register struct SCommandPoint *pCP;
	{
		// register: 4
		register int i;
		{
			// register: 16
			// size: 0x18
			register struct SCommandPoint *pNext;
		}
	}
}


// address: 0x80045844
// size: 0x18
// line start: 159
// line end:   170
struct SCommandPoint *GetCommandPoint__Fi(int Node) {
	{
		{
			// register: 3
			// size: 0x18
			register struct SCommandPoint *pCP;
		}
	}
}


// address: 0x800458B8
// line start: 175
// line end:   181
void Trig_ResetCPCollisionFlags__Fi(int Player) {
	// register: 3
	// size: 0x18
	register struct SCommandPoint *pCP;
}


// address: 0x800458F0
// line start: 187
// line end:   194
void Trig_ResetCPExecutedFlags__Fi(int Player) {
	// register: 3
	// size: 0x18
	register struct SCommandPoint *pCP;
}


// address: 0x80045944
// size: 0x18
// line start: 213
// line end:   258
struct SCommandPoint *Trig_TriggerCommandPoint__FUib(unsigned int checksum, bool assert) {
	// register: 16
	// size: 0x18
	register struct SCommandPoint *pSearch;
	{
		{
			{
				// register: 17
				register int Player;
			}
		}
	}
}


// address: 0x800459FC
// line start: 270
// line end:   294
void Trig_SetRestart__FPc(char *pName) {
	{
		// register: 16
		register int i;
		{
			// register: 3
			register short *pNode;
			{
				{
					// address: 0xFFFFFFE0
					// size: 0xC
					auto struct CVector Dummy;
					{
						{
						}
					}
				}
			}
		}
	}
}


// address: 0x80045AA8
// line start: 297
// line end:   332
void FudgeAngles__FP6CBruce(struct CBruce_duplicate_s0 *pBruce) {
	// address: 0xFFFFFFD0
	// size: 0xC
	auto struct CVector Temp1;
	// address: 0xFFFFFFE0
	// size: 0xC
	auto struct CVector Temp2;
	{
		{
			{
				{
				}
			}
		}
	}
}


// address: 0x80045B9C
// line start: 337
// line end:   413
void Trig_ExecuteRestart__Fv() {
	// address: 0xFFFFFFB8
	// size: 0xC
	auto struct CVector StartPos;
	// register: 17
	// size: 0x6
	register struct CSVector *pAngles;
	// register: 16
	// size: 0x108
	register struct CBody_duplicate_s1 *MechListCopy;
	// register: 3
	register char *pName;
	// register: 17
	// size: 0x146C
	register struct CBruce_duplicate_s0 *pMan;
	{
		{
			{
				{
					{
						{
							// register: 16
							register int i;
							{
								// register: 3
								register short *pNode;
								{
									{
										// address: 0xFFFFFFC8
										// size: 0xC
										auto struct CVector Dummy;
										{
											{
												{
													{
														// address: 0xFFFFFFD8
														// size: 0xC
														auto struct CVector StartPos;
														{
															{
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80045DA8
// line start: 421
// line end:   430
void Trig_DeleteTrigFile__Fv() {
}


// address: 0x80045DD8
// line start: 435
// line end:   492
void Trig_LoadTRG__FPc(char *Name) {
	// address: 0xFFFFFFD8
	// size: 0x1E
	auto char Buf[30];
	// register: 2
	register char *p;
	// register: 4
	register char *pFrom;
	// register: 5
	register char *pTo;
	// register: 5
	register unsigned int *pTRG;
	{
		// register: 6
		register int i;
		{
			{
				// register: 4
				register char *pStart;
				// register: 16
				register int newsize;
			}
		}
	}
}


// address: 0x80045F0C
// line start: 574
// line end:   582
unsigned char GetFlag__FUcPUc(unsigned char flag, unsigned char *pFlags) {
}


// address: 0x80045F44
// line start: 586
// line end:   590
char *SkipFlags__FPUc(unsigned char *pFlags) {
}


// address: 0x80045F74
// size: 0x108
// line start: 598
// line end:   738
struct CBody_duplicate_s1 *Trig_CreateObject__Fi(int NodeIndex) {
	// register: 18
	register int Type;
	// register: 20
	register int NotSuspendedAtStart;
	// register: 21
	register int ManualSuspendControl;
	// register: 22
	register int Seedable;
	// register: 17
	// size: 0x108
	register struct CBody_duplicate_s1 *NewObject;
	// register: 16
	register short *pInfo;
	// register: 3
	register int NodeType;
	// address: 0xFFFFFFD0
	// size: 0xC
	auto struct CVector Pos;
	// register: 2
	register unsigned short *pStuff;
	{
		{
			{
				{
					// register: 7
					register int LifeTime;
					{
						{
							{
								{
									{
										// register: 5
										// size: 0x108
										register struct CBody_duplicate_s1 **ppList;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8004622C
// line start: 742
// line end:   825
void Trig_SendPulseToNode__Fi(int NodeIndex) {
	// register: 3
	register short *pNode;
	{
		{
			// register: 2
			// size: 0x18
			register struct SCommandPoint *pCommandPoint;
			{
				// address: 0xFFFFFFE0
				// size: 0xC
				auto struct CVector Pos;
				// register: 16
				register unsigned short *pStuff;
				{
					{
					}
				}
			}
		}
	}
}


// address: 0x800463E8
// line start: 832
// line end:   839
void Trig_SendPulse__FPUs(unsigned short *pLinkInfo) {
	// register: 17
	register unsigned short *pLink;
	// register: 18
	register unsigned short NumLinks;
	{
		// register: 16
		register int i;
	}
}


// address: 0x80046444
// line start: 843
// line end:   863
void KillInList__FiP5CBodyi(int Node, struct CBody_duplicate_s1 *pList, int How) {
}


// address: 0x80046504
// line start: 870
// line end:   1007
void SendVisibleFromNode__Fii(int node, int visible) {
	// register: 17
	register int SetFlags;
	// register: 19
	register int ClearFlags;
	// register: 16
	register unsigned short *pNodes;
	// register: 20
	register unsigned short NumLinks;
	{
		// register: 18
		register int i;
		{
			// register: 5
			register unsigned short VisNode;
			// register: 4
			register short *pVisNode;
			{
				{
					// register: 3
					// size: 0x138
					register struct CPowerUp *pUp;
					// register: 3
					// size: 0x48
					register struct CBit *pBit;
					{
						{
							{
								{
									{
										{
											{
												{
													{
														{
															{
																{
																	{
																		{
																			{
																				// register: 3
																				// size: 0x24
																				register struct Item *pItem;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8004675C
// line start: 1013
// line end:   1147
void SendKillFromNode__Fii(int Node, int How) {
	// register: 18
	register unsigned short *pNodes;
	// register: 21
	register unsigned short NumLinks;
	// register: 5
	register int Bounced;
	{
		// register: 19
		register int i;
		{
			// register: 17
			register unsigned short KillNode;
			// register: 4
			register short *pKillNode;
			// register: 16
			// size: 0x108
			register struct CBody_duplicate_s1 *pList;
			{
				{
					// register: 4
					// size: 0x48
					register struct CBit *pBit;
					{
						{
							{
								{
									{
										{
											// register: 4
											// size: 0x24
											register struct Item *pItem;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80046A08
// line start: 1153
// line end:   1164
void SendSignalToNode__FP5CBodyi(struct CBody_duplicate_s1 *pBody, int NodeIndex) {
}


// address: 0x80046A48
// line start: 1169
// line end:   1199
void SendSignalToLinks__FPUs(unsigned short *pLinkInfo) {
	// register: 18
	register unsigned short *pLink;
	// register: 19
	register unsigned short NumLinks;
	{
		// register: 17
		register int i;
		{
			// register: 16
			register int NodeIndex;
			// register: 4
			register short *pNode;
		}
	}
}


// address: 0x80046B08
// line start: 1203
// line end:   1209
void SendSuspend__FPP5CBodyi(struct CBody_duplicate_s1 **ppList, int NodeIndex) {
	// register: 16
	// size: 0x108
	register struct CBody_duplicate_s1 *pList;
}


// address: 0x80046B70
// line start: 1214
// line end:   1220
void SendUnSuspend__Fi(int NodeIndex) {
	// register: 16
	// size: 0x108
	register struct CBody_duplicate_s1 *pList;
}


// address: 0x80046BCC
// line start: 1226
// line end:   1278
void SendSuspendOrActivate__FPUsi(unsigned short *pLinkInfo, int signaltype) {
	// register: 18
	register unsigned short *pLink;
	// register: 19
	register unsigned short NumLinks;
	{
		// register: 17
		register int i;
		{
			// register: 16
			register int NodeIndex;
			// register: 4
			register short *pNode;
		}
	}
}


// address: 0x80046CBC
// line start: 1282
// line end:   1286
unsigned short *SkipString__FPc(char *pText) {
}


// address: 0x80046CF4
// line start: 1293
// line end:   1393
unsigned short *SkipCommand__FPUs(unsigned short *pCommand) {
	{
		{
			{
				// register: 2
				register unsigned int *p_checksum;
				{
					// register: 2
					register unsigned int *p_checksum;
					{
						{
							// register: 2
							register int *p_pos;
						}
					}
				}
			}
		}
	}
}


// address: 0x8004701C
// line start: 1398
// line end:   1406
void Trig_AllocateDualBuffer__FUi(unsigned int Size) {
}


// address: 0x80047024
// line start: 1409
// line end:   1412
void Trig_RemoveDualBuffer__Fv() {
}


// address: 0x8004704C
// line start: 1423
// line end:   2164
void ExecuteCommandList__FPUsii(unsigned short *pCommands, int Node, int WaitForSpooling) {
	// register: 23
	register int NewFoggingParameters;
	// address: 0xFFFFFFC8
	auto int ZHither;
	// address: 0xFFFFFFCC
	auto int ZDpqMin;
	// address: 0xFFFFFFD0
	auto unsigned int Range;
	// register: 20
	// size: 0x18
	register struct SCommandPoint *pCommandPoint;
	{
		// register: 17
		register unsigned short Command;
		{
			{
				// register: 16
				register int OldRestart;
				{
					{
						// address: 0xFFFFFF98
						// size: 0xC
						auto struct CVector min;
						// address: 0xFFFFFFA8
						// size: 0xC
						auto struct CVector max;
						{
							{
								{
									{
										{
											// register: 16
											register int *p_pos;
											{
												// register: 19
												register unsigned short on;
												// register: 17
												register unsigned short in;
												// address: 0xFFFFFF98
												// size: 0xC
												auto struct CVector min;
												// address: 0xFFFFFFB8
												// size: 0xC
												auto struct CVector max;
												{
													{
														{
															{
																{
																	// register: 16
																	register int *p_pos;
																	{
																		// register: 3
																		register unsigned int *p_checksum;
																		// register: 16
																		register unsigned int checksum;
																		// address: 0xFFFFFF98
																		// size: 0x6
																		auto struct CSVector ang_vel;
																		{
																			{
																				{
																					// register: 2
																					register unsigned int fadecolor;
																					{
																						// register: 2
																						register unsigned int skycolor;
																						{
																							// register: 4
																							register unsigned int *pChecksum;
																							// register: 19
																							register unsigned int Checksum;
																							// register: 21
																							register int GapType;
																							{
																								{
																									{
																										// register: 16
																										register int i;
																										{
																											{
																												{
																													{
																														{
																															// register: 5
																															// size: 0x8
																															register struct SGapTrick *pGapTrick;
																															{
																																{
																																	{
																																		{
																																			{
																																				{
																																					{
																																						{
																																							{
																																								// address: 0xFFFFFF98
																																								// size: 0xC
																																								auto struct CVector StartPos;
																																								// address: 0xFFFFFFA8
																																								// size: 0xC
																																								auto struct CVector BestStartPos;
																																								// register: 17
																																								// size: 0x6
																																								register struct CSVector *pBestAngles;
																																								// register: 16
																																								// size: 0x146C
																																								register struct CBruce_duplicate_s0 *pBruce;
																																								{
																																									{
																																										{
																																											{
																																												{
																																													{
																																														{
																																															{
																																																{
																																																	{
																																																		{
																																																			{
																																																				{
																																																					{
																																																						{
																																																							{
																																																								{
																																																									{
																																																										{
																																																											{
																																																											}
																																																										}
																																																									}
																																																								}
																																																							}
																																																						}
																																																					}
																																																				}
																																																			}
																																																		}
																																																	}
																																																}
																																															}
																																														}
																																													}
																																												}
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80047D3C
// line start: 2168
// line end:   2246
void Trig_InitialParseTRGFile__Fv() {
	// register: 17
	register int Found;
	{
		// register: 16
		register int i;
		{
			// register: 3
			register short *pNode;
			{
				{
					// address: 0xFFFFFFE0
					// size: 0xC
					auto struct CVector Dummy;
					// register: 2
					register char *pNodeName;
					{
						{
							{
								// register: 16
								register int i;
								{
									// register: 3
									register short *pNode;
									{
										{
											// address: 0xFFFFFFE0
											// size: 0xC
											auto struct CVector Dummy;
											// register: 4
											register char *pNodeName;
											{
												{
													{
														{
															{
																// register: 16
																register int i;
																{
																	// register: 3
																	register short *pNode;
																	{
																		{
																			{
																				// register: 16
																				register int i;
																				{
																					// register: 3
																					register short *pNode;
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80047F44
// line start: 2256
// line end:   2375
void Trig_ParseTRGFile__Fv() {
	{
		// register: 17
		register int i;
		{
			// register: 6
			register short *pNode;
			{
				{
					// register: 4
					register unsigned int checksum;
					{
						// address: 0xFFFFFFE0
						// size: 0xC
						auto struct CVector Pos;
						{
							{
								{
									// address: 0x00000764
									// size: 0x4
									static unsigned short CrateCommands[2];
									{
										// address: 0xFFFFFFE0
										// size: 0xC
										auto struct CVector Pos;
										// register: 16
										register unsigned short *pStuff;
										{
											{
												{
													// register: 16
													register int i;
													{
														// register: 3
														register short *pNode;
														{
															{
																// address: 0xFFFFFFE0
																// size: 0xC
																auto struct CVector Dummy;
																// register: 2
																register char *pNodeName;
																{
																	{
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8004827C
// line start: 2381
// line end:   2416
unsigned short *Trig_GetLinksPointer__Fi(int node) {
	// register: 4
	register unsigned short *pNode;
}


// address: 0x80048330
// line start: 2421
// line end:   2493
unsigned short *Trig_GetPosition__FR7CVectori(struct CVector *pos, int node) {
	// register: 5
	register unsigned short *pNode;
	// register: 2
	register unsigned short *pPos;
	// register: 6
	register int *pLong;
	{
		{
			// register: 5
			register unsigned char *pFlags;
		}
	}
}


// address: 0x800484A4
// line start: 134
// line end:   169
void Debug_String__FPciT0(char *p, int line, char *file) {
}


// address: 0x800484AC
// line start: 61
// line end:   105
void Utils_VblankProcessing__Fv() {
	{
		{
			// address: 0xFFFFFFD8
			// size: 0x18
			auto struct POLY_F4 aPoly;
			// address: 0xFFFFFFF0
			// size: 0x8
			auto struct DR_TPAGE ptpage;
		}
	}
}


// address: 0x800485A0
// line start: 116
// line end:   149
void MyVSync__Fv() {
}


// address: 0x80048624
// line start: 160
// line end:   163
void Pause__Fi(int Time) {
	// register: 3
	register int Until;
}


// address: 0x80048658
// line start: 195
// line end:   202
void Utils_InitialRand__Fi(int a) {
}


// address: 0x8004867C
// line start: 207
// line end:   238
int Rnd__Fi(int n) {
}


// address: 0x800486D8
// line start: 246
// line end:   250
void Utils_RotateY__FR7CVectorRC7CVectori(struct CVector *ans, struct CVector *in, int a) {
}


// address: 0x80048764
// line start: 263
// line end:   278
void Utils_CalcUnit__FR7CVectorRC7CVector(struct CVector *Unit, struct CVector *Vec) {
	// address: 0xFFFFFFE0
	// size: 0xC
	auto struct CVector u;
	// register: 6
	register int l;
	{
		// register: 2
		// size: 0xC
		register struct CVector *this;
		{
		}
	}
}


// address: 0x80048854
// line start: 285
// line end:   289
void Utils_GetVecFromMagDir__FR7CVectoriRC8CSVector(struct CVector *v, int r, struct CSVector *a) {
}


// address: 0x80048924
// line start: 294
// line end:   302
unsigned int Utils_Dist__FRC7CVectorT0(struct CVector *a, struct CVector *b) {
	// address: 0xFFFFFFE8
	// size: 0xC
	auto struct CVector u;
	{
		{
		}
	}
}


// address: 0x800489A0
// line start: 307
// line end:   311
unsigned int Utils_XZDist__FRC7CVectorT0(struct CVector *a, struct CVector *b) {
	// register: 3
	register int x;
	// register: 4
	register int z;
}


// address: 0x800489F4
// line start: 317
// line end:   368
unsigned int Utils_CrapDist__FRC7CVectorT0(struct CVector *a, struct CVector *b) {
	// address: 0xFFFFFFF0
	// size: 0xC
	auto struct CVector u;
	{
		{
		}
	}
}


// address: 0x80048B0C
// line start: 395
// line end:   441
int Utils_CalcAim__FR8CSVectorRC7CVectorT1(struct CSVector *Dir, struct CVector *From, struct CVector *To) {
	// register: 17
	register int dx;
	// register: 19
	register int dy;
	// register: 16
	register int dz;
	// register: 16
	register unsigned int d;
}


// address: 0x80048C70
// line start: 450
// line end:   469
void Utils_TurnTowards__FG8CSVectorR8CSVectorT1T0i(struct CSVector Current, struct CSVector *AngVel, struct CSVector *AngAcc, struct CSVector Ideal, int accfactor) {
	// address: 0xFFFFFFF8
	// size: 0x6
	auto struct CSVector angdiff;
	{
		{
		}
	}
}


// address: 0x80048D74
// line start: 673
// line end:   676
void Utils_ClearExplosionStack__Fv() {
}


// address: 0x80048D80
// line start: 768
// line end:   788
int Utils_CompareStrings__FPCcT0Ui(char *pA, char *pB, unsigned int MaxLen) {
	// register: 3
	register char lettera;
	// register: 7
	register char letterb;
}


// address: 0x80048E04
// line start: 792
// line end:   796
void Utils_CopyString__FPCcPc(char *pSource, char *pDest) {
}


// address: 0x80048E28
// line start: 893
// line end:   925
int Utils_ArcCos__Fi(int a) {
	// register: 8
	register int flag;
	// register: 5
	register int d;
	// register: 6
	register int t;
	{
		// register: 2
		register int c;
	}
}


// address: 0x80048EA0
// line start: 931
// line end:   948
int Utils_LineOfSight__FRC7CVectorT0(struct CVector *pos0, struct CVector *pos1) {
	// address: 0xFFFFFF50
	// size: 0xA4
	auto struct SLineInfo line_info;
	{
		// register: 3
		register int _x;
		// register: 6
		register int _y;
		// register: 7
		register int _z;
		{
			// register: 8
			register int _x;
			// register: 9
			register int _y;
			// register: 10
			register int _z;
		}
	}
}


// address: 0x80048F18
// line start: 954
// line end:   974
int Utils_GetGroundHeight__FRC7CVectorii(struct CVector *pos, int above, int below) {
	// address: 0xFFFFFF50
	// size: 0xA4
	auto struct SLineInfo line_info;
}


// address: 0x80048FA8
// line start: 981
// line end:   1010
int Utils_KillObjectsInBox__FRC7CVectorT0P5CBodyb(struct CVector *min, struct CVector *max, struct CBody_duplicate_s1 *p_list, bool use_die) {
	// register: 17
	register int killed;
	{
		// register: 18
		// size: 0x108
		register struct CBody_duplicate_s1 *p_next;
		{
			{
				// address: 0xFFFFFFD0
				// size: 0xC
				auto struct CVector pos;
			}
		}
	}
}


// address: 0x80049110
// line start: 1016
// line end:   1033
int Utils_KillEverythingInBox__FRC7CVectorT0(struct CVector *min, struct CVector *max) {
	// register: 16
	register int killed;
}


// address: 0x800491AC
// line start: 1045
// line end:   1299
void Utils_SetVisibilityInBox__FRC7CVectorT0bT2(struct CVector *min, struct CVector *max, bool visible, bool in) {
	// register: 24
	register int minvx;
	// register: 15
	register int minvy;
	// register: 14
	register int minvz;
	// register: 13
	register int maxvx;
	// register: 12
	register int maxvy;
	// register: 11
	register int maxvz;
	// register: 9
	register int SetFlags;
	// register: 10
	register int ClearFlags;
	// register: 4
	// size: 0x24
	register struct Item *p_item;
	// register: 4
	// size: 0x138
	register struct CPowerUp *pUp;
	// register: 4
	// size: 0x108
	register struct CBody_duplicate_s1 *pSuspended;
	// register: 4
	// size: 0x108
	register struct CBody_duplicate_s1 *pEnvObj;
	// register: 4
	// size: 0x48
	register struct CBit *pBit;
	{
		{
			// register: 3
			register int posvx;
			// register: 8
			register int posvy;
			// register: 5
			register int posvz;
			{
				{
					{
						{
							{
								{
									{
										{
											{
												{
													// register: 4
													// size: 0x64
													register struct CLight *this;
													{
														{
															{
																{
																	{
																		// register: 4
																		// size: 0x64
																		register struct CLight *this;
																		{
																			{
																				{
																					{
																						{
																							{
																								{
																									// register: 4
																									// size: 0x64
																									register struct CLight *this;
																									{
																										{
																											{
																												{
																													{
																														// register: 4
																														// size: 0x64
																														register struct CLight *this;
																														{
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8004970C
// line start: 1344
// line end:   1408
unsigned int Utils_CalculateSpatialAttenuation__FRC7CVectorii(struct CVector *pos, int near, int far) {
	// register: 16
	register int vol;
	// address: 0xFFFFFFC0
	// size: 0xC
	auto struct CVector cam_pos;
	// register: 3
	register int d;
	// address: 0xFFFFFFD0
	// size: 0xC
	auto struct CVector centre;
	// register: 3
	register short heading;
	// register: 5
	register unsigned int behind;
	// register: 4
	register unsigned int left;
	// register: 2
	register unsigned int right;
	{
		// register: 9
		// size: 0xC
		register struct CVector *this;
		{
			{
				{
				}
			}
		}
	}
}


// address: 0x80049980
// line start: 1410
// line end:   1410
void _GLOBAL__I_ExplosionCentre() {
	{
		{
		}
	}
}


// address: 0x800428F4
// line start: 150
// line end:   153
void BoardOff__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x80042954
// line start: 158
// line end:   161
void BoardOn__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x800429B4
// line start: 226
// line end:   254
void GetStats__6CBrucei(struct CBruce_duplicate_s0 *this, int Skater) {
	{
		{
			// register: 7
			register int highest_board;
		}
	}
}


// address: 0x80042B44
// size: 0x146C
// line start: 268
// line end:   464
struct CBruce_duplicate_s0 *__6CBruce(struct CBruce_duplicate_s0 *this) {
	{
		{
			{
				{
					{
						{
							{
								{
									{
										{
											{
												{
													{
														{
															{
																{
																	{
																		{
																			{
																				{
																					{
																						{
																							{
																								{
																									{
																										{
																											{
																												{
																													{
																														{
																															{
																																{
																																	{
																																		{
																																			{
																																				{
																																					{
																																						{
																																							{
																																								// register: 3
																																								// size: 0x6
																																								register struct CSVector *this;
																																								{
																																									{
																																										// register: 2
																																										// size: 0xC
																																										register struct CVector *this;
																																										{
																																											{
																																												{
																																													// register: 3
																																													// size: 0x3
																																													register struct CFriction *this;
																																													{
																																														{
																																															// register: 4
																																															// size: 0x684
																																															register struct CCamera *this;
																																															{
																																															}
																																														}
																																													}
																																												}
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80042F44
// line start: 475
// line end:   504
void ___6CBruce(struct CBruce_duplicate_s0 *this, int __in_chrg) {
	{
	}
}


// address: 0x80043080
// line start: 512
// line end:   521
int History_Checksum__FPci(char *pName, int Spins) {
	// register: 3
	register int c;
	{
		// register: 2
		register int top_bit;
	}
}


// address: 0x800430C8
// line start: 526
// line end:   547
int History_Find__6CBrucePci(struct CBruce_duplicate_s0 *this, char *pName, int Spins) {
	// register: 6
	register int c;
	{
		// register: 3
		register int i;
	}
}


// address: 0x80043134
// line start: 551
// line end:   552
void History_Reset__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x8004313C
// line start: 556
// line end:   583
int History_Add__6CBrucePci(struct CBruce_duplicate_s0 *this, char *pName, int Spins) {
	// register: 16
	register int i;
}


// address: 0x800431EC
// line start: 620
// line end:   631
int GlowTowards__Fiii(int A, int B, int Speed) {
}


// address: 0x8004322C
// line start: 636
// line end:   664
void GlowUpdate__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x80043330
// line start: 669
// line end:   689
void DoLightingSetup__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x80043338
// line start: 694
// line end:   758
void CalculateDynamicLighting__6CBrucePUiP4Item(struct CBruce_duplicate_s0 *this, unsigned int *p_face, struct Item *p_item) {
	{
		{
			// register: 12
			register unsigned int *pColourTable;
			// register: 9
			register int vertices;
			{
				// register: 7
				register int i;
				{
					// register: 5
					register unsigned int rgb;
					{
						// register: 4
						register unsigned int rgb;
					}
				}
			}
		}
	}
}


// address: 0x80043474
// line start: 788
// line end:   794
void ReadAnalogueInput__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x800434B4
// line start: 800
// line end:   802
void GetHookPosition__6CBruceR7CVectorUc(struct CBruce_duplicate_s0 *this, struct CVector *pos, unsigned char hook) {
}


// address: 0x800434E0
// line start: 978
// line end:   986
void Die__6CBruce(struct CBruce_duplicate_s0 *this) {
	{
		// register: 16
		// size: 0x4C
		register struct CItem *this;
		{
		}
	}
}


// address: 0x80043524
// line start: 991
// line end:   994
void DeleteStuff__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x8004352C
// line start: 1002
// line end:   1005
int Hit__6CBruceiRC7CVectori(struct CBruce_duplicate_s0 *this, int Damage, struct CVector *knock, int whathit) {
}


// address: 0x80043534
// line start: 1011
// line end:   1014
void CollideWithObject__6CBruceP5CBody(struct CBruce_duplicate_s0 *this, struct CBody_duplicate_s1 *pOb) {
}


// address: 0x8004353C
// line start: 1032
// line end:   1105
void DoShadowCheck__6CBruce(struct CBruce_duplicate_s0 *this) {
	// address: 0xFFFFFF50
	// size: 0xA4
	auto struct SLineInfo line_info;
	{
		{
			{
				// register: 2
				register int _x;
				// register: 3
				register int _y;
				// register: 4
				register int _z;
				{
					// register: 5
					register int _x;
					// register: 6
					register int _z;
				}
			}
		}
	}
}


// address: 0x800436F0
// line start: 1111
// line end:   1114
void InitItem__6CBrucePc(struct CBruce_duplicate_s0 *this, char *pName) {
}


// address: 0x80043738
// line start: 1120
// line end:   1141
int FlipToVelocity__6CBruce(struct CBruce_duplicate_s0 *this) {
}


// address: 0x80043820
// line start: 1149
// line end:   1251
void BloodSplat__6CBruceii(struct CBruce_duplicate_s0 *this, int BodyPart, int MaxBloodBits) {
	{
		{
			{
				{
					// address: 0xFFFFFF18
					// size: 0x6
					auto struct CSVector v;
					// address: 0xFFFFFF20
					// size: 0xC
					auto struct CVector Pos;
					// address: 0xFFFFFF30
					// size: 0x6
					auto struct CSVector Cone;
					// register: 21
					register int Bits;
					// register: 20
					register int FloorY;
					// address: 0xFFFFFF38
					// size: 0xA4
					auto struct SLineInfo BloodLine;
					{
						{
							{
								{
									{
										{
											{
												{
													{
														{
															{
																{
																	{
																		{
																			{
																				// register: 17
																				register int i;
																				{
																					// register: 16
																					// size: 0x5C
																					register struct CSpark *pSpark;
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80043A74
// line start: 1254
// line end:   1452
void AI__6CBruce(struct CBruce_duplicate_s0 *this) {
	// register: 2
	// size: 0xC0
	register struct SVideoInfo *VInfo;
	// address: 0xFFFFFFD8
	// size: 0xC
	auto struct CVector nearest;
	// register: 2
	// size: 0x108
	register struct CBody_duplicate_s1 *pOb;
	{
		{
			{
				{
					// size: 0x1E
					static char lm[30];
				}
			}
		}
	}
}


// address: 0x80043F38
// line start: 1457
// line end:   1500
void HandleWater__6CBruce(struct CBruce_duplicate_s0 *this) {
	// register: 17
	register int WaterLevel;
	// register: 2
	register int bottom;
	{
		{
			{
				{
					// address: 0xFFFFFFE0
					// size: 0xC
					auto struct CVector p;
					// register: 16
					register int offset;
				}
			}
		}
	}
}


// address: 0x800440E8
// line start: 1505
// line end:   1544
void SFX_Grunt__FP6CBruce(struct CBruce_duplicate_s0 *pSkater) {
}


// address: 0x8004D580
// line start: 103
// line end:   132
void WriteNumber__Fi(int Num) {
	// register: 4
	register int PrintZeros;
	{
		// register: 6
		register int PowerTen;
		{
			{
				{
				}
			}
		}
	}
}


// address: 0x8004D65C
// line start: 138
// line end:   141
void Font_Init__Fv() {
}


// address: 0x8004D690
// line start: 146
// line end:   151
void Font_Reset__Fv() {
}


// address: 0x8004D6B8
// line start: 155
// line end:   167
void Font_String__FUsUsPcUcUcUcUc(unsigned short X, unsigned short Y, char *pString, unsigned char r, int g, int b, int BigText) {
}


// address: 0x8004D71C
// line start: 171
// line end:   185
void Font_Number__FUsUsiUcUcUcUc(unsigned short X, unsigned short Y, int Num, unsigned char r, int g, int b, int BigText) {
}


// address: 0x8004D7A0
// line start: 221
// line end:   392
void Font_Display__Fv() {
	// register: 18
	// size: 0x20
	register struct SString *pStringInfo;
	// register: 17
	register char *CurrentChar;
	// register: 7
	// size: 0x28
	register struct POLY_FT4 *apoly;
	// register: 10
	register int LetterFrame;
	// register: 8
	register int Width;
	// register: 5
	register int Height;
	// register: 9
	register int LetterX;
	// register: 11
	register int LetterY;
	// address: 0xFFFFFF78
	// size: 0xC
	auto struct CVector camera_pos;
	// address: 0xFFFFFFD0
	auto unsigned int ColourInfo;
	{
		{
			{
				// address: 0xFFFFFFBC
				auto long zed;
				// address: 0x000007A8
				bool SKIP;
				{
					{
						// address: 0xFFFFFF88
						// size: 0xC
						auto struct CVector Temp;
						// address: 0xFFFFFFC0
						auto unsigned int y0x0;
						{
							{
								{
									// register: 13
									register char letter;
									{
										{
											// register: 2
											// size: 0x8
											register struct SAnimFrame *pFrame;
											// register: 5
											// size: 0x28
											register struct Texture *stored;
											// register: 3
											register unsigned char *newppoly;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8004DC54
// line start: 410
// line end:   410
void _GLOBAL__I_StringBuffer() {
	{
		{
			{
			}
		}
	}
}


// address: 0x8004DC70
// line start: 124
// line end:   135
char *FileIO_OpenLoad__FPc(char *pName) {
	// register: 16
	register char *pMemory;
}


// address: 0x8004DCD4
// line start: 184
// line end:   221
int CD_There__FPc(char *filename) {
	// register: 5
	register char *header;
	// register: 7
	register char *scan;
	{
		// register: 6
		register char letter;
		// register: 3
		register char checkletter;
	}
}


// address: 0x8004DDC0
// line start: 236
// line end:   238
void FileIO_SetSectorsPerFrame__Fi(int n) {
}


// address: 0x8004DDCC
// line start: 242
// line end:   298
void FileIO_Init__Fv() {
	// address: 0xFFFFFFD8
	// size: 0x18
	auto struct CdlFILE fp;
	// register: 16
	register int nsector;
	{
		{
			// register: 16
			register int i;
			{
				{
					{
						// register: 16
						register int i;
						{
							// register: 16
							register int i;
							{
								{
									// register: 16
									register int i;
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8004DF24
// line start: 338
// line end:   529
int FileIO_Open__FPCc(char *filename) {
	// register: 16
	register char *header;
	// register: 17
	register char *scan;
	// register: 2
	register int len;
	{
		// register: 4
		register char letter;
		// register: 3
		register char checkletter;
		{
			{
				{
					{
						// address: 0xFFFFFFD0
						// size: 0x8
						auto struct RECT rect;
						{
							{
								{
									{
										{
											// address: 0xFFFFFFD0
											// size: 0x8
											auto struct RECT rect;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8004E19C
// line start: 533
// line end:   593
void FileIO_Load__FPv(void *where) {
	// register: 7
	register int Free0;
	// register: 6
	register int Free1;
}


// address: 0x8004E2A8
// line start: 623
// line end:   625
int FileIO_Exists__FPc(char *filename) {
}


// address: 0x8004E2C8
// line start: 667
// line end:   887
void FileIO_Continue__Fv() {
	// register: 16
	register int ReadError;
	// address: 0xFFFFFF88
	// size: 0x64
	auto unsigned char result[100];
	// register: 2
	register int status;
	{
		{
			// address: 0xFFFFFFF0
			// size: 0x8
			auto struct RECT rect;
		}
	}
}


// address: 0x8004E478
// line start: 893
// line end:   910
void FileIO_Sync__Fv() {
}


// address: 0x8004E4C8
// line start: 916
// line end:   917
char *FileIO_GetSubDir__Fv() {
}


// address: 0x8004E4D4
// line start: 921
// line end:   925
void FileIO_SetSubDir__FPc(char *subDir) {
}


// address: 0x8004E4FC
// line start: 42
// line end:   45
void Bang__FUcUcUc(unsigned char r, unsigned char g, unsigned char b) {
	// address: 0x00000008
	// size: 0x8
	static struct RECT bg;
}


// address: 0x8004E528
// line start: 335
// line end:   460
void AddToFreeList__FP12SBlockHeaderi(struct SBlockHeader *pNewFreeBlock, int Heap) {
	// register: 6
	// size: 0x8
	register struct SBlockHeader *pAfter;
	// register: 7
	// size: 0x8
	register struct SBlockHeader *pBefore;
}


// address: 0x8004E650
// line start: 466
// line end:   527
void Mem_Init__Fv() {
	{
		// register: 16
		register int i;
		{
			// register: 6
			// size: 0x8
			register struct SBlockHeader *pAllFreeMem;
		}
	}
}


// address: 0x8004E76C
// line start: 552
// line end:   815
void *Mem_NewX__FUiii(unsigned int size, int Heap, int AssertOnFailure) {
	// register: 16
	// size: 0x8
	register struct SBlockHeader *pBlock;
	// register: 7
	// size: 0x8
	register struct SBlockHeader *pLast;
	{
		{
			// register: 4
			// size: 0x8
			register struct SBlockHeader *pLeftOver;
			{
				// register: 7
				register unsigned int *pMem;
				{
					// register: 6
					register int ii;
					{
						{
							// register: 7
							register unsigned int *pMem;
							{
								// register: 6
								register int ii;
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8004EA08
// line start: 822
// line end:   1066
void *Mem_NewTop__FUi(unsigned int size) {
	// register: 10
	register int Heap;
	// register: 11
	register int AssertOnFailure;
	// register: 7
	// size: 0x8
	register struct SBlockHeader *pBlock;
	// register: 5
	// size: 0x8
	register struct SBlockHeader *pLast;
	// register: 8
	// size: 0x8
	register struct SBlockHeader *pChoice;
	// register: 6
	// size: 0x8
	register struct SBlockHeader *pChoiceLast;
	{
		{
			{
				// register: 7
				register unsigned int *pMem;
				{
					// register: 5
					register int ii;
					{
						{
							// register: 8
							register unsigned int *pMem;
							{
								// register: 7
								register int ii;
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8004EC68
// line start: 1076
// line end:   1157
void Mem_DeleteX__FPv(void *p) {
	// register: 4
	// size: 0x8
	register struct SBlockHeader *pBlock;
}


// address: 0x8004ECFC
// line start: 1168
// line end:   1202
void Mem_ShrinkX__FPvUi(void *p, unsigned int newsize) {
	{
		{
			// register: 4
			// size: 0x8
			register struct SBlockHeader *pNewFreeBlock;
		}
	}
}


// address: 0x8004EDD0
// line start: 1343
// line end:   1350
int Mem_GetBlockSizeX__FPv(void *p) {
}


// address: 0x8004EDDC
// line start: 1404
// line end:   1405
int Mem_GetFree__Fc(char heap) {
}


// address: 0x8004EE18
// line start: 1409
// line end:   1429
void Mem_Copy__FPvT0i(void *dest, void *source, int bytes) {
	// register: 3
	register int num32;
	// register: 6
	register int num8;
	// register: 5
	register unsigned int *s1;
	// register: 4
	register unsigned int *d1;
	// register: 5
	register unsigned char *s2;
	// register: 4
	register unsigned char *d2;
}


// address: 0x8004EE64
// line start: 1545
// line end:   1551
void *Mem_New__FUiii(unsigned int size, int Heap, int AssertOnFailure) {
}


// address: 0x8004EE90
// line start: 1555
// line end:   1557
void Mem_Delete__FPv(void *p) {
}


// address: 0x8004EEB0
// line start: 1561
// line end:   1565
void Mem_Shrink__FPvUi(void *p, unsigned int newsize) {
}


// address: 0x8004EEE0
// line start: 1569
// line end:   1571
int Mem_GetBlockSize__FPv(void *p) {
}


// address: 0x8004A288
// size: 0x10
// line start: 313
// line end:   321
struct TSPack *Pack_GetSlot__Fv() {
}


// address: 0x8004A2C4
// line start: 328
// line end:   333
void Pack_KillSlot__FP6TSPack(struct TSPack *pToFree) {
}


// address: 0x8004A2F8
// size: 0x10
// line start: 340
// line end:   345
struct TSPack *Pack_New__FPP6TSPack(struct TSPack **ppHead) {
	// register: 3
	// size: 0x10
	register struct TSPack *pNew;
}


// address: 0x8004A32C
// size: 0x10
// line start: 352
// line end:   373
struct TSPack *Pack_NewFree__Fiiii(int X, int Y, int W, int H) {
	// register: 3
	// size: 0x10
	register struct TSPack *pNew;
}


// address: 0x8004A38C
// size: 0x10
// line start: 380
// line end:   398
struct TSPack *Pack_NewFull__Fiiii(int X, int Y, int W, int H) {
	// register: 3
	// size: 0x10
	register struct TSPack *pNew;
}


// address: 0x8004A3EC
// line start: 406
// line end:   423
void Pack_Remove__FPP6TSPackP6TSPack(struct TSPack **pHead, struct TSPack *pRemove) {
	// register: 6
	// size: 0x10
	register struct TSPack *pSkip;
}


// address: 0x8004A45C
// line start: 430
// line end:   451
void Pack_Init__Fv() {
}


// address: 0x8004A4B0
// line start: 457
// line end:   475
void Pack_Init640x480__Fv() {
}


// address: 0x8004A508
// size: 0x10
// line start: 489
// line end:   995
struct TSPack *Pack_Pack__FiiiPiT3iiUi(int Type, int WW, int H, int *X, int *Y, int BPP, int Aligned, unsigned int checksum) {
	// register: 18
	// size: 0x10
	register struct TSPack *pBest;
	// register: 17
	// size: 0x10
	register struct TSPack *pPack;
	// register: 23
	// size: 0x10
	register struct TSPack *pNew;
	// register: 20
	register int OX;
	// register: 21
	register int OY;
	// register: 16
	register int OW;
	// register: 17
	register int OH;
	// register: 6
	register int Over;
	// register: 19
	register int W;
	{
		{
			// address: 0xFFFFFFC8
			auto int NewX;
			// address: 0xFFFFFFCC
			auto int NewY;
			// register: 18
			register int OldX;
			// register: 16
			register int OldY;
			// register: 21
			register int OldW;
			// register: 20
			register int OldH;
			{
				// register: 4
				register int RightEdge;
				{
					{
						{
							// register: 7
							register int RightEdge;
							{
								{
									// register: 4
									register int AlignedX;
									// register: 16
									register int AlignedW;
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8004AF54
// line start: 1001
// line end:   1027
void Pack_Unpack__Fss(short X, short Y) {
	// register: 3
	// size: 0x10
	register struct TSPack *pToFree;
	{
		{
			{
				// register: 16
				register int w;
				// register: 17
				register int h;
			}
		}
	}
}


// address: 0x8004B008
// size: 0x10
// line start: 1082
// line end:   1180
struct TSPack *Pack_MergeAdjacent__FP6TSPackT0(struct TSPack *p_first, struct TSPack *p_second) {
	// register: 18
	register int x;
	// register: 19
	register int y;
	// register: 16
	register int w;
	// register: 17
	register int h;
}


// address: 0x8004B210
// line start: 1192
// line end:   1243
int Pack_Merge__FP6TSPack(struct TSPack *p_merge) {
	// register: 4
	// size: 0x10
	register struct TSPack *p_free;
	// register: 16
	register int worth_continuing;
	// register: 8
	register int merged;
}


// address: 0x8004B31C
// line start: 1344
// line end:   1474
void Pack_Zap__Fiiii(int x, int y, int w, int h) {
	// register: 4
	// size: 0x10
	register struct TSPack *p_loop;
	// address: 0x000010C0
	bool REDO;
	{
		{
			{
				{
					{
						{
							// register: 16
							register int half;
							{
								{
									// register: 16
									register int half;
									{
										{
											// register: 16
											register int half;
											{
												{
													// register: 16
													register int half;
													{
														{
															// register: 16
															register int half;
															{
																// register: 16
																register int half;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8004B54C
// line start: 1495
// line end:   1557
void Pack_DefragmentFully__Fv() {
	// register: 16
	// size: 0x10
	register struct TSPack *p_loop;
	// register: 17
	register int Changes;
	{
		// register: 4
		// size: 0x10
		register struct TSPack *p_kill;
		{
			// register: 16
			// size: 0x10
			register struct TSPack *p_merge;
		}
	}
}


// address: 0x8004B6EC
// line start: 56
// line end:   110
void Pal_Init__Fv() {
	// address: 0xFFFFFFE8
	// size: 0x8
	auto struct RECT rec;
	{
		// register: 4
		register int i;
		{
			// register: 4
			register int i;
		}
	}
}


// address: 0x8004B898
// size: 0x14
// line start: 148
// line end:   166
struct tag_S_Pal *NewPaletteEntry__FUi(unsigned int checksum) {
	// register: 4
	// size: 0x14
	register struct tag_S_Pal *pNew;
}


// address: 0x8004B900
// line start: 170
// line end:   177
void RemovePaletteEntry__FP9tag_S_Pal(struct tag_S_Pal *pEntry) {
}


// address: 0x8004B974
// size: 0x14
// line start: 185
// line end:   190
struct tag_S_Pal *Pal_FindPaletteEntry__FUi(unsigned int checksum) {
	// register: 3
	// size: 0x14
	register struct tag_S_Pal *pSearch;
}


// address: 0x8004B9AC
// line start: 194
// line end:   210
void Pal_RemoveUnusedPalettes__Fv() {
	// register: 4
	// size: 0x14
	register struct tag_S_Pal *pPal;
	{
		// register: 16
		// size: 0x14
		register struct tag_S_Pal *pNext;
	}
}


// address: 0x8004BA68
// line start: 215
// line end:   221
int GetFree16Slot__Fv() {
	// register: 4
	register int i;
}


// address: 0x8004BAB8
// line start: 225
// line end:   234
void Free16Slot__FUs(unsigned short clut) {
	// register: 16
	register int i;
}


// address: 0x8004BB1C
// line start: 238
// line end:   244
int GetFree256Slot__Fv() {
	// register: 4
	register int i;
}


// address: 0x8004BB6C
// line start: 248
// line end:   257
void Free256Slot__FUs(unsigned short clut) {
	// register: 16
	register int i;
}


// address: 0x8004BBD0
// line start: 263
// line end:   272
int Get256SlotNumber__FUs(unsigned short clut) {
	// register: 16
	register int i;
}


// address: 0x8004BC24
// size: 0x14
// line start: 306
// line end:   480
struct tag_S_Pal *Pal_LoadPalette__FUiPUiUci(unsigned int checksum, unsigned int *pData, unsigned char flags, int Remap) {
	// register: 17
	// size: 0x14
	register struct tag_S_Pal *pNew;
	// register: 18
	register int transparent_encountered;
	// register: 4
	register unsigned short *pEntry;
	// address: 0xFFFFFFD8
	// size: 0x8
	auto struct RECT rec;
	// register: 19
	register int entries;
	// register: 6
	register int transparent_index;
	{
		// register: 5
		register int i;
		{
			{
				{
					{
						{
							// register: 5
							register int i;
						}
					}
				}
			}
		}
	}
}


// address: 0x8004BE84
// line start: 487
// line end:   513
void Pal_CopyToMemory__FP9tag_S_PalPv(struct tag_S_Pal *p_pal, void *p_buffer) {
	// address: 0xFFFFFFF0
	// size: 0x8
	auto struct RECT rc;
}


// address: 0x8004BF04
// line start: 520
// line end:   530
void Pal_StoreFromMemory__FP9tag_S_PalPv(struct tag_S_Pal *p_pal, void *p_buffer) {
}


// address: 0x8004BF64
// line start: 118
// line end:   145
void SFX_InitAtStart__Fv() {
	// address: 0xFFFFFFD0
	// size: 0x28
	auto struct SpuCommonAttr attr;
	{
		// register: 9
		register int i;
	}
}


// address: 0x8004C00C
// line start: 158
// line end:   176
void SFX_Init__FPc(char *filename) {
	{
		// register: 3
		register int i;
	}
}


// address: 0x8004C07C
// line start: 183
// line end:   206
void SFX_SpoolInLevelSFX__FPCc(char *p_name) {
	// address: 0xFFFFFFE0
	// size: 0x14
	auto char filename[20];
	{
		// register: 7
		register int i;
	}
}


// address: 0x8004C138
// line start: 228
// line end:   229
void SFX_SpoolInMIDI__FPCc(char *p_name) {
}


// address: 0x8004C140
// line start: 232
// line end:   233
void SFX_SpoolOutMIDI__Fv() {
}


// address: 0x8004C148
// line start: 255
// line end:   347
int SFX_OpenVABFile__FPcPPv(char *filename, void **p_soundbuffer) {
	// register: 16
	register int vab_size;
	// register: 17
	register unsigned char *p_buffer;
	// register: 19
	register int headsize;
	// register: 16
	register unsigned int waveform_data_size;
	// register: 18
	register int transfer_address;
	// register: 4
	register unsigned short *p_offset;
	// register: 6
	register unsigned int address;
	{
		// register: 5
		register int w;
		{
			// register: 2
			register int size;
		}
	}
}


// address: 0x8004C258
// line start: 365
// line end:   442
unsigned int SFX_PlayX__FUisi(unsigned int sound, short vol, int pitch_offset) {
	// register: 20
	register bool no_reverb;
	// register: 19
	register bool level_specific;
	// register: 16
	register unsigned int *p_array;
	// register: 7
	register unsigned int vol_mod;
	// register: 5
	register unsigned int pitch;
}


// address: 0x8004C3A8
// line start: 448
// line end:   520
unsigned int SFX_PlayLR__FUissi(unsigned int sound, short vl, short vr, int pitch_offset) {
	// register: 21
	register bool no_reverb;
	// register: 18
	register bool level_specific;
	// register: 7
	register unsigned int *p_array;
	// register: 8
	register unsigned int vol_mod;
	// register: 5
	register unsigned int pitch;
}


// address: 0x8004C50C
// line start: 526
// line end:   623
unsigned int SFX_PlayPos__FUiRC7CVectori(unsigned int sound, struct CVector *pos, int pitch_offset) {
	// register: 19
	register bool no_reverb;
	// register: 18
	register bool level_specific;
	// register: 16
	register unsigned int *p_array;
	// register: 18
	register unsigned int falloff;
	// register: 2
	register unsigned int vol;
	// register: 17
	register unsigned int vol_mod;
	// register: 3
	register int vl_normalised;
	// register: 3
	register int vl;
	// register: 5
	register int vr_normalised;
	// register: 7
	register int vr;
	// register: 5
	register unsigned int pitch;
	// register: 5
	register unsigned int rv;
	{
		// register: 4
		register int i;
	}
}


// address: 0x8004C6C4
// line start: 629
// line end:   649
unsigned short SFX_GetVoicePitch__FUi(unsigned int voice_bf) {
	{
		{
			// address: 0xFFFFFFB8
			// size: 0x40
			auto struct SpuVoiceAttr attr;
		}
	}
}


// address: 0x8004C704
// line start: 652
// line end:   676
void SFX_SetVoicePitch__FUiUs(unsigned int voice_bf, unsigned short pitch) {
	{
		{
			{
				// register: 16
				register int v;
				{
					{
						{
							// address: 0xFFFFFFA8
							// size: 0x40
							auto struct SpuVoiceAttr attr;
						}
					}
				}
			}
		}
	}
}


// address: 0x8004C790
// line start: 680
// line end:   776
void SFX_ModifyPos__FUiRC7CVectori(unsigned int voice_id, struct CVector *pos, int delta_dist) {
	{
		// register: 16
		register int v;
		{
			{
				{
					// address: 0xFFFFFFA0
					// size: 0x40
					auto struct SpuVoiceAttr attr;
					// register: 7
					register unsigned int vol;
					// register: 6
					register unsigned int vol_mod;
					// register: 5
					register int vl_normalised;
					// register: 4
					register int vr_normalised;
					{
						{
							// register: 5
							register int new_pitch;
						}
					}
				}
			}
		}
	}
}


// address: 0x8004C938
// line start: 779
// line end:   816
void SFX_ModifyVol__FUiii(unsigned int voice_id, int vl, int vr) {
	{
		// register: 18
		register int v;
		{
			{
				{
					// address: 0xFFFFFFA8
					// size: 0x40
					auto struct SpuVoiceAttr attr;
				}
			}
		}
	}
}


// address: 0x8004CA74
// line start: 819
// line end:   820
void SFX_ResetMIDIPausedPriorToPause__Fv() {
}


// address: 0x8004CA7C
// line start: 823
// line end:   826
void SFX_LevelStart__Fv() {
}


// address: 0x8004CA88
// line start: 833
// line end:   856
void SFX_Pause__Fv() {
	// address: 0xFFFFFFB0
	// size: 0x40
	auto struct SpuVoiceAttr attr;
	{
		// register: 16
		register int v;
	}
}


// address: 0x8004CB04
// line start: 861
// line end:   884
void SFX_Unpause__Fv() {
	// address: 0xFFFFFFB0
	// size: 0x40
	auto struct SpuVoiceAttr attr;
	{
		// register: 16
		register int v;
	}
}


// address: 0x8004CB78
// line start: 898
// line end:   907
void SFX_StopAll__Fv() {
	{
		// register: 16
		register int i;
	}
}


// address: 0x8004CBBC
// line start: 911
// line end:   927
void SFX_Stop__FUi(unsigned int voice_id) {
}


// address: 0x8004CC04
// line start: 944
// line end:   979
void SFX_SetReverbType__FUc(unsigned char reverb_type) {
	// address: 0xFFFFFFE0
	// size: 0x14
	auto struct SpuReverbAttr attr;
}


// address: 0x8004CC84
// line start: 993
// line end:   995
void SFX_ReverbOff__Fv() {
}


// address: 0x8004CCA4
// line start: 1001
// line end:   1014
void SFX_SetReverbDepth__FUcUc(unsigned char ld, unsigned char rd) {
	// address: 0xFFFFFFE0
	// size: 0x14
	auto struct SpuReverbAttr attr;
}


// address: 0x8004CCDC
// line start: 1023
// line end:   1024
void SFX_MIDIFadeOut__Fi(int ticks) {
}


// address: 0x8004CCE4
// line start: 1027
// line end:   1028
void SFX_MIDIStop__Fv() {
}


// address: 0x8004CCEC
// line start: 1031
// line end:   1032
void SFX_MIDIFadeIn__Fi(int ticks) {
}


// address: 0x8004CCF4
// line start: 1035
// line end:   1036
void SFX_MIDIChannelMute__FUs(unsigned short mute) {
}


// address: 0x8004CCFC
// line start: 1040
// line end:   1207
unsigned int playSFX__FUiUcssiUs(unsigned int sfx, unsigned char pitch, short vl, short vr, int pitch_offset, int volMod) {
	// address: 0xFFFFFFB4
	auto bool looping;
	// address: 0xFFFFFFB8
	auto unsigned short prog;
	// register: 8
	register unsigned short tones;
	// register: 17
	register unsigned short voices;
	// address: 0xFFFFFFBC
	auto int voice_bf;
	{
		{
			{
				// register: 3
				register int t;
				{
					// register: 16
					register int i;
					{
						// register: 2
						register int free;
						{
							{
								// address: 0xFFFFFFA8
								auto unsigned int lzc;
								// register: 10
								register char *p_vab_hdr;
								// address: 0xFFFFFFC0
								auto int tone_start;
								// address: 0xFFFFFF68
								// size: 0x40
								auto struct SpuVoiceAttr attr;
								{
									// register: 20
									register int v;
									{
										{
											{
												{
													// register: 18
													register int t;
													{
														{
															{
																// register: 17
																// size: 0x20
																register struct VagAtr *p_vagatr;
																// register: 4
																register unsigned short *p_offset;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8004D0CC
// line start: 1222
// line end:   1244
int allocateVoice__Fv() {
	{
		// register: 3
		register int i;
	}
}


// address: 0x8004D108
// line start: 1275
// line end:   1336
void SFX_ProcessingPerFrame__Fv() {
	{
		// register: 17
		register int i;
		{
			// address: 0xFFFFFFE8
			auto short env;
		}
	}
}


// address: 0x8004D248
// line start: 1343
// line end:   1434
void SFX_ParseSFXFile__FPcPUiPUsii(char *p_name, unsigned int *array, unsigned short *aliasArray, int maxEntries, int mask) {
	// address: 0xFFFFFFD0
	// size: 0x14
	auto char filename[20];
	// register: 16
	register unsigned char *p_block;
	// register: 9
	register int alias_index;
	{
		// register: 8
		register int i;
		{
			// register: 6
			register unsigned int *p_parse;
			// register: 8
			register int i;
			{
				// register: 7
				register unsigned int val;
				// register: 2
				register unsigned int tone;
				// register: 4
				register unsigned int vol_and_falloff;
			}
		}
	}
}


// address: 0x8004D408
// line start: 1438
// line end:   1453
unsigned int translateLevelSpecificAliasToIndex__FUs(unsigned short alias) {
	{
		// register: 5
		register int i;
		{
			// register: 3
			register unsigned short e;
		}
	}
}


// address: 0x8004D45C
// line start: 1456
// line end:   1471
unsigned int translateGlobalAliasToIndex__FUs(unsigned short alias) {
	{
		// register: 5
		register int i;
		{
			// register: 3
			register unsigned short e;
		}
	}
}


// address: 0x8004D4B0
// line start: 1479
// line end:   1501
unsigned int sfxMalloc__FUi(unsigned int size) {
	{
		// register: 8
		register int i;
	}
}


// address: 0x8004999C
// line start: 98
// line end:   101
int Db_OTSize__Fv() {
}


// address: 0x800499A8
// line start: 105
// line end:   122
void Db_UpdateSky__Fv() {
}


// address: 0x80049A04
// line start: 138
// line end:   194
void Db_CallBack__Fv() {
	{
		// register: 5
		register int i;
	}
}


// address: 0x80049A94
// line start: 199
// line end:   248
void Db_Vblank__Fv() {
	{
		// register: 19
		register int i;
		{
			{
				{
					{
						// register: 17
						register int i;
					}
				}
			}
		}
	}
}


// address: 0x80049C60
// line start: 262
// line end:   298
void Db_WaitRender__Fv() {
}


// address: 0x80049D10
// line start: 308
// line end:   336
void Db_Render__Fv() {
}


// address: 0x80049DE4
// line start: 348
// line end:   351
void Db_InitAtStart__Fv() {
}


// address: 0x80049E08
// line start: 360
// line end:   363
void Db_Reset__Fv() {
}


// address: 0x80049E1C
// line start: 372
// line end:   465
void Db_Init__Fv() {
	// address: 0xFFFFFFD0
	// size: 0x8
	auto struct RECT screen;
	{
		// register: 23
		register int i;
	}
}


// address: 0x8004A128
// line start: 474
// line end:   487
void Db_FlipClear__Fv() {
}


// address: 0x8004A19C
// line start: 495
// line end:   552
void Db_DisplayDraw__Fv() {
	{
		{
			// address: 0xFFFFFFF0
			// size: 0x8
			auto struct RECT r;
		}
	}
}


// address: 0x8004F7D4
// line start: 41
// line end:   43
void CamPt_Init__Fv() {
}


// address: 0x8004F7E0
// line start: 50
// line end:   64
void CamPt_Cleanup__Fv() {
}


// address: 0x8004F810
// line start: 69
// line end:   83
void CamPt_New__Fi(int Node) {
	// address: 0xFFFFFFE8
	// size: 0xC
	auto struct CVector Dummy;
	{
		{
		}
	}
}


// address: 0x8004F85C
// line start: 95
// line end:   396
void CamPt_SetClosestCamera__FP6CBruce(struct CBruce_duplicate_s0 *pSkater) {
	// register: 20
	register unsigned long ClosestDist;
	// register: 23
	register unsigned long ClosestDist2;
	// register: 2
	register unsigned long Dist;
	// register: 19
	register int Index;
	// register: 22
	register int Index2;
	// address: 0xFFFFFF88
	// size: 0xC
	auto struct CVector CamPos;
	// address: 0xFFFFFF98
	// size: 0xC
	auto struct CVector ClosestPos;
	// address: 0xFFFFFFA8
	// size: 0xC
	auto struct CVector ClosestPos2;
	// address: 0xFFFFFFB8
	// size: 0xC
	auto struct CVector AdjustedPlayerPos;
	// register: 18
	// size: 0xC0
	register struct SVideoInfo *VInfo;
	{
		{
			{
				{
					{
						{
							{
								{
									{
										// register: 16
										register int i;
										{
											{
												{
													{
														// address: 0xFFFFFFC8
														// size: 0xC
														auto struct CVector Dummy;
														// register: 2
														register short *pCam;
														// register: 5
														register int Type;
														// register: 22
														register int Param;
														{
															{
																{
																	{
																		// register: 4
																		register int Val;
																		{
																			{
																				{
																					// register: 3
																					// size: 0x684
																					register struct CCamera *this;
																					{
																						{
																							// register: 2
																							// size: 0x684
																							register struct CCamera *this;
																							// register: 21
																							// size: 0x108
																							register struct CBody_duplicate_s1 *focus;
																							{
																								{
																									// register: 3
																									// size: 0x684
																									register struct CCamera *this;
																									// register: 21
																									// size: 0x108
																									register struct CBody_duplicate_s1 *tripod;
																									{
																										{
																											{
																												{
																													{
																														// register: 4
																														// size: 0x684
																														register struct CCamera *this;
																														{
																															{
																																// register: 3
																																// size: 0x684
																																register struct CCamera *this;
																																// register: 21
																																// size: 0x108
																																register struct CBody_duplicate_s1 *focus;
																																{
																																	{
																																		// register: 2
																																		// size: 0x684
																																		register struct CCamera *this;
																																		{
																																			{
																																				{
																																					{
																																						{
																																							{
																																								{
																																									{
																																										{
																																											// register: 4
																																											register int Dist;
																																											// register: 7
																																											register int FogDist;
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8004FF60
// line start: 134
// line end:   198
void Exp_HitEnvItem__FP4ItemPUii(struct Item *pItem, unsigned int *pFace, int Damage) {
	// register: 2
	// size: 0x24
	register struct Item *pScan;
	// register: 3
	// size: 0x24
	register struct SModel *pModel;
	{
		{
			// register: 3
			register unsigned char Life;
		}
	}
}


// address: 0x8005004C
// size: 0x74
// line start: 204
// line end:   220
struct CFlatRipple *__11CFlatRippleRC7CVectoriUcUcUcii(struct CFlatRipple *this, struct CVector *Pos, int MaxRadius, unsigned char r, int g, int b, int NumSegs, int GrowRate) {
	{
		// register: 5
		register int i;
	}
}


// address: 0x80050194
// line start: 224
// line end:   225
void ___11CFlatRipple(struct CFlatRipple *this, int __in_chrg) {
}


// address: 0x800501E4
// line start: 229
// line end:   257
void Move__11CFlatRipple(struct CFlatRipple *this) {
	// register: 9
	register int intensity;
	// register: 8
	register int a;
	{
		// register: 7
		register int i;
	}
}


// address: 0x80050414
// line start: 27
// line end:   29
void TrickOb_Init__Fv() {
}


// address: 0x8005045C
// line start: 38
// line end:   45
void TrickOb_DeleteAll__Fv() {
	// register: 4
	// size: 0x18
	register struct CTrickOb *pTrickOb;
	{
		// register: 16
		// size: 0x18
		register struct CTrickOb *pNext;
	}
}


// address: 0x800504B0
// size: 0x18
// line start: 63
// line end:   90
struct CTrickOb *__8CTrickObUsUs(struct CTrickOb *this, unsigned short Node, unsigned short DelayLevel) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
		// register: 5
		register unsigned short *pNode;
	}
}


// address: 0x80050520
// line start: 100
// line end:   119
void ___8CTrickOb(struct CTrickOb *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
		{
			// register: 7
			// size: 0x18
			register struct CTrickOb *pLast;
			// register: 6
			// size: 0x18
			register struct CTrickOb *pTrickOb;
		}
	}
}


// address: 0x80050598
// line start: 128
// line end:   255
int TrickOb_TrickedOnItem__FP4ItemPvi(struct Item *pItem, void *pB, int Score) {
}


// address: 0x800505A0
// line start: 261
// line end:   296
void TrickOb_DarkenNode__Fi(int NodeIndex) {
	// register: 16
	// size: 0x18
	register struct CTrickOb *pTrickOb;
	{
		{
			{
				{
					{
						{
							// register: 2
							// size: 0x24
							register struct Item *pItem;
						}
					}
				}
			}
		}
	}
}


// address: 0x8005066C
// line start: 340
// line end:   384
void TrickOb_Update__Fv() {
	// register: 6
	// size: 0x18
	register struct CTrickOb *pTrickOb;
	{
		{
			{
				// register: 7
				// size: 0x24
				register struct Item *pItem;
				{
					{
						{
							{
								// register: 5
								register int Red;
								{
									// register: 4
									register int Red;
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8005083C
// line start: 92
// line end:   92
void ___6CClass_addr_8005083C(struct CClass *this, int __in_chrg) {
}


// address: 0x8005086C
// line start: 81
// line end:   92
unsigned short Rail_Flags__FUs(unsigned short Node) {
	// address: 0xFFFFFFE8
	// size: 0xC
	auto struct CVector Dummy;
	// register: 4
	register short *pRailDef;
	{
		{
		}
	}
}


// address: 0x800508A8
// line start: 97
// line end:   107
unsigned short *Rail_FlagsPointer__FUs(unsigned short Node) {
	// address: 0xFFFFFFE8
	// size: 0xC
	auto struct CVector Dummy;
	// register: 5
	register short *pRailDef;
	{
		{
		}
	}
}


// address: 0x800508E4
// line start: 114
// line end:   123
int Rail_IsRailNode__FUs(unsigned short Node) {
	{
		{
		}
	}
}


// address: 0x80050964
// line start: 129
// line end:   135
unsigned short Rail_GetLink__FUss(unsigned short Node, short Link) {
}


// address: 0x8005099C
// line start: 141
// line end:   146
unsigned short Rail_NumLinks__FUs(unsigned short Node) {
}


// address: 0x800509C0
// line start: 153
// line end:   171
unsigned short Rail_NextNode__FUs(unsigned short Node) {
	// register: 18
	register unsigned short Links;
	// register: 19
	register int NextRailNode;
	{
		// register: 17
		register int Link;
		{
			{
				{
				}
			}
		}
	}
}


// address: 0x80050A74
// line start: 177
// line end:   194
unsigned short Rail_PrevNode__FUs(unsigned short Node) {
	{
		// register: 17
		register int Prev;
	}
}


// address: 0x80050AF8
// line start: 200
// line end:   231
void Rail_KillRail__Fi(int node) {
	{
		// register: 16
		// size: 0x28
		register struct CRail *pRail;
		{
			// register: 2
			register int CurrentNode;
			// register: 4
			register int NextNode;
		}
	}
}


// address: 0x80050B98
// line start: 246
// line end:   253
int GetIndexOfNode__FUs(unsigned short node) {
	{
		// register: 3
		register int r;
	}
}


// address: 0x80050BFC
// line start: 257
// line end:   279
void SetupLookup__Fv() {
	// register: 16
	register unsigned short r;
	{
		// register: 17
		register unsigned short n;
		{
			{
				// register: 2
				register int next_r;
			}
		}
	}
}


// address: 0x80050CF8
// line start: 289
// line end:   380
void Rail_CreateRails__Fv() {
	// register: 16
	register unsigned short Prev;
	// register: 18
	register unsigned short First;
	// register: 21
	register int rail_num;
	{
		// register: 5
		register unsigned short Node;
		{
			// register: 19
			register unsigned short Node;
			{
				// register: 20
				register int is_rail_node;
				{
					{
						// register: 4
						register int r;
					}
				}
			}
		}
	}
}


// address: 0x80050EC4
// line start: 420
// line end:   423
void Rail_Init__Fv() {
}


// address: 0x80050F0C
// line start: 428
// line end:   435
void Rail_DeleteAll__Fv() {
	// register: 4
	// size: 0x28
	register struct CRail *pRail;
	{
		// register: 16
		// size: 0x28
		register struct CRail *pNext;
	}
}


// address: 0x80050F60
// size: 0x28
// line start: 442
// line end:   699
struct CRail *__5CRaili(struct CRail *this, int node_index) {
	// register: 17
	// size: 0x4
	register struct CClass *this;
	{
		{
			{
				{
					{
						// address: 0xFFFFFEC0
						// size: 0xC
						auto struct CVector NodePos;
						// register: 16
						register int CurrentNode;
						{
							{
								{
									// register: 18
									register unsigned short NextNode;
									{
										{
											// address: 0xFFFFFED0
											// size: 0xC
											auto struct CVector StartPos;
											// address: 0xFFFFFEE0
											// size: 0xC
											auto struct CVector EndPos;
											// address: 0xFFFFFEF0
											// size: 0xC
											auto struct CVector MidPos;
											// address: 0xFFFFFF00
											// size: 0xC
											auto struct CVector Stick;
											// register: 3
											register int temp;
											// address: 0xFFFFFF20
											// size: 0xA4
											auto struct SLineInfo line_info;
											{
												{
													{
														{
															{
																{
																	{
																		{
																			{
																				{
																					// register: 2
																					register unsigned short *pFlags;
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80051568
// line start: 711
// line end:   725
void ___5CRail(struct CRail *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x800515EC
// line start: 729
// line end:   1149
void Rail_Update__Fv() {
	// address: 0xFFFFFF90
	auto int s;
	// address: 0xFFFFFF94
	auto int t;
	// address: 0xFFFFFFA4
	auto int SkaterMin_vx;
	// address: 0xFFFFFFA8
	auto int SkaterMin_vy;
	// address: 0xFFFFFFAC
	auto int SkaterMin_vz;
	// address: 0xFFFFFFB0
	auto int SkaterMax_vx;
	// address: 0xFFFFFFB4
	auto int SkaterMax_vy;
	// address: 0xFFFFFFB8
	auto int SkaterMax_vz;
	// address: 0xFFFFFE18
	// size: 0xC
	auto struct CVector SegMin;
	// address: 0xFFFFFE28
	// size: 0xC
	auto struct CVector SegMax;
	// address: 0xFFFFFE38
	// size: 0xC
	auto struct CVector SegFrom;
	// address: 0xFFFFFE48
	// size: 0xC
	auto struct CVector SegTo;
	// address: 0xFFFFFE58
	// size: 0xC
	auto struct CVector SkaterPos;
	// address: 0xFFFFFE68
	// size: 0xC
	auto struct CVector RailPos;
	{
		{
			{
				{
					{
						{
							{
								{
									{
										{
											{
												{
													{
														// register: 18
														// size: 0x108
														register struct CBody_duplicate_s1 *MLCopy;
														{
															// address: 0xFFFFFFBC
															// size: 0x146C
															auto struct CBruce_duplicate_s0 *pSkater;
															{
																// register: 21
																// size: 0x28
																register struct CRail *pRail;
																{
																	// register: 22
																	register int CurrentNode;
																	// register: 30
																	register int NextNode;
																	// register: 23
																	register int Dist;
																	{
																		{
																			{
																				{
																					{
																						{
																							{
																								{
																									// address: 0xFFFFFE78
																									// size: 0xC
																									auto struct CVector SegDir;
																									// address: 0xFFFFFE88
																									// size: 0xC
																									auto struct CVector SkaterVel;
																									// register: 4
																									register int VelocityDotSegment;
																									// register: 16
																									register int End;
																									{
																										{
																											// address: 0xFFFFFE98
																											// size: 0xC
																											auto struct CVector SkaterVel;
																											{
																												{
																													// address: 0xFFFFFE98
																													// size: 0xC
																													auto struct CVector StartPos;
																													// address: 0xFFFFFEA8
																													// size: 0xC
																													auto struct CVector EndPos;
																													// address: 0xFFFFFEB8
																													// size: 0xC
																													auto struct CVector MidPos;
																													// address: 0xFFFFFEC8
																													// size: 0xC
																													auto struct CVector Stick;
																													// register: 3
																													register int temp;
																													// address: 0xFFFFFEE8
																													// size: 0xA4
																													auto struct SLineInfo line_info;
																													// register: 16
																													register int leftside;
																													// register: 3
																													register int rightside;
																													{
																														{
																															{
																																{
																																	{
																																		{
																																			{
																																				{
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80051EDC
// line start: 92
// line end:   92
void ___6CClass_addr_80051EDC(struct CClass *this, int __in_chrg) {
}


// address: 0x8004EF00
// line start: 15
// line end:   26
int Length__C7CVector(struct CVector *this) {
	// address: 0xFFFFFFE8
	// size: 0xC
	auto struct CVector u;
	{
		{
		}
	}
}


// address: 0x8004EF80
// line start: 45
// line end:   52
void Normalize__7CVector(struct CVector *this) {
	// register: 2
	register int length;
}


// address: 0x8004EFE0
// line start: 56
// line end:   59
void KillSmall__7CVector(struct CVector *this) {
}


// address: 0x8004F03C
// size: 0xC
// line start: 63
// line end:   67
struct CVector *__apl__7CVectorRC7CVector(struct CVector *this, struct CVector *a) {
}


// address: 0x8004F078
// size: 0xC
// line start: 71
// line end:   75
struct CVector *__ami__7CVectorRC7CVector(struct CVector *this, struct CVector *a) {
}


// address: 0x8004F0B4
// size: 0xC
// line start: 79
// line end:   83
struct CVector *__aml__7CVectorRCi(struct CVector *this, int *a) {
}


// address: 0x8004F104
// size: 0xC
// line start: 87
// line end:   91
struct CVector *__adv__7CVectorRCi(struct CVector *this, int *a) {
}


// address: 0x8004F154
// size: 0xC
// line start: 95
// line end:   99
struct CVector *__ars__7CVectorRCi(struct CVector *this, int *a) {
}


// address: 0x8004F190
// size: 0xC
// line start: 103
// line end:   107
struct CVector *__als__7CVectorRCi(struct CVector *this, int *a) {
}


// address: 0x8004F1CC
// size: 0xC
// line start: 112
// line end:   116
struct CVector *__amd__7CVectorRC9CFriction(struct CVector *this, struct CFriction *f) {
}


// address: 0x8004F218
// line start: 120
// line end:   121
bool __eq__7CVectorRC7CVector(struct CVector *this, struct CVector *v) {
}


// address: 0x8004F25C
// line start: 125
// line end:   126
bool __ne__7CVectorRC7CVector(struct CVector *this, struct CVector *v) {
}


// address: 0x8004F2A4
// size: 0xC
// line start: 130
// line end:   136
struct CVector __pl__FRC7CVectorT0(struct CVector *a, struct CVector *b) {
	// address: 0xFFFFFFF0
	// size: 0xC
	auto struct CVector ans;
	{
		{
		}
	}
}


// address: 0x8004F2FC
// size: 0xC
// line start: 139
// line end:   145
struct CVector __mi__FRC7CVectorT0(struct CVector *a, struct CVector *b) {
	// address: 0xFFFFFFF0
	// size: 0xC
	auto struct CVector ans;
	{
		{
		}
	}
}


// address: 0x8004F354
// size: 0xC
// line start: 148
// line end:   154
struct CVector __ml__FRC7CVectorRCi(struct CVector *a, int *scalar) {
	// address: 0xFFFFFFF0
	// size: 0xC
	auto struct CVector ans;
	{
		{
		}
	}
}


// address: 0x8004F3BC
// size: 0xC
// line start: 157
// line end:   163
struct CVector __ml__FRCiRC7CVector(int *scalar, struct CVector *a) {
	// address: 0xFFFFFFF0
	// size: 0xC
	auto struct CVector ans;
	{
		{
		}
	}
}


// address: 0x8004F424
// size: 0xC
// line start: 166
// line end:   172
struct CVector __dv__FRC7CVectorRCi(struct CVector *a, int *scalar) {
	// address: 0xFFFFFFF0
	// size: 0xC
	auto struct CVector ans;
	{
		{
		}
	}
}


// address: 0x8004F48C
// size: 0xC
// line start: 175
// line end:   181
struct CVector __rs__FRC7CVectorRCi(struct CVector *a, int *scalar) {
	// address: 0xFFFFFFF0
	// size: 0xC
	auto struct CVector ans;
	{
		{
		}
	}
}


// address: 0x8004F4DC
// size: 0xC
// line start: 184
// line end:   190
struct CVector __ls__FRC7CVectorRCi(struct CVector *a, int *scalar) {
	// address: 0xFFFFFFF0
	// size: 0xC
	auto struct CVector ans;
	{
		{
		}
	}
}


// address: 0x8004F52C
// size: 0xC
// line start: 193
// line end:   195
struct CVector __mi__C7CVector(struct CVector *this) {
	{
		// register: 2
		// size: 0xC
		register struct CVector *this;
		{
		}
	}
}


// address: 0x8004F558
// line start: 213
// line end:   216
void Mask__8CSVector(struct CSVector *this) {
}


// address: 0x8004F580
// line start: 220
// line end:   223
void KillSmall__8CSVector(struct CSVector *this) {
}


// address: 0x8004F5E8
// size: 0x6
// line start: 241
// line end:   245
struct CSVector *__apl__8CSVectorRC8CSVector(struct CSVector *this, struct CSVector *a) {
}


// address: 0x8004F624
// size: 0x6
// line start: 265
// line end:   269
struct CSVector *__adv__8CSVectorRCi(struct CSVector *this, int *a) {
}


// address: 0x8004F674
// size: 0x6
// line start: 289
// line end:   293
struct CSVector *__amd__8CSVectorRC9CFriction(struct CSVector *this, struct CFriction *f) {
}


// address: 0x8004F6C4
// size: 0x6
// line start: 336
// line end:   342
struct CSVector __mi__FRC8CSVectorT0(struct CSVector *a, struct CSVector *b) {
	// address: 0xFFFFFFF8
	// size: 0x6
	auto struct CSVector ans;
	{
		{
		}
	}
}


// address: 0x8004F71C
// size: 0x6
// line start: 354
// line end:   360
struct CSVector __ml__FRCiRC8CSVector(int *scalar, struct CSVector *a) {
	// address: 0xFFFFFFF8
	// size: 0x6
	auto struct CSVector ans;
	{
		{
		}
	}
}


// address: 0x8004F784
// size: 0x6
// line start: 372
// line end:   378
struct CSVector __rs__FRC8CSVectorRCi(struct CSVector *a, int *scalar) {
	// address: 0xFFFFFFF8
	// size: 0x6
	auto struct CSVector ans;
	{
		{
		}
	}
}


// address: 0x8005A090
// line start: 19
// line end:   22
void Init__7Spooler() {
}


// address: 0x8005A0C0
// line start: 29
// line end:   34
void Cleanup__7Spooler() {
}


// address: 0x8005A0FC
// line start: 52
// line end:   74
void OrderHelper__7SpoolerPiii(int *array, int num, int first) {
	// register: 6
	register int bottom;
	// register: 7
	register int top;
	// register: 3
	register int n;
}


// address: 0x8005A154
// size: 0x810
// line start: 82
// line end:   93
struct Spooler *__7Spooler(struct Spooler *this) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
		{
			// register: 7
			register int i;
		}
	}
}


// address: 0x8005A1B0
// line start: 100
// line end:   102
void ___7Spooler(struct Spooler *this, int __in_chrg) {
	// register: 17
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x8005A200
// line start: 111
// line end:   134
void Reset__7Spooler(struct Spooler *this) {
	{
		// register: 16
		register int i;
	}
}


// address: 0x8005A2C4
// line start: 141
// line end:   171
int AddFile__7SpoolerPci(struct Spooler *this, char *filename, int ignoreExt) {
	// register: 16
	register int n;
}


// address: 0x8005A3E8
// line start: 178
// line end:   182
void Spooool__7Spooler(struct Spooler *this) {
}


// address: 0x8005A418
// line start: 189
// line end:   192
bool IsSetDone__7Spooler(struct Spooler *this) {
}


// address: 0x8005A430
// line start: 199
// line end:   237
void Update__7Spooler(struct Spooler *this) {
}


// address: 0x8005A504
// line start: 243
// line end:   265
void BeginSpoolingCurrentFile__7Spooler(struct Spooler *this) {
	{
		{
			{
			}
		}
	}
}


// address: 0x8005A5D0
// line start: 295
// line end:   298
bool IsFileLoaded__7Spooleri(struct Spooler *this, int id) {
}


// address: 0x8005A5E4
// line start: 316
// line end:   323
void *GetFile__7Spooleri(struct Spooler *this, int id) {
	// register: 2
	register unsigned char *pData;
}


// address: 0x8005A604
// line start: 330
// line end:   355
void KillFile__7Spooleri(struct Spooler *this, int slot) {
}


// address: 0x8005A6B8
// line start: 92
// line end:   92
void ___6CClass_addr_8005A6B8(struct CClass *this, int __in_chrg) {
}


// address: 0x80051F0C
// line start: 24
// line end:   26
void FaceRemoval_Setup__Fv() {
}


// address: 0x80051F38
// line start: 33
// line end:   35
void FaceRemoval_Cleanup__Fv() {
}


// address: 0x80051F5C
// size: 0x18
// line start: 42
// line end:   51
struct FP *NewFP__Fv() {
}


// address: 0x80051F94
// line start: 58
// line end:   60
void ResetFPList__Fv() {
}


// address: 0x80051FA8
// line start: 108
// line end:   340
int GetEmbeddedArea__FP2FPT0(struct FP *points1, struct FP *points2) {
	// address: 0xFFFFFFC8
	// size: 0x8
	auto struct FP *points[2];
	// register: 19
	// size: 0x18
	register struct FP *start;
	// address: 0xFFFFFFD0
	auto int other_face;
	// register: 8
	// size: 0x18
	register struct FP *other_first;
	// register: 5
	// size: 0x18
	register struct FP *t;
	{
		// register: 30
		register int face;
		{
			// register: 21
			// size: 0x18
			register struct FP *A;
			// register: 18
			// size: 0x18
			register struct FP *B;
			// register: 16
			// size: 0x18
			register struct FP *t1;
			{
				// register: 17
				// size: 0x18
				register struct FP *t2;
				{
					// register: 2
					// size: 0x18
					register struct FP *list;
					{
						{
							// register: 4
							// size: 0x18
							register struct FP *temp;
							{
								// register: 4
								// size: 0x18
								register struct FP *other;
								// register: 6
								register bool shared;
								{
									{
										{
											// register: 5
											// size: 0x18
											register struct FP *point1;
											// register: 4
											// size: 0x18
											register struct FP *point2;
											{
												// register: 2
												register int diffz;
												// register: 2
												register int diffy;
												// register: 2
												register int diffx;
												{
													{
														{
															// register: 4
															// size: 0x18
															register struct FP *point1;
															// register: 19
															// size: 0x18
															register struct FP *point2;
															{
																// register: 2
																register int diffz;
																// register: 2
																register int diffy;
																// register: 2
																register int diffx;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x800522C8
// line start: 346
// line end:   365
int GetArea__FP2FP(struct FP *list) {
	// register: 7
	register int area;
	// register: 3
	// size: 0x18
	register struct FP *point;
}


// address: 0x8005232C
// size: 0x18
// line start: 393
// line end:   571
struct FP *GetIntersection__FP2FPT0(struct FP *first1, struct FP *first2) {
	// register: 19
	// size: 0x18
	register struct FP *add1;
	// register: 21
	// size: 0x18
	register struct FP *add2;
	// register: 16
	// size: 0xC
	register struct Vector *b;
	// address: 0xFFFFFF98
	// size: 0xC
	auto struct Vector *c;
	// address: 0xFFFFFF9C
	// size: 0xC
	auto struct Vector *d;
	// register: 9
	register int cross1;
	// register: 7
	register int cross2;
	// register: 5
	register int cross3;
	// register: 3
	register int cross4;
	// register: 8
	register char test1;
	// register: 7
	register char test2;
	// register: 5
	register int r_num;
	// register: 4
	register int r_dnom;
	{
		// register: 16
		// size: 0xC
		register struct Vector *a1;
		// register: 16
		// size: 0xC
		register struct Vector *b0;
		// address: 0xFFFFFF98
		// size: 0xC
		auto struct Vector *b1;
		{
			{
				// register: 16
				// size: 0xC
				register struct Vector *a1;
				// register: 16
				// size: 0xC
				register struct Vector *b0;
				// address: 0xFFFFFF9C
				// size: 0xC
				auto struct Vector *b1;
				{
					{
						// address: 0xFFFFFF98
						// size: 0xC
						auto struct Vector *a0;
						// address: 0xFFFFFF9C
						// size: 0xC
						auto struct Vector *a1;
						// address: 0xFFFFFF9C
						// size: 0xC
						auto struct Vector *b0;
						{
							{
								// address: 0xFFFFFF98
								// size: 0xC
								auto struct Vector *a0;
								// address: 0xFFFFFF9C
								// size: 0xC
								auto struct Vector *a1;
								// address: 0xFFFFFF9C
								// size: 0xC
								auto struct Vector *b0;
								// register: 16
								// size: 0xC
								register struct Vector *b1;
								{
									{
										{
											// register: 7
											register int abc;
											// register: 9
											register int abd;
											// register: 4
											register int bac;
											// register: 6
											register int bad;
											// register: 8
											register int cda;
											// register: 10
											register int cdb;
											// register: 3
											register int dca;
											// register: 5
											register int dcb;
											{
												// register: 16
												// size: 0xC
												register struct Vector *a1;
												// register: 16
												// size: 0xC
												register struct Vector *b0;
												// address: 0xFFFFFF98
												// size: 0xC
												auto struct Vector *b1;
												{
													// register: 7
													register int dot;
													{
														// register: 16
														// size: 0xC
														register struct Vector *a1;
														// register: 16
														// size: 0xC
														register struct Vector *b0;
														// address: 0xFFFFFF9C
														// size: 0xC
														auto struct Vector *b1;
														{
															// register: 9
															register int dot;
															{
																// register: 16
																// size: 0xC
																register struct Vector *a0;
																// address: 0xFFFFFF98
																// size: 0xC
																auto struct Vector *b1;
																{
																	// register: 4
																	register int dot;
																	{
																		// register: 16
																		// size: 0xC
																		register struct Vector *a0;
																		// address: 0xFFFFFF9C
																		// size: 0xC
																		auto struct Vector *b1;
																		{
																			// register: 6
																			register int dot;
																			{
																				// address: 0xFFFFFF98
																				// size: 0xC
																				auto struct Vector *a0;
																				// address: 0xFFFFFF9C
																				// size: 0xC
																				auto struct Vector *a1;
																				// address: 0xFFFFFF9C
																				// size: 0xC
																				auto struct Vector *b0;
																				{
																					// register: 8
																					register int dot;
																					{
																						// address: 0xFFFFFF98
																						// size: 0xC
																						auto struct Vector *a0;
																						// address: 0xFFFFFF9C
																						// size: 0xC
																						auto struct Vector *a1;
																						// address: 0xFFFFFF9C
																						// size: 0xC
																						auto struct Vector *b0;
																						// register: 16
																						// size: 0xC
																						register struct Vector *b1;
																						{
																							// register: 10
																							register int dot;
																							{
																								// address: 0xFFFFFF9C
																								// size: 0xC
																								auto struct Vector *a0;
																								// address: 0xFFFFFF98
																								// size: 0xC
																								auto struct Vector *a1;
																								// address: 0xFFFFFF98
																								// size: 0xC
																								auto struct Vector *b0;
																								{
																									// register: 3
																									register int dot;
																									{
																										// address: 0xFFFFFF9C
																										// size: 0xC
																										auto struct Vector *a0;
																										// address: 0xFFFFFF98
																										// size: 0xC
																										auto struct Vector *a1;
																										// address: 0xFFFFFF98
																										// size: 0xC
																										auto struct Vector *b0;
																										// register: 16
																										// size: 0xC
																										register struct Vector *b1;
																										{
																											// register: 5
																											register int dot;
																											{
																												{
																													// register: 19
																													// size: 0x18
																													register struct FP *point1;
																													// size: 0x18
																													auto struct FP *point2;
																													{
																														// register: 2
																														register int diffz;
																														// register: 2
																														register int diffy;
																														// register: 2
																														register int diffx;
																														{
																															// register: 19
																															// size: 0x18
																															register struct FP *point1;
																															// register: 4
																															// size: 0x18
																															register struct FP *point2;
																															{
																																// register: 2
																																register int diffz;
																																// register: 2
																																register int diffy;
																																// register: 2
																																register int diffx;
																																{
																																	{
																																		// register: 21
																																		// size: 0x18
																																		register struct FP *point1;
																																		// size: 0x18
																																		auto struct FP *point2;
																																		{
																																			// register: 2
																																			register int diffz;
																																			// register: 2
																																			register int diffy;
																																			// register: 2
																																			register int diffx;
																																			{
																																				// register: 21
																																				// size: 0x18
																																				register struct FP *point1;
																																				// register: 4
																																				// size: 0x18
																																				register struct FP *point2;
																																				{
																																					// register: 2
																																					register int diffz;
																																					// register: 2
																																					register int diffy;
																																					// register: 2
																																					register int diffx;
																																					{
																																						{
																																							// size: 0x18
																																							auto struct FP *point1;
																																							// address: 0x00000004
																																							// size: 0x18
																																							auto struct FP *point2;
																																							{
																																								// register: 2
																																								register int diffz;
																																								// register: 2
																																								register int diffy;
																																								// register: 2
																																								register int diffx;
																																								{
																																									// size: 0x18
																																									auto struct FP *point1;
																																									// register: 6
																																									// size: 0x18
																																									register struct FP *point2;
																																									{
																																										// register: 2
																																										register int diffz;
																																										// register: 2
																																										register int diffy;
																																										// register: 2
																																										register int diffx;
																																										{
																																											// address: 0x00000004
																																											// size: 0x18
																																											auto struct FP *point2;
																																											{
																																												// register: 2
																																												register int diffz;
																																												// register: 2
																																												register int diffy;
																																												// register: 2
																																												register int diffx;
																																												{
																																													{
																																														// register: 2
																																														register int diffz;
																																														// register: 2
																																														register int diffy;
																																														// register: 2
																																														register int diffx;
																																														{
																																															{
																																																// register: 19
																																																// size: 0x18
																																																register struct FP *point1;
																																																// size: 0x18
																																																auto struct FP *point2;
																																																{
																																																	// register: 2
																																																	register int diffz;
																																																	// register: 2
																																																	register int diffy;
																																																	// register: 7
																																																	register int diffx;
																																																	{
																																																		// register: 19
																																																		// size: 0x18
																																																		register struct FP *point1;
																																																		// register: 4
																																																		// size: 0x18
																																																		register struct FP *point2;
																																																		{
																																																			// register: 2
																																																			register int diffz;
																																																			// register: 2
																																																			register int diffy;
																																																			// register: 2
																																																			register int diffx;
																																																		}
																																																	}
																																																}
																																															}
																																														}
																																													}
																																												}
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80052D28
// line start: 371
// line end:   373
int CrossProduct__FR6VectorN30(struct Vector *a0, struct Vector *a1, struct Vector *b0, struct Vector *b1) {
}


// address: 0x80052D70
// line start: 34
// line end:   40
void InitPolyBuf__13EditorInModelb(bool game_build) {
	// register: 3
	register int buf_size;
	// register: 3
	register int num_entries;
}


// address: 0x80052DC4
// size: 0x2C
// line start: 47
// line end:   54
struct ModelFace *NewModelFace__13EditorInModel() {
}


// address: 0x80052E18
// size: 0x44
// line start: 61
// line end:   61
struct EditorInModel *__13EditorInModel(struct EditorInModel *this) {
	// register: 2
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x80052E28
// line start: 68
// line end:   70
void ___13EditorInModel(struct EditorInModel *this, int __in_chrg) {
	// register: 17
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x80052E78
// line start: 76
// line end:   87
void KillModelInfo__13EditorInModel(struct EditorInModel *this) {
	{
		// register: 16
		// size: 0x2C
		register struct ModelFace *next_face;
	}
}


// address: 0x80052F08
// line start: 94
// line end:   359
void SetData__13EditorInModelP6SModeli(struct EditorInModel *this, struct SModel *pModel, int model_index) {
	// register: 8
	register short xmax;
	// register: 7
	register short xmin;
	// register: 5
	register short zmax;
	// register: 6
	register short zmin;
	// register: 3
	register int NumVertices;
	// register: 4
	register int NumNormals;
	// register: 20
	register int NumFaces;
	// register: 17
	register char *pFace;
	// register: 19
	// size: 0x2C
	register struct ModelFace *last_face;
	{
		// register: 18
		register int j;
		{
			// register: 8
			// size: 0x2C
			register struct ModelFace *face;
			// register: 4
			register unsigned short flags;
			// register: 12
			// size: 0x8
			register struct ModelPoint *verts;
			// register: 9
			// size: 0x6
			register struct SVector *point;
			// register: 7
			register char plane;
			// register: 11
			register int x;
			// register: 10
			register int z;
			// address: 0xFFFFFFD8
			// size: 0x6
			auto struct SVector temp;
			// register: 6
			register int dir;
			{
				// register: 6
				register int i;
				{
					// register: 3
					register int index;
					{
						// register: 6
						register int i;
						{
							// register: 2
							register int diff;
							{
								// register: 10
								register int i;
								{
									// register: 10
									register int i;
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80053428
// line start: 366
// line end:   396
void SetTransparency__13EditorInModelb(struct EditorInModel *this, bool on) {
	// register: 2
	register int NumVertices;
	// register: 6
	register int NumNormals;
	// register: 3
	register char *pFace;
	// register: 7
	// size: 0x2C
	register struct ModelFace *face;
	{
	}
}


// address: 0x8005349C
// line start: 418
// line end:   461
void Init__14EditorOutModel() {
	{
		// register: 10
		register int i;
		{
			// register: 5
			register int i;
			{
				// register: 3
				register int color;
				{
					// register: 6
					register int i;
					{
						// register: 4
						register int i;
					}
				}
			}
		}
	}
}


// address: 0x8005366C
// line start: 469
// line end:   474
void Cleanup__14EditorOutModel() {
}


// address: 0x800536A8
// size: 0x14
// line start: 481
// line end:   503
struct ModelFace2 *NewFace__14EditorOutModel() {
	// register: 5
	register int count;
	// register: 2
	// size: 0x14
	register struct ModelFace2 *face;
}


// address: 0x80053740
// size: 0x80
// line start: 516
// line end:   550
struct EditorOutModel *__14EditorOutModelP13EditorInModeli(struct EditorOutModel *this, struct EditorInModel *source, int id) {
	// register: 18
	// size: 0x4
	register struct CClass *this;
	{
		// register: 16
		// size: 0x2C
		register struct ModelFace *source_face;
		// register: 17
		// size: 0x14
		register struct ModelFace2 *last_face;
		{
			// register: 4
			register int i;
			{
				{
					{
						// register: 2
						// size: 0x14
						register struct ModelFace2 *face;
					}
				}
			}
		}
	}
}


// address: 0x80053844
// line start: 557
// line end:   563
void ___14EditorOutModel(struct EditorOutModel *this, int __in_chrg) {
	// register: 6
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x800538B0
// line start: 569
// line end:   576
void RestoreFaces__14EditorOutModel(struct EditorOutModel *this) {
	// register: 2
	// size: 0x14
	register struct ModelFace2 *face;
}


// address: 0x800538E4
// line start: 759
// line end:   802
void RemoveSomeHiddenFaces__14EditorOutModelP14EditorOutModeli(struct EditorOutModel *this, struct EditorOutModel *neighbor, int orientation) {
	{
		{
			// register: 14
			// size: 0x14
			register struct ModelFace2 *faceA;
			{
				// register: 12
				// size: 0x14
				register struct ModelFace2 *faceB;
				{
					{
						// size: 0x80
						auto struct EditorOutModel *model1;
						// address: 0x00000004
						// size: 0x80
						auto struct EditorOutModel *model2;
						// register: 14
						// size: 0x14
						register struct ModelFace2 *face1;
						// register: 12
						// size: 0x14
						register struct ModelFace2 *face2;
						// address: 0xFFFFFFB0
						auto unsigned char facing;
						{
							// register: 4
							register int orig_area;
							// register: 5
							register int sub_area;
							// address: 0xFFFFFFA8
							// size: 0x8
							auto int orientation[2];
							// address: 0xFFFFFFA0
							// size: 0x8
							auto struct FP *fp_list[2];
							// address: 0xFFFFFF98
							// size: 0x8
							auto struct EditorOutModel *model[2];
							// address: 0xFFFFFF90
							// size: 0x8
							auto struct ModelFace2 *face[2];
							{
								// register: 8
								register int i;
								{
									// register: 8
									register int i;
									// register: 11
									register int index;
									{
										// register: 20
										// size: 0x18
										register struct FP *fp;
										// register: 16
										// size: 0x18
										register struct FP *last_fp;
										{
											// register: 30
											register int i;
											{
												{
													{
														// register: 4
														// size: 0x18
														register struct FP *next;
														{
															// register: 13
															// size: 0x14
															register struct ModelFace2 *faceA;
															{
																{
																	{
																		// register: 10
																		// size: 0x14
																		register struct ModelFace2 *faceB;
																		{
																			{
																				{
																					{
																						// size: 0x80
																						auto struct EditorOutModel *model1;
																						// address: 0x00000004
																						// size: 0x80
																						auto struct EditorOutModel *model2;
																						// register: 13
																						// size: 0x14
																						register struct ModelFace2 *face1;
																						// register: 10
																						// size: 0x14
																						register struct ModelFace2 *face2;
																						// register: 16
																						register unsigned char facing;
																						{
																							// register: 4
																							register int orig_area;
																							// register: 5
																							register int sub_area;
																							// address: 0xFFFFFFA8
																							// size: 0x8
																							auto int orientation[2];
																							// address: 0xFFFFFFA0
																							// size: 0x8
																							auto struct FP *fp_list[2];
																							// address: 0xFFFFFF98
																							// size: 0x8
																							auto struct EditorOutModel *model[2];
																							// address: 0xFFFFFF90
																							// size: 0x8
																							auto struct ModelFace2 *face[2];
																							{
																								// register: 8
																								register int i;
																								{
																									// register: 8
																									register int i;
																									// register: 11
																									register int index;
																									{
																										// register: 21
																										// size: 0x18
																										register struct FP *fp;
																										// register: 16
																										// size: 0x18
																										register struct FP *last_fp;
																										{
																											// register: 9
																											register int i;
																											{
																												{
																													{
																														// register: 3
																														// size: 0x18
																														register struct FP *next;
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80054354
// line start: 820
// line end:   892
void RemoveAllHiddenFaces__14EditorOutModel(struct EditorOutModel *this) {
	{
		// register: 18
		register int i;
	}
}


// address: 0x800544BC
// line start: 898
// line end:   926
int SetModelDataSize__14EditorOutModelb(struct EditorOutModel *this, bool game_build) {
	// register: 9
	register int size_to_faces;
	// register: 6
	// size: 0x2C
	register struct ModelFace *source_face;
	// register: 7
	// size: 0x14
	register struct ModelFace2 *out_face;
	// register: 8
	register int size_of_faces;
	{
		// register: 3
		register bool copy_it;
	}
}


// address: 0x80054550
// line start: 938
// line end:   1137
int CreateModelData__14EditorOutModelPcb(struct EditorOutModel *this, char *pData, bool game_build) {
	// register: 17
	// size: 0x24
	register struct SModel *pModel;
	// register: 16
	register int size_to_faces;
	// register: 4
	// size: 0xC
	register struct ModelBounds *bounds;
	// register: 8
	register int xmax;
	// register: 9
	register int xmin;
	// register: 6
	register int zmax;
	// register: 7
	register int zmin;
	// register: 21
	// size: 0x8
	register struct ModelPoint *vertex;
	// register: 2
	// size: 0x8
	register struct ModelPoint *normal;
	// register: 22
	register char *pFace;
	// register: 17
	// size: 0x2C
	register struct ModelFace *face;
	// register: 20
	// size: 0x14
	register struct ModelFace2 *test_face;
	{
		// register: 9
		register int i;
		{
			// register: 5
			register short x;
			// register: 3
			register short z;
			{
				// register: 10
				register int i;
				{
					// register: 5
					register short x;
					// register: 3
					register short z;
					{
						// register: 3
						register bool copy_it;
						// register: 16
						register bool make_invisible;
						{
							{
								// register: 15
								register unsigned char *pColor;
								{
									// register: 12
									register int vert;
									{
										// register: 7
										register int color;
										{
											// register: 11
											register int lt;
											{
												// address: 0xFFFFFFB8
												// size: 0xC
												auto struct Vector light;
												// address: 0xFFFFFFC8
												// size: 0xC
												auto struct CVector VSqd;
												// register: 3
												register int r_squared;
												// register: 4
												register int add_color;
												{
													{
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80054A18
// line start: 1152
// line end:   1221
void UnhideSharedFaces__14EditorOutModelbP14EditorOutModelUc(struct EditorOutModel *this, bool unhide, struct EditorOutModel *wire_model, unsigned char against) {
	// register: 4
	register char *pFaceData;
	// register: 9
	// size: 0x2C
	register struct ModelFace *face1;
	// register: 6
	// size: 0x14
	register struct ModelFace2 *face1_info;
	{
		{
			{
				// register: 7
				register int j;
				{
					{
						// register: 10
						register int j;
						{
							// register: 3
							register bool is_hidden_face;
							// register: 8
							register bool is_outer_face;
						}
					}
				}
			}
		}
	}
}


// address: 0x80054B74
// size: 0x1C
// line start: 1227
// line end:   1231
struct RailPoint *__9RailPoint(struct RailPoint *this) {
	// register: 2
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x80054B98
// line start: 1240
// line end:   1250
bool Compare__9RailPointP9RailPoint(struct RailPoint *this, struct RailPoint *point) {
	// register: 2
	register int dx;
	// register: 8
	register int dy;
	// register: 3
	register int dz;
}


// address: 0x80054C00
// size: 0x20
// line start: 1257
// line end:   1261
struct RailString *__10RailString(struct RailString *this) {
	// register: 2
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x80054C20
// line start: 1268
// line end:   1277
void ___10RailString(struct RailString *this, int __in_chrg) {
	// register: 18
	// size: 0x4
	register struct CClass *this;
	{
		{
			// register: 4
			// size: 0x1C
			register struct RailPoint *point;
			{
				// register: 17
				register int i;
				{
					// register: 16
					// size: 0x1C
					register struct RailPoint *next_point;
				}
			}
		}
	}
}


// address: 0x80054CC4
// line start: 1283
// line end:   1310
void AddPoint__10RailStringP9RailPointb(struct RailString *this, struct RailPoint *new_point, bool is_loop) {
	// register: 6
	// size: 0x1C
	register struct RailPoint *point;
}


// address: 0x80054D38
// line start: 1318
// line end:   1371
void MakeCCW__10RailString(struct RailString *this) {
	// address: 0xFFFFFFF8
	// size: 0x6
	auto struct SVector center;
	// register: 7
	// size: 0x1C
	register struct RailPoint *a;
	// register: 5
	register int cross;
	// register: 4
	// size: 0x1C
	register struct RailPoint *last;
	{
		// register: 8
		// size: 0x1C
		register struct RailPoint *b;
		{
			// register: 3
			// size: 0x1C
			register struct RailPoint *next;
		}
	}
}


// address: 0x80054E50
// line start: 1379
// line end:   1443
void CopyString__10RailStringP10RailStringiiii(struct RailString *this, struct RailString *from, int xoff, int yoff, int zoff, int rot) {
	// register: 16
	// size: 0x1C
	register struct RailPoint *source;
	// register: 18
	// size: 0x1C
	register struct RailPoint *last_copy;
	// register: 8
	// size: 0x1C
	register struct RailPoint *copy;
	{
		// register: 17
		register int i;
	}
}


// address: 0x80055038
// line start: 1450
// line end:   1803
bool MergeString__10RailStringP10RailStringb(struct RailString *this, struct RailString *string_from, bool debugify) {
	// register: 19
	// size: 0x1C
	register struct RailPoint *from;
	// register: 23
	// size: 0x1C
	register struct RailPoint *to;
	// register: 17
	// size: 0x1C
	register struct RailPoint *a;
	// register: 18
	// size: 0x1C
	register struct RailPoint *b;
	// address: 0xFFFFFFCC
	// size: 0x1C
	auto struct RailPoint *to_first;
	// register: 21
	// size: 0x1C
	register struct RailPoint *to_last;
	// address: 0xFFFFFFD0
	// size: 0x1C
	auto struct RailPoint *from_first;
	// register: 19
	// size: 0x1C
	register struct RailPoint *from_last;
	// register: 30
	register bool scanning;
	// register: 4
	// size: 0x1C
	register struct RailPoint *kill;
	{
		{
			// register: 17
			// size: 0x1C
			register struct RailPoint *from_last;
			// register: 16
			// size: 0x1C
			register struct RailPoint *to_last;
			{
				{
					// register: 3
					// size: 0x1C
					register struct RailPoint *prev;
					{
						// register: 2
						// size: 0x1C
						register struct RailPoint *next;
						{
							// register: 22
							register int j;
							{
								// register: 20
								register bool is_shared;
								{
									// register: 16
									register int i;
									{
										// register: 22
										register int j;
										{
											// register: 20
											register bool is_shared;
											{
												// register: 16
												register int i;
												{
													// register: 16
													// size: 0x1C
													register struct RailPoint *next;
													{
														// register: 16
														// size: 0x1C
														register struct RailPoint *next;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x800557D0
// size: 0x20
// line start: 1810
// line end:   1954
struct RailString *SplitString__10RailString(struct RailString *this) {
	// register: 18
	// size: 0x1C
	register struct RailPoint *a;
	// register: 6
	register bool scanning;
	// register: 23
	// size: 0x1C
	register struct RailPoint *first1;
	// register: 30
	// size: 0x1C
	register struct RailPoint *first2;
	// register: 19
	// size: 0x1C
	register struct RailPoint *last1;
	// register: 20
	// size: 0x1C
	register struct RailPoint *last2;
	// register: 4
	// size: 0x1C
	register struct RailPoint *kill;
	// register: 16
	// size: 0x20
	register struct RailString *new_string;
	{
		// register: 22
		register int j;
		{
			// register: 21
			register bool is_double;
			// register: 16
			// size: 0x1C
			register struct RailPoint *b;
			{
				{
					{
						// register: 17
						register int i;
						{
							// register: 16
							// size: 0x1C
							register struct RailPoint *next;
							{
								// register: 16
								// size: 0x1C
								register struct RailPoint *next;
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80055B50
// line start: 1964
// line end:   2008
int CountPoints__10RailString(struct RailString *this) {
	// register: 6
	// size: 0x1C
	register struct RailPoint *point;
}


// address: 0x80055C70
// size: 0xC
// line start: 2015
// line end:   2016
struct RailInfo *__8RailInfo(struct RailInfo *this) {
	// register: 2
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x80055C84
// line start: 2023
// line end:   2025
void ___8RailInfo(struct RailInfo *this, int __in_chrg) {
	// register: 17
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x80055CD4
// size: 0x20
// line start: 2031
// line end:   2042
struct RailString *NewString__8RailInfo(struct RailInfo *this) {
	// register: 4
	// size: 0x20
	register struct RailString *string;
}


// address: 0x80055D5C
// line start: 2049
// line end:   2060
void Clear__8RailInfo(struct RailInfo *this) {
	// register: 4
	// size: 0x20
	register struct RailString *string;
	// register: 16
	// size: 0x20
	register struct RailString *next_string;
}


// address: 0x80055DC8
// line start: 2067
// line end:   2076
int CountStrings__8RailInfo(struct RailInfo *this) {
	// register: 2
	register int count;
	// register: 3
	// size: 0x20
	register struct RailString *string;
}


// address: 0x80055DF0
// line start: 2083
// line end:   2092
int CountPoints__8RailInfo(struct RailInfo *this) {
	// register: 17
	register int count;
	// register: 16
	// size: 0x20
	register struct RailString *string;
}


// address: 0x80055E40
// line start: 2108
// line end:   2189
void MergeAdd__8RailInfoP10RailStringb(struct RailInfo *this, struct RailString *new_string, bool debugify) {
	// register: 18
	// size: 0x20
	register struct RailString *merge_list;
	{
		// register: 19
		// size: 0x20
		register struct RailString *merge_list_next;
		// register: 20
		register bool repeat_merge;
		{
			// register: 16
			// size: 0x20
			register struct RailString *string;
			// register: 17
			// size: 0x20
			register struct RailString *prev;
			{
				{
					{
						// register: 2
						// size: 0x20
						register struct RailString *branch;
					}
				}
			}
		}
	}
}


// address: 0x80055FC0
// line start: 216
// line end:   1274
void ___9RailPoint(struct RailPoint *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x80055FF0
// line start: 92
// line end:   92
void ___6CClass_addr_80055FF0(struct CClass *this, int __in_chrg) {
}


// address: 0x80056020
// size: 0xA634
// line start: 49
// line end:   73
struct LevelGenerator *__14LevelGeneratorb(struct LevelGenerator *this, bool game_build) {
	// register: 18
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x800560EC
// line start: 80
// line end:   100
void ___14LevelGenerator(struct LevelGenerator *this, int __in_chrg) {
	// register: 18
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x800561A0
// line start: 109
// line end:   125
void Init__14LevelGenerator() {
	{
		// register: 10
		register int j;
		{
			{
				// register: 8
				register int i;
				{
					{
						// register: 5
						register int s;
					}
				}
			}
		}
	}
}


// address: 0x8005623C
// line start: 140
// line end:   253
void LoadModels__14LevelGeneratorPc(struct LevelGenerator *this, char *file) {
	// register: 12
	register unsigned int *pPSX;
	// register: 13
	register int num_items;
	// register: 17
	// size: 0x24
	register struct SModel **ppModels;
	{
		// register: 10
		register int x;
		{
			// register: 11
			register int i;
			{
				// register: 16
				register int i;
				{
					// address: 0xFFFFFFC8
					// size: 0x20
					auto char trig_file[32];
					// register: 8
					register int x;
				}
			}
		}
	}
}


// address: 0x800564E0
// line start: 260
// line end:   278
void UnloadModels__14LevelGenerator(struct LevelGenerator *this) {
	{
		// register: 17
		register int i;
	}
}


// address: 0x80056594
// line start: 286
// line end:   434
void ProcessGrid__14LevelGenerator(struct LevelGenerator *this) {
	// register: 30
	register int replacement_top;
	{
		// register: 8
		register int slot;
		{
			{
				// register: 9
				register int j;
				{
					{
						// register: 7
						register int i;
						{
							// register: 19
							register int slot;
							{
								{
									// register: 25
									register int j;
									{
										{
											// register: 15
											register int i;
											{
												// register: 11
												register int piece_num;
												// address: 0xFFFFFFB0
												auto int w;
												// address: 0xFFFFFFB4
												auto int l;
												// register: 14
												register int h;
												{
													{
														// register: 20
														register int start_level;
														{
															// register: 10
															register int z;
															{
																{
																	// register: 5
																	register int x;
																	{
																		{
																			// register: 4
																			register int s;
																			{
																				{
																					{
																						// register: 6
																						register int z;
																						{
																							{
																								// register: 4
																								register int x;
																								{
																									{
																										{
																											// register: 6
																											register int z;
																											{
																												{
																													// register: 4
																													register int x;
																													{
																														// register: 18
																														register int slot;
																														{
																															{
																																// register: 15
																																register int j;
																																{
																																	{
																																		// register: 13
																																		register int i;
																																		{
																																			// register: 14
																																			register int slot;
																																			{
																																				{
																																					// register: 4
																																					register int j;
																																					{
																																						{
																																							// register: 5
																																							register int i;
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80056CD4
// line start: 445
// line end:   469
void ClearOutModels__14LevelGenerator(struct LevelGenerator *this) {
	// register: 4
	// size: 0x80
	register struct EditorOutModel *model;
	{
		// register: 16
		// size: 0x80
		register struct EditorOutModel *next_model;
		{
			// register: 9
			register int j;
			{
				{
					// register: 7
					register int i;
					{
						{
							// register: 5
							register int slot;
						}
					}
				}
			}
		}
	}
}


// address: 0x80056D94
// line start: 488
// line end:   600
void GenerateOutModels__14LevelGenerator(struct LevelGenerator *this) {
	// address: 0xFFFFFFB0
	// size: 0x80
	auto struct EditorOutModel *last_model;
	// register: 22
	register int z;
	{
		// register: 30
		register int j;
		{
			// register: 20
			register int x;
			{
				// register: 17
				register int i;
				{
					// register: 23
					register int y;
					{
						// register: 21
						register int slot;
						{
							// register: 16
							// size: 0x44
							register struct EditorInModel *in_model;
							// register: 5
							// size: 0x80
							register struct EditorOutModel *out_model;
							// register: 19
							register int xoff;
							// register: 18
							register int zoff;
							{
								// register: 12
								register int n;
								{
									{
										// register: 8
										register int m;
										{
											{
												// register: 4
												register int s;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8005714C
// line start: 613
// line end:   638
void RemoveDeletedModels__14LevelGenerator(struct LevelGenerator *this) {
	// register: 18
	// size: 0x80
	register struct EditorOutModel *prev;
	// register: 16
	// size: 0x80
	register struct EditorOutModel *model;
	{
		// register: 17
		// size: 0x80
		register struct EditorOutModel *next;
	}
}


// address: 0x80057208
// line start: 646
// line end:   725
void FigureOutNeighbors__14LevelGenerator(struct LevelGenerator *this) {
	// register: 7
	// size: 0x80
	register struct EditorOutModel *model;
	{
		// register: 4
		register int z;
		// register: 10
		register int x;
		{
			{
				{
					{
						{
							// register: 11
							register int neighbor_slot;
							{
								// register: 8
								// size: 0x80
								register struct EditorOutModel *possible_add;
								// register: 3
								register int i;
								{
									{
										{
											{
												{
													// register: 11
													register int neighbor_slot;
													{
														// register: 8
														// size: 0x80
														register struct EditorOutModel *possible_add;
														// register: 5
														register int i;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80057428
// line start: 737
// line end:   747
void ClearFloorModels__14LevelGenerator(struct LevelGenerator *this) {
	// register: 4
	// size: 0x80
	register struct EditorOutModel *model;
	{
		// register: 16
		// size: 0x80
		register struct EditorOutModel *next_model;
	}
}


// address: 0x80057494
// line start: 754
// line end:   866
void GenerateFloorModels__14LevelGenerator(struct LevelGenerator *this) {
	// register: 14
	// size: 0x80
	register struct EditorOutModel *last_model;
	// register: 21
	register int z;
	{
		// register: 9
		register int j;
		{
			{
				// register: 6
				register int i;
				{
					{
						// register: 4
						register int slot;
						{
							// register: 30
							register int j;
							{
								// register: 18
								register int x;
								{
									// register: 17
									register int i;
									{
										// register: 23
										register int y;
										{
											// register: 22
											register int slot;
											{
												// register: 16
												// size: 0x44
												register struct EditorInModel *in_model;
												// register: 5
												// size: 0x80
												register struct EditorOutModel *out_model;
												// register: 20
												register int xoff;
												// register: 19
												register int zoff;
												{
													// register: 7
													register int n;
													{
														{
															// register: 4
															register int m;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8005784C
// line start: 878
// line end:   887
void HideFloorPieces__14LevelGenerator(struct LevelGenerator *this) {
	// register: 16
	// size: 0x80
	register struct EditorOutModel *model;
}


// address: 0x800578B0
// line start: 897
// line end:   1001
void LoadRails__14LevelGeneratorPc(struct LevelGenerator *this, char *file) {
	// address: 0xFFFFFFD0
	auto unsigned int *pModelChecksums;
	// register: 18
	register unsigned short node;
	{
		// register: 19
		register short num_links;
		// register: 17
		register int trickob;
		// register: 4
		register unsigned short *pTrick;
		// register: 4
		register unsigned int checksum;
		// register: 5
		register int model;
		// register: 21
		// size: 0x20
		register struct RailString *string;
		// register: 17
		register unsigned short linked_node;
		{
			// register: 5
			register short i;
			{
				{
					// address: 0xFFFFFFC0
					// size: 0xC
					auto struct CVector loc;
					// register: 20
					register unsigned short *pMaterial;
					// register: 16
					// size: 0x1C
					register struct RailPoint *point;
					{
						{
						}
					}
				}
			}
		}
	}
}


// address: 0x80057B68
// line start: 1010
// line end:   1042
void UnloadOutPSX__14LevelGeneratorb(bool killBuffers) {
}


// address: 0x80057BE8
// line start: 1061
// line end:   1097
void LoadMap__14LevelGeneratorPc(char *load_name) {
	// register: 20
	register char *buf;
	// register: 2
	// size: 0x10
	register struct GridCell *out_grid;
	{
		// address: 0xFFFFFF90
		auto int i;
		{
			{
				// register: 17
				register int slot;
			}
		}
	}
}


// address: 0x80057E88
// line start: 1141
// line end:   1162
void SetMapTheme__14LevelGeneratori(int theme) {
	// register: 2
	// size: 0x10
	register struct GridCell *grid;
	{
		// register: 21
		register int i;
		{
			{
				// register: 17
				register int slot;
				{
					// register: 21
					register int i;
					{
						{
							// register: 17
							register int slot;
						}
					}
				}
			}
		}
	}
}


// address: 0x80057FD0
// line start: 1169
// line end:   1256
bool RemoveModelFromMap__14LevelGeneratoriiPiPP13EditorInModel(struct LevelGenerator *this, int xmap, int zmap, int *no_lower_than, struct EditorInModel **ret_model) {
	// register: 9
	register int slot;
	// register: 22
	// size: 0x80
	register struct EditorOutModel *model;
	// register: 11
	register int x0;
	// register: 12
	register int z0;
	// register: 14
	register int x1;
	// register: 15
	register int z1;
	{
		{
			{
				// register: 6
				register int z;
				{
					{
						// register: 4
						register int x;
						{
							// register: 23
							register int z;
							{
								{
									// register: 17
									register int x;
									{
										{
											// register: 16
											register int s;
											{
												// register: 3
												// size: 0x80
												register struct EditorOutModel *mod;
												{
													// register: 7
													register int z;
													{
														{
															// register: 4
															register int x;
															{
																{
																	// register: 5
																	register int s;
																	{
																		// register: 2
																		// size: 0x80
																		register struct EditorOutModel *mod;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80058368
// line start: 1284
// line end:   1859
unsigned int *CreatePSX__14LevelGeneratorPib(struct LevelGenerator *this, int *ret_region, bool refresh_models) {
	// register: 19
	register unsigned int *pSourcePSX;
	// register: 16
	// size: 0x80
	register struct EditorOutModel *out_model;
	// address: 0xFFFFFF50
	auto int num_ed_models;
	// register: 18
	register int model_data_size;
	// address: 0xFFFFFF54
	auto unsigned int *pShellPSX;
	// address: 0xFFFFFF58
	// size: 0x24
	auto struct SModel **ppShellModels;
	// address: 0xFFFFFF5C
	auto unsigned int *pShellPacket;
	// register: 3
	register int shell_model_data_size;
	// address: 0xFFFFFF60
	auto int num_models;
	// register: 2
	register int model_table_size;
	// address: 0xFFFFFF6C
	auto int packet_data_size;
	// address: 0xFFFFFF70
	auto unsigned int *pSourceTextures;
	// address: 0xFFFFFF74
	auto unsigned int num_ed_textures;
	// address: 0xFFFFFF78
	auto unsigned int *pShellTextures;
	// address: 0xFFFFFF7C
	auto unsigned int num_shell_textures;
	// address: 0xFFFFFF80
	auto unsigned int num_textures;
	// register: 3
	register int texture_checksum_size;
	// address: 0xFFFFFF84
	auto unsigned int *pHeader;
	// address: 0xFFFFFF88
	// size: 0x24
	auto struct Item *pSourceItem;
	// register: 6
	// size: 0x24
	register struct Item *pItem;
	// register: 21
	register int i;
	// register: 2
	// size: 0x24
	register struct Item *pShellItems;
	// register: 22
	register unsigned int *pModelTable;
	// register: 19
	register char *pModelData;
	// register: 8
	register unsigned int *pTexture;
	{
		{
			{
				// register: 3
				register int i;
				{
					// register: 17
					register int which_list;
					{
						// address: 0xFFFFFF8C
						auto int which_list;
						{
							{
								// register: 3
								register int source_index;
								{
									// register: 9
									register int i;
									{
										// register: 5
										register int item_num;
										{
											// register: 18
											register int which_list;
											{
												// register: 18
												register int i;
												{
													// register: 2
													register int model_num;
													// register: 16
													register int model_size;
													{
														// register: 7
														register int i;
														{
															// register: 5
															register int i;
															{
																// register: 2
																register int num;
																{
																	// register: 4
																	register int i;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80058E3C
// line start: 1993
// line end:   2181
int CreateZonePacket__14LevelGeneratorPi(struct LevelGenerator *this, int *at) {
	// register: 18
	register bool actual_create;
	// register: 10
	register int zone_length;
	// register: 14
	register int zone_item_count;
	// register: 24
	register int ed_item_index;
	// register: 4
	register unsigned int *pShellPSX;
	// register: 2
	// size: 0x24
	register struct SModel **ppShellModels;
	// register: 15
	register int start_x;
	// register: 10
	register int index;
	{
		{
			{
				// register: 16
				register int i;
				{
					{
						{
							// register: 6
							register int j;
							{
								{
									// register: 5
									register int i;
									{
										// register: 16
										register int which_list;
										{
											// register: 9
											// size: 0x80
											register struct EditorOutModel *model;
											{
												// register: 2
												register int ix0;
												// register: 2
												register int ix1;
												// register: 4
												register int iz0;
												// register: 4
												register int iz1;
												// register: 12
												register int zz1;
												// register: 15
												register int zz0;
												{
													// register: 6
													register int zx;
													{
														{
															// register: 5
															register int zz;
															{
																// register: 16
																register int i;
																// register: 16
																register int which_list;
																{
																	// register: 2
																	register int x0;
																	// register: 5
																	register int x1;
																	// register: 3
																	register int z0;
																	// register: 4
																	register int z1;
																	// register: 8
																	register int zx0;
																	// register: 9
																	register int zx1;
																	// register: 11
																	register int zz0;
																	// register: 7
																	register int zz1;
																	{
																		// register: 6
																		register int zx;
																		{
																			{
																				// register: 5
																				register int zz;
																				{
																					// register: 16
																					register int zz;
																					// register: 16
																					register int i;
																					// register: 16
																					register int which_list;
																					{
																						{
																							// register: 12
																							register int zx;
																							{
																								{
																									// register: 6
																									register int i;
																									{
																										// register: 16
																										register int i;
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8005946C
// line start: 2194
// line end:   2237
void CreateRails__14LevelGenerator(struct LevelGenerator *this) {
	// register: 17
	// size: 0x80
	register struct EditorOutModel *model;
	{
		// register: 2
		// size: 0x44
		register struct EditorInModel *in_model;
		// register: 18
		// size: 0x20
		register struct RailString *in_string;
		{
			// register: 16
			// size: 0x20
			register struct RailString *out_string;
		}
	}
}


// address: 0x80059550
// line start: 2251
// line end:   2295
int GenerateRailNode__FPsP9RailPointT1i(short *pData, struct RailPoint *point, struct RailPoint *next_point, int next_node) {
	// register: 6
	register int num_links;
	// register: 3
	register int pad;
	// register: 13
	register int size;
	// register: 10
	register int n;
}


// address: 0x8005962C
// line start: 2304
// line end:   2459
void FakeTrig__14LevelGenerator(struct LevelGenerator *this) {
	// register: 20
	register int num_rail_points;
	// register: 19
	register int rail_nodes_size;
	// register: 17
	// size: 0x20
	register struct RailString *string;
	// register: 16
	register short *pNode;
	// register: 4
	register char *pNodeName;
	// register: 19
	register int node_count;
	{
		// register: 16
		// size: 0x1C
		register struct RailPoint *point;
		{
			// register: 18
			register int i;
			{
				// register: 18
				// size: 0x1C
				register struct RailPoint *point;
				// register: 21
				register int first_node;
				{
					// register: 20
					register int i;
					{
						// register: 2
						register int size;
					}
				}
			}
		}
	}
}


// address: 0x800598B8
// line start: 2470
// line end:   2520
void UnhideFaces__14LevelGeneratorP14EditorOutModelb(struct LevelGenerator *this, struct EditorOutModel *das_model, bool on) {
	// register: 23
	register int m0;
	// register: 19
	register int m1;
	// register: 30
	register int n0;
	// register: 18
	register int n1;
	{
		// address: 0xFFFFFFC0
		auto int s;
		{
			// register: 16
			register int m;
			// register: 17
			register int n;
		}
	}
}


// address: 0x80059B2C
// line start: 2526
// line end:   2554
void UnhideFloor__14LevelGeneratorP14EditorOutModelb(struct LevelGenerator *this, struct EditorOutModel *das_model, bool unhide) {
	// register: 3
	register int slot;
	// register: 7
	register int z0;
	// register: 13
	register int z1;
	// register: 12
	register int x0;
	// register: 11
	register int x1;
	{
		// register: 9
		register int z;
		{
			{
				// register: 8
				register int x;
				{
					// register: 3
					// size: 0x80
					register struct EditorOutModel *floor;
				}
			}
		}
	}
}


// address: 0x80059C40
// line start: 2560
// line end:   2572
void HideWalls__14LevelGeneratorb(struct LevelGenerator *this, bool hide) {
	// register: 6
	register int num_models;
	// register: 3
	register unsigned int *pHeader;
	// register: 3
	// size: 0x24
	register struct SModel **pModelTable;
	{
		// register: 7
		register int i;
	}
}


// address: 0x80059CE0
// line start: 2579
// line end:   2654
void AddModel__14LevelGeneratoriiiii(struct LevelGenerator *this, int x, int z, int slot, int rot, int index) {
	// register: 16
	// size: 0x44
	register struct EditorInModel *in_model;
	// register: 7
	// size: 0x80
	register struct EditorOutModel *out_model;
	// register: 20
	register int xoff;
	// register: 19
	register int zoff;
	// register: 3
	register int xworld;
	// register: 2
	register int zworld;
	// register: 5
	register int yworld;
	{
		{
			// register: 4
			// size: 0x80
			register struct EditorOutModel *last_model;
			{
				// register: 11
				register int n;
				{
					{
						// register: 5
						register int m;
						{
							{
								// register: 4
								register int s;
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80059FF4
// line start: 2661
// line end:   2668
void KillModel__14LevelGeneratoriii(struct LevelGenerator *this, int x, int z, int slot) {
}


// address: 0x8005A060
// line start: 92
// line end:   92
void ___6CClass_addr_8005A060(struct CClass *this, int __in_chrg) {
}


// address: 0x8005E214
// line start: 38
// line end:   137
int Load8BitBMP2__FPcPPcPiT2PUs(char *pData, char **data, int *ww, int *hh, unsigned short *clut) {
	// register: 23
	register int clutx;
	// register: 22
	register int cluty;
	// register: 17
	register int w;
	// register: 19
	register int h;
	// register: 5
	register int bpp;
	// register: 18
	register int colors;
	// register: 20
	register int transparent_color;
	// address: 0xFFFFFDD0
	// size: 0x200
	auto unsigned short colorTab[256];
	// register: 9
	register char *pColor;
	// address: 0xFFFFFFD0
	// size: 0x8
	auto struct RECT r;
	// register: 16
	register int pad;
	// register: 6
	register char *in;
	// register: 4
	register char *out;
	{
		// register: 8
		register int i;
		{
			// register: 5
			register unsigned short r;
			// register: 3
			register unsigned short g;
			// register: 4
			register unsigned short b;
			{
				// register: 8
				register int j;
				// register: 8
				register int i;
				{
					{
						// register: 5
						register int i;
						{
							// register: 3
							register int i;
						}
					}
				}
			}
		}
	}
}


// address: 0x8005E49C
// line start: 145
// line end:   166
int Load8BitBMP__FPcPPcPiT2PUs(char *file, char **data, int *ww, int *hh, unsigned short *clut) {
	// register: 2
	register int size;
	// register: 16
	register char *pData;
}


// address: 0x8005E55C
// line start: 420
// line end:   427
void DrawColoredBox__FiiiiUcUcUc(int x, int y, int w, int h, int r, int g, int b) {
	// register: 8
	// size: 0x18
	register struct POLY_F4 *Poly;
}


// address: 0x8005E624
// line start: 431
// line end:   440
void SetClippingBox__Fiiii(int x, int y, int w, int h) {
	// address: 0xFFFFFFF0
	// size: 0x8
	auto struct RECT r;
	// register: 16
	// size: 0xC
	register struct DR_AREA *pClip;
}


// address: 0x8005E6D0
// line start: 444
// line end:   446
void ResetOT__Fv() {
}


// address: 0x8005E6E4
// size: 0x34
// line start: 467
// line end:   527
struct SlicedImage *__11SlicedImagePciiiiiUs(struct SlicedImage *this, char *pImg, int w, int h, int slicew, int sliceh, int arg_bpp, int arg_clut) {
	// register: 16
	// size: 0x4
	register struct CClass *this;
	{
		// register: 8
		register unsigned short *out;
		// register: 5
		register unsigned short *in;
		// register: 6
		register int remainder;
		{
			// register: 9
			register int k;
			{
				{
					// register: 7
					register int j;
					{
						{
							// register: 3
							register int i;
							{
								{
									{
										// register: 7
										register int j;
										{
											{
												// register: 4
												register int i;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8005E8E0
// line start: 531
// line end:   547
void ___11SlicedImage(struct SlicedImage *this, int __in_chrg) {
	// register: 16
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x8005E9A8
// line start: 550
// line end:   687
int pack__11SlicedImage(struct SlicedImage *this) {
	// register: 18
	register int j;
	// register: 16
	register int k;
	// register: 30
	register unsigned short *data_col;
	// register: 20
	register unsigned short *data;
	// address: 0xFFFFFFC0
	// size: 0x8
	auto struct RECT r;
	// register: 22
	register int remx;
	// address: 0xFFFFFFD0
	auto int numy;
	// register: 23
	register int remy;
	// address: 0xFFFFFFC8
	auto int dum1;
	// address: 0xFFFFFFCC
	auto int dum2;
}


// address: 0x8005EFD4
// line start: 832
// line end:   853
void unpack__11SlicedImage(struct SlicedImage *this) {
	{
		// register: 17
		register int j;
		{
			{
				// register: 16
				register int i;
			}
		}
	}
}


// address: 0x8005F0BC
// line start: 866
// line end:   930
void draw__11SlicedImageiiiiiiii(struct SlicedImage *this, int x, int y, int UsePanelOT, int r, int g, int b, int Trans, int DrawStraight) {
	// register: 19
	register int xt;
	// register: 20
	register int yt;
	// register: 8
	register int index;
	// register: 21
	register unsigned int *pOT;
	// register: 6
	// size: 0x28
	register struct POLY_FT4 *apoly;
	// register: 18
	register int bpp8;
	{
		// register: 30
		register int j;
		{
			{
				// register: 23
				register int i;
			}
		}
	}
}


// address: 0x8005F534
// line start: 947
// line end:   970
void DrawIt__FP4RECTiiii(struct RECT *r, int x, int y, int bpp, int clut) {
	// address: 0xFFFFFFD0
	// size: 0x28
	auto struct POLY_FT4 poly;
	// register: 8
	// size: 0x28
	register struct POLY_FT4 *apoly;
}


// address: 0x8005F6DC
// line start: 975
// line end:   1075
void rotateDraw__11SlicedImageii(struct SlicedImage *this, int x, int y) {
	// register: 20
	register int xt;
	// register: 18
	register int yt;
	// address: 0xFFFFFFC0
	// size: 0x8
	auto struct RECT r;
	// register: 21
	register unsigned short *data_col;
	// register: 17
	register unsigned short *data;
	// register: 30
	register int remx;
	// address: 0xFFFFFFD4
	auto int remy;
	// register: 23
	register int j;
	// register: 16
	register int k;
	{
		{
			// address: 0xFFFFFFC8
			auto int dum1;
			// address: 0xFFFFFFCC
			auto int dum2;
		}
	}
}


// address: 0x8005FA38
// line start: 1079
// line end:   1091
void removeBlack__11SlicedImage(struct SlicedImage *this) {
	// register: 4
	register unsigned short *buf;
	// register: 3
	register int temp;
	{
		// register: 5
		register int i;
	}
}


// address: 0x8005FA98
// size: 0x18
// line start: 1109
// line end:   1127
struct Sprite *__6SpritePciii(struct Sprite *this, char *file, int pack, int slicew, int sliceh) {
	// register: 17
	// size: 0x4
	register struct CClass *this;
	{
		// address: 0xFFFFFFDC
		auto char *buf;
		// address: 0xFFFFFFE0
		auto int w;
		// address: 0xFFFFFFE4
		auto int h;
		// address: 0xFFFFFFD8
		auto unsigned short clut;
	}
}


// address: 0x8005FB8C
// size: 0x18
// line start: 1158
// line end:   1184
struct Sprite *__6Spriteiiiiiii(struct Sprite *this, int x, int y, int w, int h, int pack, int slicew, int sliceh) {
	// register: 17
	// size: 0x4
	register struct CClass *this;
	{
		// address: 0xFFFFFFD0
		// size: 0x8
		auto struct RECT r;
		// register: 16
		register unsigned long *buf;
	}
}


// address: 0x8005FCBC
// line start: 1241
// line end:   1243
void ___6Sprite(struct Sprite *this, int __in_chrg) {
	// register: 16
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x8005FD28
// line start: 1246
// line end:   1250
void draw__6Spriteiiiiii(struct Sprite *this, int x, int y, int UsePanelOT, int r, int g, int b) {
}


// address: 0x8005FD8C
// line start: 1296
// line end:   1298
void ___11EraseSprite(struct EraseSprite *this, int __in_chrg) {
	// register: 17
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x8005FDE0
// size: 0x334
// line start: 1462
// line end:   1545
struct VerticalMenu *__12VerticalMenuiiiPPciPiT6i(struct VerticalMenu *this, int top, int bottom, int spacing, char **items, int num, int *xlist, int *ylist, int selection) {
	// register: 21
	// size: 0x4
	register struct CClass *this;
	{
		// address: 0xFFFFFFC0
		auto int tot_h;
		// address: 0xFFFFFFC4
		auto int y;
		{
			// register: 20
			register int i;
			{
				// address: 0xFFFFFFC8
				auto int i;
				{
				}
			}
		}
	}
}


// address: 0x800601A4
// line start: 1549
// line end:   1563
void setString__12VerticalMenuiPc(struct VerticalMenu *this, int i, char *string) {
}


// address: 0x80060214
// line start: 1566
// line end:   1582
void ___12VerticalMenu(struct VerticalMenu *this, int __in_chrg) {
	// register: 18
	// size: 0x4
	register struct CClass *this;
	{
		{
			{
				// register: 17
				register int i;
			}
		}
	}
}


// address: 0x80060368
// line start: 1642
// line end:   1739
void draw__12VerticalMenu(struct VerticalMenu *this) {
	// register: 20
	register int tri_off;
	// register: 5
	register int y;
	{
		// register: 20
		register int i;
	}
}


// address: 0x80060970
// line start: 1743
// line end:   1760
void erase__12VerticalMenu(struct VerticalMenu *this) {
	// register: 16
	register int tri_off;
	{
		// register: 16
		register int i;
	}
}


// address: 0x80060AF4
// line start: 1764
// line end:   1779
void select__12VerticalMenui(struct VerticalMenu *this, int num) {
}


// address: 0x80060B40
// line start: 1782
// line end:   1783
int getSelected__12VerticalMenu(struct VerticalMenu *this) {
}


// address: 0x80060B4C
// line start: 1787
// line end:   1807
void up__12VerticalMenu(struct VerticalMenu *this) {
	// register: 5
	register int choice;
}


// address: 0x80060C04
// line start: 1810
// line end:   1830
void down__12VerticalMenu(struct VerticalMenu *this) {
	// register: 5
	register int choice;
}


// address: 0x80060CB8
// line start: 1839
// line end:   1839
void ___14VerticalDialog(struct VerticalDialog *this, int __in_chrg) {
}


// address: 0x80060D08
// line start: 1844
// line end:   1865
void draw__14VerticalDialog(struct VerticalDialog *this) {
	{
		// register: 20
		register int i;
	}
}


// address: 0x80060E94
// line start: 122
// line end:   2251
void ___9PadBuffer(struct PadBuffer *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x80060EC4
// line start: 92
// line end:   92
void ___6CClass_addr_80060EC4(struct CClass *this, int __in_chrg) {
}


// address: 0x80060EF4
// line start: 92
// line end:   113
long BitsRequired__Fl(long n) {
	// register: 3
	register long Limit;
	// register: 5
	register long Bits;
}


// address: 0x80060F48
// line start: 120
// line end:   155
void PutNBits__FP10SVideoInfoli(struct SVideoInfo *VInfo, long v, int n) {
}


// address: 0x8006100C
// line start: 160
// line end:   166
void FlushBits__FP10SVideoInfo(struct SVideoInfo *VInfo) {
}


// address: 0x80061044
// line start: 174
// line end:   204
long GetNBitsUnsigned__FP10SVideoInfoi(struct SVideoInfo *VInfo, int n) {
	// register: 5
	register unsigned long res;
}


// address: 0x80061100
// line start: 211
// line end:   222
long GetNBitsSigned__FP10SVideoInfoi(struct SVideoInfo *VInfo, int n) {
	// register: 4
	register long res;
}


// address: 0x8006114C
// line start: 229
// line end:   242
long GetBit__FP10SVideoInfo(struct SVideoInfo *VInfo) {
}


// address: 0x8006119C
// line start: 269
// line end:   271
void InitSoundCmdQueue__Fv() {
}


// address: 0x800611AC
// line start: 275
// line end:   278
void QueueSoundCmd__F13ESoundCmdTypei(enum ESoundCmdType SoundCmdType, int SoundNum) {
}


// address: 0x8006120C
// line start: 282
// line end:   283
int HasSoundCmd__Fv() {
}


// address: 0x80061224
// line start: 287
// line end:   291
void DequeueSoundCmd__FR13ESoundCmdTypeRi(enum ESoundCmdType *SoundCmdType, int *SoundNum) {
}


// address: 0x800612A0
// line start: 304
// line end:   310
void Video_SFXPlay__Fisi(int Sound, short Vol, int PitchOffset) {
}


// address: 0x800612E8
// line start: 320
// line end:   321
void InitBloodSplat__Fv() {
}


// address: 0x800612FC
// line start: 325
// line end:   336
void Video_BloodSplat__FP6CBruceii(struct CBruce_duplicate_s0 *pSkater, int BodyPart, int MaxBloodBits) {
}


// address: 0x80061340
// line start: 346
// line end:   347
void InitTrickObs__Fv() {
}


// address: 0x80061354
// line start: 380
// line end:   403
void Video_HighlightStart__FP6CBruce(struct CBruce_duplicate_s0 *pSkater) {
	// register: 3
	// size: 0xC0
	register struct SVideoInfo *VInfo;
}


// address: 0x800613A8
// line start: 410
// line end:   497
void Video_HighlightEnd__FP6CBrucei(struct CBruce_duplicate_s0 *pSkater, int Score) {
	// register: 8
	// size: 0xC0
	register struct SVideoInfo *VInfo;
	// register: 12
	register int WasABail;
	{
		// register: 7
		register int i;
		{
			{
				{
					{
						// register: 6
						register int j;
					}
				}
			}
		}
	}
}


// address: 0x80061534
// line start: 505
// line end:   564
void Video_SortAndMerge__Fv() {
	// address: 0xFFFFFFC0
	// size: 0x28
	auto struct SHighlight TempHL[5];
	// address: 0xFFFFFFE8
	// size: 0x8
	auto struct SHighlight NullHL;
	{
		// register: 12
		register int i;
		{
			// register: 8
			register int BestFrom;
			// register: 9
			register int BestIndex;
			{
				// register: 5
				register int j;
				{
					// register: 2
					register int i;
					{
						// register: 7
						register int i;
					}
				}
			}
		}
	}
}


// address: 0x80061764
// line start: 579
// line end:   615
void Video_SetHeader__FP10SVideoHeadi(struct SVideoHead *Head, int SkaterNum) {
	// address: 0xFFFFFF40
	// size: 0xC0
	auto struct SVideoInfo VInfo;
	// register: 6
	// size: 0x146C
	register struct CBruce_duplicate_s0 *pSkater;
	// register: 3
	// size: 0x146C
	register struct CBruce_duplicate_s0 *pSkater2;
	{
		{
			{
				{
					{
						{
							{
								{
									// register: 7
									register int i;
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80061870
// line start: 621
// line end:   639
void Video_InitOnce__Fv() {
}


// address: 0x800618EC
// line start: 646
// line end:   650
void Video_Init__Fv() {
}


// address: 0x800618F4
// line start: 655
// line end:   685
void Video_SyncObs__Fi(int NumFrames) {
	// register: 18
	// size: 0x146C
	register struct CBruce_duplicate_s0 *pSkater;
	// register: 17
	// size: 0x146C
	register struct CBruce_duplicate_s0 *pSkater2;
	{
		// register: 16
		register int i;
	}
}


// address: 0x800619B4
// line start: 690
// line end:   710
void Video_SyncObsIfNeeded__Fv() {
	{
		{
			{
				{
					{
						// register: 4
						register int t1;
						// register: 5
						register int t2;
					}
				}
			}
		}
	}
}


// address: 0x80061A30
// line start: 717
// line end:   723
void Video_Cleanup__Fv() {
}


// address: 0x80061A44
// line start: 739
// line end:   815
void Video_Start__FP6CBruce10EVideoModeii(struct CBruce_duplicate_s0 *pSkater, enum EVideoMode_duplicate_e17 VMode, int StartFrame, int EndFrame) {
	// register: 16
	// size: 0xC0
	register struct SVideoInfo *VInfo;
	{
		{
			{
				// register: 4
				register int i;
				{
					// register: 3
					register int i;
				}
			}
		}
	}
}


// address: 0x80061BDC
// line start: 825
// line end:   850
void Video_Stop__FP6CBruce(struct CBruce_duplicate_s0 *pSkater) {
	// register: 16
	// size: 0xC0
	register struct SVideoInfo *VInfo;
}


// address: 0x80061C38
// line start: 929
// line end:   943
void Matrix2Euler__FP6MATRIXP7SVECTOR(struct MATRIX *m, struct SVECTOR *a) {
	// address: 0xFFFFFFC8
	// size: 0x20
	auto struct MATRIX mm;
	// register: 16
	register int x;
	// register: 19
	register int y;
	// register: 2
	register int z;
}


// address: 0x80061D34
// line start: 949
// line end:   1235
void PutDataChunk__FP6CBruce(struct CBruce_duplicate_s0 *pSkater) {
	// register: 16
	register int i;
	// register: 18
	register int bx;
	// register: 16
	register int by;
	// register: 4
	register int bz;
	// register: 7
	register int PredX;
	// register: 8
	register int PredY;
	// register: 10
	register int PredZ;
	// register: 19
	register int DeltaX;
	// register: 21
	register int DeltaY;
	// register: 20
	register int DeltaZ;
	// address: 0xFFFFFF90
	// size: 0xC
	auto struct CVector PredPos;
	// address: 0xFFFFFFA0
	// size: 0xC
	auto struct CVector DeltaPos;
	// register: 17
	// size: 0xC0
	register struct SVideoInfo *VInfo;
	{
		{
			{
				{
					{
						{
							// register: 18
							register int Delta;
							// register: 5
							register int Bits;
							{
								{
									// address: 0xFFFFFFC4
									// size: 0x4
									auto enum ESoundCmdType SoundCmdType;
									// address: 0xFFFFFFC8
									auto int SoundNum;
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x800624D8
// line start: 1239
// line end:   1254
void Video_Record__FP6CBruce(struct CBruce_duplicate_s0 *pSkater) {
}


// address: 0x80062518
// line start: 1260
// line end:   1540
void GetDataChunk__FP6CBrucei(struct CBruce_duplicate_s0 *pSkater, int NChunks) {
	// register: 17
	register int i;
	// register: 17
	register int DeltaX;
	// register: 18
	register int DeltaY;
	// register: 2
	register int DeltaZ;
	// register: 19
	// size: 0xC0
	register struct SVideoInfo *VInfo;
	{
		{
			{
				{
					{
						// register: 2
						register int Delta;
						{
							{
								// register: 16
								register int Delta;
								{
									{
										{
											{
												// register: 2
												register int SoundNum;
												{
													// register: 2
													register int SoundNum;
													{
														{
															{
																{
																	{
																		{
																			// register: 4
																			register int TrickObIndex;
																			// register: 16
																			// size: 0x18
																			register struct CTrickOb *pTrickOb;
																			{
																				// register: 3
																				register int i;
																				{
																					{
																						// address: 0xFFFFFF10
																						// size: 0xA4
																						auto struct SLineInfo LInfo;
																						// register: 16
																						register int Player;
																						// address: 0xFFFFFF00
																						// size: 0xC
																						auto struct CVector nearest;
																						// address: 0xFFFFFFB8
																						// size: 0xC
																						auto struct CVector Start;
																						// address: 0xFFFFFFC8
																						// size: 0xC
																						auto struct CVector End;
																						{
																							{
																								{
																									{
																										{
																											{
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80062C88
// line start: 1552
// line end:   1692
void Video_Playback__FP6CBruce(struct CBruce_duplicate_s0 *pSkater) {
	// register: 19
	// size: 0xC0
	register struct SVideoInfo *VInfo;
	{
		{
			{
				{
					{
						{
							// register: 17
							register int IsAGrind;
							{
								{
									{
										{
											// address: 0xFFFFFFC8
											// size: 0x6
											auto struct CSVector Angles;
											// address: 0xFFFFFFD0
											// size: 0x6
											auto struct CSVector cone;
											// address: 0xFFFFFFD8
											// size: 0xC
											auto struct CVector SparkPos;
											{
												{
													{
														// register: 2
														register int _x;
														// register: 3
														register int _y;
														// register: 5
														register int _z;
														{
															{
																{
																	{
																		{
																			// register: 16
																			register int i;
																			{
																				{
																					{
																						{
																							{
																								// register: 3
																								register int StartFrame;
																								// register: 4
																								register int EndFrame;
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80062FDC
// line start: 1711
// line end:   1826
void Video_HandleStepping__Fv() {
	{
		{
			{
				{
					{
						// register: 24
						register int p;
						{
							{
								{
									{
										// address: 0x0000000C
										static int RepeatDelay;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x800632B4
// line start: 1826
// line end:   1826
void _GLOBAL__I_ReplaySoundLockout() {
	{
		{
			{
				{
					{
						{
							{
								{
									{
										{
											{
												{
													{
														{
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8005A6E8
// line start: 15
// line end:   17
void PRE_Init__Fv() {
}


// address: 0x8005A718
// line start: 24
// line end:   27
void PRE_Cleanup__Fv() {
}


// address: 0x8005A750
// size: 0x144
// line start: 34
// line end:   40
struct PREManager *__10PREManager(struct PREManager *this) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
		{
			// register: 7
			register int i;
		}
	}
}


// address: 0x8005A790
// line start: 47
// line end:   51
void ___10PREManager(struct PREManager *this, int __in_chrg) {
	// register: 18
	// size: 0x4
	register struct CClass *this;
	{
		{
			{
				// register: 17
				register int i;
			}
		}
	}
}


// address: 0x8005A81C
// line start: 57
// line end:   59
void loadPRE__10PREManagerPc(struct PREManager *this, char *pre_name) {
}


// address: 0x8005A844
// line start: 66
// line end:   91
void spoolPRE__10PREManagerPc(struct PREManager *this, char *pre_name) {
	// register: 16
	register int slot;
}


// address: 0x8005A92C
// line start: 100
// line end:   120
void spoolPREData__10PREManagerPcT1(struct PREManager *this, char *pDataBuffer, char *pre_name) {
	// register: 7
	register int slot;
}


// address: 0x8005A9B4
// line start: 126
// line end:   139
void unloadPRE__10PREManagerPc(struct PREManager *this, char *pre_name) {
	// register: 18
	register int slot;
}


// address: 0x8005AA54
// line start: 149
// line end:   163
char *getFile__10PREManagerPcPi(struct PREManager *this, char *filename, int *size) {
	// register: 3
	register char *ptr;
	{
		// register: 17
		register int i;
	}
}


// address: 0x8005AADC
// line start: 171
// line end:   206
char *parsePRE__10PREManagerPcT1Pi(struct PREManager *this, char *pre, char *filename, int *size) {
	// register: 16
	register char *ptr;
	// register: 19
	register int num_files;
	// register: 17
	register int length;
	{
		// register: 18
		register int i;
		{
			// register: 4
			register char *name;
			// register: 2
			register int offs;
		}
	}
}


// address: 0x8005ABA0
// line start: 213
// line end:   223
bool inPRE__10PREManagerPc(struct PREManager *this, char *pre_name) {
	{
		// register: 18
		register int slot;
	}
}


// address: 0x8005AC28
// line start: 92
// line end:   92
void ___6CClass_addr_8005AC28(struct CClass *this, int __in_chrg) {
}


// address: 0x8005AC58
// line start: 40
// line end:   48
void ___6Slider(struct Slider *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x8005AC88
// line start: 92
// line end:   92
void ___6CClass_addr_8005AC88(struct CClass *this, int __in_chrg) {
}


// address: 0x8005ACB8
// size: 0x50
// line start: 126
// line end:   130
struct Font_duplicate_s0 *__4Font(struct Font_duplicate_s0 *this) {
	// register: 2
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x8005ACD0
// size: 0x50
// line start: 137
// line end:   252
struct Font_duplicate_s0 *__4FontPUc(struct Font_duplicate_s0 *this, unsigned char *buf) {
	// register: 17
	// size: 0x4
	register struct CClass *this;
	{
		// register: 19
		register int clutx;
		// register: 18
		register int cluty;
		// register: 16
		register unsigned short *colors;
		// address: 0xFFFFFFC8
		// size: 0x8
		auto struct RECT r;
		// register: 30
		register unsigned char *db;
		// register: 21
		register unsigned char *tb;
		// register: 19
		register int image_w;
		// register: 16
		register int crap_size;
		// register: 18
		register unsigned char *crap;
		{
			// register: 5
			register int i;
			{
				// register: 20
				register int i;
				{
					// register: 22
					register int image_w;
					{
						// register: 3
						register int i;
					}
				}
			}
		}
	}
}


// address: 0x8005B150
// line start: 259
// line end:   260
void ___4Font(struct Font_duplicate_s0 *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x8005B180
// line start: 267
// line end:   410
void draw__4FontiiPci(struct Font_duplicate_s0 *this, int x, int y, char *str, int drawFirst) {
	// register: 20
	register int xstart;
	// register: 4
	register int strWidth;
	// register: 16
	register int ystart;
	// register: 18
	register char *ltr;
	// register: 19
	register int xt;
	// address: 0xFFFFFFC8
	auto int yt;
	{
		// register: 4
		register int i;
		{
			{
				// address: 0xFFFFFFC0
				auto int ScreenX;
				// address: 0xFFFFFFC4
				auto int ScreenY;
				// register: 30
				register int PostEffectX;
				// register: 23
				register int PostEffectY;
				// address: 0xFFFFFFCC
				auto int PreEffectX;
				// address: 0xFFFFFFD0
				auto int PreEffectY;
			}
		}
	}
}


// address: 0x8005B704
// line start: 419
// line end:   436
int width__4FontPc(struct Font_duplicate_s0 *this, char *str) {
	// register: 17
	register int w;
	{
		// register: 2
		register int i;
	}
}


// address: 0x8005B7D4
// line start: 443
// line end:   444
int height__4FontPc(struct Font_duplicate_s0 *this, char *str) {
}


// address: 0x8005B820
// line start: 451
// line end:   464
int heightAboveBaseline__4FontPc(struct Font_duplicate_s0 *this, char *str) {
	// register: 17
	register int max_h;
	{
		// register: 3
		register int i;
	}
}


// address: 0x8005B8D4
// line start: 471
// line end:   484
int heightBelowBaseline__4FontPc(struct Font_duplicate_s0 *this, char *str) {
	// register: 17
	register int max_h;
	{
		// register: 2
		register int i;
	}
}


// address: 0x8005B98C
// line start: 491
// line end:   540
int getCharIndex__4Fontc(struct Font_duplicate_s0 *this, char asc) {
	// register: 3
	register int myCharMap;
}


// address: 0x8005BC20
// line start: 550
// line end:   563
int isEscapeChar__4Fontc(struct Font_duplicate_s0 *this, char asc) {
}


// address: 0x8005BCC0
// line start: 570
// line end:   627
void handleEscapeChar__4Fontc(struct Font_duplicate_s0 *this, char asc) {
	// register: 4
	register int escCode;
}


// address: 0x8005BE14
// line start: 637
// line end:   644
int fixedWidth__4FontPc(struct Font_duplicate_s0 *this, char *pString) {
	// register: 17
	register int width;
}


// address: 0x8005BE7C
// line start: 652
// line end:   676
int fixedCharWidth__4Fontc(struct Font_duplicate_s0 *this, char asc) {
	// register: 17
	register int charWidth;
}


// address: 0x8005BF24
// line start: 684
// line end:   687
void setRGB__4Fontiii(struct Font_duplicate_s0 *this, int r, int g, int b) {
}


// address: 0x8005BF34
// line start: 696
// line end:   697
void SetTextEffect__4FontP10TextEffect(struct Font_duplicate_s0 *this, struct TextEffect *pEffect) {
}


// address: 0x8005BF3C
// line start: 715
// line end:   725
void unload__4Font(struct Font_duplicate_s0 *this) {
	{
		// register: 16
		register int i;
	}
}


// address: 0x8005BFEC
// size: 0x50
// line start: 745
// line end:   759
struct Font_duplicate_s0 *LoadFont__11FontManagerPc(char *filename) {
	// register: 17
	register unsigned char *pData;
}


// address: 0x8005C058
// size: 0x50
// line start: 766
// line end:   786
struct Font_duplicate_s0 *LoadFont__11FontManagerPUcPc(unsigned char *pData, char *fontname) {
	// register: 16
	register int slot;
}


// address: 0x8005C10C
// size: 0x50
// line start: 793
// line end:   800
struct Font_duplicate_s0 *GetFont__11FontManagerPc(char *fontname) {
	// register: 16
	register int slot;
}


// address: 0x8005C180
// line start: 807
// line end:   817
void UnloadFont__11FontManagerPc(char *fontname) {
	// register: 16
	register int slot;
}


// address: 0x8005C228
// line start: 92
// line end:   92
void ___6CClass_addr_8005C228(struct CClass *this, int __in_chrg) {
}


// address: 0x8005C258
// line start: 44
// line end:   52
void SetClippingBox2__Fiiii(int x, int y, int w, int h) {
	// address: 0xFFFFFFF0
	// size: 0x8
	auto struct RECT r;
	// register: 16
	// size: 0xC
	register struct DR_AREA *pClip;
}


// address: 0x8005C2FC
// line start: 60
// line end:   79
void MakeTransparentClut2__Fii(int x, int y) {
	// register: 18
	register unsigned short *buf;
	// address: 0xFFFFFFE8
	// size: 0x8
	auto struct RECT temp;
	// register: 3
	register unsigned short *buf2;
	{
		// register: 4
		register int i;
	}
}


// address: 0x8005C3B8
// line start: 95
// line end:   209
int Load8BitBMP_2__FPcPPcPiT2PUs(char *pData, char **data, int *ww, int *hh, unsigned short *clut) {
	// register: 23
	register int clutx;
	// register: 22
	register int cluty;
	// register: 17
	register int w;
	// register: 19
	register int h;
	// register: 18
	register int colors;
	// register: 20
	register int transparent_color;
	// address: 0xFFFFFDD0
	// size: 0x200
	auto unsigned short colorTab[256];
	// register: 9
	register char *pColor;
	// address: 0xFFFFFFD0
	// size: 0x8
	auto struct RECT r;
	// register: 16
	register int pad;
	// register: 4
	register char *in;
	// register: 5
	register char *out;
	{
		// register: 8
		register int i;
		{
			// register: 5
			register unsigned short r;
			// register: 3
			register unsigned short g;
			// register: 4
			register unsigned short b;
			{
				// register: 8
				register int j;
				// register: 8
				register int i;
				{
					{
						// register: 6
						register int i;
						{
							// register: 3
							register int i;
						}
					}
				}
			}
		}
	}
}


// address: 0x8005C610
// line start: 220
// line end:   248
int Load8BitBMP___FPcPPcPiT2PUs(char *file, char **data, int *ww, int *hh, unsigned short *clut) {
	// register: 2
	register int size;
	// register: 16
	register char *pData;
}


// address: 0x8005C6DC
// size: 0x1C
// line start: 258
// line end:   274
struct Image *__5Image(struct Image *this) {
	// register: 2
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x8005C718
// size: 0x3C
// line start: 284
// line end:   291
struct SlicedImage2 *__12SlicedImage2(struct SlicedImage2 *this) {
}


// address: 0x8005C758
// size: 0x3C
// line start: 307
// line end:   316
struct SlicedImage2 *__12SlicedImage2PviiiiUcUs(struct SlicedImage2 *this, void *pData, int width, int height, int slice_width, int slice_height, int bpp, int clut) {
}


// address: 0x8005C810
// line start: 323
// line end:   333
void ___12SlicedImage2(struct SlicedImage2 *this, int __in_chrg) {
	// register: 16
	// size: 0x1C
	register struct Image *this;
	{
		// register: 16
		// size: 0x4
		register struct CClass *this;
		{
			{
				{
				}
			}
		}
	}
}


// address: 0x8005C8A0
// line start: 353
// line end:   378
void newSlicedImage2__12SlicedImage2PviiiiUcUs(struct SlicedImage2 *this, void *pData, int width, int height, int slice_width, int slice_height, int bpp, int clut) {
}


// address: 0x8005C948
// line start: 419
// line end:   480
void setData__12SlicedImage2Pv(struct SlicedImage2 *this, void *data) {
	// register: 30
	register int remX;
	// address: 0xFFFFFFC8
	auto int remY;
	// address: 0xFFFFFFCC
	auto unsigned short *line_start;
	// register: 9
	register int j;
	// register: 22
	register unsigned short *in;
	// register: 19
	register int i;
	{
		{
			// register: 23
			register unsigned short *in;
			// register: 20
			register int i;
			{
				{
					{
						// register: 23
						register unsigned short *src;
						// register: 19
						// size: 0xC
						register struct Slice *slice;
						{
							// register: 5
							register unsigned short *out;
							// register: 17
							register unsigned short *in;
							{
								// register: 6
								register int j;
								{
									{
										// register: 4
										register int i;
										{
											// register: 23
											register unsigned short *src;
											// register: 17
											// size: 0xC
											register struct Slice *slice;
											// register: 30
											register int slicew;
											{
												// register: 5
												register unsigned short *out;
												// register: 16
												register unsigned short *in;
												{
													// register: 6
													register int j;
													{
														{
															// register: 4
															register int i;
															{
																{
																	{
																		// register: 22
																		register unsigned short *src;
																		// register: 18
																		// size: 0xC
																		register struct Slice *slice;
																		// address: 0xFFFFFFC8
																		auto int sliceh;
																		{
																			// register: 5
																			register unsigned short *out;
																			// register: 16
																			register unsigned short *in;
																			{
																				// register: 6
																				register int j;
																				{
																					{
																						// register: 4
																						register int i;
																						{
																							// register: 22
																							register unsigned short *src;
																							// register: 17
																							// size: 0xC
																							register struct Slice *slice;
																							// register: 30
																							register int slicew;
																							// address: 0xFFFFFFC8
																							auto int sliceh;
																							{
																								// register: 5
																								register unsigned short *out;
																								// register: 16
																								register unsigned short *in;
																								{
																									// register: 6
																									register int j;
																									{
																										{
																											// register: 4
																											register int i;
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8005CE7C
// line start: 488
// line end:   495
void removeFromMemory__12SlicedImage2(struct SlicedImage2 *this) {
	{
		// register: 17
		register int i;
	}
}


// address: 0x8005CF08
// line start: 503
// line end:   530
void pack__12SlicedImage2(struct SlicedImage2 *this) {
	// register: 19
	register int temp1;
	// register: 20
	register int temp2;
	{
		// register: 18
		register int i;
		{
			// address: 0xFFFFFFE0
			auto int x;
			// address: 0xFFFFFFE4
			auto int y;
		}
	}
}


// address: 0x8005D030
// line start: 540
// line end:   556
void repack__12SlicedImage2(struct SlicedImage2 *this) {
	// address: 0xFFFFFFE8
	// size: 0x8
	auto struct RECT r;
	{
		// register: 18
		register int j;
		{
			{
				// register: 16
				register int i;
			}
		}
	}
}


// address: 0x8005D114
// line start: 564
// line end:   570
void unpack__12SlicedImage2(struct SlicedImage2 *this) {
	{
		// register: 17
		register int i;
	}
}


// address: 0x8005D1A4
// line start: 577
// line end:   667
void draw__12SlicedImage2iii(struct SlicedImage2 *this, int x, int y, int drawFirst) {
	// register: 8
	// size: 0x28
	register struct POLY_FT4 *apoly;
	// register: 22
	register unsigned int *pOT;
	// register: 23
	register int just_x;
	// register: 6
	register int just_y;
	// address: 0xFFFFFFD0
	auto int dx;
	// address: 0xFFFFFFD4
	auto int dy;
	// register: 21
	register int index;
	// register: 19
	register int yt;
	{
		// register: 30
		register int j;
		{
			// register: 18
			register int xt;
			{
				// register: 20
				register int i;
			}
		}
	}
}


// address: 0x8005D764
// size: 0x3C
// line start: 676
// line end:   689
struct Sprite2 *__7Sprite2Pciii(struct Sprite2 *this, char *filename, int pack, int slice_w, int slice_h) {
	// address: 0xFFFFFFDC
	auto char *pixel_data_buf;
	// address: 0xFFFFFFE0
	auto int w;
	// address: 0xFFFFFFE4
	auto int h;
	// address: 0xFFFFFFD8
	auto unsigned short clut;
}


// address: 0x8005D850
// size: 0x3C
// line start: 698
// line end:   712
struct Sprite2 *__7Sprite2PUciii(struct Sprite2 *this, unsigned char *buffer, int pack, int slice_w, int slice_h) {
	// address: 0xFFFFFFDC
	auto char *pixel_data_buf;
	// address: 0xFFFFFFE0
	auto int w;
	// address: 0xFFFFFFE4
	auto int h;
	// address: 0xFFFFFFD8
	auto unsigned short clut;
}


// address: 0x8005D93C
// line start: 743
// line end:   746
void ___7Sprite2(struct Sprite2 *this, int __in_chrg) {
}


// address: 0x8005D9AC
// line start: 755
// line end:   778
void setData__7Sprite2Pv(struct Sprite2 *this, void *data) {
	// address: 0xFFFFFFEC
	auto char *pixel_data_buf;
	// address: 0xFFFFFFF0
	auto int w;
	// address: 0xFFFFFFF4
	auto int h;
	// address: 0xFFFFFFE8
	auto unsigned short clut;
}


// address: 0x8005DA24
// line start: 789
// line end:   790
int screenWidth__12SlicedImage2(struct SlicedImage2 *this) {
}


// address: 0x8005DA44
// line start: 800
// line end:   801
int screenHeight__12SlicedImage2(struct SlicedImage2 *this) {
}


// address: 0x8005DA60
// size: 0x40
// line start: 807
// line end:   810
struct RotateSprite *__12RotateSpritePciii(struct RotateSprite *this, char *filename, int pack, int slice_w, int slice_h) {
}


// address: 0x8005DAA4
// line start: 839
// line end:   995
void draw__12RotateSpriteiii(struct RotateSprite *this, int x, int y, int rot) {
	// register: 7
	// size: 0x28
	register struct POLY_FT4 *apoly;
	// register: 17
	register unsigned int *pOT;
	// address: 0xFFFFFFB8
	// size: 0x8
	auto int dux[2];
	// address: 0xFFFFFFC0
	// size: 0x8
	auto int duy[2];
	// address: 0xFFFFFFC8
	// size: 0x8
	auto int dvx[2];
	// address: 0xFFFFFFD0
	// size: 0x8
	auto int dvy[2];
	// register: 8
	register int aspect;
	// register: 13
	register int just_ux;
	// register: 14
	register int just_uy;
	// register: 9
	register int just_vx;
	// register: 11
	register int just_vy;
	// register: 4
	register int just_u;
	// register: 3
	register int just_v;
	// register: 20
	register int xbig1;
	// register: 19
	register int ybig1;
	// register: 21
	register int slice_type_y;
	{
		// register: 11
		register int i;
		{
			// register: 16
			register int j;
			// register: 11
			register int i;
			{
				// register: 11
				register int xbig2;
				// register: 9
				register int ybig2;
				// register: 25
				register int slice_type_x;
				{
					// register: 12
					register int i;
				}
			}
		}
	}
}


// address: 0x8005E158
// line start: 208
// line end:   208
void ___12RotateSprite(struct RotateSprite *this, int __in_chrg) {
}


// address: 0x8005E1AC
// line start: 40
// line end:   40
void draw__5Imageii(struct Image *this, int x, int y) {
}


// address: 0x8005E1B4
// line start: 38
// line end:   38
void ___5Image(struct Image *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x8005E1E4
// line start: 92
// line end:   92
void ___6CClass_addr_8005E1E4(struct CClass *this, int __in_chrg) {
}


// address: 0x800674F8
// line start: 126
// line end:   164
void Spool_Init__Fv() {
	// register: 4
	register int i;
}


// address: 0x80067618
// line start: 171
// line end:   183
int Spool_FreeRegion__Fv() {
	// register: 5
	register int freeregion;
	{
		// register: 3
		register int i;
	}
}


// address: 0x80067658
// line start: 231
// line end:   247
unsigned int Spool_GetModel__FUii(unsigned int Checksum, int Region) {
	// register: 5
	register unsigned int NumModels;
	// register: 3
	register unsigned int *pChecksums;
	{
		// register: 7
		register unsigned int i;
	}
}


// address: 0x800676A8
// size: 0x24
// line start: 253
// line end:   273
struct Item *Spool_FindEnviroItem__FUi(unsigned int Checksum) {
	// register: 5
	// size: 0x24
	register struct Item *pItem;
	// register: 6
	register int Region;
	// register: 7
	register unsigned int *pChecksums;
}


// address: 0x80067720
// size: 0x28
// line start: 292
// line end:   314
struct Texture *NewTextureEntry__FUi(unsigned int checksum) {
	// register: 5
	// size: 0x28
	register struct Texture *pNew;
	// register: 7
	register unsigned int Lower;
}


// address: 0x800677B0
// line start: 318
// line end:   329
void RemoveTextureEntry__FP7Texture(struct Texture *pEntry) {
	// register: 2
	register unsigned int Lower;
}


// address: 0x80067848
// size: 0x28
// line start: 337
// line end:   342
struct Texture *Spool_FindTextureEntry__FUi(unsigned int checksum) {
	// register: 3
	// size: 0x28
	register struct Texture *pSearch;
}


// address: 0x80067894
// line start: 348
// line end:   351
void GotoStartOfTextureList__Fv() {
}


// address: 0x800678AC
// size: 0x28
// line start: 355
// line end:   380
struct Texture *NextTexture__Fv() {
	// register: 2
	// size: 0x28
	register struct Texture *pReturnedTex;
}


// address: 0x80067930
// line start: 384
// line end:   395
unsigned int *Spool_SkipPackets__FPUi(unsigned int *pPSX) {
	// register: 4
	register unsigned int *pPacket;
	{
		// register: 3
		register int NumBytes;
	}
}


// address: 0x80067978
// line start: 403
// line end:   438
void DecrementTextureUsage__Fi(int region) {
	// register: 4
	register unsigned int *pPSX;
	// register: 3
	register unsigned int *pNumModels;
	// register: 16
	register unsigned int NumModels;
	// register: 2
	register unsigned int *ChecksumTable;
	// register: 7
	register unsigned int NumChecksums;
	{
		// register: 6
		register int i;
	}
}


// address: 0x80067A1C
// line start: 441
// line end:   471
void Spool_RemoveUnusedTextures__Fv() {
	// register: 16
	// size: 0x28
	register struct Texture *pTex;
}


// address: 0x80067AB4
// line start: 506
// line end:   857
void ProcessNewPSX__Fi(int region) {
	// register: 19
	register unsigned int *pPSX;
	// register: 3
	register int NumItems;
	// register: 21
	// size: 0x24
	register struct SModel **ppModels;
	// register: 18
	register unsigned int NumModels;
	// register: 20
	register unsigned int *ChecksumTable;
	// register: 22
	register unsigned int NumChecksums;
	// register: 20
	register unsigned int GeometryAndTableSize;
	// register: 16
	register unsigned int *pPaletteInfo;
	// register: 18
	register unsigned int Num16CPalettes;
	// register: 18
	register unsigned int Num256CPalettes;
	// register: 16
	register unsigned int *pPacket;
	// register: 20
	register int AnimPacketFound;
	// register: 4
	register int PacketType;
	{
		// register: 5
		register int i;
		{
			// register: 17
			register int i;
			{
				// register: 3
				// size: 0x28
				register struct Texture *pTextureEntry;
				{
					// register: 9
					register int m;
					// register: 5
					register int i;
					{
						// register: 2
						// size: 0x24
						register struct SModel *pModel;
						// register: 3
						register unsigned int NumVertices;
						// register: 4
						register unsigned int NumNormals;
						// register: 7
						register unsigned int NumFaces;
						// register: 4
						register unsigned int *pFace;
						{
							// register: 6
							register int j;
							{
								// register: 17
								register int i;
								{
									// register: 17
									register int i;
									{
										// register: 17
										register int NumBytes;
										{
											{
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80067FFC
// line start: 868
// line end:   886
void AttachNewEnviro__Fi(int region) {
	{
		{
			// register: 5
			// size: 0x24
			register struct Item *pScan;
			// register: 4
			// size: 0x24
			register struct Item *pStart;
		}
	}
}


// address: 0x800680AC
// line start: 891
// line end:   1144
void Spool_LoadTexturesToVRAM__Fii(int Region, int defrag) {
	// address: 0xFFFFFFC8
	auto unsigned int *pPSX;
	// register: 3
	register unsigned int *pStuff;
	// register: 3
	register int NumModels;
	// register: 4
	register int Temp;
	// address: 0xFFFFFFCC
	// size: 0x28
	auto struct Texture **TextureLookup;
	// register: 30
	register unsigned int *pTextureInfo;
	// address: 0xFFFFFFD0
	auto unsigned int NumTextures;
	{
		// address: 0xFFFFFFD4
		auto int i;
		{
			// register: 16
			register unsigned int *pTexture;
			// register: 18
			register unsigned int Flags;
			// register: 23
			register unsigned int NumColours;
			// register: 4
			register unsigned int PaletteChecksum;
			// register: 2
			register unsigned int TextureIndex;
			// register: 17
			// size: 0x28
			register struct Texture *pTextureEntry;
			{
				{
					// register: 20
					// size: 0x14
					register struct tag_S_Pal *pPal;
					{
						{
							// register: 22
							register unsigned short Width;
							// register: 19
							register unsigned short Height;
							// register: 21
							register unsigned int *pTextureData;
							// address: 0xFFFFFFC0
							auto int x;
							// address: 0xFFFFFFC4
							auto int y;
							{
								{
									// register: 16
									register int AlignedWidth;
									// address: 0xFFFFFFB8
									// size: 0x8
									auto struct RECT rec;
									// register: 6
									register unsigned char remap;
									{
										{
											// register: 7
											register int Size;
											// register: 3
											register unsigned char *pRemap;
											{
												// register: 5
												register int i;
												{
													// register: 4
													register unsigned char x;
													{
														{
															// register: 16
															register int AlignedWidth;
															// address: 0xFFFFFFB8
															// size: 0x8
															auto struct RECT rec;
															{
																{
																	// register: 4
																	register int Size;
																	// register: 3
																	register unsigned char hi;
																	// register: 10
																	register unsigned char lo;
																	// register: 6
																	register unsigned char *pRemap;
																	{
																		// register: 7
																		register int i;
																		{
																			// register: 2
																			register unsigned char x;
																			// register: 9
																			register unsigned char y;
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80068558
// line start: 1201
// line end:   1233
void DetachOldEnviro__FUc(unsigned char index) {
	// register: 6
	// size: 0x24
	register struct Item *pThisStart;
	// register: 9
	// size: 0x24
	register struct Item *pOtherStart;
	// register: 3
	// size: 0x24
	register struct Item *pScan;
}


// address: 0x80068624
// line start: 1236
// line end:   1241
int Spool_FindRegion__FPc(char *pName) {
	{
		// register: 16
		register int i;
	}
}


// address: 0x8006868C
// line start: 1245
// line end:   1254
void Spool_ClearPSX__FPc(char *pName) {
}


// address: 0x800686E8
// line start: 1260
// line end:   1274
void Spool_ClearAllPSXs__Fv() {
	{
		// register: 16
		register int i;
	}
}


// address: 0x80068758
// line start: 1288
// line end:   1340
void ClearRegion__Fiii(int Region, int cleanuptextures, int KeepInMemory) {
	{
		{
			// register: 16
			register int EnvIndex;
		}
	}
}


// address: 0x800688B0
// line start: 1356
// line end:   1364
void Spool_ClearEnvironmentRegions__Fv() {
}


// address: 0x800688FC
// line start: 1369
// line end:   1431
void PreProcessAnimPacket__FPUiT0(unsigned int *pPSX, unsigned int *pPacket) {
	// register: 17
	// size: 0x28
	register struct Texture **pTextures;
	// register: 2
	// size: 0x8
	register struct AnimPacket *pNewAnimPacket;
	// register: 10
	register unsigned int NumAnims;
	{
		// register: 9
		register unsigned int i;
		{
			// register: 8
			register unsigned int NumFrames;
			{
				// register: 7
				register unsigned int j;
				{
					// register: 2
					register unsigned int index;
				}
			}
		}
	}
}


// address: 0x80068A18
// size: 0x8
// line start: 1461
// line end:   1520
struct SAnimFrame *Spool_FindAnim__FPc(char *pName) {
	// register: 14
	// size: 0x8
	register struct SAnimFrame *pAnim;
	// register: 11
	// size: 0x8
	register struct AnimPacket *pPacketInfo;
	{
		// register: 12
		register unsigned int NumAnims;
		// register: 9
		register char *pAnimName;
		// register: 13
		register int found;
		{
			// register: 10
			register int i;
			{
				// register: 5
				register char lettera;
				// register: 3
				register char letterb;
				// register: 6
				register char *pA;
				// register: 8
				register char *pB;
				// register: 7
				register int count;
				// register: 2
				register unsigned int NumFrames;
			}
		}
	}
}


// address: 0x80068AF4
// line start: 1531
// line end:   1542
void LoadNameExt__FPcT0(char *Name, char *Ext) {
	// register: 7
	register char *from;
	// register: 3
	register char *to;
	// register: 8
	register char *p;
}


// address: 0x80068B64
// line start: 1550
// line end:   1626
int Spool_PSX__FPciii(char *Name, int IsEnviro, int KeepTextures, int WhichHeap) {
	// register: 16
	register int freeregion;
	{
		// register: 17
		register int i;
		{
			// register: 10
			register int i;
			{
				{
					{
						// register: 5
						register char *pQName;
						// register: 4
						register char *pPSXName;
						// register: 6
						register int Identical;
						{
							{
								// register: 6
								register char *pNew;
								// register: 5
								register char *pDest;
								// register: 7
								register int c;
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80068DE0
// line start: 1632
// line end:   1636
int Spool_GetEnvIndex__Fi(int region) {
}


// address: 0x80068E10
// line start: 1641
// line end:   1766
void Spool_Continue__Fv() {
	// address: 0x00000034
	static int SpoolMode;
	// register: 18
	// size: 0x11
	register struct SQueue *Q;
	{
		{
			{
				{
					// register: 20
					register int FileSize;
					{
						{
							// register: 6
							register char *pNew;
							// register: 5
							register char *pDest;
							// register: 7
							register int c;
							{
								{
									// register: 17
									register unsigned int *Temp;
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80069228
// line start: 1774
// line end:   1779
void Spool_Sync__Fv() {
}


// address: 0x800692BC
// line start: 1792
// line end:   1828
void Spool_StripAnim__Fi(int Region) {
	// register: 18
	register char *pPSX;
	// register: 16
	register char *pAnim;
	// register: 4
	register unsigned int *pStuff;
	// register: 6
	register int NumModels;
	// register: 16
	register unsigned int *pDest;
	// register: 6
	register int NumTextures;
	// register: 16
	register int NewModelLen;
	{
		// register: 5
		register int i;
		{
			// register: 5
			register int i;
		}
	}
}


// address: 0x800693B4
// line start: 1836
// line end:   1972
void Spool_StripModel__FiPs(int AnimRegion, short *pAnimationList) {
	// register: 9
	register unsigned int *pAnimPSX;
	// register: 12
	register unsigned int *pAnimAnim;
	// register: 14
	register unsigned int *pAnimHierarchy;
	// register: 24
	register int HierarchyLen;
	// register: 13
	register int NumAnims;
	// register: 10
	register char *pSourceBytes;
	// register: 4
	register char *pDestBytes;
	// register: 6
	register short *pDA;
	// address: 0xFFFFFDE8
	// size: 0x200
	auto char AnimUsed[512];
	// register: 16
	register int NewLen;
	{
		// register: 11
		register int i;
		{
			// register: 5
			register int i;
			{
				// register: 6
				register int i;
				{
					// register: 5
					register char *pNextSource;
					{
						// register: 3
						register int i;
					}
				}
			}
		}
	}
}


// address: 0x80069690
// line start: 1977
// line end:   2014
int Spool_GetReducedSkater__FPcT0(char *modelFile, char *animFile) {
	// register: 17
	register int ModelRegion;
	// register: 16
	register int AnimRegion;
}


// address: 0x80069768
// line start: 2022
// line end:   2092
char *Spool_LoadPSH__FPcPPcPii(char *pPSHName, char **pHierarchyArray, int *pPartCount, int maxPartNames) {
	// address: 0xFFFFFFC8
	// size: 0x10
	auto char filename[16];
	// address: 0xFFFFFFD8
	// size: 0x10
	auto char prefixString[16];
	// register: 18
	register char *pData;
	// register: 16
	register int prefixStringLength;
	// register: 17
	register char *p;
}


// address: 0x800698E8
// line start: 105
// line end:   140
void Pad_InitAtStart__Fv() {
	{
		// register: 11
		register int i;
	}
}


// address: 0x80069998
// line start: 145
// line end:   148
void Pad_LockAnalog__Fv() {
}


// address: 0x800699D0
// line start: 153
// line end:   159
void Pad_ClearAllOne__Fi(int pad) {
}


// address: 0x80069A44
// line start: 164
// line end:   171
void Pad_ClearAll__Fv() {
	{
		// register: 16
		register int i;
	}
}


// address: 0x80069A7C
// line start: 181
// line end:   197
void Pad_Clear__FP8SControl(struct SControl *p_pad) {
	// register: 4
	// size: 0x10
	register struct SButton *pBut;
	{
		// register: 6
		register int i;
	}
}


// address: 0x80069AD0
// line start: 203
// line end:   211
void Pad_ClearTriggers__FP8SControl(struct SControl *p_pad) {
	// register: 4
	// size: 0x10
	register struct SButton *pBut;
	{
		// register: 3
		register int i;
	}
}


// address: 0x80069AF0
// line start: 217
// line end:   274
void Pad_ActuatorOn__FUcUsUcUc(unsigned char index, unsigned short time, unsigned char motor, unsigned char motor_value) {
	// register: 16
	register int checkIndex;
	// register: 18
	register int state;
	// register: 3
	register unsigned char *p_motor_value;
	// register: 2
	register unsigned short *p_motor_timer;
}


// address: 0x80069C94
// line start: 279
// line end:   292
void Pad_ActuatorOff__FUcUc(unsigned char index, unsigned char motor) {
	// register: 3
	register unsigned char *p_motor_value;
	// register: 2
	register unsigned short *p_motor_timer;
}


// address: 0x80069CE4
// line start: 299
// line end:   333
void Pad_Button__FP7SButtoni(struct SButton *p_but, int state) {
}


// address: 0x80069D80
// line start: 343
// line end:   373
void ReadControllers__Fv() {
	{
		// address: 0xFFFFFFD0
		auto int controller_port;
		{
		}
	}
}


// address: 0x80069ECC
// line start: 383
// line end:   414
void ReadController__FP14ControllerDataPUc(struct ControllerData *p_controller_data, unsigned char *p_buf) {
	// register: 8
	register unsigned char old_type;
}


// address: 0x80069F88
// line start: 418
// line end:   445
int Pad_Analog__Fiiii(int x, int min, int max, int c) {
}


// address: 0x8006A020
// line start: 450
// line end:   622
int Pad_Update__Fv() {
	// register: 18
	register unsigned int pad_data;
	// register: 16
	// size: 0x10
	register struct SButton *pBut;
	// register: 16
	register unsigned short pad0;
	// register: 2
	register unsigned short pad1;
	static int olda0;
	// address: 0x00000004
	static int oldb0;
	// address: 0x00000008
	static int oldc0;
	// address: 0x0000000C
	static int oldd0;
	// address: 0x00000010
	static int olda1;
	// address: 0x00000014
	static int oldb1;
	// address: 0x00000018
	static int oldc1;
	// address: 0x0000001C
	static int oldd1;
	// register: 10
	register int a0;
	// register: 11
	register int b0;
	// register: 8
	register int c0;
	// register: 9
	register int d0;
	// register: 7
	register int a1;
	// register: 6
	register int b1;
	// register: 5
	register int c1;
	// register: 4
	register int d1;
	{
		// register: 16
		register int i;
		{
			// register: 22
			register int p;
			// register: 16
			register int i;
			{
				// register: 20
				register int p;
			}
		}
	}
}


// address: 0x8006A5B4
// line start: 629
// line end:   654
void Pad_Restore__Fv() {
	// address: 0xFFFFFFA0
	// size: 0x10
	auto struct SButton TempButtonTriangle;
	// address: 0xFFFFFFB0
	// size: 0x10
	auto struct SButton TempButtonX;
	// address: 0xFFFFFFC0
	// size: 0x10
	auto struct SButton TempButtonCircle;
	// address: 0xFFFFFFD0
	// size: 0x10
	auto struct SButton TempButtonSquare;
	{
		// register: 10
		register int i;
		{
			{
				{
					// address: 0xFFFFFFE0
					// size: 0x10
					auto struct SButton Temp;
				}
			}
		}
	}
}


// address: 0x8006A7D0
// line start: 660
// line end:   683
void Pad_Remap__Fv() {
	// address: 0xFFFFFF90
	// size: 0x10
	auto struct SButton TempButtonTriangle;
	// address: 0xFFFFFFA0
	// size: 0x10
	auto struct SButton TempButtonX;
	// address: 0xFFFFFFB0
	// size: 0x10
	auto struct SButton TempButtonCircle;
	// address: 0xFFFFFFC0
	// size: 0x10
	auto struct SButton TempButtonSquare;
	{
		// register: 13
		register int i;
		{
			{
				{
					// address: 0xFFFFFFD0
					// size: 0x10
					auto struct SButton Temp;
				}
			}
		}
	}
}


// address: 0x8006AA00
// line start: 47
// line end:   56
void ___11CTextWindow(struct CTextWindow *this, int __in_chrg) {
	// register: 16
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x8006AAB0
// line start: 92
// line end:   92
void ___6CClass_addr_8006AAB0(struct CClass *this, int __in_chrg) {
}


// address: 0x8006B6C0
// size: 0x40
// line start: 17
// line end:   24
struct Dust *__4Dust(struct Dust *this) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
		{
			// register: 5
			register int i;
		}
	}
}


// address: 0x8006B6F4
// line start: 32
// line end:   47
void ___4Dust(struct Dust *this, int __in_chrg) {
	// register: 18
	// size: 0x4
	register struct CClass *this;
	{
		{
			{
				// register: 17
				register int i;
			}
		}
	}
}


// address: 0x8006B7A4
// line start: 53
// line end:   73
void Reset__4Dustii(struct Dust *this, int terrainType, int dustType) {
	// address: 0xFFFFFFE8
	auto short scale;
	// address: 0xFFFFFFEA
	auto unsigned char tint;
	// address: 0xFFFFFFEC
	auto short transDecay;
	// address: 0xFFFFFFEE
	auto short scaleDecay;
	// address: 0xFFFFFFF0
	auto int randomOffset;
}


// address: 0x8006B814
// line start: 81
// line end:   194
void Update__4DustP6CBruce(struct Dust *this, struct CBruce_duplicate_s0 *pBruce) {
	// address: 0xFFFFFFC0
	auto short scale;
	// address: 0xFFFFFFC2
	auto unsigned char tint;
	// address: 0xFFFFFFC4
	auto short transDecay;
	// address: 0xFFFFFFC6
	auto short scaleDecay;
	// address: 0xFFFFFFE4
	auto int randomOffset;
	// address: 0xFFFFFFE0
	auto int dummy;
	// register: 16
	// size: 0x70
	register struct CFlatBit *pDust;
	{
		// register: 17
		register int i;
		{
			{
				{
					// register: 6
					register int done;
					{
						// register: 5
						register int i;
						{
							{
								{
									// register: 17
									register int i;
									{
										{
											// address: 0xFFFFFFC8
											// size: 0xC
											auto struct CVector tempVector;
											// address: 0xFFFFFFD8
											// size: 0x8
											auto struct SHook hook;
											{
												{
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8006BB60
// line start: 200
// line end:   232
void insert_dust__4DustP8CFlatBit(struct Dust *this, struct CFlatBit *pDust) {
	// register: 9
	register int unusedSlot;
	// register: 8
	register int dimmestColor;
	{
		// register: 6
		register int i;
		{
			// register: 3
			register int newColor;
		}
	}
}


// address: 0x8006BC48
// line start: 238
// line end:   251
void get_terrain_parameters__4DustiPsPUcT2T2PiPi(struct Dust *this, int terrainType, short *pScale, unsigned char *pTint, short *pTransDecay, short *pScaleDecay, int *pNumClouds, int *pRandomOffset) {
}


// address: 0x8006BCF8
// line start: 257
// line end:   296
void get_land_terrain_parameters__4DustiPsPUcT2T2PiPi(struct Dust *this, int terrainType, short *pScale, unsigned char *pTint, short *pTransDecay, short *pScaleDecay, int *pNumClouds, int *pRandomOffset) {
}


// address: 0x8006BD94
// line start: 304
// line end:   345
void get_bail_terrain_parameters__4DustiPsPUcT2T2PiPi(struct Dust *this, int terrainType, short *pScale, unsigned char *pTint, short *pTransDecay, short *pScaleDecay, int *pNumClouds, int *pRandomOffset) {
}


// address: 0x8006BE4C
// line start: 353
// line end:   393
void get_brake_terrain_parameters__4DustiPsPUcT2T2PiPi(struct Dust *this, int terrainType, short *pScale, unsigned char *pTint, short *pTransDecay, short *pScaleDecay, int *pNumClouds, int *pRandomOffset) {
}


// address: 0x8006BF0C
// line start: 401
// line end:   420
void apply_random_offset__4DustR7CVectorii(struct Dust *this, struct CVector *pos, int randomRange, int shiftAmount) {
	// register: 2
	register int offset;
}


// address: 0x8006BF8C
// line start: 92
// line end:   92
void ___6CClass_addr_8006BF8C(struct CClass *this, int __in_chrg) {
}


// address: 0x8006BFBC
// size: 0x8
// line start: 22
// line end:   23
struct TextEffect *__10TextEffect(struct TextEffect *this) {
	// register: 2
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x8006BFD4
// line start: 31
// line end:   36
void ___10TextEffect(struct TextEffect *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x8006C004
// line start: 42
// line end:   50
void bind__10TextEffectP4Font(struct TextEffect *this, struct Font_duplicate_s0 *pFont) {
}


// address: 0x8006C038
// line start: 56
// line end:   63
void unbind__10TextEffectP4Font(struct TextEffect *this, struct Font_duplicate_s0 *pFont) {
}


// address: 0x8006C068
// line start: 69
// line end:   76
void getScreenPos__10TextEffectPiT1(struct TextEffect *this, int *pX, int *pY) {
}


// address: 0x8006C070
// line start: 82
// line end:   89
void getColor__10TextEffectPUcN21(struct TextEffect *this, unsigned char *pR, unsigned char *pG, unsigned char *pB) {
}


// address: 0x8006C078
// line start: 95
// line end:   99
void PostEffect__10TextEffectiiii(struct TextEffect *this) {
}


// address: 0x8006C080
// line start: 105
// line end:   107
void disable__10TextEffect(struct TextEffect *this) {
}


// address: 0x8006C088
// size: 0x120
// line start: 115
// line end:   117
struct FallingTextEffect *__17FallingTextEffect(struct FallingTextEffect *this) {
}


// address: 0x8006C0C0
// line start: 125
// line end:   125
void ___17FallingTextEffect(struct FallingTextEffect *this, int __in_chrg) {
}


// address: 0x8006C114
// line start: 133
// line end:   134
void SetBloodiness__17FallingTextEffecti(struct FallingTextEffect *this, int bloody) {
}


// address: 0x8006C11C
// line start: 142
// line end:   160
void init__17FallingTextEffect(struct FallingTextEffect *this) {
	{
		// register: 20
		register int i;
	}
}


// address: 0x8006C1EC
// line start: 168
// line end:   182
void update__17FallingTextEffect(struct FallingTextEffect *this) {
	{
		// register: 6
		register int i;
	}
}


// address: 0x8006C25C
// line start: 187
// line end:   231
void PostEffect__17FallingTextEffectiiii(struct FallingTextEffect *this, int oldX, int oldY, int ScreenX, int ScreenY) {
	{
		{
			// register: 18
			register int clipX;
			// register: 19
			register int clipY;
			// register: 6
			register int clipW;
			// register: 7
			register int clipH;
		}
	}
}


// address: 0x8006C36C
// line start: 237
// line end:   275
void getScreenPos__17FallingTextEffectPiT1(struct FallingTextEffect *this, int *pX, int *pY) {
	// register: 3
	register int gravityIdx;
	// register: 7
	register int gravShifted;
}


// address: 0x8006C424
// line start: 281
// line end:   292
void getColor__17FallingTextEffectPUcN21(struct FallingTextEffect *this, unsigned char *pR, unsigned char *pG, unsigned char *pB) {
}


// address: 0x8006C44C
// line start: 298
// line end:   300
void setScale__17FallingTextEffecti(struct FallingTextEffect *this, int scale) {
}


// address: 0x8006C454
// line start: 308
// line end:   322
void bind__17FallingTextEffectP4Font(struct FallingTextEffect *this, struct Font_duplicate_s0 *pFont) {
}


// address: 0x8006C4A8
// line start: 328
// line end:   333
int handleComplete__17FallingTextEffect(struct FallingTextEffect *this) {
}


// address: 0x8006C4C0
// line start: 340
// line end:   402
void drawBloodyFrame__17FallingTextEffectiii(struct FallingTextEffect *this, int x, int y, int width) {
	{
		{
			{
				{
					// register: 2
					register int r;
					// register: 4
					register int g;
					// register: 5
					register int b;
				}
			}
		}
	}
}


// address: 0x8006C578
// line start: 413
// line end:   416
void InitSprite__17FallingTextEffect() {
}


// address: 0x8006C5C8
// line start: 424
// line end:   427
void FreeSprite__17FallingTextEffect() {
}


// address: 0x8006C600
// size: 0x18
// line start: 455
// line end:   456
struct TrickTextEffect *__15TrickTextEffect(struct TrickTextEffect *this) {
}


// address: 0x8006C638
// line start: 466
// line end:   466
void ___15TrickTextEffect(struct TrickTextEffect *this, int __in_chrg) {
}


// address: 0x8006C68C
// line start: 483
// line end:   560
void bind__15TrickTextEffectP4Font(struct TrickTextEffect *this, struct Font_duplicate_s0 *pFont) {
	// register: 6
	register int Steady;
	// register: 7
	register int Grown;
	{
		{
			{
				// register: 5
				register int A;
				// register: 6
				register int B;
				// register: 3
				register int Pos;
				{
					{
						// register: 7
						register int B;
						// register: 3
						register int Pos;
						{
							{
								// register: 7
								register int A;
								// register: 6
								register int B;
								// register: 3
								register int Pos;
								{
									{
										// register: 6
										register int A;
										// register: 3
										register int Pos;
										{
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8006C86C
// line start: 566
// line end:   574
void init__15TrickTextEffect(struct TrickTextEffect *this) {
}


// address: 0x8006C880
// line start: 582
// line end:   591
void update__15TrickTextEffect(struct TrickTextEffect *this) {
}


// address: 0x8006C8D0
// line start: 597
// line end:   628
void getColor__15TrickTextEffectPUcN21(struct TrickTextEffect *this, unsigned char *pR, unsigned char *pG, unsigned char *pB) {
	{
		// register: 3
		register int Pos;
		{
			{
				{
				}
			}
		}
	}
}


// address: 0x8006C968
// line start: 633
// line end:   638
int handleComplete__15TrickTextEffect(struct TrickTextEffect *this) {
}


// address: 0x8006C988
// line start: 645
// line end:   650
void Bail__15TrickTextEffect(struct TrickTextEffect *this) {
}


// address: 0x8006C9A0
// line start: 92
// line end:   92
void ___6CClass_addr_8006C9A0(struct CClass *this, int __in_chrg) {
}


// address: 0x800632BC
// line start: 125
// line end:   192
void HiRes_Init__Fb(bool clear_screen) {
}


// address: 0x800632C4
// line start: 231
// line end:   234
void HiRes_ClearOTag__Fv() {
}


// address: 0x800632FC
// line start: 247
// line end:   276
void HiRes_DrawOTag__Fv() {
}


// address: 0x8006337C
// line start: 354
// line end:   369
void HiRes_TitleScreen__Fv() {
	// address: 0xFFFFFFF0
	// size: 0x8
	auto struct RECT r;
}


// address: 0x800633B8
// line start: 376
// line end:   385
void kickIt__Fii(int Selected, int guy) {
}


// address: 0x8006341C
// size: 0x21C
// line start: 44
// line end:   113
struct CCar *__4CCarPsii(struct CCar *this, short *pInfo, int NodeIndex, int Type) {
	{
		// register: 17
		// size: 0x190
		register struct CSuper *this;
		{
		}
	}
}


// address: 0x80063600
// line start: 130
// line end:   137
void ___4CCar(struct CCar *this, int __in_chrg) {
}


// address: 0x80063664
// line start: 151
// line end:   156
int GetDeltaAngle__Fii(int StartAngle, int EndAngle) {
	// register: 5
	register int d;
}


// address: 0x80063690
// line start: 160
// line end:   329
void CollideWithSkater__FP4CCarP6CBruceRC6MATRIXPs(struct CCar *pCar, struct CBruce_duplicate_s0 *pSkater, struct MATRIX *tm, short *pBox) {
	{
		{
			// address: 0xFFFFFFC0
			// size: 0x10
			auto struct VECTOR OldPos;
			// address: 0xFFFFFFD0
			// size: 0x10
			auto struct VECTOR Pos;
			// register: 2
			register int OldX;
			// register: 4
			register int OldY;
			// register: 3
			register int OldZ;
			// register: 6
			register int NewX;
			// register: 5
			register int NewY;
			// register: 7
			register int NewZ;
			// register: 8
			register int XMin;
			// register: 6
			register int XMax;
			// register: 9
			register int YMin;
			// register: 7
			register int YMax;
			// register: 5
			register int ZMin;
			// register: 4
			register int ZMax;
			// register: 2
			register int tmp;
			{
				{
					{
						{
							{
								{
									// register: 4
									register int CarHeight;
									{
										{
											{
												{
													// address: 0xFFFFFFE0
													// size: 0x6
													auto struct CSVector cone;
													{
														{
															{
																// register: 16
																register int i;
																{
																	{
																		{
																			{
																				{
																					// register: 17
																					register int vx;
																					// register: 18
																					register int vz;
																					{
																						{
																							// register: 16
																							register int t;
																							{
																								// register: 16
																								register int t;
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80063C60
// line start: 334
// line end:   353
void CollideWithSkaters__FP4CCar(struct CCar *pCar) {
	// address: 0xFFFFFFD0
	// size: 0x20
	auto struct MATRIX tm;
	// register: 2
	// size: 0x24
	register struct SModel *m;
	// register: 17
	register short *pBox;
}


// address: 0x80063D14
// line start: 360
// line end:   426
void HonkAtSkaters__FP4CCarG7CVector(struct CCar *pCar, struct CVector Front) {
	// register: 21
	register int Honk;
	{
		// register: 19
		register int Skater;
		{
			{
				{
					// register: 6
					register int LeftZ;
					// register: 17
					register int VecX;
					// register: 16
					register int VecZ;
					{
						{
							// register: 3
							register int RightX;
						}
					}
				}
			}
		}
	}
}


// address: 0x80063EE4
// line start: 429
// line end:   588
void AI__4CCar(struct CCar *this) {
	// address: 0xFFFFFF90
	// size: 0xC
	auto struct CVector SegStart;
	// address: 0xFFFFFFA0
	// size: 0xC
	auto struct CVector SegEnd;
	// address: 0xFFFFFFB0
	// size: 0xC
	auto struct CVector SegDir;
	// register: 16
	register int Speed;
	// register: 21
	register int InitialSpeed;
	// register: 3
	register int RemainingSpeed;
	// register: 20
	register int NextSegment;
	// register: 18
	register int Length;
	// register: 19
	register int t;
	// register: 6
	register int MajorAxis;
	// address: 0xFFFFFFD0
	auto int FirstTimeThroughLoop;
	// register: 16
	register int TargetAngle;
	// register: 4
	register int d;
	{
		{
			// register: 20
			register int t;
			{
				{
					{
						{
							{
								{
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x800643F8
// line start: 607
// line end:   639
int ExecuteCommand__4CCarUs(struct CCar *this, unsigned short command) {
}


// address: 0x80064400
// line start: 150
// line end:   161
void Panel_Line__Fiiiii(int x0, int y0, int x1, int y1, int Color) {
	// register: 9
	// size: 0x10
	register struct LINE_F2 *aline;
	// register: 3
	register unsigned char *newppoly;
}


// address: 0x80064480
// line start: 174
// line end:   188
void Panel_BalanceUD__Fiiiiiii(int Balance, int Max, int Length, int x, int y, int LineColor, int MarkerColor) {
	// register: 21
	register int ShadowColor;
}


// address: 0x80064614
// line start: 195
// line end:   199
void Panel_addPrim__FPv(void *prim) {
}


// address: 0x80064668
// line start: 236
// line end:   257
void Panel_Init__Fv() {
}


// address: 0x80064710
// line start: 261
// line end:   274
void Panel_Uninit__Fv() {
}


// address: 0x800647A0
// line start: 313
// line end:   386
void Panel_Update__Fv() {
}


// address: 0x800647A8
// size: 0x28
// line start: 391
// line end:   422
struct POLY_FT4 *Panel_DrawTexturedPoly__FP10SAnimFrame(struct SAnimFrame *pFrame) {
	// register: 8
	// size: 0x28
	register struct POLY_FT4 *apoly;
	// register: 5
	register unsigned char *newppoly;
	// register: 2
	// size: 0x28
	register struct Texture *stored;
	// register: 4
	register unsigned int foo1;
	// register: 3
	register unsigned int foo2;
	// register: 5
	register unsigned int foo3;
}


// address: 0x8006485C
// line start: 426
// line end:   441
void Panel_SetStretchedScreenCoords__FiiP8POLY_FT4P10SAnimFrame(int x, int y, struct POLY_FT4 *pPol, struct SAnimFrame *pFrame) {
	// register: 2
	register int Width;
	// register: 11
	register int Height;
	// register: 9
	register int OffX;
	// register: 3
	register int OffY;
}


// address: 0x800648D8
// size: 0x18
// line start: 464
// line end:   490
struct POLY_F4 *Panel_DrawFlatShadedPoly__FiiiiUcUcUci(int x, int y, int w, int h, int r, int g, int b, int sort) {
	// register: 9
	// size: 0x18
	register struct POLY_F4 *apoly;
	// register: 3
	register unsigned char *newppoly;
}


// address: 0x800649B8
// size: 0x24
// line start: 497
// line end:   522
struct POLY_G4 *DrawGouraudPoly__FiiiiUcUcUcUcUcUci(int x, int y, int w, int h, int rtop, int gtop, int btop, int rbottom, int gbottom, int bbottom, int sort) {
	// register: 9
	// size: 0x24
	register struct POLY_G4 *apoly;
	// register: 3
	register unsigned char *newppoly;
}


// address: 0x80064AC8
// line start: 607
// line end:   657
void DisplayTapesSkate__Fv() {
	{
		{
			{
			}
		}
	}
}


// address: 0x80064CFC
// line start: 662
// line end:   673
void GraffitiColor__FP6CBruce(struct CBruce_duplicate_s0 *pBruce) {
}


// address: 0x80064D8C
// line start: 690
// line end:   860
void DisplayScore__FP6CBruceUsUs(struct CBruce_duplicate_s0 *pBruce, unsigned short xpos, unsigned short ypos) {
	// register: 22
	register int DoDisplay;
	{
		{
			// register: 18
			register int r;
			// register: 17
			register int g;
			// register: 16
			register int b;
			{
				{
					// address: 0xFFFFFFD0
					// size: 0xF
					auto char score[15];
					{
						{
							// register: 17
							register int Value;
						}
					}
				}
			}
		}
	}
}


// address: 0x800653B4
// line start: 863
// line end:   872
void DisplaySwitchness__FP6CBruceUsUs(struct CBruce_duplicate_s0 *pBruce, unsigned short xpos, unsigned short ypos) {
	// register: 8
	register int Flipped;
}


// address: 0x80065438
// line start: 877
// line end:   1014
void DisplayHolding__FP6CBruceUsUs(struct CBruce_duplicate_s0 *pBruce, unsigned short xpos, unsigned short ypos) {
	// register: 23
	register int DoDisplay;
	// address: 0xFFFFFFB0
	// size: 0xF
	auto char score[15];
	// address: 0xFFFFFFC0
	// size: 0xF
	auto char mult[15];
	// register: 20
	register unsigned int HoldingScore;
	// register: 22
	register int Mult;
	// register: 4
	register int bailing;
}


// address: 0x800656BC
// line start: 1017
// line end:   1091
void DisplayTime__FP6CBruceUsUs(struct CBruce_duplicate_s0 *pBruce, unsigned short xpos, unsigned short ypos) {
	// address: 0xFFFFFFD8
	// size: 0x8
	auto char time[8];
	// register: 18
	register int ticks;
	// register: 16
	register int mins;
	// register: 17
	register int secs;
	{
		// register: 2
		// size: 0xC0
		register struct SVideoInfo *VInfo;
		{
			{
				static int Urgent;
				{
					{
						{
							{
								{
									{
										// register: 3
										register int sub;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80065944
// line start: 1094
// line end:   1136
void Panel_GetViewportMessOffset__FiPsT1(int viewportMode, short *pOffsetX, short *pOffsetY) {
}


// address: 0x800659CC
// line start: 1141
// line end:   1196
void DisplayOutOfBounds__FP6CBruceUsUs(struct CBruce_duplicate_s0 *pBruce, unsigned short xpos, unsigned short ypos) {
	{
		{
			// address: 0xFFFFFFD8
			auto short offsetX;
			// address: 0xFFFFFFDA
			auto short offsetY;
			// register: 18
			register char *pString;
		}
	}
}


// address: 0x80065B3C
// line start: 1209
// line end:   1229
void Panel_ReplayInstructions__Fv() {
	{
		{
			{
				{
				}
			}
		}
	}
}


// address: 0x80065C1C
// line start: 1250
// line end:   1290
int TQ_SpinDisplay__10CPanelDatai(struct CPanelData *this, int i) {
	// register: 5
	register int first;
}


// address: 0x80065CB4
// line start: 1298
// line end:   1333
int TQ_SpinMultiplier__10CPanelDatai(struct CPanelData *this, int i) {
	// register: 5
	register int first;
	// register: 7
	register int spins;
}


// address: 0x80065D80
// line start: 1340
// line end:   1377
int TotalTrickScore__10CPanelData(struct CPanelData *this) {
	// register: 18
	register int score;
	{
		// register: 17
		register int i;
		{
			// register: 3
			register int count;
		}
	}
}


// address: 0x80065FB4
// line start: 1381
// line end:   1384
int TotalScore__10CPanelData(struct CPanelData *this) {
}


// address: 0x80066040
// line start: 1389
// line end:   1480
void DisplayTrick__10CPanelDataP6CBruceUsUs(struct CPanelData *this, struct CBruce_duplicate_s0 *pBruce, unsigned short xpos, unsigned short ypos) {
}


// address: 0x80066268
// line start: 1529
// line end:   1740
void Panel_Display__Fv() {
	// register: 18
	// size: 0x146C
	register struct CBruce_duplicate_s0 *pBruce;
}


// address: 0x8006665C
// line start: 1751
// line end:   1759
void Panel_PlayerInit__FUsP6CBruce(unsigned short PlayerNum, struct CBruce_duplicate_s0 *pPlayer) {
	{
		{
			{
				{
					{
						{
							{
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80066680
// line start: 1763
// line end:   1766
void Panel_TakeOff__FP6CBruce(struct CBruce_duplicate_s0 *pPlayer) {
}


// address: 0x800666A0
// line start: 1780
// line end:   1797
void Panel_HoldTrick__FP6CBrucei(struct CBruce_duplicate_s0 *pPlayer, int Points) {
}


// address: 0x800666F4
// line start: 1801
// line end:   1803
void Panel_Land__FP6CBruce(struct CBruce_duplicate_s0 *pPlayer) {
}


// address: 0x80066714
// line start: 1811
// line end:   1812
void Panel_Bail__FP6CBruce(struct CBruce_duplicate_s0 *pPlayer) {
}


// address: 0x80066734
// line start: 1821
// line end:   1843
int Panel_Letter__Fi(int Letter) {
}


// address: 0x800667E4
// line start: 1848
// line end:   1881
void Panel_Tape__Fi(int Tape) {
	// size: 0x20
	static char buf[32];
}


// address: 0x80066920
// line start: 1897
// line end:   1924
void Panel_GoalCounter__Fi(int N) {
	{
		{
			// address: 0x00000020
			// size: 0x20
			static char Msg[32];
		}
	}
}


// address: 0x800669C0
// line start: 1927
// line end:   1933
void Set__6CTrickP7MessagePci(struct CTrick *this, struct Message *m, char *n, int p) {
}


// address: 0x800669E0
// size: 0x8E4
// line start: 1936
// line end:   1981
struct CPanelData *__10CPanelDataP6CBruce(struct CPanelData *this, struct CBruce_duplicate_s0 *pBruce) {
	{
		// register: 4
		register int i;
	}
}


// address: 0x80066CA8
// line start: 1985
// line end:   2098
void TrickMessageRefresh__10CPanelData(struct CPanelData *this) {
	// register: 19
	register char *p;
	// address: 0xFFFFFF78
	// size: 0x60
	auto char tbuf[96];
	// register: 21
	register int lineWidth;
	// register: 17
	register int steadyScale;
	// register: 20
	register int currLine;
	{
		// register: 16
		register int i;
	}
}


// address: 0x80067050
// line start: 2103
// line end:   2115
void TrickMessage__10CPanelData(struct CPanelData *this) {
}


// address: 0x800670AC
// line start: 2133
// line end:   2191
void Trick__10CPanelDataPciii(struct CPanelData *this, char *pName, int Points, int Lock, int Dep) {
	// address: 0x00000010
	// size: 0xF
	static char points[15];
	// address: 0x00000020
	// size: 0xF
	static char time[15];
	// register: 6
	register int Flipped;
}


// address: 0x8006733C
// line start: 2215
// line end:   2254
void Land__10CPanelData(struct CPanelData *this) {
	{
		{
		}
	}
}


// address: 0x80067430
// line start: 2258
// line end:   2271
void Bail__10CPanelData(struct CPanelData *this) {
}


// address: 0x800674B0
// line start: 2292
// line end:   2296
void OutOfBounds__10CPanelData(struct CPanelData *this) {
}


// address: 0x8006AAE0
// line start: 102
// line end:   109
void DeleteList__FP5CBody(struct CBody_duplicate_s1 *pList) {
	// register: 16
	// size: 0x108
	register struct CBody_duplicate_s1 *pNext;
}


// address: 0x8006AB4C
// line start: 117
// line end:   151
void Init_KillAll__Fv() {
}


// address: 0x8006ABF4
// line start: 161
// line end:   266
void Init_Cleanup__Fi(int type) {
	{
		{
		}
	}
}


// address: 0x8006ADA4
// line start: 283
// line end:   350
int Init_ResetMemory__Fi(int Heap0Size) {
}


// address: 0x8006AE2C
// line start: 361
// line end:   395
void Init_Restart__F13EPackInitTypei(enum EPackInitType_duplicate_e1 Mode, int SmallHeapSize) {
}


// address: 0x8006AEE0
// line start: 403
// line end:   414
void Init_ForGame__Fv() {
}


// address: 0x8006AF30
// line start: 419
// line end:   505
void Init_DebugStuff__Fv() {
}


// address: 0x8006AF38
// line start: 509
// line end:   546
void Init_AtStart__Fv() {
	// address: 0xFFFFFFF0
	// size: 0x8
	auto struct RECT screen;
}


// address: 0x8006B1E4
// size: 0x34
// line start: 31
// line end:   35
struct FrontPreLoader *__14FrontPreLoader(struct FrontPreLoader *this) {
	// register: 2
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x8006B204
// line start: 44
// line end:   49
void ___14FrontPreLoader(struct FrontPreLoader *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x8006B234
// line start: 55
// line end:   87
int BeginLoad__14FrontPreLoaderi(struct FrontPreLoader *this, int whichScreen) {
	// register: 3
	// size: 0x8
	register struct _FrontPreInfo *pInfo;
}


// address: 0x8006B308
// line start: 95
// line end:   137
int DoneLoading__14FrontPreLoader(struct FrontPreLoader *this) {
	// register: 9
	// size: 0x18
	register struct POLY_F4 *Poly;
	// register: 16
	// size: 0xC
	register struct DR_MODE *dr;
	{
		{
		}
	}
}


// address: 0x8006B53C
// line start: 92
// line end:   92
void ___6CClass_addr_8006B53C(struct CClass *this, int __in_chrg) {
}


// address: 0x8006B56C
// size: 0x5C
// line start: 18
// line end:   25
struct Blood *__5Blood(struct Blood *this) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
		{
			// register: 5
			register int i;
		}
	}
}


// address: 0x8006B5A4
// line start: 33
// line end:   37
void ___5Blood(struct Blood *this, int __in_chrg) {
	// register: 17
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x8006B5F4
// line start: 43
// line end:   51
void Reset__5Blood(struct Blood *this) {
	{
		// register: 17
		register int i;
	}
}


// address: 0x8006B680
// line start: 59
// line end:   197
void Update__5BloodP6CBruce(struct Blood *this, struct CBruce_duplicate_s0 *pBruce) {
	// address: 0xFFFFFFC8
	// size: 0x6
	auto struct CSVector traj;
	// address: 0xFFFFFFD0
	// size: 0x6
	auto struct CSVector cone;
	// address: 0xFFFFFFD8
	// size: 0xC
	auto struct CVector SparkPos;
	{
		{
			{
				{
					{
						{
							{
								{
									{
										{
											// address: 0xFFFFFFE8
											// size: 0xC
											auto struct CVector tempVector;
											// address: 0xFFFFFFF8
											// size: 0x8
											auto struct SHook hook;
											{
												{
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8006B690
// line start: 92
// line end:   92
void ___6CClass_addr_8006B690(struct CClass *this, int __in_chrg) {
}


// address: 0x8006C9D0
// line start: 15
// line end:   35
char *strstr__FPcT0(char *pHay, char *pNeedle) {
	// register: 8
	register char First;
	{
		// register: 7
		register char *pH;
		// register: 3
		register char *pN;
		{
			{
			}
		}
	}
}


// address: 0x8006CA38
// line start: 41
// line end:   47
void LowerCase__FPc(char *p) {
	{
		// register: 3
		register char letter;
	}
}


// address: 0x8006CA84
// line start: 52
// line end:   56
int WhiteSpace__FPc(char *p) {
}


// address: 0x8006CAAC
// line start: 186
// line end:   191
unsigned char MIN3__FUcUcUc(unsigned char r, unsigned char g, unsigned char b) {
	// register: 4
	register char min;
}


// address: 0x8006CADC
// line start: 200
// line end:   205
unsigned char MAX3__FUcUcUc(unsigned char r, unsigned char g, unsigned char b) {
	// register: 4
	register unsigned char max;
}


// address: 0x8006CB0C
// line start: 216
// line end:   263
void Create_RGB2HSV__FUcUcUcPiN23(unsigned char r, unsigned char g, unsigned char b, int *pH, int *pS, int *pV) {
	// register: 19
	register int min;
	// register: 4
	register int max;
	// register: 5
	register int delta;
	// register: 3
	register int diff;
	// register: 4
	register int rotOffset;
}


// address: 0x8006CC2C
// line start: 271
// line end:   317
void Create_HSV2RGB__FiiiPUcN23(int h, int s, int v, unsigned char *pR, unsigned char *pG, unsigned char *pB) {
	// register: 3
	register int i;
	// register: 3
	register int f;
	// register: 9
	register int p;
	// register: 10
	register int q;
	// register: 7
	register int t;
}


// address: 0x8006CD80
// line start: 418
// line end:   475
void Create_RememberPalette__FP9tag_S_PalP9HSV_VALUE(struct tag_S_Pal *pPal, struct HSV_VALUE *pDestPalette) {
	// address: 0xFFFFFDD0
	// size: 0x200
	auto unsigned short TempPalette[256];
	// register: 19
	// size: 0x10
	register struct HSV_VALUE *pEntry32;
	// register: 20
	register unsigned short *pEntry16;
	// register: 22
	register int PalSize;
	{
		// register: 18
		register int i;
		{
			{
				{
					// address: 0xFFFFFFD0
					auto int h;
					// address: 0xFFFFFFD4
					auto int s;
					// address: 0xFFFFFFD8
					auto int v;
				}
			}
		}
	}
}


// address: 0x8006CE98
// line start: 491
// line end:   585
void Create_UpdatePalette__FP9tag_S_PalP9HSV_VALUEUsUsUs(struct tag_S_Pal *pPal, struct HSV_VALUE *pSourcePalette, unsigned short hXForm, unsigned short sXForm, int vXForm) {
	// address: 0xFFFFFDC0
	// size: 0x200
	auto unsigned short TempPalette[256];
	// register: 19
	// size: 0x10
	register struct HSV_VALUE *pEntry32;
	// register: 18
	register unsigned short *pEntry16;
	// register: 20
	register int PalSize;
	{
		// register: 16
		register int i;
		{
			// address: 0xFFFFFFC0
			// size: 0x10
			auto struct HSV_VALUE bgr;
			// register: 4
			register int h;
			// register: 5
			register int s;
			// register: 6
			register int v;
			// address: 0xFFFFFFD0
			auto unsigned char r;
			// address: 0xFFFFFFD1
			auto unsigned char g;
			// address: 0xFFFFFFD2
			auto unsigned char b;
		}
	}
}


// address: 0x8006D0C0
// size: 0x48
// line start: 308
// line end:   321
struct CCreateTexSpec *__14CCreateTexSpecPcT1iP15_SCreateTexListN34(struct CCreateTexSpec *this, char *name, char *frontEndName, int hue, struct _SCreateTexList *list0, struct _SCreateTexList *list1, struct _SCreateTexList *list2, struct _SCreateTexList *list3) {
	// register: 16
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x8006D15C
// line start: 328
// line end:   330
char *GetGeometryName__14CCreateTexSpec(struct CCreateTexSpec *this) {
}


// address: 0x8006D164
// line start: 337
// line end:   339
char *GetFrontEndName__14CCreateTexSpec(struct CCreateTexSpec *this) {
}


// address: 0x8006D16C
// size: 0x8
// line start: 346
// line end:   349
struct _SCreateTexList *GetTextureList__14CCreateTexSpeci(struct CCreateTexSpec *this, int i) {
}


// address: 0x8006D180
// line start: 356
// line end:   358
int GetDefaultHue__14CCreateTexSpec(struct CCreateTexSpec *this) {
}


// address: 0x8006D18C
// line start: 360
// line end:   360
void _GLOBAL__D_DefaultFace() {
}


// address: 0x8006D270
// line start: 360
// line end:   360
void _GLOBAL__I_DefaultFace() {
}


// address: 0x8006D80C
// line start: 27
// line end:   360
void ___14CCreateTexSpec(struct CCreateTexSpec *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x8006D83C
// line start: 92
// line end:   92
void ___6CClass_addr_8006D83C(struct CClass *this, int __in_chrg) {
}


// address: 0x8006D86C
// line start: 178
// line end:   184
int Create_GetAnimIndex__Fi(int i) {
	{
		// register: 17
		register int n;
	}
}


// address: 0x8006D8E8
// line start: 190
// line end:   200
int Create_GetModelIndex__Fi(int i) {
	{
		// register: 16
		register int n;
	}
}


// address: 0x8006D970
// line start: 204
// line end:   265
void Create_LoadPSH__FPc(char *pPSHName) {
	// register: 16
	register char *p;
	{
		// register: 6
		register char *g;
		// register: 5
		register char *pGroupName;
	}
}


// address: 0x8006DB08
// line start: 280
// line end:   290
char *GetFrontEndName__8MySkateriP14CCreateTexSpec(struct MySkater *this, int Number, struct CCreateTexSpec *pSpec) {
}


// address: 0x8006DBC8
// line start: 297
// line end:   299
char *GetGroupName__8MySkateri(struct MySkater *this, int Number) {
}


// address: 0x8006DC0C
// line start: 306
// line end:   322
char *Create_GetGroupName__8MySkaterPci(struct MySkater *this, char *p, int Number) {
	// register: 19
	register int n;
	// register: 3
	// size: 0x40
	register struct SPSXRegion *pRegion;
	// register: 20
	register int NumParts;
	{
		// register: 18
		register int i;
		{
		}
	}
}


// address: 0x8006DCD0
// line start: 325
// line end:   337
int Create_GetModelSize__FP6SModel(struct SModel *pModel) {
	// register: 2
	// size: 0x8
	register struct SVECTOR *Normals;
	// register: 5
	register unsigned int *pFaceX;
	{
		// register: 6
		register int i;
	}
}


// address: 0x8006DD18
// line start: 343
// line end:   359
int Create_CountString__FPci(char *p, int sourceRegion) {
	// register: 18
	register int n;
	// register: 5
	// size: 0x40
	register struct SPSXRegion *pRegion;
	// register: 19
	register int NumParts;
	{
		// register: 17
		register int i;
		{
		}
	}
}


// address: 0x8006DDB0
// line start: 364
// line end:   374
int Create_CountStitches__FP6SModel(struct SModel *pModel) {
	// register: 3
	// size: 0x8
	register struct SVECTOR *pVertex;
	// register: 4
	register int count;
	// register: 5
	register int i;
}


// address: 0x8006DDFC
// size: 0x1F4
// line start: 381
// line end:   383
struct MySkaterTextureInfo *__19MySkaterTextureInfoUi(struct MySkaterTextureInfo *this, unsigned int checksum) {
	// register: 2
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x8006DE14
// line start: 393
// line end:   397
void AddBodyPart__19MySkaterTextureInfoi(struct MySkaterTextureInfo *this, int partNum) {
}


// address: 0x8006DE3C
// line start: 405
// line end:   410
void SetTextureInfo__19MySkaterTextureInfoP7Texture(struct MySkaterTextureInfo *this, struct Texture *pTexture) {
}


// address: 0x8006DE8C
// size: 0x734
// line start: 424
// line end:   454
struct MySkater *__8MySkater(struct MySkater *this) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
		{
			// register: 5
			register int i;
			{
				// register: 10
				register int i;
			}
		}
	}
}


// address: 0x8006DF40
// line start: 462
// line end:   464
void ___8MySkater(struct MySkater *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x8006DF70
// size: 0x28
// line start: 470
// line end:   486
struct Texture *FindTexture__8MySkaterUi(struct MySkater *this, unsigned int checksum) {
	// register: 3
	// size: 0x40
	register struct SPSXRegion *pRegion;
	// register: 16
	register unsigned int NumModels;
	// register: 2
	register unsigned int *ChecksumTable;
	// register: 6
	register unsigned int NumChecksums;
	{
		// register: 5
		register int i;
	}
}


// address: 0x8006E008
// line start: 494
// line end:   527
void SaveTextures__8MySkater(struct MySkater *this) {
	// register: 22
	register unsigned int *pPSX;
	// register: 3
	register unsigned int *pStuff;
	// register: 3
	register int NumModels;
	// register: 4
	register int Temp;
	// register: 21
	// size: 0x28
	register struct Texture **TextureLookup;
	// register: 17
	register unsigned int *pTextureInfo;
	// register: 20
	register unsigned int NumTextures;
	{
		// register: 19
		register int i;
		{
			// register: 5
			register unsigned int *pTexture;
			// register: 16
			register unsigned int TextureIndex;
		}
	}
}


// address: 0x8006E160
// line start: 535
// line end:   566
void UpdateTextureList__8MySkater(struct MySkater *this) {
	// register: 22
	// size: 0x40
	register struct SPSXRegion *pRegion;
	// register: 20
	// size: 0x24
	register struct SModel **ppModels;
	{
		// register: 19
		register int i;
		{
			// register: 5
			// size: 0x24
			register struct SModel *pModel;
			// address: 0xFFFFFF58
			// size: 0x80
			auto unsigned int checksums[32];
			// address: 0xFFFFFFD8
			auto int checksumCount;
			{
				// register: 18
				register int j;
				{
					// register: 16
					// size: 0x1F4
					register struct MySkaterTextureInfo *pInfo;
				}
			}
		}
	}
}


// address: 0x8006E264
// size: 0x1F4
// line start: 574
// line end:   581
struct MySkaterTextureInfo *FindTextureInfo__8MySkaterUi(struct MySkater *this, unsigned int checksum) {
	{
		// register: 6
		register int i;
	}
}


// address: 0x8006E2B4
// line start: 589
// line end:   662
void BuildChecksumList__8MySkaterP6SModelPUiPi(struct MySkater *this, struct SModel *pModel, unsigned int *pChecksumList, int *pChecksumCount) {
	// register: 16
	register unsigned int NumModels;
	// register: 19
	register unsigned int *ChecksumTable;
	// register: 16
	register unsigned int NumChecksums;
	// register: 3
	// size: 0x8
	register struct SVECTOR *Normals;
	// register: 10
	register unsigned int *pFace;
	{
		// register: 25
		register int i;
		{
			// register: 12
			register unsigned short tpage;
			// register: 15
			register unsigned char v0;
			// register: 14
			register unsigned char u0;
			// register: 4
			register int match;
			{
				// register: 11
				register int i;
				{
					{
						{
							// register: 6
							register int foundInChecksums;
							{
								// register: 5
								register int j;
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8006E4A8
// line start: 670
// line end:   721
void Init__8MySkaterPc(struct MySkater *this, char *pAnimFile) {
	// register: 17
	// size: 0x24
	register struct SModel **modelPointers;
	// register: 3
	// size: 0x24
	register struct SModel **ppBuildModels;
	{
		// register: 4
		register int i;
	}
}


// address: 0x8006E5F8
// line start: 729
// line end:   744
void UpdateStats__8MySkaterPci(struct MySkater *this, char *partName, int modelIndex) {
}


// address: 0x8006E694
// line start: 753
// line end:   854
void Rebuild__8MySkaterP6CSuperT1i(struct MySkater *this, struct CSuper *pSourceSkater, struct CSuper *pBuildSkater, int spoolTextures) {
	{
		{
			// register: 30
			// size: 0x24
			register struct SModel **ppSourceModels;
			// address: 0xFFFFFFD0
			// size: 0x24
			auto struct SModel **ppBuildModels;
			{
				// register: 21
				register int i;
				{
					// register: 19
					// size: 0x24
					register struct SModel *pModel;
					{
						{
							// register: 17
							register int animIndex;
							// register: 16
							register int modelIndex;
							{
								{
									// register: 16
									register int modelSize;
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8006E95C
// line start: 862
// line end:   875
int TextureIsInBodyPart__8MySkaterUiPc(struct MySkater *this, unsigned int checksum, char *part) {
	{
		// register: 19
		register int i;
		{
			{
				{
					{
						// register: 16
						register int j;
					}
				}
			}
		}
	}
}


// address: 0x8006EA8C
// line start: 895
// line end:   937
unsigned int FindUniqueTextureBySize__8MySkaterPci(struct MySkater *this, char *inPart, int findLarger) {
	// register: 22
	register int numFound;
	// register: 17
	register unsigned int checksum;
	// register: 4
	register int sourceIndex;
	// register: 23
	register int largestChecksum;
	// register: 30
	register int smallestChecksum;
	// register: 21
	register unsigned int largestSize;
	// register: 20
	register unsigned int smallestSize;
	{
		// register: 18
		register int j;
		{
			{
				{
					// register: 2
					// size: 0x1F4
					register struct MySkaterTextureInfo *myTexInfo;
					// register: 4
					register int size;
				}
			}
		}
	}
}


// address: 0x8006EC04
// line start: 944
// line end:   1044
unsigned int FindUniqueTexture__8MySkaterPcN21(struct MySkater *this, char *inPart, char *notInPart, char *notInPart2) {
	// register: 19
	register int numFound;
	// register: 20
	register unsigned int checksum;
	// register: 21
	register int sourceIndex;
	// register: 23
	register int sourceIndex2;
	// address: 0xFFFFFFD0
	auto int oldNumFound;
	{
		// register: 17
		register int j;
		{
			// register: 17
			register int j;
			{
				{
					// register: 5
					register int sourceIndex3;
					{
						// register: 17
						register int j;
						{
							{
								// register: 5
								register int sourceIndex3;
								{
									// register: 17
									register int j;
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8006F020
// line start: 1051
// line end:   1072
int FindBuildIndex__8MySkaterPc(struct MySkater *this, char *name) {
	// register: 18
	register int animIndex;
	{
		// register: 16
		register int n;
		{
			// register: 3
			register int i;
			// register: 16
			register int n;
		}
	}
}


// address: 0x8006F0C8
// line start: 1079
// line end:   1117
unsigned int GetChecksumToReplace__8MySkateri(struct MySkater *this, int texPart) {
}


// address: 0x8006F220
// line start: 1122
// line end:   1140
char *GetSkinToneFileName__8MySkaterPc(struct MySkater *this, char *filename) {
}


// address: 0x8006F26C
// line start: 1147
// line end:   1180
void SpoolTextures__8MySkater(struct MySkater *this) {
	// address: 0xFFFFFFA8
	// size: 0x20
	auto char FileNameWithExt[32];
	// address: 0xFFFFFFC8
	// size: 0x10
	auto char oldSubDir[16];
	{
		// register: 17
		register int i;
		{
			{
				{
					// register: 16
					register unsigned int checksum;
					{
						{
							// register: 16
							register unsigned int checksum;
						}
					}
				}
			}
		}
	}
}


// address: 0x8006F3E8
// line start: 1187
// line end:   1249
void ReplaceTextures__8MySkater(struct MySkater *this) {
	// address: 0xFFFFFFA8
	// size: 0x20
	auto char FileNameWithExt[32];
	// address: 0xFFFFFFC8
	// size: 0x10
	auto char oldSubDir[16];
	{
		// register: 17
		register int i;
		{
			{
				{
					{
						{
							// register: 16
							register unsigned int checksum;
							{
								{
									// register: 16
									register unsigned int checksum;
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8006F610
// line start: 1289
// line end:   1324
void RefreshTexture__FUiPc(unsigned int Checksum, char *pBuf) {
	// register: 6
	// size: 0x28
	register struct Texture *pTexture;
	// register: 5
	register int X;
	// register: 6
	register int Y;
	// register: 7
	register int ClutX;
	// register: 2
	register int ClutY;
}


// address: 0x8006F66C
// line start: 1330
// line end:   1339
void AddSpoolerEntry__8MySkaterUiPci(struct MySkater *this, unsigned int checksum, char *filename, int texPart) {
}


// address: 0x8006F70C
// line start: 1347
// line end:   1355
void AddSpoolerEntries__8MySkater(struct MySkater *this) {
	{
		// register: 18
		register int i;
	}
}


// address: 0x8006F790
// line start: 1367
// line end:   1412
void ProcessSpoolerEntry__8MySkater(struct MySkater *this) {
	{
		// register: 21
		register int i;
		{
			{
				{
					// register: 16
					register char *theData;
				}
			}
		}
	}
}


// address: 0x8006F8D0
// line start: 1430
// line end:   1455
void Free2__8MySkater(struct MySkater *this) {
	{
		// register: 16
		register int i;
		{
			// register: 17
			register int i;
		}
	}
}


// address: 0x8006F9B4
// line start: 1463
// line end:   1519
void Free__8MySkater(struct MySkater *this) {
	// register: 19
	// size: 0x24
	register struct SModel **ppModels;
	// register: 16
	// size: 0x24
	register struct SModel **ppBuildModels;
	{
		// register: 17
		register int i;
	}
}


// address: 0x8006FADC
// size: 0x8
// line start: 1537
// line end:   1576
struct _SCreateTexList *GetFirstTexture__8MySkaterP14CCreateTexSpeciii(struct MySkater *this, struct CCreateTexSpec *pCurrSpec, int bodyGroup, int index, int lastTexture) {
	// register: 17
	// size: 0x8
	register struct _SCreateTexList *pTexList;
	{
		{
			{
				{
					{
						// register: 3
						// size: 0x8
						register struct _SCreateTexList *pNextList;
					}
				}
			}
		}
	}
}


// address: 0x8006FBF4
// line start: 1583
// line end:   1603
void UpdateGeometry__8MySkateri(struct MySkater *this, int bodyGroup) {
}


// address: 0x8006FD48
// line start: 1611
// line end:   1654
void UpdateDefaultHue__8MySkateri(struct MySkater *this, int bodyGroup) {
	// register: 17
	// size: 0x48
	register struct CCreateTexSpec *pCurrSpec;
}


// address: 0x8006FF2C
// line start: 1663
// line end:   1696
void NextGeometry__8MySkaterii(struct MySkater *this, int bodyGroup, int forwards) {
	{
		{
			// register: 5
			register int oldSkinTone;
		}
	}
}


// address: 0x8007003C
// line start: 1703
// line end:   1783
void NextTexture__8MySkaterii(struct MySkater *this, int texPart, int forwards) {
	// register: 18
	// size: 0x48
	register struct CCreateTexSpec *pSpec;
	// register: 19
	register int bodyGroup;
	// register: 17
	register int index;
}


// address: 0x80070224
// line start: 1790
// line end:   1869
void NextFace__8MySkaterP14CCreateTexSpeci(struct MySkater *this, struct CCreateTexSpec *pSpec, int forwards) {
	// register: 30
	register int oldSkinTone;
	// address: 0xFFFFFFA8
	// size: 0x10
	auto char oldSubDir[16];
	{
		{
			{
				// address: 0xFFFFFFB8
				// size: 0x20
				auto char textureName[32];
			}
		}
	}
}


// address: 0x80070428
// line start: 1878
// line end:   1899
void Create_Off__8MySkater(struct MySkater *this) {
	// register: 3
	register int region;
	// register: 3
	// size: 0x40
	register struct SPSXRegion *pRegion;
	// register: 7
	register int NumParts;
	// register: 5
	// size: 0x24
	register struct SModel **ppModels;
	{
		// register: 6
		register int i;
		{
			// register: 2
			// size: 0x24
			register struct SModel *pModel;
		}
	}
}


// address: 0x80070474
// line start: 1908
// line end:   1934
void Create_On__8MySkaterPcT1(struct MySkater *this, char *p1, char *p2) {
	// register: 3
	// size: 0x40
	register struct SPSXRegion *pRegion;
	// register: 21
	register int Parts;
	// register: 19
	// size: 0x24
	register struct SModel **ppModels;
	// address: 0xFFFFFFC0
	// size: 0x20
	auto char buf[32];
	{
		// register: 20
		register int i;
		{
			// register: 18
			// size: 0x24
			register struct SModel *pModel;
			// register: 16
			register char *s1;
			// register: 2
			register char *s2;
		}
	}
}


// address: 0x8007056C
// line start: 1942
// line end:   1944
void Create_OnHead__8MySkaterPc(struct MySkater *this, char *p) {
}


// address: 0x80070590
// line start: 1952
// line end:   1956
void Create_OnBoard__8MySkaterPc(struct MySkater *this, char *p) {
}


// address: 0x800705F0
// line start: 1963
// line end:   1972
void Create_OnTorso__8MySkaterPc(struct MySkater *this, char *p) {
}


// address: 0x800706B4
// line start: 1980
// line end:   1988
void Create_OnLegs__8MySkaterPc(struct MySkater *this, char *p) {
}


// address: 0x80070764
// line start: 1998
// line end:   2008
int GetSourceIndex__8MySkateri(struct MySkater *this, int buildIndex) {
	{
		// register: 3
		register int sourceIndex;
	}
}


// address: 0x800707AC
// line start: 2016
// line end:   2026
void GetInternalStitches__8MySkater(struct MySkater *this) {
	// register: 18
	register int stitchCount;
	{
		// register: 17
		register int i;
		{
			// register: 4
			// size: 0x24
			register struct SModel *pModel;
		}
	}
}


// address: 0x80070880
// line start: 2034
// line end:   2102
void PatchInternalStitches__8MySkater(struct MySkater *this) {
	// register: 18
	register int stitchCount;
	{
		// register: 16
		register int i;
		{
			// register: 2
			register int sourceIndex;
			// register: 4
			// size: 0x24
			register struct SModel *pModel;
			{
				// register: 18
				register int i;
				{
					{
						{
							// register: 16
							// size: 0x24
							register struct SModel *pModel;
							// register: 8
							// size: 0x8
							register struct SVECTOR *pVertex;
							// register: 11
							// size: 0x8
							register struct SVECTOR *pNormal;
							// register: 14
							register int j;
							{
								{
									{
										{
											// register: 15
											register int stitchedVertexIndex;
											// register: 6
											register int stitchedPartIndex;
											// register: 3
											register int offset;
											{
												// register: 7
												register int k;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80070B28
// line start: 2112
// line end:   2175
int InsertStitch__8MySkaterP7SVECTORN31(struct MySkater *this, struct SVECTOR *pNewStitchVertex, struct SVECTOR *pNewGhostVertex, struct SVECTOR *pNewStitchNormal, struct SVECTOR *pNewGhostNormal) {
	// register: 12
	register int stitchIndex;
	// register: 15
	register int found;
	{
		// register: 14
		register int n;
		{
			// register: 11
			// size: 0x24
			register struct SModel *pModel;
			// register: 4
			// size: 0x8
			register struct SVECTOR *pVertex;
			// register: 8
			// size: 0x8
			register struct SVECTOR *pNormal;
			// register: 10
			register int j;
		}
	}
}


// address: 0x80070C74
// line start: 2183
// line end:   2236
void CreateManualStitches__8MySkaterP6CSuperii(struct MySkater *this, struct CSuper *mySuper, int partIndexA, int partIndexB) {
	// address: 0xFFFFFFC4
	// size: 0x18
	auto struct SMatrix *pTestTransform;
	// register: 17
	// size: 0x24
	register struct SModel *pBuildModelJ;
	// address: 0xFFFFFFC8
	// size: 0x24
	auto struct SModel *pBuildModelK;
	// address: 0xFFFFFFCC
	// size: 0x24
	auto struct SModel *pCreateModelJ;
	// register: 21
	// size: 0x24
	register struct SModel *pCreateModelK;
	// register: 23
	// size: 0x8
	register struct SVECTOR *pVertexBuildJ;
	// register: 30
	// size: 0x8
	register struct SVECTOR *pVertexCreateJ;
	// register: 22
	// size: 0x8
	register struct SVECTOR *pVertexNormalBuildJ;
	{
		// address: 0xFFFFFFD0
		auto int j;
		{
			// register: 16
			// size: 0x8
			register struct SVECTOR *pVertexBuildK;
			// register: 19
			// size: 0x8
			register struct SVECTOR *pVertexCreateK;
			// register: 17
			// size: 0x8
			register struct SVECTOR *pVertexNormalBuildK;
			{
				// register: 18
				register int k;
				{
					// address: 0xFFFFFFA0
					// size: 0x10
					auto struct VECTOR xformedVertJ;
					// address: 0xFFFFFFB0
					// size: 0x10
					auto struct VECTOR xformedVertK;
					// address: 0xFFFFFFC0
					auto long flag;
				}
			}
		}
	}
}


// address: 0x80070F14
// line start: 2244
// line end:   2251
void DecrementBuildTextures__8MySkater(struct MySkater *this) {
	{
		// register: 6
		register int i;
	}
}


// address: 0x80070F60
// line start: 2259
// line end:   2292
void IncrementTextureUsage__8MySkater(struct MySkater *this) {
	// register: 17
	// size: 0x24
	register struct SModel **ppModels;
	// register: 16
	register unsigned int NumModels;
	// register: 22
	register unsigned int *ChecksumTable;
	// register: 16
	register unsigned int NumChecksums;
	{
		// register: 18
		register int i;
		{
			// register: 5
			// size: 0x24
			register struct SModel *pModel;
			{
				// register: 12
				register int i;
				{
					{
						// register: 7
						register int j;
					}
				}
			}
		}
	}
}


// address: 0x800710C4
// line start: 2301
// line end:   2344
void RememberPalette__8MySkateriUi(struct MySkater *this, int texPart, unsigned int checksum) {
	// register: 17
	register unsigned int textureChecksum;
	// register: 7
	register unsigned int paletteChecksum;
	{
		// register: 16
		register int j;
		{
			{
				{
					// register: 3
					// size: 0x14
					register struct tag_S_Pal *pPalette;
				}
			}
		}
	}
}


// address: 0x800711E0
// line start: 2351
// line end:   2438
void UpdatePalette__8MySkateri(struct MySkater *this, int texPart) {
	// register: 5
	// size: 0x10
	register struct HSV_VALUE *pPaletteBuffer;
	{
		{
			// register: 5
			// size: 0x10
			register struct HSV_VALUE *pPaletteBuffer;
			{
				{
					{
						// register: 5
						// size: 0x10
						register struct HSV_VALUE *pPaletteBuffer;
					}
				}
			}
		}
	}
}


// address: 0x80071604
// line start: 2449
// line end:   2456
void PatchAnimationOrder__8MySkaterP6CSuper(struct MySkater *this, struct CSuper *pBuildSkater) {
	{
		// register: 16
		register int i;
	}
}


// address: 0x80071660
// size: 0x1A0
// line start: 2463
// line end:   2635
struct CharacterEditor *__15CharacterEditor(struct CharacterEditor *this) {
	// register: 2
	// size: 0x24
	register struct ScreenElement *pElement;
	{
		// register: 5
		register int i;
		{
			// register: 7
			// size: 0x190
			register struct CSuper *this;
			{
				{
					// register: 18
					register int i;
					{
						// register: 17
						register int i;
						{
							// register: 18
							register int i;
						}
					}
				}
			}
		}
	}
}


// address: 0x80071F84
// line start: 2658
// line end:   2681
void ___15CharacterEditor(struct CharacterEditor *this, int __in_chrg) {
	{
		// register: 17
		register int i;
	}
}


// address: 0x8007211C
// line start: 2692
// line end:   2893
void update__15CharacterEditor(struct CharacterEditor *this) {
	// size: 0x8
	static struct SVECTOR RotAngle;
	// register: 19
	register int prev;
	// register: 16
	register int next;
}


// address: 0x80072430
// line start: 2901
// line end:   2987
void draw__15CharacterEditorii(struct CharacterEditor *this, int x, int y) {
	{
		{
			// register: 3
			register int OldJust;
		}
	}
}


// address: 0x800726FC
// line start: 2995
// line end:   3018
int handlePress__15CharacterEditor(struct CharacterEditor *this) {
}


// address: 0x800727A4
// line start: 3026
// line end:   3131
void Create_InitSkater__Fi(int forGame) {
	// register: 17
	// size: 0x190
	register struct CSuper *pSourceSkater;
	// register: 18
	// size: 0x734
	register struct MySkater *pMySkater;
	// address: 0xFFFFFFE0
	// size: 0x8
	auto short FrontEndAnimations[4];
	{
		// register: 5
		register int i;
		{
			{
			}
		}
	}
}


// address: 0x800729A4
// line start: 3142
// line end:   3255
void Create_InitSkaterFrontEnd__Fv() {
	// register: 19
	register int forGame;
	// register: 17
	// size: 0x190
	register struct CSuper *pSourceSkater;
	// register: 18
	// size: 0x734
	register struct MySkater *pMySkater;
	// address: 0xFFFFFFE0
	// size: 0x8
	auto short FrontEndAnimations[4];
	{
		// register: 5
		register int i;
		{
			// register: 4
			register int i;
			{
				{
				}
			}
		}
	}
}


// address: 0x80072B88
// line start: 3275
// line end:   3284
void Create_FreeSkaterFrontEnd__Fv() {
}


// address: 0x80072BC4
// line start: 3292
// line end:   3298
void Create_BuildSkater__FP6CSuper(struct CSuper *pBuildSkater) {
	// register: 16
	// size: 0x734
	register struct MySkater *pMySkater;
}


// address: 0x80072C0C
// line start: 3306
// line end:   3361
void Create_FreeSkater__Fv() {
	// register: 19
	// size: 0x734
	register struct MySkater *pMySkater;
	// register: 18
	// size: 0x24
	register struct SModel **ppModels;
	// register: 16
	// size: 0x24
	register struct SModel **ppBuildModels;
	{
		// register: 17
		register int i;
	}
}


// address: 0x80072D38
// line start: 3367
// line end:   3372
void Create_SaveTextures__Fv() {
}


// address: 0x80072D5C
// line start: 3380
// line end:   3382
int Create_ProcessingSourcePSX__Fv() {
}


// address: 0x80072D68
// line start: 3390
// line end:   3392
int Create_ProcessingBuildPSX__Fv() {
}


// address: 0x80072D74
// line start: 3400
// line end:   3401
int Create_UseSkater__Fi(int selectedSkater) {
}


// address: 0x80072D80
// line start: 3411
// line end:   3507
int Create_Main__Fv() {
	// register: 17
	// size: 0x1A0
	register struct CharacterEditor *pEditor;
	// register: 18
	register unsigned int oldSkyColor;
	// register: 16
	register int press;
}


// address: 0x80072FB4
// line start: 3514
// line end:   3566
void Create_InitSystem__Fv() {
	{
		{
			// register: 17
			// size: 0x734
			register struct MySkater *mpSkater;
			{
				// register: 4
				register int i;
			}
		}
	}
}


// address: 0x8007310C
// line start: 3575
// line end:   3587
int Create_SpoolTextures__Fv() {
	// address: 0xFFFFFFE8
	// size: 0x10
	auto char oldSubDir[16];
}


// address: 0x80073178
// line start: 3594
// line end:   3603
void Create_BeginSpooling__Fv() {
	// address: 0xFFFFFFE8
	// size: 0x10
	auto char oldSubDir[16];
}


// address: 0x800731C8
// line start: 3605
// line end:   3605
void _GLOBAL__D_BodyPart() {
}


// address: 0x800731F0
// line start: 3605
// line end:   3605
void _GLOBAL__I_BodyPart() {
}


// address: 0x80073214
// line start: 57
// line end:   57
void ___19MySkaterTextureInfo(struct MySkaterTextureInfo *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x80073244
// line start: 92
// line end:   92
void ___6CClass_addr_80073244(struct CClass *this, int __in_chrg) {
}


// address: 0x8007EDD0
// line start: 337
// line end:   373
void GameFMV_Init__Fv() {
	{
		// register: 17
		register int i;
		{
			{
				{
					// address: 0xFFFFFFD0
					// size: 0x18
					auto struct CdlFILE fmv_file;
				}
			}
		}
	}
}


// address: 0x8007EEA0
// line start: 380
// line end:   693
void GameFMV_PlayMovie__Fi(int track) {
	// address: 0xFFFFFFB8
	// size: 0x14
	auto struct DISPENV disp;
	// register: 21
	register short old_screen_w;
	// address: 0xFFFFFFD0
	// size: 0x4
	auto struct CdlATV atv;
	// address: 0x000006C0
	bool InsufficientMemory;
	{
		// register: 17
		register int i;
		{
			// register: 17
			register int i;
			{
				{
					// register: 2
					register int fmv_level;
					{
						{
							// address: 0xFFFFFFD8
							// size: 0x8
							auto unsigned char result[8];
							// register: 16
							register int count;
							{
								// register: 17
								register int i;
								{
									// register: 17
									register int i;
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8007F3EC
// line start: 701
// line end:   740
void GameFMV_SetStartTrack__Fi(int track) {
}


// address: 0x8007F4E4
// line start: 754
// line end:   838
void GameFMV_StartFMV__Fi(int Decoding) {
	{
		{
			{
				// register: 17
				register int i;
				{
					{
						{
							// register: 17
							register int i;
						}
					}
				}
			}
		}
	}
}


// address: 0x8007F644
// line start: 842
// line end:   913
void GameFMV_StopFMV__Fv() {
	// address: 0xFFFFFFD8
	// size: 0x4
	auto struct CdlATV atv;
	// address: 0xFFFFFFE0
	// size: 0x4
	auto struct CdlLOC pos;
	{
		// register: 17
		register int i;
		{
			// register: 17
			register int i;
			{
				{
					// address: 0xFFFFFFE8
					// size: 0x8
					auto struct RECT r;
				}
			}
		}
	}
}


// address: 0x8007F79C
// line start: 934
// line end:   1041
void GameFMV_SyncFMV__Fi(int DecodeData) {
	// address: 0x000001D0
	static int recalculate_attenuation_timer;
	{
		{
		}
	}
}


// address: 0x8007F910
// line start: 1290
// line end:   1306
void handleLidOpen__Fv() {
	// address: 0xFFFFFFF0
	// size: 0x8
	auto unsigned char result[8];
}


// address: 0x8007F980
// line start: 1313
// line end:   1342
void strInit__Fv() {
}


// address: 0x8007F9F8
// line start: 1352
// line end:   1399
void strCallback__Fv() {
	// address: 0xFFFFFFF0
	// size: 0x8
	auto struct RECT old_slice;
	// register: 16
	register unsigned long *p_old_buffer;
	{
		{
		}
	}
}


// address: 0x8007FB44
// line start: 1407
// line end:   1424
unsigned long *strNext__Fv() {
	// address: 0xFFFFFFF0
	auto unsigned long *addr;
	// address: 0xFFFFFFF4
	// size: 0x20
	auto struct StHEADER *sector;
}


// address: 0x8007FB98
// line start: 1432
// line end:   1450
int strNextVlc__Fi(int DecodeData) {
	// register: 16
	register unsigned long *next;
}


// address: 0x8007FC00
// line start: 1456
// line end:   1474
void strKickCD__Fv() {
	// address: 0xFFFFFFF0
	auto unsigned char param;
	// address: 0xFFFFFFE8
	// size: 0x4
	auto struct CdlLOC loc;
}


// address: 0x8007FC6C
// line start: 1475
// line end:   1475
void _GLOBAL__I_GameFMV_IsMovie() {
	{
		{
		}
	}
}


// address: 0x800750CC
// line start: 83
// line end:   95
bool Competition_WonGame__Fv() {
	// register: 6
	register unsigned int medal_count;
	{
		// register: 4
		register int i;
	}
}


// address: 0x80075144
// line start: 100
// line end:   112
bool Competition_WonGameAllGold__Fv() {
	// register: 6
	register unsigned int medal_count;
	{
		// register: 4
		register int i;
	}
}


// address: 0x800751BC
// line start: 1348
// line end:   1349
bool Competition_IsOver__Fv() {
	{
		{
		}
	}
}


// address: 0x800751D4
// line start: 1353
// line end:   1356
void Competition_Init__Fv() {
	{
		{
			{
				// register: 4
				register int i;
				{
					// register: 17
					register unsigned char i;
					{
						// register: 4
						register unsigned char i;
						{
							{
								// register: 3
								register unsigned char j;
								{
									{
										{
											// register: 4
											register int i;
											{
												// register: 16
												register int i;
												{
													// register: 6
													register int slot;
													// register: 5
													register int j;
													// register: 4
													register int k;
													{
														// register: 4
														register int i;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80075470
// line start: 1360
// line end:   1363
void Competition_JudgeLogic__Fv() {
	{
		{
			{
				{
					{
						{
							// register: 23
							// size: 0x146C
							register struct CBruce_duplicate_s0 *pSkater;
							// register: 7
							register unsigned int temp;
							// register: 17
							register unsigned int score;
							// register: 4
							register int average_score;
							{
								// register: 22
								register int i;
								{
									// register: 5
									register int i;
									{
										// register: 5
										register int i;
										{
											// register: 3
											register int i;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x800758F0
// line start: 1367
// line end:   1370
void Competition_JudgeDisplay__Fv() {
	{
		{
			// register: 20
			register int dimness;
			// address: 0xFFFFFFD0
			// size: 0xF
			auto char text_buf[15];
			{
				// register: 17
				register int i;
				{
					{
						// register: 17
						register int average_score;
						{
							// register: 3
							register int i;
						}
					}
				}
			}
		}
	}
}


// address: 0x80075CD4
// line start: 1374
// line end:   1377
void Competition_LadderLogic__Fv() {
	{
		{
			{
				{
					{
						{
							{
								// register: 17
								register unsigned char i;
								{
									// register: 16
									register unsigned short base;
									{
										// register: 5
										register unsigned char j;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80075E50
// line start: 1381
// line end:   1384
void Competition_LadderDisplay__Fv() {
	{
		{
			// register: 17
			register unsigned char b;
			// register: 20
			register unsigned char a;
			// register: 17
			register unsigned char i;
			// address: 0xFFFFFF90
			// size: 0x2D
			auto char text_buf[45];
			{
				{
					{
						{
							// register: 7
							register unsigned int low_score;
							// register: 4
							register unsigned int score2;
							// register: 6
							register unsigned int score1;
							// register: 5
							register unsigned int score0;
							// register: 8
							register int dimness;
							{
								{
									{
										{
											// register: 6
											register unsigned int score2;
											// register: 4
											register unsigned int score1;
											// register: 5
											register unsigned int score0;
											{
												{
													// register: 2
													register int temp_b;
													{
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x800766A8
// line start: 1388
// line end:   1391
void Competition_WinLoseLogic__FR13EPausedStatusRi(enum EPausedStatus_duplicate_e2 *Status, int *Activated) {
	{
		// register: 18
		// size: 0x4
		register enum EPausedStatus_duplicate_e2 *Status;
		// register: 17
		register int *Activated;
		{
			{
				{
					{
						{
							{
								{
									{
										{
											{
												{
													{
														{
															{
																{
																	{
																		{
																			{
																				{
																					{
																						{
																							{
																								{
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80076A10
// line start: 1395
// line end:   1398
void Competition_WinLoseDisplay__Fv() {
	{
		{
			// register: 20
			register int our_placing;
			// address: 0xFFFFFFA0
			// size: 0x28
			auto char buf[40];
			{
				{
					{
						{
							// register: 17
							register unsigned char i;
							{
								// register: 16
								register unsigned short base;
								{
									// register: 5
									register unsigned char j;
									{
										// register: 10
										register int b;
										{
											// register: 5
											register unsigned int score2;
											// register: 3
											register unsigned int score1;
											// register: 4
											register unsigned int score0;
											{
												// register: 4
												register int i;
												{
													// register: 13
													register int i;
													{
														{
															{
																// register: 4
																register int i;
																{
																	{
																		{
																			{
																				{
																					{
																						{
																							{
																								{
																									// address: 0xFFFFFFD0
																									auto int third;
																									// address: 0xFFFFFFCC
																									auto int second;
																									// address: 0xFFFFFFC8
																									auto int first;
																									{
																										// register: 3
																										register int i;
																										{
																											{
																												{
																													{
																														{
																															{
																																{
																																	{
																																		{
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8007751C
// line start: 1402
// line end:   1403
bool Competition_JudgeFullyDisplayed__Fv() {
	{
		{
		}
	}
}


// address: 0x8007752C
// line start: 1407
// line end:   1408
bool Competition_LadderFullyDisplayed__Fv() {
	{
		{
		}
	}
}


// address: 0x8007753C
// line start: 1412
// line end:   1413
void Competition_FullyDisplayJudge__Fv() {
	{
		{
		}
	}
}


// address: 0x8007754C
// line start: 1417
// line end:   1418
void Competition_FullyDisplayLadder__Fv() {
	{
		{
		}
	}
}


// address: 0x8007755C
// line start: 1422
// line end:   1423
bool Competition_NewHeat__Fv() {
	{
		{
		}
	}
}


// address: 0x80077590
// line start: 1432
// line end:   1433
void Competition_MarqueeDisplay__Fv() {
	{
		{
			{
				{
				}
			}
		}
	}
}


// address: 0x80077634
// line start: 1437
// line end:   1438
void Competition_ResetMarquee__Fv() {
	{
		{
			{
				{
					{
						{
							{
								// register: 4
								register int i;
								{
									// register: 17
									register unsigned char i;
									{
										// register: 4
										register unsigned char i;
										{
											{
												// register: 3
												register unsigned char j;
												{
													{
														{
															// register: 4
															register int i;
															{
																// register: 16
																register int i;
																{
																	// register: 4
																	register int k;
																	// register: 5
																	register int j;
																	// register: 6
																	register int slot;
																	{
																		// register: 4
																		register int i;
																		{
																			{
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80077940
// line start: 1447
// line end:   1448
void Competition_EndGameLogic__FR13EPausedStatusRi(enum EPausedStatus_duplicate_e2 *Status, int *Activated) {
	{
		// register: 18
		// size: 0x4
		register enum EPausedStatus_duplicate_e2 *Status;
		// register: 5
		register int *Activated;
		{
			{
				{
					{
						{
							{
								{
									{
										{
											{
												{
													{
														{
															{
																{
																	{
																		{
																			{
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80077C70
// line start: 1452
// line end:   1453
void Competition_EndGameDisplay__Fv() {
	{
		{
			{
				{
					// address: 0xFFFFFFE0
					// size: 0xC
					auto enum EMedalType_duplicate_e2 m[3];
					{
						// register: 6
						register int i;
						{
							{
								{
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80078070
// line start: 1455
// line end:   1455
void _GLOBAL__D_MedalMessage() {
	{
		{
			{
			}
		}
	}
}


// address: 0x800780E0
// line start: 1455
// line end:   1455
void _GLOBAL__I_MedalMessage() {
	{
		{
			{
				{
					{
					}
				}
			}
		}
	}
}


// address: 0x80078120
// line start: 1326
// line end:   1330
bool GotMedal__12CCompetition(struct CCompetition *this) {
}


// address: 0x8007812C
// line start: 1341
// line end:   1455
void ___12CCompetition(struct CCompetition *this, int __in_chrg) {
	// register: 18
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x800781B4
// line start: 124
// line end:   503
void ___6CJudge(struct CJudge *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x800781E4
// line start: 92
// line end:   92
void ___6CClass_addr_800781E4(struct CClass *this, int __in_chrg) {
}


// address: 0x80078214
// size: 0x14
// line start: 15
// line end:   23
struct CQuat __ml__FRC5CQuatT0(struct CQuat *a, struct CQuat *b) {
	// address: 0xFFFFFFC8
	// size: 0x14
	auto struct CQuat q;
	{
		// register: 3
		// size: 0x14
		register struct CQuat *this;
		// register: 6
		// size: 0x14
		register struct CQuat *_ctor_arg;
		{
			// register: 6
			// size: 0x4
			register struct CClass *_ctor_arg;
			// register: 3
			// size: 0x4
			register struct CClass *this;
			{
				// register: 5
				// size: 0x14
				register struct CQuat *q;
				{
					// register: 10
					register int tempw;
					// register: 6
					register int tempz;
					// register: 7
					register int tempy;
					// register: 8
					register int tempx;
					{
						// register: 2
						// size: 0x14
						register struct CQuat *this;
						{
							// register: 2
							// size: 0x4
							register struct CClass *this;
							{
								{
									{
										{
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x800783E8
// size: 0x14
// line start: 27
// line end:   43
struct CQuat QFromV__FRC7CVector(struct CVector *v) {
	// register: 16
	register unsigned int mag;
	// address: 0xFFFFFFE0
	// size: 0xC
	auto struct CVector tempv;
	// register: 8
	register int cos2;
	// register: 4
	register int sin2;
	{
		{
			{
				// register: 17
				// size: 0x14
				register struct CQuat *this;
				{
					// register: 17
					// size: 0x4
					register struct CClass *this;
					{
						{
							{
								{
									// register: 17
									// size: 0x14
									register struct CQuat *this;
									// register: 8
									register int d;
									{
										// register: 17
										// size: 0x4
										register struct CClass *this;
										{
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80078500
// size: 0x14
// line start: 46
// line end:   51
struct CQuat QFromXRot__Fs(short angle) {
	// register: 6
	register int cos2;
	// register: 4
	register int sin2;
	{
		// register: 2
		// size: 0x14
		register struct CQuat *this;
		// register: 4
		register int a;
		// register: 6
		register int d;
		{
			// register: 2
			// size: 0x4
			register struct CClass *this;
			{
			}
		}
	}
}


// address: 0x8007853C
// size: 0x14
// line start: 54
// line end:   59
struct CQuat QFromYRot__Fs(short angle) {
	// register: 6
	register int cos2;
	// register: 4
	register int sin2;
	{
		// register: 2
		// size: 0x14
		register struct CQuat *this;
		// register: 4
		register int b;
		// register: 6
		register int d;
		{
			// register: 2
			// size: 0x4
			register struct CClass *this;
			{
			}
		}
	}
}


// address: 0x80078578
// size: 0x14
// line start: 62
// line end:   67
struct CQuat QFromZRot__Fs(short angle) {
	// register: 6
	register int cos2;
	// register: 4
	register int sin2;
	{
		// register: 2
		// size: 0x14
		register struct CQuat *this;
		// register: 4
		register int c;
		// register: 6
		register int d;
		{
			// register: 2
			// size: 0x4
			register struct CClass *this;
			{
			}
		}
	}
}


// address: 0x800785B4
// line start: 70
// line end:   104
void QToM__FRC5CQuatR6MATRIX(struct CQuat *q, struct MATRIX *m) {
	// register: 14
	register int wx;
	// register: 13
	register int wy;
	// register: 8
	register int wz;
	// register: 11
	register int xx;
	// register: 4
	register int xy;
	// register: 6
	register int xz;
	// register: 12
	register int yy;
	// register: 7
	register int yz;
	// register: 3
	register int zz;
}


// address: 0x800786C4
// line start: 119
// line end:   168
void MToQ__FRC6MATRIXR5CQuat(struct MATRIX *m, struct CQuat *q) {
	// register: 2
	register int tr;
	// register: 6
	register int s;
	// register: 17
	register int i;
	// register: 18
	register int j;
	// register: 21
	register int k;
}


// address: 0x80078A90
// line start: 188
// line end:   243
void Quat_Slerp__FG5CQuatT0iR5CQuat(struct CQuat p, struct CQuat q, int t, struct CQuat *qt) {
	// register: 2
	register int omega;
	// register: 4
	register int cosom;
	// register: 6
	register int sinom;
	// register: 10
	register int sclp;
	// register: 9
	register int sclq;
	{
		// register: 17
		// size: 0x14
		register struct CQuat *this;
		{
			// register: 8
			register int mag;
			{
				// register: 19
				// size: 0x14
				register struct CQuat *this;
				{
					// register: 8
					register int mag;
					{
						// register: 18
						// size: 0x14
						register struct CQuat *this;
						{
							// register: 8
							register int mag;
							{
								{
									// register: 17
									// size: 0x14
									register struct CQuat *this;
									{
										// register: 17
										// size: 0x4
										register struct CClass *this;
										{
											{
												// register: 19
												// size: 0x14
												register struct CQuat *this;
												{
													// register: 19
													// size: 0x4
													register struct CClass *this;
													{
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80079050
// line start: 132
// line end:   18
void ___5CQuat_addr_80079050(struct CQuat *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x80079080
// line start: 92
// line end:   92
void ___6CClass_addr_80079080(struct CClass *this, int __in_chrg) {
}


// address: 0x80073274
// line start: 604
// line end:   606
void TrickTips_Display__Fv() {
	{
		// register: 17
		register unsigned short xpos;
		{
			{
				{
				}
			}
		}
	}
}


// address: 0x8007347C
// line start: 610
// line end:   612
void TrickTips_Init__Fv() {
	{
		{
		}
	}
}


// address: 0x80073514
// line start: 616
// line end:   619
void TrickTips_Update__Fv() {
	{
		{
			{
				{
					{
						{
							{
								{
									{
										// register: 5
										register int i;
										{
											{
												{
													{
														{
															// register: 5
															register int tip;
															{
																{
																	// register: 5
																	register int tip;
																	{
																		{
																			{
																				// register: 5
																				register int tip_mask;
																				// register: 6
																				register int tip_used;
																				// register: 12
																				register int tip_bank;
																				{
																					{
																						{
																							{
																								{
																									{
																										{
																											{
																												{
																													{
																														// register: 4
																														register int tip_mask;
																														// register: 2
																														register int tip_used;
																														{
																															{
																																{
																																	{
																																		{
																																			{
																																				{
																																					{
																																						{
																																							{
																																								// register: 4
																																								register int tip_mask;
																																								// register: 2
																																								register int tip_used;
																																								{
																																									{
																																										{
																																											{
																																												{
																																													{
																																														{
																																															{
																																																// register: 4
																																																register int tip_mask;
																																																// register: 2
																																																register int tip_used;
																																																{
																																																	{
																																																		{
																																																			{
																																																				{
																																																					{
																																																						{
																																																							{
																																																								// register: 4
																																																								register int tip_mask;
																																																								// register: 2
																																																								register int tip_used;
																																																								{
																																																									{
																																																										{
																																																											{
																																																												{
																																																													{
																																																														{
																																																															{
																																																																// register: 4
																																																																register int tip_mask;
																																																																// register: 2
																																																																register int tip_used;
																																																																{
																																																																	{
																																																																		{
																																																																			{
																																																																				{
																																																																					{
																																																																						{
																																																																							{
																																																																								// register: 4
																																																																								register int tip_mask;
																																																																								// register: 2
																																																																								register int tip_used;
																																																																								{
																																																																									{
																																																																									}
																																																																								}
																																																																							}
																																																																						}
																																																																					}
																																																																				}
																																																																			}
																																																																		}
																																																																	}
																																																																}
																																																															}
																																																														}
																																																													}
																																																												}
																																																											}
																																																										}
																																																									}
																																																								}
																																																							}
																																																						}
																																																					}
																																																				}
																																																			}
																																																		}
																																																	}
																																																}
																																															}
																																														}
																																													}
																																												}
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80073F80
// line start: 634
// line end:   634
void _GLOBAL__D_TEXT_TIP() {
	{
		{
			{
			}
		}
	}
}


// address: 0x80073F98
// line start: 634
// line end:   634
void _GLOBAL__I_TEXT_TIP() {
	{
		{
		}
	}
}


// address: 0x80073FA8
// line start: 598
// line end:   634
void ___16CTrickTipMonitor(struct CTrickTipMonitor *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x80073FD8
// line start: 92
// line end:   92
void ___6CClass_addr_80073FD8(struct CClass *this, int __in_chrg) {
}


// address: 0x80074008
// line start: 81
// line end:   85
bool DisplayTitle__5CTape() {
}


// address: 0x80074014
// line start: 89
// line end:   93
bool DisplayContinueButton__5CTape() {
}


// address: 0x80074020
// size: 0x170
// line start: 98
// line end:   219
struct CTape *__5CTapeUsRC7CVectorT2iiT2Uii(struct CTape *this, unsigned short PowerupType, struct CVector *Pos, struct CVector *Pos2, int Size1, int Size2, struct CVector *Vel, unsigned int Flags, int Lifetime) {
	{
		{
			{
				{
					{
						{
							{
								// register: 2
								// size: 0x6
								register struct CSVector *this;
								{
									{
										// register: 5
										// size: 0x3
										register struct CFriction *this;
										{
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80074368
// line start: 223
// line end:   226
void ___5CTape(struct CTape *this, int __in_chrg) {
}


// address: 0x800743D4
// line start: 236
// line end:   241
void DontDisplay__5CTape(struct CTape *this) {
}


// address: 0x8007440C
// line start: 252
// line end:   260
void CreateBit__5CTape(struct CTape *this) {
}


// address: 0x80074420
// line start: 264
// line end:   268
void DeleteStuff__5CTape(struct CTape *this) {
}


// address: 0x8007446C
// line start: 279
// line end:   288
void DoPhysics__5CTape(struct CTape *this) {
}


// address: 0x8007451C
// line start: 293
// line end:   458
void AI__5CTapei(struct CTape *this, int tape_no) {
	// register: 10
	register int message_count;
	// address: 0xFFFFFFA0
	// size: 0x14
	auto struct STapeMessage *messages[5];
	// register: 5
	register int message_no;
	{
		{
			// address: 0xFFFFFFD0
			auto int temptime;
			// address: 0xFFFFFFA0
			// size: 0xC
			auto struct CVector pos_offset;
			// register: 19
			register int size_offset;
			{
				// register: 2
				// size: 0x6
				register struct CSVector *this;
				{
					{
						// register: 4
						register int i;
						{
							// register: 4
							register int i;
							{
								// register: 4
								register int i;
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80074B94
// size: 0x170
// line start: 476
// line end:   528
struct CTape *Tape_Create__Fiiiiiiii(int x, int y, int z, int Size, int x2, int y2, int z2, int Size2) {
	// register: 6
	// size: 0x170
	register struct CTape *Tape;
	// address: 0xFFFFFFC0
	// size: 0x8
	auto struct SVECTOR vec;
	// address: 0xFFFFFFC8
	// size: 0x10
	auto struct VECTOR vec2;
	// address: 0xFFFFFFD8
	// size: 0xC
	auto struct CVector TapePos;
	// address: 0xFFFFFFE8
	// size: 0xC
	auto struct CVector TapePos2;
	{
		{
			{
				{
				}
			}
		}
	}
}


// address: 0x80074DC4
// line start: 99
// line end:   101
void ___6CMedal(struct CMedal *this, int __in_chrg) {
}


// address: 0x80074E20
// line start: 106
// line end:   108
void DeleteStuff__6CMedal(struct CMedal *this) {
}


// address: 0x80074E28
// line start: 111
// line end:   119
void DoPhysics__6CMedal(struct CMedal *this) {
}


// address: 0x80074ED8
// line start: 125
// line end:   129
void AI__6CMedal(struct CMedal *this) {
}


// address: 0x80074EF8
// size: 0x138
// line start: 133
// line end:   194
struct CPowerUp *Medal_Create__F10EMedalTypeiiiii(enum EMedalType_duplicate_e2 t, int x, int y, int z, int Size, int yvel) {
	// register: 8
	// size: 0x138
	register struct CPowerUp *Medal;
	// address: 0xFFFFFFD0
	// size: 0x8
	auto struct SVECTOR vec;
	// address: 0xFFFFFFD8
	// size: 0x10
	auto struct VECTOR vec2;
	// address: 0xFFFFFFE8
	// size: 0xC
	auto struct CVector MedalPos;
	{
		{
			{
				// register: 5
				// size: 0x6
				register struct CSVector *this;
				{
				}
			}
		}
	}
}


// address: 0x800790B0
// line start: 13
// line end:   22
void Backgrnd_On__FUs(unsigned short index) {
	// register: 3
	// size: 0x10C
	register struct CBackground *p_back;
}


// address: 0x800790FC
// line start: 27
// line end:   36
void Backgrnd_Off__FUs(unsigned short index) {
	// register: 3
	// size: 0x10C
	register struct CBackground *p_back;
}


// address: 0x80079148
// size: 0x10C
// line start: 43
// line end:   51
struct CBackground *__11CBackgroundUiRC8CSVector(struct CBackground *this, unsigned int checksum, struct CSVector *ang_vel) {
}


// address: 0x800791DC
// line start: 57
// line end:   62
void ___11CBackground(struct CBackground *this, int __in_chrg) {
}


// address: 0x8007924C
// line start: 68
// line end:   72
void AI__11CBackground(struct CBackground *this) {
}


// address: 0x80079274
// line start: 35
// line end:   39
void frug__FUi(unsigned int n) {
}


// address: 0x800792C4
// line start: 43
// line end:   295
int Shell_DoCheatProcessing__Fv() {
}


// address: 0x800793C8
// line start: 301
// line end:   311
void Shell_PauseScreen__Fv() {
}


// address: 0x800793D0
// line start: 258
// line end:   262
void Camera_InitialRand__Fi(int a) {
}


// address: 0x800793F4
// size: 0x684
// line start: 295
// line end:   435
struct CCamera *__7CCameraP5CBodyUs(struct CCamera *this, struct CBody_duplicate_s1 *tripod, unsigned short mike_index) {
	{
		{
			{
				{
					{
						{
							{
								{
									{
										{
											{
												{
													{
														{
															{
																{
																	{
																		{
																			// register: 3
																			// size: 0x14
																			register struct CQuat *this;
																			{
																				// register: 3
																				// size: 0x4
																				register struct CClass *this;
																				{
																					{
																						// register: 2
																						// size: 0x14
																						register struct CQuat *this;
																						{
																							// register: 2
																							// size: 0x4
																							register struct CClass *this;
																							{
																								{
																									// register: 3
																									// size: 0x14
																									register struct CQuat *this;
																									{
																										// register: 3
																										// size: 0x4
																										register struct CClass *this;
																										{
																											{
																												// register: 2
																												// size: 0x14
																												register struct CQuat *this;
																												{
																													// register: 2
																													// size: 0x4
																													register struct CClass *this;
																													{
																														{
																															// register: 3
																															// size: 0x14
																															register struct CQuat *this;
																															{
																																// register: 3
																																// size: 0x4
																																register struct CClass *this;
																																{
																																	{
																																		{
																																			{
																																				{
																																					{
																																						{
																																							{
																																								{
																																									{
																																										{
																																											{
																																												{
																																													{
																																														{
																																															{
																																																// register: 4
																																																register unsigned int *t;
																																																{
																																																	{
																																																		// register: 2
																																																		// size: 0x14
																																																		register struct CQuat *this;
																																																		{
																																																			// register: 2
																																																			// size: 0x4
																																																			register struct CClass *this;
																																																			{
																																																				{
																																																					{
																																																						{
																																																							{
																																																								{
																																																									{
																																																										{
																																																											{
																																																												{
																																																													{
																																																														// register: 2
																																																														// size: 0x14
																																																														register struct CQuat *this;
																																																														{
																																																															// register: 2
																																																															// size: 0x4
																																																															register struct CClass *this;
																																																															{
																																																																{
																																																																	{
																																																																		// register: 3
																																																																		// size: 0xC
																																																																		register struct CVector *this;
																																																																		{
																																																																		}
																																																																	}
																																																																}
																																																															}
																																																														}
																																																													}
																																																												}
																																																											}
																																																										}
																																																									}
																																																								}
																																																							}
																																																						}
																																																					}
																																																				}
																																																			}
																																																		}
																																																	}
																																																}
																																															}
																																														}
																																													}
																																												}
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x800796CC
// line start: 440
// line end:   454
void ___7CCamera(struct CCamera *this, int __in_chrg) {
	{
		{
			{
				{
					{
						{
							{
								{
									{
										{
											{
												{
													{
														{
															{
																{
																	{
																		{
																			{
																				{
																					{
																						{
																							{
																								{
																									{
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80079794
// line start: 465
// line end:   467
void SetCollisionRayLR__7CCamerai(struct CCamera *this, int r) {
}


// address: 0x8007979C
// line start: 471
// line end:   473
void SetCollisionRayBack__7CCamerai(struct CCamera *this, int r) {
}


// address: 0x800797A4
// line start: 477
// line end:   479
void SetCollisionAngLR__7CCameras(struct CCamera *this, short a) {
}


// address: 0x800797AC
// line start: 483
// line end:   485
void SetCollisionAngBack__7CCameras(struct CCamera *this, short a) {
}


// address: 0x800797B4
// line start: 489
// line end:   494
void SendShake__FRC7CVectorP5CBody10EShakeType(struct CVector *pos, struct CBody_duplicate_s1 *pOb, enum EShakeType ShakeMagnitude) {
}


// address: 0x800797E4
// line start: 499
// line end:   529
void Shake__7CCameraRC7CVector10EShakeType(struct CCamera *this, struct CVector *pos, enum EShakeType ShakeMagnitude) {
}


// address: 0x80079908
// line start: 535
// line end:   537
void SetComplexMode__7CCameraUs(struct CCamera *this, unsigned short mode) {
}


// address: 0x80079910
// line start: 542
// line end:   612
void LoadIntoMikeCamera__7CCamera(struct CCamera *this) {
	// address: 0xFFFFFFD8
	// size: 0x10
	auto struct VECTOR v;
}


// address: 0x80079B94
// line start: 701
// line end:   728
void ResetOrientation__7CCamera(struct CCamera *this) {
	// address: 0xFFFFFFB8
	// size: 0x10
	auto struct VECTOR vtemp1;
	// address: 0xFFFFFFC8
	// size: 0x10
	auto struct VECTOR vtemp2;
	// register: 4
	// size: 0x146C
	register struct CBruce_duplicate_s0 *pBruce;
}


// address: 0x80079D3C
// line start: 736
// line end:   1727
void ReactToCollision__7CCamera(struct CCamera *this) {
	// address: 0xFFFFFE10
	// size: 0xA4
	auto struct SLineInfo line_info;
	// address: 0xFFFFFEB8
	// size: 0x20
	auto struct MATRIX m;
	// address: 0xFFFFFED8
	// size: 0x10
	auto struct VECTOR vLeft;
	// address: 0xFFFFFEE8
	// size: 0x10
	auto struct VECTOR vRight;
	// address: 0xFFFFFEF8
	// size: 0x10
	auto struct VECTOR vBack;
	// address: 0xFFFFFF08
	// size: 0x10
	auto struct VECTOR vTemp;
	// address: 0xFFFFFF18
	// size: 0xC
	auto struct CVector vVel;
	// address: 0xFFFFFF28
	// size: 0xC
	auto struct CVector vStick;
	// address: 0xFFFFFF38
	// size: 0xC
	auto struct CVector vColCheck;
	// address: 0xFFFFFF48
	// size: 0x10
	auto struct VECTOR vOffset;
	{
		{
			{
				{
					{
						{
							{
								{
									{
										// register: 22
										// size: 0x684
										register struct CCamera *this;
										{
											{
												{
													// register: 6
													register int _x;
													// register: 2
													register int _y;
													// register: 7
													register int _z;
													{
														{
															{
																{
																	{
																		// register: 2
																		register int ratio;
																		// register: 2
																		register int ang;
																		{
																			{
																				{
																					{
																						// register: 2
																						register int ratio;
																						// register: 4
																						register int ang;
																						{
																							{
																								{
																									{
																										{
																											// register: 22
																											// size: 0x684
																											register struct CCamera *this;
																											{
																												{
																													{
																														// register: 2
																														register int ratio;
																														// register: 3
																														register int ang;
																														{
																															{
																																{
																																	// register: 22
																																	// size: 0x684
																																	register struct CCamera *this;
																																	{
																																		{
																																			{
																																				// register: 2
																																				register int ratio;
																																				// register: 3
																																				register int ang;
																																				{
																																					{
																																						{
																																							{
																																								// register: 16
																																								register unsigned int ratioL;
																																								// register: 17
																																								register unsigned int ratioR;
																																								// register: 5
																																								register int ang;
																																								{
																																									// register: 22
																																									// size: 0x684
																																									register struct CCamera *this;
																																									{
																																										{
																																											{
																																												{
																																													{
																																														// register: 22
																																														// size: 0x684
																																														register struct CCamera *this;
																																														{
																																															{
																																																// register: 22
																																																// size: 0x684
																																																register struct CCamera *this;
																																																{
																																																	{
																																																		// register: 22
																																																		// size: 0x684
																																																		register struct CCamera *this;
																																																		{
																																																			{
																																																				{
																																																					// register: 22
																																																					// size: 0x684
																																																					register struct CCamera *this;
																																																					{
																																																						{
																																																							// register: 22
																																																							// size: 0x684
																																																							register struct CCamera *this;
																																																							{
																																																								{
																																																									// register: 22
																																																									// size: 0x684
																																																									register struct CCamera *this;
																																																									{
																																																										{
																																																											{
																																																												{
																																																													// register: 22
																																																													// size: 0x684
																																																													register struct CCamera *this;
																																																													{
																																																														{
																																																															{
																																																																{
																																																																	// register: 2
																																																																	register int ratio;
																																																																	// register: 2
																																																																	register int ang;
																																																																	{
																																																																		{
																																																																			// register: 22
																																																																			// size: 0x684
																																																																			register struct CCamera *this;
																																																																			{
																																																																				{
																																																																					{
																																																																						// register: 22
																																																																						// size: 0x684
																																																																						register struct CCamera *this;
																																																																						{
																																																																							{
																																																																								{
																																																																									{
																																																																										{
																																																																											{
																																																																												{
																																																																													{
																																																																														{
																																																																															// register: 22
																																																																															// size: 0x684
																																																																															register struct CCamera *this;
																																																																															{
																																																																																{
																																																																																	{
																																																																																		// register: 22
																																																																																		// size: 0x684
																																																																																		register struct CCamera *this;
																																																																																		{
																																																																																			{
																																																																																				{
																																																																																					{
																																																																																						{
																																																																																							{
																																																																																								{
																																																																																									{
																																																																																										{
																																																																																											// register: 22
																																																																																											// size: 0x684
																																																																																											register struct CCamera *this;
																																																																																											{
																																																																																												{
																																																																																													{
																																																																																														// register: 22
																																																																																														// size: 0x684
																																																																																														register struct CCamera *this;
																																																																																														{
																																																																																															{
																																																																																																{
																																																																																																	{
																																																																																																		{
																																																																																																			{
																																																																																																				{
																																																																																																					{
																																																																																																						{
																																																																																																							{
																																																																																																								{
																																																																																																									// register: 7
																																																																																																									register int tempw;
																																																																																																									// register: 6
																																																																																																									register int tempz;
																																																																																																									// register: 4
																																																																																																									register int tempy;
																																																																																																									// register: 3
																																																																																																									register int tempx;
																																																																																																									{
																																																																																																										{
																																																																																																											{
																																																																																																												{
																																																																																																													{
																																																																																																														// register: 22
																																																																																																														// size: 0x684
																																																																																																														register struct CCamera *this;
																																																																																																														{
																																																																																																															{
																																																																																																																{
																																																																																																																	// register: 22
																																																																																																																	// size: 0x684
																																																																																																																	register struct CCamera *this;
																																																																																																																	{
																																																																																																																		{
																																																																																																																			{
																																																																																																																				// register: 7
																																																																																																																				register int tempw;
																																																																																																																				// register: 6
																																																																																																																				register int tempz;
																																																																																																																				// register: 4
																																																																																																																				register int tempy;
																																																																																																																				// register: 3
																																																																																																																				register int tempx;
																																																																																																																				{
																																																																																																																					{
																																																																																																																						{
																																																																																																																							{
																																																																																																																								{
																																																																																																																									// address: 0xFFFFFF70
																																																																																																																									// size: 0x10
																																																																																																																									auto struct VECTOR v_temp;
																																																																																																																									// address: 0xFFFFFF80
																																																																																																																									// size: 0x10
																																																																																																																									auto struct VECTOR v_temp2;
																																																																																																																									// address: 0xFFFFFF58
																																																																																																																									// size: 0xC
																																																																																																																									auto struct CVector vworlddown;
																																																																																																																									// address: 0xFFFFFF90
																																																																																																																									// size: 0xC
																																																																																																																									auto struct CVector vdown;
																																																																																																																									// address: 0xFFFFFFA0
																																																																																																																									// size: 0xC
																																																																																																																									auto struct CVector vstop;
																																																																																																																									// address: 0xFFFFFFB8
																																																																																																																									// size: 0x20
																																																																																																																									auto struct MATRIX mstop;
																																																																																																																									// register: 17
																																																																																																																									register int dot_stop;
																																																																																																																									{
																																																																																																																										{
																																																																																																																											{
																																																																																																																												{
																																																																																																																													{
																																																																																																																														{
																																																																																																																															{
																																																																																																																																{
																																																																																																																																	{
																																																																																																																																		{
																																																																																																																																			{
																																																																																																																																				// register: 2
																																																																																																																																				// size: 0x14
																																																																																																																																				register struct CQuat *_ctor_arg;
																																																																																																																																				{
																																																																																																																																					// register: 2
																																																																																																																																					// size: 0x4
																																																																																																																																					register struct CClass *_ctor_arg;
																																																																																																																																					{
																																																																																																																																						{
																																																																																																																																							{
																																																																																																																																								{
																																																																																																																																									{
																																																																																																																																										{
																																																																																																																																											{
																																																																																																																																												{
																																																																																																																																													// register: 22
																																																																																																																																													// size: 0x684
																																																																																																																																													register struct CCamera *this;
																																																																																																																																													{
																																																																																																																																														{
																																																																																																																																															// register: 22
																																																																																																																																															// size: 0x684
																																																																																																																																															register struct CCamera *this;
																																																																																																																																															{
																																																																																																																																																{
																																																																																																																																																	// register: 22
																																																																																																																																																	// size: 0x684
																																																																																																																																																	register struct CCamera *this;
																																																																																																																																																	{
																																																																																																																																																		{
																																																																																																																																																			{
																																																																																																																																																				{
																																																																																																																																																					{
																																																																																																																																																						// register: 2
																																																																																																																																																						// size: 0x14
																																																																																																																																																						register struct CQuat *_ctor_arg;
																																																																																																																																																						{
																																																																																																																																																							// register: 2
																																																																																																																																																							// size: 0x4
																																																																																																																																																							register struct CClass *_ctor_arg;
																																																																																																																																																							{
																																																																																																																																																								{
																																																																																																																																																									{
																																																																																																																																																										{
																																																																																																																																																											// register: 22
																																																																																																																																																											// size: 0x684
																																																																																																																																																											register struct CCamera *this;
																																																																																																																																																											{
																																																																																																																																																												{
																																																																																																																																																													// register: 22
																																																																																																																																																													// size: 0x684
																																																																																																																																																													register struct CCamera *this;
																																																																																																																																																													{
																																																																																																																																																														{
																																																																																																																																																															// register: 22
																																																																																																																																																															// size: 0x684
																																																																																																																																																															register struct CCamera *this;
																																																																																																																																																															{
																																																																																																																																																																{
																																																																																																																																																																	{
																																																																																																																																																																		// register: 22
																																																																																																																																																																		// size: 0x684
																																																																																																																																																																		register struct CCamera *this;
																																																																																																																																																																		{
																																																																																																																																																																			{
																																																																																																																																																																				{
																																																																																																																																																																					{
																																																																																																																																																																						{
																																																																																																																																																																							{
																																																																																																																																																																								{
																																																																																																																																																																									{
																																																																																																																																																																										{
																																																																																																																																																																											{
																																																																																																																																																																												// register: 22
																																																																																																																																																																												// size: 0x684
																																																																																																																																																																												register struct CCamera *this;
																																																																																																																																																																												{
																																																																																																																																																																													{
																																																																																																																																																																														// register: 22
																																																																																																																																																																														// size: 0x684
																																																																																																																																																																														register struct CCamera *this;
																																																																																																																																																																														{
																																																																																																																																																																															{
																																																																																																																																																																																// register: 22
																																																																																																																																																																																// size: 0x684
																																																																																																																																																																																register struct CCamera *this;
																																																																																																																																																																																{
																																																																																																																																																																																	{
																																																																																																																																																																																		{
																																																																																																																																																																																			// register: 22
																																																																																																																																																																																			// size: 0x684
																																																																																																																																																																																			register struct CCamera *this;
																																																																																																																																																																																			{
																																																																																																																																																																																				{
																																																																																																																																																																																					{
																																																																																																																																																																																						{
																																																																																																																																																																																							{
																																																																																																																																																																																								{
																																																																																																																																																																																									{
																																																																																																																																																																																										{
																																																																																																																																																																																											{
																																																																																																																																																																																												{
																																																																																																																																																																																													{
																																																																																																																																																																																														// register: 7
																																																																																																																																																																																														register int tempw;
																																																																																																																																																																																														// register: 6
																																																																																																																																																																																														register int tempz;
																																																																																																																																																																																														// register: 4
																																																																																																																																																																																														register int tempy;
																																																																																																																																																																																														// register: 3
																																																																																																																																																																																														register int tempx;
																																																																																																																																																																																														{
																																																																																																																																																																																															{
																																																																																																																																																																																																{
																																																																																																																																																																																																}
																																																																																																																																																																																															}
																																																																																																																																																																																														}
																																																																																																																																																																																													}
																																																																																																																																																																																												}
																																																																																																																																																																																											}
																																																																																																																																																																																										}
																																																																																																																																																																																									}
																																																																																																																																																																																								}
																																																																																																																																																																																							}
																																																																																																																																																																																						}
																																																																																																																																																																																					}
																																																																																																																																																																																				}
																																																																																																																																																																																			}
																																																																																																																																																																																		}
																																																																																																																																																																																	}
																																																																																																																																																																																}
																																																																																																																																																																															}
																																																																																																																																																																														}
																																																																																																																																																																													}
																																																																																																																																																																												}
																																																																																																																																																																											}
																																																																																																																																																																										}
																																																																																																																																																																									}
																																																																																																																																																																								}
																																																																																																																																																																							}
																																																																																																																																																																						}
																																																																																																																																																																					}
																																																																																																																																																																				}
																																																																																																																																																																			}
																																																																																																																																																																		}
																																																																																																																																																																	}
																																																																																																																																																																}
																																																																																																																																																															}
																																																																																																																																																														}
																																																																																																																																																													}
																																																																																																																																																												}
																																																																																																																																																											}
																																																																																																																																																										}
																																																																																																																																																									}
																																																																																																																																																								}
																																																																																																																																																							}
																																																																																																																																																						}
																																																																																																																																																					}
																																																																																																																																																				}
																																																																																																																																																			}
																																																																																																																																																		}
																																																																																																																																																	}
																																																																																																																																																}
																																																																																																																																															}
																																																																																																																																														}
																																																																																																																																													}
																																																																																																																																												}
																																																																																																																																											}
																																																																																																																																										}
																																																																																																																																									}
																																																																																																																																								}
																																																																																																																																							}
																																																																																																																																						}
																																																																																																																																					}
																																																																																																																																				}
																																																																																																																																			}
																																																																																																																																		}
																																																																																																																																	}
																																																																																																																																}
																																																																																																																															}
																																																																																																																														}
																																																																																																																													}
																																																																																																																												}
																																																																																																																											}
																																																																																																																										}
																																																																																																																									}
																																																																																																																								}
																																																																																																																							}
																																																																																																																						}
																																																																																																																					}
																																																																																																																				}
																																																																																																																			}
																																																																																																																		}
																																																																																																																	}
																																																																																																																}
																																																																																																															}
																																																																																																														}
																																																																																																													}
																																																																																																												}
																																																																																																											}
																																																																																																										}
																																																																																																									}
																																																																																																								}
																																																																																																							}
																																																																																																						}
																																																																																																					}
																																																																																																				}
																																																																																																			}
																																																																																																		}
																																																																																																	}
																																																																																																}
																																																																																															}
																																																																																														}
																																																																																													}
																																																																																												}
																																																																																											}
																																																																																										}
																																																																																									}
																																																																																								}
																																																																																							}
																																																																																						}
																																																																																					}
																																																																																				}
																																																																																			}
																																																																																		}
																																																																																	}
																																																																																}
																																																																															}
																																																																														}
																																																																													}
																																																																												}
																																																																											}
																																																																										}
																																																																									}
																																																																								}
																																																																							}
																																																																						}
																																																																					}
																																																																				}
																																																																			}
																																																																		}
																																																																	}
																																																																}
																																																															}
																																																														}
																																																													}
																																																												}
																																																											}
																																																										}
																																																									}
																																																								}
																																																							}
																																																						}
																																																					}
																																																				}
																																																			}
																																																		}
																																																	}
																																																}
																																															}
																																														}
																																													}
																																												}
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8007B284
// line start: 1735
// line end:   2531
void MoveToDesiredPos__7CCameraUi(struct CCamera *this, unsigned int normal_slerp) {
	// address: 0xFFFFFE70
	// size: 0xC
	auto struct CVector old_pos;
	// address: 0xFFFFFE80
	// size: 0xC
	auto struct CVector Dist;
	// register: 4
	register int Spd;
	// register: 5
	register int Frames;
	// register: 20
	register int mph;
	// address: 0xFFFFFE90
	// size: 0x10
	auto struct VECTOR v1;
	// address: 0xFFFFFEA0
	// size: 0x10
	auto struct VECTOR v2;
	// register: 2
	register int speed_lag_dist;
	// register: 5
	register int temptime;
	// address: 0xFFFFFEB0
	// size: 0x20
	auto struct MATRIX m;
	{
		{
			// address: 0xFFFFFE70
			// size: 0xC
			auto struct CVector U;
			// address: 0xFFFFFE80
			// size: 0xC
			auto struct CVector V;
			// address: 0xFFFFFE90
			// size: 0xC
			auto struct CVector N;
			// register: 17
			register int dot;
			// address: 0xFFFFFEB0
			// size: 0x14
			auto struct CQuat tempO;
			{
				{
					{
						{
							{
								{
									{
										{
											{
												{
													{
														{
															// register: 2
															// size: 0x14
															register struct CQuat *_ctor_arg;
															{
																// register: 2
																// size: 0x4
																register struct CClass *_ctor_arg;
																{
																	{
																		{
																			{
																				{
																					{
																						{
																							{
																								{
																									{
																										{
																											// register: 5
																											register int i;
																											{
																												// register: 6
																												register int i;
																												{
																													{
																														// address: 0xFFFFFEB0
																														// size: 0x14
																														auto struct CQuat wouldbeO;
																														{
																															{
																																{
																																	{
																																		// address: 0xFFFFFEF8
																																		// size: 0x20
																																		auto struct MATRIX m;
																																		// address: 0xFFFFFEC8
																																		// size: 0x10
																																		auto struct VECTOR v;
																																		// address: 0xFFFFFF18
																																		// size: 0x10
																																		auto struct VECTOR vCheck;
																																		// address: 0xFFFFFF28
																																		// size: 0xA4
																																		auto struct SLineInfo line_info;
																																		{
																																			{
																																				{
																																					{
																																						{
																																							{
																																								{
																																									{
																																										{
																																											{
																																												{
																																													{
																																														{
																																															{
																																																{
																																																	{
																																																		{
																																																			{
																																																				{
																																																					{
																																																						{
																																																							{
																																																								// register: 2
																																																								// size: 0x14
																																																								register struct CQuat *_ctor_arg;
																																																								{
																																																									// register: 2
																																																									// size: 0x4
																																																									register struct CClass *_ctor_arg;
																																																									{
																																																										{
																																																											{
																																																												// register: 20
																																																												register bool loosen_up;
																																																												{
																																																													{
																																																														{
																																																															{
																																																																{
																																																																	{
																																																																		{
																																																																			{
																																																																				{
																																																																					{
																																																																						{
																																																																							{
																																																																								{
																																																																									{
																																																																										{
																																																																											{
																																																																												{
																																																																													{
																																																																														{
																																																																															{
																																																																																{
																																																																																	{
																																																																																		{
																																																																																			{
																																																																																				{
																																																																																					// register: 2
																																																																																					// size: 0x14
																																																																																					register struct CQuat *_ctor_arg;
																																																																																					{
																																																																																						// register: 2
																																																																																						// size: 0x4
																																																																																						register struct CClass *_ctor_arg;
																																																																																						{
																																																																																							{
																																																																																								{
																																																																																									{
																																																																																										{
																																																																																											{
																																																																																												// register: 2
																																																																																												// size: 0x14
																																																																																												register struct CQuat *_ctor_arg;
																																																																																												{
																																																																																													// register: 2
																																																																																													// size: 0x4
																																																																																													register struct CClass *_ctor_arg;
																																																																																													{
																																																																																														{
																																																																																															{
																																																																																																{
																																																																																																	{
																																																																																																		{
																																																																																																			// register: 2
																																																																																																			// size: 0x14
																																																																																																			register struct CQuat *_ctor_arg;
																																																																																																			{
																																																																																																				// register: 2
																																																																																																				// size: 0x4
																																																																																																				register struct CClass *_ctor_arg;
																																																																																																				{
																																																																																																					{
																																																																																																					}
																																																																																																				}
																																																																																																			}
																																																																																																		}
																																																																																																	}
																																																																																																}
																																																																																															}
																																																																																														}
																																																																																													}
																																																																																												}
																																																																																											}
																																																																																										}
																																																																																									}
																																																																																								}
																																																																																							}
																																																																																						}
																																																																																					}
																																																																																				}
																																																																																			}
																																																																																		}
																																																																																	}
																																																																																}
																																																																															}
																																																																														}
																																																																													}
																																																																												}
																																																																											}
																																																																										}
																																																																									}
																																																																								}
																																																																							}
																																																																						}
																																																																					}
																																																																				}
																																																																			}
																																																																		}
																																																																	}
																																																																}
																																																															}
																																																														}
																																																													}
																																																												}
																																																											}
																																																										}
																																																									}
																																																								}
																																																							}
																																																						}
																																																					}
																																																				}
																																																			}
																																																		}
																																																	}
																																																}
																																															}
																																														}
																																													}
																																												}
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8007BFAC
// line start: 2675
// line end:   2723
void SetCamAngle__7CCamerasUs(struct CCamera *this, short y, unsigned short frames) {
}


// address: 0x8007BFB4
// line start: 2728
// line end:   2745
void SetCamXZDistance__7CCameraUsUs(struct CCamera *this, unsigned short dist, unsigned short frames) {
}


// address: 0x8007BFBC
// line start: 2750
// line end:   2767
void SetCamYDistance__7CCamerasUs(struct CCamera *this, short dist, unsigned short frames) {
}


// address: 0x8007BFC4
// line start: 2772
// line end:   2789
void SetCamXOffset__7CCamerasUs(struct CCamera *this, short offset, unsigned short frames) {
}


// address: 0x8007BFCC
// line start: 2794
// line end:   2813
void SetCamYOffset__7CCamerasUs(struct CCamera *this, short offset, unsigned short frames) {
}


// address: 0x8007BFD4
// line start: 2818
// line end:   2835
void SetCamZOffset__7CCamerasUs(struct CCamera *this, short offset, unsigned short frames) {
}


// address: 0x8007BFDC
// line start: 2838
// line end:   2847
void SetZoom__7CCameraUsUs(struct CCamera *this, unsigned short zoom, unsigned short time) {
}


// address: 0x8007C014
// line start: 2853
// line end:   2855
int GetZoom__7CCamera(struct CCamera *this) {
}


// address: 0x8007C020
// line start: 2890
// line end:   3004
void TweakMenu__7CCamera(struct CCamera *this) {
	// register: 18
	// size: 0xB8
	register struct CamPos *cp;
	{
		{
			{
				{
					{
						{
							{
								{
									{
										{
											{
												{
													{
														{
															{
																{
																	{
																		{
																			{
																				{
																					{
																						{
																							{
																								{
																									{
																										{
																											{
																												{
																													{
																														{
																															{
																																{
																																	{
																																		{
																																			{
																																				{
																																					{
																																						{
																																							{
																																								{
																																									{
																																										{
																																											{
																																												{
																																													{
																																														{
																																															{
																																																{
																																																	{
																																																		{
																																																			{
																																																				{
																																																					{
																																																						{
																																																							{
																																																								{
																																																									{
																																																										{
																																																											{
																																																												{
																																																												}
																																																											}
																																																										}
																																																									}
																																																								}
																																																							}
																																																						}
																																																					}
																																																				}
																																																			}
																																																		}
																																																	}
																																																}
																																															}
																																														}
																																													}
																																												}
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8007C6C4
// line start: 3012
// line end:   3594
void AI__7CCamera(struct CCamera *this) {
	// address: 0x000000D8
	static int Released;
	static int old_camYOffset;
	// address: 0x00000004
	static int old_camDist;
	// address: 0x00000008
	static int old_camPitch;
	// address: 0x000000DC
	static int Mick_DisplayCameraValues;
	// address: 0x000000E0
	static int old_GlobalZoom;
	// address: 0x000000E4
	static int Mick_Select_Triggered;
	// address: 0x000000E8
	static int Mick_Select_Released;
	{
		{
			// address: 0xFFFFFF30
			// size: 0x6
			auto struct CSVector oldamp;
			{
				{
					{
						{
							{
								{
									{
										{
											{
												{
													{
														{
															{
																{
																	{
																		{
																			{
																				{
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8007D138
// line start: 3678
// line end:   3906
void CM_Normal__7CCamera(struct CCamera *this) {
	// address: 0xFFFFFED8
	// size: 0xC
	auto struct CVector vUp;
	// address: 0xFFFFFEE8
	// size: 0xC
	auto struct CVector vRight;
	// address: 0xFFFFFEF8
	// size: 0x6
	auto struct CSVector ang1;
	// register: 20
	register int dot_up;
	// register: 18
	register int dot_front;
	// address: 0xFFFFFF00
	// size: 0xC
	auto struct CVector temp_vel;
	// address: 0xFFFFFF10
	// size: 0xC
	auto struct CVector Down;
	// address: 0xFFFFFF20
	// size: 0xC
	auto struct CVector Zero;
	// address: 0xFFFFFF30
	// size: 0xC
	auto struct CVector temp_front;
	// address: 0xFFFFFF40
	// size: 0xC
	auto struct CVector U;
	// address: 0xFFFFFF50
	// size: 0xC
	auto struct CVector V;
	// address: 0xFFFFFF70
	// size: 0xC
	auto struct CVector N;
	{
		{
			{
				{
					{
						{
							{
								{
									{
										{
											{
												{
													{
														{
															{
																{
																	{
																		{
																			{
																				{
																					{
																						{
																							{
																								{
																									{
																										{
																											{
																												{
																													{
																														{
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8007D708
// line start: 3949
// line end:   3952
void StartCompetitionIntro__7CCamera(struct CCamera *this) {
}


// address: 0x8007D730
// line start: 3956
// line end:   4077
void CM_CompetitionIntro__7CCamera(struct CCamera *this) {
	// address: 0xFFFFFF10
	// size: 0x14
	auto struct CQuat begin_o;
	// address: 0xFFFFFF28
	// size: 0x14
	auto struct CQuat end_o;
	// address: 0xFFFFFF40
	// size: 0xC
	auto struct CVector begin_pos;
	// address: 0xFFFFFF58
	// size: 0xC
	auto struct CVector offset_inc;
	// address: 0xFFFFFF68
	// size: 0xC
	auto struct CVector offset;
	// register: 4
	register int activated;
	{
		{
			// address: 0xFFFFFF10
			// size: 0x10
			auto struct VECTOR v1;
			// address: 0xFFFFFF20
			// size: 0x10
			auto struct VECTOR v2;
			// register: 2
			register int speed_lag_dist;
			// address: 0xFFFFFF30
			// size: 0x20
			auto struct MATRIX m;
			{
				// register: 16
				register int i;
				{
					// register: 17
					// size: 0x14
					register struct CQuat *this;
					{
						// register: 17
						// size: 0x4
						register struct CClass *this;
						{
							{
								{
									{
										{
											{
												{
													{
														{
															{
																{
																	{
																		{
																			{
																				{
																					{
																						{
																							{
																								{
																									{
																										{
																											{
																												{
																													{
																														{
																															{
																																{
																																	{
																																		{
																																			{
																																				{
																																					{
																																						{
																																							{
																																								{
																																									{
																																										{
																																											{
																																												{
																																													{
																																														{
																																															{
																																															}
																																														}
																																													}
																																												}
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8007DC78
// line start: 4080
// line end:   4086
bool InCompetitionIntro__7CCamera(struct CCamera *this) {
}


// address: 0x8007DC8C
// line start: 4090
// line end:   4218
void CM_NoBigAir__7CCamera(struct CCamera *this) {
	// address: 0xFFFFFEE0
	// size: 0xC
	auto struct CVector vUp;
	// address: 0xFFFFFEF0
	// size: 0xC
	auto struct CVector vRight;
	// address: 0xFFFFFF00
	// size: 0x6
	auto struct CSVector ang1;
	// register: 17
	register int dot_front;
	// address: 0xFFFFFF08
	// size: 0xC
	auto struct CVector temp_vel;
	// address: 0xFFFFFF18
	// size: 0xC
	auto struct CVector Down;
	// address: 0xFFFFFF28
	// size: 0xC
	auto struct CVector Zero;
	// address: 0xFFFFFF38
	// size: 0xC
	auto struct CVector temp_front;
	// address: 0xFFFFFF48
	// size: 0xC
	auto struct CVector U;
	// address: 0xFFFFFF68
	// size: 0xC
	auto struct CVector V;
	// address: 0xFFFFFF78
	// size: 0xC
	auto struct CVector N;
	{
		{
			{
				{
					{
						{
							{
								{
									{
										{
											{
												{
													{
														{
															{
																{
																	{
																		{
																			{
																				{
																					{
																						{
																							{
																								{
																									{
																										{
																											{
																												{
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8007E0E8
// size: 0xB8
// line start: 4903
// line end:   4904
struct CamPos *__6CamPos(struct CamPos *this) {
	// register: 2
	// size: 0x4
	register struct CClass *this;
	{
		{
			{
				// register: 4
				// size: 0x14
				register struct CQuat *this;
				{
					// register: 4
					// size: 0x4
					register struct CClass *this;
					{
						{
							{
								{
									// register: 3
									// size: 0x14
									register struct CQuat *this;
									{
										// register: 3
										// size: 0x4
										register struct CClass *this;
										{
											{
												{
													{
														{
															{
																// register: 4
																// size: 0x14
																register struct CQuat *this;
																{
																	// register: 4
																	// size: 0x4
																	register struct CClass *this;
																	{
																		{
																			{
																				{
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8007E148
// line start: 4920
// line end:   4922
void ___6CamPos(struct CamPos *this, int __in_chrg) {
	{
		{
			{
				{
					{
						{
							{
								{
									{
										// register: 4
										// size: 0x4
										register struct CClass *this;
										{
											{
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8007E18C
// line start: 5029
// line end:   5051
void Display__6CamPosUsUsUcUcUc(struct CamPos *this, unsigned short x, unsigned short y, unsigned char r, int g, int b) {
}


// address: 0x8007E3E8
// line start: 5055
// line end:   5067
void DisplayLabels__6CamPosUsUsUcUcUc(unsigned short x, unsigned short y, unsigned char r, unsigned char g, int b) {
}


// address: 0x8007E5EC
// line start: 5123
// line end:   5123
void _GLOBAL__D_camDist() {
	{
		{
			{
				{
					{
						{
							{
								{
									{
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8007E614
// line start: 5123
// line end:   5123
void _GLOBAL__I_camDist() {
	{
		{
			{
				{
					{
						{
							{
								{
									{
										{
											{
												{
													{
														{
															{
																{
																	{
																		{
																			{
																				{
																					{
																						{
																							{
																								{
																									{
																										{
																											{
																												{
																													{
																														{
																															{
																																{
																																	{
																																		{
																																			{
																																				{
																																					{
																																						{
																																							{
																																								{
																																									{
																																										{
																																											{
																																												{
																																													{
																																														{
																																															{
																																															}
																																														}
																																													}
																																												}
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8007E7E0
// line start: 141
// line end:   141
void ___t9AnimParam1Z5CQuat(struct t9AnimParam1Z5CQuat *this, int __in_chrg) {
	{
		{
			{
				// register: 4
				// size: 0x4
				register struct CClass *this;
				{
					{
					}
				}
			}
		}
	}
}


// address: 0x8007E81C
// line start: 132
// line end:   321
void ___5CQuat_addr_8007E81C(struct CQuat *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x8007E84C
// line start: 92
// line end:   92
void ___6CClass_addr_8007E84C(struct CClass *this, int __in_chrg) {
}


// address: 0x80081FF0
// line start: 44
// line end:   115
int MainMenu_Main__Fv() {
	// register: 19
	register unsigned int oldSkyColor;
	// register: 17
	// size: 0x14C
	register struct MainMenuScreen *pScreen;
	// address: 0xFFFFFFE0
	auto int return_value;
	// register: 18
	register int Finishing;
}


// address: 0x800821C0
// line start: 122
// line end:   127
void InitEndProcess__14MainMenuScreeni(struct MainMenuScreen *this, int return_value) {
}


// address: 0x800821FC
// line start: 134
// line end:   142
int EndProcess__14MainMenuScreen(struct MainMenuScreen *this) {
}


// address: 0x80082254
// size: 0x14C
// line start: 145
// line end:   192
struct MainMenuScreen *__14MainMenuScreen(struct MainMenuScreen *this) {
	// register: 2
	// size: 0x68
	register struct PromptScreenElement *pPromptElement;
}


// address: 0x800824EC
// line start: 199
// line end:   206
void ___14MainMenuScreen(struct MainMenuScreen *this, int __in_chrg) {
}


// address: 0x800825A0
// line start: 213
// line end:   216
void draw__14MainMenuScreen(struct MainMenuScreen *this) {
}


// address: 0x800825EC
// line start: 223
// line end:   228
void update__14MainMenuScreen(struct MainMenuScreen *this) {
}


// address: 0x8008260C
// line start: 259
// line end:   278
bool isDone__14MainMenuScreenPi(struct MainMenuScreen *this, int *return_value) {
}


// address: 0x800826B4
// size: 0x7C
// line start: 285
// line end:   296
struct WheelElementList *__16WheelElementListiiii(struct WheelElementList *this, int homeX, int homeY, int screenX, int screenY) {
	// register: 2
	// size: 0x28
	register struct SpriteScreenElement *item;
}


// address: 0x8008279C
// line start: 303
// line end:   305
void ___16WheelElementList(struct WheelElementList *this, int __in_chrg) {
}


// address: 0x8008281C
// line start: 315
// line end:   363
void update__16WheelElementList(struct WheelElementList *this) {
	// register: 3
	register int diff;
}


// address: 0x800829E8
// line start: 370
// line end:   373
void draw__16WheelElementListii(struct WheelElementList *this, int x, int y) {
}


// address: 0x80082A50
// line start: 1243
// line end:   1274
void EditorPieces_SetTheme__Fi(int theme) {
	{
	}
}


// address: 0x80082BE0
// line start: 1281
// line end:   1287
int MapPieceToIndex__Fii(int piece, int theme) {
	// register: 6
	register int i;
}


// address: 0x80082C30
// line start: 1294
// line end:   1297
int MapBasePieceToTheme__Fii(int piece, int theme) {
	// register: 2
	register int index;
}


// address: 0x80082C80
// line start: 1304
// line end:   1312
bool IsAFloorPiece__Fi(int piece) {
	{
		// register: 7
		register int i;
	}
}


// address: 0x80082CF0
// line start: 1321
// line end:   1332
int EditorPieces_TranslatePieceOut__Fi(int piece) {
	// register: 2
	register int index;
	// register: 4
	register int theme0_piece;
	{
		// register: 6
		register int i;
	}
}


// address: 0x80082D74
// line start: 1340
// line end:   1348
int EditorPieces_TranslatePieceIn__Fi(int save_index) {
	// register: 4
	register int theme0_piece;
	// register: 2
	register int index;
}


// address: 0x80082DDC
// line start: 1356
// line end:   1364
unsigned char EditorPieces_GetPieceFlags__Fi(int piece_number) {
	// register: 2
	register int index;
}


// address: 0x80082E4C
// line start: 1371
// line end:   1383
int GetPoolLink__Fiii(int piece, int side, int rot) {
	// register: 2
	register int index;
	// register: 7
	register int theme0_piece;
	// register: 6
	register int link_index;
	// register: 3
	register int the_side;
}


// address: 0x80082F10
// line start: 1390
// line end:   1394
bool ComparePoolLinks__Fii(int link1, int link2) {
}


// address: 0x80082F4C
// line start: 118
// line end:   128
void LevelEditor_Main__Fv() {
	// register: 16
	// size: 0x5C
	register struct LevelEditor *Ed;
}


// address: 0x80082FC8
// size: 0x5C
// line start: 135
// line end:   208
struct LevelEditor *__11LevelEditor(struct LevelEditor *this) {
	// register: 16
	// size: 0x4
	register struct CClass *this;
	{
		// address: 0xFFFFFFE0
		// size: 0xA
		auto char theme_name[10];
	}
}


// address: 0x800831D4
// line start: 215
// line end:   230
void ___11LevelEditor(struct LevelEditor *this, int __in_chrg) {
	// register: 16
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x800832E8
// line start: 237
// line end:   292
void Draw__11LevelEditor(struct LevelEditor *this) {
	// register: 17
	// size: 0xA4
	register struct SCamera *C;
}


// address: 0x8008342C
// line start: 303
// line end:   383
bool Update__11LevelEditor(struct LevelEditor *this) {
	// register: 2
	register int new_time;
	{
		{
			{
				{
					// address: 0xFFFFFFE8
					// size: 0xA
					auto char theme_name[10];
				}
			}
		}
	}
}


// address: 0x80083634
// line start: 390
// line end:   509
void HandleInput__11LevelEditor(struct LevelEditor *this) {
	// register: 5
	register int press;
}


// address: 0x80083A58
// line start: 585
// line end:   588
void CreateMenu__11LevelEditor(struct LevelEditor *this) {
}


// address: 0x80083A68
// line start: 610
// line end:   809
void UpdateMenu__11LevelEditor(struct LevelEditor *this) {
	{
		{
			{
				{
					// address: 0xFFFFFF60
					// size: 0x18
					auto char *names[6];
					// address: 0xFFFFFF78
					// size: 0x18
					auto int ids[6];
					{
						{
							// address: 0xFFFFFF60
							// size: 0x14
							auto char names[2][10];
							// address: 0xFFFFFF90
							// size: 0x28
							auto char *name_ptrs[10];
							// address: 0xFFFFFFB8
							// size: 0x28
							auto int ids[10];
							{
								// register: 17
								register int i;
								{
									{
										{
											// register: 2
											register int id;
											{
												{
													// address: 0xFFFFFF60
													// size: 0x14
													auto char names[2][10];
													// address: 0xFFFFFF78
													// size: 0x28
													auto char *name_ptrs[10];
													// address: 0xFFFFFFA0
													// size: 0x28
													auto int ids[10];
													{
														// register: 17
														register int i;
														{
															{
																{
																	// register: 2
																	register int id;
																	{
																		{
																			// address: 0xFFFFFF60
																			// size: 0xE
																			auto char load_name[14];
																			{
																				{
																					// address: 0xFFFFFF60
																					// size: 0x10
																					auto char *names[4];
																					// address: 0xFFFFFF70
																					// size: 0x10
																					auto int ids[4];
																					{
																						{
																							// address: 0xFFFFFF60
																							// size: 0xC
																							auto char *names[3];
																							// address: 0xFFFFFF70
																							// size: 0xC
																							auto int ids[3];
																							// address: 0xFFFFFF80
																							// size: 0x1E
																							auto char title[30];
																							{
																								{
																									{
																										// register: 3
																										register int id;
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80084144
// size: 0x628
// line start: 816
// line end:   888
struct SelectManager *__13SelectManager(struct SelectManager *this) {
	// register: 16
	// size: 0x4
	register struct CClass *this;
	{
		// register: 5
		register int i;
	}
}


// address: 0x800844CC
// line start: 896
// line end:   909
void ___13SelectManager(struct SelectManager *this, int __in_chrg) {
	// register: 18
	// size: 0x4
	register struct CClass *this;
	{
		{
			{
				// register: 17
				register int i;
			}
		}
	}
}


// address: 0x800845DC
// line start: 919
// line end:   962
void Draw__13SelectManager(struct SelectManager *this) {
	// register: 3
	// size: 0x18
	register struct POLY_F4 *Poly;
	// register: 16
	// size: 0xC
	register struct DR_MODE *dr;
	{
		// register: 18
		register int i;
	}
}


// address: 0x800848A4
// line start: 969
// line end:   994
void Update__13SelectManager(struct SelectManager *this) {
	// register: 19
	register int diffY;
	// register: 2
	register int change;
	{
		// register: 17
		register int i;
	}
}


// address: 0x800849D0
// line start: 1003
// line end:   1033
void SetPiece__13SelectManageri(struct SelectManager *this, int piece) {
}


// address: 0x80084BCC
// line start: 1039
// line end:   1049
void ChangePiece__13SelectManageri(struct SelectManager *this, int dir) {
	// register: 5
	register int piece;
	// register: 6
	register int diff;
}


// address: 0x80084C28
// line start: 1056
// line end:   1084
void SetCategory__13SelectManageri(struct SelectManager *this, int category) {
	// register: 7
	register int last_used_piece;
	{
		// register: 6
		register int i;
	}
}


// address: 0x80084DB8
// line start: 1090
// line end:   1096
void ChangeCategory__13SelectManageri(struct SelectManager *this, int dir) {
	// register: 5
	register int cat;
}


// address: 0x80084E08
// line start: 1103
// line end:   1123
void SetMenuState__13SelectManagerb(struct SelectManager *this, bool turn_on) {
	{
		{
			{
				// register: 6
				register int i;
				{
					{
						// register: 6
						register int i;
					}
				}
			}
		}
	}
}


// address: 0x80084EB8
// line start: 1131
// line end:   1132
int GetPieceIndex__13SelectManager(struct SelectManager *this) {
}


// address: 0x80084EF0
// line start: 1139
// line end:   1140
void SetTheme__13SelectManageri(struct SelectManager *this, int theme) {
}


// address: 0x80084EF8
// size: 0x2C
// line start: 1147
// line end:   1173
struct EditorCamera_duplicate_s2 *__12EditorCamera(struct EditorCamera_duplicate_s2 *this) {
	// register: 16
	// size: 0x4
	register struct CClass *this;
	{
		{
			{
				{
					{
						{
							// register: 3
							// size: 0x684
							register struct CCamera *this;
							{
								{
									// register: 4
									// size: 0x684
									register struct CCamera *this;
									// register: 5
									// size: 0x108
									register struct CBody_duplicate_s1 *focus;
									{
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80085028
// line start: 1180
// line end:   1184
void ___12EditorCamera(struct EditorCamera_duplicate_s2 *this, int __in_chrg) {
	// register: 16
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x800850E4
// line start: 1190
// line end:   1194
void SetTarget__12EditorCameraiii(struct EditorCamera_duplicate_s2 *this, int x, int y, int z) {
}


// address: 0x80085108
// line start: 1201
// line end:   1205
void SwitchType__12EditorCamera(struct EditorCamera_duplicate_s2 *this) {
	// register: 2
	register int type;
}


// address: 0x8008512C
// line start: 1212
// line end:   1216
void Rotate__12EditorCamera(struct EditorCamera_duplicate_s2 *this) {
}


// address: 0x80085154
// line start: 1224
// line end:   1281
void Update__12EditorCamera(struct EditorCamera_duplicate_s2 *this) {
	// register: 5
	register int wall;
	// register: 2
	register int diffx;
	// register: 3
	register int diffz;
	{
		{
			// register: 2
			register int start_sector;
			{
				// register: 2
				// size: 0x684
				register struct CCamera *this;
				{
					{
						// register: 3
						// size: 0x684
						register struct CCamera *this;
						// register: 4
						// size: 0x108
						register struct CBody_duplicate_s1 *focus;
						{
						}
					}
				}
			}
		}
	}
}


// address: 0x800853F4
// line start: 1288
// line end:   1299
int TranslatePress__12EditorCamerai(struct EditorCamera_duplicate_s2 *this, int press) {
}


// address: 0x80085448
// size: 0x6
// line start: 1306
// line end:   1341
struct SVector GetCameraTargetVector__12EditorCamera(struct EditorCamera_duplicate_s2 *this) {
	// address: 0xFFFFFFE8
	// size: 0xC
	auto struct Vector temp;
	// address: 0xFFFFFFF8
	// size: 0x6
	auto struct SVector vect;
}


// address: 0x80085604
// size: 0x14FC
// line start: 1359
// line end:   1378
struct Cursor *__6CursorR14LevelGenerator(struct Cursor *this, struct LevelGenerator *ed) {
	// register: 16
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x80085688
// line start: 1385
// line end:   1386
void ___6Cursor(struct Cursor *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x800856B8
// line start: 1392
// line end:   1502
bool SetPiece__6Cursori(struct Cursor *this, int piece) {
	// register: 12
	// size: 0x24
	register struct Item *pSourceItem;
	// register: 17
	register int min_x;
	// register: 13
	register int max_x;
	// register: 18
	register int min_y;
	// register: 14
	register int max_y;
	// register: 19
	register int min_z;
	// register: 15
	register int max_z;
	{
		// register: 20
		register int i;
		{
			// register: 11
			register int i;
		}
	}
}


// address: 0x80085BA0
// line start: 1509
// line end:   1536
void Rotate__6Cursori(struct Cursor *this, int dir) {
}


// address: 0x80085C70
// line start: 1543
// line end:   1559
bool Move__6Cursoriii(struct Cursor *this, int x, int y, int z) {
}


// address: 0x80085CEC
// line start: 1566
// line end:   1588
bool Move__6Cursori(struct Cursor *this, int dir) {
	// register: 8
	register int inc;
}


// address: 0x80085DD4
// line start: 1595
// line end:   1761
void SetPosition__6Cursor(struct Cursor *this) {
	static int last_x;
	// address: 0x00000004
	static int last_z;
	// register: 5
	register int rot_adjust;
	// register: 18
	register int lowest_slot;
	// register: 25
	register int last_model;
	{
		// register: 13
		register int j;
		{
			{
				// register: 5
				register int i;
				{
					// register: 3
					register int temp;
					{
						// register: 17
						register int i;
						// register: 13
						register int j;
						{
						}
					}
				}
			}
		}
	}
}


// address: 0x800864D0
// line start: 1768
// line end:   1821
void Update__6Cursor(struct Cursor *this) {
	{
		// register: 12
		register int i;
		{
		}
	}
}


// address: 0x8008673C
// line start: 1828
// line end:   1839
void Draw__6Cursor(struct Cursor *this) {
	// register: 17
	register bool is_pool_piece;
}


// address: 0x800867D4
// line start: 1849
// line end:   1973
bool Stamp__6Cursor(struct Cursor *this) {
	// register: 2
	register int num_faces;
	// register: 23
	register int cost;
	// register: 5
	register int slot;
	// register: 2
	register int top_slot;
	// register: 19
	register int this_slot;
	// register: 17
	register int link1;
	// register: 16
	// size: 0x80
	register struct EditorOutModel *mod;
	{
		// register: 12
		register int z;
		{
			{
				// register: 6
				register int x;
				{
					{
						{
							// register: 12
							register int z;
							{
								{
									// register: 5
									register int x;
									{
										{
											// register: 4
											register int s;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80086DCC
// line start: 1981
// line end:   2011
bool Remove__6Cursor(struct Cursor *this) {
	// address: 0xFFFFFFE0
	auto int lowest_removal_slot;
	// register: 19
	register bool successful_remove;
	{
		// register: 18
		register int cursor_z;
		{
			{
				// register: 16
				register int cursor_x;
				{
					// address: 0xFFFFFFE4
					// size: 0x44
					auto struct EditorInModel *in_model;
					// register: 6
					register bool result;
					// register: 3
					register int source_index;
					// register: 5
					register int num_faces;
					// register: 3
					register int cost;
				}
			}
		}
	}
}


// address: 0x80086F10
// line start: 2021
// line end:   2071
void WireframeCollidingPieces__6Cursorb(struct Cursor *this, bool wireframe_on) {
	// register: 30
	register int ztop;
	// register: 9
	register int zbottom;
	// register: 22
	register int xleft;
	// register: 23
	register int xright;
	// register: 6
	register int highest_slot;
	{
		// register: 8
		register int z;
		{
			{
				// register: 5
				register int x;
				{
					// register: 21
					register int slot;
					// register: 8
					register int z;
					{
						{
							// register: 19
							register int z;
							{
								{
									// register: 17
									register int x;
									{
										// register: 16
										// size: 0x80
										register struct EditorOutModel *das_model;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x800871AC
// line start: 2114
// line end:   2203
void PushbackPieces__6Cursorb(struct Cursor *this, bool draw_back) {
	// register: 18
	register int last_blocked;
	{
		// register: 17
		register int i;
		{
			// register: 5
			// size: 0x80
			register struct EditorOutModel *model;
			// register: 6
			register bool behind;
			{
				// register: 7
				register int i;
				{
					// register: 4
					// size: 0x80
					register struct EditorOutModel *model;
					// register: 3
					register bool draw_it;
				}
			}
		}
	}
}


// address: 0x80087390
// line start: 2215
// line end:   2246
void AddSortModel__6CursorP14EditorOutModel(struct Cursor *this, struct EditorOutModel *new_model) {
	// register: 3
	// size: 0x80
	register struct EditorOutModel *temp;
	// register: 9
	register int i;
	{
		{
			// register: 7
			register bool behind;
		}
	}
}


// address: 0x800874D8
// line start: 2253
// line end:   2277
void SortModels__6Cursor(struct Cursor *this) {
	{
		// register: 17
		register int list;
		{
			// register: 16
			// size: 0x80
			register struct EditorOutModel *model;
		}
	}
}


// address: 0x800875A8
// line start: 2284
// line end:   2285
void SetCameraTargetVector__6CursorG7SVector(struct Cursor *this, struct SVector camera) {
}


// address: 0x800875D0
// line start: 92
// line end:   92
void ___6CClass_addr_800875D0(struct CClass *this, int __in_chrg) {
}


// address: 0x8007FC88
// line start: 61
// line end:   118
int LevelSelect2_Main__Fv() {
	// register: 18
	register unsigned int oldSkyColor;
	// register: 17
	// size: 0x11C
	register struct LevelSelectScreen *pScreen;
	// address: 0xFFFFFFD8
	auto int return_value;
}


// address: 0x8007FE74
// size: 0x11C
// line start: 124
// line end:   199
struct LevelSelectScreen *__17LevelSelectScreen(struct LevelSelectScreen *this) {
	// address: 0xFFFFFFD8
	// size: 0xC
	auto struct PromptScreenElement *pPromptElement[3];
	{
		// register: 17
		register int i;
		{
			{
				// register: 2
				// size: 0x24
				register struct ScreenElement *item;
				{
					{
						// register: 2
						// size: 0xC0
						register struct SkaterNameScreenElement *item2;
						{
							{
								{
									// register: 2
									// size: 0xC0
									register struct SkaterNameScreenElement *item2;
									{
										// register: 2
										// size: 0xC0
										register struct SkaterNameScreenElement *item2;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x800802DC
// line start: 210
// line end:   211
void ___17LevelSelectScreen(struct LevelSelectScreen *this, int __in_chrg) {
}


// address: 0x8008036C
// line start: 219
// line end:   237
void draw__17LevelSelectScreen(struct LevelSelectScreen *this) {
}


// address: 0x800803B8
// line start: 245
// line end:   274
void update__17LevelSelectScreen(struct LevelSelectScreen *this) {
}


// address: 0x800804EC
// line start: 281
// line end:   282
void refresh__17LevelSelectScreen(struct LevelSelectScreen *this) {
}


// address: 0x800804F4
// line start: 287
// line end:   321
bool isDone__17LevelSelectScreenPi(struct LevelSelectScreen *this, int *return_value) {
}


// address: 0x800805E0
// size: 0xC0
// line start: 328
// line end:   360
struct SkaterNameScreenElement *__23SkaterNameScreenElementbiiii(struct SkaterNameScreenElement *this, bool secondPlayer, int homeX, int homeY, int screenX, int screenY) {
	{
		{
			// register: 2
			// size: 0x28
			register struct SpriteScreenElement *pElement;
		}
	}
}


// address: 0x800808D8
// line start: 367
// line end:   367
void ___23SkaterNameScreenElement(struct SkaterNameScreenElement *this, int __in_chrg) {
}


// address: 0x8008093C
// size: 0x60
// line start: 374
// line end:   414
struct GlobeScreenElement *__18GlobeScreenElementiiii(struct GlobeScreenElement *this, int homeX, int homeY, int screenX, int screenY) {
	// register: 2
	// size: 0x24
	register struct Item *pItemList;
}


// address: 0x80080AB0
// line start: 421
// line end:   425
void ___18GlobeScreenElement(struct GlobeScreenElement *this, int __in_chrg) {
}


// address: 0x80080B58
// line start: 432
// line end:   468
void update__18GlobeScreenElement(struct GlobeScreenElement *this) {
	// register: 5
	register int diff;
}


// address: 0x80080C54
// line start: 475
// line end:   486
void draw__18GlobeScreenElementii(struct GlobeScreenElement *this, int x, int y) {
}


// address: 0x80080D2C
// line start: 493
// line end:   495
void SetLevel__18GlobeScreenElementi(struct GlobeScreenElement *this, int level) {
}


// address: 0x80080D64
// size: 0x124
// line start: 576
// line end:   602
struct LevelNameScreenElement *__22LevelNameScreenElementiiii(struct LevelNameScreenElement *this, int homeX, int homeY, int screenX, int screenY) {
}


// address: 0x80080F88
// line start: 609
// line end:   609
void ___22LevelNameScreenElement(struct LevelNameScreenElement *this, int __in_chrg) {
}


// address: 0x80080FF8
// line start: 616
// line end:   620
void SetLevel__22LevelNameScreenElementi(struct LevelNameScreenElement *this, int level) {
}


// address: 0x80081020
// line start: 627
// line end:   645
void update__22LevelNameScreenElement(struct LevelNameScreenElement *this) {
}


// address: 0x80081174
// size: 0x2C
// line start: 653
// line end:   654
struct NameScreenElement *__17NameScreenElementPcP4Fontiiii(struct NameScreenElement *this, char *pString, struct Font_duplicate_s0 *pFont, int homeX, int homeY, int screenX, int screenY) {
}


// address: 0x800811C0
// line start: 661
// line end:   661
void ___17NameScreenElement(struct NameScreenElement *this, int __in_chrg) {
}


// address: 0x80081214
// line start: 668
// line end:   706
void update__17NameScreenElement(struct NameScreenElement *this) {
	// register: 3
	register int distX;
	// register: 3
	register int distY;
	{
		{
			// register: 2
			register int add;
			{
				{
					// register: 2
					register int add;
				}
			}
		}
	}
}


// address: 0x800812C4
// size: 0x9C
// line start: 720
// line end:   748
struct VideoScreenElement *__18VideoScreenElementiiii(struct VideoScreenElement *this, int homeX, int homeY, int screenX, int screenY) {
	// register: 2
	// size: 0x28
	register struct SpriteScreenElement *item;
}


// address: 0x80081548
// line start: 755
// line end:   761
void ___18VideoScreenElement(struct VideoScreenElement *this, int __in_chrg) {
}


// address: 0x80081604
// line start: 768
// line end:   795
void draw__18VideoScreenElementii(struct VideoScreenElement *this, int x, int y) {
	// register: 17
	register int video_x;
	// register: 18
	register int video_y;
	{
		{
			// address: 0xFFFFFFE0
			// size: 0x8
			auto struct RECT r;
		}
	}
}


// address: 0x80081804
// line start: 802
// line end:   857
void update__18VideoScreenElement(struct VideoScreenElement *this) {
}


// address: 0x80081998
// line start: 864
// line end:   865
void SetLevel__18VideoScreenElementi(struct VideoScreenElement *this, int level) {
}


// address: 0x800819A0
// size: 0xCC
// line start: 918
// line end:   970
struct GoalScreenElement *__17GoalScreenElementiiii(struct GoalScreenElement *this, int homeX, int homeY, int screenX, int screenY) {
	// register: 17
	register unsigned char *bmpBuf;
	// address: 0xFFFFFFB0
	// size: 0x20
	auto int order[8];
	// address: 0xFFFFFFD0
	// size: 0x10
	auto char name[16];
	{
		// register: 18
		register int i;
		{
			// register: 20
			register int i;
			{
				// register: 16
				register int num;
			}
		}
	}
}


// address: 0x80081BB4
// line start: 977
// line end:   982
void ___17GoalScreenElement(struct GoalScreenElement *this, int __in_chrg) {
	{
		// register: 17
		register int i;
	}
}


// address: 0x80081C6C
// line start: 989
// line end:   1053
void update__17GoalScreenElement(struct GoalScreenElement *this) {
	{
		// register: 20
		register int i;
		{
			{
				{
					// register: 16
					register unsigned char *theData;
					{
						{
							{
								// register: 4
								register int scale_offs;
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80081EC8
// line start: 1060
// line end:   1065
void draw__17GoalScreenElementii(struct GoalScreenElement *this, int x, int y) {
}


// address: 0x80081FCC
// line start: 1072
// line end:   1077
void SetLevel__17GoalScreenElementii(struct GoalScreenElement *this, int level, int dir) {
}


// address: 0x8008EED8
// line start: 93
// line end:   612
void M3dElips_RenderShadow__FP6SModelP6MATRIXP8CSVectorP7CVectorP7SVECTORG7CVECTOR(struct SModel *pModel, struct MATRIX *pTransform, struct CSVector *pNormal, struct CVector *pPoint, struct SVECTOR *pLightVec, struct CVECTOR rgb) {
	// register: 23
	register short a;
	// register: 22
	register short b;
	// register: 21
	register short c;
	// register: 20
	register short d;
	// register: 17
	register short Mag_d_m;
	// register: 2
	register int d12;
	// register: 16
	register int k;
	// address: 0xFFFFFFD0
	auto int n_dot_l;
	// address: 0xFFFFFF08
	// size: 0x12
	auto short R[3][3];
	// address: 0xFFFFFF20
	// size: 0x12
	auto short RT[3][3];
	// address: 0xFFFFFF38
	// size: 0x12
	auto short d_Ainv[3][3];
	// address: 0xFFFFFF50
	// size: 0x12
	auto short M[3][3];
	// address: 0xFFFFFF68
	// size: 0x6
	auto struct Vec t;
	// address: 0xFFFFFF70
	// size: 0x6
	auto struct Vec v;
	// address: 0xFFFFFF78
	// size: 0x6
	auto struct Vec d_m;
	// address: 0xFFFFFF80
	// size: 0x6
	auto struct Vec Scaled_q;
	// address: 0xFFFFFF88
	// size: 0x6
	auto struct Vec e;
	// address: 0xFFFFFF90
	// size: 0x6
	auto struct Vec f;
	// address: 0xFFFFFF98
	// size: 0x6
	auto struct Vec DotProds;
	// address: 0xFFFFFFA0
	// size: 0x6
	auto struct Vec Centre;
	// address: 0xFFFFFFA8
	// size: 0x6
	auto struct Vec e_Proj;
	// address: 0xFFFFFFB0
	// size: 0x6
	auto struct Vec f_Proj;
	// address: 0xFFFFFFB8
	// size: 0x6
	auto struct Vec Vertex;
	// address: 0xFFFFFFC0
	// size: 0xC
	auto struct CVector d_m_Squared;
	// register: 8
	// size: 0x28
	register struct POLY_FT4 *pQuad;
	// address: 0xFFFFFFD4
	auto unsigned int OTPos;
	// register: 18
	register int t1;
	// register: 16
	register int t2;
	// register: 17
	register int t3;
	{
		{
			{
				// register: 4
				register unsigned int t0;
				// register: 3
				register unsigned int t1;
				// register: 5
				register unsigned int t2;
				// register: 6
				register unsigned int t3;
			}
		}
	}
}


// address: 0x8008F82C
// line start: 620
// line end:   825
void M3dElips_RenderEllipsoid__FP6SModelP6MATRIXUiiiP7Texture(struct SModel *pModel, struct MATRIX *pTransform, unsigned int Rgb, int Scale, int OTPushback, struct Texture *pTex) {
	// register: 30
	register short a;
	// register: 22
	register short b;
	// register: 23
	register short c;
	// register: 21
	register short d;
	// register: 17
	register short Mag_d_m;
	// register: 2
	register int d12;
	// register: 16
	register int k;
	// address: 0xFFFFFF30
	// size: 0x12
	auto short R[3][3];
	// address: 0xFFFFFF48
	// size: 0x12
	auto short RT[3][3];
	// address: 0xFFFFFF60
	// size: 0x12
	auto short d_Ainv[3][3];
	// address: 0xFFFFFF78
	// size: 0x6
	auto struct Vec l;
	// address: 0xFFFFFF80
	// size: 0x6
	auto struct Vec t;
	// address: 0xFFFFFF88
	// size: 0x6
	auto struct Vec v;
	// address: 0xFFFFFF90
	// size: 0x6
	auto struct Vec d_m;
	// address: 0xFFFFFF98
	// size: 0x6
	auto struct Vec Scaled_q;
	// address: 0xFFFFFFA0
	// size: 0x6
	auto struct Vec e;
	// address: 0xFFFFFFA8
	// size: 0x6
	auto struct Vec f;
	// address: 0xFFFFFFB0
	// size: 0x6
	auto struct Vec Vertex;
	// address: 0xFFFFFFB8
	// size: 0x6
	auto struct Vec Centre;
	// address: 0xFFFFFFC0
	// size: 0xC
	auto struct CVector d_m_Squared;
	// register: 8
	// size: 0x28
	register struct POLY_FT4 *pQuad;
	// address: 0xFFFFFFD0
	auto unsigned int OTPos;
	{
		{
		}
	}
}


// address: 0x8008FFC0
// line start: 45
// line end:   57
void NextInquiry__Fv() {
	{
		{
			// register: 3
			// size: 0x24
			register struct Item *pItem;
		}
	}
}


// address: 0x80090034
// line start: 75
// line end:   325
void M3dColij_InitLineInfo__FP9SLineInfo(struct SLineInfo *pInfo) {
	// register: 2
	register short *pShort;
	// address: 0xFFFFFFC8
	// size: 0x8
	auto struct SVECTOR L;
	// address: 0xFFFFFFD0
	// size: 0x8
	auto struct SVECTOR AbsL;
	// register: 5
	// size: 0xC
	register struct Vector *p1;
	// address: 0xFFFFFFD8
	auto int lzc;
	// register: 18
	register int Shift1;
	// register: 16
	register int Shift2;
	// register: 16
	register int s1;
	// register: 5
	register int s2;
	// register: 17
	register int r1Norm;
	// register: 2
	register int r2Norm;
	// register: 6
	register short Sin;
}


// address: 0x800903B0
// line start: 333
// line end:   351
void M3dColij_LineToItem__FP4ItemP9SLineInfo(struct Item *pItem, struct SLineInfo *pInfo) {
}


// address: 0x8009045C
// line start: 432
// line end:   440
void M3dColij_FlushCache__Fv() {
	{
		// register: 5
		register int i;
	}
}


// address: 0x80090498
// line start: 460
// line end:   979
void M3dColij_LineToThisItemCached__FP4ItemP9SLineInfoP9SColCache(struct Item *pItem, struct SLineInfo *pInfo, struct SColCache *pColCache) {
	// address: 0xFFFFFE40
	// size: 0x10
	auto struct VECTOR PosnRelStart;
	// register: 8
	// size: 0x24
	register struct SModel *pModel;
	// address: 0xFFFFFE50
	auto int XMin;
	// address: 0xFFFFFE54
	auto int YMin;
	// address: 0xFFFFFE58
	auto int ZMin;
	// address: 0xFFFFFE5C
	auto int XMax;
	// address: 0xFFFFFE60
	auto int YMax;
	// address: 0xFFFFFE64
	auto int ZMax;
	// register: 3
	// size: 0x1C
	register struct SFaceCache *pFaceCache;
	// address: 0xFFFFFE68
	auto int Faces;
	// register: 2
	register int NumNormals;
	// address: 0xFFFFFE6C
	// size: 0x8
	auto struct SVECTOR *pVerts;
	// address: 0xFFFFFE70
	// size: 0x8
	auto struct SVECTOR *Normals;
	// address: 0xFFFFFE74
	auto unsigned int *pFace;
	// address: 0xFFFFFE78
	auto int tNear;
	// address: 0xFFFFFE7C
	auto int CollidedTriggerModel;
	{
		// address: 0xFFFFFE80
		auto int i;
		{
			{
				{
					// register: 4
					register unsigned short FaceFlags;
					// register: 8
					register unsigned char *pVertexIndex;
					// register: 10
					register int Nx;
					// register: 11
					register int Ny;
					// register: 6
					register int Nz;
					// register: 25
					register int x0;
					// register: 24
					register int y0;
					// register: 19
					register int z0;
					// register: 18
					register int L0x;
					// register: 17
					register int L0y;
					// address: 0xFFFFFFD0
					auto int L0z;
					// register: 9
					register int L1x;
					// register: 22
					register int L1y;
					// register: 23
					register int L1z;
					// address: 0xFFFFFE84
					auto int LineLen;
					// address: 0xFFFFFE88
					auto int s0;
					// address: 0xFFFFFE8C
					auto int s1;
					// register: 5
					register int x1;
					// register: 4
					register int y1;
					// register: 11
					register int z1;
					// register: 12
					register int x2;
					// register: 13
					register int y2;
					// register: 3
					register int z2;
					// address: 0xFFFFFE90
					auto int x3;
					// address: 0xFFFFFE94
					auto int y3;
					// address: 0xFFFFFE98
					auto int z3;
					// address: 0xFFFFFEA0
					auto bool Dx;
					// address: 0xFFFFFEA8
					auto bool Dy;
					// address: 0xFFFFFEB0
					auto bool Dz;
					// register: 8
					register int V0x;
					// register: 9
					register int V0y;
					// register: 6
					register int V0z;
					// register: 7
					register int V1x;
					// register: 30
					register int V1y;
					// register: 16
					register int V1z;
					// address: 0xFFFFFEB8
					auto int V2x;
					// address: 0xFFFFFEBC
					auto int V2y;
					// address: 0xFFFFFEC0
					auto int V2z;
					// register: 22
					register int V3x;
					// register: 23
					register int V3y;
					// address: 0xFFFFFFD0
					auto int V3z;
					// address: 0xFFFFFEC8
					auto bool S0;
					// register: 24
					register bool S1;
					// register: 10
					register bool S2;
					// register: 4
					register bool S3;
					// address: 0xFFFFFED0
					auto int contained;
					{
						{
							// register: 6
							register int Qx;
							// register: 3
							register int Qy;
							// register: 5
							register int Qz;
							// register: 22
							register int t;
							// register: 6
							register int xd;
							// register: 18
							register int yd;
							// register: 23
							register int zd;
							// register: 17
							register int sxd;
							// register: 16
							register int syd;
							// register: 19
							register int szd;
							// register: 17
							register int xd1;
							// register: 16
							register int yd1;
							// register: 2
							register int zd1;
							{
								{
									// register: 2
									register int i;
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x800918AC
// line start: 1477
// line end:   1516
bool FitFacesAtCacheEnd__Fi(int faces) {
}


// address: 0x8009192C
// line start: 1521
// line end:   1542
void RemoveFacesFromCache__Fv() {
}


// address: 0x800919A0
// line start: 1547
// line end:   1867
void M3dColij_LineToItemZoned__FPP4ItemP9SLineInfo(struct Item **ppItem, struct SLineInfo *pInfo) {
	{
		{
			{
				{
					// register: 18
					// size: 0x24
					register struct Item *pItem;
					// register: 6
					register int i;
					{
						{
							// register: 16
							// size: 0x24
							register struct SModel *pModel;
							// register: 17
							register int Faces;
							// address: 0xFFFFFFC8
							auto int ItemX;
							// register: 30
							register int ItemY;
							// address: 0xFFFFFFD0
							auto int ItemZ;
							// address: 0xFFFFFFCC
							auto int NumFaces;
							// register: 2
							register int NumNormals;
							// register: 4
							// size: 0x8
							register struct SVECTOR *Normals;
							// register: 19
							// size: 0x8
							register struct SVECTOR *pVertices;
							// register: 17
							register unsigned int *pFaceX;
							// register: 20
							// size: 0x1C
							register struct SFaceCache *pFaceCache;
							{
								// register: 22
								register int i;
								{
									// register: 24
									register unsigned char *pVertexIndex;
									// register: 25
									register int z0;
									// register: 8
									register int xmin;
									// register: 7
									register int ymin;
									// register: 10
									register int zmin;
									// register: 11
									register int xmax;
									// register: 12
									register int ymax;
									// register: 9
									register int zmax;
									// register: 6
									register int x1;
									// register: 13
									register int y1;
									// register: 15
									register int z1;
									// register: 5
									register int x2;
									// register: 14
									register int y2;
									// register: 3
									register int z2;
									// register: 4
									register int x3;
									// register: 5
									register int y3;
									// register: 6
									register int z3;
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80091E58
// line start: 1890
// line end:   1952
int M3dColij_GetLineInfo__FP9SLineInfo(struct SLineInfo *pInfo) {
}


// address: 0x80091F0C
// line start: 1959
// line end:   2065
void M3dColij_LineToThisItem__FP4ItemP9SLineInfo(struct Item *pItem, struct SLineInfo *pInfo) {
	// address: 0xFFFFFFD8
	// size: 0x10
	auto struct VECTOR PosnRelStart;
	// register: 20
	// size: 0x24
	register struct SModel *pModel;
	// register: 19
	// size: 0x8
	register struct SProjectedVertex *pVertices;
	{
		{
			// register: 2
			register int i;
		}
	}
}


// address: 0x800922B4
// size: 0x108
// line start: 2086
// line end:   2214
struct CBody_duplicate_s1 *M3dColij_LineToSphere__FRC7CVectorT0R7CVectorP5CBodyT3i(struct CVector *OldPos, struct CVector *NewPos, struct CVector *ColijPos, struct CBody_duplicate_s1 *pBody, struct CBody_duplicate_s1 *pIgnore, int ScaleFactor) {
	// register: 5
	register int Radius;
	// register: 5
	register int RadiusSquared;
	// address: 0xFFFFFFC8
	auto int Length;
	// address: 0xFFFFFFCC
	auto int DotProd;
	// address: 0xFFFFFF28
	// size: 0xC
	auto struct CVector DirectionVec;
	// address: 0xFFFFFF38
	// size: 0xC
	auto struct CVector MinCoords;
	// address: 0xFFFFFF48
	// size: 0xC
	auto struct CVector MaxCoords;
	// address: 0xFFFFFF58
	// size: 0xC
	auto struct CVector SquareVec;
	// address: 0xFFFFFF68
	// size: 0x10
	auto struct VECTOR OldToCentre;
	// address: 0xFFFFFF78
	// size: 0x10
	auto struct VECTOR NewToCentre;
	// address: 0xFFFFFF88
	// size: 0x8
	auto struct SVECTOR DirVecShort;
	{
		{
			{
				{
					{
						{
							{
								{
									{
										// register: 2
										register int _x;
										// register: 3
										register int _y;
										// register: 4
										register int _z;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x800927E4
// line start: 2215
// line end:   2215
void _GLOBAL__I_NearestHit() {
	{
		{
			{
				{
					{
					}
				}
			}
		}
	}
}


// address: 0x800927EC
// line start: 53
// line end:   60
void M3dUtils_ReadHooksPacket__FP6CSuperPv(struct CSuper *pSuper, void *pPacket) {
	// register: 5
	register unsigned short *pData;
}


// address: 0x8009280C
// line start: 133
// line end:   193
void M3dUtils_GetHookPosition__FP6VECTORP6CSuperi(struct VECTOR *pResult, struct CSuper *pSuper, int Hook) {
	// register: 5
	// size: 0x18
	register struct SMatrix *pAnimTransform;
	// register: 5
	register int Anim;
	// register: 16
	register int Part;
	// register: 6
	register unsigned int *pAnimFile;
	// register: 19
	// size: 0x8
	register struct SHook *pHook;
}


// address: 0x800929F8
// line start: 200
// line end:   243
void M3dUtils_GetDynamicHookPosition__FP6VECTORP6CSuperP5SHook(struct VECTOR *pResult, struct CSuper *pSuper, struct SHook *pHook) {
	// register: 5
	// size: 0x18
	register struct SMatrix *pAnimTransform;
	// register: 2
	register int Anim;
	// register: 16
	register int Part;
	// register: 6
	register unsigned int *pAnimFile;
}


// address: 0x80092B60
// line start: 298
// line end:   313
void M3dUtils_InBetween__FP6CSuper(struct CSuper *pSuper) {
	// register: 6
	register unsigned int *pAnimFile;
	// register: 4
	register int NumParts;
	// register: 5
	register int Interval;
}


// address: 0x80092BC8
// line start: 317
// line end:   410
void M3dUtils_InterpolateVectors__FiiPUiP4Itemii(int NumVectors, int Interval, unsigned int *pAnimFile, struct Item *pItem, int Part, int NumParts) {
	// address: 0xFFFFFFE8
	// size: 0x6
	auto struct CSVector dAnim;
	// register: 6
	// size: 0x18
	register struct SMatrix *pAnims;
	// register: 10
	register int Alpha;
	// register: 8
	register int Frame0;
	// register: 9
	register int Frame1;
	// register: 10
	register int Frame;
	// register: 11
	register int NumFrames;
	// register: 11
	register int i;
	// register: 2
	register int Anim;
	// register: 24
	// size: 0x6
	register struct CSVector *pTween;
	// register: 14
	// size: 0x6
	register struct CSVector *pAnim0;
	{
		{
			{
				{
					// register: 15
					// size: 0x6
					register struct CSVector *pAnim1;
					{
						{
							// register: 7
							register int p0x;
							// register: 5
							register int p0y;
							// register: 6
							register int p0z;
							// register: 4
							register int dx;
							// register: 2
							register int dy;
							// register: 3
							register int dz;
						}
					}
				}
			}
		}
	}
}


// address: 0x80092DE4
// line start: 598
// line end:   612
void M3dUtils_AnglesFromMatrix__FP7SVECTORP6MATRIX(struct SVECTOR *pAngles, struct MATRIX *pMatrix) {
	// register: 18
	register int r02;
	// register: 20
	register int r10;
	// register: 21
	register int r11;
	// register: 16
	register int r12;
	// register: 17
	register int r22;
}


// address: 0x80092E90
// line start: 691
// line end:   847
int M3dUtils_LineLineClosestPoints__FP7CVectorN40PiT0T5(struct CVector *L1Start, struct CVector *L1End, struct CVector *L2Start, struct CVector *L2End, struct CVector *PointL1, int *t1, struct CVector *PointL2, int *t2) {
	// address: 0xFFFFFED8
	// size: 0xC
	auto struct CVector DL1;
	// address: 0xFFFFFEE8
	// size: 0xC
	auto struct CVector DL2;
	// address: 0xFFFFFEF8
	// size: 0xC
	auto struct CVector DStart;
	// address: 0xFFFFFF08
	// size: 0xC
	auto struct CVector L1StartInt;
	// address: 0xFFFFFF18
	// size: 0xC
	auto struct CVector L2StartInt;
	// address: 0xFFFFFF28
	// size: 0xC
	auto struct CVector V;
	// address: 0xFFFFFF38
	// size: 0xC
	auto struct CVector SquaredVec;
	// address: 0xFFFFFF48
	// size: 0xC
	auto struct CVector CrossProd;
	// address: 0xFFFFFF58
	// size: 0xC
	auto struct CVector ApproachVec;
	// address: 0xFFFFFF68
	// size: 0x8
	auto struct SVECTOR VShifted;
	// address: 0xFFFFFFC0
	auto int Numerator;
	// register: 5
	register int Denominator;
	// address: 0xFFFFFFB8
	auto int Shift;
	// register: 16
	register int ExtraShift;
	{
		{
			{
				{
					{
						{
							{
								{
									{
										{
											{
												{
													{
														{
															{
																{
																	{
																		{
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8009363C
// line start: 855
// line end:   877
void M3dUtils_NormaliseVector__FP7CVector(struct CVector *pV) {
	// address: 0xFFFFFFE0
	// size: 0xC
	auto struct CVector VSqd;
	// register: 6
	register int Magnitude;
	{
		{
		}
	}
}


// address: 0x8009376C
// line start: 47
// line end:   72
void M3dInit_InitAtStart__Fv() {
	// register: 7
	register int Amp;
	// register: 5
	register int Angle;
	// register: 6
	register short *pHalfword;
}


// address: 0x80093818
// line start: 91
// line end:   108
void M3dInit_SetResolution__FUiUi(unsigned int X, unsigned int Y) {
}


// address: 0x8009388C
// line start: 129
// line end:   174
void M3dInit_SetFoggingParams__FiiUi(int Dummy, int Min, unsigned int Range) {
}


// address: 0x8009392C
// line start: 202
// line end:   464
void M3dInit_ParsePSX__Fi(int Region) {
	// register: 11
	// size: 0x24
	register struct SModel *pModel;
	// register: 6
	// size: 0x24
	register struct Item *pItem;
	// register: 5
	register unsigned int *pFace;
	// register: 20
	register unsigned int Fastable;
	// register: 14
	register int i;
	// register: 10
	register int j;
	// register: 18
	register int NumModels;
	// register: 17
	register int NumParts;
	// register: 11
	register int NumItems;
	// register: 9
	register int NumVertices;
	// register: 13
	register int NumNormals;
	// register: 25
	register int NumFaces;
	// register: 16
	register int NumStitchVertices;
	// register: 3
	// size: 0x28
	register struct Texture *pTex;
	// register: 7
	// size: 0x8
	register struct SVECTOR *pVertex;
	// register: 6
	// size: 0x8
	register struct SVECTOR *pNormal;
	// register: 12
	register unsigned short clut;
	// register: 13
	register unsigned short tpage;
	// register: 6
	register unsigned short u0v0;
	// register: 7
	register unsigned short u1v1;
	// register: 9
	register unsigned short u2v2;
	// register: 8
	register unsigned short u3v3;
	// register: 15
	register unsigned int OrOfFlags;
	// register: 24
	register unsigned int AndOfFUFlags;
}


// address: 0x80093E6C
// line start: 473
// line end:   498
void M3dInit_FlagZeroWibbles__FP15STexWibItemInfo(struct STexWibItemInfo *pTexWibItemInfo) {
	{
		// register: 7
		register int NumFaces;
		// register: 5
		// size: 0x4
		register struct STexWibVertInfo *pTexWibVertInfo;
		{
			// register: 6
			register int i;
		}
	}
}


// address: 0x80093FA8
// line start: 40
// line end:   46
void M3dZone_FreePSX__Fi(int EnvIndex) {
	{
		{
			{
				// register: 7
				register int i;
				{
					{
						// register: 4
						register int j;
					}
				}
			}
		}
	}
}


// address: 0x80094018
// line start: 76
// line end:   77
void M3dZone_Init__Fv() {
}


// address: 0x80094038
// line start: 95
// line end:   98
int M3dZone_LineToItem__FP9SLineInfoi(struct SLineInfo *pInfo, int CheckEnviroObs) {
	// register: 16
	register unsigned int sp;
}


// address: 0x80094090
// line start: 104
// line end:   284
int M3dZone_LineToItemNotSCached__FP9SLineInfoi(struct SLineInfo *pInfo, int CheckEnviroObs) {
	// register: 21
	register int x0;
	// register: 18
	register int x1;
	// register: 19
	register int z0;
	// register: 20
	register int z1;
	// address: 0xFFFFFFA0
	auto int xL;
	// register: 22
	register int xH;
	// register: 30
	register int zL;
	// address: 0xFFFFFFA4
	auto int zH;
	// register: 17
	register int X0;
	// address: 0xFFFFFFA8
	auto int X1;
	// register: 22
	register int Z0;
	// address: 0xFFFFFFAC
	auto int Z1;
	// register: 16
	register int r0;
	// register: 5
	register int s0;
	// register: 16
	register int X;
	// register: 17
	register int Z;
	// address: 0xFFFFFFB0
	auto int dX;
	// address: 0xFFFFFFB4
	auto int dZ;
	// register: 7
	register int w;
	// register: 30
	register int h;
	// register: 23
	register int l;
	// register: 18
	register int d;
	// register: 4
	register int qh;
	// register: 23
	register int qw;
	{
		// address: 0xFFFFFFB8
		auto int EnvIndex;
	}
}


// address: 0x800948DC
// line start: 354
// line end:   396
void M3dZone_SetZone__FiPUi(int EnvIndex, unsigned int *pPack) {
	{
		// register: 10
		register int Z;
		{
			{
				// register: 9
				register int X;
				{
					// register: 5
					register int count;
					// register: 7
					register unsigned int *pPSX;
				}
			}
		}
	}
}


// address: 0x80087600
// line start: 38
// line end:   277
void FrontEnd2_Main__Fv() {
	{
		{
			{
				{
					{
						{
							// register: 4
							register int choice;
							{
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x800878CC
// line start: 304
// line end:   345
void LaunchTheDamnGame__Fii(int selected_level, int mode) {
}


// address: 0x80087A08
// line start: 349
// line end:   383
void FrontEnd2_UpdateMusicLoop__Fv() {
}


// address: 0x80087A98
// line start: 130
// line end:   157
int Menu_GetPress__Fv() {
	// register: 5
	register int press;
}


// address: 0x80087B14
// size: 0x28
// line start: 165
// line end:   166
struct MenuItem *__8MenuItemi(struct MenuItem *this, int id) {
	// register: 2
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x80087B2C
// line start: 173
// line end:   175
void ___8MenuItem(struct MenuItem *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x80087B5C
// line start: 182
// line end:   183
void setHighlightState__8MenuItemb(struct MenuItem *this, bool highlight_state) {
}


// address: 0x80087B64
// line start: 191
// line end:   192
void setItemState__8MenuItemi(struct MenuItem *this, int state) {
}


// address: 0x80087B6C
// line start: 200
// line end:   201
void processPress__8MenuItemi(struct MenuItem *this, int press) {
}


// address: 0x80087B94
// line start: 210
// line end:   212
void update__8MenuItem(struct MenuItem *this) {
}


// address: 0x80087B9C
// size: 0x2C
// line start: 218
// line end:   219
struct VMenuItem *__9VMenuItemi(struct VMenuItem *this, int id) {
}


// address: 0x80087BD0
// line start: 226
// line end:   227
int GetHighlightedId__11MenuWrapper(struct MenuWrapper *this) {
}


// address: 0x80087BDC
// size: 0x80
// line start: 234
// line end:   248
struct TextMenuProperties *__18TextMenuProperties(struct TextMenuProperties *this) {
	// register: 16
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x80087C58
// size: 0x50
// line start: 255
// line end:   267
struct TextMenuItem *__12TextMenuItemiPCcR18TextMenuProperties(struct TextMenuItem *this, int id, char *text, struct TextMenuProperties *properties) {
}


// address: 0x80087D10
// line start: 274
// line end:   275
void ___12TextMenuItem(struct TextMenuItem *this, int __in_chrg) {
	// register: 17
	// size: 0x2C
	register struct VMenuItem *this;
	{
	}
}


// address: 0x80087D64
// line start: 281
// line end:   283
void setXY__12TextMenuItemii(struct TextMenuItem *this, int x, int y) {
}


// address: 0x80087D70
// line start: 291
// line end:   331
void draw__12TextMenuItem(struct TextMenuItem *this) {
}


// address: 0x80087F0C
// size: 0x50
// line start: 339
// line end:   342
struct TitleMenuItem *__13TitleMenuItemiPCcR18TextMenuProperties(struct TitleMenuItem *this, int id, char *text, struct TextMenuProperties *properties) {
}


// address: 0x80087F54
// line start: 349
// line end:   368
void draw__13TitleMenuItem(struct TitleMenuItem *this) {
}


// address: 0x80088044
// line start: 419
// line end:   420
void ___14SelectMenuItem(struct SelectMenuItem *this, int __in_chrg) {
	// register: 17
	// size: 0x2C
	register struct VMenuItem *this;
	{
	}
}


// address: 0x80088098
// line start: 426
// line end:   428
void setXY__14SelectMenuItemii(struct SelectMenuItem *this, int x, int y) {
}


// address: 0x800880A4
// line start: 436
// line end:   484
void draw__14SelectMenuItem(struct SelectMenuItem *this) {
	// register: 19
	register int x;
	{
		// register: 17
		register int i;
	}
}


// address: 0x800882C0
// line start: 492
// line end:   506
void processPress__14SelectMenuItemi(struct SelectMenuItem *this, int press) {
}


// address: 0x80088330
// line start: 514
// line end:   527
void setArrows__9BasicMenuP12SlicedImage2T1i(struct BasicMenu *this, struct SlicedImage2 *left, struct SlicedImage2 *right, int spacing) {
}


// address: 0x80088380
// line start: 535
// line end:   543
int getHighlighted__9BasicMenu(struct BasicMenu *this) {
	{
		// register: 5
		register int i;
	}
}


// address: 0x800883CC
// line start: 550
// line end:   564
void setHighlighted__9BasicMenui(struct BasicMenu *this, int id) {
}


// address: 0x800884A8
// size: 0x74
// line start: 571
// line end:   585
struct VerticalMenu2 *__13VerticalMenu2iiiiiii(struct VerticalMenu2 *this, int x, int y, int w, int h, int just_x, int just_y, int spacing) {
	// register: 4
	// size: 0x68
	register struct BasicMenu *this;
	{
		// register: 4
		// size: 0x4
		register struct CClass *this;
		{
			{
				// register: 8
				register int i;
			}
		}
	}
}


// address: 0x80088518
// line start: 592
// line end:   594
void ___13VerticalMenu2(struct VerticalMenu2 *this, int __in_chrg) {
	// register: 4
	// size: 0x68
	register struct BasicMenu *this;
	{
		// register: 4
		// size: 0x4
		register struct CClass *this;
		{
			{
			}
		}
	}
}


// address: 0x80088548
// line start: 602
// line end:   652
void activate__13VerticalMenu2(struct VerticalMenu2 *this) {
	// register: 6
	register int total_h;
	// register: 18
	register int y;
	// register: 20
	register int arrow_x;
	{
		// register: 5
		register int i;
		{
			// register: 19
			register int i;
			{
				// register: 7
				register int i;
			}
		}
	}
}


// address: 0x80088758
// line start: 659
// line end:   670
void draw__13VerticalMenu2(struct VerticalMenu2 *this) {
	{
		// register: 17
		register int i;
	}
}


// address: 0x80088878
// line start: 676
// line end:   679
void update__13VerticalMenu2(struct VerticalMenu2 *this) {
	{
		// register: 17
		register int i;
	}
}


// address: 0x800888F0
// line start: 686
// line end:   712
void processPress__13VerticalMenu2i(struct VerticalMenu2 *this, int press) {
}


// address: 0x80088A60
// line start: 719
// line end:   723
void addItem__13VerticalMenu2P9VMenuItem(struct VerticalMenu2 *this, struct VMenuItem *item) {
}


// address: 0x80088A88
// size: 0xB8
// line start: 745
// line end:   761
struct ScrollingMenu2 *__14ScrollingMenu2iiiiii(struct ScrollingMenu2 *this, int x, int y, int w, int h, int just_x, int slide_amount) {
	// register: 4
	// size: 0x68
	register struct BasicMenu *this;
	{
		// register: 4
		// size: 0x4
		register struct CClass *this;
		{
			{
				// register: 8
				register int i;
			}
		}
	}
}


// address: 0x80088AF8
// line start: 768
// line end:   770
void ___14ScrollingMenu2(struct ScrollingMenu2 *this, int __in_chrg) {
	// register: 4
	// size: 0x68
	register struct BasicMenu *this;
	{
		// register: 4
		// size: 0x4
		register struct CClass *this;
		{
			{
			}
		}
	}
}


// address: 0x80088B28
// line start: 776
// line end:   810
void activate__14ScrollingMenu2(struct ScrollingMenu2 *this) {
	// register: 20
	register int arrow_x;
	// register: 18
	register int y;
	{
		// register: 19
		register int i;
		{
			// register: 8
			register int i;
		}
	}
}


// address: 0x80088CD8
// line start: 818
// line end:   834
void draw__14ScrollingMenu2(struct ScrollingMenu2 *this) {
	// register: 16
	register int y;
	{
		// register: 17
		register int i;
	}
}


// address: 0x80088E60
// line start: 841
// line end:   869
void update__14ScrollingMenu2(struct ScrollingMenu2 *this) {
	{
		// register: 17
		register int i;
	}
}


// address: 0x80088FC4
// line start: 876
// line end:   914
void processPress__14ScrollingMenu2i(struct ScrollingMenu2 *this, int press) {
	{
		{
			// register: 4
			register int target;
			{
				{
					// register: 4
					register int target;
				}
			}
		}
	}
}


// address: 0x80089140
// line start: 921
// line end:   930
void addItem__14ScrollingMenu2P9VMenuItem(struct ScrollingMenu2 *this, struct VMenuItem *item) {
}


// address: 0x800891B0
// size: 0x110
// line start: 941
// line end:   972
struct TextMenuWrapper *__15TextMenuWrapperPCPcPiiPcb(struct TextMenuWrapper *this, char **string_list, int *id_list, int num_items, char *font_name, bool use_scrolling_menu) {
	// register: 19
	// size: 0xC
	register struct MenuWrapper *this;
	{
		// register: 19
		// size: 0x4
		register struct CClass *this;
		{
			{
				// register: 20
				register int i;
			}
		}
	}
}


// address: 0x80089420
// line start: 979
// line end:   984
void ___15TextMenuWrapper(struct TextMenuWrapper *this, int __in_chrg) {
	{
		{
			{
				// register: 18
				// size: 0xC
				register struct MenuWrapper *this;
				{
					// register: 18
					// size: 0x4
					register struct CClass *this;
					{
						{
							{
								// register: 17
								register int i;
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80089504
// line start: 990
// line end:   997
void HandleInput__15TextMenuWrapper(struct TextMenuWrapper *this) {
	// register: 16
	register int press;
}


// address: 0x80089590
// line start: 1004
// line end:   1033
bool TestComplete__15TextMenuWrapper(struct TextMenuWrapper *this) {
	{
		{
			{
				// register: 5
				register int i;
			}
		}
	}
}


// address: 0x8008966C
// line start: 356
// line end:   356
bool TestComplete__11MenuWrapper(struct MenuWrapper *this) {
}


// address: 0x80089674
// line start: 355
// line end:   355
void HandleInput__11MenuWrapper(struct MenuWrapper *this) {
}


// address: 0x8008967C
// line start: 361
// line end:   941
void ___11MenuWrapper(struct MenuWrapper *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x800896AC
// line start: 224
// line end:   1036
void ___13TitleMenuItem(struct TitleMenuItem *this, int __in_chrg);

// address: 0x800896F4
// line start: 184
// line end:   941
void ___18TextMenuProperties(struct TextMenuProperties *this, int __in_chrg) {
	// register: 17
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x80089744
// line start: 134
// line end:   134
void addItem__9BasicMenuP9VMenuItem(struct BasicMenu *this, struct VMenuItem *item) {
}


// address: 0x8008974C
// line start: 130
// line end:   130
void processPress__9BasicMenui(struct BasicMenu *this, int press) {
}


// address: 0x80089754
// line start: 128
// line end:   128
void update__9BasicMenu(struct BasicMenu *this) {
}


// address: 0x8008975C
// line start: 126
// line end:   126
void draw__9BasicMenu(struct BasicMenu *this) {
}


// address: 0x80089764
// line start: 123
// line end:   123
void activate__9BasicMenu(struct BasicMenu *this) {
}


// address: 0x8008976C
// line start: 151
// line end:   571
void ___9BasicMenu(struct BasicMenu *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x8008979C
// line start: 102
// line end:   256
void ___9VMenuItem(struct VMenuItem *this, int __in_chrg);

// address: 0x800897E4
// line start: 58
// line end:   58
void draw__8MenuItem(struct MenuItem *this) {
}


// address: 0x800897EC
// line start: 56
// line end:   56
void setXY__8MenuItemii(struct MenuItem *this, int x, int y) {
}


// address: 0x800897F4
// line start: 92
// line end:   92
void ___6CClass_addr_800897F4(struct CClass *this, int __in_chrg) {
}


// address: 0x80089824
// line start: 524
// line end:   524
void _GLOBAL__I_SCROLL_COUNT() {
}


// address: 0x8008984C
// size: 0x168
// line start: 29
// line end:   126
struct MultiSelectScreen *__17MultiSelectScreen(struct MultiSelectScreen *this) {
	// address: 0xFFFFFFA8
	// size: 0x40
	auto struct ScreenElement *item[16];
	// register: 2
	// size: 0x24
	register struct ScreenElement *pElement;
	{
		// register: 6
		register int i;
		{
			// register: 17
			register int i;
		}
	}
}


// address: 0x80089F1C
// line start: 148
// line end:   162
void ___17MultiSelectScreen(struct MultiSelectScreen *this, int __in_chrg) {
	{
		// register: 17
		register int i;
	}
}


// address: 0x8008A0A8
// line start: 169
// line end:   174
void draw__17MultiSelectScreenii(struct MultiSelectScreen *this, int x, int y) {
}


// address: 0x8008A0EC
// line start: 182
// line end:   188
void update__17MultiSelectScreen(struct MultiSelectScreen *this) {
}


// address: 0x8008A17C
// line start: 196
// line end:   225
int handlePress__17MultiSelectScreen(struct MultiSelectScreen *this) {
}


// address: 0x8008A224
// line start: 233
// line end:   234
int GetGameMode__17MultiSelectScreen(struct MultiSelectScreen *this) {
}


// address: 0x8008A248
// line start: 239
// line end:   244
void InitEndProcess__17MultiSelectScreeni(struct MultiSelectScreen *this, int press) {
}


// address: 0x8008A288
// line start: 250
// line end:   255
int EndProcess__17MultiSelectScreen(struct MultiSelectScreen *this) {
}


// address: 0x8008A2B8
// line start: 265
// line end:   351
int MultiSelect_Main__FPi(int *pGameMode) {
	// register: 20
	register unsigned int oldSkyColor;
	// register: 17
	// size: 0x168
	register struct MultiSelectScreen *pMultiSelectScreen;
	// register: 4
	register int press;
	// register: 18
	register int exitPress;
}


// address: 0x8008A4D4
// size: 0x24
// line start: 15
// line end:   33
struct ScreenElement *__13ScreenElementiiii(struct ScreenElement *this, int homeX, int homeY, int screenX, int screenY) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
	}
}


// address: 0x8008A530
// line start: 41
// line end:   46
void ___13ScreenElement(struct ScreenElement *this, int __in_chrg) {
	// register: 4
	// size: 0x4
	register struct CClass *this;
	{
		{
		}
	}
}


// address: 0x8008A560
// line start: 52
// line end:   54
int width__13ScreenElement(struct ScreenElement *this) {
}


// address: 0x8008A568
// line start: 62
// line end:   108
void update__13ScreenElement(struct ScreenElement *this) {
	// register: 3
	register int distX;
	// register: 3
	register int distY;
	{
		{
			// register: 2
			register int add;
			{
				{
					// register: 2
					register int add;
				}
			}
		}
	}
}


// address: 0x8008A630
// line start: 113
// line end:   117
void refresh__13ScreenElement(struct ScreenElement *this) {
}


// address: 0x8008A638
// line start: 123
// line end:   125
void SnapToHomeX__13ScreenElement(struct ScreenElement *this) {
}


// address: 0x8008A644
// line start: 142
// line end:   144
int GetScreenX__13ScreenElement(struct ScreenElement *this) {
}


// address: 0x8008A650
// line start: 151
// line end:   153
int GetScreenY__13ScreenElement(struct ScreenElement *this) {
}


// address: 0x8008A65C
// size: 0x68
// line start: 160
// line end:   168
struct ScreenElementList *__17ScreenElementListiiii(struct ScreenElementList *this, int homeX, int homeY, int screenX, int screenY) {
	{
		// register: 4
		register int i;
	}
}


// address: 0x8008A6B8
// line start: 176
// line end:   184
void ___17ScreenElementList(struct ScreenElementList *this, int __in_chrg) {
	{
		// register: 17
		register int i;
	}
}


// address: 0x8008A760
// line start: 192
// line end:   208
void addItem__17ScreenElementListP13ScreenElement(struct ScreenElementList *this, struct ScreenElement *pScreenElement) {
	{
		// register: 6
		register int i;
	}
}


// address: 0x8008A7A4
// line start: 214
// line end:   221
void update__17ScreenElementList(struct ScreenElementList *this) {
	{
		// register: 17
		register int i;
	}
}


// address: 0x8008A824
// line start: 229
// line end:   238
void draw__17ScreenElementListii(struct ScreenElementList *this, int x, int y) {
	{
		// register: 17
		register int i;
	}
}


// address: 0x8008A8CC
// size: 0x2C
// line start: 243
// line end:   253
struct TextScreenElement *__17TextScreenElementPcP4Fontiiii(struct TextScreenElement *this, char *pString, struct Font_duplicate_s0 *pFont, int homeX, int homeY, int screenX, int screenY) {
}


// address: 0x8008A958
// line start: 261
// line end:   265
void ___17TextScreenElement(struct TextScreenElement *this, int __in_chrg) {
}


// address: 0x8008A9B8
// line start: 273
// line end:   283
void setString__17TextScreenElementPc(struct TextScreenElement *this, char *pString) {
}


// address: 0x8008AA14
// line start: 291
// line end:   301
void draw__17TextScreenElementii(struct TextScreenElement *this, int x, int y) {
}


// address: 0x8008AA84
// line start: 307
// line end:   308
int width__17TextScreenElement(struct TextScreenElement *this) {
}


// address: 0x8008AAB0
// size: 0x28
// line start: 316
// line end:   326
struct SpriteScreenElement *__19SpriteScreenElementPciiiiii(struct SpriteScreenElement *this, char *pFileName, int homeX, int homeY, int screenX, int screenY, int justY, int justX) {
}


// address: 0x8008AB48
// line start: 334
// line end:   337
void ___19SpriteScreenElement(struct SpriteScreenElement *this, int __in_chrg) {
}


// address: 0x8008ABC0
// line start: 345
// line end:   355
void draw__19SpriteScreenElementii(struct SpriteScreenElement *this, int x, int y) {
}


// address: 0x8008AC2C
// line start: 361
// line end:   364
int width__19SpriteScreenElement(struct SpriteScreenElement *this) {
}


// address: 0x8008AC50
// line start: 92
// line end:   92
void ___6CClass_addr_8008AC50(struct CClass *this, int __in_chrg) {
}


// address: 0x8008AC80
// size: 0x174
// line start: 85
// line end:   87
struct PlayerSelectScreen *__18PlayerSelectScreeni(struct PlayerSelectScreen *this, int gameMode) {
}


// address: 0x8008ACF8
// line start: 95
// line end:   237
void init__18PlayerSelectScreeni(struct PlayerSelectScreen *this, int gameMode) {
	// address: 0xFFFFFFA0
	// size: 0x40
	auto struct ScreenElement *item[16];
	{
		// register: 4
		register int i;
		{
			// register: 17
			register int i;
		}
	}
}


// address: 0x8008B2EC
// line start: 245
// line end:   263
void ___18PlayerSelectScreen(struct PlayerSelectScreen *this, int __in_chrg) {
}


// address: 0x8008B3D4
// line start: 271
// line end:   276
void draw__18PlayerSelectScreen(struct PlayerSelectScreen *this) {
}


// address: 0x8008B420
// line start: 284
// line end:   306
void update__18PlayerSelectScreen(struct PlayerSelectScreen *this) {
}


// address: 0x8008B484
// line start: 313
// line end:   342
void refresh__18PlayerSelectScreen(struct PlayerSelectScreen *this) {
}


// address: 0x8008B598
// line start: 350
// line end:   530
int handlePress__18PlayerSelectScreen(struct PlayerSelectScreen *this) {
	// register: 17
	register int SELECTED_CONTROLLER;
	{
		{
			{
				{
				}
			}
		}
	}
}


// address: 0x8008BBF0
// line start: 538
// line end:   601
int PlayerSelect_Main__Fi(int gameMode) {
	// register: 18
	register unsigned int oldSkyColor;
	// register: 17
	// size: 0x174
	register struct PlayerSelectScreen *pPlayerSelectScreen;
	// register: 16
	register int press;
}


// address: 0x8008BD78
// size: 0x68
// line start: 611
// line end:   630
struct PromptScreenElement *__19PromptScreenElementPcT1P4Fontiiii(struct PromptScreenElement *this, char *pFileName, char *pString, struct Font_duplicate_s0 *pFont, int homeX, int homeY, int screenX, int screenY) {
	// address: 0xFFFFFFE0
	// size: 0x8
	auto struct ScreenElement *item[2];
}


// address: 0x8008BECC
// line start: 638
// line end:   638
void ___19PromptScreenElement(struct PromptScreenElement *this, int __in_chrg) {
}


// address: 0x8008BF20
// line start: 646
// line end:   653
int width__19PromptScreenElement(struct PromptScreenElement *this) {
	// register: 4
	// size: 0x2C
	register struct TextScreenElement *pTextElement;
	// register: 17
	// size: 0x28
	register struct SpriteScreenElement *pSpriteElement;
}


// address: 0x8008BF88
// size: 0x78
// line start: 660
// line end:   674
struct ScoreScreenElement *__18ScoreScreenElementiP4Fontii(struct ScoreScreenElement *this, int value, struct Font_duplicate_s0 *pFont, int x, int y) {
	// address: 0xFFFFFFC8
	// size: 0x20
	auto char newString[32];
}


// address: 0x8008C054
// line start: 682
// line end:   682
void ___18ScoreScreenElement(struct ScoreScreenElement *this, int __in_chrg) {
}


// address: 0x8008C0A8
// line start: 690
// line end:   694
void setValue__18ScoreScreenElementi(struct ScoreScreenElement *this, int value) {
}


// address: 0x8008C0CC
// line start: 702
// line end:   708
void draw__18ScoreScreenElementii(struct ScoreScreenElement *this, int x, int y) {
	// register: 17
	register int oldFixedWidth;
}


// address: 0x8008C110
// line start: 716
// line end:   732
void update__18ScoreScreenElement(struct ScoreScreenElement *this) {
	// register: 3
	register int diff;
	// address: 0xFFFFFFD8
	// size: 0x20
	auto char newString[32];
}


// address: 0x8008C184
// size: 0x98
// line start: 739
// line end:   761
struct CareerScreenElement *__19CareerScreenElementP4Fontiiii(struct CareerScreenElement *this, struct Font_duplicate_s0 *pFont, int homeX, int homeY, int screenX, int screenY) {
	// address: 0xFFFFFFE0
	// size: 0xC
	auto struct ScreenElement *item[3];
	{
		// register: 17
		register int i;
	}
}


// address: 0x8008C360
// line start: 769
// line end:   775
void ___19CareerScreenElement(struct CareerScreenElement *this, int __in_chrg) {
}


// address: 0x8008C428
// line start: 783
// line end:   814
void draw__19CareerScreenElementii(struct CareerScreenElement *this, int x, int y) {
	{
		// register: 16
		register int i;
		{
			{
				{
					// register: 6
					register int space;
					{
						// register: 17
						register int i;
					}
				}
			}
		}
	}
}


// address: 0x8008C5C4
// line start: 822
// line end:   824
void update__19CareerScreenElement(struct CareerScreenElement *this) {
}


// address: 0x8008C5E4
// line start: 832
// line end:   847
void refresh__19CareerScreenElement(struct CareerScreenElement *this) {
	// register: 5
	register int delay;
	{
		// register: 4
		register int i;
	}
}


// address: 0x8008C6A8
// size: 0xB4
// line start: 867
// line end:   890
struct BioScreenElement *__16BioScreenElementP4Fontiiii(struct BioScreenElement *this, struct Font_duplicate_s0 *pFont, int homeX, int homeY, int screenX, int screenY) {
	{
		// register: 4
		register int i;
	}
}


// address: 0x8008C7B4
// line start: 898
// line end:   905
void ___16BioScreenElement(struct BioScreenElement *this, int __in_chrg) {
	{
		// register: 17
		register int i;
	}
}


// address: 0x8008C860
// line start: 913
// line end:   926
void draw__16BioScreenElementii(struct BioScreenElement *this, int x, int y) {
	{
		// register: 17
		register int i;
	}
}


// address: 0x8008C93C
// line start: 934
// line end:   945
void update__16BioScreenElement(struct BioScreenElement *this) {
	{
		// register: 17
		register int i;
	}
}


// address: 0x8008C9FC
// line start: 952
// line end:   985
void refresh__16BioScreenElement(struct BioScreenElement *this) {
	// register: 16
	register char **foo;
	// register: 17
	register int currY;
	{
		// register: 17
		register int i;
		{
			{
				{
					// register: 4
					// size: 0x24
					register struct ScreenElement *item;
				}
			}
		}
	}
}


// address: 0x8008CB68
// line start: 996
// line end:   1008
void HandleDown__16BioScreenElement(struct BioScreenElement *this) {
	{
		{
			{
				// register: 6
				register int i;
			}
		}
	}
}


// address: 0x8008CBD8
// line start: 1017
// line end:   1028
void HandleUp__16BioScreenElement(struct BioScreenElement *this) {
	{
		{
			{
				// register: 6
				register int i;
			}
		}
	}
}


// address: 0x8008CC40
// size: 0xA58
// line start: 1036
// line end:   1157
struct SkaterScreenElement *__19SkaterScreenElementiP4Fontiiii(struct SkaterScreenElement *this, int fullWindow, struct Font_duplicate_s0 *pFont, int homeX, int homeY, int screenX, int screenY) {
	// address: 0xFFFFFFD8
	// size: 0x10
	auto struct ScreenElement *item[4];
	// register: 5
	// size: 0x24
	register struct Item *pItemList;
	// register: 17
	register unsigned char *bmpBuf;
	{
		// register: 6
		register int i;
		{
			// register: 18
			register int i;
		}
	}
}


// address: 0x8008D03C
// line start: 1166
// line end:   1201
void ___19SkaterScreenElement(struct SkaterScreenElement *this, int __in_chrg) {
	{
		// register: 17
		register int i;
		{
			// register: 17
			register int i;
			{
				// register: 17
				register int i;
				{
					// register: 19
					register int i;
				}
			}
		}
	}
}


// address: 0x8008D26C
// line start: 1209
// line end:   1211
void RotateSkater__19SkaterScreenElementi(struct SkaterScreenElement *this, int angle) {
}


// address: 0x8008D298
// line start: 1244
// line end:   1264
void LoadAllIcons__19SkaterScreenElement(struct SkaterScreenElement *this) {
	{
		// register: 5
		register int i;
	}
}


// address: 0x8008D354
// line start: 1288
// line end:   1296
void SetClippingBox3__Fiiii(int x, int y, int w, int h) {
	// address: 0xFFFFFFF0
	// size: 0x8
	auto struct RECT r;
	// register: 16
	// size: 0xC
	register struct DR_AREA *pClip;
}


// address: 0x8008D3F8
// line start: 1303
// line end:   1415
void draw__19SkaterScreenElementii(struct SkaterScreenElement *this, int x, int y) {
	// register: 2
	register int DrawThisSkater;
	// address: 0xFFFFFFD0
	auto int fullWindowFaceOffsetX;
	// address: 0xFFFFFFD4
	auto int fullWindowFaceOffsetY;
	{
		{
			{
				{
					{
						{
							{
								{
									{
										{
											// register: 17
											register int t1;
											// register: 16
											register int t2;
											{
												// register: 17
												register int i;
												{
													// register: 21
													register int i;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8008D7DC
// line start: 1426
// line end:   1498
char *Spool_LoadPSH2__FPcT0PPcPii(char *pPSHBuffer, char *pPSHName, char **pHierarchyArray, int *pPartCount, int maxPartNames) {
	// address: 0xFFFFFFC8
	// size: 0x10
	auto char filename[16];
	// address: 0xFFFFFFD8
	// size: 0x10
	auto char prefixString[16];
	// register: 17
	register int prefixStringLength;
	// register: 16
	register char *p;
}


// address: 0x8008D954
// line start: 1504
// line end:   1600
void UpdateSpoolItems__19SkaterScreenElement(struct SkaterScreenElement *this) {
	{
		// register: 17
		register int i;
		{
			{
				{
					// register: 18
					register unsigned char *theData;
					{
						// register: 19
						register int i;
						{
							{
								{
									// register: 17
									register unsigned char *theData;
									{
										{
											// register: 16
											register unsigned int *theData;
											{
												{
													// register: 3
													register char *theData;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8008DC94
// line start: 1608
// line end:   1698
void update__19SkaterScreenElement(struct SkaterScreenElement *this) {
	{
		// register: 17
		register int i;
		{
			// register: 17
			register int i;
		}
	}
}


// address: 0x8008DDD8
// line start: 1705
// line end:   1718
void refresh__19SkaterScreenElement(struct SkaterScreenElement *this) {
}


// address: 0x8008DE88
// line start: 1726
// line end:   1795
void AddSpoolItems__19SkaterScreenElement(struct SkaterScreenElement *this) {
	// address: 0xFFFFFF78
	// size: 0x38
	auto int order[14];
	{
		// register: 18
		register int num;
		// address: 0xFFFFFFB0
		// size: 0x20
		auto char filename[32];
		{
			// register: 19
			register int i;
			{
				// register: 20
				register int i;
				{
					// register: 16
					register int num;
					// address: 0xFFFFFFB0
					// size: 0x20
					auto char filename[32];
				}
			}
		}
	}
}


// address: 0x8008E1F0
// line start: 1803
// line end:   1922
void LoadAllSkaters__19SkaterScreenElement(struct SkaterScreenElement *this) {
	// address: 0xFFFFFFD0
	auto unsigned int *pSpoolFile;
	{
		// register: 3
		register int i;
		{
			// register: 19
			register int i;
			{
				{
					// register: 8
					// size: 0x190
					register struct CSuper *this;
					{
					}
				}
			}
		}
	}
}


// address: 0x8008E574
// line start: 1932
// line end:   1941
unsigned int *GetReducedPSXFile__19SkaterScreenElementPc(struct SkaterScreenElement *this, char *modelFile) {
	// address: 0xFFFFFFE8
	// size: 0x10
	auto char filename[16];
	// register: 16
	register char *pData;
}


// address: 0x8008E5BC
// line start: 1948
// line end:   2062
void Spool_StripAnimFile__FPc(char *pPSX) {
	// register: 16
	register char *pAnim;
	// register: 3
	register unsigned int *pNumModels;
	// register: 17
	register unsigned int NumModels;
	// register: 6
	register unsigned int *pStuff;
	// register: 16
	register unsigned int *pDest;
	// register: 7
	register int NumTextures;
	// register: 7
	register int NumPalettes;
	{
		// register: 4
		register int i;
		{
			// register: 4
			register int i;
			{
				// register: 5
				register int i;
				{
					{
						// register: 4
						register int j;
						{
							// register: 5
							register int i;
							{
								{
									// register: 4
									register int j;
									{
										// register: 4
										register int i;
										{
											// register: 8
											register int i;
											{
												// register: 5
												register int numColors;
												// register: 2
												register int width;
												// register: 3
												register int height;
												// register: 4
												register int numBytes;
												{
													// register: 3
													register int j;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x8008E828
// line start: 2071
// line end:   2131
int GetReducedAnim__19SkaterScreenElementPc(struct SkaterScreenElement *this, char *animFile) {
	// address: 0xFFFFFFE0
	auto int size;
	// register: 20
	register char *preAnimFile;
	// register: 19
	register int AnimRegion;
	// address: 0xFFFFFFD8
	// size: 0x6
	auto short FrontEndAnimations[3];
}


// address: 0x8008E94C
// line start: 2139
// line end:   2189
void refreshSkater__19SkaterScreenElement(struct SkaterScreenElement *this) {
	// register: 2
	register int LoadThisSkater;
	{
		{
		}
	}
}


// address: 0x8008EAF0
// size: 0x6C
// line start: 2194
// line end:   2197
struct StatsScreenElement *__18StatsScreenElementiiii(struct StatsScreenElement *this, int homeX, int homeY, int screenX, int screenY) {
}


// address: 0x8008EB68
// line start: 2205
// line end:   2208
void ___18StatsScreenElement(struct StatsScreenElement *this, int __in_chrg) {
}


// address: 0x8008EBE0
// line start: 2216
// line end:   2228
void draw__18StatsScreenElementii(struct StatsScreenElement *this, int x, int y) {
	{
		// register: 16
		register int i;
	}
}


// address: 0x8008ECD4
// line start: 2235
// line end:   2237
void update__18StatsScreenElement(struct StatsScreenElement *this) {
}


// address: 0x8008ED0C
// size: 0x70
// line start: 2244
// line end:   2267
struct MultiPlayerScreenElement *__24MultiPlayerScreenElementP4Fontiiii(struct MultiPlayerScreenElement *this, struct Font_duplicate_s0 *pFont, int homeX, int homeY, int screenX, int screenY) {
	// address: 0xFFFFFF70
	// size: 0x80
	auto char test[128];
}


// address: 0x8008EE14
// line start: 2275
// line end:   2275
void ___24MultiPlayerScreenElement(struct MultiPlayerScreenElement *this, int __in_chrg) {
}


// address: 0x8008EE68
// line start: 2283
// line end:   2296
void update__24MultiPlayerScreenElement(struct MultiPlayerScreenElement *this) {
}


// address: 0x8008EE88
// line start: 2304
// line end:   2310
void refresh__24MultiPlayerScreenElement(struct MultiPlayerScreenElement *this) {
	// address: 0xFFFFFF78
	// size: 0x80
	auto char test[128];
}


// address: 0x8008EECC
// line start: 2318
// line end:   2320
void ResetStartingLocation__24MultiPlayerScreenElement(struct MultiPlayerScreenElement *this) {
}


// address: 0x80094AB8
// line start: 259
// line end:   330
void M3d_Line__Fiiiiii(int x0, int y0, int x1, int y1, int Color, int z) {
	// register: 2
	register int t;
	// register: 6
	// size: 0x10
	register struct LINE_F2 *aline;
	// register: 3
	register unsigned char *newppoly;
}


// address: 0x80094C94
// line start: 335
// line end:   507
int Wireframe_ProcessPolys__FPUiii(unsigned int *pFaceX, int Num, int color) {
	// address: 0xFFFFFFC0
	// size: 0x8
	auto struct SProjectedVertex *pVertices;
	// register: 4
	register int FaceR;
	// register: 6
	register int FaceG;
	// register: 7
	register int FaceB;
	{
		// address: 0xFFFFFFC4
		auto int i;
		{
			// register: 7
			register unsigned char *pVertexIndex;
			// register: 19
			register int x0;
			// register: 20
			register int y0;
			// register: 5
			register int z0;
			// register: 23
			register int x1;
			// register: 21
			register int y1;
			// register: 22
			register int x2;
			// register: 30
			register int y2;
			// register: 17
			register int zmax;
			{
				{
					// address: 0xFFFFFFC8
					auto int x3;
					// address: 0xFFFFFFCC
					auto int y3;
					// register: 16
					register int color2;
					{
						{
							// register: 5
							// size: 0x18
							register struct POLY_F4 *p_poly;
							{
								{
									// register: 3
									register int push;
									{
										{
											// register: 3
											register int push;
											{
												{
													{
														// register: 16
														register int color2;
														{
															{
																// register: 5
																// size: 0x14
																register struct POLY_F3 *p_poly;
																{
																	{
																		// register: 3
																		register int push;
																		{
																			{
																				// register: 3
																				register int push;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80095220
// line start: 540
// line end:   749
void M3d_RenderSetup__FP7SCameraP9SViewportPUi(struct SCamera *pCamera, struct SViewport *pVP, unsigned int *ot) {
	// address: 0xFFFFFFD8
	// size: 0x8
	auto struct RECT Window;
	// register: 17
	// size: 0xC
	register struct DR_AREA *pClipArea;
	// register: 19
	register unsigned int opp;
	// register: 18
	register unsigned int adj;
	// register: 6
	register unsigned int hyp;
	// register: 2
	// size: 0x28
	register struct Texture *pTex;
	{
		// register: 6
		register int i;
		{
			// register: 10
			register int i;
		}
	}
}


// address: 0x800957FC
// line start: 755
// line end:   792
void M3d_RenderCleanup__Fv() {
	// address: 0xFFFFFFF0
	// size: 0x8
	auto struct RECT Window;
	// register: 16
	// size: 0xC
	register struct DR_AREA *pClipArea;
	{
		{
			{
				// register: 7
				register int i;
				{
					// register: 6
					// size: 0x18
					register struct POLY_F4 *p_polyF4;
				}
			}
		}
	}
}


// address: 0x800959A8
// line start: 806
// line end:   1340
void M3d_Render__FPv(void *p) {
	// register: 17
	// size: 0x24
	register struct Item *pItem;
	// address: 0xFFFFFF60
	// size: 0x10
	auto struct VECTOR Position;
	// address: 0xFFFFFF70
	// size: 0x10
	auto struct VECTOR PosnRelCam;
	// address: 0xFFFFFF80
	// size: 0x20
	auto struct MATRIX Transform;
	// address: 0xFFFFFFA0
	// size: 0x20
	auto struct MATRIX WorldTransform;
	// address: 0xFFFFFFC0
	// size: 0x20
	auto struct MATRIX TempMatrix;
	// register: 18
	// size: 0x24
	register struct SModel *pModel;
	// register: 16
	register unsigned int GlobalFaceFlags;
	// register: 16
	register unsigned short yon;
	{
		{
			{
				{
					{
						{
							// register: 18
							register int tmp;
							// register: 3
							register int r;
							// register: 6
							register int g;
							// register: 5
							register int b;
						}
					}
				}
			}
		}
	}
}


// address: 0x80096700
// line start: 1562
// line end:   1637
void M3d_RenderBackground__FPv(void *p) {
	// register: 16
	// size: 0x24
	register struct Item *pItem;
	// address: 0xFFFFFF80
	// size: 0x10
	auto struct VECTOR Position;
	// address: 0xFFFFFF90
	// size: 0x10
	auto struct VECTOR PosnRelCam;
	// address: 0xFFFFFFA0
	// size: 0x20
	auto struct MATRIX Transform;
	// address: 0xFFFFFFC0
	// size: 0x20
	auto struct MATRIX WorldTransform;
	// register: 4
	// size: 0x24
	register struct SModel *pModel;
	// register: 21
	register unsigned int GlobalFaceFlags;
}


// address: 0x800968D8
// line start: 1643
// line end:   1917
void RenderSuperItem__FP4Item(struct Item *pItem) {
	// address: 0xFFFFFFB0
	auto unsigned int NumParts;
	// address: 0xFFFFFFB4
	auto unsigned int Rgb;
	// address: 0xFFFFFF20
	// size: 0x10
	auto struct VECTOR Position;
	// register: 19
	// size: 0x18
	register struct SMatrix *pAnimTransform;
	// address: 0xFFFFFF30
	// size: 0x20
	auto struct MATRIX Transform;
	// address: 0xFFFFFF50
	// size: 0x20
	auto struct MATRIX SuperTransform;
	// address: 0xFFFFFF70
	// size: 0x20
	auto struct MATRIX WorldTransform;
	// address: 0xFFFFFF90
	// size: 0x20
	auto struct MATRIX SuperLightTransform;
	// register: 21
	register int i;
	// register: 6
	register int Type;
	// register: 17
	// size: 0x24
	register struct SModel *pModel;
	// register: 16
	// size: 0x24
	register struct SModel **ppModels;
	// address: 0xFFFFFFB8
	// size: 0x8
	auto struct SAnimFrame *pAnimTex;
	// address: 0xFFFFFFBC
	auto unsigned short Scale;
	// address: 0xFFFFFFC0
	auto short OTPushback;
	// address: 0xFFFFFFC4
	auto unsigned int ItemFlags;
	// address: 0xFFFFFFC8
	// size: 0x18
	auto struct SMatrix *pFirstTransform;
	{
		{
			// register: 2
			register int Lookup;
			{
				{
					// register: 16
					register int DoEllipsoids;
					// register: 20
					register int DoShadows;
					{
						{
							{
								// register: 16
								register int s;
							}
						}
					}
				}
			}
		}
	}
}


// address: 0x80097164
// line start: 1930
// line end:   1964
void RenderModel__FP6SModel(struct SModel *pModel) {
	// register: 19
	register unsigned int Outcode;
	// register: 18
	register unsigned int *pFace;
	// register: 16
	register unsigned int Num;
	// register: 17
	// size: 0x8
	register struct SVECTOR *pGeom;
}


// address: 0x80097240
// line start: 1969
// line end:   2010
void RenderModelFast__FP6SModelP6VECTOR(struct SModel *pModel, struct VECTOR *pPosnRelCam) {
	// register: 19
	register unsigned int *pFace;
	// register: 18
	register unsigned int Num;
	// register: 17
	register unsigned int NumVerts;
	// register: 16
	// size: 0x8
	register struct SVECTOR *pGeom;
}


// address: 0x80097334
// line start: 2015
// line end:   2043
void RenderBackgroundModel__FP6SModel(struct SModel *pModel) {
	// register: 18
	register unsigned int *pFace;
	// register: 16
	register unsigned int Num;
	// register: 17
	// size: 0x8
	register struct SVECTOR *pGeom;
}


// address: 0x800973D8
// line start: 2050
// line end:   2086
void RenderModelInSuper__FP6SModel(struct SModel *pModel) {
	// register: 18
	register unsigned int Outcode;
	// register: 18
	register unsigned int *pFace;
	// register: 16
	register unsigned int Num;
	// register: 17
	// size: 0x8
	register struct SVECTOR *pGeom;
}


// address: 0x800974D4
// line start: 2091
// line end:   2124
void RenderModelInSuperFast__FP6SModel(struct SModel *pModel) {
	// register: 4
	register unsigned int Outcode;
	// register: 16
	register unsigned int Num;
	// register: 17
	// size: 0x8
	register struct SVECTOR *pGeom;
}


// address: 0x80097574
// line start: 2129
// line end:   2179
void RenderModelNonRotated__FP6SModelP6VECTOR(struct SModel *pModel, struct VECTOR *pPosnRelCam) {
	// register: 18
	register unsigned int Outcode;
	// register: 18
	register unsigned int *pFace;
	// register: 16
	register unsigned int Num;
	// register: 17
	// size: 0x8
	register struct SVECTOR *pGeom;
}


// address: 0x80097654
// line start: 2183
// line end:   2212
void RenderBackgroundModelNonRotated__FP6SModel(struct SModel *pModel) {
	// register: 18
	register unsigned int *pFace;
	// register: 16
	register unsigned int Num;
	// register: 17
	// size: 0x8
	register struct SVECTOR *pGeom;
}


// address: 0x800976FC
// line start: 4050
// line end:   4076
void M3d_BuildTransform__FP6CSuper(struct CSuper *pSuper) {
}


// address: 0x800977B8
// line start: 4082
// line end:   4099
int uWibble__FP15STexWibVertInfo(struct STexWibVertInfo *pTexWibVertInfo) {
	// register: 4
	register short *pWibbleTable;
	// register: 4
	register int Amplitude;
	// register: 2
	register int Phase;
	// register: 3
	register int Index;
}


// address: 0x80097808
// line start: 4104
// line end:   4122
int vWibble__FP15STexWibVertInfo(struct STexWibVertInfo *pTexWibVertInfo) {
	// register: 4
	register short *pWibbleTable;
	// register: 4
	register int Amplitude;
	// register: 2
	register int Phase;
	// register: 3
	register int Index;
}


// address: 0x80097858
// line start: 4128
// line end:   4319
void M3d_PreprocessWibblyTextures__Fi(int Region) {
	// register: 9
	register unsigned int *pData;
	// address: 0xFFFFFFA0
	auto unsigned int *pPSX;
	// address: 0xFFFFFFA4
	auto unsigned int *pFace;
	// register: 10
	// size: 0x10
	register struct STexWibFaceInfo *pTexWibFaceInfo;
	// register: 3
	// size: 0x24
	register struct Item *pItem;
	// register: 5
	// size: 0x24
	register struct SModel *pModel;
	// address: 0xFFFFFFA8
	auto int NumFaces;
	// address: 0xFFFFFFAC
	auto int i;
	// address: 0xFFFFFFB0
	auto int uScroll;
	// address: 0xFFFFFFB4
	auto int vScroll;
	// register: 30
	register int TileWidth;
	// address: 0xFFFFFFB8
	auto int TileHeight;
	// register: 17
	register int u0;
	// register: 23
	register int v0;
	// register: 16
	register int u1;
	// register: 22
	register int v1;
	// register: 18
	register int u2;
	// register: 20
	register int v2;
	// register: 21
	register int u3;
	// register: 19
	register int v3;
	// register: 2
	register int And;
	// register: 3
	register int Or;
	// register: 4
	register int Count;
	{
		// address: 0xFFFFFFBC
		auto int ZeroUAmplitudes;
		// address: 0xFFFFFFC0
		auto int ZeroVAmplitudes;
	}
}


// address: 0x80097CD0
// line start: 4342
// line end:   4445
void M3d_PreprocessPulsingColours__Fi(int Region) {
	// register: 8
	register unsigned int *pData;
	// register: 14
	register unsigned int *pEnd;
	// register: 15
	register unsigned int dt;
	// register: 13
	register unsigned int ListLen;
	// register: 6
	register unsigned int ListPos;
	// register: 7
	register int t;
	// address: 0xFFFFFFD8
	// size: 0xC
	auto int rgb0[3];
	// address: 0xFFFFFFE8
	// size: 0xC
	auto int drgb[3];
	// register: 9
	// size: 0x4
	register struct SRGBI *RGBs;
}


