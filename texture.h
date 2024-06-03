#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

// @TODO go to types.h
struct Texture
{
	unsigned char field_0;
	unsigned char field_1;
	unsigned char padAfter1[0x4-0x1-1];

	int field_4;
	unsigned char padAfter4[0x9-0x4-4];

	unsigned char field_9;
};

#endif
