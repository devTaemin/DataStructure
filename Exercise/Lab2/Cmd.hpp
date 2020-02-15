#ifndef _Cmd_hpp_
#define _Cmd_hpp_
#include "SortedList.hpp"

class Cmd
{
public:
	Cmd();
	~Cmd();

	void run();
	void addItem();
	void printAll();
	void makeEmptyList();
	void searchById();
	void searchByName();
	void deleteItem();
	void updateItem();
	void getFromFile();
	void putToFile();
	bool quit();

private:
	SortedList SL;
};



#endif