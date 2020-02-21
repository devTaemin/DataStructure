#ifndef _SortedLinkedList_hpp_
#define _SortedLinkedList_hpp_
#include "NodeType.hpp"

template <typename T>
class LinkedList
{
public:
	LinkedList(){}

	~LinkedList(){}

	void MakeEmpty(){}

	int GetLength() const {}

	int Add(T item){}

	int Get(T& item){}

	void ResetList(){}

	void GetNextItem(T& item){}

private:
	NodeType<T>* m_pList;
	NodeType<T>* m_pCurPointer;
	int m_nLength;
};
#endif