#pragma once
class Application
{
private:
	BinarySearchTree<ItemType> Tree;
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


	int GetCommand();
	//--------------------------------------------------------------------
	//	Brief:  Get the number of command.
	//	Pre:	none.
	//	Post:	command number is stored.
	//	Return:	return the command number.
	//--------------------------------------------------------------------


	void InsertItem();
	//--------------------------------------------------------------------
	//	Brief:	Add new item in tree.
	//	Pre:	none.
	//	Post:	new item is stored in tree.
	//--------------------------------------------------------------------


	void RemoveItem();
	//--------------------------------------------------------------------
	//	Brief:	Remove target item from tree.
	//	Pre:	none.
	//	Post:	if target item is in tree, the item is removed from tree.
	//--------------------------------------------------------------------


	void DisplayItem();
	//--------------------------------------------------------------------
	//	Brief:	Display all items in tree.
	//	Pre:	none.
	//	Post:	if tree is not empty, display the records of all items.
	//--------------------------------------------------------------------


	void SearchItem();
	//--------------------------------------------------------------------
	//	Brief:  Search the item whether the target is in tree or not.
	//	Pre:	none.
	//	Post:	display the result.
	//--------------------------------------------------------------------
};