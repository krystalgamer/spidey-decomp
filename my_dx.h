#ifndef MY_DX_H
#define MY_DX_H

#ifdef _WIN32

#define DIRECTINPUT_VERSION 0x0800

#include <d3d.h>
#include <d3dcaps.h>
#include <ddraw.h>
#include <basetsd.h>
#include <dinput.h>

#else

typedef i32 _DDPIXELFORMAT;
typedef i32 DDPIXELFORMAT;
typedef i32 DDSURFACEDESC2;
typedef i32 D3DDEVICEDESC7;
typedef i32 IDirectInputA;
typedef i32 IDirectDrawSurface7;
typedef void* DIDEVICEINSTANCEA;
typedef i32* LPDIRECTINPUTDEVICEA;

#endif

#endif
