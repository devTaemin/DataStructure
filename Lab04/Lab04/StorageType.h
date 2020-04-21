#pragma once
#include "pch.h"
class StorageType
{
private:
	int m_StorageID;
	string m_Name;
	int numOfContainer;
	int maxOfContainer;
	SinglyLinkedList<ContainerType> m_ContainerList;

public:
	StorageType()
	{
		m_StorageID = -1;
		m_Name = "";
		numOfContainer = 0;
		maxOfContainer = MAXCONTAINER;
	}

	~StorageType(){}


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


	int AddContainer(ContainerType _container);
	int DeleteContainer(ContainerType _container);
	int UpdateContainer(ContainerType _container);
	int GetContainer(ContainerType& _container);

	int DisplayAllContainer();
	int DisplayAllContainer();
};