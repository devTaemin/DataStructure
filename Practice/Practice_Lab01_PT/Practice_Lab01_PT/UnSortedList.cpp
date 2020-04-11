#include "UnSortedList.h"


void UnSortedList::MakeEmpty()
{
	m_Length = 0;
}


int UnSortedList::GetLength() const
{
	return m_Length;
}


bool UnSortedList::IsFull()
{
	if (m_Length == MAXSIZE)
		return true;
	return false;
}


bool UnSortedList::IsEmpty()
{
	if (m_Length == 0)
		return true;
	return false;
}


int UnSortedList::Add(ItemType inData)
{
	if (!IsFull()) {
		ItemType item;
		ResetList();
		int iPos = GetNextItem(item);
		for (iPos; iPos > 0; iPos = GetNextItem(item)) {
			if (item.CompareByID(inData) == EQUAL) {
				return -1;
			}
		}
		m_Array[m_Length++] = inData;
		return 1;
	}
	return 0;
}


void UnSortedList::ResetList()
{
	m_CurPointer = -1;
}


int UnSortedList::GetNextItem(ItemType& data)
{
	m_CurPointer++;
	if (m_CurPointer > m_Length - 1) {
		return 0;
	}
	data = m_Array[m_CurPointer];
	return 1;
}


int UnSortedList::Get(ItemType& data)
{
	ItemType item;
	ResetList();
	int iPos = GetNextItem(item);
	for (iPos; iPos > 0; iPos = GetNextItem(item)) {
		if (item.CompareByID(data) == EQUAL) {
			data = item;
			return 1;
		}
	}
	return 0;
}


int UnSortedList::Delete(ItemType data)
{
	ItemType item;
	bool found = false;
	ResetList();
	int iPos = GetNextItem(item);
	for (iPos; iPos > 0; iPos = GetNextItem(item)) {
		if (!found) {
			if (item.CompareByID(data) == EQUAL) {
				found = true;
			}
		}
		else {
			m_Array[m_CurPointer - 1] = m_Array[m_CurPointer];
		}
	}

	if (!found) { return 0; }
	else {
		m_Length--;
		return 1;
	}
}


int UnSortedList::Replace(ItemType data)
{
	ItemType item;
	ResetList();
	int iPos = GetNextItem(item);
	for (iPos; iPos > 0; iPos = GetNextItem(item)) {
		if (item.CompareByID(data) == EQUAL) {
			m_Array[m_CurPointer] = data;
			return 1;
		}
	}
	return 0;
}