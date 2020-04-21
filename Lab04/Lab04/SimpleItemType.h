#pragma once
#include "pch.h"
class SimpleItemType
{
protected:
	int m_StorageID;
	int m_ContainerID;
	int m_Serial;
	string m_Name;


public:
	SimpleItemType()
	{
		m_StorageID = -1;
		m_ContainerID = -1;
		m_Serial = -1;
		m_Name = "";
	}


	~SimpleItemType() {}


	int GetStorageID() const
	{
		return m_StorageID;
	}
	int GetContainerID() const
	{
		return m_ContainerID;
	}
	int GetSerial() const
	{
		return m_Serial;
	}
	string GetName() const
	{
		return m_Name;
	}


	void SetStorageID(int inStorageID)
	{
		m_StorageID = inStorageID;
	}
	void SetContainerID(int inContainerID)
	{
		m_ContainerID = inContainerID;
	}
	void SetSerial(int inSerial)
	{
		m_Serial = inSerial;
	}
	void SetName(string inName)
	{
		m_Name = inName;
	}
	void SetRecord(int inStorageID, int inContainerID, int inSerial, string inName)
	{
		SetStorageID(inStorageID);
		SetContainerID(inContainerID);
		SetSerial(inSerial);
		SetName(inName);
	}


	void SetStorageIDFromKB()
	{
		cout << "\tStorageID  : ";
		cin >> m_StorageID;
	}
	void SetContainerIDFromKB()
	{
		cout << "\tContainerID: ";
		cin >> m_StorageID;
	}
	void SetSerialFromKB()
	{
		cout << "\tSerial     : ";
		cin >> m_StorageID;
	}
	void SetNameFromKB()
	{
		cout << "\tName       : ";
		cin >> m_StorageID;
	}
	void SetRecordFromKB()
	{
		SetStorageIDFromKB();
		SetContainerIDFromKB();
		SetSerialFromKB();
		SetNameFromKB();
	}


	void DisplayStorageIDOnScreen()
	{
		cout << "\tStorageID  : " << m_StorageID << '\n';
	}
	void DisplayContainerIDOnScreen()
	{
		cout << "\tContainerID : " << m_ContainerID << '\n';
	}
	void DisplaySerialOnScreen()
	{
		cout << "\tSerial     : " << m_Serial << '\n';
	}
	void DisplayNameOnScreen()
	{
		cout << "\tName       : " << m_Name << '\n';
	}
	void DisplayRecordOnScreen()
	{
		DisplayStorageIDOnScreen();
		DisplayContainerIDOnScreen();
		DisplaySerialOnScreen();
		DisplayNameOnScreen();
	}


	bool operator==(const SimpleItemType& _item) {
		if (m_Serial == _item.GetSerial())
			return true;
		return false;
	}
	bool operator>(const SimpleItemType& _item) {
		if (m_Serial > _item.GetSerial())
			return true;
		return false;
	}
	bool operator<(const SimpleItemType& _item) {
		if (m_Serial < _item.GetSerial())
			return true;
		return false;
	}
	void operator=(const SimpleItemType& _item) {
		m_StorageID = _item.GetStorageID();
		m_ContainerID = _item.GetContainerID();
		m_Serial = _item.GetSerial();
		m_Name = _item.GetName();
	}
};