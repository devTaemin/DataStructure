#include "ItemType.h"


ItemType::ItemType()
{
	m_StorageID = -1;
	m_ContainerID = -1;
	m_Id = -1;
	m_Name = "";
	m_Num = 0;
	m_Usage = "";
	m_Date = 0;
}


ItemType::~ItemType()
{

}

int ItemType::GetStorageID() const
{
	return m_StorageID;
}

int ItemType::GetContainerID() const
{
	return m_ContainerID;
}

int ItemType::GetID() const
{
	return m_Id;
}

string ItemType::GetName() const
{
	return m_Name;
}

int ItemType::GetNum() const
{
	return m_Num;
}

string ItemType::GetUsage() const
{
	return m_Usage;
}

int ItemType::GetDate() const
{
	return m_Date;
}

void ItemType::SetStorageID(int _sid)
{
	m_StorageID = _sid;
}

void ItemType::SetContainerID(int _cid)
{
	m_ContainerID = _cid;
}

void ItemType::SetID(int _id)
{
	m_Id = _id;
}

void ItemType::SetName(string _name)
{
	m_Name = _name;
}

void ItemType::SetNum(int _num)
{
	m_Num = _num;
}

void ItemType::SetUsage(string _usage)
{
	m_Usage = _usage;
}

void ItemType::SetDate(int _date)
{
	m_Date = _date;
}

void ItemType::SetRecord(int _sid, int _cid, int _id, string _name, int _num, string _usage, int _date)
{
	SetStorageID(_sid);
	SetContainerID(_cid);
	SetID(_id);
	SetName(_name);
	SetNum(_num);
	SetUsage(_usage);
	SetDate(_date);
}

void ItemType::SetStorageIDFromKB()
{
	cout << "\tStorageID : ";
	cin >> m_StorageID;
}

void ItemType::SetContainerIDFromKB()
{
	cout << "\tContainerID : ";
	cin >> m_ContainerID;
}

void ItemType::SetIDFromKB()
{
	cout << "\tID : ";
	cin >> m_Id;
}

void ItemType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_Name;
}

void ItemType::SetNumFromKB()
{
	cout << "\tNum : ";
	cin >> m_Num;
}

void ItemType::SetUsageFromKB()
{
	cout << "\tUsage : ";
	cin >> m_Usage;
}

void ItemType::SetDateFromKB()
{
	cout << "\Date : ";
	cin >> m_Date;
}

void ItemType::SetRecordFromKB()
{
	SetStorageIDFromKB();
	SetContainerIDFromKB();
	SetIDFromKB();
	SetNameFromKB();
	SetNumFromKB();
	SetUsageFromKB();
	SetDateFromKB();
}

int ItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_StorageID;
	fin >> m_ContainerID;
	fin >> m_Id;
	fin >> m_Name;
	fin >> m_Num;
	fin >> m_Usage;
	fin >> m_Date;
	return 1;
}

int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << m_StorageID << " ";
	fout << m_ContainerID << " ";
	fout << m_Id << " ";
	fout << m_Name << " ";
	fout << m_Num << " ";
	fout << m_Usage << " ";
	fout << m_Date << endl;
	return 1;
}