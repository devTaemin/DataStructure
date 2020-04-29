#pragma once
#include "DoubleLinkedList.h"
#include "UnSortedLIst.h"
#include "SortedList.h"
#include "SimpleItemType.h"
#include "ItemType.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class ContainerType
{
private:
	int	m_ContainerID;
	string m_Location;
	UnSortedList<SimpleItemType> m_SimpleItemList;
	UnSortedList<string> m_PhotoList;

public:
	ContainerType();
	~ContainerType();

	int GetId() const;
	string GetLocation() const;

	void SetId(int _id);
	void SetLocation(string _location);

	void SetIdFromKB();
	void SetLocationFromKB();
	void SetRecordFromKB();

	int AddsItem(SimpleItemType& _item);
	int DeletesItem(SimpleItemType& _item);
	int UpdatesItem(SimpleItemType& _item);

	int AddPhoto(string photo);
	int DeletePhoto(string photo);

	void DisplayAllPhoto();
	void DisplayAllsItem();
	void DisplayAllDetailsItem(DoubleLinkedList<ItemType>& ref);

	bool operator==(const ContainerType& _container) {
		return (m_ContainerID == _container.GetId());
	}
	bool operator>(const ContainerType& _container) {
		return (m_ContainerID > _container.GetId());
	}
	bool operator<(const ContainerType& _container) {
		return (m_ContainerID < _container.GetId());
	}
	void operator=(const ContainerType& _container) {
		m_ContainerID = _container.GetId();
		m_Location = _container.GetLocation();
		m_SimpleItemList = _container.m_SimpleItemList;
		m_PhotoList = _container.m_PhotoList;
	}
	friend ostream& operator<<(ostream& os, const ContainerType& _container) {
		os << "+-----------------------------------+" << endl;
		os << "\tContainer ID : " << _container.GetId() << endl;
		os << "\tPosition     : " << _container.GetLocation() << endl;
		os << "\t[ItemList] " << endl;
		os << _container.m_SimpleItemList << endl;
		os << "+-----------------------------------+" << endl;
		return os;
	}
};

