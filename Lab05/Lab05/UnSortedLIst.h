#pragma once
#include "pch.h"
template <typename T>
class UnSortedList
{
private:
	T* m_List;
	int m_Length;
	int m_CurPointer;
	int m_MaxSize;


public:
	UnSortedList();
	UnSortedList(int _max);
	~UnSortedList();

	bool IsFull();
	bool IsEmpty();

	void MakeEmpty();
	void ResetList();

	int GetLength();
	int GetNextItem(T& data);

	int Add(const T& _data);
	int Delete(T _data);
	int Replace(const T& _data);
	int Get(T& _data);

	void operator=(const UnSortedList& _list)
	{
		m_Length = _list.m_Length;
		m_CurPointer = _list.m_CurPointer;
		m_MaxSize = _list.m_MaxSize;
		delete[] m_List;
		m_List = new T[m_MaxSize];
		for (int i = 0; i < m_Length; i++) {
			m_List[i] = _list.m_List[i];
		}
	}
	friend ostream& operator<<(ostream& os, const UnSortedList& _list)
	{
		for (int i = 0; i < _list.m_Length; i++) {
			os << _list.m_List[i] << endl;
		}
		return os;
	}
};

template<typename T>
UnSortedList<T>::UnSortedList()
{
	m_MaxSize = LISTSIZE;
	m_Length = 0;
	ResetList();
	m_List = new T[m_MaxSize];
}

template<typename T>
UnSortedList<T>::UnSortedList(int _max)
{
	m_MaxSize = _max;
	m_Length = 0;
	ResetList();
	m_List = new T[m_MaxSize];
}

template<typename T>
UnSortedList<T>::~UnSortedList()
{
	delete[] m_List;
}


template<typename T>
bool UnSortedList<T>::IsFull()
{
	return (m_Length > m_MaxSize - 1);
}

template<typename T>
bool UnSortedList<T>::IsEmpty()
{
	return (m_Length == 0);
}

template<typename T>
void UnSortedList<T>::MakeEmpty()
{
	m_Length = 0;
}

template<typename T>
void UnSortedList<T>::ResetList()
{
	m_CurPointer = -1;
}

template<typename T>
int UnSortedList<T>::GetLength()
{
	return m_Length;
}

template<typename T>
int UnSortedList<T>::GetNextItem(T& data)
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
int UnSortedList<T>::Add(const T& _data)
{
	bool found = false;
	if (IsFull()) { return 0; }
	for (int i = 0; i < m_Length; i++) {
		if (m_List[i] == _data) {
			found = true;
			break;
		}
	}

	if (found) { return -1; } // 중복으로 인한 실패(-1)
	m_List[m_Length++] = _data;
	return 1;
}

template<typename T>
int UnSortedList<T>::Delete(T _data)
{
	if (IsEmpty()) { return 0; }
	for (int i = 0; i < m_Length; i++) {
		if (m_List[i] == _data) {
			for (int j = i; j < m_Length; j++) {
				m_List[j] = m_List[j + 1];
			}
			m_Length--;
			return 1;
		}
	}
	return 0;
}

template<typename T>
int UnSortedList<T>::Replace(const T& _data)
{
	if (IsEmpty()) { return 0; }
	for (int i = 0; i < m_Length; i++) {
		if (m_List[i] == _data) {
			m_List[i] = _data;
			return 1;
		}
	}
	return 0;
}

template<typename T>
int UnSortedList<T>::Get(T& _data)
{
	if (IsEmpty()) { return 0; }
	for (int i = 0; i < m_Length; i++) {
		if (m_List[i] == _data) {
			_data = m_List[i];
			return 1;
		}
	}
	return 0;
}