#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class ItemType
{
private:
	int m_StorageID;
	int m_ContainerID;
	int m_Id;
	string m_Name;
	int m_Num;
	string m_Usage;
	int m_Date;

public:
	ItemType();
	~ItemType();

	int GetStorageID() const;
	int GetContainerID() const;
	int GetID() const;
	string GetName() const;
	int GetNum() const;
	string GetUsage() const;
	int GetDate() const;

	void SetStorageID(int _sid);
	void SetContainerID(int _cid);
	void SetID(int _id);
	void SetName(string _name);
	void SetNum(int _num);
	void SetUsage(string _usage);
	void SetDate(int _date);
	void SetRecord(int _sid, int _cid, int _id, string _name, int _num, string _usage, int _date);

	void SetStorageIDFromKB();
	void SetContainerIDFromKB();
	void SetIDFromKB();
	void SetNameFromKB();
	void SetNumFromKB();
	void SetUsageFromKB();
	void SetDateFromKB();
	void SetRecordFromKB();

	int ReadDataFromFile(ifstream& fin);
	int WriteDataToFile(ofstream& fout);

	bool operator==(const ItemType& _item) {
		return (m_Id == _item.GetID());
	}
	bool operator>(const ItemType& _item) {
		return (m_Id > _item.GetID());
	}
	bool operator<(const ItemType& _item) {
		return (m_Id < _item.GetID());
	}
	void operator=(const ItemType& _item) {
		m_StorageID = _item.GetStorageID();
		m_ContainerID = _item.GetContainerID();
		m_Id = _item.GetID();
		m_Name = _item.GetName();
		m_Num = _item.GetNum();
		m_Usage = _item.GetUsage();
		m_Date = _item.GetDate();
	}
	friend ostream& operator<<(ostream& os, const ItemType& _item) {
		os << "\tStorageID	: " << _item.GetStorageID() << endl;
		os << "\tContainerID  : " << _item.GetContainerID() << endl;
		os << "\tID  : " << _item.GetID() << endl;
		os << "\tName  : " << _item.GetName() << endl;
		os << "\tNum  : " << _item.GetNum() << endl;
		os << "\tUsage  : " << _item.GetUsage() << endl;
		os << "\tDate  : " << _item.GetDate() << endl;
		return os;
	}
};