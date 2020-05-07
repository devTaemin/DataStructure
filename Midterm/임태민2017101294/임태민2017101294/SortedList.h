#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define MAXLIST 20
//--------------------------------------------------------------------
//		Array based on 'Sorted list'.
//--------------------------------------------------------------------
template <typename T>
class SortedList
{
private:
	T* m_List;				///< list array.
	int m_Length;			///< number of elements in list.
	int m_CurPointer;		///< iterator pointer.
	int m_MaxSize;			///< maximum size of list.

public:
	SortedList();
	//--------------------------------------------------------------------
	//		Default Constructor.
	//--------------------------------------------------------------------

	SortedList(int _max);
	//--------------------------------------------------------------------
	//		Constructor.
	//--------------------------------------------------------------------

	~SortedList();
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------

	bool IsFull() const;
	//--------------------------------------------------------------------
	//	Brief:	Check the list upper is reached to the limit.
	//	Pre:	none.
	//	Post:	none.
	//	Return:	return true if list capacity reached to the upper bound, 
	//			otherwise return false.
	//--------------------------------------------------------------------

	bool IsEmpty() const;
	//--------------------------------------------------------------------
	//	Brief:	Check whether list's length is 0 or not.
	//	Pre:	none.
	//	Post:	none.
	//	Return:	return true if list is empty, otherwise return false.
	//--------------------------------------------------------------------

	void MakeEmpty();
	//--------------------------------------------------------------------
	//	Brief:	Make list empty. (Initialize list)
	//	Pre:	none.
	//	Post:	clear list.
	//--------------------------------------------------------------------

	void ResetList();
	//--------------------------------------------------------------------
	//	Brief:	Initialize the list iterator.
	//	Pre:	list should be initialized.
	//	Post:	iterator is reset.
	//--------------------------------------------------------------------

	void SetMaxSize(int _max);


	int GetLength() const;
	//--------------------------------------------------------------------
	//	Brief:	Return the number of records in the list.
	//	Pre:	none.
	//	Post:	none.
	//	Return:	number of records in current list.
	//--------------------------------------------------------------------

	int GetNextItem(T& _data);
	//--------------------------------------------------------------------
	//	Brief:	Update pointer to point to next record,
	//			and get that new record.
	//	Pre:	list and list iterator should not be initialized.
	//	Post:	iterator is moved to next item.
	//	Param:	data		get current iterator's item. 
	//						it does not need to be initialized
	//	Return:	index of current iterator's item if it is not end of list,
	//			otherwise return -1.
	//--------------------------------------------------------------------

	int Add(T& _data);
	//--------------------------------------------------------------------
	//	Brief:	Add a new data into list.
	//	Pre:	list should be initialized.
	//	Post:	add the new record in sorted ways into the list 
	//	Param:	data		new data.
	//	Return:	return 1 if this function works well, otherwise 0. -1(duplicated).
	//--------------------------------------------------------------------

	int Delete(T& _data);
	//--------------------------------------------------------------------
	//	Brief:	Delete item in accordance with data's primary key.
	//	Pre:	data's serial number should be set.
	//	Post:	a item is removed from the list.
	//	Param:	data		the target data to be deleted.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------

	int Replace(const T& _data);
	//--------------------------------------------------------------------
	//	Brief:	Find same record using primary key and replace it.
	//	Pre:	data's serial number should be set,
	//	Post:	a item's record is replaced with new information.
	//	Param:	data		the target data to be replaced.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------

	int Get(T& _data);
	//--------------------------------------------------------------------
	//	Brief:	Find the item whose primary key matches with the primary 
	//			key of target. and get the item in target.
	//	Pre:	the list should be initialized.
	//	Post:	matching item is founded and refered the record by target.
	//	Param:	target		the target item to retrieve.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------

	int GetByBinarySearch(T& _data);
	//--------------------------------------------------------------------
	//	Brief:	Retrieve item by using binary search.
	//	Pre:	the list should be initialized.
	//	Post:	matching item is founded and refered the record by data.
	//	Param:	data		the target data to retrieve.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------

	void operator=(const SortedList& _list)
	{
		m_Length = _list.m_Length;
		m_CurPointer = _list.m_CurPointer;
		m_MaxSize = _list.m_MaxSize;
		delete[] m_List;
		for (int i = 0; i < m_Length; i++) {
			m_List[i] = _list.m_List[i];
		}
	}

	friend ostream& operator<<(ostream& os, const SortedList& _list)
	{
		for (int i = 0; i < _list.m_Length; i++) {
			os << _list.m_List[i] << endl;
		}
		return os;
	}
};

// Default constructor.
template<typename T>
SortedList<T>::SortedList()
{
	m_MaxSize = MAXLIST;
	m_Length = 0;
	ResetList();
	m_List = new T[m_MaxSize];
}

// Constructor.
template<typename T>
SortedList<T>::SortedList(int _max)
{
	m_MaxSize = _max;
	m_Length = 0;
	ResetList();
	m_List = new T[m_MaxSize];
}

// Destructor.
template<typename T>
SortedList<T>::~SortedList()
{
	//delete[] m_List;
}

// Check capacity of list is full.
template<typename T>
bool SortedList<T>::IsFull() const
{
	return (m_Length > m_MaxSize - 1);
}

// Check capacity of list is empty.
template<typename T>
bool SortedList<T>::IsEmpty() const
{
	return (m_Length == 0);
}

// Make list empty.
template<typename T>
void SortedList<T>::MakeEmpty()
{
	m_Length = 0;
}

// Initialize list iterator.
template<typename T>
void SortedList<T>::ResetList()
{
	m_CurPointer = -1;
}

template<typename T>
void SortedList<T>::SetMaxSize(int _max)
{
	m_MaxSize = _max;
}

// Get a number of records in current list.
template<typename T>
int SortedList<T>::GetLength() const
{
	return m_Length;
}

// Update pointer to point next record, and get the new record.
template<typename T>
int SortedList<T>::GetNextItem(T& _data)
//---------------------------------------------------------------
// (1) 현재 list가 empty라면, 실패(-1)을 return.
// (2) 다음 record를 가리키도록 Pointer를 increment.
// (3) 만약 Pointer가 저장한 list의 index를 초과(=저장 개수)하면 
//	   실패(-1)를 return.
// (4) data에 현재 item을 refer하고 현재 위치 포인터를 return.
//---------------------------------------------------------------
{
	if (IsEmpty()) { return -1; }
	m_CurPointer++;
	if (m_CurPointer == m_Length) {
		return -1;
	}
	_data = m_List[m_CurPointer];
	return m_CurPointer;
}

// Add a new data into list.
template<typename T>
int SortedList<T>::Add(T& _data)
//---------------------------------------------------------------
// (1) 현재 list의 용량을 확인한다.
//	   - 다 채워져있을 경우, 실패(0)을 return.
//	   - 빈 경우, 첫 자리 삽입, 길이 증가, 성공(1) return.
// (2) 검색, 삽입 위치를 찾기 위해 GetNextItem을 사용한다.
//	   - GetNextItem을 이용하여, 실패(0 or -1)이 나올때까지 loop.
//	   - 입력될 데이터의 Serial이 '중복'되는 경우, 실패(-1)을 return.
//     - 입력될 데이터의 Serial이 더 작은 경우, break.
//     - 입력될 데이터의 Serial이 더 큰 경우, continue.
// (3) 정렬리스트, 삽입
//	   - m_Length를 이용하여, 삽입될 위치 이후의 값들을 하나씩 
//       밀어서 이동해준다.
//     - 이후, 삽입 공간에 data를 넣어준다.
//     - 삽입이 되었으므로, 리스트의 길이를 증가해준다.
//     - 성공(1)을 return.
//----------------------------------------------------------------
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
	for (int i = 0; i < m_Length; i++) {//중간 입력
		if (m_List[i] > _data) { // 오름차순
			for (int j = m_Length; j > i; j--) {
				m_List[j] = m_List[j - 1];
			}
			m_List[i] = _data;
			m_Length++;
			return 1;
		}
	}
	m_List[m_Length++] = _data; // 끝 입력
	return 1;
}

// Delete item in accordance with data's primary key.
template<typename T>
int SortedList<T>::Delete(T& _data)
//---------------------------------------------------------------
// (1) 현재 list의 용량을 확인한다.
//	   - list가 비어있으면, 실패(0)을 return.
// (2) 검색
//	   - GetNextItem을 이용하여, list의 element를 받아올 것이다.
//	   - found(false)인 경우, 입력된 데이터와, 리스트의 element의 
//		 Serial을 비교한다. 같을 경우, found = true로 지정한다.
//     - found(true)인 경우, 이전 Pointer에서 해당 데이터를 찾은 것
//		 이기 때문에, 그 이전 list의 index로 현재 element를 이동하여
//       값을 지워준다.
// (3) found(true)라면, 길이를 1줄이고, 성공(1)을 return.
//	   found(false)라면, 실패(0)을 return.
// ---------------------------------------------------------------
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

// Find same record using primary key and replace it.
template<typename T>
int SortedList<T>::Replace(const T& _data)
//---------------------------------------------------------------
// (1) 현재 list의 용량을 확인한다.
//	   - list가 비어있으면, 실패(0)을 return.
// (2) 검색, 교체
//	   - GetNextItem을 이용하여, list의 element를 받아들인다.
//	   - 입력받은 데이터의 key가 EQUAL, 해당 자리의 record를 교체.
//		 성공(1)을 return.
//	   - 입력받은 데이터의 key가 LESS,리스트에 없음(0)을 return.
//     - 입력받은 데이터의 key가 GREATER, 다음 item과 비교.
// (3) 함수의 끝
// ---------------------------------------------------------------
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

// Find the item whose primary key matches with that of input data.
template<typename T>
int SortedList<T>::Get(T& _data)
//---------------------------------------------------------------
// (1) 현재 list의 용량을 확인한다.
//	   - list가 비어있으면, 실패(0)을 return.
// (2) 검색, 참조
//	   - GetNextItem을 이용하여, list의 element를 받아들인다.
//	   - 입력받은 데이터의 key가 EQUAL, 해당 자리의 record를 refer.
//		 성공(1)을 return.
//	   - 입력받은 데이터의 key가 LESS,리스트에 없음(0)을 return.
//     - 입력받은 데이터의 key가 GREATER, 다음 item과 비교.
// (3) 함수의 끝
// ---------------------------------------------------------------
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

// Retrieve by using binary search.
template<typename T>
int SortedList<T>::GetByBinarySearch(T& _data)
//---------------------------------------------------------------
// (1) 현재 list의 용량을 확인한다.
//	   - list가 비어있으면, 실패(0)을 return.
// (2) 정렬 리스트, 2진 검색 시작.
//     - 시작점을 배열의 중간 지점으로 설정.
//	   - Relation EQUAL 의 경우
//		 [1] 해당 지점의 item을 반환하고, 성공(1)을 return.
//	   - Relation GREATER 의 경우
//		 [1] 비교한 데이터가 리스트의 첫 지점이면, 실패(0)을 return.
//		 [2] 아닌 경우, 해당 지점과 첫 지점의 사이로 Position 이동.
//	   - Relation LESS 의 경우
//		 [1] 비교한 데이터가 리스트의 마지막이면, 실패(0)을 return.
//		 [2] 아닌 경우, 해당 지점과 끝 지점의 사이로 Position 이동.
// (4) 함수가 실패하면, 실패(0)을 return.
// ---------------------------------------------------------------
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