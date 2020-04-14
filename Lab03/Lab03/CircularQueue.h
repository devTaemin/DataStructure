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
#endif _CIRCULAR_QUEUE_H_


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
// (1) 현재 Queue가 empty이면, 실패(0)을 return.
// (2) CircularQueue의 포인터가 다음 포인터를 가리키도록 한다.
//     - 현재 포인터를 1 증가하고, 큐의 길이만큼 모듈러 계산
// (3) 만약 가장 마지막 값을 가진 rear보다 1칸 앞까지 간다면, 초과
//     된 포인터이므로, 실패(-1)을 return.
// (4) data가 현재 포인터가 가리키는 Queue의 item을 지정하도록 하고
//	   현재 포인터의 값을 return.
//---------------------------------------------------------------
{
	if (IsEmpty()) { return 0; }							// (1).
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
// (1) 원형 Queue는 index의 첫 부분과 끝 부분이 연결되어 있다.
//     - 그러므로, queue의 시작지점 이전까지 rear가 도착하면 full.
//---------------------------------------------------------------
{
	return ((m_Rear + 1) % m_Maxsize == m_Front);			// (1).
}


// Check whether Queue is empty.
template <typename T>
bool CircularQueue<T>::IsEmpty() const
//---------------------------------------------------------------
// (1) 원형 Queue에서 Rear가 시작점에 있다는 것은, empty를 의미.
//---------------------------------------------------------------
{
	return (m_Front == m_Rear);								// (1).
}


// Adds new data to the last of the queue.
template <typename T>
int CircularQueue<T>::EnQueue(T data)
//---------------------------------------------------------------
// (1) 현재 Queue가 Full이면, 실패(0)을 return.
// (2) 입력할 데이터의 자리를 위해 Rear을 증가시키고 queue에 삽입.
// (3) 성공(1) return.
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
// (1) 현재 Queue가 Empty이면, 실패(0)을 return.
// (2) 삭제할 데이터를 가져오기 위해, Front를 이동해서 data refer.
// (3) 성공(1) return.
//---------------------------------------------------------------
{
	if (IsEmpty()) { return 0; };							// (1).
	m_Front = (m_Front + 1) % m_Maxsize;					// (2).
	data = m_Queue[m_Front];
	return 1;												// (3).
}
