#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class SimpleItemType
{
private:
	int m_Id;
	string m_Name;

public:
	SimpleItemType();
	~SimpleItemType();

	int GetId() const;
	string GetName() const;

	void SetId(int _id);
	void SetName(string _name);
	void SetRecord(int _id, string _name);

	void SetIdFromKB();
	void SetNameFromKB();
	void SetRecordFromKB();

	int ReadDataFromFile(ifstream& fin);
	int WriteDataToFile(ofstream& fout);

	bool operator==(const SimpleItemType& _item) {
		return (m_Id == _item.GetId());
	}
	bool operator>(const SimpleItemType& _item) {
		return (m_Id > _item.GetId());
	}
	bool operator<(const SimpleItemType& _item) {
		return (m_Id < _item.GetId());
	}
	void operator=(const SimpleItemType& _item) {
		m_Id = _item.GetId();
		m_Name = _item.GetName();
	}
	friend ostream& operator<<(ostream& os, const SimpleItemType& _item) {
		os << "\tID   : " << _item.GetId() << endl;
		os << "\tName   : " << _item.GetName() << endl;
		return os;
	}
};