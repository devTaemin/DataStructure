#pragma once
#include "pch.h"
class StorageType
{
private:
	int m_StorageID;
	string m_Name;
	int numOfContainer;
	int maxOfContainer;
	SingleLinkedList<ContainerType> m_ContainerList;

public:
	StorageType()
	{
		m_StorageID = -1;
		m_Name = "";
		numOfContainer = 0;
		maxOfContainer = MAXCONTAINER;
	}

	~StorageType() {}


	int GetStorageID() const
	{
		return m_StorageID;
	}
	string GetName() const
	{
		return m_Name;
	}
	int GetNumOfContainer() const
	{
		return numOfContainer;
	}
	int GetMaxOfContainer() const
	{
		return maxOfContainer;
	}


	void SetStorageID(int inStorageID)
	{
		m_StorageID = inStorageID;
	}
	void SetName(string inName)
	{
		m_Name = inName;
	}
	void SetMaxOfContainer(int inMax)
	{
		maxOfContainer = inMax;
	}
	void SetRecord(int inStorageID, string inName, int inMax)
	{
		SetStorageID(inStorageID);
		SetName(inName);
		SetMaxOfContainer(inMax);
	}


	void SetStorageIDFromKB()
	{
		cout << "\tStorageID  : ";
		cin >> m_StorageID;
	}
	void SetNameFromKB()
	{
		cout << "\tStorageName: ";
		cin >> m_Name;
	}
	void SetMaxOfContainerFromKB()
	{
		cout << "\tContainer-max: ";
		cin >> maxOfContainer;
	}
	void SetRecordFromKB()
	{
		SetStorageIDFromKB();
		SetNameFromKB();
		SetMaxOfContainerFromKB();
	}

	void DisplayStorageIDOnScreen()
	{
		cout << "\tStorageID  : " << m_StorageID << '\n';
	}
	void DisplayNameOnScreen()
	{
		cout << "\tStorageName: " << m_Name << '\n';
	}
	void DisplayNumOfContainerOnScreen()
	{
		cout << "\tContainer-num: " << numOfContainer << " / " << maxOfContainer << '\n';
	}
	void DisplayStorageRecordOnScreen()
	{
		DisplayStorageIDOnScreen();
		DisplayNameOnScreen();
		DisplayNumOfContainerOnScreen();
	}

	bool operator==(const StorageType& _item) {
		if (m_StorageID == _item.GetStorageID())
			return true;
		return false;
	}
	bool operator>(const StorageType& _item) {
		if (m_StorageID > _item.GetStorageID())
			return true;
		return false;
	}
	bool operator<(const StorageType& _item) {
		if (m_StorageID < _item.GetStorageID())
			return true;
		return false;
	}
	void operator=(const StorageType& _item) {
		m_StorageID = _item.m_StorageID;
		m_Name = _item.m_Name;
		numOfContainer = _item.numOfContainer;
		maxOfContainer = _item.maxOfContainer;
		m_ContainerList.Equal(_item.m_ContainerList);
	}

	int AddContainer(ContainerType _container) {
		if (m_ContainerList.Add(_container)) { 
			numOfContainer++;
			return 1; 
		}
		return 0;
	}
	int DeleteContainer(ContainerType _container) {
		if (m_ContainerList.Delete(_container)) { 
			numOfContainer--;
			return 1; 
		}
		return 0;
	}
	int UpdateContainer(ContainerType _container) {
		if (m_ContainerList.Replace(_container)) { return 1; }
		return 0;
	}
	int GetContainer(ContainerType& _container) {
		if (m_ContainerList.Get(_container)) { return 1; }
		return 0;
	}

	void DisplayAllContainer() {
		ContainerType curContainer;
		m_ContainerList.ResetList();
		int iPos = m_ContainerList.GetNextItem(curContainer);
		for (iPos; iPos >= 0; iPos = m_ContainerList.GetNextItem(curContainer)) {
			curContainer.DisplayContainerRecordOnScreen();
			curContainer.DisplayAllPhoto();
			curContainer.DisplayAllItem();
		}
	}
};