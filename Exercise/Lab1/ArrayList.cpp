#include "ArrayList.hpp"

ArrayList::ArrayList()
{
	MakeEmpty();
	ResetList();
}

ArrayList::~ArrayList(){}

void ArrayList::MakeEmpty() 
{
	m_Length = 0;
}

int ArrayList::GetLength() 
{
	return m_Length;
}

bool ArrayList::IsFull() 
{
	if (m_Length == MAXSIZE) { return true; }
	else { return false; }
}

int ArrayList::Add(ItemType data) 
{
	m_Array[m_Length++] = data;
	return 0;
}

void ArrayList::ResetList() 
{
	m_CurPointer = -1;
}

int ArrayList::GetNextItem(ItemType& data) 
{
	int length = GetLength();
	if (++m_CurPointer < length) {
		data = m_Array[m_CurPointer];
		data.DisplayRecordOnScreen();
	}
	else {
		ResetList();
		return 0;
	}
	return 0;
}