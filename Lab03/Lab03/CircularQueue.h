#ifndef _CIRCULAR_QUEUE_H_
#define _CIRCULAR_QUEUE_H_
//--------------------------------------------------------------------
//		Array based on 'Circular Queue'.
//--------------------------------------------------------------------
template <typename T>
class CircularQueue
{
private:
	int m_Maxsize;				///< maximum size of queue.
	int m_Front;				///< index of one infront of element from queue.
	int m_Rear;					///< index of the last element.
	int m_CurPointer;			///< iterator pointer.
	T* m_Queue;					///< queue.


public:
	CircularQueue();
	//--------------------------------------------------------------------
	//		Default Constructor.
	//--------------------------------------------------------------------


	CircularQueue(int max);
	//--------------------------------------------------------------------
	//		Constructor.
	//--------------------------------------------------------------------


	~CircularQueue();
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	void MakeEmpty();
	//--------------------------------------------------------------------
	//	Brief:	Make Queue empty. 
	//	Pre:	none.
	//	Post:	clear Queue.	
	//--------------------------------------------------------------------


	void ResetQueuePointer();
	//--------------------------------------------------------------------
	//	Brief:	Make Queue iterator reset. 
	//	Pre:	none.
	//	Post:	iterator is reset.
	//--------------------------------------------------------------------


	int GetNextItem(T& data);
	//--------------------------------------------------------------------
	//	Brief:	Update pointer to point to next record,
	//			and get that new record.
	//	Pre:	Queue and queue iterator should not be initialized.
	//	Post:	iterator is moved to next item.
	//	Param:	data		get current iterator's item. 
	//						it does not need to be initialized
	//	Return:	index of current iterator's item if it is not end of Queue,
	//			otherwise return -1.
	//--------------------------------------------------------------------


	bool IsFull() const;
	//--------------------------------------------------------------------
	//	Brief:	Check whether Queue is full.
	//	Pre:	Queue has been initialized.
	//	Post:	none.
	//	Return:	return true if Queue is full, otherwise false.
	//--------------------------------------------------------------------


	bool IsEmpty() const;
	//--------------------------------------------------------------------
	//	Brief:	Check whether Queue is empty.
	//	Pre:	Queue has been initialized.
	//	Post:	none.
	//	Return: return true if stack is empty, otherwise false.
	//--------------------------------------------------------------------


	int EnQueue(T data);
	//--------------------------------------------------------------------
	//	Brief:	Adds new data to the last of the queue.
	//	Pre:	Queue has been initialized.
	//	Post:	none.
	//  Param:	data			new data.
	//	Return: return 1, if functions works well, otherwise 0.
	//--------------------------------------------------------------------


	int DeQueue(T& data);
	//--------------------------------------------------------------------
	//	Brief:	delete data from the first of the queue.
	//	Pre:	Queue has been initialized.
	//	Post:	none.
	//  Param:	data			target data.
	//	Return: return 1, if functions works well, otherwise 0.
	//--------------------------------------------------------------------
};

// Default Constructor.
template <typename T>
CircularQueue<T>::CircularQueue()
{
	m_Maxsize = MAXQUEUE;
	m_Front = m_Maxsize - 1;
	m_Rear = m_Maxsize - 1;
	m_CurPointer = m_Front;
	m_Queue = new T[m_Maxsize];
}


// Constructor.
template <typename T>
CircularQueue<T>::CircularQueue(int max)
{
	m_Maxsize = max + 1;
	m_Front = m_Maxsize - 1;
	m_Rear = m_Maxsize - 1;
	m_CurPointer = m_Front;
	m_Queue = new T[m_Maxsize];
}


// Destructor.
template <typename T>
CircularQueue<T>::~CircularQueue()
{
	delete[] m_Queue;
}


// Make Queue empty. 
template <typename T>
void CircularQueue<T>::MakeEmpty()
{
	m_Front = m_Maxsize - 1;
	m_Rear = m_Maxsize - 1;
	delete[] m_Queue;
	m_Queue = new T[m_Maxsize];
}


// Make Queue iterator reset. 
template <typename T>
void CircularQueue<T>::ResetQueuePointer()
{
	m_CurPointer = m_Front;
}


// Update pointer to point to next record, and get that new record.
template <typename T>
int CircularQueue<T>::GetNextItem(T& data)
//---------------------------------------------------------------
// (1) ���� Queue�� empty�̸�, ����(-1)�� return.
// (2) CircularQueue�� �����Ͱ� ���� �����͸� ����Ű���� �Ѵ�.
//     - ���� �����͸� 1 �����ϰ�, ť�� ���̸�ŭ ��ⷯ ���
// (3) ���� ���� ������ ���� ���� rear���� 1ĭ �ձ��� ���ٸ�, �ʰ�
//     �� �������̹Ƿ�, ����(-1)�� return.
// (4) data�� ���� �����Ͱ� ����Ű�� Queue�� item�� �����ϵ��� �ϰ�
//	   ���� �������� ���� return.
//---------------------------------------------------------------
{
	if (IsEmpty()) { return -1; }							// (1).
	m_CurPointer = (m_CurPointer + 1) % m_Maxsize;			// (2).
	if (m_CurPointer == (m_Rear + 1) % m_Maxsize) {			// (3).
		return -1;
	}
	data = m_Queue[m_CurPointer];							// (4).
	return m_CurPointer;
}


// Check whether Queue is full.
template <typename T>
bool CircularQueue<T>::IsFull() const
//---------------------------------------------------------------
// (1) ���� Queue�� index�� ù �κа� �� �κ��� ����Ǿ� �ִ�.
//     - �׷��Ƿ�, queue�� �������� �������� rear�� �����ϸ� full.
//---------------------------------------------------------------
{
	return ((m_Rear + 1) % m_Maxsize == m_Front);			// (1).
}


// Check whether Queue is empty.
template <typename T>
bool CircularQueue<T>::IsEmpty() const
//---------------------------------------------------------------
// (1) ���� Queue���� Rear�� �������� �ִٴ� ����, empty�� �ǹ�.
//---------------------------------------------------------------
{
	return (m_Front == m_Rear);								// (1).
}


// Adds new data to the last of the queue.
template <typename T>
int CircularQueue<T>::EnQueue(T data)
//---------------------------------------------------------------
// (1) ���� Queue�� Full�̸�, ����(0)�� return.
// (2) �Է��� �������� �ڸ��� ���� Rear�� ������Ű�� queue�� ����.
// (3) ����(1) return.
//---------------------------------------------------------------
{
	if (IsFull()) { return 0; }								// (1).
	m_Rear = (m_Rear + 1) % m_Maxsize;						// (2).
	m_Queue[m_Rear] = data;
	return 1;												// (3).
}


// delete data from the first of the queue.
template <typename T>
int CircularQueue<T>::DeQueue(T& data)
//---------------------------------------------------------------
// (1) ���� Queue�� Empty�̸�, ����(0)�� return.
// (2) ������ �����͸� �������� ����, Front�� �̵��ؼ� data refer.
// (3) ����(1) return.
//---------------------------------------------------------------
{
	if (IsEmpty()) { return 0; };							// (1).
	m_Front = (m_Front + 1) % m_Maxsize;					// (2).
	data = m_Queue[m_Front];
	return 1;												// (3).
}

#endif _CIRCULAR_QUEUE_H_


