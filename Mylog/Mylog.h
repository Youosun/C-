 ///
 /// @file    Mylog.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-27 10:33:59
 ///
 
#ifndef __WD_MYLOG_H__
#define __WD_MYLOG_H__

#include <log4cpp/Category.hh>

#include <string>
#include <sstream>

using std::string;
using std::ostringstream;

class Mylog
{
public:
	static Mylog * getInstance();
	static void destroy();
	
	void warn(const char * msg);
	void info(const char * msg);
	void error(const char * msg);
	void debug(const char * msg);

private:
	Mylog();
	~Mylog();
private:
	static Mylog * _pInstance;
	log4cpp::Category & _root;
};

inline string int2str(int number)
{
	ostringstream oss;
	oss << number;
	return oss.str();
}

#define prefix(msg)	string("[").append(__FILE__)\
					.append(":").append(__FUNCTION__)\
					.append(":").append(int2str(__LINE__))\
					.append("] ").append(msg).c_str()


#define LogInfo(msg) Mylog::getInstance()->info(prefix(msg))
#define LogWarn(msg) Mylog::getInstance()->warn(prefix(msg))
#define LogError(msg) Mylog::getInstance()->error(prefix(msg))
#define LogDebug(msg) Mylog::getInstance()->debug(prefix(msg))

#endif
