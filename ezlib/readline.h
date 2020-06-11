#ifndef __READLINE_H__
#define __READLINE_H__

#include <sys/types.h>

ssize_t readline(int fd,void * buf,size_t n);

#endif