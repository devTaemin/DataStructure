#ifndef _STACK_H_
#define _STACK_H_
#include "pch.h"
//--------------------------------------------------------------------
//		Array based on 'Stack'.
//--------------------------------------------------------------------
template <typename T>
class Stack
{
private:
	int m_Maxsize;				///< max size of stack.
	int m_Top;					///< number of elements.
	int m_CurPointer;			///< iterator pointer.
	T* m_Stack;					///< stack.


public:
	Stack();
	//--------------------------------------------------------------------
	//		Default Constructor.
	//--------------------------------------------------------------------


	Stack(int max);
	//--------------------------------------------------------------------
	//		Constructor.
	//--------------------------------------------------------------------


	~Stack();
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	void MakeEmpty();
	//--------------------------------------------------------------------
	//	Brief:	Make Stack empty. 
	//	Pre:	none.
	//	Post:	clear Stack.	
	//--------------------------------------------------------------------


	void ResetStackPointer();
	//--------------------------------------------------------------------
	//	Brief:	Make Stack iterator reset. 
	//	Pre:	none.
	//	Post:	iterator is reset.
	//--------------------------------------------------------------------


	int GetNextItem(T& data);
	//--------------------------------------------------------------------
	//	Brief:	Update pointer to point to next record,
	//			and get that new record.
	//	Pre:	Stack and stack iterator should not be initialized.
	//	Post:	iterator is moved to next item.
	//	Param:	data		get current iterator's item. 
	//						it does not need to be initialized
	//	Return:	index of current iterator's item if it is not end of Stack,
	//			otherwise return -1.
	//--------------------------------------------------------------------


	bool IsFull() const;
	//--------------------------------------------------------------------
	//	Brief:	Check whether stack is full.
	//	Pre:	Stack has been initialized.
	//	Post:	none.
	//	Return:	return true if stack is full, otherwise false.
	//--------------------------------------------------------------------


	bool IsEmpty() const;
	//--------------------------------------------------------------------
	//	Brief:	Check whether stack is empty.
	//	Pre:	Stack has been initialized.
	//	Post:	none.
	//	Return: return true if stack is empty, otherwise false.
	//--------------------------------------------------------------------


	int Push(T data);
	//--------------------------------------------------------------------
	//	Brief:	Push new data to the top of the stack.
	//	Pre:	Stack has been initialized.
	//	Post:	new item is stored in stack.
	//	Param:	data			new data.
	//	Return:	return 1, if function works successfully, otherwise 0.
	//--------------------------------------------------------------------


	int Pop(T& data);
	//--------------------------------------------------------------------
	//	Brief:	Remove top items from the stack.
	//	Pre:	Stack has been initialized.
	//	Post:	an item is removed from stack.
	//	Param:	data			target data.
	//	Return:	return 1, if function works successfully, otherwise 0.
	//--------------------------------------------------------------------

};
#endif _STACK_H_


// Default Constructor.
template <typename T>
Stack<T>::Stack()
{
	m_Maxsize = MAXSTACK;
	m_Top = -1;
	m_CurPointer = -1;
	m_Stack = new T[m_Maxsize];
}


// constructor.
template <typename T>
Stack<T>::Stack(int max)
{
	m_Maxsize = max;
	m_Top = -1;
	m_CurPointer = -1;
	m_Stack = new T[m_Maxsize];
}


// destructor.
template <typename T>
Stack<T>::~Stack()
{
	delete[] m_Stack;
}


// Make Stack empty. 
template <typename T>
void Stack<T>::MakeEmpty()
{
	m_Top = -1;
	delete[] m_Stack;
	m_Stack = new T[m_Maxsize];
}


// Make Stack iterator reset.
template <typename T>
void Stack<T>::ResetStackPointer()
{
	m_CurPointer = -1;
}


// Update pointer to point to next record, and get that new record.
template <typename T>
int Stack<T>::GetNextItem(T& data)
//---------------------------------------------------------------
// (1) ���� Stack�� empty�̸�, ����(0)�� return.
// (2) ������ �����͸� increment�ؼ�, index�� �Ѿ�� �ʴ��� Ȯ��.
//	   - Maxsize�� ���޽�, ����(-1)�� return.
// (3) data�� ���� �����Ͱ� ����Ű�� stack�� item�� �����ϵ��� �ϰ�
//	   ���� �������� ���� return.
//---------------------------------------------------------------
{
	if (IsEmpty()) { return 0; }							// (1).
	m_CurPointer++;											// (2).
	if (m_CurPointer == m_Maxsize) {
		return -1;
	}
	data = m_Stack[m_CurPointer];							// (3).
	return m_CurPointer;
}


// Check whether stack is full.
template <typename T>
bool Stack<T>::IsFull() const
{
	return (m_Top == m_Maxsize - 1);
}


// Check whether stack is empty.
template <typename T>
bool Stack<T>::IsEmpty() const
{
	return (m_Top == -1);
}


// Push new data to the top of the stack.
template <typename T>
int Stack<T>::Push(T data)
//---------------------------------------------------------------
// (1) ���� Stack�� full�̸�, ����(0)�� return.
// (2) ������ top�� increment�ϰ� ���ο� top���� data�� ����.
//	   ����(1)�� return.
//---------------------------------------------------------------
{
	if (IsFull()) { return 0; }								// (1).
	m_Stack[++m_Top] = data;								// (2).
	return 1;
}


// Remove a top item from the stack.
template <typename T>
int Stack<T>::Pop(T& data)
//---------------------------------------------------------------
// (1) ���� Stack�� empty�̸�, ����(0)�� return.
// (2) ������ top�� ��ġ�� item�� refer�ϰ�, top�� decrement,
//	   ����(1)�� return.
//---------------------------------------------------------------
{
	if (IsEmpty()) { return 0; }							// (1).
	data = m_Stack[m_Top--];								// (2).
	return 1;
}
