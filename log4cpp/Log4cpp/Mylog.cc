#include "Mylog.h"
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <sstream>
#include <iostream>
#include <string>

Mylog * Mylog::_pInstance = NULL;

Mylog::Mylog()
: _root(log4cpp::Category::getRoot())
{
		log4cpp::PatternLayout * ptLyt1 = new log4cpp::PatternLayout();
		ptLyt1->setConversionPattern("%d: [%p]: %m %n");

		log4cpp::PatternLayout * ptLyt2 = new log4cpp::PatternLayout();
		ptLyt2->setConversionPattern("%d: [%p]: %m %n");

		log4cpp::OstreamAppender * OsAppender = new log4cpp::OstreamAppender("OsAppender", &cout);
		OsAppender->setLayout(ptLyt1);

		log4cpp::FileAppender *fAppender = new log4cpp::FileAppender("fAppender", "Mylog");
		fAppender->setLayout(ptLyt2);

		_root.addAppender(OsAppender);
		_root.addAppender(fAppender);
		_root.setPriority(log4cpp::Priority::DEBUG);
}

Mylog::~Mylog()
{
	log4cpp::Category::shutdown();
}

Mylog * Mylog::getInstance()
{
	if(NULL == _pInstance)
	{
		_pInstance = new Mylog();
	}
	return _pInstance;
}

void Mylog::destroy()
{
	delete _pInstance;
	_pInstance = NULL;
}

void Mylog::err(const char * mesg)
{
	_root.error(mesg);	
}

void Mylog::info(const char * mesg)
{
	_root.info(mesg);
}

void Mylog::fatal(const char * mesg)
{
	_root.fatal(mesg);
}

void Mylog::debug(const char * mesg)
{
	_root.debug(mesg);
}

void Mylog::warn(const char * mesg)
{
	_root.warn(mesg);
}
