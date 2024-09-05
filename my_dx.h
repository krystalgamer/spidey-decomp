#ifndef MY_DX_H
#define MY_DX_H

#ifdef _WIN32

#include <d3d.h>
#include <d3dcaps.h>
#include <ddraw.h>

#else

typedef i32 DDPIXELFORMAT;
typedef i32 DDSURFACEDESC2;
typedef i32 D3DDEVICEDESC7;

#endif

#endif
