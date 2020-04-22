#pragma once
#include "pch.h"
class TempType
{
private:
	int numOfItems;
	CircularQueue<ItemType> tItemList;


public:
	TempType()
	{
		numOfItems = 0;
	}
	~TempType(){}

	bool IsFull() const
	{
		return tItemList.IsFull();
	}
	bool IsEmpty() const
	{
		return tItemList.IsEmpty();
	}
	int GetNumOfItems() const
	{
		return numOfItems;
	}
	int Enqueue(ItemType data)
	{
		if (tItemList.EnQueue(data)) { return 1; }
		return 0;
	}
	int Dequeue(ItemType& data)
	{
		if (tItemList.DeQueue(data)) { return 1; }
		return 0;
	}
	void DisplayNumOfItems()
	{
		cout << "[TEMP : " << numOfItems << "°³]" << '\n';
	}
	void DisplayAllItems()
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
	int GetItem(ItemType _data)
	{
		if (tItemList.Get(_data)) { return 1; }
		return 0;
	}
	int DeleteItem(ItemType _data)
	{
		if (tItemList.Delete(_data)) { return 1; }
		return 0;
	}
	int ReplaceItem(ItemType _data)
	{
		if (tItemList.Replace(_data)) { return 1; }
		return 0;
	}
};