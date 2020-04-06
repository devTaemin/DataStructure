#include "SortedList.h"

// Make list empty. (Initialize list)
void SortedList::MakeEmpty()
{
	m_Length = 0;
}


// Return the number of records in the list.
int SortedList::GetLength()
{
	return m_Length;
}


// Check the list upper is reached to the limit.
bool SortedList::IsFull()
{
	if (m_Length >= MAXSIZE) {
		return true;
	}
	return false;
}


// Check the list is empty.
bool SortedList::IsEmpty()
{
	if (m_Length == 0) {
		return true;
	}
	return false;
}


// Initialize the list iterator.
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
	// ---------------------------------------------------------------
	m_CurPointer++;												// (1).
	if (m_CurPointer == MAXSIZE) {								// (2).
		return -1;
	}
	data = m_Array[m_CurPointer];								// (3).
	return m_CurPointer;										// (4).
}


// Add a new data into list.
int SortedList::Add(ItemType data)
{
	//---------------------------------------------------------------
	// (1) ���� list�� �뷮�� Ȯ���Ѵ�.
	//	   - �� ä�������� ���, ����(0)�� return.
	//	   - �� ���, ù �ڸ� ����, ���� ����, ����(1) return.
	// (2) ���� ��ġ�� ã�� ����, GetNextItem�� ����Ѵ�
	//	   - Position�� ������ ����, �˻� Ȯ���ϴ� ���� found ����.
	//	   - List���� �޾ƿ� item�� ������ ���� temp ����.
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

	if (IsFull()) { return 0; }									// (1).
	if (IsEmpty()) {
		m_Array[m_Length++] = data;
		return 1;
	}

	int Position = 0;											// (2).
	bool found = false;
	ItemType temp;
	ResetList();
	Position = GetNextItem(temp);

	while (Position > -1 && !found)								// (3).
	{
		switch (temp.Compare(data))
		{
		case EQUAL:
			cout << "\tError: duplicated item in the list\n";
			return 0;
		case GREATER:
			found = true;
			break;
		case LESS:
			Position = GetNextItem(temp);
			break;
		}
	}

	if (Position == -1) {										// (4).
		m_Array[m_Length++] = data;
		return 1;
	}

	for (int i = m_Length; i > Position; i--) {					// (5).
		m_Array[i] = m_Array[i - 1];
	}
	m_Array[Position] = data;
	m_Length++;
	return 1;
}


// Delete item in accordance with data's primary key.
int SortedList::Delete(ItemType data)
{
	//---------------------------------------------------------------
	// (1) List�� ����ִ��� Ȯ��. ��������� ���� ����(0)�� return.
	// (2) List�� ������� �ʴ� ���,
	//	   - List���� data�� �˻��Ѵ�. 
	//	   [1] ����(1) return��, ���� data�� �̵��ϰ� ���̸� ���δ�.
	//	   [2] ����(0) return.
	// ---------------------------------------------------------------
	if (IsEmpty()) { return 0; }								// (1).
	else {														// (2).
		if (Retrieve_SeqS(data)) {
			for (int i = m_CurPointer; i < m_Length; i++) {
				m_Array[i] = m_Array[i + 1];
			}
			m_Length--;
			return 1;
		}
		else { return 0; }
	}
}


// Find same record using primary key and replace it.
int SortedList::Replace(ItemType data)
{
	//---------------------------------------------------------------
	// (1) List�� ����ִ��� Ȯ��. ��������� ���� ����(0)�� return.
	// (2) �˻� Ȯ�� ���� isFind, ������ �ʱ�ȭ
	// (3) �˻�, ��ü
	//	   - List���� data�� �˻��Ѵ�. 
	//	   [1] ã�� �Ǹ�, ����(1) return.
	//	   [2] ����(0) return.
	// ---------------------------------------------------------------
	if (IsEmpty()) { return 0; }								// (1).

	bool isFind = false;										// (2).
	ResetList();
	m_CurPointer++;

	for (m_CurPointer; m_CurPointer < m_Length; m_CurPointer++) {// (3).
		if (!isFind) {
			if (m_Array[m_CurPointer] == data) {
				m_Array[m_CurPointer] = data;
				isFind = true;
				break;
			}
		}
	}

	if (isFind) {
		return 1;
	}
	else {
		cout << "\tFail to find and replace item!" << '\n';
		return 0;
	}
}


// Find the item whose primary key matches with the primary 
int SortedList::Retrieve_SeqS(ItemType& data)
{
	//---------------------------------------------------------------
	// (1) List�� element�� �޾ƿ� ItemType CurItem ����.
	// (2) List�� Current Pointer �ʱ�ȭ.
	// (3) List�� ù��° item�� �޾ƿ�.
	// (4) ���� ����Ʈ, �˻� ����
	//	   - case LESS  �� ���, ���� item�� �޾ƿ´�.
	//	   - case EQUAL �� ���, item�� ��ȯ�ϰ�, 1�� return�Ѵ�.
	//	   - case GRETER�� ���, item�� �����Ƿ�, 0�� return�Ѵ�.
	// (5) �Լ��� �����ϸ�, 0�� return�Ѵ�.
	// ---------------------------------------------------------------
	ItemType CurItem;											// (1).
	ResetList();												// (2).
	GetNextItem(CurItem);										// (3).

	while (m_CurPointer < m_Length)								// (4).
	{
		switch (CurItem.Compare(data))
		{
		case EQUAL:
			data = CurItem;
			return 1;
			break;
		case GREATER:
			return 0;
			break;
		default:
			GetNextItem(CurItem);
			break;
		}
	}
	return 0;													// (5).
}



// Retrieve by using binary search.
int SortedList::RetrieveByBS(ItemType& data)
{
	//---------------------------------------------------------------
	// (1) List�� ���������, ����(0)�� return�Ѵ�.
	// (2) �������� �迭�� �߰� �������� ����.
	// (3) ���� ����Ʈ, 2�� �˻� ����.
	//	   - case LESS �� ���
	//		 [1] ���� �����Ͱ� ����Ʈ�� �������̸�, ����(0)�� return.
	//		 [2] �ƴ� ���, �ش� ������ �� ������ ���̷� Position �̵�.
	//	   - case EQUAL �� ���
	//		 [1] �ش� ������ item�� ��ȯ�ϰ�, ����(1)�� return.
	//	   - case GREATER �� ���
	//		 [1] ���� �����Ͱ� ����Ʈ�� ù �����̸�, ����(0)�� return.
	//		 [2] �ƴ� ���, �ش� ������ ù ������ ���̷� Position �̵�.
	// (4) �Լ��� �����ϸ�, ����(0)�� return.
	// ---------------------------------------------------------------
	if (IsEmpty()) { return 0; }								// (1).
	int curPosition = m_Length / 2;								// (2).
	while (1)													// (3).
	{
		switch (m_Array[curPosition].Compare(data))
		{
		case EQUAL:
			data = m_Array[curPosition];
			return 1;
			break;
		case GREATER:
			if (curPosition == 0)
				return 0;
			curPosition /= 2;
			break;
		case LESS:
			if (curPosition == m_Length - 1)
				return 0;
			curPosition = (curPosition + m_Length) / 2;
			break;
		}
	}
	return 0;													 // (4).

}

