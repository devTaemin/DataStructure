#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <typename T>
struct NodeType
{
	T data;
	NodeType* next;
};


template <typename T>
class SingleLinkedList
{
private:
	NodeType<T>* m_pSingleList;
	NodeType<T>* m_pCurPointer;
	int m_Length;

public:
	SingleLinkedList();
	~SingleLinkedList();

	//bool IsFull();
	bool IsEmpty();

	void MakeEmpty();
	void ResetList();

	int GetLength();
	int GetNextItem(T& _data);

	int Add(const T& _data);
	int Delete(T _data);
	int Replace(T& _data);
	int Get(T& _data);

	void operator=(SingleLinkedList& _list)
	{
		MakeEmpty();
		if (!_list.IsEmpty())
		{
			_list.ResetList();
			T item;
			//_list.GetNextItem(item); //ó���� ������ -1�� �����ϴϱ� loop������ �޾Ƽ� ���ϱ�.
			//Add(item);
			while (_list.GetNextItem(item) != -1) {
				Add(item);
			}
		}
	}
	
	friend ostream& operator<<(ostream& os, SingleLinkedList& _list) {
		T temp;
		_list.ResetList();
		while (_list.GetNextItem(temp) != -1) {
			os << temp << endl;
		}
		return os;
	}
};

template <typename T>
SingleLinkedList<T>::SingleLinkedList()
{
	m_pSingleList = nullptr;
	m_pCurPointer = nullptr;
	m_Length = 0;
}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList()
{
	MakeEmpty();
}


template <typename T>
bool SingleLinkedList<T>::IsEmpty()
{
	return (m_Length == 0);
}

template <typename T>
void SingleLinkedList<T>::MakeEmpty()
{
	NodeType<T>* tempNode;
	while (m_pSingleList != nullptr)
	{
		tempNode = m_pSingleList;
		m_pSingleList = m_pSingleList->next;
		delete tempNode;
	}
	m_Length = 0;
}

template <typename T>
void SingleLinkedList<T>::ResetList()
{
	m_pCurPointer = nullptr;
}

template <typename T>
int SingleLinkedList<T>::GetLength()
{
	return m_Length;
}

template <typename T>
int SingleLinkedList<T>::GetNextItem(T& _data)
{
	if (m_pCurPointer == nullptr)
	{
		m_pCurPointer = m_pSingleList;
		return -1; // 0���� ���ϰ� -1����.
	}
	else {
		m_pCurPointer = m_pCurPointer->next;
	}
	_data = m_pCurPointer->data;
	return 1;
}

template <typename T>
int SingleLinkedList<T>::Add(const T& _data)
{
	ResetList();
	NodeType<T>* node = new NodeType<T>;
	NodeType<T>* pre;
	T dummy;

	node->data = _data;
	node->next = nullptr;

	if (IsEmpty()) { m_pSingleList = node; }
	else
	{
		while (1)
		{
			pre = m_pCurPointer;
			GetNextItem(dummy);
			if (m_pCurPointer->data > node->data)
			{
				if (pre == nullptr) // �� �տ� �Է½�
				{
					node->next = m_pCurPointer;
					m_pSingleList = node;
					break;
				}
				node->next = m_pCurPointer;
				pre->next = node;
				break;
			}
			else if (m_pCurPointer->data == node->data) // �ߺ��Է� �ȵǵ���!
			{
				return -1; // �ߺ��� ����(-1)
			}

			if (m_pCurPointer->next == nullptr)
			{
				m_pCurPointer->next = node;
				break;
			}
		}
	}
	m_Length++;
	return 1;
}

template <typename T>
int SingleLinkedList<T>::Delete(T _data)
{
	ResetList();
	NodeType<T>* pre;
	T dummy;
	bool found = false;

	if (IsEmpty()) { return 0; }
	else
	{
		while (1)
		{
			pre = m_pCurPointer;
			GetNextItem(dummy);
			if (_data == m_pCurPointer->data)
			{
				found = true;
				if (pre == nullptr) {
					m_pSingleList = m_pCurPointer->next;
					break;
				}
				else {
					pre->next = m_pCurPointer->next;
					delete m_pCurPointer;
					break;
				}
			}
			else if (_data < m_pCurPointer->data){break;}
			else { continue; }
		}
	}

	if (!found) { return 0; }
	m_Length--;
	return 1;
}

template <typename T>
int SingleLinkedList<T>::Replace(T& _data)
{
	ResetList();
	NodeType<T>* pre;
	T dummy;
	bool found = false;

	if (IsEmpty()) { return 0; }
	else
	{
		while (1)
		{
			pre = m_pCurPointer;
			GetNextItem(dummy);
			if (_data == m_pCurPointer->data)
			{
				found = true;
				m_pCurPointer->data = _data;
			}
			else if (_data < m_pCurPointer->data) { break; }
			else { continue; }
		}
	}

	if (!found) { return 0; }
	return 1;
}

template <typename T>
int SingleLinkedList<T>::Get(T& _data)
{
	ResetList();
	NodeType<T>* pre;
	T dummy;
	bool found = false;

	if (IsEmpty()) { return 0; }
	else
	{
		while (1)
		{
			pre = m_pCurPointer;
			GetNextItem(dummy);
			if (_data == m_pCurPointer->data)
			{
				found = true;
				_data = m_pCurPointer->data;
			}
			else if (_data < m_pCurPointer->data) { break; }
			else { continue; }
		}
	}

	if (!found) { return 0; }
	return 1;
}