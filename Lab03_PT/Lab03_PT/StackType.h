#ifndef _STACKTYPE_H_
#define _STACKTYPE_H_

#include <iostream>
#include <fstream>
#include <string>
#include "ItemType.h"
using namespace std;

#define MAX_ITEMS 5

class StackType
{
public:
	StackType()
	{
		top = -1;
	}


	~StackType() {}


	void MakeEmpty();


	bool IsEmpty() const;


	bool IsFull() const;


	void Push(ItemType newItem);


	void Pop(ItemType& Item);


private:
	int top;
	ItemType items[MAX_ITEMS];
};
#endif _STACKTYPE_H_