#ifndef _UNSORTEDLIST_H_
#define _UNSORTEDLIST_H_

#include <iostream>
#include <string>
#include "ItemType.h"
using namespace std;

#define MAXSIZE 5


class UnSortedList
{
public:
	// Default Constructor.
	UnSortedList()
	{
		m_Length = 0;
		m_CurPointer = -1;
	}


	// Destructor.
	~UnSortedList() {}


	void MakeEmpty();


	int GetLength() const;


	bool IsFull();


	bool IsEmpty();


	int Add(ItemType data);


	void ResetList();


	int GetNextItem(ItemType& data);


private:
	ItemType m_Array[MAXSIZE];
	int m_Length;
	int m_CurPointer;


};
#endif _UNSORTEDLIST_H_