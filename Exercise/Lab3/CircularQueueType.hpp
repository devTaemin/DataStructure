#ifndef _CircularQueueType_hpp_
#define _CircularQueueType_hpp_
#include <iostream>
#include <string>
using namespace std;


template <typename T>
class CircularQueueType
{
public:
	CircularQueueType();
	CircularQueueType(int max);
	~CircularQueueType();

	bool IsFull();
	bool IsEmpty();
	void MakeEmpty();
	void EnQueue(T item);
	void DeQueue(T& item);
	void Print();

private:
	int m_iFront;
	int m_iRear;
	int m_nMaxQueue;
	T* m_pItem;
};
#endif