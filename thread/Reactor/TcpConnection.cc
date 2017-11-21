#include "TcpConnection.h"
#include <string.h>
#include <string>
#include <stdio.h>

namespace SM
{
TcpConnection::TcpConnection(int sockfd)
: _sockfd(sockfd)
, _sockIO(sockfd)
, _localAddr(SM::Socket::getLocalAddr(sockfd))
, _peerAddr(SM::Socket::getPeerAddr(sockfd))
, _isShutdownWrite(false)
{}

TcpConnection::~TcpConnection()
{
	if(!_isShutdownWrite)
	{
		_isShutdownWrite = true;
		shutdown();
	}
	printf("~TcpConnection()\n");
}

std::string TcpConnection::receive()
{
	char buf[65536];
	::memset(buf, 0, sizeof(buf));
	size_t ret = _sockIO.readline(buf, sizeof(buf));
	if(0 == ret)
	{
		return std::string();
	}
	else
		return std::string(buf);
}

void TcpConnection::send(const std::string & msg)
{
	_sockIO.writen(msg.c_str(), msg.size());
}

void TcpConnection::shutdown()
{
	if(!_isShutdownWrite)
		_sockfd.shutdownWrite();
	_isShutdownWrite = true;
}

std::string TcpConnection::toString()
{
	char str[100];
	snprintf(str, sizeof(str), "%s:%d -> %s:%d",
			 _localAddr.ip().c_str(),
			 _localAddr.port(),
			 _peerAddr.ip().c_str(),
			 _peerAddr.port());
	return std::string(str);
}

} //end of namespace SM
