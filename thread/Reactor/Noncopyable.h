#ifndef _SM_NONCOPYABLE_H__
#define _SM_NONCOPYABLE_H__

namespace SM
{
class Noncopyable
{
public:
	Noncopyable()
	{}
	~Noncopyable()
	{}
private:
	Noncopyable & operator=(const Noncopyable &);
	Noncopyable(const Noncopyable &);
};


}




#endif
