#pragma once
class Application
{
private:
	BaseHeap<ItemType>* m_List;
	int m_Command;

public:
	Application()
		//--------------------------------------------------------------------
		//		Default Constructor.
		//--------------------------------------------------------------------
	{
		m_Command = 0;
	}


	~Application()
		//--------------------------------------------------------------------
		//		Destructor.
		//--------------------------------------------------------------------
	{

	}


	void Run();
	//--------------------------------------------------------------------
	//		Program running function.
	//--------------------------------------------------------------------

	
	bool WhatHeap();
	//--------------------------------------------------------------------
	//	Brief:  Choose the type of heap.
	//	Pre:	none.
	//	Post:	type of heap is chosen (Maxheap, Minheap, Quit).
	//	Return: return true if type is chosen, otherwise false to exterminate.
	//--------------------------------------------------------------------


	int GetCommand();
	//--------------------------------------------------------------------
	//	Brief:  Get the number of command.
	//	Pre:	none.
	//	Post:	command number is stored.
	//	Return:	return the command number.
	//--------------------------------------------------------------------


	void InsertItem();
	//--------------------------------------------------------------------
	//	Brief:	Add new item in heap.
	//	Pre:	none.
	//	Post:	new item is stored in heap.
	//--------------------------------------------------------------------


	void RemoveItem();
	//--------------------------------------------------------------------
	//	Brief:	Remove target item from heap.
	//	Pre:	none.
	//	Post:	if target item is in tree, the item is removed from heap.
	//--------------------------------------------------------------------


	void DequeueItem();
	//--------------------------------------------------------------------
	//	Brief:	Remove target first item from heap.
	//	Pre:	none.
	//	Post:	if item is in heap, the item is removed from heap.
	//--------------------------------------------------------------------


	void DisplayItem();
	//--------------------------------------------------------------------
	//	Brief:	Display all items in heap.
	//	Pre:	none.
	//	Post:	if heap is not empty, display the records of all items.
	//--------------------------------------------------------------------


	void SearchItem();
	//--------------------------------------------------------------------
	//	Brief:  Search the item whether the target is in heap or not.
	//	Pre:	none.
	//	Post:	display the result.
	//--------------------------------------------------------------------
};