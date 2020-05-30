#include "Pch.h"


// Program running function.
void Application::Run()
//--------------------------------------------------------------------
//		
//--------------------------------------------------------------------
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
			DisplayItem();
			break;
		case 4:
			SearchItem();
			break;
		case 0:
			return;
		default:
			cout << "\t---[ILLEGAL COMMAND]---\n";
			break;
		}
	}
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
	cout << "\t   3 : Display Item" << endl;
	cout << "\t   4 : Search Item" << endl;
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

	Tree.Add(item);												//	(2)
	//DisplayItem();											//	(3)
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
	ItemType item;												//	(1)
	cout << "\t---[DELETE ITEM(ID)]---" << endl;
	item.SetSerialFromKB();	
	cout << "\t-----------------------" << endl;

	bool found;													//	(2)
	Tree.Retrieve(item, found);

	if (found == true)											//	(3)
	{
		Tree.Delete(item);
		DisplayItem();
	}
	else														//	(4)
		cout << "\t[ERROR: NO TARGET ITEM]" << endl;
}


// Display all items in tree.
void Application::DisplayItem()
//--------------------------------------------------------------------
//	(1) Call the display function from tree
//	***** use 'cout' as argument of function!!!!
//--------------------------------------------------------------------
{
	Tree.PrintTree(cout);										//	(1)
}


// Search the item whether the target is in tree or not.
void Application::SearchItem()
//--------------------------------------------------------------------
//
//--------------------------------------------------------------------
{
	ItemType item;
	cout << "\t---[SEARCH ITEM(ID)]---" << endl;
	item.SetSerialFromKB();
	cout << "\t-----------------------" << endl;

	bool found;
	Tree.Retrieve(item, found);
	if (found == true)
	{
		cout << "\t-----[ITEM RECORD]-----" << endl;
		item.DisplayRecordOnScreen();
	}
	else
		cout << "\t---[ERROR: FAIL TO FIND ITEM]---" << endl;
}