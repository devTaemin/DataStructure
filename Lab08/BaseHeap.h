#pragma once
//--------------------------------------------------------------------
//		Base Heap Class.
//--------------------------------------------------------------------
template <typename T>
class BaseHeap
{
protected:
	T* m_pHeap;					///< Data Storage
	int m_iLastNode;			///< End of array
	int m_MaxSize;				///< MaxSize of array

public:
	BaseHeap();
	//--------------------------------------------------------------------
	//		Default Constructor.
	//--------------------------------------------------------------------


	virtual ~BaseHeap();
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	bool IsEmpty();
	//----------------------------------------------------------------
	//	Brief  : Check Whether array is empty.
	//	Pre    : None.
	//	Post   : None.
	//	Return : Return True if array is empty, otherwise False.
	//----------------------------------------------------------------


	bool IsFull();
	//----------------------------------------------------------------
	//	Brief  : Check Whether array is full.
	//	Pre    : None.
	//	Post   : None.
	//	Return : Return True if array is full, otherwise False.
	//----------------------------------------------------------------


	int GetLength() const;
	//----------------------------------------------------------------
	//	Brief  : Get the length of array.
	//	Pre    : None.
	//	Post   : None.
	//	Return : Return the length of array.
	//----------------------------------------------------------------


	void MakeEmpty();
	//----------------------------------------------------------------
	//	Brief  : Make array empty.
	//	Pre    : None.
	//	Post   : array is empty.
	//----------------------------------------------------------------


	virtual int Add(T item);
	//----------------------------------------------------------------
	//	Brief  : Add new item in array.
	//	Pre    : None.
	//	Post   : New item is added in array.
	//----------------------------------------------------------------


	virtual int Delete(T item);
	//----------------------------------------------------------------
	//	Brief  : Delete target item from array.
	//	Pre    : None.
	//	Post   : Target item is deleted from array.
	//----------------------------------------------------------------


	virtual T Dequeue();
	//----------------------------------------------------------------
	//	Brief  : Delete first item from array.
	//	Pre    : None.
	//	Post   : First item is deleted from array.
	//----------------------------------------------------------------


	virtual void RetrieveItem(T& _item, bool& _found);
	//----------------------------------------------------------------
	//	Brief  : Retrieve target item from array.
	//	Pre    : Initialize bool variable to check if node is founded.
	//	Post   : None.
	//----------------------------------------------------------------


	virtual void PrintHeap();
	//----------------------------------------------------------------
	//	Brief  : Print Heap data.
	//	Pre    : Heap is initialized.
	//	Post   : Print heap data.
	//----------------------------------------------------------------


	virtual void ReheapDown(int _iparent, int _ibottom) = 0;
	//----------------------------------------------------------------
	//	Brief  : Compare item from top to down and arrange the array
	//	Pre    : Heap is initialized.
	//	Post   : Heap is arranged
	//	Param  : _iparent		start data.
	//	Param  : _ibottom		end data.
	//----------------------------------------------------------------


	virtual void ReheapUp(int _iroot, int _ibottom) = 0;
	//----------------------------------------------------------------
	//	Brief  : Compare item from top to down and arrange the array
	//	Pre    : Heap is initialized.
	//	Post   : Heap is arranged
	//	Param  : _iparent		start data.
	//	Param  : _ibottom		end data.
	//----------------------------------------------------------------


	virtual void Delete(T _item, bool& _found, int _iparent) = 0;
	//----------------------------------------------------------------
	//	Brief  : Virtual function for deleting data.
	//	Pre    : Heap is initialized.
	//	Post   : Target Data is deleted.
	//	Param  : _item			target data.
	//	Param  : _found			boolean variable
	//	Param  : _iparent		start data.
	//----------------------------------------------------------------


	virtual void Retrieve(T& _item, bool& _found, int _iparent) = 0;
	//----------------------------------------------------------------
	//	Brief  : Virtual function for deleting data.
	//	Pre    : Heap is initialized.
	//	Post   : Target Data is deleted.
	//	Param  : _item			target data.
	//	Param  : _found			boolean variable
	//	Param  : _iparent		start data.
	//----------------------------------------------------------------


	void Swap(int _iparent, int _ibottom);
	//----------------------------------------------------------------
	//	Brief  : Change the two data in the heap.
	//	Pre    : Heap is initialized.
	//	Post   : the location of data is changed.
	//	Param  : _iparent		Target data.
	//	Param  : _ibottom		Target data.
	//----------------------------------------------------------------
};


template <typename T>
BaseHeap<T>::BaseHeap()
{
	m_iLastNode = 0;
}


template <typename T>
BaseHeap<T>::~BaseHeap()
{
	MakeEmpty();
}


template <typename T>
bool BaseHeap<T>::IsEmpty()
{
	if (m_iLastNode == 0)
		return 1;
	else
		return 0;
}


template <typename T>
bool BaseHeap<T>::IsFull()
{
	if (m_iLastNode == m_MaxSize)
		return 1;
	else
		return 0;
}


template <typename T>
int BaseHeap<T>::GetLength() const
{
	return m_iLastNode;
}


template <typename T>
void BaseHeap<T>::MakeEmpty()
{
	delete[] m_pHeap;
}


template <typename T>
int BaseHeap<T>::Add(T item)
{
	m_pHeap[m_iLastNode] = item;
	ReheapUp(0, m_iLastNode);
	m_iLastNode++;
	return 1;
}


template <typename T>
int BaseHeap<T>::Delete(T item)
{
	bool found = false;
	Delete(item, found, 0);

	if (found)
		m_iLastNode--;
	else
		return 0;

	return 1;
}


template <typename T>
T BaseHeap<T>::Dequeue()
{
	T item = m_pHeap[0];
	Delete(item);
	return item;
}


template <typename T>
void BaseHeap<T>::RetrieveItem(T& _item, bool& _found)
{
	Retrieve(_item, _found, 0);
}


template <typename T>
void BaseHeap<T>::PrintHeap()
{
	T item;
	for (int i = 0; i < m_iLastNode; i++)
	{
		item = m_pHeap[i];
		cout << item << endl;
	}
}


template <typename T>
void BaseHeap<T>::Swap(int _iparent, int _ibottom)
{
	T temp = m_pHeap[_iparent];
	m_pHeap[_iparent] = m_pHeap[_ibottom];
	m_pHeap[_ibottom] = temp;
}