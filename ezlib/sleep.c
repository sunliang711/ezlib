#include <sys/select.h>
#include "sleep.h"

int ez_sleep(uint32_t micro_sec)
{
    struct timeval tv;
    tv.tv_usec = micro_sec;

    select(0, NULL, NULL, NULL, &tv);

    return 0;
}