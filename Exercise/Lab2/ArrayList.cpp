#include "ArrayList.hpp"

ArrayList::ArrayList() 
{
	m_Length = 0;
	m_CurPointer = 0;
}

ArrayList::~ArrayList() {}

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
	if (m_Length < 5) { return false; }
	else { return true; }
}

int ArrayList::Add(ItemType data)
{
	m_Array[m_Length++] = data;
	return 0;
}

void ArrayList::ResetList()
{
	m_CurPointer = 0;
}

int ArrayList::GetNextItem(ItemType& data)
{
	if (m_CurPointer < m_Length) {
		data = m_Array[m_CurPointer++];
		return 1;
	}
	else {
		ResetList();
		return 0;
	}
}