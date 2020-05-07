#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


#include "DoublyIterator.h"
template <typename T>
class DoublyIterator;


template <typename T>
struct DoublyNodeType
{
	T data;								///< node가 담고있는 자료.
	DoublyNodeType<T>* prev;			///< 다음 node.
	DoublyNodeType<T>* next;			///< 이전 node.
};


template <typename T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>;

private:
	DoublyNodeType<T>* m_pHead;			///< 이중연결리스트의 시작 node.
	DoublyNodeType<T>* m_pTail;			///< 이중연결리스트의 끝 node.
	int m_Length;						///< 연결된 node의 수량 (데이터의 수).

public:
	DoublySortedLinkedList();
	//--------------------------------------------------------------------
	//		Constructor.
	//--------------------------------------------------------------------

	~DoublySortedLinkedList();
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------

	bool IsEmpty();
	//--------------------------------------------------------------------
	//	Brief:	Check whether list is empty or not.
	//	Pre:	list has initialized.
	//	Post:	none.
	//	Return:	return true if list is empty, otherwise return false.
	//--------------------------------------------------------------------

	void MakeEmpty();
	//--------------------------------------------------------------------
	//	Brief:	Make list empty.
	//	Pre:	list has initialized.
	//	Post:	list is empty.
	//--------------------------------------------------------------------

	int GetLength() const;
	//--------------------------------------------------------------------
	//	Brief:	Display the number of stored data.
	//	Pre:	none.
	//	Post:	none.
	//	Return:	number of data.
	//--------------------------------------------------------------------

	int Add(T& _data);
	//--------------------------------------------------------------------
	//	Brief:	Add new data in the list.
	//	Pre:	the list has initialized.
	//	Post:	new data is stored in the list.
	//	Param:	_data			new data.
	//	Return:	return 1 if function works well, otherwise -1(duplicated).
	//--------------------------------------------------------------------

	int Delete(T& _data);
	//--------------------------------------------------------------------
	//	Brief:	Delete data from the list.
	//	Pre:	the list has initialized.
	//	Post:	data is removed from the list.
	//	Param:	_data			target data.
	//	Return:	return 1 if function works well, otherwise 0(fail).
	//--------------------------------------------------------------------

	int Replace(T& _data);
	//--------------------------------------------------------------------
	//	Brief:	Replace data in the list.
	//	Pre:	the list has initialized.
	//	Post:	data's record is replaced.
	//	Param:	_data			target data.
	//	Return:	return 1 if function works well, otherwise 0(fail).
	//--------------------------------------------------------------------

	int Get(T& _data);
	//--------------------------------------------------------------------
	//	Brief:	Get data from the list.
	//	Pre:	the list has initialized.
	//	Post:	data is refered by copying argument.
	//	Param:	_data			target data.
	//	Return:	return 1 if function works well, otherwise 0(fail).
	//--------------------------------------------------------------------

	void operator=(const DoublySortedLinkedList<T>& _list)
	{
		m_pHead = _list.m_pHead;
		m_pTail = _list.m_pTail;
		m_Length = _list.m_Length;
	}

	friend ostream& operator<<(ostream& os, const DoublySortedLinkedList<T>& _list)
	{
		DoublyIterator<T> itor(_list);					// 이중연결리스트를 포인터에 연결.
		itor.Next();									// Head 다음 node로 이동.
		while (itor.NextNotNull()) {					// 현재와 다음 node가 NULL이 아니면 반복.
			T data;
			itor.Now(T);								// 이중연결리스트의 node가 가진 data를 참조.
			os << data << endl;							// 해당 자료형을 operator을 이용하여 출력
			itor.Next();								// 포인터 이동하여 다음 node 지정
		}
		return os;										// 출력.
	}
};


// Constructor.
template <typename T>
DoublySortedLinkedList<T>::DoublySortedLinkedList()
{
	m_pHead = new DoublyNodeType<T>;					// head node 생성.
	m_pTail = new DoublyNodeType<T>;					// tail node 생성.
	m_pHead->prev = NULL;								// head 이전 NULL, 이후 Tail 연결.
	m_pHead->next = m_pTail;
	m_pTail->prev = m_pHead;							// Tail 이전 head, 이후 NULL 연결.
	m_pTail->next = NULL;
	m_Length = 0;										// 길이 0으로 초기화.
}


// Destructor.
template <typename T>
DoublySortedLinkedList<T>::~DoublySortedLinkedList()
{
	/*
	MakeEmpty();
	delete m_pHead;
	delete m_pLast;
	*/
}


// Check whether list is empty or not.
template <typename T>
bool DoublySortedLinkedList<T>::IsEmpty()
{
	return (m_Length == 0);
}


// Make list empty.
template <typename T>
void DoublySortedLinkedList<T>::MakeEmpty()
{
	DoublyNodeType<T>* tempNode;						// 임시 node 생성.
	DoublyIterator<T> itor(*this);						// Pointer 생성.
	itor.Next();										// Pointer가 head 다음으로 이동.
	while (itor.NextNotNull())							// loop.
	{
		tempNode = itor.m_pCurPointer;					// 임시 node가 현재 node를 가리킴.
		itor.Next();									// Pointer가 다음 node로 이동.
		delete tempNode;								// 임시 node로 받은 node 해제.
	}
	m_pHead->prev = NULL;								// 초기 설정.
	m_pHead->next = m_pTail;
	m_pTail->prev = m_pHead;
	m_pTail->next = NULL;
	m_Length = 0;
}


// Display the number of stored data.
template <typename T>
int DoublySortedLinkedList<T>::GetLength() const
{
	return m_Length;
}


// Add new data in the list.
template <typename T>
int DoublySortedLinkedList<T>::Add(T& _data)
{
	DoublyIterator<T> itor(*this);
	itor.Next();
	if (IsEmpty())															// 리스트가 비어있으면 head와 tail 사이에 입력.
	{
		DoublyNodeType<T>* node = new DoublyNodeType<T>;
		node->data = _data;
		m_pHead->next = node;
		node->prev = m_pHead;
		node->next = m_pTail;
		m_pTail->prev = node;
		m_Length++;
		return 1;
	}
	else
	{
		while (1)
		{
			T curData;
			if (_data == itor.Now(curData)) { return -1; }					// 등록순위가 같다면 중복 입력이므로 실패(-1).
			else if (_data < itor.Now(curData) && !itor.NextNotNull()) {	// 현재 node보다 작거나, 현재 node가 NUll 혹은 다음 node가 NULL인 경우(현재 Tail node).
				DoublyNodeType<T>* node = new DoublyNodeType<T>;			// node 생성.
				node->data = _data;											// node에 데이터를 저장.
				node->prev = itor.m_pCurPointer->prev;						// node 이전 node는 기존 node의 이전 node.
				node->next = itor.m_pCurPointer;							// node 다음 node는 기존 node.
				itor.m_pCurPointer->prev->next = node;						// 기존 node 이전의 다음 node는 새 node.
				itor.m_pCurPointer->prev = node;							// 기존 node 이전 node는 새 node.
				m_Length++;													// 길이 증가.
				return 1;													// 성공(1).
			}
			else { itor.Next(); }											// 다음 node로 이동.
		}
	}
}


// Delete data from the list.
template <typename T>
int DoublySortedLinkedList<T>::Delete(T& _data)
{
	DoublyIterator<T> itor(*this);
	itor.Next();

	if (IsEmpty()) { return 0; }											// 비어있는 경우 실패(0);
	while (itor.m_pCurPointer != m_pTail)									// 현재 pointer가 끝에 도달할때 까지 반복.
	{
		if (itor.m_pCurPointer->data == _data)
		{
			DoublyNodeType<T>* tempNode = new DoublyNodeType<T>;			// 임시 node 생성.
			tempNode = itor.m_pCurPointer;
			itor.Next();
			tempNode->prev->next = itor.m_pCurPointer;						// 임시 node의 앞과 뒤 node를 연결
			itor.m_pCurPointer->prev = tempNode->prev;
			delete tempNode;												// 해당 node를 해제.
			m_Length--;														// 길이 감소.
			return 1;														// 성공(1).
		}
		else { itor.Next(); }												// 다음 node로 이동.
	}
	return 0;																// 실패.
}


// Replace data in the list.
template <typename T>
int DoublySortedLinkedList<T>::Replace(T& _data)
{
	DoublyIterator<T> itor(*this);
	itor.Next();

	if (IsEmpty()) { return 0; }											// 리스트가 비어있으면 실패(0).
	while (itor.m_pCurPointer != m_pTail)									// 끝 node에 도달할때까지 loop.
	{
		if (itor.m_pCurPointer->data == _data)								// target data를 발견한다면.
		{
			itor.m_pCurPointer->data = _data;								// 수정된 정보로 data를 replace.
			return 1;														// 성공(1).
		}
		else { itor.Next(); }												// 다음 node로 이동.
	}
	return 0;																// 실패(0).
}


// Get data from the list.
template <typename T>
int DoublySortedLinkedList<T>::Get(T& _data)
{
	DoublyIterator<T> itor(*this);
	itor.Next();

	if (IsEmpty()) { return 0; }											// 리스트가 비어있으면 실패(0).
	while (itor.m_pCurPointer != m_pTail)									// 끝 node에 도달할때까지 loop.
	{
		if (itor.m_pCurPointer->data == _data)								// target data를 발견한다면.
		{
			_data = itor.m_pCurPointer->data;								// target data를 참조해서 받아온다.
			return 1;														// 성공(1).
		}
		else { itor.Next(); }												// 다음 node로 이동.
	}
	return 0;																// 실패(0).
}
