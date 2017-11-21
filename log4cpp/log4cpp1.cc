#include <iostream>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>

using namespace std;

int main(void)
{
	log4cpp::OstreamAppender * pOsAppender = new log4cpp::OstreamAppender("osAppender", &cout);

	pOsAppender-> setLayout(new log4cpp::BasicLayout());

	log4cpp::Category & root = log4cpp::Category::getRoot();

	root.addAppender(pOsAppender);

	root.setPriority(log4cpp::Priority::DEBUG);

	root.error("This is a error message");
	root.warn("This is a warning message");

	log4cpp::Category::shutdown();

	return 0;
}
