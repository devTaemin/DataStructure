#include "ArrayList.h"


// Make list empty.
void ArrayList::MakeEmpty()
{
	m_Length = 0;
}


// Get a number of records in current list.
int ArrayList::GetLength()
{
	return m_Length;
}


// Check whether capacity of list is full.
bool ArrayList::IsFull()
{
	if (m_Length == MAXSIZE)
		return true;
	return false;
}


// add a new data into list.
int ArrayList::Add(ItemType data)
{
	if (!IsFull()) {
		m_Array[m_Length++] = data;
		return 1;
	}
	return -1;
}


// Initialize list iterator.
void ArrayList::ResetList()
{
	m_CurPointer = -1;
}


// move list iterator to the next item in list and get that item.
int ArrayList::GetNextItem(ItemType& data)
{
	ResetList();
	m_CurPointer++;
	if (m_CurPointer == MAXSIZE) {
		return -1;
	}
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}


// Check whether list is empty.
bool ArrayList::IsEmpty()
{
	if (m_Length == 0) {
		return true;
	}
	return false;
}


// Search item in accordance with data's student id as a primary key.
int ArrayList::Get(ItemType& data)
{
	ResetList();
	m_CurPointer++;
	for (m_CurPointer; m_CurPointer < m_Length; m_CurPointer++) {
		if (m_Array[m_CurPointer] == data) {
			data = m_Array[m_CurPointer];
			return 1;
		}
	}
	return -1;
}


// Delete item in accordance with data's student id as a primary key.
int ArrayList::Delete(ItemType data)
{
	bool isFind = false;
	ResetList();
	m_CurPointer++;
	for (m_CurPointer; m_CurPointer < m_Length; m_CurPointer++) {
		if (!isFind) {
			if (m_Array[m_CurPointer] == data)
				isFind = true;
		}
		else {
			m_Array[m_CurPointer - 1] = m_Array[m_CurPointer];
		}
	}

	if (isFind) {
		return 1;
	}
	else {
		return -1;
	}
}


// Replace item in accordance with data's student id as a primary key.
int ArrayList::Replace(ItemType data)
{
	bool isFind = false;
	ResetList();
	m_CurPointer++;

	for (m_CurPointer; m_CurPointer < m_Length; m_CurPointer++) {
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
		return -1;
	}
}