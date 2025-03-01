#ifndef MY_BINK_H
#define MY_BINK_H

#pragma once

#include "non_win32.h"
#include "export.h"
#include "my_dx.h"

typedef void* HBINK;

#define BINKFILEHANDLE        0x00800000L // Use when passing in a file handle
#define BINKIOSIZE            0x01000000L // Set an io size (call BinkIOSize first)

struct BINKSUMMARY
{
	u32 Width;                  // Width of frames
	u32 Height;                 // Height of frames
	u32 TotalTime;              // total time (ms)
	u32 FileFrameRate;          // frame rate

	u32 FileFrameRateDiv;       // frame rate divisor
	u32 FrameRate;              // frame rate
	u32 FrameRateDiv;           // frame rate divisor
	u32 TotalOpenTime;          // Time to open and prepare for decompression
	u32 TotalFrames;            // Total Frames
	u32 TotalPlayedFrames;      // Total Frames played
	u32 SkippedFrames;          // Total number of skipped frames
	u32 SkippedBlits;           // Total number of skipped blits
	u32 SoundSkips;             // Total number of sound skips
	u32 TotalBlitTime;          // Total time spent blitting
	u32 TotalReadTime;          // Total time spent reading
	u32 TotalVideoDecompTime;   // Total time spent decompressing video
	u32 TotalAudioDecompTime;   // Total time spent decompressing audio

	u32 TotalIdleReadTime;      // Total time spent reading while idle
	u32 TotalBackReadTime;      // Total time spent reading in background
	u32 TotalReadSpeed;         // Total io speed (bytes/second)
	u32 SlowestFrameTime;       // Slowest single frame time (ms)
	u32 Slowest2FrameTime;      // Second slowest single frame time (ms)
	u32 SlowestFrameNum;        // Slowest single frame number
	u32 Slowest2FrameNum;       // Second slowest single frame number
	u32 AverageDataRate;        // Average data rate of the movie
	u32 AverageFrameSize;       // Average size of the frame
	u32 HighestMemAmount;       // Highest amount of memory allocated
	u32 TotalIOMemory;          // Total extra memory allocated
	u32 HighestIOUsed;          // Highest extra memory actually used
	u32 Highest1SecRate;        // Highest 1 second rate
	u32 Highest1SecFrame;       // Highest 1 second start frame
};

EXPORT i32 STDCALL BinkWait(HBINK);
EXPORT void STDCALL BinkClose(HBINK);
EXPORT void STDCALL BinkSetVolume(HBINK, i32);
EXPORT void STDCALL BinkSetPan(HBINK, i32);
EXPORT void STDCALL BinkSetSoundSystem(void (STDCALL *fptr)(void), LPDIRECTSOUND8);
EXPORT void STDCALL BinkOpenDirectSound(void);
EXPORT void STDCALL BinkSetIOSize(i32);
EXPORT i32 STDCALL BinkDDSurfaceType(LPDIRECTDRAWSURFACE7);
EXPORT HBINK STDCALL BinkOpen(void*, i32);
EXPORT void STDCALL BinkSetVideoOnOff(HBINK, i32);
EXPORT void STDCALL BinkGetSummary(HBINK, BINKSUMMARY*);

void validate_BINKSUMMARY(void);

#endif
