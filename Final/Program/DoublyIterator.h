#pragma once
template <typename T>
struct DoublyNodeType;
template <typename T>
class DoublySortedLinkedList;


template <typename T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>;

private:
	const DoublySortedLinkedList<T>& m_pList;				///< Iterator�� ������ �ڷ� ��ũ.
	DoublyNodeType<T>* m_pCurPointer;						///< Node pointer.

public:

	DoublyIterator(DoublySortedLinkedList<T>& _list) : m_pList(_list), m_pCurPointer(_list.m_pHead) {}
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

	int Now(T& _data);
	//--------------------------------------------------------------------
	//	Brief:	Refer to the data that current pointer designated.
	//	Pre:	Iterator has initialized.
	//	Post:	none.
	//	Param:	_data		copying vaiable.
	//	Return:	return 1 if fuction works well, otherwise return 0.
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
	if (m_pCurPointer != nullptr && m_pCurPointer->next != NULL) {		// ���� �����Ͱ� NULL�� �ƴϰ�, ���� �����͵� NULL�� �ƴѰ��.
		return true;
	}
	return false;
}


// Move the pointer to the next pointer.
template <typename T>
void DoublyIterator<T>::Next()
{
	m_pCurPointer = m_pCurPointer->next;								// ������ �̵�.
}


// Refer to the data that current pointer designated.
template <typename T>
int DoublyIterator<T>::Now(T& _data)
{
	if (NextNotNull() && m_pCurPointer != m_pList.m_pTail) {
		_data = m_pCurPointer->data;										// ���� �����Ͱ� ������ �ִ� �����͸� ����.
		return 1;															// ����.
	}
	return 0;																// ����.

}