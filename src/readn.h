#ifndef __READ_N_H__
#define __READ_N_H__

#include <sys/types.h>

ssize_t readn(int fd, void *buf, size_t n);

#endif