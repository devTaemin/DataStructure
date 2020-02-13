#ifndef _cmd_hpp_
#define _cmd_hpp_
#include <iostream>
#include <string>
#include <iomanip>
#include "ArrayList.hpp"
using namespace std;

class cmd
{
public:

	cmd();
	~cmd();

	void run();
	void addItem();
	void printAll();
	void makeEmpty();
	//void getFromFile();
	//void putToFile();
	bool quit();

private:
	ArrayList AL;
};

#endif