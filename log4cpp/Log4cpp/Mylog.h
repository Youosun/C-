#ifndef __LOG4CPP_MYLOG_H__
#define __LOG4CPP_MYLOG_H__

#include <log4cpp/Category.hh>
#include <iostream>

using namespace std;

class Mylog
{
public:
	static Mylog * getInstance();

	static void destroy();

	void err(const char * msg);

	void fatal(const char * msg);

	void warn(const char * msg);

	void debug(const char * msg);

	void info(const char * msg);

private:
	Mylog();
	~Mylog();

	static Mylog * _pInstance;
	log4cpp::Category & _root;
};


#endif
