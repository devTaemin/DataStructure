#include "UnSortedList.h"


void UnSortedList::MakeEmpty()
{
	m_Length = 0;
}


int UnSortedList::GetLength() const
{
	return m_Length;
}


bool UnSortedList::IsFull()
{
	if (m_Length == MAXSIZE)
		return true;
	return false;
}


bool UnSortedList::IsEmpty()
{
	if (m_Length == 0)
		return true;
	return false;
}


int UnSortedList::Add(ItemType inData)
{
	if (!IsFull()) {
		m_Array[m_Length++] = inData;
		return 1;
	}
	return 0;
}


void UnSortedList::ResetList()
{
	m_CurPointer = -1;
}


// ������ ���� -> ������ �Ѿ�� return 0, �ȳѾ�� data reference, return 1
int UnSortedList::GetNextItem(ItemType& inData)
{
	m_CurPointer++;
	if (m_CurPointer > m_Length - 1) {
		return 0;
	}
	inData = m_Array[m_CurPointer];
	return 1;
}