#ifndef _DYNAMIC_STACKTYPE_H_
#define _DYNAMIC_STACKTYPE_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ItemType.h"

template <class RecordType>
class StackType
{
public:
	StackType();


	StackType(int max);


	~StackType();


	bool IsEmpty() const;


	bool IsFull() const;


	void push(RecordType inItem);


	void pull(RecordType& Item);


private:
	int top;
	int maxStack;
	RecordType* items;
};


template <class RecordType>
StackType<RecordType>::StackType()
{
	top = -1;
	maxStack = 500;
	items = new items[maxStack];
}


template <class RecordType>
StackType<RecordType>::StackType(int max)
{
	top = -1;
	maxStack = max;
	items = new items[maxStack]
}


template <class RecordType>
StackType<RecordType>::~StackType()
{
	delete items[];
}


template <class RecordType>
bool StackType<RecordType>::IsEmpty() const
{
	return (top == -1);
}


template <class RecordType>
bool StackType<RecordType>::IsFull() const
{
	return (top == maxStack - 1)
}


template <class RecordType>
void StackType<RecordType>::push(RecordType inItem)
{
	if (Isfull()) {
		return PushOnFullStack();
	}
	items[++top] = inItem;
}


template <class RecordType>
void StackType<RecordType>::pull(RecordType& Item)
{
	if (IsEmpty()) {
		return PullOnEmptyStack();
	}
	Item = items[top--];
}
#endif _DYNAMIC_STACKTYPE_H_