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
	if (m_Length >= MAXSIZE) {
		return true;
	}
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
	m_CurPointer++;							// increment list pointer.
	if (m_CurPointer == MAXSIZE) {			// if list pointer reached to the end; stop and return -1.
		return -1;
	}
	data = m_Array[m_CurPointer];			// copy the current pointer's record.
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
	if (IsEmpty()) {						// check if list is empty or not.
		return -1;							// if list is empty, return -1 and stop the function.
	}

	ResetList();							// before starting to search item, initialize pointer.
	m_CurPointer++;							// set list pointer started from 0. 
	for (m_CurPointer; m_CurPointer < m_Length; m_CurPointer++) {
		if (m_Array[m_CurPointer] == data) {// compare both items.
			data = m_Array[m_CurPointer];	// if both items matches, copy the items.
			return 1;
		}
	}
	cout << "Fail to get item!" << '\n';
	return -1;	// if there's no matching item, return -1 and stop the function
}


// Delete item in accordance with data's student id as a primary key.
int ArrayList::Delete(ItemType data)
{
	if (IsEmpty()) {							// check if list is empty or not.
		return -1;								// if list is empty, return -1 and stop the function.
	}

	bool isFind = false;						// check if matching item is founded or not.
	ResetList();								// before starting to search item, initialize pointer.
	m_CurPointer++;								// set list pointer started from 0. 
	for (m_CurPointer; m_CurPointer < m_Length; m_CurPointer++) {
		if (!isFind) {							// when matching item is not founded yet, and founded in this loop,
			if (m_Array[m_CurPointer] == data)
				isFind = true;					// make isFind true.
		}
		else {									// if matching item is founded, cover the founded space by moving down.
			m_Array[m_CurPointer - 1] = m_Array[m_CurPointer];
		}
	}

	if (isFind) {								// if matching item is founded and deleted, diminish the total length of list.
		m_Length--;
		return 1;
	}
	else {										// if not, display the sign of failure, and return -1.
		cout << "Fail to find and delete item!" << '\n';
		return -1;
	}
}


// Replace item in accordance with data's student id as a primary key.
int ArrayList::Replace(ItemType data)
{
	if (IsEmpty()) {							// check if list is empty or not.
		return -1;								// if list is empty, return -1 and stop the function.
	}

	bool isFind = false;						// check if matching item is founded or not.
	ResetList();								// before starting to search item, initialize pointer.
	m_CurPointer++;								// set list pointer started from 0. 

	for (m_CurPointer; m_CurPointer < m_Length; m_CurPointer++) {
		if (!isFind) {							// when matching item is not founded yet, and founded in this loop,
			if (m_Array[m_CurPointer] == data) {// replace the item by the input item.
				m_Array[m_CurPointer] = data;	
				isFind = true;
				break;
			}
		}
	}

	if (isFind) {								// if matching item is founded, return 1.
		return 1;
	}
	else {										// if not, display the sign of failure, and return -1.
		cout << "Fail to find and replace item!" << '\n';
		return -1;
	}
}