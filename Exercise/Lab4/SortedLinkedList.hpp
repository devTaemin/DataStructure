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
		while (m_pCurPointer != NULL) {
			NodeType<T>* temp = m_pCurPointer;
			m_pCurPointer = m_pCurPointer->next;
			delete[] temp;
		}
		m_nLength = 0;
		delete[] m_pCurPointer;
	}

	void MakeEmpty()
	{
		m_pList->next = NULL;
		m_nLength = 0;
		ResetList();
	}

	int GetLength() const 
	{
		return m_nLength;
	}

	int Add(T item)
	{
		ResetList();
		if (GetLength() == 0) {
			m_pList->info = item;
		}
		else {
			NodeType<T>* temp = new NodeType<T>;
			NodeType<T>* pre = m_pCurPointer;
			temp->info = item;
			temp->next = NULL;
			if (temp->info <= m_pCurPointer->info) {
				temp->next = m_pCurPointer;
				m_pList = temp;
			}
			else {
				while (m_pCurPointer != NULL) {
					if (m_pCurPointer->info <= temp->info) {
						pre = m_pCurPointer;
						m_pCurPointer = m_pCurPointer->next;
					}
					else { break; }
				}
				temp->next = pre->next;
				pre->next = temp;
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
			NodeType<T>* pre = m_pCurPointer;
			if (item == m_pList->info) {
				m_pList = m_pCurPointer->next;
				m_nLength--;
				return 1;
			}
			else {
				while (m_pCurPointer != NULL) {
					if (item == m_pCurPointer->info) {
						pre->next = m_pCurPointer->next;
						m_nLength--;
						return 1;
					}
					else {
						pre = m_pCurPointer;
						m_pCurPointer = m_pCurPointer->next;
					}
				}
				return 0;
			}
		}
	}


	int ReplaceItem(T item_1, T item_2) 
	{
		ResetList();
		if (GetLength() == 0) {
			return 0;
		}
		else {
			while (m_pCurPointer != NULL) {
				if (item_1 == m_pCurPointer->info) {
					DeleteItem(item_1);
					Add(item_2);
					return 1;
				}
				else {
					m_pCurPointer = m_pCurPointer->next;
				}
			}
			return 0;
		}
	}

	int RetrieveItem(T item)
	{
		ResetList();
		if (GetLength() == 0) {
			return 0;
		}
		else {
			while (m_pCurPointer != NULL) {
				if (item == m_pCurPointer->info) {
					return 1;
				}
				else {
					m_pCurPointer = m_pCurPointer->next;
				}
			}
			return 0;
		}
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
		ResetList();
		if (GetLength() == 0) {
			cerr << "       " << "Empty List" << endl;
		}
		else {
			while (m_pCurPointer != NULL) {
				cout << "  " << m_pCurPointer->info << endl;
				m_pCurPointer = m_pCurPointer->next;
			}
		}
	}

private:
	NodeType<T>* m_pList;
	NodeType<T>* m_pCurPointer;
	int m_nLength;
};
#endif