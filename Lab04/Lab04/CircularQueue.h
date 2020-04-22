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
// (1) ���� Queue�� index�� ù �κа� �� �κ��� ����Ǿ� �ִ�.
//     - �׷��Ƿ�, queue�� �������� �������� rear�� �����ϸ� full.
//---------------------------------------------------------------
{
	return ((q_Rear + 1) % q_Maxsize == q_Front);			// (1).
}


// Check whether Queue is empty.
template <typename T>
bool CircularQueue<T>::IsEmpty() const
//---------------------------------------------------------------
// (1) ���� Queue���� Rear�� �������� �ִٴ� ����, empty�� �ǹ�.
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
// (1) ���� Queue�� Full�̸�, ����(0)�� return.
// (2) �Է��� �������� �ڸ��� ���� Rear�� ������Ű�� queue�� ����.
// (3) ����(1) return.
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
// (1) ���� Queue�� Empty�̸�, ����(0)�� return.
// (2) ������ �����͸� �������� ����, Front�� �̵��ؼ� data refer.
// (3) ����(1) return.
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
int CircularQueue<T>::Delete(T _data)     // ť�� ����Ʈ�� ����
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
