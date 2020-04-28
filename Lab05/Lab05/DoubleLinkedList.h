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
	T data;
	DoublyNodeType* prev;
	DoublyNodeType* next;
};


template <typename T>
class DoubleLinkedList
{
	friend class DoublyIterator<T>;

private:
	DoublyNodeType<T>* m_pFirst;
	DoublyNodeType<T>* m_pLast;
	int m_Length;

public:
	DoubleLinkedList();
	~DoubleLinkedList();

	bool IsEmpty();
	void MakeEmpty();
	//void ResetList(); // Pointer class에서 선언시 기능해서 필요x

	int GetLength() const;
	//int GetNextItem(T& _data); // Pointer class에서 기능해서 필요x

	int Add(const T& _data);
	int Delete(T& _data);
	int Replace(T& _data);
	int Get(T& _data);
};

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	m_pFirst = new DoublyNodeType<T>;
	m_pLast = new DoublyNodeType<T>;
	m_pFirst->prev = NULL;
	m_pFirst->next = m_pLast;
	m_pLast->prev = m_pFirst;
	m_pLast->next = NULL;
	m_Length = 0;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	MakeEmpty();
	delete m_pFirst;
	delete m_pLast;
}

template<typename T>
bool DoubleLinkedList<T>::IsEmpty()
{
	return (m_Length == 0);
}

template<typename T>
void DoubleLinkedList<T>::MakeEmpty()
{
	DoublyNodeType<T>* tempNode;
	DoublyIterator<T> itor(*this);
	itor.Next();
	while (itor.NextNotNull())
	{
		tempNode = itor.m_pCurPointer;
		itor.Next();
		delete tempNode;
	}
	m_pFirst->prev = NULL;
	m_pFirst->next = m_pLast;
	m_pLast->prev = m_pFirst;
	m_pLast->next = NULL;
	m_Length = 0;
}


template<typename T>
int DoubleLinkedList<T>::GetLength() const
{
	return m_Length;
}


template<typename T>
int DoubleLinkedList<T>::Add(const T& _data)
{
	DoublyIterator<T> itor(*this);
	itor.Next();

	if (IsEmpty())
	{
		DoublyNodeType<T>* node = new DoublyNodeType<T>;
		node->data = _data;
		m_pFirst->next = node;
		node->prev = m_pFirst;
		node->next = m_pLast;
		m_pLast->prev = node;
		m_Length++;
		return 1;
	}
	else
	{
		while (1)
		{
			if (_data < itor.m_pCurPointer->data || !itor.NextNotNull())
			{
				DoublyNodeType<T>* node = new DoublyNodeType<T>;
				node->data = _data;
				node->prev = itor.m_pCurPointer->prev;
				node->next = itor.m_pCurPointer;
				itor.m_pCurPointer->prev->next = node;
				itor.m_pCurPointer->prev = node;
				m_Length++;
			}
			else if (_data == itor.m_pCurPointer->data) { return -1; } // 중복
			else { itor.Next(); }
		}
	}
}

template<typename T>
int DoubleLinkedList<T>::Delete(T& _data)
{
	DoublyIterator<T>* itor(*this);
	itor.Next();

	if (IsEmpty()) { return 0; }
	while(itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == _data)
		{
			DoublyNodeType<T>* tempNode = new DoublyNodeType<T>;
			tempNode = itor.m_pCurPointer;
			itor.Next();
			tempNode->prev->next = itor.m_pCurPointer;
			itor.m_pCurPointer->prev = tempNode->prev;
			delete tempNode;
			m_Length--;
			return 1;
		}
		else { itor.Next(); }
	}
	return 0;
}

template<typename T>
int DoubleLinkedList<T>::Replace(T& _data)
{
	DoublyIterator<T> itor(*this);
	itor.Next();

	if (IsEmpty()) { return 0; }
	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == _data)
		{
			itor.m_pCurPointer->data = _data;
			return 1;
		}
		else { itor.Next(); }
	}
	return 0;
}

template<typename T>
int DoubleLinkedList<T>::Get(T& _data)
{
	DoublyIterator<T> itor(*this);
	itor.Next();

	if (IsEmpty()) { return 0; }
	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == _data)
		{
			_data = itor.m_pCurPointer->data;
			return 1;
		}
		else { itor.Next(); }
	}
	return 0;
}