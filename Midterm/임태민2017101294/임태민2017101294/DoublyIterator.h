#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


#include "DoublySortedLinkedList.h"
template <typename T>
struct DoublyNodeType;
template <typename T>
class DoublySortedLinkedList;


template <typename T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>;
	
private:
	const DoublySortedLinkedList<T>& m_pList;				///< Iterator을 참조할 자료 링크.
	DoublyNodeType<T>* m_pCurPointer;						///< Node pointer.

public:
	
	DoublyIterator(const DoublySortedLinkedList<T>& _list) : m_pList(_list), m_pCurPointer(_list.m_pHead){}
	//--------------------------------------------------------------------
	//		Constructor.
	//--------------------------------------------------------------------

	bool IsNull();
	//--------------------------------------------------------------------
	//	Brief:	Check whether current pointer is Null or not.
	//	Pre:	none.
	//	Post:	none.
	//	Return:	return true if list is null, otherwise return false.
	//--------------------------------------------------------------------

	bool NextNotNull();
	//--------------------------------------------------------------------
	//	Brief:	Check whether next and current pointer is Null or not.
	//	Pre:	none.
	//	Post:	none.
	//	Return:	return true if list is null, otherwise return false.
	//--------------------------------------------------------------------

	void Next();
	//--------------------------------------------------------------------
	//	Brief:	Move the pointer to the next pointer.
	//	Pre:	Iterator has initialized.
	//	Post:	Pointer moves to the next pointer.
	//--------------------------------------------------------------------

	void Now(T& _data);
	//--------------------------------------------------------------------
	//	Brief:	Refer to the data that current pointer designated.
	//	Pre:	Iterator has initialized.
	//	Post:	none.
	//	Param:	_data		copying vaiable.
	//--------------------------------------------------------------------
};


// Check whether current pointer is Null or not.
template <typename T>
bool DoublyIterator<T>::IsNull()
{
	return (m_pCurPointer == NULL);
}


// Check whether next and current pointer is Null or not.
template <typename T>
bool DoublyIterator<T>::NextNotNull()
{
	if (m_pCurPointer != nullptr && m_pCurPointer->next != NULL) {		// 현재 포인터가 NULL이 아니고, 다음 포인터도 NULL이 아닌경우.
		return true;											
	}
	return false;
}


// Move the pointer to the next pointer.
template <typename T>
void DoublyIterator<T>::Next()
{
	m_pCurPointer = m_pCurPointer->next;								// 포인터 이동.
}


// Refer to the data that current pointer designated.
template <typename T>
void DoublyIterator<T>::Now(T& _data)
{
	_data = m_pCurPointer->data;										// 현재 포인터가 가지고 있는 데이터를 참조.
}