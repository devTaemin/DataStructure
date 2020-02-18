/*
#include "CircularQueueType.hpp"

template <typename T>
CircularQueueType<T>::CircularQueueType() : m_iFront(7), m_iRear(7), m_nMaxQueue(8)
{
	m_pItem = new T[m_nMaxQueue];
}

template <typename T>
CircularQueueType<T>::CircularQueueType(int max) : m_iFront(max - 1), m_iRear(max - 1), m_nMaxQueue(max)
{
	m_pItem = new T[m_nMaxQueue];
}

template <typename T>
CircularQueueType<T>::~CircularQueueType()
{
	delete[] m_pItem;
}

template <typename T>
bool CircularQueueType<T>::IsFull()
{
	if ((m_iFront - 1) == m_iRear) {
		return true;
	}
	else { return false; }
}

template <typename T>
bool CircularQueueType<T>::IsEmpty()
{
	if (m_iFront == m_iRear) {
		return true;
	}
	else { return false; }
}

template <typename T>
void CircularQueueType<T>::MakeEmpty()
{
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;
}

template <typename T>
void CircularQueueType<T>::EnQueue(T item)
{
	if (m_iRear == (m_nMaxQueue - 1)) {
		m_iRear = -1;
	}
	m_pItem[++m_iRear] = item;
}

template <typename T>
T CircularQueueType<T>::DeQueue(T& item)
{
	if (m_iFront == (m_nMaxQueue - 1)) {
		m_iFront = -1;
	}
	item = m_pItem[++m_iFront];
	return item;
}

template <typename T>
void CircularQueueType<T>::Print()
{
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
		cerr << "Fail to print! [Empty array]" << endl;
	}
	
}
*/