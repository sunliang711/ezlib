#include <sys/select.h>
#include "common.h"
#include "sleep.h"

int ez_sleep(ez_time_unit unit, uint32_t val)
{
    int err;
    struct timeval tv;
    switch (unit)
    {
    case EZ_SEC:
        tv.tv_sec = val;
        tv.tv_usec = 0;
        break;
    case EZ_MS:
        tv.tv_sec = val / 1000;
        tv.tv_usec = (val % 1000) * 1000;
        break;
    case EZ_US:
        tv.tv_sec = val / 1000000;
        tv.tv_usec = val % 1000000;
        break;
    }

    do
    {
        err = select(0, nullptr, nullptr, nullptr, &tv);
    } while (err < 0 && errno == EINTR);

    return 0;
}
int ez_sleep_sec(uint32_t val)
{
    return ez_sleep(EZ_SEC, val);
}

int ez_sleep_ms(uint32_t val)
{
    return ez_sleep(EZ_MS, val);
}

int ez_sleep_us(uint32_t val)
{
    return ez_sleep(EZ_US, val);
}