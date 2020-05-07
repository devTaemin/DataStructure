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
// (1) ���� list�� empty���, ����(-1)�� return.
// (2) ���� record�� ����Ű���� Pointer�� increment.
// (3) ���� Pointer�� ������ list�� index�� �ʰ�(=���� ����)�ϸ� 
//	   ����(-1)�� return.
// (4) data�� ���� item�� refer�ϰ� ���� ��ġ �����͸� return.
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
// (1) ���� list�� �뷮�� Ȯ���Ѵ�.
//	   - �� ä�������� ���, ����(0)�� return.
//	   - �� ���, ù �ڸ� ����, ���� ����, ����(1) return.
// (2) �˻�, ���� ��ġ�� ã�� ���� GetNextItem�� ����Ѵ�.
//	   - GetNextItem�� �̿��Ͽ�, ����(0 or -1)�� ���ö����� loop.
//	   - �Էµ� �������� Serial�� '�ߺ�'�Ǵ� ���, ����(-1)�� return.
//     - �Էµ� �������� Serial�� �� ���� ���, break.
//     - �Էµ� �������� Serial�� �� ū ���, continue.
// (3) ���ĸ���Ʈ, ����
//	   - m_Length�� �̿��Ͽ�, ���Ե� ��ġ ������ ������ �ϳ��� 
//       �о �̵����ش�.
//     - ����, ���� ������ data�� �־��ش�.
//     - ������ �Ǿ����Ƿ�, ����Ʈ�� ���̸� �������ش�.
//     - ����(1)�� return.
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
	if (found) { return -1; } // �ߺ����� ���� ����(-1)


	if (IsEmpty()) {//�Ǿ� �Է�
		m_List[m_Length++] = _data;
		return 1;
	}
	for (int i = 0; i < m_Length; i++) {//�߰� �Է�
		if (m_List[i] > _data) { // ��������
			for (int j = m_Length; j > i; j--) {
				m_List[j] = m_List[j - 1];
			}
			m_List[i] = _data;
			m_Length++;
			return 1;
		}
	}
	m_List[m_Length++] = _data; // �� �Է�
	return 1;
}

// Delete item in accordance with data's primary key.
template<typename T>
int SortedList<T>::Delete(T& _data)
//---------------------------------------------------------------
// (1) ���� list�� �뷮�� Ȯ���Ѵ�.
//	   - list�� ���������, ����(0)�� return.
// (2) �˻�
//	   - GetNextItem�� �̿��Ͽ�, list�� element�� �޾ƿ� ���̴�.
//	   - found(false)�� ���, �Էµ� �����Ϳ�, ����Ʈ�� element�� 
//		 Serial�� ���Ѵ�. ���� ���, found = true�� �����Ѵ�.
//     - found(true)�� ���, ���� Pointer���� �ش� �����͸� ã�� ��
//		 �̱� ������, �� ���� list�� index�� ���� element�� �̵��Ͽ�
//       ���� �����ش�.
// (3) found(true)���, ���̸� 1���̰�, ����(1)�� return.
//	   found(false)���, ����(0)�� return.
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
// (1) ���� list�� �뷮�� Ȯ���Ѵ�.
//	   - list�� ���������, ����(0)�� return.
// (2) �˻�, ��ü
//	   - GetNextItem�� �̿��Ͽ�, list�� element�� �޾Ƶ��δ�.
//	   - �Է¹��� �������� key�� EQUAL, �ش� �ڸ��� record�� ��ü.
//		 ����(1)�� return.
//	   - �Է¹��� �������� key�� LESS,����Ʈ�� ����(0)�� return.
//     - �Է¹��� �������� key�� GREATER, ���� item�� ��.
// (3) �Լ��� ��
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
// (1) ���� list�� �뷮�� Ȯ���Ѵ�.
//	   - list�� ���������, ����(0)�� return.
// (2) �˻�, ����
//	   - GetNextItem�� �̿��Ͽ�, list�� element�� �޾Ƶ��δ�.
//	   - �Է¹��� �������� key�� EQUAL, �ش� �ڸ��� record�� refer.
//		 ����(1)�� return.
//	   - �Է¹��� �������� key�� LESS,����Ʈ�� ����(0)�� return.
//     - �Է¹��� �������� key�� GREATER, ���� item�� ��.
// (3) �Լ��� ��
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
// (1) ���� list�� �뷮�� Ȯ���Ѵ�.
//	   - list�� ���������, ����(0)�� return.
// (2) ���� ����Ʈ, 2�� �˻� ����.
//     - �������� �迭�� �߰� �������� ����.
//	   - Relation EQUAL �� ���
//		 [1] �ش� ������ item�� ��ȯ�ϰ�, ����(1)�� return.
//	   - Relation GREATER �� ���
//		 [1] ���� �����Ͱ� ����Ʈ�� ù �����̸�, ����(0)�� return.
//		 [2] �ƴ� ���, �ش� ������ ù ������ ���̷� Position �̵�.
//	   - Relation LESS �� ���
//		 [1] ���� �����Ͱ� ����Ʈ�� �������̸�, ����(0)�� return.
//		 [2] �ƴ� ���, �ش� ������ �� ������ ���̷� Position �̵�.
// (4) �Լ��� �����ϸ�, ����(0)�� return.
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