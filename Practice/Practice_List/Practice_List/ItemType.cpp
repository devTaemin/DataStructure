#include "ItemType.h"


// Get functions
int ItemType::GetId() const
{
	return m_Id;
}


string ItemType::GetName() const
{
	return m_Name;
}


string ItemType::GetAddress() const
{
	return m_Address;
}


// Set functions
void ItemType::SetId(int inId)
{
	m_Id = inId;
}


void ItemType::SetName(string inName)
{
	m_Name = inName;
}


void ItemType::SetAddress(string inAddress)
{
	m_Address = inAddress;
}


void ItemType::SetRecord(int inId, string inName, string inAddress)
{
	SetId(inId);
	SetName(inName);
	SetAddress(inAddress);
}


// Display functions
void ItemType::DisplayIdOnScreen()
{
	cout << "\tID     : " << m_Id << '\n';
}


void ItemType::DisplayNameOnScreen()
{
	cout << "\tName   : " << m_Name << '\n';
}


void ItemType::DisplayAddressOnScreen()
{
	cout << "\tAddress: " << m_Address << '\n';
}


void ItemType::DisplayRecordOnScreen()
{
	DisplayIdOnScreen();
	DisplayNameOnScreen();
	DisplayAddressOnScreen();
}


// Set from KB
void ItemType::SetIdFromKB()
{
	cout << "\tID     : ";
	cin >> m_Id;
}


void ItemType::SetNameFromKB()
{
	cout << "\tName   : ";
	cin >> m_Name;
}


void ItemType::SetAddressFromKB()
{
	cout << "\tAddress: ";
	cin >> m_Address;
}


void ItemType::SetRecordFromKB()
{
	SetIdFromKB();
	SetNameFromKB();
	SetAddressFromKB();
}


// File functions
int ItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_Id;
	fin >> m_Name;
	fin >> m_Address;
	return 1;
}


int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_Id << " ";
	fout << m_Name << " ";
	fout << m_Address;
	return 1;
}


// Compare functions
RelationType ItemType::CompareByID(const ItemType& inData)
{
	if (this->m_Id > inData.m_Id) {
		return GREATER;
	}
	else if (this->m_Id < inData.m_Id) {
		return LESS;
	}
	else { return EQUAL; }
}