#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "DoubleLinkedList.h"


template <typename T>
struct DoublyNodeType;
template <typename T>
class DoubleLinkedList;


template <typename T>
class DoublyIterator
{
	friend class DoubleLinkedList<T>;

private:
	const DoubleLinkedList<T>& m_pDoubleList;
	DoublyNodeType<T>* m_pCurPointer;


public:
	DoublyIterator(const DoubleLinkedList<T>& _list) : m_pDoubleList(_list), m_pCurPointer(_list.m_pFirst) {};


	bool NotNull();
	bool NextNotNull();
	T First();
	T Next();
	DoublyNodeType<T> GetCurrentNode();
};


template <typename T>
bool DoublyIterator<T>::NotNull()
{
	return (m_pCurPointer == NULL);
}

template <typename T>
bool DoublyIterator<T>::NextNotNull()
{
	return (m_pCurPointer->next == NULL);
}

template <typename T>
T DoublyIterator<T>::First()
{
	return m_pDoubleList.m_pFirst->data;
}

template <typename T>
T DoublyIterator<T>::Next()
{
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer->data;
}

template <typename T>
DoublyNodeType<T> DoublyIterator<T>::GetCurrentNode()
{
	return *m_pCurPointer;
}