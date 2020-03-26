#ifndef _UNSORTED_H_
#define _UNSORTED_H_

#include <iostream>
#include <string>
#include "ItemType.h"
#define MAXSIZE 5


class ArrayList
{
public:
	ArrayList();
	~ArrayList();

	void makeEmpty();
	int GetLength();
	bool IsFull();
	int Add(ItemType data);
	void ResetList();
	int GetNextItem(ItemType& data);

	bool IsEmpty();
	int Get(ItemType& data);
	int Delete(ItemType data);
	int Replace(ItemType data);

private:
	ItemType m_Array[MAXSIZE];
	int m_Length;
	int m_CurPointer;
};








#endif _UNSORTED_H_

