#ifndef _Cmd_hpp_
#define _Cmd_hpp_
#include "SortedLinkedlist.hpp"

template <typename T>
class Cmd
{
public:
	Cmd(){}

	~Cmd(){}

	void run() {}

	void insertItem(){}

	void deleteItem(){}

	void replaceItem(){}

	void retrieveItem(){}

	void displayAll(){}

	bool quit(){}

private:
	LinkedList<T> list;
};
#endif