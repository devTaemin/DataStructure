#ifndef _SortedLinkedList_hpp_
#define _SortedLinkedList_hpp_
#include "NodeType.hpp"

template <typename T>
class LinkedList
{
public:
	LinkedList<T>() : m_nLength(0)
	{
		m_pList = new NodeType<T>;
		m_pList->next = NULL;
		m_pCurPointer = m_pList;
	}

	~LinkedList<T>()
	{
		m_pCurPointer = m_pList;
		while (m_pCurPointer->next != NULL) {
			NodeType<T>* temp = m_pCurPointer;
			m_pCurPointer = m_pCurPointer->next;
			delete[] temp;
		}
		m_nLength = 0;
		delete[] m_pCurPointer;
	}

	void MakeEmpty()
	{
		m_pList->info = NULL;
		m_pList->next = NULL;
		ResetList();
		m_nLength = 0;
	}

	int GetLength() const 
	{
		return m_nLength;
	}

	int Add(T item)
	{
		ResetList();
		if (GetLength() == 0) {
			m_pCurPointer->info = item;
		}
		else {
			NodeType<T>* temp = new NodeType<T>;
			temp->info = item;
			temp->next = NULL;
			if (m_pList->info >= temp->info) {
				temp->next = m_pList;
				m_pList = temp;
			}
			else {
				NodeType<T>* compare = m_pCurPointer->next;
				while (compare != NULL) {
					if (temp->info < compare->info) {
						m_pCurPointer = m_pCurPointer->next;
						continue;
					}
					else { break; }
				}
				temp->next = m_pCurPointer->next;
				m_pCurPointer->next = temp;
			}
		}
		m_nLength++;
		return 1;
	}

	int DeleteItem(T item)
	{
		ResetList();
		if (GetLength() == 0) {
			return 0;
		}
		else {
			NodeType<T>* cur = m_pCurPointer;
			NodeType<T>* pre = cur;
			while (cur != NULL) {
				if (cur->info != item) {
					pre = cur;
					cur = cur->next;
				}
				else {
					pre->next = cur->next;
					delete[] cur;
				}
			}
		}
		m_nLength--;
		return 1;
	}

	int Get(T& item)
	{
		item = m_pCurPointer->info;
		return 0;
	}

	void ResetList()
	{
		m_pCurPointer = m_pList;
	}

	void GetNextItem(T& item)
	{
		NodeType<T>* next = m_pCurPointer->next;
		item = next->info;
	}

	void printAll()
	{

	}
private:
	NodeType<T>* m_pList;
	NodeType<T>* m_pCurPointer;
	int m_nLength;
};
#endif