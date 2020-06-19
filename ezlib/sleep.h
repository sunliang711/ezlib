#ifndef __SLEEP_H__
#define __SLEEP_H__
#include <stdint.h>
#include <errno.h>

// int ez_sleep(uint32_t micro_sec);
typedef enum
{
    EZ_SEC,
    EZ_MS,
    EZ_US
} ez_time_unit;

int ez_sleep(ez_time_unit unit, uint32_t val);

int ez_sleep_sec(uint32_t val);

int ez_sleep_ms(uint32_t val);

int ez_sleep_us(uint32_t val);

#endif