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
	m_CurPointer++;							// increment list pointer.
	if (m_CurPointer == MAXSIZE) {			// if list pointer reached to the end; stop and return -1.
		return -1;
	}
	data = m_Array[m_CurPointer];			// copy the current pointer's record.
	return m_CurPointer;
}


// Add a new data into list.
int SortedList::Add(ItemType data)
{
	if (!IsFull()) {
		m_Array[m_Length++] = data;
		return 1;
	}
	return -1;
}


// Delete item in accordance with data's primary key.
int SortedList::Delete(ItemType data)
{
	if (IsEmpty()) {							// check if list is empty or not.
		return 0;								// if list is empty, return 0 and stop the function.
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
	else {										// if not, display the sign of failure, and return 0.
		cout << "\tFail to find and delete item!" << '\n';
		return 0;
	}
}


// Find same record using primary key and replace it.
int SortedList::Replace(ItemType data)
{
	if (IsEmpty()) {							// check if list is empty or not.
		return 0;								// if list is empty, return 0 and stop the function.
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
	else {										// if not, display the sign of failure, and return 0.
		cout << "\tFail to find and replace item!" << '\n';
		return 0;
	}
}


// Find the item whose primary key matches with the primary 
int SortedList::Retrieve(ItemType& target)
{

}



// Retrieve by using binary search.
int SortedList::RetrieveByBS(ItemType& data)
{

}

