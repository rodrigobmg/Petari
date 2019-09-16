#ifndef GDBASE_H
#define GDBASE_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GDLObj 
{
    u8* mStart; // _0
    u32 mLength; // _4
    u8* mPtr; // _8
    u8* mTop; // _C
};

extern GDLObj*__GDCurrentDL;

void GDInitGDLObj(GDLObj *, void *, u32);

void GDPadCurr32();

#ifdef __cplusplus
}
#endif

#endif // GDBASE_H