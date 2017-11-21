#include "Observer.h"

#include <iostream>
#include <memory>
using namespace std;

int main(void)
{
	std::unique_ptr<Observer> observer1(new ConcreteObserver);
	std::unique_ptr<Observer> observer2(new ConcreteObserver);
	std::unique_ptr<Observer> observer3(new ConcreteObserver);
	std::unique_ptr<Observer> observer4(new ConcreteObserver);

	unique_ptr<Subject> subject(new ConcreteSubject);

	subject->attach(observer1.get());
	subject->attach(observer2.get());
	subject->attach(observer3.get());
	subject->attach(observer4.get());

	subject->setState(1);

	subject->detach(observer4.get());
	cout << endl;
	subject->setState(2);

	return 0;
}
