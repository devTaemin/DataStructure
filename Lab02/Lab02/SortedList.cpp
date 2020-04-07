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
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
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

	if (IsFull()) return 0;									// (1).
	if (m_Length == 0) {    	
		m_Array[m_Length++] = inData;
		return 1;
	}
	
	int iPos = 0;											// (2).
	bool found = false;
	ItemType curItem;
	ResetList();
	iPos = GetNextItem(curItem);							// (3).
	while (iPos > -1 && !found)								
	{
		switch (curItem.Compare(inData))
		{
		case EQUAL:
			cout << " %%% same item exist in the list %%%\n";
			return 0;
		case GREATER:
			found = true;
			break;
		case LESS:
			iPos = GetNextItem(curItem);
			break;
		}
	}

	
	if (iPos == -1) {										// (4).
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


// Find the item whose type matches with the data's type.
int SortedList::Retrieve_SeqS_Type(ItemType& data)
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
		switch (CurItem.Compare_Type(data))
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


// Find the item whose name matches with the data's name.
int SortedList::Retrieve_SeqS_Name(ItemType& data)
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
		switch (CurItem.Compare_Name(data))
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
	if (Retrieve_SeqS(data))									// (1).
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
	// (1) �Է¹��� item ���.
	// (2) �˻�, ��ü
	//	   - List���� data�� �˻��Ѵ�. 
	//	   [1] ã�� �Ǹ�, ����(1) return.
	//	   [2] ����(0) return.
	// ---------------------------------------------------------------
	ItemType tmp(data);											// (1)

	if (Retrieve_SeqS(data))									// (2)
	{
		m_Array[m_CurPointer] = tmp;	
		return 1;	
	}
	return 0;	
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
	if (m_Length == 0)											// (1).
		return 0;												// (2).
	int currentPos = m_Length / 2;								// (3).
	while (1)
	{
		switch (m_Array[currentPos].Compare(data))
		{
		case EQUAL:	
			data = m_Array[currentPos];	
			return 1;	
			break;
		case GREATER:	
			if (currentPos == 0)
				return 0;	
			currentPos /= 2;	
			break;
		case LESS:	 
			if (currentPos == m_Length - 1)
				return 0;	
			currentPos = (currentPos + m_Length) / 2;	
			break;
		}
	}
	return 0;													// (4).
}
