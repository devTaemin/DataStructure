#include "ItemType.h"

// Default constructor
ItemType::ItemType()
{
	m_Id = -1;
	m_sName = "";
	m_sAddress = "";
}


// Destructor
ItemType::~ItemType(){}


// Return Id from ItemType
int ItemType::GetId()
{
	return m_Id;
}


// Return Name from ItemType
string ItemType::GetName()
{
	return m_sName;
}


// Set Id in ItemType
void ItemType::SetId(int inId)
{
	m_Id = inId;
}


// Set Name in ItemType
void ItemType::SetName(string inName)
{
	m_sName = inName;
}


// Set Address in ItemType
void ItemType::SetAddress(string inAddress)
{
	m_sAddress = inAddress;
}


// Set Record in ItemType
void ItemType::SetRecord(int inId, string inName, string inAddress)
{
	SetId(inId);
	SetName(inName);
	SetAddress(inAddress);
}


// Display Id from ItemType
void ItemType::DisplayIdOnScreen()
{
	cout << m_Id << '\n';
}


// Display Name from ItemType
void ItemType::DisplayNameOnScreen()
{
	cout << m_sName << '\n';
}


// DIsplay Address from ItemType
void ItemType::DisplayAddressOnScreen()
{
	cout << m_sAddress << '\n';
}


// Display Record from ItemType
void ItemType::DisplayRecordOnScreen()
{
	DisplayIdOnScreen();
	DisplayNameOnScreen();
	DisplayAddressOnScreen();
}


// Set Id in ItemType by KB input
void ItemType::SetIdFromKB()
{
	cout << "Set Id: ";
	cin >> m_Id;
}


// Set Name in ItemType by KB input
void ItemType::SetNameFromKB()
{
	cout << "Set Name: ";
	cin >> m_sName;
}


// Set Address in ItemType by KB input
void ItemType::SetAddressFromKB()
{
	cout << "Set Address: ";
	cin >> m_sAddress;
}


// Set Record in ItemType by KB input
void ItemType::SetRecordFromKB()
{
	SetIdFromKB();
	SetNameFromKB();
	SetAddressFromKB();
}


// Read Data from File to ItemType
int ItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_Id;
	fin >> m_sName;
	fin >> m_sAddress;

	return 1;
}


// Write Data from ItemType to File
int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << m_Id;
	fout << m_sName;
	fout << m_sAddress;
	fout << '\n';

	return 1;
}


// Compare information of students based on primary key(Id)
RelationType ItemType::CompareByID(const ItemType& data)
{
	if (this->m_Id > data.m_Id) {
		return GREATER;
	}
	else if (this->m_Id < data.m_Id) {
		return LESS;
	}
	else {
		return EQUAL;
	}
}