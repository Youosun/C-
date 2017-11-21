#include <iostream>
#include <log4cpp/Priority.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>

using namespace std;
using std::ostringstream;

class GC;
class Mylog
{
public:
	static Mylog * getInstance()
	{
		if(_mlog == NULL)
		{
			_mlog = new Mylog();
		}
		return _mlog;
	}

	void log_err(const char * mesg)
	{
		ostringstream oss;
		oss << mesg << "[" << __FILE__ << "]"
					<< "[" << __FUNCTION__ << "]"
					<< "[" << __LINE__ << "]";
		_root.error(oss.str());
	}


	void log_fatal(const char * mesg)
	{
		ostringstream oss;
		oss << mesg << "[" << __FILE__ << "]"
					<< "[" << __FUNCTION__ << "]"
					<< "[" << __LINE__ << "]";
		_root.fatal(oss.str());
	}

	void log_warn(const char * mesg)
	{
		ostringstream oss;
		oss << mesg << "[" << __FILE__ << "]"
					<< "[" << __FUNCTION__ << "]"
					<< "[" << __LINE__ << "]";
		_root.warn(oss.str());
	}


	void log_debug(const char * mesg)
	{
		ostringstream oss;
		oss << mesg << "[" << __FILE__ << "]"
					<< "[" << __FUNCTION__ << "]"
					<< "[" << __LINE__ << "]";
		_root.debug(oss.str());
	}

	void info(const char * mesg)
	{
		ostringstream oss;
		oss << mesg << "[" << __FILE__ << "]"
					<< "[" << __FUNCTION__ << "]"
					<< "[" << __LINE__ << "]";
		_root.info(oss.str());
	}

	static void destory()
	{
		_mlog->info("Destroy");
		_mlog->_root.shutdown();
	}

	
private:
	Mylog()
	: _root(log4cpp::Category::getRoot())
	{
		log4cpp::PatternLayout * plyout1 = new log4cpp::PatternLayout();
		log4cpp::PatternLayout * plyout2 = new log4cpp::PatternLayout();
		plyout1->setConversionPattern("%d:[%7p] %m %n");
		plyout2->setConversionPattern("%d:[%7p] %m %n");

		log4cpp::RollingFileAppender * rfAppender = new log4cpp::RollingFileAppender("rfAppender", "my.log", 5 * 1024, 1); 
		rfAppender->setLayout(plyout1);

		log4cpp::OstreamAppender * OsAppender = new log4cpp::OstreamAppender("OsAppender" , &cout);
		OsAppender->setLayout(plyout2);

		_root.setPriority(log4cpp::Priority::DEBUG);
		_root.addAppender(rfAppender);
		_root.addAppender(OsAppender);
	}

	static Mylog * _mlog;
	log4cpp::Category & _root;

	class GC
	{
	public:
		GC()
		{
		}
		
		~GC()
		{
			if(Mylog::_mlog != NULL)
			{
				delete Mylog::_mlog;
				Mylog::_mlog = NULL;
			}
		}
	};

	static GC gc;
};

Mylog * Mylog::_mlog = NULL;
Mylog::GC Mylog::gc;

int main(void)
{
	Mylog * pml = Mylog::getInstance();

	pml->log_err("message");

	return 0;
}

