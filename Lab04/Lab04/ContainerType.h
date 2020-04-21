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


	int AddItem(ItemType _data);
	int DeleteItem(ItemType _data);
	int GetItem(ItemType& _data);
	int UpdateItem(ItemType _data);
	int DisplayAllItem();

	int AddPhoto(string _data);
	int DeletePhoto(string _data);
	int GetPhoto(ItemType _data);
	int DisplayAllPhoto();


};