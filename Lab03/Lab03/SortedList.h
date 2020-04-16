#ifndef _SORTEDLIST_H_
#define _SORTEDLIST_H_
//--------------------------------------------------------------------
//		Array based on 'Sorted list'.
//--------------------------------------------------------------------
template <typename T>
class SortedList
{
private:
	int m_Maxsize;				///< maximum size of list.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
	T* m_Array;					///< list array.


public:
	SortedList();
	//--------------------------------------------------------------------
	//		Default Constructor.
	//--------------------------------------------------------------------


	SortedList(int max);
	//--------------------------------------------------------------------
	//		Constructor.
	//--------------------------------------------------------------------


	~SortedList();
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	void MakeEmpty();
	//--------------------------------------------------------------------
	//	Brief:	Make list empty. (Initialize list)
	//	Pre:	none.
	//	Post:	clear list.
	//--------------------------------------------------------------------


	int GetLength() const;
	//--------------------------------------------------------------------
	//	Brief:	Return the number of records in the list.
	//	Pre:	none.
	//	Post:	none.
	//	Return:	number of records in current list.
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


	void ResetList();
	//--------------------------------------------------------------------
	//	Brief:	Initialize the list iterator.
	//	Pre:	list should be initialized.
	//	Post:	iterator is reset.
	//--------------------------------------------------------------------


	int GetNextItem(T& data);
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


	int Add(T data);
	//--------------------------------------------------------------------
	//	Brief:	Add a new data into list.
	//	Pre:	list should be initialized.
	//	Post:	add the new record in sorted ways into the list 
	//	Param:	data		new data.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	int Delete(T data);
	//--------------------------------------------------------------------
	//	Brief:	Delete item in accordance with data's primary key.
	//	Pre:	data's serial number should be set.
	//	Post:	a item is removed from the list.
	//	Param:	data		the target data to be deleted.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	int Replace(T data);
	//--------------------------------------------------------------------
	//	Brief:	Find same record using primary key and replace it.
	//	Pre:	data's serial number should be set,
	//	Post:	a item's record is replaced with new information.
	//	Param:	data		the target data to be replaced.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	int Retrieve_SeqS(T& data);
	//--------------------------------------------------------------------
	//	Brief:	Find the item whose primary key matches with the primary 
	//			key of target. and get the item in target.
	//	Pre:	the list should be initialized.
	//	Post:	matching item is founded and refered the record by target.
	//	Param:	target		the target item to retrieve.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	int RetrieveByBS(T& data);
	//--------------------------------------------------------------------
	//	Brief:	Retrieve item by using binary search.
	//	Pre:	the list should be initialized.
	//	Post:	matching item is founded and refered the record by data.
	//	Param:	data		the target data to retrieve.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------
};
// Default constructor.
template <typename T>
SortedList<T>::SortedList()
{
	m_Maxsize = MAXLIST;
	m_Length = 0;
	m_CurPointer = -1;
	m_Array = new T[m_Maxsize];
}


// Constructor.
template <typename T>
SortedList<T>::SortedList(int max)
{
	m_Maxsize = max;
	m_Length = 0;
	m_CurPointer = -1;
	m_Array = new T[m_Maxsize];
}


// Destructor.
template <typename T>
SortedList<T>::~SortedList()
{
	delete[] m_Array;
}


// Make list empty.
template <typename T>
void SortedList<T>::MakeEmpty()
{
	m_Length = 0;
	delete[] m_Array;
	m_Array = new T[m_Maxsize];
}


// Get a number of records in current list.
template <typename T>
int SortedList<T>::GetLength() const
{
	return m_Length;
}


// Check capacity of list is full.
template <typename T>
bool SortedList<T>::IsFull() const
{
	return (m_Length == m_Maxsize);
}


// Check capacity of list is empty.
template <typename T>
bool SortedList<T>::IsEmpty() const
{
	return (m_Length == 0);
}


// Initialize list iterator.
template <typename T>
void SortedList<T>::ResetList()
{
	m_CurPointer = -1;
}


// Update pointer to point next record, and get the new record.
template <typename T>
int SortedList<T>::GetNextItem(T& data)
//---------------------------------------------------------------
// (1) 현재 list가 empty라면, 실패(-1)을 return.
// (2) 다음 record를 가리키도록 Pointer를 increment.
// (3) 만약 Pointer가 저장한 list의 index를 초과(=저장 개수)하면 
//	   실패(-1)를 return.
// (4) data에 현재 item을 refer하고 현재 위치 포인터를 return.
//---------------------------------------------------------------
{
	if (IsEmpty()) { return -1; }							// (1).
	m_CurPointer++;											// (2).
	if (m_CurPointer == m_Length) {							// (3).
		return -1;
	}
	data = m_Array[m_CurPointer];							// (4).
	return m_CurPointer;
}


// Add a new data into list.
template <typename T>
int SortedList<T>::Add(T data)
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
	if (IsFull()) { return 0; }								// (1).
	
	if (IsEmpty()) {
		m_Array[m_Length++] = data;
		return 1;
	}

	T curItem;												// (2). 
	ResetList();
	int iPos = GetNextItem(curItem);
	for (iPos; iPos >= 0; iPos = GetNextItem(curItem)) {
		if (data.Compare(curItem) == EQUAL) {
			return -1;
		}
		else if (data.Compare(curItem) == GREATER) {
			break;
		}
		else { continue; }
	}

	for (int i = m_Length; i > iPos; i--) {				// (3).
		m_Array[i] = m_Array[i - 1];
	}
	m_Array[iPos] = data;
	m_Length++;
	return 1;
}


// Delete item in accordance with data's primary key.
template <typename T>
int SortedList<T>::Delete(T data)
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
	if (IsEmpty()) { return 0; }							// (1).
	T curItem;												// (2).
	ResetList();
	int iPos = GetNextItem(curItem);
	bool found = false;
	for (iPos; iPos > 0; iPos = GetNextItem(curItem)) {
		if (!found) {
			if (data.Compare(curItem) == EQUAL) {
				found = true;
			}
		}
		else {
			m_Array[iPos - 1] = m_Array[iPos];
		}
	}

	if (found) {											// (3).
		m_Length--;
		return 1;
	}
	else { return 0; }
}


// Find same record using primary key and replace it.
template <typename T>
int SortedList<T>::Replace(T data)
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
	if (IsEmpty()) { return 0; }							// (1).
	T curItem;												// (2).
	ResetList();
	int iPos = GetNextItem(curItem);
	for (iPos; iPos > 0; iPos = GetNextItem(curItem)) {
		if (data.Compare(curItem) == EQUAL) {
			m_Array[iPos] = data;
			return 1;
		}
		else if (data.Compare(curItem) == LESS) {
			return 0;
		}
		else { continue; }
	}
	return 0;												// (3).
}


// Find the item whose primary key matches with that of input data.
template <typename T>
int SortedList<T>::Retrieve_SeqS(T& data)
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
	if (IsEmpty()) { return 0; }							// (1).
	T curItem;												// (2).
	ResetList();
	int iPos = GetNextItem(curItem);
	for (iPos; iPos > 0; iPos = GetNextItem(curItem)) {
		if (data.Compare(curItem) == EQUAL) {
			data = m_Array[iPos];
			return 1;
		}
		else if (data.Compare(curItem) == GREATER) {
			return 0;
		}
		else { continue; }
	}
	return 0;												// (3).
}


// Retrieve by using binary search.
template <typename T>
int SortedList<T>::RetrieveByBS(T& data)
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
	if (IsEmpty()) { return 0; }							// (1).
	while (1)												// (2).
	{
		m_CurPointer = m_Length / 2;
		T curItem = m_Array[m_CurPointer];
		switch (curItem.Compare(data))
		{
		case EQUAL:
			data = curItem;
			return 1;
			break;
		case GREATER:
			if (m_CurPointer == 0) { return 0; }
			m_CurPointer /= 2;
			break;
		case LESS:
			if (m_CurPointer >= m_Length - 1) { return 0; }
			m_CurPointer = (m_CurPointer + m_Length) / 2;
			break;
		}
	}
	return 0;
}
#endif _SORTEDLIST_H_


