#pragma once
#include "pch.h"
class ItemType : public SimpleItemType
{
private:
	int m_StorageID;
	int m_ContainerID;
	int m_Serial;
	string m_Name;
	int m_Num;
	string m_Usage;
	int m_Date;


public:
	ItemType()
	{
		SimpleItemType();
		m_Num = 0;
		m_Usage = "";
		m_Date = -1;
	}
	~ItemType(){}


	int GetNum() const
	{
		return m_Num;
	}
	string GetUsage() const
	{
		return m_Usage;
	}
	int GetDate() const
	{
		return m_Date;
	}


	void SetNum(int inNum)
	{
		m_Num = inNum;
	}
	void SetUsage(string inUsage)
	{
		m_Usage = inUsage;
	}
	void SetDate(int inDate)
	{
		m_Date = inDate;
	}
	void SetRecord(int inStorageID, int inContainerID, int inSerial, string inName, int inNum, string inUsage, int inDate)
	{
		SetStorageID(inStorageID);
		SetContainerID(inContainerID);
		SetSerial(inSerial);
		SetName(inName);
		SetNum(inNum);
		SetUsage(inUsage);
		SetDate(inDate);
	}


	void SetNumFromKB()
	{
		cout << "\tNum        : ";
		cin >> m_Num;
	}
	void SetUsageFromKB()
	{
		cout << "\tUsage      : ";
		cin >> m_Usage;
	}
	void SetDateFromKB()
	{
		cout << "\tDate       : ";
		cin >> m_Date;
	}
	void SetRecordFromKB()
	{
		SetStorageIDFromKB();
		SetContainerIDFromKB();
		SetSerialFromKB();
		SetNameFromKB();
		SetNumFromKB();
		SetUsageFromKB();
		SetDateFromKB();
	}


	void DisplayNumOnScreen()
	{
		cout << "\tNum        : " << m_Num << '\n';
	}
	void DisplayUsageOnScreen()
	{
		cout << "\tUsage      : " << m_Usage << '\n';
	}
	void DisplayDateOnScreen()
	{
		cout << "\tDate       : " << m_Date << '\n';
	}
	void DisplayRecordOnScreen()
	{
		DisplayStorageIDOnScreen();
		DisplayContainerIDOnScreen();
		DisplaySerialOnScreen();
		DisplayNameOnScreen();
		DisplayNumOnScreen();
		DisplayUsageOnScreen();
		DisplayDateOnScreen();
	}


	int ReadDataFromFile(ifstream& fin)
	{
		fin >> m_StorageID;
		fin >> m_ContainerID;
		fin >> m_Serial;
		fin >> m_Name;
		fin >> m_Num;
		fin >> m_Usage;
		fin >> m_Date;

		return 1;
	}
	int WriteDataToFile(ofstream& fout)
	{
		fout << endl;
		fout << m_StorageID << " ";
		fout << m_ContainerID << " ";
		fout << m_Serial << " ";
		fout << m_Name << " ";
		fout << m_Num << " ";
		fout << m_Usage << " ";
		fout << m_Date;

		return 1;
	}


	bool operator==(const ItemType& _item) {
		if (m_Serial == _item.GetSerial())
			return true;
		return false;
	}
	bool operator>(const ItemType& _item) {
		if (m_Serial > _item.GetSerial())
			return true;
		return false;
	}
	bool operator<(const ItemType& _item) {
		if (m_Serial < _item.GetSerial())
			return true;
		return false;
	}
	void operator=(const ItemType& _item) {
		m_StorageID = _item.GetStorageID();
		m_ContainerID = _item.GetContainerID();
		m_Serial = _item.GetSerial();
		m_Name = _item.GetName();
		m_Usage = _item.GetUsage();
		m_Date = _item.GetDate();
		m_Num = _item.GetNum();
	}
};