#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define LISTSIZE 10
template <typename T>
class SortedList
{
private:
	T* m_List;
	int m_Length;
	int m_CurPointer;
	int m_MaxSize;


public:
	SortedList();
	SortedList(int _max);
	~SortedList();

	bool IsFull();
	bool IsEmpty();

	void MakeEmpty();
	void ResetList();

	int GetLength();
	int GetNextItem(T& _data);

	int Add(const T& _data);
	int Delete(T _data);
	int Replace(const T& _data);
	int Get(T& _data);
	int GetByBinarySearch(T& _data);

	//void operator=(const SortedList& _list)
	//friend ostream& operator<<(ostream& os, const SortedList& _list)
};

template<typename T>
SortedList<T>::SortedList()
{
	m_MaxSize = LISTSIZE;
	m_Length = 0;
	ResetList();
	m_List = new T[m_MaxSize];
}

template<typename T>
SortedList<T>::SortedList(int _max)
{
	m_MaxSize = _max;
	m_Length = 0;
	ResetList();
	m_List = new T[m_MaxSize];
}

template<typename T>
SortedList<T>::~SortedList()
{
	delete[] m_List;
}


template<typename T>
bool SortedList<T>::IsFull()
{
	return (m_Length > m_MaxSize - 1);
}

template<typename T>
bool SortedList<T>::IsEmpty()
{
	return (m_Length == 0);
}

template<typename T>
void SortedList<T>::MakeEmpty()
{
	m_Length = 0;
}

template<typename T>
void SortedList<T>::ResetList()
{
	m_CurPointer = -1;
}

template<typename T>
int SortedList<T>::GetLength()
{
	return m_Length;
}

template<typename T>
int SortedList<T>::GetNextItem(T& _data)
{
	if (IsEmpty()) { return -1; }
	m_CurPointer++;
	if (m_CurPointer == m_Length) {
		return -1;
	}
	_data = m_List[m_CurPointer];
	return m_CurPointer;
}

template<typename T>
int SortedList<T>::Add(const T& _data)
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


	if (IsEmpty()) {//맨앞 입력
		m_List[m_Length++] = _data;
		return 1;
	}
	int position;
	for (int i = 0; i < m_Length; i++) {//중간 입력
		if (m_List[i] > _data) { // 오름차순
			for (int j = m_Length; j > i; j--) {
				m_List[j] = m_List[j - 1];
				position = j;
			}
			m_List[position] = _data;
			m_Length++;
			return 1;
		}

	}
	m_List[m_Length++] = _data; // 끝 입력
	return 1;
}

template<typename T>
int SortedList<T>::Delete(T _data)
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
int SortedList<T>::Replace(const T& _data)
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
int SortedList<T>::Get(T& _data)
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

template<typename T>
int SortedList<T>::GetByBinarySearch(T& _data)
{
	if (IsEmpty()) { return 0; }
	int first = 0;
	int last = m_Length - 1;
	bool found = false;
	while (first <= last && !found)
	{
		int mid = (first + last) / 2;
		if (_data < m_List[mid]) {
			last = mid - 1;
		}
		else if (_data > m_List[mid]) {
			first = mid + 1;
		}
		else {
			_data = m_List[mid];
			found = true;
		}
	}

	if (!found) { return 0; }
	return 1;
}