#include "SortedList.hpp"

SortedList::SortedList()
{
	m_Length = 0;
	m_CurPointer = -1;
}

SortedList::~SortedList(){}

void SortedList::makeEmpty()
{
	m_Length = -1;
}

int SortedList::GetLength()
{
	return m_Length;
}

bool SortedList::IsFull()
{
	if (GetLength() < 5) { return false; }
	else { return true; }
}

bool SortedList::IsEmpty()
{
	if (GetLength() == 0) { return true; }
	else { return false; }
}

void SortedList::ResetList()
{
	m_CurPointer = -1;
}

int SortedList::GetNextItem(ItemType& data)
{
	if (m_CurPointer < MAXSIZE - 1) {
		if (m_CurPointer < m_Length - 1) {
			data = m_Array[++m_CurPointer];
			return 1;
		}
		else {
			ResetList();
			return 0;
		}
	}
	else {
		return 0;
	}

}

int SortedList::Add(ItemType data)
{
	ItemType temp;

	if (IsEmpty()) {
		m_Array[m_Length++] = data;
		return 1;
	}
	else {
		if (!IsFull()) {
			ResetList();
			while (true) {
				if (GetNextItem(temp) == 1) {
					if (temp.CompareByID(data) == GREATER) {
						for (int i = m_Length; i > m_CurPointer; i--) {
							m_Array[i] = m_Array[i - 1];
						}
						m_Array[m_CurPointer] = data;
						m_Length++;
						return 1;
					}
				}
				else {
					m_Array[m_Length++] = data;
					return 1;
				}
			}
		}
		else {
			return 0;
		}
	}
	
	/*
	if (IsEmpty()) {
		m_Array[m_Length++] = data;
		return 1;
	}
	else {
		if (!IsFull()) {
			while (true) {
				ResetList();
				if (GetNextItem(temp) == 1) {
					if (temp.CompareByID(data) == GREATER) {
						for (int i = m_Length; i > m_CurPointer; i--) {
							m_Array[i] = m_Array[i - 1];
						}
						m_Array[m_CurPointer] = data;
						m_Length++;
						return 1;
					}
				}
				else {
					m_Array[m_Length++] = data;
					return 1;
				}
			}
		}
		else {
			cerr << "Error: Array is full!" << endl;
			return 0;
		}
	}
	
	/*
	if (!IsFull()) {
		while (GetNextItem(temp) == 1) {
			if (temp.CompareByID(data) == GREATER) {
				for (int i = m_Length; i > m_CurPointer; i--) {
					m_Array[i] = m_Array[i - 1];
				}
				m_Array[m_CurPointer] = data;
				m_Length++;
				return 1;
			}
		}
		m_Array[m_Length++] = data;
		return 1;
	}
	else {
		cerr << "Error: Array is full!" << endl;
		return 0;
	}
	*/
}

int SortedList::Delete(ItemType data)
{
	ItemType temp;
	if (!IsEmpty()) {
		while (GetNextItem(temp) == 1) {
			if (temp.CompareByID(data) == EQUAL) {
				if (m_CurPointer != m_Length - 1) {
					for (int i = m_CurPointer; i < m_Length; i++) {
						m_Array[i] = m_Array[i + 1];
					}
				}
				m_Length--;
				return 1;
			}
		}
		cerr << "Error: Fail to find data!" << endl;
		return 0;
	}
	else {
		cerr << "Error: Array is Empty!" << endl;
		return 0;
	}
}

int SortedList::Replace(ItemType data)
{
	ItemType temp;
	if (!IsEmpty()) {
		while (GetNextItem(temp) == 1) {
			if (temp.CompareByID(data) == EQUAL) {
				m_Array[m_CurPointer] = data;
				return 1;
			}
		}
		cerr << "Error: Fail to find data!" << endl;
		return 0;
	}
	else {
		cerr << "Error: Array is Empty!" << endl;
		return 0;
	}
}

int SortedList::Get(ItemType& target)
{
	ItemType temp;

	if (!IsEmpty()) {
		while (GetNextItem(temp) == 1) {
			if (temp.CompareByID(target) == EQUAL) {
				target = m_Array[m_CurPointer];
				return 1;
			}
		}
		return 0;
	}
	else {
		return 0;
	}
}

int SortedList::GetByBinarySearch(ItemType& data)
{
	int front = 0;
	int end = m_Length - 1;
	
	if (!IsEmpty()) {
		while (front <= end) {
			int index = (front + end) / 2;
			if (m_Array[index].CompareByID(data) == GREATER) {
				end = end - 1;
			}
			else if (m_Array[index].CompareByID(data) == LESS) {
				front = front + 1;
			}
			else {
				data = m_Array[index];
				return 1;
			}
		}
		return 0;
	}
	else {
		return 0;
	}
}