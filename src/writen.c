#include <sys/types.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "writen.h"

ssize_t writen(int fd, void *buf, size_t n)
{
    char *ptr = buf;
    size_t nleft = n;
    ssize_t nwrite;

    while (nleft > 0)
    {
        // 写入0 属于错误情况
        if ((nwrite = write(fd, ptr, nleft)) <= 0)
        {
            if (nwrite < 0 && errno == EINTR)
            {
                nwrite = 0;
            }
            return -1;
        }
        ptr += nwrite;
        nleft -= nwrite;
    }
    return n;
}