#ifndef _Cmd_hpp_
#define _Cmd_hpp_
#include "CircularQueueType.hpp"

template <typename T>
class Cmd
{
public:
	Cmd();
	~Cmd();

	void enqueueElem();
	void dequeueElem();
	void isEmpty();
	void isFull();
	void emptyQueueExceptionTest();
	void fullQueueExceptionTest();
	void printAll();
	void quit();

private:
	CircularQueueType<T> Cqueue;
};



#endif