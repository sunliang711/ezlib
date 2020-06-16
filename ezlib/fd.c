#include "fd.h"

int make_fd_nonblock(int fd)
{
    int flags;
    int res;

    if ((flags = fcntl(fd, F_GETFL, 0)) == -1)
    {
        return -1;
    }

    if ((res = fcntl(fd, F_SETFL, flags | O_NONBLOCK)) != -1)
    {
        // return old flags when success
        return flags;
    }
    else
    {
        return -1;
    }
}