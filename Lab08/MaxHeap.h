#pragma once
template <typename T>
class MaxHeap : public BaseHeap<T>
{
public:
	MaxHeap();
	MaxHeap(int _size);

	virtual void ReheapDown(int _iparent, int _ibottom);				//	Override.
	virtual void ReheapUp(int _iroot, int _ibottom);					//	Override.
	virtual void Delete(T _item, bool& _found, int _iparent);			//	Override.
	virtual void Retrieve(T& _item, bool& _found, int _iparent);		//	Override.
};


template <typename T>
MaxHeap<T>::MaxHeap()
{

}


template <typename T>
MaxHeap<T>::MaxHeap(int _size)
{
	this->m_MaxSize = _size;
	this->m_pHeap = new T[this->m_MaxSize];
}


template <typename T>
void MaxHeap<T>::ReheapDown(int _iparent, int _ibottom)
{
	int maxChild;
	int leftChild;
	int rightChild;

	leftChild = _iparent * 2 + 1;
	rightChild = _iparent * 2 + 2;

	if (leftChild <= _ibottom)
	{
		if (leftChild == _ibottom)
			maxChild = leftChild;
		else
		{
			if (this->m_pHeap[leftChild] < this->m_pHeap[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}

		if (this->m_pHeap[_iparent] < this->m_pHeap[maxChild])
		{
			this->swap(_iparent, maxChild);
			ReheapDown(maxChild, _ibottom);
		}
	}
}


template <typename T>
void MaxHeap<T>::ReheapUp(int _iroot, int _ibottom)
{
	int iparent;
	if (_ibottom > _iroot)
	{
		iparent = (_ibottom - 1) / 2;
		if (this->m_pHeap[iparent] < this->m_pHeap[_ibottom])
		{
			this->Swap(iparent, _ibottom);
			ReheapUp(_iroot, iparent);
		}
	}
}


template <typename T>
void MaxHeap<T>::Delete(T _item, bool& _found, int _iparent)
{
	int leftChild;
	int rightChild;

	leftChild = _iparent * 2 + 1;
	rightChild = _iparent * 2 + 2;

	if (this->m_pHeap[_iparent] == _item)
	{
		this->m_pHeap[_iparent] = this->m_pHeap[this->m_iLastNode - 1];
		ReheapDown(_iparent, this->m_iLastNode - 2);
		_found = true;
	}
	if (leftChild < this->m_iLastNode && !_found)
	{
		Delete(_item, _found, leftChild);
	}
	if (rightChild < this->m_iLastNode && !_found)
	{
		Delete(_item, _found, rightChild);
	}
}


template <typename T>
void MaxHeap<T>::Retrieve(T& _item, bool& _found, int _iparent)
{
	int leftChild;
	int rightChild;

	leftChild = _iparent * 2 + 1;
	rightChild = _iparent * 2 + 2;

	if (this->m_pHeap[_iparent] == _item)
	{
		_item = this->m_pHeap[_iparent];
		_found = true;
	}
	if (leftChild < this->m_iLastNode && !_found)
	{
		Retrieve(_item, _found, leftChild);
	}
	if (rightChild < this->m_iLastNode && !_found)
	{
		Retrieve(_item, _found, rightChild);
	}
}