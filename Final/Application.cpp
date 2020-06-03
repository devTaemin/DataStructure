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
			Storage();
			break;
		case 2:
			Container();
			break;
		case 3:
			Item();
			break;
		case 4:
			Functions();
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
	cout << "\t+-------- [ Commodity Management Storage Program ] --------+" << endl;
	cout << "\t|==========================================================|" << endl;
	cout << "\t|   [1 : STORAGE ]                     [2 : CONTAINER ]    |" << endl;
	cout << "\t|   [3 : ITEM    ]                     [4 : FUNCTION  ]    |" << endl;
	cout << "\t|==========================================================|" << endl;
	cout << "\t|   [0 : Quit    ]                                         |" << endl;
	cout << "\t|==========================================================|" << endl;
	cout << endl;
	cout << "\t Choose a Program Command--> ";
	cin >> command;

	return command;
}


void Application::Storage()
{

	int command;
	cout << endl << endl;
	cout << "\t|====== [ STORAGE ] =======================================|" << endl;
	cout << "\t|   [1 : Add    ]                      [2 : Delete  ]      |" << endl;
	cout << "\t|   [3 : Update ]                      [4 : Display ]      |" << endl;
	cout << "\t|==========================================================|" << endl;
	cout << "\t|   [0 : Quit   ]                                          |" << endl;
	cout << "\t|==========================================================|" << endl;
	cout << endl;
	cout << "\t Choose a Command--> ";
	cin >> command;

	switch (command)
	{
	case 1:
		StorageAdd();
		break;
	case 2:
		StorageDelete();
		break;
	case 3:
		StorageUpdate();
		break;
	case 4:
		StorageDisplay();
		break;
	case 0:
		return;
	default:
		cout << "\t---[ILLEGAL COMMAND]---\n";
		break;
	}
}


void Application::StorageAdd()
{
	StorageDisplay();
	StorageType _container;
	_container.SetStorageRecordFromKB();
	StorageList.Add(_container);
}


void Application::StorageDelete()
{
	StorageDisplay();
	StorageType _container;
	_container.SetStorageIDFromKB();
	StorageList.Delete(_container);

}


void Application::StorageUpdate()
{
	StorageDisplay();
	StorageType _container;
	_container.SetStorageRecordFromKB();
	StorageList.Replace(_container);
}


void Application::StorageDisplay()
{
	StorageList.PrintTree(cout);
}


void Application::Container()
{
	int command;
	cout << endl << endl;
	cout << "\t|====== [ CONTAINER ] =====================================|" << endl;
	cout << "\t|   [1 : Add    ]                      [2 : Delete  ]      |" << endl;
	cout << "\t|   [3 : Update ]                      [4 : Display ]      |" << endl;
	cout << "\t|==========================================================|" << endl;
	cout << "\t|   [0 : Quit   ]                                          |" << endl;
	cout << "\t|==========================================================|" << endl;
	cout << endl;
	cout << "\t Choose a Command--> ";
	cin >> command;

	switch (command)
	{
	case 1:
		ContainerAdd();
		break;
	case 2:
		ContainerDelete();
		break;
	case 3:
		ContainerUpdate();
		break;
	case 4:
		ContainerDisplay();
		break;
	case 0:
		return;
	default:
		cout << "\t---[ILLEGAL COMMAND]---\n";
		break;
	}
}


void Application::ContainerAdd()
{
	if (StorageList.IsEmpty()) { return; }
	else
	{
		StorageDisplay();
		StorageType _storage;
		_storage.SetStorageIDFromKB();
		bool found;
		StorageList.Retrieve(_storage, found);

		if (!found) 
		{
			cout << "\t[ERROR: STORAGE IS NOT FOUNDED]" << endl;
		}
		else
		{
			_storage.DisplayAllContainer();
			ContainerType _container;
			_container.SetContainerRecordFromKB();
			_storage.AddContainer(_container);
			StorageList.Replace(_storage);
		}
	}
}


void Application::ContainerDelete()
{
	if (StorageList.IsEmpty()) { return; }
	else
	{
		StorageDisplay();
		StorageType _storage;
		_storage.SetStorageIDFromKB();
		bool found;
		StorageList.Retrieve(_storage, found);

		if (!found)
		{
			cout << "\t[ERROR: STORAGE IS NOT FOUNDED]" << endl;
		}
		else
		{
			_storage.DisplayAllContainer();
			ContainerType _container;
			_container.SetContainerIDFromKB();
			_storage.DeleteContainer(_container);
			StorageList.Replace(_storage);
		}
	}
}


void Application::ContainerUpdate()
{
	
	if (StorageList.IsEmpty()) { return; }
	else
	{
		StorageDisplay();
		StorageType _storage;
		_storage.SetStorageIDFromKB();
		bool found;
		StorageList.Retrieve(_storage, found);

		if (!found)
		{
			cout << "\t[ERROR: STORAGE IS NOT FOUNDED]" << endl;
		}
		else
		{
			_storage.DisplayAllContainer();
			ContainerType _container;
			_container.SetContainerRecordFromKB();
			_storage.UpdateContainer(_container);
			StorageList.Replace(_storage);
		}
	}
}


void Application::ContainerDisplay()
{
	if (StorageList.IsEmpty()) { return; }
	else
	{
		StorageDisplay();
		StorageType _storage;
		_storage.SetStorageIDFromKB();
		bool found;
		StorageList.Retrieve(_storage, found);

		if (!found)
		{
			cout << "\t[ERROR: STORAGE IS NOT FOUNDED]" << endl;
		}
		else
		{
			_storage.DisplayAllContainer();
		}
	}
}


void Application::Item()
{
	int command;
	cout << endl << endl;
	cout << "\t|====== [ CONTAINER ] =====================================|" << endl;
	cout << "\t|   [1 : Add    ]                      [2 : Delete  ]      |" << endl;
	cout << "\t|   [3 : Update ]                      [4 : Display ]      |" << endl;
	cout << "\t|==========================================================|" << endl;
	cout << "\t|   [0 : Quit   ]                                          |" << endl;
	cout << "\t|==========================================================|" << endl;
	cout << endl;
	cout << "\t Choose a Command--> ";
	cin >> command;

	switch (command)
	{
	case 1:
		ItemAdd();
		break;
	case 2:
		ItemDelete();
		break;
	case 3:
		ItemUpdate();
		break;
	case 4:
		ItemDisplay();
		break;
	case 0:
		return;
	default:
		cout << "\t---[ILLEGAL COMMAND]---\n";
		break;
	}
}


void Application::ItemAdd()
{

}


void Application::ItemDelete()
{

}


void Application::ItemUpdate()
{

}


void Application::ItemDisplay()
{

}


void Application::Functions()
{
	int command;
	cout << endl << endl;
	cout << "\t|====== [Functions]  ======================================|" << endl;
	cout << "\t|  [4 : Display All workers]                               |" << endl;
	cout << "\t|  [5 : Search worker By Name]                             |" << endl;
	cout << "\t|  [6 : Search worker By Skill]                            |" << endl;
	cout << "\t|  [7 : Get workers By Conditions]                         |" << endl;
	cout << "\t|  [8 : Get workers By Score]                              |" << endl;
	cout << "\t|==========================================================|" << endl;
	cout << "\t|  [0 : Quit  ]                                            |" << endl;
	cout << "\t|==========================================================|" << endl;
	cout << endl;
	cout << "\t Choose a Command--> ";
	cin >> command;

	switch (command)
	{
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	case 0:
		return;
	default:
		cout << "\t---[ILLEGAL COMMAND]---\n";
		break;
	}
}



/*
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
*/