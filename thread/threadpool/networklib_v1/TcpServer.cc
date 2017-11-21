#include "TcpServer.h"
#include "SocketUtil.h"

namespace SM
{
TcpServer::TcpServer(const string & ip, unsigned short port)
: _acceptor(createSockFd(), InetAddress(ip.c_str(), port))
, _poller(_acceptor)
{}

void TcpServer::start()
{
	_acceptor.ready();
	_poller.setConnectionCallback(_connectionCallback);
	_poller.setMessageCallback(_messageCallback);
	_poller.setCloseCallback(_closeCallback);
	_poller.loop();
}

void TcpServer::stop()
{
	_poller.unloop();
}

void TcpServer::setConnectionCallback(TcpServerCallback cb)
{
	_connectionCallback = cb;
}

void TcpServer::setMessageCallback(TcpServerCallback cb)
{
	_messageCallback = cb;
}

void TcpServer::setCloseCallback(TcpServerCallback cb)
{
	_closeCallback = cb;
}

}
