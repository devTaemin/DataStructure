#include "SortedList.h"


void SortedList::MakeEmpty()
{
	m_Length = 0;
}


int SortedList::GetLength() const
{
	return m_Length;
}


bool SortedList::IsFull() const
{
	if (m_Length == MAXSIZE)
		return true;
	return false;
}


bool SortedList::IsEmpty() const
{
	if (m_Length == 0)
		return true;
	return false;
}


void SortedList::ResetList()
{
	m_CurPointer = -1;
}


int SortedList::GetNextItem(ItemType& data)
{
	m_CurPointer++;
	if (m_CurPointer > m_Length - 1) {
		return 0;
	}
	data = m_Array[m_CurPointer];
	return 1;
}


int SortedList::Get(ItemType& data)
{
	if (!IsEmpty())
	{
		ItemType item;
		ResetList();
		int iPos = GetNextItem(item);
		for (iPos; iPos > 0; iPos = GetNextItem(item)) {
			if (item.CompareBySerial(data) == EQUAL) {
				data = item;
				return 1;
			}
		}
		return -1;
	}
	return 0;
}


int SortedList::Add(ItemType inData) // Retrieve함수를 이용하여 구현 가능.
{
	if (IsFull()) { return 0; }
	if (IsEmpty()) {
		m_Array[m_Length++] = inData;
		return 1;
	}

	ItemType item;
	ResetList();
	int iPos = GetNextItem(item);
	bool duplicate = false;
	for (iPos; iPos > 0; iPos = GetNextItem(item)) {
		RelationType result = item.CompareBySerial(inData);
		if (result == EQUAL) {
			duplicate = true;
			break;
		}
		else if (result == GREATER) {
			break;
		}
		else { continue; }
	}

	if (duplicate) { return -1; }
	else {
		for (int i = m_Length; i > m_CurPointer; i--) {
			m_Array[i] = m_Array[i - 1];
		}
		m_Array[m_CurPointer] = inData;
		m_Length++;
		return 1;
	}	
}


int SortedList::Delete(ItemType data)  // Retrieve 함수를 이용하여 구현 가능.
{
	if (IsEmpty()) { return 0; }

	ItemType item;
	ResetList();
	int iPos = GetNextItem(item);
	for (iPos; iPos > 0; iPos = GetNextItem(item)) {
		RelationType result = item.CompareBySerial(data);
		if (result == EQUAL) {
			break;
		}
		else if (result == GREATER) {
			return -1;
		}
		else { continue; }
	}

	for (int i = m_CurPointer; i < m_Length - 1; i++) {
		m_Array[i] = m_Array[i + 1];
	}
	m_Length--;
	return 1;
}


int SortedList::Replace(ItemType data)
{
	if (!IsEmpty())
	{
		ItemType item;
		ResetList();
		int iPos = GetNextItem(item);
		for (iPos; iPos > 0; iPos = GetNextItem(item)) {
			if (item.CompareBySerial(data) == EQUAL) {
				m_Array[m_CurPointer] = data;
				return 1;
			}
		}
		return -1;
	}
	return 0;
}


int SortedList::Retrieve_SeqS(ItemType& target)
{
	if (IsEmpty()) { return 0; }
	
	ItemType item;
	ResetList();
	int iPos = GetNextItem(item);
	for (iPos; iPos > 0; iPos = GetNextItem(item)) {
		RelationType result = item.CompareBySerial(target);
		if (result == EQUAL) {
			target = item;
			return 1;
		}
		else if (result == GREATER) {
			return -1;
		}
		else {
			continue;
		}
	}
}


int SortedList::RetrieveByBS(ItemType& target)
{
	if (!IsEmpty())
	{
		bool found = false;
		bool quit = false;
		m_CurPointer = m_Length / 2;
		
		while (!quit)
		{
			ItemType item = m_Array[m_CurPointer];
			RelationType result = item.CompareBySerial(target);
			switch (result)
			{
			case EQUAL:
				target = item;
				found = true;
				quit = true;
				break;
			case GREATER:
				if (m_CurPointer == 0) { quit = true; }
				else { m_CurPointer /= 2; }
				break;
			case LESS:
				if (m_CurPointer == m_Length - 1) { quit = true; }
				else { m_CurPointer = (m_CurPointer + m_Length) / 2; }
				break;
			default:
				break;
			}
		}
		if (found) { return 1; }
		else { return -1; }
	}
	return 0;
}



