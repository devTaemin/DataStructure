#ifndef _CIRCULARQUEUE_TYPE_H_
#define _CIRCULARQUEUE_TYPE_H_


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ItemType.h"


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


	void Print();

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
	m_iFront = -1;
	m_iRear = -1;
	m_nMaxQueue = 9; //8개의 item을 다루기 위해
	m_pItems = new[m_nMaxQueue];
}


template <typename T>
CircularQueueType<T>::CircularQueueType(int max)
{
	m_iFront = -1;
	m_iRear = -1;
	m_nMaxQueue = max;
	m_pItems = new[m_nMaxQueue];
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


template <typename T>
void CircularQueueType<T>::Print()
{

}