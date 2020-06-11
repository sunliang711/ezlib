#include <pthread.h>
#include <sys/socket.h>
#ifdef __linux__
#include <sys/epoll.h>
#endif
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "socket_util.h"
#include "return.h"

#define MAX_LEN 255
static __thread char buf[MAX_LEN];

void must_sockaddr_init4(struct sockaddr_in *addr, int af, const char *ip, int port)
{
    bzero(addr, sizeof(struct sockaddr_in));
    addr->sin_family = af;
    must_inet_pton(AF_INET, ip, &addr->sin_addr);
    addr->sin_port = htons(port);
}

int must_socket(int domain, int type, int protocol)
{
    int fd;

    if ((fd = socket(domain, type, protocol)) < 0)
    {
        perror("socket()");
        exit(1);
    }
    return fd;
}

void must_bind(int fd, const struct sockaddr *addr, socklen_t len)
{
    int res;

    if ((res = bind(fd, addr, len)) != BIND_OK)
    {
        perror("bind()");
        exit(1);
    }
}

void must_listen(int fd, int backlog)
{
    int res;
    if ((res = listen(fd, backlog)) != LISTEN_OK)
    {
        perror("listen()");
        exit(1);
    }
}

int must_accept(int fd, struct sockaddr *addr, socklen_t *len)
{
    int connfd;

    if ((connfd = accept(fd, addr, len)) == ACCEPT_ERROR)
    {
        perror("accept()");
        exit(1);
    }
    return connfd;
}

void must_connect(int fd, const struct sockaddr *addr, socklen_t len)
{
    int res;

    if ((res = connect(fd, addr, len)) == CONNECT_ERROR)
    {
        perror("connect()");
        exit(1);
    }
}

void must_getsockname(int fd, struct sockaddr *addr, socklen_t *len)
{

    if (getsockname(fd, addr, len) != GETSOCKNAME_OK)
    {
        perror("getsockname()");
        exit(1);
    }
}

void must_inet_pton(int af, const char *src, void *dst)
{
    int res;

    res = inet_pton(af, src, dst);
    switch (res)
    {
    case INET_PTON_ERROR_ADDR:
        fprintf(stdout, "network address is invalid");
        exit(1);
        break;

    case INET_PTON_ERROR_AF:
        perror("inet_pton()");
        exit(1);
        break;

    case INET_PTON_OK:
        break;
    }
}

// thread-safe sock_ntop
char *
sock_ntop(const struct sockaddr *addr)
{
    char port_buf[8];
    switch (addr->sa_family)
    {
    case AF_INET:
    {
        struct sockaddr_in *addr4 = (struct sockaddr_in *)addr;
        const char *ptr = inet_ntop(AF_INET, &addr4->sin_addr, buf, sizeof(buf));
        if (!ptr)
        {
            return NULL;
        }
        snprintf(port_buf, sizeof(port_buf), ":%d", ntohs(addr4->sin_port));
        strcat(buf, port_buf);
        return buf;
    }
    case AF_INET6:
        // TODO
        return NULL;
    default:
        return NULL;
    }
}

#ifdef __linux__
int must_epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout)
{
    int event_count;

    if ((event_count = epoll_wait(epfd, events, maxevents, timeout)) == -1)
    {
        perror("epoll_wait()");
        exit(1);
    }
    return event_count;
}
#endif
