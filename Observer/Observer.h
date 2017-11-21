#ifndef _OBSERVER_H__
#define _OBSERVER_H__

#include <list>
using namespace std;

class Observer;
typedef int State;

class Subject
{
public:
	void attach(Observer * observer);
	void detach(Observer * observer);
	void notify();

	virtual State getState()const =0;
	virtual void setState(State)=0;

	virtual ~Subject(){
	}

protected:
	list<Observer *> _listObservers;
};

class ConcreteSubject
: public Subject
{
public: 
	ConcreteSubject()
	: _subState(-1)
	{}

	void setState(State state);
	State getState() const;

private:
	State _subState;

};

class Observer
{
public:
	virtual void update(Subject * subject)=0;
	virtual ~Observer(){}
};

class ConcreteObserver
: public Observer
{
public:
	ConcreteObserver()
	: _observerState(-1)
	{}

	void update(Subject * subject);
private:
	State _observerState;
};

#endif
