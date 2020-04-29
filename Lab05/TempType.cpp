#include "TempType.h"

TempType::TempType()
{
	m_Length = 0;
}

TempType::~TempType() {}


void TempType::AddItem(ItemType _item)
{
	m_TempList.Add(_item);
	m_Length++;
}

void TempType::DequeueFromTempList(ItemType& _item)
{
	m_TempList.Delete(_item);
	m_Length--;
}

void TempType::PrintTempList()
{
	m_TempList.DisplayAll();
}