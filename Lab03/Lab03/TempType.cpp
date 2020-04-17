#include "pch.h"


// Default Constructor.
TempType::TempType()
{
	numOfItems = 0;
}


// Destructor.
TempType::~TempType() {}


// Check whether CircularQueue is full.
bool TempType::IsFull() const
{
	return tItemList.IsFull();
}


// Check whether CircularQueue is empty.
bool TempType::IsEmpty() const
{
	return tItemList.IsEmpty();
}


// Get number of items in tItemList.
int TempType::GetNumOfItems() const
{
	return numOfItems;
}



// Adds new data to the last of the queue.
int TempType::Enqueue(ItemType data)
{
	if (tItemList.EnQueue(data)) {
		numOfItems++;
		return 1;
	}
	return 0;
}


// Delete data from the first of the queue.
int TempType::Dequeue(ItemType& data)
{
	if (tItemList.DeQueue(data)) {
		numOfItems--;
		return 1;
	}
	return 0;
}


// Display number of items in tItemList.
void TempType::DisplayNumOfItems()
{
	cout << "\tNumber  : " << numOfItems << '\n';
}


// Display all items in tItemList.
void TempType::DisplayAllItems()
{
	ItemType curItem;
	tItemList.ResetList();
	int iPos = tItemList.GetNextItem(curItem);
	for (iPos; iPos >= 0; iPos = tItemList.GetNextItem(curItem)) {
		cout << '\n';
		curItem.DisplaySerialOnScreen();
		curItem.DisplayNameOnScreen();
		curItem.DisplayNumOnScreen();
		curItem.DisplayUsageOnScreen();
		curItem.DisplayDateOnScreen();
	}
}

