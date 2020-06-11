#include <stdlib.h>
#include <string.h>
#include "memory.h"

void *malloc0(size_t size)
{
    void *loc = malloc(size);
    memset(loc, 0, size);
    return loc;
}