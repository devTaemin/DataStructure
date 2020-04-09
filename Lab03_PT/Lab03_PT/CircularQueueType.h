#ifndef _CIRCULARQUEUE_TYPE_H_
#define _CIRCULARQUEUE_TYPE_H_


#include <iostream>


template <typename T>
class CircularQueueType
{
public:

	CircularQueueType();

	CircularQueueType(int max);

	~CircularQueueType();

	bool IsFull() const;

	bool IsEmpty() const;

	void makeEmpty();

	void EnQueue(T item);

	void DeQueue(T& item);

private:
	int m_iFront;
	int m_iRear;
	int m_nMaxQueue;
	T* m_pItems;
};
#endif _CIRCULARQUEUE_TYPE_H_


template <typename T>
CircularQueueType<T>::CircularQueueType()
{

}


template <typename T>
CircularQueueType<T>::CircularQueueType(int max)
{

}


template <typename T>
CircularQueueType<T>::~CircularQueueType()
{

}


template <typename T>
bool CircularQueueType<T>::IsFull() const
{

}


template <typename T>
bool CircularQueueType<T>::IsEmpty() const
{

}


template <typename T>
void CircularQueueType<T>::makeEmpty()
{

}


template <typename T>
void CircularQueueType<T>::EnQueue(T item)
{

}


template <typename T>
void CircularQueueType<T>::DeQueue(T& item)
{

}

