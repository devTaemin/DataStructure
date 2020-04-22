#pragma once
#include "pch.h"
//--------------------------------------------------------------------
//		Array based on 'Circular Queue'.
//--------------------------------------------------------------------
template <typename T>
class CircularQueue
{
private:
	int q_Maxsize;				///< maximum size of queue.
	int q_Front;				///< index of one infront of element from queue.
	int q_Rear;					///< index of the last element.
	int q_CurPointer;			///< iterator pointer.
	T* q_Queue;					///< queue.
	int q_Length;				///< number of items in queue.


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


	void MakeEmpty();
	//--------------------------------------------------------------------
	//	Brief:	Make Queue empty. 
	//	Pre:	none.
	//	Post:	clear Queue.	
	//--------------------------------------------------------------------


	void ResetList();
	//--------------------------------------------------------------------
	//	Brief:	Make Queue iterator reset. 
	//	Pre:	none.
	//	Post:	iterator is reset.
	//--------------------------------------------------------------------


	int GetLength() const;
	//--------------------------------------------------------------------
	//	Brief:	Return the number of records in the list.
	//	Pre:	none.
	//	Post:	none.
	//	Return:	number of records in current list.
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


	int Get(T& _data);
	int Delete(T _data);
	int Replace(T _data);
};

// Default Constructor.
template <typename T>
CircularQueue<T>::CircularQueue()
{
	q_Maxsize = MAXQUEUE;
	q_Front = q_Maxsize - 1;
	q_Rear = q_Maxsize - 1;
	q_CurPointer = q_Front;
	q_Queue = new T[q_Maxsize];
	q_Length = 0;
}


// Constructor.
template <typename T>
CircularQueue<T>::CircularQueue(int max)
{
	q_Maxsize = max + 1;
	q_Front = q_Maxsize - 1;
	q_Rear = q_Maxsize - 1;
	q_CurPointer = q_Front;
	q_Queue = new T[q_Maxsize];
	q_Length = 0;
}


// Destructor.
template <typename T>
CircularQueue<T>::~CircularQueue()
{
	//delete[] q_Queue;
}


// Check whether Queue is full.
template <typename T>
bool CircularQueue<T>::IsFull() const
//---------------------------------------------------------------
// (1) 원형 Queue는 index의 첫 부분과 끝 부분이 연결되어 있다.
//     - 그러므로, queue의 시작지점 이전까지 rear가 도착하면 full.
//---------------------------------------------------------------
{
	return ((q_Rear + 1) % q_Maxsize == q_Front);			// (1).
}


// Check whether Queue is empty.
template <typename T>
bool CircularQueue<T>::IsEmpty() const
//---------------------------------------------------------------
// (1) 원형 Queue에서 Rear가 시작점에 있다는 것은, empty를 의미.
//---------------------------------------------------------------
{
	return (q_Front == q_Rear);								// (1).
}


// Make Queue empty. 
template <typename T>
void CircularQueue<T>::MakeEmpty()
{
	q_Front = q_Maxsize - 1;
	q_Rear = q_Maxsize - 1;
	delete[] q_Queue;
	q_Queue = new T[q_Maxsize];
	q_Length = 0;
}


// Make Queue iterator reset. 
template <typename T>
void CircularQueue<T>::ResetList()
{
	q_CurPointer = q_Front;
}


// Return the number of records in the list.
template <typename T>
int CircularQueue<T>::GetLength() const
{
	return q_Length;
}


// Update pointer to point to next record, and get that new record.
template <typename T>
int CircularQueue<T>::GetNextItem(T& data)
//---------------------------------------------------------------
// (1) 현재 Queue가 empty이면, 실패(-1)을 return.
// (2) CircularQueue의 포인터가 다음 포인터를 가리키도록 한다.
//     - 현재 포인터를 1 증가하고, 큐의 길이만큼 모듈러 계산
// (3) 만약 가장 마지막 값을 가진 rear보다 1칸 앞까지 간다면, 초과
//     된 포인터이므로, 실패(-1)을 return.
// (4) data가 현재 포인터가 가리키는 Queue의 item을 지정하도록 하고
//	   현재 포인터의 값을 return.
//---------------------------------------------------------------
{
	if (IsEmpty()) { return -1; }							// (1).
	q_CurPointer = (q_CurPointer + 1) % q_Maxsize;			// (2).
	if (q_CurPointer == (q_Rear + 1) % q_Maxsize) {			// (3).
		return -1;
	}
	data = q_Queue[q_CurPointer];							// (4).
	return q_CurPointer;
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
	q_Rear = (q_Rear + 1) % q_Maxsize;						// (2).
	q_Queue[q_Rear] = data;
	q_Length++;
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
	q_Front = (q_Front + 1) % q_Maxsize;					// (2).
	data = q_Queue[q_Front];
	q_Length--;
	return 1;												// (3).
}


template <typename T>
int CircularQueue<T>::Get(T& _data)
{
	if (IsEmpty()) { return 0; }
	T curData;
	ResetList();
	int iPos = GetNextItem(curData);
	for (iPos; iPos > 0; iPos = GetNextItem(curData)) {
		if (curData == _data) {
			_data = curData;
			return 1;
		}
	}
	return 0;
}

template <typename T>
int CircularQueue<T>::Delete(T _data)     // 큐와 리스트를 결합
{
	if (IsEmpty()) { return 0; }
	T curData;
	ResetList();
	bool found = false;
	int iPos = GetNextItem(curData);
	for (iPos; iPos > 0; iPos = GetNextItem(curData)) {
		if (curData == _data) {
			T temp = q_Queue[q_Front];
			q_Queue[q_Front] = curData;
			q_Queue[iPos] = temp;
			found = true;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
		}
	}
	if (!found) { return 0; }
	if (DeQueue(_data)) { return 1; }
	return 0;
}

template <typename T>
int CircularQueue<T>::Replace(T _data)
{
	if (IsEmpty()) { return 0; }
	T curData;
	ResetList();
	int iPos = GetNextItem(curData);
	for (iPos; iPos > 0; iPos = GetNextItem(curData)) {
		if (curData == _data) {
			curData = _data;
			return 1;
		}
	}
	return 0;
}
