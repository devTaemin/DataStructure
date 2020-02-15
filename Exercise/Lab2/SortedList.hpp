#ifndef _SortedList_hpp_
#define _SortedList_hpp_
#include "ItemType.hpp"
#define MAXSIZE 5

class SortedList
{
public:
	SortedList();
	~SortedList();

	void makeEmpty();
	int GetLength();
	bool IsFull();
	bool IsEmpty();
	void ResetList();
	int GetNextItem(ItemType& data);
	int Add(ItemType data);
	int Delete(ItemType data);
	int Replace(ItemType data);
	int Get(ItemType& target);
	int GetByBinarySearch(ItemType& data);

private:
	ItemType m_Array[MAXSIZE];
	int m_Length;
	int m_CurPointer;

};


#endif