#pragma once

#ifndef MAIN_H
#define MAIN_H

#include "export.h"
class CClass
{
	public:

	EXPORT void * operator new(size_t size);
	EXPORT void operator delete(void*);
	EXPORT virtual ~CClass();
};

#endif
