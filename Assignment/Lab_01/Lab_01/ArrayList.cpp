#include "ArrayList.h"


// Default Constructor
ArrayList::ArrayList()
{
	m_Length = 0;
	ResetList();
}



ArrayList::~ArrayList() {}



void ArrayList::makeEmpty()
{
	m_Length = 0;
	ResetList();
}



int ArrayList::GetLength()
{
	return m_Length;
}



bool ArrayList::IsFull()
{
	if (m_Length == MAXSIZE) {
		return true;
	}
	else { return false; }
}



int ArrayList::Add(ItemType data)
{
	if (!IsFull) {
		m_Array[++m_CurPointer] = data;
		m_Length++;
	}
	else {
		cerr << "Array is Full!" << '\n';
	}
}



void ArrayList::ResetList()
{
	m_CurPointer = -1;
}



int ArrayList::GetNextItem(ItemType& data)
{
	int m_NextPointer = m_CurPointer + 1;
	if (m_NextPointer < m_Length) {
		data = m_Array[++m_CurPointer];
		return 1;
	}
	else { return -1; }
}




bool ArrayList::IsEmpty()
{
	if (m_Length == 0) {
		return true;
	}
	else { return false; }
}



int ArrayList::Get(ItemType& data)
{
	ResetList();
	if (!IsEmpty()) {

	}
	else {
		return -1;
	}

}



int ArrayList::Delete(ItemType data)
{
	ResetList();
	if (!IsEmpty()) {

	}
	else {
		return -1;
	}
}



int ArrayList::Replace(ItemType data)
{
	ResetList();
	if (!IsEmpty()) {

	}
	else {
		return -1;
	}
}