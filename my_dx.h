#ifndef MY_DX_H
#define MY_DX_H

#ifdef _WIN32

#define DIRECTINPUT_VERSION 0x0800
#define DIRECTSOUND_VERSION 0x0800
#define DIRECT3D_VERSION 0x0700

#include <d3d.h>
#include <d3dcaps.h>
#include <ddraw.h>
#include <basetsd.h>
#include <dinput.h>
#include <dsound.h>

#else

typedef i32 _DDPIXELFORMAT;
typedef i32 DDPIXELFORMAT;
typedef i32 DDSURFACEDESC2;
typedef DDSURFACEDESC2* LPDDSURFACEDESC2;
typedef i32 D3DDEVICEDESC7;
typedef i32 IDirectInputA;
typedef i32 IDirectDrawSurface7;
typedef void* DIDEVICEINSTANCEA;
typedef i32* LPDIRECTINPUTDEVICEA;
typedef i32* LPDIRECTINPUTDEVICE8A;
typedef i32 DIRECTINPUT8;
typedef DIRECTINPUT8* LPDIRECTINPUT8;
typedef i32 DIRECTSOUND8;
typedef DIRECTSOUND8* LPDIRECTSOUND8;
typedef void* LPDIRECTDRAWSURFACE7;
typedef void* LPDIRECTDRAW7;
typedef void* LPD3DDEVICEDESC7;
typedef void* LPDIRECTDRAWCLIPPER;
typedef void* LPDIRECT3D7;
typedef void* LPDDPIXELFORMAT;
typedef void* LPDIRECT3DDEVICE7;
typedef float D3DVALUE;
typedef u32 D3DCOLOR;
typedef i32 LONG;

struct DSCAPS
{
};

#endif

#endif
