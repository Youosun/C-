#ifndef _SM_SOCKETUTIL_H__
#define _SM_SOCKETUTIL_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/eventfd.h>
#include <sys/epoll.h>

namespace SM
{
inline int createSockFd()
{
	int fd = ::socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == fd)
	{
		perror("socket create error!");
	}
	return fd;
}

inline void setNonblock(int fd)
{
	int flags = ::fcntl(fd, F_GETFL, 0);
	flags |= O_NONBLOCK;
	::fcntl(fd, F_SETFL, flags);
}

inline int createEpollFd()
{
	int epfd = ::epoll_create1(0);
	if(-1 == epfd)
	{
		perror("epoll_create1 error!");
		exit(EXIT_FAILURE);
	}
	return epfd;
}

inline int creatEventFd()
{
	int evfd = ::eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC);
	if(-1 == evfd)
	{
		perror("eventfd create error");
	}
	return evfd;
}

inline void addEpollFdRead(int efd, int fd)
{
	struct epoll_event ev;
	ev.data.fd = fd;
	ev.events = EPOLLIN;
	int ret = epoll_ctl(efd, EPOLL_CTL_ADD, fd, &ev);
	if(-1 == ret)
	{
		perror("add epollfd error");
		exit(EXIT_FAILURE);
	}
}

inline void delEpollReadFd(int efd, int fd)
{
	struct epoll_event ev;
	ev.data.fd = fd;
	int ret = epoll_ctl(efd, EPOLL_CTL_DEL, fd, &ev);
	if(-1 == ret)
	{
		perror("delete epollfd error");
		exit(EXIT_FAILURE);
	}
}

inline size_t recvPeek(int sockfd, void * buf, size_t len)
{
	int nread;
	do
	{
		nread = ::recv(sockfd, buf, len, MSG_PEEK);
	}while(nread == -1 && errno == EINTR);
	return nread;
}

inline bool isConnectionClosed(int sockfd)
{
	char buf[1024];
	int nread = recvPeek(sockfd, buf, sizeof(buf));
	if(-1 == nread)
	{
		perror("recvPeek---");
		return true;
	}
	return (0 == nread);
}

}//end of namespace SM

#endif
