#pragma once

#ifndef IMAGE_H
#define IMAGE_H

#include "export.h"
#include "main.h"

#pragma pack(push, 1)
struct BMPHeader
{
	u16  type;             // Magic identifier: 0x4d42
	u32  size;             // File size in bytes
	u16  reserved1;        // Not used
	u16  reserved2;        // Not used
	u32  offset;           // Offset to image data in bytes from beginning of file (54 bytes)
	u32  dib_header_size;  // DIB Header size in bytes (40 bytes)
	i32  width_px;         // Width of the image
	i32  height_px;        // Height of image
	u16  num_planes;       // Number of color planes
	u16  bits_per_pixel;   // Bits per pixel
	u32  compression;      // Compression type
	u32  image_size_bytes; // Image size in bytes
	i32  x_resolution_ppm; // Pixels per meter
	i32  y_resolution_ppm; // Pixels per meter
	u32  num_colors;       // Number of colors  
	u32  important_colors; // Important colors 
};
#pragma pack(pop)

class Image : public CClass
{
	public:
		EXPORT Image(void);
		EXPORT ~Image(void);
		u8 field_4;
		u8 Shaded;
		u8 field_6;
		u8 field_7;
		u8 field_8;
		u8 field_9;
		u8 field_A;
		u8 field_B;
		u32 field_C;
};

class SlicedImage2 : public Image
{
	public:
		EXPORT SlicedImage2(void);
		EXPORT SlicedImage2(void*, i32, i32, i32, i32, u8, u16, u32);

		EXPORT ~SlicedImage2(void);
		EXPORT i32 screenHeight(void);

		EXPORT virtual void UnknownSlicedImageVirtualFunc(void);
		EXPORT virtual void setData(void*);
		EXPORT virtual void draw(i32, i32, i32, float);

		EXPORT void pack(void);
		EXPORT void removeFromMemory(void);

		u32 field_10;

		i16 field_14;
		i16 field_16;
		i32 field_18;
		u8 field_1C;

		PADDING(1);

		u16 field_1E;
};

EXPORT i32 Load8BitBMP_2(char *, char **, i32 *, i32 *, u16*);
EXPORT i32 Load8BitBMP2(char *, char **, i32 *, i32 *, u16*, bool);
EXPORT i32 GetBMPBitDepth(char *);
EXPORT void Load4BitBMP_2(char *,char **,i32 *,i32 *,u16 *);
EXPORT i32 LoadNBitBMP_(const char *,char **,i32 *,i32 *,u16 *,i32 *);

EXPORT extern u16 gSlicedImageRelated[256];

void validate_Image(void);
void validate_SlicedImage2(void);
void validate_BmpHeader(void);
void validate_Load8BitBMP2(void);
#endif
