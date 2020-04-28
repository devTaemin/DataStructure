#pragma once
#include "pch.h"
template <typename T>
class CircularQueue
{
private:
	int m_MaxSize;
	int m_Length;
	int m_CurPointer;
	int m_Front;
	int m_Rear;
	T* m_Queue;


public:
	CircularQueue();
	CircularQueue(int _max);
	~CircularQueue();

	bool IsFull();
	bool IsEmpty();

	void MakeEmpty();
	void ResetQueue();

	int GetLength();
	int GetNextItem(T& data);

	int Add(const T& _data);
	int Delete(T _data);

	//int Replace(const T& _data);
	//int Get(T& _data);
	//void operator=(const CircularQueue& _list)
	//friend ostream& operator<<(ostream& os, const CircularQueue& _list)
};

template<typename T>
CircularQueue<T>::CircularQueue()
{
	m_MaxSize = MAXQUEUE;
	m_Length = 0;
	m_CurPointer = m_MaxSize - 1;
	m_Front = m_MaxSize - 1;
	m_Rear = m_MaxSize - 1;
	m_Queue = new T[m_MaxSize];
}

template<typename T>
CircularQueue<T>::CircularQueue(int _max)
{
	m_MaxSize = _max;
	m_Length = 0;
	m_CurPointer = m_MaxSize - 1;
	m_Front = m_MaxSize - 1;
	m_Rear = m_MaxSize - 1;
	m_Queue = new T[m_MaxSize];
}

template<typename T>
CircularQueue<T>::~CircularQueue()
{
	delete[] m_Queue;
}


template<typename T>
bool CircularQueue<T>::IsFull()
{
	return (m_Length > m_MaxSize - 1);
}

template<typename T>
bool CircularQueue<T>::IsEmpty()
{
	return (m_Length == 0);
}

template<typename T>
void CircularQueue<T>::MakeEmpty()
{
	
}

template<typename T>
void CircularQueue<T>::ResetQueue()
{
	m_CurPointer = m_Front;
}

template<typename T>
int CircularQueue<T>::GetLength()
{
	return m_Length;
}

template<typename T>
int CircularQueue<T>::GetNextItem(T& data)
{
	if (IsEmpty()) { return -1; }
	m_CurPointer++;
	if (m_CurPointer == m_Length) {
		return -1;
	}
	data = m_List[m_CurPointer];
	return m_CurPointer;
}

template<typename T>
int CircularQueue<T>::Add(const T& _data)
{
	
}

template<typename T>
int CircularQueue<T>::Delete(T _data)
{
	
}