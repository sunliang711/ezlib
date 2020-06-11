#ifndef __RETURN__H__
#define __RETURN__H__

/*process related*/
#define CHILD_PID 0

/*file related*/
#define OPEN_ERROR -1
#define CLOSE_OK 0

/*errno == 0 ? EOF : ERROR*/
#define GETLINE_ERROR_OR_EOF -1
/*TODO*/



/*socket related*/
#define SOCKET_ERROR -1
#define BIND_OK 0
#define LISTEN_OK 0
#define ACCEPT_ERROR -1
#define CONNECT_OK 0
#define CONNECT_ERROR -1
#define INET_PTON_OK 1
#define INET_PTON_ERROR_ADDR 0
#define INET_PTON_ERROR_AF -1
#define SELECT_ERROR -1
#define EPOLL_ERROR -1
#define EPOLL_CTL_OK 0
#define EPOLL_CTL_ERROR -1
#define GETSOCKNAME_OK 0

/*pthread related*/
#define PTHREAD_CREATE_OK 0
#define PTHREAD_ATTR_INIT_OK 0
#define PTHREAD_ATTR_DESTROY_OK 0
#define PTHREAD_ATTR_SETDETACHSTATE_OK 0
/*TODO*/

#endif