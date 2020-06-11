#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include "readline.h"

#define MAX 255
static char linebuf[MAX];
static size_t index;
static char left;

ssize_t read1(int fd, char *c)
{
    int nread;
    if (left == 0)
    {
    again:
        nread = read(fd, linebuf, sizeof(linebuf));
        if (nread < 0)
        {
            if (errno == EINTR)
            {
                goto again;
            }
            return -1;
        }
        else if (nread == 0)
        {
            return 0;
        }
        left = nread;
        index = 0;
    }
    *c = linebuf[index++];
    left--;
    return 1;
}

ssize_t readline(int fd, void *buf, size_t n)
{
    int res;
    char c;
    char *ptr = buf;
    size_t i;
    for (i = 0; i < n; i++)
    {
        res = read1(fd, &c);
        if (res < 0)
        {
            return -1;
        }
        else if (res == 1)
        {
            ptr[i] = c;
            if (c == '\n')
            {
                i++;
                break;
            }
        }
        else
        {
            break;
        }
    }
    if (i < n)
    {
        ptr[i] = '\0';
    }
    return i;
}