#ifndef _UNSORTEDLIST_H_
#define _UNOSRTEDLIST_H_
//--------------------------------------------------------------------
//		Array based on 'UnSorted list'.
//--------------------------------------------------------------------
template <typename T>
class UnSortedList
{
private:
	int m_Maxsize;				///< maximum size of list.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
	T* m_Array;					///< list array.


public:
	UnSortedList();
	//--------------------------------------------------------------------
	//		Default Constructor.
	//--------------------------------------------------------------------


	UnSortedList(int max);
	//--------------------------------------------------------------------
	//		Constructor.
	//--------------------------------------------------------------------


	~UnSortedList() {}
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


	int Get(T& data);
	//--------------------------------------------------------------------
	//	Brief:	Search data in accordance with data's serial number,
	//			and refer the record on argument 'data'.
	//	Pre:	data's serial number should be set,
	//			and data is searched from list.
	//	Post:	the new item is added into the list.
	//	Param:	data		the target data to be copied.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------
};
#endif _UNSORTEDLIST_H_


// Default constructor.
template <typename T>
UnSortedList<T>::UnSortedList() {
	m_Maxsize = MAXLIST;
	m_Length = 0;
	m_CurPointer = -1;			
	m_Array = new T[m_Maxsize];
}


// Constructor.
template <typename T>
UnSortedList<T>::UnSortedList(int max)
{
	m_Maxsize = max;
	m_Length = 0;
	m_CurPointer = -1;
	m_Array = new T[m_Maxsize];
}


// Destructor.
template <typename T>
UnSortedList<T>::~UnSortedList() 
{
	delete[] m_Array;
}


// Make list empty.
template <typename T>
void UnSortedList<T>::MakeEmpty()
{
	m_Length = 0;
	delete[] m_Array;
	m_Array = new T[m_Maxsize];
}


// Get a number of records in current list.
template <typename T>
int UnSortedList<T>::GetLength() const
{
	return m_Length;
}


// Check whether capacity of list is full.
template <typename T>
bool UnSortedList<T>::IsFull() const
{
	return (m_Length == m_Maxsize);
}


// Check whether capacity of list is empty.
template <typename T>
bool UnSortedList<T>::IsEmpty() const
{
	return (m_Length == 0);
}


// Initialize list iterator.
template <typename T>
void UnSortedList<T>::ResetList()
{
	m_CurPointer = -1;
}


// Update pointer to point next record, and get the new record.
template <typename T>
int UnSortedList<T>::GetNextItem(T& data)
//---------------------------------------------------------------
// (1) 현재 list가 empty라면, 실패(0)을 return.
// (2) 다음 record를 가리키도록 Pointer를 increment.
// (3) 만약 Pointer가 저장한 list의 index를 초과(=저장 개수)하면 
//	   실패(-1)를 return.
// (4) data에 현재 item을 refer하고 현재 위치 포인터를 return.
//---------------------------------------------------------------
{
	if (IsEmpty()) { return 0; }							// (1).
	m_CurPointer++;											// (2).
	if (m_CurPointer == m_Length) {							// (3).
		return -1;
	}
	data = m_Array[m_CurPointer];							// (4).
	return m_CurPointer;
}


// Add a new data into list.
template <typename T>
int UnSortedList<T>::Add(T data)
//---------------------------------------------------------------
// (1) 현재 list가 full이라면, 실패(0)을 return.
//     현재 list가 empty이라면, 첫자리에 삽입 후 성공(1) return.
// (2) 중복 검사를 위해 GetNextItem을 이용하여, Serial을 비교.
//     - 중복일 경우, duplicate를 나타내는, 실패(-1)을 return.
// (3) list의 길이에 해당하는 index에 data를 삽입, 길이 1증가
//     성공(1)을 return.
//---------------------------------------------------------------
{
	if (IsFull()) { return 0; }								// (1).
	T curItem;												// (2).
	ResetList();
	int iPos = GetNextItem(curItem);
	for (iPos; iPos > 0; iPos = GetNextItem(curItem)) {
		if (curItem.Compare_Serial(data) == EQUAL) {
			return -1;
		}
	}

	m_Array[m_Length++] = data;								// (3).
	return 1;
}


// Delete item in accordance with data's primary key.
template <typename T>
int UnSortedList<T>::Delete(T data)
//---------------------------------------------------------------
// (1) 현재 list가 empty이라면, 실패(0)을 return.
// (2) 지울 item을 찾기위해 GetNextItem을 이용하여, Serial을 비교.
//     - found(false)인 경우, serial을 비교, 찾은경우 found(true).
//	   - found(true)인 경우, 그 이전 자리로 한칸씩 이동.
// (3) found(true)를 통해 지우기에 성공하면, 길이를 줄이고 성공(1),
//     found(false)라고 한다면, 실패(0)을 return.
//---------------------------------------------------------------
{
	if (IsEmpty()) { return 0; }							// (1).
	T curItem;												// (2).
	ResetList();
	int iPos = GetNextItem(curItem);
	bool found = false;
	for (iPos; iPos > 0; iPos = GetNextItem(curItem)) {
		if (!found) {
			if (curItem.Compare_Serial(data) == EQUAL) {
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
	return 0;
}


// Find same record using primary key and replace it.
template <typename T>
int UnSortedList<T>::Replace(T data)
//---------------------------------------------------------------
// (1) 현재 list의 용량을 확인한다.
//	   - list가 비어있으면, 실패(0)을 return.
// (2) 검색, 교체
//	   - GetNextItem을 이용하여, list의 element를 받아들인다.
//	   - 입력받은 데이터의 key가 EQUAL, 해당 자리의 record를 교체.
//		 성공(1)을 return.
// (3) 함수의 끝
// ---------------------------------------------------------------
{
	if (IsEmpty()) { return 0; }							// (1).
	T curItem;												// (2).
	ResetList();
	int iPos = GetNextItem(curItem);
	for (iPos; iPos > 0; iPos = GetNextItem(curItem)) {
		if (curItem.Compare_Serial(data) == EQUAL) {
			m_Array[iPos] = data;
			return 1;
		}
	}
	return 0;												// (3).
}


// Search data in accordance with data's serial number,and refer the record on argument 'data'.
template <typename T>
int UnSortedList<T>::Get(T& data)
//---------------------------------------------------------------
// (1) 현재 list의 용량을 확인한다.
//	   - list가 비어있으면, 실패(0)을 return.
// (2) 검색, 교체
//	   - GetNextItem을 이용하여, list의 element를 받아들인다.
//	   - 입력받은 데이터의 key가 EQUAL, 해당 자리의 record를 refer.
//		 성공(1)을 return.
// (3) 함수의 끝
// ---------------------------------------------------------------
{
	if (IsEmpty()) { return 0; }							// (1).
	T curItem;												// (2).
	ResetList();
	int iPos = GetNextItem(curItem);
	for (iPos; iPos > 0; iPos = GetNextItem(curItem)) {
		if (curItem.Compare_Serial(data) == EQUAL) {
			data = m_Array[iPos];
			return 1;
		}
	}
	return 0;												// (3).
}