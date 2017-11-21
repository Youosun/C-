#include "Observer.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Subject::attach(Observer * observer)
{
	auto iter = std::find(_listObservers.begin(), _listObservers.end(), observer);
	if(iter == _listObservers.end())
		_listObservers.push_back(observer);
}

void Subject::detach(Observer * observer)
{
	auto iter = std::find(_listObservers.begin(), _listObservers.end(), observer);
	if(iter != _listObservers.end())
		_listObservers.erase(iter);
}

void Subject::notify()
{
	cout << "notify all the observers" << endl;
	for(auto iter = _listObservers.begin(); iter != _listObservers.end(); ++iter)
	{
		(*iter)->update(this);   //observer更新状态
	}
}

void ConcreteSubject::setState(State state)
{
	_subState = state;
	notify();
}

State ConcreteSubject::getState()const
{
	return _subState;
}

//如果传递的就是状态本身时,称之为推模式 -- 观察者是被动的
//void ConcreteObserver::update(State state)
//
//如果传递的是指针或者是引用.称之为拉模式 -- 观察者是主动的
void ConcreteObserver::update(Subject * subject)
{
	State tmp = subject->getState(); //观察者主动获取状态
	if(_observerState != tmp)
	{
		_observerState = tmp;
		cout << "update State to: " << _observerState << endl;
	}
}
