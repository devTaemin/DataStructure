#ifndef _GENERAL_STACKTYPE_H_
#define _GENERAL_STACKTYPE_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ItemType.h"
#define MAX_ITEMS 5


template<class RecordType>
class StackType
{
	StackType()
	{
		top = -1;
	}


	~StackType();

	
	void MakeEmpty();


	bool IsEmpty() const;


	bool IsFull() const;


	void Push(RecordType inItem);


	void Push(RecordType& Item);

	
private:
	int top;
	RecordType items[MAX_ITEMS];
};


template<class RecordType>
void StackType<RecordType>::MakeEmpty()
{
	top = -1;
}


template<class RecordType>
bool StackType<RecordType>::IsEmpty() const
{
	return (top == -1);
}


template<class RecordType>
bool StackType<RecordType>::IsFull() const
{
	return (top == MAX_ITEMS - 1);
}


template<class RecordType>
void StackType<RecordType>::Push(RecordType inItem)
{
	if (IsFull) {
		throw PushOnFullStack();
	}
	items[++top] = inItem;
}


template<class RecordType>
void StackType<RecordType>::Push(RecordType& Item)
{
	if (IsEmpty()) {
		throw PopOnEmptyStack();
	}
	item = items[top--];
}

#endif _GENERAL_STACKTYPE_H_