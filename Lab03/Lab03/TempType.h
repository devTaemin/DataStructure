#pragma once
//--------------------------------------------------------------------
//		Temp Item information class.
//--------------------------------------------------------------------
class TempType
{
private:
	int numOfItems;
	CircularQueue<ItemType> tItemList;

public:
	TempType();
	//--------------------------------------------------------------------
	//		Default Constructor.
	//--------------------------------------------------------------------


	~TempType();
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	bool IsFull() const;
	//--------------------------------------------------------------------
	//	Brief:	Check whether CircularQueue is full.
	//	Pre:	Queue has been initialized.
	//	Post:	none.
	//	Return:	return true if Queue is full, otherwise false.
	//--------------------------------------------------------------------


	bool IsEmpty() const;
	//--------------------------------------------------------------------
	//	Brief:	Check whether CircularQueue is empty.
	//	Pre:	Queue has been initialized.
	//	Post:	none.
	//	Return: return true if stack is empty, otherwise false.
	//--------------------------------------------------------------------


	int GetNumOfItems() const;
	//--------------------------------------------------------------------
	//	Brief:	Get number of items in tItemList.
	//	Pre:	the number of Items is set. 
	//	Post:	none.
	//  Return:	number of items in tItemlist.
	//--------------------------------------------------------------------


	int Enqueue(ItemType data);
	//--------------------------------------------------------------------
	//	Brief:	Adds new data to the last of the queue.
	//	Pre:	CircularQueue has been initialized.
	//	Post:	new data's pointer is included in queue.
	//	Param:	*data		new data's pointer.
	//	Return: return 1 if function works well, otherwise 0.
	//--------------------------------------------------------------------


	int Dequeue(ItemType& data);
	//--------------------------------------------------------------------
	//	Brief:	Delete data from the first of the queue.
	//	Pre:	CircularQueue has been initialized.
	//	Post:	front data's pointer is excluded from queue.
	//	Param	*data		target data's pointer.
	//	Return:	return 1 if function works well, otherwise 0.
	//--------------------------------------------------------------------


	void DisplayNumOfItems();
	//--------------------------------------------------------------------
	//	Brief:	Display number of items in tItemList.
	//	Pre:	TempType has been initialized.
	//	Post:	none.
	//--------------------------------------------------------------------


	void DisplayAllItems();
	//--------------------------------------------------------------------
	//	Brief:	Display all items in tItemList.
	//	Pre:	TempType has been initialized.
	//	Post:	none.
	//--------------------------------------------------------------------
};