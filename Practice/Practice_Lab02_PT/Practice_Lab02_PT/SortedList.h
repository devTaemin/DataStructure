#ifndef _SORTEDLIST_H_
#define _SORTEDLIST_H_

#include <iostream>
#include <string>
#include "ItemType.h"
using namespace std;

#define MAXSIZE 5


class SortedList
{
public:
	// Default Constructor.
	SortedList()
	{
		m_Length = 0;
		m_CurPointer = -1;
	}


	// Destructor.
	~SortedList() {}


	void MakeEmpty();


	int GetLength() const;


	bool IsFull() const;


	bool IsEmpty() const;


	void ResetList();


	int GetNextItem(ItemType& data);
	

	int Get(ItemType& data);
	

	int Add(ItemType inData);


	int Delete(ItemType data);


	int Replace(ItemType data);


	int Retrieve_SeqS(ItemType& target);


	int RetrieveByBS(ItemType& target);


private:
	ItemType m_Array[MAXSIZE];
	int m_Length;
	int m_CurPointer;


};
#endif _SORTEDLIST_H_