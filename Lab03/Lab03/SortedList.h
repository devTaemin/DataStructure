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
int SortedList<T>::Add(T data)
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


