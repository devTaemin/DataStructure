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
	~TempType();

	bool IsFull() const;
	bool IsEmpty() const;
	int GetNumOfItems() const;
	int Enqueue(ItemType data);
	int Dequeue(ItemType& data);
	void DisplayNumOfItems();
	void DisplayAllItems();
	int GetItem(ItemType _data);
	int DeleteItem(ItemType _data);
	int ReplaceItem(ItemType _data);
};