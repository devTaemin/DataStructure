#pragma once
#include "CircularQueue.h"
#include "ItemType.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class TempType
{
	CircularQueue<ItemType> m_TempList;
	int m_Length;

public:
	TempType();
	~TempType();

	void AddItem(ItemType _item);
	void DequeueFromTempList(ItemType& _item);
	void PrintTempList();
};