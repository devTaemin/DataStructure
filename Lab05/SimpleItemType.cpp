#include "SimpleItemType.h"

SimpleItemType::SimpleItemType() : m_Id(-1), m_Name("")
{}

SimpleItemType::~SimpleItemType()
{

}

int SimpleItemType::GetId() const
{
	return m_Id;
}

string SimpleItemType::GetName() const
{
	return m_Name;
}

void SimpleItemType::SetId(int _id)
{
	m_Id = _id;
}

void SimpleItemType::SetName(string _name)
{
	m_Name = _name;
}

void SimpleItemType::SetRecord(int _id, string _name)
{
	SetId(_id);
	SetName(_name);
}

void SimpleItemType::SetIdFromKB()
{
	cout << "\tID : ";
	cin >> m_Id;
}

void SimpleItemType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_Name;
}

void SimpleItemType::SetRecordFromKB()
{
	SetIdFromKB();
	SetNameFromKB();
}

int SimpleItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_Id;
	fin >> m_Name;
	return 1;
}

int SimpleItemType::WriteDataToFile(ofstream& fout)
{
	fout << m_Id << " ";
	fout << m_Name << endl;
	return 1;
}