#pragma once
#include "pch.h"
template<typename T>
struct NodeType {
	T info;
	NodeType<T>* next;
};


template<typename T>
class SingleLinkedList
{
private:
	NodeType<T>* m_List;
	NodeType<T>* m_CurPointer;
	int m_Length;
public:
	SingleLinkedList();
	~SingleLinkedList();

	bool IsEmpty() const;
	void MakeEmpty();
	void ResetList();
	int GetNextItem(T& _item);
	int GetLength() const;
	int Add(T _item);
	int Get(T& _item);
	int Delete(T _item);
	int Replace(T _item);

	void operator=(const SingleLinkedList& _item)
	{
		MakeEmpty();
		if (!_item.IsEmpty()) {
			T item;
			_item.ResetList();
			while (_item.GetNextItem(item) != 0) {
				Add(item);
			}
		}
	}

	void Equal(SingleLinkedList _item)	// const로 인한 오류로 인해 같은 기능을 하는 함수 생성
	{
		MakeEmpty();
		if (!_item.IsEmpty()) {
			T item;
			_item.ResetList();
			while (_item.GetNextItem(item) != 0) {
				Add(item);
			}
		}
	}
};


template<typename T>
SingleLinkedList<T>::SingleLinkedList() 
{
	m_List = nullptr;
	ResetList();
	m_Length = 0;
}


template<typename T>
SingleLinkedList<T>::~SingleLinkedList() 
{
	MakeEmpty();
}


template<typename T>
bool SingleLinkedList<T>::IsEmpty() const
{
	return (m_Length == 0);
}


template<typename T>
void SingleLinkedList<T>::MakeEmpty()
{
	NodeType<T>* temp;
	while (m_List != nullptr)
	{
		temp = m_List;
		m_List = m_List->next;
		delete temp;
	}
	ResetList();
	m_Length = 0;
}


template<typename T>
void SingleLinkedList<T>::ResetList()
{
	m_CurPointer = nullptr;
}


template<typename T>
int SingleLinkedList<T>::GetNextItem(T& _item)
{
	if (m_CurPointer == nullptr) {
		m_CurPointer = m_List;
	}
	else { m_CurPointer = m_CurPointer->next; }


	if (m_CurPointer != nullptr) {
		_item = m_CurPointer->info;
		return 1;
	}
	else {
		return -1;
	}
	
}


template<typename T>
int SingleLinkedList<T>::GetLength() const
{
	return m_Length;
}


template<typename T>
int SingleLinkedList<T>::Add(T _item)
{
	NodeType<T>* node = new NodeType<T>;
	node->info = _item;
	node->next = nullptr;

	ResetList();
	if (IsEmpty()) {
		m_List = node;
		m_Length++;
		return 1;
	}
	else 
	{
		NodeType<T>* pre;
		T dummy;
		while (1) {
			pre = m_CurPointer;
			GetNextItem(dummy);
			if (node->info == m_CurPointer->info) {
				return 0;
			}
			else if (node->info < m_CurPointer->info) {
				if (m_CurPointer == m_List) {
					node->next = m_CurPointer;
					m_List = node;
					break;
				}
				pre->next = node;
				node->next = m_CurPointer;
				break;
			}
			else {
				if (m_CurPointer->next == nullptr) {
					m_CurPointer->next = node;
					break;
				}
			}
		}
	}
	m_Length++;
	return 1;
}


template<typename T>
int SingleLinkedList<T>::Get(T& _item)
{
	ResetList();
	if (IsEmpty()) { return 0; }
	else {
		T dummy;
		bool found = false;
		while (!found)
		{
			GetNextItem(dummy);
			if (m_CurPointer == nullptr) { return 0; }
			if (m_CurPointer->info == _item) {
				_item = m_CurPointer->info;
				found = true;
			}
			else if (m_CurPointer->info > _item) {
				break;
			}
			else { continue; }
		}

		if (!found) { return 0; }
		return 1;
	}
}


template<typename T>
int SingleLinkedList<T>::Delete(T _item)
{
	ResetList();
	if (IsEmpty()) { return 0; }
	else 
	{
		NodeType<T>* pre;
		T dummy;
		bool found = false;
		while (!found)
		{
			pre = m_CurPointer;
			GetNextItem(dummy);
			if (m_CurPointer == nullptr) { break; }
			if (m_CurPointer->info == _item) {
				if (pre == nullptr) {
					m_List = m_List->next;
				}
				pre->next = m_CurPointer->next;
				delete m_CurPointer;
				found = true;
			}
			else {
				if (m_CurPointer->info > _item) {break;}
			}
		}
		if (!found) { return 0; }
		m_Length--;
		return 1;
	}
	
}


template<typename T>
int SingleLinkedList<T>::Replace(T _item)
{
	ResetList();
	if (IsEmpty()) { return 0; }
	else
	{
		T dummy;
		bool found;
		while (!found) {
			GetNextItem(dummy);
			if (m_CurPointer == nullptr) { return 0; }
			if (m_CurPointer->info == _item) {
				m_CurPointer->info = _item;
				found = true;
			}
			else if (m_CurPointer->info > _item) {
				break;
			}
			else { continue; }
		}

		if (!found) { return 0; }
		return 1;
	}
};