#ifndef _ArrayList_hpp_
#define _ArrayList_hpp_
#include "ItemType.hpp"
#define MAXSIZE 5

class ArrayList
{
public:
	ArrayList();
	~ArrayList();

	void MakeEmpty();
	int GetLength();
	bool IsFull();
	int Add(ItemType data);
	void ResetList();
	int GetNextItem(ItemType& data);

private:
	ItemType m_Array[MAXSIZE];
	int m_Length;
	int m_CurPointer;
};




#endif