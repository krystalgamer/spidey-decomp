#pragma once

#ifndef STATEFLAGS_H
#define STATEFLAGS_H

struct SStateFlags{
	union {
		__int16 flags[2];
		int bothFlags;
	};
};


#endif

