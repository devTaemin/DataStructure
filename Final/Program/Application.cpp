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
	bool func;
	StorageList.PrintTree(cout);
	StorageType _container;
	_container.SetStorageRecordFromKB();
	StorageList.Add(_container, func);
	if (func){
		cout << "\t[SUCCESS: STORAGE ADD]" << endl;
	}
	else {
		cout << "\t[ERROR: FAIL TO ADD STORAGE]" << endl;
	}
}


void Application::StorageDelete()
{
	bool func;
	StorageList.PrintTree(cout);
	StorageType _container;
	_container.SetStorageIDFromKB();
	StorageList.Delete(_container, func);
	if (func) {
		cout << "\t[SUCCESS: STORAGE DELETE]" << endl;
	}
	else {
		cout << "\t[ERROR: FAIL TO DELETE STORAGE]" << endl;
	}

}


void Application::StorageUpdate()
{
	bool func;
	StorageList.PrintTree(cout);
	StorageType _container;
	_container.SetStorageRecordFromKB();
	StorageList.Replace(_container, func);
	if (func) {
		cout << "\t[SUCCESS: STORAGE REPLACE]" << endl;
	}
	else {
		cout << "\t[ERROR: FAIL TO REPLACE STORAGE]" << endl;
	}
}


void Application::StorageDisplay()
{
	cout << "\t+--------------------------------------+" << endl;
	cout << "\t|                RESULT                |" << endl;
	cout << "\t+--------------------------------------+" << endl;
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
	bool func;
	if (StorageList.IsEmpty()) { return; }
	else
	{
		StorageList.PrintTree(cout);
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
			_storage.AddContainer(_container,func);
			StorageList.Replace(_storage,func);
		}
	}
}


void Application::ContainerDelete()
{
	bool func;
	if (StorageList.IsEmpty()) { return; }
	else
	{
		StorageList.PrintTree(cout);
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
			_storage.DeleteContainer(_container, func);
			StorageList.Replace(_storage, func);
		}
	}
}


void Application::ContainerUpdate()
{
	bool func;
	if (StorageList.IsEmpty()) { return; }
	else
	{
		StorageList.PrintTree(cout);
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
			_storage.UpdateContainer(_container, func);
			StorageList.Replace(_storage, func);
		}
	}
}


void Application::ContainerDisplay()
{
	if (StorageList.IsEmpty()) { return; }
	else
	{
		StorageList.PrintTree(cout);
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
			cout << "\t+--------------------------------------+" << endl;
			cout << "\t|                RESULT                |" << endl;
			cout << "\t+--------------------------------------+" << endl;
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


bool Application::WhatType(ItemType*& _item)
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- ITEMTYPE ---- " << endl;
	cout << "\t   1 : UNDECIDED" << endl;
	cout << "\t   2 : FOODTYPE" << endl;
	cout << "\t   3 : CLOTHTYPE" << endl;
	cout << "\t   4 : LIVINGTYPE" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	switch (command)
	{
	case 1:
		_item = new ItemType();
		return true;
		break;
	case 2:
		_item = new FoodType();
		return true;
		break;
	case 3:
		_item = new ClothType();
		return true;
		break;
	case 4:
		_item = new LivingType();
		return true;
		break;
	case 0:
		return false;
	default:
		cout << "\t---[ILLEGAL COMMAND]---\n";
		break;
	}
	return false;
}


void Application::ItemAdd()
{
	bool func;
	bool Storage_found;
	bool Container_found;
	if (StorageList.IsEmpty()) 
	{ 
		cout << "\t[ERROR: EMPTY STORAGE]" << endl;
		return; 
	}
	else
	{
		StorageList.PrintTree(cout);
		StorageType _storage;
		_storage.SetStorageIDFromKB();
		StorageList.Retrieve(_storage, Storage_found);

		if (!Storage_found)
		{
			cout << "\t[ERROR: STORAGE IS NOT FOUNDED]" << endl;
			return;
		}
		else
		{
			if (_storage.IsContainerEmpty())
			{
				cout << "\t[ERROR: EMPTY CONTAINER]" << endl;
			}
			else
			{
				_storage.DisplayAllContainer();
				ContainerType _container;
				_container.SetContainerIDFromKB();
				_storage.RetrieveContainer(_container, Container_found);

				if (!Container_found)
				{
					cout << "\t[ERROR: CONTAINER IS NOT FOUNDED]" << endl;
					return;
				}
				else
				{
					ItemType* _item;
					if (!WhatType(_item)) { return; }						// SELECT DETAILS OF ITEM.
					_item->SetRecordFromKB();

					if (!_container.IsFound(_item))
					{
						_container.AddItem(_item,func);
						_storage.UpdateContainer(_container,func);
						StorageList.Replace(_storage,func);
						MasterList.AddPointerItem(_item,func);
					}
					else
					{
						cout << "\t[ERROR: TARGET ITEM IS DUPLICATED]" << endl;
					}
				
				}
			}
		}
	}
}



void Application::ItemDelete()
{
	bool func;
	bool Storage_found;
	bool Container_found;
	if (StorageList.IsEmpty())
	{
		cout << "\t[ERROR: EMPTY STORAGE]" << endl;
		return;
	}
	else
	{
		StorageList.PrintTree(cout);
		StorageType _storage;
		_storage.SetStorageIDFromKB();
		StorageList.Retrieve(_storage, Storage_found);

		if (!Storage_found)
		{
			cout << "\t[ERROR: STORAGE IS NOT FOUNDED]" << endl;
			return;
		}
		else
		{
			if (_storage.IsContainerEmpty())
			{
				cout << "\t[ERROR: EMPTY CONTAINER]" << endl;
			}
			else
			{
				_storage.DisplayAllContainer();
				ContainerType _container;
				_container.SetContainerIDFromKB();
				_storage.RetrieveContainer(_container, Container_found);

				if (!Container_found)
				{
					cout << "\t[ERROR: CONTAINER IS NOT FOUNDED]" << endl;
					return;
				}
				else
				{
					_container.DisplayAllItem();
					ItemType* item = new ItemType();
					item->SetSerialFromKB();
					if (_container.IsFound(item))
					{
						_container.DeleteItem(item,func);
						_storage.UpdateContainer(_container,func);
						StorageList.Replace(_storage,func);
						MasterList.DeletePointerItem(item,func);
					}
					else
					{
						cout << "\t[ERROR: TARGET ITEM IS NOT FOUNDED]" << endl;
					}
				}
			}
		}
	}
}


void Application::ItemUpdate()
{
	bool func;
	bool Storage_found;
	bool Container_found;
	if (StorageList.IsEmpty())
	{
		cout << "\t[ERROR: EMPTY STORAGE]" << endl;
		return;
	}
	else
	{
		StorageList.PrintTree(cout);
		StorageType _storage;
		_storage.SetStorageIDFromKB();
		StorageList.Retrieve(_storage, Storage_found);

		if (!Storage_found)
		{
			cout << "\t[ERROR: STORAGE IS NOT FOUNDED]" << endl;
			return;
		}
		else
		{
			if (_storage.IsContainerEmpty())
			{
				cout << "\t[ERROR: EMPTY CONTAINER]" << endl;
			}
			else
			{
				_storage.DisplayAllContainer();
				ContainerType _container;
				_container.SetContainerIDFromKB();
				_storage.RetrieveContainer(_container, Container_found);

				if (!Container_found)
				{
					cout << "\t[ERROR: CONTAINER IS NOT FOUNDED]" << endl;
					return;
				}
				else
				{
					ItemType* _item;
					if (!WhatType(_item)) { return; }						// SELECT DETAILS OF ITEM.
					_item->SetRecordFromKB();
					if (_container.IsFound(_item))
					{
						_container.UpdateItem(_item,func); 
						_storage.UpdateContainer(_container,func);
						StorageList.Replace(_storage,func);
						MasterList.ReplacePointerItem(_item,func);
					}
					else
					{
						cout << "\t[ERROR: TARGET ITEM IS NOT FOUNDED]" << endl;
					}
				}
			}
		}
	}
}


void Application::ItemDisplay()
{
	bool Storage_found;
	bool Container_found;
	if (StorageList.IsEmpty())
	{
		cout << "\t[ERROR: EMPTY STORAGE]" << endl;
		return;
	}
	else
	{
		StorageList.PrintTree(cout);
		StorageType _storage;
		_storage.SetStorageIDFromKB();
		StorageList.Retrieve(_storage, Storage_found);

		if (!Storage_found)
		{
			cout << "\t[ERROR: STORAGE IS NOT FOUNDED]" << endl;
			return;
		}
		else
		{
			if (_storage.IsContainerEmpty())
			{
				cout << "\t[ERROR: EMPTY CONTAINER]" << endl;
			}
			else
			{
				_storage.DisplayAllContainer();
				ContainerType _container;
				_container.SetContainerIDFromKB();
				_storage.RetrieveContainer(_container, Container_found);

				if (!Container_found)
				{
					cout << "\t[ERROR: CONTAINER IS NOT FOUNDED]" << endl;
					return;
				}
				else
				{
					cout << "\t+--------------------------------------+" << endl;
					cout << "\t|                RESULT                |" << endl;
					cout << "\t+--------------------------------------+" << endl;
					_container.DisplayAllItem();
				}
			}
		}
	}
}


void Application::Functions()
{
	int command;
	cout << endl << endl;
	cout << "\t|====== [Functions]  ======================================|" << endl;
	cout << "\t|  <<<< DISPLAY >>>>                                       |" << endl;
	cout << "\t|  [1 : Display Details in Storage]                        |" << endl;
	cout << "\t|  [2 : Display Details in Container]                      |" << endl;
	cout << "\t|  [4 : Display Photo]                                     |" << endl;
	cout << "\t|----------------------------------------------------------|" << endl;
	cout << "\t|  <<<< SEARCH >>>>                                        |" << endl;
	cout << "\t|  [5 : Search By ID]                                      |" << endl;
	cout << "\t|  [6 : Search By Name]                                    |" << endl;
	cout << "\t|  [7 : Search By Type]                                    |" << endl;
	cout << "\t|==========================================================|" << endl;
	cout << "\t|  [8 : SAVE  ]                                            |" << endl;
	cout << "\t|  [9 : LOAD  ]                                            |" << endl;
	cout << "\t|  [0 : Quit  ]                                            |" << endl;
	cout << "\t|==========================================================|" << endl;
	cout << endl;
	cout << "\t Choose a Command--> ";
	cin >> command;

	switch (command)
	{
	case 1:
		DisplayDetailsStorage();
		break;
	case 2:
		DisplayDetailsContainer();
		break;
	case 3:
		DisplayPhoto();
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 0:
		return;
	default:
		cout << "\t---[ILLEGAL COMMAND]---\n";
		break;
	}
}


void Application::DisplayDetailsStorage()
{
	StorageType curStorage;
	bool found;

	if (!StorageList.IsEmpty())
	{
		StorageList.PrintTree(cout);
		curStorage.SetStorageIDFromKB();
		StorageList.Retrieve(curStorage, found);
		if (!found)
		{
			cout << "[ERROR: STORAGE NOT FOUND]" << endl;
		}
		else
		{
			if (curStorage.IsContainerEmpty())
			{
				cout << "[ERROR: EMPTY CONTAINER IN STORAGE]" << endl;
			}
			else
			{
				curStorage.DisplayAllDetailsStorage(MasterList);
			}
		}
	}
	else
	{
		cout << "[ERROR: EMPTY DATA]" << endl;
	}
}


void Application::DisplayDetailsContainer()
{
	StorageType curStorage;
	ContainerType curContainer;
	bool found;

	if (!StorageList.IsEmpty())
	{
		StorageList.PrintTree(cout);
		curStorage.SetStorageIDFromKB();
		StorageList.Retrieve(curStorage, found);
		if (!found)
		{
			cout << "[ERROR: STORAGE NOT FOUND]" << endl;
		}
		else
		{
			if (curStorage.IsContainerEmpty())
			{
				cout << "[ERROR: EMPTY CONTAINER IN STORAGE]" << endl;
			}
			else
			{
				curStorage.DisplayAllContainer();
				curContainer.SetContainerIDFromKB();
				curStorage.RetrieveContainer(curContainer, found);
				if (!found)
				{
					cout << "[ERROR: CONTAINER NOT FOUND]" << endl;
				}
				else
				{
					if (curContainer.IsEmpty())
					{
						cout << "[ERROR: EMPTY CONTAINER]" << endl;
					}
					else
					{
						curContainer.DisplayAllDetailsContainer(MasterList);
					}
				}
			}
		}
	}
	else
	{
		cout << "[ERROR: EMPTY DATA]" << endl;
	}
}


void Application::DisplayPhoto()
{
	StorageType curStorage;
	ContainerType curContainer;
	bool found;

	if (!StorageList.IsEmpty())
	{
		StorageList.PrintTree(cout);
		curStorage.SetStorageIDFromKB();
		StorageList.Retrieve(curStorage, found);
		if (!found)
		{
			cout << "[ERROR: STORAGE NOT FOUND]" << endl;
		}
		else
		{
			curStorage.DisplayAllContainer();
			curContainer.SetContainerIDFromKB();
			curStorage.RetrieveContainer(curContainer, found);
			if (!found)
			{
				cout << "[ERROR: CONTAINER NOT FOUND]" << endl;
			}
			else
			{
				curContainer.DisplayAllPhoto();
			}
		}
	}
	else
	{
		cout << "[ERROR: EMPTY DATA]" << endl;
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