#include "TcpServer.h"
#include "Threadpool.h"
#include <iostream>
using std::cout;
using std::endl;

SM::Threadpool * pThreadpool = NULL;

class Task
{
public:
	Task(const std::string & query, SM::TcpConnectionPtr conn)
	: _query(query)
	, _conn(conn)
	{}

	void process()
	{
		//...处理业务逻辑
		//_conn->send(_query)
		//回显发送成功, 相当于在计算线程里做了IO线程数据发送的工作, 这是一个错误的做法
		//正确的做法:需要将数据传递给IO线程,再由IO线程进行发送数据的工作
		//(涉及到的问题是由计算线程通知IO线程)
		_conn->sendInLoop(_query);  //将处理过后的string发送到Loop中, 由IO线程去发送
	}

private:
	std::string _query;
	SM::TcpConnectionPtr _conn;
};

void onConnection(const SM::TcpConnectionPtr &conn)
{
	cout << conn->toString() << endl;
	conn->send("hello, welcome to char server.\r\n");
}

void onMessage(const SM::TcpConnectionPtr &conn)
{
	std::string s(conn->receive());

	Task task(s, conn);
	pThreadpool->addTask(std::bind(&Task::process, task));
}

void onClose(const SM::TcpConnectionPtr & conn)
{
	printf("%s close\n", conn->toString().c_str());
}

int main(void)
{
	SM::Threadpool threadpool(4, 10);
	threadpool.start();

	pThreadpool = & threadpool;

	SM::TcpServer tcpserver("192.168.78.128", 6666);
	tcpserver.setConnectionCallback(&onConnection);
	tcpserver.setMessageCallback(&onMessage);
	tcpserver.setCloseCallback(&onClose);

	tcpserver.start();

	return 0;
}
