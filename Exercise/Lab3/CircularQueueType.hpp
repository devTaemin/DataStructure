#ifndef CircularQueueType_hpp
#define CircularQueueType_hpp
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class CircularQueueType
{
public:
	CircularQueueType() : m_iFront(7), m_iRear(7), m_nMaxQueue(8)
	{
		m_pItem = new T[m_nMaxQueue];
	}

	CircularQueueType(int max) : m_iFront(max - 1), m_iRear(max - 1), m_nMaxQueue(max)
	{
		m_pItem = new T[m_nMaxQueue];
	}

	~CircularQueueType()
	{
		delete[] m_pItem;
	}

	bool IsFull()
	{
		if ((m_iFront - 1) == m_iRear) {
			return true;
		}
		else if (abs(m_iFront - m_iRear) == 7) {
			return true;
		}
		else { return false; }
	}

	bool IsEmpty()
	{
		if (m_iFront == m_iRear) {
			return true;
		}
		else { return false; }
	}

	void MakeEmpty()
	{
		m_iFront = m_nMaxQueue - 1;
		m_iRear = m_nMaxQueue - 1;
	}

	void EnQueue(T item)
	{
		if (m_iRear == (m_nMaxQueue - 1)) {
			m_iRear = -1;
		}
		m_pItem[++m_iRear] = item;
	}

	T DeQueue(T& item)
	{
		if (m_iFront == (m_nMaxQueue - 1)) {
			m_iFront = -1;
		}
		item = m_pItem[++m_iFront];
		return item;
	}

	void Print()
	{
		cout << "     ";
		if (!IsEmpty()) {
			if (m_iFront > m_iRear) {
				for (int i = m_iFront + 1; i < m_nMaxQueue; i++) {
					cout << m_pItem[i] << " ";
				}
				for (int j = 0; j <= m_iRear; j++) {
					cout << m_pItem[j] << " ";
				}
				cout << endl;
			}
			else {
				for (int i = m_iFront + 1; i <= m_iRear; i++) {
					cout << m_pItem[i] << " ";
				}
				cout << endl;
			}
		}
		else {
			cerr << "     " << "Fail to print! [Empty array]" << endl;
		}

	}

private:
	int m_iFront;
	int m_iRear;
	int m_nMaxQueue;
	T* m_pItem;
};
/*
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
#include "CircularQueueType.hpp"
*/
#endif