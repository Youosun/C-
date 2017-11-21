 ///
 /// @file    Mylog.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-27 09:42:03
 ///


#include "Mylog.h"

#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>

#include <iostream>
using std::cout;

Mylog * Mylog::_pInstance = NULL;

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
	if(_pInstance)
		delete _pInstance;
}

Mylog::Mylog()
: _root(log4cpp::Category::getRoot())
{
	log4cpp::PatternLayout * ptnLayout1 = new log4cpp::PatternLayout();
	ptnLayout1->setConversionPattern("%d: [%p]: %m%n");

	log4cpp::PatternLayout * ptnLayout2 = new log4cpp::PatternLayout();
	ptnLayout2->setConversionPattern("%d: [%p]: %m%n");

	log4cpp::OstreamAppender * osAppender = new log4cpp::OstreamAppender("osAppender", &cout);
	osAppender->setLayout(ptnLayout1);
	
	log4cpp::FileAppender * fileAppender = new log4cpp::FileAppender("fileAppender", "wd.log");
	fileAppender->setLayout(ptnLayout2);
	
	_root.addAppender(osAppender);
	_root.addAppender(fileAppender);
	_root.setPriority(log4cpp::Priority::DEBUG);
}

Mylog::~Mylog()
{
	log4cpp::Category::shutdown();
}

void Mylog::warn(const char * msg)
{
	_root.warn(msg);
}

void Mylog::info(const char * msg)
{
	_root.info(msg);
}

void Mylog::error(const char * msg)
{
	_root.error(msg);
}

void Mylog::debug(const char * msg)
{
	_root.debug(msg);
}

