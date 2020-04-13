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


	void EnQueue(T Data);


	void DeQueue(T& Data);


	void Print();


	void ResetList();


	int GetNextItem(T& Data);


	int Search(ItemType& Data);


	int Delete(ItemType Data);


	int Replace(ItemType Data);


private:
	int m_iFront;
	int m_iRear;
	int m_nMaxQueue;
	int m_CurPointer;
	T* m_pItems;
};
#endif _CIRCULARQUEUE_TYPE_H_


template <typename T>
CircularQueueType<T>::CircularQueueType()
{
	m_nMaxQueue = 9; //8개의 item을 다루기 위해
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;
	m_pItems = new m_pItems[m_nMaxQueue];
}


template <typename T>
CircularQueueType<T>::CircularQueueType(int max)
{
	m_nMaxQueue = max + 1;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;
	m_pItems = new m_pItems[m_nMaxQueue];
}


template <typename T>
CircularQueueType<T>::~CircularQueueType()
{
	delete m_pItems[];
}


template <typename T>
bool CircularQueueType<T>::IsFull() const
{
	return ((m_iRear + 1) % m_nMaxQueue == m_iFront);
}


template <typename T>
bool CircularQueueType<T>::IsEmpty() const
{
	return (m_iFront == m_iRear);
}


template <typename T>
void CircularQueueType<T>::makeEmpty()
{
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;
}


template <typename T>
void CircularQueueType<T>::EnQueue(T Data)
{
	if (IsFull()) { throw FullQueue(); }
	else
	{
		m_iRear = (m_iRear + 1) % m_nMaxQueue;
		m_pItems[m_iRear] = Data;
	}
}


template <typename T>
void CircularQueueType<T>::DeQueue(T& Data)
{
	if (IsEmpty()) { throw EmptyQueue(); }
	else
	{
		m_iFront = (m_iFront + 1) % m_nMaxQueue;
		Data = items[m_iFront];
	}
}


template <typename T>
void CircularQueueType<T>::Print()
{
	if (IsEmpty()) { throw EmptyQueue(); }
	else
	{
		int CurPointer = (m_iFront + 1) % m_nMaxQueue;
		if (CurPointer <= m_iRear)
		{
			for (CurPointer; CurPointer <= m_iRear; CurPointer++){
				cout << m_pItems[CurPointer] << '\n';
			}
		}
		else
		{
			for (CurPointer; CurPointer < m_nMaxQueue; CurPointer++) {
				cout << m_pItems[CurPointer] << '\n';
			}
			for (int i = 0; i <= m_iRear; i++) {
				cout << m_pItems[i] << '\n';
			}
		}
	}
}


template <typename T>
void CircularQueueType<T>::ResetList()
{
	m_CurPointer = m_iFront;
}


template <typename T>
int CircularQueueType<T>::GetNextItem(T& Data)
{
	if (IsEmpty()) { return 0; }
	m_CurPointer = (m_CurPointer + 1) % m_nMaxQueue;
	Data = m_pItems[m_CurPointer];
	return 1;
}


template <typename T>
int CircularQueueType<T>::Search(ItemType& Data)
{
	if (IsEmpty()) { return 0; }
	ItemType item;
	ResetList();
	int iPos = GetNextItem(item);
	for (iPos; iPos > 0; iPos = GetNextItem(item)) {
		if (Data.Compare_Serial(item) == EQUAL) {
			item = m_pItems[m_CurPointer];
			return 1;
		}
	}
	return 0;
}


template <typename T>
int CircularQueueType<T>::Delete(ItemType Data)
{
	if (IsEmpty()) { return 0; }
	ItemType item;
	bool found = false;
	ResetList();
	int iPos = GetNextItem(item);
	for (iPos; iPos > 0; iPos = GetNextItem(item)) {
		if (!found) {
			if (Data.Compare_Serial(item) == EQUAL) {
				found = true;
			}
		}
		else {
			m_pItems[m_CurPointer - 1] = m_pItems[m_CurPointer];
		}
	}
	if (!found) { return 0; }
	return 1;
}


template <typename T>
int CircularQueueType<T>::Replace(ItemType Data)
{
	if (IsEmpty()) { return 0 };
	ItemType item;
	ResetLIst();
	int iPos = GetNextItem(item);
	for (iPos; iPos > 0; iPos = GetNextItem(item)) {
		if (Data.Compare_Serial(item) == EQUAL) {
			m_pItems[m_CurPointer] = Data;
			return 1;
		}
	}
	return 0;
}