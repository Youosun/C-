#ifndef _SM_ACCEPTOR_H__
#define _SM_ACCEPTOR_H__

#include "Socket.h"
#include "InetAddress.h"

namespace SM
{
class Acceptor
{
public:
	Acceptor(int listenfd, const InetAddress & addr);
	void ready(bool RAddr, bool RPort);
	int accept();

	int fd()const
	{
		return _listenSock.fd();
	}
private:
	void setReuseAddr(bool on);
	void setReusePort(bool on);
	void bind();
	void listen();

private:
	Socket _listenSock;
	InetAddress _addr;
};

}

#endif
