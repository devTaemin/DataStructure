#include "SortedList.h"


// Make list empty.
void SortedList::MakeEmpty()
{
	m_Length = 0;
}


// Get a number of records in current list.
int SortedList::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
bool SortedList::IsFull()
{
	if (m_Length >= MAXSIZE)
		return true;
	else
		return false;
}


// Check whether list is empty or not.
bool SortedList::IsEmpty()
{
	if (m_Length == 0)
		return true;
	else
		return false;
}


// Initialize list iterator.
void SortedList::ResetList()
{
	m_CurPointer = -1;
}


// Update pointer to point to next record, and get that new record.
int SortedList::GetNextItem(ItemType& data)
{
	//---------------------------------------------------------------
	// (1) ���� Pointer�� increment�Ͽ� ���� item�� index�� ����Ų��.
	// (2) Pointer�� capacity�� �Ѿ��, ����(-1)�� return.
	// (3) List���� �ش� index�� data�� �����´�.
	// (4) ���� ��ġ�� ����Ѵ�.
	//---------------------------------------------------------------
	m_CurPointer++;												// (1).
	if (m_CurPointer == m_Length)								// (2).
		return -1;
	data = m_Array[m_CurPointer];								// (3).
	return m_CurPointer;										// (4).
}


// Add a new data into list.
int SortedList::Add(ItemType inData)
{
	//---------------------------------------------------------------
	// (1) ���� list�� �뷮�� Ȯ���Ѵ�.
	//	   - �� ä�������� ���, ����(0)�� return.
	//	   - �� ���, ù �ڸ� ����, ���� ����, ����(1) return.
	// (2) ���� ��ġ�� ã�� ����, GetNextItem�� ����Ѵ�
	//	   - Position�� ������ ����, �˻� Ȯ���ϴ� ���� found ����.
	//	   - List���� �޾ƿ� item�� ������ ���� curItem ����.
	//	   - ResetList(), ������ �ʱ�ȭ
	//	   - Position�� �������� ����, ���� �����ϸ� -1.
	// (3) ���ĸ���Ʈ, ������ ���� ��ġ �ľ��ϱ�.
	//	   - case EQUAL, �ߺ��� item�� �����ϹǷ� ����(0) return.
	//	   - case GREATER, ����Ʈ�� ��� item�� �� ũ�Ƿ� ����x, ����(0)
	//	   - case LESS, ���� item�� �޾ƿ´�.
	// (4) ����
	//	   - �˻��� ���� ���� ���, �� ������ �����Ѵ�. ����(1).
	//	   - �߰��� ���Ե� ���, �Ĺ� �����͸� �̵��ϰ� ����. ����(1).
	// ---------------------------------------------------------------

	if (IsFull()) return 0;										// (1).
	if (IsEmpty()) {    	
		m_Array[m_Length++] = inData;
		return 1;
	}
	
	ItemType CurItem;											// (2).
	ResetList();
	bool found = false;
	int iPos = GetNextItem(CurItem);

	for (iPos; iPos > -1 && !found; iPos = GetNextItem(CurItem))// (3).
	{
		RelationType Relation = CurItem.Compare_Serial(inData);
		if (Relation == EQUAL) {
			cout << "<========| Error: Aleady Stored |========>" << endl;
			return 0;
		}
		else if (Relation == GREATER) {
			found = true;
			break;
		}
		else {
		continue;
		}
	}


	if (iPos == -1) {											// (4).
		m_Array[m_Length++] = inData;
		return 1;
	}

	for (int i = m_Length; i > iPos; i--) {
		m_Array[i] = m_Array[i - 1];
	}
	m_Array[iPos] = inData;
	m_Length++;

	return 1;
}


// Delete item in accordance with data's primary key.
int SortedList::Delete(ItemType data)
{
	//---------------------------------------------------------------
	// (1) ���� Ž������.
	// (2) List�� ������� �ʴ� ���,
	//	   - List���� data�� �˻��Ѵ�. 
	//	   [1] ����(1) return��, ���� data�� �̵��ϰ� ���̸� ���δ�.
	//	   [2] ����(0) return.
	// ---------------------------------------------------------------
	if (RetrieveByBS(data))										// (1).
	{
		for (int i = m_CurPointer; i < m_Length; i++)			// (2).
			m_Array[i] = m_Array[i + 1];
		m_Length--;
		return 1;
	}
	return 0;
}


// Find same record using primary key and replace it.
int SortedList::Replace(ItemType data)
{
	//---------------------------------------------------------------
	// (1) �Է¹��� item ���. �˻� ��, ������ �ʱ�ȭ.
	// (2) �˻�, ��ü
	//	   - List���� data�� �˻��Ѵ�. 
	//	   [1] ã�� �Ǹ�, ����(1) return.
	//	   [2] ����(0) return.
	// ---------------------------------------------------------------
	ItemType temp(data);										// (1).
	if (RetrieveByBS(data))										// (2).
	{
		m_Array[m_CurPointer] = temp;
		return 1;
	}
	return 0;
}


// Find the item whose primary key matches with the primary 
int SortedList::Retrieve_SeqS(ItemType& data)
{
	//---------------------------------------------------------------
	// (1) List�� element�� �޾ƿ� ItemType CurItem ����.
	// (2) List�� Current Pointer �ʱ�ȭ.
	// (3) List�� ù��° item�� �޾ƿ�.
	// (4) ���� ����Ʈ, �˻� ����
	//	   - Relation LESS  �� ���, ���� item�� �޾ƿ´�.
	//	   - Relation EQUAL �� ���, item�� ��ȯ�ϰ�, 1�� return�Ѵ�.
	//	   - Relation GRETER�� ���, item�� �����Ƿ�, 0�� return�Ѵ�.
	// (5) �Լ��� �����ϸ�, 0�� return�Ѵ�.
	// ---------------------------------------------------------------
	ItemType CurItem;											// (1).
	ResetList();												// (2).
	int iPos = GetNextItem(CurItem);							// (3).

	for (iPos; iPos > -1; iPos = GetNextItem(CurItem))			// (4).
	{
		RelationType Relation = CurItem.Compare_Serial(data);
		if (Relation == EQUAL) {
			data = m_Array[iPos];
			return 1;
		}
		else if (Relation == GREATER) {
			return 0;
		}
		else {
			continue;
		}
	}
	return 0;													// (5).
}

/*
// Find the item whose type matches with the data's type.
int SortedList::Retrieve_SeqS_Type(ItemType& data)
{
	//---------------------------------------------------------------
	// (1) List�� element�� �޾ƿ� ItemType CurItem ����.
	// (2) List�� Current Pointer �ʱ�ȭ.
	// (3) List�� ù��° item�� �޾ƿ�.
	// (4) ���� ����Ʈ, �˻� ����
	//	   - iPos�� -1(�������� �������� �˻��Ѵ�.)
	//	   - Relation EQUAL �� ���, item�� ��ȯ�ϰ�, 1�� return�Ѵ�.
	//	   - else �� ���, continue.
	// (5) �Լ��� �����ϸ�, 0�� return�Ѵ�.
	// ---------------------------------------------------------------
	ItemType CurItem;											// (1).
	ResetList();												// (2).
	int iPos = GetNextItem(CurItem);							// (3).

	for (iPos; iPos > -1; iPos = GetNextItem(CurItem))			// (4).
	{
		RelationType Relation = CurItem.Compare_Type(data);
		if (Relation == EQUAL) {
			data = m_Array[iPos];
			return 1;
		}
		else {
			continue; // �� ������ loop�� ���� �� �ִ� ����� ã�ƾ���.
		}
	}
	return 0;													// (5).
}


// Find the item whose name matches with the data's name.
int SortedList::Retrieve_SeqS_Name(ItemType& data)
{
	//---------------------------------------------------------------
	// (1) List�� element�� �޾ƿ� ItemType CurItem ����.
	// (2) List�� Current Pointer �ʱ�ȭ.
	// (3) List�� ù��° item�� �޾ƿ�.
	// (4) ���� ����Ʈ, �˻� ����
	//	   - iPos�� -1(�������� �������� �˻��Ѵ�.)
	//	   - case EQUAL �� ���, item�� ��ȯ�ϰ�, 1�� return�Ѵ�.
	//	   - else�� ��� continue.
	// (5) �Լ��� �����ϸ�, 0�� return�Ѵ�.
	// ---------------------------------------------------------------
	ItemType CurItem;											// (1).
	ResetList();												// (2).
	int iPos = GetNextItem(CurItem);							// (3).
	bool found = false;

	for (iPos; iPos > -1; iPos = GetNextItem(CurItem))			// (4).
	{
		RelationType Relation = CurItem.Compare_Name(data);
		if (Relation == EQUAL) {
			data = m_Array[iPos];
			return 1;
		}
		else {
			continue; // �� ������ loop�� ���� �� �ִ� ����� ã�ƾ���.
		}
	}
	return 0;													// (5).
}
*/



// Retrieve by using binary search.
int SortedList::RetrieveByBS(ItemType& data)
{
	//---------------------------------------------------------------
	// (1) List�� ���������, ����(0)�� return�Ѵ�.
	// (2) �������� �迭�� �߰� �������� ����.
	// (3) ���� ����Ʈ, 2�� �˻� ����.
	//	   - Relation LESS �� ���
	//		 [1] ���� �����Ͱ� ����Ʈ�� �������̸�, ����(0)�� return.
	//		 [2] �ƴ� ���, �ش� ������ �� ������ ���̷� Position �̵�.
	//	   - Relation EQUAL �� ���
	//		 [1] �ش� ������ item�� ��ȯ�ϰ�, ����(1)�� return.
	//	   - Relation GREATER �� ���
	//		 [1] ���� �����Ͱ� ����Ʈ�� ù �����̸�, ����(0)�� return.
	//		 [2] �ƴ� ���, �ش� ������ ù ������ ���̷� Position �̵�.
	// (4) �Լ��� �����ϸ�, ����(0)�� return.
	// ---------------------------------------------------------------
	if (IsEmpty()) { return 0; }								// (1).
	int iPos = m_Length / 2;									// (2).
	while (1)													// (3).
	{
		ItemType CurItem = m_Array[iPos];
		RelationType Relation = CurItem.Compare_Serial(data);
		if (Relation == EQUAL) {
			data = m_Array[iPos];
			m_CurPointer = iPos;		// Replace �Լ��� ����ϱ�����.
			return 1;
		}
		else if (Relation == GREATER) {
			if (iPos <= 0) { return 0; }
			iPos /= 2;
		}
		else {
			if (iPos >= m_Length - 1) { return 0; }
			iPos = (iPos + m_Length) / 2;
		}
	}
	return 0;												// (4).
}
