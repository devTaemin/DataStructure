#include "Pch.h"


// Program running function.
void Application::Run()
//--------------------------------------------------------------------
//		
//--------------------------------------------------------------------
{
	bool prog = WhatHeap();
	if (!prog) { return; }
	else
	{
		while (1)
		{
			m_Command = GetCommand();

			switch (m_Command)
			{
			case 1:
				InsertItem();
				break;
			case 2:
				RemoveItem();
				break;
			case 3:
				DequeueItem();
				break;
			case 4:
				DisplayItem();
				break;
			case 5:
				SearchItem();
				break;
			case 0:
				return;
			default:
				cout << "\t---[ILLEGAL COMMAND]---\n" << endl;
				break;
			}
		}
	}
}


// Choose the type of heap.
bool Application::WhatHeap()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Min Heap" << endl;
	cout << "\t   0 : Quit" << endl;
	cout << endl;
	cout << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	switch (command)
	{
	case 1:
		m_List = new MinHeap<ItemType>(10);
		return true;
		break;
	case 0:
		break;
	default:
		cout << "\t---[ILLEGAL COMMAND]---\n" << endl;
		break;
	}
	return false;
}


// Get the number of command.
int Application::GetCommand()
//--------------------------------------------------------------------
//	
//--------------------------------------------------------------------
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add Item" << endl;
	cout << "\t   2 : Delete Item" << endl;
	cout << "\t   3 : Dequeue Item" << endl;
	cout << "\t   4 : Display Item" << endl;
	cout << "\t   5 : Search Item" << endl;
	cout << "\t   0 : Quit " << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new item in tree.
void Application::InsertItem()
//--------------------------------------------------------------------
//	(1)	Set new record in object.
//	(2)	Try to add the item in tree.
//	(3)	Display the state of tree after inserting item. - temporary
//--------------------------------------------------------------------
{
	ItemType item;												//	(1)
	cout << "\t---[NEW ITEM RECORD]---" << endl;
	item.SetRecordFromKB();
	cout << "\t-----------------------" << endl;

	if (!m_List->IsFull())
	{
		m_List->Add(item);
	}
	else
	{
		cout << "[ERROR: FULL HEAP]" << endl;
	}
}


// Remove target item from tree.
void Application::RemoveItem()
//--------------------------------------------------------------------
//	(1) Set target item's serial number in object.
//	(2)	Try to find whether the item is in tree or not.
//	(3)	If target item is in tree, delete the item from tree.
//	(4)	Otherwise, Display the error message.
//--------------------------------------------------------------------
{
	ItemType item;												

	if (!m_List->IsEmpty())
	{
		cout << "\t---[DELETE ITEM(ID)]---" << endl;
		item.SetSerialFromKB();
		cout << "\t-----------------------" << endl;

		bool found;
		m_List->Delete(item, found, 0);
		if (found == true)											
		{
			DisplayItem();
		}
		else														
			cout << "\t[ERROR: NO TARGET ITEM]" << endl;
	}
	else
	{
		cout << "\t[ERROR: EMPTY HEAP]" << endl;
	}
}


// Dequeue first item in the heap.
void Application::DequeueItem()
//--------------------------------------------------------------------
//	
//--------------------------------------------------------------------
{
	if (!m_List->IsEmpty())
	{
		m_List->Dequeue();
	}
	else
	{
		cout << "\t[ERROR: EMPTY HEAP]" << endl;
	}
}


// Display all items in tree.
void Application::DisplayItem()
//--------------------------------------------------------------------
//	(1) Call the display function from tree
//--------------------------------------------------------------------
{
	if (!m_List->IsEmpty())
	{
		m_List->PrintHeap();										//	(1)
	}
	else
	{
		cout << "\t[ERROR: EMPTY HEAP]" << endl;
	}

}


// Search the item whether the target is in tree or not.
void Application::SearchItem()
//--------------------------------------------------------------------
//
//--------------------------------------------------------------------
{
	ItemType item;
	bool found = false;

	if (!m_List->IsEmpty())
	{
		cout << "\t---[SEARCH ITEM(ID)]---" << endl;
		item.SetSerialFromKB();
		cout << "\t-----------------------" << endl;
		
		m_List->RetrieveItem(item, found);
		if (found)
		{
			cout << "\t-----[ITEM RECORD]-----" << endl;
			item.DisplayRecordOnScreen();
		}
		else
			cout << "\t---[ERROR: FAIL TO FIND ITEM]---" << endl;
	}
	else
	{
		cout << "\t[ERROR: EMPTY HEAP]" << endl;
	}
}