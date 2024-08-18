#ifndef PKR_H
#define PKR_H

#pragma once

#include "export.h"


EXPORT u8 fileCRCCheck(u8*, i32, u32);
EXPORT void PKR_ReportError(const char*, ...);


#endif
