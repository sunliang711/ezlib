#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include "readn.h"

ssize_t readn(int fd, void *buf, size_t n)
{
    char *ptr = buf;
    size_t nleft = n;
    ssize_t nread;

    while (nleft > 0)
    {
        if ((nread = read(fd, ptr, nleft)) < 0)
        {
            if (errno == EINTR)
            {
                nread = 0;
            }
            return -1;
        }
        // 读取0，表示遇到EOF
        else if (nread == 0)
        {
            break;
        }

        ptr += nread;
        nleft -= nread;
    }
    return n - nleft;
}