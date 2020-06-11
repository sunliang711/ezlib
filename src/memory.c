#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "memory.h"

void *malloc0(size_t size)
{
    void *loc = malloc(size);
    if (loc != nullptr)
    {
        memset(loc, 0, size);
    }
    return loc;
}