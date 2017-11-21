#include <iostream>
#include <queue>
#include <string>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/StringQueueAppender.hh>

using namespace std;

int main(void)
{
	log4cpp::PatternLayout * pLyout = new log4cpp::PatternLayout();
	pLyout->setConversionPattern("%d: [%7p] %m %n");

	log4cpp::StringQueueAppender * strQAppender = new log4cpp::StringQueueAppender("strQAppender");

	log4cpp::Category & root = log4cpp::Category::getRoot();

	root.addAppender(strQAppender);
	root.setPriority(log4cpp::Priority::DEBUG);

	root.warn("This is a warning message");
	root.error("This is a error message");
	
	cout << "Get message from message Queue" << endl;

	queue<string> & mystr = strQAppender->getQueue();

	while(!mystr.empty())
	{
		cout << mystr.front();
		mystr.pop();
	}

	return 0;
}
