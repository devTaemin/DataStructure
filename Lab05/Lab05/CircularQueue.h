#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define MAXQUEUE 11
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
	int GetNextItem(T& _data);

	int Add(const T& _data);
	int Delete(T& _data);
	
	void DisplayAll();

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
	m_Front = m_MaxSize - 1;
	m_Rear = m_MaxSize - 1;
	delete[] m_Queue;
	m_Queue = new T[m_MaxSize];
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
int CircularQueue<T>::GetNextItem(T& _data)
{
	if (IsEmpty()) { return -1; }
	m_CurPointer = (m_CurPointer + 1) % m_MaxSize;
	_data = m_Queue[m_CurPointer];
	if (m_CurPointer == m_Rear) {
		ResetQueue();
		return -1;
	}
	return 1;
}

template<typename T>
int CircularQueue<T>::Add(const T& _data)
{
	if (IsFull()) { return 0; }
	m_Rear = (m_Rear + 1) & m_MaxSize;
	m_Queue[m_Rear] = _data;
	m_Length++;
	return 1;
}

template<typename T>
int CircularQueue<T>::Delete(T& _data) // delete하면서 가져올 수 있다.
{
	if (IsEmpty()) { return 0; }
	m_Front = (m_Front + 1) % m_MaxSize;
	_data = m_Queue[m_Rear];
	m_Length--;
	return 1;
}

template<typename T>
void CircularQueue<T>::DisplayAll()
{
	if (IsEmpty()) { return; }
	if (m_Front > m_Rear)
	{
		for (int i = m_Front + 1; i < m_MaxSize; i++)
		{
			cout << m_Queue[i] << " - ";
		}
		for (int i = 0; i <= m_Rear; i++)
		{
			cout << m_Queue[i] << " - ";
		}
	}
	else
	{
		for (int i = m_Front + 1; i < m_Rear; i++)
		{
			cout << m_Queue[i] << " - ";
		}
	}
	cout << endl;
}