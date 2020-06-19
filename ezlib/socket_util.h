#ifndef __SOCKET_UTIL_H__
#define __SOCKET_UTIL_H__

#include <netinet/in.h>
#ifdef __linux__
#include <sys/epoll.h>
#endif

#define SA struct sockaddr

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

int ez_epoll_add(int epfd,int fd,uint32_t events);
int ez_epoll_del(int epfd,int fd,uint32_t events);
int ez_epoll_mod(int epfd,int fd,uint32_t events);

#define FOREVER_POLL -1
#define FOREVER_SELECT NULL
#define FOREVER_EPOLL -1

typedef enum
{
    ipv4,
    ipv6
} ipversion;

/*
* tcp_server_init creates a listener socket bind to (ipaddress,port)
* @param ver: ip protocol version, ipv4 or ipv6
* @param ipaddress: listening ip address
* @param port: listening port
* @param backlog: lisiten backlog
* @param reuse_addr: enable or disable SO_REUSEADDR option
* @param nonblock: enable or disable nonblock of listening fd
* @return: listening fd on success,-1 on error
*/
int tcp_server_init(ipversion ver, const char *ipaddress, short port, int backlog, int reuse_addr,int nonblock);
/*
* tcp_client_init creates a client socket connected to (serverip,port)
* @param ver: ipversion, ipv4 or ipv6
* @param serverip: server ip address;
* @param port: server port
* @param nonblock: enable or disable nonblock fd
* @return: connected fd on success,-1 on error
*/
int tcp_client_init(ipversion ver, const char *serverip, short port,int nonblock);
#endif
