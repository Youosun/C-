#include <iostream>
#include <log4cpp/Priority.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/BasicLayout.hh>

using namespace std;

int main(void)
{
	log4cpp::PatternLayout * plyout = new log4cpp::PatternLayout();
	plyout->setConversionPattern("%d:[%7p] %m %n");

	log4cpp::OstreamAppender * OsAppender1 = new log4cpp::OstreamAppender("OsAppender1", &cout);
	OsAppender1->setLayout(plyout);

	log4cpp::OstreamAppender * OsAppender2 = new log4cpp::OstreamAppender("OsAppender2", &cout);
	OsAppender2->setLayout(new log4cpp::BasicLayout());

	log4cpp::Category & root = log4cpp::Category::getRoot();

	root.setPriority(log4cpp::Priority::DEBUG);

	log4cpp::Category & sub1 = root.getInstance("sub1");
	sub1.setAppender(OsAppender1);
	sub1.setPriority(log4cpp::Priority::DEBUG);
	sub1.error("This is a sub1 error message");

	log4cpp::Category & sub2 = root.getInstance("sub2");
	sub2.setAppender(OsAppender2);
	sub2.setPriority(101);
	sub2.warn("This is a sub2 warning message");
	sub2.error("This is a sub2 error message");
	sub2.fatal("This is a sub2 fatal message");
	sub2.alert("This is a sub2 alert message");
	sub2.crit("This is a sub2 crit message");

	return 0;
}
