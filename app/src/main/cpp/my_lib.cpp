#include "my_lib.h"

void *
memcpy_chk (void *dstpp, const void *srcpp, size_t len, size_t dstlen)
{
    return memcpy (dstpp, srcpp, len);
}

void* (*__memcpy_chk)(void *dstpp, const void *srcpp, size_t len, size_t dstlen)=memcpy_chk;

