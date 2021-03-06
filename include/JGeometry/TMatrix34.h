#pragma once

#include "JGeometry/TVec3.h"
#include <revolution/mtx.h>

namespace JGeometry
{
    template<class T>
    class TMatrix34
    {
    public:
        void identity();
        void mult(const JGeometry::TVec3<f32> &, JGeometry::TVec3<f32> &);
        void concat(const T &);

        operator Mtx*() { return reinterpret_cast<Mtx*>(this); }
    
        T val[3][4];
    };
    
    template<typename T>
    class SMatrix34C
    {
    public:
        /* empty */
    };
};