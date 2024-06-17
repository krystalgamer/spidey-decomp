#pragma once

#ifndef STATEFLAGS_H
#define STATEFLAGS_H

#include "my_types.h"

struct SStateFlags{
	union {
		i16 flags[2];
		i32 bothFlags;
	};
};


#endif

