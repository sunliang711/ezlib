#ifndef __SOCKET_UTIL_H__
#define __SOCKET_UTIL_H__

#include <netinet/in.h>
#ifdef __linux__
#include <sys/epoll.h>
#endif
// thread-safe sock_ntop
char* sock_ntop(const struct sockaddr* addr);

// #define mem0(buf) bzero((buf),sizeof((buf)))

/*socket with error check*/
// int Socket(int domain,int type,int protocol);

void must_sockaddr_init4(struct sockaddr_in *addr, int af, const char *ip, int port);

int must_socket(int domain, int type, int protocol);

void must_bind(int fd, const struct sockaddr *addr, socklen_t len);

void must_listen(int fd, int backlog);

void must_connect(int fd, const struct sockaddr *addr, socklen_t len);

void must_inet_pton(int af, const char *src, void *dst);

void must_getsockname(int fd, struct sockaddr *addr, socklen_t *len);

#ifdef __linux__
int must_epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);
#endif


#define FOREVER_POLL -1
#define FOREVER_SELECT NULL
#define FOREVER_EPOLL -1

#endif
