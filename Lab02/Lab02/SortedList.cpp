#include "SortedList.h"


// Make list empty.
void SortedList::MakeEmpty()
{
	m_Length = 0;
}


// Get a number of records in current list.
int SortedList::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
bool SortedList::IsFull()
{
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


// Add a new data into list.
int SortedList::Add(ItemType inData)
{
	//---------------------------------------------------------------
	// (1) 현재 list의 용량을 확인한다.
	//	   - 다 채워져있을 경우, 실패(0)을 return.
	//	   - 빈 경우, 첫 자리 삽입, 길이 증가, 성공(1) return.
	// (2) 삽입 위치를 찾기 위해, GetNextItem을 사용한다
	//	   - Position을 저장할 변수, 검색 확인하는 변수 found 선언.
	//	   - List에서 받아온 item을 저장할 변수 temp 선언.
	//	   - ResetList(), 포인터 초기화
	//	   - Position에 시작지점 저장, 끝에 도달하면 -1.
	// (3) 정렬리스트, 삽입을 위한 위치 파악하기.
	//	   - case EQUAL, 중복된 item이 존재하므로 실패(0) return.
	//	   - case GREATER, 리스트에 담긴 item이 더 크므로 존재x, 실패(0)
	//	   - case LESS, 다음 item을 받아온다.
	// (4) 삽입
	//	   - 검색이 되지 않은 경우, 맨 끝에다 삽입한다. 성공(1).
	//	   - 중간에 삽입된 경우, 후방 데이터를 이동하고 삽입. 성공(1).
	// ---------------------------------------------------------------

	if (IsFull()) return 0;									// (1).
	if (m_Length == 0) {    	
		m_Array[m_Length++] = inData;
		return 1;
	}
	
	int iPos = 0;											// (2).
	bool found = false;
	ItemType curItem;
	ResetList();
	iPos = GetNextItem(curItem);							// (3).
	while (iPos > -1 && !found)								
	{
		switch (curItem.Compare(inData))
		{
		case EQUAL:
			cout << " %%% same item exist in the list %%%\n";
			return 0;
		case GREATER:
			found = true;
			break;
		case LESS:
			iPos = GetNextItem(curItem);
			break;
		}
	}

	
	if (iPos == -1) {										// (4).
		m_Array[m_Length++] = inData;
		return 1;
	}

	for (int i = m_Length; i > iPos; i--) {
		m_Array[i] = m_Array[i - 1];
	}
	m_Array[iPos] = inData;
	m_Length++;

	return 1;
}


// Initialize list iterator.
void SortedList::ResetList()
{
	m_CurPointer = -1;
}


// Update pointer to point to next record, and get that new record.
int SortedList::GetNextItem(ItemType& data)
{
	//---------------------------------------------------------------
	// (1) 현재 Pointer를 increment하여 다음 item의 index를 가리킨다.
	// (2) Pointer가 capacity를 넘어서면, 실패(-1)를 return.
	// (3) List에서 해당 index의 data를 가져온다.
	// (4) 현재 위치를 출력한다.
	//---------------------------------------------------------------
	m_CurPointer++;												// (1).
	if (m_CurPointer == m_Length)								// (2).
		return -1;
	data = m_Array[m_CurPointer];								// (3).
	return m_CurPointer;										// (4).
}




// Find the item whose primary key matches with the primary 
int SortedList::Retrieve_SeqS(ItemType& data)
{
	//---------------------------------------------------------------
	// (1) List의 element를 받아올 ItemType CurItem 생성.
	// (2) List의 Current Pointer 초기화.
	// (3) List의 첫번째 item을 받아옴.
	// (4) 정렬 리스트, 검색 시작
	//	   - case LESS  의 경우, 다음 item을 받아온다.
	//	   - case EQUAL 의 경우, item을 반환하고, 1을 return한다.
	//	   - case GRETER의 경우, item이 없으므로, 0을 return한다.
	// (5) 함수가 실패하면, 0을 return한다.
	// ---------------------------------------------------------------
	ItemType CurItem;											// (1).
	ResetList();												// (2).
	GetNextItem(CurItem);										// (3).

	while (m_CurPointer < m_Length)								// (4).
	{
		switch (CurItem.Compare(data))	
		{
		case EQUAL:	
			data = CurItem;	
			return 1;	
			break;
		case GREATER:	
			return 0;	
			break;
		default:	
			GetNextItem(CurItem);	
			break;
		}
	}
	return 0;													// (5).
}



// Delete item in accordance with data's primary key.
int SortedList::Delete(ItemType data)
{
	//---------------------------------------------------------------
	// (1) List가 비어있는지 확인. 비어있을시 삭제 실패(0)을 return.
	// (2) List가 비어있지 않는 경우,
	//	   - List에서 data를 검색한다. 
	//	   [1] 성공(1) return시, 상위 data를 이동하고 길이를 줄인다.
	//	   [2] 실패(0) return.
	// ---------------------------------------------------------------
	if (Retrieve_SeqS(data))									// (1).
	{
		for (int i = m_CurPointer; i < m_Length; i++)			// (2).
			m_Array[i] = m_Array[i + 1];	
		m_Length--;	
		return 1;	
	}
	return 0;
}

// Find same record using primary key and replace it.
int SortedList::Replace(ItemType data)
{
	//---------------------------------------------------------------
	// (1) 입력받은 item 백업.
	// (2) 검색, 교체
	//	   - List에서 data를 검색한다. 
	//	   [1] 찾게 되면, 성공(1) return.
	//	   [2] 실패(0) return.
	// ---------------------------------------------------------------
	ItemType tmp(data);											// (1)

	if (Retrieve_SeqS(data))									// (2)
	{
		m_Array[m_CurPointer] = tmp;	
		return 1;	
	}
	return 0;	
}

// Retrieve by using binary search.
int SortedList::RetrieveByBS(ItemType& data)
{
	//---------------------------------------------------------------
	// (1) List가 비어있으면, 실패(0)을 return한다.
	// (2) 시작점을 배열의 중간 지점으로 설정.
	// (3) 정렬 리스트, 2진 검색 시작.
	//	   - case LESS 의 경우
	//		 [1] 비교한 데이터가 리스트의 마지막이면, 실패(0)을 return.
	//		 [2] 아닌 경우, 해당 지점과 끝 지점의 사이로 Position 이동.
	//	   - case EQUAL 의 경우
	//		 [1] 해당 지점의 item을 반환하고, 성공(1)을 return.
	//	   - case GREATER 의 경우
	//		 [1] 비교한 데이터가 리스트의 첫 지점이면, 실패(0)을 return.
	//		 [2] 아닌 경우, 해당 지점과 첫 지점의 사이로 Position 이동.
	// (4) 함수가 실패하면, 실패(0)을 return.
	// ---------------------------------------------------------------
	if (m_Length == 0)											// (1).
		return 0;												// (2).
	int currentPos = m_Length / 2;								// (3).
	while (1)
	{
		switch (m_Array[currentPos].Compare(data))
		{
		case EQUAL:	
			data = m_Array[currentPos];	
			return 1;	
			break;
		case GREATER:	
			if (currentPos == 0)
				return 0;	
			currentPos /= 2;	
			break;
		case LESS:	 
			if (currentPos == m_Length - 1)
				return 0;	
			currentPos = (currentPos + m_Length) / 2;	
			break;
		}
	}
	return 0;													// (4).
}
