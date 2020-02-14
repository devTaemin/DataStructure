#ifndef _Cmd_hpp_
#define _Cmd_hpp_
#include "ArrayList.hpp"

class Cmd
{
public:
	Cmd();
	~Cmd();

	void run();
	void addItem();
	void printAll();
	void makeEmptyList();
	void getFromFile();
	void putToFile();
	bool quit();

private:
	ArrayList AL;
};



#endif