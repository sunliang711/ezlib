#include <sys/select.h>
#include "common.h"
#include "sleep.h"

int ez_sleep(uint32_t micro_sec)
{
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = micro_sec;

    select(0, nullptr, nullptr, nullptr, &tv);

    return 0;
}