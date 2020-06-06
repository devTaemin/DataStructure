#pragma once
template <typename T>
class DoublyIterator;


template <typename T>
struct DoublyNodeType
{
	T data;								///< node�� ����ִ� �ڷ�.
	DoublyNodeType<T>* prev;			///< ���� node.
	DoublyNodeType<T>* next;			///< ���� node.
};


template <typename T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>;

private:
	DoublyNodeType<T>* m_pHead;			///< ���߿��Ḯ��Ʈ�� ���� node.
	DoublyNodeType<T>* m_pTail;			///< ���߿��Ḯ��Ʈ�� �� node.
	int m_Length;						///< ����� node�� ���� (�������� ��).

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

	friend ostream& operator<<(ostream& os, DoublySortedLinkedList<T>& _list)
	{
		DoublyIterator<T> itor(_list);					// ���߿��Ḯ��Ʈ�� �����Ϳ� ����.
		itor.Next();									// Head ���� node�� �̵�.
		while (itor.NextNotNull()) {					// ����� ���� node�� NULL�� �ƴϸ� �ݺ�.
			T data;
			itor.Now(data);								// ���߿��Ḯ��Ʈ�� node�� ���� data�� ����.
			os << data << endl;							// �ش� �ڷ����� operator�� �̿��Ͽ� ���
			itor.Next();								// ������ �̵��Ͽ� ���� node ����
		}
		return os;										// ���.
	}
};


// Constructor.
template <typename T>
DoublySortedLinkedList<T>::DoublySortedLinkedList()
{
	m_pHead = new DoublyNodeType<T>;					// head node ����.
	m_pTail = new DoublyNodeType<T>;					// tail node ����.
	m_pHead->prev = NULL;								// head ���� NULL, ���� Tail ����.
	m_pHead->next = m_pTail;
	m_pTail->prev = m_pHead;							// Tail ���� head, ���� NULL ����.
	m_pTail->next = NULL;
	m_Length = 0;										// ���� 0���� �ʱ�ȭ.
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
	DoublyNodeType<T>* tempNode;						// �ӽ� node ����.
	DoublyIterator<T> itor(*this);						// Pointer ����.
	itor.Next();										// Pointer�� head �������� �̵�.
	while (itor.NextNotNull())							// loop.
	{
		tempNode = itor.m_pCurPointer;					// �ӽ� node�� ���� node�� ����Ŵ.
		itor.Next();									// Pointer�� ���� node�� �̵�.
		delete tempNode;								// �ӽ� node�� ���� node ����.
	}
	m_pHead->prev = NULL;								// �ʱ� ����.
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
	if (IsEmpty())															// ����Ʈ�� ��������� head�� tail ���̿� �Է�.
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
			itor.Now(curData);
			if (_data == curData) { return -1; }							// ��ϼ����� ���ٸ� �ߺ� �Է��̹Ƿ� ����(-1).
			else if (_data < curData || !itor.NextNotNull()) {				// ���� node���� �۰ų�, ���� node�� NUll Ȥ�� ���� node�� NULL�� ���(���� Tail node).
				DoublyNodeType<T>* node = new DoublyNodeType<T>;			// node ����.
				node->data = _data;											// node�� �����͸� ����.
				node->prev = itor.m_pCurPointer->prev;						// node ���� node�� ���� node�� ���� node.
				node->next = itor.m_pCurPointer;							// node ���� node�� ���� node.
				itor.m_pCurPointer->prev->next = node;						// ���� node ������ ���� node�� �� node.
				itor.m_pCurPointer->prev = node;							// ���� node ���� node�� �� node.
				m_Length++;													// ���� ����.
				return 1;													// ����(1).
			}
			else { itor.Next(); }											// ���� node�� �̵�.
		}
	}
}


// Delete data from the list.
template <typename T>
int DoublySortedLinkedList<T>::Delete(T& _data)
{
	DoublyIterator<T> itor(*this);
	itor.Next();

	if (IsEmpty()) { return 0; }											// ����ִ� ��� ����(0);
	while (itor.NextNotNull() && itor.m_pCurPointer != m_pTail)				// ���� pointer�� ���� �����Ҷ� ���� �ݺ�.
	{
		if (itor.m_pCurPointer->data == _data)
		{
			DoublyNodeType<T>* tempNode = new DoublyNodeType<T>;			// �ӽ� node ����.
			tempNode = itor.m_pCurPointer;
			itor.Next();
			tempNode->prev->next = itor.m_pCurPointer;						// �ӽ� node�� �հ� �� node�� ����
			itor.m_pCurPointer->prev = tempNode->prev;
			delete tempNode;												// �ش� node�� ����.
			m_Length--;														// ���� ����.
			return 1;														// ����(1).
		}
		else { itor.Next(); }												// ���� node�� �̵�.
	}
	return 0;																// ����.
}


// Replace data in the list.
template <typename T>
int DoublySortedLinkedList<T>::Replace(T& _data)
{
	DoublyIterator<T> itor(*this);
	itor.Next();

	if (IsEmpty()) { return 0; }											// ����Ʈ�� ��������� ����(0).
	while (itor.NextNotNull() && itor.m_pCurPointer != m_pTail)									// �� node�� �����Ҷ����� loop.
	{
		if (itor.m_pCurPointer->data == _data)								// target data�� �߰��Ѵٸ�.
		{
			itor.m_pCurPointer->data = _data;								// ������ ������ data�� replace.
			return 1;														// ����(1).
		}
		else { itor.Next(); }												// ���� node�� �̵�.
	}
	return 0;																// ����(0).
}


// Get data from the list.
template <typename T>
int DoublySortedLinkedList<T>::Get(T& _data)
{
	DoublyIterator<T> itor(*this);
	itor.Next();

	if (IsEmpty()) { return 0; }											// ����Ʈ�� ��������� ����(0).
	while (itor.NextNotNull() && itor.m_pCurPointer != m_pTail)									// �� node�� �����Ҷ����� loop.
	{
		if (itor.m_pCurPointer->data == _data)								// target data�� �߰��Ѵٸ�.
		{
			_data = itor.m_pCurPointer->data;								// target data�� �����ؼ� �޾ƿ´�.
			return 1;														// ����(1).
		}
		else { itor.Next(); }												// ���� node�� �̵�.
	}
	return 0;																// ����(0).
}
