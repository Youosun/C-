#include "SocketUtil.h"
#include "TcpConnection.h"
#include "Acceptor.h"
#include "EpollPoller.h"
#include <iostream>
using std::cout;
using std::endl;

void onConnection(const SM::TcpConnectionPtr &conn)
{
	cout << conn->toString() << endl;
	conn->send("hello, welcome to Chat Server.\n");
}

void onMessage(const SM::TcpConnectionPtr &conn)
{
	std::string s(conn->receive());
	cout << "server: " << s << endl;
	conn->send(s);
}

void onClose(const SM::TcpConnectionPtr &conn)
{
	printf("%s close\n", conn->toString().c_str());
}

int main()
{
	SM::InetAddress addr("192.168.78.128", 6666);
	SM::Acceptor acceptor(SM::createSocketFd(), addr);
	acceptor.ready(true, true);

	SM::EpollPoller poller(acceptor);
	poller.setConnectionCallback(&onConnection);
	poller.setMessageCallback(&onMessage);
	poller.setCloseCallback(&onClose);

	poller.loop();

	return 0;
}
