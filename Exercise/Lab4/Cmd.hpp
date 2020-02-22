#ifndef _Cmd_hpp_
#define _Cmd_hpp_
#include "SortedLinkedlist.hpp"

template <typename T>
class Cmd
{
public:
	Cmd(){}

	~Cmd(){}

	void run() 
	{
		bool run = true;
		int cmd;
		while (run) {
			cout << endl;
			cout << "       " << "--- ID - Command -----" << endl;
			cout << "       " << "        1 : Insert Item" << endl;
			cout << "       " << "        2 : Delete Item" << endl;
			cout << "       " << "        3 : Replace Item" << endl;
			cout << "       " << "        4 : Retrieve Item" << endl;
			cout << "       " << "        5 : Display all Item" << endl;
			cout << "       " << "        0 : Quit" << endl;
			cout << endl;
			cout << endl;
			cout << "       " << "Choose a Command --> ";
			cin >> cmd;

			switch (cmd) {
			case(1):
				insertItem();
				break;
			case(2):
				deleteItem();
				break;
			case(3):
				replaceItem();
				break;
			case(4):
				retrieveItem();
				break;
			case(5):
				displayAll();
				break;
			case(0):
				run = quit();
				break;
			default:
				cerr << "       " << "Wrong Command!" << endl;
			}
		}
	}

	void insertItem()
	{
		T item;
		cout << "       " << "Insert item: ";
		cin >> item;
		list.Add(item);
	}

	void deleteItem()
	{
		T item;
		cout << "       " << "Delete item: ";
		cin >> item;
		int run = list.DeleteItem(item);
		if (run == 0) {
			cout << "       " << "Fail to delete Item";
		}
		else {
			cout << "       " << "Delete Success!";
		}
	}

	void replaceItem()
	{
		T item_1, item_2;
		cout << "       " << "Enter item to replace: ";
		cin >> item_1;
		cout << "       " << "Enter item to add: ";
		cin >> item_2;
		int run = list.ReplaceItem(item_1, item_2);
		if (run == 0) {
			cout << "       " << "Fail to replace Item";
		}
		else {
			cout << "       " << "Replace Success!";
		}
	}

	void retrieveItem()
	{
		T item;
		cout << "       " << "Retrieve item: ";
		cin >> item;
		int run = list.RetrieveItem(item);
		if (run == 0) {
			cout << "       " << "Fail to retrieve Item";
		}
		else {
			cout << "       " << "Retrieve Success!";
		}
	}

	void displayAll()
	{
		cout << "=================D=I=S=P=L=A=Y=================" << endl;
		list.printAll();
	}

	bool quit()
	{
		return false;
	}

private:
	LinkedList<T> list;
};
#endif