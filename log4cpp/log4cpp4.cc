#include <iostream>
#include <string>
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>

using namespace std;
using std::ostringstream;
using namespace log4cpp;

int main(void)
{
	PatternLayout * ptnLyOut1 = new PatternLayout();
	ptnLyOut1->setConversionPattern("%d: [%7p] %m %n");

	PatternLayout * ptnLyOut2 = new PatternLayout();
	ptnLyOut2->setConversionPattern("%d: [%7p] %m %n");

	FileAppender * fAppender = new FileAppender("fileAppender","fAppender.log");
	fAppender->setLayout(ptnLyOut1);

	RollingFileAppender * rfAppender = new RollingFileAppender("rfAppender","rfAppender.log",5 * 1024, 1);
	rfAppender->setLayout(ptnLyOut2);

	Category & root = Category::getRoot().getInstance("rootname");

	root.setAppender(fAppender);
	root.setAppender(rfAppender);
	root.setPriority(Priority::DEBUG);

	for(size_t idx = 0; idx <= 100; ++idx)
	{
		string Errstr;
	
		ostringstream oss;
		oss << idx << "This is a error message";

		Errstr = oss.str();

		root.error(Errstr);
	}

	Category::shutdown();

	return 0;
}
