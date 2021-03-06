#include "JKernel/JKRHeap.h"
#include "JUtility/JUTException.h"

JKRHeap* JKRHeap::becomeSystemHeap()
{
    JKRHeap* pInstance = this;
    JKRHeap* pCurSystemHeap = JKRHeap::sSystemHeap;
    JKRHeap::sSystemHeap = pInstance;
    return pCurSystemHeap;
}

JKRHeap* JKRHeap::becomeCurrentHeap()
{
    JKRHeap* pInstance = this;
    JKRHeap* pCurHeap = JKRHeap::sCurrentHeap;
    JKRHeap::sCurrentHeap = pInstance;
    return pCurHeap;
}

void JKRHeap::destroy(JKRHeap *pHeap)
{
    do_destroy();
}

void* JKRHeap::alloc(u32 a1, s32 a2, JKRHeap *pHeap)
{
    if (pHeap != 0)
    {
        return pHeap->alloc(a1, a2);
    }

    JKRHeap *pCurHeap = JKRHeap::sCurrentHeap;

    if (pCurHeap != 0)
    {
        return pCurHeap->alloc(a1, a2);
    }

    return 0;
}

JKRHeap* JKRHeap::alloc(u32 a1, s32 a2)
{
    return do_alloc(a1, a2);
}

void JKRHeap::free(void *pSrc, JKRHeap *pHeap)
{
    if (pHeap == 0)
    {
        pHeap = JKRHeap::findFromRoot(pSrc);

        if (pHeap == 0)
        {
            return;
        }
    }

    pHeap->do_free(pSrc);
}

void JKRHeap::free(void *pSrc)
{
    do_free(pSrc);
}

void JKRHeap::freeAll()
{
    do_freeAll();
}

void JKRHeap::freeTail()
{
    do_freeTail();
}

void JKRHeap::resize(void *pSrc, u32 a2)
{
    do_resize(pSrc, a2);
}

void JKRHeap::copyMemory(void *pDest, void *pSrc, u32 len)
{
    __asm
    {
        addi r0, r5, 3
        srwi. r0, r0, 2
        mtctr r0
        beqlr

    loop:
        lwz r0, 0(r4)
        addi r4, r4, 4
        stw r0, 0(r3)
        addi r3, r3, 4
        bdnz loop
        blr
    }
}

void JKRDefaultMemoryErrorRoutine(void *mSrc, u32 a2, s32 a3)
{
    JUTException::panic_f("JKRHeap.cpp", 0x355, "%s", "abort\n");
}

void* JKRHeap::setErrorHandler(void (*err)(void *, u32, s32))
{
    if (err == 0)
    {
        err = (void (*)(void *, u32, s32))(*JKRDefaultMemoryErrorRoutine);
    }

    void *pCurErrHandler = JKRHeap::sErrorHandler;
    JKRHeap::sErrorHandler = err;
    return pCurErrHandler;
}