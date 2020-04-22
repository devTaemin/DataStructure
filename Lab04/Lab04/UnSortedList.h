#pragma once
#include "pch.h"
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


	~UnSortedList();
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	bool IsEmpty() const;
	//--------------------------------------------------------------------
	//	Brief:	Check whether list's length is 0 or not.
	//	Pre:	none.
	//	Post:	none.
	//	Return:	return true if list is empty, otherwise return false.
	//--------------------------------------------------------------------


	bool IsFull() const;
	//--------------------------------------------------------------------
	//	Brief:	Check the list upper is reached to the limit.
	//	Pre:	none.
	//	Post:	none.
	//	Return:	return true if list capacity reached to the upper bound, 
	//			otherwise return false.
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



	int GetLength() const;
	//--------------------------------------------------------------------
	//	Brief:	Return the number of records in the list.
	//	Pre:	none.
	//	Post:	none.
	//	Return:	number of records in current list.
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


	int Add(const T& inData);
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


	int Replace(const T& data);
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


// Default constructor.
template <typename T>
UnSortedList<T>::UnSortedList() {
	m_Maxsize = MAXLIST;
	m_Length = 0;
	ResetList();
	m_Array = new T[m_Maxsize];
}


// Constructor.
template <typename T>
UnSortedList<T>::UnSortedList(int max)
{
	m_Maxsize = max;
	m_Length = 0;
	ResetList();
	m_Array = new T[m_Maxsize];
}


// Destructor.
template <typename T>
UnSortedList<T>::~UnSortedList()
{
	//delete[] m_Array;
}


// Check whether capacity of list is full.
template <typename T>
bool UnSortedList<T>::IsFull() const
{
	return (m_Length > m_Maxsize - 1);
}


// Check whether capacity of list is empty.
template <typename T>
bool UnSortedList<T>::IsEmpty() const
{
	return (m_Length == 0);
}


// Make list empty.
template <typename T>
void UnSortedList<T>::MakeEmpty()
{
	m_Length = 0;
	delete[] m_Array;
	m_Array = new T[m_Maxsize];
}


// Initialize list iterator.
template <typename T>
void UnSortedList<T>::ResetList()
{
	m_CurPointer = -1;
}


// Get a number of records in current list.
template <typename T>
int UnSortedList<T>::GetLength() const
{
	return m_Length;
}



// Update pointer to point next record, and get the new record.
template <typename T>
int UnSortedList<T>::GetNextItem(T& data)
//---------------------------------------------------------------
// (1) ���� list�� empty���, ����(-1)�� return.
// (2) ���� record�� ����Ű���� Pointer�� increment.
// (3) ���� Pointer�� ������ list�� index�� �ʰ�(=���� ����)�ϸ� 
//	   ����(-1)�� return.
// (4) data�� ���� item�� refer�ϰ� ���� ��ġ �����͸� return.
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
int UnSortedList<T>::Add(const T& inData)
//---------------------------------------------------------------
// (1) ���� list�� full�̶��, ����(0)�� return.
//     ���� list�� empty�̶��, ù�ڸ��� ���� �� ����(1) return.
// (2) �ߺ� �˻縦 ���� GetNextItem�� �̿��Ͽ�, Serial�� ��.
//     - �ߺ��� ���, duplicate�� ��Ÿ����, ����(-1)�� return.
// (3) list�� ���̿� �ش��ϴ� index�� data�� ����, ���� 1����
//     ����(1)�� return.
//---------------------------------------------------------------
{
	if (IsFull()) { return 0; }								// (1).
	T curItem;												// (2).
	ResetList();
	int iPos = GetNextItem(curItem);
	for (iPos; iPos >= 0; iPos = GetNextItem(curItem)) {
		if (curItem == inData) {
			return -1;
		}
	}
	m_Array[m_Length++] = inData;							// (3).
	return 1;
}


// Delete item in accordance with data's primary key.
template <typename T>
int UnSortedList<T>::Delete(T data)
//---------------------------------------------------------------
// (1) ���� list�� empty�̶��, ����(0)�� return.
// (2) ���� item�� ã������ GetNextItem�� �̿��Ͽ�, Serial�� ��.
//     - found(false)�� ���, serial�� ��, ã����� found(true).
//	   - found(true)�� ���, �� ���� �ڸ��� ��ĭ�� �̵�.
// (3) found(true)�� ���� ����⿡ �����ϸ�, ���̸� ���̰� ����(1),
//     found(false)��� �Ѵٸ�, ����(0)�� return.
//---------------------------------------------------------------
{
	if (IsEmpty()) { return 0; }							// (1).
	T curItem;												// (2).
	ResetList();
	int iPos = GetNextItem(curItem);
	bool found = false;
	for (iPos; iPos >= 0; iPos = GetNextItem(curItem)) {
		if (!found) {
			if (curItem == data) {
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
int UnSortedList<T>::Replace(const T& data)
//---------------------------------------------------------------
// (1) ���� list�� �뷮�� Ȯ���Ѵ�.
//	   - list�� ���������, ����(0)�� return.
// (2) �˻�, ��ü
//	   - GetNextItem�� �̿��Ͽ�, list�� element�� �޾Ƶ��δ�.
//	   - �Է¹��� �������� key�� EQUAL, �ش� �ڸ��� record�� ��ü.
//		 ����(1)�� return.
// (3) �Լ��� ��
// ---------------------------------------------------------------
{
	if (IsEmpty()) { return 0; }							// (1).
	T curItem;												// (2).
	ResetList();
	int iPos = GetNextItem(curItem);
	for (iPos; iPos >= 0; iPos = GetNextItem(curItem)) {
		if (curItem == data) {
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
// (1) ���� list�� �뷮�� Ȯ���Ѵ�.
//	   - list�� ���������, ����(0)�� return.
// (2) �˻�, ��ü
//	   - GetNextItem�� �̿��Ͽ�, list�� element�� �޾Ƶ��δ�.
//	   - �Է¹��� �������� key�� EQUAL, �ش� �ڸ��� record�� refer.
//		 ����(1)�� return.
// (3) �Լ��� ��
// ---------------------------------------------------------------
{
	if (IsEmpty()) { return 0; }							// (1).
	T curItem;												// (2).
	ResetList();
	int iPos = GetNextItem(curItem);
	for (iPos; iPos > 0; iPos = GetNextItem(curItem)) {
		if (curItem == data) {
			data = m_Array[iPos];
			return 1;
		}
	}
	return 0;												// (3).
}


