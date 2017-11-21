#include "SocketUtil.h"
#include "SocketIO.h"
#include "Socket.h"
#include "Acceptor.h"
#include "InetAddress.h"
#include "TcpConnection.h"

#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

int main()
{
	SM::InetAddress addr("192.168.79.128", 9999);
	SM::Acceptor acceptor(SM::createSocketFd(), addr);
	acceptor.ready();

	int peerfd = acceptor.accept();
	SM::TcpConnection conn(peerfd);
	conn.send("welcome to chat server!");

	while(1)\
	{
		string msg = conn.receive();
		cout << "server recieve: " << msg << endl;
		conn.send(msg);
	}
	return 0;
}
