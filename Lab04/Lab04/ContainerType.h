#pragma once
#include "pch.h"
class ContainerType
{
private:
	int m_ContainerID;
	string m_Location;
	UnSortedList<string> m_PhotoList;
	UnSortedList<SimpleItemType> c_ItemList;


public:
	ContainerType()
	{
		m_ContainerID = -1;
		m_Location = "";
	}
	~ContainerType(){}


	int GetContainerID() const
	{
		return m_ContainerID;
	}
	string GetLocation() const
	{
		return m_Location;
	}


	void SetContainerID(int inContainerID)
	{
		m_ContainerID = inContainerID;
	}
	void SetLocation(string inLocation)
	{
		m_Location = inLocation;
	}
	void SetRecord(int inContainerID, string inLocation)
	{
		SetContainerID(inContainerID);
		SetLocation(inLocation);
	}


	void SetContainerIDFromKB()
	{
		cout << "\tContainerID: ";
		cin >> m_ContainerID;
	}
	void SetLocationFromKB()
	{
		cout << "\tLocation   : ";
		cin >> m_Location;
	}
	void SetRecordFromKB()
	{
		SetContainerIDFromKB();
		SetLocationFromKB();
	}


	void DisplayContainerIDOnScreen()
	{
		cout << "\tContainerID: " << m_ContainerID << '\n';
	}
	void DisplayLocationOnScreen()
	{
		cout << "\tLocation   : " << m_Location << '\n';
	}
	void DisplayContainerRecordOnScreen()
	{
		DisplayContainerIDOnScreen();
		DisplayLocationOnScreen();
	}


	bool operator==(const ContainerType& _item) {
		if (m_ContainerID == _item.GetContainerID())
			return true;
		return false;
	}
	bool operator>(const ContainerType& _item) {
		if (m_ContainerID > _item.GetContainerID())
			return true;
		return false;
	}
	bool operator<(const ContainerType& _item) {
		if (m_ContainerID < _item.GetContainerID())
			return true;
		return false;
	}
	void operator=(const ContainerType& _item) {
		m_ContainerID = _item.m_ContainerID;
		m_Location = _item.m_Location;
		m_PhotoList = _item.m_PhotoList;
		c_ItemList = _item.c_ItemList;
	}

	bool IsItemListEmpty()
	{
		return c_ItemList.IsEmpty();
	}
	void ResetItemList()
	{
		c_ItemList.ResetList();
	}
	int GetNextListItem(SimpleItemType& _Item)
	{
		SimpleItemType curItem;
		if (c_ItemList.GetNextItem(curItem)) {
			_Item = curItem;
			return 1;
		}
		return 0;
	}
	int AddItem(ItemType _data)
	{
		if (c_ItemList.Add(_data)) { return 1; }
		return 0;
	}

	int DeleteItem(ItemType _data)
	{
		if (c_ItemList.Delete(_data)) { return 1; }
		return 0;
	}
	int GetItem(ItemType& _data)
	{
		if (c_ItemList.Get(_data)) { return 1; }
		return 0;
	}
	int UpdateItem(ItemType _data)
	{
		if (c_ItemList.Replace(_data)) { return 1; }
		return 0;
	}
	void DisplayAllItem()
	{
		c_ItemList.ResetList();
		SimpleItemType curItem;
		int iPos = c_ItemList.GetNextItem(curItem);
		for (iPos; iPos > 0; iPos = c_ItemList.GetNextItem(curItem)) {
			curItem.DisplayRecordOnScreen();
		}
	}

	int AddPhoto(string _data)
	{
		if (m_PhotoList.Add(_data)) { return 1; }
		return 0;
	}
	int DeletePhoto(string _data)
	{
		if (m_PhotoList.Delete(_data)) { return 1; }
		return 0;
	}
	int GetPhoto(string _data)
	{
		if (m_PhotoList.Get(_data)) { return 1; }
		return 0;
	}
	void DisplayAllPhoto()
	{
		m_PhotoList.ResetList();
		string curPhoto;
		int iPos = m_PhotoList.GetNextItem(curPhoto);
		for (iPos; iPos > 0; iPos = m_PhotoList.GetNextItem(curPhoto)) {
			cout << curPhoto << '\n';
		}
	}
};